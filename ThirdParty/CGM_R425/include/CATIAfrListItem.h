
#ifndef CATIAfrListItem_H
#define CATIAfrListItem_H

// COPYRIGHT DASSAULT SYSTEMES 2012/02/07

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

class CATBaseUnknown;
class CATAfrColor;
class CATICAfrComponentElement;

extern ExportedByCATAfrItf  IID IID_CATIAfrListItem ;

//-----------------------------------------------------------------------------
/**
* Interface representing a thumbnail.
*/
class ExportedByCATAfrItf CATIAfrListItem: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * @Gets the Data model object, Data Model object is the applicative object
    */
    virtual CATBaseUnknown_var& GetDataModel() = 0;

    /**
    * @ Sets the Data Model object, Data Model object is the applicative object.
    */
    virtual void SetDataModel( CATBaseUnknown_var ispDataModel ) = 0;

    /**
    * @return the Afr item
    *  The created element [out, CATICAfrComponentElement#Addref be done]
    */
    virtual HRESULT GetCAfrItem( CATICAfrComponentElement** opiCAfrItem ) = 0;

    /**
    * @ Sets the Afr item
    */
    virtual HRESULT SetCAfrItem( CATICAfrComponentElement* ipiCAfrItem ) = 0;

    /**
    * @Gets the delegate object
    * No Addref is done
    */
    virtual CATBaseUnknown* GetDelegateObject( ) = 0;

    /**
    * @Sets the Display of the thumbnail
    */
    virtual void SetDisplay( const CATUnicodeString& iDisplay ) = 0;

    /**
    * @Gets the Display of the thumbnail
    */
    virtual const CATUnicodeString GetDisplay( ) const = 0;

    /**
    * @Sets the tooltip of the thumbnail
    */
    virtual void SetTooltip(const CATUnicodeString & i_tooltip) = 0;

    /**
    * @Sets the icon of the thumbnail
    */
    virtual void SetIcon( const CATUnicodeString& iIcon ) = 0;

    /**
    * @Gets the icon of the thumbnail
    */
    virtual const CATUnicodeString GetIcon( )const = 0;

    /**
    * @Gets the icon image.
    */
    virtual CATBaseUnknown* GetIconPixelImage( ) = 0;

    /**
    * @Sets the icon image.
    */
    virtual void SetIconPixelImage( CATBaseUnknown* ipPixel ) = 0;

    /**
    * @Sets the thumbnail image file name.
    */
    virtual void SetThumbnail( const CATUnicodeString& iIcon ) = 0;

    /**
    * @Gets the thumbnail image file name.
    */
    virtual const CATUnicodeString GetThumbnail( )const = 0;

    /**
    * @Sets the thumbnail image.
    */
    virtual void SetThumbPixelImage( CATBaseUnknown* ipPixel ) = 0;

    /**
    * @Gets the thumbnail image, ie like the ranking picture.
    */
    virtual CATBaseUnknown* GetThumbPixelImage( ) = 0;

    /**
    * @Sets the thumbnail image, , ie like the ranking picture.
    */
    virtual void SetThumbDisplay( CATBaseUnknown* ipPixel ) = 0;

    /**
    * @Gets the thumbnail image.
    */
    virtual CATBaseUnknown* GetThumbDisplay( ) = 0;
    /**
    * @Sets the tile mode image.
    */
    virtual void SetTileIcon( const CATUnicodeString& iIcon ) = 0;

    /**
    * @Gets the tile mode image.
    */
    virtual const CATUnicodeString GetTileIcon( )const = 0;

    /**
    * @Gets the Description tile
    */
    virtual void SetDescription( const CATUnicodeString& iDescription ) = 0;

    /**
    * @Gets the Description tile
    */
    virtual const CATUnicodeString GetDescription( )const = 0;

    /**
    * @Gets the info tile
    */
    virtual void SetTileInfo( const CATUnicodeString& iTileInfo ) = 0;

    /**
    * @Gets the Description tile
    */
    virtual const CATUnicodeString GetTileInfo( )const = 0;

    /**
    * @Gets the tile image.
    */
    virtual CATBaseUnknown* GetTilePixelImage( ) = 0;

    /**
    * @Sets the tile image.
    */
    virtual void SetTilePixelImage( CATBaseUnknown* ipPixel ) = 0;

    /**
    * @Gets the 3d rep thumbnail.
    */
    virtual CATBaseUnknown* GetRep3D() = 0;

    /**
    * @Sets the 3d rep thumbnail
    */
    virtual void SetRep3D( CATBaseUnknown* ipRep ) = 0;

    /**
    * @Gets the 3d Camera.
    */
    virtual CATBaseUnknown_var& GetCamera() = 0;

    /**
    * @Sets the 3d Camera
    */
    virtual void SetCamera( CATBaseUnknown_var ispCamera ) = 0;

    /**
    * Sets the shading color.
    */
    virtual void SetShadingColor(const CATAfrColor& i_color) = 0;

    /**
    * Gets the shading color.
    */
    virtual const CATAfrColor GetShadingColor() const = 0;

    /**
    * @Sets SelectedFlag
    */
    virtual void SetSelectedFlag(const int & i_selectedFlag) = 0;
    virtual void SetPreSelectedFlag(const CATBoolean &i_preSelectedFlag) = 0; 
    virtual void SetEditorFlag (const CATBoolean& iEditorFlag) = 0;
    virtual void SetReadOnlyFlag (const CATBoolean& iReadOnlyFlag) = 0;
    virtual void SetThumbnailContour (const int& iThumbnailContour) = 0;
    virtual void SetActivateTextFlag( const int& i_ActivateTextFlag ) = 0;
    virtual void SetThumbnailFlag (const CATBoolean& ThumbnailFlag) = 0;
    virtual void SetIconTypeFlag (const CATBoolean& iIconTypeFlag) = 0;
    virtual void SetLoaderFlag( const CATBoolean& iLoaderFlag ) = 0;
    virtual void SetUIActivateFlag( const CATBoolean& iUIActivateFlag ) = 0;


};
#endif
