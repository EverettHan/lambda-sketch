/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
#ifndef CATAdpQueryAttributeSet_H
#define CATAdpQueryAttributeSet_H

/**
 * @level Protected
 * @usage U1
 */


#include "CATPLMIntegrationAccess.h"
//#include "CATErrorDef.h"
#include "CATAdpQueryAttributeOperator.h"
#include "CATString.h"

class CATIAdpValueWriter;
class CATIAdpValueReader;
class CATAdpPrivateAttributeSet;
class CATUnicodeString;
class CATOmxKeyValueBlock;

// ecn comment : généralisation CATAdpIdentifierSet avec operateur
/**
 * Class defining a set of attributes.
 *
 * <br><b>Role</b>: provide a set of attributes made of an attribute name and a value and operators for query.
 */
class ExportedByCATPLMIntegrationAccess CATAdpQueryAttributeSet
{
public:

/**
 * Constructs an attribute set.
 */
  CATAdpQueryAttributeSet();
/**
 * Destructs an attribute set.
 */
  virtual ~CATAdpQueryAttributeSet();

/**
 * Copy constructs an attribute set.
  * @return
  *   The copy of the attribute set.
 */
  CATAdpQueryAttributeSet( const CATAdpQueryAttributeSet & );

/**
 * Affectation operator.    (plutot private ?)
 */
  CATAdpQueryAttributeSet & operator =( const CATAdpQueryAttributeSet & );

/** 
 * Adds a new attribute to the attribute set.
 *
 * <br><b>Role</b>: Adds a new attribute (identifier/value) to the attribute set.
 *
 * @param iAttributeId [in]
 *   The attribute name.
 * @param iAttributeValue [in]
 *   The attribute value. You can use #GetAdpValueWriter to create an attribute value.
 * @param iOperatorValue[in]
 *   The operator . You can go to #CATAdpQueryAttributeOperator to detail avalaibles operators.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the attribute was added in the set.</li>
 *   <li><code>E_FAIL</code> if an internal error occured.</li>
 *   <li><code>E_INVALIDARG</code> if an invalid attribute identifier (such as null string) was provided.</li>
 *   </ul>
 */
  HRESULT AddAttribute( const CATString & iAttributeId, CATIAdpValueWriter * iAttributeValue, const CATAdpQueryAttributeOperator::QueryOperator &iOperator=CATAdpQueryAttributeOperator::COND_LIKE);
  HRESULT AddStringAttribute( const CATString & iAttributeId, const CATUnicodeString & iAttributeValue, const CATAdpQueryAttributeOperator::QueryOperator &iOperator=CATAdpQueryAttributeOperator::COND_LIKE);

/** 
 * Retrieves an attribute from the attribute set.
 *
 * <br><b>Role</b>: Enables to get the attributes being part of the attribute set.
 *
 * @param ioPosition [inout]
 *   On input, it's the index of the attribute (specify 0 for the first attribute). On output, it will contain the index
 * of the next attribute.
 * @param oAttributeId [out]
 *   The attribute name.
 * @param oAttributeValue [out]
 *   The attribute value.
 * @param oOperatorValue [out]
 *   The attribute value operator for query.
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
  HRESULT NextAttribute(int & ioPosition, CATString & oAttributeId, CATIAdpValueReader *& oAttributeValue, CATAdpQueryAttributeOperator::QueryOperator & oOperator) const;


   /**
   * Provides a @href CATIAdpValueWriter pointer on an attribute value.
   * <br><b>Role</b>: Use this method if you need a CATIAdpValueWriter pointer on an attribute value.
   * @param oValueWriter [out,CATBaseUnknown#Release] The out pointer.
   * @return
   * <ul>
   *   <li><code>S_OK</code> if the method succeeded and provided you a good pointer on an attribute value.</li>
   *   <li><code>E_FAIL</code> if an internal error occured.</li>
   * </ul>
   *
   */
  static HRESULT GetAdpValueWriter(CATIAdpValueWriter *& oValueWriter);

  HRESULT BuildFromBlock( const CATOmxKeyValueBlock & iAttributes, const CATAdpQueryAttributeOperator::QueryOperator &iOperator=CATAdpQueryAttributeOperator::COND_EQUAL);

   private:
  CATAdpPrivateAttributeSet * _letter;

};
#endif
