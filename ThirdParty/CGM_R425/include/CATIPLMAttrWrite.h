// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATIPLMAttrWrite.h
// Define the CATIPLMAttrWrite interface
//
//===================================================================
//
// Usage notes:
// If you need to set/get strong relationship (from, to, fromrel , torel , V_Owner, V_InstanceOf), please use following methods:
// CATIPLMCompRecordWrite::SetAssociatedObj(...)/CATIPLMCompRecordWrite::GetAssociatedObj(...)
//
//===================================================================
//  Dec 2003  Creation: jvm
//===================================================================
/**
* @level Protected
* @usage U5
*/
#ifndef CATIPLMAttrWrite_H
#define CATIPLMAttrWrite_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATPLMMask.h"
#include "CATPLMOmxCollections.h"

#include "CATVariant.h"
#include "CATBoolean.h"
#include "CATPLMID.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMAttrWrite;
#else
extern "C" const IID IID_CATIPLMAttrWrite;
#endif

class CATPLMAttribute;
class CATListPtrCATPLMAttribute;
class CATUnicodeString;
class CATListValCATUnicodeString;
class CATString;
class CATListValCATString;
class CATTime;
class CATMathTransformation;
class CATBinary;
class CATOmxKeyValueBlock;
class CATOmxAny;
class CATPLMTypeH;

/**
 * Manage object attributes setting.
 */
