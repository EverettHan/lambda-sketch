#ifndef CATICDSBBoxEquationAdapter_H
#define CATICDSBBoxEquationAdapter_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSInline.h"
#include "CATCDSBoolean.h"
#include "CATICDSBBoxEquation.h"

/**
 * @SKIP
 *
 * Abstract class that specifies a implementation of black box equation.
 */
class CATICDSBBoxEquationAdapter
{
public:

  /** Destructor. */
  CATCDSInline virtual ~CATICDSBBoxEquationAdapter();
  
  /** Retreive equation. */
  CATCDSInline CATICDSBBoxEquation *GetEquation() const;
  
  /**
   * Evaluates the equation.
   * @param iaX
   *   An array of values corresponding to the variables in the equation.
   * @param oValue
   *   The returned output value which is the result of the evaluation.
   * @return
   *   0 is returned for a successful evaluation.
   */
  virtual int Eval(double *iaX, double &oValue) const = 0;

  /**
   * Computes partial derivatives of the equation.
   * @param iaX
   *   An array of values corresponding to the variables in the equation.
   * @param oaDX
   *   The returned computed values of the partial derivatives.
   * @return
   *   0 is returned for a successful evaluation. If 1 is returned then
   *   finite differences using Eval will be used to estimated it, which
   *   will lead to lower quality evaluations.
   */
  virtual int EvalGradient(double *iaX, double *oaDX) const = 0;

private:
  
  /** Equation container. */
  CATICDSBBoxEquation *_pEquation;
  friend CATICDSBBoxEquation* CATICDSBBoxEquation::Create(CATICDSFactory*, int, CATICDSVariable**, CATICDSBBoxEquationAdapter*);
};

CATCDSInline CATICDSBBoxEquationAdapter::~CATICDSBBoxEquationAdapter() {
  _pEquation = 0;}

CATCDSInline CATICDSBBoxEquation *CATICDSBBoxEquationAdapter::GetEquation() const {
  return _pEquation;}

#endif
