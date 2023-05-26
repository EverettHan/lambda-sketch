// ============================================================================
//
// CATWBVarNode
//
// ============================================================================
//   /10/11 KJD Creation
// 26/11/19 Q48 Migration to use CATWBEnvironment
// ============================================================================
#ifndef CATWBVarNode_H
#define CATWBVarNode_H

// Base class
#include "CATWBNode.h"

// ExportedBy
#include "WhiteBoxModel.h"

// CDS
#include "CATCDSVirtual.h"
#include "CATCDSString.h"
#include "CATCDSErrorDef.h"

// WBx
#include "CATWBValue.h"


CATCDSLISTP_FORWARD(CATCDSString);

class ExportedByWhiteBoxModel CATWBVarNode : public CATWBNode
{
  //Constructor and destructor
protected:
  CATWBVarNode(const CATWBLocation    & iLocation,
               const CATWBEnvironment & iEnv,
               const CATCDSString     & iName);

public:
  static HRESULT New(const CATWBLocation     & iLocation,
                     const CATWBEnvironment  & iEnv,
                     const CATCDSString      & iName,
                           CATWBVarNode    *& oNode);

  const CATCDSString& GetName() const;
  void SetUnitType(CATCDSString & iUnitType);
  virtual ~CATWBVarNode();

  virtual void FillPresentVariables(CATCDSLISTP(CATCDSString) & oVarNames) const CATCDSOverride;
  virtual CATCDSBoolean IsConstant() const CATCDSOverride;
  virtual CATCDSBoolean IsEqual(CATWBNode * iOtherTerm) const CATCDSOverride;
  // Visitor entry point
  virtual HRESULT Accept(CATWBVisitor &v) CATCDSOverride;

private:
  const CATCDSString _Name;
};
CATCDSLISTP_DECLARE_EXPORTED(CATWBVarNode, ExportedByWhiteBoxModel);
#endif 
