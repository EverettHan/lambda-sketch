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
# ifndef _CATISYSGLOBALSTATISTISSETTINGSATT
# define _CATISYSGLOBALSTATISTISSETTINGSATT
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


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS03TRA IID IID_CATISysGlobalStatisticsSettingAtt;
#else
extern "C" const IID IID_CATISysGlobalStatisticsSettingAtt;
#endif


/**
* Interface to handle the parameters of the global statistic.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the global statistic. 
* <br>This interface defines:
* <ul>
* <li>Methods to set each parameter</li>
* <li>Methods to get the value of each parameter</li>
* <li>A method to lock/unlock all parameters </li>
* <li>A method to retrieve the informations concerning all parameters</li>
* </ul>
*/

class ExportedByJS03TRA CATISysGlobalStatisticsSettingAtt : public CATBaseUnknown
{
  CATDeclareInterface;

public :
/**
 * Retrieves the value of the file maximum size.
 * <br><b>Role</b>: Retrieves the value of the statistics file maximum size in Mo
 * @param oSize
 *	The maximum allowed size of the file in Mo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT GetMaxSizePerFile(unsigned int *oSize)=0;
/**
 * Sets the value of the file maximum size.
 * <br><b>Role</b>: Sets the value of the statistics file maximum size in Mo
 * @param iSize
 *	The maximum allowed size of the file in Mo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT SetMaxSizePerFile(unsigned int iSize)=0;

/**
 * Retrieves the value of the copy files maximum number.
 * <br><b>Role</b>: Retrieves the value of the copy file maximum number
 * @param oNb
 *	The maximum allowed number of copies.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT GetMaxCopyFile(unsigned int *oNb)=0;
/**
 * Sets the value of the copy files maximum number.
 * <br><b>Role</b>: Sets the value of the copy file maximum number
 * @param iNb
 *	The maximum allowed number of copies.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT SetMaxCopyFile(unsigned int iNb)=0;

/**
 * Retrieves the value of the buffer maximum size.
 * <br><b>Role</b>: Retrieves the value of the buffer maximum size in Mo
 * @param oSize
 *	The maximum allowed size of the buffer in Mo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT GetBufferSize(unsigned int *oSize)=0;
/**
 * Sets the value of the buffer maximum size.
 * <br><b>Role</b>: Sets the value of the buffer maximum size in Mo
 * @param iSize
 *	The maximum allowed size of the buffer in Mo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
	virtual HRESULT SetBufferSize(unsigned int iSize)=0;
	
/**
 * Retrieves the copy files directory.
 * <br><b>Role</b>: Retrieves the path of the copy files directory
 * @param oCopyDir
 *	The path of the copy files directory.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
	virtual HRESULT GetCopyDirectory(CATUnicodeString *oCopyDir)=0;
/**
 * Sets the copy files directory.
 * <br><b>Role</b>: Sets the path of the copy files directory
 * @param iCopyDir
 *	The path of the copy files directory.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
	virtual HRESULT SetCopyDirectory(CATUnicodeString *iCopyDir)=0;
/**
 * Retrieves the event scheduling capability.
 * <br><b>Role</b>: Get if the statistics events scheduling is on
 * @param oIsSet
 *	Flag about the event scheduling.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
  virtual HRESULT GetEventScheduling(bool* oSet)=0;
/**
 * Sets the event scheduling capability.
 * <br><b>Role</b>: Set the statistics events scheduling capability
 * @param oIsSet
 *	Flag about the event scheduling.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
  virtual HRESULT SetEventScheduling(bool iSet)=0;
/**
 * Retrieves the event scheduling capability.
 * <br><b>Role</b>: Get if the usage collection formatting is on
 * @param oIsSet
 *	Flag about usage collection formatting.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
  virtual HRESULT GetUsageCollectFormat(bool* oSet)=0;
/**
 * Sets the event scheduling capability.
 * <br><b>Role</b>: Set the usage collection formatting capability
 * @param oIsSet
 *	Flag about usage collection formatting.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on success
 * 	<br><tt>E_FAIL:</tt>  on failure
 */
  virtual HRESULT SetUsageCollectFormat(bool iSet)=0;
/** 
 * Locks or unlocks the global statistic parameters.
 * <br><b>Role</b>: Locks or unlocks the global statistic parameters. if the
 * operation is allowed in the current administrated environment. In user mode 
 * this method will always return E_FAIL.
 * @param Lock
 *	the locking operation to be performed
 *	<b>Legal values</b>:
 *	<br><tt>1 :</tt>   to lock the parameter.
 * 	<br><tt>0:</tt>   to unlock the parameter.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT SetThematicsParameterLock ( unsigned char Lock)=0;
/**
 * Retrieves the state of the global statistic parameters.
 * @param oInfo
 *	Address of an object CATSettingInfo.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
	virtual HRESULT GetThematicsParameterInfo (CATSettingInfo * oInfo)=0;
};


# endif /* _CATISYSGLOBALSTATISTISSETTINGSATT */

