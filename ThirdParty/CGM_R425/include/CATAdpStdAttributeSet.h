#ifndef CATAdpStdAttributeSet_h
#define CATAdpStdAttributeSet_h

/**
 * @level Protected
 * @usage U1
 */

#include "CATString.h"
#include "CATPLMIntegrationAccess.h"

class CATIAdpValueWriter;
class CATIAdpValueReader;
class CATAdpPrivateAttributeSet;
class CATOmxKeyValueBlock;

/**
 * Class defining a set of attributes.
 *
 * <br><b>Role</b>: provide a set of attributes made of an attribute name and a value.
 */
class ExportedByCATPLMIntegrationAccess CATAdpStdAttributeSet
{

 public :
  CATAdpStdAttributeSet();
  /**
   * copy ctor
   */
  CATAdpStdAttributeSet(const CATAdpStdAttributeSet &);

  /**
   * operator =
   */
  CATAdpStdAttributeSet& operator=(const CATAdpStdAttributeSet&);



  virtual ~CATAdpStdAttributeSet();

  /** 
   * Retrieves an attribute from the attribute set.
   *
   * <br><b>Role</b>: Enables to get an attribute being part of the attribute set.
   *
   * @param iAttributeId [in]
   *   The requested attribute name.
   * @param oValue [out,CATBaseUnknown#Release]
   *   The attribute value as a @href CATIAdpValueWriter.
   *
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if everything ran ok.</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
   *   </ul>
   */
  HRESULT GetAttribute( CATString & iAttributeId, CATIAdpValueReader *& oValue ) const;
  HRESULT GetStringAttribute( CATString & iAttributeId, CATUnicodeString & oValue ) const;

  /** 
   * Adds a new attribute to the attribute set.
   *
   * <br><b>Role</b>: Adds a new attribute (identifier/value) to the attribute set.
   *
   * @param iAttributeId [in]
   *   The attribute name.
   * @param iAttributeValue [in]
   *   The attribute value. You can use #GetAdpValueWriter to create an attribute value.
   *
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if the attribute was added in the set.</li>
   *   <li><code>S_FALSE</code> if the attribute was already available in the set. Add query is ignored for this attribute name.</li>
   *   <li><code>E_FAIL</code> if an internal error occured.</li>
   *   <li><code>E_INVALIDARG</code> if an invalid attribute identifier (such as null string) was provided.</li>
   *   </ul>
   */

  HRESULT AddAttribute(const CATString & iAttributeId, CATIAdpValueWriter * iValue);
  HRESULT AddStringAttribute(const CATString & iAttributeId, const CATUnicodeString & iValue);


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
   * @param oValue [out,CATBaseUnknown#Release]
   *   The attribute value as a @href CATIAdpValueReader.
   *
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if everything ran ok.</li>
   *   <li><code>S_FALSE</code> if no more attribute is available. All the attributes of the set were parsed.</li>
   *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
   *   </ul>
   */
  HRESULT NextAttribute(int & ioPosition, CATString & oAttributeId, CATIAdpValueReader *& oValue) const ;


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

  /** 
   * Adds the content of an attribute block to the Attribute Set.
   *
   * <br><b>Role</b>: Adds the content of an attribute block to the Attribute Set.
   *
   * @param iBlock [in]
   *   The block which will be transferred in the the Attribute Set.
   *
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if the attributes were added in the set.</li>
   *   <li><code>E_FAIL</code> if an internal error occured.</li>
   *   <li><code>E_INVALIDARG</code> if an invalid attribute identifier (such as null string) was provided.</li>
   *   </ul>
   */
  HRESULT BuildFromBlock( const CATOmxKeyValueBlock & iBlock );


 private:
  CATAdpPrivateAttributeSet * _letter;

};

#endif
