#ifndef CATAfrSelectionSuspendHeader_h
#define CATAfrSelectionSuspendHeader_h
#include "CATDialogEngine.h"
//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2010
//-----------------------------------------------------------------------------
// Inheritance: CATAfrSelectionSuspendHeader
//                CATCheckHeader
//                  CATCommandHeader
//                    CATCallbackManager (System framework)
//-----------------------------------------------------------------------------
#include "CATCheckHeader.h"

/**
* Class to create a Remove Filter command header.
* this class overrides the SetChecked and SetUnChecked methods of CATCheckHeader to provide the 
* selection behavior of Remove filter command.
**/

class ExportedByCATDialogEngine CATAfrSelectionSuspendHeader : public CATCheckHeader
{

  CATDeclareClass;
  CATDeclareHeaderResources;

 public:
   
  CATAfrSelectionSuspendHeader (const CATString & iHeaderID,
                                CATString         iResourcesFileName="CATAfr");
  
  virtual ~CATAfrSelectionSuspendHeader ();

  /**
  * Please do not use this method.
  * This is overrided per CATCheckHeader migration purpose
  * Do not call this method.
  */
  virtual void SetChecked ();
  /**
  * Please do not use this method.
  * This is overrided per CATCheckHeader migration purpose
  * Do not call this method.
  */
  virtual void SetUnChecked ();
  /**
  * Please do not use this method.
  * This is overrided per CATCheckHeader migration purpose
  * Do not call this method.
  */
  virtual void SetCheck(int checked=1, int startCmd=1);
  /**
  * Please do not use this method.
  * This is overrided per CATCheckHeader migration purpose
  * Do not call this method.
  */
  virtual int IsChecked();
  /**
  * Please do not use this method.
  * This is overrided per CATCheckHeader migration purpose
  * Do not call this method.
  */
  virtual CATCommand * StartCommand();

private:
  void SetInternalChecked ();
  void SetInternalUnChecked ();

  CATCallback _AgentCB, _ResetCB;

  void UpdateRemoveFilter (CATCallbackEvent iEvent, void* iSender, CATNotification* iNotif, CATSubscriberData , CATCallback );
  void UpdateFromReset (CATCallbackEvent iEvent, void* iSender, CATNotification* iNotif, CATSubscriberData iData, CATCallback iCB);

};

#endif
