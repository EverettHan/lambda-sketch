// COPYRIGHT DASSAULT SYSTEMES 2004

#ifndef CATAfrBottomToolbarRep_h
#define CATAfrBottomToolbarRep_h

//===========================================================================
//  Abstract of the class:
//  ----------------------
//  This class is the representation ( a CATCommand ) of the 
//  CAAAfrComboColorHeader in the tool bar.
//
//  The current color is kept by the UIActive object of the CAAGeometry 
//  document. 
//  
//===========================================================================

#include "CATAfrCommandHeaderRep.h" // to derive from 
#include "CATString.h"
#include "CATDlgUtility.h"
#include "CATBoolean.h"

class CATString ;
class CATSysWeakRef;
class CATDialog ;
class CATAfrButtonWrapper ;
class CATAfrComboWrapper;
class CATCommandHeader;

class CATAfrBottomToolbarRep : public CATAfrCommandHeaderRep
{

public:
  
  // Constructor
  // -----------
  // iParent kept by the CATAfrBottomToolbarRep class instance will be
  // the dialog object parent of the Combo created by 
  // this class.
  //
  CATAfrBottomToolbarRep(const CATDialog * iParent, CATString & iCommandName, CATString & headerName, CATBoolean comboEditable, CATBoolean comboIcon);

  // Destructor
  // ----------
  // The CATDlgPushButon instance created in this class instance must
  // be released.
  //
  virtual ~CATAfrBottomToolbarRep();

  // Build
  // -----
  // This method  creates the CATDlgPushButon instance 
  //
  HRESULT Build();

  CATAfrComboWrapper  *GetCombo();  // Gets a pointer to the combo.
  CATAfrButtonWrapper *GetButton(); // Gets a pointer to the button.
  void SetComboEditable (CATBoolean ibool);
  void SetComboIcon (CATBoolean ibool);


private:

  void MenuSelectCB (CATCommand * iPublishingCommand, 
                     CATNotification * iNotification, 
                     CATCommandClientData iData);

  void ComboSelectCB(CATCommand * iPublishingCommand, 
                     CATNotification * iNotification, 
                     CATCommandClientData iData);
  void ComboEditCB  (CATCommand * iPublishingCommand, 
                     CATNotification * iNotification, 
                     CATCommandClientData iData);
  void AvailabilityCB(CATCallbackEvent    iEvt,
                      void              * ipFrom, 
                      CATNotification   * ipNotif,
                      CATSubscriberData   iData,
                      CATCallback         iCbk);

  // Copy constructor, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATAfrBottomToolbarRep(const CATAfrBottomToolbarRep &iObjectToCopy);

  // Assignment operator, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATAfrBottomToolbarRep & operator = (const CATAfrBottomToolbarRep &iObjectToCopy);

  // The Button instance created by CreateRep method
  CATAfrButtonWrapper * _pMenuButton;
  CATAfrComboWrapper  * _pCombo;
  CATString             _headerName;
  CATString             _myName;
  CATBoolean            _comboEditable;
  CATBoolean            _comboIcon;

  CATSysWeakRef       * _buttonWeakRef;

  CATDlgStyle           _comboStyle;
};

#endif

