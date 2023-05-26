#ifndef CATCmdWarningDialog_H
#define CATCmdWarningDialog_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2000
// protected DI0STATE.m

// Copyright Dassault Systemes 2000
//----------------------------------------------------------------------------
// Abstract: Dialog box to notify a warning.
//           Goes to a specific state in a CATStateCommand after notifying.
//----------------------------------------------------------------------------
#include "CATCmdUserInfo.h"

#include "CATCommand.h"

class CATError;
class CATStateCommand;
class CATDialogState;
class CATDialogAgent;
class CATDialogTransition;
class CATNotification;

class ExportedByCATDialogEngine CATCmdWarningDialog : public CATCmdUserInfo
{

  DeclareResource(CATCmdWarningDialog, CATDlgNotify)
  
public:

  CATCmdWarningDialog (CATError * Error,
                       CATStateCommand * cmd,
                       CATDialogState * stateToGo,
                       const char * MsgId=NULL,
                       const char * MsgCatalog=NULL);
  ~CATCmdWarningDialog ();
  

private:

  virtual void CloseCB (CATCommand *, CATNotification *, CATCommandClientData);

  CATStateCommand     * _cmd;
  CATDialogState      * _stateToGo;
  CATDialogAgent      * _agent;
  CATDialogTransition * _trans;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCmdWarningDialog ();
  CATCmdWarningDialog (const CATCmdWarningDialog &);
  CATCmdWarningDialog & operator= (const CATCmdWarningDialog &);

};

#endif
