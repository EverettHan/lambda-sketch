// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBEquation.h
// Header definition of CATWBEquation
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /12/06     Creation (Vladislav Kornienko)
//===================================================================

#ifndef CATWBEquation_h
#define CATWBEquation_h

#include "CATCDSString.h"
#include "WhiteBoxData.h"
#include "CATWBTypes.h"
#include "CATCDSListP.h"
#include "CATCDSIntArray.h"

class CATWBFactory;
class CATWBExpression;
class CATWBVariable;
CATCDSLISTP_FORWARD(CATWBVariable);

// To solve the problem of converting knowledge "rules", we may need to store the left-
// and right-side of the equation.
// Knowledge rules are of the form #2 = f(#1)
// WBEquations     are of the form #2 - f(#1) = 0
//   some applications need just f(#1) ==> we need to store separately the LHS and RHS
//#define Q48_ConvertedEquations
// Put behind a define flag - not needed for now (just keep in case current approach fails)

//-----------------------------------------------------------------------
 /**
  * @brief The CATWBEquation class represents the structure which manages the equations
  */
class ExportedByWhiteBoxData CATWBEquation
{
public:
  CATWBEquation(      CATWBFactory      & iFactory,
                      CATWBExpression   * ipRoot,
                const CATWBEquationType   iType,
                const int                 iId,
                      CATWBEquation     * ipPrevEquation = NULL);

  ~CATWBEquation();

  CATWBFactory* GetFactory() const;

  void SetRoot(CATWBExpression * ipRoot);
  
  CATWBExpression * GetRoot();
  const CATWBExpression * GetRoot() const;

  CATWBEquationType GetType() const;

  int GetId() const;

  virtual void SetName(const CATCDSString& iaName);
  const CATCDSString& GetName() const;
  const char* GetStrName() const { return GetName().str(); }

  /*const*/ CATWBEquation* GetPrev() const;
  /*const*/ CATWBEquation* GetNext() const;

#ifdef Q48_ConvertedEquations
  // Get / set the left- and right- sides of the equation (from converter)
  void SetSides(CATWBExpression *  iLHS, CATWBExpression *  iRHS);
  void GetSides(CATWBExpression *& oLHS, CATWBExpression *& oRHS) const;
#endif

  // Fills the list of the pointers of the variables which are used in the equation.
  CATCDSBoolean FindPresentVariables(CATCDSLISTP(CATWBVariable) &oWBVariableList) const;
  void SetTheoreticalVarList(CATCDSIntArray * iTheoreticalVarList);
  void GetTheoreticalVarList(CATCDSIntArray * ioTheoreticalVarList) const;
  CATCDSBoolean AreVarConsistent();

  /**
   * Duplicates the root of the equation with the same variables.  
   * Then the initial root is replaced by its copy.
   * Method used by the symbolic transformations to preserve the terms of the root to simplify
   **/
  void DuplicateRoot();

private : 
  CATWBExpression * Clone(CATWBExpression * iExpr);

protected:

        CATWBFactory      & _factory;
        CATWBExpression   * _pRoot;
  const CATWBEquationType   _type;
  const int                 _id;

  CATCDSString        _name;
  CATCDSIntArray      _TheoreticalVarList;
  CATWBEquation     * _pPrev;
  CATWBEquation     * _pNext;

#ifdef Q48_ConvertedEquations
  // Some equations (from conversion of knowledge rule) are really LHS = RHS
  // but are stored as LHS - RHS = 0
  // For ease, we store the LHS and RHS expressions for later
  CATWBExpression   * _pLHS;
  CATWBExpression   * _pRHS;
#endif
};

//-----------------------------------------------------------------------

CATCDSLISTP_DECLARE_EXPORTED(CATWBEquation, ExportedByWhiteBoxData);

#endif
