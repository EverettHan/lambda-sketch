/* -*-c++-*- */
//*===========================================================================*
//* COPYRIGHT DASSAULT SYSTEMES 2005                                          *
//*===========================================================================*
//*                                                                           *
//*                                                                           *
//*  Usage Notes:                                                             *
//*===========================================================================*
//*  Aug 2005  Creation                                               cfo     *
//*===========================================================================*

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATOmyExposedCacheServices_H
#define CATOmyExposedCacheServices_H

 //  NULL  
#ifndef  NULL  
#define  NULL  0  
#endif  

#include "CATOMYUtils.h"
#include "CATOmyCioTypeOfCaches.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATMD5.h"
#include "CATOmxArray.h"
#include "CATOmyResourceReference.h"
#include "CATIAV5Level.h"

class CATVVSUrl;
class CATUnicodeString;
class CATVVSURLConnection;
class CATCuteIOSettingsFrame;

class ExportedByCATOMYUtils CATOmyExposedCacheServices
{
  friend class CATOmyPowerIOCachingBusinessLogic;
  friend class CATCuteIOSettingsFrame;
  friend class SelectiveLoading_Collab;
  friend class CATPLMCollabStreamData;
  friend class CacheLocationTester;
  friend class CATPLMAppIdQueryCache;
  friend class CATOmbStreamDescriptorObjectImpl;
  friend class CATOmyCachingDirectoryMngt;
  friend class CATOmbOxiTestCase;

public:

  /**
   * Generates an unique URL.
   * @param oUrl [out]
   *   The generated URL.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL;
   */
  static HRESULT RetrieveAnUniqueUrlKey(CATVVSUrl& oUrl);

  /**
   * Register a new cache file vault site.
   * If a vault site with the same name exists, return only the index.
   * @param iCacheName [in]
   *   The name of the vault site.
   * @param oIndex [out]
   *   The index of the vault site.
   *
   * @return
   *  <UL>
   *    <LI><code>S_OK</code> if everything ran ok.</LI>
   *    <LI><code>E_FAIL</code> if an error occurs.</LI>
   *  </UL>
   */
  static HRESULT RegisterTemporaryCacheFileVaultSite(const CATUnicodeString & iCacheName, int & oIndex);

  /**
   * Return the index of a registered vault site
   * @param iCacheName [in]
   *   The name of the vault site.
   * @param oIndex [out]
   *   The index of the vault site.
   *
   * @return
   *  <UL>
   *    <LI><code>S_OK</code> if everything ran ok.</LI>
   *    <LI><code>E_FAIL</code> if an error occurs or if a vault site with the given name dos not exist.</LI>
   *  </UL>
   */
  static HRESULT FindIndexOfVaultSiteFromName(const CATUnicodeString & iCacheName, int & oIndex);

  /**
  * Delete a XMM cached stream associated with an URL.
  * @param iUrlToDelete [in]
  *   The URL associated to the stream.
  * @param iWaterMarkstamp [in]
  *   The WaterMarkStamp of the stream
  * @param iLateType [in]
  *   The lateType of the stream.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL;
  */
  static HRESULT DeleteUrlInXMMCache(const CATVVSUrl& iUrlToDelete, int iWaterMarkstamp, const CATUnicodeString& iLateType);

  /**
  * Tests if there is a stream cached in CuteIO for a given URL.
  * @param iUrl [in]
  *   The Url to test
  * @param iWs [in]
  *   The timestamp associated to the URL
  * @param iLateType [in]
  *   The late type of the stream
  * @param iTypeOfCache [in]
  *   The type of cache where the stream mmust be streamed
  * @param InFile [in]
  *   <UL>
  *       <LI>NULL: All cache implementation is tested.</LI>
  *       <LI>TRUE: only the file implementation of the given cache is tested.</LI>
  *       <LI>FALSE: only the not file implementation of the given cache is tested.</LI>
  *   </UL>
  * @return
  *   <UL>
  *     <LI>TRUE: there is a stream associated with the given URL.</LI>
  *     <LI>FALSE: there is no stream associated with the given URL</LI>
  *   </UL>
  */
  static CATBoolean HasThisURLBeenStreamed(const CATVVSUrl& iUrl, int iWs, CATUnicodeString& iLateType, CATOmyCioTypeOfCache iTypeOfCache, CATBoolean* InFile = NULL);
  static CATBoolean HasThisURLBeenStreamed(const CATOmyResourceReference& isrcRef, CATOmyCioTypeOfCache iTypeOfCache, CATBoolean* InFile = NULL);

