// COPYRIGHT Dassault Systemes 2009
//===================================================================
// PLMIConfigurableConnectionsManagerFactory.h
// Define the PLMIConfigurableConnectionsManagerFactory interface
//===================================================================
//  June 2009  Creation: Code generated by the LRG wizard
//===================================================================
#ifndef PLMIConfigurableConnectionsManagerFactory_H
#define PLMIConfigurableConnectionsManagerFactory_H

/**
* @level Protected
* @usage U3
*/

#include "CATBaseUnknown.h"
#include "CATPLMCfgCnxMngrInterfaces.h"
class CATListPtrCATIPLMComponent;
class CATICfgOperationInput;
class PLMIConfigurableConnectionsManager;
class PLMIConfigurableConnectionsManager_var;
// To remove:
class CATICfgOperationInput;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMCfgCnxMngrInterfaces IID IID_PLMIConfigurableConnectionsManagerFactory;
#else
extern "C" const IID IID_PLMIConfigurableConnectionsManagerFactory ;
#endif

#define PLMConfigurableConnectionsManagerFactory_Component "PLMConfigurableConnectionsManagerFactory"

//------------------------------------------------------------------

/**
* Factory to create PLMConfigurableConnectionsManagers
*
* @example
*  PLMIConfigurableConnectionsManagerFactory *pPLMCfgCnxMngr = NULL;
*  if (SUCCEEDED(::CATInstantiateComponent(PLMConfigurableConnectionsManagerFactory_Component,IID_PLMIConfigurableConnectionsManagerFactory,(void **)&pPLMCfgCnxMngr))&&pPLMCfgCnxMngr)
*  {
*    ...
*  }
*  CATSysReleasePtr(pPLMCfgCnxMngr);
*/
class ExportedByCATPLMCfgCnxMngrInterfaces PLMIConfigurableConnectionsManagerFactory: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Service to create a SYNCHRONEOUS manager of impacted connections for a given set of instances
  * that will be split by a configured operation.
  *
  *  @param  iSetOfOriginalInstances
  *      The set of original instances that have been split or trimmed.<br>
  *      This set must not be provided by caller as empty (size>0)!
  *  @param  iSetOfVariantInstances
  *      The set of corresponding variant instances. <br>
  *      This set must have the same size as <tt>iSetOfOriginalInstances</tt>. If an item of this
  *      list is equal to NULL_var, then it means that a configured deletion has been performed. 
  *  @param  opPLMCfgCnxManager (output parameter)
  *      The created manager for the given scope of split instances.
  *   @return
  *     <ul>
  *       <li> S_OK if the manager has been successfully created.</li>
  *       <li> E_INVALIDARG if some of the input arguments are not valid.</li>
  *       <li> E_FAIL if the creation of the manager failed.<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional 
  *           information about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href 
  *           CATError#CATCleanLastError to clean the error manager.
  *           <ul>
  *             <li><tt>CfgCnxMngr_ERR_05</tt>:</li>
  *                Creation of a manager for this scope of instances failed because there is already 
  *                a manager registered for this scope of instances.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT CreateSynchroneousManagerForScopeOfSplitInstances(
                              const CATListPtrCATIPLMComponent& iSetOfOriginalInstances,
                              const CATListPtrCATIPLMComponent& iSetOfVariantInstances,
                              PLMIConfigurableConnectionsManager*& opPLMCfgCnxManager)=0;

  /**
  * Service to create an ASYNCHRONEOUS  manager to analyze a given set of connections in session.
  *
  *  @param  iSetOfConnectionsToAnalyze
  *      The set of connections to analyze.<br>
  *      This set must not be provided by caller as empty (size>0) and must contain only connections!
  *  @param  opPLMCfgCnxManager (output parameter)
  *      The created manager for the given set of connections to analyze.
  *   @return
  *     <ul>
  *       <li> S_OK if the manager has been successfully created.</li>
  *       <li> E_INVALIDARG if some of the input arguments are not valid.</li>
  *       <li> E_FAIL if the creation of the manager failed.<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional 
  *           information about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href 
  *           CATError#CATCleanLastError to clean the error manager.
  *           <ul>
  *             <li><tt>CfgCnxMngr_ERR_05</tt>:</li>
  *                Creation of a manager for this set of connections failed because there is already 
  *                a manager working on this set of connections.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT CreateAsynchroneousManagerForSetOfConnectionsToAnalyze(
                                      const CATListPtrCATIPLMComponent& iSetOfConnectionsToAnalyze,
                                      PLMIConfigurableConnectionsManager*& opPLMCfgCnxManager)=0;

  /**
  * Service to unregister and invalidate/destroy a manager.
  *
  *  @param  ispPLMCfgCnxManager
  *      The manager to unregister and destroy. It becomes unusable.
  *   @return
  *     <ul>
  *       <li> S_OK if the manager has been successfully unregistered & destroyed.</li>
  *       <li> E_INVALIDARG if some of the input arguments are not valid.</li>
  *       <li> E_FAIL if the unregistration & desctruction of the manager failed.<br>
  *           Use @href CATError#CATGetLastError and @href CATError#GetMsgId to retrieve additional 
  *           information about the reason of the failure.
  *           Eventually release the @href CATError you retrieved and call @href 
  *           CATError#CATCleanLastError to clean the error manager.
  *           <ul>
  *             <li><tt>CfgCnxMngr_ERR_0</tt>:</li>
  *                Blabla.
  *           </ul>
  *        <li> E_UNEXPECTED otherwise.
  *      </ul>
  */
  virtual HRESULT UnregisterAndDestroyManager(const PLMIConfigurableConnectionsManager_var &ispPLMCfgCnxManager)=0;

  /* DO NOT USE. DEPRECATED! */
  virtual HRESULT CreateManagerForScopeOfSplittedInstances(const CATListPtrCATIPLMComponent& iSetOfSplittedInstancesDefiningScope,const CATICfgOperationInput* ipCfgOperationInput,PLMIConfigurableConnectionsManager*& opPLMCfgCnxManager)=0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(PLMIConfigurableConnectionsManagerFactory, CATBaseUnknown);

#endif
