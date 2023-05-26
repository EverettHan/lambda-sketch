// COPYRIGHT Dassault Systemes 2022
//===================================================================
//
// CATWBBlackBoxDerivOperator.h
// Header definition of CATWBBlackBoxDerivOperator
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
// 19/05/22 Q48  Creation
//===================================================================

#ifndef CATWBBlackBoxDerivOperator_h
#define CATWBBlackBoxDerivOperator_h

// Base class
#include "CATWBBlackBoxBaseOperator.h"

// ExportedBy
#include "WhiteBoxData.h"

// C++ 11
#include "CATCDSVirtual.h"

// CDS
#include "CATCDSString.h"

class CATWBFactory;
class CATWBVariable;
class CATWBBlackBoxOperator;

//-----------------------------------------------------------------------
/**
* @brief The CATWBBlackBoxOperator class represents the structure managing the operator associated to the BlackBox objects
*/
class ExportedByWhiteBoxData CATWBBlackBoxDerivOperator : public CATWBBlackBoxBaseOperator
{
private:

  //CATWBBlackBoxDerivOperator(      CATWBFactory              & iFactory,
  //                           const CATWBBlackBoxBaseOperator * ipBBxOp,
  //                                 CATWBVariable             * iDerivVar);

   friend class CATWBFactory;
   CATWBBlackBoxDerivOperator(CATWBFactory     & iFactory,
                              CATWBExpression ** iExprs);

public:

  virtual ~CATWBBlackBoxDerivOperator();

  //virtual const CATWBBlackBox* GetBlackBox() const CATCDSOverride;

  CATCDSString GetBlackBoxName() const CATCDSOverride;
  //void SetBlackBoxName(const CATCDSString & iName);

  //CATCDSString GetBlackBoxPrefix() const;
  //void SetBlackBoxPrefix(const CATCDSString & iPrefix);

  virtual CATCDSBoolean IsEqualTo(const CATWBExpression * ipExpression) const CATCDSOverride;

  //virtual double DoEval() const CATCDSOverride;
  
  virtual CATCDSBoolean IsADerivative() const CATCDSOverride CATCDSFinal;

protected:
  
  virtual void DoEval(CATWBValue & oValue) const CATCDSOverride;

  virtual CATWBExpression* DifferentiateProtected(CATWBVariable * ipVariable) CATCDSOverride;

  CATWBExpression* DifferentiateChild(const int iChildIndex, /*const*/ CATWBExpression* iChildDeriv) CATCDSOverride;

  // Streaming
  // ---------

protected:

   friend class CATWBFactory;
   CATWBBlackBoxDerivOperator(      CATWBFactory     & iFactory,
                              const int                iTag,
                                    CATWBExpression ** iExprs);

   // Data
   // ----

   CATCDSString _NamePrefix;

   // Debug
   // -----

private:
#ifdef WBX_DEBUG_TRACE
public:

   virtual CATCDSString Debug_SymbolString(const short iLongMode) const CATCDSOverride;
#endif
};
//-----------------------------------------------------------------------
#endif // CATWBBlackBoxDerivOperator_h
