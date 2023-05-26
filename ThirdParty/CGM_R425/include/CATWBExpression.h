// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBExpression.h
// Header definition of CATWBExpression
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /06/06      Creation (Sergey Lipski)
//   /07/16 Q48  Performance (store parent links)
// 24/07/18 Q48  Make Eval methods const and buffers mutable (for printer)
// 10/12/18 Q48  Make IntegrateTable protected --> use Integrate method only
//                  - add pure virtual IntegrateTableProtected for implemtation
// 05/03/19 Q48  Add new const method for GetFactory
// 18/07/19 Q48  Add unique tag data for streaming
// 18/07/19 Q48  Add protected constructor for streaming
// 09/09/19 TE9  Make PartialEval virtual (implemented in Expression/Constant/Variable)
// 19/08/21 R1Y  IR-748300: Changed SetAllowBufferEval() access from protected to public
// 01/06/22 Q48  Add UpdateExprValue to recursively update expr values to current value
//===================================================================

#ifndef CATWBExpression_h
#define CATWBExpression_h

// ExportedBy
#include "WhiteBoxData.h"

// C++ 11
#include "CATCDSVirtual.h"

// CDS
#include "CATCDSBoolean.h"
#include "CATCDSListP.h"
#include "CATCDSArray.h"

// WBx
#include "CATWBTypes.h"
#include "CATWBLists.h"
#include "CATWBValue.h"
//#include "CATWBFactory.h" // for friend method declaration
class CATWBFactory;
class CATWBVariable;
class CATWBBlackBox;

struct CATWBProperty;

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

// Debug
#include "CATWBDebug.h"

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------
 /**
  * @brief The CATWBExpression class represents the structure which stores a formal expression.
  *
  * It can be represented as a tree diagram.
  *         @image html ExprTree.GIF
  * Each node represents : a constant, a variable or an operator (+, -, *, /, cos, sin, blackbox operator, ...).
  */
class ExportedByWhiteBoxData CATWBExpression 
{
  friend class CATWBIntegration;

public:
  /**
  *  @brief Constructor  (internal use)
  * @param[in] iFactory the factory where  the expression will be stored
  * @note To create an expression, use the <tt>CreateXXX</tt> methods of the <tt>CATWBFactory</tt> interface.
  */ 
  CATWBExpression(CATWBFactory & iFactory, const CATWBExpressionType iType);

  /**
  *  @brief Destructor  
  */
  virtual ~CATWBExpression();

  /**
  * @brief Get the factory where is stored the current expression
  * @return the factory associated to the current expression
  */
  const CATWBFactory* GetFactory() const;

  /**
  * @brief Get the factory where is stored the current expression
  * @return the factory associated to the current expression
  */
  CATWBFactory* GetFactory();

  /**
  * @brief Get the environment defined for the factory
  * @return the environment associated to the factory
  */
  const CATWBEnvironment& GetEnvironment() const;

  /**
  * @brief Get the type of the current expression (etNone,etVariable,etConstant,etSum, ...)
  * @return the type of the current expression
  */
  CATWBExpressionType GetType() const;


  /**
  * @brief Get the number of arguments of the current expression (not null in case of  operator)
  * @return 0 if the term is a constant or  a variable, otherwise  the number of children of the operator
  */
  virtual int GetNbOfChildren() const = 0;

   /**
  * @brief Get the <tt>iIdx</tt>-th argument of the current expression when it represents an operation or a function
  * @param [in] iIdx the index of the term involved in the current operation
  * @return the <tt>iIdx</tt>-th argument 
  */
  virtual CATWBExpression * GetChild(int iIdx) = 0;

    /**
  * @brief Get the iIdx-th argument of the current expression when it represents an operation or a function
  * @param [in] iIdx the index of the term involved in the current operation
  * @return the <tt>iIdx</tt>-th argument 
  */
  virtual const CATWBExpression * GetChild(int iIdx) const = 0;

   /**
  * @brief Add an addtionnal argument  to an operation or function  when it is possible (algebraic operator)
  * @param [in] ipChild the term to add 
  * @return TRUE if the term is added, otherwise FALSE
  */
  virtual CATCDSBoolean AddChild(CATWBExpression * ipChild);

