// COPYRIGHT Dassault Systemes 2011
//=============================================================================
//
// CATWBEquationPrinter.h
// Header definition of CATWBEquationPrinter
//
//=============================================================================
//
// Usage notes: A class for printing White Boxes equations
//
//=============================================================================
//
//   /02/11      Creation (Benoit PERROT)
// 24/07/18 Q48  Print methods to take const arguments
// 26/07/18 R1Y  Added debug trace and resolved issues with plus and minus signs
// 16/10/18 R1Y  Modified the Print() functions (removed default arguments)
// 02/01/19 Q48  Added const for Print of CATWbFactory
// 04/03/19 R1Y  Printed expressions with variables in lexicographical order.
// 03/12/19 R1Y  Added CloneExpressionIntoFactory().
//=============================================================================

#ifndef CATWBEquationPrinter_h
#define CATWBEquationPrinter_h

#include "WhiteBoxUtilities.h"

#include "CATWBTypes.h"
#include "CATCDSBoolean.h"

//#ifdef _AIX_SOURCE
//#undef throw
//#undef catch
//#undef try
//#endif
//#include "CATCDSMap.h"
//#ifdef _AIX_SOURCE
//#   define throw ERROR
//#   define catch ERROR
//#   define try ERROR
//#endif

#include "CATCDSString.h"
#include "CATCDSMapForward.h"

#include "CATWBDebug.h"

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

class ExportedByWhiteBoxUtilities CATWBEquationPrinter
{
public:
  
  //Factory management

  // Print() Overload #1
  static void Print(      CATCDSString  & output,
                    const CATWBFactory  & iFactory,
                    const CATCDSBoolean & iWithEqName);
      
  // Print() Overload #2
  static void Print(      CATCDSString  & output,
                    const CATWBFactory  & iFactory);

  // Print() Overload #3
  static void Print(      CATCDSString    & output, 
                    const CATWBExpression * iExpr);

  // Print() Overload #4
  static void Print(      CATCDSString    & output, 
                    const CATWBExpression & iExpr);
 
  // Print() Overload #5
  static void Print(      CATCDSString    & output, 
                    const CATWBExpression & iExpr,
                    const int               iPrecisonAfterComma);

  // Print() Overload #6
  static void Print(      CATCDSString  & output,
                    const CATWBVariable & v);

  // Print() Overload #7
  static void Print(      CATCDSString & output,
                    const CATWBValue   & v);

  // Print() Overload #8
  static void Print(      CATCDSString  & output,
                    const CATWBEquation & iEquation);

  // Print() Overload #9
  //For the API with const char *, don't forget to remove the returned value with delete []
  static const char * Print(const CATWBEquation & iEquation,
                            const CATCDSBoolean & iWithName);

  // Model management

  // Print() Overload #10
  static void Print(CATCDSString & output, 
                    CATWBModel   & model);

  // Print() Overload #11
  static void Print(CATCDSString & output, 
                    CATWBNode    & n);

  // Function to clone an expression from one factory into another.
  // Note that if cloning is successful then the return value of "oNewExpr" is not null.
  static void CloneExpressionIntoFactory(const CATWBExpression * const   iExpr,
                                               CATWBFactory            & ioNewFactory,
                                               CATWBExpression *       & oNewExpr);

  // Public member data
  // ------------------
  static /*const*/ bool _ifthenelsescopeCmode;

private:

  // A class that is used for sorting expressions into an order for printing.
  class ExpressionOrder
  {
  public:

    // Constructor.
    ExpressionOrder(const CATWBExpression * const iExpr,
                    const int                     iNumOrders,
                    const int             * const iOrders);

    // Destructor.
    ~ExpressionOrder();

    // Function to obtain the expression.
    inline const CATWBExpression * const GetExpression() const;

    // Function to obtain the number of order values for printing the expression.
    inline int GetNumOrders() const;

    // Function to obtain a specified order value for printing for the expression.
    inline int GetOrder(const int iOrderIndex) const;

  private:

    const CATWBExpression * const _Expr;       // the expression
    const int               _NumOrders;  // the number of order values for printing the expression
          int       *       _Orders;     // the order values for printing the expression
  };

  //Factory management

  // Print() Overload #12
  static void Print(      CATCDSString  & output,
                    const CATWBFactory  & factory,
                    const CATCDSBoolean & iWithEqName,
                    const int             iPrecisonAfterComma);

  // Print() Overload #13
  static void Print(      CATCDSString    & output, 
                    const CATWBExpression & iExpr,
                    const int               iPrecisonAfterComma,
                    const int             & iIndex);
  
  // Print() Overload #14
  static void Print(      CATCDSString & output,
                    const CATWBValue   & v,
                    const int            iPrecisonAfterComma);

