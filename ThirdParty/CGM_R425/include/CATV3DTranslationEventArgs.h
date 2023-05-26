//===================================================================
// COPYRIGHT Dassault Systemes 2012/06/27
//===================================================================
// CATV3DTranslationEventArgs.h
// Header definition of class CATV3DTranslationEventArgs
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2012/06/27 Creation: Code generated by the 3DS wizard  JV8
//===================================================================

#ifndef CATV3DTranslationEventArgs_H
#define CATV3DTranslationEventArgs_H

#include <VisuImmersive3D.h>
#include <CATV3DManipulationEventArgs.h>

/** @ingroup V3D
 * Dispatching arguments for manipulation events of @ref CATV3DGraphicPrimitive.
 *
 * @see CATV3DGraphicPrimitive::Drag
 */
class ExportedByVisuImmersive3D CATV3DTranslationEventArgs: public CATV3DManipulationEventArgs
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
  CATV3DTranslationEventArgs(CATSYPEvent *i_pEvent, 
                       CATULONG32 i_timestamp, 
                       CATVizViewer *i_pViewer,
                       const CATMathPoint2Df &i_mousePositionInViewer, 
                       const CATMathPoint &iPickedPoint, 
                       const CATMathDirection &iNormal,
                       const CATMathDirection &iIndicationSegmentDirection,
                       CATPathElement *i_Path, 
                       Modifiers i_modifiers,
                       const CATMathTransformation &i_transformation,
                       const CATMathVector &i_translation,
                       int i_ButtonPressed=1,
                       double i_RatioToCompensateScaling =1.);

  /** Destroy this class */
  virtual ~CATV3DTranslationEventArgs();
  
  /**
   * Get the value of the translation. 
   *
   * @return the value of the translation.
   */
  CATMathVector GetTranslation();

  /**
  * Get the value of the translation to apply to compensate scaling operations of higher V3DWidgets in the hierarchy.
  *
  * @return the value of the translation to apply to compensate scaling operations of higher V3DWidgets in the hierarchy.
  */
  CATMathVector GetCompensatedTranslation();

private:
  CATV3DTranslationEventArgs(const CATV3DTranslationEventArgs &);
  CATV3DTranslationEventArgs &operator=(const CATV3DTranslationEventArgs &);

private:
  /** the value of the translation.*/
  const CATMathVector _translation;
  const double        _ratioToCompensateScaling;
};

#endif // CATV3DTranslationEventArgs