 /**
  * @brief Remove the <tt>iIdx</tt>-th operand of the current operation when it is possible (algebraic operator)
  * @param [in] iIdx the index of the term to remove
  * @return TRUE if the term is removed, otherwise FALSE
  */
  virtual CATCDSBoolean RemoveChild(int iIdx);

   /**
  * @brief Replace the <tt>iIdx</tt>-th argument by  the term <tt>ipChild</tt>  in the current operator 
  * @param [in] iIdx the index of the term to remove
  * @param [in] ipChild the replacing term 
  * @return TRUE if the term is replaced, otherwise FALSE
  */
  virtual CATCDSBoolean ReplaceChild(int iIdx, CATWBExpression * ipChild) = 0;

  /**
  * @brief Replace the variable <tt>ipVar</tt> by  the term <tt>ipNewTerm</tt> in the current expression
  * @param[in] ipVar the variable to replace
  * @param[in] ipNewTerm the replacing term  
  * @return TRUE except if the expression is equal to the variable (to avoid the ambiguities)
  */
  CATCDSBoolean ReplaceVar(CATWBVariable* ipVar, CATWBExpression * ipNewTerm);

  // /**
  //* @brief Replace a BlackBox <tt>*ipBBbox</tt> by  the term <tt>ipNewTerm</tt> in the current expression
  //* @param[in] ipBBbox the BlackBox to replace
  //* @param[in] ipNewTerm the replacing term  
  //* @return TRUE except if the expression is equal to the BlacBox (to avoid the ambiguities)
  //*/
  //CATCDSBoolean ReplaceBBx(CATWBBlackBox *ipBBbox, CATWBExpression *ipNewTerm );

   /**
  * @brief Set the <tt>iIdx</tt>-th parameter of the current expression when it represents an operator. Used in the <tt>CreateStep</tt> method of the <tt>CATWBFactory</tt> interface.
  * @param [in] iIdx the index of the parameter to set
  * @param [in] iParam the parameter value
  */
  virtual void SetParameter(int iIdx, double iParam);

  /**
  * @brief Get the <tt>iIdx</tt>-th parameter of the current expression when it represents an operator. 
  * @param [in] iIdx the index of the parameter to get
  * @return the parameter value
  */
  virtual double GetParameter(int iIdx) const;

  /**
  * @brief Get the number of parameters of the current expression when it represents an operator. 
  * @return the number of parameters
  */
  virtual int GetNbOfParameters() const;


  /**
  *  @brief  Fill an array whose dimension is the number of the variables in the factory with TRUE at the i-th element if the i-th  variable is used in this expression and FALSE if not
  *  @param[in] iaVariables the array to complete
  *  @remark The array must be allocated by the application, AND INITIALIZED TO FALSE.
  */
  virtual void FillPresentVariables(CATCDSBoolean * iaVariables) const = 0;

  /**
  * @brief Fills an array of the pointers of the variables which are used in the expression.
  * @param[out] opWBVariableArray the array of the pointers of the variables 
  * @return the size of the array.
  * @attention  Since the caller does not know the number of the involved variables, the creation of the array CATWBVariable  ** is done in the method
  * @attention  to avoid any memory leak, the object should be empty before call !
  * @attention  the caller will have to delete the object after use  !!!!
  */
  int FindPresentVariables(CATWBVariable  **& opWBVariableArray) const;


  /**
  * @brief Get the value recorded for the current expression.
  * The value can be the result of a setting (constant, variable) or of an evaluation
  * @return the value of the current expression.
  */
  virtual const CATWBValue & GetExprValue() const;

  /**
  * @brief Set the value of the current expression.
  * @param[in] iValue the value to record
  */
  virtual void SetExprValue(const CATWBValue & iValue) /*const*/;

  /**
  * @brief Set the value of the current expression.
  * @param[in] iValue the value to record
  */
  virtual void UpdateExprValue(const CATCDSBoolean iRecursive) CATCDSFinal;

