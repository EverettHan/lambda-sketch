#ifndef CATICDSBBoxCurve2DAdapter_H
#define CATICDSBBoxCurve2DAdapter_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATCDSAdvancedEnums.h"
#include "CATCDSInline.h"
#include "CATCDSBoolean.h"
#include "CATICDSBBoxCurve2D.h"
#include "CATCDSAssert.h"

/**
 * @SKIP
 *
 * Abstract class that specifies an implementation
 * of black box dependent curves.
 */
class ExportedBySolverInterface CATICDSBBoxCurve2DAdapter
{
public:

  /** Destructor. */
  CATCDSInline virtual ~CATICDSBBoxCurve2DAdapter();

  /** Retreive curve. */
  CATCDSInline CATICDSBBoxCurve2D *GetCurve() const;

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
   * Evaluate the curve point or/and derivative at given parameter's value
   * @param iT
   *    Evaluation parameter
   * @param oaPoint
   *    Evaluated coordinates (no evaluation is done if null)
   * @param oaFirstDeriv
   *    Evaluated first derivative (no evaluation is done if null)
   * @param oaSecondDeriv
   *    Evaluated second derivative (no evaluation is done if null)
   */
  virtual void Evaluate2D(double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv = 0) const = 0;

  /**
   * Get the number of parametric discontinuities
   */
  virtual int GetNbOfDiscontinuities() const = 0;

  /**
   * Fill the array of parameter values where there are discontinuities
   * (array allocated by caller)
   */
  virtual void GetDiscontinuitiesParams(double *oaValues) const = 0;

  /**
   * For a given discontinuity index (1-based), side and parameter,
   * return point, first and second derivatives (arrays allocated by caller)
   */
  virtual void EvaluateAtDiscontinuity2D(int iIdx,
    CATCDSDiscontinuitySide iSide,
    double iT,
    double* oaPoint,
    double* oaFirstDeriv,
    double* oaSecondDeriv,
    double* oaThirdDeriv = 0) const = 0;

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
  virtual CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) const = 0;

  virtual void GetDirection2D(double &oX, double &oY) const = 0;

  virtual CATCDSBoolean IsMatched(CATCSType iType) const = 0;

private:

  /** Curve2D container. */
  CATICDSBBoxCurve2D *_pCurve;
  friend CATICDSBBoxCurve2D* CATICDSBBoxCurve2D::Create(CATICDSFactory*, CATICDSBBoxCurve2DAdapter*);
};

CATCDSInline CATICDSBBoxCurve2DAdapter::~CATICDSBBoxCurve2DAdapter() {
  _pCurve = 0;
}

CATCDSInline CATICDSBBoxCurve2D *CATICDSBBoxCurve2DAdapter::GetCurve() const {
  return _pCurve;
}

#endif
