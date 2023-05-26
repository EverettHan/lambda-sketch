// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBFactory.h
// Header definition of CATWBFactory
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /06/06      Creation (Sergey Lipski)
// 23/03/17 Q48  Add to predefined constants
// 18/04/18 Q48  Add to predefined constants
// 18/04/18 Q48  Add utilities for segment function creation
// 02/01/19 Q48  Add const methods for equation iterators
// 05/03/19 Q48  Add const to some Get methods
// 18/07/19 Q48  Make _WBLevel const
// 29/07/19 Q48  Add protected methods for JSON streaming and friend
//               with streaming classes
// 05/08/19 Q48  Life-cycle management of BBx
// 06/09/19 Q48  Move WBx level (versioning) to CATWBEnvironment
// 25/09/19 Q48  IR-668158: Add interface for new 3-child operator
// 27/11/19 Q48  Utilities to allow versioning in CATWBValue
// 29/11/19 Q48  Allow ODT_StreamJSON to validate _GlobalTag
// 25/01/23 Q48  Migrate to new BBx architecture
//===================================================================

#ifndef CATWBFactory_h
#define CATWBFactory_h

// ExportedBy
#include "WhiteBoxData.h"

// WBx
#include "CATWBTypes.h"
#include "CATWBLists.h"
#include "CATWBEnvironment.h"
#include "CATWBValue.h"
#include "CATWBEquation.h"
#include "CATWBModel.h"
#include "CATWBSegmentFunction.h"
class CATWBBlackBox;
class CATWBExpression;
#include "CATWBExpression.h" // temp include needed for CATKSDimSynthesisMdl/CATKSDimSynthesisMdl.m/src/CATKSDimPath.cpp

// CDS
#include "CATCDSBoolean.h"
#include "CATCDSString.h"
#include "CATCDSMapForward.h"
#include "CATCDSArray.h"

//#include "CATWBBlackBoxOperator.h" // needed for friend method declaration
class CATWBBlackBoxBaseOperator;
class CATWBBlackBoxOperator;
class CATWBBlackBoxDerivOperator;

class CATWBVariable;
class CATWBConstant;
class CATWBBlackBox;
class CATCDSIntArray;

struct CATWBPropRegistry;

//-----------------------------------------------------------------------

/**
* @brief The CATWBFactory class is the structure where is stored all the terms of the formal expressions.
*/
class ExportedByWhiteBoxData CATWBFactory
{
  friend class CATWBModel;
public:
  /**
  * @deprecated CATWBFactory with versioning level
  *  @brief Constructor  
  */ 
  CATWBFactory();
  /**
  * @brief Constructor 
  * @param[in] iWBLevel the versioning level in which is created the factory
  */ 
  CATWBFactory(unsigned int iWBLevel); // iCDSLevel = versioning level 
  /**
  *  @brief Destructor  
  */
  virtual ~CATWBFactory();

  //
  // Information methods
  //

  /**
  * @brief Get the environment defined for the factory
  * @return the environment associated to the factory
  */
  CATWBEnvironment& GetEnvironment();
  
  /**
  * @brief Get the environment defined for the factory
  * @return the environment associated to the factory
  */
  const CATWBEnvironment& GetEnvironment() const;
  
  /**
  * @brief Set the environment for evaluation
  */
  void InitEnvForEval();
  
  /**
  * @brief Set tolerance in environment.
  */
  void SetTolerance(double iTolerance);
  
  /**
  * @brief  Get the expression associated to this tag
  * @return the expression associated to this unique tag
  */
  CATWBExpression * GetExpressionFromTag(const int iTag) const;
    
  /**
  * @brief  Get a predefined constant (pcPi (\f$ \pi\f$), pcDTOR (the degrees to radians conversion factor), pcRTOD (the radians to degrees conversion factor),...)
  * @param[in] iType  the name of the predefined constant (pcPi, pcDTOR, pcRTOD,...)
  * @return the term, otherwise null in case of error.
  */
  CATWBConstant* GetConstant(const CATWBPredefinedConst iType) const;

  /**
  * @brief  Get the predefined constant "indefinite" stored in the factory
  * @return the predefined constant "indefinite" stored in the factory
  */
  /*const*/ CATWBConstant * GetIndefinite() const;

  /**
  * @brief  Get the predefined constant "invalid" stored in the factory
  * @return the predefined constant "invalid" stored in the factory
  */
  /*const*/ CATWBConstant * GetInvalid() const;
  
  /**
  * @brief  Get the predefined constant -1 stored in the factory
  * @return the predefined constant -1 stored in the factory
  */
  /*const*/ CATWBConstant * GetMinusOne() const;
  
  /**
  * @brief  Get the predefined constant 0 stored in the factory
  * @return the predefined constant 0 stored in the factory
  */
  /*const*/ CATWBConstant * GetZero() const;
  
  /**
  * @brief  Get the predefined constant 1 stored in the factory
  * @return the predefined constant 1 stored in the factory
  */
  /*const*/ CATWBConstant * GetOne() const;
  
  /**
  * @brief  Get the predefined constant 2 stored in the factory
  * @return the predefined constant 2 stored in the factory
  */
  /*const*/ CATWBConstant * GetTwo() const;
  
  /**
  * @brief  Get the predefined constant 3 stored in the factory
  * @return the predefined constant 3 stored in the factory
  */
  /*const*/ CATWBConstant * GetThree() const;
  
