//===================================================================
// COPYRIGHT Dassault Systemes 2020/07/02
//===================================================================
// CATOmbLoadingOrderRule.cpp
// Header definition of class CATOmbLoadingOrderRule
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2020/07/02 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATOmbLoadingOrderRule_H
#define CATOmbLoadingOrderRule_H

#include "CATOmbSwitchEngine.h"
#include "CATOmxSharable.h"
#include "CATUnicodeString.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxCollecManager.h"
#include "IUnknown.h"
#include "CATSysBoolean.h"

//-----------------------------------------------------------------------

class ExportedByCATOmbSwitchEngine CATOmbLoadingOrderRule
{
public:
  // Standard constructors and destructors
  // -------------------------------------
  CATOmbLoadingOrderRule();
  CATOmbLoadingOrderRule(CATOmbLoadingOrderRule &);
  CATOmbLoadingOrderRule& operator=(CATOmbLoadingOrderRule&);

  inline CATOmbLoadingOrderRule(const CATUnicodeString& iTargetLoadingMode, const CATUnicodeString& iTargetLoadingOrder
    , const CATUnicodeString& iTargetLateType)
    : _TargetLoadingMode(iTargetLoadingMode)
    , _TargetLoadingOrder(iTargetLoadingOrder)
    , _TargetLateType(iTargetLateType) {}

  virtual ~CATOmbLoadingOrderRule();

  inline CATUnicodeString GetTargetLoadingMode() const { return _TargetLoadingMode; }
  inline CATUnicodeString GetTargetLoadingOrder() const { return _TargetLoadingOrder; }
  inline CATUnicodeString GetTargetLateType() const { return _TargetLateType; }
  inline void SetTargetLoadingOrder(const CATUnicodeString& TargetLoadingOrder) { _TargetLoadingOrder = TargetLoadingOrder; }

  CATBoolean IsEqual(const CATOmbLoadingOrderRule& other);
private:

  CATUnicodeString _TargetLoadingMode;
  CATUnicodeString _TargetLoadingOrder;
  CATUnicodeString _TargetLateType;

};

template<> CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmbLoadingOrderRule>::manager();

//-----------------------------------------------------------------------

#endif