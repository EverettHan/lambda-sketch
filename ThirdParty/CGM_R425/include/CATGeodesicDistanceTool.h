#ifndef CATGeodesicDistanceTool_H
#define CATGeodesicDistanceTool_H
// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @level Protected
 * @usage U1
 */ 
//#include "AdvTopoSketch.h"
#include "AdvTopoSketchLight.h"


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
 * @deprecated V5R10 CATCreateTopGeodesicDistanceTool
 * Class defining the geodesic parallel computation.
 * This class is used to define the parameters of a @href CATTopParallel operator.
 */
class ExportedByAdvTopoSketchLight CATGeodesicDistanceTool : public CATDistanceTool
{
  CATCGMVirtualDeclareClass(CATGeodesicDistanceTool);
public:
  /**
 * Constructs the object for the geodesic computation.
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
  CATGeodesicDistanceTool( CATGeoFactory * iGeoFactory,
                           CATSoftwareConfiguration * iSoftwareConfiguration,
                           CATOrientation iOrientation, CATCompositeLaw *iDistance );

/** 
 * @nodoc
 * Use the signature with CATCompositeLaw.
 * Constructs the object for the geodesic computation.
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

  CATGeodesicDistanceTool( CATGeoFactory * iGeoFactory,
                           CATSoftwareConfiguration * iSoftwareConfiguration,
                           CATOrientation iOrientation, CATLaw *iDistance );
 virtual ~CATGeodesicDistanceTool();

/** @nodoc */
  short GetType() const;

/** @nodoc */
  CATTopSign GetSign();

/** @nodoc
  * @nocgmitf
  */
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

/** @nodoc
  * @nocgmitf
  */
	CATCGMOperator * GetProjectOpe(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iToProject, CATGeometry * iSupport);
/** @nodoc
  * @nocgmitf
  */
	CATCGMOperator * GetDistOpe(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iToProject, CATGeometry * iSupport);
 private :
    
  CATOrientation _Orientation;
  CATSoftwareConfiguration   * _SoftwareConfiguration;
  CATBoolean _OwnedConfig;


 public:
/** @nodoc */
  CATGeodesicDistanceTool( CATGeoFactory * iGeoFactory,
                           CATOrientation iOrientation, CATLaw *iDistance );

/** @nodoc */
  CATGeodesicDistanceTool( CATGeoFactory * iGeoFactory,
                           CATOrientation iOrientation, CATCompositeLaw *iDistance );

};

#endif




















