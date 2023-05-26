/**
* @level Protected
* @usage U1
*/

#ifndef CATOmyPowerIOEnv_H
#define CATOmyPowerIOEnv_H

#include "CATOMYCuteIO.h"

#include "CATUnicodeString.h"

class ExportedByCATOMYCuteIO CATOmyPowerIOEnv
{    
public:
  
  static HRESULT GetValues(CATULONG64 &oMaxSize, CATUINT32 &oMode, CATBoolean &oCheckProperty);

  static CATBoolean       IsNewPowerIOActive();  
  static CATBoolean       IsPowerIOCacheShared();
  static CATBoolean       IsCacheDirSharedBetweenODT();
  
  static int              GetStrategy();
  
  static CATUnicodeString GetProtocolName()                      {return env()._Protocol;}
  static CATULONG32       GetMetaDataCacheMaxSizeMo()            {return env()._MetaDataCacheMaxSizeMo;}
  static CATULONG32       GetMetaDataCacheMaxElements()          {return env()._MetaDataCacheMaxElements;}
  static CATBoolean       GetMetaDataCacheIsPersistent()         {return env()._MetaDataCacheIsPersistent;}
  static CATBoolean       GetNoCacheCheckOnStartup()             {return env()._NoCacheCheckOnStartup;}
  
  
private:
  
  // Methods
  static const CATOmyPowerIOEnv &env();
  CATOmyPowerIOEnv();  
  
  CATBoolean       _IsInODTAndFromFWNotConcurrent();
  
  // Data
  CATUnicodeString _Protocol;
  CATBoolean       _MetaDataCacheIsPersistent;
  CATULONG32       _MetaDataCacheMaxSizeMo;  
  CATULONG32       _MetaDataCacheMaxElements;    
  CATBoolean       _NoCacheCheckOnStartup;      
  int              _MaxCacheSize;
  int              _Strategy;  
  
  CATBoolean       _IsCacheDirSharedBetweenODT;
  CATBoolean       _ConcurrentCacheActivate; 
  CATBoolean       _NewPowerIOMode;
    
  friend class CATOmyPWCacheServices;
  friend class TestConcCacScenarioPlayer;
};

#endif


