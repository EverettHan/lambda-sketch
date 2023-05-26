#ifndef CATScriptVSTARef_h
#define CATScriptVSTARef_h

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "AutomationItf.h"
#include "CATScriptRef.h"
#include "CATUnicodeString.h"

/**
 * Class to represent a reference to a VSTA script container.
 */
class ExportedByCATAutoItf CATScriptVSTARef : public CATScriptRef {
	public:
		CATDeclareClass;

		/**
		 * Factory method.
		 */
		static HRESULT CreateReference(
			const CATUnicodeString& iProjectPath,
			CATScriptVSTARef*& oReference);

		static HRESULT CreateReference(
			const CATUnicodeString& iProjectPath,
			const CATUnicodeString& iOwnerContainerEncodedRef,
			CATScriptVSTARef*& oReference);

		/**
		 * Returns the referenced VSTA Project.
		 */
		CATUnicodeString GetProjectPath();

		/**
		 * Destructor.
		 */
		virtual ~CATScriptVSTARef();

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
		CATScriptVSTARef(
			const CATUnicodeString& iProjectPath,
                        const CATUnicodeString* iOwnerContainerEncodedRef = NULL);

	private:
		CATUnicodeString _projectPath;
		CATUnicodeString _OwnerContainerEncodedRef;
		CATBoolean       _OwnerContainerEncodedRefSet;
};

#endif // CATScriptVSTARef_h

