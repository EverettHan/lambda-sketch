// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMAttrReadAdapter.h
// Provide implementation to interface CATIPLMAttrRead
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// Feb 2009  Creation: EPB
//===================================================================
#ifndef CATPLMAttrReadAdapter_H
#define CATPLMAttrReadAdapter_H

/**
* @level Private
* @usage U1
*/

#include "CATPLMImplAdapterClass.h"// ExportedByCATPLMImplAdapterClass

#include "CATPLMOmxCollections.h"

#include "CATIPLMAttrRead.h"

#include "CATListOfCATString.h"

class CATOmxAny;
class CATString;
class CATPLMAttribute;
class CATUnicodeString;
class CATString;

/**
 * gives an adapter to the interface CATIPLMAttrRead
 * each methods returns E_NOTIMPL
*/
class ExportedByCATPLMImplAdapterClass CATPLMAttrReadAdapter : public CATIPLMAttrRead
{
public:

  CATPLMAttrReadAdapter();
  virtual ~CATPLMAttrReadAdapter();

  // @nodoc    
  virtual HRESULT GetStringValue(CATPLMMask iMask, int iAttrIndex, CATUnicodeString ** oValue) { return E_NOTIMPL; }
  virtual HRESULT GetStringValue(CATString* iAttributeId, CATUnicodeString ** oValue) { return E_NOTIMPL; }
  virtual HRESULT GetStringVal(const CATString& iAttributeId, CATUnicodeString*& opValue);
  virtual HRESULT GetStringVal(const CATString& iAttributeId, CATUnicodeString& oValue);
  virtual HRESULT GetStringValue(CATPLMAttribute* ipAttribute, CATUnicodeString ** oValue) { return E_NOTIMPL; }
  virtual HRESULT GetStringVal(CATPLMAttribute* ipAttribute, CATUnicodeString*& opValue);
  virtual HRESULT GetStringVal(CATPLMAttribute* ipAttribute, CATUnicodeString& oValue);

  virtual HRESULT GetDoubleValue(CATPLMMask iMask, int iAttrIndex, double * oValue) { return E_NOTIMPL; }
  virtual HRESULT GetDoubleValue(CATString* iAttributeId, double * oValue) { return E_NOTIMPL; }
  virtual HRESULT GetDoubleVal(const CATString& iAttributeId, double& oValue);
  virtual HRESULT GetDoubleValue(CATPLMAttribute* iAttribute, double * oValue) { return E_NOTIMPL; }
  virtual HRESULT GetDoubleVal(CATPLMAttribute* ipAttribute, double& oValue);

  virtual HRESULT GetIntValue(CATPLMMask iMask, int iAttrIndex, int* oValue) { return E_NOTIMPL; }
  virtual HRESULT GetIntValue(CATString* iAttributeId, int* oValue) { return E_NOTIMPL; }
  virtual HRESULT GetIntVal(const CATString& iAttributeId, int& oValue);
  virtual HRESULT GetIntValue(CATPLMAttribute* iAttribute, int* oValue) { return E_NOTIMPL; }
  virtual HRESULT GetIntVal(CATPLMAttribute* ipAttribute, int& oValue);

  virtual HRESULT GetTimeValue(CATPLMMask iMask, int  iAttrIndex, CATTime** oValue) { return E_NOTIMPL; }
  virtual HRESULT GetTimeValue(CATString* iAttributeId, CATTime** oValue) { return E_NOTIMPL; }
  virtual HRESULT GetTimeVal(const CATString& iAttributeId, CATTime*& opValue);
  virtual HRESULT GetTimeVal(const CATString& iAttributeId, CATTime& oValue);
  virtual HRESULT GetTimeValue(CATPLMAttribute* iAttribute, CATTime** oValue) { return E_NOTIMPL; }
  virtual HRESULT GetTimeVal(CATPLMAttribute* ipAttribute, CATTime*& opValue);
  virtual HRESULT GetTimeVal(CATPLMAttribute* ipAttribute, CATTime& oValue);

  virtual HRESULT GetMathTransformationValue(CATPLMMask  iMask, int iAttrIndex, CATMathTransformation ** oValue) { return E_NOTIMPL; }
  virtual HRESULT GetMathTransformationValue(CATString  * iAttributeId, CATMathTransformation ** oValue) { return E_NOTIMPL; }
  virtual HRESULT GetMathTransformationValue(CATPLMAttribute * iAttribute, CATMathTransformation     ** oValue) { return E_NOTIMPL; }

