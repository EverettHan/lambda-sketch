// COPYRIGHT Dassault Systemes 2012
//===================================================================

// CATCSMonoParametric.h
// Header definition of CATCSMonoParametric

//===================================================================

// Usage notes:
//   This abstract class is dedicated to represent all objects that can be seen as curves, with one single parameter
//   and an explicit or default parameterization
//   The subclasses are: CATCSCurve, CATCSLine, CATCSCircle, CATCSCirline, CATCSEllipse, CATCSParabola, CATCSHyperbola
//   All objects have G1 continuity

//===================================================================

//  Feb 2012  Creation:                   chu 

//===================================================================
#ifndef CATCSMonoParametric_H
#define CATCSMonoParametric_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCDSBoolean.h"
#include "CATCSGeometryLeaf.h"
#include "CATCDSEnums.h"

class CATCDSBox2D;

//-----------------------------------------------------------------------

/**
 * A callback for parametric curves, line segments and conic arcs
 * Provides an information about parameter limits, and evaluators
 * for curves and its derivative.
 */
class ExportedBySolverInterface CATCSMonoParametric: public CATCSGeometryLeaf
{
public:
  
  CATCSMonoParametric();
  virtual ~CATCSMonoParametric();
  
  /**
  * Get the type of the mono-parametric
  * An application should never re-define these methods.
  */ 
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  /**
   * Get the parameter limits of the curve
   * @param oLow
   *     Lower bound of parametrization interval
   * @param oUp
   *     Upper bound of parametrization interval
   * @return
   *     Specifies if curve is periodic or bounded
   */
  virtual CATParamType GetLimits(double &oLow, double &oUp) = 0;

  /**
  * Deprecated: do not use
  */
  virtual void Evaluate(double iT,
                        double* oaPoint,
                        double* oaFirstDeriv,
                        double* oaSecondDeriv);

  /**
  * Evaluate the curve point or/and derivative at given parameter's value
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
  virtual void Evaluate(double iT,
                        double* oaPoint,
                        double* oaFirstDeriv,
                        double* oaSecondDeriv,
                        double* oaThirdDeriv);

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
  virtual void Evaluate2D(double iT,
                          double* oaPoint,
                          double* oaFirstDeriv,
                          double* oaSecondDeriv,
                          double* oaThirdDeriv = 0);

  /**
  * Get the number of parametric discontinuities
  */
  virtual int GetNbOfDiscontinuities();

  /**
  * Fill the array of parameter values where there are discontinuities
  * (array allocated by caller)
  */
  virtual void GetDiscontinuitiesParams(double *oaValues);

  /**
  * Deprecated: do not use
  */
  virtual void EvaluateAtDiscontinuity(int iIdx,
                                       CATDiscontinuitySide iSide,
                                       double iT,
                                       double* oaPoint,
                                       double* oaFirstDeriv,
                                       double* oaSecondDeriv);

  /**
  * For a given discontinuity index (1-based), side and parameter,
  * return point, first, second and third derivatives
  * (arrays allocated by caller)
  */
  virtual void EvaluateAtDiscontinuity(int iIdx,
                                       CATDiscontinuitySide iSide,
                                       double iT,
                                       double* oaPoint,
                                       double* oaFirstDeriv,
                                       double* oaSecondDeriv,
                                       double* oaThirdDeriv);

  /**
  * For a given discontinuity index (1-based), side and parameter,
  * return point, first and second derivatives
  * (arrays allocated by caller)
  */
  virtual void EvaluateAtDiscontinuity2D(int iIdx,
                                         CATDiscontinuitySide iSide,
                                         double iT,
                                         double* oaPoint,
                                         double* oaFirstDeriv,
                                         double* oaSecondDeriv,
                                         double* oaThirdDeriv = 0);

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
  virtual CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength);

  /**
  * Compute curve curvature at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oCurvature
  *    Computed curvature
  * @return
  *    FALSE if computation failed
  */
  virtual CATCDSBoolean EvaluateCurvature(double iT, double &oCurvature) = 0;

  /**
  * Compute curve curvature derivative at given parameter's value
  * @param iT
  *    Evaluation parameter
  * @param oCurvatureDeriv
  *    Computed curvature deriv
  * @return
  *    FALSE if computation failed
  */
  virtual CATCDSBoolean EvaluateCurvatureDeriv(double iT, double &oCurvatureDeriv) = 0;

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
  virtual void Get2DBoundingBoxForSubDomain(double iWMin, double iWMax, CATCDSBox2D *& oBox);
 

  protected :

    // Get the initial limits, not taking into account a possible extrapolation
    // This method must be redefined in all classes that implement Extrapolate() method
    virtual CATParamType GetInitialLimits(double &oInitialLow, double &oInitialUp);
};

//-----------------------------------------------------------------------

#endif
