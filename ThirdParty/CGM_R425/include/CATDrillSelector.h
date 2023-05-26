#ifndef CATDrillSelector_H
#define CATDrillSelector_H

#include "CATCommand.h"
#include "CATVisController.h"
#include "CATGraphicAttributeSet.h"
#include "CATDialog.h"
#include "list.h"
#include "SortedList.h"

#include "CATDataType.h"
#include "CATBoolean.h"
#include "CATKeybdEvent.h"

// COPYRIGHT DASSAULT SYSTEMES 2003

class CATUnicodeString;
class CATViewer;
class CATIndicator;
class CAT3DIndicator;
class CAT2DCustomRep;
class CAT2DMarkerGP;
class CAT2DArcCircleGP;
class CAT2DPolygonGP;
class CATGraphicPrimitive;
class CATPathElement;
class CAT2DLineGP;
class CAT2DAnnotationTextGP;
class CATPathViewer;
class CATHSO;
class CATPSO;
class CAT2DRep;
class CATPickPath;
class CATRep;
class CAT2DViewpoint;
class CAT2DBagRep;
class CATNotification;
class CATVisProtocolUIDrillPanels;
class CAT2DImagePixelGP;


class ExportedByCATVisController CATDrillSelector : public CATCommand
{
 public:
   CATDrillSelector (CATViewer* viewer, int iFilteredDrill = 0);
  ~CATDrillSelector ( void);
  void Destroy ( void);

  void CreateDrillSelector(void);
  void StopDrillSelector(void);

  HRESULT OnMouseMove       ( CATNotification* n,CATViewer * iViewer);
  HRESULT OnMouseButtonDown ( int button,CATViewer * iViewer);
  HRESULT OnMouseButtonUp   ( int button,CATViewer * iViewer);
  HRESULT OnMouseManipulate(CATNotification* n,CATViewer * iViewer);
  void OnKeyboardKeyDown ( CATKeyCode Key, CATModifier i_modifier = CATNone);
  void OnKeyboardKeyUp   ( CATKeyCode Key, CATModifier i_modifier = CATNone);

  int OnContextualEvent(CATCommand *c, CATNotification *n, CATCommandClientData d);

  CATUnicodeString * GetNumberForStatusBar();
  void SetPickPathList(list<CATPickPath> *listpp);

 protected:
  int HasA3DViewer();
  CAT2DViewpoint* GetOverlayViewpoint();
  void AddRepOverlay(CAT2DRep* rep);
  void RemoveRepOverlay(CAT2DRep* rep);

  enum DrillStyle {Deep, Shallow, Left, Right, Select, BeginContext, EndContext, Abort, NoDrill};

  void GetTextPixelDimension(CATUnicodeString *i_pString, float& o_textWidth, float& o_textHeight, int& o_fontIndex);

  void CreateSelector ( void);
  void CreateDrillPanel();
  void DrillPanelDestroyed (/*CATCommand *command, CATNotification *notification, CATCommandClientData data */);
  void QuickDraw();

  virtual void DrillSelection    (DrillStyle style);
  virtual void SemanticSelection (DrillStyle style);

  void HighlightArrows (CATGraphicPrimitive* highlightGP);
  void HighlightDrillList(CATRep* iDrillRepToHighlight);

  void Drill (DrillStyle mode);
  void Blink (CATGraphicPrimitive* gp);
  
  CATGraphicPrimitive* PickGP ( int  pos[2]);

  void UpdateAndOrderDisplay(unsigned int i_quickDrawFlag);
  void RemoveAllRepOverlay();

 private:

   // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDrillSelector ();
  CATDrillSelector (const CATDrillSelector &);
  CATDrillSelector & operator= (const CATDrillSelector &);


  void AuxiliaryViewerClosed (CATCommand *command, CATNotification *notification, CATCommandClientData data );
  void CloseDrillSelector ( void);
  void UpdateUpDownArrows();
  void UpdateRightLeftArrows();
  void CreateDrillList();
  void DestroyDrillList();
  CATUnicodeString * PathElementToText(CATPathElement * iPathElement, int index, int totalNbr);
  void PositionDrillList(int iStart, int iEnd, int iCreation=0);
  void ActualizeIndexDrill(CATINTPTR iIndexRef, CATINTPTR iIndex);
  void CreateRectangleRep(float iBottomLeft[2],float iTopRight[2]);
  void CreateSlider(float iBottomLeft[2],float iTopRight[2]);
  //iMousePositionY is the Y position that the elevator has to reach.
  void TranslateSlider(float iMousePositionY);
  void UpdateDrillListDisplay(float iYPosSlider);
  int MouseHasMovedEnough(int iCurrentMousePosition[2]);
 
