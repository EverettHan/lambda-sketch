// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATIPLMCompMetaDataService.h
// Define the CATIPLMCompMetaDataService interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  Nov 2003  Creation: jvm
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompMetaDataService_H
#define CATIPLMCompMetaDataService_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATPLMRepositoryName.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompMetaDataService;
#else
extern "C" const IID IID_CATIPLMCompMetaDataService ;
#endif

class CATPLMDomain;
class CATString;
class CATListValCATString;
class CATListValCATUnicodeString;
class CATPLMEnvironment;
class CATLISTV(CATString);
class CATLISTV(CATUnicodeString);
class CATPLMType;
class CATPLMTypeId;
class CATListPtrCATPLMType;
class VPMIDicExtension;

/**
* @level Protected
* @usage U3
* Interface allowing access to the dictionary.<br>
*
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* <p>This interface provides access to the object, relation and function types managed by the provider inside a domain. The provider for which the domain has no significance will use a "default" domain.<br>
* It is recommended that the implementation of this interface keeps in a cache all the metadata definition because the objects managed in the Immersive Applications may point this metadata model.
* </p>
* @href CATPLMComponentServices#GetMetaDataService
*/
class ExportedByCATPLMServicesItf CATIPLMCompMetaDataService: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Load specific domain identified by its name
  * @param iDomainId
  * metadata name is expected (and not modeler name) eg: PRODUCTCFG
  */
  virtual HRESULT LoadDomain(CATString *iDomainId, CATPLMDomain **oDomain, const CATPLMRepositoryName &iType = NULL) =0;

  /**
  * Find a specific domain identified by its name
  * @param iDomainId
  * metadata name is expected (and not modeler name) eg: PRODUCTCFG
  */
  virtual HRESULT GetDomain(CATString *iDomainId, CATPLMDomain **oDomain, const CATPLMRepositoryName &iType = NULL) =0;

  /**
  * List available domains
  */
  virtual HRESULT ListDomains(CATListValCATString& oListDomainId, const CATPLMRepositoryName& iType = NULL) = 0;
  /** @deprecated*/
  virtual HRESULT ListDomains(CATListValCATString **oDomainId, CATListValCATUnicodeString **oDomainAlias, const CATPLMRepositoryName &iType = NULL) =0;

  /**
  * Gets the available environments.
  *
  * <br><b>Role</b>: Provide to the user the different environments available.
  *
  * @param CATLISTV(CATString) & oEnvId [out]
  *   The environment ids
  * @param CATLISTV(CATUnicodeString) & oEnvAlias [out]
  *   The environment display names.
  * @param  iType 
  *   The Repository which load the environment from. By default the repository is undefined. List all environments whatever the Repository source
  * @return
  * <dt> <code>S_OK</code>     <dd> At least one environment is available.
  * <dt> <code>S_FALSE</code>  <dd> No environment available.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  *
  */
  virtual HRESULT ListEnvironments(CATListValCATUnicodeString & oEnvAlias, const CATPLMRepositoryName &iRepoName = NULL) = 0;
  /** @deprecated*/
  virtual HRESULT ListEnvironments( CATListValCATString & oEnvId, CATListValCATUnicodeString & oEnvAlias, const CATPLMRepositoryName &iType = NULL) =0;

  /**
  * Loads the environment identified through the provided identifier. This will result in the loading of the corresponding domains.
  *
  * <br><b>Role</b>: Provide the user an entry point to be able to load the metadata associated to a provided environment.
  *
  * @param iEnvId [in]
  *   The environment identifier.
  * @param oEnvironment [out, CATBaseUnknown#Release]
  *   The loaded environment. Release the pointer when useless.
  * @param  iType 
  *   The Repository which load the Environment from. By default the repository is undefined. Load the environment whatever the Repository source
  * @return
  *     <dt><code>S_OK</code></dt>
  *     <dd> The provided environment was successfully loaded.
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using @href CATIPLMErrorStack</dd>
  *
  */
  virtual HRESULT LoadEnvironment( const CATString & iEnvId, CATPLMEnvironment ** oEnvironment, const CATPLMRepositoryName &iType = NULL ) =0;

  /**
  * Returns the Environment for the given EnvironmentId.
  * The GetEnvironment method returns a NULL Environment as far as the  environment  has not been loaded using the LoadEnvironment method.
  * @param  iEnvId
  *   The environment ID.
  * @param  oEnvironment [out, CATBaseUnknown#Release]
  *   The loaded CATPLMEnvironment with the given Id.
  * @param  iType 
  *   The Repository which load the Environment from. By default the repository is undefined. Gets the Environment whatever the Repository source
  */
  virtual HRESULT GetEnvironment(const CATString & iEnvId, CATPLMEnvironment ** oEnvironment, const CATPLMRepositoryName &iType = NULL) =0;

  /**
  * Gets the available Modelers.
  *
  * <br><b>Role</b>: Provide to the user the different modelers available.
  *
  * @param CATLISTV(CATString) & oModelerId [out]
  *   The Modeler ids
  * @param CATLISTV(CATUnicodeString) & oModelerAlias [out]
  *   The modeler display names.
  * @param  iType 
  *   The Repository which load the modeler from. By default the repository is undefined. List all modelers whatever the Repository source
  * @return
  * <dt> <code>S_OK</code>     <dd> At least one Modeler is available.
  * <dt> <code>S_FALSE</code>  <dd> No Modeler available.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  *
  */
  virtual HRESULT ListModelers(CATListValCATUnicodeString & oModelerId, const CATPLMRepositoryName &iType = NULL) = 0;
  /** @deprecated*/
  virtual HRESULT ListModelers( CATListValCATString & oModelerId, CATListValCATUnicodeString & oModelerAlias, const CATPLMRepositoryName &iType = NULL) =0;

  /**
  * Loads the Modeler identified through the provided identifier.
  *
  * <br><b>Role</b>: Load the given Modeler.
  *
  * @param iModelerId [in]
  *   The Modeler identifier (and not metadata). eg: PRODUCT is expected and not PRODUCTCFG.
  * @param oTypes
  *   The types of components that can be examined in this modeler. Ptrs to be released by caller.
  * @param  iType 
  *   The Repository which load the Modeler from. By default the repository is undefined. Load the Modeler whatever the Repository source
  * @return
  *     <dt><code>S_OK</code></dt>
  *     <dd> The provided Modeler was successfully loaded.
  *     <dt><code>S_FALSE</code></dt>
  *     <dd> No Types defined in this modeler.
  *     <dt>E_FAIL </dt>
  *     <dd>A problem occurs during the operation. get further information by using @href CATIPLMErrorStack</dd>
  *
  */
  virtual HRESULT LoadModeler( const CATString & iModelerId, CATListPtrCATPLMType & oTypes, const CATPLMRepositoryName &iType = NULL ) =0;

  /**
  * Returns the Modeler for the given ModelerID.
  * The GetModeler method returns a NULL Modeler as far as the  Modeler  has not been loaded using the LoadModeler method.
  * @param  iModelerId
  *   The Modeler identifier (and not metadata). eg: PRODUCT is expected and not PRODUCTCFG.
  * @param oTypes
  *   The types of components that can be examined in this modeler. Ptrs to be released by caller.
  * @param  iType 
  *   The Repository which load the Modeler from. By default the repository is undefined. Gets the modeler whatever the Repository source
  */
  virtual HRESULT GetModeler(const CATString & iModelerId, CATListPtrCATPLMType & oTypes, const CATPLMRepositoryName &iType = NULL) =0;

  /**
  * Returns the TypeId for a CacheInstance. 
  *
  * <br><b>Role</b>: Returns the TypeId for a CacheInstance.
  *
  * @param oTypeId [out]
  *   The Type identifier.
  * @return
  * <dt> <code>S_OK</code>     <dd> The TypeId was successfully returned.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  */
  virtual HRESULT GetCacheInstanceTypeId( CATPLMTypeId * oTypeId ) =0;

  /**
  * Returns the PLM Type from a type identification. The PLMType's environment has to be loaded before calling this service 
  *
  * <br><b>Role</b>: Returns the PLM Type from a type identification.
  *
  * @param iTypeId [in]
  *   The Type identifier.
  * @param oType [out, CATBaseUnknown#Release]
  *   The CATPLMType. Release the pointer when useless.
  * @param iType
  *   The Repository name
  * @param SearchOnlyClientName
  *   SearchOnlyClientName==TRUE. Products (Class) and Relation.Products can be passed. Products (Relation) is not supported
  *   SearchOnlyClientName==FALSE. Products (Class) and Relation.Products can be passed. Products (Relation) is supported
  *   (SearchOnlyClientName==FALSE expert mode only plmadapter layer can use that)
  * @param  iType 
  *   The Repository which load the Environment from. By default the repository is undefined. Returns the first PLMType found whatever the Repository source
  * @return
  * <dt> <code>S_OK</code>     <dd> The provided environment was successfully loaded.
  * <dt> <code>E_FAIL</code>   <dd> Failure. the Environment for the PLMType may not be Loaded
  */
  virtual HRESULT GetPLMTypeFromTypeId( const CATPLMTypeId &iTypeId, CATPLMType ** oType, const CATPLMRepositoryName &iType = NULL, CATBoolean SearchOnlyClientName = TRUE ) =0;

  /**
  *	Returns the DataBase sites.
  *	@param  oSites
  *   The list of sites managed by the Repository.
  * @param  iType [in]
  *   The Repository which load the site list from. By default the repository is undefined. Gets the list of sites whatever the Repository source
  */
  virtual HRESULT ListSiteNames(CATListValCATUnicodeString * oSiteNames, const CATPLMRepositoryName &iType = NULL) =0;

  /**
  *	Register a domain in the PLMAdapter.
  * @param  iDomain [in]
  *   The domain that needs to be taken into account in the PLMAdapter.
  * @return
  * <dt> <code>S_OK</code>     <dd> The domain is succesfully registered.
  * <dt> <code>S_FALSE</code>  <dd> The domain was already registered, nothing was done.
  * <dt> <code>E_FAIL</code>   <dd> Failure. The domain was invalid.
  */
  virtual HRESULT RegisterDomain(CATPLMDomain *iDomain) =0;

  /**
  * Checks if an Application Service has been declared and is available from the server.
  *
  * <br><b>Note</b>: The availability depends on the client/server level.
  * <br>If a client has a lower level than the server, it will check availability on its level.
  *
  * @param iApplicationServiceName [in]
  *   The Name of the application service to test.
  * @return
  *     <dt><code>S_OK</code></dt>
  *     <dd>Application service is available.</dd>
  *     <dt><code>S_FALSE</code></dt>
  *     <dd>Application service is not available because it has not been declared in a metadata.</dd>
  *     <dt><code>E_NOTIMPL</code></dt>
  *     <dd>Application service is not available because it has been manually deactivated.</dd>
  *     <dt><code>E_FAIL</code></dt>
  *     <dd>A problem occurs during the operation.</dd>
  *
  */
  virtual HRESULT IsApplicationServiceAvailable ( const char* iApplicationServiceName) = 0;

#ifdef CATIAR418
  virtual HRESULT AddExtension(VPMIDicExtension* ipExtensionType, const CATPLMRepositoryName& iRepoName = NULL) = 0;
#endif
#ifdef CATIAR418
  virtual HRESULT EnrichExtension(VPMIDicExtension* ipExtensionType, const CATPLMRepositoryName& iRepoName = NULL) = 0;
#endif
};

#endif
