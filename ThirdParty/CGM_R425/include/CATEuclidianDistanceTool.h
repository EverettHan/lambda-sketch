#ifndef CATEuclidianDistanceTool_H
#define CATEuclidianDistanceTool_H
// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @level Protected
 * @usage U1
 */ 
#include "ParallelLight.h"

#include "CATTopDef.h"
#include "CATDistanceTool.h"

class CATMathSetOfPointsND;
class CATMathFunctionX;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCurve;
class CATSurface;
class CATCrvLimits;
class CATSurLimits;
class CATLaw;
class CATCompositeLaw;
class CATParallelComputer;


/**
 * @deprecated V5R10 CATCreateTopEuclidianDistanceTool
 * Class defining the euclidean parallel computation.
 * This class is used to define the parameters of a @href CATTopParallel operator.
 */
class ExportedByParallelLight CATEuclidianDistanceTool : public CATDistanceTool
{
  CATCGMVirtualDeclareClass(CATEuclidianDistanceTool);
 public:

  /**
 * Constructs the object for the euclidean computation.
 * @param iGeoFactory
 * The pointer to geometry factory.
 * @param iSoftwareConfiguration
 * The pointer to the software configuration with which the code must be run.
 * @param iOrientation
 * The side on which the parallel is computed.
 * The cross product between the shell normal and the wire tangent define the
 * left side.
 * <br><b>Legal values </b>: <tt>CATOrientationPositive</tt> for the left side,
 * <tt>CATOrientationNegative</tt> for the right side.
 * @param iDistance
 * The pointer to the law defining the parallel offset.
 */
  CATEuclidianDistanceTool( CATGeoFactory * iGeoFactory,
                            CATSoftwareConfiguration * iSoftwareConfiguration,
                            CATOrientation iOrientation, CATCompositeLaw *iDistance );

  /**
 * @nodoc
 * Use the signature with CATCompositeLaw.
 * Constructs the object for the euclidean computation.
 * @param iGeoFactory
 * The pointer to geometry factory.
 * @param iSoftwareConfiguration
 * The pointer to the software configuration with which the code must be run.
 * @param iOrientation
 * The side on which the parallel is computed.
 * The cross product between the shell normal and the wire tangent define the
 * left side.
 * <br><b>Legal values </b>: <tt>CATOrientationPositive</tt> for the left side,
 * <tt>CATOrientationNegative</tt> for the right side.
 * @param iDistance
 * The pointer to the law defining the parallel offset.
 */

  CATEuclidianDistanceTool( CATGeoFactory * iGeoFactory,
                            CATSoftwareConfiguration * iSoftwareConfiguration,
                            CATOrientation iOrientation, CATLaw *iDistance );
  ~CATEuclidianDistanceTool();

/** @nodoc */
  short GetType() const;

/** @nodoc */
  CATTopSign GetSign();

/** @nodoc @nocgmitf */
  CATParallelComputer *GetParallelComputer( CATCurve * iCurve,
				       CATCrvLimits & iCurveLimit,
				       CATLONG32 iOrientationEdge,
				       CATBoolean iExtrapolEdge,
				       CATSurface * iSupport,
				       CATSurLimits & iSupportLimit,
				       CATLONG32 iOrientationSupport,
				       CATBoolean iExtrapolSupport,
                                       CATParallelConnectTool *iConnectTool,
				       CATMathSetOfPointsND * iInitPoints,
	                               CATBoolean iLoopSearch );

/** @nodoc @nocgmitf */
	CATCGMOperator * GetProjectOpe(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iToProject, CATGeometry * iSupport);
/** @nodoc @nocgmitf */
	CATCGMOperator * GetDistOpe(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iToProject, CATGeometry * iSupport);
 private :

  CATOrientation _Orientation;

  // Temporaire
  CATSoftwareConfiguration   * _SoftwareConfiguration;
  CATBoolean _OwnedConfig;

 
 public:
 /**
 * @nodoc
 * Use the signature with CATSoftwareConfiguration and CATCompositeLaw.
 */
  CATEuclidianDistanceTool( CATGeoFactory * iGeoFactory,
                            CATOrientation iOrientation, CATLaw *iDistance );
  /**
 * @nodoc
 * Use the signature with CATSoftwareConfiguration.
 */
  CATEuclidianDistanceTool( CATGeoFactory * iGeoFactory,
                            CATOrientation iOrientation, CATCompositeLaw *iDistance );

};

#endif




















