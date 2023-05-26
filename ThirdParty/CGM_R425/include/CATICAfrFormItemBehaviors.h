#ifndef CATICAfrFormItemBehaviors_H
#define CATICAfrFormItemBehaviors_H

// COPYRIGHT Dassault Systemes 2014/04/04

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATUnicodeString;
class CATMathPoint2Df;

extern ExportedByCATAfrItf  IID IID_CATICAfrFormItemBehaviors ;

//-----------------------------------------------------------------------------
/**
* Interface managed CAfrForm item behaviors.
**/
class ExportedByCATAfrItf CATICAfrFormItemBehaviors: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Sets the UndefinedFlag, the default value is FALSE
    */
    virtual HRESULT SetUndefinedFlag( const CATUnicodeString& iPropName, const CATBoolean& ibFlag ) = 0;

    /**
    * Sets the EnableFlag, the default value is TRUE
    */
    virtual HRESULT SetEnableFlag( const CATUnicodeString& iPropName, const CATBoolean& ibFlag ) = 0;

    /**
    * Sets the VisibleFlag, the default value is TRUE
    */
    virtual HRESULT SetVisibleFlag( const CATUnicodeString& iPropName, const CATBoolean& ibFlag ) = 0;

    /**
    * Sets the LayoutWhenUnvisibleFlag, the default value is TRUE
    */
    virtual HRESULT SetLayoutWhenUnvisibleFlag( const CATUnicodeString& iPropName, const CATBoolean& ibFlag ) = 0;

    /**
    * Sets the ColumnWeight, the default value is 2
    */
    virtual HRESULT SetColumnWeight( const CATUnicodeString& iPropName, const int& iWeight ) = 0;

    /**
    * Sets the Tweaker ClassName to defined the attribut
    * User can define his tweak class
    * Or set CATAfrCtlTweakerTextEditor to have a Tex Editor
    * CATAfrCtlTweakerText to have a WordWrap text.
    */
    virtual HRESULT SetTweakClassName( const CATUnicodeString& iPropName, const CATUnicodeString& iTweakClassName ) = 0;

    /**
    * Sets the Tweaker minimum dimension
    */
    virtual HRESULT SetMinimumDimension( const CATUnicodeString& iPropName, const CATMathPoint2Df& iDimension ) = 0;

    /**
    * Sets the creation of the label, the default value is TRUE. The label is the text before the property.
    */
    virtual HRESULT SetLabelFlag( const CATUnicodeString& iPropName, const CATBoolean& i_Bool ) = 0;

    /**
    * Sets the Tweaker minimum dimension of the label. The label is the text before the property.
    */
    virtual HRESULT SetMinimumDimensionOfLabel( const CATUnicodeString& iPropName, const CATMathPoint2Df& iDimension ) = 0;

    /**
    * Sets the ShortHelp of the property..
    */
    virtual HRESULT SetShortHelp( const CATUnicodeString& iPropName, const CATUnicodeString& i_ShortHelp) = 0;
	/**
	* Sets the LongHelp of the property..
	*/
	virtual HRESULT SetLongHelp(const CATUnicodeString& iPropName, const CATUnicodeString& i_LongHelp) = 0;

    /**
    * Sets the style informations of a standard control, that will allow to build the XML styled view of the control.
    */
    virtual HRESULT SetStyle( const CATUnicodeString& iPropName, const CATUnicodeString& i_TemplateName ) = 0;

    /**
    * Sets flag to fire notif , the default value is TRUE.
    */
    virtual HRESULT SetNotifUpdateFlag( const CATUnicodeString& iPropName, const CATBoolean& i_Bool ) = 0;

    /**
    * Sets Unit To Use for parameter.
    */
    virtual HRESULT SetUnitToUse( const CATUnicodeString& iPropName, const CATBaseUnknown_var& i_spUnit ) = 0;
    /**
    * Sets number of decimals  for CATVidCtlTweakerDouble.
    */
    virtual HRESULT SetDecimalPlaces(const CATUnicodeString& iPropName, const int& i_decimalPlaces) = 0;

    /**
    * Remove all behaviors
    */
    virtual HRESULT RemoveAll( ) = 0;

    /**
    * NODOC
    */
    virtual HRESULT SetUndefinedFlag( const CATUnicodeString& iPropName,  const CATBaseUnknown_var &i_spValue ) = 0;
    virtual HRESULT SetEnableFlag( const CATUnicodeString& iPropName,  const CATBaseUnknown_var &i_spValue ) = 0;
    virtual HRESULT SetVisibleFlag( const CATUnicodeString& iPropName,  const CATBaseUnknown_var &i_spValue ) = 0;
    virtual HRESULT SetColumnWeight( const CATUnicodeString& iPropName, const CATBaseUnknown_var &i_spValue ) = 0;
    virtual HRESULT SetLayoutWhenUnvisibleFlag( const CATUnicodeString& iPropName, const CATBaseUnknown_var &i_spValue ) = 0;

};
//-----------------------------------------------------------------------
CATDeclareHandler( CATICAfrFormItemBehaviors, CATBaseUnknown );

#endif
