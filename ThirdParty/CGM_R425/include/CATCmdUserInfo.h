#ifndef CATCmdUserInfo_H
#define CATCmdUserInfo_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2000
// protected DI0STATE.m

//----------------------------------------------------------------------------
// Abstract: Base class for notify dialogs in commands.
//           A close button is implemented.
//           A message is built from the Error, MsgId and MsgCatalog data.
//----------------------------------------------------------------------------

#include "CATDlgNotify.h"

#include "CATCommand.h"
#include "CATUnicodeString.h"
#include "CATDlgUtility.h"

class CATError;
class CATString;
class CATNotification;

class ExportedByCATDialogEngine CATCmdUserInfo : public CATDlgNotify
{

  DeclareResource(CATCmdUserInfo, CATDlgNotify)
  
public:

  // Style CATDlgNfyOK|CATDlgWndModal is already assumed.
  // Add CATDlgNfyError or CATDlgNfyWarning or CATDlgNfyInformation or...
  CATCmdUserInfo (const CATString & name,
                  CATError * Error,
                  const char * MsgId,
                  const char * MsgCatalog,
                  CATDlgStyle style);
  ~CATCmdUserInfo ();
  
protected:

  // Sets the callbacks and calls Info() :
  virtual void Init ();
  // Builds the message to display in the dialog box :
  virtual CATUnicodeString Info ();
  // Callback on the Close button :
  virtual void CloseCB (CATCommand *, CATNotification *, CATCommandClientData);

  CATError * _Error;
  char     * _MsgId;
  char     * _MsgCatalog;

private:

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCmdUserInfo ();
  CATCmdUserInfo (const CATCmdUserInfo &);
  CATCmdUserInfo & operator= (const CATCmdUserInfo &);

};

#endif
