// COPYRIGHT DASSAULT SYSTEMES 2001

#ifndef CATSpiralOperator_H
#define CATSpiralOperator_H

#include "FrFOpeCrv.h"
#include "CATCGMOperator.h"

#include "CATMathDef.h"
#include "CATMathAxis.h"

class CATGeoFactory;
class CATHelix;


/**
 * Class defining a geometric operator that creates a geometric spiral.
 * <br>A spiral is a particular case of <tt>CATHelix</tt>: the z-law is constant. 
 * <ul>
 * <li>A CATSpiralOperator operator is created with the <tt>CATCreateSpiralOperator</tt> global function:
 * It must be directly deleted with the usual C++ <tt>delete</tt> operator after use. It is not streamable. 
 * <li>Options must be precised (such as the pitch, the radius or the angle) with the <tt>SetXxx</tt>
 * methods, before
 * asking for the computation with the <tt>Run</tt> method. 
 * <li>The result is accessed with the <tt>GetResult</tt> method. If you do not want 
 * to keep the resulting geometry, use the @href CATICGMContainer#Remove method to remove it from the 
 * geometric factory.
 *</ul>
 */

class ExportedByFrFOpeCrv CATSpiralOperator : public CATCGMOperator
{
public :
/**
 * Destructor.
 */ 
  ~CATSpiralOperator();

/**
 * Defines the spiral limitation by an ending angle and an ending radius.
 * @param iEndAngle
 *  The end angle of the spiral. <tt>iEndAngle</tt> must be greater than 0.
 * @param iEndRadius
 *  The end radius of the spiral. <tt>iEndRadius</tt> must be greater than or equal to 0.
 * @return
 *  Not null in case of error.
 */
  virtual int SetEndAngleEndRadius(CATAngle iEndAngle, CATLength iEndRadius) = 0;

/**
 * Defines the spiral limitation by an ending angle and a pitch.
 * @param iEndAngle
 *  The end angle of the spiral. <tt>iEndAngle</tt> must be greater than 0.
 * @param iPitch
 *  The spiral pitch, measuring the absolute radius variation of spiral current point for a round 
 *  (variation of the angle is <tt>2*CATPI</tt>).
 *  <tt>iPitch</tt> must be greater than 0.
 * @return
 *  Not null in case of error.
 */
  virtual int SetEndAnglePitch(CATAngle iEndAngle, CATLength iPitch) = 0;

/**
 * Defines the spiral limitation by an ending radius and a pitch.
 * @param iEndRadius
 *  The end radius of the spiral. <tt>iEndRadius</tt> must be greater than or equal to 0.
 * @param iPitch
 *  The spiral pitch, measuring the absolute radius variation of spiral current point for a round 
 *  (variation of the angle is <tt>2*CATPI</tt>).
 *  <tt>iPitch</tt> must be greater than 0.
 * @return
 *  Not null in case of error.
 */
  virtual int SetEndRadiusPitch(CATLength iEndRadius, CATLength iPitch) = 0;

/**
 * Runs <tt>this</tt> operator.
 */
  virtual int Run() =0;

/**
 * Returns the geometric spiral.
 * @return
 *  The pointer to the created spiral. If you do not want
 *  to keep the resulting geometry, use the @href CATICGMContainer#Remove method to remove it from the 
 *  geometric factory.
 */
  virtual CATHelix* GetResult() = 0;

  protected:
/**
 * @nodoc
 */
  CATSpiralOperator(CATGeoFactory* iFactory);
/**
 * @nodoc
 */
  CATSpiralOperator(CATSpiralOperator& );
};


/**
 * Creates a geometric operator to create a spiral.
 * <br>A spiral is a particular case of <tt>CATHelix</tt>: the z-law is constant.
 * @param iAxis
 *  The axis of the spiral.
 * @param iStartRadius
 *  Defines the starting point of the spiral at distance <tt>iStartRadius</tt> from the axis origin of <tt>iAxis</tt>.
 *  <tt>iStartRadius</tt> must be greater than or equal to 0.
 * @param iClockwiseRevolution
 *  The clockwise/counterclockwise indicator.
 *  <br><b>Legal values</tt>:
 *  Spiral revolutions are clockwise if <tt>TRUE</tt>, counterclockwise if <tt>FALSE</tt> round shell normal at point <tt>iRadiusOrigin</tt>.
 */

ExportedByFrFOpeCrv
CATSpiralOperator* CATCreateSpiralOperator(CATGeoFactory      *iFactory,
                                           const CATMathAxis  &iAxis,
                                           double              iStartRadius,
                                           CATBoolean          iClockwiseRevolution);


#endif

