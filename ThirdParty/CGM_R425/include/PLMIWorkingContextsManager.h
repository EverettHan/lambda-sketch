// COPYRIGHT Dassault Systemes 2009
#ifndef PLMIWorkingContextsManager_H
#define PLMIWorkingContextsManager_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMModelerBaseInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATString.h"

// --- Forward declarations
class CATString;
class CATIPLMNavOccurrence;
class CATIPLMNavInstance;
class CATIPLMNavReference;
class CATListPtrCATIPLMNavOccurrence;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModelerBaseInterfaces IID IID_PLMIWorkingContextsManager;
#else
extern "C" const IID IID_PLMIWorkingContextsManager ;
#endif

//------------------------------------------------------------------

/**
 * Interface dedicated to establish and manage a working context federating different partitions. <br>
 * This working context will be used when navigating on cross-partitions "links" to provide a coherent view 
 * taking into account configuration.
 */
class ExportedByCATPLMModelerBaseInterfaces PLMIWorkingContextsManager: public CATBaseUnknown
{
  CATDeclareInterface;

public:
    /**
     * Retrieves the object managing the working contexts.
     *
     *  @param  opManager
     *    A Working Contexts Manager. <br>
     *    Output Parameter. <br>
     *    This parameter MUST be provided by caller as NULL. This method returns an error otherwise.
     *  @return
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    static HRESULT GetWorkingContextsManager(PLMIWorkingContextsManager *&opManager);

    /**
     * Adds a new context to the specified partition.
     *
     *  @param  iPartitionName
     *      A Partition name. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as empty. This method returns an error otherwise.
     *  @param  ipContext
     *      A Root Occurrence. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as NULL. This method returns an error otherwise.
     *  @param  iIsActive
     *      Defines that the given context will be active or not in the given partition.<br>
     *      TRUE by default. <br>
     *      Input Parameter.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but the context is already handled. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT AppendContext (CATString iPartitionName, CATIPLMNavOccurrence *ipContext, CATBoolean iIsActive = TRUE) = 0;

    /**
     * Sets the specified context as the active context for the partition it is related.
     *
     *  @param  ipContext
     *      A Root Occurrence. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as NULL. This method returns an error otherwise.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT SetActiveContext (CATIPLMNavOccurrence *ipContext) = 0;

    /**
     * Gets the active context related a specified partition.
     *
     *  @param  iPartitionName
     *      A Partition name. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as empty. This method returns an error otherwise.
     *  @param  opContext
     *      A Root Occurrence. <br>
     *      Output Parameter. <br>
     *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT GetActiveContext (CATString iPartition, CATIPLMNavOccurrence *&opContext) = 0;

    /**
     * Gets the active context given an reference.
     *
     *  @param  ipReference
     *      A Reference. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as empty. This method returns an error otherwise.
     *  @param  opContext
     *      A Root Occurrence. <br>
     *      Output Parameter. <br>
     *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but there is no active context related to the input. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT GetActiveContext (CATIPLMNavReference *ipReference, CATIPLMNavOccurrence *&opContext) = 0;

    /**
     * Gets the active context given an instance.
     *
     *  @param  ipInstance
     *      An Instance. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as empty. This method returns an error otherwise.
     *  @param  opContext
     *      A Root Occurrence. <br>
     *      Output Parameter. <br>
     *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but there is no active context related to the input. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT GetActiveContext (CATIPLMNavInstance *ipInstance, CATIPLMNavOccurrence *&opContext) = 0;

    /**
     * Gets the active context given an occurrence.
     *
     *  @param  ipOccurrence
     *      An Occurrence. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as empty. This method returns an error otherwise.
     *  @param  opContext
     *      A Root Occurrence. <br>
     *      Output Parameter. <br>
     *      This parameter MUST be provided by caller as NULL. This method returns an error otherwise.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but there is no active context related to the input. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT GetActiveContext (CATIPLMNavOccurrence *ipOccurrence, CATIPLMNavOccurrence *&opContext) = 0;

    /**
     * Retrieves the contexts related to a specified partition.
     *
     *  @param  iPartitionName
     *      A Partition name. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as empty. This method returns an error otherwise.
     *  @param  oLContexts
     *      A list of Root Occurrences. <br>
     *      Output Parameter. <br>
     *      This parameter MUST be provided by caller as empty. This method returns an error otherwise.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but there is no context related to the specified partition. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT ListContexts (CATString iPartitionName, CATListPtrCATIPLMNavOccurrence &oLContexts) = 0;

    /**
     * Retrieves the partitions handled by this manager.
     *
     *  @param  oLManagedPartitions
     *      A list of Partition Names. <br>
     *      Output Parameter. <br>
     *      This parameter MUST be provided by caller as empty. This method returns an error otherwise.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>S_FALSE</code> if the method succeeds but there is no managed partitions. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT ListManagedPartitions (CATListOfCATString &oLManagedPartitions) = 0;

    /**
     * Retrieves a context from the manager.
     *
     *  @param  ipContext
     *      A Root Occurrence. <br>
     *      Input Parameter. <br>
     *      This parameter MUST NOT be provided by caller as NULL. This method returns an error otherwise.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT RemoveContext (CATIPLMNavOccurrence *ipContext) = 0;

    /**
     * Retrieves all the contexts related to a given partition.
     *
     *  @param  iPartitionName
     *      A Partition Name. <br>
     *      Input Parameter. <br>
     *      If Empty, all the contexts of every partition will be removed.
     *  @return 
     *      <code>S_OK</code> if the method succeeds. <br>
     *      <code>E_INVALIDARG</code> if parameters provided are unexpected. <br>
     *      <code>E_FAIL</code> otherwise. <br>
     */
    virtual HRESULT RemoveAllContexts (CATString &iPartitionName) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(PLMIWorkingContextsManager, CATBaseUnknown);

//------------------------------------------------------------------

#endif
