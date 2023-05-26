// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessCacheAccess.h
//
//===================================================================
//
// Usage notes: Don't use this class directly. 
//              Use CATTessFaceCacheAccess or CATTessEdgeCacheAccess instead
//
//===================================================================
//
// Feb 2016  Creation: TPG
//===================================================================

#ifndef CATTessCacheAccess_H
#define CATTessCacheAccess_H

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "ExportedByTessellateCommon.h"
#include "CATCGMUVEKCodeDebug.h"
#include "CATMapOfPtrToPtr.h"
#include "CATTessellateParamCacheContainer.h"

class CATTessellateParamCache;
class CATSoftwareConfiguration;
class CATTessDataCache;
class CATCGMTessCacheAttribute;
class CATCell;

class ExportedByTessellateCommon CATTessCacheAccess
{
public:
  inline CATTessCacheAccess();
  virtual ~CATTessCacheAccess();

  inline void SetCell(CATCell& iCell);

  inline void SetGeomVisu(int iGeomVisu);

  CATBoolean IsCacheAvailable(
              const CATTessellateParamCache& iParam, 
              CATSoftwareConfiguration& iConfig) const;

  HRESULT GetDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, const CATTessDataCache*& oCache) const;

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
  HRESULT SetPersistent(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATBoolean iIsPersistent);


  // Gets the current persistency flag on a particular cache item (the one matching with given iParam and iConfig).
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT GetPersistent(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATBoolean& oIsPersistent) const;

  // Remove a mesh (the one matching with given iParam and iConfig) from cache
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT RemoveFromCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig) const;

  // AddRef CacheItem (the one matching with given iParam and iConfig) found in cache
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT AddRefCacheItem(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig) const;

  // Release CacheItem (the one matching with given iParam and iConfig) found in cache
  // Returns 
  //    S_OK : success
  //    E_FAIL : failure
  //    S_FALSE : no cache item was found for given iParam and iConfig
  HRESULT ReleaseCacheItem(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig) const;
    
protected:

  // Returns S_OK is cache is added.
  // Returns S_FALSE if cache is not added because max limit has exceeded
  // Returns other errors for failures
  HRESULT AddToCellCache(
            const CATTessellateParamCache& iParam, 
            CATSoftwareConfiguration& iConfig, 
            const CATTessDataCache& iCache);

#ifdef EK_CODE_DISPO
public:
  HRESULT GetCacheStream(const CATTessellateParamCache& iParam, 
                         CATSoftwareConfiguration& iConfig, 
                         const unsigned char*& oBuffer,
                         CATULONG32& oBufferSize) const;
  
  HRESULT SetCacheStream(const CATTessellateParamCache& iParam, 
                         CATSoftwareConfiguration& iConfig, 
                         const unsigned char* iBuffer,
                         CATULONG32 iBufferSize);
#endif
protected:

  inline HRESULT FindAttribute(CATCGMTessCacheAttribute*& oAttrib) const;
  HRESULT FindOrCreateAttribute(CATCGMTessCacheAttribute*& oAttrib, CATBoolean iCreateIfNotFound);
  HRESULT AddNewAttribute(CATCGMTessCacheAttribute*& oAttrib);
  double Resolution() const;

protected:
  int _GeomVisu;
  double _Resolution;
  CATCell* _Cell;
  CATCGMTessCacheAttribute* _Attrib;

public:
	CATTessellateParamCacheContainer* _TessParamCacheContainer;
};

inline 
CATTessCacheAccess::CATTessCacheAccess()
:_Cell(0), _Attrib(0), _Resolution(-1.0), _GeomVisu(0)
{
	_TessParamCacheContainer = CATTessellateParamCacheContainer::GetTessellateParamCacheContainer();
}

inline void 
CATTessCacheAccess::SetGeomVisu(int iGeomVisu)
{
	if (iGeomVisu==0 || iGeomVisu==1)
		_GeomVisu = iGeomVisu;
}

inline void 
CATTessCacheAccess::SetCell(CATCell& iCell)
{
  _Attrib = 0;
  _Cell = &iCell;
}

inline HRESULT
CATTessCacheAccess::FindAttribute(CATCGMTessCacheAttribute*& oAttrib) const
{
  return ((CATTessCacheAccess*)this)->FindOrCreateAttribute(oAttrib, FALSE);
}

#endif
