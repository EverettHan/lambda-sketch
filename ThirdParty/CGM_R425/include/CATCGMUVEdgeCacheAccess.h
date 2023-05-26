// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVEdgeCacheAccess.h
//
//===================================================================
//
// Usage notes: Similar to CATCGMUVFaceCacheAccess. 
//              See CATCGMUVEdgeCacheAccess for more details
//===================================================================
//
// July 2011  Creation: MPX
//===================================================================

#ifndef CATCGMUVEdgeCacheAccess_H
#define CATCGMUVEdgeCacheAccess_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMUVCacheAccess.h"


class CATCGMUVParam;
class CATSoftwareConfiguration;
class CATTessEdgeDataCache;
class CATCGMUVEdgeMeshRichItf;
class CATCGMUVEdgeMeshBasicItf;
class CATCGMUVEdgeMeshBuffersItf;
class CATCGMUVCompressedEdgeMesh;
class CATCGMUVEdgeCacheMemPool;
class CATEdge;
class CATCGMUVAbstractTopo;
class CATCGMUVEdgeCacheReadAccess2;


class ExportedByTessellateCommon CATCGMUVEdgeCacheAccess  : public CATCGMUVCacheAccess
{
public:
  CATCGMUVEdgeCacheAccess();
  ~CATCGMUVEdgeCacheAccess();

public:

  // Returns HRESULT as S_OK if cache is found for the given param. 
  // Returned oEdgeMesh represents the interface for the cache object found.
  // Remember to delete oEdgeMesh after use.
  // If no cache is found for the given params and config, then returns HRESULT as S_FALSE and oEdgeMesh as NULL.
  HRESULT GetCache(
              const CATCGMUVParam& iParam, 
              CATSoftwareConfiguration& iConfig, 
              CATCGMUVEdgeMeshBasicItf*& oEdgeMesh) const;

  // Returns HRESULT as S_OK if cache is found for the given param. 
  // Returned oEdgeMesh represents the interface for the cache object found.
  // Remember to delete oEdgeMesh after use.
  // If no cache is found for the given params and config, then returns HRESULT as S_FALSE and oEdgeMesh as NULL.
  HRESULT GetBuffersFromCache(
              const CATCGMUVParam& iParam, 
              CATSoftwareConfiguration& iConfig, 
              CATCGMUVEdgeMeshBuffersItf*& oEdgeMesh) const;

  // Returns S_OK is cache is added.
  // Returns S_FALSE if cache is not added because max limit has exceeded
  // Returns other errors for failures
  HRESULT AddToCache(
            const CATCGMUVParam& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATCGMUVEdgeMeshRichItf& iMeshItf);

  // To be used only for V5 tessellation
  // Returns S_OK is cache is added.
  // Returns S_FALSE if cache is not added because max limit has exceeded
  // Returns other errors for failures
  HRESULT AddToCache(
            const CATCGMUVParam& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATTessEdgeDataCache& iCache);

protected:
  CATCGMUVEdgeCacheMemPool* GetMemPool() const;
  HRESULT ReleaseMemPool() const;

  CATCGMUVAbstractTopo* GetTopo() const;
  CATCGMUVEdgeCacheReadAccess2* GetReadAccess2() const;

protected:
  CATCGMUVEdgeCacheMemPool* _MemPool;
  CATCGMUVAbstractTopo* _Topo;
  CATCGMUVEdgeCacheReadAccess2* _ReadAccess2;
};


#endif
