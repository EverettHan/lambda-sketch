#ifndef CATScriptCATVBARef_h
#define CATScriptCATVBARef_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"
#include "CATScriptRef.h"
#include "CATUnicodeString.h"

/**
 * Class to represent a reference to a CATVBA
 * script container.
 * Author: JDU
 */

class ExportedByCATAutoItf CATScriptCATVBARef : public CATScriptRef {
	public:
		CATDeclareClass;

		/**
		 * Factory method.
		 */
		static HRESULT CreateReference(
			const CATUnicodeString& iProjectPath,
			CATScriptCATVBARef*& oReference);

		static HRESULT CreateReference(
			const CATUnicodeString& iProjectPath,
			const CATUnicodeString& iOwnerContainerEncodedRef,
			CATScriptCATVBARef*& oReference);

		/**
		 * Returns the referenced VBA Project.
		 */
		CATUnicodeString GetProjectPath();

		/**
		 * Destructor.
		 */
		virtual ~CATScriptCATVBARef();

		virtual CATUnicodeString GetDisplayName();

		// oHasOwnerContainer == TRUE if this has an owner container then oOwnerContainerEncodedRef contains the encoded ref
                // else oHasOwnerContainer == FALSE
                virtual HRESULT GetOwnerContainerEncodedRef(CATBoolean & oHasOwnerContainer, CATUnicodeString & oOwnerContainerEncodedRef);
        
        /**
         * Compare two CATScriptRef instances.
         */
        virtual HRESULT Equals(CATScriptRef &iScriptRef, bool &oEqual);
	
	private:
		/**
		 * Constructor.
		 */
		CATScriptCATVBARef(
			const CATUnicodeString& iProjectPath,
                        const CATUnicodeString* iOwnerContainerEncodedRef = NULL);

	private:
		CATUnicodeString _projectPath;
		CATUnicodeString _OwnerContainerEncodedRef;
		CATBoolean       _OwnerContainerEncodedRefSet;
};

#endif // CATScriptCATVBARef_h

