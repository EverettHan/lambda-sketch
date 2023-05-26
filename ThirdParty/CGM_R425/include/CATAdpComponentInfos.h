/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpComponentInfos_H
#define CATAdpComponentInfos_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATTypeHAdpStdAttributeSetMap.h"
#include "CATOmxOHMap.h"
#include "CATPLMAttributeValues.h"
class CATPLMTypeH;
class CATAdpStdAttributeSet;
class CATOmxKeyValueBlock;

/*
 * Collection of attributes associated to a component. Mainly used as @href CATAdpComponentQuery output.
 * If you retrieved such a collection through a query (such as @href CATAdpComponentQuery::GetElementsByUniqueKey), you can handle it this way:
 *
 * <code>
 * CATAdpComponentInfos myInfos;
 * // ... Your query here. You may have to iterate over a CATAdpComponentsInfos collection
 * CATOmxIter<const KeyValuePair> iter = myInfos.Iterator();
 * while ( const KeyValuePair * pkeyvalue=iter.Next() )
 * {
 *    const CATPLMTypeH & type=pkeyvalue->key;
 *    CATPLMAttributeValues & attributeSet = pkeyvalue->value;
 *    // ... Your code here
 * }
 * </code>
 */
class  ExportedByCATPLMIntegrationAccess CATAdpComponentInfos
{
public:
  CATAdpComponentInfos();
  ~CATAdpComponentInfos();
  CATAdpComponentInfos(const CATAdpComponentInfos &);
  CATAdpComponentInfos & operator=(const CATAdpComponentInfos &);
  
 /*
  * @deprecated V6R422
  * Do not use CATAdpStdAttributeSet
  * @use CATAdpComponentInfos#GetAttributeSet
  */
  HRESULT GetAttributeSet(const CATPLMTypeH & iType, CATAdpStdAttributeSet & oAttrSet) const;

  /*
  * @deprecated V6R422
  * Do not use CATAdpStdAttributeSet
  * @use CATAdpComponentInfos#AddAttributeSet
  */
  HRESULT AddAttributeSet(const CATPLMTypeH & iType, const CATAdpStdAttributeSet & iAttrSet);
  
 /*
  * Number of sets of attributes available.
  */
  unsigned int Size() const;
  
 /*
  * @deprecated V6R422
  * Do not use CATAdpStdAttributeSet
  * @use CATAdpComponentInfos#Iterator
  */
  CATTypeHAdpStdAttributeSetMapIter GetIterator() const;

 /*
  * Associates some attributes values to a base type or an extension type.
  *
  * @param iType [in]
  *   PLM type associated to the set of attributes. It can the base type of a component or an extension type. See @href CATPLMTypeH.
  * @parma iAttributes [in]
  *   The attributes associated with the given type. See @href CATPLMAttributeValues.
  */
  void AddAttributes(const CATPLMTypeH & iType, const CATPLMAttributeValues & iAttributes);

  /*
  * Associates some attributes values to a base type or an extension type.
  *
  * @param iType [in]
  *   PLM type associated to the set of attributes. It can the base type of a component or an extension type. See @href CATPLMTypeH.
  * @parma iAttributes [in]
  *   The attributes associated with the given type. See @href CATOmxKeyValueBlock.
  * 
  * @return
  * <ul>
  *   <li><code>S_OK</code> if attributes were added to the set.</li>
  *   <li><code>E_INVALIDARG</code> if the given block is not compatible with @href CATAdpComponentInfos.</li>
  * </ul>
  */
  HRESULT AddAttributes(const CATPLMTypeH & iType, const CATOmxKeyValueBlock & iAttributes);

 /*
  * Retrieve the attributes associated to the base type or an extension type.
  *
  * @param iType [in]
  *   PLMType of the attributes to retrieve. It can the base type of a component or an extension type. See @href CATPLMTypeH.
  * @parma oAttributes [out]
  *   The attributes associated with the given type. See @href CATPLMAttributeValues.
  *
  * @return
  * <ul>
  *   <li><code>S_OK</code> if attributes are available for this plm type.</li>
  *   <li><code>E_FAIL</code> if no attribute is available for this plm type.</li>
  * </ul>
  */
  HRESULT GetAttributes(const CATPLMTypeH & iType, CATPLMAttributeValues & oAttributes) const;

 /*
  * Get an iterator on all the attributes available. 
  * Role: enables the user to retrieve the attributes associated to the base type and the attributes associated to the extension types.
  *
  * @return
  * An iterator on the sets of attributes.
  */
  typedef CATOmxPair<CATPLMTypeH, CATPLMAttributeValues> KeyValuePair;
  CATOmxIter<const KeyValuePair> Iterator() const;


private:
  CATOmxOHMap<CATPLMTypeH, CATPLMAttributeValues> _impl;
};

template <> CATOmxCollecManager & CATOmxDefaultCollecManager <CATAdpComponentInfos>::manager () ;

#endif
