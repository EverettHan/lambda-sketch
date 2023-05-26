#ifndef CATScriptNotificationBase_h
#define CATScriptNotificationBase_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "AutomationItf.h"
#include "CATNotification.h"

class CATIScriptFunctionCall;

/**
 * Abstract base class for scripting notifications.
 * These notifications are broadcast both by the CATApplication
 * (for subscribers interested in global scripting events) and
 * by CATIScriptFunctionCalls (for subscribers interested in
 * events related to a particular script).
 * @author: Jean-Francois Doue (JDU)
 */
class ExportedByCATAutoItf CATScriptNotificationBase : public CATNotification {
	public:

		/**
		 * Destructor.
		 */
		virtual ~CATScriptNotificationBase();

		/**
		 * Returns the error object associated with the notification.
		 */
		HRESULT GetFunctionCall(
			CATIScriptFunctionCall*& oFctCall);

	protected:
		/**
		 * Constructor.
		 */
		CATScriptNotificationBase(
			CATIScriptFunctionCall* iFctCall);

	protected:
		CATIScriptFunctionCall* _fctCall;
};

#endif // CATScriptNotificationBase_h

