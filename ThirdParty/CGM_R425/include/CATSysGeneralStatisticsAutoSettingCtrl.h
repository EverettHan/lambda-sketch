// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef __CATSYSGeneralSTATISTICSAUTOSTGCTRL
#define __CATSYSGeneralSTATISTICSAUTOSTGCTRL
#include "JS03TRA.h"
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATSysMacroSettingCtrl.h"
#include "CATIAGeneralStatisticsSettingAtt.h"
#include "CAT_VARIANT_BOOL.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

class CATISysGeneralStatisticsSettingAtt;


class ExportedByJS03TRA CATSysGeneralStatisticsAutoSettingCtrl:public CATSysAutoSettingController
{
 // Macro for declaration of the SysGeneralStatisticsSetting controller
 // CATDeclareAutoSettingCtrl(CAT,Sys,GeneralStatistics);

public :

  virtual HRESULT get_Activation(unsigned char & oActivatationState);
  virtual HRESULT put_Activation(unsigned char iActivationState);
  
  virtual HRESULT get_CumulationMode(unsigned char & oCumulative);
  virtual HRESULT put_CumulationMode(unsigned char iCumulative);
  
  virtual HRESULT GetFormatMode(CATLONG flag, unsigned char & oFormatMode);
  virtual HRESULT SetFormatMode(unsigned char iFormatMode, CATLONG flag);
  
  virtual HRESULT get_Output(CATBSTR & oOutputType);
  virtual HRESULT put_Output(const CATBSTR & iOutputType);
  
  virtual HRESULT get_OutputFile(CATBSTR & oOutputFile);
  virtual HRESULT put_OutputFile(const CATBSTR & iOutputFile);
  
//  virtual HRESULT get_MaxSizePerFile(CATLONG & oSize);
//  virtual HRESULT put_MaxSizePerFile(CATLONG iSize);
  
//  virtual HRESULT get_MaxCopyFile(CATLONG & oNb);
//  virtual HRESULT put_MaxCopyFile(CATLONG iNb);
  
//  virtual HRESULT get_BufferSize(CATLONG & oSize);
//  virtual HRESULT put_BufferSize(CATLONG iSize);
  
//  virtual HRESULT get_CopyDirectory( CATBSTR &oCopyDir);
//  virtual HRESULT put_CopyDirectory(const CATBSTR & iCopyDir);
  
  virtual HRESULT get_THEM(CAT_VARIANT_BOOL & oStatus);
  virtual HRESULT put_THEM(CAT_VARIANT_BOOL iStatus);
  
  virtual HRESULT get_TIME(CAT_VARIANT_BOOL & oStatus);
  virtual HRESULT put_TIME(CAT_VARIANT_BOOL iStatus);
  
  virtual HRESULT get_CPUS(CAT_VARIANT_BOOL & oStatus);
  virtual HRESULT put_CPUS(CAT_VARIANT_BOOL iStatus);
  
  virtual HRESULT get_RTIM(CAT_VARIANT_BOOL & oStatus);
  virtual HRESULT put_RTIM(CAT_VARIANT_BOOL iStatus);

  virtual HRESULT get_ELPS(CAT_VARIANT_BOOL & oStatus);
  virtual HRESULT put_ELPS(CAT_VARIANT_BOOL iStatus);

  virtual HRESULT get_USER(CAT_VARIANT_BOOL & oStatus);
  virtual HRESULT put_USER(CAT_VARIANT_BOOL iStatus);
  
  virtual HRESULT get_HOST(CAT_VARIANT_BOOL & oStatus);
  virtual HRESULT put_HOST(CAT_VARIANT_BOOL iStatus);
  
  virtual HRESULT get_UPID(CAT_VARIANT_BOOL & oStatus);
  virtual HRESULT put_UPID(CAT_VARIANT_BOOL iStatus);
  
  virtual HRESULT  get_TimeUnit(CATBSTR & iTimeUnit);
  virtual HRESULT  put_TimeUnit(const CATBSTR & iTimeUnit);
  
  virtual HRESULT  get_DateFormat(CATBSTR & iTimeUnit);
  virtual HRESULT  put_DateFormat(const CATBSTR & iTimeUnit);
  
  virtual HRESULT  get_OutputFormat(CATBSTR & iOutputFormat);
  virtual HRESULT  put_OutputFormat(const CATBSTR & iOutputFormat);

  virtual HRESULT  SetThematicsParameterLock(CAT_VARIANT_BOOL iLocked);
  
  virtual HRESULT  GetThematicsParameterInfo(CATBSTR & AdminLevel, 
				     CATBSTR & oLocked, 
				     CAT_VARIANT_BOOL & oModified);

  virtual HRESULT GetMyPtr (  CATISysGeneralStatisticsSettingAtt *&oItf)=0;

  virtual HRESULT  get_OutputDirectory(CATBSTR & iDirPath);
  virtual HRESULT  put_OutputDirectory(const CATBSTR & oDirPath);


  static HRESULT GetVBInterface (const char *iName,CATISysGeneralStatisticsSettingAtt *iItf,
								 CATIAGeneralStatisticsSettingAtt *&oItf);
  
  
};

#endif /*__CATSYSWorkbenchSTATISTICSAUTOSTGCTRL */
