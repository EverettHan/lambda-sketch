// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVCacheAccess.h
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

#ifndef CATCGMUVCacheAccess_H
#define CATCGMUVCacheAccess_H

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "ExportedByTessellateCommon.h"
#include "CATCGMUVEKCodeDebug.h"

class CATCGMUVParam;
class CATSoftwareConfiguration;
class CATTessDataCache;
class CATCGMUVCacheAttribute;
class CATCell;

class ExportedByTessellateCommon CATCGMUVCacheAccess
{
public:
  inline CATCGMUVCacheAccess();
  virtual ~CATCGMUVCacheAccess();

  inline void SetCell(CATCell& iCell);

  CATBoolean IsCacheAvailable(
              const CATCGMUVParam& iParam, 
              CATSoftwareConfiguration& iConfig) const;

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


  // Gets the current persistency flag on a particular cache item (the one matching with given iParam and iConfig).
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT GetPersistent(const CATCGMUVParam& iParam, CATSoftwareConfiguration& iConfig, CATBoolean& oIsPersistent) const;

  // Remove a mesh (the one matching with given iParam and iConfig) from cache
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT RemoveFromCache(const CATCGMUVParam& iParam, CATSoftwareConfiguration& iConfig) const;

  // AddRef CacheItem (the one matching with given iParam and iConfig) found in cache
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT AddRefCacheItem(const CATCGMUVParam& iParam, CATSoftwareConfiguration& iConfig) const;

  // Release CacheItem (the one matching with given iParam and iConfig) found in cache
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT ReleaseCacheItem(const CATCGMUVParam& iParam, CATSoftwareConfiguration& iConfig) const;

	HRESULT GetDataCache(const CATCGMUVParam& iParam, CATSoftwareConfiguration& iConfig, const CATTessDataCache*& oCache) const;


protected:

  // Returns S_OK is cache is added.
  // Returns S_FALSE if cache is not added because max limit has exceeded
  // Returns other errors for failures
  HRESULT AddToCellCache(
            const CATCGMUVParam& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATTessDataCache& iCache);

#ifdef EK_CODE_DISPO
public:
  HRESULT GetCacheStream(const CATCGMUVParam& iParam, 
                         CATSoftwareConfiguration& iConfig, 
                         const unsigned char*& oBuffer,
                         CATULONG32& oBufferSize) const;
  
  HRESULT SetCacheStream(const CATCGMUVParam& iParam, 
                         CATSoftwareConfiguration& iConfig, 
                         const unsigned char* iBuffer,
                         CATULONG32 iBufferSize);
#endif
protected:

  inline HRESULT FindAttribute(CATCGMUVCacheAttribute*& oAttrib) const;
  HRESULT FindOrCreateAttribute(CATCGMUVCacheAttribute*& oAttrib, CATBoolean iCreateIfNotFound);
  HRESULT AddNewAttribute(CATCGMUVCacheAttribute*& oAttrib);
  double Resolution() const;

protected:
  double _Resolution;
  CATCell* _Cell;
  CATCGMUVCacheAttribute* _Attrib;
};

inline 
CATCGMUVCacheAccess::CATCGMUVCacheAccess()
:_Cell(0), _Attrib(0), _Resolution(-1.0)
{
}

inline void 
CATCGMUVCacheAccess::SetCell(CATCell& iCell)
{
  _Attrib = 0;
  _Cell = &iCell;
}

inline HRESULT
CATCGMUVCacheAccess::FindAttribute(CATCGMUVCacheAttribute*& oAttrib) const
{
  return ((CATCGMUVCacheAccess*)this)->FindOrCreateAttribute(oAttrib, FALSE);
}

#endif
