#ifndef CATICDSMonoParametric2D_H
#define CATICDSMonoParametric2D_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"
#include "CATICDSGeometryLeaf.h"

class CATICDSFactory;

/**
 * A callback for parametric curves, line segments and conic arcs
 * Provides an information about parameter limits, and evaluators
 * for curves and its derivative.
 */
class ExportedByCDSInterface CATICDSMonoParametric2D : public CATICDSGeometryLeaf
{
public:

  /**
   * Get the parameter limits of the curve
   * @param oLow
   *     Lower bound of parametrization interval
   * @param oUp
   *     Upper bound of parametrization interval
   * @return
   *     Specifies if curve is periodic or bounded
   *
   * @RETURNNAME type
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
                          double oaPoint[2],
                          double oaFirstDerivative[2],
                          double oaSecondDerivative[2]) const = 0;

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
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) const = 0;

  virtual ~CATICDSMonoParametric2D() {}
};

#endif