  void AddDrillListRep(CAT2DRep * iRep);
  void RemoveDrillListRep(CAT2DRep * iRep);

  //index that references the position of the last seen item in the DrillList.
  int _lastIndexpp;
  //index indicating the last current position of the elevator.
  float _lastSliderPositionY;
  //Scrolling length of elevator.
  float _sizeSlider;
  //Top starting point of the elevator.
  float _startPointSliderY;
  

  //index that references the position of the highlighted item in the DrillList.
  int _highlightedIndex;
  //index that references the number associated to the item we are currently preselecting.
  int _statusBarIndex;
  CATUnicodeString  * _statusBarNumber;

  CAT2DCustomRep    * _pArrowsAndPlusSignRep;
  CAT2DArcCircleGP  * _pSelectGP;
  CAT2DPolygonGP    * _pUpArrowGP, *_pDownArrowGP, *_pLeftArrowGP, *_pRightArrowGP;
  CAT2DArcCircleGP  * _pSelectOutGP;
  CAT2DLineGP       * _pUpOutGP, *_pDownOutGP, *_pLeftOutGP, *_pRightOutGP;
  CAT2DImagePixelGP * _filteredGP;
   

  CAT2DCustomRep    * _pSliderRep;
  CAT2DPolygonGP    * _upSlider, *_downSlider,*_squareSlider;
  CAT2DLineGP       * _upSliderOut, *_downSliderOut,*_squareSliderOut;

  CATViewer         * _pViewer;
  int                _tOrigin[2];//where the mouse is placed when the DrillSelection starts
  float              _tPadCenter[2];
  float              _tOriginGraph[2];
  float              _tLastMousePosition[2];

  int _depthCursor;
  int _numberOfPickPath;

  CATGraphicAttributeSet _GAS;
  CATGraphicAttributeSet _hiGAS;
  CATGraphicAttributeSet _outGAS;
  CATGraphicAttributeSet _bgGAS;
  CATGraphicPrimitive*   _pPreselectedGP;

  // etat de l'affichage des GP
  unsigned int _stateSelect;
  unsigned int _stateUp;
  unsigned int _stateDown;
  unsigned int _stateRight;
  unsigned int _stateLeft;

  int _isBeingScrolled;
  enum DrillState {ContextOff, ContextOn};
  DrillState _contextualState;

  CATDialog::CATDlgCursor previousCursor_;
  
  CAT2DBagRep * _pDrillList;
  CATVisProtocolUIDrillPanels * _pDrillPanel;
  
  list<CATRep> _listGraphRepElements;//Toutes les reps du graphe visualisees a l'ecran
  list<CATUnicodeString> _listOfTitles;//Toutes les reps du graphe visualisees a l'ecran
  /* A partir de la rep highlightee dans le graphe on en deduit l'indice du picking.
  La cle est la rep du graphe, on en deduit un pickPath*/
  SortedList _tableDrillRep;
  /* A partir de l'indice de picking dans le viewer on en deduit la rep a highlighter dans le graphe
  La cle est le pickPath, on en deduit une rep.*/
  SortedList _tableDrillPickPath;

  const list<CATPickPath> *_pPickPathList;
  
  int _minXtoAbort, _maxXtoAbort,_minYtoAbort, _maxYtoAbort;
  CATPathViewer* _pPathViewer;
  float _roundViewerRadius;//la taille en pixel du rayon de la loupe
  CAT2DBagRep * _pGraphRectangleRep;
    
  int _mode;
  int _isA3DViewer;

  CAT2DViewpoint* _pDrillOverlayViewpoint;
  void 	CreateOverlay();
  void DestroyOverlay();

  int _graphMargin;
  float _textLineSpacement;

  unsigned int _semanticSelection : 1;
  unsigned int _filteredDrill : 1;
  unsigned int _padding : 30;
  CATBoolean _showTooltipFlag;
  int _graphWidth;
  int _replayPathListPointer;
};

#endif
