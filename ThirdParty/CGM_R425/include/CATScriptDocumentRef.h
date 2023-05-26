#ifndef CATScriptDocumentRef_h
#define CATScriptDocumentRef_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "AutomationItf.h"
#include "CATScriptRef.h"

class CATDocument;

/**
 * Class to represent a reference to a document
 * script container.
 * Author: JDU
 */

class ExportedByCATAutoItf CATScriptDocumentRef : public CATScriptRef {
	public:
		CATDeclareClass;

		/**
		 * Factory method.
		 */
		static HRESULT CreateReference(
			CATDocument* iDocument,
			CATScriptDocumentRef*& oReference);

		/**
		 * Returns the referenced V5 document.
		 */
		CATDocument* GetDocument();

		/**
		 * Destructor.
		 */
		virtual ~CATScriptDocumentRef();

		virtual CATUnicodeString GetDisplayName();
        
        /**
         * Compare two CATScriptRef instances.
         */
        virtual HRESULT Equals(CATScriptRef &iScriptRef, bool &oEqual);
	
	private:
		/**
		 * Constructor.
		 */
		CATScriptDocumentRef(
			CATDocument* iDocument);

	private:
		CATDocument* _document;
};

#endif // CATScriptDocumentRef_h

