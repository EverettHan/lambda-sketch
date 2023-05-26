#ifndef CATScriptRef_h
#define CATScriptRef_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

/**
 * Abstract base class for the scripting reference objects.
 * A scripting reference can be used to point to a container
 * or a program.
 * Author: JDU
 */

class ExportedByCATAutoItf CATScriptRef : public CATBaseUnknown {
	public:
		/**
		 * Destructor.
		 */
		virtual ~CATScriptRef();

		/**
		 * Returns the reference display name.
		 */
		virtual CATUnicodeString GetDisplayName() = 0;
        
        /**
         * Compare two CATScriptRef instances.
         */
        virtual HRESULT Equals(CATScriptRef &iScriptRef, bool &oEqual) = 0;

	protected:
		/**
		 * Constructor.
		 */
		CATScriptRef();
};

#endif // CATScriptRef_h

