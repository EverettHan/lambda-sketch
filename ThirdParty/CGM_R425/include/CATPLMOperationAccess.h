/* -*-c++-*- */
#ifndef CATPLMOperationAccess_H
#define CATPLMOperationAccess_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMOperationAccess"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMOperationAccess
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATOmxSR.h"
#include "CATPLMOperationContext.h"
#include "CATIAV5Level.h"
#include "CATPLMID.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATPLMQueryEngineProgress.h"
#include "CATPLMOperationInput.h"
#include "CATPLMOperationInputs.h"
#include "CATPLMOperationBehavior.h"
#include "CATOmxCxxPortability.h"

class CATPLMLoadingSpec;
class CATPLMLoadingLevels;
class CATIPLMQueryFilter;
class CATIAdpErrorMonitor;
class CATPLMQueryEngineCB;
class CATPLMOperationKey;

/**
* An Operation Context is a named log of high level query operations performed on a provider and producing a result.
* For exemple, when using the "Session" (use OC_Session) Operation Context, the produced result will be PLM objects (PC2)
* and occurrences (PLMOccurrences) loaded in session (CATIA3D Tos).
* Operations are designed to be close to UI capabilities, such as:
*   -Loading a root PLMID and all the necessary graph of objects to perform applicative scenarii (using LoadNetwork method).
*   -Enrich a pre existing session with a new consistent set of objects (using LoadNetwork method).
*   -Enrich a pre existing session by mutating objects state (using LoadBranch).
*   -More to come.
* As a consequence, each operations are identified using a key (CATPLMOperationKey) identifying a pre-existing root
* occurrence, root reference. In case you want to perform a brand new list of operations, use an empty key.
* Operation context is designed to be runned asynchronously, an end callback must be provided.
*
* Sample: To construct a filtered Explore Session from a root product:
*   CATPLMID plmid_rootPRODUCT = ...;
*   CATPLMQueryEngineCB *myCallback = ...;
*   CATIAdpErrorMonitor *errorMonitor = ...;
*   CATIPLMQueryFilter *myAttributeFilter = ...;
*   CATPLMOperationKey newKey;
*   CATOmxSR<CATPLMOperationAccess> srSessionContext = CATPLMOperationAccess::FactoryOA(newKey, OC_Session);
*   if (srSessionContext) {
*       CATPLMLoadingSpec spec = CATPLMLoadingSpec::Factory(LS_Explore);
*       CATAssert(SUCCEEDED(srSessionContext->ApplyFilter(myAttributeFilter)));
*       CATAssert(SUCCEEDED(srSessionContext->LoadNetwork(plmid_rootPRODUCT, spec)));
*
*       HRESULT rc = srSessionContext->Commit(myCallback, errorMonitor);
*       if (rc == PLMOC_S_ASYNC_QUERY_STARTED) {
*           ...;
*       }
*       else if (rc == PLMOC_S_SYNC_QUERY_STARTED) {
*           ...;
*       }
*
*   }
*/
class ExportedByCATPLMModelBuilder CATPLMOperationAccess : public CATBaseUnknown
{
  CATDeclareClass;

public:

  /**
   * Get a named operation context- DO NOT USE - DEPRECATED
   * As of today, only "Session" Operation Context is supported, designed to contruct a valide Session.
   * @param iKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
   * @param iProfileContext
   *    Name of the Operation Context.
   * @return CATBaseUnknown#Release
   *    Operation Context to work with.
   */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent FactoryOA method.")
    static CATPLMOperationAccess* Factory(const CATPLMOperationKey& iKey,
      CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);
#else
  static CATPLMOperationAccess* Factory(const CATPLMOperationKey& iKey,
    CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);
#endif

  /**
   * Get a named operation context.
   * As of today, only "Session" Operation Context is supported, designed to contruct a valide Session.
   * @param iKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
   * @param iProfileContext
   *    Name of the Operation Context.
   * @return
   *    Operation Context to work with.
   */
  static CATOmxSR<CATPLMOperationAccess> FactoryOA(const CATPLMOperationKey& iKey,
    CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);

  CATPLMOperationAccess(const CATPLMOperationAccess&) = delete;
  CATPLMOperationAccess(CATPLMOperationAccess&&) = delete;

  CATPLMOperationAccess& operator=(const CATPLMOperationAccess&) = delete;
  CATPLMOperationAccess& operator=(CATPLMOperationAccess&&) = delete;

  /**
  * Get the key associated to the Operation Handler.
  * @return
  *    The key.
  */
  const CATPLMOperationKey& GetKey() const;

