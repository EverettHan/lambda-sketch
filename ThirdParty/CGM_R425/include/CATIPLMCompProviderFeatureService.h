// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIPLMCompProviderFeatureService.h
// Define the CATIPLMCompProviderFeatureService interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  May 2004  Creation: Code generated by the CAA wizard  jsy
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompProviderFeatureService_H
#define CATIPLMCompProviderFeatureService_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATPLMProviderFeatureEnum.h"
#include "CATPLMProviderCapabilityEnum.h"
#include "CATPLMPropertyEnum.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMCompProviderFeatureService;
#else
extern "C" const IID IID_CATIPLMCompProviderFeatureService ;
#endif

class CATPLMRepositoryName;
class CATUnicodeString;
class CATString;
class CATOmxAny;

/**
 * Handles the Provider feature requests.
 *
 */
class ExportedByCATPLMServicesItf CATIPLMCompProviderFeatureService: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
  /**
   * Returns a Feature level of implementation from a specified provider.
   * 
   * @param iFeatureRequest
   *  The feature asked to the provider.
   * @param oResult
   *  The answer of the provider.
   * @param iRepository
   *  The provider on which the query will be launch.
   * @param iInstanceID
   *  The instance of connection.
   *   NULL : the provider should answer the default behavior of current level.
   *   not NULL : the provider should answer the behavior of this specific connection. (with the level of this connection)
   *              If this instance is not connected : return like if the instance is NULL and return S_FALSE for the method.
   * @return
   *  S_OK    : everything is OK. The answer is readable (even FeatureResult_NotImpl)
   *  S_FALSE : At least one capability was not declared by the provider (seen as FullyImpl)
   *          : Or instance of provider was not connected, the answer is the default one (using current client level)
   *  E_FAIL  : The InstanceID is not connected or the provider is unknown or the provider does not support feature querying.
   */
   virtual HRESULT QueryFeature (const CATPLMProviderFeatureEnum iFeatureRequest
                                ,CATPLMProviderFeatureResult &oResult
                                ,const CATPLMRepositoryName &iRepository
                                ,const CATString *iInstanceID = NULL ) = 0;



  /**
   * Returns a Feature level of implementation from a specified provider.
   * 
   * @param iFeatureRequest
   *  The feature asked to the provider.
   * @param oResult
   *  The answer of the provider.
   * @param oCapabilityRecord
   *  The list of provider capability and each answers.
   * @param iRepository
   *  The provider on which the query will be launch.
   * @param iInstanceID
   *  The instance of connection.
   *   NULL : the provider should answer the default behavior of current level.
   *   not NULL : the provider should answer the behavior of this specific connection. (with the level of this connection)
   *              If this instance is not connected : return like if the instance is NULL and return S_FALSE for the method.
   * @return
   *  S_OK    : everything is OK. The answer is readable (even FeatureResult_NotImpl)
   *  S_FALSE : Instance of provider was not connected, the answer is the default one (using current client level)
   *  E_FAIL  : The InstanceID is not connected or the provider is unknown or the provider does not support feature querying.
   */
   virtual HRESULT QueryFeature (const CATPLMProviderFeatureEnum iFeatureRequest
                                ,CATPLMProviderFeatureResult &oResult
                                ,CATPLMCapabilityRecord &oCapabilityRecord
                                ,const CATPLMRepositoryName &iRepository
                                ,const CATString *iInstanceID = NULL ) = 0;

  /**
   * Returns a Property from a specified provider.
   * 
   * Note: A property is different from a capacity. It returns a value to use as a base.
   * @param iProperty
   *  The property to request. @see  CATPLMPropertyEnum
   * @param oValue
   *  The value returned by the provider. The type of the any depends on the property, see documentation of the property.
   * @param iRepository
   *  The provider on which the query will be launch.
   * @param iInstanceID
   *  The instance of connection. Use empty string for current connection.
   * @return
   *  S_OK    : everything is OK.
   *  S_FALSE : Instance of provider was not connected or the default value was returned.
   *  E_FAIL  : The InstanceID is not found or the provider is unknown or the provider does not support feature querying.
   */
   virtual HRESULT GetProperty (const CATPLMPropertyEnum iProperty
                                ,CATOmxAny &oValue
                                ,const CATPLMRepositoryName &iRepository
                                ,const CATString &iInstanceID ) = 0;

};
#endif
