#ifndef CATFRMVIEWMANAGER_H
#define CATFRMVIEWMANAGER_H
#include "CATAfrFoundation.h"
//
// COPYRIGHT DASSAULT SYSTEMES 1996
//----------------------------------------------------------------------------
// Abstract: Manager of viewpoint for the current viewer. 
//
//----------------------------------------------------------------------------
// Usage:    A CATFrmViewManager is created by the current Layout.
// 
//----------------------------------------------------------------------------
// Inheritance:  None
//----------------------------------------------------------------------------
// Main methods:    
//
//----------------------------------------------------------------------------
//       

#include "CATDlgInclude.h"
#include "CATListOfCATICamera.h"

//#include "CATFrmLayout.h"
//#include "CATFrmWindow.h"
//#include "CATDocument.h"
#include "CATSafeArray.h"
#include "CATUnicodeString.h"

class CATViewer;
class CATICamera;
class CATIAViewpoint3D;
class CATI3DCamera;
class CATIAViewpoint2D;
class CATI2DCamera;

class CATFrmLayout;
class CATFrmWindow;
class CATDocument;

class CATDlgContextualMenu;
class CATDlgPushItem;

class ExportedByCATAfrFoundation CATFrmViewManager : public CATDlgDialog 
{
   CATDeclareClass;
   DeclareResource(CATFrmViewManager, CATDlgDialog)

   public:

      //Constructor / Destructor
      CATFrmViewManager(CATDialog * parent);
      virtual ~CATFrmViewManager();

      virtual void   SetVisibility(CATULong state);
      CATICamera *   GetCurrentCamera();     
      CATViewer  *   GetCurrentViewer();
      
      int SetCurrentCamera(int number);

      int            IsStdCamera(CATICamera * camera);     

   private:
      CATFrmLayout         * _currentLayout;
      CATFrmWindow         * _currentWindow;
      CATViewer            * _currentViewer;
      CATDocument          * _currentDocument;
      CATICamera           * _currentCamera;

      CATDialog          * _parent;
      CATDlgFrame        * _mainFrame;
      CATDlgFrame        * _cmdFrame;
      CATDlgFrame        * _listFrame;
      CATDlgPushButton   * _modifyBtn;
      CATDlgPushButton   * _addBtn;
      CATDlgPushButton   * _deleteBtn;
      CATDlgPushButton   * _propertiesBtn;
      CATDlgPushButton   * _reverseBtn;
      CATDlgSelectorList * _viewList;
      CATDlgEditor       * _viewEdit;

      CATDlgContextualMenu * _ctxMenu;
      CATDlgPushItem       * _prefixItm;
      CATUnicodeString     _viewNamePrefix;
      int                  _prefixEdit;

      int                  _camType;
      int                  _viewListSize;
      int                  _selectedViewCount;
      CATUnicodeString     _selectedViewName;

      void OkCB          (CATCommand *, CATNotification *, CATCommandClientData) ;
      void CloseCB       (CATCommand *, CATNotification *, CATCommandClientData) ;
      void ApplyViewCB   (CATCommand *, CATNotification *, CATCommandClientData) ;
      void ModifyViewCB  (CATCommand *, CATNotification *, CATCommandClientData) ;
      void AddViewCB     (CATCommand *, CATNotification *, CATCommandClientData) ;
      void DeleteViewCB  (CATCommand *, CATNotification *, CATCommandClientData) ;
      void PropertiesCB  (CATCommand *, CATNotification *, CATCommandClientData) ;
      void ReverseCB     (CATCommand *, CATNotification *, CATCommandClientData) ;
      void SelectViewCB  (CATCommand *, CATNotification *, CATCommandClientData) ;
      void ActivateViewCB(CATCommand *, CATNotification *, CATCommandClientData) ;
      void EditViewCB    (CATCommand *, CATNotification *, CATCommandClientData) ;
      void EditPrefixCB  (CATCommand *, CATNotification *, CATCommandClientData) ;

      void             UpdateViewList();
      void             UpdatePanel();
      CATUnicodeString GetDefaultName();
      CATString        GetNameFromNumber(int number);
      int              IsUnicName(CATUnicodeString);

      CATLISTP(CATICamera) _cameraList;
      CATLISTP(CATICamera) _stdCameraList;
      CATLISTP(CATICamera) _sortedList;
      CATLISTP(CATICamera) & GetCameraList (int sort=1);//return the camera list

      static int CompareNames(CATICamera * camera1, CATICamera * camera2);

   // Call back
      CATCallbackManager * _callbackManager;
      void AddCB();
      void WindowCB(CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);
      void CameraCB(CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);

      // Journaling
      CATSafeArrayVariant* BuildSafeArrayVariant(const double* t, int size);
      HRESULT DumpCATIAViewpoint(CATIAViewpoint3D*, CATI3DCamera*);
      HRESULT DumpCATIAViewpoint(CATIAViewpoint2D*, CATI2DCamera*);
};
#endif
