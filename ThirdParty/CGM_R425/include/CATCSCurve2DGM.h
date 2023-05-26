//===================================================================
// COPYRIGHT Dassault Systemes 2016
//===================================================================
//
// CATCSCurve2DGM.h
// GM CATCSCurve2DGM object
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// March 2016    Creation                                       FCX
// Feb 2018     Use of CATCSCurve2DGMImp as implementation        FCX
//===================================================================

#ifndef CATCSCurve2DGM_H
#define CATCSCurve2DGM_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATCSCurve2D.h"
#include "SkinWireGMEnums.h"
#include "SkinWireGMDefines.h"

#ifndef CATCDSGMINFRA_IMP
class CATCSCurve2DCGMImp;
#endif

class CATSoftwareConfiguration;
class CATPCurve;
class CATCrvLimits;
class CATCSSketch;
class CATCSCurve2DGMImp;
class CATCGMStream;
class CATGeoFactory;

class ExportedBySkinWireGM CATCSCurve2DGM: public CATCSCurve2D
{
public:

  // Object management

  CATCSCurve2DGM();

  /* DEPRECATED: use constructor with Sketch instead */
  CATCSCurve2DGM(CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbCurves, CATPCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations, double iApproxTolerance, CATCDSBoolean iNoReparameterization = FALSE);
  
  CATCSCurve2DGM(CATCSSketch * ipSketch, CATSoftwareConfiguration * ipSoftwareConfiguration, int iNbCurves, CATPCurve ** iCurves, CATCrvLimits * iCurveLimits, int * iOrientations, double iApproxTolerance, CATCDSBoolean iNoReparameterization = FALSE);
  
  virtual ~CATCSCurve2DGM();
  
  /**
   * Get the parameter limits of the curve
   * @param oLow
   *     Lower bound of parametrization interval
   * @param oUp
   *     Upper bound of parametrization interval
   * @return
   *     Specifies if curve is periodic or bounded
   */
  CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride;

  /**
   * Set the curve as periodic
   */
  void  SetPeriodic();

  /**
  * Evaluate the 2D curve point or/and derivative at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oaPoint
  *    Evaluated coordinates (no evaluation is done if null)
  * @param oaFirstDeriv
  *    Evaluated first derivative (no evaluation is done if null)
  * @param oaSecondDeriv
  *    Evaluated second derivative (no evaluation is done if null)
  * @param oaThirdDeriv
  *    Evaluated third derivative (no evaluation is done if null)
  */
  void Evaluate2D(double iT,
                  double* oaPoint,
                  double* oaFirstDeriv,
                  double* oaSecondDeriv,
                  double* oaThirdDeriv = 0) CATCDSOverride;

  /**
  * Get the number of parametric discontinuities
  */
  int GetNbOfDiscontinuities() CATCDSOverride;

  /**
  * Fill the array of parameter values where there are discontinuities
  * (array allocated by caller)
  */
  void GetDiscontinuitiesParams(double *oaValues) CATCDSOverride;

  /**
  * For a given discontinuity index (1-based), side and parameter,
  * return point, first and second derivatives
  * (arrays allocated by caller)
  */
  void EvaluateAtDiscontinuity2D(int iIdx,
                                 CATDiscontinuitySide iSide,
                                 double iT,
                                 double* oaPoint,
                                 double* oaFirstDeriv,
                                 double* oaSecondDeriv,
                                 double* oaThirdDeriv = 0) CATCDSOverride;

  /**
  * Compute curve length between two parameters
  * @param iStart
  *    Start parameter
  * @param iEnd
  *    End parameter
  * @param oLength
  *    Computed length
  * @return
  *    FALSE if computation failed
  */
  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) CATCDSOverride;

  /**
  * Compute curve curvature at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oCurvature
  *    Computed curvature
  * @return
  *    FALSE if computation failed
  */
  CATCDSBoolean EvaluateCurvature(double iT, double &oCurvature) CATCDSOverride;

  /**
  * Compute curve curvature derivative at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oCurvatureDeriv
  *    Computed curvature deriv
  * @return
  *    FALSE if computation failed
  */
  CATCDSBoolean EvaluateCurvatureDeriv(double iT, double &oCurvatureDeriv) CATCDSOverride;

  /**
  * Get the 2D box corresponding to a sub-interval of the parametric domain, on a 2D curve
  * This method computes nothing on a non-2D curve
  * @param iWMin
  *    Lower bound of the parametric interval
  * @param iWMax
  *    Upper bound of the parametric interval
  * @param oBox
  *    Pointer to the 2D box, null if not implemented for the given object
  */
  void Get2DBoundingBoxForSubDomain(double iWMin, double iWMax, CATCDSBox2D *& oBox) CATCDSOverride;

  /**
   * Applies an affine transformation to the geometry.
   * @param iMatrix
   *   A matrix containing a rotation in two-dimensional space as 2x2
   *   submatrix and a translation at the last column. The last row of the
   *   matrix is dummy.
   */
  void ApplyTransformation2D(double iMatrix[3][3]) CATCDSOverride;

  void GetDirection2D(double &oX, double &oY) CATCDSOverride;

  void SetDirection2D(double iX, double iY) CATCDSOverride;

  CATCDSBoolean IsClosed(CATCSCurveGMContinuity & oClosureContinuity);

  CATCSCurve* Clone() const CATCDSOverride;

  CATCDSBoolean ComputeDistanceMinParameter(double iPointCoords[2], double & oParameter) CATCDSOverride;

  CATCDSBoolean ComputeDistanceMinParameter(CATCSCurve2D * iOtherCurve, double & oParamOnThisCurve, double & oParamOnTheOtherCurve);

  virtual void SetSketch(CATCSSketch* pSketch);

  // Stream/Unstream
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength);
  CATCDSBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

  // internal use
#ifdef CATCDSGMINFRA_IMP
  inline CATCSCurve2DGMImp* GetImplementation() {return _pImp;}
#else
  inline CATCSCurve2DCGMImp* GetImplementation() { return _pImp; }
#endif

private:
  CATCSCurve2DGM(const CATCSCurve2DGM & iCurveGM);
#ifdef CATCDSGMINFRA_IMP
  CATCSCurve2DGMImp *_pImp;
#else
  CATCSCurve2DCGMImp *_pImp;
#endif
};

//-----------------------------------------------------------------------

#endif
