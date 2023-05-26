// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATCAfrAdapterCAfrTreeController
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Fev 2011  Creation                                                   T. Pech
//=============================================================================
#ifndef CATCAfrAdapterCAfrTreeController_H
#define CATCAfrAdapterCAfrTreeController_H

#include "CATAfrFoundation.h"
#include "CATCAfrAdapterCAfrComponentController.h"
#include "CATString.h"

class CATCAfrComponentControllerArg;
class CATViewer;
class CATFrmEditor;
class CATNotification;
class CATSO;
class CATSysWeakRef;
class CATPathElement;

//-----------------------------------------------------------------------------
class ExportedByCATAfrFoundation CATCAfrAdapterCAfrTreeController: public CATCAfrAdapterCAfrComponentController
{
  public:
    CATCAfrAdapterCAfrTreeController( CATBaseUnknown* ipiCAfrTree, 
                                      CATCommand * ipParent = NULL, 
                                      const CATBoolean& iEditor = FALSE, 
                                      CATFrmEditor* ipEditor = NULL, 
                                      const CATBoolean& iCSOCB = FALSE, 
                                      const CATBoolean& ibMenu = FALSE );
    virtual ~CATCAfrAdapterCAfrTreeController ();

    virtual HRESULT ComponentAction( CATCAfrComponentControllerArg* ipControllerArg );
    virtual void Clean( );

  protected:
    virtual void OnExpand( CATBaseUnknown_var ispNode );
    virtual void OnCollapse( CATBaseUnknown_var ispNode );
    virtual void OnContext( CATBaseUnknown_var ispNode );
    virtual void OnActivate( CATBaseUnknown_var ispNode );
    virtual void OnMoveOver( CATBaseUnknown_var ispNode );
    virtual void OnSelect( CATBaseUnknown_var ispNode );

    virtual CATPathElement* CreateObjectPath( CATBaseUnknown_var ispElement );
    virtual CATBaseUnknown_var GetParent( CATBaseUnknown_var iObject );
    virtual CATBaseUnknown* GetCAfrTreeView( );
    virtual void GetSelectedElements( CATLISTV(CATBaseUnknown_var)& oListNodes );

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATCAfrAdapterCAfrTreeController (CATCAfrAdapterCAfrTreeController &);
    CATCAfrAdapterCAfrTreeController& operator=(CATCAfrAdapterCAfrTreeController&);

    CATSysWeakRef*             _piTreeView;

};
#endif
