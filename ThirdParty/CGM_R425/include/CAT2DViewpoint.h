#ifndef CAT2DViewpoint_H
#define CAT2DViewpoint_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

#include "SGInfra.h"
#include "CATViewpoint.h"
#include "CATMathPoint2Df.h"
#include "CATMathPointf.h"
#include "CAT3x3Matrix.h"
#include "CAT2DBoundingBox.h"
#include "CAT2DBagRep.h"

#include "CATBoolean.h"

class CATIndicator;
class CATVisFilter;
class CATVisRepTypeFilter;
class CAT2DBagRep;

//enum ViewpointZoomType {  
//  MillimeterScreenBased,	
//  HalfWindowHeightBased,
//  HalfWindowWidthAndHeigthBased };

/** 
* Type of zoom for 2D Viewpoint. 
* <br>The zoom type gives the reference of the zoom
* and (consequently) the behaviour of the display at the
* resize of the window
* @param  MillimeterScreenBased		
*  For usual 2D viewpoint.
*  <br>The zoom is based on the millimeter. 
*   With this style, a model distance of L will take L*zoom millimeter on screen.
* @param  HalfWindowHeightBased		
*  For 2D viewpoint over conic 3D viewpoint.
*  <br>The zoom is based on the half height of the window.
*   With this style, a model distance of L will take L*zoom*(half height of the window) millimeter 
*   on screen.
* @param  HalfWindowWidthAndHeigthBased 
*  For overview or non-isometric viewpoint.
*  <br>	The zoom is based on the half height (resp width).
*   of the window in vertical (resp. horizontal) direction. Projection is not isometric.
*   When window is resized, the viewpoint does not changes. The same image is seen but stretched.
* @see CAT2DViewpoint
*/
enum CATViewpointZoomType {  
  MillimeterScreenBased,	
  HalfWindowHeightBased,
  HalfWindowWidthAndHeigthBased };

/** @nodoc */
typedef CATViewpointZoomType ViewpointZoomType;

/** 
* Class that represents the way the 2D scene is seen.
* <b>Role</b>:
* A 2D viewpoint describes a list of 2D representations of a scene 
* seen by an observer position (point-of-view) through a 
* viewer's graphic window.
*/
class ExportedBySGInfra CAT2DViewpoint : public CATViewpoint
{
  //------------------------------------------------------------------------------
  CATDeclareClass;

  friend class CSISceneBinder;

public :

  /**
  * Retrieves whether viewpoint is a three dimensional one or not. 
  * @return
  * The value is always <tt>FALSE</tt>.
  */
  virtual CATBoolean Is3D();

  /**
  * Anchor types. 
  * <br><b>Role</b>:The anchor type gives the location in the window
  * where the origin is projected. When zooming, this point will stay
  * invariant.
  */
  enum Anchor { UpLeft=5, Up=4, UpRight=6,
    Left=1, Center=0, Right=2,
    DownLeft=9, Down=8, DownRight=10 };

  /**
  * Creates a non-initialized viewpoint. 
  * <br><b>Role</b>:At the first display (when the viewer will appear)
  * a reframe will automatically been done on the viewpoint.
  */
  CAT2DViewpoint();                      

  /**
  * Creates a new viewpoint by copying geometrical values.
  * <ul>
  * <li>Eye position and orientation (Origin, Zoom, ZoomType)
  * <li>Dynamic behaviour (Anchor, Bounds)
  * </ul>
  */
  CAT2DViewpoint( const CAT2DViewpoint &iViewpoint);

  /**
  * Creates a new viewpoint with main characteristics.
  * @param iEye Position of the Eye
  * @param iZoom Zoom factor)
  */
  CAT2DViewpoint( const CATMathPoint2Df &iEye, const float iZoom=1.);

  virtual ~CAT2DViewpoint ();

  /**
  * Gets the origin.
  * @return The eye position.
  */
  CATMathPoint2Df GetOrigin() const;

  /** 
  * Sets the origin.
  * @param iEye The eye posision
  */
  virtual void SetOrigin( const CATMathPoint2Df &iEye);

  /**
  * Sets the Anchor type. 
  * @param iAnchor 
  *   Usually <tt>Center</tt> or <tt>UpLeft</tt> 
  */
  void SetAnchor ( const Anchor iAnchor);

  /**
  * Gets the Anchor type. 
  */
  Anchor GetAnchor();

  /** 
  * Gets the zoom type. 
  */
  virtual CATViewpointZoomType GetZoomType() const;


  /**
  * Sets the zoom type.
  * @param iZoomType 
  * The zoom type
  */
  virtual void SetZoomType( const CATViewpointZoomType iZoomType);

  /**
  * Sets the zoom value.
  * @param iZoom 
  * Value meaning depends of the zoom type.
  */
  void SetZoom( const float &iZoom);

