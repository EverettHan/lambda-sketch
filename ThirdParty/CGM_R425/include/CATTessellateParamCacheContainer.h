/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Inheritance
// -----------
// CATTessellateParamCacheContainer
//
//==============================================================================
// Abstract
// --------
// CATTessellateParamCacheContainer administers a collection of tessellation settings
// to factorize their storage 
//
// The collection token are addref/released to permit data factorization
// in a safe way.
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
#ifndef CATTessellateParamCacheContainer_H
#define CATTessellateParamCacheContainer_H

#include "ExportedByTessellateCommon.h"
#include "CATCGMEvents.h"
#include "CATTessSettings.h"
#include "CATListPV.h"
#include "CATMapOfPtrToPtr.h"

/* CATTessellateParamCache
 * This is the database token. When you entry a set in the collection, the cache
 * returns you a reference on this token. You must use it to release the entry.
 * You also can use it to compare settings.
 */
class CATTessellateParamCache;
class CATTessellateIDDeltaParams;
class CATTessellatePolyID;
class CATSoftwareConfiguration;
class CATCGMMemoryManager;
class CATCell;
class CATTessDataCache;
class CATICGMSession;
class CATGeoFactory;
class CATCGMStream;
class CATCGMTessBody;

#ifndef CATTessellateParamCacheContainerFactory_H

/* IsSettingsEquals
 * Return whether iBaseSettings can be considered identical to iSettings
 */
int AreSettingsEquals(CATTessellateParamCache* iBaseSettings, const CATTessSettings& iTessSettings, double iResolution);

#endif

class ExportedByTessellateCommon CATTessellateParamCacheContainer : public CATCGMEventImplicitFactoryLife 
{
public:

  /* AddSettings
   * Add a settings set to the collection.
   * It won't duplicate information if the set is already present.
   * Take care to remove settings when they are not needed anymore.
   */
   CATTessellateParamCache* AddTessellateParamCache(const CATTessellateParamCache& iParamCache, double iResolution);

  /* RemoveSettings
   * Remove the settings set from the collection.
   */
   void RemoveSettings(CATTessellateParamCache* iBaseSettings);

  /* AddTessellateID
   * Add a TessellateID set to the collection.
   * It won't duplicate information if the set is already present.
   * Take care to remove TessellateID when they are not needed anymore.
   */
   CATTessellateIDDeltaParams* AddTessellateID(const void* iCachePtr, int iOrientation, CATListOfDouble * iListOfDeltaParams);

  /* RemoveTessellateID
   * Remove the TessellateID set from the collection.
   */
   void RemoveTessellateID(CATTessellateIDDeltaParams* iBaseTessellateID);
   
   /* AddTessellateID
   * Add a TessellateID set to the collection.
   * It won't duplicate information if the set is already present.
   * Take care to remove TessellateID when they are not needed anymore.
   */
   CATTessellatePolyID* AddTessellateID(long CellTag , int iOrientation);

   /* RemoveTessellateID
   * Remove the TessellateID set from the collection.
   */
   void RemoveTessellateID(CATTessellatePolyID* iBaseTessellateID);
   
   /* GetMemoryManager
   * Get the centralized memory manager for tessellation and scene graph.
   * The memory manager is owned by this.
   */
   CATCGMMemoryManager* GetMemoryManager();

  /* SetTessBody & GetTessBody: give/retrieve the current TessBody for optimization
   */
   void SetTessBody(CATCGMTessBody* iTessBody);
   CATCGMTessBody* GetTessBody(); // should be released by the caller

  /* GetSession
   */
   CATICGMSession* GetSession();

  /* GetTessSettingsCache
   * Get the static manager of settings.
   * You must release it.
   */
   static CATTessellateParamCacheContainer* GetTessellateParamCacheContainer();
   
  /*
   */
   void Release();
   
   // Cache handling
   HRESULT RegisterDeltaCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, double iResolution, CATCell* iCell, const CATTessDataCache* iDeltaCache=0); // iDeltaCache=0 if empty delta cache
   HRESULT GetDeltaCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, double iResolution, CATCell* iCell, const CATTessDataCache*& oDeltaCache); // oDeltaCache=0 if empty delta cache, else oDeltaCache to be released by caller
   CATBoolean LocateDeltaCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, double iResolution, CATCell* iCell, const CATTessDataCache*& oDeltaCache); // if located and oDeltaCache=0 -> empty delta cache 
   HRESULT UnregisterDeltaCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, double iResolution, CATCell* iCell);

   HRESULT RegisterDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, double iResolution, CATCell* iCell, const CATTessDataCache* iDataCache=0); // iDataCache=0 if empty delta cache
   HRESULT GetDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, double iResolution, CATCell* iCell, const CATTessDataCache*& oDataCache); // oDataCache=0 if empty delta cache, else oDataCache to be released by caller
   CATBoolean LocateDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, double iResolution, CATCell* iCell, const CATTessDataCache*& oDataCache); // if located and oDataCache=0 -> empty delta cache 
   HRESULT UnregisterDataCache(const CATTessellateParamCache& iParam, CATSoftwareConfiguration& iConfig, double iResolution, CATCell* iCell);
   
   // Cache access optimization: to avoid doing Cell->GetContainer() while cache handling -> make sure that the Cell belongs to the same Factory before accessing its cache 
   void SetCurrentFactory(CATGeoFactory *iFactory); // iFactory = Cell->GetContainer() or Body->GetContainer()
   void ResetCurrentFactory();

   // Cache flushing
   void EmptyFactoryDataCache(CATGeoFactory *iFactory);
   void EmptyFactoryDeltaCache(CATGeoFactory *iFactory);
   void EmptyMapFactoryToCacheContainer();

   /* ImplicitFactoryLife
   * Subscriber USE : get information about ImplicitFactoryLife
   * notification whenever a Factory is created/closed
   */
  //
  virtual void Creating(CATGeoFactory *iFactory);

  // Icontext   -1 : before RemoveAll,    +1 : after closing
  virtual void Closing(CATGeoFactory *iFactory, short iContext);

  // Icontext   -1 : before UnStreaming,    +1 : before Freezing
  virtual void UnStreaming(CATGeoFactory *iFactory, CATCGMStream* ipStr, short iContext);

  // Icontext   -1 : before Streaming,    +1 : after Streaming
  virtual void Streaming(CATGeoFactory *iFactory, CATCGMStream* ipStr, short iContext);

private:
   CATTessellateParamCacheContainer(CATICGMSession *iSession = 0);
   virtual ~CATTessellateParamCacheContainer();
   
   CATCGMTessBody* _TessBody;

   CATICGMSession *_Session;
   CATGeoFactory *_CurrentFactory;

   unsigned int m_unRef;
   CATRawCollPV m_SettingsList;
   CATRawCollPV m_CATTessellateIDDeltaParamsList;
   CATRawCollPV m_CATTessellatePolyIDList;

   CATCGMMemoryManager* m_pMemoryManager;

   CATMapOfPtrToPtr m_CATMapFactoryToCacheContainer;

   static CATTessellateParamCacheContainer* ms_pTessellateParamCacheContainer;
};

#endif // CATTessellateParamCacheContainer_H
