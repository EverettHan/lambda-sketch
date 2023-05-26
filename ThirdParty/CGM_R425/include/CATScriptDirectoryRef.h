#ifndef CATScriptDirectoryRef_h
#define CATScriptDirectoryRef_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"
#include "CATScriptRef.h"
#include "CATUnicodeString.h"

/**
 * Class to represent a reference to a directory
 * script container.
 * Author: JDU
 */

class ExportedByCATAutoItf CATScriptDirectoryRef : public CATScriptRef {
	public:
		CATDeclareClass;

		/**
		 * Factory method.
		 */
		static HRESULT CreateReference(
			const CATUnicodeString& iDirectoryPath,
                        const CATUnicodeString& iOwnerContainerEncodedRef,
			CATScriptDirectoryRef*& oReference);

                static HRESULT CreateReference(
			const CATUnicodeString& iDirectoryPath,
			CATScriptDirectoryRef*& oReference);

		/**
		 * Returns the referenced directory.
		 */
		CATUnicodeString GetDirectoryPath();

		/**
		 * Destructor.
		 */
		virtual ~CATScriptDirectoryRef();

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
		CATScriptDirectoryRef(
			const CATUnicodeString& iDirectoryPath,
                        const CATUnicodeString* iOwnerContainerEncodedRef = NULL);

	private:
		CATUnicodeString _directoryPath;
		CATUnicodeString _OwnerContainerEncodedRef;
		CATBoolean       _OwnerContainerEncodedRefSet;
};

#endif // CATScriptDirectoryRef_h

