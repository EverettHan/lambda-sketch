/**
 * @level Private
 * @usage U1
 */
#ifndef __CATIUpdNode_H
#define __CATIUpdNode_H

#include "CATUpd.h"
#include "CATBaseUnknown.h"
#include "CATUpdHRESULT.h"
#include "CATOmxKernel.h"

class CATIUpdNode;
class CATIUpdContext;
class CATIBuild;
#ifdef CATWUpdNode
#pragma error
#endif
class CATWUpdNode;
extern ExportedByCATUpd IID IID_CATIUpdNode;

/**
  * Class representing a node of the update graph. 
  * It allows the update engine to maintain synchroneously the update status of a direct acyclic graph of objects.
  * An object is considered as "up to date" if it and none of its inputs have been modified since its last update.
  * The only way to turn an object to "up to date" status is to update it.
  * Each node of the update graph must know its inputs (objects which intrinsic result can modify its result) and symmetrically its impacts.
  * This interface can be overriden but must never be called directly.
  * It is the role of the update engine (@see CATUpdEngine) to use it and offer high level functionnalities.
  */
class ExportedByCATUpd CATIUpdNode: public CATBaseUnknown
{
public:
  CATDeclareInterface;
public:
  
  /**
   * Enum representing update status of an update node.
   */
  enum Status {OutOfDate=0,UpToDate=1};
  
  /**
   * Enum representing update cache status of an update node.
   * Passive means update status is not known and must be computed.
   */
  enum CacheStatus {Passive=0,Active=1,ActiveUntilLoad=2};

protected:
  /**
   * Get current unitary update status.
   * A newly created node must have an "OutOfDate" status.
   * A node must in Passive cache mode until UpdateEngine has computed its status.
   */
  virtual HRESULT GetUpdateStatus(CATIUpdContext& iContext,CATIUpdNode::Status& oStatus,CATIUpdNode::CacheStatus& oCacheStatus) const=0;

  /**
   * Set update status.
   */
  virtual HRESULT SetUpdateStatus(CATIUpdContext& iContext,CATIUpdNode::Status iStatus,CATIUpdNode::CacheStatus iCacheStatus)=0;

  /**
   * This method allows to implement a specific update status computation
   * it will be called if the cache status is Passive.
   * This method must not ask dependencies for their update status, this the work of the update engine
   * This method must not call back SetUpdateStatus, this will be done by the update engine
   */
  virtual HRESULT ComputeUpdateStatus(CATIUpdContext& iContext,CATIUpdNode::Status& oStatus) const=0;

  /**
   * This method must be implemented if the previous one is.
   * It will be called after inputs update and before build to refresh update datas
   * that are used by ComputeUpdateStatus method
   */
  virtual HRESULT RefreshUpdateData(CATIUpdContext& iContext)=0;

  /**
   * Get an iterator on the inputs of this node.
   */
  virtual HRESULT GetInputs(CATIUpdContext& iContext,CATOmxIter<CATIUpdNode>& oIterator) const=0;

  /**
   * Get an iterator on the impacts of this node.
   */
  virtual HRESULT GetImpacts(CATIUpdContext& iContext,CATOmxIter<CATIUpdNode>& oIterator) const=0;

  /**
   * Get an iterator on the outputs of this node.
   * Outputs are features which must be updated after update of this node.
   */
  virtual HRESULT GetOutputs(CATIUpdContext& iContext,CATOmxIter<CATIUpdNode>& oIterator) const=0;
  
  /**
   * Get object in charge of build of this node.
   */
  virtual HRESULT GetBuilder(CATIUpdContext& iContext,CATOmxSR<CATIBuild>& oBuilder) const=0; 

  /**
   * Get a stable identifier for this node.
   */
  virtual HRESULT GetId(CATIUpdContext& iContext,CATOmxSR<IUnknown>& oId) const=0;

  /**
   * the only class which is authorized to manipulate this interface.
   */
  friend class CATWUpdNode;
};


#endif
