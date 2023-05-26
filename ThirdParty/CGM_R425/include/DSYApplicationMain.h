#ifndef DSYApplicationMain_H
#define DSYApplicationMain_H

#ifdef _ANDROID_SOURCE
# include "DSYSysAndroid.h"
#endif  // _ANDROID_SOURCE

#include "CATSysGetBatchMode.h"

// TODO:
// - Prepare header for CAA (nodoc ...)

/**
 * DSYApplicationMain.
 ***************************
 * Interactive application *
 ***************************
 * Provide a generic way to define an interactive application using System's main.
 * How to:
 *  + Imakefile: link the archive DSYApplicationMainArch & the JS0GROUP Dll
 *  + Exe module code: given that your interactive application is named MyCNext,
 *     1) Remove the following global statement if present:
 *        MyCNext MyApplication;
 *     2) Call the macro DSYInteractiveApplicationMainImpl at global scope:
 *        DSYInteractiveApplicationMainImpl(MyCNext)
 *
 ***************************
 * Console application     *
 ***************************
 * Provide a generic way to define a console application that leverages System's initialization
 * thanks to the use of the following macros:
 *  + DSYConsoleApplicationMainBegin
 *  + DSYConsoleApplicationMainEnd
 */

class CATApplication;

extern "C" CATApplication * CATApplicationFactory();
#if defined(_WINDOWS_SOURCE)
int WINAPI ExeInitInteractiveApp(CATSysBatchMode iMode, HINSTANCE hInstance, LPTSTR lpstrCmdLine, int *oExitRequired);
int WINAPI ExeMainLoop(CATSysBatchMode iMode, HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow);
extern "C" int ExeInitWin32App(PWSTR lpCmdLine, int* oExitRequired);
extern "C" void ExeFinaWin32App(void);
#else   // _WINDOWS_SOURCE
int ExeInitInteractiveApp(CATSysBatchMode iMode, int argc, char *argv[], char **env, int *oExitRequired);
int ExeMainLoop(CATSysBatchMode iMode, int argc, char *argv[], char **env);
#endif  // _WINDOWS_SOURCE
int ExeInitConsoleApp(int argc, char *argv[], char **env, int *oExitRequired);
extern "C" void ExeFinaConsoleApp(void);
extern "C" void ExeFinaInteractiveApp(void);

inline CATSysBatchMode sGetValidBatchModeForInteractiveApp(CATSysBatchMode iMode)
{
    CATSysBatchMode l_iMode = iMode;
    if(CATSysBatch == iMode)
        l_iMode = CATSysInteractiveAsBatch;
    return l_iMode; // returns either CATSysInteractive or CATSysInteractiveAsBatch
}

/**
 * Custom main for interactive applications.
 * In order to be able to define a custom main for an interactive application, the following macros 
 * should be used instead of DSYInteractiveApplicationMainImpl:
 *  + _DSYInteractiveApplicationMainBegin
 *  + _DSYInteractiveApplicationMainEntryPoint (Mandatory)
 *  + _DSYInteractiveApplicationMainEnd
 *
 * Example:
 *   _DSYInteractiveApplicationMainBegin(AppClassName,CATSysInteractive|CATSysInteractiveAsBatch)
 *      // Custom init code
 *      _DSYInteractiveApplicationMainEntryPoint(AppClassName,CATSysInteractive|CATSysInteractiveAsBatch)     // Starts the main loop
 *      // Custom finalization code (cleanup...)
 *   _DSYInteractiveApplicationMainEnd(AppClassName,CATSysInteractive|CATSysInteractiveAsBatch)
 */
#if defined(_WINDOWS_SOURCE)
# define _DSYInteractiveApplicationMainBegin(AppClassName,iBatchMode)                   \
    int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpstrCmdLine, int nCmdShow)\
    {                                                                                   \
        CATSysBatchMode l_iMode = sGetValidBatchModeForInteractiveApp(iBatchMode);      \
        int l_bExitRequired = 0;                                                        \
        int rc = ExeInitInteractiveApp(l_iMode, hInstance, lpstrCmdLine, &l_bExitRequired);

# define _DSYInteractiveApplicationMainEntryPoint(AppClassName,iBatchMode)              \
        do                                                                              \
        {                                                                               \
          if( l_bExitRequired == 0 )                                                    \
          { rc = ExeMainLoop(l_iMode, hInstance, hPrevInstance, lpstrCmdLine, nCmdShow); }\
        } while( false );

# define _DSYInteractiveApplicationMainEnd(AppClassName,iBatchMode)                     \
        ExeFinaInteractiveApp();                                                        \
        return rc;                                                                      \
    }
#else   // _WINDOWS_SOURCE
    // Unix OSes
#   define _DSYInteractiveApplicationMainBegin(AppClassName,iBatchMode)                 \
    int main(int argc, char *argv[], char **env)                                        \
    {                                                                                   \
        CATSysBatchMode l_iMode = sGetValidBatchModeForInteractiveApp(iBatchMode);      \
        int l_bExitRequired = 0;                                                        \
        int rc = ExeInitInteractiveApp(l_iMode, argc, argv, env, &l_bExitRequired);

#   define _DSYInteractiveApplicationMainEntryPoint(AppClassName,iBatchMode)            \
        do                                                                              \
        {                                                                               \
          if( l_bExitRequired == 0 )                                                    \
          { rc = ExeMainLoop(l_iMode, argc, argv, env); }                               \
        } while( false );

#   define _DSYInteractiveApplicationMainEnd(AppClassName,iBatchMode)                   \
        ExeFinaInteractiveApp();                                                        \
        return rc;                                                                      \
    }
