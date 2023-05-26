/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2021
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMAttributeValues_H
#define CATPLMAttributeValues_H

#include "CATPLMIdentificationAccess.h"
#include "CATOmxPair.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxIter.h"

class CATPLMTypeH;
class CATOmxKeyString;
class CATPLMAttributeValue;

/**
 * Collection of PLM attributes.
 */
class ExportedByCATPLMIdentificationAccess CATPLMAttributeValues
{
public:
  /**standard constructors*/
  CATPLMAttributeValues() = default;
  CATPLMAttributeValues(const CATPLMAttributeValues&) = default;
  CATPLMAttributeValues& operator=(const CATPLMAttributeValues&) = default;
  CATPLMAttributeValues(CATPLMAttributeValues&&) = default;
  CATPLMAttributeValues& operator=(CATPLMAttributeValues&&) = default;

  typedef CATOmxPair<CATOmxKeyString, CATPLMAttributeValue> KeyValuePair;

  /**
   * construct from an initializer list, example:
   * CATPLMAttributeValues values{ {"monday", 1 }, {"tuesday", 2 } };
   */
  CATPLMAttributeValues(const std::initializer_list<KeyValuePair>& list);
  CATPLMAttributeValues& operator=(const std::initializer_list<KeyValuePair>& list) { return *this = CATPLMAttributeValues{ list }; }

  /**
   * Retrieve the value of an attribute.
   *
   * @param iKey [in]
   *   The attribute identifier
   * @parma oValue [out]
   *   The attribute value.
   *
   * @return
   * <ul>
   *   <li><code>S_OK</code> if the attribute value is available in the collection</li>
   * </ul>
   */
  HRESULT GetValue(const CATOmxKeyString & iKey, CATPLMAttributeValue & oValue) const;
  CATPLMAttributeValue operator[](const CATOmxKeyString & iKey) const;

  /**
   * Add an attribute in the collection. Value is overwritten is the attribute is already available.
   *
   * @param iKey [in]
   *   The attribute identifier
   * @parma iValue [in]
   *   The attribute value.
   */
  void SetValue(const CATOmxKeyString & iKey, const CATPLMAttributeValue & iValue);

  /**
   * Gets an iterator on the attributes defined in the set.
   *
   * @return An iterator on the collection of attributes
   */
  CATOmxIter<const KeyValuePair> GetIterator() const;

  /**
   * Range for integration (do not use directly begin/end).
   *
   * <code>
   * CATPLMAttributeValues myAttributeValues;
   * // ... Your code here
   * for (CATPLMAttributeValues::const KeyValuePair & keyvalue: myAttributeValues)
   * {
   *   CATOmxKeyString attrkey=keyvalue.key;
   *   CATPLMAttributeValue attrvalue=keyvalue.value;
   *   // ... your code here
   * }
   * </code>
   */
  CATOmxSTLIter<const KeyValuePair> begin() const { return { GetIterator() }; }
  CATOmxSTLIter<const KeyValuePair> end() const { return {}; }

  /**
   * Builder from a @href CATOmxKeyValueBlock. Compatibility check will be made before valuation to determine if the format is compliant with the one of @href CATPLMAttributeValues.
   *
   * @param iAttributes [in]
   *   The attributes to add
   *
   * @return
   * <ul>
   *   <li><code>S_OK</code> if the given attributes have successfully be added to the set.</li>
   *   <li><code>E_INVALIDARG</code> if the given attributes are not compatible with @href CATPLMAttributeValue.</li>
   * </ul>
   */
  HRESULT BuildFromKeyValueBlock(const CATPLMTypeH& iType, const CATOmxKeyValueBlock & iAttributes);

  unsigned int Size() const { return m_block.Size(); }
  /**
   * @nodoc
   */
  CATOmxKeyValueBlock GetBlock() const { return m_block; }

  /** reserve */
  inline void Reserve(unsigned int reserve) { m_block.Reserve(reserve); }
private:
  CATOmxKeyValueBlock m_block;
};

template<> ExportedByCATPLMIdentificationAccess CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMAttributeValues>::manager();

#endif
