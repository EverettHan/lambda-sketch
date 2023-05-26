/*
 * CATOmyOfflineDataAccess.h
 *
 *  Created on: Apr 22, 2013
 *      Author: PJQ
 */

#ifndef CATOMYOFFLINEDATAACCESS_H_
#define CATOMYOFFLINEDATAACCESS_H_

#include "CATOMYBaseSession.h"
#include "CATUnicodeString.h"
#include "CATIOmxBinaryStream.h"
#include "CATOmxMutex.h"
#include "CATOmyAppsDefinitions.h"
class CATBinary;
class CATIOmyOfflineDataAccess_var;

/**
 * Api to manage applicative data necessary for offline usage. If you need to add your
 * own applicative data, please contact us. Don't ever use someone else data !
 *
 * Note that this api will work even if offline is not available in your session. You can
 * therefore use it as a cache for your data. If offline is active, the data is read/written
 * to an archive file at each access. No in memory caching is done.
 *
 * Important note: you should only use those apis in a symetric manner with Get and Set
 * methods or it will fail...
 *
 * Basic pattern:
 * <code>
 * // First, you must retrieve your application key. Note that it will only work once, so you
 * // must keep the key in a static variable. If you call GetOfflineDataKey a second time with
 * // the same application name, you will get 0 in return and the other methods in the api will fail.
 * // Nobody should touch your data. You should assert if you get 0 with this pattern !
 * static CATOmyOfflineDataKey myDataKey = CATOmyOfflineDataAccess::GetOfflineDataKey("MyData");
 * CATAssert(myDataKey);
 *
 * char * data=NULL;
 * int dataSize = 0;
 * if(CATOmyOnlineOfflineSwitch::IsOnline() && S_FALSE == CATOmyOfflineDataAccess::HasOfflineData(myDataKey))
 * {
 *   // your own way to get the real data, via CATHttpClient or MyApps calls
 *   // ...
 *   CATOmyOfflineDataAccess::SetOfflineData(myDataKey, data, dataSize);
 * }
 * else
 * {
 *   CATOmyOfflineDataAccess::GetOfflineData(myDataKey, data, dataSize);
 * }
 * // Use your data, but don't forget to clean it with delete [] or equivalent
 * CATSysDeleteTab(data);
 * </code>
 *
 * Aternatively, you may implement an object inheriting from @CATOmyOfflineData that will streamline this pattern.
 * See further down this file form more information on CATOmyOfflineData.
 */
typedef unsigned int CATOmyOfflineDataKey;

class DSYSysPath;
typedef void* DSYSysRscHandle;

class ExportedByCATOMYBaseSession CATOmyAppsOfflineDataAccessTS
{
  static CATOmx::mutex & mutex() { static CATOmx::mutex sMutex; return sMutex; } //Reading & writing
protected:
  CATBoolean FirstCall() { static CATBoolean FirstCall = 1; CATBoolean ret = FirstCall; FirstCall = FALSE; return ret; } //We don't keep the cache from a run to another
public:
  CATOmyAppsOfflineDataAccessTS() { mutex().lock(); } //instanciate this class once before calling multiple time reading or writing functions not to have serious performance issue
  ~CATOmyAppsOfflineDataAccessTS() { mutex().unlock(); }
  HRESULT EraseBundleContentIfFirstCall(); // Reinitialize the bundle only if it's the first call. This is done because there is no versioning mecanism on resource
  static CATUnicodeString& BundleRelativePath() { static CATUnicodeString sBundlePath = CATUnicodeString("ServerRsc") + OMX_DIR_SEP_STR + "MyApps" + OMX_DIR_SEP_STR; return sBundlePath; }
  static CATUnicodeString& BundleName() { static CATUnicodeString sBundleName = "icons.DSYRsc"; return sBundleName; }
  HRESULT GetBundlePathAndName(DSYSysPath &oPath); //Absolute path
  HRESULT GetBundlePath(DSYSysPath &oPath); //Absolute path
};

class ExportedByCATOMYBaseSession CATOmyAppsOfflineDataAccessTSForWrite : public CATOmyAppsOfflineDataAccessTS
{
public:
  CATOmyAppsOfflineDataAccessTSForWrite();
  ~CATOmyAppsOfflineDataAccessTSForWrite();
  HRESULT SetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey, const CATBinary & iData);
private:
  HRESULT InitializeWrite();
  HRESULT FinalizeWrite();
  CATBoolean _initialized;
};

