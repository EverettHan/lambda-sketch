#ifndef CATMainwinInit_h
#define CATMainwinInit_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#ifndef _WINDOWS_SOURCE

#ifdef PLATEFORME_DS64
  typedef int HRESULT;
#else
  typedef long HRESULT;
#endif


class CATMainwin {
 public:
  /**
   * Initialization function which must be called prior making to
   * any calls to Mainwin.
   * It takes care of calling the COM CoInitialize and OleInitialoize, 
   * initializers, so the application must never call them directly.
   */
  static HRESULT Initialize(void);

  /**
   * Clean-up function which must be called once the application has
   * finished making calls to mainwin.
   * If the application is the last Mainwin client, the COM 
   * CoUninitialize and OleUnitialize clean-up function are called, so
   * so the application must never call them directly.
   */
  static void Uninitialize(void);
  
  /**
   * + qay 27/03/2007 IR A0578057 /tmp filling up
   * Mainwin implementation of the _exit() routine, making sure it first
   * cleans up its temp files.
   */
  static void _Exit(int iExitCode);

 private:
  static int _isMainwinInitialized; // + qay 27/03/2007 IR A0578057
  static int _mwrefs;
};

#endif /* _WINDOWS_SOURCE */
#endif /* CATMainwinInit_h */



