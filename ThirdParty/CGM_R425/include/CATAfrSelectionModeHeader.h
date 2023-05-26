#ifndef CATAfrSelectionModeHeader_h
#define CATAfrSelectionModeHeader_h
#include "CATDialogEngine.h"
//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2002
//-----------------------------------------------------------------------------
// Inheritance: CATAfrSelectionModeHeader
//                CATCheckHeader
//                  CATCommandHeader
//                    CATCallbackManager (System framework)
//-----------------------------------------------------------------------------
#include "CATCheckHeader.h"

#include "CATString.h"
#include "CATEventSubscriberTypedefs.h"

class ExportedByCATDialogEngine CATAfrSelectionModeHeader : public CATCheckHeader
{

  CATDeclareClass;
  CATDeclareHeaderSpecialResources;

 public:
  
  CATAfrSelectionModeHeader (const CATString & iHeaderID,
                             CATString         iResourcesFileName="",
                             int               iMode             =-1);
  CATAfrSelectionModeHeader (CATAfrSelectionModeHeader * iHeader);
  
  virtual ~CATAfrSelectionModeHeader ();

  int  GetMode ();
  
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
  CATCommand * StartCommand();

  enum CATSelectionModeCursor
  {
    CATDefaultFilter,
    CATGeometryFilter,
    CATFeatureFilter
  };

  /**
   * Call this method to activate a mouse cursor when this mode
   * is selected. 
   * Authorized value : CATAfrSelectionModeHeader::CATGeometryFilter 
   * for a geometry filter.
   */
  void SetModeCursor(CATSelectionModeCursor cursor);

  /**
   * Internal use.
   * Please do not use this method.
   */
  CATSelectionModeCursor GetModeCursor();

  /**
   * @nodoc
   * Internal use.
   */
  virtual CATCommandHeader * Clone();

  void UpdateHeaders    (int iActivity);

 private:
  void SetInternalChecked ();
  void SetInternalUnChecked ();

  int                     _Mode;
  int                     _NbHeader;
  CATCallback             _HeaderCB, _ResetCB, _RecoverCB, _RecoverResetCB;
  CATSelectionModeCursor  _cursor;
  // ZBJ: 2 Nov 2010: Selection Filter HL
  CATBoolean              _recoverSet;           // to store checked/unchecked state of filter.
  CATBoolean              _removeFilterChecked;  // to store Remove filter commands checked/unchecked state.

  void PrivateInit      (const CATString & iHeaderID);
  void UpdateFromHeader (CATCallbackEvent iEvent,
                         void* iSender,
                         CATNotification* iNotif,
                         CATSubscriberData iData,
                         CATCallback iCB);
  void UpdateFromReset  (CATCallbackEvent iEvent,
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

};

#endif