class ExportedByCATOMYBaseSession CATOmyAppsOfflineDataAccessTSForRead : public CATOmyAppsOfflineDataAccessTS
{
public:
  CATOmyAppsOfflineDataAccessTSForRead();
  ~CATOmyAppsOfflineDataAccessTSForRead();
  /*
  * Same as below. Same behavior, but for MyApps.
  * The main difference is that the archive used is a DSYSysRscTools (see header for more information).
  * This resource handle supports well asynchronism. The methods on CATOmyOfflineDataAccess use a a CATIStorage, through CATBaseUnknown casts.
  * This is NOT thread safe, as CBU and CAT_DYNAMIC_CAST etc. are not threadsafe.
  * Only using this method is thread safe
  */

  HRESULT HasOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey);
  HRESULT GetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey, CATBinary & oData);
private:
  HRESULT InitializeOpen();
  HRESULT OpenRsc(DSYSysRscHandle &iHandle, const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey);
  HRESULT FinalizeOpen();
  void **_ppOpenedBundleHandler;
};

class ExportedByCATOMYBaseSession CATOmyOfflineDataAccess
{
public:
  /**
   * Retrieves the CATOmyOfflineDataKey for a given data name. This key will be used to
   * to access your data with the other methods in this api. Note that this method should
   * only be called once per session. Subsequent calls will lead to invalid (null) keys.
   * @param iDataName [in]
   *   The name for your data. Note that the authorized values are limited.
   *   Please contact us if you need to keep some data for offline.
   * @return
   *   A key to be used is the other mehtods of this api. A valid key is not null.
   */
  static CATOmyOfflineDataKey GetOfflineDataKey(const CATUnicodeString & iDataName);

  /**
   * Overwrites the offline data for the given key. If you don't want to overwrite,
   * check it availability through HasOfflineData first. You should use the GetOfflineData
   * with char * and unsigned int to retrieve your data.
   * @param iDataKey [in]
   *   The key for your data. Retrieved once through @GetOfflineDataKey.
   * @param iData [in]
   *   A valid pointer to the data you may want to keep for offline usage.
   * @param iDataSize [in]
   *   The size of the data you want to keep. You must ensure that those
   *   two inputs are coherent.
   * @return
   *   S_OK if the data was set for the first time.
   *   S_FALSE if the data has been set but some data was previously there.
   *   E_* if an error occured. It can be that your key or your data is invalid.
   */
  static HRESULT SetOfflineData(const CATOmyOfflineDataKey iDataKey, const char * iData, const unsigned int iDataSize);

  /**
   * Same as previous but with a sub key associated to it. Note that you may have data associated to the key
   * and some other data associated the key+subKey. No check is done on the sub keys.
   * @param iSubKey [in]
   *   The sub key for your data.
   * Other params and return values are identical.
   */
  static HRESULT SetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey, const char * iData, const unsigned int iDataSize);

  /**
   * Same as previous using a CATBinary. You should use the GetOfflineData with CATBinary to retrieve your data.
   */
  static HRESULT SetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATBinary & iData);
  static HRESULT SetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey, const CATBinary & iData);

  /**
   * Same as previous using a CATIOmxBinaryStream. You should access
   * the result through the GetOfflineData api also using a CATIOmxBinaryStream.
   */
  static HRESULT SetOfflineData(const CATOmyOfflineDataKey iDataKey, CATIOmxBinaryStream * iData);
  static HRESULT SetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey, CATIOmxBinaryStream * iData);

  /**
   * Check if some data is already available. This may be useful to use this infrastructure has
   * a cache for accessing 'pseudo constant' online data
   * @param iDataKey [in]
   *   The key for your data. Retrieved once through @GetOfflineDataKey.
   * @return
   *   S_OK if the information is available.
   *   S_FALSE if no data is available for the given key
   *   E_* if an error occured. It can be that your key is invalid.
   */
  static HRESULT HasOfflineData(const CATOmyOfflineDataKey iDataKey);

  /**
   * Same as previous but with a sub key associated to it. Note that you may have data associated to the key
   * and some other data associated the key+subKey. No check is done on the sub keys.
   * @param iSubKey [in]
   *   The sub key for your data.
   * Other params and return values are identical.
   */
  static HRESULT HasOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey);

  /**
   * Retrieves the offline data for the given key. Note that it can be used both in online and offline mode.
   * The data must have been set using SetOfflineData with char * and unsigned int inputs.
   * @param iDataKey [in]
   *   The key for your data. Retrieved once through @GetOfflineDataKey.
   * @param oData [out] @delete tab
   *   A valid pointer to the data kept for offline usage. Shoud be given with a NULL value.
   *   Should be deleted after use through delete [] or equivalent.
   * @param oDataSize [out]
   *   The size of the retrieved data.
   * @return
   *   S_OK if some data was retrived.
   *   S_FALSE if no data was retrieved.
   *   E_* if an error occured. It can be that your key is invalid.
   */
  static HRESULT GetOfflineData(const CATOmyOfflineDataKey iDataKey, char *& oData, unsigned int & oDataSize);

  /**
   * Same as previous but with a sub key associated to it. Note that you may have data associated to the key
   * and some other data associated the key+subKey. No check is done on the sub keys.
   * @param iSubKey [in]
   *   The sub key for your data.
   * Other params and return values are identical.
   */
  static HRESULT GetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey, char *& oData, unsigned int & oDataSize);

  /**
   * Same as previous using a CATBinary.
   * The data must have been set using SetOfflineData with CATBinary input.
   */
  static HRESULT GetOfflineData(const CATOmyOfflineDataKey iDataKey, CATBinary & oData);
  static HRESULT GetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey, CATBinary & oData);

  /**
   * Same as previous using a CATIOmxBinaryStream.
   * The data must have been set using SetOfflineData with CATIOmxBinaryStream input.
   * @param oData [out]
   *   A valid pointer to a CATIOmxBinaryStream where you want your data.
   */
  static HRESULT GetOfflineData(const CATOmyOfflineDataKey iDataKey, CATIOmxBinaryStream * oData);
  static HRESULT GetOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey, CATIOmxBinaryStream * oData);