class ExportedByCATPLMServicesItf CATIPLMAttrWrite : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
   * Set value of an attribute as a CATUnicodeString.
   * @param iMask
   *    Attribute mask.
   * @param iAttrIndex
   *    Attribute index in the mask iMask.
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMMask iMask,
    int iAttrIndex,
    CATUnicodeString * iValue) = 0;

  /**
   * Set value of an attribute as a CATUnicodeString.
   *
   * remark:
   * If you need to set/get strong relationship (from, to, fromrel , torel , V_Owner, V_InstanceOf), please use following methods:
   * CATIPLMCompRecordWrite::SetAssociatedObj(...)/CATIPLMCompRecordWrite::GetAssociatedObj(...)
   *
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATString* iAttributeId,
    CATUnicodeString* iValue) = 0;

  /**
   * Set value of an attribute as a CATUnicodeString.
   *
   * remark:
   * If you need to set/get strong relationship (from, to, fromrel , torel , V_Owner, V_InstanceOf), please use following methods:
   * CATIPLMCompRecordWrite::SetAssociatedObj(...)/CATIPLMCompRecordWrite::GetAssociatedObj(...)
   *
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetVal(const CATString& iAttributeId,
    const CATUnicodeString& iValue) = 0;

  /**
   * Set value of an attribute as a CATUnicodeString.
   *
   * remark:
   * If you need to set/get strong relationship (from, to, fromrel , torel , V_Owner, V_InstanceOf), please use following methods:
   * CATIPLMCompRecordWrite::SetAssociatedObj(...)/CATIPLMCompRecordWrite::GetAssociatedObj(...)
   *
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute,
    CATUnicodeString* iValue) = 0;

  /**
   * Set value of an attribute as a CATUnicodeString.
   *
   * remark:
   * If you need to set/get strong relationship (from, to, fromrel , torel , V_Owner, V_InstanceOf), please use following methods:
   * CATIPLMCompRecordWrite::SetAssociatedObj(...)/CATIPLMCompRecordWrite::GetAssociatedObj(...)
   *
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute,
    const CATUnicodeString& iValue) = 0;

  /**
   * Set value of an attribute as a INT.
   * @param iMask
   *    Attribute mask.
   * @param iAttrIndex
   *    Attribute index in the mask iMask.
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMMask iMask,
    int iAttrIndex,
    int iValue) = 0;

  /**
   * Set value of an attribute as a INT.
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATString* iAttributeId,
    int iValue) = 0;

  /**
   * Set value of an attribute as a INT.
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetVal(const CATString& iAttributeId,
    int iValue) = 0;

  /**
   * Set value of an attribute as a INT.
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute,
    int iValue) = 0;
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute,
    int iValue) = 0;

  /**
   * Set value of an attribute as a DOUBLE.
   * @param iMask
   *    Attribute mask.
   * @param iAttrIndex
   *    Attribute index in the mask iMask.
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMMask iMask,
    int iAttrIndex,
    double iValue) = 0;

  /**
   * Set value of an attribute as a DOUBLE.
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATString* iAttributeId,
    double iValue) = 0;

  /**
  * Set value of an attribute as a DOUBLE.
  * @param iAttributeId
  *    Attribute Identifier
  * @param iValue
  *    Attribute value.
  */
  virtual HRESULT SetVal(const CATString& iAttributeId,
    double iValue) = 0;

  /**
   * Set value of an attribute as a DOUBLE.
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute,
    double iValue) = 0;
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute,
    double iValue) = 0;

  /**
   * Set value of an attribute as a TIME value.
   * @param iMask
   *    Attribute mask.
   * @param iAttrIndex
   *    Attribute index in the mask iMask.
   * @param iValue
   *    Attribute value. Should be between 1970 and 2038.
   */
  virtual HRESULT SetValue(CATPLMMask iMask,
    int iAttrIndex,
    CATTime* iValue) = 0;

  /**
   * Set value of an attribute as a TIME value.
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value. Should be between 1970 and 2038.
   */
  virtual HRESULT SetValue(CATString* iAttributeId,
    CATTime* iValue) = 0;

  /**
   * Set value of an attribute as a TIME value.
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value. Should be between 1970 and 2038.
   */
  virtual HRESULT SetVal(const CATString& iAttributeId,
    const CATTime& iValue) = 0;

  /**
   * Set value of an attribute as a TIME value
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value. Should be between 1970 and 2038.
   */
  virtual HRESULT SetValue(CATPLMAttribute  * iAttribute,
    CATTime* iValue) = 0;

  /**
   * Set value of an attribute as a TIME value
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value. Should be between 1970 and 2038.
   */
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute,
    const CATTime& iValue) = 0;

  /**
   * Set value of an attribute as a MATRIX3x4 value.
   * @param iMask
   *    Attribute mask.
   * @param iAttrIndex
   *    Attribute index in the mask iMask.
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMMask iMask,
    int iAttrIndex,
    CATMathTransformation* iValue) = 0;

  /**
   * Set value of an attribute as a MATRIX3x4 value.
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATString* iAttributeId,
    CATMathTransformation* iValue) = 0;

  /**
   * Set value of an attribute as a MATRIX3x4 value.
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMAttribute  * iAttribute,
    CATMathTransformation* iValue) = 0;

  /**
   * Set value of an attribute as a CATBinary value.
   * @param iMask
   *    Attribute mask.
   * @param iAttrIndex
   *    Attribute index in the mask iMask.
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMMask iMask,
    int iAttrIndex,
    CATBinary * iValue) = 0;

  /**
   * Set value of an attribute as a CATBinary value.
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATString* iAttributeId,
    CATBinary* iValue) = 0;

  /**
   * Set value of an attribute as a CATBinary value.
   * @param iAttributeId
   *    Attribute Identifier
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetVal(const CATString& iAttributeId,
    const CATBinary& iValue) = 0;

  /**
   * Set value of an attribute as a CATBinary value.
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute,
    CATBinary* iValue) = 0;

  /**
   * Set value of an attribute as a CATBinary value.
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute,
    const CATBinary& iValue) = 0;

  /**
   * Set value of an attribute as a boolean value.
   * @param iMask
   *    Attribute mask.
   * @param iAttrIndex
   *    Attribute index in the mask iMask.
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMMask iMask,
    int iAttrIndex,
    CATBoolean iValue) = 0;

  /**
  * Set value of an attribute as a boolean value.
  * @param iAttributeId
  *    Attribute Identifier
  * @param iValue
  *    Attribute value.
  */
  virtual HRESULT SetValue(CATString* iAttributeId,
    CATBoolean iValue) = 0;

  /**
  * Set value of an attribute as a boolean value.
  * @param iAttributeId
  *    Attribute Identifier
  * @param iValue
  *    Attribute value.
  */
  virtual HRESULT SetVal(const CATString& iAttributeId,
    CATBoolean iValue) = 0;

  /**
   * Set value of an attribute as a boolean value.
   * @param iAttribute
   *    Attribute as CATPLMAttribute
   * @param iValue
   *    Attribute value.
   */
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute,
    CATBoolean iValue) = 0;
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute,
    CATBoolean iValue) = 0;

  /**
  * Set value of an attribute as a boolean value.
  * @param iMask
  *    Attribute mask.
  * @param iAttrIndex
  *    Attribute index in the mask iMask.
  * @param iValue
  *    Attribute value.
  */
  virtual HRESULT SetValueBool(CATPLMMask iMask,
    int iAttrIndex,
    bool iValue) = 0;

  /**
  * Set value of an attribute as a boolean value.
  * @param iAttributeId
  *    Attribute Identifier
  * @param iValue
  *    Attribute value.
  */
  virtual HRESULT SetValueBool(CATString* iAttributeId,
    bool iValue) = 0;

  /** @ Deprecated */
  /*Please use SetValBool*/
  //virtual HRESULT SetValue(CATString* iAttributeId, bool iValue) = 0;

  /**
  * Set value of an attribute as a boolean value.
  * @param iAttributeId
  *    Attribute Identifier
  * @param iValue
  *    Attribute value.
  */
  virtual HRESULT SetValBool(const CATString& iAttributeId, bool iValue) = 0;

  /** @ Deprecated */
  /*Please use SetValBool*/
  //virtual HRESULT SetValue(CATPLMAttribute* iAttribute, bool iValue) = 0;

  /**
  * Set value of an attribute as a boolean value.
  * @param iAttribute
  *    Attribute as CATPLMAttribute
  * @param iValue
  *    Attribute value.
  */
  virtual HRESULT SetValBool(CATPLMAttribute* iAttribute, bool iValue) = 0;

  /**
  * Get list of attribute for a mask.
  * @param iMask
  *    attribute mask. if NULL returns ALL attributes.
  * @param oAttribute
  *    List of attribute.
  */
  virtual HRESULT ListAttributes(CATPLMMask  iMask, CATListPtrCATPLMAttribute** oppAttributeList) = 0;

  /**
  * Get list of attribute for a mask.
  * @param iMask
  *    attribute mask. if NULL returns ALL attributes.
  * @param oAttribute
  *    List of attribute.
  */
  virtual HRESULT ListAttributes(CATPLMMask iMask, CATPLMAttributeList& oAttributeList) = 0;

  /**
  * Same job made by CATPLMType::ListAttributes
   * Get list of attribute for a mask.
   * @param iMask
   *    attribute mask. if NULL returns ALL attributes.
   * @param oAttributeIdList
   *    List of attributeId
   */
  virtual HRESULT ListAttributes(CATPLMMask iMask, CATListValCATString** oppAttributeIdList) = 0;

  /**
  * Same job made by CATPLMType::ListAttributes
   * Get list of attribute for a mask.
   * @param iMask
   *    attribute mask. if NULL returns ALL attributes.
   * @param oAttributeIdList
   *    List of attributeId
   */
  virtual HRESULT ListAttributes(CATPLMMask iMask, CATListValCATString& oAttributeIdList) = 0;

  /**
  * Same job made by CATPLMType::GetAttribute
  * Get attribute for a given mask.
   * @param iMask
   *    attribute mask. if NULL returns ALL attributes.
  * @param iAttributeId
  *    name of attribute.
  * @param opAttribute
  *    attribute found
  */
  virtual HRESULT GetAttribute(CATPLMMask iMask, const CATOmxKeyString& iAttributeId, CATPLMAttribute*& opAttribute) = 0;

  /**
   * @deprecated, Please use virtual HRESULT AttributeCount(CATPLMMask iMask, int& oAttrCount)
   */
  virtual HRESULT AttributeCount(CATPLMMask iMask, int *oAttrCount) = 0;

  /**
   *	Returns the number of attributes of the given mask.
   * @param iMask
   *    attribute mask. if NULL returns ALL attributes.
   * @param oAttrCount
   *    number of attributes.
   */
  virtual HRESULT AttributeCount(CATPLMMask iMask, int& oAttrCount) = 0;

  /**
  * Method implemented on all providers.
  * Please use CATPLMOmxHelpers to fill iValue
  */
  virtual HRESULT SetValue(const CATString& iAttrName, const CATOmxAny& iValue) = 0;

  /**
  * Method implemented on all providers.
  * Please use CATPLMOmxHelpers to fill iValue
  */
  virtual HRESULT SetValue(CATPLMAttribute* ipAttr, const CATOmxAny& iValue) = 0;

  /**
  * Method implemented on all providers.
  * Please use CATPLMOmxHelpers to fill iValue
  */
  virtual HRESULT SetValue(const CATOmxKeyValueBlock & iAttrBlock) = 0;

  /**
  * note: Only attributes of type DATE can be unset
  */
  virtual HRESULT Unset(CATPLMAttribute* ipAttr) = 0;

  /**
  * note: Only attributes of type DATE can be unset
  */
  virtual HRESULT Unset(const CATString& iAttrName) = 0;

  /**
  * Method must be implemented by providers.
  */
  virtual CATPLMTypeH GetType() const = 0;

  /** @ Deprecated */
  /*Please use CATOmxAny*/
  virtual HRESULT SetValue(CATPLMMask iMask,
    int iAttrIndex,
    CATVariant* iValue) = 0;

  /** @ Deprecated */
  /*Please use CATOmxAny*/
  virtual HRESULT SetValue(CATString* iAttributeId,
    CATVariant* iValue) = 0;

  /** @ Deprecated */
  /*Please use CATOmxAny*/
  virtual HRESULT SetVal(const CATString& iAttributeId,
    const CATVariant& iValue) = 0;

  /** @ Deprecated */
  /*Please use CATOmxAny*/
  virtual HRESULT SetValue(CATPLMAttribute* iAttribute,
    CATVariant* iValue) = 0;

  /** @ Deprecated */
  /*Please use CATOmxAny*/
  virtual HRESULT SetVal(CATPLMAttribute* iAttribute,
    const CATVariant& iValue) = 0;
};

#endif
