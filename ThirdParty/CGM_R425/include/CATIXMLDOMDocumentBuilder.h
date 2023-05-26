// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIXMLDOMDocumentBuilder_h
#define CATIXMLDOMDocumentBuilder_h

// System framework
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATISAXEntityResolver.h"
#include "CATISAXErrorHandler.h"
class CATIDOMDocument_var;
class CATIDOMImplementation_var;
class CATISAXInputSource_var;
class CATIXMLDOMDocumentBuilder_var;
class CATIDOMNode_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIXMLDOMDocumentBuilder;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLDOMDocumentBuilder ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * CLSID of the XML4C 3.0 IBM DOM parser.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XML4C_DOM;

/**
 * CLSID of the XML4C 5.0 IBM DOM parser.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XML4C5_DOM;

/**
 * CLSID of the Xerces 3 DOM parser.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XMLXER3_DOM;

/**
 * CLSID of the MSXML 3.0 Microsoft DOM parser.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_MSXML3_DOM;

/**
 * CLSID of the MSXML 4.0 Microsoft DOM parser.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_MSXML4_DOM;

/**
 * CLSID of the MSXML 5.0 Microsoft DOM parser.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_MSXML5_DOM;

/**
 * CLSID of the MSXML 6.0 Microsoft DOM parser.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_MSXML6_DOM;

/**
 * CLSID of the MSXML Microsoft DOM parser (will look for the
 * highest installed version)
 */
extern ExportedByCatXmlItfExt CLSID CLSID_MSXML_DOM;

/**
 * CLSID of the default DOM parser.
 * On windows: will look for the highest version of MSXML,
 * and if not installed, will look for the highest version of XML4C
 * On unix: will look for the highest version of XML4C
 */
extern ExportedByCatXmlItfExt CLSID CLSID_DEFAULT_DOM;

/**
 * Interface to parse or to create DOM documents.
 */ 
class ExportedByCatXmlItfExt CATIXMLDOMDocumentBuilder: public CATBaseUnknown {
	CATDeclareInterface;

	public:
		/**
		 * Returns the list of options which can be used to customize
		 * the <tt>Parse</tt> methods.
		 *
		 * @param oOptions
		 * The list of options supported by the @href #Parse methods.
		 * The current list of options is
		 * <table border="1">
		 * <tr bgcolor="a4f4a4">
		 *  <td><b>Option name</b></td>
		 *  <td><b>Description</b></td>
		 *  <td><b>Possible values</b></td>
		 *  <td><b>Default value</b></td>
		 * </tr>
		 * <tr>
		 *  <td>CATDoValidation</td>
		 *  <td>Specifies if validation check is performed during parse</td>
		 *  <td>true or false</td>
		 *  <td>true</td>
		 * </tr>
		 * <tr>
		 *  <td>CATEnableNameSpaces</td>
		 *  <td>Specifies if the builder is XML namespace aware</td>
		 *  <td>true or false</td>
		 *  <td>true (NB: false is not supported by MSXML)</td>
		 * </tr>
		 * <tr>
		 *  <td>CATExpandEntityReferences</td>
		 *  <td>Specifies if the builder expands entity reference at parse time</td>
		 *  <td>true or false</td>
		 *  <td>false</td>
		 * </tr>
		 * </table>
		 */
		virtual HRESULT GetSupportedOptions(
			CATListOfCATUnicodeString& oOptions) = 0;

		/**
		 * Parses the supplied input source to generate a DOM document.
		 *
		 * @param iInputSource
		 * The @href CATISAXInputSource to parse
		 * @param oDocument
		 * The resulting @href CATIDOMDocument
		 * @param iOptions
		 * The names of the options to set
		 * @param iOptionValues
		 * The values of the options to set.
		 * @param iEntityResolver
		 * An optional @href CATISAXEntityResolver which can be used to resolve entities during parse.
		 * @param iErrorHandler
		 * An optional @href CATISAXErrorHandler which can be used to control the errors during parse.
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
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2100</td>
		 *        <td class="errtd">Invalid options definition</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2101</td>
		 *        <td class="errtd">Unsupported option</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2102</td>
		 *        <td class="errtd">Illegal option value</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">If an error (such as a not well formed XML document) occurs during parse</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2001</td>
		 *        <td class="errtd">If an I/O error occurs during parse</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 */
		virtual HRESULT Parse(
			const CATISAXInputSource_var& iInputSource,
			CATIDOMDocument_var& oDocument,
			const CATListOfCATUnicodeString& iOptions = CATListOfCATUnicodeString(),
			const CATListOfCATUnicodeString& iOptionValues = CATListOfCATUnicodeString(),
			const CATISAXEntityResolver_var& iEntityResolver = NULL_var,
			const CATISAXErrorHandler_var& iErrorHandler = NULL_var) = 0;