private:
  static CATOmx::mutex & mutex() { static CATOmx::mutex sMutex; return sMutex; }
};

/**
 * Base class that can be derived from in order to easily acces offline data. You must at least implement
 * one of the GetOnlineData.
 *
 * Basic example :
 * class MyOfflineData : public CATOmyOfflineData
 * {
 * public:
 *   MyOfflineData()
 *   {
 *     static CATOmyOfflineDataKey myKey = CATOmyOfflineDataAccess::GetOfflineDataKey("MyData");
 *     SetOfflineDataKey(myKey);
 *   }
 *
 *   HRESULT GetData(CATUnicodeString & oData);
 *   {
 *     // you should handle errors correctly, not like this sample !!!
 *     char * data= NULL; unsigned int dataSize = 0;
 *     HRESULT hr = GetOfflineData(data, dataSize);
 *     oData.BuildFromUTF8(data, dataSize);
 *     return hr;
 *   }
 *
 * private:
 *   HRESULT GetOnlineData(char *& oData, unsigned int & oDataSize)
 *   {
 *     // Your very complex work. Leading, for example to a CATUnicodeString
 *     CATUnicodeString myDataAsString;
 *     oData = new char[4*myDataAsString.GetLengthInChar()+1];
 *     size_t realSize=0;
 *     myDataAsString.ConvertToUTF8(oData, realSize);
 *     oDataSize=realSize;
 *     return S_OK;
 *   }
 * };
 *
 * // Later in your code:
 * MyOfflineData myOfflineData;
 * CATUnicodeString myValue;
 * myOfflineData.GetData(myValue);
 */
class ExportedByCATOMYBaseSession CATOmyOfflineDataBase
{
protected:
  CATOmyOfflineDataKey _key;
  CATUnicodeString _subkey;
public:
  CATOmyOfflineDataBase(const CATOmyOfflineDataKey iDataKey = 0)
    :_key(iDataKey)
  {
  }
  CATOmyOfflineDataBase(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey)
    :_key(iDataKey), _subkey(iSubKey)
  {
  }
  virtual ~CATOmyOfflineDataBase() {}

  /**
   * Sets the offline key to use. Only useful if you didn't set any valid value in the constructor.
   */
  HRESULT SetOfflineDataKey(const CATOmyOfflineDataKey iDataKey);
  HRESULT SetOfflineDataKey(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey);
};

class ExportedByCATOMYBaseSession CATOmyOfflineData : public CATOmyOfflineDataBase
{
public:
  CATOmyOfflineData(const CATOmyOfflineDataKey iDataKey = 0)
    :CATOmyOfflineDataBase(iDataKey)
  {
  };
  CATOmyOfflineData(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey)
    :CATOmyOfflineDataBase(iDataKey, iSubKey)
  {
  };

