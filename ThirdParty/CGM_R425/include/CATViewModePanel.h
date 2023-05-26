#ifndef CATViewModePanel_H
#define CATViewModePanel_H

//
// COPYRIGHT DASSAULT SYSTEMES 2004
//       
#include "CATDlgInclude.h"
#include "CATVisPanel.h"
#include <map>

class CATViewer;
class CATString;

class ExportedByCATVisPanel CATViewModePanel : public CATDlgDialog 
{
  DeclareResource(CATViewModePanel, CATDlgDialog)

public:
  CATViewModePanel(CATDialog* i_pParent, CATViewer* i_pViewer);
  virtual ~CATViewModePanel();
  
  void SetVisibility(CATULong state);
  void Close();  
  
  friend class CATRepViewModeFilterPanel;
  
private: 
  CATViewer          * _pViewer;
  
  CATDlgFrame        * _pMainFrame;
  CATDlgFrame        * _pOptionFrame;

  //Edges
  CATDlgCheckButton  * _pEdgeBtn;
  CATDlgRadioButton  * _pAllEdgesRadioBtn;
  CATDlgRadioButton  * _pWithoutSmoothEdgesRadioBtn;
  CATDlgRadioButton  * _pWithoutSmallCurvatureEdgesRadioBtn;
  CATDlgRadioButton  * _pHalfLightedSmoothEdgesRadioBtn;
  CATDlgCheckButton  * _pColoredEdgesFromFaces;
  CATDlgCheckButton  * _pOutlineBtn;
  CATDlgCheckButton  * _pLineOnLineBtn;
  CATDlgCheckButton  * _pIsoparBtn;
  CATDlgCheckButton  * _pWithoutWiresBtn;
  CATDlgCheckButton  * _pWithoutAxisBtn;
  CATDlgCheckButton  * _pWithoutPointBtn;
  
  //Points
  CATDlgRadioButton  * _pAllPointsRadioBtn;
  CATDlgRadioButton  * _pWithoutVerticesRadioBtn;

  //Mesh
  CATDlgCheckButton  * _pShadingOnOffBtn;
  CATDlgRadioButton  * _pGouraudRadioBtn;
  CATDlgRadioButton  * _pMaterialRadioBtn;
  CATDlgRadioButton  * _pPolygonRadioBtn;
  CATDlgRadioButton  * _pTransparentRadioBtn;
  CATDlgCheckButton  * _pHiddenEdgeBtn;
  CATDlgCheckButton  * _pHRDBtn;
  CATDlgCheckButton  * _pRayTracingOnOffBtn;

  //Options
  CATDlgCheckButton  * _pObjectViewModeBtn;

  int                _savedViewMode;
  short              _panelCreatedFlag;

  std::map<int, CATDlgControl *> _ViewModeBtnMap;
protected:   

  // Recuperation du viewer
  virtual CATViewer* GetViewer() const;
  // Recuperation du ViewMode par defaut
  virtual int    GetViewMode();

  void CreatePanel();
  void BuildInterface();
  void UpdatePanel(int viewMode=0);
  void UpdateViewer();

  // Callbacks
  void OkCB                 (CATCommand *, CATNotification *, CATCommandClientData) ;
  virtual void OkCBAction   (CATNotification *); // appelee par OKCB

  void CloseCB              (CATCommand *, CATNotification *, CATCommandClientData) ;
  virtual void CloseCBAction(CATNotification *); // appelee par CloseCB

  void CheckButtonCB (CATCommand *, CATNotification *, CATCommandClientData) ;

};
#endif
