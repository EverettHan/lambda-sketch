// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATCSEquation.h
// Header definition of CATCSEquation.
//
// This class represents an implicit equation f(V0,...,Vn-1) = 0
// linking n variables V0,...,Vn-1. It's usefull to define laws (with 2
// variables including a "time" variable) and more generally engineering
// equations.
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2006  Creation:                    Andrey CHUGUEV
//===================================================================
#ifndef CATCSEquation_H
#define CATCSEquation_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSConstraint.h"

class CATCSVariable;
class CATCDSEquation;

//-----------------------------------------------------------------------

/**
 * A basic class for all equations.
 */
class ExportedBySolverInterface CATCSEquation : public CATCSConstraint
{
public:
  /**
   * Constructs an instance of the equation.
   */
  CATCSEquation();

  /**
   * Constructs an instance of the equation.
   * @param iNbVariables
   *   A number of variables.
   * @param iaVariables
   *   An array of variables.
   */
  CATCSEquation(int iNbVariables, CATCSVariable **iaVariables);

  virtual ~CATCSEquation();

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

  /**
   * Get the number of variables of the equation.
   * @return The number of variables.
   */
  int GetNbOfVariables() const;

  /**
   * Retrieves variables of the equation.
   * @param oNbVariables
   *   A number of variables.
   * @param oaVariables
   *   An array of variables.
   */
  virtual int GetVariables(int &oNbVariables, CATCSVariable **&oaVariables);

  virtual void SetVariables(int iNbVariables, CATCSVariable **iaVariables);

  /**
   * Removes variable from the equation.
   * @param iVar
   *   An index of variables.
   */
  void RemoveVariable(int iVar);

  /**
   * Retrieves tolerance of the equation.
   * @return
   *   A tolerance of the equation.
   */
  double GetTolerance() const;

  /**
   * Sets tolerance of the equation.
   * @param iTolerance
   *   A tolerance of the equation.
   */
  void SetTolerance(double iTolerance);

  /**
   * Evaluates the equation.
   * @param iaX
   *   An array of values corresponding to the variables.
   * @param oValue
   *   A value of the equation.
   */
  virtual int Eval(double *iaX, double &oValue) = 0;

  /**
   * Computes partial derivatives of the equation.
   * @param iaX
   *   An array of values corresponding to the variables.
   * @param oaDX
   *   An array of the partial derivatives.
   */
  virtual int EvalGradient(double *iaX, double *oaDX);

  /**
   * Retrieves clone of the equation.
   * @return
   *   A clone of the equation.
   */
  virtual CATCDSEquation *GetEquation();

  /**
   * DO NOT USE
   * TEST ONLY
   */
  virtual void Scale(double *iVariableScale);

protected:
  void GetLocalVariablesScale(double const *iaGlobalScales, double *&oLocalScales);
  void ScaleEquation(double *iVariableScale, CATCDSEquation &iEquation);

  CATCSVariable **_aVariables;
  int _nVariables;
  double _tolerance;
};

//-----------------------------------------------------------------------

#endif
