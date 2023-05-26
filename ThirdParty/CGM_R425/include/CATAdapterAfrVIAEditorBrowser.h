// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATAdapterAfrVIAEditorBrowser
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Fev 2011  Creation                                                   T. Pech
//=============================================================================
#ifndef CATAdapterAfrVIAEditorBrowser_H
#define CATAdapterAfrVIAEditorBrowser_H

#include "CATAfrItf.h"
#include "CATIAfrVIAEditorBrowser.h"

//-----------------------------------------------------------------------------
class ExportedByCATAfrItf CATAdapterAfrVIAEditorBrowser: public CATIAfrVIAEditorBrowser
{
  CATDeclareClass;

  public:
    CATAdapterAfrVIAEditorBrowser ();
    virtual ~CATAdapterAfrVIAEditorBrowser ();

    virtual const CATBoolean GetExtractedFlag();
    virtual const CATBoolean GetVisibleFlag();
    virtual const CATBoolean GetMaximizeFlag();
    virtual const CATBoolean GetDockContentVisibleFlag();
    virtual const CATBoolean GetDockLeftFlag();
    virtual HRESULT UpdateComponent( );

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATAdapterAfrVIAEditorBrowser (CATAdapterAfrVIAEditorBrowser &);
    CATAdapterAfrVIAEditorBrowser& operator=(CATAdapterAfrVIAEditorBrowser&);

};
#endif