  virtual HRESULT GetAnyValue(CATPLMMask iMask, int iAttrIndex, CATOmxAny& oValue) { return E_NOTIMPL; }
  virtual HRESULT GetAnyValue(CATString* iAttributeId, CATOmxAny& oValue) { return E_NOTIMPL; }
  virtual HRESULT GetAnyValue(const CATString& iAttributeId, CATOmxAny& oValue) { return E_NOTIMPL; }
  virtual HRESULT GetAnyValue(CATPLMAttribute* iAttribute, CATOmxAny& oValue) { return E_NOTIMPL; }

  virtual HRESULT GetBinaryValue(CATPLMMask iMask, int iAttrIndex, CATBinary**  oValue) { return E_NOTIMPL; }
  virtual HRESULT GetBinaryValue(CATString*  iAttributeId, CATBinary**  oValue) { return E_NOTIMPL; }
  virtual HRESULT GetBinaryVal(const CATString& iAttributeId, CATBinary*& opValue);
  virtual HRESULT GetBinaryVal(const CATString& iAttributeId, CATBinary& oValue);
  virtual HRESULT GetBinaryValue(CATPLMAttribute* iAttribute, CATBinary**  oValue) { return E_NOTIMPL; }
  virtual HRESULT GetBinaryVal(CATPLMAttribute* ipAttribute, CATBinary*& opValue);
  virtual HRESULT GetBinaryVal(CATPLMAttribute* ipAttribute, CATBinary& oValue);

  virtual HRESULT GetBooleanValue(CATPLMMask iMask, int iAttrIndex, CATBoolean*  oValue) { return E_NOTIMPL; }
  virtual HRESULT GetBooleanValue(CATString* iAttributeId, CATBoolean* oValue) { return E_NOTIMPL; }
  virtual HRESULT GetBooleanVal(const CATString& iAttributeId, CATBoolean& oValue);
  virtual HRESULT GetBooleanValue(CATPLMAttribute* iAttribute, CATBoolean* oValue) { return E_NOTIMPL; }
  virtual HRESULT GetBooleanVal(CATPLMAttribute* ipAttribute, CATBoolean& oValue);

  virtual HRESULT ListAttributes(CATPLMMask iMask, CATListPtrCATPLMAttribute** oAttribute) { return E_NOTIMPL; }
  virtual HRESULT ListAttributes(CATPLMMask iMask, CATListValCATString** oAttributeIdList) { return E_NOTIMPL; }
  virtual HRESULT ListAttributes(CATPLMMask iMask, CATPLMAttributeList& oAttribute) { return E_NOTIMPL; }
  virtual HRESULT ListAttributes(CATPLMMask iMask, CATListValCATString& oAttributeIdList) { return E_NOTIMPL; }
  virtual HRESULT AttributeCount(CATPLMMask iMask, int *oAttrCount) { return E_NOTIMPL; }
  virtual CATPLMType* GetType() { return NULL; }

  virtual HRESULT GetOrderOfAttributes(OrderOfAttributesMode& oOrder) { oOrder = Default; return S_OK; }

  /** @ Deprecated */
  virtual HRESULT GetVariantValue(CATPLMMask iMask, int iAttrIndex, CATVariant**  oValue) { return E_NOTIMPL; }
  /** @ Deprecated */
  virtual HRESULT GetVariantValue(CATString* iAttributeId, CATVariant** oValue) { return E_NOTIMPL; }
  /** @ Deprecated */
  virtual HRESULT GetVariantVal(const CATString& iAttributeId, CATVariant& oValue);
  /** @ Deprecated */
  virtual HRESULT GetVariantValue(CATPLMAttribute* iAttribute, CATVariant** oValue) { return E_NOTIMPL; }
  /** @ Deprecated */
  virtual HRESULT GetVariantVal(CATPLMAttribute* iAttribute, CATVariant& oValue);

  void SetDefMode(unsigned int idm) { _dm = idm; }

protected:
  /**
   * @nodoc
   * Internal
   */
#define ExtAttrsReq      0x08
  unsigned int _dm;
  void ExtAttrs_AskedButNotRequired();

private:
  CATPLMAttrReadAdapter(const CATPLMAttrReadAdapter &);
  CATPLMAttrReadAdapter& operator=(const CATPLMAttrReadAdapter&);
};

#endif
