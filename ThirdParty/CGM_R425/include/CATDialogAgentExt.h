#ifndef CATDialogAgentExt_H
#define CATDialogAgentExt_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m + CATDegUUID.m

//------------------------------------------------------------------------------
// Abstract: definition of the interface CATDialogAgentExt 
//           Is a new interface (extension) for a CATCommand.
//------------------------------------------------------------------------------
// Usage:    it is used by a CATCommand which is integrated into a
//           CATStateCommand as an agent of a state.
//------------------------------------------------------------------------------
#include "CATBaseUnknown.h"

#include "CATDialogAgent.h"
#include "CATUnicodeString.h"
#include "CATDlgEngUtility.h"
#include "CATBooleanDef.h"

class CATNotification;
class CATCommand;

typedef void (CATCommand::*AgentMethod)();

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATDialogEngine IID IID_CATDialogAgentExt;
#else
extern "C" const IID IID_CATDialogAgentExt;
#endif

class ExportedByCATDialogEngine CATDialogAgentExt : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
public:
  
  //-----------------------------------------------------------------
  // method to modify the default behaviour of the command  
  //-----------------------------------------------------------------
  
  virtual void SetBehavior (CATDlgEngBehavior Behavior) = 0;
  virtual CATDlgEngBehavior GetBehavior () = 0;
  
  //-----------------------------------------------------------------
  // trigger the test of conditions in the CATStateCommand 
  //-----------------------------------------------------------------
  
  virtual void Accept (CATNotification * notif=NULL) = 0;
  
  //-----------------------------------------------------------------
  // methods to initialize or question the commands about acquisitions
  //-----------------------------------------------------------------
  
  virtual void InitializeAcquisition () = 0;
  virtual CATBoolean IsOutputSet () = 0;
  
};

#endif
