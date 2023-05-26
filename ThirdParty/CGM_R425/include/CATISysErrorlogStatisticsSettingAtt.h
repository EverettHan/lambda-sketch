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
# ifndef _CATISYSERRORLOGSTATISTISSETTINGSATT
# define _CATISYSERRORLOGSTATISTISSETTINGSATT
// COPYRIGHT DASSAULT SYSTEMES 2003

# include "JS03TRA.h"
# include "CATBaseUnknown.h"
# include "CATISysSettingController.h"
# include "CATBoolean.h"
# include "CATSysStatisticsDef.h"
#include "CATISysGeneralStatisticsSettingAtt.h"

class CATString;
class CATUnicodeString;
class CATSettingRepository;
class CATSettingInfo;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS03TRA IID IID_CATISysErrorlogStatisticsSettingAtt;
#else
extern "C" const IID IID_CATISysErrorlogStatisticsSettingAtt;
#endif


/**
* Interface to handle the parameters of the errorlog statistics.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the errorlog statistics.
* <br>This interface defines:
* <ul>
* <li>Methods to set each parameter</li>
* <li>Methods to get the value of each parameter</li>
* <li>A method to lock/unlock all parameters (there is only one lock per thematic)</li>
* <li>A method to retrieve the informations concerning all parameters</li>
* </ul>
* <br>For the definitions of methods and variables common to every thematic, see the @href CATISysGeneralStatisticsSettingAtt
*/
class ExportedByJS03TRA CATISysErrorlogStatisticsSettingAtt : public CATISysGeneralStatisticsSettingAtt
{
  CATDeclareInterface;

public :
/**
 * Retrieves the activation state of the workbench name field.
 * <br><b>Role</b>: Retrieves the activation state of the workbench name field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT GetWKBN(CATBoolean &oStatus)=0;
/**
 * Retrieves the activation state of the workbench name field.
 * <br><b>Role</b>: Retrieves the activation state of the workbench name field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT SetWKBN (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the command name field.
 * <br><b>Role</b>: Retrieves the activation state of the command name field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT GetCMND (CATBoolean &oStatus)=0;
/**
 * Retrieves the activation state of the command name field.
 * <br><b>Role</b>: Retrieves the activation state of the command name field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT SetCMND (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the message field.
 * <br><b>Role</b>: Retrieves the activation state of the message field
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT GetMSGE (CATBoolean &oStatus)=0;
/**
 * Retrieves the activation state of the message field.
 * <br><b>Role</b>: Retrieves the activation state of the message field
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT SetMSGE (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the severity level field "abend".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "abend".
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT GetABND (CATBoolean &oStatus)=0;
/**
 * Retrieves the activation state of the severity level field "abend".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "abend".
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT SetABND (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the severity level field "critical error".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "critical error".
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT GetCERR (CATBoolean &oStatus)=0;
/**
 * Retrieves the activation state of the severity level field "critical error".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "critical error".
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT SetCERR (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the severity level field "warning".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "warning".
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT GetWARN (CATBoolean &oStatus)=0;
/**
 * Retrieves the activation state of the severity level field "warning".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "warning".
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT SetWARN (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the severity level field "comment".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "comment".
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT GetCOMT (CATBoolean &oStatus)=0;
/**
 * Retrieves the activation state of the severity level field "comment".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "comment".
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT SetCOMT (const CATBoolean &iStatus)=0;

/**
 * Retrieves the activation state of the severity level field "user report".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "user report".
 * @param oStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT GetUREP (CATBoolean &oStatus)=0;
/**
 * Retrieves the activation state of the severity level field "user report".
 * <br><b>Role</b>: Retrieves the activation state of the severity level field "user report".
 * @param iStatus
 *	<b>Legal values</b>:
 *	<br><tt>TRUE :</tt>  activated
 * 	<br><tt>FALSE:</tt>  not activated
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/	virtual HRESULT SetUREP (const CATBoolean &iStatus)=0;
};


# endif /* _CATISYSERRORLOGSTATISTISSETTINGSATT */

