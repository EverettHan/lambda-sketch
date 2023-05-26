// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMProviderServices.h
//
//===================================================================
//
// Usage notes:
// 
//===================================================================
// SRU(jun03) Creation
//===================================================================
/**
* @level Private
* @usage U1
*/
#ifndef CATPLMProviderServices_H
#define CATPLMProviderServices_H

#include "CATPLMImplAdapterBase.h"
//--
#include "CATUnicodeString.h"
#include "CATEventSubscriber.h"
#include "CATOmxList.h"
//--
class CATIPLMProviderConnection;
class CATIPLMProviderDesc;
class CATPLMRepositoryName;
class CATIPLMErrorStack;
class CATListPtrCATIPLMProviderDesc;
//-----------------------------------------------------------------------

/**
*
*/
class ExportedByCATPLMImplAdapterBase CATPLMProviderServices
{
public:
  /**
  * Returns the provider for the given type and instance Id.
  * @param ipType
  *     The provider type.
  * @param ipInstanceId
  *     The instance Id.
  * @param oppProv [out, CATBaseUnknown#Release]
  *     The provider.
  * @return
  *     The method return S_FALSE if no provider descriptor of the required type has been found.
  */
  static HRESULT GetProvider(const CATPLMRepositoryName ipType,
    CATUnicodeString * ipInstanceId,
    CATIPLMProviderConnection ** oppProv);

  /**
  * Returns the provider Desc for the given type and instance Id.
  * @param ipType
  *     The provider type.
  * @param ipInstanceId
  *     The instance Id.
  * @param oppProv [out, CATBaseUnknown#Release]
  *     The provider Desc.
  * @return
  *     The method return S_FALSE if no provider descriptor of the required type has been found.
  */
  static HRESULT GetProviderDesc(const CATPLMRepositoryName ipType,
    CATUnicodeString * ipInstanceId,
    CATIPLMProviderDesc ** oppProv);
  /**
  * Returns the user Id for the given provider.
  * @param ipProvider
  *    The provider.
  * @param oppUserId
  *    The user Id.
  */
  //static HRESULT GetUserId( CATIPLMProvider   * ipProvider
  // , CATUnicodeString ** oppUserId );

  /**
  * Check if a provider is connected or not
  * @param ipType
  *     The provider type.
  * @param ipInstanceId
  *     The instance Id.
  * @return
  *     RC=E_FAIL if not connected.
  */
  static HRESULT IsConnected(const CATPLMRepositoryName ipType,
    CATUnicodeString * ipInstanceId);

  /**
  * Returns the PLMAdapater ErrorStack.
  * @param opErrorStack [out, CATBaseUnknown#Release]
  *     The Error Stack.
  * @return
  *     The method returns S_OK
  */
  static HRESULT GetPLMErrorStack(CATIPLMErrorStack ** opErrorStack);

  /**
  * Returns all the provider descriptors which can be used.
  * @param iType
  *     provider type. if empty, all providers are required. @see CATPLMRepositoryName
  * @param  oListProvDesc
  *     provider descriptors. Each descriptor of the list must be released after use.
  * @return
  *     Error code of function.
  */
  static HRESULT ListProviderDescs(const CATPLMRepositoryName iType, CATListPtrCATIPLMProviderDesc** oListProvDesc);

  /**
  *   List of possible filter for ListFilteredProviderDescs.
  */
  enum PvFilter
  {
    PvDescAll = 0
    , PvDescIsConnected = 1
    , PvDescIsReadyToConnect = 2
  };

  /**
  * Returns a filtered view of the provider descriptors.
  * @param  iType
  *     provider type. if empty, all providers are required. @see CATPLMRepositoryName.
  * @param  oListProvDesc
  *     provider descriptors. Each descriptor of the list must be released after use.
  * @param iFilter
  *     Default 0 : connection
  * @return
  *     E_INVALIDARG : input list is not empty
  */
  static HRESULT ListFilteredProviderDescs(const CATPLMRepositoryName iType, CATListPtrCATIPLMProviderDesc &oListProvDesc, CATPLMProviderServices::PvFilter iFilter = PvDescAll);
  static HRESULT ListFilteredProviderDescs(const CATPLMRepositoryName iType, CATOmxList<CATIPLMProviderDesc> & oListProvDesc, CATPLMProviderServices::PvFilter iFilter = PvDescAll);


private:
  // leak in odt CATObjectModelerCommands.tst CATObjectModelerCommands_EmbeddedBitmap_Edit called in CATPLMCompMetaDataService::CleanAfterDisconnect() (then CATPLMProviderServices::ListFilteredProviderDescs())
  friend class CATPLMCompMetaDataService;// called in CATPLMCompMetaDataService::CleanAfterDisconnect
  static HRESULT ListFilteredProviderDescs(const CATPLMRepositoryName iType, CATBoolean isCreationOfAdapterAuthorized, CATOmxList<CATIPLMProviderDesc> & oListProvDesc, CATPLMProviderServices::PvFilter iFilter = PvDescAll);
};

//-----------------------------------------------------------------------

#endif
