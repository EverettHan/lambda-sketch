// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATAdapterAfrLabel
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Fev 2011  Creation                                                   T. Pech
//=============================================================================
#ifndef CATAdapterAfrLabel_H
#define CATAdapterAfrLabel_H

#include "CATAfrItf.h"
#include "CATIAfrLabel.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATMathPointf.h"
#include "CATMathPoint2Df.h"

class CATMathPointf;
class CATPathElement;
class CATPixelImage;
class CATVidWidget;
class CATMathPoint2Df;

//-----------------------------------------------------------------------------
class ExportedByCATAfrItf CATAdapterAfrLabel: public CATIAfrLabel
{
  CATDeclareClass;

  public:
    CATAdapterAfrLabel ();
    virtual ~CATAdapterAfrLabel ();

    virtual HRESULT GetTitle( CATUnicodeString& oTitle );
    virtual HRESULT GetTitleIcon( CATUnicodeString& oIcon );
    virtual HRESULT GetTitleIcon( CATPixelImage** opIcon );
    virtual HRESULT GetProperties( CATListOfCATString& oProperties, 
                                   CATListOfCATUnicodeString& oListOfNls );
    virtual HRESULT GetGroupProperties( CATListOfCATUnicodeString& oListTilte, 
                                        CATListOfInt& oListExpanded, 
                                        CATListOfCATString*& oProperties, 
                                        CATListOfCATUnicodeString*& oListOfNls );
    virtual HRESULT GetLabel( const CATString& iProperty, CATUnicodeString& oLabel );
    virtual HRESULT GetIcon( const CATString& iProperty, CATPixelImage** opIcon );
    virtual HRESULT GetStyle( const CATString& iProperty, CATAfrLabelType& oStyle );
    virtual HRESULT GetAnchor( CATMathPointf& oAnchor );
    virtual HRESULT GetTargetPoint( CATMathPoint2Df& oPoint );
    virtual HRESULT GetPath( CATPathElement** opPath );
    virtual HRESULT GetIconCommand( const CATString& iProperty, CATPixelImage** opIcon );
    virtual HRESULT LaunchCommand( const CATString& iPropertyID );
    virtual HRESULT IsEditableValue( const CATString &iColumnID );
    virtual HRESULT SetLabel( const CATString &iColumnID, const CATUnicodeString& iValue );
    virtual HRESULT GetWidget( CATVidWidget** ipVidWidget );
    virtual const CATMathPointf& GetAnchorPoint() const;
    virtual const CATMathPoint2Df& GetOffsetPoint() const;
    virtual const CATUnicodeString & GetTitle() const;
    virtual const CATUnicodeString& GetTitleIcon() const;
    virtual void SetAnchorPoint(const CATMathPointf &i_point);
    virtual void SetOffsetPoint(const CATMathPoint2Df &i_offsetPoint);
    virtual void SetTitle( const CATUnicodeString& iTitle );
    virtual void SetTitleIcon( const CATUnicodeString& TitleIcon );

  protected:
    CATMathPointf                  _AnchorPoint;
    CATMathPoint2Df                _OffsetPoint;
    CATUnicodeString               _Title;
    CATUnicodeString               _TitleIcon;

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATAdapterAfrLabel (CATAdapterAfrLabel &);
    CATAdapterAfrLabel& operator=(CATAdapterAfrLabel&);

};
#endif