  /** @nodoc */
  //int IsEmpty() const;


  /**
  * Copies the geometric definition of a CAT2DViewpoint.
  */
  CAT2DViewpoint & operator = ( const CAT2DViewpoint &iViewpoint);

  /**
  * Applies a geometric transformation to the viewpoint.
  * That transformation is defined by the CAT3x3matrix
  */
  CAT2DViewpoint & operator *= ( const CAT3x3Matrix &iMatrix);

  /** 
  *Gets the limits between which the viewpoint can move.
  */
  virtual int GetTranslationBounds( float &XMinModel, float &XMaxModel, float &YMinModel, float &YMaxModel) const;

  /** 
  * Sets the limits between which the viewpoint can move.
  */
  virtual void SetTranslationBounds( const float XMinModel=-1.e+10, const float XMaxModel=1.e+10, 
    const float YMinModel=-1.e+10, const float YMaxModel=1.e+10);

  /** @nodoc */
  const CAT3x3Matrix &GetMatrix() const ;
  /** @nodoc */
  const CAT3x3Matrix &GetInverseMatrix();

  /** @nodoc */
  virtual CATViewpoint *Clone() const;
  /** @nodoc */
  virtual CATViewpoint *FullClone();
  /** @nodoc */
  virtual CATViewpoint *Clone(CATViewpoint **) const;
  /** @nodoc */
  inline virtual const CAT2DBagRep* GetBag() const;
  /** @nodoc */
  inline virtual const CAT2DBagRep* GetBagFurtive() const;
  /** @nodoc */
  inline virtual const CAT2DBagRep* GetBagOnTop() const;
  /** @nodoc */
  inline virtual const CAT2DBagRep* GetBagPrehighlight() const;

  /**
  * Reframes the model in the window.
  * @param XMinModel        Leftmost coordinate to be seen
  * @param XMaxModel        Rightmost coordinate to be seen
  * @param YMinModel        Bottommost coordinate to be seen
  * @param YMaxModel        Topmost corrrdinate to be seen
  * @param width            Wight of the window (in pixel)
  * @param height           Height of the window (in pixel)
  * @param mmInSupportUnit  Inverse of the size(height) of a pixel in millimeter
  * @param ratioWH          Ratio Height of a pixel / Width of a pixel
  */
  virtual void ReframeOn( const float &XMinModel, const float &XMaxModel, 
    const float &YMinModel, const float &YMaxModel,
    const float &width, const float &height, 
    const float &mmInSupportUnit, const float &ratioWH);
  /**
  * Reframes the model in the window.
  * @param iWidth Wight of the window (in pixel)
  * @param iHeight Height of the window (in pixel)
  * @param mmInSupportUnit Inverse of the size(height) of a pixel in millimeter
  * @param ratioWH Ratio Height of a pixel / Width of a pixel
  */
  virtual void Reframe ( const float width, const float height, const float mmInSupportUnit, const float ratioWH);

  /** @nodoc */
  virtual void CreateViewportFrom (const float x, const float y, const float deltaX, const float deltaY, const float supportWidth, const float supportHeight, const float mmInSupportUnit, const float ratioWH);
  /** @nodoc */
  virtual void CreateViewport (const float supportWidth, const float supportHeight, const float mmInSupportUnit, const float ratioWH);
  /** @nodoc */
  void CreateClippedViewport (const CATMathPoint2Df &bottomLeft, const CATMathPoint2Df &topRight, unsigned int iClipMode=1);
  /** @nodoc */
  int GetClippedViewport (CATMathPoint2Df &bottomLeft, CATMathPoint2Df &topRight); 
  /** @nodoc */
  void ResetClippedViewport ();

  /**
  * Sets the Depth mode. 
  * @param iDepthMode The Depth mode
  *   <br><b> Legal values</b>:<ul>
  *   <li><tt>1</tt> the draw priority is the same as the selection priority</li>
  *   <li><tt>0</tt> otherwise (default value)</li>.</ul>
  * The priority of each element attached to the viewpoint is retrieval
  * with the @href CATGraphicAttributeSet#GetPriority method.
  */
  void SetDepth(const int iDepthMode);
  /**
  * Gets the Depth mode.
  * @return The Depth mode.
  */
  int GetDepth() const;

  /**
  *  Computes the point laying under a given pixel position.
  *  @param x               Position in X of the point
  *  @param y               Position in Y of the point
  *  @param neard           Nearest point in the viewpoint under the given position
  *  @param fard            farest point in the viewpoint under the given position
  *  @param width           Width in pixels of the window
  *  @param height          Height in pixels of the window
  *  @param mmInSupportunit Inverse of the size(height) of a pixel in millimeter
  *  @param ratioWH         Ratio Height of a pixel / Width of a pixel
  *
  * The neard and fard CATMathPointf are 3D point. Ignore the z coordinate.
  */
  virtual void ComputeModelFromPixel(const float x, const float y, CATMathPointf &neard, CATMathPointf &fard, const float width, const float height, const float mmInSupportUnit, const float ratioWH);

