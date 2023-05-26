#ifndef CATScriptStopNotification_h
#define CATScriptStopNotification_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "AutomationItf.h"
#include "CATScriptNotificationBase.h"

class CATIScriptFunctionCall;

/**
 * Class for notifications sent when a CATIScriptFunctionCall stops.
 * @author: Jean-Francois Doue (JDU)
 */

class ExportedByCATAutoItf CATScriptStopNotification : public CATScriptNotificationBase {
	public:
		CATDeclareClass;

		/**
		 * Destructor.
		 */
		virtual ~CATScriptStopNotification();

		/**
		 * Factory method.
		 */
		static HRESULT CreateNotification(
			CATIScriptFunctionCall* iFctCall,
			CATScriptStopNotification*& oNotification);

	protected:
		/**
		 * Constructor.
		 */
		CATScriptStopNotification(
			CATIScriptFunctionCall* iFctCall);
};

#endif // CATScriptStopNotification_h

