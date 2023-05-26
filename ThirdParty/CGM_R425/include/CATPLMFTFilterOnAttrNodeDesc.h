//===================================================================
// COPYRIGHT Dassault Systemes 2017/05/15
//===================================================================
// Header definition of class CATPLMFTFilterOnAttrNodeDesc
//===================================================================
// Usage notes:
// Current Class is used to describe a filter on attribute on a flat table.
// Current class stores a tree of condition (And, Or, None).
// Leaf of this tree are lists of CATPLMFTFilterOnAttrDesc
//
// Work on the stack and not on the heap, don't use pointers of CATPLMFTFilterOnAttrNodeDesc
//===================================================================
//Each time that you add a new instance of CATPLMFTFilterOnAttrNodeDesc under another one, you add new parenthesis in MQL expression.
//Note 1: You cannot add at the same time under an instance of CATPLMFTFilterOnAttrNodeDesc a list of CATPLMFTFilterOnAttrNodeDesc and a list of CATPLMFTFilterOnAttrDesc.
//Note 2 : If you have only one CATPLMFTFilterOnAttrDesc under CATPLMFTFilterOnAttrNodeDesc or if you have CATPLMFTFilterOnAttrNodeDesc under CATPLMFTFilterOnAttrNodeDesc, we don t add useless parenthesis.
//Note 3 : If you add under a CATPLMFTFilterOnAttrNodeDesc only one CATPLMFTFilterOnAttrNodeDesc / CATPLMFTFilterOnAttrDesc, use : ConditionalOperator::eNone
//===================================================================
//  2017/05/15 Creation: EPB
//===================================================================

#ifndef CATPLMFTFilterOnAttrNodeDesc_H
#define CATPLMFTFilterOnAttrNodeDesc_H

#include "CATPLMServicesItf.h"

#include "CATPLMQueryFilterEnum.h"
#include "CATPLMOmxCollections.h"

#include "CATBoolean.h"

#include "CATOmxSR.h"

class CATPLMFTFilterOnAttrDesc;
class CATPLMFTFilterOnAttrNodeDescInt;
class CATOmxKeyString;
class CATOmxAny;
class CATPLMAttrDesc;

class ExportedByCATPLMServicesItf CATPLMFTFilterOnAttrNodeDesc
{
  friend class CATPLMFlatTableRowToWriteInt;
  friend class xMQLFlatTableRowToWrite;
public:
  CATPLMFTFilterOnAttrNodeDesc();

  CATPLMFTFilterOnAttrNodeDesc(ConditionalOperator::eProp iOp);

  ~CATPLMFTFilterOnAttrNodeDesc();

  // Internal structure is shared
  // Suppose you write
  // CATPLMFTFilterOnAttrNodeDesc a(c);
  // Modification made on a are shared by b!
  // b cannot be modified!
  // Suppose you want to have 2 different objects with internal structure not shared, please use Clone method
  CATPLMFTFilterOnAttrNodeDesc(const CATPLMFTFilterOnAttrNodeDesc &);

  // Internal structure is shared
  // Suppose you write
  // CATPLMFTFilterOnAttrNodeDesc a(c);
  // Modification made on a are shared by b!
  // b cannot be modified!
  // Suppose you want to have 2 different objects with internal structure not shared, please use Clone method
  CATPLMFTFilterOnAttrNodeDesc& operator=(const CATPLMFTFilterOnAttrNodeDesc&);

  // Internal structure is duplicated, nothing is shared.
  // Suppose you write:
  // CATPLMFTFilterOnAttrNodeDesc a;
  // ...
  // CATPLMFTFilterOnAttrNodeDesc b;
  // b.Clone(a)
  // Each object has its own lifecycle, a and b can be modified!
  HRESULT Clone(const CATPLMFTFilterOnAttrNodeDesc&);

  /**
  * Comparison of identifier, total order.
  *
  * @return
  *       1 same value
  *       0 different value
  */
  int operator==(const CATPLMFTFilterOnAttrNodeDesc &) const;

  int operator!=(const CATPLMFTFilterOnAttrNodeDesc &) const;

  /*
  * Method used after call to Clone method or after creation of instance of current class
  * Suppose you have:
  * CATPLMFTFilterOnAttrNodeDesc a;
  * ...
  * CATPLMFTFilterOnAttrNodeDesc b=a;
  * b.Add(...) is forbidden
  * Here is what you have to do:
  * CATPLMFTFilterOnAttrNodeDesc a;
  * ...
  * CATPLMFTFilterOnAttrNodeDesc b;
  * b.Clone(a)
  * b.Add(...) is authorized
  */
  HRESULT Add(const CATPLMFTFilterOnAttrDesc& iFOAD);

  /*
  * Method used after call to Clone method or after creation of instance of current class
  * Suppose you have:
  * CATPLMFTFilterOnAttrNodeDesc a;
  * ...
  * CATPLMFTFilterOnAttrNodeDesc b=a;
  * b.Add(...) is forbidden
  * Here is what you have to do:
  * CATPLMFTFilterOnAttrNodeDesc a;
  * ...
  * CATPLMFTFilterOnAttrNodeDesc b;
  * b.Clone(a)
  * b.Add(...) is authorized
  */
  HRESULT Add(const CATPLMFTFilterOnAttrNodeDesc& iFOAND);

  /*
  * TRUE: Instance of current class only contain CATPLMFTFilterOnAttrDesc or nothing
  * FALSE: Instance of current class only contain CATPLMFTFilterOnAttrNodeDesc
  */
  CATBoolean IsLeaf() const;

  HRESULT SetConditionalOperatorValue(ConditionalOperator::eProp iOp);

  ConditionalOperator::eProp GetConditionalOperatorValue() const;

  const CATPLMArrayOfFilterOnAttrDesc& GetListOfTerminalNode() const;

  const CATPLMArrayOfFilterOnAttrNodeDesc& GetListOfIntermediateNode() const;

private:
  CATOmxAny _Search(const CATPLMAttrDesc& iAttrDesc) const;

  HRESULT _Add(const CATPLMFTFilterOnAttrDesc& iFOAD);

  HRESULT _Add(const CATPLMFTFilterOnAttrNodeDesc& iFOAND);

  CATBoolean _IsRuleVerified() const;

  CATOmxSR<CATPLMFTFilterOnAttrNodeDescInt> _sp;
};

extern const ExportedByCATPLMServicesItf CATPLMFTFilterOnAttrNodeDesc CATPLMFTFilterOnAttrNodeDesc_Null;

#endif
