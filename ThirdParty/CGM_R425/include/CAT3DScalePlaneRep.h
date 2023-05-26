/* -*-c++-*- */
#ifndef CAT_3D_SCALE_PLANE_REP_H
#define CAT_3D_SCALE_PLANE_REP_H

// COPYRIGHT DASSAULT SYSTEMES 2000


//==============================================================================
// Inheritance
// -----------
// CAT3DScalePlaneRep
//    CAT3DBagRep
//
//==============================================================================

#include "SGInfra.h"
#include "CAT3DBagRep.h"

#include "CATMathVectorf.h"
#include "CATMathPointf.h"

class CAT3DCustomRep;
class CATRender;
class CATVizViewer;

/**
 * Class to create the graphic primitive of a 3D plan in which object placed
 * will be on a specified scale.
 * For a proper use of this function, you have to measure your physical screen
 * widths and heights and place this millimetered values in the two environment
 * variables : CATWidthMMOfScreen and CATHeightMMOfScreen.
 */

class ExportedBySGInfra CAT3DScalePlaneRep : public CAT3DBagRep
{
  CATDeclareClass;
  friend class SGInfraToVisuFConnectToolImpl;

 public :

  /**
   * Constructs a 3D plan with a width and a height expressed in millimeters. 
   * The origin of this plane will be on the viewpoint sight direction, while the 
   * direction 1 and 2 will respectively correspond to the viewpoint up and right 
   * directions.
   * <pre>
   *
   *                         -----------------------------      ^
   *                        |                             |     |
   *                        |          iDirection1        |     |     
   *                        |              ^              |     |
   *                        |              |              |     |
   *                        |              |  iDirection2 |     |
   *                        |              x --->         |     | iHeightInMM
   *                        |           iOrigin           |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                         -----------------------------      v
   *
   *                         <--------------------------->
   *                                  iWidthInMM
   *       
   *
   * </pre>
   * @param ScaleFactor
   *   This parameter is used to specify on which scale objects placed in this plane
   *   will be displayed : a ScaleFactor equal to 1 means that the object will be displayed
   *   in real measures, while a ScaleFactor of 0.5 will display it half-sized.
   * @param WidthInMillimeters
   *   Width of the plane, expressed in millimeters.
   * @param HeightInMillimeters
   *   Height of the plane, expressed in millimeters.
   * @param WidthLineSpaceinMillimeters
   *   The space between two vertical lines, expressed in millimeters.
   * @param HeightLineSpaceInMillimeters
   *   The space between two horizontal lines, expressed in millimeters.
   */  
   static CAT3DScalePlaneRep* CreateRep( const float ScaleFactor,
                      const float WidthInMillimeters,
                      const float HeightInMillimeters,
                      const float WidthLineSpaceInMillimeters,
                      const float HeightLineSpaceInMillimeters);

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DScalePlaneRep( const float ScaleFactor,
                      const float WidthInMillimeters,
                      const float HeightInMillimeters,
                      const float WidthLineSpaceInMillimeters,
                      const float HeightLineSpaceInMillimeters);

  /**
   * Destructor
   */
  virtual ~CAT3DScalePlaneRep();

public:
  /**
   * Draws the 3D plane.
   * @param render_draw
   *   The render through which the plan is drawn.
   */
  virtual void DrawShading(CATRender &render_draw, int ) override final;

  // AZX: (A2X migration) Making draw functions final 
  virtual void DrawPath(CATRender& iRender, int iInside, CATRepPath& iRepPath) override final;
  virtual void Draw(CATRender& iRender, int iInside) override final;
  virtual int IsOkToDraw(CATRender& ioRender, int ioInside) override final;

  /**
   * Compute the Scale in cylindric projection.
   * @param iViewer
   *   The Viewer used.
   */
  void ComputeScaleInCylindric( CATVizViewer *iViewer );

  /**
   * @nodoc .
   */
  inline void GetScaleFactor  (float& oScaleFactor);
  /**
   * @nodoc .
   */
  inline void GetPlaneSize    (float& oPlaneWidth, float& oPlaneHeight);
  /**
   * @nodoc .
   */
  inline void GetLinesSpace   (float& oLineWidth, float& oLineHeight);

private :

  CAT3DScalePlaneRep();
  CAT3DScalePlaneRep( const CAT3DScalePlaneRep & );
  CAT3DScalePlaneRep& operator = (const CAT3DScalePlaneRep&);

  void InitializeReps();

  float  _ScaleFactor;

  float	_WidthInMillimeters;
  float	_HeightInMillimeters;

  float _VerticalLinesSpace;
  float _HorizontalLinesSpace;

  CAT3DCustomRep* _CustomRepForPlane;
  CAT3DCustomRep* _CustomRepForLinesAndTexts;
};

inline void CAT3DScalePlaneRep::GetScaleFactor(float& oScaleFactor)
{
  oScaleFactor = 0.0f;

  if (_ScaleFactor!=0.0f) oScaleFactor = 1.0f / _ScaleFactor;
}

inline void CAT3DScalePlaneRep::GetPlaneSize(float& oPlaneWidth, float& oPlaneHeight)
{
  oPlaneWidth   = _WidthInMillimeters;
  oPlaneHeight  = _HeightInMillimeters;
}

inline void CAT3DScalePlaneRep::GetLinesSpace(float& oLineWidth, float& oLineHeight)
{
  oLineWidth  = _VerticalLinesSpace;
  oLineHeight = _HorizontalLinesSpace;
}

#endif
