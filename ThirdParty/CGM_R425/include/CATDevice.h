#ifndef CATDevice_H
#define CATDevice_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	Basic class of logical devices. Control the status of the device
//		and the pluged and pointed manipulators
//------------------------------------------------------------------------------
// Usage :	
//------------------------------------------------------------------------------
// Heritage :	CATDevice
//		  CATObject (DIALOG framework)
//------------------------------------------------------------------------------
#include "CATCallbackManager.h"
#include "CATVisFoundation.h"
#include "CATViewpointEditor.h"

class CATManipulator;
class CATVizViewer;
class CATGraphicWindow;
class CATDeviceEvent;
class CATViewerEvent;
class CATNotification;
class CATPickPath;
class CATPickPathList;
class CATSupport;
#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus
  struct CATDeviceExtensionStruct;
#ifdef __cplusplus
};
#endif  // __cplusplus

enum DeviceUseState { UNUSED, USED };
enum DeviceLockState { UNLOCKED, LOCKED };

class ExportedByCATVisFoundation CATDevice : public CATCallbackManager
{
  friend class CATGraphicWindow;
  CATDeclareClass;

  public:
  ///////

    CATDevice( CATVizViewer *, CATViewerEvent * );
    ~CATDevice();

   virtual int InterpretDeviceEvent( CATNotification *event, CATSubscriberData data);
    int IsControlPanelEditable() const;
    virtual void SetViewpointEditor( CATViewpointEditor *Editor);
    virtual void SetPlugedManip( CATManipulator *manip) ;
    virtual CATManipulator * GetPlugedManip() const;
    virtual void SetPointedManip( CATManipulator *Manip);
    virtual CATManipulator * GetPointedManip() const;
    virtual void SetLockState( const DeviceLockState state);
    virtual DeviceLockState IsLocked();
    virtual void SetUseState( const DeviceUseState state);
    virtual DeviceUseState IsUsed();
    virtual CATViewerEvent *GetCurrentEvent();
    virtual int MoveToNextPickPath();
    virtual void InitPickPathList();
    virtual void OnCurrentViewerChange();
    virtual CATManipulator * GetNextPreactivatedManipulator() const;
    virtual CATViewpointEditor* GetViewpointEditor () const;
    CATBoolean IsOnDialogGP( CATMathPoint2Df &iPoint, int imode, CATSupport* iPublisherSupport);

public:
    /// Get an extension.
    const void* ExtensionGet(int iId) const;

    /// Check an extension.
    bool ExtensionIsAttached(int iId);

    /// Set an extension.
    const void* ExtensionAttach(int iId, const void* ipExtension, bool iForceReplace = true);

    /// Remove an extension.
    bool ExtensionDetach(int iId, void** oppExtension = nullptr);

private:
  ////////
    // Default Constructor
    CATDevice ();
    // Copy Constructor
    CATDevice (const CATDevice &);
    // Assignment Operator
    CATDevice & operator= (const CATDevice &);

  void ViewpointEditorDestroyedCB(CATCallbackEvent, void *, CATNotification *Event, CATSubscriberData , CATCallback);

  protected:

  // compare two pick pathes
  int IsIdenticalPickPath(CATPickPath& iFirstPickPath, CATPickPath& iSecondPickPath, int& oEmptyPickPath) const;
  // compute manipulator under point
  virtual CATManipulator* ComputePointedManipulator(const CATMathPoint2Df& iPoint, CATPickPathList& oPickPathList, CATPickPath& oPickPath, CATPickPath& oPickPathUnder, int &under, CATSupport* ipSupport=NULL) const;
  // do a pick
  virtual void Pick(const CATMathPoint2Df& iPoint, CATPickPathList& oPickPathList,  CATSupport* ipSupport=NULL) const;
  //////////

    CATViewpointEditor  *_ViewpointEditor;
    CATManipulator      *_PlugedManip;
    CATManipulator      *_PointedManip;
    CATViewerEvent      *_CurrentEvent;
    CATVizViewer        *_Viewer;
    CATManipulator      *_pNextPreactivatedManipulator;

    unsigned int _IsControlPanelEditable:1;
    DeviceLockState _Lock:2;
    DeviceUseState _UseState:2;

private:
  /// Extension object (opaque structure).
  CATDeviceExtensionStruct* _pExtension;
};

#endif

