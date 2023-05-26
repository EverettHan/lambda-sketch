/* -*-c++-*- */
#ifndef CATPLMOperationContext_H
#define CATPLMOperationContext_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMOperationContext"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMOperationContext
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATOmxSR.h"
#include "CATIAV5Level.h"
#include "CATLISTV_CATPLMID.h"
#include "CATPLMID.h"
#include "CATOmxVector.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATPLMQueryEngineProgress.h"
#include "CATPLMOperationInput.h"
#include "CATPLMOperationInputs.h"
#include "CATPLMOperationBehavior.h"
#include "CATPLMQEConstants.h"
#include "CATNotification.h"
#include "CATEventSubscriber.h"
#include "CATEventSubscriberTypedefs.h"
#include "CATOmxOSet.h"
#include "CATOmxCollecManagers.h"
#include "CATPLMCBUOrderedSet.h"

using namespace CATPLMQEConstants;

class CATPLMLoadingDico;
class CATPLMLoadingSpec;
class CATIPLMQueryFilter;
class CATIAdpErrorMonitor;
class CATPLMOperation;
class CATPLMOperationSet;
class CATPLMQueryEngineCB;
class CATPLMOperationKey;
class CATPLMBuilder;
class CATPLMOperationSandbox;
class CATPLMLoadingProfile;

#define FACILITY_PLMOC 0x0086
#define CODE_PLMOC     0x8601
#define PLMOC_S_SYNC_QUERY_STARTED   MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_PLMOC, CODE_PLMOC + 0x00)
#define PLMOC_S_ASYNC_QUERY_STARTED  S_OK
#define PLMOC_S_USELESS_OPERATION    MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_PLMOC, CODE_PLMOC + 0x01)
#define PLMOC_S_PENDING_OPERATIONS   MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_PLMOC, CODE_PLMOC + 0x02)
#define PLMOC_E_PENDING_OPERATIONS   MAKE_HRESULT(SEVERITY_ERROR, FACILITY_PLMOC, CODE_PLMOC + 0x00)

/**
 * Key used to identify a list of operations to perform or allready performed with CATPLMOperationContext.
 */
class ExportedByCATPLMModelBuilder CATPLMOperationKey
{
public:

  /**
   * Constructor.
   */
  CATPLMOperationKey() = default;
  CATPLMOperationKey(const CATPLMOperationKey& iCopy) = default;
  CATPLMOperationKey(CATPLMOperationKey&& iCopy) = default;

  /**
   * Destructor.
   */
  ~CATPLMOperationKey() = default;

  /**
   * Assigns from another key.
   * @param iKey
   *    Key to copy.
   * @return: this key
   */
  CATPLMOperationKey& operator=(const CATPLMOperationKey& iKey) = default;
  CATPLMOperationKey& operator=(CATPLMOperationKey&& iKey) = default;

  /**
   * Tests whether a key is empty or not.
   * @return
   *    TRUE: Is NULL
   *    FALSE: Not NULL
   */
  boolean IsNull() const { return (m_keyId == 0) ? true : false; }

  /**
   * Gets the value associated to this key
   * @return
   *   Key value.
   */
  unsigned int GetKeyValue() const { return m_keyId; }

  /**
   * Compares two operations keys.
   * @param iKey: key to compared with.
   * @return
   *     TRUE: keys are identical
   *    FALSE: otherwise
   */
  CATBoolean operator==(const CATPLMOperationKey& iKey) const { return m_keyId == iKey.m_keyId; }

private:
  friend class CATPLMOperationContext;

  void CreateTemporaryKey()
  {
    if (IsNull())
    {
      static unsigned int key_counter = 0;
      m_keyId = ++key_counter;
    }
  }

  unsigned int               m_keyId{ 0 };

};

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
 *   CATOmxSR<CATPLMOperationContext> srSessionContext(CATPLMOperationContext::GetOC(OC_Session));
 *   if (srSessionContext) {
 *       CATPLMOperationKey newKey;
 *       CATPLMLoadingSpec spec = CATPLMLoadingSpec::Factory(LS_Explore);
 *       CATAssert(SUCCEEDED(srSessionContext->ApplyFilter(newKey, myAttributeFilter)));
 *       CATAssert(SUCCEEDED(srSessionContext->LoadNetwork(newKey, plmid_rootPRODUCT, spec)));
 *
 *       HRESULT rc = srSessionContext->Commit(newKey, myCallback, errorMonitor);
 *       if (rc == PLMOC_S_ASYNC_QUERY_STARTED) {
 *           ...;
 *       }
 *       else if (rc == PLMOC_S_SYNC_QUERY_STARTED) {
 *           ...;
 *       }
 *
 *   }
 */
