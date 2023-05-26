#ifndef CATIPLMFilterConfigVolatileDefinition_H
#define CATIPLMFilterConfigVolatileDefinition_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMFilterCfgLimitedAccess.h"

#include "CATListOfInt.h"

#include "CATBaseUnknown.h"

class CATListPtrCATIPLMFilterCfgCriteria;
class CATIPLMFilterCfgExprElement;
class CATPLMID;
class CATUnicodeString;
class CATBinary;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMFilterCfgLimitedAccess IID IID_CATIPLMFilterConfigVolatileDefinition;
#else
extern "C" const IID IID_CATIPLMFilterConfigVolatileDefinition;
#endif

/**
 * Interface of definition data of the Config Filter
 */
class ExportedByCATPLMFilterCfgLimitedAccess CATIPLMFilterConfigVolatileDefinition : public CATBaseUnknown
{
    CATDeclareInterface;    

	public:

    /**
    * Specifies the view of Effectivity which the query will be applyed on.
    */
    enum ApplyingView
    {
        /**
        * Source effectivity view.
        */
        APPLYING_VIEW_SOURCE,

        /**
        * Current effectivity view
        */
        APPLYING_VIEW_CURRENT,

        /**
        * Projected effectivity view
        */
        APPLYING_VIEW_PROJECTED
    };

	/**
    * Specifies the domain of Effectivity which the query will be applyed on.
    */
	enum DiversityDomain
	{
		/**
		* Historisation effectivity domain 
		*/
		DIVERSITY_DOMAIN_HISTORISATION = 1,
		/**
		* ConfigChange effectivity domain
		*/
		DIVERSITY_DOMAIN_CONFIGCHANGE = 2,
		/**
		* EngineeringActivation effectivity domain
		*/
		DIVERSITY_DOMAIN_ENGINEERINGACTIVATION =3,
	};
    /**
	* Get query applying view. Mandatory filter data.    
    *
    * @param oValue
    *    Applying view value.
    * @return
    * <dt> <code>S_OK</code>     <dd> Successfully retrieved.
    * <dt> <code>E_FAIL</code>   <dd> Failed.
  	*/
    virtual HRESULT GetApplyingView ( ApplyingView& oValue ) const = 0;

	/**
	* Get query domain. Mandatory filter data.    
    *
    * @param oDomainValueList
    *    Domain List value.
    * @return
    * <dt> <code>S_OK</code>     <dd> Successfully retrieved.
    * <dt> <code>E_FAIL</code>   <dd> Failed.
  	*/
    virtual HRESULT GetDiversityDomain ( CATListOfInt& oDomainValueList ) const = 0;

    /**
	* Get Identifier of the Dictionary (Variability Space).
    * Mandatory for filters with config variables (in List or Expression mode).
    * @param oDictionnaryId
    *    Identifier of the config context.
    * @return
    * <dt> <code>S_OK</code>     <dd> The ID has been successfully retrieved    
    * <dt> <code>E_FAIL</code>   <dd> Failure. Possibly the filter has no ConfigContext ID defined. PLMID returned in this case is EMPTY.
  	*/
    virtual HRESULT GetDictionnaryPLMId ( DiversityDomain iDomainValue ,CATPLMID& oDictionnaryId ) const = 0;

	/**
	* Get Identifier of the Config Context (Variability Space).
    * Mandatory for filters with config variables (in List or Expression mode).
    * @param oContextId
    *    Identifier of the config context.
    * @return
    * <dt> <code>S_OK</code>     <dd> The ID has been successfully retrieved    
    * <dt> <code>E_FAIL</code>   <dd> Failure. Possibly the filter has no ConfigContext ID defined. PLMID returned in this case is EMPTY.
  	*/
    virtual HRESULT GetConfigContextPLMID       ( CATPLMID & oContextId ) const = 0;

    /**
	* Get XML expression of the Config Filter
    * @param oXMLExpression
    *    expression in XML format with names.
    * @return
    * <dt> <code>S_OK</code>     <dd> Successfully done.    
    * <dt> <code>E_FAIL</code>   <dd> Failed.
  	*/
    virtual HRESULT GetXMLExpression ( DiversityDomain iDomainValue, CATUnicodeString& oXMLExpression ) const = 0;

	/**
	* Get compiled binary form of the Config Filter
	* @param oEncodingVersion
    *    Encoding version of the binary data.
    * @param oCompiledQuery
    *    Binary data.
  	*/
    virtual HRESULT GetCompiledBinaryForm ( CATBinary& oCompiledQuery ) const = 0;

	/**
	* Get the domain name of the Config Filter
	* @param iDomainValue
    *    the domain we want the name
    * @param oName
    *    Name of the selected domain.
	*<dt> <code>S_OK</code>     <dd> Successfully done.
	*<dt> <code>S_FALSE</code>  <dd> the choosen domain doesn't contain a name.
	*<dt> <code>E_FAIL</code>   <dd> Failed.
  	*/
	virtual HRESULT GetFilterName( DiversityDomain iDomainValue, CATUnicodeString&  oName ) const = 0;

};

#endif
