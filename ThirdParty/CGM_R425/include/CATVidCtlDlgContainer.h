#ifndef CATVidCtlDlgContainer_H
#define CATVidCtlDlgContainer_H

// COPYRIGHT Dassault Systemes 2006

#include <VisuDialog.h>
#include <CATVidModelWidget.h>
#include <CATVidEnum.h>
#include <CATSYPHashMap.h>
#include <CATBoolean.h>

#include "CATSysWeakRef.h"

class CATVizViewer;
class CATVidModelWidget;
class CATDlgDialog;
class CATDlgFrame;
class CATVidRectangle;
class CATVidFraWindow;

class CATDlgDrawingArea;

class ExportedByVisuDialog CATVidCtlDlgContainer : public CATVidModelWidget
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  CATVidCtlDlgContainer (CATCommand *i_pParent, const CATString & i_pIdentifier, int i_useDlgDrawingArea=0);

  virtual void Update();

  void SetEmbededDialog(CATDialog* i_pEmbededDialog);
  CATDialog* GetEmbededDialog() const;

  void SetUpdateWhenUnvisibleFlag(CATBoolean i_updateWhenUnvisibleFlag);
  CATBoolean GetUpdateWhenUnvisibleFlag() const;

  void SetNeverShowDialogFlag(int i_neverShowDialogFlag);
  int GetNeverShowDialogFlag() const;

  /**
   * Returns TRUE if the given bounding rectangle is overlapping one of the existing visible CATVidCtlDlgContainer, FALSE otherwise.
   * The coordinates of the bounding rectangle must be absolute (i.e relative to the screen) in pixels (px).
   * The given window allows to filter the CATVidCtlDlgContainer that belongs to this window.
   */
  static CATBoolean IsBoundingRectOverlapping(const CATVidRectangle& i_absoluteBoundingRect, CATVidFraWindow * i_pWindow);

  /**
   * Returns TRUE if the given window is overlapping one of the existing visible CATVidCtlDlgContainer, FALSE otherwise.
   */
  static CATBoolean IsWindowOverlapping(CATVidFraWindow * i_pWindow);

  // Virtual from CATVidWidget
  virtual void TunnelInformation(const CATVidInformation& i_information);

protected:
  virtual ~CATVidCtlDlgContainer ();
  void HandledWidgetDeletedCB(CATCallbackEvent, void*, CATNotification* i_pNotification, CATSubscriberData , CATCallback OnHandledWidgetModify);

private:
  // Copy constructor and equal operator
  CATVidCtlDlgContainer (CATVidCtlDlgContainer &);
  CATVidCtlDlgContainer& operator=(CATVidCtlDlgContainer& original);

  void CreateDialogBox(CATDialog * i_pParentDialog);
  void DestroyDialogBox();
  void UpdateDimension();
  void UpdatePosition();
  void UpdateClipping();
  void ReparentDialog();
  void UpdateVisibility();
  void DialogBoxDeletedCB(CATCallbackEvent i_callBackEvent, void *i_pVoid, CATNotification *i_pNotif, CATSubscriberData i_data, CATCallback i_callback);
  void WindowActivatedCB(CATCallbackEvent i_callBackEvent, void *i_pVoid, CATNotification *i_pNotif, CATSubscriberData i_data, CATCallback i_callback);
  void WindowCreatedCB(CATCommand *, CATNotification *, CATCommandClientData);
  void HostFrameActivatedCB(CATCommand *, CATNotification *, CATCommandClientData);

  CATCallback _handledWidgetDeletedCB;

  CATDialog* _pEmbededDialog;
  CATDialog* _pDialogBox;
  CATCallback _dialogBoxCB;
  CATBoolean _updateWhenUnvisibleFlag;
  int _neverShowDialogFlag;

  static CATSYPHashMap<CATVidCtlDlgContainer *, CATVidCtlDlgContainer *, CATSYPHashMapPointerHasher> s_dlgContainerMap;

  // + CATDlgDrawingArea
  int _useDlgDrawingArea;
  void ManageHostFrame();
  void OnHostFrameDestroyed(CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
  CATSysWeakRef * _pEmbededDialogWR;
  CATDlgDrawingArea * _pDlgDrawingArea;
  CATDlgFrame * _pHostFrame;
  CATCallback _cbHostFrameDestroyed;
  CATBoolean _hostFrameDestroyed;
  // - CATDlgDrawingArea

#ifdef _WINDOWS_SOURCE
  HRGN _clipRgn;
#endif
};

#endif
