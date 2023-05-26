/* -*-C++-*- */
// Copyright Dassault Systemes 1996
//-----------------------------------------------------------------------------
// Abstract: groupe de radio buttons dans un menu
//           specialisation de CATCmdRep
//-----------------------------------------------------------------------------
// Usage:    permet le traitement simultane de tous les boutons correspondant a
//           une commande donnee
//-----------------------------------------------------------------------------
// Inheritance: CATCmdStarterRep
//                 CATCmdRep
//-----------------------------------------------------------------------------
// Main methods:    
//
//-----------------------------------------------------------------------------
#ifndef CATCmdStarterRep_H
#define CATCmdStarterRep_H
#include "CATAfrFoundation.h"

class CATCmdStarter;
class CATAfrPLMBarStarterView;
class CATCommandHeader;
class CATDialog;
class CATSysWeakRef;
//extension AfrFoundation
class CATAfrStarterView;

#include "CATCmdRep.h"



class ExportedByCATAfrFoundation CATCmdStarterRep: public CATCmdRep
{
    friend class CATCAfrActionPadController;
  CATDeclareKindOf;
  
public:
  CATCmdStarterRep(CATCmdStarter *, CATCommand *, CATCommandHeader *);
  virtual ~CATCmdStarterRep();
  virtual void SetDialog (CATDialog *);
  virtual int            UpdateContext ();

  virtual void Free()    const;
  virtual void Freeze()  const;

  virtual void Press()   const;
  virtual int  Pressed();
  virtual void ReleaseButton() const;
  virtual void SetMnemonic (const char mnemonic);
  virtual CATCommandHeader * GetHeader();

  virtual void           DoStartDrag (CATCommand *, CATNotification *);
  virtual void           DoEndDrop   (CATCommand *, CATNotification *);

  /**
  *   @author ld3
  *   Create the View for this Starter rep.
  * 
  */
  CATCommand * CreateStarterView(CATCommand *);
  /**
  *   @author ld3
  *   Delete the View for this Starter rep.
  * 
  */
  void DeleteStarterView();

  void SetHeader(CATCommandHeader * header);

protected:
  void                   AddCBs(CATCommandHeader * header);
 
  virtual void ActivateCB       (CATCallbackEvent, void *, CATNotification *,
			 CATSubscriberData, CATCallback);
  void ActivateCommandCB(CATCommand *, CATNotification *,
			 CATCommandClientData);
  void RepeatCommandCB  (CATCommand *, CATNotification *,
			 CATCommandClientData);
  virtual void SetUserAliasCB (CATCallbackEvent, void *, CATNotification *,
			 CATSubscriberData, CATCallback);

  // This is protected data member for legacy reason.
  // Please don't use it and use GetHeader() and SetHeader() method instead.
  CATCommandHeader      * _header;

private:
 



  void DeactivateCB     (CATCallbackEvent, void *, CATNotification *,
			 CATSubscriberData, CATCallback);
  void CancelCB         (CATCallbackEvent, void *, CATNotification *,
			 CATSubscriberData, CATCallback);
  void AvailabilityCB   (CATCallbackEvent, void *, CATNotification *,
			 CATSubscriberData, CATCallback);
  void SetIconCB        (CATCallbackEvent, void *, CATNotification *,
			 CATSubscriberData, CATCallback);
  void SetTitleCB       (CATCallbackEvent, void *, CATNotification *,
			 CATSubscriberData, CATCallback);
  void SetAcceleratorCB (CATCallbackEvent, void *, CATNotification *,
			 CATSubscriberData, CATCallback);
  void SetBehaviorChangedCB();
  
  void GenericCB (CATCallbackEvent, void *, CATNotification *,
		  CATSubscriberData, CATCallback);

  void CheckedCB (CATCallbackEvent, void *, CATNotification *,
      CATSubscriberData, CATCallback);

  /**
  *   @author ld3
  *   Get the View for this starter rep.
  * 
  */
  CATAfrStarterView * GetStarterView() const;

  /**
  *   @author ld3
  *   Set the View for this starter rep.
  *   @param
  *     The starter view to set
  */
  void SetStarterView (CATAfrStarterView * v);

  CATAfrPLMBarStarterView * GetPLMBarStarterView();
  CATSysWeakRef * _headerWeakRef;
  CATSysWeakRef * _plmTbViewWeakRef;
};

#endif