  /**
  * Log the loading of a given reference and all the necessary graph relativly to an operation key.
  * Log Optimization:
  *    Operation is considered to be useless if it exists an other previously added Operation (prevOp) verifying
  *    this condition: c1 & c2 & c3 & c4 & ((c5 & c7 & c8) | (c6 & c9) | (c6 & c10 & c11))
  *    List of conditions:
  *       -c1 : They share the same Operation Key.
  *       -c2 : They are of the same type (LoadNetwork Operation).
  *       -c3 : No ApplyFilter has been performed meantime.
  *       -c4 : They share the exact same profile.
  *       -c5 : Their Index specifications (query type, density, used PLMIDs, ...) are identical.
  *       -c6 : Every input path (iInput) fully includes an input path of prevOp
  *       -c7 : Every input path (iInput) is identical to an input path of prevOp
  *       -c8 : They share the exact same Levels specifications (iSpec)
  *       -c9 : prevOp is asking for an Expand All in Full mode
  *       -c10: prevOp is asking for an Expand All if Navigation mode
  *       -c11: iSpec is NOT asking anything in Full mode
  * @param iInput
  *    PLMID identifying the root reference to load.
  *    May be a complex PLMID, identifying an occurrence path (Ref/Inst-Ref/...).
  * @param iSpec
  *    Specification used to load the reference and all it's associated graph.
  *    @see CATPLMLoadingSpec
  * @param iBehavior
  *    Behaviors of the added operation.
  *    @see CATPLMOperationBehavior
  * @return
  *    S_OK                     : Operation has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT LoadNetwork(const CATPLMOperationInput& iInput, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable);

  /**
  * Log the loading of a given branch relativly to an operation key.
  * Log Optimization:
  *    Operation is never considered to be useless
  * @param iBranch
  *    Complex plmid identifying the branch path to load with the discipline
  *    of its last component if available, wrapped in a CATPLMOperationInput.
  * @param iSpec
  *    Specification used to load the branch.
  *    @see CATPLMLoadingSpec
  * @param iEndOfPath
  *    Specification if end of path needs to be expanded or not.
  * @param iBehavior
  *    Behaviors of the added operation.
  *    @see CATPLMOperationBehavior
  * @return
  *    S_OK                     : Operation has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT LoadBranch(const CATPLMOperationInput& iBranch, const CATPLMLoadingSpec& iSpec, int iEndOfPath = 0, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable);

  /**
  * Log the loading of the pointed objects of a given one relativly to an operation key.
  * Log Optimization:
  *    Operation is never considered to be useless
  * @param iPointing
  *    Object pointing to other objects (through SRs).
  * @param iSpec
  *    Specification used to load the pointed objects.
  *    @see CATPLMLoadingSpec
  * @param iBehavior
  *    Behaviors of the added operation.
  *    @see CATPLMOperationBehavior
  * @return
  *    S_OK                     : Operation has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT LoadPointed(const CATPLMOperationInput& iPointing, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable);

  /**
  * Enrich existing objects by adding an attribute on them or to one of there extension.
  * Log Optimization:
  *    Operation is never considered to be useless
  * @param iObjects
  *    Objects to enrich.
  * @param iAttributes
  *    Attributes to add to iObjects.
  *    If empty and iExtension is valuated, all attributes of this extension are loaded.
  * @param iExtensions
  *    Optional, extensions to add.
  * @return
  *    S_OK                     : Operation has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_FAIL: Otherwise.
  */
  virtual HRESULT EnrichObjects(const CATPLMOperationInputs& iObjects,
    const CATOmxArray<CATOmxKeyString>& iAttributes,
    const CATOmxArray<CATOmxKeyString>& iExtensions);

  /**
  * Log the application of a query filter relativly to an operation key.
  * The filter will e used with all LoadNetwork operations associated to the same key.
  * Log Optimization:
  *    Operation breaks LoadNetwork optimization. See LoadNetwork
  * @param iFilter
  *    Query filter to be used (attribute filter, config, volume, ...).
  *    Explicit filters (add and remove) are now supported
  * @param iBehavior
  *    Behaviors of the added operation.
  *    @see CATPLMOperationBehavior
  * @return
  *    S_OK                     : Operation has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_FAIL: Otherwise.
  */
  virtual HRESULT ApplyFilter(CATIPLMQueryFilter* iFilter, const CATPLMOperationBehavior& iBehavior = CATPLMOCGraphFilterMode::Merge, CATBoolean iUnloadPVSIfExisting = TRUE);

