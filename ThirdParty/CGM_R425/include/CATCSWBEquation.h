// COPYRIGHT Dassault Systemes 2011
//===================================================================
//
// CATCSWBEquation.h
// Header definition of CATCSWBEquation
//
//===================================================================
//
// Usage notes: A class for White Boxes support in CDS.
//
//===================================================================
//
//  Jun 2011  Creation                                          FCX
//===================================================================
#ifndef CATCSWBEquation_h
#define CATCSWBEquation_h

#include "CATCDSVirtual.h"
#include "CATCSEquation.h"
#include "CATWBVariable.h"
#include "CATCSVariable.h"
#include "CATCSEquation.h"
#include "CATCDSDebug.h"

class CATWBFactory;
class CATWBEquation;
class CATCDSStream;
CATCDSLISTP_FORWARD(CATWBVariable);
class CATCSWBExpression;

//-----------------------------------------------------------------------

/**
 * An algebraic equation constructed from a WhiteBox object.
 */
class ExportedBySolverInterface CATCSWBEquation : public CATCSEquation
{
public:
  /**
   * Constructs an instance of the equation from a WhiteBox equation.
   * @param iEquation
   *   A pointer to the WB equation
   */
  CATCSWBEquation(CATWBEquation * iEquation);

  /**
   * Constructs an instance of the equation from two CATCSWBExpression.
   * (corresponding to Expression1(v1,...,vn) = Expression2(v1,...,vn) or Expression1(v1,...,vn) = 0 if Expression2 is null)
   * @param iExpression1
   *   A pointer to the first expression
   * @param iExpression2
   *   A pointer to the second expression
   */
  CATCSWBEquation(CATCSWBExpression * iExpression1, CATCSWBExpression * iExpression2 = 0);

  virtual ~CATCSWBEquation();

  /**
   * Allows to map CATCSVariables to CATWBVariables used in the WB equation
   * this method must be called once before any evaluation
   * @param iWBVariableList
   *   List of WB variables (at least all the variables used in this WB equation)
   * @param iCSVariableList
   *   List of corresponding CS variables
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the mapping is successful,
   *     <li><tt>1</tt> - otherwise.
   *   </ul>
   */
  virtual int SetVariablesMapping(CATCDSLISTP(CATWBVariable) &iWBVariableList, CATCDSLISTP(CATCSVariable) &iCSVariableList);

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
  * Get Expression defined in the equation
  */
  CATWBExpression* GetExpression();

  CATWBVariable * GetVariable(int idx);
  virtual CATCSWBExpression* GetCSWBExpression();

  int GetWBVariables(int &oNbWBVariables, CATWBVariable **&oaWBVariables);

#ifdef CDS_DEBUG
  virtual void WriteEquation(CATCDSStream& ioStream,
                             const CATCDSString iaNames[] = 0,
                             unsigned int iaMapVars[] = 0) const;
#endif

  /**
   * DO NOT USE
   * TEST ONLY
   */
  virtual void Scale(double *iVariableScale) CATCDSOverride;

protected:
  CATWBEquation    * _pWBEquation;
  CATCSWBExpression * _pExpression;
  CATCDSBoolean _RightTermEquation;

public:
  // for CDS's public interfaces
  CATCSWBEquation();
  void SetWBEquation(CATWBEquation * iEquation);
  void SetWBExpression(CATCSWBExpression * iExpression1, CATCSWBExpression * iExpression2 = 0);
  CATWBEquation* GetWBEquation();
};

//-----------------------------------------------------------------------

#endif
