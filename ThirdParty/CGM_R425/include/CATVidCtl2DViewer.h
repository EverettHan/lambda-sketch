// COPYRIGHT Dassault Systemes 2011
//===================================================================
//  Oct 2011  Creation: jov
//===================================================================
#ifndef CATVidCtl2DViewer_H
#define CATVidCtl2DViewer_H

#include <CATVisImmersivePanel.h>
#include <CATVidCtlViewerBase.h>
#include <CATVidInformation.h>
#include <CATVisRepresentationRole.h>
#include <CATVisInvalidationToken.h>
#include <CATMotionEvent.h>
#include <CAT2DViewpoint.h>
#include <CATSYPDeclareEnumFactory.h>

class CATViewer;
class CATVidCtlDlgContainer;
class CATVidGPSquare;
class CATIndicator;
class CATRep;
class CATViewpoint;
class CAT2DViewer;
/**
 * This component is a 2D specialization of the CATVidCtlViewerBase.
 */
class ExportedByCATVisImmersivePanel CATVidCtl2DViewer: public CATVidCtlViewerBase
{
  CATDeclareClass;
public:
  /**
   * Default constructor. 
   */
  CATVidCtl2DViewer();

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
  *   When window is resized, the viewpoint does not changes. The same image is seen but streched.
  * @see CAT2DViewpoint
  */
  enum ViewpointZoomType {  
    MillimeterScreenBased,	
    HalfWindowHeightBased,
    HalfWindowWidthAndHeigthBased };

  /**
  * Anchor types. 
  * <br><b>Role</b>:The anchor type gives the location in the window
  * where the origin is projected. When zooming, this point will stay
  * invariant.
  */
  enum ViewpointAnchor { UpLeft=0, Up, UpRight,
    Left, Center, Right,
    DownLeft, Down, DownRight };

  /**
   * Static method allowing to create a %CATVidCtl2DViewer.
   * @param i_pParent the CATCommand parent, used to send events.
   * @param i_pIdentifier the name of the widget.
   * @returns the created %CATVidCtl2DViewer
   */
  static CATVidCtl2DViewer* Create2DViewer(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
  * Static method allowing to create a %CATVidCtl2DViewer.
  * @param i_pParent the CATCommand parent, used to send events.
  * @param i_pIdentifier the name of the widget.
  * @returns the created %CATVidCtl2DViewer
  */
  static CATVidCtl2DViewer* Create2DViewer(CATCommand *i_pParent, const CATString & i_pIdentifier, CAT2DViewer* i_pViewer);

  /**
  * Sets the ViewpointAnchor type. 
  * @param iAnchor 
  *   Usually <tt>Center</tt> or <tt>UpLeft</tt> 
  */
  void SetViewpointAnchor ( const ViewpointAnchor iAnchor);

  /**
  * Gets the Anchor type. 
  */
  ViewpointAnchor GetViewpointAnchor() const;

  /** 
  * Gets the zoom type. 
  */
  virtual ViewpointZoomType GetViewpointZoomType() const;

  /**
  * Sets the zoom type.
  * @param iZoomType 
  * The zoom type
  */
  virtual void SetViewpointZoomType( const ViewpointZoomType iZoomType);

  static CATVidCtl2DViewer::ViewpointAnchor GetViewpointAnchor( const CAT2DViewpoint::Anchor iAnchor);
  static CAT2DViewpoint::Anchor GetViewpointAnchor(const ViewpointAnchor iAnchor);

  static CATVidCtl2DViewer::ViewpointZoomType GetViewpointZoomType( const CATViewpointZoomType iZoomType);
  static CATViewpointZoomType GetViewpointZoomType(const ViewpointZoomType iZoomType);

  /**
   * Sets the zoom on the viewpoint.
   * @param i_zoom...
   */
  void SetZoom( float i_zoom);
  /**
   * @return the zoom of the viewpoint
   */
  float GetZoom() const;
  /**
   * Sets the orgin of the 2D viewpoint
   * @param i_2DOrigin the wished new origin.
   */
  void Set2DOrigin( const CATMathPoint2Df& i_2DOrigin);
  /**
   * @return the origin of the viewpoint
   */
  CATMathPoint2Df Get2DOrigin() const;
  /**
   * Computes model point from a given pixel point.
   * @param i_x the x pixel value.
   * @param i_y the y pixel value
   * @return the corresponding 2D floating point in model referential.
   */
  CATMathPoint2Df ComputeModelFromPixel(int i_x, int i_y);
  /**
   * Sets the viewport regarding the zoom limitations.
   */
  void SetViewport(const CATMathPoint2Df& i_firstPoint, const CATMathPoint2Df& i_secondPoint); 
  /**
   * @return the viewport defined by two points.
   */
  void GetViewport(CATMathPoint2Df& o_firstPoint, CATMathPoint2Df& o_secondPoint);
  /**
   * Computes pixel point from a given 2D model point.
   * @param i_x the x model point value.
   * @param i_y the y model point value
   * @param i_z the z model point value
   * @return the corresponding 2D floating point in view referential.
   */
  CATMathPoint2Df ComputePixelFromModel(float i_x, float i_y, float i_z = 0.f);
protected:
  /** Destructor */
  virtual ~CATVidCtl2DViewer ();
  /** @copydoc CATVidCtlViewerBase#ReactOnViewpointModified*/
  virtual void ReactOnViewpointModified();
public:
  void SetHiddenViewer(CAT2DViewer* i_pViewer);
};

CATSYP_DECLARE_ENUMFACTORY (ExportedByCATVisImmersivePanel, CATVidCtl2DViewer__ViewpointAnchor);
CATSYP_DECLARE_ENUMFACTORY (ExportedByCATVisImmersivePanel, CATVidCtl2DViewer__ViewpointZoomType);
//-----------------------------------------------------------------------
#endif

