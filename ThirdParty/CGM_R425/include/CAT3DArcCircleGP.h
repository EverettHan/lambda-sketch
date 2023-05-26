#ifndef CAT3DArcCircleGP_H
#define CAT3DArcCircleGP_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//------------------------------------------------------------------------------
// Inheritance: CAT3DArcCircleGP
//                 CAT3DArcEllipseGP
//                    CATDynamicGP
//                       CATGraphicPrimitive
//                          CATBaseUnknown
//------------------------------------------------------------------------------

#include "SGInfra.h"

#include "CAT3DArcEllipseGP.h"
class CATStreamer;

/**
 * Class to create the dynamic graphic primitive of a 3D circle arc or a 3D circle.
 */
class ExportedBySGInfra CAT3DArcCircleGP : public CAT3DArcEllipseGP
{
 CATDeclareClass;
  
 public :
	 
  /**
   * Constructs an empty 3D Arc Circle dynamic graphic primitive.
   */
	 CAT3DArcCircleGP ();

  /**
   * Constructs a 3D circle arc or a 3D circle graphic primitive
   * @param iCenter
   *   The center of the circle arc.
   * @param iNormal
   *   The normal to the circle plan.
   *   This vector must be normalized
   * @param iRadius
   *   The circle arc radius.
   * @param iReferenceAxis
   *   The reference axis.
   *   It is in the circle plan.
   * @param iStartAngle
   *   The start angle of the arc with
   *   respect to the reference axis.
   *   <br><b>Legal values</b>: The default start angle value
   *   is 0.
   * @param iEndAngle
   *   The ending angle of the arc with
   *   respect to the reference axis.
   *   <br><b>Legal values</b>: The default end angle value
   *   is 360 degrees.
   * @param iStaticSagUsed
   *   Used to specify whether using a dynamic or a static
   *   sag for the circle arc visualization.
   *   <br><b>Legal values</b>:
   *   <dl>
   *      <dt>1</dt>
   *        <dd>The sag value is static and taken
   *            from the settings, and is constant whatever the distance between
   *            the view point and the circle arc may be</dd>
   *      <dt>0</dt>
   *        <dd>The sag value is dynamic and calculated depending on
   *            the distance between the view point and the circle arc</dd>
   *   </dl>
   */
   CAT3DArcCircleGP (const CATMathPointf  &iCenter,
		     const CATMathVectorf &iNormal,
		     const float           iRadius,
		     const CATMathVectorf &iReferenceAxis,
		     const float           iStartAngle = 0.f,
                     const float           iEndAngle   = 6.2831853f,
                     const int             iStaticSagUsed = 0);

  /**
   * @nodoc
   */
  virtual void Stream(CATStreamer& oStr,int iSaveType=0);

  /**
   * @nodoc
   */
  virtual void UnStream(CATStreamer& str);

//--------------------------------------------------------------------------------
 
 protected :

   virtual ~CAT3DArcCircleGP();
};

#endif
