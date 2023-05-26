#ifndef CATTopGeodesicLineOperator_h
#define CATTopGeodesicLineOperator_h

//COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @required Protected
 * @usage U1
 */ 

#include "CATIAV5Level.h"
#include "CATIACGMLevel.h" 

#ifdef CATIACGMR215CAA
#include "CATTopCurveOperator.h"
#include "CATMathConstant.h"
#else
#include "CATTopOperator.h"
#endif
#include "BasicTopology.h"
class CATMathVector;

/**
* Class defining a topological operator that builds a geodesic line on a shell.
* <br> The definition of the line is:
* <ul><li> passing by a point, in a given direction, with first and second length.
* <li> If first length>0 (or<0) and second length2<0 (or>0), the point will be cleaned.
*</ul>
*<br> This operator follows the general scheme of the topological operators.
*<li> Create the operator with the <tt>CATCreateTopGeodesicLineOperatorFromDirection</tt> global function.
*<li> Run with the <tt>Run</tt> method. 
*<li> Get the result body by the <tt>GetResult</tt> method. 
*<li> Delete the operator with the usual C++ <tt>delete</tt> operator.
*</ul>
*<br>The created body can be removed from the factory with the 
* @href CATICGMContainer#Remove method as any CATICGMObject.
*/
#ifdef CATIACGMR215CAA
class ExportedByBasicTopology CATTopGeodesicLineOperator : public CATTopCurveOperator
#else
class ExportedByBasicTopology CATTopGeodesicLineOperator : public CATTopOperator
#endif
{
  //-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATTopGeodesicLineOperator);
public:
  //-------------------------------------------------------------------
 /**
 * @nodoc
 * Constructor. Do not use. Use <tt>CATCreateTopGeodesicLineXXXOperator</tt> to create an
 * <tt>CATTopGeodesicLineOperator</tt>.
 */
  CATTopGeodesicLineOperator(CATGeoFactory* iFactory, CATTopData* iData);

  virtual ~CATTopGeodesicLineOperator();

};


/**
* Creates the CATTopGeodesicLineOperator that will create geodesic line body passing through a point in a given direction.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line. This body must only contain one point (vertex).
* @param iDirection
* The vector defining the line direction.
* @param iFirstLength
* The first length of the line from the origin point.
* @param iEndLength
* The second length of the line from the origin point.
* @return
* The pointer to the created line body. To remove with the @href CATICGMContainer#Remove method.
*/
ExportedByBasicTopology CATTopGeodesicLineOperator * 
CATCreateTopGeodesicLineOperatorFromDirection(CATGeoFactory * iFactory,
                                              CATTopData* iTopData,
                                              CATBody * iSupport,
                                              CATBody * iOriginPoint,
                                              const CATMathVector& iDirection,
                                              double iFirstLength,
                                              double iSecondLength=0);

#ifdef CATIACGMR215CAA
/**
* Creates the CATTopGeodesicLineOperator which builds
* a line angled to the tangent to the wire at the origin point,
* and lying in the plane tangent to the shell at the origin point.
* <br>In other words:
* <ul>
*   <li>consider T as the tangent to the wire at the origin point P,
*   <li>build the result line by rotation of T of a given angle round the
*     normal to the shell at P.
* </ul>
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line. This body must only contain one point (vertex).
* @param iCurve
* The pointer to the wire which contains the origin point. It must be included in the shell. 
* @param iShellOfCurve
* The pointer to the shell which contains the origin point and the wire. 
* @param iAngle
* The angle in radian of the rotation around the normal of the shell at the origin point.
* @param iFirstLength
* The first length of the line from the origin point.
* @param iEndLength
* The second length of the line from the origin point.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/
ExportedByBasicTopology CATTopGeodesicLineOperator * 
CATCreateTopGeodesicLineOperatorAngledTangentToWire(CATGeoFactory * iFactory,
                                                    CATTopData    * iTopData,
                                                    CATBody       * iOriginPoint,
                                                    CATBody       * iCurve,
                                                    CATBody       * iShellOfCurve,
                                                    CATAngle        iAngle,
                                                    double          iFirstLength,
                                                    double          iSecondLength = 0.0);
#endif

#endif
