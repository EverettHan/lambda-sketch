#ifndef CATScriptFormRef_h
#define CATScriptFormRef_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"
#include "CATScriptRef.h"
#include "CATUnicodeString.h"

/**
 * Class to represent a reference to a scripted form.
 * Author: JDU
 */

class ExportedByCATAutoItf CATScriptFormRef : public CATScriptRef {
	public:
		CATDeclareClass;

		/**
		 * Factory method.
		 */
		static HRESULT CreateReference(
			const CATUnicodeString& iFormName,
			CATScriptRef* iContainerRef,
			CATScriptFormRef*& oReference);

		/**
		 * Returns the form name.
		 */
		CATUnicodeString GetFormName();

		/**
		 * Returns the reference to the form container.
		 */
		CATScriptRef* GetContainerRef();

		/**
		 * Destructor.
		 */
		virtual ~CATScriptFormRef();

		virtual CATUnicodeString GetDisplayName();
        
        virtual HRESULT Equals(CATScriptRef &iScriptRef, bool &oEqual) { return E_NOTIMPL; }
	
	private:
		/**
		 * Constructor.
		 */
		CATScriptFormRef(
			const CATUnicodeString& iFormName,
			CATScriptRef* iContainerRef);

        // Members
		CATUnicodeString _formName;
		CATScriptRef* _containerRef;
};

#endif // CATScriptFormRef_h

