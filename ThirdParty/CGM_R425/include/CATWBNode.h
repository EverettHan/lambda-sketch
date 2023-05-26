// ============================================================================
//
// CATWBNode
//
// ===================================================================
//   /10/11 KJD Creation
// 26/11/19 Q48 Migration to use CATWBEnvironment
// ===================================================================
#ifndef CATWBNode_H
#define CATWBNode_H

// ExportedBy
#include "WhiteBoxModel.h"

// CDS
#include "CATCDSListP.h"
#include "CATCDSErrorDef.h"

// WBx
#include "CATWBLocation.h"
#include "CATWBEnvironment.h"
#include "CATWBTypes.h"

class CATWBVisitor;
class CATCDSString;
CATCDSLISTP_FORWARD(CATCDSString);

class ExportedByWhiteBoxModel CATWBNode
{
public:

  // Constructor and destructor
  CATWBNode(const CATWBLocation    & iLocation,
            const CATWBEnvironment & iEnv);

  virtual ~CATWBNode();

  // This method creates the pointers on the CATCDSTring which stores the name of the variables.
  // WARNING :It is left to the caller to delete them !!!!
  virtual void FillPresentVariables(CATCDSLISTP(CATCDSString) & oVarNames) const = 0;
  virtual CATCDSBoolean IsConstant() const = 0;
  virtual CATCDSBoolean IsEqual(CATWBNode * iOtherTerm) const = 0;
  static void Free(void *self);

  //  Visitor entry point
  virtual HRESULT Accept(CATWBVisitor &v) = 0;

  //  Accessors
  const CATWBLocation &GetLocation() const;
  const CATWBNodeType GetNodeType() const;

  const CATCDSString & GetUnit() const;
  const CATWBLocation & GetUnitLocation() const;
  const CATCDSString & GetUnitType() const;
  void SetUnitData(const CATWBLocation & iLoc, const CATCDSString & iString) ;

  CATWBNode* GetParentNode() const;
  void SetParentNode(CATWBNode* iParent);
  int  GetItsIndexAsChild() const;
  void SetItsIndexAsChild(const int  iIndex);

  const CATWBEnvironment& GetEnvironment() const;

protected:
  CATWBNodeType _NodeType;
  
        CATWBLocation      _Location;
  const CATWBEnvironment & _Env;
  
  CATCDSString _Unit;
  CATCDSString _UnitType;
  CATWBLocation _UnitLocation;
  
  CATWBNode * _ParentNode;
  int _ChildIndex;

};

CATCDSLISTP_DECLARE_EXPORTED(CATWBNode, ExportedByWhiteBoxModel);

#endif 
