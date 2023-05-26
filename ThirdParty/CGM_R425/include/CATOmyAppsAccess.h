/*
 * CATOmyMyAppsAccess.h
 *
 *  Created on: Oct 1, 2013
 *      Author: PJQ
 */

#ifndef CATOMYAPPSACCESS_H_
#define CATOMYAPPSACCESS_H_

#include "CATOMYBaseSession.h"
#include "CATSysErrorDef.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATOmxOHMap.h"
#include "CATOmxMapIter.h"
#include "CATBinary.h"
#include "CATOmxArray.h"

/**
 * Collection of utilities to retrieve information regarding the avaliable apps.
 * Those apis are not specially design to be thread safe.
 */
class CATOmyAppsInfosCB;
class CATOmyAppsResourcesCB;
class CATOmyFavoriteAppsCB;
class CATOmyAppsProvider;

class ExportedByCATOMYBaseSession CATOmyAppsAccess
{
public:
  static CATBoolean IsAsyncMyApps();

  enum RefreshMode{UseCache, ForceRefresh};

  /**
   * Retrieves the available apps. See @CATOmyAppsInfosCB for code sample.
   *
   * @param iCallBack [in]:
   *   an implementation of CATOmyAppsInfosCB that will be called once the
   *   necessary information has been retrieved.
   * @param iForceRefresh [in]:
   *   by default, the available apps informations are cached and therefore
   *   fetched only once. If necessary, you can force the refresh with the
   *   ForceRefresh flag.
   * @return
   *   S_OK if everything is OK
   *   E_FAIL if something went wrong
   */
  static HRESULT GetAvailableApps(
      CATOmyAppsInfosCB & iCallBack, RefreshMode RefreshMode=UseCache, CATOmyAppsProvider * iProvider = NULL);

  /**
   * Retrieves various resources for the apps based on their urls.
   *
   * @param iResourcesUrls [in]:
   *   list of urls for the resources to retrieve.
   * @param iCallback [in]:
   *   an implementation of CATOmyAppsResourcesCB that will be called once the
   *   necessary resources have been retrieved.
   * @param iWaitAllResources [in]:
   *   ressources will be returned once all retrieved in the callback if true (default).
   *   if false, resources will be returned each time a new one is retrieved
   * @param iForceRefresh [in]:
   *   by default, the resources are cached and therefore fetched only once. If
   *   necessary, you can force their refresh with the ForceRefresh flag.
   * @return
   *   S_OK if everything is OK
   *   E_FAIL if something went wrong
   */
  static HRESULT GetAppsResources(const CATListOfCATUnicodeString & iResourcesUrls,
      CATOmyAppsResourcesCB & iCallBack, CATBoolean iWaitAllResources = TRUE, RefreshMode RefreshMode=UseCache, CATOmyAppsProvider * iProvider = NULL);

  /**
   * Sets the given apps as favorites. The cached data for available apps is automatically updated if necessary.
   *
   * @param iFavoritesAppIds [in]:
   *   list of ids for the favorites apps.
   * @param iCallBack [in]:
   *   an implementation of CATOmyFavoriteAppsCB that will be called once the query is done.
   * @return
   *   S_OK if MyApps is available and everything is OK
   *   S_FALSE if MyApps is not available
   *   E_FAIL if something went wrong
   */
  static HRESULT SetFavoriteApps(const CATListOfCATUnicodeString & iFavoritesAppIds,
      CATOmyFavoriteAppsCB & iCallBack, CATOmyAppsProvider * iProvider = NULL);

  /**
   * Sets the given apps as active for role. The cached data for available apps is automatically updated if necessary.
   *
   * @param iActiveApps [in]:
   *   The apps which to set active.
   * @param iCallBack [in]:
   *   an implementation of CATOmyFavoriteAppsCB that will be called once the query is done.
   * @return
   *   S_OK if MyApps is available and everything is OK
   *   S_FALSE if MyApps is not available
   *   E_FAIL if something went wrong
   */
  static HRESULT SetAppsPreference(const CATListOfCATUnicodeString & iActiveApps, 
      CATOmyFavoriteAppsCB & iCallBack, CATOmyAppsProvider * iProvider = NULL);

  /**
   * @nodoc
   */
  static CATUnicodeString GetAppsDevelopmentSubDirInRTV();
};


/**
 * Callback object for CATOmyAppsAccess::GetAvailableApps.
 * You only have to implement OnAppsRetrieved.
 *
 * <code>
 * class MyAppsInfosCB : public CATOmyAppsInfosCB
 * {
 * public:
 *   void OnAppsInfosRetrieved(const CATOmyAppsInfos & iAppsInfos)
 *   {
 *      CATOmyAppsInfos::IteratorType iter = iAppsInfos.GetIterator();
 *      const CATOmyAppsInfo * appsInfos = NULL;
 *      while(appsInfos = iter.Next())
 *      {
 *        const CATBinary & appsInfosContent = appsInfos -> AppsInfosContent();
 *        CATOmyAppsInfo::AppsInfoOrigin appsInfosOrigin = appsInfos -> AppsInfosOrigin();
 *        //...
 *      }
 *   }
 * }
 * MyAppsInfosCB myAppsInfosCB;
 * CATOmyAppsAccess::GetAvailableApps(myAppsInfosCB);
 * // active wait for queries to be made...
 * </code>
 */
class CATOmyAppsInfos;
class ExportedByCATOMYBaseSession CATOmyAppsInfosCB : public CATBaseUnknown
{
public:
  /**
   * Method called once the apps informations are retrieved.
   *
   * @param iAppsInfos [in]: the available apps informations.
   */
  virtual void OnAppsInfosRetrieved(const CATOmyAppsInfos & iAppsInfos)=0;
};


