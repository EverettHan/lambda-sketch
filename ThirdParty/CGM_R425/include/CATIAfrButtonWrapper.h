// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIAfrButtonWrapper.h
// Define the CATIAfrButtonWrapper interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  May 2009  Creation: Code generated by the CAA wizard  LD3
//===================================================================
#ifndef CATIAfrButtonWrapper_H
#define CATIAfrButtonWrapper_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATString.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrButtonWrapper;
#else
extern "C" const IID IID_CATIAfrButtonWrapper ;
#endif

class CATNotification;
class CATSysWeakRef;
class CATCommand;

typedef unsigned long   CATULong;

//------------------------------------------------------------------

/**
* Interface representing the connection between CATDlgPushButton and CATVidCtlPushButton.
*
* <br><b>Role</b>: Bridge to connect CATDlgPushButton methods to CATVidCtlPushButton equivalent methods.
* <p>
* Do not implement the CATIAfrButtonWrapper interface outside of @href CATEAfrButtonWrapper class
* Do not use the CATIAfrButtonWrapper interface outside of @href CATEAfrButtonWrapper class
*/
class ExportedByCATAfrItf CATIAfrButtonWrapper: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

/** Bridge for Button constructor */
     virtual void InstanciateButton (CATBaseUnknown *iParent, const CATString& iObjectName,int mode) = 0;

    /** Bridge for Button destructor */
     virtual void DestroyButton () = 0;

    /** Bridge for CATDlgPushButton::GetPushBActivateNotification */
     virtual CATNotification *ButtonWrapperGetPushBActivateNotification() const = 0;

    /** Bridge for CATDlgPushButton::SetIconName */
     virtual void ButtonWrapperSetIconName(const CATString& iIconNameNormal,
                              const CATString& iIconNameSelected = "",
                              const CATString& iIconNameFocused = "",
                              const CATString& iIconNameDisabled = "",
                              const CATBoolean iForceSmall = FALSE) = 0;

    /** Bridge for CATDlgPushButton::GetComponentWeakRef */
     virtual CATSysWeakRef *ButtonWrapperGetComponentWeakRef() const = 0;

    /** Bridge for CATDlgPushButton::SetHelp */
    virtual    void  ButtonWrapperSetHelp( const CATUnicodeString& iMessage)= 0;

    /** Bridge for CATDlgPushButton::SetShortHelp */
    virtual    void  ButtonWrapperSetShortHelp( const CATUnicodeString& iMessage)= 0;

     /** Bridge for CATDlgPushButton::SetLongHelp */
    virtual    void  ButtonWrapperSetLongHelp( const CATUnicodeString& iMessage)= 0;

     /** Bridge for CATDlgPushButton::SetLongHelpId */
    virtual    void  ButtonWrapperSetLongHelpId(const CATUnicodeString& longHelpId)= 0;

	  /** Bridge to CATDlgPushButton::SetSensitivity */
     virtual void ButtonWrapperSetSensitivity( CATULong iState) = 0;

    /** Bridge for CATDlgPushButton::SetAcceleratorString */
    virtual    void  ButtonWrapperSetAcceleratorString( const CATUnicodeString& iKey )= 0;

    	/** Bridge for xxxButton::SetButtonFather */
	 virtual void ButtonWrapperSetFather(CATCommand * iParent) = 0;

      /** Bridge to get the wrapped button */
    virtual    CATCommand *  ButtonWrapperGetWrappedButton()= 0;


  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

#endif