class ExportedByCATPLMModelBuilder CATPLMOperationContext : public CATBaseUnknown
{
  CATDeclareClass;

public:

  /**
   * Get a named operation context - DO NOT USE - DEPRECATED
   * As of today, only QE_Session Operation Context is supported, designed to contruct a valide Session.
   * @param iProfileContext
   *    Name of the Operation Context.
   * @return CATBaseUnknown#Release
   *    Operation Context to work with.
   */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent GetOC method.")
    static CATPLMOperationContext* Get(CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session)
#else
  static CATPLMOperationContext* Get(CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session)
#endif
  {
    return GetOC(iProfileContext).GiveBack();
  }

  /**
   * Get a named operation context.
   * As of today, only QE_Session Operation Context is supported, designed to contruct a valide Session.
   * @param iProfileContext
   *    Name of the Operation Context.
   * @return
   *    Operation Context to work with.
   */
  static CATOmxSR<CATPLMOperationContext> GetOC(CATPLMQEProfileContext iProfileContext = CATPLMQEProfileContext::QE_Session);

  CATPLMOperationContext(const CATPLMOperationContext&) = delete;
  CATPLMOperationContext(CATPLMOperationContext&&) = delete;

  CATPLMOperationContext& operator=(const CATPLMOperationContext&) = delete;
  CATPLMOperationContext& operator=(CATPLMOperationContext&&) = delete;

  /**
  * Log the loading of a given reference and all the necessary graph relativly to an operation key.
  * Log Optimization:
  *    Operation is considered to be useless if it exists an other previously added Operation (prevOp) verifying
  *    this condition: c1 & c2 & c3 & c4 & ((c5 & c7 & c8) | (c6 & c9) | (c6 & c10 & c12) | (c5 && c7 & c11 & c12) ) && c13
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
  *       -c11: prevOp has greater expand depth in Navigation mode.
  *       -c12: iSpec is NOT asking anything in Full mode
  *       -c13: iSpec has same option list
  * @param ioKey
  *    Key identifying the list of operations.
  *    May be empty in case of creating a brand new occurrence graph.
  * @param iInput
   *    PLMID identifying the root reference to load.
   *    May be a complex PLMID, identifying an occurrence path (Ref/Inst-Ref/...).
   * @param iSpec
   *    Specification used to load the reference and all it's associated graph.
   *    @see CATPLMLoadingSpec
   * @param iBehavior
   *    Behaviors of the added operation.
   *    @see CATPLMOperationBehavior
   * @param iCompactable
   *    Specifies whether the operation should compacted with others, if possible.
   * @return
   *    S_OK                     : Operation has been logged correctly.
   *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
   *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
   *    E_FAIL                   : Otherwise.
   */
  HRESULT LoadNetwork(CATPLMOperationKey& ioKey,
    const CATPLMOperationInput& iInput,
    const CATPLMLoadingSpec& iSpec,
    const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable,
    CATBoolean iCompactable = TRUE);

