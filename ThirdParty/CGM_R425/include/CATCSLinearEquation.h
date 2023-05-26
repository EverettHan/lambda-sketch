// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATCSLinearEquation.h
// Header definition of CATCSLinearEquation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2008  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSLinearEquation_H
#define CATCSLinearEquation_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSEquation.h"

class CATCDSEquation;
class CATCDSQuadraticEquation;

//-----------------------------------------------------------------------

/**
 * An algebraic equation which consists of linear terms only.
 */
class ExportedBySolverInterface CATCSLinearEquation : public CATCSEquation
{
public:
  /**
   * Constructs an instance of the equation.
   */
  CATCSLinearEquation();

  /**
   * Constructs an instance of the equation.
   * @param iNbVariables
   *   A number of variables.
   * @param iaVariables
   *   An array of variables.
   */
  CATCSLinearEquation(int iNbVariables, CATCSVariable **iaVariables);

  virtual ~CATCSLinearEquation();

  /**
   * Retrieves type of the entity.
   * @return
   *   Type of the entity.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
   * Checks whether the entity is matched to a specific type. The entity can
   * be casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  void SetVariables(int iNbVariables, CATCSVariable ** iaVariables) CATCDSOverride;
  
  /**
   * Evaluates the equation.
   * @param iaX
   *   An array of values corresponding to the variables.
   * @param oValue
   *   A value of the equation.
   */
  virtual int Eval(double *iaX, double &oValue) CATCDSOverride;

  /**
   * Computes partial derivatives of the equation.
   * @param iaX
   *   An array of values corresponding to the variables.
   * @param oaDX
   *   An array of the partial derivatives.
   */
  virtual int EvalGradient(double *iaX, double *oaDX) CATCDSOverride;

  /**
   * Retrieves clone of the equation.
   * @return
   *   A clone of the equation.
   */
  virtual CATCDSEquation *GetEquation() CATCDSOverride;

  /**
   * Sets linear term of the equation.
   * @param iVal
   *   A value of the coefficient.
   * @param iIdx
   *   An index of the variable.
   */
  void SetLinear(double iVal, unsigned int iIdx);

  /**
   * Sets constant term of the equation.
   * @param iVal
   *   A value of the constant.
   */
  void SetConstant(double iVal);

  /**
   * Gets the value of a linear term.
   * @param iIdx
   *   Index of the variable
   * @return
   *   Value of the coefficient
   */
  double GetLinear(unsigned int iIdx);

  /**
   * Gets the value of the constant term.
   * @return
   *   Value of the constant term
   */
  double GetConstant();

  /**
   * For PLUG and test Infra
   * DO NOT USE
   * Underlying equation is currently a quadratic equation
   */
  void SetQuadratic(double iVal, unsigned int iIdx1, unsigned int Idx2);

  /**
   * DO NOT USE
   * TEST ONLY
   */
  virtual void Scale(double *iVariableScale) CATCDSOverride;

protected:
  CATCDSQuadraticEquation *_pEquation;
};

//-----------------------------------------------------------------------

#endif
