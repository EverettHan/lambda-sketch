// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#ifndef CATSAXDefaultHandler_h
#define CATSAXDefaultHandler_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"
class CATISAXLocator_var;
class CATISAXAttributes_var;
class CATISAXInputSource_var;
class CATSAXParseException;

/**
 * Default base class for SAX2 event handlers.
 *
 *<p>This class is available as a convenience base class for SAX2
 * applications: it provides default implementations for all of the
 * callbacks in the four core SAX2 handler classes:</p>
 *
 * <ul>
 *  <li>@href CATISAXEntityResolver </li>
 *  <li>@href CATISAXDTDHandler </li>
 *  <li>@href CATISAXContentHandler </li>
 *  <li>@href CATISAXErrorHandler </li>
 * </ul>
 *
 * <p>Application writers can extend this class when they need to
 * implement only part of an interface; parser writers can
 * instantiate this class to provide default handlers when the
 * application has not supplied its own.</p>
 *
 * @see CATISAXEntityResolver, CATISAXDTDHandler, CATISAXContentHandler, CATISAXErrorHandler
 */
class ExportedByCatXmlItfBase CATSAXDefaultHandler: public CATBaseUnknown {
	CATDeclareClass;
	
	public:
		
		/**
		 * Constructor
		 */
		CATSAXDefaultHandler();

		/**
		 * Destructor
		 */
		virtual ~CATSAXDefaultHandler();

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
		virtual HRESULT StartDocument();
		
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
		virtual HRESULT EndDocument();
		
		/**
		 * Receives notification of the beginning of an element.
		 *
		 * <p>The Parser will invoke this method at the beginning of every
		 * element in the XML document; there will be a corresponding @href #EndElement 
		 * event for every @href #StartElement event
		 * (even when the element is empty).</p>
                 *
                 * <p>All of the element content will be reported, in order,
                 * before the corresponding @href #EndElement event @href .</p>
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
			const CATISAXAttributes_var & iAttributes);
		
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
			const CATUnicodeString & iQualifiedName);
		
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
			const CATUnicodeString & iCharacters);
		
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
			const CATUnicodeString & iCharacters);
		
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
			const CATUnicodeString & iData);
		
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
			const CATISAXLocator_var& iLocator);

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
			const CATUnicodeString & iURI);

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
			const CATUnicodeString & iPrefix);

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
			const CATUnicodeString & iName);


		/**
		 * Receives notification of a notation declaration event.
		 *
		 * <p>It is up to the application to record the notation for later
		 * reference, if necessary.</p>
		 *
		 * <p>At least one of publicId and systemId must be non-empty.</p>
		 *
		 * <p>If a system identifier is present, and it is a URL, the SAX
		 * parser must resolve it fully before passing it to the
		 * application.</p>
		 *
		 * @param iName
		 * The notation name.
		 * @param iPublicId
		 * The notation's public identifier (can be an empty @href CATUnicodeString if
		 * no public identifier was given).
		 * @param iSystemId
		 * The notation's system identifier (can be an empty @href CATUnicodeString if
		 * no system identifier was given).
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
		 * @see CATISAXAttributes, #UnparsedEntityDecl
		 * 
		 */
		virtual HRESULT NotationDecl(
			const CATUnicodeString & iName, 
			const CATUnicodeString & iPublicId, 
			const CATUnicodeString & iSystemId);
		
