/**
 * @level Protected
 * @usage U1
 */

/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//===================================================================
//
// CATEventBus:
// An event bus able to convey Events and Notifications.
// This class is a singleton.
//===================================================================
// Feb.   1998  Creation                         P. Grignon (PPG) 
//===================================================================
/**
* @level Protected 
* @usage U1
*/

#include "CATLifDictionary.h" // Just for WinNT dllexport !!
#include "CATEventSubscriber.h"
#include "CATCallbackManager.h"
#include "CATNotification.h"

#ifndef CATEventBus_h
#define CATEventBus_h

/** The CATEventBus<br>
*  This class is a Singleton i.e. there exists only one instance of the bus.<br>
*  WARNING !!<br>
* The bus is detroyed by Knowledgeware only. However, it is recommended to any user
* to listen to the CATKWEBusDeleteEvent. If this event is received it means that <br>
* bus was destroyed and thus any previously stored reference to this bus is obsolete.<br>
* It is then advised to remove all callbacks put on the bus and put them on a new bus <br>
* obtained via the CATEventBusInstance method.
*/
class ExportedByCATLifDictionary CATEventBus : public CATCallbackManager
{
	CATDeclareClass;
	static CATEventBus* CATEventBusInstance();
	static void CATEventBusDelete();
	void SendEvent(CATNotification* myNotif);
};
#endif


