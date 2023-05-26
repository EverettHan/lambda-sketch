// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessFaceCacheAccess.h
//
//===================================================================
//
// Usage notes: Class for accessing tessellation cache of a CATFace
//
// Sample Usage:
//
//      {
//        ...
//        ...
//        CATTessellateParamCache TessParam;
//        CATSoftwareConfiguration* Config = new CATSoftwareConfiguration();
//        ...
//        ...
//        CATFace* MyFace = GetFaceFromSomewhere();
//        ...
//        ...
//
//        if (MyFace && Config)
//        {
//          const CATTessFaceDataCache* TessCache = NULL;
//          CATTessFaceCacheAccess CacheAccess(*MyFace);
//
//          // Find if TessCache is available for the given parameters and config
//
//          HRESULT Status = CacheAccess.GetCache(UVParam, *Config, TessCache);
//
//          if (SUCCEEDED(Status))
//          {
//            if (S_OK == Status && TessCache)
//            {
//              // Cache found.
//              ...
//              ...
//
//              // Remember to release the cache after use
//              TessCache->Release();
//              TessCache = 0
//            }
//            if (S_FALSE == Status)
//            {
//              // No Cache available for the given settings
//            }
//          }
//          else
//          {
//            // Some unexpected error has occurred
//          }
//        }
//
//        ...
//        ...
//      }
//
//===================================================================
//
// Feb 2016  Creation: TPG
//===================================================================

#ifndef CATTessFaceCacheAccess_H
#define CATTessFaceCacheAccess_H

#include "ExportedByTessellateCommon.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATTessCacheAccess.h"

class CATBody;
class CATTessellateParamCache;
class CATSoftwareConfiguration;
class CATTessFaceDataCache;
class CATFace;
class CATCGMUVFaceMeshRichItf;
class CATCGMUVFaceMeshBasicItf;
class CATCGMUVFaceMeshBuffersItf;
class CATCGMUVEdgeMeshFetcher;
class CATCGMUVCompressedFaceMesh;
class CATCGMUVFaceCacheMemPool;
class CATCGMUVAbstractTopo;
class CATCGMUVFaceCacheReadAccess2;

//#define _FOR_DEBUG_Test_Iter_Interfaces

class ExportedByTessellateCommon CATTessFaceCacheAccess
  : public CATTessCacheAccess
{
public:
  CATTessFaceCacheAccess();
  ~CATTessFaceCacheAccess();

public:

  // Returns HRESULT as S_OK if cache is found for the given param. 
  // Returned oFaceMesh represents the interface for the cache object found.
  // Remember to delete oFaceMesh after use.
  // If no cache is found for the given params and config, then returns HRESULT as S_FALSE and oFaceMesh as NULL.
  HRESULT GetBuffersFromCache(
              const CATTessellateParamCache& iParam, 
              CATSoftwareConfiguration& iConfig, 
              CATCGMUVFaceMeshBuffersItf*& oFaceMesh) const;


  // Returns HRESULT as S_OK if cache is found for the given param. 
  // If no cache is found for the given params and config, then returns HRESULT as S_FALSE and oCache as NULL.
  // Remember to call oCache->Release() after use.
  HRESULT GetClassicCache(
              const CATTessellateParamCache& iParam, 
              CATSoftwareConfiguration& iConfig, 
              const CATTessFaceDataCache*& oCache) const;

  // Returns S_OK is cache is added.
  // Returns S_FALSE if cache is not added because max limit has exceeded
  // Returns other errors for failures
  HRESULT AddToCache(
            const CATTessellateParamCache& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATCGMUVEdgeMeshFetcher& iEdgeMeshFetcher,
            const CATCGMUVFaceMeshRichItf& iMeshItf);

  // To be used only for V5 tessellation
  // Returns S_OK is cache is added.
  // Returns S_FALSE if cache is not added because max limit has exceeded
  // Returns other errors for failures
  HRESULT AddToCache(
            const CATTessellateParamCache& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATTessFaceDataCache& iCache);


#ifdef _FOR_DEBUG_Test_Iter_Interfaces

public:
  static HRESULT ForDebug(
            CATBody& iBody,
            const CATTessellateParamCache& iParam, 
            CATSoftwareConfiguration& iConfig);

#endif //_FOR_DEBUG_Test_Iter_Interfaces

protected:

  CATCGMUVFaceCacheMemPool* GetMemPool() const;
  HRESULT ReleaseMemPool() const;

  CATCGMUVAbstractTopo* GetTopo() const;
  CATCGMUVFaceCacheReadAccess2* GetReadAccess2() const;

protected:
  CATCGMUVFaceCacheMemPool* _MemPool;
  CATCGMUVAbstractTopo* _Topo;
  CATCGMUVFaceCacheReadAccess2* _ReadAccess2;
};

#endif
