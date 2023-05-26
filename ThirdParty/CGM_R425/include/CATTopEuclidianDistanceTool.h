#ifndef CATTopEuclidianDistanceTool_H
#define CATTopEuclidianDistanceTool_H
// COPYRIGHT DASSAULT SYSTEMES 2000

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByPARLight.h"

#include "CATTopDef.h"
#include "CATTopDistanceTool.h"

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
class CATMathVector;
class CATBody;
class CATVertex;
class CATVertexInVolume;



/**
 * Class defining the euclidean parallel computation.
 * This class is used to define the parameters of a @href CATTopParallel operator.
 */
class ExportedByPARLight CATTopEuclidianDistanceTool : public CATTopDistanceTool
{
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
  CATTopEuclidianDistanceTool(CATGeoFactory * iGeoFactory,
                              CATTopData * iData,
                              CATOrientation iOrientation, CATLaw *iDistance );
  CATTopEuclidianDistanceTool(CATGeoFactory * iGeoFactory,
                              CATTopData * iData,
                              CATOrientation iOrientation, CATCompositeLaw *iDistance );

  ~CATTopEuclidianDistanceTool();

/** @nodoc */
  short GetType() const;

  virtual int IsParallelImage(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry * iVtxImage,CATGeometry * iVtxOrig);
/** @nodoc */
  virtual void ComputeParallelImage(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry *& oVtxImage,CATGeometry * iVtxOrig);
/** @nodoc */
  virtual void DuplicateTool(CATTopDistanceTool * & oNewTool);

  /** @nodoc */
  // Modified By : SUH : 2003:7:2
  virtual CATLONG32 ValidateInitSide (CATCurve * iCurve, CATCrvParam & iCrvParam,
                                 CATSurface * iSurface, CATSurParam & iSurParam,
                                 double iRadiusValue, double * iTangent3D,
                                 double * oProduct = NULL);

  /** @nodoc */
  virtual void ComputeParallelImageFromTangent(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry *& oVtxImage,CATGeometry * iVtxOrig,CATVertex * iVtxExtremity,CATMathVector & iTangent); 
  /** @nodoc */
  CATBody * ComputeImageByIntersection(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iBodySupport,CATBody * iPointInit,CATMathVector & iTgtOnIni,double radius);
  /** @nodoc */
  double ComputeRadius(CATGeoFactory * iFacto,CATTopData * iData,CATVertex * VertexIni,CATBody * iCurveIni,CATLaw ** MapLaws);
  
  

};

#endif




















