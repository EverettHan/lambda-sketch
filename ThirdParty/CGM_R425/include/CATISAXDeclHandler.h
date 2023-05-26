// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATISAXDeclHandler_h
#define CATISAXDeclHandler_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXDeclHandler;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXDeclHandler ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to receive notification of DTD declaration events.
 *
 * <p>This is an optional extension handler for SAX2 to provide
 * information about DTD declarations in an XML document.  XML
 * readers are not required to support this handler, and this
 * handler is not included in the core SAX2 distribution.</p>
 * 
 * <p>Note that data-related DTD declarations (unparsed entities and
 * notations) are already reported through the @href CATISAXDTDHandler interface.</p>
 * 
 * <p>If you are using the declaration handler together with a lexical
 * handler, all of the events will occur between the
 * @href CATISAXLexicalHandler#StartDTD and the
 * @href CATISAXLexicalHandler#EndDTD events.</p>
 * 
 * <p>To set the CATISAXDeclHandler for an CATISAXXMLReader, use the
 * @href CATISAXXMLReader#SetProperty method
 * with the propertyId <tt>"http://xml.org/sax/properties/declaration-handler"</tt>.
 * If the reader does not support declaration events, it will return a
 * @href CATSAXNotRecognizedException error or a @href CATSAXNotSupportedException error
 * when you attempt to register the handler.</p>
 * 
 * @see CATISAXXMLReader, CATISAXLexicalHandler
 */
class ExportedByCatXmlItfBase CATISAXDeclHandler: public CATBaseUnknown {
	CATDeclareInterface;
	
	public:

		/**
		 * Receives notification of an element type declaration.
		 *
		 * <p>The content model will consist of the string <tt>"EMPTY"</tt>, the
		 * string <tt>"ANY"</tt>, or a parenthesised group, optionally followed
		 * by an occurrence indicator.  The model will be normalized so
		 * that all parameter entities are fully resolved and all whitespace 
		 * is removed, and will include the enclosing parentheses.  Other
		 * normalization (such as removing redundant parentheses or 
		 * simplifying occurrence indicators) is at the discretion of the
		 * parser.</p>
		 *
		 * @param iName
		 * The element type name.
		 * @param iModel
		 * The content model as a normalized string.
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
		 */
		virtual HRESULT ElementDecl(
			const CATUnicodeString & iName, 
			const CATUnicodeString & iModel) = 0;

		/**
		 * Receives notification of an attribute type declaration.
		 *
		 * <p>Only the effective (first) declaration for an attribute will
		 * be reported.  The type will be one of the strings <tt>"CDATA"</tt>,
		 * <tt>"ID"</tt>, "<tt>IDREF"</tt>, <tt>"IDREFS"</tt>, <tt>"NMTOKEN"</tt>, <tt>"NMTOKENS"</tt>, <tt>"ENTITY"</tt>,
		 * <tt>"ENTITIES"</tt>, a parenthesized token group with 
		 * the separator "|" and all whitespace removed, or the word
		 * <tt>"NOTATION"</tt> followed by a space followed by a parenthesized
		 * token group with all whitespace removed.</p>
		 * 
		 * <p>Any parameter entities in the attribute value will be
		 * expanded, but general entities will not.</p>
		 *
		 * @param iElementName
		 * The name of the associated element.
		 * @param iAttributeName
		 * The name of the attribute.
		 * @param iType
		 * A string representing the attribute type.
		 * @param iValueDefault
		 * A string representing the attribute default (<tt>"#IMPLIED"</tt>, <tt>"#REQUIRED"</tt>, or <tt>"#FIXED"</tt>) or an empty string if none of these applies.
		 * @param iValue
		 * A string representing the attribute's default value, or an empty string if there is none.
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
		 */
		virtual HRESULT AttributeDecl(
			const CATUnicodeString & iElementName, 
			const CATUnicodeString & iAttributeName,
			const CATUnicodeString & iType,
			const CATUnicodeString & iValueDefault,
			const CATUnicodeString & iValue) = 0;


		/**
		 * Receives notification of an internal entity declaration.
		 *
		 * <p>Only the effective (first) declaration for each entity
		 * will be reported.  All parameter entities in the value
		 * will be expanded, but general entities will not.</p>
		 *
		 * @param iName
		 * The name of the entity. If it is a parameter entity, the name will begin with <tt>'%'</tt>.
		 * @param iValue
		 * The replacement text of the entity.
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
		 */
		virtual HRESULT InternalEntityDecl(
			const CATUnicodeString & iName, 
			const CATUnicodeString & iValue) = 0;

		/**
		 * Receives notification of an external entity declaration.
		 *
		 * <p>Only the effective (first) declaration for each entity
		 *  will be reported.</p>
		 *
		 * @param iName
		 * The name of the entity. If it is a parameter entity, the name will begin with <tt>'%'</tt>.
		 * @param iPublicId
		 * The declared public identifier of the entity, or an empty string if none was declared.
		 * @param iSystemId
		 * The declared system identifier of the entity.
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
		 */
		virtual HRESULT ExternalEntityDecl(
			const CATUnicodeString & iName, 
			const CATUnicodeString & iPublicId,
			const CATUnicodeString & iSystemId) = 0;
		

};
CATDeclareHandler(CATISAXDeclHandler, CATBaseUnknown);


#endif // CATISAXDeclHandler_h
