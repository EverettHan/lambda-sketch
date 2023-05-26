
#ifndef CATIAfrLabel_H
#define CATIAfrLabel_H

// COPYRIGHT DASSAULT SYSTEMES 2011/02/07

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"

class CATMathPointf;
class CATPathElement;
class CATPixelImage;
class CATVidWidget;
class CATMathPoint2Df;

enum CATAfrLabelType
{
  CATAfrLabelText          = 0, 
  CATAfrLabelTextLink      = 1, 
  CATAfrLabelEditor        = 2, 
  CATAfrLabelCombo         = 3
};

extern ExportedByCATAfrItf  IID IID_CATIAfrLabel ;
//-----------------------------------------------------------------------------
/**
* Interface managing Label.
* The object implemented this interface must derive from the AfrInterfaces\ProtectedInterfaces\CATIAfrLabel.h
*
*/
class ExportedByCATAfrItf CATIAfrLabel: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Get title
    * Introspectable method
    **/
    virtual const CATUnicodeString & GetTitle() const = 0;

    /**
    * Get icon title
    * Introspectable method
    **/
    virtual const CATUnicodeString& GetTitleIcon() const = 0;

    /**
    * Get anchor point 3D position
   * Introspectable method
   **/
    virtual const CATMathPointf& GetAnchorPoint() const = 0;

    /**
    * Get the target anchor point 2D position
   * Introspectable method
   **/
    virtual const CATMathPoint2Df& GetOffsetPoint() const = 0;

    /**
    * Get title
    **/
    virtual HRESULT GetTitle( CATUnicodeString& oTitle ) = 0;

    /**
    * Get icon title
    **/
    virtual HRESULT GetTitleIcon( CATPixelImage** opIcon ) = 0;

    /**
    * Get icon title
    **/
    virtual HRESULT GetTitleIcon( CATUnicodeString& oIcon ) = 0;

    /**
    * Sets anchor point 3D position
    * Introspectable method
    **/
    virtual void SetAnchorPoint(const CATMathPointf &i_point) = 0;

    /**
    * Sets the target anchor point 2D position
    * Introspectable method
    **/
    virtual void SetOffsetPoint(const CATMathPoint2Df &i_offsetPoint) = 0;

    /**
    * Sets title
    * Introspectable method
    **/
    virtual void SetTitle( const CATUnicodeString& iTitle ) = 0;

    /**
    * Sets Icon title
    * Introspectable method
    **/
    virtual void SetTitleIcon( const CATUnicodeString& TitleIcon ) = 0;


    /**
    * List of property.
    *   @param oProperties and oListOfNls
    *     Must have the same size.
    **/
    virtual HRESULT GetProperties( CATListOfCATString& oProperties, 
                                   CATListOfCATUnicodeString& oListOfNls ) = 0;

    /**
    * List of Group.
    *   @param oListTilte, oListExpanded, oProperties and oListOfNls
    *     Must have the same size.
    **/
    virtual HRESULT GetGroupProperties( CATListOfCATUnicodeString& oListTilte, 
                                        CATListOfInt& oListExpanded, 
                                        CATListOfCATString*& opProperties, 
                                        CATListOfCATUnicodeString*& opListOfNls ) = 0;

    /**
    * Label data access. Returns the label for property 'iProperty'.
    **/
    virtual HRESULT GetLabel( const CATString& iProperty, CATUnicodeString& oLabel ) = 0;

    /**
    * Icon data access. Returns the icon for property 'iProperty'.
    **/
    virtual HRESULT GetIcon( const CATString& iProperty, CATPixelImage** opIcon ) = 0;

    /**
    * Style data access. Returns the style for property 'iProperty'.
    **/
    virtual HRESULT GetStyle( const CATString& iProperty, CATAfrLabelType& oStyle ) = 0;

    /**
    * Get anchor point 3D position
    **/
    virtual HRESULT GetAnchor( CATMathPointf& oAnchor ) = 0;

    /**
    * Get the target anchor point 2D position
    **/
    virtual HRESULT GetTargetPoint( CATMathPoint2Df& oPoint ) = 0;

    /**
    * Get path element of object
    **/
    virtual HRESULT GetPath( CATPathElement** opPath ) = 0;

    /**
    * Icon data access. Returns the icon for property 'iProperty'.
    **/
    virtual HRESULT GetIconCommand( const CATString& iProperty, CATPixelImage** opIcon ) = 0;

    /**
    * Launch command.
    *   @param iPropertyID
    *     Attribute identificator
    */
    virtual HRESULT LaunchCommand( const CATString& iPropertyID ) = 0;

    /**
    * Retrieves the editable status for CATAfrLabelEditor style.
    *   @param iColumnID column value.
    */
    virtual HRESULT IsEditableValue( const CATString &iColumnID ) = 0;

    /**
    * Sets the label for CATAfrLabelEditor style.
    *   @param iColumnID column value.
    *   @param iValue Label value.
    */
    virtual HRESULT SetLabel( const CATString &iColumnID, const CATUnicodeString& iValue ) = 0;

    /**
    * Widget data access. Returns the extended custo Widget.
    **/
    virtual HRESULT GetWidget( CATVidWidget** ipVidWidget ) = 0;
};
#endif
