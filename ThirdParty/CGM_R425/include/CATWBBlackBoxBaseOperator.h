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
//===================================================================

#ifndef CATWBBlackBoxBaseOperator_h
#define CATWBBlackBoxBaseOperator_h

// Class header
#include "CATWBOperator.h"

// ExportedBy
#include "WhiteBoxData.h"

// C++11
#include "CATCDSVirtual.h"

// CDS
#include "CATCDSString.h"

class CATWBFactory;
class CATWBExpression;
class CATWBVariable;
class CATWBBlackBox;

//-----------------------------------------------------------------------
/**
* @brief The CATWBBlackBoxOperator class represents the structure managing the operator associated to the BlackBox objects
*/
class ExportedByWhiteBoxData CATWBBlackBoxBaseOperator : public CATWBOperator 
{
public:

  CATWBBlackBoxBaseOperator(      CATWBFactory     & iFactory,
                            const int                inVariables,
                                  CATWBExpression ** iapVariables);

  virtual ~CATWBBlackBoxBaseOperator();
    
  //virtual const CATWBBlackBox* GetBlackBox() const = 0;

  virtual CATCDSString GetBlackBoxName() const = 0;

  //void SetBlackBoxName(const CATCDSString & iName) const;

  //virtual double DoEval() const CATCDSOverride CATCDSFinal;

  virtual CATCDSBoolean IsADerivative() const = 0;

  // Streaming
  // ---------

protected:

  //friend class CATWBFactory;
  CATWBBlackBoxBaseOperator(      CATWBFactory     & iFactory,
                            const int                iTag,
                            const int                inVariables,
                                  CATWBExpression ** iapVariables);
};
//-----------------------------------------------------------------------
#endif