  /**
  * @brief Evaluate the expression provided that every variable is affected to a value.
  * @param[out] oValue the result of the evaluation
  * @note these evaluators use buffers (they should not be overloaded in derivated classes).
  * @note the buffer is reseted during the evaluation of the system of equations / of the equation the expression belongs to.
  * @attention  If you launch independant evaluations, do not forget to call ResetBuffer before each call
  */
  void Eval(CATWBValue & oValue) const;

   /**
  * @brief Evaluate the expression provided that every variable is affected to a value.
  * @return the result of the evaluation 
  * @note Used in DoEval methods.
  *
  * @note these evaluators use buffers (they should not be overloaded in derivated classes).
  * @note the buffer is reseted during the evaluation of the system of equations / of the equation the expression belongs to.
  * @attention  If you launch independant evaluations, do not forget to call ResetBuffer before each call
  */
  const CATWBValue & GetValue() const;

  /**
  * @brief Evaluate the expression provided that every variable is affected to a value.
  * @return the result of the evaluation converted in double
  * @note these evaluators use buffers (they should not be overloaded in derivated classes).
  * @note the buffer is reseted during the evaluation of the system of equations / of the equation the expression belongs to.
  * @attention  If you launch independant evaluations, do not forget to call ResetBuffer before each call
  */
   double Eval() const;

  /**
  * @brief Create a new expression where one variable is replaced by a new term. 
  * @param[in] iapVar  the  variable to substitute
  * @param[in] iapVal  the  new term replacing terms
  * @return   the new expression 
  * @note If the variable is substituted by a constant, the expression matches a partial evaluation 
  */
  CATWBExpression * PartialEval(CATWBVariable * iapVar, CATWBExpression *iapVal);

  /**
  * @brief Create a new expression where one or several variables are replaced by new terms. Similar to ReplaceVar.
  * @param[in] n the number of variables to substitute
  * @param[in] iapVar      the array of the variables to substitute
  * @param[in] iapVal      the array of the new replacing terms
  * @return   the new expression 
  * @note If the variables are substituted by constants, the expression matches a partial evaluation 
  */
  virtual CATWBExpression * PartialEval(CATWBVariable ** iapVar, CATWBExpression ** iapVal, const int iNumVar);

  /**
   * @brief Create a new expression where one or several variables are replaced by new terms. Similar to PartialEval 
   * @param[in] iNVariables the number of variables to substitute
   * @param[in] iapVar      the array of the variables to substitute
   * @param[in] iapVal      the array of the new replacing terms
   * @return   the new expression 
   * @note If the variables are substituted by constants, the expression matches a partial evaluation 
   */
  virtual CATWBExpression * Evaluate(int iNVariables, CATWBVariable **iapVar, CATWBExpression **iapVal) = 0;

  
  

  
   /**
  * @brief Compare two expressions
  * @param [in] ipExpression the expression to compare with the current expression
  * @return TRUE if the expressions are equivalent, otherwise FALSE
  */
  virtual CATCDSBoolean IsEqualTo(const CATWBExpression * ipExpression) const;
  
  /**
  *@brief State  if the current expression  does not depend on any variable 
  *@return TRUE if the current expression  is constant, otherwise FALSE
  */
  CATCDSBoolean IsConstant() const;
  
  /**
  *@brief State if the expression contains the variable "ipVariable"
  *@param[in] ipVariable a variable
  *@return TRUE if the expression does not contain the variable "ipVariable", otherwise FALSE
  */
  virtual CATCDSBoolean IsFree(CATWBVariable const *ipVariable) const = 0;

  /**
  *@brief State  if the current expression  is linear
  *@return TRUE if the current expression  is linear, otherwise FALSE
  */
  CATCDSBoolean IsLinear() const;
  
  /**
  *@brief State  if the current expression  is quadratic
  *@return TRUE if the current expression  is quadratic, otherwise FALSE
  */
  CATCDSBoolean IsQuadratic() const;

  /**
  *@brief State  if the current expression  is a polynomial 
  *@return NULL if it is not a polynomial, otherwise the variable of the polynomial 
  */
  CATWBVariable *  IsPolynomial() ;