  /*
  * Project iURLConnection in TemporaryCache (registered in CutesIO's MakeDefaultRegistration)
  * and return projected url (oUrl).
  * NB : TemporaryCache has a transient lifecycle (is flushed when ending unregistrering vault sites).
  */
  static HRESULT ProjectUrlConnectionToTemporaryCache(CATVVSURLConnection* pURLConnection, CATUnicodeString& iFileName, CATVVSUrl& oUrl);

#ifndef CATIAR423
  // Do not use.
  static void Activate3DSearchModeForPowerIOCache3DSearch() {}
  static void ActivateCATIAModeForPowerIOCache3DSearch() {}
  static HRESULT MergeCATIAIndexForPowerIOCache3DSearch() { return E_FAIL; }
#endif

  /**
  * For LargeFile, returns whether the VaultSite in charge of the input Url support Hard Link
  * @param iUrl [in]
  *   Url
  * @return
  *   <UL>
  *    <LI><code>S_OK</code> the vault site support hard link.</LI>
  *    <li><code>S_FALSE</code>: the vault site does not support Hard Link.</li>
  *     <li><code>E*</code>: unexpected error.</li>
  *   </UL>
  */
  static HRESULT SupportHardLink(CATVVSUrl & iUrl);

  /**
  * This service enables some specific customer (Indexer, CATLnk checker), to set a specific path for the cache.
  * All of their sub processes can work with a dedicated cache.
  * This service must be called before connection to the server
  * Do not use without contacting us. This may corrupt the cache and customer data
  *
  * @return
  *   <code>S_OK</code> cache path set and will be used,
  *   <code>E_*</code> cache has already been created with the default cache path
  */
  static HRESULT ForceCachePath(CATUnicodeString& iCachePath);

  /**
  * This service enables some specific customer (PLMBatch) to force the cache to be deleted at the end of process.
  * This service must be called before connection to the server
  * Do not use without contacting us. This may corrupt the cache and customer data
  *
  * @return
  *   <code>S_OK</code> cache will be deleted at the end of process
  *   <code>E_*</code> cache has already been created with the default cache path
  */
  static HRESULT ForceCacheToBeTransient();

  /**
  * Get list of MD5 corresponding to the input url list.
  * Because MD5s are stored in the PLMCache of streams, each URL of the list must be already indexed in the cache.
  * @return
  *   <code>S_OK</code> all urls have been found in cache and all corresponding cache files have a valid MD5
  *   <code>E_FAIL</code> some urls have not been found in the cache or some corresponding cache files have not a valid MD5
  */
  static HRESULT GetMD5sInCache(CATOmxArray<CATOmyResourceReference> & iUrls, CATOmxArray<CATMD5> & oMD5s);
  /**
  * Duplicate the key (CATOmyResourceReference) to access cache Url.
  * @param
  *   iSrcAlreadyIndexed = first array of CATOmyResourceReference to duplicate (already exist in cache)
  *   iSrcAlreadyIndexed = second array of iSrcToBeIndexed to duplicate to (they will act as a spare key to the same entry in cache)
  * @return
  *   <code>S_OK</code> all CATOmyResourceReference have been duplicated
  *   <code>E_FAIL</code> Some CATOmyResourceReference where not duplicated
  */
  static HRESULT DuplicateIndexedUrlInCache(const CATOmxArray<CATOmyResourceReference> & iSrcAlreadyIndexed, const CATOmxArray<CATOmyResourceReference> & iSrcToBeIndexed);

  static HRESULT GetCacheUrlFromConnection(CATVVSURLConnection& iConnection, CATVVSUrl & oCacheUrl);
private:
  /**
  * Get Temporary and Transient cache location
  */
  static HRESULT GetRootCacheTempDirectory(CATUnicodeString & oRootCacheDirectory);

  /**
  * For Collab ODT and Services Only
  * Convert an URLIndexed known to be in the cache to the URL pointing to the associated file in the cache...
  * Simplify version of OpenConnections
  * @param iIndexURL [in]
  *   Indexation Url of stream in cache (ie Vault URL / OMB Url)
  * @param iWs [in]
  *   The timestamp associated to the URL
  * @param iLateType [in]
  *   The late type of the stream
  * @param oCachedURL [out]
  *   The URL poiting the file in cache
  * @return
  *   <UL>
  *    <LI><code>S_OK</code> if everything ran ok.</LI>
  *    <LI><code>E_FAIL</code> if an error occurs.</LI>
  *   </UL>
  */
  static HRESULT FromIndexedUrlToPWCachedUrl(CATVVSUrl& iIndexURL, CATUnicodeString& iLateType, unsigned int iWs, CATVVSUrl& oCachedURL);
};

#endif
