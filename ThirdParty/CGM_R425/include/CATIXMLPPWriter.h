#ifndef CATIXMLPPWriter_h
#define CATIXMLPPWriter_h

// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// System framework
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

// XMLParser framework
#include "CatXmlItfBase.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLPPWriter;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLPPWriter ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to efficiently generate XML content.
 * The interface guarantees that the generated XML is well-formed.
 * It can keep track of namespaces. It supports pretty-printing.
 */
class ExportedByCatXmlItfBase CATIXMLPPWriter : public CATBaseUnknown {
	CATDeclareInterface;
	public:
		/**
		 * Writes the XML declaration.
		 * @param iStandalone
		 * TRUE if the XML document is standalone, FALSE otherwise
		 * @param iSkipDeclaration
		 * TRUE if the XML declaration should not be written, FALSE otherwise
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteStartDocument(
			CATBoolean iStandalone = FALSE,
			CATBoolean iSkipDeclaration = FALSE) = 0;

		/**
		 * Opens an element and pushes its namespace on the stack.
		 * @param iLocalName
		 * The element local name
		 * @param iURI
		 * The URI of the element's namespace
		 * @param iPrefix
		 * The namespace prefix for this element
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteStartElement(
			const CATUnicodeString& iLocalName,
			const CATUnicodeString& iURI = "",
			const CATUnicodeString& iPrefix = "") = 0;

		/**
		 * Adds an attribute to the currently open element.
		 * @param iLocalName
		 * The attribute local name
		 * @param iValue
		 * The attribute value
		 * @param iURI
		 * The URI of the attribute's namespace
		 * @param iPrefix
		 * The namespace prefix for this attribute
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteAttribute(
			const CATUnicodeString& iLocalName,
			const CATUnicodeString& iValue,
			const CATUnicodeString& iURI = "",
			const CATUnicodeString& iPrefix = "") = 0;

		/**
		 * Writes a processing instruction.
		 * @param iTarget
		 * The processing instruction target
		 * @param iData
		 * The processing instruction data
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteProcessingInstruction(
			const CATUnicodeString& iTarget,
			const CATUnicodeString& iData) = 0;

		/**
		 * Writes a comment.
		 * @param iComment
		 * the comment text
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteComment(
			const CATUnicodeString& iComment) = 0;

		/**
		 * Writes the document type declaration of the XML file.
		 * @param iName
		 * The name of the root element
		 * @param iPublicId
		 * If non empty, the external ID of the document type declaration will be of the form:
		 * <tt>PUBLIC iPublicId iSystemId</tt>
		 * @param iSystemId
		 * If non empty and iPublicId is empty, the external ID of the document type declaration will be of the form:
		 * <tt>SYSTEM iSystemId</tt>
		 * @param iInternalSubset
		 * The internal subset of the document type declaration
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteDocumentType(
			const CATUnicodeString& iName,
			const CATUnicodeString& iPublicId,
			const CATUnicodeString& iSystemId,
			const CATUnicodeString& iInternalSubset) = 0;

		/**
		 * Writes a CDATA section.
		 * @param iCharacters
		 * The contents of the CDATA section
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteCData(
			const CATUnicodeString& iCharacters) = 0;

		/**
		 * Writes XML text.
		 * @param iCharacters
		 * The XML text to write
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteCharacters(
			const CATUnicodeString& iCharacters) = 0;

		/**
		 * Writes an entity reference.
		 * @param iEntityName
		 * The name of the entity
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteEntityReference(
			const CATUnicodeString& iEntityName) = 0;


		/**
		 * Writes a character entity.
		 * @param iValue
		 * The character value
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteCharacterEntity(
			unsigned int iValue) = 0;

		/**
		 * Closes any open elements and flushes the output.
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteEndDocument() = 0;

		/**
		 * Closes one element and pops its namespace out of scope.
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteEndElement() = 0;

		/**
		 * Writes raw XML under the control of the caller.
		 * This method bypasses well-formedness tests and should be only in
		 * exceptional circumstances when the equivalent result cannot be
		 * obtained through other API calls.
		 * @param iXml
		 * the raw XML to write
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
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2400</td>
		 *        <td class="errtd">I/O error</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATXMLPPException </td>
		 *        <td class="errtd">XMLParserERR_2401</td>
		 *        <td class="errtd">Illegal state. The requested action cannot be performed
		 *                           or would result in a not-well-formed XML document</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT WriteRawXml(
			const CATUnicodeString& iXml) = 0;
};

CATDeclareHandler(CATIXMLPPWriter, CATBaseUnknown);

#endif // CATIXMLPPWriter_h