#endif  // _WINDOWS_SOURCE

#define DSYApplicationFactoryImpl(AppClassName) \
    CATApplication * CATApplicationFactory()                                            \
    {                                                                                   \
      return new AppClassName;                                                          \
    }
    

#if defined(_WINDOWS_SOURCE)
# define Enforce_ComCtl32_V6 \
    __pragma(comment(linker,"\"/manifestdependency:type='win32' \
    name='Microsoft.Windows.Common-Controls' version='6.0.0.0'  \
    processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\""))
# define PlatformSpecificImpl \
    Enforce_ComCtl32_V6
#else   // _WINDOWS_SOURCE
# define PlatformSpecificImpl
#endif  // _WINDOWS_SOURCE

// Flags
#define DSYApplicationMainPrologue      0x01
#define DSYApplicationMainEpilogue      0x02

/**
 * PFuncDSYApplicationExecuteStep.
 * Callback for prologue and epilogue steps.
 * @param iFlags:
 *   + DSYApplicationMainPrologue
 *   + DSYApplicationMainEpilogue
 */
typedef int (*PFuncDSYApplicationExecuteStep)(int iFlags);

/**
 * Interactive applications.
 */
#define DSYInteractiveApplicationMain                                           DSYInteractiveApplicationMainImpl
#define DSYInteractiveApplicationMainImpl(AppClassName)                         \
    PlatformSpecificImpl                                                        \
    DSYApplicationFactoryImpl(AppClassName)                                     \
    _DSYInteractiveApplicationMainBegin(AppClassName,CATSysInteractive)         \
    _DSYInteractiveApplicationMainEntryPoint(AppClassName,CATSysInteractive)    \
    _DSYInteractiveApplicationMainEnd(AppClassName,CATSysInteractive)

#ifdef _ANDROID_SOURCE
# define DSYAndroidNativeApplicationMain(f)      static fAndroidMain_t s_fMain = DSYNativeApplicationMainAndroidGlue(f);
extern "C" fAndroidMain_t DSYNativeApplicationMainAndroidGlue(fAndroidMain_t ifMain);
extern "C" DSYExport void* DSYNativeApplicationMainAndroidCreate(void);
#endif  // _ANDROID_SOURCE

typedef int (*PFuncDSYConsoleApplicationMain)(int argc, char *argv[]);

# define _DSYConsoleApplicationMainBegin(pFuncMain)                                         \
    int main(int argc, char *argv[], char **env)                                            \
    {                                                                                       \
        int l_bExitRequired = 0;                                                            \
        int rc = ExeInitConsoleApp(argc, argv, env, &l_bExitRequired);                      \
        if( l_bExitRequired == 0 )                                                          \
        {                                                                                   \
          PFuncDSYConsoleApplicationMain pFn = (PFuncDSYConsoleApplicationMain) pFuncMain;  \
          if(pFn) rc = pFn(argc, argv);                                                     \
        }

#define _DSYConsoleApplicationMainEnd     \
        ExeFinaConsoleApp();              \
        return rc;                        \
    }

/**
 * Console/batch applications.
 */
#define DSYConsoleApplicationMain                   DSYConsoleApplicationMainImpl
#define DSYConsoleApplicationMainImpl(pFuncMain)    \
  _DSYConsoleApplicationMainBegin(pFuncMain)        \
  _DSYConsoleApplicationMainEnd

#ifdef _WINDOWS_SOURCE
typedef int (*PFuncDSYWin32ApplicationMain)(HINSTANCE, HINSTANCE, PWSTR, int);

# define __DSYWin32ApplicationMain(pFuncMain)                                                                               \
    int CALLBACK wWinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ PWSTR lpCmdLine, _In_ int nCmdShow)  \
    {                                                                                                                       \
        int l_bExitRequired = 0;                                                                                            \
        int rc = ExeInitWin32App(lpCmdLine, &l_bExitRequired);                                                              \
        if( l_bExitRequired == 0 )                                                                                          \
        {                                                                                                                   \
          PFuncDSYWin32ApplicationMain pFn = (PFuncDSYWin32ApplicationMain) pFuncMain;                                      \
          if(pFn) rc = pFn(hInstance, hPrevInstance, lpCmdLine, nCmdShow);                                                  \
        }

# define __DSYWin32ApplicationMainEnd     \
        ExeFinaWin32App();                \
        return rc;                        \
    }

/**
 * Win32 Application.
 */
# define DSYWin32ApplicationMain                    DSYWin32ApplicationMainImpl  
# define DSYWin32ApplicationMainImpl(pFuncMain)     \
  __DSYWin32ApplicationMain(pFuncMain)              \
  __DSYWin32ApplicationMainEnd
#endif  // _WINDOWS_SOURCE

#endif  // DSYApplicationMain_H
