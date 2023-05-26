#ifndef CATOxStreamDescriptorsMediator_H 
#define CATOxStreamDescriptorsMediator_H

/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                     999
#define CATPLMTos                            AuthorizedModule
#define CATOmbSelectiveLoading               AuthorizedModule
#define CATPLMTosStream                      AuthorizedModule
#define AC0XXLNK                             AuthorizedModule
#define CATOmbConverter                      AuthorizedModule
#define CATOmbImportExport                   AuthorizedModule
#define CATOmbRCAEngine                      AuthorizedModule
#define CATOmbSwitchEngine                   AuthorizedModule
#define SelectiveLoadingTST_RepRefTSTImpl    AuthorizedModule
#define CATPLMLog                            AuthorizedModule
#define CATPLMTosPending                     AuthorizedModule
#define CATOmbDebugLink                      AuthorizedModule
#define CATOmbLinkTrader                     AuthorizedModule
#define CATPLMTransaction                    AuthorizedModule
#define CATPLMTosManager                     AuthorizedModule
#define CATPLMIdentification_PLM             AuthorizedModule
#define CATOxiLocalSaveDiffTodoRecovery      AuthorizedModule
#define CATOmbLinks                          AuthorizedModule
#define CATOmbTestLib_PLM                    AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATOxStreamDescriptorsMediator from a non-infrastructure module
@error
#endif
#undef CATPLMTos
#undef CATOmbSelectiveLoading
#undef CATPLMTosStream
#undef AC0XXLNK
#undef CATOmbConverter
#undef CATOmbImportExport
#undef CATOmbRCAEngine
#undef CATOmbSwitchEngine
#undef SelectiveLoadingTST_RepRefTSTImpl
#undef CATPLMLog
#undef CATPLMTosPending
#undef CATOmbDebugLink
#undef CATOmbLinkTrader
#undef CATPLMTransaction
#undef CATPLMTosManager
#undef CATPLMIdentification_PLM
#undef CATOxiLocalSaveDiffTodoRecovery
#undef CATOmbLinks
#undef CATOmbTestLib_PLM

// ----------------------------------------------------------------------------------------------------------------------
#include "ExportedByCATPLMTos.h"
#include "CATComponentId.h"
#include "CATBoolean.h"
#include "CATOxStreamDescriptorsEvents.h"
#include "CATCollec.h"

class CATITosIterator_var;
class CATOxEntity;
class CATBinary;
class CATUuid;
class CATPLMStreamingContext;
class CATPLMStreamingResult;
class CATIPLMRecordRead;
class CATPLMStreamDefinition;
class CATLISTV(CATPLMStreamDefinition);
class CATListValCATPLMStreamDefinition;
class CATUnicodeString;
class CATVVSURLConnection;
class CATITosStreamDescriptorStreamAccess_var;

/**
* Usage is restricted to ObjectModelerBase Framework.
* After instanciation, a mediator defined in ObjectModelerBase and derived from CATOxStreamDescriptorsMediator is automatically aggregated under a cell (component's proxy).
* The mediator life cycle is managed by TOS. A set of overloaded methods allows to communicate between ObjectModelerBase and CATPLMIdentification
* without extra APIs and by an internal way.
* This solution allows to load and manipulate stream descriptor view even if component implementation is not available.
*/
class ExportedByCATPLMTos CATOxStreamDescriptorsMediator
{
public:

  /**
  * Build a CATComponentId handle representation the component owner.
  *
  * @return
  *     The handle.
  */
  CATComponentId GetOwner() const;

  /**
  * Find mediator from component handle.
  *
  * @param iComponentOwner
  *        The mediator's owner.
  * @return
  *        The mediator.
  */
  static CATOxStreamDescriptorsMediator * Search(const CATComponentId & iComponentOwner);
  static CATOxStreamDescriptorsMediator * Search(CATBaseUnknown * iComponentOwner) = delete;

  /**
  * Get iterator providing access to stream descriptors
  *
  * Interfaces to be implemented by stream descriptors :
  *   CATITosStreamDescriptor (basic view)
  *   CATITosStreamDescriptorStreamAccess (specific access for persistency management)
  *
  * @return
  *     The iterator
  */
  virtual CATITosIterator_var GetIterator() = 0;

  /**
  * Serialize internal states for backup.This stream is inbedded into TOS image.
  *
  * @param iBinary
  *      The stream containing necessary informations for restoring previous configuration
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT Serialize(CATBinary & iBinary) = 0;

  /**
  * Deserialize internal states for backup
  * When this method is call, the mediator is still instanciated and SDs definition is available
  *
  * @param iBinary
  *      The stream containing necessary informations for restoring previous configuration
  * @param oLoadMode
  *      The future loading mode for local save
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT Deserialize(const CATBinary & iBinary, CATUnicodeString & oLoadMode) = 0;


  /**
  * Returns the modification status according to LOG level.
  *
  * @param iTodoLevel
  *     The LOG level Global/Differential.
  * @param oIsModified
  *     The modification status.
  * @return
  *     An HRESULT value.
  *     <br><b>Legal values</b>:
  *     <ul>
  *         <li><tt>S_OK</tt> if succeeded.</li>
  *         <li><tt>E_FAIL</tt> if failed.</li>
  *     </ul>
  */
  virtual HRESULT IsModified(CATTosTodoLevel iTodoLevel, CATBoolean & oIsModified) = 0;

