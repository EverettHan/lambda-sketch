#ifndef CATICDSBBoxCurveAdapter_H
#define CATICDSBBoxCurveAdapter_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSInline.h"
#include "CATCDSBoolean.h"
#include "CATICDSBBoxCurve.h"

/**
 * @SKIP
 *
 * Abstract class that specifies an implementation
 * of black box dependent curves.
 */
class ExportedBySolverInterface CATICDSBBoxCurveAdapter
{
public:

  /** Destructor. */
  CATCDSInline virtual ~CATICDSBBoxCurveAdapter();
  
  /** Retreive curve. */
  CATCDSInline CATICDSBBoxCurve *GetCurve() const;
  
  /**
   * Regenerate curve, called each time a dependency has changed.
   */
  virtual CATCDSBoolean Regenerate() = 0;
  
  /**
   * Get the parameter limits of the curve
   * @param oLow
   *     Lower bound of parametrization interval
   * @param oUp
   *     Upper bound of parametrization interval
   * @return
   *     Specifies if curve is periodic or bounded
   */
  virtual CATCDSParamType GetLimits(double &oLow, double &oUp) const = 0;

  /**
   * Evaluate the curve point or/and derivative at given parameter's value.
   * @param iT
   *    Evaluation parameter.
   * @param oaPoint
   *    Evaluated coordinates (no evaluation is done if null).
   * @param oaFirstDeriv
   *    Evaluated first derivative (no evaluation is done if null).
   * @param oaSecondDeriv
   *    Evaluated second derivative (no evaluation is done if null).
   */
  virtual void Evaluate(double iT,
                        double oaPoint[3],
                        double oaFirstDeriv[3],
                        double oaSecondDeriv[3],
                        double oaThirdDeriv[3] = 0) const = 0;
  
  /**
   * Get the number of parametric discontinuities.
   */
  virtual int GetNbOfDiscontinuities() const = 0;

  /**
   * Fill the array of parameter values where there are discontinuities
   * (array allocated by caller).
   */
  virtual void GetDiscontinuitiesParams(double *oaValues) const = 0;

  /**
   * For a given discontinuity index (1-based), side and parameter,
   * return point, first and second derivatives (arrays allocated by caller).
   */
  virtual void EvaluateAtDiscontinuity(int iIdx,
                                       CATCDSDiscontinuitySide iSide,
                                       double iT,
                                       double oaPoint[3],
                                       double oaFirstDeriv[3],
                                       double oaSecondDeriv[3],
                                       double oaThirdDeriv[3] = 0) const = 0;

  /**
   * Compute curve length between two parameters.
   * @param iStart
   *    Start parameter
   * @param iEnd
   *    End parameter
   * @param oLength
   *    Computed length
   * @return
   *   TRUE if computation succeded. If FALSE is returned then a rough 
   *  approximation will be computed using Evaluate, which will produce
   *  lower quality evaluations for the solver.
   */
  virtual CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) const = 0;

private:

  /** Curve container. */
  CATICDSBBoxCurve *_pCurve;
  friend CATICDSBBoxCurve* CATICDSBBoxCurve::Create(CATICDSFactory*, CATICDSBBoxCurveAdapter*);
};

CATCDSInline CATICDSBBoxCurveAdapter::~CATICDSBBoxCurveAdapter() {
  _pCurve = 0;}

CATCDSInline CATICDSBBoxCurve *CATICDSBBoxCurveAdapter::GetCurve() const {
  return _pCurve;}

#endif