  // Print() Overload #15
  static void Print(      CATCDSString  & output,
                    const CATWBEquation & iEquation,
                    const CATCDSBoolean & iWithName);

  // Print() Overload #16
  static void Print(      CATCDSString  & output,
                    const CATWBEquation & equation,
                    const CATCDSBoolean & iWithName, 
                    const int             iPrecisonAfterComma);

  // Print() Overload #17
  //For the API with const char *, don't forget to remove the returned value with delete []
  static const char * Print(const CATWBEquation & iEquation,
                            const CATCDSBoolean & iWithName,
                            const int             iPrecisonAfterComma);

  // Model management

  // Print() Overload #18
  static void Print(      CATCDSString & output, 
                          CATWBModel   & model,
                    const int            iPrecisonAfterComma);

  // Print() Overload #19
  static void Print(      CATCDSString & output, 
                          CATWBNode    & n, 
                    const int            iPrecisonAfterComma,
                    const int          & index);

  // Helper functions

  // Print() Overload #20
  static void Print(      CATCDSString      & output, 
                    const CATWBEquationType   t);

  // Print() Overload #21
  static void Print(      CATCDSString        & output,
                    const CATWBExpressionType   t);

  // Print() Overload #22
  static void Print(      CATCDSString        & output, 
                    const CATWBExpressionType   et, 
                    const CATWBComparisonType   ct);

  // Print() Overload #23
  static void Print(      CATCDSString  & output,
                    const CATWBConstant & c,
                    const int             iPrecisonAfterComma);

  // Print() Overload #24
  static void Print(      CATCDSString & output, 
                          CATWBEqNode  & equation,
                    const int            iPrecisonAfterComma);

  // Print() Overload #25
  static void Print(CATCDSString & output, 
                    CATWBVarNode & v);

  // Print() Overload #26
  static void Print(      CATCDSString   & output,
                          CATWBConstNode & c,
                    const int              iPrecisonAfterComma);
  
  // Function to print an expression with the variables in lexicographical order.
  static CATCDSBoolean PrintWithOrderedVariables(      CATCDSString            & output,
                                                 const CATWBExpression * const   iExpr);

  // --------------------------------------------------------------------
  // Deprecated: no longer since CATWBx_Factory_CloneBBx is active
  // 
  // Function to clone an expression in a factory
  // --------------------------------------------------------------------
  static CATWBExpression * CloneExpression(const CATWBExpression                           * const   iExpr,
                                                 CATWBFactory                                      & ioFactory,
                                                 CATCDSMap<CATWBVariable*, CATWBVariable*>         & ioMappedVars);

  // --------------------------------------------------------------------
  // Deprecated: no longer since CATWBx_Factory_CloneBBx is active
  // 
  // Function to partially clone a black-box expression in a factory
  // Note that only the children and name of the original black box are cloned
  // --------------------------------------------------------------------
  static CATWBExpression * PartiallyCloneBlackBoxExpr(const CATWBExpression                           * const   iExpr,
                                                            CATWBFactory                                      & ioFactory,
                                                            CATCDSMap<CATWBVariable*, CATWBVariable*>         & ioMappedVars);

  // Function to compare the names of variables.
  // This function, which is used to sort variables names in lexicographical order, is a helper function for PrintWithOrderedVariables().
  static int CompareVariableNames(const CATWBVariable * const iVariable1,
                                  const CATWBVariable * const iVariable2);

  // Function to reorder the children of expressions that are sums and products (so that it is easier to print terms in the required order).
  static void ReorderSumsAndProducts(const CATWBExpressionType           iParentExprType,
                                     const int                           iExprIndexInParent,
                                           CATWBExpression     * const & ioParentExpr,
                                           CATWBExpression     * const & ioExpr);

  // Function to (a) reorder the children of an expression (if necessary) according to the lexicographical order of its variables
  // and (b) obtain data for determining the order of printing for terms in the expression.
  static void ReorderChildrenAndGetData(const CATWBExpressionType                       iParentExprType,
                                        const CATCDSMap<CATWBVariable *, int>         & iVarOrderMap,
                                              CATWBExpression                 * const & ioExpr,
                                              int                                     & oTotalNumChildren,
                                              int                                     & oVariableOrder,
                                              int                                     & oVarPowerX,
                                              int                                     & oVarPowerY,
                                              int                                     & oVarPowerZ,
                                              int                                     & oExprTypeOrderX,
                                              int                                     & oExprTypeOrderY,
                                              int                                     & oExprTypeOrderZ,
                                              int                                     & oExprPowerX,
                                              int                                     & oExprPowerY,
                                              int                                     & oExprPowerZ);