  /**
  * Dispatch events to TOS for dirty status delegation (to be overloaded for additional treatments)
  *
  * @param iEvent
  *        Event to be dispatched to TOS
  */
  virtual void DispatchNotification(CATBaseUnknown& iSD);

  /**
  * Restore SDs model as newly created
  */
  virtual HRESULT RestoreAsCreated() = 0;
  /**
  * Restore SDs model as cloned
  */
  virtual HRESULT RestoreAsCloned() = 0;

  /**
  * Force authoring stream to be saved
  *
  * @param iPropagateToComponent
  *        Propagate modification to component and increment Master Stamp.
  */
  virtual HRESULT ForceAuthoringToBeSaved(CATBoolean iPropagateToComponent) = 0;

  /**
  * Asks for a component to stream into a cache its binary view.
  * <br><b>Role:</b>This method enables to stream the data of a component into the cache for a late send to
  * a specific repository.
  * @param iContext [in]
  *   The context the streams must be created for.
  * @param oResult [out]
  *   The result of the streaming operation.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: The stream were succesfully generated.</li>
  *   <li><tt>S_FALSE</tt>: The component has no streams to generate.</li>
  *   <li><tt>E_FAIL</tt>: Failure occured during the treatment.</li>
  *   </ul>
  */
  virtual HRESULT StreamInCache(const CATPLMStreamingContext & iContext, CATPLMStreamingResult & oResult) = 0;

  /**
  * Asks for a component to unstream from a cache its binary view.
  * <br><b>Role:</b>This method enables to unstream the data of a component from the cache
  * @param ihStreamDesc [in]
  * @param iConnection [in]
  *   The context the streams must be created for.
  * @param oResult [out]
  *   The result of the streaming operation.
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>: if succeeded.</li>
  *   <li><tt>E_FAIL</tt>: if failure.</li>
  *   </ul>
  */
  virtual HRESULT UnstreamFromCache(const CATITosStreamDescriptorStreamAccess_var & ihStreamDesc, CATVVSURLConnection * iConnection) = 0;

  /**
  * Acces au mode chargement courant
  *
  * @param oCurrentMode
  *        Mode de chargement courant
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT GetCurrentMode(CATUnicodeString & oCurrentMode) = 0;

  /**
  * Evenement envoyé sur le SDs lors du switch du composant en coquille vide
  * Ce call doit décharger l'authoring ainsi que le modèle de SDs.
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT OnSwitchToEmptyShell() = 0;

  /**
  * Evenement envoyé sur le SDs lors d'une tentative de demontage du modele suite à un echec
  * Ce call doit décharger l'authoring ainsi que le modèle de SDs.
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT BeforeComponentDestroyedWhenTransactionIsAborted() = 0;

  /**
  * Synchronization du modele de SDs
  *
  * @return
  *      S_OK if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  virtual HRESULT Synchronize(const CATLISTV(CATPLMStreamDefinition) & iSDFs) = 0;

  /**
  * Called by TOS when cell is irreversibly clearing
  */
  virtual ~CATOxStreamDescriptorsMediator();

protected:
  /**
  * Automatically reserved under cell (component's proxy) during instanciation
  *
  * @param iComponentOwner
  *        Component owner of the mediator
  */
  CATOxStreamDescriptorsMediator(const CATComponentId & iComponentOwner);

  /**
  * Callback send to mediator when cell (component's proxy) is switch to destroyed
  */
  virtual void OnComponentDestroyed() = 0;

  /**
  * Callback send to mediator when component is imported
  */
  virtual void AfterImported(CATBoolean iIsOK) = 0;

  /**
  * Callback send to mediator when component is locally saved
  *
  * @param iIsOK
  *        TRUE : save operation is successful
  *        FALSE : save operation failure
  */
  virtual void AfterLocallySaved(CATBoolean iIsOK) = 0;

  /**
  * Callback send to mediator when component is saved
  *
  * @param iIsOK
  *        TRUE : save operation is successful
  *        FALSE : save operation failure
  */
  virtual void AfterSaved(CATBoolean iIsOK) = 0;


  /**
  * Callback send to mediator when component is unloaded
  *
  * @param iIsOK
  *        TRUE : save operation is successful
  *        FALSE : save operation failure
  */
  virtual void AfterUnload(CATBoolean iIsOK) = 0;


  /**
  * Reidentify documents if loaded
  *
  * @return
  *    S_OK if everything went right
  *    E_FAIL or any failing return code otherwise
  */
  virtual HRESULT Reidentify() = 0;

  /**
  * Returns S_OK if stream descriptors can be "synchronized" without unloading/destroying everything.
  */
  virtual HRESULT CanSynchronizeWithoutUnloadingSDs(const CATListValCATPLMStreamDefinition& iSDFs) = 0;

private:

  CATOxEntity* _Entity;

private:

  /* forbidden operations */
  CATOxStreamDescriptorsMediator(CATOxStreamDescriptorsMediator &) = delete;
  CATOxStreamDescriptorsMediator& operator=(CATOxStreamDescriptorsMediator&) = delete;

  friend class CATOxEntity;
  friend class CATOxJanus;
  friend class CATOxSpace;
  friend class CATOxEntityTransferInformation;
  friend class CATOxSessionUpgrade_IMPORT_ACTIVATED;
};

#endif
