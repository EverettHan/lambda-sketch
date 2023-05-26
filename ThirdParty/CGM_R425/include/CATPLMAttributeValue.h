/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2021
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMAttributeValue_H
#define CATPLMAttributeValue_H

 // ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxArray.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxKeyString.h"
#include "CATOmxKeyValueFlags.h"
#include "CATOmxKind.h"
// CATPLMIdentificationAccess
#include "AttrTypes.h"
#include "CATPLMIdentificationAccess.h"
#include "CATTime.h"

class CATBinary;
class CATUnicodeString;
class CATPLMTypeH;
class CATTime;

/**
 * representation of an enum value in CATPLMAttributeValue
 */
struct CATPLMAttributeEnumValue
{
  /** rank of the value, for example "MustBeRebuilt" value of V_isUptodate enum has a rank of 2*/
  int m_rank = 0;
  /** value, for example "UpdateToDate" or "MustBeRebuilt" for V_isUptodate attribute */
  CATOmxKeyString m_value;

  /** comparison */
  bool operator==(const CATPLMAttributeEnumValue& ivalue) const { return m_rank == ivalue.m_rank && m_value == ivalue.m_value; }
  bool operator!=(const CATPLMAttributeEnumValue& ivalue) const { return !(*this == ivalue); }
};

template<>
ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMAttributeEnumValue>::manager();

/**
 * CATPLMAttributeValue is a variant able to hold the different types of values a PLM attribute can hold:
 *   bool                     (PLMTYPE_BOOLEAN)
 *   int                      (PLMTYPE_INTEGER)
 *   double                   (PLMTYPE_DOUBLE)
 *   CATUnicodeString         (PLMTYPE_STRING)
 *   CATTime                  (PLMTYPE_DATE)
 *   CATBinary                (PLMTYPE_BINARY)
 *   CATPLMAttributeEnumValue (PLMTYPE_ENUM)
 * it can also be "multi-valuated" (hold a list)
 *   CATOmxArray<bool>
 *   CATOmxArray<int>
 *   CATOmxArray<double>
 *   CATOmxArray<CATUnicodeString>
 *   CATOmxArray<CATTime>
 *   CATOmxArrayCATBinary>
 *   CATOmxArrayCATPLMAttributeEnumValue>
 */
class ExportedByCATPLMIdentificationAccess CATPLMAttributeValue final
{
public:
  /** default constructors */
  CATPLMAttributeValue() :m_mask(OMX_KEYVALUE_NONE) {}
  CATPLMAttributeValue(const CATPLMAttributeValue&) = default;
  CATPLMAttributeValue(CATPLMAttributeValue&&) = default;
  CATPLMAttributeValue& operator=(const CATPLMAttributeValue&) = default;
  CATPLMAttributeValue& operator=(CATPLMAttributeValue&&) = default;
  ~CATPLMAttributeValue() = default;

  /**
    * prohibit ambiguous constructions through casts, for example CATPLMAttributeValue{"toto"} which resolves in CATPLMAttributeValue{true}
    */
  template<typename T> CATPLMAttributeValue(const T&) = delete;

  /**
   * constructors for single values (monovaluated)
   *   IsUnset() will return false
   *   IsMultiValuated() will return false
   */
  CATPLMAttributeValue(int iValue) : m_value(iValue), m_mask(OMX_KEYVALUE_ISVALUATED) { }
  CATPLMAttributeValue(double iValue) : m_value(iValue), m_mask(OMX_KEYVALUE_ISVALUATED) { }
  CATPLMAttributeValue(const CATUnicodeString & iValue) : m_value(iValue), m_mask(OMX_KEYVALUE_ISVALUATED) { }
  CATPLMAttributeValue(bool iValue) : m_mask(OMX_KEYVALUE_ISVALUATED) { m_value.SetBoolean(iValue); }
  CATPLMAttributeValue(const CATBinary& iValue);
  CATPLMAttributeValue(const CATPLMAttributeEnumValue& iValue) : m_mask(OMX_KEYVALUE_ISVALUATED) { m_value.SetEnum(iValue.m_value, iValue.m_rank); }
  CATPLMAttributeValue(const CATTime& iTime) : m_mask(OMX_KEYVALUE_ISVALUATED) { m_value.SetTime(iTime.Gettime_t()); }

  /**
   * constructors for lists (multivaluated)
   *   IsUnset() will return false
   *   IsMultiValuated() will return true
   */
  CATPLMAttributeValue(const CATOmxArray<int> & iValues);
  CATPLMAttributeValue(const CATOmxArray<double> & iValues);
  CATPLMAttributeValue(const CATOmxArray<CATUnicodeString> & iValues);
  CATPLMAttributeValue(const CATOmxArray<bool> & iValues);
  CATPLMAttributeValue(const CATOmxArray<CATBinary> & iValues);
  CATPLMAttributeValue(const CATOmxArray<CATPLMAttributeEnumValue> & iValues);
  CATPLMAttributeValue(const CATOmxArray<CATTime> & iValues);
  /**
   * constructor for an unset monovaluated value of given type
   * on the created instance:
   *   GetType() returns iAttrType
   *   IsUnset() returns true
   *   IsMultiValuated() return false
   *   all value getters will fail
   */
  explicit CATPLMAttributeValue(AttrTypes iAttrType);

