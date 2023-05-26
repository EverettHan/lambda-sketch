#ifndef CATTopPointOperator_h
#define CATTopPointOperator_h

//COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @required Protected
 * @usage U1
 */ 
#include "CATIACGMLevel.h"

#include "BasicTopology.h"
#include "CATTopDef.h"
#include "CATMathDef.h"
#include "CATMathVector.h"
#include "CATTopOperator.h"
#include "CatTopPointLMode.h"

/**
 * Class defining a topological operator that creates a point Body.
 *<br> 
 * Use directly the global functions
 * <tt>CATCreateTopPointxxx</tt>, that directly return the resulting body.
 */
class ExportedByBasicTopology CATTopPointOperator : public CATTopOperator
{
  //-------------------------------------------------------------------
  CATCGMVirtualDeclareClass(CATTopPointOperator);
public:
  //-------------------------------------------------------------------
  
  /**
  * @nodoc
  * Constructor. Do not use. Use <tt>CATCreateTopPointXXX</tt> to create an
  * <tt>CATTopPointOperator</tt>.
  */
  CATTopPointOperator(CATGeoFactory* iFactory, CATTopData* iTopData=0);
  
  /**
  * @nodoc
  * Constructor. Do not use. Use <tt>CATCreateTopPointXXX</tt> to create an
  * <tt>CATTopPointOperator</tt>.
  */
  CATTopPointOperator(CATGeoFactory* Factory, CATCGMJournalList* Report=0);

  virtual ~CATTopPointOperator();
  
  //
  // ADVANCED : Set Methods
  //
  /** @nodoc */  
  virtual CATLONG32 SetDirection(const CATMathVector& iVector)=0;
	/** @nodoc */
  virtual CATLONG32 SetLength(const double iLength)=0;
	/** @nodoc */
  virtual CATLONG32 SetLengthMode(const CatTopPointLMode iMode)=0;
	/** @nodoc */
  virtual CATLONG32 SetRefPoint(CATBody * iRefPoint)=0;
	/** @nodoc */
  virtual CATLONG32 SetSupport(CATBody * iSupport)=0;
	/** @nodoc */
  virtual CATLONG32 SetUV(const double U,const double V)=0;
	/** @nodoc */
  virtual CATLONG32 SetXYZ(const double X,const double Y,const double Z)=0;
  
  // ADVANCED : Run() : compute result after settings and before GetResult()
	/** @nodoc */
  virtual int Run()=0;
  
};

/**
 * Default constructor of an operator of topological point.
 * <br>To be used in advanced mode: after the operator creation, you have to
 * set the parameters, rnus the operator, reads then resulting body and delete the operator.
 * @param iFactory
 * The factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @return
 * The pointer to the created operator. To delete with the usual C++ <tt>delete</tt> operator.
 */
ExportedByBasicTopology CATTopPointOperator* CATCreateTopPointOperator(CATGeoFactory * iFactory,
                                                                       CATTopData* iTopData);
/**
 * Creates a topological point body from three coordinates.
 * @param iFactory
 * The factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iX
 * The first coordinate.
 * @param iY
 * The second coordinate.
 * @param iZ
 * The third coordinate.
 * @return
 * The pointer to the created point body. To remove with the @href CATICGMContainer#Remove method.
 */
ExportedByBasicTopology CATBody * CATCreateTopPointXYZ(CATGeoFactory * iFactory,
                                                       CATTopData* iTopData,
                                                       double iX,double iY,double iZ);
/**
 * Creates a topological point body on a wire at a given distance from another point on the wire.
 * <br>This basic mode corresponds to the settings <tt>SetSupport</tt>, <tt>SetLength</tt>, 
 * <tt>SetRefPoint</tt>, <tt>SetLengthMode</tt> of the advanced mode.
 * @param iFactory
 * The factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iWire
 * A pointer to the body on which the point is created.
 * @param iLength
 * The distance on the wire between the reference point and the point to create. 
 * In both distance modes, <tt>iLength</tt> can be positive or negative,
 *   and may lead to build a point outside the wire bounds.
 *   In such a case, the distance will be evaluated on the tangent
 *   to the wire at the reference point.
 * @param iRefPoint
 * The pointer to the point body from which the distance on the wire is computed. 
 * The point body must be a vertex of <tt>iWire</tt>
 * @param iLengthMode
 * The type of length computation.
 * @return
 * The pointer to the created point body. To remove with the @href CATICGMContainer#Remove method.
 */
ExportedByBasicTopology CATBody * CATCreateTopPointOnWire(CATGeoFactory * iFactory,
                                                          CATTopData* iTopData,
                                                          CATBody * iWire,
                                                          const double iLength,
                                                          CATBody * iRefPoint,
                                                          const CatTopPointLMode iLengthMode = CatTopPointLValue);
/**
 * Creates a body containing the set of points having a given tangent on a wire.
 * <br>This basic mode corresponds to the settings <tt>SetSupport</tt>, <tt>SetDirection</tt>
 * of the advanced mode.
 * @param iFactory
 * The factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iWire
 * A pointer to the wire on which the points are created.
 * @param iTangent
 * The common tangential direction of all the created points.
 * @return
 * The pointer to the created point body. To remove with the @href CATICGMContainer#Remove method.
 */
ExportedByBasicTopology CATBody * CATCreateTopPointsTgtOnWire(CATGeoFactory * ioFactory,
                                                              CATTopData* iTopData,
                                                              CATBody * iWire,
                                                              const CATMathVector& iTangent);
/**
 * Creates a topological point body on a surface at a given distance in each surface direction.
 * <br>This basic mode corresponds to the settings <tt>SetSupport</tt>, <tt>SetUV</tt>, 
 * of the advanced mode.
 * @param iFactory
 * The factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iReferencePointOnSurface
 * The pointer to the point on the surface from which the distances are computed.
 * @param iSurface
 * The pointer to the surface body.
 * @param iULength
 * The distance in the first direction.
 * @param iVLength
 * The distance in the second direction.
 * @return
 * The pointer to the created point body. To remove with the @href CATICGMContainer#Remove method.
 */
ExportedByBasicTopology CATBody * CATCreateTopPointUV(CATGeoFactory * ioFactory, 
                                                      CATTopData * iTopData,
                                                      const CATBody* iReferencePointOnSurface,
                                                      CATBody * iSurface,
                                                      const double iULength,const double iVLength);
/**
 * Creates a topological point body on a surface at a given distance 
 * from another point in a given direction.
 * <br>This basic mode corresponds to the settings <tt>SetSupport</tt>, <tt>SetDirection</tt>, 
 * <tt>SetLength</tt>, <tt>SetRefPoint</tt> of the advanced mode.
 * @param iFactory
 * The factory that creates the resulting body.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iSurface
 * The pointer to the surface body.
 * @param iDirection
 * The direction.
 * @param iGeodesicLength
 * The distance from <tt>iReferencePointOnSurface</tt>, evaluated on the geodesic line on the 
 * surface body <tt>iSurface</tt>, corresponding with the direction <tt>iDirection</tt>.
 * @param iReferencePointOnSurface
 * The pointer to the point on the surface from which the distance is computed. 
 * @return
 * The pointer to the created point body. To remove with the @href CATICGMContainer#Remove method.
 */
ExportedByBasicTopology CATBody * CATCreateTopPointOnSurface(CATGeoFactory * ioFactory,
                                                             CATTopData* iTopData,
                                                             CATBody * iSurface,
                                                             const CATMathVector& iDirection,
                                                             const double iGeodesicLength,
                                                             CATBody* iReferencePointOnSurface);

#endif
