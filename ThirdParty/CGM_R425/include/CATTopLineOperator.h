#ifndef CATTopLineOperator_h
#define CATTopLineOperator_h

//COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @required Protected
 * @usage U1
 */ 
#include "CATIACGMLevel.h"

#include "CATTopCurveOperator.h"
#include "BasicTopology.h"
class CATMathVector;

/**
* Class defining a topological operator that builds a line body.
* <br> The definition of the line can be:
* <ul><li> passing by two points,
* <li> passing by a point and with a given direction,
* <li> tangent to a wire at a given point,
* <li> angled to the tangent to a wire at a given point, round the shell normal at this point 
* <li> normal to a shell at a point.
*</ul>
*<br> This operator follows the general scheme of the topological operators.
* For a basic use, use the functions <tt>CATCreateTopLineXXX</tt>
* that directly returns a line body.
* If you need to tune specific parameters, use the advanced scheme:
*<ul>
*<li> Create the operator with one of the functions <tt>CATCreateTopLineOperatorXXX</tt>
*<li> Set parameters: for example, use the </tt>SetFirstLimit</tt>
* </tt>SetSecondLimit</tt> methods to tune the line limits
*<li> Run
*<li> Get the resulting body 
*<li> Delete the operator with the usual C++ <tt>delete</tt> operator.
*</ul>
*<br>The created body can be removed from the factory with the 
* @href CATICGMContainer#Remove method as any CATICGMObject.
*/
class ExportedByBasicTopology CATTopLineOperator : public CATTopCurveOperator
{
  //-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATTopLineOperator);
public:
  //-------------------------------------------------------------------
 /**
 * @nodoc
 * Constructor. Do not use. Use <tt>CATCreateTopLineXXXOperator</tt> to create an
 * <tt>CATTopLineOperator</tt>.
 */
  CATTopLineOperator(CATGeoFactory* iFactory, CATCGMJournalList* ioJournal=0);

 /**
 * @nodoc
 * Constructor. Do not use. Use <tt>CATCreateTopLineXXXOperator</tt> to create an
 * <tt>CATTopLineOperator</tt>.
 */
  CATTopLineOperator(CATGeoFactory* iFactory, CATTopData* iData);

  virtual ~CATTopLineOperator();
 
  /** 
  * Defines the first limitation of the Line Body.
  * @param iFirstLength
  * The length from the origin of the line to define the first limitation.
  */
  virtual void SetFirstLimit(double iFirstLength)=0;

   /** 
  * Defines the second limitation of the Line Body.
  * @param iSecondLength
  * The length from the origin of the line to define the second limitation.
  */
  virtual void SetSecondLimit(double iSecondLength)=0;
/**
 * Reads the first limitation, set for <tt>this</tt> CATTopLineOperator.
 * @param ioFirstLength
 * The length from the origin of the line to define the first limitation.
 */
  virtual void GetFirstLimit(double & ioFirstLength)=0;
  /**
 * Reads the second limitation, set for <tt>this</tt> CATTopLineOperator.
 * @param ioSecondLength
 * The length from the origin of the line to define the second limitation.
 */
  virtual void GetSecondLimit(double & ioSecondLength)=0;
};


/**
* Creates a topological line operator that builds
* a line passing through two points.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line. This body must only contain one point (vertex).
* @param iSecondPoint
* A pointer to the second point body, defining the line. This body must only contain one point (vertex).
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/
ExportedByBasicTopology CATTopLineOperator* 
CATCreateTopLineOperatorFromPoints(CATGeoFactory* iFactory,
                                   CATTopData* iTopData,
                                   CATBody* iOriginPoint,
                                   CATBody* iSecondPoint);

/**
* Creates a line body passing through two points.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line.  This body must only contain one point (vertex).
* @param iSecondPoint
* The pointer to the second point body defining the line.  This body must only contain one point (vertex).
* @return
* The pointer to the created line body. To remove with the @href CATICGMContainer#Remove method.
*/

ExportedByBasicTopology CATBody* 
CATCreateTopLineFromPoints(CATGeoFactory* iFactory,
                           CATTopData* iTopData,
                           CATBody* iOriginPoint,
                           CATBody* iSecondPoint);

/**
* Creates a topological line operator that builds
* a line passing through a point and with a given direction.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* A pointer to the point body, origin of the line.  This body must only contain one point (vertex).
* @param iDirection
* The vector defining the line direction.
* @param iLength
* The length of the line from the origin point.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/
ExportedByBasicTopology CATTopLineOperator* 
CATCreateTopLineOperatorFromDirection(CATGeoFactory* iFactory,
                                      CATTopData* iTopData,
                                      CATBody* iOriginPoint,
                                      const CATMathVector& iDirection,
                                      double iLength);

/**
* Creates a line body passing through a point with a given direction.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line. This body must only contain one point (vertex).
* @param iDirection
* The vector defining the line direction.
* @param iLength
* The length of the line from the origin point.
* @return
* The pointer to the created line body. To remove with the @href CATICGMContainer#Remove method.
*/
ExportedByBasicTopology CATBody* 
CATCreateTopLineFromDirection(CATGeoFactory * iFactory,
                              CATTopData* iTopData,
                              CATBody * iOriginPoint,
                              const CATMathVector& iDirection,
                              double iLength);

