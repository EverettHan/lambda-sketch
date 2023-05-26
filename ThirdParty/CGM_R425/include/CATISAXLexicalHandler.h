// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATISAXLexicalHandler_h
#define CATISAXLexicalHandler_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXLexicalHandler;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXLexicalHandler ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to receive notification of lexical events.
 *
 * <p>This is an optional extension handler for SAX2 to provide
 * lexical information about an XML document, such as comments
 * and CDATA section boundaries; XML readers are not required to 
 * support this handler, and it is not part of the core SAX2
 * distribution.</p>
 *
 * <p>The events in the lexical handler apply to the entire document,
 * not just to the document element, and all lexical handler events
 * must appear between the content 
 * handler's @href CATISAXContentHandler#StartDocument and @href CATISAXContentHandler#EndDocument events.</p>
 *
 * <p>To set the CATISAXDeclHandler for an CATISAXXMLReader, use the
 * @href CATISAXXMLReader#SetProperty method
 * with the propertyId <tt>"http://xml.org/sax/properties/lexical-handler"</tt>.
 * If the reader does not support declaration events, it will return a
 * @href CATSAXNotRecognizedException error or a @href CATSAXNotSupportedException error
 * when you attempt to register the handler.</p>
 * 
 * @see CATISAXXMLReader
 */
class ExportedByCatXmlItfBase CATISAXLexicalHandler: public CATBaseUnknown {
	CATDeclareInterface;
	
	public:

 		/**
		 * Receives notification of an XML comment anywhere in the document.
		 *
		 * <p>This callback will be used for comments inside or outside the
		 * document element, including comments in the external DTD
		 * subset (if read).  Comments in the DTD must be properly
		 * nested inside @href #StartDTD / @href #EndDTD and @href #StartEntity / @href #EndEntity events (if
		 * used).</p>
		 *
		 * @param iComment
		 * The comment text.
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
		 *   </table>
		 * </dd>
		 *
		 * @see #StartCDATA
		 */
		virtual HRESULT Comment(
			const CATUnicodeString & iComment) = 0;

 		/**
		 * Receives notification of the end of a <tt>CDATA</tt> section.
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
		 *   </table>
		 * </dd>
		 *
		 * @see #StartCDATA
		 */
		virtual HRESULT EndCDATA() = 0;

 		/**
		 * Receives notification of the end of DTD declarations.
		 *
		 * <p>This method is intended to report the end of the
		 * <tt>DOCTYPE</tt> declaration; if the document has no <tt>DOCTYPE</tt> declaration,
		 * this method will not be invoked.</p>
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
		 *   </table>
		 * </dd>
		 *
		 * @see #StartDTD
		 */
		virtual HRESULT EndDTD() = 0;

 		/**
		 * Receives notification of the end of an entity.
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
		 *   </table>
		 * </dd>
		 *
		 * @param iName
		 * The name of the entity that is ending.
		 *
		 * @see #StartEntity
		 */
		virtual HRESULT EndEntity(
			const CATUnicodeString & iName) = 0;

 		/**
		 * Receives notification of  the start of a <tt>CDATA</tt> section.
		 *
		 * <p>The contents of the <tt>CDATA</tt> section will be reported through the regular 
		 * @href CATISAXContentHandler#Characters event; this event is intended only to report the boundary.</p>
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
		 *   </table>
		 * </dd>
		 *
		 * @see #EndCDATA
		 */
		virtual HRESULT StartCDATA() = 0;

 		/**
		 * Receives notification of the start of DTD declarations, if any.
		 *
		 * <p>This method is intended to report the beginning of the
		 * <tt>DOCTYPE</tt> declaration; if the document has no <tt>DOCTYPE</tt> declaration,
		 * this method will not be invoked.</p>
		 * 
		 * <p>All declarations reported through 
		 * @href CATISAXDTDHandler or @href CATISAXDeclHandler events must appear
		 * between the @href #StartDTD and @href #EndDTD events.
		 * Declarations are assumed to belong to the internal DTD subset
		 * unless they appear between @href #StartEntity and @href #EndEntity events.
		 * Comments and processing instructions from the DTD should also be reported
		 * between the @href #StartDTD and @href #EndDTD events, in their original 
		 * order of (logical) occurrence; they are not required to
		 * appear in their correct locations relative to @href CATISAXDTDHandler
		 * or @href CATISAXDeclHandler events, however.</p>
		 * 
		 * <p>Note that the @href #StartDTD / @href #EndDTD events will appear within
		 * the @href CATISAXContentHandler#StartDocument / @href CATISAXContentHandler#EndDocument events and
		 * before the first  @href CATISAXContentHandler#StartElement event.</p>
		 *
		 * @param iName
		 * The document type name.
		 * @param iPublicId
		 * The declared public identifier for the external DTD subset, or an empty string if none was declared.
		 * @param iSystemId
		 * The declared system identifier for the external DTD subset, or an empty string if none was declared.
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
		 *   </table>
		 * </dd>
		 *
		 * @see #EndDTD
		 */
		virtual HRESULT StartDTD(
			const CATUnicodeString & iName, 
			const CATUnicodeString & iPublicId,
			const CATUnicodeString & iSystemId) = 0;

 		/**
		 * Receives notification of the beginning of some internal and external XML entities.
		 *
		 * <p>The reporting of parameter entities (including
		 * the external DTD subset) is optional, and SAX2 drivers that
		 * support @href CATISAXLexicalHandler may not support it; you can use the
		 * <tt>http://xml.org/sax/features/lexical-handler/parameter-entities</tt>
		 * feature to query or control the reporting of parameter entities.</p>
		 *
		 * <p>General entities are reported with their regular names,
		 * parameter entities have <tt>'%'</tt> prepended to their names, and 
		 * the external DTD subset has the pseudo-entity name <tt>"[dtd]"</tt>.</p>
		 *
		 * <p>When a SAX2 driver is providing these events, all other 
		 * events must be properly nested within @href #StartEntity / @href #EndEntity events.
		 * There is no additional requirement that events from 
		 * @href CATISAXDeclHandler or @href CATISAXDTDHandler be properly ordered.</p>
		 *
		 * <p>Note that skipped entities will be reported through the
		 * @href CATISAXContentHandler#SkippedEntity
		 * event, which is part of the @href CATISAXContentHandler interface.</p>
		 *
		 * <p>Because of the streaming event model that SAX uses, some
		 * entity boundaries cannot be reported under any 
		 * circumstances:</p>
		 *
		 * <ul>
		 * <li>general entities within attribute values</li>
		 *
		 * <li>parameter entities within declarations</li>
		 * </ul>
		 *
		 * <p>These will be silently expanded, with no indication of where
		 * the original entity boundaries were.</p>
		 *
		 * <p>Note also that the boundaries of character references (which
		 * are not really entities anyway) are not reported.</p>
		 *
		 * <p>All @href #StartEntity / @href #EndEntity events must be properly nested.
		 *
		 * @param iName
		 * The name of the entity. If it is a parameter entity, the name will begin with <tt>'%'</tt>, and if it is the external DTD subset, it will be <tt>"[dtd]"</tt>.
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
		 *   </table>
		 * </dd>
		 *
		 * @see #EndEntity, CATISAXDeclHandler#InternalEntityDecl, CATISAXDeclHandler#ExternalEntityDecl
		 */
		virtual HRESULT StartEntity(
			const CATUnicodeString & iName) = 0;

};
CATDeclareHandler(CATISAXLexicalHandler, CATBaseUnknown);


#endif // CATISAXLexicalHandler_h
