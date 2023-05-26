// implementation des methodes de CATSysGeneralStatisticsSettingCtrl

#ifndef __CATSYSGENERALSTATISTICSSTGCTRL
#define __CATSYSGENERALSTATISTICSSTGCTRL
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATSysMacroSettingCtrl.h"
#include "CATSafeArray.h"
#include "JS03TRA.h"
#include "CATLib.h"
#include "CATSysStatisticsDef.h"
#include "CATISysGeneralStatisticsSettingAtt.h"
#include "CATISysSettingController.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

class ExportedByJS03TRA CATSysGeneralStatisticsSettingCtrl:public CATSysSettingController
{
  // Macro for declaration of the SysGeneralStatisticsSetting controller
//  CATDeclareSettingCtrl(CAT,Sys,GeneralStatistics);

protected:
	CATSysGeneralStatisticsSettingCtrl(const char *iname);

	public :
	~CATSysGeneralStatisticsSettingCtrl();


	virtual HRESULT GetActivation(int *oActivatationState);
	virtual HRESULT SetActivation(int iActivationState);

	virtual HRESULT GetCumulationMode(int *oCumulative);
	virtual HRESULT SetCumulationMode(int oCumulative);

	virtual HRESULT GetFormatMode(int* oFormatMode, int flag = 0);
	virtual HRESULT SetFormatMode(int iFormatMode, int flag = 0);

	virtual HRESULT GetOutput(int* oOutputType);
	virtual HRESULT SetOutput(int iOutputType );

	virtual HRESULT GetOutputFile(CATUnicodeString* oOutputFile);
	virtual HRESULT SetOutputFile(CATUnicodeString iOutputFile);

//	virtual HRESULT GetOutputFile(CATUnicodeString *oOutputFileUX,CATUnicodeString *oOutputFileNT);
	
//	virtual HRESULT GetMaxSizePerFile(unsigned int *oSize);
//	virtual HRESULT SetMaxSizePerFile(unsigned int iSize);

//	virtual HRESULT GetMaxCopyFile(unsigned int *oNb);
//	virtual HRESULT SetMaxCopyFile(unsigned int iNb);

//	virtual HRESULT GetBufferSize(unsigned int *oSize);
//	virtual HRESULT SetBufferSize(unsigned int iSize);
	
//	virtual HRESULT GetCopyDirectory(CATUnicodeString *oCopyDir);
//	virtual HRESULT SetCopyDirectory(CATUnicodeString *iCopyDir);

	virtual HRESULT GetTHEM (CATBoolean &oStatus);
	virtual HRESULT SetTHEM (const CATBoolean &iStatus);

	virtual HRESULT GetTIME (CATBoolean &oStatus);
	virtual HRESULT SetTIME (const CATBoolean &iStatus);

	virtual HRESULT GetCPUS (CATBoolean &oStatus);
	virtual HRESULT SetCPUS (const CATBoolean &iStatus);

	virtual HRESULT GetRTIM (CATBoolean &oStatus);
	virtual HRESULT SetRTIM (const CATBoolean &iStatus);
	
	virtual HRESULT GetELPS (CATBoolean &oStatus);
	virtual HRESULT SetELPS (const CATBoolean &iStatus);

	virtual HRESULT GetUPID (CATBoolean &oStatus);
	virtual HRESULT SetUPID (const CATBoolean &iStatus);

	virtual HRESULT GetUSER (CATBoolean &oStatus);
	virtual HRESULT SetUSER (const CATBoolean &iStatus);

	virtual HRESULT GetHOST (CATBoolean &oStatus);
	virtual HRESULT SetHOST (const CATBoolean &iStatus);

//	virtual HRESULT GetWBCH (CATBoolean &oStatus);
//	virtual HRESULT SetWBCH (const CATBoolean &iStatus);

//	virtual HRESULT GetCMND (CATBoolean &oStatus);
//	virtual HRESULT SetCMND (const CATBoolean &iStatus);

	virtual HRESULT GetTimeUnit (CATSysStatisticsTimeUnit& oTimeUnit);
	virtual HRESULT SetTimeUnit (const CATSysStatisticsTimeUnit& iTimeUnit);

	virtual HRESULT GetDateFormat  (CATSysStatisticsDateFormat& oDateFormat);
	virtual HRESULT SetDateFormat  (const CATSysStatisticsDateFormat& iDateFormat);

	virtual HRESULT GetOutputFormat (CATSysStatisticsOutputFormat& oOutputFormat);
	virtual HRESULT SetOutputFormat (const CATSysStatisticsOutputFormat& iOutputFormat);

	virtual HRESULT GetOutputSettingInfo (CATSettingInfo& iOutputFormat);

	virtual HRESULT GetThematicsParameterInfo (CATSettingInfo* iOutputFormat);
	virtual HRESULT SetThematicsParameterLock( unsigned char iLock );

	virtual HRESULT GetOutputDirectory (CATUnicodeString* oDirPath);
	virtual HRESULT SetOutputDirectory (const CATUnicodeString* iDirPath);

//	HRESULT ResetToAdminValues();
//	HRESULT ResetToDefautValues();

//	HRESULT Commit(int iFlags=0);
//	HRESULT Rollback(int iFlags=0);

protected :
	CATSysGeneralStatisticsSettingCtrl ();
	const char * m_Name; /* nom du theme de stats                      */

public :

  static HRESULT GetInterface(const char *iName,
			      CATISysGeneralStatisticsSettingAtt *&iItf);


  DSYSysFlag     m_Status; /* status des statistics             */
  DSYSysFlag  m_StgStatus; /* status lu sur setting          */
  int m_Output;          /* specifie le type d'output         */
  int m_StgOutput;       /* output lu sur setting          */
  unsigned short m_Port; /* port optionnel                    */
  char *         m_File; /* pointage optionnel sur le fichier */
  int m_StgFormat;           /* pointage optionnel sur le fichier */
#ifdef _WINDOWS_SOURCE
  char *    m_StgFileNT; /* pointage optionnel sur le fichier */
#else
  char *    m_StgFileUX; /* pointage optionnel sur le fichier */
#endif
	char * m_DefaultDirectory;
};

# endif /* __CATSYSGENERALSTATISTICSSTGCTRL */

// implementation de GeneralStatistics Setting Controller