/**
* Creates a topological line operator that builds
* a line tangent to a wire at a given point on the wire.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line.  This body must only contain one point (vertex).
* @param iWire
* The pointer to the wire body which geometrically contains the origin point. This body must only contain one wire.
* @param iLength
* The length of the line from the origin point.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/
ExportedByBasicTopology CATTopLineOperator* 
CATCreateTopLineOperatorTangentToWire(CATGeoFactory* iFactory,
                                      CATTopData* iTopData,
                                      CATBody* iOriginPoint,
                                      CATBody* iCurve,
                                      double iLength);

/**
* Creates a line body tangent to a wire at a given point on the wire.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line. This body must only contain one point (vertex).
* @param iCurve
* The pointer to the wire body which geometrically contains the origin point. This body must only contain one wire.
* @param iLength
* The length of the line from the origin point.
* @return
* The pointer to the created line body. To remove with the @href CATICGMContainer#Remove method.
*/
ExportedByBasicTopology CATBody* 
CATCreateTopLineTangentToWire(CATGeoFactory* iFactory,
                              CATTopData* iTopData,
                              CATBody* iOriginPoint,
                              CATBody* iCurve,
                              double iLength);

/**
* Creates a topological line operator that builds
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
* @param iLength
* The length of the line from the origin point.
* @param iAngle
* The angle in radian of the rotation around the normal of the shell at the origin point.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/
ExportedByBasicTopology CATTopLineOperator* 
CATCreateTopLineOperatorAngledTangentToWire(CATGeoFactory* iFactory,
                                            CATTopData* iTopData,
                                            CATBody* iOriginPoint,
                                            CATBody* iCurve,
                                            CATBody* iShellOfCurve,
                                            double iLength,
                                            CATAngle  iAngle);

/**
* Creates a line body angled to the tangent to the wire at the origin point,
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
* @param iWire
* The wire which contains the origin point. It must be included in the shell. 
* @param iShellOfWire
* The pointer to the shell containing the origin point and the wire. 
* @param iLength
* The length of the line from the origin point.
* @param iAngle
* The angle in radian of the rotation around the normal of the shell at the origin point.
* @return
* The pointer to the created line body. To remove with the @href CATICGMContainer#Remove method.
*/
ExportedByBasicTopology CATBody*
CATCreateTopLineAngledTangentToWire(CATGeoFactory * iFactory,
                                    CATTopData* iTopData,
                                    CATBody * iOriginPoint,
                                    CATBody * iWire,
                                    CATBody * iShellOfWire,
                                    double iLength,
                                    CATAngle iAngle);

/**
* @nodoc
* @nocgmitf Not yet implemented!
* Creates a line body normal to a curve. 
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line. This body must only contain one point (vertex).
* @param iWire
* The wire which contains the origin point. It must be included in the shell. 
* @param iShellOfWire
* The shell containing the origin point and the wire. 
* @param iLength
* The length of the line from the origin point.
* @return
* The pointer to the created line body. To remove with the @href CATICGMContainer#Remove method.
*/
ExportedByBasicTopology CATBody* 
CATCreateTopLineNormalToCurve(CATGeoFactory* iFactory,
                              CATTopData* iTopData,
                              CATBody* iFirstPoint,
                              CATBody* iCurve,
                              CATBody* iShellOfCurve,
                              double iLength,
                              CATAngle  iAngle);
                                                               

/**
* Creates a topological line operator  that builds
* a line normal to a shell at a point.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line. This body must only contain one point (vertex).
* @param iShellOfPoint
* The pointer to the shell containing the origin point. 
* @param iLength
* The length of the line from the origin point.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/
ExportedByBasicTopology CATTopLineOperator* 
CATCreateTopLineOperatorNormalToShell(CATGeoFactory* iFactory,
                                      CATTopData* iTopData,
                                      CATBody* iOriginPoint,
                                      CATBody* iShellOfPoint,
                                      double iLength);

/**
* Creates a line body normal to a shell at a point.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The pointer to the point body, origin of the line. This body must only contain one point (vertex).
* @param iShellOfPoint
* The pointer to the shell containing the origin point. 
* @param iLength
* The length of the line from the origin point.
* @return
* The pointer to the created line body. To remove with the @href CATICGMContainer#Remove method.
*/
ExportedByBasicTopology CATBody* 
CATCreateTopLineNormalToShell(CATGeoFactory* iFactory,
                              CATTopData* iTopData,
                              CATBody* iFirstPoint,
                              CATBody* iShellOfPoint,
                              double iLength);

/**
* Create an infinite line passing through a point in a given direction.
* @param iFactory
* The factory that creates the resulting body.
* @param iOriginPoint
* The point body origin of the line.
* @param iDirection
* The vector giving the line direction.
* @param iIsSemiInfinite
* Yes if the line is only infinite in the given direction
* and No if the line is infinite on the both side.
* @return
* The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
*/
//===================================================================
ExportedByBasicTopology CATTopLineOperator* 
CATCreateTopLineInfiniteOperatorFromDirection(CATGeoFactory * iFactory,
                                              CATTopData* iTopData,
                                              CATBody * iOriginPoint,
                                              const CATMathVector& iDirection,
                                              CATBoolean iIsSemiInfinite);

/**
* Create an infinite line passing through a point in a given direction.
* @param iFactory
* The factory that creates the resulting body.
* @param iTopData
* The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
* is <tt>NULL</tt>, it is not filled. 
* @param iOriginPoint
* The point body origin of the line.
* @param iDirection
* The vector giving the line direction.
* @param iIsSemiInfinite
* TRUE if the line is only infinite in the given direction
* and FALSE if the line is infinite on the both side.
* @return
* The pointer to the created line body. To remove with the @href CATICGMContainer#Remove method.
*/
ExportedByBasicTopology CATBody* 
CATCreateTopInfiniteLineFromDirection(CATGeoFactory * iFactory,
                                      CATTopData* iTopData,
                                      CATBody * iOriginPoint,
                                      const CATMathVector& iDirection,
                                      CATBoolean iIsSemiInfinite);


#endif
