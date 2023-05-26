#ifndef CATICDSLinearEquation_H
#define CATICDSLinearEquation_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEquation.h"

class CATICDSFactory;

/**
 * An multi-variable algebraic equation that consists only of linear terms.
 */
class ExportedByCDSInterface CATICDSLinearEquation : public CATICDSEquation
{
public:
  
  /**
   * Sets a linear term of the equation.
   * @param iIdx
   *   An index of the variable.
   * @param iVal
   *   A value of the coefficient.
   */
  virtual void SetLinear(unsigned int iIdx, double iVal) = 0;

  /**
   * Gets the value of a linear term.
   * @param iIdx
   *   An index of the variable.
   * @return
   *   A value of the coefficient.
   */
  virtual double GetLinear(unsigned int iIdx) const = 0;

  /**
   * Sets the constant term of the equation.
   * @param iVal
   *   A value of the constant.
   */
  virtual void SetConstant(double iVal) = 0;

  /**
   * Gets the value of the constant term.
   * @return
   *   A value of the constant term.
   */
  virtual double GetConstant() const = 0;

  /**
   * Creates an instance of the CATICDSLinearEquation equation.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param inVariables
   *   Value that indicates the number of variables.
   * @param iapVariables
   *   Pointer to the array of variables.
   * @param iaLinearCoefficients
   *   Pointer to the array of linear coefficients.
   * @param iConstantTerm
   *   Value of the constant term.
   *
   * @SIZE iapVariables inVariables
   * @SIZE iaLinearCoefficients inVariables
   */
  static CATICDSLinearEquation* Create(CATICDSFactory* ipFactory,
                                       unsigned int inVariables,
                                       CATICDSVariable **iapVariables,
                                       double *iaLinearCoefficients,
                                       double iConstantTerm);

  virtual ~CATICDSLinearEquation() {}
};

#endif
