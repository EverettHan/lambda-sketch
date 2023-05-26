/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2009
#ifndef CATIPLMSessionDuplicateEngine_H
#define CATIPLMSessionDuplicateEngine_H

/**
* @level Protected
* @usage U3
*/
#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATOmxSR.h"

class CATIPLMComponent;
class CATPLMLifeCycleRootsBag;
class CATPLMBag;
class CATPLMID;
class CATUnicodeString;
class CATIAdpErrorMonitor;
class CATListValCATPLMID;
class CATProxySpace;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMSessionDuplicateEngine;
#else
extern "C" const IID IID_CATIPLMSessionDuplicateEngine;
#endif

/**
* This engine allows to duplicate a set of PLM components in session.
*
* Duplicated components need to be saved in database (as opposed with server cloning/copy)
*
* You can create an instance of this interface using CATPLMSessionDuplicateEngineToolbox::GetSessionDuplicateEngine
*
* Warning, there are several bugs and limitations:
*  config is not managed
*  undo-redo is not supported
*  by default reroute might not be what you expect (see CompleteMappingWithSharedComponent) and is unsafe (see RerouteCloneRelationsActivation)
*  rep clones are not loaded (they are in "PLM_Mode" while they probably should be loaded in "AuthoringFullEdit_Mode") and should probably be loaded manually (see CATIOmiSwitchEngine)
*
* Do not use without aknowledgement from integration team.
*
* This class can be used to duplicate any modeler data, however it must not be used without the approval of the modeler's responsible.
*
* There are several options which default value is not always the smartest (for legacy/compatibility reasons)
* Please read all the documentation in this header before using this class.
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMSessionDuplicateEngine : public CATBaseUnknown
{
public:

  CATDeclareInterface;

  /**
  * Attach a bag for managing life cycle.
  *
  * It is mandatory in some cases (for example if you clone a single reference).
  * It is useless in some other cases (if you clone only instances)
  */
  virtual HRESULT AttachBag(CATPLMLifeCycleRootsBag& iBag) = 0;
  virtual HRESULT AttachBag(CATPLMBag& iBag) = 0;

  /**
  * Cloning string allows to change identification attributes
  * behavior depends on Business logic activation (see next method)
  *   activated:     PLM_ExternalID will be prefixed by Cloning String
  *   not activated: Cloning string will be accessible by BL via "IdCloningString"
  */
  virtual HRESULT SetCloningString(const CATUnicodeString& iCloningString) = 0;

  /**
  * activate/deactivate business logic
  * if true (default) cloning BLs will be called on cloned objects (nb: only on references/representations, NOT on instances, connections etc...)
  */
  virtual HRESULT BusinessLogicActivation(CATBoolean iActivated) = 0;

  /**
  * activate/deactivate usage of omb reroute engine
  * if true (default being false)
  *    relations integrity rules will be checked (contextual, bundle and those defined through SRPatternConstraint keywords of metadata files)
  *    if ever an integrity rule is violated, the clone is created anyway and the problematic relations are either isolated or left unrerouted.
  * if false, the result of the cloning can be broken from modeler's point of view
  */
  virtual HRESULT RerouteCloneRelationsActivation(CATBoolean iActivated) = 0;

  /**
  * Duplicate a component as loaded in memory
  * The target component will be seen in session as ToCreate.
  *
  * @param iSourceComponent
  *        component to clone
  * @param iKeepSameLogicalId
  *        if TRUE, clone will have the same logicalid as clone
  * @param oCloneId
  *        id of the clone
  * at this point clone is not created (will be performed when calling Duplicate)
  */
  virtual HRESULT RegisterDelayedOperation_CloneAsLoaded(const CATBaseUnknown* iSourceComponent, CATBoolean iKeepSameLogicalId, CATPLMID* oCloneId = NULL) = 0;

  /** not implemented */
  virtual HRESULT RegisterDelayedOperation_SynchronizeCloneAsLoaded(const CATBaseUnknown * iSourceComponent, const CATBaseUnknown * iTargetComponent) = 0;
  /** not implemented */
  virtual HRESULT RegisterDelayedOperation_SynchronizeCloneAsDeleted(const CATBaseUnknown * iTargetComponent) = 0;

  /**
  * Declare a component as being a clone of another.
  * Use it to allow a reroute on cloned objects
  * example, duplicate an instance under an existing reference
  * let's say we have
  * root1
  *   + inst -> ref
  * and we want to duplicate inst under another reference "root2"
  * this can be achieved by the following snippet:
  *   CATIPLMSessionDuplicateEngine_var cloner;
  *   CATPLMSessionDuplicateEngineToolbox::GetSessionDuplicateEngine(cloner);
  *   CATPLMID instCloneId;
  *   cloner->RegisterDelayedOperation_CloneAsLoaded(inst,copyLogicalId,&instCloneId);
  *   cloner->CompleteMappingWithUpToDateClone(root1,root2); //replace links to root1 by links to root2 in clone context
  *   clone->Duplicate();
  */
  virtual HRESULT CompleteMappingWithUpToDateClone(const CATBaseUnknown* iSourceComponent, const CATBaseUnknown* iTargetComponent) = 0;

  /**
  * By default, reroute is not performed on clone if it is partial (if some of the target objects are not being duplicated)
  * Calling this method on objects outside duplication set will force reroute in "some cases":
  *
  * given the data model
  *   root
  *     + inst1 -> ref1
  *                 + inst2 -> ref2
  *     + port, target = [ inst1, inst2 ]
  *
  * we want to duplicate inst1 and port
  *
  * by default the result will be
  *   root
  *     + inst1 -> ref1
  *                 + inst2 -> ref2
  *     + port, target = [ inst1, inst2 ]
  *     + cloneof(inst1) -> ref1
  *     + cloneof(port), target = [ inst1, inst2 ]
  * notice that cloneof(port) has NOT been rerouted to [ cloneof(inst1), inst2 ] the reason being the inst2 is not part of the cloning operation and partial reroute is forbidden
  *
  * now if we call CompleteMappingWithSharedComponent(inst2), then the result will be:
  *   root
  *     + inst1 -> ref1
  *                 + inst2 -> ref2
  *     + port, target = [ inst1, inst2 ]
  *     + cloneof(inst1) -> ref1
  *     + cloneof(port), target = [ cloneof(inst1), inst2 ]
  * notice that cloneof(port) has been rerouted to [ cloneof(inst1), inst2 ]
  */
  virtual HRESULT CompleteMappingWithSharedComponent(const CATBaseUnknown * iSharedComponent) = 0;

  /**
  * List CloneAsLoaded delayed operations.
  * There is no reason to call this method, try to stay away.
  */
  virtual HRESULT ListCloneAsLoadedMapping(CATListValCATBaseUnknown_var & oSources, CATListValCATPLMID & oClones) = 0;

  /**
  * List CloneAsLoaded delayed operations.
  * There is no reason to call this method, try to stay away.
  */
  virtual HRESULT ListCloneAsLoadedTargettedIdentifiers(CATListValCATPLMID & oClones) = 0;

  /**
  * Returns current error monitor
  */
  virtual HRESULT GetErrorMonitor(CATIAdpErrorMonitor *& oErrorMonitor) const = 0;

  /**
  * Specify the space where objects will be cloned.
  * Must be called before any other method.
  */
  virtual HRESULT SetTargetSpace(const CATProxySpace& iTargetSpace) = 0;

  /**
  * Execute duplication.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_ACCESSDENIED : if data partially accessible and cannot be duplicated.
  *      E_FAIL         : if request failed.
  */
  virtual HRESULT Duplicate() = 0;

  /**
  * Return the clone of the source
  *
  * @param iSourceComponent
  *        The source of the cloning operation.
  */
  virtual CATOmxSR <CATBaseUnknown> GetClone(const CATBaseUnknown* iSourceComponent) = 0;

  /**
   * @param iActivated
   * if false (which is the default)
   *   "tree order" attributes are copied 'as-is', the resulting order is unspecified
   *   let
   *      root
   *        + inst1
   *        + inst2
   *    the result after a cloning of inst1 will be either
   *      root
   *        + inst1
   *        + cloneof(inst1)
   *        + inst2
   *    or
   *      root
   *        + cloneof(inst1)
   *        + inst1
   *        + inst2
   *
   * if true (which is NOT the default), then the result of the previous example will be
   *      root
   *        + inst1
   *        + inst2
   *        + cloneof(inst1)
   *
   *   notice that relative order of clones is respected, after cloning of inst1 and inst2 (in the same transaction), the result will be
   *      root
   *        + inst1
   *        + inst2
   *        + cloneof(inst1)
   *        + cloneof(inst2)
   */
  virtual void TreeOrderManagementActivation(CATBoolean iActivated) = 0;
};

CATDeclareHandler(CATIPLMSessionDuplicateEngine, CATBaseUnknown);

#endif
