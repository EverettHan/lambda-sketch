// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATCAfrAdapterCAfrComponentController
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Fev 2011  Creation                                                   T. Pech
//=============================================================================
#ifndef CATCAfrAdapterCAfrComponentController_H
#define CATCAfrAdapterCAfrComponentController_H

#include "CATAfrFoundation.h"
#include "CATCommand.h"
#include "CATString.h"
#include "CATActivate.h"
#include "CATPreactivate.h"
#include "CATMultiSel.h"
#include "CATContext.h"
#include "CATBaseUnknown_WR.h"

class CATCAfrComponentControllerArg;
class CATDlgContextualMenu;
class CATDeviceEvent;
class CATViewer;
class CATFrmEditor;
class CATNotification;
class CATSO;
class CATSysWeakRef;
class CATPathElement;
class CATCmdContainer;
class CATMarshal;

//-----------------------------------------------------------------------------
class ExportedByCATAfrFoundation CATCAfrAdapterCAfrComponentController: public CATCommand
{
  public:
    CATCAfrAdapterCAfrComponentController( CATCommand * ipParent = NULL, 
                                           const CATBoolean& iEditor = FALSE, 
                                           CATFrmEditor* ipEditor = NULL, 
                                           const CATBoolean& iCSOCB = FALSE, 
                                           const CATBoolean& ibMenu = FALSE );
    virtual ~CATCAfrAdapterCAfrComponentController ();

    virtual HRESULT ComponentAction( CATCAfrComponentControllerArg* ipControllerArg );

  protected:

    // CEF Management
    virtual HRESULT ComponentActionOnDisplayMenu( CATCAfrComponentControllerArg* ipControllerArg );
    enum CAfrComponentControllerBehavior {  NoBehavior = 0,
                                            ContextMenuFromCef  };

    void SetCAfrControllerBehavior(const CAfrComponentControllerBehavior iBehavior);
    CAfrComponentControllerBehavior GetCAfrControllerBehavior() const;

    void SetCAfrCefComponentName(const CATUnicodeString & iName);
    CATUnicodeString GetCAfrCefComponentName() const;

    virtual CATViewer* GetViewer();
    virtual CATBaseUnknown_var GetAppObject( CATBaseUnknown_var ispBase );
    virtual void OnContext( CATBaseUnknown_var ispNode );
    virtual void OnActivate( CATBaseUnknown_var ispNode );
    virtual void OnMoveOver( CATBaseUnknown_var ispNode );
    virtual void OnSelect( CATBaseUnknown_var ispNode );
    virtual HRESULT AddCSOMulti( );
    virtual CATPathElement* CreateObjectPath( CATBaseUnknown_var ispElement );
    virtual CATBaseUnknown_var GetCurrentObject();
    virtual void OnSO( CATCallbackEvent, void* ipPublisher, CATNotification* ipNotif, 
                       CATSubscriberData iData, CATCallback );
    virtual void* SendCommandSpecificObject( const char* ipObjectClassNeeded,
                                             CATNotification* ipNotification);
    virtual int IsSelected( CATBaseUnknown_var ispNode );
    virtual void NotifToSelector( );
    virtual void NotifRightClickToSelector( );
    virtual HRESULT DisplayContextualMenu( CATCmdContainer* ipCmdContainer );
    virtual int IsSelectedWithoutCSO( CATBaseUnknown_var ispNode );
    virtual void GetSelectedElements( CATLISTV(CATBaseUnknown_var)& oListNodes );
    virtual void NotifMultiToSelector( );

    CATSO* GetMultiSelSO( );
    CATFrmEditor* GetFrmEditor( );
    CATDlgContextualMenu* GetMenu( );
    CATDeviceEvent* GetDeviceEvent( );
    CATCmdContainer* GetCmdContainer( );
    HRESULT DisplayContextualMenuFromCef( const CATUnicodeString & iMessage );

    void OnEditorActivate( CATCallbackEvent iCBEvt, void* ipPublisher, 
                           CATNotification* ipNotif, CATSubscriberData iData, 
                           CATCallback iCB );
    void DeleteCtxMenu( );

    CATSysWeakRef*                 _pMultiSelSO;
    CATActivate                    _Activate;
    CATPreactivate                 _Preactivate;
    CATMultiSel                    _MultiSel;
    CATBoolean                     _bEditor;
    CATBaseUnknown_WR              _spCurrent;
    CATBoolean                     _bMenu;
    CATContext                     _Context;
    CATCallback                    _CBCSO;
    CATCallback                    _EditorActivateCB;
    CATCallback                    _EditorDeactivateCB;
    CATSysWeakRef*                 _pEditor;
    CATSysWeakRef*                 _pContainer;

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATCAfrAdapterCAfrComponentController (CATCAfrAdapterCAfrComponentController &);
    CATCAfrAdapterCAfrComponentController& operator=(CATCAfrAdapterCAfrComponentController&);

    void OnEditorDeactivate( CATCallbackEvent iCBEvt, void* ipPublisher, 
                             CATNotification* ipNotif, CATSubscriberData iData, 
                             CATCallback iCB );

    // From CATCommand: called on ODT record and replay.
    int SaveState(CATNotification*, CATMarshal&);
    int RestoreState(CATNotification*, CATMarshal&);

    void PauseReplay();
    void ResumeReplay();

    CAfrComponentControllerBehavior _behavior;
    CATUnicodeString                _CefComponentName;
    bool                            _replayPaused;
};
#endif