  /**
  *@brief State  if the current expression is a polynomial relative to a given variable.
  *@param[in] ipVariable  the  variable to test
  *@return TRUE if the current expression  is a polynomial relative to the given variable, otherwise FALSE
  */

  CATCDSBoolean IsPolynomial(CATWBVariable const *ipVariable) const;

  /**
  * @brief State  if the current expression  is a polynomial to a given variable and compute its data if it is the case
  * @param[in] ipVar  the  variable to test
  * @param[out] oDegree  the  degree of the polynomial if the current expression  is a polynomial
  * @param[out] oCoef the  array of the coefficients of the polynomial as such as  the current expression  is equal to \f$ \sum^{oDegree}_{k=0} oCoef[k] (ipVariable)^k \f$
  * @attention  Since the caller does not know the number of the involved coefficients the creation of the array CATWBExpression ** is done in the method
  * @attention  to avoid any memory leak, the object should be empty before call !
  * @attention  the caller will have to delete the object after use  !!!!
  */
  CATCDSBoolean IsPolynomial(CATWBVariable const *ipVar, int & oDegree, CATWBExpression**& oCoef) const;

  /**
  *@brief State  if the current expression  is rational relative to a given variable.
  *@param[in] ipVariable  the  variable to test
  *@return TRUE if the current expression  is  rational  relative to the given variable, otherwise FALSE
  */
  CATCDSBoolean IsRationalFunction(CATWBVariable * ipVariable) const;
    
  /**
  * @brief Compute the formal derivative of the current expression with respect to a given  variable.
  * @param[in] ipVariable   the variable  used to differentiate 
  * @return the expression of the derivative
  * @note Don't call directly this method. Use the <tt>CreateDerivative</tt> method of the <tt>CATWBFactory</tt> interface.
  */
  virtual CATWBExpression * Differentiate(CATWBVariable * ipVariable) CATCDSFinal;

  /**
  * @brief Compute the formal integration of the current expression relative to the variable "ipVariable".
  * @param[in] ipVariable the variable  used to integrate
  * @param[out] oSuccess diagnostic to state if all the terms have been integrated.
  * @return the computed integral.  
  * @return   An  "IntegrateOperator" (specific integration operator which points on the original function) is returned for the terms whose integration fails.
  */
  CATWBExpression * Integrate(CATWBVariable * ipVariable, CATCDSBoolean & oSuccess);

  /**
  * @brief Compute the formal integration of the current expression relative to the variable "ipVariable" as such as it is equal to iX0 at it0
  * @param[in] ipVariable the variable  used to integrate
  * @param[in] it0 the value of the variable at which the integral is imperative
  * @param[in] iX0 the awaited value of the integral at it0
  * @param[out] oSuccess diagnostic to state if all the terms have been integrated.
  * @return the computed integral if the integration is done and an  IntegrateOperator if not.
  */
  CATWBExpression * Integrate(CATWBVariable * ipVariable, CATWBValue & it0, CATWBValue & iX0, CATCDSBoolean & oSuccess);

  /**
  * @brief Get the value of the expression property (used in the symbolic transformations)
  * @param[in] iIdx the index of the property, returned by CATWBFactory::RegisterProperty  
  * @return If property was not set, returns default value of this property.
  */
  int GetProperty(int iIdx) const;

  /**
  * @brief Set expression property (used in the symbolic transformations)
  * @param[in] iIdx the index of the property, returned by CATWBFactory::RegisterProperty
  * @param[in] iValue the  property value
  */
  void SetProperty(int iIdx, int iValue);

public:

   // Memory usage optimisation
   // -------------------------

   CATCDSBoolean CanBeRemoved(const CATWBExpression * iParent = NULL) const;

   virtual void RemoveUniqueChildren() = 0;


  // Performance data
  // ----------------

public:

  /**
  * @brief Query if the evaluation buffer can be used for this object (internal use)
  */
  CATCDSBoolean AllowsBufferEval() const;

//protected:

