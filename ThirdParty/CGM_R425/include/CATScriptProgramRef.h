#ifndef CATScriptProgramRef_h
#define CATScriptProgramRef_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"
#include "CATScriptRef.h"
#include "CATUnicodeString.h"

/**
 * Class to represent a reference to a scripted program.
 * Author: JDU
 */

class ExportedByCATAutoItf CATScriptProgramRef : public CATScriptRef {
	public:
		CATDeclareClass;

		/**
		 * Factory method.
		 */
		static HRESULT CreateReference(
			const CATUnicodeString& iProgramName,
			CATScriptRef* iContainerRef,
			CATScriptProgramRef*& oReference);

		/**
		 * Returns the form name.
		 */
		CATUnicodeString GetProgramName();

		/**
		 * Returns the reference to the form container.
		 */
		CATScriptRef* GetContainerRef();

		/**
		 * Destructor.
		 */
		virtual ~CATScriptProgramRef();

		virtual CATUnicodeString GetDisplayName();
        
        virtual HRESULT Equals(CATScriptRef &iScriptRef, bool &oEqual);
	
	private:
		/**
		 * Constructor.
		 */
		CATScriptProgramRef(
			const CATUnicodeString& iProgramName,
			CATScriptRef* iContainerRef);

        // Members
		CATUnicodeString _programName;
		CATScriptRef* _containerRef;
};

#endif // CATScriptProgramRef_h

