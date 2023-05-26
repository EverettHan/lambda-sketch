//===========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003                                         
//===========================================================================
//                                                                           
//  CATStatisticsSetting                                                 
//                                                                           
//  Usage Notes: Class Definition                                             
//===========================================================================
//  Creation novembre  2003                                 siu         	
//===========================================================================
# ifndef _CATISYSGENERALSTATISTICSSETTINGATT
# define _CATISYSGENERALSTATISTICSSETTINGATT

// COPYRIGHT DASSAULT SYSTEMES 2003
# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATISysSettingController.h"
# include "CATBoolean.h"
# include "CATSysStatisticsDef.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;


/**
* Interface to handle the parameters of all the statistics thematics.
* <b>Role</b>: This interface is implemented by a component which
* contains all the methods and variables available for all the statistics thematics.
* One should never use it as a statistics thematic.
* <br>This interface defines:
* <ul>
* <li>Methods to set each parameter</li>
* <li>Methods to get the value of each parameter</li>
* <li>A method to lock/unlock all parameters (there is only one lock per thematic)</li>
* <li>A method to retrieve the informations concerning all parameters</li>
* </ul>
*/
class ExportedByJS03TRA CATISysGeneralStatisticsSettingAtt : public CATBaseUnknown
{
public :
/**
 * Retrieves the activation state of the thematic.
 * <br><b>Role</b>: Retrieves the activation state of the thematic
 * @param oActivatationState
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>  activated
 * 	<br><tt>0 :</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetActivation(int *oActivatationState)=0;
/**
 * Sets the activation state of the thematic.
 * <br><b>Role</b>: Retrieves the activation state of the thematic
 * @param oActivatationState
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>  activated
 * 	<br><tt>0 :</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetActivation(int iActivationState)=0;

/**
 * Retrieves the cumulation state of the thematic.
 * <br><b>Role</b>: Retrieves the cumulation state of the thematic
 * @param oCumulative
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>  cumulated
 *	<br><tt>0 :</tt>  not cumulated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetCumulationMode(int *oCumulative)=0;
/**
 * Sets the value of the cumulation state of the thematic.
 * <br><b>Role</b>: Sets the cumulation state of the thematic
 * @param oCumulative
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>  cumulated
 *	<br><tt>0 :</tt>  not cumulated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetCumulationMode(int oCumulative)=0;


/**
 * Retrieves the output format mode of the thematic.
 * <br><b>Role</b>: Retrieves the output format mode of the thematic.
 * @param oFormatMode
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>  formated
 *	<br><tt>0 :</tt>  not formated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetFormatMode( int *oFormatMode, int flag=0)=0;
/**
 * Sets the output format mode of the thematic.
 * <br><b>Role</b>: Sets the output format mode of the thematic
 * @param iFormatMode
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>  formated
 *	<br><tt>0 :</tt>  not formated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetFormatMode( int iFormatMode, int flag=0)=0;


/**
 * Retrieves the output format of the thematic.
 * <br><b>Role</b>: Retrieves the output format of the thematic.
 * @param oOutputType
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>  console (if available)
 *	<br><tt>2 :</tt>  file
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetOutput( int *oOutputType)=0;
/**
 * Sets the output format of the thematic.
 * <br><b>Role</b>: Sets the output format of the thematic
 * @param iOutputType
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>  console (if available)
 *	<br><tt>2 :</tt>  file
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetOutput( int iOutputType )=0;

/**
 * Retrieves the output file of the thematic.
 * <br><b>Role</b>: Retrieves the output file of the thematic.
 * @param oOutputFile
 *	Name of the output file
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetOutputFile(CATUnicodeString *oOutputFile)=0;
/**
 * Sets the output file of the thematic.
 * <br><b>Role</b>: Sets the output file of the thematic
 * @param iOutputFile
 *	Name of the output file
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 *	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetOutputFile(CATUnicodeString iOutputFile)=0;


/**
 * Retrieves the activation state of the thematic name field.
 * <br><b>Role</b>: Retrieves the activation state of the thematic name field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetTHEM (CATBoolean &oStatus)=0;
/**
 * Sets the activation state of the thematic name field.
 * <br><b>Role</b>: Retrieves the activation state of the thematic name field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetTHEM (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the date and time field.
 * <br><b>Role</b>: Retrieves the activation state of the date and time field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetTIME (CATBoolean &oStatus)=0;
/**
 * Sets the activation state of the date and time field.
 * <br><b>Role</b>: Retrieves the activation state of the date and time field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetTIME (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the cpu time field.
 * <br><b>Role</b>: Retrieves the activation state of the cpu time field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetCPUS (CATBoolean &oStatus)=0;
/**
 * Sets the activation state of the cpu time field.
 * <br><b>Role</b>: Retrieves the activation state of the cpu time field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetCPUS (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the response time field.
 * <br><b>Role</b>: Retrieves the activation state of the response time field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetRTIM (CATBoolean &oStatus)=0;
/**
 * Sets the activation state of the response time field.
 * <br><b>Role</b>: Retrieves the activation state of the response time field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetRTIM (const CATBoolean &iStatus)=0;
	
/**
 * Retrieves the activation state of the elapsed time field.
 * <br><b>Role</b>: Retrieves the activation state of the elapsed time field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetELPS (CATBoolean &oStatus)=0;
/**
 * Sets the activation state of the elapsed time field.
 * <br><b>Role</b>: Retrieves the activation state of the elapsed time field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetELPS (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the user pid field.
 * <br><b>Role</b>: Retrieves the activation state of the user pid field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetUPID (CATBoolean &oStatus)=0;
/**
 * Sets the activation state of the user pid field.
 * <br><b>Role</b>: Retrieves the activation state of the user pid field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetUPID (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the user name field.
 * <br><b>Role</b>: Retrieves the activation state of the user name field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetUSER (CATBoolean &oStatus)=0;
/**
 * Sets the activation state of the user name field.
 * <br><b>Role</b>: Retrieves the activation state of the user name field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetUSER (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the host name field.
 * <br><b>Role</b>: Retrieves the activation state of the host name field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetHOST (CATBoolean &oStatus)=0;
/**
 * Sets the activation state of the host name field.
 * <br><b>Role</b>: Retrieves the activation state of the host name field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetHOST (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the time unit field.
 * <br><b>Role</b>: Retrieves the activation state of the time unit field
 * @param iTimeUnit
 *	<b>Legal values</b>:
 *	<br><tt>Millisecond :</tt>  durations in milliseconds
 * 	<br><tt>Second		:</tt>  durations in seconds
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetTimeUnit (CATSysStatisticsTimeUnit &iTimeUnit)=0;
/**
 * Sets the activation state of the time unit field.
 * <br><b>Role</b>: Retrieves the activation state of the time unit field
 * @param iTimeUnit
 *	<b>Legal values</b>:
 *	<br><tt>Millisecond :</tt>  durations in milliseconds
 * 	<br><tt>Second		:</tt>  durations in seconds
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetTimeUnit (CATSysStatisticsTimeUnit &iTimeUnit)=0;

/**
 * Retrieves the activation state of the date format field.
 * <br><b>Role</b>: Retrieves the activation state of the date format field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>StandardDate :</tt>  default date format
 * 	<br><tt>NumericalDate:</tt>  numerical date format
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetDateFormat  (CATSysStatisticsDateFormat &DateFormat)=0;
/**
 * Sets the activation state of the date format field.
 * <br><b>Role</b>: Retrieves the activation state of the date format field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>StandardDate :</tt>  default date format
 * 	<br><tt>NumericalDate:</tt>  numerical date format
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetDateFormat  (CATSysStatisticsDateFormat &DateFormat)=0;

/**
 * Retrieves the activation state of the output format field.
 * <br><b>Role</b>: Retrieves the activation state of the thematic name field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetOutputFormat (CATSysStatisticsOutputFormat &iOutputFormat)=0;
/**
 * Sets the activation state of the thematic name field.
 * <br><b>Role</b>: Retrieves the activation state of the thematic name field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetOutputFormat (CATSysStatisticsOutputFormat &iOutputFormat)=0;
	
/**
 * Retrieves the CATSettingInfo of the thematic.
 * <br><b>Role</b>: Retrieves the CATSettingInfo of the thematic.(no longer used)
 * @param oCATSettingInfo
 *	CATSettingInfo returned
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetOutputSettingInfo (CATSettingInfo &oCATSettingInfo)=0;

/** 
 * Retrieves environment informations for the general statistics parameters.
 * <br><b>Role</b>:Retrieves the state of statistics parameters
 * in the current environment.
 * @param oCATSettingInfo
 *	CATSettingInfo returned
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetThematicsParameterInfo (CATSettingInfo *oCATSettingInfo)=0;

/**
 * Locks or unlocks the general statistics parameters.
 * <br><b>Role</b>:Locks or unlocks the statistics parameters.
 * @param iLock
 *	the locking operation to be performed
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>   to lock the parameter.
 * 	<br><tt>FALSE:</tt>   to unlock the parameter.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetThematicsParameterLock( unsigned char iLock )=0;

/**
 * Retrieves the output directory.
 * <br><b>Role</b>: Retrieves output directory
 * @param oDirPath
 *	output directory complete path
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT GetOutputDirectory (CATUnicodeString * oDirPath)=0;

/**
 * Sets the output directory.
 * <br><b>Role</b>: Retrieves the output directory
 * @param iDirPath
 *	output directory complete path
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on Failure
*/
	virtual HRESULT SetOutputDirectory(const CATUnicodeString * iDirPath)=0;
    
};


# endif /* CATISYSGENERALSTATISTISSETTINGSATT */


