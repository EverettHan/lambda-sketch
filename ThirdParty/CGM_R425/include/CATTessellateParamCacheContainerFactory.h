/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Inheritance
// -----------
// CATTessellateParamCacheContainerFactory
//
//==============================================================================
// Abstract
// --------
// CATTessellateParamCacheContainerFactory administers cell's tessellation cache
// within a specific factory
//
//==============================================================================
// Usage
// -----
// 
//==============================================================================
// History
// -------
// Jan 2017  Creation: TPG
//==============================================================================
#ifndef CATTessellateParamCacheContainerFactory_H
#define CATTessellateParamCacheContainerFactory_H

#include "ExportedByTessellateCommon.h"
#include "CATCGMEvents.h"
#include "CATTessSettings.h"
#include "CATListPV.h"
#include "CATMapOfPtrToPtr.h"
#include "CATListPV.h"


class CATTessellateParamCache;
class CATTessellateIDCachePtr;
class CATListPtrCATCell;
class CATSoftwareConfiguration;
class CATCGMMemoryManager;
class CATCell;
class CATTessDataCache;
class CATGeoFactory;

/* IsSettingsEquals
 * Return whether iBaseSettings can be considered identical to iSettings
 */
int AreSettingsEquals(CATTessellateParamCache* iBaseSettings, const CATTessSettings& iTessSettings, double iResolution);


class ExportedByTessellateCommon CATTessellateParamCacheContainerFactory : public CATCGMEventRemoveComponent 
{
public:
   CATTessellateParamCacheContainerFactory(CATGeoFactory* iGeoFactory = 0);
   virtual ~CATTessellateParamCacheContainerFactory();

  /* ComponentLife
   * Subscriber USE : get information about RemoveComponent
   * notification whenever a CGM object is deleted
   */
   virtual void ComponentLife(CATICGMUnknown *iComponent);

   // Cache optimization
   HRESULT RegisterDeltaCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATCell* iCell, const CATTessDataCache* iDeltaCache=0); // iDeltaCache=0 if empty delta cache
   HRESULT GetDeltaCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATCell* iCell, const CATTessDataCache*& oDeltaCache); // oDeltaCache=0 if empty delta cache, else oDeltaCache to be released by caller
   CATBoolean LocateDeltaCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATCell* iCell, const CATTessDataCache*& oDeltaCache); // if located and oDeltaCache=0 -> empty delta cache 
   HRESULT UnregisterDeltaCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATCell* iCell);
   void EmptyMapCellToDeltaCache();

   HRESULT RegisterDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATCell* iCell, const CATTessDataCache* iDataCache=0); // iDataCache=0 if empty delta cache
   HRESULT GetDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATCell* iCell, const CATTessDataCache*& oDataCache); // oDataCache=0 if empty delta cache, else oDataCache to be released by caller
   CATBoolean LocateDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATCell* iCell, const CATTessDataCache*& oDataCache); // if located and oDataCache=0 -> empty delta cache 
   HRESULT UnregisterDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, CATCell* iCell);
   void EmptyMapCellToDataCache();

	 inline CATGeoFactory * GetGeoFactory() const;

private:
   CATMapOfPtrToPtr m_CATMapCellToDataCache;
   CATMapOfPtrToPtr m_CATMapCellToDeltaCache;
   CATGeoFactory* _GeoFactory;
};

inline CATGeoFactory * CATTessellateParamCacheContainerFactory::GetGeoFactory() const
{
	return _GeoFactory;
}

#endif // CATTessellateParamCacheContainerFactory_H