  // Function to initialise data for determining the order of printing for an expression.
  static void InitialiseData(int & oTotalNumChildren,
                             int & oVariableOrder,
                             int & oVarPowerX,
                             int & oVarPowerY,
                             int & oVarPowerZ,
                             int & oExprTypeOrderX,
                             int & oExprTypeOrderY,
                             int & oExprTypeOrderZ,
                             int & oExprPowerX,
                             int & oExprPowerY,
                             int & oExprPowerZ);

  // Function to update the data for determining the order of printing for a constant.
  static void UpdateDataForConstant(const CATWBFactory        * const   iFactory,
                                    const CATWBExpressionType           iParentExprType,
                                          int                         & oTotalNumChildren,
                                          int                         & oVariableOrder);

  // Function to update data for determining the order of printing for a variable.
  static void UpdateDataForVariable(const CATWBExpressionType                       iParentExprType,
                                    const CATCDSMap<CATWBVariable *, int>         & iVarOrderMap,
                                    const CATWBVariable                   * const   iVariable,
                                          int                                     & oTotalNumChildren,
                                          int                                     & oVariableOrder,
                                          int                                     & oVarPowerX,
                                          int                                     & oVarPowerY,
                                          int                                     & oVarPowerZ,
                                          int                                     & oExprTypeOrderX,
                                          int                                     & oExprTypeOrderY,
                                          int                                     & oExprTypeOrderZ);

  // Function to (a) reorder the children of an expression (if necessary) according to the lexicographical order of its variables
  // and (b) update data for determining the order of printing for terms in the expression.
  static void ReorderChildrenAndUpdateData(const CATWBExpressionType                       iParentExprType,
                                           const CATWBExpressionType                       iExprType,
                                           const CATCDSMap<CATWBVariable *, int>         & iVarOrderMap,
                                                 CATWBExpression                 * const & ioExpr,
                                                 int                                     & oTotalNumChildren,
                                                 int                                     & oVariableOrder,
                                                 int                                     & oVarPowerX,
                                                 int                                     & oVarPowerY,
                                                 int                                     & oVarPowerZ,
                                                 int                                     & oExprTypeOrderX,
                                                 int                                     & oExprTypeOrderY,
                                                 int                                     & oExprTypeOrderZ,
                                                 int                                     & oExprPowerX,
                                                 int                                     & oExprPowerY,
                                                 int                                     & oExprPowerZ);

  // Function to determine whether the children of an expression can be reordered.
  static CATCDSBoolean CanReorderChildren(const CATWBExpressionType & iExprType,
                                          const int                   iNumChildren);

  // Function to (a) reorder the child of an expression (if necessary) according to the lexicographical order of its variables and
  // (b) update data for determining the order of printing for terms in the expression.
  static void ReorderChildAndUpdateData(const CATWBExpressionType                       iExprType,
                                        const CATCDSMap<CATWBVariable *, int>         & iVarOrderMap,
                                        const int                                       iChildLoopIndex,
                                        const int                                       iExprTypeOrder,
                                        const CATCDSBoolean                             iReorderChildren,
                                        const int                                       iNumOrders,
                                              CATWBExpression                 * const   ioExpr,
                                              CATCDSBoolean                           & ioUpdateVarPowerX,
                                              CATCDSBoolean                           & ioUpdateVarPowerY,
                                              CATCDSBoolean                           & ioUpdateVarPowerZ,
                                              CATCDSBoolean                           & ioUpdateExprPowerX,
                                              CATCDSBoolean                           & ioUpdateExprPowerY,
                                              CATCDSBoolean                           & ioUpdateExprPowerZ,
                                              int                             * const   ioOrders,
                                              CATCDSArray<ExpressionOrder *>  * const   ioListOfExprOrders,
                                              int                                     & oTotalNumChildren,
                                              int                                     & oVariableOrder,
                                              int                                     & oVarPowerX,
                                              int                                     & oVarPowerY,
                                              int                                     & oVarPowerZ,
                                              int                                     & oExprTypeOrderX,
                                              int                                     & oExprTypeOrderY,
                                              int                                     & oExprTypeOrderZ,
                                              int                                     & oExprPowerX,
                                              int                                     & oExprPowerY,
                                              int                                     & oExprPowerZ);

  // Function to obtain the order of printing for the type of the expression.
  static int GetExpressionTypeOrder(const CATWBExpressionType         iParentExprType,
                                    const CATWBExpression     * const iExpr,
                                    const CATWBExpressionType         iExprType);

  // Function to obtain the order of printing for the power expression.
  static int GetExprTypeOrderForPower(const CATWBExpressionType         iParentExprType,
                                      const CATWBExpression     * const iExpr);

  // Function to obtain the power for each variable in an expression
  static void GetVarPowers(const CATWBExpression                 * const   iExpr,
                           const CATCDSMap<CATWBVariable *, int>         & iVarOrderMap,
                                 int                                     & oVarPowerX,
                                 int                                     & oVarPowerY,
                                 int                                     & oVarPowerZ);

