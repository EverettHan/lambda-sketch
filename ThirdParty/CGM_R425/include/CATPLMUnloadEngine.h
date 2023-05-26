#ifndef CATPLMUnloadEngine_H
#define CATPLMUnloadEngine_H
/* -*-c++-*- */
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATOmbLifeCycle                   AuthorizedModule
#define CATAuthoringUnload                AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATOxiLifeCycle                   AuthorizedModule	
#define CATPLMIdentificationAccess        AuthorizedModule	
#define CATOmbTransientServices           AuthorizedModule	
#define CATOmbDebugLink                   AuthorizedModule	
#define CATFmtToolsServices               AuthorizedModule	
#define CATPLMIntegrationAccess           AuthorizedModule
#define CATAuthoringReload                AuthorizedModule	 
#define CATPLMModelBuilderTests           AuthorizedModule
#define CATImmCaptureCmd                  AuthorizedModule
#define CATPLMDmtDocCommands		          AuthorizedModule
#define CATPLMDocRelations  		          AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMUnloadEngine from a non-authorized module
@error
#endif
#undef CATOmbLifeCycle
#undef CATAuthoringUnload
#undef CATPLMIdentification_PLM
#undef CATOxiLifeCycle
#undef CATPLMIdentificationAccess
#undef CATOmbTransientServices
#undef CATOmbDebugLink
#undef CATFmtToolsServices
#undef CATPLMIntegrationAccess
#undef CATAuthoringReload
#undef CATPLMModelBuilderTests
#undef CATImmCaptureCmd
#undef CATPLMDmtDocCommands
#undef CATPLMDocRelations
// ----------------------------------------------------------------------------------------------------------------------

#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATOmxList.h"
#include "CATOmxSR.h"

class CATIPLMComponent;
class CATPLMUnloadManager;

/*
* Engine managing the unload of components from session.
* The unload of component is managed through a life cycle transaction,
*	which triggers a life cycle graph to remove unused components from session.
* You can be notified of the unload of a component by subscribing to the PLM_Unload event.
*	NB: this operation flushes the undo/redo log.
*/
class ExportedByCATPLMIdentificationAccess CATPLMUnloadEngine
{
public:

  CATPLMUnloadEngine();
  ~CATPLMUnloadEngine();

  /**
  *	InsertComponentToUnload
  * <br><b>Role</b>: insert a component to unload.
  *	WARNING: you cannot insert components if a Simulate has already been done. You
  * must call either Cancel or DoUnload methods.
  * Inserting a reference means inserting all its instances too.
  *	WARNING: the inserted component can be not unloaded according
  *	to life cycle rules: held by a bag (for example if root of an editor),...
  * WARNING: Port, connexions and ER components are not authorized.
  * @param iComponent
  *		the component. Only PC2 components are accepted.
  * @return
  * <dl>
  * <dt><code>S_OK</code>if succeeded<dd>
  * <dt><code>S_FALSE</code>already done<dd>
  * <dt><code>E_FAIL</code>there is already a simulation launched<dd>
  * <dt><code>E_INVALIDARG</code>Invalid input object type (port, connexion, ER)<dd>
  * </dl>
  */
  HRESULT InsertComponentToUnload(const CATIPLMComponent * iComponent);

  /**
  *	Simulate
  * <br><b>Role</b>: Simulate the unload of the inserted components.
  *	Propagation of the unload and locks of compoents (e.g. by a bag) are computed
  * but no modification is made. The callee must call the DoUnload method to execute
  *	the modifications, or cancel it to be able to start a new graph
  * @param oAllIncludedComponentsAreUnloadable
  *		TRUE if all inserted components are unloadable, FALSE otherwise.
  *   See methods below to get details on unloadable/not unloadable components.
  * @param oIncludeModifiedComponents
  *		Ifat least one component asked to be unloaded is either modified or will
  *   imply the loss of modifications.
  *		See methods below to get details on modified components.
  * @return
  * <dl>
  * <dt><code>S_OK</code>Compute succeeded<dd>
  * <dt><code>S_FALSE</code>No components inserted<dd>
  * <dt><code>E_FAIL</code>Error happened. The current graph is CANCELED to preserve session integrity.<dd>
  * </dl>
  */
  HRESULT Simulate(CATBoolean &oAllIncludedComponentsAreUnloadable, CATBoolean &oIncludeComponentsUnloadableWithModificationLost);

  /**
  *	DoUnload
  * <br><b>Role</b>: Unload all the components if possible.
  * It is not necessary to do a Simulate before this method.
  * The current unload transaction is flushed after a call to this method.
  *	WARNING: the method will succeed even if no inserted components
  * can be unloaded, see Simulate method.
  * WARNING: this method may imply the loss of modifications, see Simulate method.
  *	WARNING: this operation flushes the undo/redo log.
  * @return
  * <dl>
  * <dt><code>S_OK</code>Unload all components that can be unloaded (it can mean no components).<dd>
  * <dt><code>S_FALSE</code>No components inserted<dd>
  * <dt><code>E_FAIL</code>Error happened. The current graph is CANCELED to preserve session integrity.<dd>
  * </dl>
  */
  HRESULT DoUnload();

  /**
  * Cancel
  * <br><b>Role</b>: Cancel the current unload transaction.
  * The user can start a new unlaod transaction by calling again
  * the InsertComponentToUnload methods.
  */
  void Cancel();

  /**
  *	GetNotUnloadableComponents
  * <br><b>Role</b>: Get not unloadable components after a simulation.
  * @param oNotUnloadableComponents
  *		the components that will not be unloaded
  * @return
  * <dl>
  * <dt><code>S_OK</code>succeeded<dd>
  * <dt><code>S_FALSE</code>No components inserted<dd>
  * <dt><code>E_FAIL</code>Simulate has not already been done or error happened<dd>
  * </dl>
  */
  HRESULT GetNotUnloadableComponents(CATOmxList<CATIPLMComponent>  & oNotUnloadableComponents) const;

  /**
  *	GetUnloadableComponents
  * <br><b>Role</b>: Get unloadable components after a simulation.
  * @param oUnloadableComponents
  *		the components that will be unloaded
  * @return
  * <dl>
  * <dt><code>S_OK</code>succeeded<dd>
  * <dt><code>S_FALSE</code>No components inserted<dd>
  * <dt><code>E_FAIL</code>Simulate has not already been done or error happened<dd>
  * </dl>
  */
  HRESULT GetUnloadableComponents(CATOmxList<CATIPLMComponent>  & oUnloadableComponents) const;

private:
  friend class CATOxiLifeCycle;
  CATOmxSR<CATPLMUnloadManager> _Manager;

  CATPLMUnloadEngine(CATPLMUnloadEngine&);
  CATPLMUnloadEngine& operator=(CATPLMUnloadEngine&);
};

#endif