  /**
  * @brief  Get the predefined constant Pi stored in the factory
  * @return the predefined constant Pi stored in the factory
  */
  
  /*const*/ CATWBConstant * GetPi() const;
  
  /**
  * @brief  Get the predefined constant Pi/2 stored in the factory
  * @return the predefined constant Pi/2 stored in the factory
  */
  /*const*/ CATWBConstant * GetPiByTwo() const;

  /**
  * @brief  Get the predefined constant for degrees to radians stored in the factory
  * @return the predefined constant for degrees to radians stored in the factory
  */
  
  /*const*/ CATWBConstant * GetDToR() const;

  /**
  * @brief  Get the predefined constant for radians to degrees stored in the factory
  * @return the predefined constant for radians to degrees stored in the factory
  */
  
  /*const*/ CATWBConstant * GetRToD() const;

  /**
  * @brief Get the number of variables stored in the factory
  * @return  the number of variables
  */
  int GetNbOfVariables() const;

  /**
  * @brief Get the iIdx-th variable of the factory
  * @param[in] iIdx the index of the awaited variable
  * @return    the pointer to the  iIdx-th variable
  */
  CATWBVariable* GetVariable(int iIdx);

  /**
  * @brief Get iIdx-th variable of the factory
  * @param[in] iIdx the index of the awaited variable
  * @return   the pointer to the  iIdx-th variable
  */
  const CATWBVariable* GetVariable(int iIdx) const;

  /**
  * @brief Get the variable following in the factory  the given variable 
  * @param[in] ipVariable the  given variable
  * @return   the  pointer to the next variable in the factory
  */
  CATWBVariable* GetNextVariable(CATWBVariable* ipVariable);

  /**
  * @brief Get variable by its name.
  * @param[in] iName the name of the variable to find.
  * @return the  pointer to the associated variable,  0  if the variable doesn't exist.
  */
  CATWBVariable* GetVariable(const CATCDSString& iName);

  /**
  * @brief Get the number of equations stored in the factory
  * @return  the number of equations
  */
  int GetNbOfEquations() const;

  /**
  * @brief Get the first equation stored in the factory
  * @return   the pointer to the first equation 
  */
  CATWBEquation* GetFirstEquation();
  /**
  * @brief Get the first equation stored in the factory
  * @return   the pointer to the first equation 
  */
  const CATWBEquation* GetFirstEquation() const;
  /**
  * @brief Get the last equation stored in the factory
  * @return  the pointer to the last equation
  */
  CATWBEquation* GetLastEquation();
  /**
  * @brief Get the last equation stored in the factory
  * @return  the pointer to the last equation
  */
  const CATWBEquation* GetLastEquation() const;
  /**
  * @brief Get the equation following in the factory  the given equation
  * @param[in] ipEquation the given equation
  * @return   the  pointer to the next equation in the factory
  */
  CATWBEquation* GetNextEquation(const CATWBEquation* ipEquation);
  /**
  * @brief Get the equation following in the factory  the given equation
  * @param[in] ipEquation the given equation
  * @return   the  pointer to the next equation in the factory
  */
  const CATWBEquation* GetNextEquation(const CATWBEquation* ipEquation) const;
  /**
  * @brief Get the equation preceding in the factory  the given equation
  * @param[in] ipEquation the given equation
  * @return   the  pointer to the  previous equation in the factory
  */
  CATWBEquation* GetPrevEquation(const CATWBEquation* ipEquation);
  /**
  * @brief Get the equation preceding in the factory  the given equation
  * @param[in] ipEquation the given equation
  * @return   the  pointer to the  previous equation in the factory
  */
  const CATWBEquation* GetPrevEquation(const CATWBEquation* ipEquation) const;
  /**
  * @brief Get the iIdx-th equation of the factory
  * @param[in] iIdx the index of the awaited equation
  * @return   the pointer to the  iIdx-th equation
  */
  CATWBEquation* GetEquationById(const int iIdx);
  /**
  * @brief Get equation by its name.
  * @param[in] iName the name of the equation to find.
  * @return the  pointer to the associated equation,  0  if the equation doesn't exist.
  */
  CATWBEquation* GetEquationByName(const CATCDSString& iName);

  /**
  * @brief Declare an equation to the factory.
  * @param[in] ipRoot  the expression associated to the equation
  * @param[in] iType  the type of the equation (eqNone, eqEQ, eqLE, eqMinimize, ....). By default eqNone
  * @return the created equation
  */
  CATWBEquation* AddEquation(CATWBExpression* ipRoot, CATWBEquationType iType = eqNone);
  /**
  * @brief Declare an equation to the factory.
  * @param[in] ipLeftRoot  the left term of the equation
  * @param[in] iType  the type of the equation (eqNone, eqEQ, eqLE, eqMinimize, ....). By default eqNone
  * @param[in]  ipRightRoot  the right term of the equation
  * @return the created equation
  */
  CATWBEquation* AddEquation(CATWBExpression* ipLeftRoot, CATWBEquationType iType, CATWBExpression* ipRightRoot);

  /**
  * @brief Remove equation from the solver.
  * @param[in] ipEquation  the equation to remove
  * @note the internal terms of the equation are not removed at the same time. They will be automatically deleted with the factory instance.  
  */
  void RemoveEquation(CATWBEquation* &ipEquation);


  /**
  * @brief  Create copies in the same factory of equations with new variables.
  * @param[in] iaEquationsId
  *   Array of the id of the equations to clone.
  * @param [out] oaNewEquationsId
  *   Array of the id of the new equations.
  * @param[in] iaOldVarNames
  *   Array of the names of the variables to substitute.
  * @param[in] iaNewVarNames
  *   Array of the names of the variables which replace the previous one.
  * @return
  *   0 if the function is succeeded,
  *   1 if arguments are invalid.
  */
  int CloneEquations(CATCDSIntArray& iaEquationsId,
    CATCDSIntArray& oaNewEquationsId,
    CATCDSARRAY(CATCDSString)& iaOldVarNames,
    CATCDSARRAY(CATCDSString)& iaNewVarNames);


  //  Elementary nodes
  /**
  * @brief  Create a variable
  * @return the created term, otherwise null in case of error.
  */
  CATWBVariable* CreateVariable();
  /**
  * @brief  Create a real constant
  * @return the created term, otherwise null in case of error.
  */
  CATWBConstant* CreateRealConstant(double iValue);
  /**
  * @brief  Create an integer
  * @return the created term, otherwise null in case of error.
  */
  CATWBConstant* CreateIntegerConstant(int iValue);
  /**
  * @brief  Create a constant
  * @return the created term, otherwise null in case of error.
  */
  CATWBConstant* CreateConstant(const CATWBValue & iValue);
  /**
  * @brief  Create a constant equal to \f$ \pi\f$
  * @return the created term, otherwise null in case of error.
  */
  CATWBConstant* CreateConstantPi();
  /**
  * @brief  Create a constant equal to the degrees to radians conversion factor
  * @return the created term, otherwise null in case of error.
  */
  CATWBConstant* CreateConstantDTOR();
  /**
  * @brief  Create a constant equal to the radians to degrees conversion factor
  * @return the created term, otherwise null in case of error.
  */
  CATWBConstant* CreateConstantRTOD();

  //  Boolean functions
  /**
  * @brief  Create an expression representing the boolean operator Not applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateNot(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the boolean operator Or applied to two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateOr(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing the boolean operator And applied to two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateAnd(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the equality operator between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateEqual(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the inequality operator between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateNotEqual(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the relational operator "Less Than Or Equal" between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateLessEqual(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the relational operator "Less Than" between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateLess(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the relational operator "Greater Than Or Equal" between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateGreaterEqual(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the relational operator "Greater Than" between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateGreater(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the logical operator Imlication between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateImplication(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the IfThenElse operator applied to three given arguments
  * @param[in] ipIfExpr  the conditional given argument of the operator
  * @param[in] ipThenExpr  the consequent  argument of the operator
  * @param[in] ipElseExpr  the alternative  argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateIfThenElse(CATWBExpression * ipIfExpr,
                                    CATWBExpression * ipThenExpr,
                                    CATWBExpression * ipElseExpr);

  //  Algebraic expressions
  /**
  * @brief  Create an expression representing  the sum between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateSum(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing the difference between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateDifference(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the sum between inExpr given arguments
  * @param[in] inExpr  the number of arguments of the operator
  * @param[in] iaExpr  the array of the arguments of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateSum(int inExpr, CATWBExpression** iaExpr);
  /**
  * @brief  Create an expression representing  the product between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateProduct(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the product between inExpr given arguments
  * @param[in] inExpr  the number of arguments of the operator
  * @param[in] iaExpr  the array of the arguments of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateProduct(int inExpr, CATWBExpression** iaExpr);
  /**
  * @brief  Create an expression representing  the quotient between two given arguments
  * @param[in] ipExpr1  the numerator of the operator
  * @param[in] ipExpr2  the denominator of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateQuotient(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the power between two given arguments
  * @param[in] ipExpr  the first given argument of the operator
  * @param[in] iPower  the exponent argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreatePower(CATWBExpression* ipExpr, int iPower);
  /**
  * @brief  Create an expression representing  the power between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the exponent argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreatePower(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the root between two given arguments
  * @param[in] ipExpr  the first given argument of the operator
  * @param[in] iPower  the exponent argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateRoot(CATWBExpression* ipExpr, int iPower);

  //   Unary functions
  /**
  * @brief  Create an expression representing the trigonometric  operator Sin applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateSin(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the trigonometric  operator Cos applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateCos(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the trigonometric  operator Tan applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateTan(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the trigonometric  operator ASin applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateAsin(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the trigonometric  operator ACos applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateAcos(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the trigonometric  operator ATan applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateAtan(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the hyperbolic operator Sinh applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateSinh(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the hyperbolic operator Cosh applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateCosh(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the hyperbolic operator Tanh applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateTanh(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the hyperbolic operator ASinh applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateASinh(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the hyperbolic operator ACosh applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateACosh(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the hyperbolic operator ATanh applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateATanh(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the square root applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateSqrt(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the commom logarithm applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateLog(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the natural logarithm  applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateLn(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the exponential applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateExp(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the absolute value applied to a given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateAbs(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression rounding  the given argument upward
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateCeil(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression rounding  the given argument downward
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateFloor(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression returning the integral value that is nearest to the given argument 
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateRound(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression returning  the nearest integral value that is not larger in magnitude than the given argument
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateTrunc(CATWBExpression* ipExpr);
  /**
  * @brief  Create an expression representing the smoothed step functionstep function such that
  * \f$\left\{ \begin{array}{lc} e_1 \leq a_1& a_2 \\ a_1 \lt e_1 \lt a_3 & a_2+a \Delta^2 (3-2\Delta) \\ e_1 \geq a_3& a_4 \\ \end{array} \right.\f$
  * @param[in] ipExpr  the given argument of the operator
  * @param[in] iX0  the given argument of the operator
  * @param[in] iH0  the given argument of the operator
  * @param[in] iX1  the given argument of the operator
  * @param[in] iH1  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateStep(CATWBExpression* ipExpr, const double iX0, const double iH0, const double iX1, const double iH1);

  //  Binary functions
  /**
  * @brief  Create an expression representing  the remainder of the division of the first term by the second one
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateMod(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the arc tangent of two terms
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateAtan2(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the difference between the both terms if the result is positive otherwise returns zero. 
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateDim(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the magnitude of the first term with the sign of the second one
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateSign(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);

  //  N-ary function
  /**
  * @brief  Create an expression representing  the minimum between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateMin(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the minimum between inExpr given arguments
  * @param[in] inExpr  the number of arguments of the operator
  * @param[in] iaExpr  the array of the arguments of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateMin(int inExpr, CATWBExpression** iaExpr);
  /**
  * @brief  Create an expression representing  the maximum between two given arguments
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateMax(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an expression representing  the maximum between inExpr given arguments
  * @param[in] inExpr  the number of arguments of the operator
  * @param[in] iaExpr  the array of the arguments of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateMax(int inExpr, CATWBExpression** iaExpr);

  //  Generic creation functions
  /**
  * @brief  Create an unary expression of a given type
  * @param[in] iType  the type of the operator
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateUnaryOperator(CATWBExpressionType iType, CATWBExpression* ipExpr);
  /**
  * @brief  Create a trigonometric expression of a given type
  * @param[in] iType  the type of the operator
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateTrigonometricOperator(CATWBExpressionType iType, CATWBExpression* ipExpr);
  /**
  * @brief  Create an unary  boolean expression of a given type
  * @param[in] iType  the type of the operator
  * @param[in] ipExpr  the given argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateBooleanOperator(CATWBExpressionType iType, CATWBExpression* ipExpr);
  /**
  * @brief  Create a binary  boolean  expression of a given type
  * @param[in] iType  the type of the operator
  * @param[in] ipExpr1  the given first argument of the operator
  * @param[in] ipExpr2  the given second argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateBooleanOperator(const CATWBExpressionType iType, CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create a binary  expression of a given type
  * @param[in] iType  the type of the operator
  * @param[in] ipExpr1  the given first argument of the operator
  * @param[in] ipExpr2  the given second argument of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateBinaryOperator(const CATWBExpressionType iType, CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an algebraic expression of a given type between inExpr given arguments
  * @param[in] iType  the type of the operator
  * @param[in] inExpr  the number of arguments of the operator
  * @param[in] iaExpr  the array of the arguments of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateAlgebraicOperator(const CATWBExpressionType iType, const int inExpr, CATWBExpression** iaExpr);
  /**
  * @brief  Create a  literal integration operator. 
  * The operator points on the  function to integrate and on the integration variable.
  * This operator is mainly generated when the formal integration doesn't succeed.
  * @param[in] ipExpr1  the function which was to integrate
  * @param[in] ipExpr2  tthe integration variable
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateIntegrateOperator(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an operator from a given expression by duplication
  * @param[in] ipExpr  the given expression
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateOperator(CATWBExpression* ipExpr);
  /**
  * @brief  Create an unary operator of a given type  applied to a given argument
  * @param[in] iType  the type of the operator
  * @param[in] ipExpr  the given argument
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateOperator(const CATWBExpressionType iType, CATWBExpression* ipExpr);
  /**
  * @brief  Create a binary operator of a given type  applied to a given argument
  * @param[in] iType  the type of the operator
  * @param[in] ipExpr1  the given first argument
  * @param[in] ipExpr2  the given second argument
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateOperator(const CATWBExpressionType iType, CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create an N-ary operator of a given type
  * @param[in] iType  the type of the operator
  * @param[in] inExpr  the number of arguments of the operator
  * @param[in] iaExpr  the array of the arguments of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateOperator(const CATWBExpressionType iType, const int inExpr, CATWBExpression** iaExpr);
  /**
  * @brief  Create an N-ary operator of a given type
  * @param[in] iType  the type of the operator
  * @param[in] ilExpr  the list of the arguments of the operator
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateOperator(const CATWBExpressionType iType, CATCDSLISTP(CATWBExpression)& ilExpr);

  //  Shortcuts

  /**
  * @brief  Create an expression representing  a substraction between two given terms (X + (-1) * Y)
  * @param[in] ipExpr1  the first given argument of the operator
  * @param[in] ipExpr2  the second given argument of the operator
  * @return the created term, otherwise null in case of error.
  * @note shortcut for creation
  */
  CATWBExpression* CreateSub(CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);
  /**
  * @brief  Create a linear expression between three given terms (a X + b)
  * @param[in] iA  the given firstargument of the operator
  * @param[in] ipExpr1  the  second given argument of the operator
  * @param[in] iB  the last given argument of the operator
  * @return the created term, otherwise null in case of error.
  * @note shortcut for creation
  */
  CATWBExpression* CreateLinearTerm(const CATWBValue & iA, CATWBExpression* ipExpr1, const CATWBValue & iB);
  /**
  * @brief  Create a quadratic expression between three given terms (a X^2 + b)
  * @param[in] iA  the given firstargument of the operator
  * @param[in] ipExpr1  the  second given argument of the operator
  * @param[in] iB  the last given argument of the operator
  * @return the created term, otherwise null in case of error.
  * @note shortcut for creation
  */
  CATWBExpression* CreateQuadraticTerm(const CATWBValue & iA, CATWBExpression* ipExpr1, const CATWBValue & iB);
  /**
  * @brief  Create a polynomial expression of degree n (a_0*X^n + ... + a_(n-1)*X + a_n)
  * @param[in] iSize the size of the coefficient array (iSize=n+1)
  * @param[in] ipA the array of the coefficients 
  * @param[in] ipX  the variable of the polynomial
  * @return the created term, otherwise null in case of error.
  * @note shortcut for creation
  */
  CATWBExpression* CreatePolynomialTerm(int iSize, CATWBExpression** ipA, CATWBExpression* ipX);

  //  Interpolation functions
  /**
  * @brief  Create a linear interpolation from  2 points
  * @param[in] (ipX0,ipF0)  the first point
  * @param[in] (ipX1,ipF1)  the second point
  * @param[in] ipX  the variable of the new term
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateLinearInterpolation2P(CATWBExpression* ipX0, CATWBExpression* ipF0,
    CATWBExpression* ipX1, CATWBExpression* ipF1,
    CATWBExpression* ipX);
  /**
  * @brief  Create a linear interpolation from two values : (f1-f0)*x + f0
  * @param[in] ipF0  the first value
  * @param[in] ipF1  the second value
  * @param[in] ipX  the variable of the new term
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateLinearInterpolation01(CATWBExpression* ipF0,
    CATWBExpression* ipF1,
    CATWBExpression* ipX);
  /**
  * @brief  Create a quadratic interpolation from  three points
  * @param[in] (ipX0,ipF0)  the first point
  * @param[in] (ipX1,ipF1)  the second point
  * @param[in] (ipX2,ipF2)  the third point
  * @param[in] ipX the variable of the new term
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateQuadraticInterpolation3P(CATWBExpression* ipX0, CATWBExpression* ipF0,
    CATWBExpression* ipX1, CATWBExpression* ipF1,
    CATWBExpression* ipX2, CATWBExpression* ipF2,
    CATWBExpression* ipX);
  /**
  * @brief  Create a cubic interpolation from  four points
  * @param[in] (ipX0,ipF0)  the first point
  * @param[in] (ipX1,ipF1)  the second point
  * @param[in] (ipX2,ipF2)  the third point
  * @param[in] (ipX3,ipF3)  the fourth point
  * @param[in] ipX the variable of the new term
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateCubicInterpolation4P(CATWBExpression* ipX0, CATWBExpression* ipF0,
    CATWBExpression* ipX1, CATWBExpression* ipF1,
    CATWBExpression* ipX2, CATWBExpression* ipF2,
    CATWBExpression* ipX3, CATWBExpression* ipF3,
    CATWBExpression* ipX);
  /**
  * @brief  Create a cubic interpolation from  two points and their tangents at these points
  * @param[in] (ipX0,ipF0,ipD0)  the first point and its tangent
  * @param[in] (ipX1,ipF1,ipD1))  the second point and its tangent
  * @param[in] ipX the variable of the new term
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateCubicInterpolation2P2D(CATWBExpression* ipX0, CATWBExpression* ipF0, CATWBExpression* ipD0,
    CATWBExpression* ipX1, CATWBExpression* ipF1, CATWBExpression* ipD1,
    CATWBExpression* ipX);


  /**
  * @brief  Create a cubic interpolation from two values : -2*(f1-f0)*x^3 + 3*(f1-f0)*x^2 + f0
  * @param[in] ipF0  the first value
  * @param[in] ipF1  the second value
  * @param[in] ipX  the variable of the new term
  * @return the created term, otherwise null in case of error.
  */
  CATWBExpression* CreateCubicInterpolation01(CATWBExpression* ipF0,
    CATWBExpression* ipF1,
    CATWBExpression* ipX);

   /**
  * @brief  Create the a segment function
  * @param[in] iExpr the pointer to the expression variable
  * @param[in] iFunc the the segment function definition
  * @return the created expression, otherwise null in case of error.
  */
  CATWBExpression* CreateSegmentFunction(CATWBExpression* iExpr, const CATWBSegmentFunction & iFunc);

   /**
  * @brief  Create the formal derivation of a given expression  with respect to a given variable
  * @param[in] ipExpr the expression to derivate 
  * @param[in] ipVariable the pointer on the derivation variable
  * @return the created term, otherwise null in case of error.
  * @note not available for black boxes
  */
  CATWBExpression* CreateDerivative(CATWBExpression* ipExpr, CATWBVariable* ipVariable);

  /**
  * @brief  Create the formal derivation of a given expression  with respect to an array of given variables
  * @param[in] ipExpr the expression to derivate 
  * @param[in] inVariables the number of derivation variables
  * @param[in] iapVariables the array of the pointers on the derivation variables
  * @return the created term, otherwise null in case of error.
  * @note not available for black boxes
  */
  CATWBExpression* CreateDerivative(CATWBExpression* ipExpr, int inVariables, CATWBVariable** iapVariables);

  /**
  * @brief Create the antiderivative (primitive function) of a given expression relative to a given variable.
  * @param[in] ipExpr the expression to integrate
  * @param[in] ipVariable the pointer on the integration variable
  * @param[out] oSuccess diagnostic to state if all the terms have been integrated.
  * @return  the created term
  * @return  an  "IntegrateOperator" (specific integration operator which points on the original function) is returned for the terms whose integration fails.
  */
  CATWBExpression* CreateAntiDerivative(CATWBExpression* ipExpr, CATWBVariable* ipVariable, CATCDSBoolean & oSuccess);
  /**
  * @brief Create the antiderivative (primitive function) of a given expression relative to an array of given variables.
  * @param[in] ipExpr the expression to integrate   
  * @param[in] inVariables the number of integration variables
  * @param[in] iapVariables the array of the pointers on the integration variables
  * @param[out] oSuccess diagnostic to state if all the terms have been integrated.
  * @return  the created term
  * @return  an  "IntegrateOperator" (specific integration operator which points on the original function) is returned for the terms whose integration fails.
  */
  CATWBExpression* CreateAntiDerivative(CATWBExpression* ipExpr, int inVariables, CATWBVariable** iapVariables, CATCDSBoolean & oSuccess);
   /**
  * @brief  Create the antiderivative (primitive function) of a given expression relative to a given variable "ipVariable" 
  * as such as it is equal to iX0 at "ipVariable"=it0
  * @param[in] ipExpr the expression to integrate 
  * @param[in] ipVariable the pointer on the integration variable
  * @param[in] it0 the value of the variable at which the integral is imperative
  * @param[in] iX0 the awaited value of the integral at it0
  * @param[out] oSuccess diagnostic to state if all the terms have been integrated.
  * @return the computed integral if the integration is done, otherwise an  IntegrateOperator.
  */
  CATWBExpression* CreateAntiDerivative(CATWBExpression* ipExpr, CATWBVariable * ipVariable, CATWBValue & it0, CATWBValue & iX0, CATCDSBoolean & oSuccess);

  /**
  * @brief Remove an expression and all singly-used children from the factory
  * @param[in] ioExpression: the expression to remove
  * @param[in] iParent     : the parent expression (if there is one)
  */
  void RemoveExpression(CATWBExpression *& ioExpression, const CATWBExpression * iParent = NULL);

  /**
  * @brief Create copies of an expression of the same or from an other factory.
  * @param[in] ipExpression
  *   the expression to clone.
  * @param[in]  iMappedVars
  *   the map between the variables to substitute and the ones of the new expression
  * @return
  *  the pointer to the new expression,
  *  0 - if the variable doesn't exist.
  */
  CATWBExpression* CloneExpression(const CATWBExpression                            * const ipExpression,
                                         CATCDSMap<CATWBVariable*, CATWBVariable*> &        iMappedVars);

  /**
  * @brief Declare a BlackBox and its arguments to the factory 
  * @param[in] ipBB the BlackBox to declare
  * @param[in] inVariables the number of variables of the factory which are  the arguments of the BlackBox 
  * @param[in] iapVariables the variables of the factory which are the arguments of the BlackBox 
  * @param[in] iToDeleteByFactory the booean indicating if BlackBox has to be deleted with the factory instance.  
  * @return  the expression associated to the BlackBox (NULL if error)
  */
  CATWBBlackBoxOperator* DeclareBlackBox(const CATWBBlackBox    * ipBB, 
                                         const int                inVariables,
                                               CATWBExpression ** iapVariables,
                                               CATCDSBoolean      iToDeleteByFactory = FALSE);


  CATWBBlackBoxDerivOperator* DeclareBlackBoxDeriv(const CATWBBlackBoxBaseOperator * ipBBxOp,
                                                         CATWBExpression           * iDerivVar);

  /**
  * @brief Get a BlackBox variable by its name.
  * @param[in] iName the name of the BlackBox to find.
  * @return the  pointer to the associated BlackBoxOperator,  0  if the variable doesn't exist.
  */
  const CATWBBlackBoxOperator*  GetBlackBoxByName(const CATCDSString & iName) const;
    
  /**
  * @brief Get a BlackBox variable by its name.
  * @param[in] iName the name of the BlackBox to find.
  * @return the  pointer to the associated BlackBoxOperator,  0  if the variable doesn't exist.
  */
  CATWBBlackBoxOperator*  GetBlackBoxByName(const CATCDSString & iName);

  /**
  * @brief Get the derivative of a BlackBox with respect to a given  variable.
  * @param[in] ipBBx the BlackBox whose derivative  is to find.
  * @param[in] ipVar the differentiation variable
  * @return the  pointer to the derivative,  0  if the variable doesn't exist.
  */
  CATWBBlackBoxDerivOperator* GetDerivBlackBox(const CATWBBlackBoxBaseOperator * ipBBxOp,
                                                     CATWBVariable             * ipVar);

  ///**
  //* @brief Buffer (internal use)
  //*/
  void ResetBuffer(CATWBExpression* ipRootToReset = 0);

  ///**
  //* @brief Buffer (internal use)
  //*/
  void SetBufferUsed();

  /**
  * @brief Register new expression property.
  * @param[in] iName  the property name, e.g. "linear"
  * @param[in] iDefault  the default value of the property
  * @return the index of registered property.
  * @note Use this index to ask an expression for this property
  */
  int RegisterProperty(const CATCDSString & iName, int iDefault);

  /**
  * @brief Get default value of registered property.
  * @param[in] iIdx the index of the property, returned by RegisterProperty
  */
  int GetDefaultPropertyValue(int iIdx);

  /**
  * @brief Temporary storage for expressions (internal use)
  */
  void UseTemporaryStorage(CATCDSBoolean iValue);
  /**
  * @brief Set if the  variables of the factory are ordered by name
  * @param[in] iIsVariablesSorted value indicating if the  variables are sorted
  */
  void UpdateIsVariablesSorted(CATCDSBoolean  iIsVariablesSorted); 
  /**
  * @brief Get the versioning level in which is created the terms of the factory
  * @return the versioning level
  */
  unsigned int GetWBLevel() const;

protected:

  CATWBExpression* AddExpression(CATWBExpression* iopCandidate);

  CATWBConstant* GetConstant(const CATWBPredefinedConst iType,
                             const CATCDSBoolean        iAllowCreation) const;

  CATWBExpression* ReplaceTemporaryExpressions(CATWBExpression* ipExpression);

  CATWBExpression* CreateDeterminant(CATWBExpression** ipMatrix, int* iIdxI, int* iIdxJ, int iSize);

  CATWBExpression* CreateInterpolation(CATWBExpression ** ipMatrix,
                                       CATWBExpression ** ipA,
                                       CATWBExpression *  ipX, 
                                       int                iSize);

  CATWBExpression* CreateSegmentFunction_X(      CATWBExpression            * iX,
                                           const CATWBSegmentFunctionDataPt & iStart,
                                           const CATWBSegmentFunctionDataPt & iEnd);

  CATWBExpression* CreateSegmentFunction_Y(      CATWBExpression            * iX,
                                           const CATWBSegmentFunctionDataPt & iStart,
                                           const CATWBSegmentFunctionDataPt & iEnd);

  CATWBExpression* CreateSegmentFunction_Linear(      CATWBExpression            * iX,
                                                const CATWBSegmentFunctionDataPt & iStart,
                                                const CATWBSegmentFunctionDataPt & iEnd);

  CATWBExpression* CreateSegmentFunction_Quadratic(      CATWBExpression            * iX,
                                                   const CATWBSegmentFunctionDataPt & iStart,
                                                   const CATWBSegmentFunctionDataPt & iEnd);

  CATWBExpression* CreateSegmentFunction_Cubic(      CATWBExpression            * iX,
                                               const CATWBSegmentFunctionDataPt & iStart,
                                               const CATWBSegmentFunctionDataPt & iEnd);

  CATWBExpression* CreateSegmentFunction_QuarterSin(      CATWBExpression            * iX,
                                                    const CATWBSegmentFunctionDataPt & iStart,
                                                    const CATWBSegmentFunctionDataPt & iEnd);

  CATWBExpression* CreateSegmentFunction_QuarterCos(      CATWBExpression            * iX,
                                                    const CATWBSegmentFunctionDataPt & iStart,
                                                    const CATWBSegmentFunctionDataPt & iEnd);

  // Create a 3-child operator (currently only ROUND)
  CATWBExpression* CreateOperator(const CATWBExpressionType   iType, 
                                        CATWBExpression     * ipExpr1,
                                        CATWBExpression     * ipExpr2,
                                        CATWBExpression     * ipExpr3);

  //CATWBConstant* CreateConstant(CATWBPredefinedConst iName);

private :
  //void BlackBoxDeletion();

  CATWBExpression* CloneExpression(const CATWBExpression                           * const   ipExpression,
                                         CATCDSMap<CATWBVariable*, CATWBVariable*>         & ioMappedVars,
                                   const CATCDSBoolean                                       iSameFactory);

protected:

  CATCDSLISTP(CATWBExpression) _lExpressions;
  CATCDSLISTP(CATWBExpression) _lVariables;

  CATCDSLISTP(CATWBEquation) _lEquations;
  int _equationLastId;

  //friend void CATWBBlackBoxOperator::RemoveBlackBox(const CATCDSBoolean); // allow this function access to private members

  //CATCDSLISTP(CATWBBlackBox) _lBlackBoxes;
  int _BBxLastId; // used only for default naming of BBx

  CATCDSLISTP(CATWBExpression) _lTmpExpressions;
  CATCDSBoolean _useTmpStorage;
  int _idxTmpProperty;

  mutable int _aIdxOfPredefinedConst[pcMax];

  CATCDSLISTP(CATWBExpression) _lSortedVariables;
  CATCDSBoolean _isVariablesSorted;
  CATCDSBoolean _bufferUsed;

