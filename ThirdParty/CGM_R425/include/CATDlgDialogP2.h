#ifndef CATDLGDIALOGP2_H
#define CATDLGDIALOGP2_H

#include "DI0PANV2.h"                                         

//------------------------------------------------------------------------------
// Abstract: The class enables user look P2 for programs without license initialization
//
//------------------------------------------------------------------------------
// Main methods:
//
//------------------------------------------------------------------------------

class ExportedByDI0PANV2 CATDlgDialogP2
{
  friend class AdminTools;
  friend class CATApplicationLibraryEx;
  
  private:
    static void ForceLookP2();
};

#endif
