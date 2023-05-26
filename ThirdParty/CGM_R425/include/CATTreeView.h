// COPYRIGHT Dassault Systemes 2004
#ifndef CATTreeView_H
#define CATTreeView_H

#include <CATDynHashTable.h>
#include <CATGraphicAttributeSet.h>
#include <CATITreeViewModel.h>
#include <CATScrollableView.h>
#include <CATSysSimpleHashTable.h>
#include <CATTreeViewLine.h>
#include <CATView.h>

class CATPixelImage;
class CATPathElement;

#define CATTreeViewNoDragScroll 0x0004
#define CATTreeViewNoArcs       0x0008
#define CATTreeViewCompact      0x0010
#define CATTreeViewHideRoot     0x0020
#define CATTreeViewNoCrop       0x0040

// SCA : Added CATTreeViewDynamicCrop style, maquette pour DassaultAviation
#define CATTreeViewDynamicCrop  0x0080

// SCA : Added CATTreeViewHighlighted style, maquette pour DassaultAviation
#define CATTreeViewHighlighted  0x0100

/**
 * OBSOLETE class. Replaced by the Component C-Afr Tree.
 * See sample in http://codewiki/codewiki/index.php/C-Afr_Tree_Component#CATTreeView_.2F_C-AfrTree
 * DEPRECATED DO NOT USE
 * CATTreeView - The Tree View display object.
 * To use with an implementation of CATITreeViewModel for link to model
 * and CATITreeViewController for link to controller.
 **/
class ExportedByCATView CATTreeView: public CATScrollableView
{
  CATDeclareClass;
  friend class CATBasicViewController;

  // SCA : Added CATTreeViewDynamicCrop style, maquette pour DassaultAviation
  friend class CATViewBase;
public:
  /**
   * Constructor
   * Available styles:
   *   - CATTreeViewLeftScroll: display vertical scroll bar on left (default)
   *   - CATTreeViewRightScroll: display vertical scroll bar on right
   *   - CATTreeViewNoDragScroll: disable scrolling on arc drag
   **/
  CATTreeView( CATCommand *iFather, const CATString &iName, int iStyle= CATLeftScroll );
  /**
   * Destructor
   **/
  virtual ~CATTreeView( void );
  /**
   * Get root node
   **/
  CATPathElement *GetRoot(void);
  /**
   * Set root node
   **/
  void SetRoot( CATPathElement *iRoot );
  /**
   * Is a node Expanded ?
   **/
  int IsExpanded( CATBaseUnknown *iNode );
  /**
   * Expand a node
   **/
  void Expand( CATBaseUnknown *iNode );
  /**
   * Collapse a node
   **/
  void Collapse( CATBaseUnknown *iNode );
  /**
  * Collapse a branch starting from a node
  **/
  void CollapseBranch( CATBaseUnknown *iNode );
  /**
   * Collapse all nodes
   **/
  void CollapseAll(void);
  /**
   * Get tooltip
   **/
  CATUnicodeString GetTooltip(void);
  /**
   * Center Graph
   **/
  HRESULT MakeVisibleGraph( CATBaseUnknown* ipNode );

protected:

  /**
   * Create path element to node under the mouse
   **/
  CATPathElement *CreateObjectPath( CATBaseUnknown_var iObject );
  /*
   * Callbacks
   */
  virtual void OnClick( float iX, float iY );
  virtual void OnRepeatClick( float iX, float iY );
  virtual void OnDoubleClick( float iX, float iY );
  virtual void OnDrag( float iOriginX, float iOriginY, float iDX, float iDY, int iStart );
  virtual void OnAfterResized( void );
  virtual void OnScroll( void );
  virtual void OnScrollStart(void);
  virtual void OnScrollStop(void);
  /**
   * Draw arcs
   **/
  void DrawArcs(void);
  /**
   * Draw node text box
   **/
  virtual void DrawNodeText( int iLine, int iRedraw );
  /**
   * Normal paint
   **/
  virtual void Paint( void );
  /**
   * Pick paint (simplified)
   **/
  virtual void PaintForPick( void );
  /**
   * Highlight paint
   **/
  virtual void PaintForHighlight( void );
  /**
   * Recursive update service
   **/
  virtual void Update(int &ioLine, int iIndent, float &ioWidth, const CATBaseUnknown_var &iNode,
                      const CATITreeViewModel_var &iModel);
  /**
   * Update service, compute CATTreeViewLine strctures before paint
   **/
  virtual void UpdateState(void);
  /**
   * Clean CATTreeViewLine structures... an update will occure before next paint
   **/
  virtual void CleanupState(void);
  /**
   * Compute dimensions from style and text size
   **/
  virtual void UpdateDimensions(void);
  /**
   * Compute colors from style and viewer
   **/
  virtual void UpdateColors(void);
  /**
   * Analyse cursor position
   **/
  HRESULT AnalysePosition( float iX, float iY,
    CATBaseUnknown_var &oObject );
  HRESULT AnalysePosition( float iX, float iY,
    CATBaseUnknown_var &oObject, int &oInExpander, int &oInArc );
  /**
   * Get the parent node of a node
   **/
  CATBaseUnknown_var GetParent( CATBaseUnknown_var iObject );
  enum Decoration
  {
    Icon= 1,
    Expander= 2,
    ArcLeft= 3,
    ArcBottom= 4,
    ArcRight= 5
  };

