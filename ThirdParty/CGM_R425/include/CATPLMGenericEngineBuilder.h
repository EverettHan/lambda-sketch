/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMGenericEngineBuilder_H
#define CATPLMGenericEngineBuilder_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATErrorDef.h"

class CATIPLMEngineFactory;
class CATIPLMEngineFactory_var;
class CATPLMID;
template <typename Type> class CATOmxIter;
class CATIPLMSpace;
class CATIAdpErrorMonitorAbstract;
class CATIPLMGenericListenerAbstract;
class CATPLMBag;
class CATProxySpace;
class CATIPLMEngineListener;
class CATIPLMAttributeSet;


/**
 * Basic builder enabling to settle parameters for late engine creation.
 *<br><b>Role</b>: Settle session parameters for engine instantiation.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMGenericEngineBuilder
{
public:
  CATPLMGenericEngineBuilder();
  virtual ~CATPLMGenericEngineBuilder();

/**
 * Valuate a Workspace identifier.
 * <br><b>Role</b>: Enables to provide to the engines the identifier of the Workspace that the next
 * transaction will have to deal with.
 *
 * @param iWorkspaceId [in]
 *   The @href CATPLMID of the Workspace.
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> if the identifier of the Workspace can be used to settle the context.
 * <dt><code>E_FAIL</code> if an unexpected error occured.
 * <dt><code>E_INVALIDARG</code> if the provided identifier is invalid.
 * </dl>
 */
  HRESULT SetWorkspaceId(const CATPLMID & iWorkspaceId);

/**
 * Valuate a specific Dataspace.
 * <br><b>Role</b>: Enables to provide to the engines a specific Dataspace to take into account for next treatments.
 *
 * @param iDataspace [in]
 *   The specific dataspace.
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> if the Dataspace can be used to settle the context.
 * <dt><code>E_FAIL</code> if an unexpected error occured.
 * <dt><code>E_INVALIDARG</code> if the provided Dataspace is invalid.
 * </dl>
 */
  HRESULT SetDataspace(CATIPLMSpace * iDataspace);
  HRESULT SetDataspace(const CATProxySpace & iDataspace);

/**
 * Valuate an Error Monitor.
 * <br><b>Role</b>: Enables to provide to the engine an Error Monitor enabling to be warned about the errors
 * which will possibly occur during the next transaction performed through this engine.
 *
 * @param iMonitor [in]
 *   The Error Monitor.
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> if the Monitor can be used to settle the context.
 * <dt><code>E_FAIL</code> if an unexpected error occured.
 * <dt><code>E_INVALIDARG</code> if the provided Monitor is invalid.
 * </dl>
 */
  HRESULT SetErrorMonitor(CATIAdpErrorMonitorAbstract * iMonitor);

/**
 * Valuate an Engine Listener.
 * <br><b>Role</b>: Enables to provide to the engine a process Listener enabling to be informed about the progress
 * of the process. This might not be implemented by all engines.
 *
 * @param iListener [in]
 *   The Engine Listener.
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> if the Listener can be used to settle the context.
 * <dt><code>E_FAIL</code> if an unexpected error occured.
 * <dt><code>E_INVALIDARG</code> if the provided Listener is invalid.
 * </dl>
 */
  HRESULT SetProcessListener(CATIPLMGenericListenerAbstract * iListener);

 /**
  * Valuate a Bag
  * <br><b>Role</b>: Set the bag where each lyfe cycle dependant operation will put the components
  * @param ioBag [in]
  *    The lifecycle management bag.
  * @return
  * <dl>
 * <dt><code>S_OK</code> if the bag can be used.
 * <dt><code>E_FAIL</code> if an unexpected error occured.
 * <dt><code>E_INVALIDARG</code> if the provided bag is invalid.
 * </dl>
 */
  HRESULT SetLifeCycleBag(const CATPLMBag & ioBag);

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
  HRESULT SetRootsForLifeCycleBag(const CATOmxIter<const CATPLMID> &iRoots);

  /**
 * Gives access to an attribute set.
 * <br><b>Role:</b>This method enables to get an attribute set enabling to specify some attributes to use with some engines.<br>
 *
 * @param oAttributeSet  [out,CATBaseUnknown#Release]
 *   A pointer on the attribute set.
 * @return
 *   <ul>
 *   <li><tt>S_OK</tt> if access is given to an attribute set.</li>
 *   <li><tt>E_FAIL</tt> if the operation failed.</li>
 *   </ul>
 */
  HRESULT GetAttributeSet(CATIPLMAttributeSet *& oAttributeSet);

  /**
   * @nodoc
   */
  CATIPLMEngineFactory * GetLetter() { return _letter; }

  static CATIPLMEngineFactory_var GetEngineFactory(CATIAdpErrorMonitorAbstract* iErrorMonitor = NULL, CATIPLMEngineListener* iListener = NULL);

protected:
  CATIPLMEngineFactory* _letter;
};
#endif
