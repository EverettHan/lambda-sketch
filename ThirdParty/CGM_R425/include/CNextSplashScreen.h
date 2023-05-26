/**
 * @quickreview NCT     20:11:02 Use HookProtector to avoid Hook to be called after its static data has been destroyed (see comment below)
 * @quickreview NCT     20:10:13 Check that hwnd is valid in hook callback, it seems that it may be already destroyed when receiving WM_UAHDESTROYWINDOW (0x0090) message
 * @quickreview NCT     16:03:29 Inhibates splashscreen when /regserver or /unregserver is part of the command line (IR 403801)
 * @quickreview DBE     15:05:13 new function TestAndSetEnvVar. CNEXTSPLASHSCREEN is valued so that the default SplashScreen management in Dialog is desactivated whenever the new one is active.
 * @quickreview NCT     14:12:04 Fix restore session issue (IR 343596)
 * @quickreview NCT     14:08:20 Remove useless activate message
 * @fullreview  NCT DBE 14:06:11 Creation
 */

#ifndef CNextSplashScreen_H
#define CNextSplashScreen_H

#ifdef _WINDOWS_SOURCE

#include <set>

static HHOOK gbl_WindowCallbackEventHook = NULL;
static LRESULT CALLBACK HandleWindowCallbackEvent(int nCode, WPARAM wParam, LPARAM lParam);

static wchar_t gbl_SplashScreenWindowClass[] = L"3DSSplashScreen";
static wchar_t gbl_SplashScreenWindowTitle[256] = { L'\0' };

static int TestAndSetEnvVar()
{
  char * odtName = getenv("ODT_LOG_NAME");
  char * varValue = getenv("CNEXTSPLASHSCREEN");

  int isNo = (NULL != varValue && strcmp(varValue, "no") == 0);
  int isYes = (NULL != varValue && strcmp(varValue, "yes") == 0);

  int rc = 1;

  if (isNo || (NULL != odtName && !isYes))
    rc = 0;
  else
  {
    // Check if an argument inhibates splash screen
    int nArgs = 0;
    LPWSTR * szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
    if (NULL != szArglist)
    {
      for(int i=0; i<nArgs && rc!=0; i++)
      {
        if (_wcsicmp(szArglist[i], L"/regserver") == 0 || _wcsicmp(szArglist[i], L"/unregserver") == 0)
          rc = 0;
      }
      LocalFree(szArglist);
      szArglist = NULL;
    }
  }

  // Ensure splashscreen will be started at most once
  static char putEnvSplashScreen[] = "CNEXTSPLASHSCREEN=no";
  putenv(putEnvSplashScreen);

  return rc;
}

/**
 * Show animated splash screen
 * @return 0 on success
 */
static int DisplaySplashScreen()
{
  int rc = -1;
  if (TestAndSetEnvVar())
  {
    // @NCT
    // Launch "3DSSplashScreen.exe"
    HMODULE hModSplashScreen = LoadLibrary(L"3DSSplashScreen.exe");
    if (NULL != hModSplashScreen)
    {
      wchar_t processPath[_MAX_PATH + 1];
      ZeroMemory(processPath, sizeof(processPath));
      if (GetModuleFileName(hModSplashScreen, processPath, _MAX_PATH + 1) > 0 && GetLastError() == ERROR_SUCCESS)
      {
        STARTUPINFO si;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);

        PROCESS_INFORMATION pi;
        ZeroMemory(&pi, sizeof(pi));

        gbl_WindowCallbackEventHook = SetWindowsHookEx(WH_CALLWNDPROC, HandleWindowCallbackEvent, NULL, GetCurrentThreadId());

        // @NCT
        // Start splash screen process : 3DSSplashScreen.exe <PID> <WindowClass> <WindowTitle>
        // PID will let splash screen process monitor our lifecycle and exit when we crash
        // WindowClass and WindowTitle will be used by splash screen process to create the splash screen window
        // We will use both information to get splash screen window handle quickly
        DWORD pid = GetCurrentProcessId();

        ZeroMemory(gbl_SplashScreenWindowTitle, sizeof(gbl_SplashScreenWindowTitle));
        swprintf(gbl_SplashScreenWindowTitle, sizeof(gbl_SplashScreenWindowTitle) / sizeof(wchar_t), L"SplashScreen_%d", pid);

        static wchar_t cmdLine[_MAX_PATH + 128];
        ZeroMemory(cmdLine, sizeof(cmdLine));
        swprintf(cmdLine, sizeof(cmdLine) / sizeof(wchar_t), L"\"%s\" %d \"%s\" \"%s\"", processPath, pid, gbl_SplashScreenWindowClass, gbl_SplashScreenWindowTitle);
        if (CreateProcess(processPath, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi) != 0)
        {
          CloseHandle(pi.hProcess);
          CloseHandle(pi.hThread);

          rc = 0;
        }
      }
    }
  }

  return rc;
}

/**
 * NCT 2020.11.02
 * DSVerifier has detected that HandleWindowCallbackEvent can still be called after its static data have been destroyed
 * This is probably due to a very low level implementation of Hook
 * We now use a specific static object whose destruction unregisters the Hook, then callback is not called anymore afterward
 */
class HookProtector
{
public:
  HookProtector()
  {
  }

  ~HookProtector()
  {
    if (NULL != gbl_WindowCallbackEventHook)
    {
      UnhookWindowsHookEx(gbl_WindowCallbackEventHook);
      gbl_WindowCallbackEventHook = NULL;
    }
  }
};

