#ifndef CATScriptErrorNotification_h
#define CATScriptErrorNotification_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "AutomationItf.h"
#include "CATScriptNotificationBase.h"

class CATScriptError;
class CATIScriptFunctionCall;

/**
 * Class for notifications sent when a CATIScriptFunctionCall generates an error.
 * @author: Jean-Francois Doue (JDU)
 */

class ExportedByCATAutoItf CATScriptErrorNotification : public CATScriptNotificationBase {
	public:
		CATDeclareClass;

		/**
		 * Destructor.
		 */
		virtual ~CATScriptErrorNotification();

		/**
		 * Returns the error object associated with the notification.
		 */
		HRESULT GetError(
			CATScriptError*& oError);

		/**
		 * Sets the error object associated with the notification.
		 */
		HRESULT SetError(
			CATScriptError* iError);

		/**
		 * Factory method.
		 */
		static HRESULT CreateNotification(
			CATIScriptFunctionCall* iFctCall,
			CATScriptError* iError,
			CATScriptErrorNotification*& oNotification);

	protected:
		/**
		 * Constructor.
		 */
		CATScriptErrorNotification(
			CATIScriptFunctionCall* iFctCall,
			CATScriptError* iError);

		CATScriptError* _error;
};

#endif // CATScriptErrorNotification_h

