// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
//
// CATExtIProgressTaskCusto
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Nov 2010  Creation                                                   T. Pech
//=============================================================================

#ifndef __CATExtIProgressTaskCusto_h
#define __CATExtIProgressTaskCusto_h

#include "CATAfrProgressTask.h"
#include "CATIProgressTaskCusto.h"

class CATIProgressTaskUI;
class CATString;

/**
* Default implementation base class for CATIProgressTaskCusto
* interface.
*/
//-----------------------------------------------------------------------------
class ExportedByCATAfrProgressTask CATExtIProgressTaskCusto: public CATIProgressTaskCusto
{
  CATDeclareClass;

  public:
    virtual HRESULT PerformTask    (CATIProgressTaskUI  * iUI, void * iUserData);
    virtual HRESULT GetCatalogName (CATString        * oCatalog);
    virtual HRESULT GetIcon        (CATString        * oIcon);
    virtual HRESULT GetProgressTaskMode( CATAfrProgressTaskMode& oTaskMode );
    virtual HRESULT GetTaskWindMode( CATAfrProgressTaskWindMode& oTaskMode );
    virtual HRESULT GetPanelStyle( CATAfrProgressTaskPanelStyle& oTaskMode );
    virtual HRESULT GetImmersiveInfinitePosition( CATAfrProgressTaskPosition& oPosition );
    virtual HRESULT GetInfiniteType( CATAfrProgressTaskCIDType& oType );
    virtual HRESULT OnInterrupt( );
    virtual HRESULT GetRemaining( CATBoolean& oDisplay );

  protected:
    CATExtIProgressTaskCusto ();
    virtual ~CATExtIProgressTaskCusto ();

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATExtIProgressTaskCusto (const CATExtIProgressTaskCusto &);
    CATExtIProgressTaskCusto & operator= (const CATExtIProgressTaskCusto &);
};
#endif
