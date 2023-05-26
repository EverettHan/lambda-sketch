#ifndef CATICDSEquation_H
#define CATICDSEquation_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSConstraint.h"

class CATICDSVariable;

/**
 * Base classfor all CDS equations classes.
 */
class ExportedByCDSInterface CATICDSEquation : public CATICDSConstraint
{
public:
  /**
   * Retrieves the number of variables of the equation.
   * @return The number of variables.
   */
  virtual int GetNbOfVariables() const = 0;

  /**
   * Retrieves variables of the equation.
   * @param oNbVariables
   *   Returned number of variables.
   * @param oapVariables
   *   Returned array of variables.
   *
   * @SIZE oapVariables oNbVariables
   */
  virtual void GetVariables(int &oNbVariables, CATICDSVariable **&oapVariables) const = 0;

  /**
   * Retrieves the tolerance value of the equation.
   * @return
   *   The tolerance of the equation.
   */
  virtual double GetTolerance() const = 0;

  /**
   * Sets the tolerance value of the equation.
   * @param iTolerance
   *   Input tolerance value of the equation.
   */
  virtual void SetTolerance(double iTolerance) = 0;

  /**  
   * Evaluates the equation.
   * @param iaX
   *   An array of values corresponding to the variables in the equation.
   * @param oValue
   *   The returned output value which is the result of the evaluation.
   * @return
   *   0 is returned for a successful evaluation.
   *
   * @SIZE iaX GetNbOfVariables()
   *
   * @CHECKRESULT 0
   */
  virtual int Eval(double *iaX, double &oValue) const = 0;

  /**
   * Computes partial derivatives of the equation.
   * @param iaX
   *   An array of values corresponding to the variables in the equation.
   * @param oaDX
   *   The returned computed values of the partial derivatives.
   * @return
   *   0 is returned for a successful evaluation.
   *
   * @SIZE iaX GetNbOfVariables()
   * @SIZE oaDX GetNbOfVariables()
   *
   * @CHECKRESULT 0
   */
  virtual int EvalGradient(double *iaX, double *oaDX) const = 0;

  virtual ~CATICDSEquation() {}
};

#endif
