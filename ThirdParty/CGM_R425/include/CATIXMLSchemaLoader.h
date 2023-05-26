#ifndef CATIXMLSchemaLoader_h
#define CATIXMLSchemaLoader_h

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// COPYRIGHT DASSAULT SYSTEMES 2006

// System framework
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"

// XMLParser framework
#include "CatXmlItfBase.h"
class CATISAXInputSource_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLSchemaLoader;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLSchemaLoader ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to manage the loading and caching of XML schemas for DOM and SAX schema validation.
 * Objects which implement CATIXMLDOMDocumentBuilder, CATISAXXMLReader will
 * also implement this interface if they support schema pre-loading and caching.
 */
class ExportedByCatXmlItfBase CATIXMLSchemaLoader : public CATBaseUnknown {
	CATDeclareInterface;
	public:
		/**
		 * Asks the loader to pre-load an XML schema.
		 * @param iNamespaceURI
		 * The namespace URI of the schema
		 * @param iSchema
		 * An input source containing the actual schema.
		 */
		virtual HRESULT PreloadSchema(
			const CATUnicodeString& iNamespaceURI,
			const CATISAXInputSource_var& iSchema) = 0;

		/**
		 * Clears the schema cache.
		 */
		virtual HRESULT ClearSchemaCache() = 0;
};

CATDeclareHandler(CATIXMLSchemaLoader, CATBaseUnknown);

#endif // CATIXMLSchemaLoader_h
