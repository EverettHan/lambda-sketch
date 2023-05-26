/**
 * @level Private
 * @usage U1
 */
#ifndef __CATUpdNodeAdapter_H
#define __CATUpdNodeAdapter_H

#include "CATUpd.h"
#include "CATIUpdNode.h"

/**
 * trivial adapter for CATIUpdNode.
 */
class ExportedByCATUpd CATUpdNodeAdapter: public CATIUpdNode
{
protected:
  virtual HRESULT GetUpdateStatus(CATIUpdContext& iContext,CATIUpdNode::Status& oStatus,CATIUpdNode::CacheStatus& oCacheStatus) const;
  virtual HRESULT SetUpdateStatus(CATIUpdContext& iContext,CATIUpdNode::Status iStatus,CATIUpdNode::CacheStatus iCacheStatus);
  virtual HRESULT ComputeUpdateStatus(CATIUpdContext& iContext,CATIUpdNode::Status& oStatus) const;
  virtual HRESULT RefreshUpdateData(CATIUpdContext& iContext);
  virtual HRESULT GetInputs(CATIUpdContext& iContext,CATOmxIter<CATIUpdNode>& oIterator) const;
  virtual HRESULT GetImpacts(CATIUpdContext& iContext,CATOmxIter<CATIUpdNode>& oIterator) const;
  virtual HRESULT GetOutputs(CATIUpdContext& iContext,CATOmxIter<CATIUpdNode>& oIterator) const;
  virtual HRESULT GetBuilder(CATIUpdContext& iContext,CATOmxSR<CATIBuild>& oBuilder) const;
  virtual HRESULT GetId(CATIUpdContext& iContext,CATOmxSR<IUnknown>& oId) const;
  virtual ~CATUpdNodeAdapter();
};

#endif

