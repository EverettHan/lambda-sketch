/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005
/**
* @level Protected
* @usage U1  
*/
#ifndef  CATAdpBasicQueryResult_h
#define  CATAdpBasicQueryResult_h

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATIAdpPLMIdentificator.h"
#include "CATCollec.h"
#include "CATOmxOMap.h"
#include "CATOmxKeyString.h"
#include "CATUnicodeString.h"
class CATLISTV(CATString);
class CATLISTV(CATUnicodeString);
class CATString;

/**
 * Generic class to manage query results .
 *
 * <b>Role</b>:
 * This class will contain the results of a query in VPDM : CATIAdpPLMIdentificator of the object 
 * result of the query and list of attribute values of this object. 
 */
class ExportedByCATPLMIntegrationAccess CATAdpBasicQueryResult : public CATBaseUnknown
{
public:

/** @nodoc
 * Constructs a query result object.
 */
  CATAdpBasicQueryResult(CATIAdpPLMIdentificator * iAdpIdentifier,
    const CATLISTV(CATString) & iAttIds,
    const CATLISTV(CATUnicodeString) & iAttValues);

  CATAdpBasicQueryResult(CATIAdpPLMIdentificator * iAdpIdentifier,
    const CATOmxOMap<CATOmxKeyString, CATUnicodeString>& iAttributes);

/** @nodoc
 * Destructor.
 * <br><b>Role</b>: Destructor.
 */
  virtual ~CATAdpBasicQueryResult() ;

/** 
 * Gets the @href CATIAdpPLMIdentificator.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpPLMIdentificator.
 *
 * @param oIdentifier [out, CATBaseUnknown#Release]
 *   The retrieved plm type.
 *
 * @return
 *   <code>S_OK</code> if the related identifier could be retrieved.
 *   <code>E_FAIL</code> otherwise.
 *
 */
  HRESULT GetIdentifier( CATIAdpPLMIdentificator *& oIdentifier );

/**
 * Gets the list of attribute ids.
 * <br><b>Role</b>: Gets the list of attributes available on this object.
 * @param oAttNames
 * Gets the list of attribute values. 
 */
  HRESULT GetAttributeIds( CATLISTV(CATString) & oAttIds );

/**
 * Gets the value of the required attribute.
 * <br><b>Role</b>: Gets the value of the required attribute.
 * @param oAttValues
 * The value. 
 */
  HRESULT GetAttributeValue( const CATString & iAttributeId, CATUnicodeString & oValue );

private:
  CATIAdpPLMIdentificator * _Identifier;
  CATOmxOMap<CATOmxKeyString, CATUnicodeString> _Attributes;

};
#endif
