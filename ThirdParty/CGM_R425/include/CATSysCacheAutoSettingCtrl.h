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
#ifndef __CATSYSCACHEAUTOSTGCTRL
#define __CATSYSCACHEAUTOSTGCTRL
#include "JS0MRSHL.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATSysMacroSettingCtrl.h"
#include "CATSafeArray.h"
#include "CAT_VARIANT_BOOL.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

class CATISysCacheSettingAtt;



class ExportedByJS0MRSHL CATSysCacheAutoSettingCtrl:public CATSysAutoSettingController
{
  // Macro for declaration of the SysCacheSetting controller
  CATDeclareAutoSettingCtrl(CAT,Sys,Cache);


public :
 
  HRESULT get_CacheMaxSizeMo (CATLONG  &oSize);
  HRESULT put_CacheMaxSizeMo (CATLONG  iSize);
  CATSysDeclareAutoSettingCtrlLocks(CacheMaxSizeMo);
  
  HRESULT get_ActivationMode(CAT_VARIANT_BOOL & oIsActive);
  HRESULT put_ActivationMode(CAT_VARIANT_BOOL iIsActive);
  CATSysDeclareAutoSettingCtrlLocks(ActivationMode);

  HRESULT get_SizeControl (CAT_VARIANT_BOOL &oMode);
  HRESULT put_SizeControl (CAT_VARIANT_BOOL iMode);
  CATSysDeclareAutoSettingCtrlLocks(SizeControl);

  HRESULT get_TimestampMode (CAT_VARIANT_BOOL &oMode);
  HRESULT put_TimestampMode (CAT_VARIANT_BOOL iMode);
  CATSysDeclareAutoSettingCtrlLocks(TimestampMode);

  HRESULT get_UTCTimeFormat (CAT_VARIANT_BOOL &oMode);
  HRESULT put_UTCTimeFormat (CAT_VARIANT_BOOL iMode);
  CATSysDeclareAutoSettingCtrlLocks(UTCTimeFormat);

  HRESULT get_ReleasedVoxel(float & oVoxel);
  HRESULT put_ReleasedVoxel(float iVoxel);
  CATSysDeclareAutoSettingCtrlLocks(ReleasedVoxel);

  HRESULT get_LODMode (CAT_VARIANT_BOOL &oMode);
  HRESULT put_LODMode (CAT_VARIANT_BOOL iMode);
  CATSysDeclareAutoSettingCtrlLocks(LODMode);

  HRESULT get_LocalPath(CATBSTR & oLocalPath);
  HRESULT put_LocalPath(const CATBSTR & iLocalPath);
  CATSysDeclareAutoSettingCtrlLocks(LocalPath);
 
  HRESULT GetReleasePath(CATSafeArrayVariant *&oRelPath);
  HRESULT PutReleasePath(const CATSafeArrayVariant & iRelPath);
  CATSysDeclareAutoSettingCtrlLocks(ReleasePath);
  
};

#endif


