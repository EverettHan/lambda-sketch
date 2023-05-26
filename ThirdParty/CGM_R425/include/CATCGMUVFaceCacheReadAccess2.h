// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVFaceCacheReadAccess2.h
//
//===================================================================
// Sept 2012  Creation: MPX
//===================================================================

#ifndef CATCGMUVFaceCacheReadAccess2_H
#define CATCGMUVFaceCacheReadAccess2_H

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMUVCacheAccess2.h"
#include "CATCGMUVAbstractTopo.h"


class CATCGMUVParam;
class CATTessellateParamCache;
class CATSoftwareConfiguration;
class CATCGMUVFaceMeshBuffersItf2;
class CATCGMUVFaceCacheMemPool;

class ExportedByTessellateCommon CATCGMUVFaceCacheReadAccess2
  : public CATCGMUVCacheAccess2
{
public:
  CATCGMUVFaceCacheReadAccess2(CATCGMUVAbstractTopo& iAbstractTopo);
  ~CATCGMUVFaceCacheReadAccess2();

  void SetFaceHandle(CATUVFaceHandle iFaceHandle);

public:

  // Returns HRESULT as S_OK if cache is found for the given param. 
  // Returned oFaceMesh represents the interface for the cache object found.
  // Remember to delete oFaceMesh after use.
  // If no cache is found for the given params and config, then returns HRESULT as S_FALSE and oFaceMesh as NULL.
  HRESULT GetBuffersFromCache(
              const CATCGMUVParam& iParam, 
              CATSoftwareConfiguration& iConfig, 
              CATCGMUVFaceMeshBuffersItf2*& oFaceMesh) const;

  HRESULT GetBuffersFromCache(
              const CATTessellateParamCache& iParam, 
              CATSoftwareConfiguration& iConfig, 
              CATCGMUVFaceMeshBuffersItf2*& oFaceMesh) const;

protected:
  CATCGMUVFaceCacheMemPool* GetMemPool() const;
  HRESULT ReleaseMemPool() const;

protected:
  CATCGMUVFaceCacheMemPool* _MemPool;
  CATUVFaceHandle _FaceHandle;
};

#endif
