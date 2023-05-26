// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef CATSAXXMLReaderOptions_h
#define CATSAXXMLReaderOptions_h

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

// System framework
#include "CATUnicodeString.h"

// XMLParser framework
#include "CatXmlItfBase.h"

// Standard SAX2 features

/**
 * Class to group constants which correspond to the standard SAX2 features and properties.
 */
class ExportedByCatXmlItfBase CATSAXXMLReaderOptions {
	public:
		/**
		 * Feature to activate namespace support in <tt>CATISAXAttributes</tt>.
		 * The corresponding SAX2 feature name is: <tt>http://xml.org/sax/features/namespaces</tt>
		 * Default value is <tt>TRUE</tt>.
		 */
		static CATUnicodeString NamespacesFeature;

		/**
		 * Feature to add namespace definition attributes to <tt>CATISAXAttributes</tt>.
		 * The corresponding SAX2 feature name is: <tt>http://xml.org/sax/features/namespace-prefixes</tt>
		 * Default value is <tt>FALSE</tt>.
		 */
		static CATUnicodeString NamespacePrefixFeature;

		/**
		 * Feature to trigger validation for <tt>CATIXMLSAXReader</tt>.
		 * The corresponding SAX2 feature name is: <tt>http://xml.org/sax/features/validation</tt>
		 * It is currently not supported.
		 */
		static CATUnicodeString ValidationFeature;

		/**
		 * Reports whether this parser processes external general entities; always true if validating.
		 */
		static CATUnicodeString ExternalGeneralEntitiesFeature;

		/**
		 * Reports whether this parser processes external parameter entities; always true if validating.
		 */
		static CATUnicodeString ExternalParameterEntitiesFeature;


		// Standard SAX2 properties

		/**
		 * Property to specify a decl handler for decl events generated by a <tt>CATIXMLSAXReader</tt>.
		 * The corresponding SAX2 property name is: <tt>http://xml.org/sax/properties/declaration-handler</tt>
		 * Default value is <tt>FALSE</tt>.
		 */
		static CATUnicodeString DeclHandlerProperty;

		/**
		 * Property to specify a lexical handler for lexical events generated by a <tt>CATIXMLSAXReader</tt>.
		 * The corresponding SAX2 property name is: <tt>http://xml.org/sax/properties/lexical-handler</tt>
		 * Default value is <tt>FALSE</tt>.
		 */
		static CATUnicodeString LexicalHandlerProperty;

	private:
		/**
		 * Make the class non instantiable
		 */
		CATSAXXMLReaderOptions();
};

#endif // CATSAXXMLReaderOptions_h