  /**
   * Get the type of the value.
   * @return The type of the value
   *   @see AttrTypes {PLMTYPE_INTEGER, PLMTYPE_DOUBLE, PLMTYPE_STRING, PLMTYPE_DATE, PLMTYPE_BINARY, PLMTYPE_BOOLEAN, PLMTYPE_ENUM}).
   *   PLMTYPE_UNDEFINED is returned if this instance has been built using default constructor
   */
  AttrTypes GetType() const;

  /**
   * @return true if the value is unset.
   * for monovaluated  (not list) attributes 'unset' is the same as '!std::optional::has_value()'
   * for multivaluated (list) attributes 'unset' is not implemented (will return false by default)
   */
  bool IsUnset() const { return 0 == (m_mask & OMX_KEYVALUE_ISVALUATED); }

  /**
   * for monovaluated: same as IsUnset
   * for multivaluated: returns true if the list is empty
   */
  bool IsUnsetOrEmptyList() const;

  /**
   * @return true if the value is multivaluated.
   */
  bool IsMultiValuated() const { return 0 != (m_mask & OMX_KEYVALUE_ISMULTIVALUATED); }

  /**
   * Get the value of the attribute.
   * @return
   * <ul>
   *   <li><code>S_OK</code> if the value is available (the attribute is set).</li>
   *   <li><code>E_TOS_UNSET</code> if the value is unset for this attribute.</li>
   *   <li><code>E_TYPEMISMATCH</code> if the value cannot be retrieved with this method (invalid type or multivaluated).</li>
   * </ul>
   */
  HRESULT GetInteger(int & oValue) const;
  HRESULT GetDouble(double & oValue) const;
  HRESULT GetString(CATUnicodeString & oValue) const;
  HRESULT GetBoolean(bool & oValue) const;
  HRESULT GetBinary(CATBinary & oValue) const;
  HRESULT GetEnum(CATPLMAttributeEnumValue & oValue) const;
  HRESULT GetTime(CATTime & oValue) const;

  /**
   * Get the value of the attribute.
   * @return
   * <ul>
   *   <li><code>S_OK</code> if the value is available.</li>
   *   <li><code>E_TYPEMISMATCH</code> if the value cannot be retrieved with this method (invalid type or not multivaluated).</li>
   * </ul>
   */
  HRESULT GetIntegerValues(CATOmxArray<int> & oValues) const;
  HRESULT GetDoubleValues(CATOmxArray<double> & oValues) const;
  HRESULT GetStringValues(CATOmxArray<CATUnicodeString> & oValues) const;
  HRESULT GetBooleanValues(CATOmxArray<bool> & oValue) const;
  HRESULT GetBinaryValues(CATOmxArray<CATBinary> & oValues) const;
  HRESULT GetEnumValues(CATOmxArray<CATPLMAttributeEnumValue> & oValues) const;
  HRESULT GetTimeValues(CATOmxArray<CATTime> & oValues) const;

  bool operator==(const CATPLMAttributeValue& other) const { return m_value == other.m_value && m_mask == other.m_mask; }
  bool operator!=(const CATPLMAttributeValue& other) const { return !((*this) == other); }

  /**
   * retrieve CATOmxAny view of the value
   * unset'ness or multi-valuated'ness information is lost
   * monovaluated binaries are stored using omx_octet kind (the size of the CATOmxAny is the size of the blob)
   * multivaluated binaries are stored using omx_any kind
   */
  CATOmxAny ToAny() const { return m_value; }

  /**
   * Build a @href CATPLMAttributeValue from a @href CATOmxAny
   * PLMAdapter format is supported (using omx_void for unset or omx_any to say multivaluated)
   *
   * iPLMType and iAttributeName are optional and used only in some specific cases where PLMAdapter format loses type information
   *
   * this method does not check that attribute iAttributeName exists on type iPLMType nor that provided value matches the type of the attribute
   */
  HRESULT BuildFromOmxAny(const CATPLMTypeH& iPLMType, const CATOmxKeyString& iAttributeName, const CATOmxAny & iValue, unsigned int iMask);

  enum BLOBType { BLOB };
  CATPLMAttributeValue(BLOBType, const CATOmxArray<unsigned char> & iValues);
  HRESULT GetBinary(CATOmxArray<unsigned char> & oValue) const;
private:
  friend class CATPLMAttributeValues;
  HRESULT CheckMono() const;
  HRESULT CheckMulti(CATOmxKind kind) const;

  template<typename T> void InitFromArray(const CATOmxArray<T>& array);
  template<typename T> HRESULT ConvertToArray(CATOmxKind kind, CATOmxArray<T>& oValues) const;
  template<class BLOBT> HRESULT GetBLOB(BLOBT&) const;

  CATOmxAny m_value;
  unsigned int m_mask;
};

class CATOmxTextStream;
ExportedByCATPLMIdentificationAccess CATOmxTextStream& operator << (CATOmxTextStream& out, const CATPLMAttributeValue& value);

#endif
