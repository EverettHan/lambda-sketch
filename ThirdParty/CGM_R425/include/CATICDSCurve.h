#ifndef CATICDSCurve_H
#define CATICDSCurve_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"
#include "CATICDSMonoParametric.h"

class CATICDSFactory;

/**
 * A geometry abstract class for parametric 3D curves.
 * Provides an information about parameter limits, and evaluators
 * for curves and its derivative.
 */
class ExportedByCDSInterface CATICDSCurve : public CATICDSMonoParametric
{
public:
  
  /**
   * Get the number of parametric discontinuities
   */
  virtual int GetNbOfDiscontinuities() const = 0;

  /**
   * Fill the array of parameter values where there are discontinuities
   * (array allocated by caller)
   * 
   * @SIZE oaValues GetNbOfDiscontinuities()
   */
  virtual void GetDiscontinuitiesParams(double *oaValues) const = 0;

  /**
   * For a given discontinuity index (1-based), side and parameter,
   * return point, first and second derivatives (arrays allocated by caller)
   */
  virtual void EvaluateAtDiscontinuity(int iIdx,
                                       CATCDSDiscontinuitySide iSide,
                                       double iT,
                                       double oaPoint[3],
                                       double oaFirstDerivative[3],
                                       double oaSecondDerivative[3]) const = 0;

  /**
   * Extend the parametric domain from [Low, Up] to [iNewLow, iNewUp], assuming iNewLow<Low and iNewUp>Up.
   * @param iNewLow
   *     New Lower bound of parametrization interval, must be inferior or equal to the old lower bound.
   * @param iNewUp
   *     New Upper bound of parametrization interval, must be superior or equal to the old upper bound.
   * @param iMode
   *     Extrapolation Mode.
   * @return
   *     FALSE if extrapolation is not allowed for the given curve and/or for the given extrapolation mode.
   */
  virtual CATCDSBoolean Extrapolate(double iNewLow, double iNewUp, CATCDSExtrapolMode iMode = exLINEAR) = 0;

  /**
   * Get extrapolation mode.
   */
  virtual CATCDSExtrapolMode GetExtrapolationMode() const = 0;

  virtual ~CATICDSCurve() {}
};

#endif
