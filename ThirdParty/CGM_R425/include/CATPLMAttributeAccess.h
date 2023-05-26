#ifndef _CATPLMAttributeAccess_H
#define _CATPLMAttributeAccess_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATPLMLifeCycle                   AuthorizedModule
#define CATOmbRelationIntegrity           AuthorizedModule
#define CATOxiAttributeAccess             AuthorizedModule
#define CATOxiRelationAccess              AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATOmbDebugLink                   AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMIntegrationBase             AuthorizedModule
#define CATPLMCompletion                  AuthorizedModule
#define CATPLMCompletionAccess            AuthorizedModule
#define CATPLMCompletionBase              AuthorizedModule
#define CATPLMCollabMgt                   AuthorizedModule
#define CATPLMItgTests                    AuthorizedModule
#define CATOxiQueryResultTransaction      AuthorizedModule
#define CATPLMImportMgt                   AuthorizedModule
#define CATPLMItgTestIntegrationAccess    AuthorizedModule
#define CATPLMSessionContentAccess        AuthorizedModule
#define CATPLMMLCreateTable               AuthorizedModule
#define CATOxiDEATOSSearch                AuthorizedModule
#define CATPLMSynchronization             AuthorizedModule
#define CATOxiMinorMajor                  AuthorizedModule
#define CATPLMEditabilityImpl             AuthorizedModule
#define TstCATPLMPspImportInSession       AuthorizedModule
#define CATOmbLinkTrader                  AuthorizedModule
#define CATPLMTosManager                  AuthorizedModule
#define CATPLMIdentification              AuthorizedModule
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATOmbLinks                       AuthorizedModule
#define CATPLMTosRefresh                  AuthorizedModule
#define CATOxiSynchronizationEngine       AuthorizedModule
#define CATPLMImplAdapterClass            AuthorizedModule
#define CATOmbLifeCycle                   AuthorizedModule
#define CATPLMItgTestBase                 AuthorizedModule
#define CATPLMModelBuilderTests           AuthorizedModule
#define CATPLMContentTracking             AuthorizedModule
#define CATPLMClientCoreModel             AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMAttributeAccess from a non-infrastructure module
@error
#endif

#undef CATPLMTos
#undef CATPLMLifeCycle
#undef CATOmbRelationIntegrity
#undef CATOxiAttributeAccess
#undef CATOxiRelationAccess
#undef CATPLMIdentification_PLM
#undef CATOmbDebugLink
#undef CATPLMIntegration
#undef CATPLMIntegrationBase
#undef CATPLMCompletion
#undef CATPLMCompletionAccess
#undef CATPLMCompletionBase
#undef CATPLMCollabMgt
#undef CATPLMItgTests
#undef CATOxiQueryResultTransaction
#undef CATPLMImportMgt
#undef CATPLMItgTestIntegrationAccess
#undef CATPLMSessionContentAccess
#undef CATPLMMLCreateTable
#undef CATOxiDEATOSSearch
#undef CATPLMSynchronization
#undef CATOxiMinorMajor
#undef CATPLMEditabilityImpl
#undef TstCATPLMPspImportInSession
#undef CATOmbLinkTrader
#undef CATPLMTosManager
#undef CATPLMIdentification
#undef CATPLMIntegrationAccess
#undef CATOmbLinks   
#undef CATPLMTosRefresh   
#undef CATOxiSynchronizationEngine
#undef CATPLMImplAdapterClass
#undef CATOmbLifeCycle
#undef CATPLMItgTestBase
#undef CATPLMModelBuilderTests
#undef CATPLMContentTracking
#undef CATPLMClientCoreModel
// ----------------------------------------------------------------------------------------------------------------------

#include "ExportedByCATPLMTos.h"
#include "CATTosMacros.h"
#include "CATComponentId.h"
#include "CATBoolean.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATOmxCollectionType.h"

class CATString;
class CATOmxAny;
class CATPLMAttributesFilter;
class CATPLMTypeId;
class CATOmxKeyValueBlock;
class CATPLMAttributeValues;
class CATPLMAttributeValue;

/**
* Access to PLM attributes
*/
class ExportedByCATPLMTos CATPLMAttributeAccess
{
public:
  inline CATPLMAttributeAccess(const CATComponentId & iCID) :_CID(iCID) {}

  /**
   * Check if component is instantiable only one.
   *
   * @return
   *      S_OK      : Is instantiable only once.
   *      S_FALSE   : Is not instantiable only once.
   *      E_PENDING : If the data necessary to complete this operation is not yet available.
   *      E_FAIL    : If an unexpected failure.
   */
  HRESULT IsOnceInstantiable();

  /**
  * Retrieves the extensions defined on the component.
  * <br><b>Role:</b>Search on the component the extensions defined and returns it.
  * @param oExtensions [out]
  *   The extensions of the component.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: The extensions are returned.</li>
  *   <li><tt>S_FALSE</tt>: No extension available on the component.</li>
  *   <li><tt>E_PENDING</tt>: If the data necessary to complete this operation is not yet available.</li>
  *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
  *   </ul>
  */
  HRESULT ListExtensions(CATPLMTypeIds & oExtensions);

  /** meaningless */
  HRESULT CheckAttributesMask(const CATPLMTypeId & iExtensionType, const CATPLMAttributesFilter & iFilter, CATLISTV(CATString) & oAttributeIds);

  /** deprecated */
  HRESULT GetAttributeValue(const CATPLMTypeId & iExtensionType, const CATString & iAttributeId, CATOmxCollectionType & oAttrValueCType, CATOmxAny & oAttributeValue);
  HRESULT GetAttributeValue(const CATOmxKeyString & iAttributeId, CATOmxAny & oAttributeValue);
  HRESULT GetAttributeValue(const CATPLMTypeH& iExtensionType, const CATOmxKeyString & iAttributeId, CATOmxAny& oAttributeValue);
  HRESULT GetAttributeBlock(const CATPLMTypeH& iExtensionType, CATOmxKeyValueBlock &oAttrBlock);

  /**
   * retrieve attribute values
   */
  HRESULT GetAttributeValues(const CATPLMTypeH& iExtensionType, CATPLMAttributeValues& oValues) const;
  HRESULT GetAttributeValue(const CATPLMTypeH& iExtensionType, const CATOmxKeyString & iAttributeId, CATPLMAttributeValue& oValue) const;

  const CATComponentId _CID;
};

#endif
