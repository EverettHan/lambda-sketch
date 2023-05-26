//===================================================================
// COPYRIGHT Dassault Systemes 2012/06/27
//===================================================================
// CATV3DRotationEventArgs.h
// Header definition of class CATV3DRotationEventArgs
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/06/27 Creation: Code generated by the 3DS wizard  JV8
//===================================================================

#ifndef CATV3DRotationEventArgs_H
#define CATV3DRotationEventArgs_H

#include <VisuImmersive3D.h>
#include <CATV3DManipulationEventArgs.h>

/** @ingroup V3D
 * Dispatching arguments for manipulation events of @ref CATV3DGraphicPrimitive.
 *
 * @see CATV3DGraphicPrimitive::Drag
 */
class ExportedByVisuImmersive3D CATV3DRotationEventArgs: public CATV3DManipulationEventArgs
{
  CATDeclareClass;
public:
  /** 
   * Initialize this class.
   *
   * @param i_pEvent the event dispatched. Can't be @c NULL.
   * 
   * @param i_timestamp the timestamp in milli-seconds of the
   * interaction represented by the dispatch of the event.
   *
   * @param i_pViewer the viewer in which the event occured. Can't be
   * @c NULL.
   *
   * @param i_mousePositionInViewer the position of the mouse in the
   * viewer.
   *
   * @param i_transformation the 3D transformation of the manipulation 
   * that has sent the event. 
   */
  CATV3DRotationEventArgs(CATSYPEvent *i_pEvent, 
                       CATULONG32 i_timestamp, 
                       CATVizViewer *i_pViewer,
                       const CATMathPoint2Df &i_mousePositionInViewer, 
                       const CATMathPoint &iPickedPoint, 
                       const CATMathDirection &iNormal,
                       const CATMathDirection &iIndicationSegmentDirection,
                       CATPathElement *i_pPath,
                       Modifiers i_modifiers,
                       const CATMathTransformation &i_transformation,
                       const CATMathLine &i_axis,
                       const CATAngle &i_angle,
                       int i_ButtonPressed=1);

  /** Destroy this class */
  virtual ~CATV3DRotationEventArgs();
  
  /**
   * Get the axis of the rotation. 
   *
   * @return the axis of the rotation.
   */
  CATMathLine GetAxis();
  /**
   * Get the value of the angle in degree of the rotation. 
   *
   * @return the value of the angle in degree of the rotation.
   */
  CATAngle GetAngle();
private:
  CATV3DRotationEventArgs(const CATV3DRotationEventArgs &);
  CATV3DRotationEventArgs &operator=(const CATV3DRotationEventArgs &);

private:
  /** the axis of the rotation.  */
  const CATMathLine _axis;
  /** the value of the angle in degree of the rotation.  */
  const CATAngle _angle;
};

#endif // CATV3DRotationEventArgs

