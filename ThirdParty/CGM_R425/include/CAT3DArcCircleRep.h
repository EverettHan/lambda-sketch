#ifndef CAT3DArcCircleRep_H
#define CAT3DArcCircleRep_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CAT3DArcEllipseRep.h"
#include "SGInfra.h"

/**
 * Class to create the representation of a 3D circle or a 3D circle arc.
 * <b>Role</b>: view (a portion of) a circle lying in a plane.
 */
class ExportedBySGInfra CAT3DArcCircleRep : public CAT3DArcEllipseRep
{
  friend class CATDmuStream3DArcCircleRep;
	CATDeclareClass;
  
public:
	
virtual ~CAT3DArcCircleRep();

  /**
   * Constructs the representation of a circle arc.
   * @param iCenter
   * The center of the circle.
   * @param iNormal
   * The normal to the plane of the circle.
   * @param iRadius
   * The radius of the circle.
   * @param iAxis
   * The direction in the plane of the circle used as a reference for angles.
   * @param iStartAngle
   * The offset in radian of the beginning of the circle arc.
   * @param iEndAngle
   * The offset in radian of the end of the circle arc.
   * @param iStaticSagUsed
   * Used to specify whether using a dynamic or a static sag for the circle arc.
   *   <br><b>Legal values</b>:
   *   <dl>
   *      <dt>1</dt>
   *        <dd>The sag value is static and taken
   *            from the settings, and is constant whatever the distance between
   *            the view point and the arc circle may be</dd>
   *      <dt>0</dt>
   *        <dd>The sag value is dynamic and calculated depending on
   *            the distance between the view point and the arc circle</dd>
   *   </dl>
   */
  static CAT3DArcCircleRep* CreateRep(const CATMathPointf  & iCenter,
                                     const CATMathVectorf & iNormal,
                                     const float            iRadius,
                                     const CATMathVectorf & iAxis,
                                     const float            iStartAngl     = 0.f,
                                     const float            iEndAngle      = (float) CAT2PI,
                                     const int              iStaticSagUsed = 0);
 
protected:

  /** @nodoc : deprecated R417 : Use CreateRep instead.*/
  CAT3DArcCircleRep(const CATMathPointf& iCenter,
    const CATMathVectorf& iNormal,
    const float            iRadius,
    const CATMathVectorf& iAxis,
    const float            iStartAngle = 0.f,
    const float            iEndAngle = (float)CAT2PI,
    const int              iStaticSagUsed = 0);


 /**
  * Constructs an empty 3DArcCircleRep.
  * Only for unstreaming purpose.
  */
  CAT3DArcCircleRep ();
};

#endif
