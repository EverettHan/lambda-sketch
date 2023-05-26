// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSWBExpression.h
// Header definition of CATCSWBExpression
//
//===================================================================
//
// Usage notes: A class for White Boxes expression support in CDS.
//
//===================================================================
//
//  May 2013  Creation                                          FCX
//===================================================================
#ifndef CATCSWBExpression_h
#define CATCSWBExpression_h

#include "CATCSEquation.h"
#include "CATWBVariable.h"
#include "CATCSVariable.h"
#include "CATCSEquation.h"
#include "CATCDSListP.h"

class CATWBFactory;
class CATWBEquation;
class CATCDSStream;
CATCDSLISTP_FORWARD(CATWBVariable);

//-----------------------------------------------------------------------

/**
 * An algebraic expression constructed from a WhiteBox expression.
 */
class ExportedBySolverInterface CATCSWBExpression
{
public:
  /**
   * Constructs an instance of the expression.
   * @param iExpression
   *   A pointer to the WB expression
   */
  CATCSWBExpression(CATWBExpression * iExpression);

  CATCSWBExpression(const CATCSWBExpression & iExpression);
  
  ~CATCSWBExpression();

  /**
   * Allows to map CATCSVariables to CATWBVariables used in the WB expression
   * this method must be called once before any evaluation
   * @param iWBVariableList
   *   List of WB variables (at least all the variables used in this WB expression)
   * @param iCSVariableList
   *   List of corresponding CS variables
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the mapping is successful,
   *     <li><tt>1</tt> - otherwise.
   *   </ul>
   */
  int SetVariablesMapping(CATCDSLISTP(CATWBVariable) &iWBVariableList, CATCDSLISTP(CATCSVariable) &iCSVariableList);

  /**
   * Evaluates the expression.
   * @param iaX
   *   An array of values corresponding to the variables.
   * @param oValue
   *   A value of the expression.
   */
  int Eval(double *iaX, double &oValue);

  /**
   * Computes partial derivatives of the expression.
   * @param iaX
   *   An array of values corresponding to the variables.
   * @param oaDX
   *   An array of the partial derivatives.
   */
  int EvalGradient(double *iaX, double *oaDX);

  /**
  * Gets type of the WB expression
  */
  CATWBExpressionType GetWBExpressionType() const;

  /**
  * Get the WB expression
  */
  inline CATWBExpression* GetWBExpression() {return _pWBExpression;}

  /**
  * Get the number of variables
  */
  inline int GetNbOfVariables() {return _nVariables;}

  /**
  * Get one WB variable
  */
  inline CATWBVariable * GetWBVariable(int idx) {return _aWBVariables[idx];}

  /**
  * Get one variable
  */
  inline CATCSVariable * GetVariable(int idx) {return _aVariables[idx];}

  /**
  * Removes a variable pointer from the expression variable list
  * and sets the expression as invalid if iVariable was involved
  */
  void RemoveVariable(CATCSVariable * iVariable);

  /**
  * Checks the validity of the expression
  */
  inline CATCDSBoolean IsValid() {return _IsValid;}

#ifdef CDS_DEBUG
  void WriteExpression(CATCDSStream& ioStream, const CATCDSString iaNames[] = 0, unsigned int iaMapVars[] = 0) const;
#endif

  CATCDSBoolean IsModified();
  void SetModified(CATCDSBoolean iModified = TRUE);

  int DifferentiateExpression();

  /**
   * DO NOT USE
   * TEST ONLY
   */
  void Scale(double *iVariableScale);

protected:

  CATCSVariable   ** _aVariables;
  CATWBVariable   ** _aWBVariables;
  int _nVariables;

  CATWBFactory     * _pWBFactory;
  CATWBExpression  * _pWBExpression;
  CATWBExpression ** _pWBFirstDeriv;

  CATCDSBoolean _Modified;
  CATCDSBoolean _IsValid;
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSWBExpression, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif
