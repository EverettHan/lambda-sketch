// COPYRIGHT Dassault Systemes 2011
//=============================================================================
//
// CATWBEquationMLPrinter.h
// Header definition of CATWBEquationMLPrinter
//
//=============================================================================
//
// Usage notes: A class for printing White Boxes equations
//
//=============================================================================
//
//   /02/11      Creation (Benoit PERROT)
// 24/07/18 Q48  Print methods to take const arguments
// 05/11/18 R1Y  Added the function QuotientIsSimpleFraction().
//=============================================================================

#ifndef CATWBEquationMLPrinter_h
#define CATWBEquationMLPrinter_h

#ifndef NULL
#define NULL 0
#endif

#include "WhiteBoxUtilities.h"

#include "CATWBTypes.h"
#include "CATCDSBoolean.h"
#include "CATCDSIntArray.h"

class CATCDSString;
class CATWBFactory;
class CATWBEquation;
class CATWBExpression;
class CATWBConstant;
class CATWBValue;
class CATWBVariable;
class CATWBModel;
class CATWBEqNode;
class CATWBNode;
class CATWBVarNode;
class CATWBConstNode;

class ExportedByWhiteBoxUtilities CATWBEquationMLPrinter
{
public:

  static void PrintML(CATCDSString &output, const CATWBValue      & v);
  static void PrintML(CATCDSString &output, const CATWBEquation   & equation);
  static void PrintML(CATCDSString &output, const CATWBExpression & e);

  static void PrintMLPlot (CATCDSString &output);
  static void PrintMLComma(CATCDSString &output);
  static void PrintMLError(CATCDSString &output, const CATCDSString & error);
  
  //iMode = 1  prints the begin  of the plot block
  //iMode = 2 prints the caracteristics of the curve
  //iMode = 3 prints the coordinates of the current point
  //iMode = 4  prints the end of the plot block
  static void PrintMLPlot2D(      CATCDSString  & output,
                            const CATWBEquation & equation, 
                            const double          iBox[4],
                            const double          iX,
                            const double          iY,
                            const int             iMode);

  static void PrintMLEval(      CATCDSString  & output,
                          const CATWBEquation & equation,
                          const CATWBValue    & v);
  
  //equation  is the equation to be evaluated
  //Expr the solution 
  //Array is the list of the id of the variabels to set
  //TheoVar is the boolean which is true if the equation is defined with theoritical var and which is false otherwise
  static void PrintMLPartialEval(      CATCDSString    & output, 
                                 const CATWBEquation   & equation,
                                 const CATWBExpression & Expr,
                                       CATCDSIntArray  * Array, 
                                 const CATCDSBoolean     TheoVar = FALSE);

  static void PrintAntiML(      CATCDSString    & output, 
                          const CATWBEquation   & equation,
                                CATWBVariable   * ipVariable,
                                CATWBExpression * expression = NULL);

  static void Print(CATCDSString &output, const CATWBExpression & iExpression, const int & index = -1);
  
  static void PrintStart(      CATCDSString        & output, 
                         const CATWBExpressionType   t);
  
  static void PrintEnd(      CATCDSString        & output, 
                       const CATWBExpressionType   t);
  
  static void Print(      CATCDSString        & output, 
                    const CATWBExpressionType   et,
                    const CATWBComparisonType   ct);
  
  static void Print(CATCDSString &output, const CATWBVariable &v);
  static void Print(CATCDSString &output, const CATWBConstant &c);
  static void Print(CATCDSString &output, const CATWBValue    &v);
  
  static void PrintHeader(CATCDSString &output, const CATWBEquation &e);

  static CATCDSBoolean  HasName(const CATWBEquation &equation);
  static void PrintDiffHeader(CATCDSString & output, const CATWBEquation & equation, const CATWBVariable & v);
  static  CATCDSBoolean IsInField(const CATWBExpression * iExpr, CATWBVariable * ioVar, CATWBValue & ioVal);

public: // for CATWBEquationPrinter

  static CATCDSBoolean IsNull(const CATWBExpression & iExpression, int & oindex);
  static CATCDSBoolean ForgetPlus(const CATWBExpression & iExpression);
  static CATCDSBoolean ParenthesisOrNot(const CATWBExpression & iExpression);
  static CATCDSBoolean ParenthesisOrNot(const CATWBNode & iNode);
  static CATCDSBoolean QuotientIsSimpleFraction(const CATWBExpression & iExpression,
                                                      int             & oNumer,
                                                      int             & oDenom);

private: // internal utilities

  static void AdvPrint(      CATCDSString    & output, 
                       const CATWBExpression * expr);

  static int CstNb(  const CATWBExpression & iExpression, 
                             int             & oindex,
                             int             & osign,
                     const   int               iFrom = 0);

private: // specific print methods

  static void Print_Sum     (CATCDSString & oString, const CATWBExpression & iExpression);
  static void Print_Product (CATCDSString & oString, const CATWBExpression & iExpression);
  static void Print_Quotient(CATCDSString & oString, const CATWBExpression & iExpression);

};

#endif
