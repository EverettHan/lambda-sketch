// ============================================================================
// COPYRIGHT Dassault Systemes 2010
// ============================================================================
//
// CATWBConstNode
//
// ============================================================================
//   /10/11 KJD Creation
// 26/11/19 Q48 Migration to use CATWBEnvironment
// ============================================================================
#ifndef CATWBConstNode_H
#define CATWBConstNode_H

// Base class
#include "CATWBNode.h"

// Exported by
#include "WhiteBoxModel.h"

// CDS
#include "CATCDSVirtual.h"
#include "CATCDSString.h"
#include "CATCDSErrorDef.h"
#include "CATCDSBoolean.h"

// WBx
#include "CATWBValue.h"
#include "CATWBEnvironment.h"

CATCDSLISTP_FORWARD(CATCDSString);

class ExportedByWhiteBoxModel CATWBConstNode : public CATWBNode
{
// Constructor and destructor
protected:
  CATWBConstNode(const CATWBLocation    & iLocation,
                 const CATWBEnvironment & iEnv,
                 const CATWBValue       & iValue,
                 const CATWBLocation    & iUnitLocation,
                 const CATCDSString     & iUnit);

public:
  static HRESULT New(const CATWBLocation     & iLocation,
                     const CATWBEnvironment  & iEnv,
                     const CATWBValue        & iValue,
                           CATWBConstNode   *& oNode);

  static HRESULT New(const CATWBLocation     & iLocation,
                     const CATWBEnvironment  & iEnv,
                     const CATWBValue        & iValue,
                     const CATWBLocation     & iUnitLocation,
                     const CATCDSString      & Unit,
                           CATWBConstNode   *& oNode);

  virtual ~CATWBConstNode();

  virtual void FillPresentVariables(CATCDSLISTP(CATCDSString) & oVarNames) const CATCDSOverride;
  virtual CATCDSBoolean IsConstant() const CATCDSOverride;
  virtual CATCDSBoolean IsEqual(CATWBNode * iOtherTerm) const CATCDSOverride ;

  // Visitor entry point
  virtual HRESULT Accept(CATWBVisitor &v) CATCDSOverride;
  CATCDSBoolean IsADimensionalConstant() ;  
 
  const CATWBValue& GetValue() const;
  CATCDSBoolean IsDimensional();
  void SetIsDimensional(CATCDSBoolean IsDimensional);


private:
  CATWBValue _Value;
};

#endif 
