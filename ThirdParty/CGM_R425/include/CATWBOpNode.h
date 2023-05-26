// ============================================================================
//
// CATWBOpNode
//
// ============================================================================
//   /10/11 KJD Creation
// 26/11/19 Q48 Migration to use CATWBEnvironment
// ============================================================================
#ifndef CATWBOpNode_H
#define CATWBOpNode_H

// Base class
#include "CATWBNode.h"

// ExportedBy
#include "WhiteBoxModel.h"

// CDS
#include "CATCDSVirtual.h"
#include "CATCDSErrorDef.h"

// WBx
#include "CATWBTypes.h"
#include "CATWBBlackBox.h"

CATCDSLISTP_FORWARD(CATCDSString);

class ExportedByWhiteBoxModel CATWBOpNode : public CATWBNode
{
  // Opructor and destructor
protected:
  CATWBOpNode(const CATWBLocation          & iLocation,
              const CATWBEnvironment       & iEnv,
              const CATWBExpressionType      eType,
              const CATWBComparisonType      cType,
                    CATCDSLISTP(CATWBNode) & pChildren);

public:
  static HRESULT New(const CATWBLocation           & iLocation,
                     const CATWBEnvironment        & iEnv,
                     const CATWBExpressionType       etype,
                           CATCDSLISTP(CATWBNode)  & pChildren,
                           CATWBOpNode            *& oNode);

  static HRESULT New(const CATWBLocation           & iLocation,
                     const CATWBEnvironment        & iEnv,
                           CATWBBlackBox          *  ipBBx,
                           CATCDSLISTP(CATWBNode)  & pChildren,
                           CATWBOpNode            *& oNode);

  static HRESULT New(const CATWBLocation           & iLocation,
                     const CATWBEnvironment        & iEnv,
                     const CATWBExpressionType       etype,
                     const CATWBComparisonType       ctype,
                           CATCDSLISTP(CATWBNode)  & pChildren,
                           CATWBOpNode            *& oNode);

  virtual ~CATWBOpNode();

  const CATWBExpressionType &GetType() const;
  const CATWBComparisonType &GetComparisonType() const;
  int GetNbOfChildren() const;
  CATWBNode * GetChild(int iIdx) const;
  CATWBBlackBox * GetBlackBox() const;

  virtual void FillPresentVariables(CATCDSLISTP(CATCDSString) & oVarNames) const CATCDSOverride;
  virtual CATCDSBoolean IsConstant() const CATCDSOverride;
  virtual CATCDSBoolean IsEqual(CATWBNode * iOtherTerm) const CATCDSOverride;

  // Visitor entry point
  virtual HRESULT Accept(CATWBVisitor &v) CATCDSOverride;
  HRESULT VisitChildrenToFindVar(int iExceptChildWithIndex, CATCDSBoolean & oFound) ;  

private:
  CATWBExpressionType _eType;
  CATWBComparisonType _cType;
  CATWBBlackBox * _pBBx;
  CATCDSLISTP(CATWBNode) _pChildren;
};

CATCDSLISTP_DECLARE_EXPORTED(CATWBOpNode, ExportedByWhiteBoxModel);

#endif 
