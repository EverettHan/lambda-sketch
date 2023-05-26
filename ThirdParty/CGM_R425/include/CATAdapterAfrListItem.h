// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATAdapterAfrListItem
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Fev 2011  Creation                                                   T. Pech
//=============================================================================
#ifndef CATAdapterAfrListItem_H
#define CATAdapterAfrListItem_H

#include "CATAfrItf.h"
#include "CATIAfrListItem.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATAfrColor.h"

class CATBaseUnknown;
class CATAfrColor;
class CATICAfrComponentElement;
class CATIAfrListItem;
class CATSYPEventArgs;
class CATCAfrComponentControllerArg;
class CATSysWeakRef;

//-----------------------------------------------------------------------------
class ExportedByCATAfrItf CATAdapterAfrListItem: public CATIAfrListItem
{
  CATDeclareClass;

  public:
    CATAdapterAfrListItem ();
    virtual ~CATAdapterAfrListItem ();

    virtual CATBaseUnknown_var& GetDataModel();
    virtual void SetDataModel( CATBaseUnknown_var ispDataModel );

    virtual HRESULT GetCAfrItem( CATICAfrComponentElement** opiCAfrItem );
    virtual HRESULT SetCAfrItem( CATICAfrComponentElement* ipiCAfrItem );

    virtual CATBaseUnknown* GetDelegateObject( );

    virtual void SetDisplay( const CATUnicodeString& iDisplay );
    virtual const CATUnicodeString GetDisplay( ) const;

    virtual void SetTooltip(const CATUnicodeString & i_tooltip);
    virtual const CATUnicodeString GetTooltip( ) const;

    virtual void SetIcon( const CATUnicodeString& iIcon );
    virtual const CATUnicodeString GetIcon( )const;

    virtual CATBaseUnknown* GetIconPixelImage( );
    virtual void SetIconPixelImage( CATBaseUnknown* ipPixel );

    virtual void SetThumbnail( const CATUnicodeString& iIcon );
    virtual const CATUnicodeString GetThumbnail( )const;

    virtual void SetThumbPixelImage( CATBaseUnknown* ipPixel );
    virtual CATBaseUnknown* GetThumbPixelImage( );

    virtual void SetThumbDisplay( CATBaseUnknown* ipPixel );
    virtual CATBaseUnknown* GetThumbDisplay( );

    virtual void SetTileIcon( const CATUnicodeString& iIcon );
    virtual const CATUnicodeString GetTileIcon( )const;

    virtual void SetDescription( const CATUnicodeString& iDescription );
    virtual const CATUnicodeString GetDescription( )const;

    virtual void SetTileInfo( const CATUnicodeString& iTileInfo );
    virtual const CATUnicodeString GetTileInfo( )const;

    virtual CATBaseUnknown* GetTilePixelImage( );
    virtual void SetTilePixelImage( CATBaseUnknown* ipPixel );

    virtual CATBaseUnknown* GetRep3D();
    virtual void SetRep3D( CATBaseUnknown* ipRep );

    virtual CATBaseUnknown_var& GetCamera();
    virtual void SetCamera( CATBaseUnknown_var ispCamera );

    virtual void SetShadingColor(const CATAfrColor& i_color);
    virtual const CATAfrColor GetShadingColor() const;

    virtual const int & GetSelectedFlag() const;
    virtual void SetSelectedFlag(const int & i_selectedFlag);

    virtual const CATBoolean & GetPreSelectedFlag() const;
    virtual void SetPreSelectedFlag(const CATBoolean &i_preSelectedFlag); 

    virtual const CATBoolean GetEditorFlag( ) const;
    virtual void SetEditorFlag (const CATBoolean& iEditorFlag);
    virtual const CATBoolean GetReadOnlyFlag( ) const;
    virtual void SetReadOnlyFlag (const CATBoolean& iReadOnlyFlag);
    virtual const int& GetThumbnailContour( ) const;
    virtual void SetThumbnailContour (const int& iThumbnailContour);
    virtual const int& GetActivateTextFlag() const;
    virtual void SetActivateTextFlag( const int& i_ActivateTextFlag );
    virtual const CATBoolean GetThumbnailFlag( ) const ;
    virtual void SetThumbnailFlag (const CATBoolean& ThumbnailFlag);
    virtual const CATBoolean GetIconTypeFlag( ) const ;
    virtual void SetIconTypeFlag (const CATBoolean& iIconTypeFlag);
    virtual const CATBoolean GetLoaderFlag( ) const ;
    virtual void SetLoaderFlag( const CATBoolean& iLoaderFlag );
    virtual const CATBoolean GetUIActivateFlag( ) const ;
    virtual void SetUIActivateFlag( const CATBoolean& iUIActivateFlag );

    virtual void HandleItemEvent(CATBaseUnknown* i_input, CATSYPEventArgs * i_pArgs);

    virtual void Clean( );

  protected:

    virtual void DispatchTextEditorEditingFinished( CATSYPEventArgs * i_pArgs, 
                                                    CATCAfrComponentControllerArg* iopControllerArg );

    HRESULT GetCATIAfrListItem( CATIAfrListItem** opiAfrListItem );

    CATUnicodeString          _Display;
    CATUnicodeString          _Tooltip;
    CATUnicodeString          _Icon;
    CATUnicodeString          _Thumbnail;
    CATUnicodeString          _Tile;
    CATUnicodeString          _Description;
    CATUnicodeString          _TileInfo;
    CATBaseUnknown*           _pThumbPixelImage;
    CATBaseUnknown*           _pThumbDisplay;
    CATBaseUnknown*           _pIconPixelImage;
    CATBaseUnknown*           _pTilePixelImage;
    CATBaseUnknown*           _pRep3D;
    CATBaseUnknown_var        _sp3DCamera;
    CATAfrColor               _ShadingColor;
    CATBaseUnknown_var        _spDataModel;
    int                       _SelectedFlag;
    CATBoolean                _PreSelectedFlag;
    CATBoolean                _EditorFlag;
    CATBoolean                _ReadOnlyFlag;
    int                       _ThumbnailContour;
    int                       _ActivateTextFlag;
    CATBoolean                _ThumbnailFlag;
    CATBoolean                _IconTypeFlag;
    CATBoolean                _LoaderFlag;
    CATBoolean                _UIActivateFlag;

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATAdapterAfrListItem (CATAdapterAfrListItem &);
    CATAdapterAfrListItem& operator=(CATAdapterAfrListItem&);

    void FoundThumbnailContour( );

    CATSysWeakRef*             _piAfrComponentElement;

};
#endif
