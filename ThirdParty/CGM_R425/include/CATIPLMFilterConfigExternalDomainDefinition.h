#ifndef CATIPLMFilterConfigExternalDomainDefinition_H
#define CATIPLMFilterConfigExternalDomainDefinition_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMFilterCfgLimitedAccess.h"


#include "CATBaseUnknown.h"

class CATListPtrCATIPLMFilterCfgCriteria;
class CATIPLMFilterCfgExprElement;
class CATPLMID;
class CATBinary;
class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMFilterCfgLimitedAccess IID IID_CATIPLMFilterConfigExternalDomainDefinition;
#else
extern "C" const IID IID_CATIPLMFilterConfigExternalDomainDefinition;
#endif

/**
 * Interface of definition data of the Config Filter
 */
class ExportedByCATPLMFilterCfgLimitedAccess CATIPLMFilterConfigExternalDomainDefinition : public CATBaseUnknown
{
    CATDeclareInterface;    

	public:

	enum CfgFilterDomain
	{
    /**
    * Substitute domain
    */
	CFG_FILTER_DOMAIN_SUBSTITUTE
    /**
    * Engineering domain
    */
   ,CFG_FILTER_DOMAIN_ENGINEERING_DEACTIVATION
	};


    /**
	* Get XML expression of the Config Filter
    * @param oXMLExpression
    *    expression in XML format with names.
    * @return
    * <dt> <code>S_OK</code>     <dd> Successfully done.    
    * <dt> <code>E_FAIL</code>   <dd> Failed.
  	*/
    virtual HRESULT GetXMLExpression ( CATUnicodeString& oXMLExpression) const = 0;

	/**
	* Get compiled binary form of the Config Filter
	* @param oEncodingVersion
    *    Encoding version of the binary data.
    * @param oCompiledQuery
    *    Binary data.
  	*/
    virtual HRESULT GetCompiledBinaryForm ( CATBinary & oCompiledQuery ) const = 0;

	/**
	* Get the domain of the filter
	*/
	virtual HRESULT GetDomain (CfgFilterDomain& oDomain) const = 0;

	/**
	* Get the dictionary of the filter
	*/
	virtual HRESULT GetDictionary (CATUnicodeString& oDictionary) const = 0;
};

#endif
