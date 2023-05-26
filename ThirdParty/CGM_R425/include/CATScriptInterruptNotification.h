#ifndef CATScriptInterruptNotification_h
#define CATScriptInterruptNotification_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "AutomationItf.h"
#include "CATScriptNotificationBase.h"

class CATIScriptFunctionCall;

/**
 * Class for notifications sent when a CATIScriptFunctionCall is interrupted.
 * @author: Jean-Francois Doue (JDU)
 */

class ExportedByCATAutoItf CATScriptInterruptNotification : public CATScriptNotificationBase {
	public:
		CATDeclareClass;

		/**
		 * Destructor.
		 */
		virtual ~CATScriptInterruptNotification();

		/**
		 * Factory method.
		 */
		static HRESULT CreateNotification(
			CATIScriptFunctionCall* iFctCall,
			CATScriptInterruptNotification*& oNotification);

	protected:
		/**
		 * Constructor.
		 */
		CATScriptInterruptNotification(
			CATIScriptFunctionCall* iFctCall);
};

#endif // CATScriptInterruptNotification_h