  CATWBEnvironment _Env;

  CATCDSARRAY(CATWBPropRegistry) *_pPropRegistry;

  // Streaming
  // ---------

protected:

  friend class CATWBExpression;
  int GetAndIncrementGlobalTag(); // called during standard creation of expressions
  void UpdateGlobalTag(const int iTag); // called only during creation of expressions from streaming

  friend class CATWBxConstantUnStr;
  CATWBConstant* CreateConstant(const int * iTag, const CATWBValue & iValue);
  CATWBConstant* CreateIntegerConstant(const int * iTag, const int iValue);

  CATWBConstant* GetConstant(const int                  * iTag, 
                             const CATWBPredefinedConst   iType,
                             const CATCDSBoolean          iAllowCreation) const;

  friend class CATWBxConstantStr;
  CATCDSBoolean IsPredefinedConstant(const CATWBConstant        * iConst,
                                           CATWBPredefinedConst & oType) const;

  friend class CATWBxVariableUnStr;
  CATWBVariable* CreateVariable(const int * iTag);
  
  friend class CATWBxOperatorUnStr;
  CATWBExpression* CreateOperator(const int * iTag, const CATWBExpressionType iType, CATCDSLISTP(CATWBExpression) & ilExpr);

  CATWBExpression* CreateOperator(const int                  * iTag, 
                                  const CATWBExpressionType    iType,
                                  const int                    inExpr,
                                        CATWBExpression     ** iaExpr);
  
  CATWBExpression* CreateOperator(const int                 * iTag,
                                  const CATWBExpressionType   iType,
                                        CATWBExpression     * ipExpr);
  
  CATWBExpression* CreateOperator(const int                 * iTag,
                                  const CATWBExpressionType   iType,
                                        CATWBExpression     * ipExpr1,
                                        CATWBExpression     * ipExpr2);

  CATWBExpression* CreateOperator(const int                 * iTag,
                                  const CATWBExpressionType   iType,
                                        CATWBExpression     * ipExpr1,
                                        CATWBExpression     * ipExpr2,
                                        CATWBExpression     * ipExpr3);

  CATWBExpression* CreateBooleanOperator(const int                 * iTag,
                                               CATWBExpressionType   iType,
                                               CATWBExpression     * ipExpr);

  CATWBExpression* CreateBooleanOperator(const int                 * iTag,
                                               CATWBExpressionType   iType,
                                               CATWBExpression     * ipExpr1,
                                               CATWBExpression     * ipExpr2);

  CATWBExpression* CreateBinaryOperator(const int                 * iTag,
                                              CATWBExpressionType   iType,
                                              CATWBExpression     * ipExpr1,
                                              CATWBExpression     * ipExpr2);

  CATWBExpression* CreateStep(const int             * iTag, 
                                    CATWBExpression * ipExpr,
                              const double            iX0,
                              const double            iH0,
                              const double            iX1,
                              const double            iH1);

  CATWBExpression* CreateIfThenElse(const int             * iTag, 
                                          CATWBExpression * ipIfExpr,
                                          CATWBExpression * ipThenExpr,
                                          CATWBExpression * ipElseExpr);

  CATWBExpression* CreateIntegrateOperator(const int * iTag, CATWBExpression* ipExpr1, CATWBExpression* ipExpr2);

  CATWBExpression* CreateAlgebraicOperator(const int * iTag, const CATWBExpressionType iType, const int inExpr, CATWBExpression** iaExpr);

  CATWBExpression* CreateUnaryOperator(const int * iTag, CATWBExpressionType iType, CATWBExpression* ipExpr);
  CATWBExpression* CreateTrigonometricOperator(const int * iTag, CATWBExpressionType iType, CATWBExpression* ipExpr);

  friend class CATWBxBlackBoxOperatorUnStr;
  CATWBBlackBoxOperator* DeclareBlackBox(const int              * iTag,
                                         const CATWBBlackBox    * ipBB, 
                                         const int                inVariables,
                                               CATWBExpression ** iapVariables,
                                               CATCDSBoolean      iToDeleteByFactory);

private:
  
  //void CreateConstants();

  //CATWBConstant * _pIndefinite;
  //CATWBConstant * _pInvalid;
  //CATWBConstant * _pMinusOne;
  //CATWBConstant * _pZero;
  //CATWBConstant * _pPi;
  //CATWBConstant * _pPiByTwo;
  //CATWBConstant * _pOne;
  //CATWBConstant * _pTwo;
  //CATWBConstant * _pThree;
  //CATWBConstant * _pDToR;
  //CATWBConstant * _pRToD;

  //const unsigned int _WBLevel;

  CATWBFactory(const CATWBFactory&);
  void operator=(const CATWBFactory&);

  friend class ODT_StreamJSON; // to allow the ODT to validate the tag
  int _GlobalTag;

  // Debug
  // -----
  
  WBX_DEBUG_DECLARE;

#ifdef WBX_DEBUG_TRACE
public:

  CATCDSBoolean _InternalMode;
  int _ExprIndexInFactory;
  int _ExprIndexInFactoryInternal;

private:
  static int _FactoryInstanceCounter;

public:
  const  int _FactoryInstanceIndex;

protected:

  void Debug_PrintSummary() const;
#endif // WBX_DEBUG_TRACE
};

//-----------------------------------------------------------------------

#endif