  /**
   * Log the loading of a given branch relativly to an operation key.
   * Log Optimization:
   *    Operation is never considered to be useless
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
   * @param iBranch
   *    Complex plmid identifying the branch path to load with the discipline
   *    of its last component if available, wrapped in a CATPLMOperationInput.
   * @param iSpec
   *    Specification used to load the branch.
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
  HRESULT LoadBranch(CATPLMOperationKey& ioKey,
    const CATPLMOperationInput& iBranch,
    const CATPLMLoadingSpec& iSpec,
    const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable);


  /**
   * Log the loading of a given branch relativly to an operation key.
   * Log Optimization:
   *    Operation is never considered to be useless
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
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
  HRESULT LoadBranch(CATPLMOperationKey& ioKey,
    const CATPLMOperationInput& iBranch,
    const CATPLMLoadingSpec& iSpec,
    int iEndOfPath,
    const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable);

  /**
   * Log the loading of the pointed objects of a given one relativly to an operation key.
   * Log Optimization:
   *    Operation is never considered to be useless
   * @param ioKey
   *    Key identifying the list of operations.
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
  HRESULT LoadPointed(CATPLMOperationKey& ioKey, const CATPLMOperationInput& iPointing, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable);

  /**
   * Enrich existing objects by adding an attribute on them or to one of there extension - DO NOT USE - DEPRECATED
   * Log Optimization:
   *    Operation is never considered to be useless
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
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
  HRESULT EnrichObjects(CATPLMOperationKey& ioKey,
    const CATPLMOperationInputs& iObjects,
    CATListOfCATString& iAttributes,
    CATListOfCATString* iExtensions = NULL);

  /**
   * Enrich existing objects by adding an attribute on them or to one of there extension
   * Log Optimization:
   *    Operation is never considered to be useless
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
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
  HRESULT EnrichObjects(CATPLMOperationKey& ioKey,
    const CATPLMOperationInputs& iObjects,
    const CATOmxArray<CATOmxKeyString>& iAttributes,
    const CATOmxArray<CATOmxKeyString>& iExtensions);

  /**
   * Log the application of a query filter relativly to an operation key.
   * The filter will e used with all LoadNetwork operations associated to the same key.
   * Log Optimization:
   *    Operation breaks LoadNetwork optimization. See LoadNetwork
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
   * @param iFilter
   *    Query filter to be used (attribute filter, config, volume, ...).
   *    Explicit filters (add and remove) are now supported
   * @param iBehavior
   *    Behaviors of the added operation.
   *    @see CATPLMOperationBehavior
   * @param iUnloadPVSIfExisting
     *    Specifies whether previously loaded pvs root should be unloaded and removed from context
   * @return
   *    S_OK                     : Operation has been logged correctly.
   *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
   *    E_FAIL: Otherwise.
   */
  HRESULT ApplyFilter(CATPLMOperationKey& ioKey, CATIPLMQueryFilter* iFilter, const CATPLMOperationBehavior& iBehavior = CATPLMOCGraphFilterMode::Merge, CATBoolean iUnloadPVSIfExisting = TRUE);

  /**
  * Log a break point in the execution log relatively to an operation key.
  *    Previsouly logged operations won't be taken into account anymore for log optimization.
  * @return
  *    S_OK                     : Operations has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_FAIL                   : Otherwise.
  */
  HRESULT BreakLog(CATPLMOperationKey& ioKey);

  /**
  * Log the removal of a root occurrence or a reference.
  *    To be called when it is no more used and can be safely unloaded.
  *    Their associated logged operations will NOT be removed from session log and the session log will NOT be broken.
  * @return
  *    S_OK                     : Operations has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_FAIL                   : Otherwise.
  */
  HRESULT RemoveRoot(CATPLMOperationKey& ioKey, const CATPLMOperationInput& iRoot, const CATPLMOperationBehavior& iBehavior = CATPLMOCGraphFilterMode::Merge);

  /**
  * Log the explicit removal of an occurrence.
  *    To be called when it is no more used and can be safely unloaded.
  * @param ioKey
  *    Key identifying the list of operations.
  * @param iBranch
  *    The path of instances representing the occurrence to be removed.
  *    Intermediate refs have to be given in the selected path (i.e: ref-inst-ref).
  * @param iBehavior
  *    Behaviors of the added operation.
  *    @see CATPLMOperationBehavior
  * @return
  *    S_OK                     : Operations has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_FAIL                   : Otherwise.
  */
  HRESULT RemoveBranch(CATPLMOperationKey& ioKey, const CATPLMOperationInput& iBranch, const CATPLMOperationBehavior& iBehavior = CATPLMOCGraphFilterMode::Merge);

#ifndef CATIAR424
  /**
   * Log the loading of a given reference in the context of another one.
   * @param ioKey
   *    Key identifying the list of operations.
   *    May be empty in case of creating a brand new occurrence graph.
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
   * @param iEndOfPath
   *    Specification if end of path needs to be expanded or not.
   * @param iBuildOccurrences
   *    Specification if occurrences network should be updated or not.
   * @return
   *    S_OK                     : Operation has been logged correctly.
   *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
   *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
   *    E_FAIL                   : Otherwise.
   */
  HRESULT LoadInContext(CATPLMOperationKey& ioKey, const CATPLMOperationInput& iInput, const CATPLMID& iContext, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable, CATBoolean iEndOfPath = TRUE, CATBoolean iBuildOccurrences = TRUE);
#endif

