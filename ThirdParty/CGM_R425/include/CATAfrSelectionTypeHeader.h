#ifndef CATAfrSelectionTypeHeader_h
#define CATAfrSelectionTypeHeader_h
#include "CATDialogEngine.h"
//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2002
//-----------------------------------------------------------------------------
// Inheritance: CATAfrSelectionTypeHeader
//                CATCommandHeader
//                  CATCheckHeader
//                    CATCallbackManager (System framework)
//-----------------------------------------------------------------------------
#include "CATCheckHeader.h"

#include "CATString.h"
#include "CATListOfInt.h"
#include "CATListPV.h"
#include "CATEventSubscriberTypedefs.h"

class ExportedByCATDialogEngine CATAfrSelectionTypeHeader : public CATCheckHeader
{

  CATDeclareClass;
  CATDeclareHeaderSpecialResources;

 public:
  
  CATAfrSelectionTypeHeader (const CATString & iHeaderID,
                             CATString         iResourcesFileName="CATAfr");
  CATAfrSelectionTypeHeader( CATAfrSelectionTypeHeader * iHeader);
  
  virtual ~CATAfrSelectionTypeHeader ();

  void SetTypeList (CATListOfCATString* iTypeList,
                    int                 iRelatedMode);
  CATListOfCATString* GetTypeList (int iRelatedMode);

  virtual CATCommandHeader * Clone();

     /**
   * Please do not use this method.
   * This is overrided per CATCheckHeader migration purpose
   * Do not call this method.
   */
  virtual void SetCheck(int checked=1, int startCmd=1);
  
  /**
   * Please do not use this method.
   * This is overrided per CATCheckHeader design request.
   * To change HeaderState use StartCommand() or SetCheck method.
   */
  virtual void SetChecked ();

  /**
   * Please do not use this method.
   * This is overrided per CATCheckHeader design request.
   * To change HeaderState use StartCommand() or SetCheck method
   */
  virtual void SetUnChecked ();
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

  /**  
   * @nodoc
   * internal use
   */
  void UpdateAgents ();

 private:
  void SetInternalChecked ();
  void SetInternalUnChecked ();

  int                     _NbAgent;
  int                     _NbMode;
  CATListOfInt            _ModeList;
  CATListOfInt            _ModeActivityList;
  CATListPV               _TypeListList;
  CATListPV               _AgentList;
  CATListOfInt            _NbAgentModeList;
  CATCallback             _ModeCB, _AgentCB, _ResetCB, _RecoverCB, _RecoverResetCB;
  // ZBJ: 2 Nov 2010: Selection Filter HL
  CATBoolean              _recoverSet;           // to store checked/unchecked state of filter.
  CATBoolean              _removeFilterChecked;  // to store Remove filter commands checked/unchecked state.

  void PrivateInit (const CATString & iHeaderID);

  void UpdateModes  (int iActivity,
                     int iModes);

  void UpdateAgents (CATListOfCATString* iTypeList,
                     int                 iActivity);
  void UpdateFromAgent (CATCallbackEvent iEvent,
                        void* iSender,
                        CATNotification* iNotif,
                        CATSubscriberData iData,
                        CATCallback iCB);
  void UpdateFromMode  (CATCallbackEvent iEvent,
                        void* iSender,
                        CATNotification* iNotif,
                        CATSubscriberData iData,
                        CATCallback iCB);
  void UpdateFromReset (CATCallbackEvent iEvent,
                        void* iSender,
                        CATNotification* iNotif,
                        CATSubscriberData iData,
                        CATCallback iCB);
  // ZBJ: 2 Nov 2010: Selection Filter HL
  // callback to reset the filters when Suspend Filters command is selected
  void ResetSelectionFilters (CATCallbackEvent iEvent,
                         void* iSender,
                         CATNotification* iNotif,
                         CATSubscriberData iData,
                         CATCallback iCB);
  // callback to restore the filters state to the state which was before selection of Suspend Filters command
  void RecoverFromReset (CATCallbackEvent iEvent,
                         void* iSender,
                         CATNotification* iNotif,
                         CATSubscriberData iData,
                         CATCallback iCB);

  void GetActiveTypes (CATListOfCATString* iListToFill);
  void GetAllTypes (CATListOfCATString* iListToFill);

};

#endif

