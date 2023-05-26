#ifndef CATDlgDeviceEvents_H
#define CATDlgDeviceEvents_H

#include "DI0PANV2.h"

#include "CATEventSubscriber.h"

#include "CATCallbackManager.h"

/** 
 * Class to define some events used by some devices (for example iOS)
 */
class ExportedByDI0PANV2 CATDlgDeviceEvents : public CATEventSubscriber
{
public:
	/**
	 * Event sent when the device is about to rotate
	 * You must subscribe to the CATApplication callback manager to be advised of this event
	 */
	CATDeclareCBEvent(DEVICE_WILL_ROTATE);

	/**
	 * Event sent when the device finished to rotate
	 * You must subscribe to the CATApplication callback manager to be advised of this event
	 */
	CATDeclareCBEvent(DEVICE_DID_ROTATE);

	/**
	 * Event sent when the device did shake
	 * You must subscribe to the CATApplication callback manager to be advised of this event
	 */
	CATDeclareCBEvent(DEVICE_DID_SHAKE);

	/**
	 * Event sent when the application goes to background
	 * You must subscribe to the CATApplication callback manager to be advised of this event
	 */
	CATDeclareCBEvent(APPLICATION_WILL_SUSPEND);

	/**
	 * Event sent when the application becomes active
	 * You must subscribe to the CATApplication callback manager to be advised of this event
	 */
	CATDeclareCBEvent(APPLICATION_DID_RESUME);

	/**
	 * Event sent when the application is activated with an URL
	 * You must subscribe to the CATApplication callback manager to be advised of this event
	 */
	CATDeclareCBEvent(APPLICATION_OPEN_URL);

	/**
	 * Event sent when the device is in a low memory situation
	 * You must subscribe to the CATApplication callback manager to be advised of this event
	 */
	CATDeclareCBEvent(LOW_MEMORY_WARNING);

	/**
	 * Event sent when the application settings are modified
	 * You must subscribe to the CATApplication callback manager to be advised of this event
	 */
	CATDeclareCBEvent(SETTINGS_MODIFIED);
};

#endif
