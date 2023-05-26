#ifndef CATPanelAcquisition_h
#define CATPanelAcquisition_h
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 1996
// protected DI0APPLI.m

//------------------------------------------------------------------------------
// Abstract: OBSOLETE CATDialogAgent for a dialog
//           DO NOT USE IT ANY MORE!!!!!
//           the command triggers the test of conditions when it receives
//           specified notifications from the dialog 
//
//------------------------------------------------------------------------------
// Usage:    use directly objects of this class.
//           Associate a dialog to this command
//------------------------------------------------------------------------------
// Inheritance: CATPanelAcquisition (DialogEngine framework)
//                  CATDialogAgent (DialogEngine framework)
//                    CATCommand (System framework)
//------------------------------------------------------------------------------

#include "CATDialogAgent.h"

#include "CATCommand.h"

class CATDialog;
class CATString;
class CATNotification;

class ExportedByCATDialogEngine CATPanelAcquisition : public CATDialogAgent
{
  
  CATDeclareClass;
  
public:
  
  CATPanelAcquisition (const CATString & commandName, CATDialog * panel);
  virtual ~CATPanelAcquisition ();
  
  //-----------------------------------------------------------------
  // specify the notifications which must trigger tests of conditions
  //-----------------------------------------------------------------
  
  void AcceptOnEvent (CATNotification * notif=NULL, CATCommand * from=NULL);
  void AcceptOnEvent (const char * notif, CATCommand * from=NULL);
  void ResetAcceptOnEvent (CATNotification * notif=NULL, CATCommand * from = NULL);
  void ResetAcceptOnEvent (const char * notif, CATCommand * from=NULL);
  
  //-----------------------------------------------------------------
  //  for internal use
  //-----------------------------------------------------------------
  
  virtual CATNotifPropagationMode AnalyseNotification (CATCommand * From,
                                                       CATNotification * notif);
  
  virtual CATStatusChangeRC Cancel (CATCommand * fromClient, CATNotification *);
  virtual CATStatusChangeRC Activate (CATCommand * fromClient, CATNotification *);
  virtual CATStatusChangeRC Desactivate (CATCommand * fromClient, CATNotification *);
  
  void NotifCB (CATCommand *sendObject,
                CATNotification * evt,
                CATCommandClientData data);
  
private:
  
  CATPanelAcquisition (); 
  CATPanelAcquisition (CATPanelAcquisition &);

  void SetDialog (CATDialog *);
 
  CATDialog * _panel;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATPanelAcquisition & operator= (const CATPanelAcquisition &);
  
};

#endif