  /**
  * Log a break point in the execution log relatively to an operation key.
  *    Previsouly logged operations won't be taken into account anymore for log optimization.
  * @return
  *    S_OK                     : Operations has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT BreakLog();

  /**
  * Log the removal of a root occurrence or a reference.
  *    To be called when it is no more used and can be safely unloaded.
  *    Their associated logged operations will NOT be removed from session log and the session log will NOT be broken.
  * @return
  *    S_OK                     : Operations has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT RemoveRoot(const CATPLMID& iPlmid, const CATPLMOperationBehavior& iBehavior = CATPLMOCGraphFilterMode::Merge);

  /**
  * Log the explicit removal of an occurrence.
  *    To be called when it is no more used and can be safely unloaded.
  * @return
  *    S_OK                     : Operations has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT RemoveBranch(const CATPLMID& iPlmid, const CATPLMOperationBehavior& iBehavior = CATPLMOCGraphFilterMode::Merge);

  /**
  * Log the loading of a given reference in the context of another one.
  * @param iLoadInContextTarget
  *    Specification if the Expand query must be made on the index or on
  *    the database. If query on index is specified, if the expand query fails
  *    no expand query on database will be made …
  * @param iInput
  *    PLMID identifying the reference to load with its discipline if available.
  * @param iContext
  *    PLMID identifying the context reference in which iPLMID will be loaded.
  * @param iSpec
  *    Specification used to load the reference and all it's associated graph.
  *    @see CATPLMLoadingSpec
  * @param iBehavior
  *    Behaviors of the added operation.
  *    @see CATPLMOperationBehavior
  * @return
  *    S_OK                     : Operation has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT LoadInContext(CATPLMLoadInContextTarget iLoadInContextTarget, const CATPLMOperationInput& iInput, const CATPLMID& iContext, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable);

  /**
  * Log the loading of all operations allready validated in a sandbox.
  * @see CATPLMOperationSandbox
  * @param iSandbox
  *    Validated operations from iSandbox will be logged in the context.
  * @return
  *    S_OK                     : Operations have been logged correctly.
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT LoadSandbox(CATPLMOperationSandbox* iSandbox);

  /**
  * Log the loading of all operations allready validated in a sandbox.
  * @see CATPLMOperationSandbox
  * @param iSandbox
  *    Validated operations from iSandbox will be logged in the context.
  * @param iSpec
  *    Specification used to load the reference and all it's associated graph.
  *    This parameter is only used to deduce targeted selective mode of representations.
  *    Information which has been lost when importing all logged operations.
  *    @see CATPLMLoadingSpec

  * @return
  *    S_OK                     : Operations have been logged correctly.
  *    E_FAIL                   : Otherwise.
  */
  virtual HRESULT LoadSandbox(CATPLMOperationSandbox* iSandbox, const CATPLMLoadingSpec& iSpec);

  /**
  * Execute all the previously logged operations relativly to a given key.
  * Execution is started by default asynchronously. But depending on the connected provider,
  * the OS the application is started on, the resources available at this time, it may
  * be started synchronously.
  * Whatever the execution mode (asynchronous/synchronous), a callback is mandatory
  * and triggered on CATPLMQueryEngineCB::Notify at the end of the process.
  * @param iCallback
  *    Callback that will be triggered at the end of operations execution.
  *    Providing a callback is mandatory.
  * @param iError
  *    Error monitor that will be used to log erros during the execution process.
  *    CATPLMQueryEngineCB::Notify will give back this same Error monitor.
  *    if NULL a brand new one is created and provided to CATPLMQueryEngineCB::Notify.
  *    @see CATPLMQueryEngineCB
  * @return
  *    PLMOC_S_ASYNC_QUERY_STARTED: Operations are started asynchronously.
  *    PLMOC_S_SYNC_QUERY_STARTED : Operations are started synchronously.
  *    PLMOC_S_PENDING_OPERATIONS : There is some Operations currently executed. Logged operations will be executed later.
  *    E_ACCESSDENIED             : Operations are not authorized for the applications associated to input plmids.
  *    E_FAIL                     : Operations are not executed, callback is not triggered.
  */
  HRESULT Commit(CATPLMQueryEngineCB* iCallback, CATIAdpErrorMonitor* iError);

