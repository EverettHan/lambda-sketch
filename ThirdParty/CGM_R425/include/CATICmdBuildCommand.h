#ifndef CATICmdBuildCommand_H
#define CATICmdBuildCommand_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1998
// protected DI0STATE.m + CATDegUUID.m

//=============================================================================
//
// CATICmdBuildCommand:
// The basic interface which enables to build the graph of a command
//
//=============================================================================
// Usage Notes:
//
//  Use the CATCmdCreateAgent service to instanciate an agent.
//=============================================================================
// Dec. 98   Creation                                   E. Gallicher
//=============================================================================
#include "CATBaseUnknown.h"

extern ExportedByCATDialogEngine IID IID_CATICmdBuildCommand;

//-----------------------------------------------------------------------------
class ExportedByCATDialogEngine CATICmdBuildCommand : public CATBaseUnknown
{

  CATDeclareInterface;
  
public:
  
  virtual HRESULT CreateGraph () = 0;

};

#endif
