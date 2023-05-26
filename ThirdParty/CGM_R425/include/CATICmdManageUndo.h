#ifndef CATICmdManageUndo_H
#define CATICmdManageUndo_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1996
// protected DI0STATE.m + CATDegUUID.m

//=============================================================================
//
// CATICmdManageUndo:
// The interface to manage undo for an agent
//
//=============================================================================
// Usage Notes:
//
// implement this interface if you create your own agent
//=============================================================================
// Dec. 96   Creation                                   E. Gallicher
//=============================================================================
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDialogEngine IID IID_CATICmdManageUndo;
#else
extern "C" const IID IID_CATICmdManageUndo;
#endif

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATICmdManageUndo : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
public:
  
  //----------------------------------------------------
  //  virtual methods to be defined by the user to manage Undo/Redo
  //----------------------------------------------------
  
  virtual HRESULT BeforeUndo () = 0;
  virtual HRESULT BeforeRedo () = 0;
  virtual HRESULT AfterUndo () = 0;
  virtual HRESULT AfterRedo () = 0;
  virtual HRESULT Clean () = 0; 
  
};

#endif
