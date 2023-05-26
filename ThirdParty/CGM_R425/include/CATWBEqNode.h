// ============================================================================
//
// CATWBEqNode
//
// ============================================================================
//   /10/11 KJD Creation
// 26/11/19 Q48 Migration to use CATWBEnvironment
// ============================================================================
#ifndef CATWBEqNode_H
#define CATWBEqNode_H

#ifndef NULL
#define NULL 0
#endif

// Base class
#include "CATWBNode.h"

// ExportedBy
#include "WhiteBoxModel.h"

// CDS
#include "CATCDSVirtual.h"
#include "CATCDSErrorDef.h"

// WBx
#include "CATWBTypes.h"

CATCDSLISTP_FORWARD(CATCDSString);

class ExportedByWhiteBoxModel  CATWBEqNode   : public CATWBNode
{
  // Constructor and destructor
protected:
  CATWBEqNode(const CATWBLocation     & iLocation,
              const CATWBEnvironment  & iEnv,
                    CATWBNode         * iLHS,
              const CATWBEquationType   iType,
                    CATWBNode         * iRHS,
              const int                 iId,
                    CATWBEqNode       * ipPrevEquation = NULL);

public:
  static HRESULT New(const CATWBLocation      & iLocation,
                     const CATWBEnvironment   & iEnv,
                           CATWBNode         *  iLHS,
                     const CATWBEquationType    iType,
                           CATWBNode         *  iRHS,
                     const int                  iId,
                           CATWBEqNode       *  ipPrevEquation,
                           CATWBEqNode       *& oNode);

  virtual ~CATWBEqNode();

  CATWBEquationType& GetWBEqType();
  int GetId();
  CATWBNode * GetLeftTerm();
  CATWBNode * GetRightTerm();

  // This method creates the pointers on the CATCDSTring which stores the name of the variables.
  // WARNING :It is left to the caller to delete them !!!!
  virtual void FillPresentVariables(CATCDSLISTP(CATCDSString) & oVarNames) const CATCDSOverride;
  virtual CATCDSBoolean IsConstant() const CATCDSOverride;
  virtual CATCDSBoolean IsEqual(CATWBNode * iOtherTerm) const CATCDSOverride ;

  CATWBEqNode* GetPrev() const;
  CATWBEqNode* GetNext() const;
  void SetPrev(CATWBEqNode* iPrevEq) ;
  void SetNext(CATWBEqNode* iNextEq) ;

  // Visitor entry point
  virtual HRESULT Accept(CATWBVisitor &v) CATCDSOverride;


private:
  CATWBEquationType _Type;
  int _Id;
  CATWBNode * _LeftTerm;
  CATWBNode * _RightTerm;
  CATWBEqNode * _pPrev;
  CATWBEqNode * _pNext;
};

#endif 
