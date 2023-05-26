// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVEdgeCacheReadAccess2.h
//
//===================================================================
//
// Sept 2012  Creation: MPX
//===================================================================

#ifndef CATCGMUVEdgeCacheReadAccess2_H
#define CATCGMUVEdgeCacheReadAccess2_H

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMUVCacheAccess2.h"
#include "CATCGMUVAbstractTopo.h"
#include "CATTessellateParamCache.h"


class CATCGMUVParam;
class CATSoftwareConfiguration;
class CATCGMUVEdgeMeshBuffersItf2;
class CATCGMUVEdgeCacheMemPool;


class ExportedByTessellateCommon CATCGMUVEdgeCacheReadAccess2
  : public CATCGMUVCacheAccess2
{
public:
  CATCGMUVEdgeCacheReadAccess2(CATCGMUVAbstractTopo& iAbstractTopo);
  ~CATCGMUVEdgeCacheReadAccess2();

  void SetEdgeHandle(CATUVEdgeHandle iEdgeHandle);

public:

  // Returns HRESULT as S_OK if cache is found for the given param. 
  // Returned oEdgeMesh represents the interface for the cache object found.
  // Remember to delete oEdgeMesh after use.
  // If no cache is found for the given params and config, then returns HRESULT as S_FALSE and oEdgeMesh as NULL.
  HRESULT GetBuffersFromCache(
              const CATCGMUVParam& iParam, 
              CATSoftwareConfiguration& iConfig, 
              CATCGMUVEdgeMeshBuffersItf2*& oEdgeMesh) const;

  HRESULT GetBuffersFromCache(
              const CATTessellateParamCache& iParam, 
              CATSoftwareConfiguration& iConfig, 
              CATCGMUVEdgeMeshBuffersItf2*& oEdgeMesh) const;

protected:
  CATCGMUVEdgeCacheMemPool* GetMemPool() const;
  HRESULT ReleaseMemPool() const;
  inline CATUVEdgeHandle GetEdgeHandle() const;

protected:
  CATCGMUVEdgeCacheMemPool* _MemPool;
  CATUVEdgeHandle _EdgeHandle;
};

#endif