  /**
  * Execute all the previously logged operations relativly to a given key.
  * Execution is started by default asynchronously. But depending on the connected provider,
  * the OS the application is started on, the resources available at this time, it may
  * be started synchronously.
  * Whatever the execution mode (asynchronous/synchronous), a callback is mandatory
  * and triggered on CATPLMQueryEngineCB::Notify at the end of the process.
  * @param iCallback
  *    Callback that will be triggered at the end of operations execution.
  *    Providing a callback is mandatory.
  * @param iError
  *    Error monitor that will be used to log erros during the execution process.
  *    CATPLMQueryEngineCB::Notify will give back this same Error monitor.
  *    if NULL a brand new one is created and provided to CATPLMQueryEngineCB::Notify.
  *    @see CATPLMQueryEngineCB
  * @param oProgress [out, CATBaseUnknown#Release]
  *    Give access to progression information of the entire process.
  *    @see CATPLMQueryEngineProgress
  * @param iSkipStreamsDownload
  *    Specifies whether the stream download should be skipped (USE WITH CARE !!)
  * @param iSkipOpenQuery
  *    Specifies whether the open query should be skipped (USE WITH CARE !!)
  * @return
  *    PLMOC_S_ASYNC_QUERY_STARTED: Operations are started asynchronously.
  *    PLMOC_S_SYNC_QUERY_STARTED : Operations are started synchronously.
  *    E_ACCESSDENIED             : Operations are not authorized for the applications associated to input plmids.
  *    E_FAIL                     : Operations are not executed, callback is not triggered.
  */
  HRESULT Commit(CATPLMQueryEngineCB* iCallback,
    CATIAdpErrorMonitor* iError,
    CATPLMQueryEngineProgress*& oProgress,
    CATBoolean iSkipStreamsDownload = FALSE,
    CATBoolean iSkipOpenQuery = FALSE);

  /**
  * Interrupt a running list of operations for a given key, in case it has been started asynchronously.
  * @return
  *    S_OK  : Operations are interrupted.
  *    E_FAIL: Otherwise.
  */
  virtual HRESULT Interrupt();

  /**
 * Get the list of associated (or created) root objects (occurrences if applicable, refrences if not)
 * at the end of operations execution.
 * To be used when triggered on CATPLMQueryEngineCB::Notify.
 * @return
 *    S_OK  : Getting the list is ok.
 *    E_FAIL: Otherwise.
 */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent GetResults method.")
    virtual HRESULT GetResults(CATListValCATBaseUnknown_var& oResults) const;
#else
  virtual HRESULT GetResults(CATListValCATBaseUnknown_var& oResults) const;
#endif

  /**
    * Get the set of associated (or created) root objects (occurrences if applicable, refrences if not)
    * at the end of operations execution.
    * To be used when triggered on CATPLMQueryEngineCB::Notify.
    * @return
    *    S_OK  : Getting the set is ok.
    *    E_FAIL: Otherwise.
    */
  virtual HRESULT GetResults(CATPLMCBUOrderedSet& oResults) const;

  /**
  * To be used when a root occurrence or a reference and their associated logged operations
  * are no longer necessary and can be unloaded, if possible.
  * at the end of operations execution.
  * @return
  *    S_OK  : Unload is successfull.
  *    E_FAIL: Otherwise.
  */
  virtual HRESULT Unload();

  ULONG __stdcall Release();
  ULONG __stdcall AddRef();

protected:
  CATPLMOperationKey m_key;
  CATOmxSR<CATPLMOperationContext> m_context;

  friend class CATPLMOperationContext;
  /**
  * Log the loading of a given branch relativly to an operation key.
  * This version also creates occurrences.
  * This is an equivalent of the old BSM "InsertBranch"
  * It should stay private and not directly be exposed: it can be used to reconstruct
  * a session without knowing the specs...
  * Log Optimization:
  *    Operation is never considered to be useless
  * @param iBranch
  *    List of PLMIDs identifying the branch path to load.
  * @param iSpec
  *    Specification used to load the branch.
  *    @see CATPLMLoadingSpec
  * @param iEndOfPath
  *    Specification if end of path needs to be expanded or not.
  * @param iBehavior
  *    Behaviors of the added operation.
  *    @see CATPLMOperationBehavior
  * @return
  *    S_OK                     : Operation has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
  *    E_FAIL                   : Otherwise.
  */
  //HRESULT InsertBranch(const CATPLMOperationInput &iBranch, const CATPLMLoadingSpec &iSpec, int iEndOfPath, const CATPLMOperationBehavior &iBehavior=CATPLMOCFiltering_Enable);

  virtual ~CATPLMOperationAccess();
  CATPLMOperationAccess(CATPLMOperationContext*, const CATPLMOperationKey& iKey);

};
#endif
