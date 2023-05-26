/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2008
#ifndef CATIPLMAttributeSet_H
#define CATIPLMAttributeSet_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

class CATString;
class CATIPLMValueWriter;
class CATIPLMValueReader;
class CATICkeParm_var;
class CATPLMTypeH;
class CATOmxKeyValueBlock;
template <typename T>
class CATOmxIter;
template <typename U, typename V>
struct CATOmxPair;

class CATUnicodeString;
class CATPLMTypeH;
class CATOmxKeyValueBlock;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMAttributeSet;
#else
extern "C" const IID IID_CATIPLMAttributeSet;
#endif

/**
 * This interface defines a protocol enabling to access to the result of a versioning operation performed
 * through the @href CATIPLMNewVersionEngine#RunVersioningOperation.
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMAttributeSet : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  typedef CATOmxPair<CATPLMTypeH, CATOmxKeyValueBlock> CATPLMTypeHKVBlockIterElem;
  typedef CATOmxIter<CATPLMTypeHKVBlockIterElem> CATPLMTypeHKVBlockIter;

  /**
   * Adds a new attribute to the attribute set.
   *
   * <br><b>Role</b>: Adds a new attribute (identifier/value) to the attribute set.
   *
   * @param iAttributeId [in]
   *   The attribute identifier.
   * @param iAttributeValue [in]
   *   The attribute value. You can use #GetPLMValueWriter to create an attribute value.
   *   <ul><li>A null pointer will result in a E_INVALIDARG return.</li></ul>
   *
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if the attribute was added in the set.</li>
   *   <li><code>S_FALSE</code> if the attribute was already available in the set. Add query is ignored for this attribute name.</li>
   *   <li><code>E_FAIL</code> if an internal error occured.</li>
   *   <li><code>E_INVALIDARG</code> if an invalid attribute identifier (such as null string) was provided.</li>
   *   </ul>
   */
  virtual HRESULT AddAttribute(const CATString & iAttributeId, CATIPLMValueWriter * iValueWriter) = 0;

  /**
  * Adds a new attribute to the attribute set by a CATICkeParm (Knowledge).
  * As for a CATIPLMValueWriter, this must not contain multivaluated attribute.
  * Date can be unset. Other attributes can not be unset.
  *
  * <br><b>Role</b>: Add the CATICkeParm, as it represents a key/value. @see CATICkeParm
  *
  * @param ispCkeParm [in]
  *   The CATICkeParm to add, as a smart pointer.
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if the ckeparm was added in the set.</li>
  *   <li><code>E_FAIL</code> if an internal error occured.</li>
  *   <li><code>E_INVALIDARG</code> if an invalid attribute identifier was provided.</li>
  *   </ul>
  */
  virtual HRESULT AddCkeParm(const CATICkeParm_var &ispCkeParm) = 0;


  /**
   * Retrieves an attribute from the attribute set.
   *
   * <br><b>Role</b>: Enables to get the attributes being part of the attribute set.
   *
   * @param ioPosition [inout]
   *   On input, it's the index of the attribute (specify 0 for the first attribute). On output, it will contain the index
   * of the next attribute.
   * @param oAttributeId [out]
   *   The attribute identifier.
   * @param oValue [out,CATBaseUnknown#Release]
   *   The attribute value as a @href CATIPLMValueReader.
   *
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if everything ran ok.</li>
   *   <li><code>S_FALSE</code> if no more attribute is available. All the attributes of the set were parsed.</li>
   *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
   *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
   *   </ul>
   */
  virtual HRESULT NextAttribute(int & ioPosition, CATString & oAttributeId, CATIPLMValueReader *& oValue) = 0;

  /**
   * Provides a @href CATIPLMValueWriter pointer on an attribute value.
   * <br><b>Role</b>: Use this method if you need a CATIPLMValueWriter pointer on an attribute value.
   * @param oValueWriter [out,CATBaseUnknown#Release] The out pointer.
   * @return
   * <ul>
   *   <li><code>S_OK</code> if the method succeeded and provided you a good pointer on an attribute value.</li>
   *   <li><code>E_FAIL</code> if an internal error occured.</li>
   * </ul>
   */
  virtual HRESULT GetPLMValueWriter(CATIPLMValueWriter *& oValueWriter) = 0;

  /**
 * Adds a new attribute Key Value block for a specific extension.
 *
 * <br><b>Role</b>: Adds a new block containing every attribute / value pair for a specific extension
 *
 * @param iExtensionType [in]
 *   The extension typename.
 * @param iValue [in]
 *   The block containing attribute associated to value.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the attribute was added in the set.</li>
 *   <li><code>S_FALSE</code> if the attribute was already available in the set. Add query is ignored for this attribute name.</li>
 *   <li><code>E_FAIL</code> if an internal error occured.</li>
 *   <li><code>E_INVALIDARG</code> if an invalid attribute identifier (such as null string) was provided.</li>
 *   </ul>
 */
  virtual HRESULT AddExtension(const CATPLMTypeH &iExtensionType, const CATOmxKeyValueBlock &iValue) = 0;

  /**
 * Retrieves an attribute block for each extension type
 *
 * <br><b>Role</b>: Enables to get the attribute key/values associated to an extension
 *
 * @param oIter [out]
 *  This iterator is a @see CATOmxIter
 *  Access each element using next. You'll get a pair, key is extention type, value is the key value block associated
 *  @see CATPLMTypeH
 *  @see CATOmxKeyValueBlock
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no extension available.</li>
 *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *   </ul>
 */

  virtual HRESULT GetExtensionsIterator(CATPLMTypeHKVBlockIter &oIter) = 0;

  /**
  * Adds a new attribute of type "string" to the attribute set.
  *
  * <br><b>Role</b>: Accelerator enabling to easily add a new attribute (identifier/value) of type "string" to the attribute set. Attribute MUST be defined as a "string" attribute in the metadata.
  *
  * @param iAttributeId [in]
  *   The attribute identifier.
  * @param iAttributeValue [in]
  *   The attribute value.
  *   <ul><li>Attribute MUST be defined as a "string" attribute in the metadata.</li></ul>
  *   <ul><li>If the attribute is not defined as a "string" attribute in the metadata, an error should be raised later on during the execution and operation might fail.</li></ul>
  *
  * @return
  *   <ul>
  *   <li><code>S_OK</code> if the attribute was added in the set.</li>
  *   <li><code>S_FALSE</code> if the attribute was already available in the set. Add query is ignored for this attribute name.</li>
  *   <li><code>E_FAIL</code> if an internal error occured.</li>
  *   <li><code>E_INVALIDARG</code> if an invalid attribute identifier (such as null string) was provided.</li>
  *   </ul>
  */
  virtual HRESULT AddStringAttribute(const CATString & iAttributeId, const CATUnicodeString & iValue) = 0;



  ///**
  //* Get a copy of this attribute set in a map to key value blocks.
  //* CATPLMTypeH_NULL is the base type, other types are extension types.
  //* <br><b>Role</b>:  This method allows to convert an existing attribute set to a key value block format.
  //* @param 0;
  //*
  //* @return The map which corresponds base type and each extension types to a keyvalueblock.
  //*
  //*/
  virtual CATPLMTypeHKVBlockIter AsKeyValueBlocksIterator() const = 0;


};
CATDeclareHandler(CATIPLMAttributeSet, CATBaseUnknown);
#endif