  /**
  * Log the loading of a given reference in the context of another one.
  * @param iLoadInContextTarget
  *    Specification if the Expand query must be made on the index or on
  *    the database. If query on index is specified, if the expand query fails
  *    no expand query on database will be made …
  * @param ioKey
  *    Key identifying the list of operations.
  *    May be empty in case of creating a brand new occurrence graph.
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
  * @param iEndOfPath
  *    Specification if end of path needs to be expanded or not.
  * @param iBuildOccurrences
  *    Specification if occurrences network should be updated or not.
  * @return
  *    S_OK                     : Operation has been logged correctly.
  *    PLMOC_S_USELESS_OPERATION: Operation is useless (see Log Optimization)
  *    E_ACCESSDENIED           : Operation is not authorized for the application associated to iPLMID
  *    E_FAIL                   : Otherwise.
  */
  HRESULT LoadInContext(CATPLMLoadInContextTarget iLoadInContextTarget, CATPLMOperationKey& ioKey, const CATPLMOperationInput& iInput, const CATPLMID& iContext, const CATPLMLoadingSpec& iSpec, const CATPLMOperationBehavior& iBehavior = CATPLMOCFiltering::Enable, CATBoolean iEndOfPath = TRUE, CATBoolean iBuildOccurrences = TRUE);

  /**
 * Log the loading of all operations allready validated in a sandbox.
 * @see CATPLMOperationSandbox
 * @param ioKey
 *    Key identifying the list of operations inside the context.
 *    May be empty in case of creating a brand new occurrence graph.
 * @param iSandbox
 *    Validated operations from iSandbox will be logged in the context.
 * @return
 *    S_OK                     : Operations have been logged correctly.
 *    E_FAIL                   : Otherwise.
 */
  HRESULT LoadSandbox(CATPLMOperationKey& ioKey, CATPLMOperationSandbox* iSandbox);

  /**
   * Log the loading of all operations allready validated in a sandbox.
   * @see CATPLMOperationSandbox
   * @param ioKey
   *    Key identifying the list of operations inside the context.
   *    May be empty in case of creating a brand new occurrence graph.
   * @param iSandbox
   *    Validated operations from iSandbox will be logged in the context.
   * @param iLevels
   *    Specification used to load the reference and all it's associated graph.
   *    This parameter is only used to deduce targeted selective mode of representations.
   *    Information which has been lost when importing all logged operations.
   *    @see CATPLMLoadingSpec
   * @return
   *    S_OK                     : Operations have been logged correctly.
   *    E_FAIL                   : Otherwise.
   */
  HRESULT LoadSandbox(CATPLMOperationKey& ioKey, CATPLMOperationSandbox* iSandbox, const CATPLMLoadingSpec& iSpec);

  /**
   * Execute all the previously logged operations relativly to a given key.
   * Execution is started by default asynchronously. But depending on the connected provider,
   * the OS the application is started on, the resources available at this time, it may
   * be started synchronously.
   * Whatever the execution mode (asynchronous/synchronous), a callback is mandatory
   * and triggered on CATPLMQueryEngineCB::Notify at the end of the process.
   * @param iKey
   *    Key identifying a list of previously added operations.
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
  HRESULT Commit(const CATPLMOperationKey& iKey,
    CATPLMQueryEngineCB* iCallback,
    CATIAdpErrorMonitor* iError);

  /**
   * Execute all the previously logged operations relativly to a given key.
   * Execution is started by default asynchronously. But depending on the connected provider,
   * the OS the application is started on, the resources available at this time, it may
   * be started synchronously.
   * Whatever the execution mode (asynchronous/synchronous), a callback is mandatory
   * and triggered on CATPLMQueryEngineCB::Notify at the end of the process.
   * @param iKey
   *    Key identifying a list of previously added operations.
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
  HRESULT Commit(const CATPLMOperationKey& iKey,
    CATPLMQueryEngineCB* iCallback,
    CATIAdpErrorMonitor* iError,
    CATPLMQueryEngineProgress*& oProgress,
    CATBoolean iSkipStreamsDownload = FALSE,
    CATBoolean iSkipOpenQuery = FALSE);

  /**
   * Interrupt a running list of operations for a given key, in case it has been started asynchronously.
   * @param iKey
   *    Key identifying a list of running operations.
   * @return
   *    S_OK  : Operations are interrupted.
   *    E_FAIL: Otherwise.
   */
  HRESULT Interrupt(const CATPLMOperationKey& iKey);

