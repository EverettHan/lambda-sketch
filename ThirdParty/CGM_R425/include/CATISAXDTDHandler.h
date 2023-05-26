// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATISAXDTDHandler_h
#define CATISAXDTDHandler_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXDTDHandler;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXDTDHandler ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to receive notification of basic DTD-related events.
 *
 * <p>If a SAX application needs information about notations and
 * unparsed entities, then the application implements this 
 * interface and registers an instance with the SAX parser using 
 * the parser's @href CATISAXXMLReader#SetDTDHandler method.  The parser uses the 
 * instance to report notation and unparsed entity declarations to 
 * the application.</p>
 *
 * <p>The SAX parser may report these events in any order, regardless
 * of the order in which the notations and unparsed entities were
 * declared; however, all DTD events must be reported after the
 * document handler's @href CATISAXContentHandler#StartDocument event, and before the first
 * @href CATISAXContentHandler#StartElement event.</p>
 *
 * <p>It is up to the application to store the information for 
 * future use (perhaps in a hash table or object tree).
 * If the application encounters attributes of type "NOTATION",
 * "ENTITY", or "ENTITIES", it can use the information that it
 * obtained through this interface to find the entity and/or
 * notation corresponding with the attribute value.</p>
 *
 * <p>The @href CATSAXDefaultHandler class provides a default implementation
 * of this interface, which simply ignores the events.</p>
 *
 * @see CATISAXXMLReader#SetDTDHandler, CATSAXDefaultHandler
 */
class ExportedByCatXmlItfBase CATISAXDTDHandler: public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		
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
			const CATUnicodeString & iSystemId) = 0;
		
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
			const CATUnicodeString & iNotationName) = 0;
	
	
};
CATDeclareHandler(CATISAXDTDHandler, CATBaseUnknown);


#endif // CATISAXDTDHandler_h