  /** @nodoc */
  virtual void ComputeModelFromPixel(const float x, const float y, CATMathPoint &neard, CATMathPoint &fard, const float width, const float height, const float mmInSupportUnit, const float ratioWH);

  /** @nodoc */
  virtual void ComputePixelFromModel(const CATMathPointf &pt_model, CATMathPoint2Df &pt_pixel, const float width, const float height, const float mmInSupportUnit, const float ratioWH);

  /** @nodoc */
  void ComputePixelFromModel( const float iXModel, const float iYModel, float &oXPixel, float &oYPixel, 
    const float &width, const float &height, const float &mmInSupportUnit, const float &ratioWH);
  /**
  *  Computes the point laying under a given pixel position.
  *  @param iXPixel               Position in X of the point
  *  @param iYPixel               Position in Y of the point
  *  @param oXModel           X coordinate of the model point nder the given position
  *  @param oYModel           Y coordinate of the model point nder the given position
  *  @param width           Width in pixels of the window
  *  @param height          Height in pixels of the window
  *  @param mmInSupportunit Inverse of the size(height) of a pixel in millimeter
  *  @param ratioWH         Ratio Height of a pixel / Width of a pixel
  */
  void ComputeModelFromPixel( const float iXPixel, const float iYPixel, float &oXModel, float &oYModel, 
    const float &width, const float &height, const float &mmInSupportUnit, const float &ratioWH);

  /** @nodoc */
  virtual float GetScaleFactor(const float width, const float height, const float mmInSupportUnit, const float ratioWH);

  /** @nodoc */
  inline int IsMain2DViewpoint ();
  /** @nodoc */
  inline void SetMain2DViewpoint(const int IsMain);

  /**
  * Adds a representation in the scene the observator may seen.
  * @param iRep 
  *   Representation 2D
  */
  void AddRep ( CAT2DRep *iRep);

  /** @nodoc */
  void AddRepForHighlight ( CAT2DRep *iRep );
  /** @nodoc */
  void AddHighlightBag ();

  /** @nodoc */
  void EndAddRepsForHighlight ();

  /**
  * Removes the representation from the furtive list.
  * @param iRep Representation 2D
  */
  void RemoveRep ( CAT2DRep *iRep);
  /** @nodoc */
  void RemoveReps ( CAT2DRep *iRep);
  /** @nodoc */
  void RemoveRepFromHighlight ( CAT2DRep *iRep );
  /** @nodoc */
  void RemoveHighlightBag ();
  /** @nodoc */
  void EndRemoveReps ();

  /** @nodoc */
  void EndRemoveRepsFromHighlight ();
  /**
  * Adds a furtive representation in the scene the observator may seen.
  * <p> Pixels of Furtive representations may not be in the expected color but can
  * be displayed and hidden without re-drawind the whole scene. Must be used for 
  * temporary displays
  * @param iRep Representation 2D
  */
  void AddFurtiveRep ( CAT2DRep *iRep);

  /**
  * Removes the representation from the furtive list.
  * @param iRep Representation 2D
  */
  void RemoveFurtiveRep ( CAT2DRep *iRep);

  /** @nodoc */
  void RemoveFurtiveReps ( CAT2DRep *iRep);
  /** @nodoc */
  void EndRemoveFurtiveReps ();

  /**
  * @nodoc 
  * Adds a representation in the scene the observator may seen.
  * <p> Pixels of representations can
  * be displayed and hidden without re-drawind the whole scene. Must be used for 
  * temporary displays
  * @param iRep Representation 3D
  */
  void AddOnTopRep ( CAT2DRep *iRep );

  /**
  * @nodoc 
  * Removes the representation from the onTop list.
  * @param iRep Representation 3D
  */
  void RemoveOnTopRep ( CAT2DRep *iRep );
  /** @nodoc */
  void RemoveOnTopReps ( CAT2DRep *iRep );

  /**
  * @nodoc 
  * Adds a prehighlight representation in the scene the observator may seen.
  * <p> Pixels of prehighlight representations may not be in the expected color but can
  * be displayed and hidden without re-drawind the whole scene. Must be used for 
  * temporary displays
  * @param iRep Representation 2D
  */
  void AddPrehighlightRep ( CAT2DRep *iRep);

  /**
  * @nodoc 
  * Removes the representation from the prehighlight list.
  * @param iRep Representation 2D
  */
  void RemovePrehighlightRep ( CAT2DRep *iRep);

  /** @nodoc */
  void RemovePrehighlightReps ( CAT2DRep *iRep);
  /** @nodoc */
  void EndRemovePRehighlightReps ();