  // Function to update data for determining the order of printing for terms in an expression.
  static void UpdateData(const CATWBExpressionType           iExprType,
                         const CATWBExpressionType           iChildExprType,
                         const CATWBExpression     * const   iChildExpr,
                         const int                           iChildLoopIndex,
                         const int                           iTotalNumChildren,
                         const int                           iVariableOrder,
                         const int                           iExprTypeOrder,
                         const int                           iVarPowerX,
                         const int                           iVarPowerY,
                         const int                           iVarPowerZ,
                         const int                           iExprTypeOrderX,
                         const int                           iExprTypeOrderY,
                         const int                           iExprTypeOrderZ,
                         const int                           iExprPowerX,
                         const int                           iExprPowerY,
                         const int                           iExprPowerZ,
                         const CATCDSBoolean                 iChildExprContainsX,
                         const CATCDSBoolean                 iChildExprContainsY,
                         const CATCDSBoolean                 iChildExprContainsZ,
                               CATCDSBoolean               & ioUpdateVarPowerX,
                               CATCDSBoolean               & ioUpdateVarPowerY,
                               CATCDSBoolean               & ioUpdateVarPowerZ,
                               CATCDSBoolean               & ioUpdateExprPowerX,
                               CATCDSBoolean               & ioUpdateExprPowerY,
                               CATCDSBoolean               & ioUpdateExprPowerZ,
                               int                         & ioVarPowerX,
                               int                         & ioVarPowerY,
                               int                         & ioVarPowerZ,
                               int                         & ioExprTypeOrderX,
                               int                         & ioExprTypeOrderY,
                               int                         & ioExprTypeOrderZ,
                               int                         & ioExprPowerX,
                               int                         & ioExprPowerY,
                               int                         & ioExprPowerZ,
                               int                         & oTotalNumChildren,
                               int                         & oVariableOrder);

  // Function to update the type and power value for an expression.
  static void UpdateExprTypeAndPower(const CATCDSBoolean   iExprIsProduct,
                                     const CATCDSBoolean   iExprIsStandardFunction,
                                     const int             iExprTypeOrder,
                                     const int             iExprPowerForVar,
                                           int           & ioExprTypeOrder,
                                           int           & ioExprPowerForVar);

  // Function to reorder the children of an expression.
  static void ReorderChildren(const CATCDSBoolean                            iReorderChildren,
                                    CATWBExpression                * const & ioExpr,
                                    CATCDSArray<ExpressionOrder *> * const   ioListOfExprOrders);

  // Function to obtain the index of a variable from the variable.
  static int GetIndexFromVariable(const CATCDSMap<CATWBVariable *, int>         & iVarOrderMap,
                                  const CATWBVariable                   * const   iVariable);

  // Function to obtain the order of printing a variable from the index of the variable.
  static int GetVariableOrderFromIndex(const int iVarIndex);

  // Function to obtain the index of a variable from the order of printing the variable.
  static int GetVariableIndexFromOrder(const int iVarOrder);

  // Function to compare the order of printing the terms in an expression.
  // This function, which is used to sort variables names in lexicographical order, is a helper function for ReorderChildrenAndGetData().
  static int CompareExpressionOrders(const ExpressionOrder * const iExprOrder1,
                                     const ExpressionOrder * const iExprOrder2);

  // Function to determine whether a minus sign should be printed (instead of a plus).
  static CATCDSBoolean MinusRatherThanPlus(const CATWBExpression & iExpr,
                                                 int             & oIndex);

  // Function to obtain the index of a child (of the input expression) that is a constant term (if there is one).
  static int GetIndexOfConstantChild(const CATWBExpression & iExpr);

  // Function to either (a) ignore a constant (for -1) or (b) print out the absolute value (for all other negative constants) and possibly an operator symbol.
  static void ProcessNegativeConstant(      CATCDSString        & output,
                                      const CATWBExpression     & iExpr,
                                      const int                   iIndex,
                                      const CATWBExpressionType & iType,
                                      const int                   iPrecisonAfterComma);

  // Debug
  // -----

  WBX_DEBUG_DECLARE;

};

#endif

// Inline functions
// ================

// Function to obtain the expression.
inline const CATWBExpression * const CATWBEquationPrinter::ExpressionOrder::GetExpression() const
{
  return _Expr;
}

// Function to obtain the number of order values for printing the expression.
inline int CATWBEquationPrinter::ExpressionOrder::GetNumOrders() const
{
  return _NumOrders;
}

// Function to obtain a specified order value for printing for the expression.
inline int CATWBEquationPrinter::ExpressionOrder::GetOrder(const int iOrderIndex) const
{
  return ((_Orders && (_NumOrders > 0) && (iOrderIndex >=0 ) && (iOrderIndex < _NumOrders)) ? _Orders[iOrderIndex] : 0);
}
