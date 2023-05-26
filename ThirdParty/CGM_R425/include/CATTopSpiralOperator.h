#ifndef CATTopSpiralOperator_h
#define CATTopSpiralOperator_h

//COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATTopCurveOperator.h"
#include "BasicTopology.h"
class CATMathVector;

/**
* Class defining a topological operator that builds an Spiral Body.
*<br> An topological Spiral is created in Advanced mode.
*<ul>
*<li>Use the CATTopSpiralOperator as any topological operator :
*<ul>
*<li> Create the operator with the function <tt>CATCreateTopSpiralOperator</tt>,
*<li> Set the spiral relimitations such as <tt>SetEndAngleEndRadius</tt>, 
* <tt>SetEndRadiusPitch</tt>,<tt>SetEndAnglePitch</tt>,  
*<li> Run,
*<li> Get the resulting body, 
*<li> Delete the operator with the usual C++ <tt>delete</tt> operator after use.
*</ul>
*</ul>
*<br>The created body can be removed from the factory with the @href CATICGMContainer#Remove 
* method as any CATICGMObject.
*/

class ExportedByBasicTopology CATTopSpiralOperator : public CATTopCurveOperator
{
  
  //-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATTopSpiralOperator);
public:
  //-------------------------------------------------------------------
  
  /**
  * @nodoc
  * Constructor. Do not use. Use <tt>CATCreateTopSpiralOperator</tt> to create an
  * <tt>CATTopSpiralOperator</tt>.
  */
  CATTopSpiralOperator(CATGeoFactory* iFactory, CATTopData* iTopData);
  
  virtual ~CATTopSpiralOperator();
  
  /**
  * Defines the spiral limitation by an ending angle and an ending radius.
  * @param iEndAngle
  * The end angle of the spiral. <tt>iEndAngle</tt> must be greater than 0. 
  * @param iEndRadius
  * The end radius of the spiral. <tt>iEndRadius</tt> must be greater than or equal to 0.  
  * @return
  * Not null if failed.
  */
  virtual CATLONG32 SetEndAngleEndRadius(CATAngle iEndAngle, CATLength iEndRadius) = 0;
  
  /**
  * Defines the spiral limitation by an ending angle and a pitch.
  * @param iEndAngle
  * The end angle of the spiral. <tt>iEndAngle</tt> must be greater than 0. 
  * @param iPitch
  * The spiral pitch, measuring the absolute radius variation of  spiral current point corresponding with a rotation of 2*PI. 
  * <tt>iPitch</tt> must be greater than 0.  
  * @return
  * Not null if failed.
  */
  virtual CATLONG32 SetEndAnglePitch(CATAngle iEndAngle,CATLength iPitch) = 0;
  
  /**
  * Defines the spiral limitation by an ending radius and a pitch.
  * @param iEndRadius
  * The end radius of the spiral. <tt>iEndRadius</tt> must be greater than or equal to 0.  
  * @param iPitch
  * The spiral pitch, measuring the absolute radius variation of  spiral current point corresponding with a rotation of 2*PI. 
  * <tt>iPitch</tt> must be greater than 0.  
  * @return
  * Not null if failed.
  */
  virtual CATLONG32 SetEndRadiusPitch(CATLength iEndRadius,CATLength iPitch) = 0;
  
};

/**
* Creates a topological spiral.
* @param iSupport
* The spiral support. 
* It is a body shell made of a single planar face, seen as infinite.
* @param iRadiusOrigin
* The origin of the spiral radii. 
* It is a body vertex in volume made of a vertex.
* Point <tt>iRadiusOrigin</tt> must be located on the plane of support 'iSupport'.
* @param iAngleAxis
* The origin axis of the spiral angles.
* It is a  CATMathVector.
* @param iStartingRadius
* Defines the starting point of the spiral at distance <tt>iStartingRadius</tt>  from the radius origin <tt>iRadiusOrigin</tt>.
*  <tt>iStartingRadius</tt> must be greater than or equal to 0.  
* @param iClockwiseRevolution
* The clockwise/counterclockwise indicator.
* Spiral revolutions are clockwise if TRUE, counterclockwise if FALSE round shell normal at point <tt>iRadiusOrigin</tt>.
*/
ExportedByBasicTopology CATTopSpiralOperator* 
CATCreateTopSpiralOperator(CATGeoFactory* iFactory, 
                           CATTopData* iTopData,
                           CATBody* iSupport,
                           CATBody* iRadiusOrigin,
                           const CATMathVector& iAngleAxis,
                           CATLength iStartingRadius,
                           CATBoolean iClockwiseRevolution);

#endif
