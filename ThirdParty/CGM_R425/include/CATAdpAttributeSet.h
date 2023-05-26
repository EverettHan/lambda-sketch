/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATAdpAttributeSet_H
#define CATAdpAttributeSet_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1  
 */

#include <memory>
#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
class CATPLMAttributeValues;
class CATString;
class CATUnicodeString;

/**
 * Class defining a set of attributes.
 *
 * <br><b>Role</b>: provide a set of attributes made of an attribute name and a value.
 * 
 * <ul>
 * <li>Only attributes of type string are available</li>
 * <li>Multivaluated attributes are not available</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationAccess CATAdpAttributeSet
{
public:

/**
 * Constructs an attribute set.
 */
  CATAdpAttributeSet( void );
/**
 * Destructs an attribute set.
 */
  virtual ~CATAdpAttributeSet( void );

/**
 * Copy constructs an attribute set.
 */
  CATAdpAttributeSet( const CATAdpAttributeSet & );

/**
 * Affectation operator.
 * @return
 *   The copy of the attribute set.
 */
  CATAdpAttributeSet & operator =( const CATAdpAttributeSet & );

/** 
 * Adds a new attribute to the attribute set.
 *
 * <br><b>Role</b>: Adds a new attribute (identifier/value) to the attribute set.
 *
 * @param iAttributeId [in]
 *   The attribute name.
 * @param iAttributeValue [in]
 *   The attribute value.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the attribute was added in the set.</li>
 *   <li><code>S_FALSE</code> if the attribute was already available in the set. Add query is ignored for this attribute name.</li>
 *   <li><code>E_FAIL</code> if an internal error occured.</li>
 *   <li><code>E_INVALIDARG</code> if an invalid attribute identifier (such as null string) was provided.</li>
 *   </ul>
 */
  HRESULT AddAttribute( const CATString & iAttributeId, const CATUnicodeString & iAttributeValue ) const;

/** 
 * Retrieves an attribute from the attribute set.
 *
 * <br><b>Role</b>: Enables to get the attributes being part of the attribute set.
 * <ul>
 * <li>Only attributes of type string are available</li>
 * <li>Multivaluated attributes are not available</li>
 * <li>Unset attributes are not available</li>
 * </ul>
 *
 * @param ioPosition [inout]
 *   On input, it's the index of the attribute (specify 0 for the first attribute). On output, it will contain the index
 * of the next attribute.
 * @param oAttributeId [out]
 *   The attribute name.
 * @param oAttributeValue [out]
 *   The attribute value.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more attribute is available. All the attributes of the set were parsed.</li>
 *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *   </ul>
 *
 */
  HRESULT NextAttribute( int & ioPosition, CATString & oAttributeId, CATUnicodeString & oAttributeValue ) const;

private:

  struct Letter;
  std::unique_ptr<Letter> m_pimpl;

private:
  friend class CATAdpPrivateQueryResult;
  HRESULT BuildFromCATPLMAttributeValues(const CATPLMAttributeValues & iAttributeValues);

};
#endif