		/**
		 * Parses the supplied URI to generate a DOM document.
		 *
		 * @param iSystemId
		 * The URI of the entity to parse
		 * @param oDocument
		 * The resulting @href CATIDOMDocument
		 * @param iOptions
		 * The names of the options to set
		 * @param iOptionValues
		 * The values of the options to set.
		 * @param iEntityResolver
		 * An optional @href CATISAXEntityResolver which can be used to resolve entities during parse.
		 * @param iErrorHandler
		 * An optional @href CATISAXErrorHandler which can be used to control the errors during parse.
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
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2100</td>
		 *        <td class="errtd">Invalid options definition</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2101</td>
		 *        <td class="errtd">Unsupported option</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2102</td>
		 *        <td class="errtd">Illegal option value</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">If an error (such as a not well formed XML document) occurs during parse</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2001</td>
		 *        <td class="errtd">If an I/O error occurs during parse</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 */
		virtual HRESULT Parse(
			const CATUnicodeString & iSystemId,
			CATIDOMDocument_var& oDocument,
			const CATListOfCATUnicodeString& iOptions = CATListOfCATUnicodeString(),
			const CATListOfCATUnicodeString& iOptionValues = CATListOfCATUnicodeString(),
			const CATISAXEntityResolver_var& iEntityResolver = NULL_var,
			const CATISAXErrorHandler_var& iErrorHandler = NULL_var) = 0;


		/**
		 * Creates a new empty DOM document.
		 *
		 * @param oDocument
		 * The resulting @href CATIDOMDocument
		 */
		virtual HRESULT CreateDocument(
			CATIDOMDocument_var& oDocument) = 0;

		/**
		 * Retrieves the DOM implementation object for this implementation.
		 *
		 * @param oImplementation
		 * the DOM implementation object for this implementation
		 */
		virtual HRESULT GetDOMImplementation(
			CATIDOMImplementation_var& oImplementation) = 0;

		/**
		 * Writes the node in a <tt>CATUnicodeString</tt>.
		 * @param iNode
		 * the root of the DOM tree to write
		 * @param oResult
		 * the resulting @href CATUnicodeString
		 * @param iOptions
		 * The names of the options to set
		 * @param iOptionValues
		 * The values of the options to set.
		 * The current list of options is
		 * <table border="1">
		 * <tr bgcolor="a4f4a4">
		 *  <td><b>Option name</b></td>
		 *  <td><b>Description</b></td>
		 *  <td><b>Possible values</b></td>
		 *  <td><b>Default value</b></td>
		 * </tr>
		 * <tr>
		 *   <td>CATExpandEntityReferences</td>
		 *   <td>Specifies if the entities references are to be expanded in the generated XML text</td>
		 *   <td>true or false</td><td>false</td>
		 * </tr>
		 * <tr>
		 *  <td>CATEncoding</td>
		 *  <td>If the node is a document node, the supplied value will
		 *      be inserted in the 'encoding' attribute of the XML header
		 *      Do not specify this attribute if you want the XML parser
		 *      to autodetect the encoding.</td>
		 *  <td>encoding value</td><td>empty @href CATUnicodeString </td>
		 * </tr>
		 * <tr>
		 *  <td>CATSortAttributes</td>
		 *  <td>Sorts the attributes of each elements alphabetically.</td>
		 *  <td>true or false</td><td>false</td>
		 * </tr>
		 * <tr>
		 *  <td>CATIndentation</td>
		 *  <td>Controls how the output is formatted to produce human-readable indented XML.</td>
		 *  <td>A positive or null integer specifying the number of 
		 *      indentation characters to insert before each element</td>
		 *  <td>0 (no identation)</td>
		 * </tr>
		 * <tr>
		 *  <td>CATIndentationCharacter</td>
		 *  <td>Specifies the indentation character to use when indentation is requested.</td>
		 *  <td>A valid indentation character (space or tab)</td>
		 *  <td>space</td>
		 * </tr>
		 * </table>
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
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2100</td>
		 *        <td class="errtd">Invalid options definition</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2101</td>
		 *        <td class="errtd">Unsupported option</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2102</td>
		 *        <td class="errtd">Illegal option value</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 */
		virtual HRESULT Write(
			const CATIDOMNode_var& iNode,
			CATUnicodeString & oResult,
			const CATListOfCATUnicodeString& iOptions = CATListOfCATUnicodeString(),
			const CATListOfCATUnicodeString& iOptionValues = CATListOfCATUnicodeString()) = 0;
		
