// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBModel.h
// Header definition of CATWBModel
//
//===================================================================
//
// Usage notes: A class for the parse of the White Boxes equations.
//
//===================================================================
//   /10/11 KJD Creation
// 04/10/17 Q48 New method for FillFactory (conversion knowledge rule)
// 26/11/19 Q48 Migration to use CATWBEnvironment
//===================================================================

#ifndef CATWBModel_h
#define CATWBModel_h

#include "WhiteBoxModel.h"
#include "CATWBTypes.h"
#include "CATWBNode.h"
#include "CATWBVarNode.h"
#include "CATWBOpNode.h"
#include "CATWBBlackBox.h"
#include "CATCDSListP.h"

class CATWBLocation;
class CATWBVisitor;
class CATWBConstNode;
class CATWBEqNode;
class CATWBValue;
class CATWBFactory;
class CATWBVariable;
class CATWBExpression;
class CATWBBBx;
class CATCDSString;
class CATCDSIntArray;

CATCDSLISTP_FORWARD(CATWBVarNode);
CATCDSLISTP_FORWARD(CATWBExpression);

//-----------------------------------------------------------------------
 /**
  * @brief The CATWBModel class represents the structure where is stored all the terms of the formal expressions and which manages the units
  */
class ExportedByWhiteBoxModel CATWBModel
{
public:
  CATWBModel(); //deprecated
  CATWBModel(unsigned int iWBLevel); // iCDSLevel = versioning level 
  virtual ~CATWBModel();

  // Visitor entry point
  virtual HRESULT Accept(CATWBVisitor &v);

  CATWBConstNode* CreateConstant(const CATWBLocation & iLocation, 
                                 const CATWBValue    & iVal);

  CATWBConstNode* CreateConstant(const CATWBLocation & iLocation,
                                 const CATWBValue    & iVal,
                                 const CATWBLocation & iUnitLocation,
                                 const CATCDSString  & iUnit);

  // A variable is defined by its name and its location.
  // Notice that there can be several variables with the same name but not the same location.
  CATWBVarNode* CreateVariable(const CATWBLocation & iLocation,
                               const CATCDSString  & iName);
  
  int GetNbOfVariables() const;
  int GetNbOfDifferentVariables() const;
  
  //return one of the occurences of the variable of name iName if there are several ones
  CATWBVarNode* GetVariable(const CATCDSString& iName);
  int GetVariable(const CATCDSString& iName, CATCDSLISTP(CATWBVarNode) & oListOfVarNode);
  CATWBVarNode* GetVariable(const CATCDSString& iName, const CATWBLocation & ilocation);

  CATWBOpNode* CreateOperator(const CATWBLocation          & iLocation,
                              const CATWBExpressionType      iType,
                                    CATCDSLISTP(CATWBNode) & pChildren);

  CATWBOpNode* CreateOperator(const CATWBLocation          & iLocation,
                              const CATWBExpressionType      ieType,
                              const CATWBComparisonType      icType,
                                    CATCDSLISTP(CATWBNode) & pChildren);

  CATWBOpNode* DeclareBlackBox(const CATWBLocation          & iLocation,
                                     CATWBBlackBox          * ipBBx,
                                     CATCDSLISTP(CATWBNode) & pChildren);

  CATWBEqNode* AddEquation(CATWBNode* ipLeftRoot);
  
  CATWBEqNode* AddEquation(const CATWBLocation     & iLocation,
                                 CATWBNode         * ipLeftRoot,
                           const CATWBEquationType   iType,
                                 CATWBNode         * ipRightRoot = NULL);
  
  int GetNbOfEquations() const;
  CATWBEqNode* GetEquationById(int iId);
  CATWBEqNode* GetFirstEquation();
  CATWBEqNode* GetLastEquation();
  CATWBEqNode* GetNextEquation(CATWBEqNode* ipEquation);
  CATWBEqNode* GetPrevEquation(CATWBEqNode* ipEquation);
  void RemoveEquation(CATWBEqNode* &ipEquation);
  void GetBlackBoxes(CATCDSLISTP(CATWBBlackBox) * pBBxList);
  CATWBOpNode * GetBBxOp(const CATCDSString& iBBxName, CATCDSLISTP(CATWBNode) & pChildren);

  HRESULT FillFactory(      CATWBFactory                 &       ioFactory,
                            CATCDSIntArray               &       oListId,
                      const int                                  iNbElem       = 0,
                            CATWBVarNode   const * const * const iVarNodeArray = NULL,
                            CATWBVariable        *       * const ioVariables   = NULL);

  HRESULT FillFactory(      CATWBFactory                               &       ioFactory,
                      const int                                                iNbElem,
                            CATWBVarNode                 const * const * const iVarNodeArray,
                            CATWBVariable                      *       * const ioVariables,
                            CATCDSLISTP(CATWBExpression)               &       oWBExprList1,
                            CATCDSLISTP(CATWBExpression)               *       oWBExprList2);

private:

  HRESULT ConvertVarNodeToExpr(const CATWBVarNode                 *         iVarNode,
                                     CATWBFactory                   &       ioFactory,
                                     CATWBVariable                 *&       oVarExpr,
                               const int                                    iNbElem,
                                     CATWBVarNode    const * const *  const iVarNodeArray,
                                     CATWBVariable         *       *  const ioVariables);

  HRESULT ConvertNodeToExpr(const CATWBNode                     *        iNode, 
                                  CATWBFactory                   &       ioFactory,
                                  CATWBExpression               *&       oExpr,
                            const int                                    iNbElem,
                                  CATWBVarNode    const * const *  const iVarNodeArray,
                                  CATWBVariable         *       *  const ioVariables);
  
  int Locate(const CATWBNode                  * const iNode,
             const int                                iNbElem,
                   CATWBVarNode const * const * const iVarNodeArray) const;

  // Versioning
  unsigned int GetWBLevel() const;

private:
  
  const CATWBEnvironment _Env;

  CATCDSLISTP(CATWBNode)     _ListOfNodes;
  CATCDSLISTP(CATWBVarNode)  _ListOfVarNodes;
  int                        _NbOfVarWithDifferentNames;
  CATCDSLISTP(CATWBNode)     _ListOfEqNodes;
  CATCDSLISTP(CATWBBlackBox) _ListOfBlackBoxes;
  CATCDSLISTP(CATWBOpNode)   _ListOfBBxOp;
  int                        _EqLastId;
  CATWBModel(const CATWBModel&);
  void operator=(const CATWBModel&);
};

//-----------------------------------------------------------------------

#endif
