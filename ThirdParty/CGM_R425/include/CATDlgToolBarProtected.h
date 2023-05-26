#ifndef CATDLGTOOLBARPROTECTED_H
#define CATDLGTOOLBARPROTECTED_H
// DBE Mar 2006 
#include "DI0PANV2.h"
#include "CATBoolean.h"

class CATDlgToolBar;

class ExportedByDI0PANV2 CATDlgToolBarProtected
{
  public :
    static CATBoolean IsActuallyVisible(CATDlgToolBar* iToolBar);
    static void       ForceVisibility  (CATDlgToolBar* iToolBar);
};
#endif


