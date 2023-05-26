// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVCacheAccess2.h
//
//===================================================================
//
// Usage notes: Don't use this class directly. 
//              Use CATCGMUVFaceCacheAccess or CATCGMUVEdgeCacheAccess instead
//
//===================================================================
//
// July 2011  Creation: MPX
//===================================================================

#ifndef CATCGMUVCacheAccess2_H
#define CATCGMUVCacheAccess2_H

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "ExportedByTessellateCommon.h"
#include "CATCGMUVAbstractTopo.h"

class CATEdge;
class CATFace;
class CATSoftwareConfiguration;
class CATCGMUVParam;
class CATCGMUVEdgeMeshRichItf;
class CATCGMUVEdgeMeshFetcher;
class CATCGMUVFaceMeshRichItf;
class CATTessDataCache;
class CATCGMUVAbstractTopo;

class ExportedByTessellateCommon CATCGMUVCacheAccess2
{
public:
  inline CATCGMUVCacheAccess2(CATCGMUVAbstractTopo& iAbstractTopo);
  virtual ~CATCGMUVCacheAccess2();

  // Gets the current persistency flag on a particular cache item (the one matching with given iParam and iConfig).
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT GetPersistent(const CATCGMUVParam& iParam, CATSoftwareConfiguration& iConfig, CATBoolean& oIsPersistent) const;


  // interfaces for compression
  static HRESULT CompressEdgeMesh(
            CATEdge& iEdge,
            const CATCGMUVParam& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATCGMUVEdgeMeshRichItf& iMeshItf,
            CATULONG32& oMeshBufferSize, 
            unsigned char*& oMeshBuffer,
            CATCGMUVTessCodeVersion& oTessCodeVersion);

  static HRESULT CompressFaceMesh(
            CATFace& iFace,
            const CATCGMUVParam& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATCGMUVEdgeMeshFetcher& iEdgeMeshFetcher,
            const CATCGMUVFaceMeshRichItf& iMeshItf,
            CATULONG32& oMeshBufferSize, 
            unsigned char*& oMeshBuffer,
            CATCGMUVTessCodeVersion& oTessCodeVersion);

protected:

  // Sets the persistency flag on a particular cache item (the one matching with given iParam and iConfig).
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : 
  //        - no cache item was found for given iParam and iConfig
  //        - cache is of older version, so it is not persistent
  //        - cache is stored in classic cache form, so it is not persistent
  //
  // IMPORTANT NOTE: 
  //    This persistency flag is valid only upto the next stream operation,
  //    after which it will be reset to non-persistent
  HRESULT SetPersistent(const CATCGMUVParam& iParam, CATSoftwareConfiguration& iConfig, CATBoolean iIsPersistent);


  // Remove a mesh (the one matching with given iParam and iConfig) from cache
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT RemoveFromCache(const CATCGMUVParam& iParam, CATSoftwareConfiguration& iConfig) const;


  // Returns S_OK is cache is added.
  // Returns S_FALSE if cache is not added because max limit has exceeded
  // Returns other errors for failures
  HRESULT AddToCellCache(
            const CATCGMUVParam& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATTessDataCache& iCache);

protected:

  double Resolution() const;

protected:
  double _Resolution;
  CATCGMUVAbstractTopo& _AbstractTopo;
};

inline 
CATCGMUVCacheAccess2::CATCGMUVCacheAccess2(CATCGMUVAbstractTopo& iAbstractTopo)
:_AbstractTopo(iAbstractTopo), _Resolution(-1.0)
{
}

#endif
