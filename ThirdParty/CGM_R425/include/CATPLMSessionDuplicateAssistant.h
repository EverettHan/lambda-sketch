#ifndef CATPLMSessionDuplicateAssistant_H
#define CATPLMSessionDuplicateAssistant_H
/* -*-c++-*- */
/**
 * @level Private
 * @usage U1
 */

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATLISTV_CATComponentId.h"
#include "CATOmxSharable.h"

class CATComponentId;
class CATIPLMErrorCollector;
class CATPLMBag;
class CATPLMID;
class CATOxSessionDuplicateAssistant;
class CATListValCATComponentId;
class CATUnicodeString;
class CATOmxKeyValueBlock;
class CATIPLMSelectiveLoadingRuleSet;

/**
 * Do not use this class directly.
 * use CATIPLMSessionDuplicateEngine instead (CATPLMSessionDuplicateEngineToolbox::GetSessionDuplicateEngine)
 */
class CATPLMSessionDuplicateAssistant : public CATOmxSharable
{
public:
  /** factory */
  ExportedByCATPLMTos static CATOmxSR<CATPLMSessionDuplicateAssistant> Create();

  virtual void AttachBag(CATPLMBag & iBag) = 0;
  virtual void AttachErrorCollector(CATIPLMErrorCollector* iErrorCollector) = 0;
  virtual void AttachSelectiveLoadingRuleSet(CATIPLMSelectiveLoadingRuleSet* iLoadingRuleSet) = 0;

  /**
   * Cloning string allows to change identification attributes
   * Without BusinessLogic : PLM_ExternalID will be prefixed by Cloning String
   * With BisnessLogic : Cloning string will be accessible by BL via "IdCloningString"
   *
   * @param iCloningString
   *        The cloning string to be used.
   */
  virtual void SetCloningString(const CATUnicodeString & iCloningString) = 0;

  /**
  * Allows to deactivate BusinessLogic during CloneAsLoaded
  * By default, the BusinessLogic is activated
  *
  * @param iActivated
  *        TRUE  : Keeps BL running (Default)
  *        FALSE : Deactivates BL
  */
  virtual void BusinessLogicActivation(CATBoolean iActivated) = 0;

  /**
 * Allows to activate Reroute of Cloned Relations instead of mapping
 * By default, it is desactivated
 *
 * @param iActivated
 *        TRUE  : Enable Reroute based on mapping and reroute integrity rules.
 *        FALSE : Keep mapping only
 */
  virtual void RerouteCloneRelationsActivation(CATBoolean iActivated) = 0;

  virtual void TreeOrderManagementActivation(CATBoolean iActivated) = 0;

  /**
  * Duplicate a component based only on loaded definition
  * The target component will be seen in session as ToCreate.
  *
  * @param iSourceComponent
  *        The source of the cloning operation.
  * @param iKeepSameLogicalId
  *        Generate the target PLMID with the same logical id
  * @param iTargetAttributesToOverride
  *        Definition d'un set d'attributs optionel a valuer sur la cible.
  * @param iTargetComponent
  *        The result of the cloning operation. Will be solved after commit.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  */
  virtual HRESULT CloneAsLoaded(const CATComponentId & iSourceComponent, CATBoolean iKeepSameLogicalId, const CATOmxKeyValueBlock * iTargetAttributesToOverride = NULL, CATComponentId * iTargetComponent = NULL) = 0;

  /**
  * Declare a component as clone of another when synchronization is not necessary.
  * Allows to complete mapping between the two structures and managing correctly relational impacts.
  * Relational impacts on :
  *            Owner
  *            IsInstanceOf
  *            Semantical Relations
  *
  * @param iSourceComponent
  *        The source of the cloning operation.
  * @param iTargetComponent
  *        The target of the cloning operation. The component to be refreshed.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  */
  virtual HRESULT CompleteMappingWithUpToDateClone(const CATComponentId & iSourceComponent, const CATComponentId & iTargetComponent) = 0;

  /**
  * Declare a component as shared by source and target.
  * Allows to complete mapping between the two structures and managing correctly relational impacts.
  *
  * @param iSharedComponent
  *        The shared component.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  */
  virtual HRESULT CompleteMappingWithSharedComponent(const CATComponentId & iSharedComponent) = 0;

  /**
  * Commit des operations
  */
  virtual HRESULT Commit() = 0;

  /**
  * List the cloned components
  */
  virtual HRESULT ListClonedAsLoaded(CATListValCATComponentId & ioSourceComponents, CATListValCATComponentId & ioTargetComponents) = 0;

  /**
  * Streams downloading mngt
  */
  virtual HRESULT ListCandidatesForSDDataModelCompletion(CATComponentIds & oComponentsToTreat) const = 0;

  /**
  * Working space
  */
  virtual CATProxySpace GetSourceSpace() const = 0;
  virtual CATProxySpace GetTargetSpace() const = 0;
  virtual HRESULT SetTargetSpace(const CATProxySpace& iTargetSpace) = 0;
  virtual CATBoolean IsUsingReroute() const = 0;
};

#endif