   //friend void CATWBFactory::ResetBuffer(CATWBExpression* ipRootToReset);

  /**
  * @brief Reset the evaluation buffer (internal use)
  * @param[in] iRecursive If iRecursive is TRUE, the parent nodes will be recursively reset as well.
  */
  virtual void ResetBuffer(const CATCDSBoolean iRecursive = TRUE);

public:
//protected:

  /**
  * @brief Reset the full evaluation buffer including the parent nodes (internal use)
  */
  void ResetBufferComplete();

  /**
  * @brief Reset the evaluation buffer for only this object (internal use)
  *
  * @note this can leave the system in an inconsistent state if this object has parent objects
  */
  void ResetBufferPartial();

protected:

  // Deprecated - only called if CATWBx_Perfo_EvalBuffer is inactive
  void ResetBufferAndChildren(const CATCDSBoolean iRecursive); 

  // These functions allow the management of the "upward" links of an expression. When
  // an expression's value is changed the evaluation must be re-done and also the evaluation
  // of all parent expressions.
  int GetNbOfParents() const;
  static CATCDSBoolean AddParent(CATWBExpression* iChild, CATWBExpression* iParent); // static because it needs to accessible in the derived classes
  static CATCDSBoolean RemoveParent(CATWBExpression* iParent, CATWBExpression* iChild); // static because it needs to accessible in the derived classes

  virtual CATCDSBoolean RemoveChild(CATWBExpression* iChild);

  virtual CATCDSBoolean ValidateAllowBufferEval() const;

public:
  void SetAllowBufferEval(const CATCDSBoolean iAllow,
                          const CATCDSBoolean iRecursiveUpwards,
                          const CATCDSBoolean iValidate);


  // Only for streaming
  // ------------------
  
public:

  int GetTag() const;

protected:

  // Special constructor for streaming only
  CATWBExpression(CATWBFactory & iFactory, const int iTag, const CATWBExpressionType iType);

protected:

  // Evaluation
  // ----------

  virtual double DoEval() const;
  virtual void   DoEval(CATWBValue & oValue) const = 0;

  virtual CATWBExpression* IntegrateTable(CATWBVariable * ipVariable, CATCDSBoolean & oSuccess) CATCDSFinal;
  virtual CATWBExpression* IntegrateTableProtected(CATWBVariable * ipVariable, CATCDSBoolean & oSuccess) = 0;

  void Replace(CATWBExpression* ipExprToReplace, CATWBExpression * ipNewTerm);

  virtual CATWBExpression* DifferentiateProtected(CATWBVariable* ipVariable) = 0;
  virtual CATWBExpression* Differentiate(CATWBExpression*, CATWBVariable*) CATCDSFinal;

  const CATWBExpressionType _type;
  CATWBFactory& _factory;

  const int _Tag;

private:
  
  mutable unsigned int _bufmask;
  mutable CATWBValue _valuebuf;  // the current (cached) evaluation
  mutable CATWBValue _exprvalue; // the externally set value - no idea really how this is used but it cannot easily be removed...

  CATCDSARRAY(CATWBProperty) * _pProperties;

  CATCDSLISTP(CATWBExpression) _apDirectParents; // Q48 - for performance

  // Debug
  // -----
  
  WBX_DEBUG_DECLARE;

#ifdef WBX_DEBUG_TRACE
protected:
  void Debug_PrintDifferentialHeader(const CATWBVariable * ipVariable) const;
  void Debug_PrintDifferentialFooter(const CATWBVariable * ipVariable, const CATWBExpression* ipDifferential) const;

public:

   void BuildListChildren(const CATCDSBoolean                  iRecursive,
                                CATCDSLISTP(CATWBExpression) & ioListExpr) const;

  CATCDSString StringForCount() const;
  CATCDSString StringForID() const;
  CATCDSString StringForType() const;
  CATCDSString StringForStructure() const;

  virtual void Debug_PrintStructure() const = 0;
  virtual CATCDSString Debug_SymbolString(const short iLongMode) const = 0;

  int _InstanceCounter;
#endif // WBX_DEBUG_TRACE
};
#endif
