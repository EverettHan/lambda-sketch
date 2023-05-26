#ifndef CATScriptStartNotification_h
#define CATScriptStartNotification_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "AutomationItf.h"
#include "CATScriptNotificationBase.h"

class CATIScriptFunctionCall;

/**
 * Class for notifications sent when a CATIScriptFunctionCall starts.
 * @author: Jean-Francois Doue (JDU)
 */

class ExportedByCATAutoItf CATScriptStartNotification : public CATScriptNotificationBase {
	public:
		CATDeclareClass;

		/**
		 * Destructor.
		 */
		virtual ~CATScriptStartNotification();

		/**
		 * Factory method.
		 */
		static HRESULT CreateNotification(
			CATIScriptFunctionCall* iFctCall,
			CATScriptStartNotification*& oNotification);

	protected:
		/**
		 * Constructor.
		 */
		CATScriptStartNotification(
			CATIScriptFunctionCall* iFctCall);
};

#endif // CATScriptStartNotification_h
