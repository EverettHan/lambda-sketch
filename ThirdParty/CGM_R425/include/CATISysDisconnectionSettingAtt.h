#ifndef CATISysDisconnectionSettingAtt_H
#define CATISysDisconnectionSettingAtt_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0ERROR.h"
#include "IUnknown.h"
#include "CATMacForIUnknown.h"
#include "CATBoolean.h"
class CATSettingInfo;
   

extern ExportedByJS0ERROR IID IID_CATISysDisconnectionSettingAtt;



/**
* Interface to handle the parameters of automatic disconnection.
* <b>Role</b>: This interface is implemented by a component which
* represents the controller of the cache. 
* <br>This interface defines:
* <ul>
* <li>A method to set each parameter</li>
* <li>A method to get the value of each parameter</li>
* <li>A method to lock/unlock each parameter</li>
* <li>A method to retrieve the informations concerning each parameter</li>
* </ul>
*/
class ExportedByJS0ERROR  CATISysDisconnectionSettingAtt : public CATBaseUnknown
{
   CATDeclareInterface; 
    public: 
/**
 * Returns activation state of automatic disconnection.
 * <br><b>Role</b>:Returns or sets the activation mode of automatic disconnection.
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
 * Turns ON/OFF the automatic disconnection.
 * <br><b>Role</b>: Activates or desactivates the cache mechanism.
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
 * Locks or unlocks the activation mode of automatic disconnection.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
   virtual HRESULT SetActivationStateLock(unsigned char iLock)=0;

/**
 * Retrieves informations about the activation mode of automatic disconnection.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
   virtual HRESULT GetActivationStateInfo(CATSettingInfo *oInfo)=0;

/**
 * Returns or sets the inactivity duration.
 * <br><b>Role</b>: Returns the timeout in seconds before the automatic
 * disconnection when no activity has been detected, if the mechanism is enabled.
 * @param oMaxInactivity
 *	The inactivity duration in seconds.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/   
   virtual HRESULT GetInactivityDuration(int *oMaxInactivity)=0;

/**
 * Sets the inactivity duration.
 * <br><b>Role</b>: Sets the timeout in seconds before the automatic
 * disconnection when no activity has been detected, if the mechanism is enabled.
 * @param iMaxInactivity
 *	The inactivity duration in second.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
   virtual HRESULT PutInactivityDuration(int iMaxInactivity)=0;


/**
 * Locks or unlocks the inactivity duration.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
   virtual HRESULT SetInactivityDurationLock(unsigned char iLock)=0;


/**
 * Retrieves environment informations for inactivity duration.
 * <br>Refer to @href CATSysSettingController for a detailled description.
*/
   virtual HRESULT GetInactivityDurationInfo(CATSettingInfo *oInfo)=0;

};
#endif