/**
 * Unitary result of the apps infos queries.
 * See @CATOmyAppsInfosCB for a code sample.
 */
class ExportedByCATOMYBaseSession CATOmyAppsInfo
{
public:
  enum AppsInfoOrigin{MyApps=0, Packaging, Development, Unknown};

  inline CATOmyAppsInfo()
  :_appsInfosOrigin(Unknown)
  {
  }

  inline CATOmyAppsInfo(const char * iAppsInfosContent, unsigned int iAppsInfosContentSize, AppsInfoOrigin iAppsInfosOrigin)
  :_appsInfosContent(iAppsInfosContentSize, (const signed char*)iAppsInfosContent), _appsInfosOrigin(iAppsInfosOrigin)
  {
  }

  inline CATOmyAppsInfo(const CATBinary & iAppsInfos, AppsInfoOrigin iAppsInfosOrigin)
  :_appsInfosContent(iAppsInfos), _appsInfosOrigin(iAppsInfosOrigin)
  {
  }

  inline const CATBinary & AppsInfosContent() const
  {
    return _appsInfosContent;
  }

  inline AppsInfoOrigin AppsInfosOrigin() const
  {
    return _appsInfosOrigin;
  }

private:
  CATBinary _appsInfosContent;
  AppsInfoOrigin _appsInfosOrigin;
};
ExportedByCATOMYBaseSession CATOmxCollecManager &CATOmyAppsInfoCollecManager();


/**
 * Results of the apps infos queries.
 * See @CATOmyAppsInfosCB for a code sample.
 */
class ExportedByCATOMYBaseSession CATOmyAppsInfos
{
public:
  typedef CATOmxIter<const CATOmyAppsInfo> IteratorType;

  /**
   * Returns an iterator on the various apps informations available for the runtime.
   * See @CATOmyAppsInfosCB for a code sample.
   */
  inline IteratorType GetIterator() const
  {
    return _infos.Iterator();
  }

  /**
   * @nodoc
   */
  inline void Append(const CATOmyAppsInfo & iAppsInfo)
  {
    _infos.Append(iAppsInfo);
  }
private:
  CATOmxArray<CATOmyAppsInfo, CATOmyAppsInfoCollecManager> _infos;
};


/**
 * Callback object for CATOmyAppsAccess::GetAppsResources.
 * You only have to implement OnAppsInfosRetrieved.
 */
class CATOmyAppsRessources;
class ExportedByCATOMYBaseSession CATOmyAppsResourcesCB : public CATBaseUnknown
{
public:
  /**
   * Method called once the apps resources are retrieved.
   *
   * @param iAppsResources [in]:
   *   the retrieved apps resources.
   */
  virtual void OnAppsInfosRetrieved(const CATOmyAppsRessources & iAppsResources)=0;
};


/**
 * Structure to acces the result of the apps infos queries.
 */
class CATOmxCollecManager;
class ExportedByCATOMYBaseSession CATOmyAppsRessources
{
public:
  /**
   * Get the resource for a given url retrieved by CATOmyAppsAccess::GetAppsResources.
   *
   * @param iAppRessourceUrl [in]:
   *   the url of the resource
   * @param oAppRessourceData [out]:
   *   the resource's content.
   * @result
   *   S_OK if the resource has been found
   *   E_INVALIDARG if the resource hasn't been found
   */
  inline HRESULT GetAppRessource(const CATUnicodeString & iAppRessourceUrl, CATBinary & oAppResourceData) const
  {
    const CATBinary * bin = _resourcesData.Locate(iAppRessourceUrl);
    if(!bin)
      return E_INVALIDARG;
    oAppResourceData = *bin;
    return S_OK;;
  }

  /**
   * Returns an iterator on the collection.
   *
   * <code>
   * CATOmyAppsRessources::IteratorType iter = myAppsResources.GetIterator();
   * while(iter.Next())
   * {
   *   const CATUnicodeString & url =  iter.Key();
   *   CATBinary & resourceBinaryData = iter.Value();
   *   //...
   * }
   */
  typedef CATOmxMapIter< CATUnicodeString, CATBinary >  IteratorType;
  inline IteratorType GetIterator() const{return _resourcesData.MapIterator();}

  /**
   * @nodoc
   */
  inline void SetAppRessource(const CATUnicodeString & iAppRessourceUrl, const CATBinary & iAppResourceData)
  {
    _resourcesData.Replace(iAppRessourceUrl, iAppResourceData);
  }
private:
  static CATOmxCollecManager &CATBinaryCollecManager();
  CATOmxOHMap<CATUnicodeString, CATBinary, CATOmxDefaultCollecManager<CATUnicodeString>::manager, CATBinaryCollecManager> _resourcesData;
};

/**
 * Callback object for CATOmyAppsAccess::SetFavoriteApps.
 * You only have to implement OnAppsInfosRetrieved.
 */
class CATOmyAppsRessources;
class ExportedByCATOMYBaseSession CATOmyFavoriteAppsCB : public CATBaseUnknown
{
public:
  /**
   * Method called once the apps resources are retrieved.
   *
   * @param iSetFavoriteAppsResult [in]:
   *   the result of the set query to MyApps.
   * @param iQueryResultContent [in]:
   *   the content returned by the set query to MyApps. May be empty...
   * @param iAppsInfos [in]: the updated apps informations.
   */
  virtual void OnFavoriteAppsSet(const HRESULT & iSetFavoriteAppsResult, const CATBinary & iQueryResultContent, const CATOmyAppsInfos & iAppsInfos)=0;
};

template<> ExportedByCATOMYBaseSession CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxPair<CATUnicodeString,CATBinary> >::manager();  

#endif /* CATOMYMYAPPSACCESS_H_ */
