#ifndef CATPLMSessionManager_H
#define CATPLMSessionManager_H
/* -*-c++-*- */
/**
 * @level Private
 * @usage U1
 */
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                  999
#define CATPLMTos                         AuthorizedModule
#define CATOxiSessionManager              AuthorizedModule
#define CATPLMTosManager                  AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMSynchronization             AuthorizedModule
#define CATPLMCollabMgt                   AuthorizedModule
#define CATPLMPspProviderImpl             AuthorizedModule
#define CATPLMImportMgt                   AuthorizedModule
#define CATOxiMinorMajor                  AuthorizedModule
#define CATPLMModelBuilder                AuthorizedModule
#define CATOxiRepoPrivilege               AuthorizedModule
#define CATOxiStatutRemote                AuthorizedModule
#define CATOxiStatutRemoteAttrLink        AuthorizedModule
#define CATPLMIdentification_PLM          AuthorizedModule
#define CATOxiTOSPCS                      AuthorizedModule
#define CATOxiLifeCycle                   AuthorizedModule
#define CATOxiAttributeExtension          AuthorizedModule
#define CATOxiTOSLight                    AuthorizedModule
#define TransitionEngine                  AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMSessionManager from a non-infrastructure module
@error
#endif
#undef CATPLMTos
#undef CATOxiSessionManager
#undef CATPLMTosManager
#undef CATPLMIntegration
#undef CATPLMSynchronization
#undef CATPLMCollabMgt
#undef CATPLMPspProviderImpl
#undef CATPLMImportMgt
#undef CATOxiMinorMajor
#undef CATPLMModelBuilder
#undef CATOxiRepoPrivilege
#undef CATOxiStatutRemote
#undef CATOxiStatutRemoteAttrLink
#undef CATPLMIdentification_PLM
#undef CATOxiTOSPCS
#undef CATOxiLifeCycle
#undef CATOxiAttributeExtension
#undef CATOxiTOSLight
#undef TransitionEngine
// ----------------------------------------------------------------------------------------------------------------------
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATPLMID.h"
#include "CATOmxOSet.h"
#include "CATOmxSR.h"

class CATComponentId;
class CATOxSessionUpdater;
class CATProxySpace;
class CATIPLMRecordRead;
class CATProxyTransaction;
class CATOxTransaction;
class CATOxSessionManager;
class CATIPLMErrorCollector;
class CATBinary;
class CATIPLMSessionDataSource;
class CATIPLMSelectiveLoadingRuleSet;
class CATPLMBag;
class CATIHydratationEngine;
class CATOmxSharable;


/**
 * Engine managing session updates for :
 *   - Synchronize engine (Refresh)
 *   - Collab engine
 *   - Open engine
 *   - ImportAsNew engine
 *   - Restore engine
 *   - Overload engine
 *
 * Network completion has to be managed by caller.
 * Network consistency is checked by transaction.
 * Use CATTry/CATCatch to manage exceptions:
 *    - the session manager itself can send exceptions (see CATPLMIdentification/CATPLMIdentificationRsc.m/src/resources/msgcatalog/CATPLMTos.CATNls)
 *    - if the session manager catches exceptions it will rethrow them
 *  => in both cases a roll back is done.
 */
class ExportedByCATPLMTos CATPLMSessionManager
{
public:
  /**
  * Creates a session manager for managing session modifications
  *
  * @iTransaction
  *              The transaction describing the type of operation and managing rollback in case of problems
  *
  *                CatPLMTransactionOpen
  *                CatPLMTransactionSynchronize
  *                CatPLMTransactionCollab
  *                CatPLMTransactionImportAsNew
  *                CatPLMTransactionOverload
  *                CatPLMTransactionRestore
  *                CatPLMTransactionDuplicate
  */
  CATPLMSessionManager(const CATProxyTransaction & iTransaction);
  ~CATPLMSessionManager();

  /**
  * Attach a bag for managing life cycle of new imported components if not still managed
  *
  * @param iBag
  *        A bag for managing life of imported components
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  */
  HRESULT AttachBag(CATPLMBag & iBag);

