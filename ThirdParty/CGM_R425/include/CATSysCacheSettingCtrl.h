//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                           
//  Implementation for Cache Setting Controller                                
//                                                                           
//  Usage Notes: Class Definition                                             
//===========================================================================
//  Creation fevrier 2003                               adt         	
//===========================================================================
#ifndef __CATSYSCACHESTGCTRL
#define __CATSYSCACHESTGCTRL
#include "JS0MRSHL.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATSysMacroSettingCtrl.h"
#include "CATSafeArray.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

/** @nodoc */
#define FACILITY_CATCACHE		0xFFF // maximum value
/** @nodoc */
#define INCONSISTENT_TIMEFORMAT		65000
/** @nodoc */
#define FORCED_INACTIVATION		65001
/** @nodoc */
#define INVALID_LOCALDIR		65002
/** @nodoc */
#define EMPTY_CACHE			65003
/** @nodoc */
#define OLD_CACHE			65004



class ExportedByJS0MRSHL CATSysCacheSettingCtrl:public CATSysSettingController
{
  // Macro for declaration of the SysCacheSetting controller
  CATDeclareSettingCtrl(CAT,Sys,Cache);

  /** @nodoc */
  CATDeclareCBEvent(Updated);
    
public :
  // The controller will use bufferised datas and thus must reimplement the 
  // ResetToadminValues and Rollback methods
  HRESULT Rollback();
  HRESULT ResetToAdminValues(char** iAttList, int iNbAtt);
  HRESULT SaveRepository ( const char *tmp=0);
  
  
  HRESULT GetCacheMaxSizeMo (unsigned int &oSize);
  HRESULT SetCacheMaxSizeMo (unsigned int iSize);
  CATSysDeclareSettingCtrlLocks(CacheMaxSizeMo);
 
  
    
 
  HRESULT GetActivationMode(unsigned char & oIsActive);
  HRESULT SetActivationMode(unsigned char iIsActive);
  CATSysDeclareSettingCtrlLocks(ActivationMode);

  HRESULT GetSizeControl (unsigned char &oMode);
  HRESULT SetSizeControl (unsigned char iMode);
  CATSysDeclareSettingCtrlLocks(SizeControl);

  HRESULT GetTimestampMode (unsigned char &oMode);
  HRESULT SetTimestampMode (unsigned char iMode);
  CATSysDeclareSettingCtrlLocks(TimestampMode);

  HRESULT GetUTCTimeFormat (unsigned char &oMode);
  HRESULT SetUTCTimeFormat (unsigned char iMode);
  CATSysDeclareSettingCtrlLocks(UTCTimeFormat);

  HRESULT GetReleasedVoxel(float & oVoxel);
  HRESULT SetReleasedVoxel(float iVoxel);
  CATSysDeclareSettingCtrlLocks(ReleasedVoxel);

  HRESULT GetLODMode (unsigned char &oMode);
  HRESULT SetLODMode (unsigned char iMode);
  CATSysDeclareSettingCtrlLocks(LODMode);

  HRESULT GetLocalPath( CATUnicodeString **oLocalPath);
  HRESULT GetLocalPathSymb (CATUnicodeString ** oLocalPath);
  HRESULT SetLocalPath (CATUnicodeString  &iLocalPath,
			int *oNew=0);
  CATSysDeclareSettingCtrlLocks(LocalPath);
 
  HRESULT GetSessionCachePath( CATUnicodeString **oLocalPath);
  HRESULT GetSessionCachePathSymb (CATUnicodeString ** oLocalPath);
  HRESULT SetSessionCachePath (CATUnicodeString  &iLocalPath);
  CATSysDeclareSettingCtrlLocks(SessionCachePath);
 

  HRESULT GetReleasePath (unsigned int &oNbDir, 
			  CATUnicodeString  **&oRelPath);
  HRESULT GetReleasePathSymb (unsigned int &oNbDir, 
			      CATUnicodeString  **&oRelPath);
  HRESULT SetReleasePath (unsigned int iNbDir, 
			  CATUnicodeString  **iRelPath);
  CATSysDeclareSettingCtrlLocks(ReleasePath);

  //In no Interface for Internal use
  HRESULT GiveCacheState (HRESULT *oState);
  void DesactivateTS (int mode);
  
    
protected:
  HRESULT Initialize();
  virtual  ~CATSysCacheSettingCtrl();

private:
  void InitDefaultPath();
  HRESULT ValidateCache();
  HRESULT GetReleasePathExt (unsigned int &oNbDir, 
			     CATUnicodeString  **&oRelPath, int type);
  HRESULT GetLocalPathExt( CATUnicodeString **oLocalPath, int type);
  HRESULT GetSessionPathExt( CATUnicodeString **oLocalPath, int type);

// donnees membres specifique au cache
  CATUnicodeString  *_CachePath, *_CachePathDefault, *_UnExpCachePath;
  CATUnicodeString  *_CacheSession, *_CacheSessionDefault, *_UnExpCacheSession;
  CATUnicodeString  **_ReleaseDir;
  CATUnicodeString  **_UnExpReleaseDir;

  unsigned int _NbReleaseDir;
  unsigned int _MaxSize;
  int _Version;
  
  int _ActivationMode;
  int _TimeStampMode;
  int _TSActif;
  int _CopyMode;
  int _SizeControl;
  int _ToRefresh;
  int _LOD;
   
  signed char _TSMode;		// default mode 
  signed char _CurTS;	// current one 	
  signed char _LocalTS;		// localdir 
  signed char _RelTS;		// Rel dir if valide
  
  HRESULT _State;
  float _Voxel;
  
};

#endif