  /**
   * Get position from line number
   **/
  virtual void GetPosition( int iLine, float &oX, float &oY, Decoration iDeco );
  /**
   * Get position from line number and indentation level
   **/
  virtual void GetPosition( int iLine, int iIndent, float &oX, float &oY, Decoration iDeco );
  /*
   * Visible lines
   */
  CATListOfCATTreeViewLine _lines;
  /*
   * We are limited to maximum 1024 depth level
   */
  int _nbrootarcs;
  CATBaseUnknown_var _rootparent[1024];
  int _rootarcs[1024];

  CATPathElement *_root;
  CATDynHashTable _expanded;
  float _lastscrollx, _lastscrolly;
  float _zoom;
  float _lastTextSize;
  CATPixelImage *_minus, *_plus, *_partial;
  unsigned int _lastIconColors;
  float _lastIconSize;
  int _computeVHeight;
  
  class Dimensions
  {
    public:
      float _line;
      float _text;
      float _textheight;
      float _expander;
      int _crop;
      float _zoom;
      float _touchFactor;
  };
  Dimensions _margins;

  class Colors
  {
    public:
      CATGraphicAttributeSet _back;
      CATGraphicAttributeSet _text;
      CATGraphicAttributeSet _arcs;
      CATGraphicAttributeSet _arcs2;
      CATGraphicAttributeSet _high;
      CATGraphicAttributeSet _mask;
      CATGraphicAttributeSet _active;
  };
  Colors _colors;
  /**
   * Record integration
   **/
  HRESULT Replay( const char *iEvent, CATBaseUnknown_var iObject );
  CATUnicodeString GetRecordId( CATBaseUnknown_var iRecordObject );
  CATBaseUnknown_var GetReplayObject( const CATUnicodeString &iReplayId );
  static CATUnicodeString PathElement2String( const CATIViewModel_var &iModel, CATPathElement *iPE );
  static CATPathElement *String2PathElement( const CATIViewModel_var &iModel, CATPathElement *iRoot, const CATUnicodeString &iName );
  /**
   * Tree Settings integration
   **/
  void OnSettings( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
  CATCallback _settingscb;
  /**
   * Create colorized expand icons
   **/
  CATPixelImage *BuildIcon( const CATUnicodeString &iName );
  /**
   * Children cache management
   **/
  void SetChildrenCache( int iMode );
  CATListOfCATBaseUnknown_var _childrenCache;
  CATSysSimpleHashTable _childrenCacheIndex;

  class ChildrenCacheIndex
  {
    public:
      CATBaseUnknown *_node;
      int _childrenoffset;
      int _childrencount;
  };

  int _childrenCacheActive;
  int _lastHeight;
  static unsigned int HashChildrenIndex( void * iObj );
  static int CompareChildrenIndex( void * iObj1, void * iObj2 );

  HRESULT GetIndexInTree(int &ioIdx, const CATBaseUnknown_var &ispBUStartingNode, const CATBaseUnknown_var &ispBUSearchedNode, int &ioFound, int &ioNbLines);
  int ExpandBranch(const CATBaseUnknown_var &ispBUStartingNode, const CATBaseUnknown_var &ispBULeafNode);

  public:
    virtual HRESULT OnDeviceAction( CATNotification* ipNotification, unsigned int& oReturn );
    virtual void SetViewer(CATVizViewer *iViewer);

  protected:
    void OnDevice( CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback);
    CATCallback _deviceCB;

  public:
    virtual void OnMoveOver( float iX, float iY );
    virtual void OnLeave( void );
    void ChangeDrillSelection( const int& ibFlag );
};

#endif
