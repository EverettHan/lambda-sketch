//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022/02/15
//===================================================================
// UIVCoreServices.h
// Header definition of class UIVCoreServices
//===================================================================
//
// Usage notes:
//
//===================================================================
// 2022/02/15 Creation: GX2
//===================================================================

#ifndef UIVCoreServices_H
#define UIVCoreServices_H

#include <UIVCoreTools.h>

class ExportedByUIVCoreTools UIVCoreServices
{
  public:

    static bool IsDebuggerPresent();

    static void DebugBreak();

  private:
    UIVCoreServices();
    virtual ~UIVCoreServices();

    // Copy constructor and equal operator
    // -----------------------------------
    UIVCoreServices(UIVCoreServices&);
    UIVCoreServices& operator=(UIVCoreServices&);
};

#endif
