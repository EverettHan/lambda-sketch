
// Copyright Dassault Systemes 1997
//-----------------------------------------------------------------------------
// Abstract: 
//-----------------------------------------------------------------------------
// Usage:    
//           
//-----------------------------------------------------------------------------
// Inheritance: CATCmdRep
//                CATCommand
//-----------------------------------------------------------------------------
// Main methods:    
//       
//-----------------------------------------------------------------------------
#ifndef CATCmdRep_H
#define CATCmdRep_H
#include "CATAfrFoundation.h"

class CATDialog;
class CATNotification;
class CATCmdAccess;
class CATSysWeakRef;

#include "CATCommand.h"
				
class CATAfrModelView;
class ExportedByCATAfrFoundation CATCmdRep: public CATCommand
{
public:
  CATCmdRep(CATCmdAccess *, CATCommand *);
  virtual ~CATCmdRep();
  
  virtual void           Free         ()    const;
  virtual void           Freeze       ()  const;

  virtual void           SetDialog    (CATDialog *);
  virtual void           SetEventType (CATNotification *);

  /* No Addref performed on returned value */
  virtual CATCmdAccess * GetAccess    () const;
  /* No Addref performed on returned value */
  virtual CATDialog *    GetParent    ();
  /* No Addref performed on returned value */
  virtual CATDialog *    GetDialog    ();

  void DragCB    (CATCommand *, CATNotification *, CATCommandClientData);
  void EndDropCB (CATCommand *, CATNotification *, CATCommandClientData);

  virtual void           DoStartDrag   (CATCommand *, CATNotification *);
  virtual void           DoEndDrop     (CATCommand *, CATNotification *);
 
  virtual int            ContextCanChange ();
  virtual int            ForgetContext ();
  virtual int            UpdateContext ();

protected:

  virtual void           OnDeleteCB    (
    CATCallbackEvent, void *, CATNotification *,
    CATSubscriberData, CATCallback
    );

  void SetDialogMember (CATDialog ** member, CATDialog * newValue);

  CATNotification       * _eventType;

  /* Do not directly access this member use GetAccess/SetAccess methods */
  CATCmdAccess          * _access;
  /* Do not directly access this member use GetParent/SetParent methods */
  CATDialog             * _parent;
  /* Do not directly access this member use GetDialog/SetDialog methods */
  CATDialog             * _dialog;


  /*======== Extension Afrfoundation ===========*/
 /**
  *   @author ld3
  *   Get the representationType for the access.<br/>
  *   If the access does not have the representation type, we ask to the father
  *   to get it.
  *   @return S_OK if the representationType has been found. E_FAIL, otherwise.
  * 
  */
  HRESULT GetAccessRepresentationType(CATString &);
  /*==============================================*/

private:

  void SetMember(
    CATBaseUnknown ** member, CATBaseUnknown * newValue, CATSysWeakRef ** memberWeakRef);
  
 
  CATSysWeakRef * _accessWeakRef;
  CATSysWeakRef * _dialogWeakRef;
  CATSysWeakRef * _parentWeakRef;

protected:
    //extension AfrFoundation
  CATSysWeakRef * _viewWeakRef;
  CATBaseUnknown * GetComponentFromMemberWeakRef(CATSysWeakRef * WeakRef) const;
  CATAfrModelView * GetAccessView() const;
  friend class CATAfrTstScanAccessViewRep;
  friend class AfrActionBarPlayer_UT1;
};

#endif


