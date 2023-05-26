//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1998                                          
//===========================================================================
//                                                                           
//  CATCacheSetting                                                 
//                                                                           
//  Usage Notes: Class Definition                                             
//===========================================================================
//  Creation janvier 1999                                 adt         	
//===========================================================================
#ifndef __CATCACHESETTING
#define __CATCACHESETTING
#include "JS0MRSHL.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;
class CATSysCacheSettingCtrl;



class ExportedByJS0MRSHL CATCacheSetting : public CATEventSubscriber
{
public :
   /** @nodoc */
  CATDeclareCBEvent(Updated);

  static CATCacheSetting * CreateCacheSetting( HRESULT *hres=0);
  HRESULT SaveCacheSetting();
  HRESULT ResetCacheSetting();
  HRESULT RollBackCacheSetting();
  HRESULT CommitCacheSetting();
 
  /** Deprecated */
  unsigned long GetCacheMaxSize ();
  /** Deprecated */
  HRESULT SetCacheMaxSize (unsigned long iSize);
  unsigned int GetCacheMaxSizeMo ();
  HRESULT SetCacheMaxSizeMo (unsigned int iSize);
  /** Deprecated */
  char GetLockMaxSize ();
  HRESULT GetInfoMaxSize (CATSettingInfo* oInfo);
  HRESULT SetLockMaxSize (int iLock);
  
  int  GetActivationMode ();
  HRESULT SetActivationMode (int iMode);
  /** Deprecated */
  char GetLockActivationMode ();
  HRESULT GetInfoActivationMode (CATSettingInfo* oInfo);
  HRESULT SetLockActivationMode (int iLock);

  int  GetSizeControl ();
  HRESULT SetSizeControl (int iMode);
  /** Deprecated */
  char GetLockSizeControl ();
  HRESULT GetInfoSizeControl (CATSettingInfo* oInfo);
  HRESULT SetLockSizeControl (int iLock);


  int  GetTimestampMode ();
  HRESULT SetTimestampMode (int iMode);
  /** Deprecated */
  char GetLockTimestampMode ();
  HRESULT GetInfoTimestampMode (CATSettingInfo* oInfo);
  HRESULT SetLockTimestampMode (int iLock);

  int GetTimeFormat ();
  int GetTimestampFormat ();
  HRESULT SetTimestampFormat (int iMode);
  /** Deprecated */
  char GetLockTimestampFormat();
  HRESULT GetInfoTimestampFormat (CATSettingInfo* oInfo);
  HRESULT SetLockTimestampFormat (int iLock);



  int  GetCopyMode ();
  HRESULT SetCopyMode (int iMode);
  /** Deprecated */
  char GetLockCopyMode ();
  HRESULT GetInfoCopyMode (CATSettingInfo* oInfo);
  HRESULT SetLockCopyMode (int iLock);
  
  HRESULT GetLocalPath( CATString **oLocalPath);
  HRESULT GetLocalPathSymb (CATString ** oLocalPath);
  HRESULT SetLocalPath (CATString  &iLocalPath,int *oNew=0);

  HRESULT GetLocalPath( CATUnicodeString **oLocalPath);
  HRESULT GetLocalPathSymb (CATUnicodeString ** oLocalPath);
  HRESULT SetLocalPath (CATUnicodeString  &iLocalPath, int *oNew=0);

  /** Deprecated */
  char GetLockLocalPath();
  HRESULT GetInfoLocalPath (CATSettingInfo* oInfo);
  HRESULT SetLockLocalPath(int iLock);
  
  HRESULT GetReleasePath (unsigned int &oNbDir, CATString  **&oLocalPath);
  HRESULT GetReleasePathSymb (unsigned int &oNbDir, CATString  **&oLocalPath);
  HRESULT SetReleasePath (unsigned int iNbDir, CATString  **oLocalPath);


  HRESULT GetReleasePath (unsigned int &oNbDir, 
			  CATUnicodeString  **&oLocalPath);
  HRESULT GetReleasePathSymb (unsigned int &oNbDir, 
			      CATUnicodeString  **&oLocalPath);
  HRESULT SetReleasePath (unsigned int iNbDir, 
			  CATUnicodeString  **oLocalPath);
  
  /** Deprecated */
  char GetLockReleasePath ();
  HRESULT GetInfoReleasePath (CATSettingInfo* oInfo);
  HRESULT SetLockReleasePath (int iLock);
  
  float GetReleasedVoxel ();
  HRESULT SetReleasedVoxel (float iVoxel);
  /** Deprecated */
  char GetLockReleasedVoxel ();
  HRESULT GetInfoReleasedVoxel (CATSettingInfo* oInfo);
  HRESULT SetLockReleasedVoxel (int iLock);

  int GetVersion ();
  HRESULT SetVersion(int iVersion);
  HRESULT GetState ();
  
private:
  CATCacheSetting();
  virtual  ~CATCacheSetting();
  HRESULT Restore();

      
  static CATSysCacheSettingCtrl *_TheCtrl;
  
  static CATCacheSetting * _CacheSetting;
  
};

#endif


