#ifdef _WINDOWS_SOURCE
#ifndef CATVBAScriptNotifications_h
#define CATVBAScriptNotifications_h

// COPYRIGHT DASSAULT SYSTEMES 2013

#include "AutomationItf.h"
#include "CATNotification.h"

/**
 * Class for notifications sent when a VBA script starts. 
 */

class ExportedByCATAutoItf CATVBAScriptStartNotification : public CATNotification 
{
	public:
		CATDeclareClass;
		CATVBAScriptStartNotification();
		virtual ~CATVBAScriptStartNotification();
};

/**
 * Class for notifications sent when a VBA script stops.
 */
class ExportedByCATAutoItf CATVBAScriptStopNotification : public CATNotification 
{
	
	public:
		CATDeclareClass;
		CATVBAScriptStopNotification();
		virtual ~CATVBAScriptStopNotification();
};

#endif // CATVBAScriptNotifications_h
#endif // _WINDOWS_SOURCE
