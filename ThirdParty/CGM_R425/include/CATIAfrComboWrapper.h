// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIAfrComboWrapper.h
// Define the CATIAfrComboWrapper interface
//
//===================================================================
//
// Usage notes:
//   This interface enables to wrap a Dialog combo box or a CID combo box from an AfrFoundation CATCmdStarterRep.
//   Used for the PLM Bar.
//
//===================================================================
//
//  May 2009  Creation: Code generated by the CAA wizard  ers ld3
//===================================================================
#ifndef CATIAfrComboWrapper_H
#define CATIAfrComboWrapper_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"


#ifndef CATDlgDataAdd
#define CATDlgDataAdd    (1 << 6)
#endif
#ifndef CATDlgDataModify
#define CATDlgDataModify (1 << 7)
#endif



#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrComboWrapper;
#else
extern "C" const IID IID_CATIAfrComboWrapper ;
#endif

class CATUnicodeString;
class CATCommand;
class CATString;
class CATNotification;
class CATPixelImage;

typedef unsigned long   CATULong;

/**
  * Callback function for a xxxCombo.
  * @see  xxxCombo#SetInputCallback
  */
typedef int (*CATDlgComboCallback)(const CATUnicodeString &, void *);
//#include "CATDlgUtility.h"  On n'a pas le droit
//------------------------------------------------------------------

/**
* Interface representing the connection between xxxCombo and CATVidCtlCombo.
*
* <br><b>Role</b>: Bridge to connect xxxCombo methods to CATVidCtlCombo equivalent methods.
* <p>
* Do not implement the CATIAfrComboWrapper interface outside of @href CATAfrComboWrapper class
* Do not use the CATIAfrComboWrapper interface outside of @href CATAfrComboWrapper class
*/
class ExportedByCATAfrItf CATIAfrComboWrapper: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /** Bridge to xxxCombo constructor */
     virtual void InstanciateCombo (CATBaseUnknown *iParent, const CATString& iObjectName, CATBoolean comboEditable, CATBoolean comboIcon,int mode =0) = 0;

    /** Bridge to xxxCombo destructor */
     virtual void DestroyCombo () = 0;

    /** Bridge to xxxCombo::GetLineCount */
     virtual int ComboWrapperGetLineCount () = 0;

    /** Bridge to xxxCombo::SetLine */
     virtual int ComboWrapperSetLine (const CATUnicodeString & iLine, int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd) = 0;

    /** Bridge to xxxCombo::SetLine */
     virtual int ComboWrapperSetLine (const CATUnicodeString * iLinesArray, int iNbLines, int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd) = 0;

    /** Bridge to xxxCombo::SetLine */
     virtual int ComboWrapperSetLine (const CATUnicodeString& iVal, const CATString& iIcon, int iIndex=-1, CATULong iModeAddOrModify=CATDlgDataAdd, CATPixelImage* ipImage=NULL) = 0;

    /** Bridge to xxxCombo::GetLine */
     virtual void 	ComboWrapperGetLine (CATUnicodeString &oLine, int iIndex)=0;

    /** Bridge to xxxCombo::ClearField */
     virtual void ComboWrapperClearField () = 0;

    /** Bridge to xxxCombo::ClearLine */
     virtual void ComboWrapperClearLine () = 0;

    /** Bridge to xxxCombo::ClearLine */
     virtual void ComboWrapperClearLine (int iIndex) = 0;

    /** Bridge to xxxCombo::SetDropDownTextWidth */
     virtual void ComboWrapperSetDropDownTextWidth (int iColumns) = 0;

    /** Bridge to xxxCombo::SetSelect */
     virtual int ComboWrapperSetSelect (int iIndex, int iNotify=1) = 0;

    /** Bridge to xxxCombo::SetSelect */
     virtual int ComboWrapperSetSelect (const CATUnicodeString &iString, int iNotify=1)=0;

    /** Bridge to xxxCombo::GetSelect */
     virtual int ComboWrapperGetSelect () = 0;

    /** Bridge to xxxCombo::ClearSelect */
     virtual void ComboWrapperClearSelect () = 0;

    /** Bridge to xxxCombo::GetField */
     virtual void ComboWrapperGetField (CATUnicodeString & oEntry) = 0;

    /** Bridge to xxxCombo::SetField */
     virtual void ComboWrapperSetField (const CATUnicodeString & iEntry) = 0;

    /** Bridge to xxxCombo::SetInputCallback */
     virtual void ComboWrapperSetInputCallback (CATDlgComboCallback iCheckingFunction, void *iUsefulData) = 0;

    /** Bridge to xxxCombo::SetVisibleTextWidth */
     virtual void ComboWrapperSetVisibleTextWidth (int iColumns) = 0;

    /** Bridge to xxxCombo::SetVisibleTextHeight */
     virtual void ComboWrapperSetVisibleTextHeight (int iRows) = 0;

    /** Bridge to xxxCombo::GetVisibleTextHeight */
     virtual int ComboWrapperGetVisibleTextHeight () = 0;

	  /** Bridge to xxxCombo::SetSensitivity */
     virtual void ComboWrapperSetSensitivity( CATULong iState) = 0;

	  /** Bridge to xxxCombo::SetFather */
	   virtual void ComboWrapperSetFather(CATCommand * iParent) = 0;

    /** Bridge to xxxCombo::GetComboSelectNotification */
     virtual CATNotification * ComboWrapperGetComboSelectNotification () const = 0;

    /** Bridge to xxxCombo::GetComboModifyNotification */
     virtual CATNotification * ComboWrapperGetComboModifyNotification () const = 0;

    /** Bridge to xxxCombo::GetComboModifyExtNotification */
     virtual CATNotification * ComboWrapperGetComboModifyExtNotification () const = 0;

    /** Bridge to xxxCombo::GetComboEditModifyNotification */
     virtual CATNotification * ComboWrapperGetComboEditModifyNotification () const = 0;

    /** Bridge to xxxCombo::SetHelp */
     virtual void  ComboWrapperSetHelp( const CATUnicodeString& iMessage) = 0;

    /** Bridge to xxxCombo::SetShortHelp */
     virtual void  ComboWrapperSetShortHelp( const CATUnicodeString& iMessage) = 0;

     /** Bridge to xxxCombo::SetLongHelp */
     virtual void  ComboWrapperSetLongHelp( const CATUnicodeString& iMessage) = 0;

     /** Bridge to xxxCombo::SetLongHelpId */
     virtual void  ComboWrapperSetLongHelpId(const CATUnicodeString& longHelpId) = 0;

    /** Bridge to xxxCombo::SetAcceleratorString */
     virtual void  ComboWrapperSetAcceleratorString( const CATUnicodeString& iKey) = 0;

    /** Bridge to get the wrapped combo */
     virtual CATCommand * ComboWrapperGetWrappedCombo()= 0;

    /** Bridge to set the wrapped combo */
     virtual void ComboWrapperSetWrappedCombo (CATCommand * ipCmd)= 0;

    /** Bridge to Set the PlaceHolderText */
     virtual void ComboWrapperSetPlaceHolderText(const CATUnicodeString & itext)= 0;

    /** Bridge to Set the Focus */
     virtual void ComboWrapperSetFocus ()= 0;
  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------

CATDeclareHandler( CATIAfrComboWrapper, CATBaseUnknown );
#endif