  /**
   * Get the list of associated (or created) root objects (occurrences if applicable, refrences if not)
   * at the end of operations execution.
   * To be used when triggered on CATPLMQueryEngineCB::Notify.
   * @param iKey
   *    Key identifying a list of operations.
   * @return
   *    S_OK  : Getting the list is ok.
   *    E_FAIL: Otherwise.
   */
#ifdef CATIAR425
  OMX_DEPRECATED("This method is deprecated. Kindly use the equivalent GetResults method.")
    HRESULT GetResults(const CATPLMOperationKey& iKey, CATListValCATBaseUnknown_var& oResults) const;
#else
  HRESULT GetResults(const CATPLMOperationKey& iKey, CATListValCATBaseUnknown_var& oResults) const;
#endif

  /**
    * Get the set of associated (or created) root objects (occurrences if applicable, refrences if not)
    * at the end of operations execution.
    * To be used when triggered on CATPLMQueryEngineCB::Notify.
    * @param iKey
    *    Key identifying a list of operations.
    * @return
    *    S_OK  : Getting the set is ok.
    *    E_FAIL: Otherwise.
    */
  HRESULT GetResults(const CATPLMOperationKey& iKey, CATPLMCBUOrderedSet& oResults) const;


  /**
   * To be used when a root occurrence or a reference and their associated logged operations
   * are no longer necessary and can be unloaded, if possible.
   * at the end of operations execution.
   * @param iKey
   *    Key identifying a root occurrence or a root reference.
   * @return
   *    S_OK  : Unload is successfull.
   *    E_FAIL: Otherwise.
   */
  HRESULT Unload(const CATPLMOperationKey& iKey);

  virtual ULONG __stdcall Release() override final;
  virtual ULONG __stdcall AddRef() override final;

  HRESULT Stream(const CATPLMOperationKey& iKey, const char* iFilePath, DebugMode iDebugMode);
  HRESULT Unstream(CATPLMOperationKey& ioKey, const char* iFilePath);

  CATPLMQEProfileContext GetProfileContext() const { return m_profileContext; }

  // temporary : DO NOT USE !!
  // As you can see .. very usefull method !
#ifdef CATIAR425  
  OMX_DEPRECATED("This method is deprecated and no more implemented.")
    static void FlushAll() {}
#else
  static void FlushAll() {}
#endif

protected:
  friend class CATPLMOperationSandbox;

  CATOmxSR<CATPLMOperationSet> GetOperationSet(const CATPLMOperationKey& iKey) const;
  CATOmxSR<CATPLMOperationSet> GetOrCreateOperationSet(CATPLMOperationKey& iKey);

  virtual HRESULT LogOperation(CATPLMOperationKey& ioKey, CATOmxSR<CATPLMOperation> ioOperation, boolean iLogOnlyValid = false, boolean iOptimizeLog = false);

  void SetSandbox(CATBoolean iIsSandbox) { m_sandbox = iIsSandbox; }

private:

  friend void g_ClearStatic();
  virtual ~CATPLMOperationContext();
  CATPLMOperationContext(CATPLMQEProfileContext iProfileContext);

  HRESULT Flush(int iFlushAll = 0);

  void InitDico() const;

  HRESULT CheckProfileExistency(const CATPLMOperationInput& iInput,
    const CATPLMLoadingSpec& iSpec,
    CATOmxSR<const CATPLMLoadingProfile>& oProfile) const;

  void OnWspMngtEvent(CATCallbackEvent iEvent, void* iSender, CATNotification* iNotif, CATSubscriberData iData, CATCallback iCallback);

  CATOmxVector<CATPLMOperationSet>          m_sets;
  mutable CATOmxSR<CATPLMLoadingDico>       m_dico;
  CATBoolean                                m_sandbox;
  CATPLMQEProfileContext                    m_profileContext;

  static CATOmxVector<CATPLMOperationContext> m_contexts;
};
#endif