LRESULT CALLBACK HandleWindowCallbackEvent(int nCode, WPARAM wParam, LPARAM lParam)
{
  static UINT msg_hide = RegisterWindowMessage(L"SPLASHSCREEN_HIDE");
  static UINT msg_show = RegisterWindowMessage(L"SPLASHSCREEN_SHOW");
  static UINT msg_exit = RegisterWindowMessage(L"SPLASHSCREEN_EXIT");

  static std::set<HWND> visibleWindows;

  // NCT 2020.11.02 See comment above
  static HookProtector hookProtector;

  static HWND hWndSplashScreen = NULL;

  if (NULL == hWndSplashScreen)
    hWndSplashScreen = FindWindow(gbl_SplashScreenWindowClass, gbl_SplashScreenWindowTitle);

  CWPSTRUCT * pCWPStruct = (CWPSTRUCT *) lParam;

  // @NCT
  // We ignore WM_GETTEXT to avoid looping if we call GetWindowText (during debug for example)
  // 2020.10.13 Check that hwnd is still valid
  if (nCode >= 0 && NULL != hWndSplashScreen && NULL != pCWPStruct && ::IsWindow(pCWPStruct->hwnd) && pCWPStruct->message != WM_GETTEXT)
  {
    WINDOWINFO wi;
    memset(&wi, 0, sizeof(wi));
    wi.cbSize = sizeof(wi);
    GetWindowInfo(pCWPStruct->hwnd, &wi);

    CWnd * pMfcWindow = CWnd::FromHandle(pCWPStruct->hwnd);
    const char * mfcClassName = NULL;
    if (NULL != pMfcWindow)
    {
      CRuntimeClass * pMfcRuntimeClass = pMfcWindow->GetRuntimeClass();
      if (NULL != pMfcRuntimeClass)
        mfcClassName = pMfcRuntimeClass->m_lpszClassName;
    }

    // @NCT
    // We only look at main windows (we ignore all labels, buttons...)
    // We also ignore EasyWarning (l_CATDlgMfcLongHelp)
    if (! (wi.dwStyle & WS_CHILD) && (NULL == mfcClassName || strcmp(mfcClassName, "l_CATDlgMfcLongHelp") != 0))
    {
      switch(pCWPStruct->message)
      {
      case WM_CREATE:
        if (wi.dwStyle & WS_VISIBLE)
        {
          visibleWindows.insert(pCWPStruct->hwnd);
          PostMessage(hWndSplashScreen, msg_hide, (WPARAM) pCWPStruct->hwnd, 0);
        }
        break;
      case WM_DESTROY:
        if (visibleWindows.erase(pCWPStruct->hwnd) > 0 && visibleWindows.empty())
          PostMessage(hWndSplashScreen, msg_show, (WPARAM) pCWPStruct->hwnd, 0);
        break;
      case WM_WINDOWPOSCHANGED:
        {
          WINDOWPOS * pWindowPos = (WINDOWPOS *) pCWPStruct->lParam;
          if (NULL != pWindowPos)
          {
            if ((pWindowPos->flags & SWP_SHOWWINDOW) && pWindowPos->cx > 0 && pWindowPos->cy > 0)
            {
              visibleWindows.insert(pCWPStruct->hwnd);
              PostMessage(hWndSplashScreen, msg_hide, (WPARAM) pCWPStruct->hwnd, 0);

              // @NCT
              // We make splash screen process exit when the main document is shown
              if (NULL != pMfcWindow && pMfcWindow->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
              {
                PostMessage(hWndSplashScreen, msg_exit, (WPARAM) pCWPStruct->hwnd, 0);
                UnhookWindowsHookEx(gbl_WindowCallbackEventHook);
                gbl_WindowCallbackEventHook = NULL;
              }
            }
            else if (pWindowPos->flags & SWP_HIDEWINDOW)
            {
              if (visibleWindows.erase(pCWPStruct->hwnd) > 0 && visibleWindows.empty())
                PostMessage(hWndSplashScreen, msg_show, (WPARAM) pCWPStruct->hwnd, 0);
            }
          }
        }
        break;
      }
    }
  }

  return CallNextHookEx(gbl_WindowCallbackEventHook, nCode, wParam, lParam);
}

#endif

#ifdef _LINUX_SOURCE

#include "DI0PANV2.h"

ExportedByDI0PANV2 int RequestAnimatedSplashScreen();

static int TestAndSetEnvVar()
{
  char * odtName = getenv("ODT_LOG_NAME");
  char * varValue = getenv("CNEXTSPLASHSCREEN");

  int isNo = (NULL != varValue && strcasecmp(varValue, "no") == 0);
  int isYes = (NULL != varValue && strcasecmp(varValue, "yes") == 0);

  int rc = 1;

  if (isNo || (NULL != odtName && !isYes))
    rc = 0;

  // Ensure splashscreen will be started at most once
  static char putEnvSplashScreen[] = "CNEXTSPLASHSCREEN=no";
  putenv(putEnvSplashScreen);

  return rc;
}

/**
 * Show animated splash screen
 * @return 0 on success
 */
static int DisplaySplashScreen()
{
  int rc = -1;

  if (TestAndSetEnvVar())
  {
    // On Linux, splash screen will be launched once X11/Motif is initialized
    // Here, we just inform Dialog that splash screen will have to be launched
    rc = RequestAnimatedSplashScreen();
  }

  return rc;
}

#endif

#endif
