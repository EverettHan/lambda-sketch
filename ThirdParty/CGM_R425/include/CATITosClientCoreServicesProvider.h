#ifndef CATITosClientCoreServicesProvider_H
#define CATITosClientCoreServicesProvider_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010

/**
* @level Private
* @usage U3
*/

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATTosAttributesFilter.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATOmxArray.h"
#include "CATOmxKeyString.h"
#include "CATIAV5Level.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATITosClientCoreServicesProvider;
#else
extern "C" const IID IID_CATITosClientCoreServicesProvider;
#endif

class CATPLMTypeId;
class CATIComponent;
class CATComponentId;
class CATPLMStreamingContext;
class CATPLMStreamingResult;
class CATVVSURLConnection;
class CATOmxKeyValueBlock;
class CATString;
class CATPLMTypeH;
class CATUnicodeString;
class CATOmxAny;
class CATIPLMErrorCollector;
class CATPLMAttributeValues;
class CATPLMAttributeValue;

/**
 * Bridge to PC2.
 * Usage is restricted to TOS
 * Do not even think about using it from elsewhere.
 */
class ExportedByCATPLMTos CATITosClientCoreServicesProvider : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  // ======================================================================================
  // IMPORT MANAGEMENT
  // ======================================================================================

  /**
  * IMPORT MANAGEMENT
  *
  * Cores a component implementation to kept an empty shell.
  * - The operation is not undoable.
  * - The content will be populated later by refresh engine.
  *
  *  @param iHandle
  *    Handle
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT SwitchComponentToEmptyShell(const CATComponentId & iHandle) = 0;

  /**
  * IMPORT Management
  *
  * Complete an empty shell with an AttrBlock (The extensions are automatically created)
  *
  * @param iHandle
  * @param iExtensionType
  * @param iAttrBlock
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT CompleteEmptyShellWithAttributeBlock(const CATComponentId & iHandle, const CATPLMTypeId & iExtensionType, CATOmxKeyValueBlock & iAttrBlock, CATIPLMErrorCollector* iErrorCollector) = 0;

  virtual HRESULT DestroyComponentWhenTransactionIsAborted(CATBaseUnknown* iComponent) = 0;

  // ======================================================================================
  // STREAMING MANAGEMENT
  // ======================================================================================

  /**
  *  Asks for a Port or Relation to stream into a cache its binary view.
  * <br><b>Role:</b>This method enables to stream the data of a component into the cache for a late send to
  * a specific repository.
  *
  * @param iCID [in]
  *   The component handle.
  * @param iContext [in]
  *   The context the streams must be created for.
  * @param oResult [out]
  *   The result of the streaming operation.
  *
  *  @return
  *       S_OK    : The stream were succesfully generated.
  *       S_FALSE : The component has no streams to generate.
  *       E_FAIL  : Failure occured during the treatment.
  */
  virtual HRESULT StreamConnectionAndPortInCache(const CATComponentId & iCID, const CATPLMStreamingContext & iContext, CATPLMStreamingResult & oResult) = 0;

  /**
  *  Asks for a Port or Relation to stream into a cache its binary view.
  * <br><b>Role:</b>This method enables to stream the data of a component into the cache for a late send to
  * a specific repository.
  *
  * @param iCID [in]
  *   The component handle.
  * @param iUrlConnection [in]
  *   An optional URL connection if component is stream dependant.
  *
  *  @return
  *       S_OK    : if succeeful.
  *       E_FAIL  : if failure.
  */
  virtual HRESULT UnstreamConnectionAndPortFromCache(const CATComponentId & iCID, const CATVVSURLConnection * iUrlConnection, CATIPLMErrorCollector* iErrorLog) = 0;

  // ======================================================================================
  // CLONING MANAGEMENT
  // ======================================================================================

  /**
  *  Mise a jour du block d'attributs extrait du composant source pour y appliquer les reglès de cloning décrites au niveau metadata
  *  - Unset par remise au default pour :
  *       - Tout un ensemble d'attributs system
  *       - Les attributs identifiés dans les metadata comme etant ResetOnCloning (PAS DISPO POUR L'INSTANT)
  */
  virtual void UpgradeAttributesToBeCompliantWithCloningRules(const CATPLMTypeH & iType, CATOmxKeyValueBlock& ioAttrBlock) = 0;


  /**
   * Setting the value of an attribute on a PC2 component
   * To be used with maximum care!
   * All usages must be identified
   * @param iCID [in]
   *   The component handle.
   * @param Attr [in]
   *   Attr name.
   * @param Value [in]
   *   Attr Value.
   *
   *  @return
   *       S_OK    : if succeeful.
   *       E_FAIL  : if failure.
   */
  virtual HRESULT SetAttribute(const CATComponentId & iCID, const CATString& Attr, const CATUnicodeString &Value) = 0;

  /**
  * Get the Master Stamp for PC2
  *
  * @param iComponent [in]
  *   The component pointer in session.
  *
  * @param oValue [out]
  *   The Master Stamp
  *
  *  @return
  *       S_OK    : if succeeful.
  *       E_FAIL  : if failure.
  */
  virtual HRESULT GetMasterStamp(const CATBaseUnknown * iComponent, CATOmxAny & oValue) = 0;

  virtual HRESULT TouchUpdateStamp(CATComponentId& iTOS, CATBaseUnknown* iPC2) = 0;

  // Same as above, Yet another PCS improvement
  virtual HRESULT CreateComponentAsEmptyShell(const CATPLMTypeH & iTypeH, CATBaseUnknown*& oEmptyShell) = 0;

  virtual double GenerateTreeOrderValue() const = 0;

  virtual void LogPC2EntityCreation(CATBaseUnknown& iPC2Entity) const = 0;

  virtual HRESULT GetPC2AttributeValue(const CATBaseUnknown& iPC2Entity, const CATPLMTypeH& iExtensionType, const CATOmxKeyString& iKey, CATPLMAttributeValue& oAttributeValue) const = 0;
  virtual HRESULT GetPC2AttributeValues(const CATBaseUnknown& iPC2Entity, const CATPLMTypeH& iExtensionType, CATPLMAttributeValues& oAttributeValues) const = 0;
  virtual HRESULT GetTreeOrder(const CATBaseUnknown& iPC2Entity, const CATOmxKeyString& iTreeOrderAttrName, double& oTreeOrder) const = 0;
};

//------------------------------------------------------------------

#endif
