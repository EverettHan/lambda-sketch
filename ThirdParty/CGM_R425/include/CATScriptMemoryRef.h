#ifndef CATScriptMemoryRef_h
#define CATScriptMemoryRef_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"
#include "CATScriptRef.h"
#include "CATUnicodeString.h"

/**
 * Class to represent a reference to a memory
 * script container. The memory container is known by its
 * identifier (a CATUnicodeString)
 * Author: JDU
 */

class ExportedByCATAutoItf CATScriptMemoryRef : public CATScriptRef {
	public:
		CATDeclareClass;

		/**
		 * Factory method.
		 */
		static HRESULT CreateReference(
			const CATUnicodeString& iIdentifier,
			CATScriptMemoryRef*& oReference);

		/**
		 * Returns the container identifier.
		 */
		CATUnicodeString GetIdentifier();

		/**
		 * Destructor.
		 */
		virtual ~CATScriptMemoryRef();

		virtual CATUnicodeString GetDisplayName();
        
        /**
         * Compare two CATScriptRef instances.
         */
        virtual HRESULT Equals(CATScriptRef &iScriptRef, bool &oEqual);
	
	private:
		/**
		 * Constructor.
		 */
		CATScriptMemoryRef(
			const CATUnicodeString& iIdentifier);

	private:
		CATUnicodeString _identifier;
};

#endif // CATScriptMemoryRef_h