  /** @nodoc */	
  void EmptyHighlightBag();

  /** @nodoc */
  CAT2DBoundingBox GetBoundingBox();

  /** @nodoc */
  virtual int SizeOf();

  /** @nodoc */
  void AttachIndicator(CATIndicator* indicator);

  /** @nodoc */
  CATPooledDisplayList* GetPooledDisplayList();

  /** @nodoc */
  CATDLPool*  GetDisplayListPool();

  /**
  * @nodoc
  * @see CATIVisRootNode#AddRep
  */
  virtual HRESULT AddRep (CATRep& i_rep, CATVisRepresentationRole i_repType);
  /**
  * @nodoc
  * @see CATIVisRootNode#RemoveRep
  */
  virtual HRESULT RemoveRep (CATRep& i_rep, CATVisRepresentationRole i_repType, int i_updateFlag=TRUE);
  /**
  * @nodoc
  * @see CATIVisRootNode#ComputeBoundingElement
  */
  virtual HRESULT ComputeBoundingElement (CATVisRepresentationRole i_repType=AllRoles);
  /**
  * @nodoc
  * @see CATIVisRootNode#RemoveAll
  */
  HRESULT RemoveAll (CATVisRepresentationRole i_repType);
  /**
  * @nodoc
  * @see CATIVisRootNode#Is3D
  */
  int Is3D()const;
  /** @nodoc */
  HRESULT AddRepTypeFilter(CATVisRepTypeFilter* iFilter); 
  /** @nodoc */
  HRESULT RemoveRepTypeFilter(CATVisRepTypeFilter* iFilter);
  /** @nodoc */
  inline const ::list<CATVisFilter>* GetVisFilters() const {return & _visfilters;}
  /** @nodoc */
  inline void SetVisFiltersApplyFlag(bool flag) { _bVisFiltersApplyFlag = flag;}
  /** @nodoc */
  inline bool GetVisFiltersApplyFlag() { return _bVisFiltersApplyFlag;}

  //=========================================================================================  
public:

  /** @nodoc */
  CATDeclareCBEvent(VIEWPOINT2D_DESTROYED); //Event sent when the viewpoint is destroyed.

  //------------------------------------------------------------------------------
protected:

  /** @nodoc */
  CATMathPoint2Df _origin;
  /** @nodoc */
  CATMathPoint2Df  _bottomLeft2D;
  /** @nodoc */
  CATMathPoint2Df   _topRight2D;
  /** @nodoc */
  CATMathPointf _bottomLeft;
  /** @nodoc */
  CATMathPointf _topRight;

  /** @nodoc */
  float _XMinimumBound;
  /** @nodoc */
  float _XMaximumBound;
  /** @nodoc */
  float _YMinimumBound;
  /** @nodoc */
  float _YMaximumBound;
  /** @nodoc */
  int _AreTranslationBoundsDefined;
  /** @nodoc */
  int _clip;
  /** @nodoc */
  int _depth;
  /** @nodoc */
  CATViewpointZoomType _ZoomType;
  /** @nodoc */
  float _VerticalToHorizontalZoomRatio;
  /** @nodoc */
  Anchor _Anchor; /** @win64 fbq : 64-bit structure padding **/
  // Main viewpoint
  /** @nodoc*/
  int _IsMain;
  /** @nodoc */
  CAT3x3Matrix	_matrix;
  CAT3x3Matrix _invert;	// matrice de transformation.

  /** @nodoc */
  CAT2DBagRep* _Bag;
  /** @nodoc */
  CAT2DBagRep* _BagFurtive;
  /** @nodoc */
  CAT2DBagRep* _BagOnTop;
  /** @nodoc */
  CAT2DBagRep* _BagPrehighlight;
  /** @nodoc */
  CAT2DBagRep* _EnglobingHighlightBag;
  /** @nodoc */
  ::list<CATVisFilter> _visfilters;
  /** @nodoc */
  bool _bVisFiltersApplyFlag;
};

/** @nodoc */
inline int CAT2DViewpoint::IsMain2DViewpoint ()
{
  return (_IsMain);
}

/** @nodoc */
inline void CAT2DViewpoint::SetMain2DViewpoint(const int IsMain)
{
  _IsMain = IsMain;
}

/** @nodoc */
inline const CAT2DBagRep* CAT2DViewpoint::GetBag() const
{
  return (_Bag);
}

/** @nodoc */
inline const CAT2DBagRep* CAT2DViewpoint::GetBagFurtive() const
{
  return (_BagFurtive);
}

/** @nodoc */
inline const CAT2DBagRep* CAT2DViewpoint::GetBagOnTop() const
{
  return (_BagOnTop);
}

/** @nodoc */
inline const CAT2DBagRep* CAT2DViewpoint::GetBagPrehighlight() const
{
  return (_BagPrehighlight);
}

#endif

