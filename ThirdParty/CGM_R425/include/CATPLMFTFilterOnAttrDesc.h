//===================================================================
// COPYRIGHT Dassault Systemes 2017/05/15
//===================================================================
// Header definition of class CATPLMFTFilterOnAttrDesc
//===================================================================
// Usage notes:
// Current Class is used to describe a filter on attribute on a flat table.
// Current class stores a tree of condition (And, Or, None).
// Leaf of this tree are lists of CATPLMFTFilterOnAttrDesc
//
// Work on the stack and not on the heap, don't use pointers of CATPLMFTFilterOnAttrNodeDesc
//===================================================================
// 2017/05/15 Creation: EPB
//===================================================================

#ifndef CATPLMFTFilterOnAttrDesc_H
#define CATPLMFTFilterOnAttrDesc_H

#include "CATPLMServicesItf.h"

#include "AttrTypes.h"

#include "CATPLMQueryFilterEnum.h"

#include "CATOmxSR.h"
#include "CATOmxArray.h"

class CATPLMFTFilterOnAttrDescInt;
class CATOmxKeyString;
class CATOmxAny;
class CATPLMAttrDesc;

class ExportedByCATPLMServicesItf CATPLMFTFilterOnAttrDesc
{
public:
  CATPLMFTFilterOnAttrDesc();

  CATPLMFTFilterOnAttrDesc(const CATOmxKeyString& iFlatTableName, const CATOmxKeyString& iAttrName,RelationalOperator::Op iOpValue,CaseSensitivity::eProp iCSValue);

  ~CATPLMFTFilterOnAttrDesc();

  // Lazy copy
  // Internal structure is shared
  // Suppose you write
  // CATPLMFTFilterOnAttrDesc a(c);
  // Modifications made on a are shared by b!
  CATPLMFTFilterOnAttrDesc (const CATPLMFTFilterOnAttrDesc & c);

  // Lazy copy
  // Internal structure is shared
  // Suppose you write
  // CATPLMFTFilterOnAttrDesc a(c);
  // Modifications made on a are shared by b!
  // b cannot be modified!
  CATPLMFTFilterOnAttrDesc& operator=(const CATPLMFTFilterOnAttrDesc& c);

  // Internal structure is duplicated, nothing is shared.
  // Suppose you write:
  // CATPLMFTFilterOnAttrDesc a;
  // ...
  // CATPLMFTFilterOnAttrDesc b;
  // b.Clone(a)
  // Each object has its own lifecycle, a and b can be modified!
  HRESULT Clone(const CATPLMFTFilterOnAttrDesc& c);

  /**
  * Comparison of identifier, total order.
  *
  * @return
  *       1 same value
  *       0 different value
  */
  int operator==(const CATPLMFTFilterOnAttrDesc &) const;

  int operator!=(const CATPLMFTFilterOnAttrDesc &) const;

  /*
  * Suppose you have:
  * CATPLMFTFilterOnAttrDesc a;
  * ...
  * CATPLMFTFilterOnAttrDesc b=a;
  * b and a share the same internal structure
  *
  * b.SetAnyValue(...) is authorized (copy on write)
  * a is not modified
  * b is not a clone of a and we have apply SetAnyValue on b only!
  */
  HRESULT SetAnyValue(const CATOmxAny& iAnyValue);

  const CATOmxKeyString& GetFlatTableName() const;
  const CATPLMAttrDesc& GetAttr() const;
  const CATOmxKeyString& GetAttrName() const;
  AttrTypes GetAttrType() const;
  CATBoolean IsMultivaluated() const;
  RelationalOperator::Op GetRelationOperatorValue() const;
  CaseSensitivity::eProp GetCaseSensitivityValue() const;
  const CATOmxAny& GetAnyValue() const;
private:
  HRESULT _Clone(CATPLMFTFilterOnAttrDescInt* ip);

  CATOmxSR<CATPLMFTFilterOnAttrDescInt> _sp;
};

extern const ExportedByCATPLMServicesItf CATPLMFTFilterOnAttrDesc CATPLMFTFilterOnAttrDesc_Null;

#endif
