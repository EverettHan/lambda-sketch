// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATISAXContentHandler_h
#define CATISAXContentHandler_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"
class CATISAXLocator_var;
class CATISAXAttributes_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXContentHandler;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXContentHandler ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to receive notification of the logical content of a document.
 *
 * <p>This is the main interface that most SAX applications
 * implement: if the application needs to be informed of basic parsing 
 * events, it implements this interface and registers an instance with 
 * the SAX parser using the @href CATISAXXMLReader#SetContentHandler method.  
 * The parser uses the instance to report basic document-related events like the start and end of elements 
 * and character data.</p>
 *
 * <p>The order of events in this interface is very important, and
 * mirrors the order of information in the document itself.  For
 * example, all of an element content (character data, processing
 * instructions, and/or subelements) will appear, in order, between
 * the @href #StartElement event and the corresponding @href #EndElement event.</p>
 *
 * @see CATISAXXMLReader#SetContentHandler, CATISAXLocator, CATSAXDefaultHandler
 */
class ExportedByCatXmlItfBase CATISAXContentHandler: public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		
		/**
		 * Receives notification of the beginning of a document.
		 *
		 * <p>The SAX parser will invoke this method only once, before any
		 * other methods in this interface or in @href CATISAXDTDHandler (except for
		 * @href #SetDocumentLocator ).</p>
		 *
		 * <dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * </dl>
		 * 
		 * @see #EndDocument
		 */
		virtual HRESULT StartDocument() = 0;
		
		/**
		 * Receives notification of the end of a document.
		 *
		 * <p>The SAX parser will invoke this method only once, and it will
		 * be the last method invoked during the parse.  The parser shall
		 * not invoke this method until it has either abandoned parsing
		 * (because of an unrecoverable error) or reached the end of
		 * input.</p>
		 *
		 * <dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * </dl>
		 * 
		 * @see #StartDocument
		 */
		virtual HRESULT EndDocument() = 0;
		
		/**
		 * Receives notification of the beginning of an element.
		 *
		 * <p>The Parser will invoke this method at the beginning of every
		 * element in the XML document; there will be a corresponding @href #EndElement 
		 * event for every @href #StartElement event
		 * (even when the element is empty).</p>
		 *
                 * <p>All of the element content will be
		 * reported, in order, before the corresponding @href #EndElement event @href .</p>
		 *
		 * <p>This event allows up to three name components for each
		 * element:</p>
		 *
		 * <ol>
		 * <li>the Namespace URI;</li>
		 * <li>the local name; and</li>
		 * <li>the qualified (prefixed) name.</li>
		 * </ol>
		 *
		 * <p>Any or all of these may be provided, depending on the
		 * values of the <tt>http://xml.org/sax/features/namespaces</tt>
		 * and the <tt>http://xml.org/sax/features/namespace-prefixes</tt>
		 * properties:</p>
		 *
		 * <ul>
		 * <li>the Namespace URI and local name are required when 
		 * the namespaces property is <tt>TRUE</tt> (the default), and are
		 * optional when the namespaces property is <tt>FALSE</tt> (if one is
		 * specified, both must be);</li>
		 * <li>the qualified name is required when the namespace-prefixes property
		 * is <tt>TRUE</tt>, and is optional when the namespace-prefixes property
		 * is <tt>FALSE</tt> (the default).</li>
		 * </ul>
		 *
		 * <p>Note that the attribute list provided will contain only
		 * attributes with explicit values (specified or defaulted):
		 * <tt>#IMPLIED</tt> attributes will be omitted.  The attribute list
		 * will contain attributes used for Namespace declarations
		 * (xmlns* attributes) only if the
		 * <tt>http://xml.org/sax/features/namespace-prefixes</tt>
		 * property is <tt>TRUE</tt> (it is <tt>FALSE</tt> by default, and support for a 
		 * <tt>TRUE</tt> value is optional).</p>
		 *
		 * @param iURI 
		 * The Namespace URI, or the empty string if the element has no Namespace URI or if Namespace processing is not being performed.
		 * @param iLocalName 
		 * The local name (without prefix), or the empty string if Namespace processing is not being performed.
		 * @param iQualifiedName 
		 * The qualified name (with prefix), or the empty string if qualified names are not available.
		 * @param iAttributes 
		 * The attributes attached to the element. If there are no attributes, it shall be an empty @href CATISAXAttributes object.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 * @see CATISAXAttributes, #EndElement
		 */
		virtual HRESULT StartElement(
			const CATUnicodeString & iURI, 
			const CATUnicodeString & iLocalName, 
			const CATUnicodeString & iQualifiedName, 
			const CATISAXAttributes_var & iAttributes) = 0;
		
		/**
		 * Receives notification of the end of an element.
		 *
		 * <p>The SAX parser will invoke this method at the end of every
		 * element in the XML document; there will be a corresponding
		 * @href #StartElement event for every @href #EndElement event
		 * (even when the element is empty).</p>
		 * 
		 * <p>For information on the names, see @href #StartElement.</p>
		 *
		 * @param iURI 
		 * The Namespace URI, or the empty string if the element has no Namespace URI or if Namespace processing is not being performed.
		 * @param iLocalName 
		 * The local name (without prefix), or the empty string if Namespace processing is not being performed.
		 * @param iQualifiedName 
		 * The qualified name (with prefix), or the empty string if qualified names are not available.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 * @see #StartElement
		 */
		virtual HRESULT EndElement(
			const CATUnicodeString & iURI, 
			const CATUnicodeString & iLocalName, 
			const CATUnicodeString & iQualifiedName) = 0;
		
		/**
		 * Receives notification of character data.
		 *
		 * <p>The @href CATISAXXMLReader will call this method to report each chunk of
		 * character data.  SAX parsers may return all contiguous character
		 * data in a single chunk, or they may split it into several
		 * chunks; however, all of the characters in any single event
		 * must come from the same external entity, so that the @href CATISAXLocator
		 * provides useful information.</p>
		 *
		 * <p>Note that some parsers will report whitespace using the
		 * @href #IgnorableWhiteSpace method rather than this one (validating
		 * parsers must do so).</p>
		 *
		 * @param iCharacters 
		 * The characters from the XML document.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see #IgnorableWhiteSpace, CATISAXLocator
		 */
		virtual HRESULT Characters(
			const CATUnicodeString & iCharacters) = 0;
		
		/**
		 * Receives notification of ignorable whitespace in element content.
		 *
		 * <p>Validating @href CATISAXXMLReader s must use this method to report each chunk
		 * of ignorable whitespace (see the W3C XML 1.0 recommendation,
		 * section 2.10): non-validating parsers may also use this method
		 * if they are capable of parsing and using content models.</p>
		 *
		 * <p>SAX parsers may return all contiguous whitespace in a single
		 * chunk, or they may split it into several chunks; however, all of
		 * the characters in any single event must come from the same
		 * external entity, so that the @href CATISAXLocator provides useful
		 * information.</p>
		 *
		 * @param iCharacters 
		 * The characters from the XML document.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 * @see #Characters
		 */
		virtual HRESULT IgnorableWhiteSpace(
			const CATUnicodeString & iCharacters) = 0;
		
		/**
		 * Receives notification of a processing instruction.
		 *
		 * <p>The @href CATISAXXMLReader will invoke this method once for each processing
		 * instruction found: note that processing instructions may occur
		 * before or after the main document element.</p>
		 *
		 * <p>A SAX parser should never report an XML declaration (XML 1.0,
		 * section 2.8) or a text declaration (XML 1.0, section 4.3.1)
		 * using this method.</p>
		 *
		 * @param iTarget
		 * The processing instruction target.
		 * @param iData 
		 * The processing instruction data (can be an empty @href CATUnicodeString if
		 * no processing instruction data was given).
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 */
		virtual HRESULT ProcessingInstruction(
			const CATUnicodeString & iTarget, 
			const CATUnicodeString & iData) = 0;
		
		/**
		 * Receives an object for locating the origin of SAX content events.
		 *
		 * <p>SAX parsers are strongly encouraged (though not absolutely
		 * required) to supply a locator: if it does so, it must supply
		 * the locator to the application by invoking this method before
		 * invoking any of the other methods in the @href CATISAXContentHandler
		 * interface.</p>
		 *
		 * <p>The locator allows the application to determine the end
		 * position of any document-related event, even if the parser is
		 * not reporting an error.  Typically, the application will
		 * use this information for reporting its own errors (such as
		 * character content that does not match an application's
		 * business rules).  The information returned by the locator
		 * is probably not sufficient for use with a search engine.</p>
		 *
		 * <p>Note that the locator will return correct information only
		 * during the invocation of the events in this interface.  The
		 * application should not attempt to use it at any other time.</p>
		 *
		 * @param iLocator
		 * An object that can return the location of any SAX document event.
		 *
		 * @see CATISAXLocator
		 */
		virtual HRESULT SetDocumentLocator(
			const CATISAXLocator_var& iLocator) = 0;

		/**
		 * Receives notification of the beginning of the scope of a prefix-URI Namespace mapping.
		 *
		 * <p>The information from this event is not necessary for
		 * normal Namespace processing: the @href CATISAXXMLReader will 
		 * automatically replace prefixes for element and attribute
		 * names when the <tt>http://xml.org/sax/features/namespaces</tt>
		 * feature is <tt>TRUE</tt> (the default).</p>
		 *
		 * <p>There are cases, however, when applications need to
		 * use prefixes in character data or in attribute values,
		 * where they cannot safely be expanded automatically; the
		 * @href #StartPrefixMapping / @href #EndPrefixMapping events supply the information
		 * to the application to expand prefixes in those contexts
		 * itself, if necessary.</p>
		 *
		 * <p>Note that @href #StartPrefixMapping / @href #EndPrefixMapping events are not
		 * guaranteed to be properly nested relative to each-other:
		 * all @href #StartPrefixMapping events will occur before the
		 * corresponding @href #StartElement event, and all @href #EndPrefixMapping events
		 * will occur after the corresponding @href #StartElement event, 
		 * but their order is not otherwise guaranteed.</p>
		 *
		 * <p>There should never be @href #StartPrefixMapping / @href #EndPrefixMapping events for the
		 * "xml" prefix, since it is predeclared and immutable.</p>
		 *
		 * @param iPrefix
		 * The Namespace prefix being declared.
		 * @param iURI 
		 * The Namespace URI the prefix is mapped to.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 * @see #EndPrefixMapping
		 */
		virtual HRESULT StartPrefixMapping(
			const CATUnicodeString & iPrefix, 
			const CATUnicodeString & iURI) = 0;

		/**
		 * Receives notification of the end of the scope of a prefix-URI Namespace mapping.
		 *
		 * @param iPrefix
		 * The prefix that was being mapped.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 * @see #StartPrefixMapping
		 */
		virtual HRESULT EndPrefixMapping(
			const CATUnicodeString & iPrefix) = 0;

		/**
		 * Receives notification of a skipped entity.
		 *
		 * <p>The @href CATISAXXMLReader will invoke this method once for each entity
		 * skipped.  Non-validating processors may skip entities if they
		 * have not seen the declarations (because, for example, the
		 * entity was declared in an external DTD subset).  All processors
		 * may skip external entities, depending on the values of the
		 * <tt>http://xml.org/sax/features/external-general-entities</tt>
		 * and the
		 * <tt>http://xml.org/sax/features/external-parameter-entities</tt>
		 * properties.</p>
		 *
		 * @param iName
		 * The name of the skipped entity. If it is a parameter entity, the name will begin with <tt>'%'</tt>, and if it is the external DTD subset, it will be the string <tt>"[dtd]"</tt>.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT SkippedEntity(
			const CATUnicodeString & iName) = 0;
};

CATDeclareHandler(CATISAXContentHandler, CATBaseUnknown);

#endif // CATISAXContentHandler_h
