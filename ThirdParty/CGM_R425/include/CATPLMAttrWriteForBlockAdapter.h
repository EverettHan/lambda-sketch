#ifndef CATPLMAttrWriteForBlockAdapter_h
#define CATPLMAttrWriteForBlockAdapter_h

/**
* @level Protected
* @usage U2
*/

#include "CATPLMImplAdapterClass.h"
#include "CATIPLMAttrWrite.h"
#include "CATPLMAttrWriteAdapter.h"
#include "CATPLMAttribute.h"
#include "CATOmxSR.h"

class CATPLMType;
class CATOmxKeyValueBlock;
class CATOmxAny;

/**
 * FIXMEs:
 * to be moved to CATPLMPXn
 * insane: contains an unsafe reference to a CATOmxKeyValueBlock "somewhere in memory", hope for the best
 */
class ExportedByCATPLMImplAdapterClass CATPLMAttrWriteForBlockAdapter : public CATPLMAttrWriteAdapter
{
  CATDeclareClass;
private:
  CATOmxSR<CATPLMType> _type;
  CATOmxKeyValueBlock & _block;

public:
  CATPLMAttrWriteForBlockAdapter(CATOmxKeyValueBlock & iAttrBlock, CATPLMType * iType);
  ~CATPLMAttrWriteForBlockAdapter();

  HRESULT SetValue(CATPLMMask  iMask, int  iAttrIndex, CATUnicodeString *);
  HRESULT SetValue(CATPLMAttribute * iAttribute, CATUnicodeString *);
  HRESULT SetValue(CATString * iAttributeId, CATUnicodeString *);

  HRESULT SetValue(CATPLMMask  iMask, int  iAttrIndex, int);
  HRESULT SetValue(CATPLMAttribute * iAttribute, int);
  HRESULT SetValue(CATString * iAttributeId, int);

  HRESULT SetValue(CATPLMMask  iMask, int  iAttrIndex, double);
  HRESULT SetValue(CATPLMAttribute * iAttribute, double);
  HRESULT SetValue(CATString * iAttributeId, double);

  HRESULT SetValue(CATPLMMask  iMask, int  iAttrIndex, CATBoolean);
  HRESULT SetValue(CATPLMAttribute * iAttribute, CATBoolean);
  HRESULT SetValue(CATString * iAttributeId, CATBoolean);

  HRESULT SetValue(CATPLMMask  iMask, int  iAttrIndex, CATTime *);
  HRESULT SetValue(CATPLMAttribute * iAttribute, CATTime *);
  HRESULT SetValue(CATString * iAttributeId, CATTime *);

  HRESULT SetValue(CATPLMMask  iMask, int  iAttrIndex, CATMathTransformation *);
  HRESULT SetValue(CATPLMAttribute * iAttribute, CATMathTransformation *);
  HRESULT SetValue(CATString * iAttributeId, CATMathTransformation *);

  HRESULT SetValue(CATPLMMask  iMask, int  iAttrIndex, CATVariant *);
  HRESULT SetValue(CATPLMAttribute * iAttribute, CATVariant *);
  HRESULT SetValue(CATString * iAttributeId, CATVariant *);

  HRESULT SetValue(CATPLMMask  iMask, int  iAttrIndex, CATBinary *);
  HRESULT SetValue(CATPLMAttribute * iAttribute, CATBinary *);
  HRESULT SetValue(CATString * iAttributeId, CATBinary *);

  HRESULT SetValue(const CATString& iAttrName, const CATOmxAny& iValue);
  HRESULT SetValue(CATPLMAttribute* ipAttr, const CATOmxAny& iValue);
  HRESULT SetValue(const CATOmxKeyValueBlock & iAttrBlock);

  HRESULT ListAttributes(CATPLMMask  iMask, CATListPtrCATPLMAttribute ** oAttrs);
  HRESULT ListAttributes(CATPLMMask  iMask, CATListValCATString ** oAttrs);
  HRESULT AttributeCount(CATPLMMask  iMask, int * oAttrCount);

private:
  HRESULT SetValue(const CATUnicodeString * iValue, CATString & iAttributeId, CATOmxAny & oAnyValue, unsigned int & oOmxMask);
  HRESULT SetValue(const int iValue, CATString & iAttributeId, CATOmxAny & oAnyValue, unsigned int & oOmxMask);
  HRESULT SetValue(const double iValue, CATString & iAttributeId, CATOmxAny & oAnyValue, unsigned int & oOmxMask);
  HRESULT SetValue(const CATBoolean iValue, CATString & iAttributeId, CATOmxAny & oAnyValue, unsigned int & oOmxMask);
  HRESULT SetValue(const CATTime * iValue, CATString & iAttributeId, CATOmxAny & oAnyValue, unsigned int & oOmxMask);
  HRESULT SetValue(const CATMathTransformation * iValue, CATString & iAttributeId, CATOmxAny & oAnyValue, unsigned int & oOmxMask);
  HRESULT SetValue(const CATVariant * iValue, CATString & iAttributeId, CATOmxAny & oAnyValue, unsigned int & oOmxMask);
  HRESULT SetValue(const CATBinary * iValue, CATString & iAttributeId, CATOmxAny & oAnyValue, unsigned int & oOmxMask);

  HRESULT CheckAttributeType(CATPLMAttribute & iAttribute, const AttrTypes & iAttrType);

  /**
   * Is this attribute an enum ?
   * returns : S_OK : enum, S_FALSE : pas enum, E_* : error
   */
  HRESULT IsEnum(CATString & iAttributeId);
  HRESULT GetEnumInfos(CATString & iAttributeId, CATListOfInt & oEnumIndexes, CATListOfCATString & oEnumKeys);
  HRESULT SetEnumValue(CATString & iAttributeId, const CATUnicodeString & iValue, CATOmxAny & oAnyValue);
  HRESULT SetEnumValue(CATString & iAttributeId, const int iValue, CATOmxAny & oAnyValue);

  /**
   * Retrieve the additionals information for mulitvalluated attributes ?
   * returns : S_OK : enum, S_FALSE : pas enum, E_* : error
   */
  HRESULT GetMultivaluatedInfo(CATString & iAttributeId, AttrTypes & oAttrType, CATBoolean & oIsEnum);
  HRESULT SetEnumVariantValue(CATString & iAttributeId, CATBoolean isMulti, const CATVariant & iValue, CATOmxAny & oAnyValue, unsigned int& oOmxMask);
  HRESULT SetVariantValue(const AttrTypes iAttrType, CATBoolean isMulti, const CATVariant & iValue, CATOmxAny & oAnyValue, unsigned int& oOmxMask);

  class SingleValueVisitor
  {
  public:
    virtual HRESULT VisitSingleValue(const CATVariant & iValue, CATOmxAny & oAnyValue, unsigned int& oOmxMask) = 0;
    virtual void SpecifyEmptyType(CATOmxAny & oAnyValue, unsigned int& oOmxMask) = 0;
    virtual void SpecifyType(CATOmxAny& oAnyValue) = 0;
  };
  HRESULT VisitSingleValues(const CATVariant & iValue, SingleValueVisitor & iVisitor, CATOmxAny & oAnyValue, unsigned int& oOmxMask);
};
#endif