		/**
		 * Writes the node to the specified file.
		 * @param iNode
		 * the root of the DOM tree to write
		 * @param iPath
		 * the path of the file to write
		 * @param iOptions
		 * The names of the options to set
		 * @param iOptionValues
		 * The values of the options to set.
		 * The current list of options is
		 * <table border="1">
		 * <tr bgcolor="a4f4a4">
		 *  <td><b>Option name</b></td>
		 *  <td><b>Description</b></td>
		 *  <td><b>Possible values</b></td>
		 *  <td><b>Default value</b></td>
		 * </tr>
		 * <tr>
		 *   <td>CATExpandEntityReferences</td>
		 *   <td>Specifies if the entities references are to be expanded in the generated XML text</td>
		 *   <td>true or false</td><td>false</td>
		 * </tr>
		 * <tr>
		 *  <td>CATEncoding</td>
		 *  <td>The encoding to use to write the file. Furthermore
		 *      if the node is a document node, the supplied value will
		 *      be inserted in the 'encoding' attribute of the XML header.
		 *      Note that you should not normally use an empty @href CATUnicodeString value 
		 *      since it makes the XML file not portable
		 *      from one platform to another. However, if you want to edit the XML file with
		 *      an external, plain text editor which does not support UTF-8 and you do not
		 *      wish to exchange files, this value can exceptionally be used.
		 * </td>
		 *  <td>UTF-8, UTF-16 or empty @href CATUnicodeString </td>
		 *  <td>UTF-8</td>
		 * </tr>
		 * <tr>
		 *  <td>CATSortAttributes</td>
		 *  <td>Sorts the attributes of each elements alphabetically.</td>
		 *  <td>true or false</td><td>false</td>
		 * </tr>
		 * <tr>
		 *  <td>CATIndentation</td>
		 *  <td>Controls how the output is formatted to produce human-readable indented XML.</td>
		 *  <td>A positive or null integer specifying the number of 
		 *      indentation characters to insert before each element</td>
		 *  <td>0 (no identation)</td>
		 * </tr>
		 * <tr>
		 *  <td>CATIndentationCharacter</td>
		 *  <td>Specifies the indentation character to use when indentation is requested.</td>
		 *  <td>A valid indentation character (space or tab)</td>
		 *  <td>space</td>
		 * </tr>
		 * </table>
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
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2100</td>
		 *        <td class="errtd">Invalid options definition</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2101</td>
		 *        <td class="errtd">Unsupported option</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2102</td>
		 *        <td class="errtd">Illegal option value</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 */
		virtual HRESULT WriteToFile(
			const CATIDOMNode_var& iNode,
			const CATUnicodeString & iPath,
			const CATListOfCATUnicodeString& iOptions = CATListOfCATUnicodeString(),
			const CATListOfCATUnicodeString& iOptionValues = CATListOfCATUnicodeString()) = 0;
};

CATDeclareHandler(CATIXMLDOMDocumentBuilder, CATBaseUnknown);

/**
 * Returns the root object which corresponds to a specific DOM implementation.
 * This object is an instance of @href CATIXMLDOMDocumentBuilder.
 * @param oBuilder
 * The resulting <tt>CATIXMLDOMDocumentBuilder</tt>
 * @param iClsId
 * The CLSID of the <tt>CATIXMLDOMDocumentBuilder</tt> to instantiate.
 * <br><b>Legal values</b>:
 * <tt>CLSID_XML4C_DOM</tt> Use this value to instantiate the implementation based on XML4C 3.0 from IBM. 
 * This implementation supports DTD validation but not XML schema validation.
 * <tt>CLSID_XML4C5_DOM</tt> Use this value to instantiate the implementation based on XML4C 5.0 from IBM.
 * This implementation supports both DTD and XML schema validation.
 */
extern "C" ExportedByCatXmlItfExt HRESULT CreateCATIXMLDOMDocumentBuilder(
	CATIXMLDOMDocumentBuilder_var& oBuilder,
	const CLSID& iClsId = CLSID_XML4C_DOM);

/**
 * Examines the DOM implementations available on the host.
 * The function sequentially examines each of the supplied DOM implementation CLSIDs
 * until one is found, which is installed on the host.
 * @param iClsIdArray
 * An array of DOM implementation CLSIDs that the function should try to detect
 * @param iClsIdArraySize
 * The size of the CLSID array
 * @param oFirstAvailableIndex
 * The array index of the first DOM implementation which was succesfully detected on the machine
 */
extern "C" ExportedByCatXmlItfExt HRESULT DetectCATIXMLDOMDocumentBuilder(
	CLSID* iClsIdArray,
	unsigned int iClsIdArraySize,
	unsigned int& oFirstAvailableIndex);

#endif // CATIXMLDOMDocumentBuilder_h
