// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATAdapterAfrThumbnail
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Fev 2011  Creation                                                   T. Pech
//=============================================================================
#ifndef CATAdapterAfrThumbnail_H
#define CATAdapterAfrThumbnail_H

#include "CATAfrItf.h"
#include "CATIAfrListItem.h"
#include "CATUnicodeString.h"

class CATPixelImage;

//-----------------------------------------------------------------------------
class ExportedByCATAfrItf CATAdapterAfrThumbnail: public CATIAfrListItem
{
  public:
    CATAdapterAfrThumbnail ();
    virtual ~CATAdapterAfrThumbnail ();

    virtual void SetDisplay( const CATUnicodeString& iTitle );
    virtual const CATUnicodeString GetDisplay( ) const ;
    virtual void SetThumbnail( const CATUnicodeString& iIcon );
    virtual const CATUnicodeString GetThumbnail( )const;
    virtual CATBaseUnknown* GetThumbPixelImage( );
    virtual void SetThumbPixelImage( CATBaseUnknown* ipPixel );
    virtual void SetIcon( const CATUnicodeString& iIcon );
    virtual const CATUnicodeString GetIcon( )const;
    virtual CATBaseUnknown* GetIconPixelImage( );
    virtual void SetIconPixelImage( CATBaseUnknown* ipPixel );

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATAdapterAfrThumbnail (CATAdapterAfrThumbnail &);
    CATAdapterAfrThumbnail& operator=(CATAdapterAfrThumbnail&);

};
#endif