  /**
  *	Attach root components definition
  * <br><b>Role</b>: The given set represent the plmid of the ONLY components
  *	that will be inserted in the bag (see @href AttachBag) during the commit
  *	of the Session Manager. If this method is not called or called with an emty
  * set, an algorithm will insert the roots into the bag.
  *	WARNING: if all references are inserted in the bag, this will prevent those
  *	components from leaving memory, for example in an unload operation. This may
  *	lead to high memory consumption.
  * @param iPLMIDSet
  *		the plmids of the only components to insert in the bag.
  * @return
  * <dl>
  * <dt><code>S_OK</code>if request succeeded.<dd>
  * <dt><code>E_FAIL</code>if request failed.<dd>
  * </dl>
  */
  HRESULT AttachRootComponentsDefinition(const CATOmxOSet<CATPLMID>& iPLMIDSet);

  /**
  * Managing component's selective loading
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  */
  HRESULT AttachSelectiveLoadingRuleSet(CATIPLMSelectiveLoadingRuleSet* iSelectiveLoadingRuleSet);

  /**
  * Attach error collector for managing user reporting
  * NB: only errors raised by the session manager will be thus reported.
  *     Errors catched by the session manager and rethrew will not.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  *      E_ACCESSDENIED : if transaction is not authorized.
  */
  HRESULT AttachErrorCollector(CATIPLMErrorCollector* iErrorCollector);

  /**
  * Attach hydration engine for hydratation phase
  * driven by external application
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  *      E_ACCESSDENIED : if transaction is not authorized.
  */
  HRESULT AttachHydratationEngine(CATIHydratationEngine* iHydratationEngine, CATOmxSharable* iVSESnapshot = NULL);

  /**
  * Load or Replace  a component in session from a data source.
  * This operation is not complete before commit.
  * All components without life cycle management will be unloaded after transaction commit.
  *
  * @param iDataSource
  *        The data source.
  * @param oCID
  *        An handle on the imported object.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  *      E_ACCESSDENIED : if transaction is not authorized.
  */
  HRESULT DelayedImportInSession(CATIPLMSessionDataSource * iDataSource, CATComponentId & oCID);

  /**
  * Load or Replace  a component in session from a data source.
  * This operation is not complete before commit.
  * All components without life cycle management will be unloaded after transaction commit.
  *
  * @param iDataSource
  *        The data source.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  *      E_ACCESSDENIED : if transaction is not authorized.
  */
  HRESULT DelayedImportInSession(CATIPLMSessionDataSource * iDataSource);

  /**
  * Load or Replace  a component in session from a data source.
  * This operation is not complete before commit.
  * All components without life cycle management will be unloaded after transaction commit.
  *
  * @param iRecordRead
  *        The data source.
  * @param oCID
  *        An handle on the imported object.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  *      E_ACCESSDENIED : if transaction is not authorized.
  */
  HRESULT DelayedImportInSession(CATIPLMRecordRead * iRecordRead, CATComponentId & oCID);

  /**
  * Load or Replace  a component in session from a data source.
  * This operation is not complete before commit.
  * All components without life cycle management will be unloaded after transaction commit.
  *
  * @param iRecordRead
  *        The data source.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  *      E_ACCESSDENIED : if transaction is not authorized.
  */
  HRESULT DelayedImportInSession(CATIPLMRecordRead * iRecordRead);

  /**
  * Unload a component from session. Only the component disappear from memory, no impacts on other components.
  * All components without life cycle management will be unloaded after transaction commit.
  *
  * @param iCID
  *        The component to process.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  *      E_ACCESSDENIED : if transaction is not authorized.
  */
  HRESULT DelayedUnloadInSession(const CATComponentId & iCID);

  /**
  * Unload a component from session. Only the component disappear from memory, no impacts on other components.
  * All components without life cycle management will be unloaded after transaction commit.
  *
  * @param iPLMID
  *        The component's identifier to process.
  *
  * @return
  *      S_OK           : if request succeeded.
  *      E_FAIL         : if request failed.
  *      E_ACCESSDENIED : if transaction is not authorized.
  */
  HRESULT DelayedUnloadInSession(const CATPLMID & iPLMID);

  /*
  * The optimist mode is to be used for PCS during an open-only.
  * WARNING: use this only if you know what you are doing.
  */
  void SetOptimistLifecycleControl();
  void EnableSwitchWizard();
  //NOTE: for the next flag...use flags !

  /**
   * Optimization:
   * If you known that you are going to import N objects (through DelayedImportInSession)
   * Call this before, it will allow to preallocate the required tables.
   */
  void Reserve(int iExpectedNumberOfObjects);
private:

  CATOxSessionManager* GetSessionManager();

  CATPLMSessionManager(CATPLMSessionManager&);
  CATPLMSessionManager& operator=(CATPLMSessionManager&);

  CATOxTransaction * _Transaction;
};

#endif