		/**
		 * Receives notification of an unparsed entity declaration event.
		 *
		 * <p>Note that the notation name corresponds to a notation
		 * reported by the @href #NotationDecl event.  It is up to the
		 * application to record the entity for later reference, if
		 * necessary.</p>
		 *
		 * <p>If the system identifier is a URL, the parser must resolve it
		 * fully before passing it to the application.</p>
		 *
		 * @param iName 
		 * The unparsed entity's name.
		 * @param iPublicId 
		 * The entity's public identifier (can be an empty @href CATUnicodeString if
		 * no public identifier was given).
		 * @param iSystemId 
		 * The entity's system identifier (it must always have one).
		 * @param iNotationName
		 * name The name of the associated notation.
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
		 * @see CATISAXAttributes, #NotationDecl
		 */
		virtual HRESULT UnparsedEntityDecl(
			const CATUnicodeString & iName, 
			const CATUnicodeString & iPublicId, 
			const CATUnicodeString & iSystemId, 
			const CATUnicodeString & iNotationName);

		
		/**
		 * Allows the application to resolve external entities.
		 *
		 * <p>The @href CATISAXXMLReader will call this method before opening any external
		 * entity except the top-level document entity (including the
		 * external DTD subset, external entities referenced within the
		 * DTD, and external entities referenced within the document
		 * element): the application may request that the parser resolve
		 * the entity itself, that it use an alternative URI, or that it
		 * use an entirely different input source.</p>
		 *
		 * <p>Application writers can use this method to redirect external
		 * system identifiers to secure and/or local URIs, to look up
		 * public identifiers in a catalogue, or to read an entity from a
		 * database or other input source (including, for example, a dialog
		 * box).</p>
		 *
		 * <p>If the system identifier is a URL, the SAX parser must
		 * resolve it fully before reporting it to the application.</p>
		 *
		 * @param iPublicId 
		 * The public identifier of the external entity being referenced 
		 * (can be an empty @href CATUnicodeString if no public identifier was given).
		 * @param iSystemId 
		 * The system identifier of the external entity being referenced.
		 * @param oInputSource
		 * An InputSource object describing the new input source,
		 *         or <tt>NULL</tt> to request that the parser open a regular
		 *         URI connection to the system identifier.
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
		 *        <td class="errtd">@href CATSAXIOException </td>
		 *        <td class="errtd">XMLParserERR_2001</td>
		 *        <td class="errtd">If an I/O error occurs, possibly the result of creating a new @href CATISAXInputSource
		 * the method can raise this error.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATISAXInputSource
		 */
		virtual HRESULT ResolveEntity(
			const CATUnicodeString & iPublicId, 
			const CATUnicodeString & iSystemId, 
			CATISAXInputSource_var& oInputSource);

		
		/**
		 * Receives notification of a recoverable error.
		 *
		 * <p>This corresponds to the definition of "error" in section 1.2
		 * of the W3C XML 1.0 Recommendation.  For example, a validating
		 * parser would use this callback to report the violation of a
		 * validity constraint.  The default behaviour is to take no
		 * action.</p>
		 *
		 * <p>The SAX parser must continue to provide normal parsing events
		 * after invoking this method: it should still be possible for the
		 * application to process the document through to the end.  If the
		 * application cannot do so, then the parser should report a fatal
		 * error even if the XML 1.0 recommendation does not require it to
		 * do so.</p>
		 *
		 * @param iException
		 * The error information encapsulated in a SAX parse exception.
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
		 * @see CATSAXParseException 
		 */
		virtual HRESULT Error(
			CATSAXParseException* iException);
		
		/**
		 * Receives notification of a non-recoverable error.
		 *
		 * <p>This corresponds to the definition of "fatal error" in
		 * section 1.2 of the W3C XML 1.0 Recommendation.  For example, a
		 * parser would use this callback to report the violation of a
		 * well-formedness constraint.</p>
		 *
		 * <p>The application must assume that the document is unusable
		 * after the parser has invoked this method, and should continue
		 * (if at all) only for the sake of collecting addition error
		 * messages: in fact, SAX parsers are free to stop reporting any
		 * other events once this method has been invoked.</p>
		 *
		 * @param iException 
		 * The error information encapsulated in a SAX parse exception.
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
		 * @see CATSAXParseException
		 */
		virtual HRESULT FatalError(
			CATSAXParseException* iException);
		
		/**
		 * Receives notification of a warning.
		 *
		 * <p>SAX parsers will use this method to report conditions that
		 * are not errors or fatal errors as defined by the XML 1.0
		 * recommendation.  The default behaviour is to take no action.</p>
		 *
		 * <p>The SAX parser must continue to provide normal parsing events
		 * after invoking this method: it should still be possible for the
		 * application to process the document through to the end.</p>
		 *
		 * @param iException
		 * The warning information encapsulated in a SAX parse exception.
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
		 * @see CATSAXParseException 
		 */
		virtual HRESULT Warning(
			CATSAXParseException* iException);

	private:
		CATSAXDefaultHandler (CATSAXDefaultHandler &);
		CATSAXDefaultHandler& operator=(CATSAXDefaultHandler&);
};

#endif // CATSAXDefaultHandler_h
