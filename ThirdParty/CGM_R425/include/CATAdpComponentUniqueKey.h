/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpComponentUniqueKey_H
#define CATAdpComponentUniqueKey_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATTypeHCATOmxKeyValueBlockMap.h"
class CATUnicodeString;
class CATAdpPrivateComponentUniqueKey;
class CATBinary;
class CATAdpComponentInfos;

/**
 * Class defining the Unique Key of a Component.
 *
 * <br><b>Role</b>: Provides a Unique Key enabling to identify a Component in the Database.
 */
class ExportedByCATPLMIntegrationAccess CATAdpComponentUniqueKey
{
public:
  CATAdpComponentUniqueKey();
  virtual ~CATAdpComponentUniqueKey();
  CATAdpComponentUniqueKey( const CATAdpComponentUniqueKey & iKey );
  CATAdpComponentUniqueKey & operator=(const CATAdpComponentUniqueKey & iKey );

/** 
 * Get the Unique Key as a Binary stream.
 * <br><b>Role</b>: This method enables to serialize the Unique Key to a @href CATBinary.
 * <ul>
 * <li>The structure of the @href CATBinary is internally defined.</li>
 * <li>No interpretation of the content of the @href CATBinary should be made. It can change at any time.</li>
 * </ul>
 *
 * @param oSerialized [out]
 * The serialized Unique Key.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Unique Key was successfully serialized. 
 *   <li><code>E_FAIL</code> if an error occured.
 *   </ul>
 */
  HRESULT AsBinary( CATBinary & oSerialized ) const;

/** 
 * Get the Unique Key as a String stream.
 * <br><b>Role</b>: This method enables to serialize the Unique Key to a @href CATUnicodeString.
 * <ul>
 * <li>The structure of the @href CATUnicodeString is internally defined.</li>
 * <li>No interpretation of the content of the @href CATUnicodeString should be made. It can change at any time.</li>
 * </ul>
 *
 * @param oSerialized [out]
 * The serialized Unique Key.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Unique Key was successfully serialized. 
 *   <li><code>E_FAIL</code> if an error occured.
 *   </ul>
 */
  HRESULT AsString( CATUnicodeString & oSerialized ) const;

/** 
 * Get a displayable value of the complete Unique Key.
 * <br><b>Role</b>: This method enables to obtain a displayable @href CATUnicodeString for the Unique Key.
 * <ul>
 * <li>It is strongly recomended not to extract infos from this value since the dump format can be modified at any moment.</li>
 * </ul>
 *
 * @param oDisplayed [out]
 * The displayable Unique Key.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Unique Key was successfully computed for display. 
 *   <li><code>E_FAIL</code> if an error occured.
 *   </ul>
 */
  HRESULT Display( CATUnicodeString & oDisplayed ) const;

/** 
 * Get an exteded access to the Unique Key content.
 * <br><b>Role</b>: This method enables to obtain a @href CATAdpComponentInfos access to the content of the Unique Key.
 *
 * @param oComponentInfos [out]
 * The Unique Key content.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Unique Key was successfully introspected. 
 *   <li><code>E_FAIL</code> if an error occured.
 *   </ul>
 */
  HRESULT MoreInformation( CATAdpComponentInfos & oComponentInfos ) const;

/** 
 * Build a Unique Key from a Binary stream.
 * <br><b>Role</b>: This method enables to create a Unique Key given a @href CATBinary stream.
 *
 * @param iSerialized [in]
 * The Binary stream which should be used to build the Unique Key.
 * <ul>
 * <li><code>E_INVALIDARG</code> is returned if an empty binary is provided.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Unique Key was successfully built 
 *   <li><code>E_FAIL</code> if an error occured.
 *   </ul>
 */
  HRESULT BuildFromBinary( const CATBinary & iSerialized );

/** 
 * Determines if the Unique Key guarantees the Unicity of the associated Component or not.
 * <br><b>Role</b>: This method enables to know if the built Unique Key guarantees the unicity of the result when looking for a component in the database.
 *
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Unique Key guarantees the Unicity of the solution 
 *   <li><code>S_FALSE</code> if the Unique Key does not completely guarantee the Unicity of the solution 
 *   <li><code>E_FAIL</code> if an error occured.
 *   </ul>
 */
  HRESULT UnicityGuarantee() const;
	/** 
 * Get the Unique Key identification.
 * <br><b>Role</b>: This method gives the Unique Key Id on which the Unique Key is built.
 *
 *
 * @param oUKId [out]
 * The Unique Key Id.
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Unique Key Id is returned.
 *   <li><code>E_FAIL</code> if an error occured.
 *   </ul>
 */
  HRESULT GetUniqueKeyId(CATUnicodeString & oUKId) const;

/** 
 * Build a Unique Key from a String stream.
 * <br><b>Role</b>: This method enables to create a Unique Key given a @href CATUnicodeString stream.
 *
 * @param iSerialized [in]
 * The String stream which should be used to build the Unique Key.
 * <ul>
 * <li><code>E_INVALIDARG</code> is returned if an invalid string is provided.</li>
 * </ul>
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Unique Key was successfully built 
 *   <li><code>E_FAIL</code> if an error occured.
 *   </ul>
 */
  HRESULT BuildFromString( const CATUnicodeString & iSerialized );

private:
  CATAdpPrivateComponentUniqueKey * _letter;

private:
  friend class CATAdpUniqueKeyManager;
  CATAdpComponentUniqueKey( const CATTypeHCATOmxKeyValueBlockMap & iInputMap,  CATUnicodeString & iUKId, CATBoolean iUnicityGuaranteed=TRUE );
};
#endif
