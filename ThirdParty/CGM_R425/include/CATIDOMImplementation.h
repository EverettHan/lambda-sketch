// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMImplementation_h
#define CATIDOMImplementation_h

// System framework
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
class CATUnicodeString;

// XMLParser
#include "CatXmlItfExt.h"
class CATIDOMDocumentType_var;
class CATIDOMDocument_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMImplementation;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMImplementation ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface providing a number of methods 
 * for performing operations that are independent of any particular instance 
 * of the document object model.
 */
class ExportedByCatXmlItfExt CATIDOMImplementation : public CATBaseUnknown {
	CATDeclareInterface;

	public:

		/**
		 * Tests if the DOM implementation implements a specific feature.
		 *
		 * @param iFeature
		 * The name of the feature to test (case-insensitive). The 
		 *   values used by DOM features are defined throughout the DOM Level 2 
		 *   specifications and listed in the  section. The name must be an XML 
		 *   name. To avoid possible conflicts, as a convention, names referring 
		 *   to features defined outside the DOM specification should be made 
		 *   unique by reversing the name of the Internet domain name of the 
		 *   person (or the organization that the person belongs to) who defines 
		 *   the feature, component by component, and using this as a prefix. 
		 *   For instance, the W3C SVG Working Group defines the feature 
		 *   "org.w3c.dom.svg".
		 * @param iVersion
		 * The version number of the feature to test. In 
		 *   Level 2, the string can be either "2.0" or "1.0". If the version is 
		 *   not specified, supporting any version of the feature causes the 
		 *   method to return <code>TRUE</code>.
		 * @param oResult
		 * Set to <code>TRUE</code> if the feature is implemented in the 
		 *   specified version, to <code>FALSE</code> otherwise.
		 */
		virtual HRESULT HasFeature(
			const CATUnicodeString& iFeature,
			const CATUnicodeString & iVersion, 
			CATBoolean& oResult) = 0;

		/**
		 * Creates an empty <code>CATIDOMDocumentType</code> node.
		 * Entity declarations and notations are not made available. 
		 * Entity reference expansions and 
		 * default attribute additions do not occur. It is expected that a 
		 * future version of the DOM will provide a way for populating a 
		 * @href CATIDOMDocumentType.
		 * 
		 * @param iQualifiedName
		 * The qualified name of the document type to be created. 
		 * @param iPublicId
		 * The external subset public identifier.
		 * @param iSystemId
		 * The external subset system identifier.
		 * @param oDocumentType
		 * A new @href CATIDOMDocumentType node whose method 
		 * @href CATIDOMNode#GetOwnerDocument will return <code>NULL_var</code>.
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
		 *        <td class="errtd">XMLParserERR_2205</td>
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if the specified <tt>iQualifiedName</tt> 
		 *   contains an illegal character.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2214</td>
		 *        <td class="errtd">NAMESPACE_ERR: Raised if the <tt>iQualifiedName</tt> is malformed.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMDocumentType
		 */
		virtual HRESULT CreateDocumentType(
			const CATUnicodeString& iQualifiedName, 
			const CATUnicodeString& iPublicId, 
			const CATUnicodeString& iSystemId, 
			CATIDOMDocumentType_var& oDocumentType) = 0;

		/**
		 * Creates an XML <code>CATIDOMDocument</code> object of the specified type with 
		 * its document element.
		 * 
		 * @param iNamespaceURI
		 * The namespace URI of the document element to create.
		 * @param iQualifiedName
		 * The qualified name of the document element to be created.
		 * @param iDocumentType
		 * The type of document to be created or <code>NULL_var</code>.
		 *   When <code>iDocumentType</code> is not <code>NULL_var</code>, the result of
		 *   the method @href CATIDOMNode#GetOwnerDocument will be the document 
		 *   being created.
		 * @param oDocument
		 * A new @href CATIDOMDocument object.
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
		 *        <td class="errtd">XMLParserERR_2205</td>
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if the specified <tt>iQualifiedName</tt> 
		 *   contains an illegal character.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2214</td>
		 *        <td class="errtd">NAMESPACE_ERR: Raised if the <tt>iQualifiedName</tt> is malformed, 
		 *   if the <code>iQualifiedName</code> has a prefix and the 
		 *   <code>iNamespaceURI</code> is an empty string, or if the 
		 *   <code>iQualifiedName</code> has a prefix that is "xml" and the 
		 *   <code>iNamespaceURI</code> is different from "http://www.w3.org/XML/1998/namespace" .</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2204</td>
		 *        <td class="errtd">WRONG_DOCUMENT_ERR: Raised if <code>iDocumentType</code> has already 
		 *   been used with a different document or was created from a different 
		 *   implementation.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMDocumentType, CATIDOMDocument
		 */
		virtual HRESULT CreateDocument(
			const CATUnicodeString& iNamespaceURI, 
			const CATUnicodeString& iQualifiedName, 
			const CATIDOMDocumentType_var& iDocumentType, 
			CATIDOMDocument_var& oDocument) = 0;
	  	
};

CATDeclareHandler(CATIDOMImplementation, CATBaseUnknown);

#endif // CATIDOMImplementation_h

