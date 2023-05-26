#ifndef CATCreateTopEuclidianDistanceTool_H
#define CATCreateTopEuclidianDistanceTool_H
// COPYRIGHT DASSAULT SYSTEMES 2000
/**
 * @level Protected
 * @usage U1
 */ 
#include "CATIACGMLevel.h"
#include "ParallelLight.h"
#include "CATTopDef.h"
#include "CATCompositeLaw.h"

class CATGeoFactory;
class CATTopData;
class CATDistanceTool;

 /**
 * Constructs the object for the euclidean computation.
 * This class is to be used when you wan to create a parallel curve onto a suppport.
 * It does not create directly a curve onto 
 * a support. To do this, you must:
 * <ol>
 * <li>Specify the parameters of the offset distance by using CATDistanceTool. This parameters are: 
 * <ul>
 * <li> the parallelism mode: euclidian (use CATCreateTopEuclidianDistanceTool)
 * or geodesic (use CATCreateTopGeodesicDistanceTool)
 * <li> the side on which the wire is offset, it is computed from the support normal and the wire tangent: Side = Normal^Tangent 
 * <li> the law which defines the distance evolution along the wire.
 * </ul>
 * and they are specified as the arguments of CATCreateTopGeodesicDistanceTool.
 * <li>Specify the type of relimitation: sharp or round and the support on which the wire is offset.
 * This is done by creating the CATExtrapolParallelTool object. 
 * <li>Create and run the CATTopParallel operator.
 * </ol>
 * @param iGeoFactory
 * The pointer to geometry factory.
 * @param iData
 * The pointer to the CATTopData.
 * @param iOrientation
 * The side on which the parallel is computed.
 * The cross product between the shell normal and the wire tangent define the
 * left side.
 * <br><b>Legal values </b>: <tt>CATOrientationPositive</tt> for the left side,
 * <tt>CATOrientationNegative</tt> for the right side.
 * @param iDistance
 * The pointer to the law defining the parallel offset.
 */
#ifndef CATIACGMR214CAA
ExportedByParallelLight  CATDistanceTool * CATCreateTopEuclidianDistanceTool(CATGeoFactory * iGeoFactory, CATTopData * iData,
                            CATOrientation iOrientation, CATCompositeLaw *iDistance );
#else
ExportedByParallelLight  CATDistanceTool * CATCreateTopEuclidianDistanceTool(CATGeoFactory * iGeoFactory, CATTopData * iData,
                            CATOrientation iOrientation, CATLaw *iDistance );
#endif

#endif




















