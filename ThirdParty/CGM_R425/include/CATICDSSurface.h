#ifndef CATICDSSurface_H
#define CATICDSSurface_H

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
 * @SKIP
 *
 * A callback for parametric surface.
 * Provides an information about parameters limits, and evaluators
 * for surfaces and its derivatives.
 */
class ExportedByCDSInterface CATICDSSurface : public CATICDSGeometryLeaf
{
public:
  
  /**
   * Get the limits for first parameter of the curve
   * @param oLow
   *     Lower bound of parametrization interval
   * @param oUp
   *     Upper bound of parametrization interval
   * @return
   *     Specifies if first paramerter is periodic or bounded
   */
  virtual CATCDSParamType GetFirstLimits(double &oLow, double &oUp) = 0;

  /**
   * Get the limits for second parameter of the curve
   * @param oLow
   *     Lower bound of parametrization interval
   * @param oUp
   *     Upper bound of parametrization interval
   * @return
   *     Specifies if second paramerter is periodic or bounded
   */
  virtual CATCDSParamType GetSecondLimits(double &oLow, double &oUp) = 0;

  /**
   * Evaluate the curve surface or/and derivative at given parameters
   * @param ipFactory.
   *   Pointer to the instance of CATICDSFactory to use.
   * @param iU
   *    Evaluation first parameter "u".
   * @param iV
   *    Evaluation second parameter "v".
   * @param oaPoint
   *    Evaluated coordinates (no evaluation is done if null)
   * @param oaDerivWithFirstParam
   *    Evaluated first derivative with respect to du (no evaluation is done if null)
   * @param oaDerivWithSecondParam
   *    Evaluated first derivative with respect to dv (no evaluation is done if null)
   * @param oaSecondDeriv_du_du
   *    Evaluated second derivative with respect to du^2 (no evaluation is done if null)
   * @param oaSecondDeriv_du_dv
   *    Evaluated second derivative with respect to du*dv (no evaluation is done if null)
   * @param oaSecondDeriv_dv_dv
   *    Evaluated second derivative with respect to dv^2 (no evaluation is done if null)
   */
  virtual void Evaluate(double  iU, double  iV,
                        double* oaPoint,
                        double* oaDerivWithFirstParam,
                        double* oaDerivWithSecondParam,
                        double* oaSecondDeriv_du_du,
                        double* oaSecondDeriv_du_dv,
                        double* oaSecondDeriv_dv_dv) = 0;

  virtual ~CATICDSSurface() {}
};

#endif
