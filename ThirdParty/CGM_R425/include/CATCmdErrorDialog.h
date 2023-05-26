#ifndef CATCmdErrorDialog_H
#define CATCmdErrorDialog_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1999
// protected DI0STATE.m

//----------------------------------------------------------------------------
// Abstract: Dialog box to notify an error. The current command is cancelled
//           after the error is notified.
//----------------------------------------------------------------------------

#include "CATCmdUserInfo.h"

class CATError;
class CATCommand;
class CATNotification;

class ExportedByCATDialogEngine CATCmdErrorDialog : public CATCmdUserInfo
{

  DeclareResource(CATCmdErrorDialog, CATDlgNotify)
  
public:

  CATCmdErrorDialog (CATError * Error,
                     const char * MsgId=NULL,
                     const char * MsgCatalog=NULL);
  ~CATCmdErrorDialog ();

  CATStatusChangeRC Activate (CATCommand *, CATNotification *);

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCmdErrorDialog ();
  CATCmdErrorDialog (const CATCmdErrorDialog &);
  CATCmdErrorDialog & operator= (const CATCmdErrorDialog &);

};

#endif
