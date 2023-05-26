// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATWBBlackBoxOperator.h
// Header definition of CATWBBlackBoxOperator
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /01/07      Creation (Sergey Lipski)
// 23/03/17 Q48  Refactor of differentiate methods
// 24/07/18 Q48  Make DoEval const (for printer)
// 29/07/19 Q48  Add protected constructor for JSON streaming
// 05/08/19 Q48  Make BBx a pointer (can be removed outside this class)
// 05/08/19 Q48  Life-cycle management of BBx
// 25/01/23 Q48  Migrate to new BBx architecture
//===================================================================

#ifndef CATWBBlackBoxOperator_h
#define CATWBBlackBoxOperator_h

// Class header
#include "CATWBBlackBoxBaseOperator.h"

// ExportedBy
#include "WhiteBoxData.h"

// C++11
#include "CATCDSVirtual.h"

// CDS
#include "CATCDSString.h"

class CATWBBlackBoxBase;

//-----------------------------------------------------------------------
/**
* @brief The CATWBBlackBoxOperator class represents the structure managing the operator associated to the BlackBox objects
*/
class ExportedByWhiteBoxData CATWBBlackBoxOperator : public CATWBBlackBoxBaseOperator
{
private:

  CATWBBlackBoxOperator(      CATWBFactory     & iFactory,
                        const int                inVariables,
                              CATWBExpression ** iapVariables,
                        const CATWBBlackBox    & iBlackBox,
                        const int                iId);

public:

  virtual ~CATWBBlackBoxOperator();

  virtual const CATWBBlackBox* GetBlackBox() const /*CATCDSOverride*/;

  CATCDSString GetBlackBoxName() const CATCDSOverride;
  //void SetBlackBoxName(const CATCDSString & iName);

  virtual CATCDSBoolean IsEqualTo(const CATWBExpression * ipExpression) const CATCDSOverride;

  virtual CATCDSBoolean IsADerivative() const CATCDSOverride CATCDSFinal;

  //static CATCDSString GetDefaultBlackBoxName(const CATWBBlackBoxOperator * iOp);


protected:
  
  virtual double DoEval()                    const CATCDSOverride; // Required for CATCkeWBBlackBox
  virtual void   DoEval(CATWBValue & oValue) const CATCDSOverride;

  virtual CATWBExpression* DifferentiateProtected(CATWBVariable * ipVariable) CATCDSOverride;

  CATWBExpression* DifferentiateChild(const int iChildIndex, /*const*/ CATWBExpression* iChildDeriv) CATCDSOverride;

  // Streaming
  // ---------

protected:

  friend class CATWBFactory;
  CATWBBlackBoxOperator(      CATWBFactory     & iFactory,
                        const int                iTag,
                        const int                inVariables,
                              CATWBExpression ** iapVariables,
                        const CATWBBlackBox    & iBlackBox,
                        const int                iId);

  // Life cycle
  // ----------

private:

   void SetInternalBBx();
   void SetExternalBBx();

  friend class CATWBBlackBoxBase;
  void RemoveBlackBox(/*const CATCDSBoolean iIsInternalBBx*/); // called during CATWBBlackBox destructor

  // Data
  // ----

private:

  const CATWBBlackBox * _BlackBox;
  const int             _FactoryID; // the position of the BBx in the factory list (internal - used for default naming of BBx so not streamed)

#ifdef WBX_DEBUG_TRACE
public:

  virtual CATCDSString Debug_SymbolString(const short iLongMode) const CATCDSOverride;
#endif

};
//-----------------------------------------------------------------------
#endif
