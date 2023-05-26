// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMAttrWriteAdapter.h
// Define the CATPLMAttrWriteAdapter adapter
//
//===================================================================
//
// Usage notes:
//   adapter
//
//===================================================================
//
//  Feb 2009  Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U2
*/

#ifndef CATPLMAttrWriteAdapter_H
#define CATPLMAttrWriteAdapter_H

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATIPLMAttrWrite.h"// CATPLMServices ProtectedInterfaces CATPLMImplAdapterClass.m CATPLMImplAdapterClass.dll

class CATPLMAttribute;
class CATPLMType;
class CATPLMTypeH;

/**
 * gives an adapter to the interface CATIPLMAttrWrite
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMAttrWriteAdapter : public CATIPLMAttrWrite
{
public:
  CATPLMAttrWriteAdapter();
  virtual ~CATPLMAttrWriteAdapter();

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMMask iMask, int iAttrIndex, CATUnicodeString* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATString* iAttributeId, CATUnicodeString* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(const CATString& iAttributeId, const CATUnicodeString& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute, CATUnicodeString* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute, const CATUnicodeString& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMMask iMask, int iAttrIndex, int iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATString* iAttributeId, int iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(const CATString& iAttributeId, int iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute, int iValue);
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute, int iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMMask iMask, int iAttrIndex, double iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATString* iAttributeId, double iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(const CATString& iAttributeId, double iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute, double iValue);
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute, double iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMMask iMask, int iAttrIndex, CATTime* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATString* iAttributeId, CATTime* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(const CATString& iAttributeId, const CATTime& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute, CATTime* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute, const CATTime& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMMask iMask, int iAttrIndex, CATMathTransformation* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATString* iAttributeId, CATMathTransformation* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute, CATMathTransformation* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMMask iMask, int iAttrIndex, CATVariant* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATString* iAttributeId, CATVariant* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(const CATString& iAttributeId, const CATVariant& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute, CATVariant* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute, const CATVariant& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMMask iMask, int  iAttrIndex, CATBinary * iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATString* iAttributeId, CATBinary* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(const CATString& iAttributeId, const CATBinary& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute, CATBinary* iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute, const CATBinary& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMMask iMask, int  iAttrIndex, CATBoolean iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATString* iAttributeId, CATBoolean iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetVal(const CATString& iAttributeId, CATBoolean iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute, CATBoolean iValue);
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute, CATBoolean iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValueBool(CATPLMMask iMask, int  iAttrIndex, bool iValue);

  /**
  * @nodoc
  */
  //virtual HRESULT SetValue(CATString* iAttributeId, bool iValue);
  virtual HRESULT SetValueBool(CATString* iAttributeId, bool iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValBool(const CATString& iAttributeId, bool iValue);

  /**
  * @nodoc
  */
  //virtual HRESULT SetValue(CATPLMAttribute* iAttribute, bool iValue);
  virtual HRESULT SetValBool(CATPLMAttribute* iAttribute, bool iValue);

  /**
  * @nodoc
  */
  virtual HRESULT ListAttributes(CATPLMMask  iMask, CATListPtrCATPLMAttribute** oppAttributeList);

  /**
  * @nodoc
  */
  virtual HRESULT ListAttributes(CATPLMMask  iMask, CATPLMAttributeList& oAttributeList);

  /**
  * @nodoc
  */
  virtual HRESULT ListAttributes(CATPLMMask  iMask, CATListValCATString** oppAttributeIdList);

  /**
  * @nodoc
  */
  virtual HRESULT ListAttributes(CATPLMMask  iMask, CATListValCATString& oAttributeIdList);

  /**
  * @nodoc
  */
  virtual HRESULT GetAttribute(CATPLMMask iMask, const CATOmxKeyString& iAttributeId, CATPLMAttribute*& opAttribute);

  /**
  * @nodoc
  */
  virtual HRESULT AttributeCount(CATPLMMask iMask, int *oAttrCount);

  /**
  * @nodoc
  */
  virtual HRESULT AttributeCount(CATPLMMask iMask, int& oAttrCount);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(const CATString& iAttrName, const CATOmxAny& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(CATPLMAttribute* ipAttr, const CATOmxAny& iValue);

  /**
  * @nodoc
  */
  virtual HRESULT SetValue(const CATOmxKeyValueBlock & iAttrBlock);

  /**
  * @nodoc
  */
  virtual HRESULT Unset(CATPLMAttribute* ipAttr);

  /**
  * @nodoc
  */
  virtual HRESULT Unset(const CATString& iAttrName);

  virtual CATPLMTypeH GetType() const;

private:
    CATPLMAttrWriteAdapter (CATPLMAttrWriteAdapter &);
    CATPLMAttrWriteAdapter& operator=(CATPLMAttrWriteAdapter&);
    // Need to release attribute.
    CATPLMAttribute* _GetAttribute( CATPLMType* ipType, const CATString& iAttrName);
};
#endif