   /**
    * Retrieves the offline data. If online, the data may queried through one of the GetOnlineData
    * You should overload at least one of them.
    * @param oData [out] @delete tab
    *   A valid pointer to the data kept for offline usage. Shoud be given with a NULL value.
    *   Should be deleted after use through delete [] or equivalent.
    * @param oDataSize [out]
    *   The size of the retrieved data.
    * @param iUseCache [in]
    *   If set to true and the data is already set in the offline cache, the data won't be retrieved
    *   even if the session is online.
    * @return
    *   S_OK if some data was retrived.
    *   S_FALSE if offline and no data was saved for this key.
    *   E_* if an error occured. It can be that your key is invalid or that it was not possible to get the online data.
    */
  HRESULT GetOfflineData(char *& oData, unsigned int & oDataSize, CATBoolean iAlwaysUseCache = TRUE);


protected:
  /**
   * Method called while online to really retrieve/compute the value you want to keep for offline usage.
   * @return
   *    S_OK in case of success and the result should be kept,
   *    S_FALSE in case of success and the result should NOT be kept,
   *    E_... in case of failure (forwarded to GetOfflineData result)
   */
  virtual HRESULT GetOnlineData(char *& oData, unsigned int & oDataSize) = 0;
};

/**
 * Same as previous but using a CATBinary for access
 */
class ExportedByCATOMYBaseSession CATOmyOfflineDataForBinary : public CATOmyOfflineDataBase
{
public:
  CATOmyOfflineDataForBinary(const CATOmyOfflineDataKey iDataKey = 0)
    :CATOmyOfflineDataBase(iDataKey)
  {
  };
  CATOmyOfflineDataForBinary(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey)
    :CATOmyOfflineDataBase(iDataKey, iSubKey)
  {
  };

   /**
    * Retrieves the offline data. If online, the data may queried through one of the GetOnlineData
    * You should overload at least one of them.
    * @param oData [out] @delete tab
    *   A valid pointer to the data kept for offline usage. Shoud be given with a NULL value.
    *   Should be deleted after use through delete [] or equivalent.
    * @param oData [out]
    *   The data.
    * @return
    *   S_OK if some data was retrived.
    *   S_FALSE if offline and no data was saved for this key.
    *   E_* if an error occured. It can be that your key is invalid or that it was not possible to get the online data.
    */
  HRESULT GetOfflineData(CATBinary & oData, CATBoolean iAlwaysUseCache = TRUE);

protected:
  /**
   * Method called while online to really retrieve/compute the value you want to keep for offline usage.
   * @return
   *    S_OK in case of success and the result should be kept,
   *    S_FALSE in case of success and the result should NOT be kept,
   *    E_... in case of failure (forwarded to GetOfflineData result)
   */
  virtual HRESULT GetOnlineData(CATBinary& oData) = 0;
};

/**
 * Same as previous class but using a CATIOmxBinaryStream for access
 */
class ExportedByCATOMYBaseSession CATOmyOfflineDataForStream : public CATOmyOfflineDataBase
{
public:
  CATOmyOfflineDataForStream(const CATOmyOfflineDataKey iDataKey = 0)
    :CATOmyOfflineDataBase(iDataKey)
  {
  };
  CATOmyOfflineDataForStream(const CATOmyOfflineDataKey iDataKey, const CATUnicodeString & iSubKey)
    :CATOmyOfflineDataBase(iDataKey, iSubKey)
  {
  };

   /**
    * Retrieves the offline data. If online, the data may queried through one of the GetOnlineData
    * You should overload at least one of them.
    * @param oData [out]
    *   A valid pointer to a CATIOmxBinaryStream where you want your data.
    * @return
    *   S_OK if some data was retrived.
    *   S_FALSE if offline and no data was saved for this key.
    *   E_* if an error occured. It can be that your key is invalid or that it was not possible to get the online data.
    */
  HRESULT GetOfflineData(CATIOmxBinaryStream * oData, CATBoolean iAlwaysUseCache = TRUE);

protected:
  /**
   * Method called while online to really retrieve/compute the value you want to keep for offline usage.
   * @return
   *    S_OK in case of success and the result should be kept,
   *    S_FALSE in case of success and the result should NOT be kept,
   *    E_... in case of failure (forwarded to GetOfflineData result)
   */
  virtual HRESULT GetOnlineData(CATIOmxBinaryStream * oData) = 0;
};
#endif /* CATOMYOFFLINEDATAACCESS_H_ */
