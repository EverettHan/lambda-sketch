#ifndef CATISysMemoryWarningSettingAtt_H
#define CATISysMemoryWarningSettingAtt_H

// COPYRIGHT DASSAULT SYSTEMES 2000


#include "JS0ERROR.h"
#include "IUnknown.h"
#include "CATMacForIUnknown.h"
#include "CATBoolean.h"
class CATSettingInfo;
   
extern ExportedByJS0ERROR IID IID_CATISysMemoryWarningSettingAtt;

/**
* Interface to handle the parameters of memory warning.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the memory warning mechanism.
* This mechanism informs the user when the process memory use exceeds
* a given percentage of the address space usage. This mechanism warns you that 
* because the amout of remaining memory is becoming low, you should save your data
* and leave the session.
* <br>This interface defines:
* <ul>
* <li>A method to set each parameter</li>
* <li>A method to get the value of each parameter</li>
* <li>A method to lock/unlock each parameter</li>
* <li>A method to retrieve the informations concerning each parameter</li>
* </ul>
*/
class ExportedByJS0ERROR  CATISysMemoryWarningSettingAtt : public CATBaseUnknown
{
   CATDeclareInterface; 
    public: 

 /**
 * Returns activation state of memory warning mechanism.
 * <br><b>Role</b>:Returns or sets the activation state of memory warning.
 * @param oMode
 *	<b>Legal values</b>:
 *	<br><tt>FALSE:</tt>   turned off
 * 	<br><tt>TRUE:</tt>   turned on
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
   virtual HRESULT GetActivationState(CATBoolean *oActivationState)=0;


/**
 * Turns ON/OFF the memory warning mechanism.
 * <br><b>Role</b>: Activates or desactivates memory warning mechanism.
 * @param iMode
 *	<b>Legal values</b>:
 *	<br><tt>FALSE:</tt>   to turn off
 * 	<br><tt>TRUE:</tt>   to turn on
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
   virtual HRESULT PutActivationState(CATBoolean iActivationState)=0;
  
/**
 * Locks or unlocks the activation mode of the memory warning mechanism.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
   virtual HRESULT SetActivationStateLock(unsigned char iLock)=0;

/**
 * Retrieves environment informations for the memory warning mechanism.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
   virtual HRESULT GetActivationStateInfo(CATSettingInfo *oInfo)=0;

/**
 * Returns the alert percentage.
 * <br><b>Role</b>: Returns or sets the percentage of the address space usage 
 * that can be used by the process before sending the warning.
 * @param oMaxLimit
 *	the percentage of the address space usage.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/  
   virtual HRESULT GetUsageLimit(int *oMaxLimit)=0;

/**
 * Sets the alert percentage.
 * <br><b>Role</b>: Sets the percentage of the address space usage that can be 
 * used by the process before sending the warning.
 * @param iMaxLimit
 *	the percentage of the address space usage.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/  
   virtual HRESULT PutUsageLimit(int iMaxLimit)=0;

/**
 * Locks or unlocks the the alert percentage.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
   virtual HRESULT SetUsageLimitLock(unsigned char iLock)=0;

/**
 * Retrieves environment informations for the alert percentage.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
   virtual HRESULT GetUsageLimitInfo(CATSettingInfo *oInfo)=0;

};
#endif
