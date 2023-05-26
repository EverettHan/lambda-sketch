// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIXMLDOMDocument_h
#define CATIXMLDOMDocument_h

// System framework
class CATUnicodeString;
#include "CATBoolean.h"

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"
class CATIDOMProcessingInstruction_var;
class CATIDOMElement_var;
class CATIDOMDocumentFragment_var;
class CATIDOMText_var;
class CATIDOMComment_var;
class CATIDOMCDATASection_var;
class CATIDOMEntityReference_var;
class CATIDOMNodeList_var;
class CATIDOMNode_var;
class CATIDOMDocumentType_var;
class CATIDOMImplementation_var;
class CATIDOMAttr_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMDocument;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMDocument ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to refer to XML Document nodes in the DOM.
 *
 * Conceptually, a DOM document node is the root of the document tree, and provides
 * the  primary access to the document's data.
 * <p>Since elements, text nodes, comments, processing instructions, etc.
 * cannot exist outside the context of a @href CATIDOMDocument, the
 * @href CATIDOMDocument interface also contains the factory methods needed
 * to create these objects.  The @href CATIDOMNode objects created have a
 * @href CATIDOMNode#GetOwnerDocument method which associates them with the
 * @href CATIDOMDocument within whose context they were created.
 */
class ExportedByCatXmlItfExt CATIDOMDocument: public CATIDOMNode {
	CATDeclareInterface;
	
	public:
	
		/**
		 * Retrieves the Document Type Declaration associated with this document.
		 *
		 * For documents without a document type declaration <tt>oDocumentType</tt> is
		 * set to <tt>NULL_var</tt>. The DOM Level
		 *  1 does not support editing the Document Type Declaration, therefore
		 * <tt>oDocumentType</tt> cannot be altered in any way.
		 *
		 * @param oDocumentType
		 * The retrieved Document Type Declaration associated with this document.
		 *
		 * @see CATIDOMDocumentType
		 */
		virtual HRESULT GetDocType(
			CATIDOMDocumentType_var& oDocumentType) = 0;
		
		/**
		 * Return the <tt>CATIDOMImplementation</tt> object that handles this document.
		 *
		 * @param oImplementation
		 * The retrieved @href CATIDOMImplementation object that handles this document.
		 *
		 * @see CATIDOMImplementation
		 */
		virtual HRESULT GetImplementation(
			CATIDOMImplementation_var& oImplementation) = 0;
		
		/**
		 * Retrieves a reference to the root element of the document.
		 *
		 * @param oDocumentElement
		 * The retrieved reference to the root element of the document.
		 *
		 * @see CATIDOMElement
		 */
		virtual HRESULT GetDocumentElement(
			CATIDOMElement_var& oDocumentElement) = 0;
		
		/**
		 * Creates an element of the type specified.
		 *
		 * Note that the instance returned implements the @href CATIDOMElement interface, 
		 * so attributes can be specified directly on the returned object.
		 *
		 * @param iTagName
		 * The name of the element type to instantiate.
		 * @param oElement
		 * A @href CATIDOMElement that references the new element.
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
		 *        <td class="errtd">XMLParserERR_2205</td>
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if the specified name contains an
		 *   invalid character.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMElement
		 */
		virtual HRESULT CreateElement(
			const CATUnicodeString& iTagName, 
			CATIDOMElement_var& oElement) = 0;
		
		/**
		 * Creates an empty <tt>CATIDOMDocumentFragment</tt> object.
		 *
		 * @param oDocumentFragment
		 * A @href CATIDOMDocumentFragment that references the newly
		 * created document fragment.
		 *
		 * @see CATIDOMDocumentFragment
		 */
		virtual HRESULT CreateDocumentFragment(
			CATIDOMDocumentFragment_var& oDocumentFragment) = 0;
		
		/**
		 * Creates a <tt>CATIDOMText</tt> node given the specified string.
		 *
		 * @param iData
		 * The data for the node.
		 * @param oTextNode
		 * A @href CATIDOMText object that references the newly
		 *  created text node.
		 *
		 * @see CATIDOMText
		 */
		virtual HRESULT CreateTextNode(
			const CATUnicodeString& iData, 
			CATIDOMText_var& oTextNode) = 0;
		
		/**
		 * Creates a <tt>CATIDOMComment</tt> node given the specified string.
		 *
		 * @param iData
		 * The data for the comment.
		 * @param oComment
		 * A @href CATIDOMComment that references the newly
		 *  created comment node.
		 *
		 * @see CATIDOMComment
		 */
		virtual HRESULT CreateComment(
			const CATUnicodeString& iData, 
			CATIDOMComment_var& oComment) = 0;
		
		/**
		 * Creates a <tt>CATIDOMCDATASection</tt> node whose value is the specified
		 * string.
		 *
		 * @param iData
		 * The data for the @href CATIDOMCDATASection contents.
		 * @param oCDDataSection
		 * A @href CATIDOMCDATASection object.
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
		 *        <td class="errtd">XMLParserERR_2209</td>
		 *        <td class="errtd">NOT_SUPPORTED_ERR: Raised if this document is an HTML document.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMCDATASection
		 */
		virtual HRESULT CreateCDATASection(
			const CATUnicodeString& iData, 
			CATIDOMCDATASection_var& oCDDataSection) = 0;

		/**
		 * Creates a <tt>CATIDOMProcessingInstruction</tt> node given the specified
		 * name and data strings.
		 *
		 * @param iTarget
		 * The target part of the processing instruction.
		 * @param iData
		 * The data for the node.
		 * @param oProcessingInstruction
		 * A @href CATIDOMProcessingInstruction that references the newly
		 *  created PI node.
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
		 *        <td class="errtd">XMLParserERR_2205</td>
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if an invalid character is specified.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMProcessingInstruction
		 */
		virtual HRESULT CreateProcessingInstruction(
			const CATUnicodeString& iTarget, 
			const CATUnicodeString& iData, 
			CATIDOMProcessingInstruction_var& oProcessingInstruction) = 0;
		
		/**
		 * Creates a <tt>CATIDOMAttr</tt> of the given name.
		 *
		 * Note that the @href CATIDOMAttr instance can then be attached to a @href CATIDOMElement
		 * using the @href CATIDOMElement#SetAttribute method.
		 *
		 * @param iName
		 * The name of the attribute.
		 * @param oAttribute
		 * A @href CATIDOMAttr that references the newly
		 *  created Attr.
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
		 *        <td class="errtd">XMLParserERR_2205</td>
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if the specified name contains an
		 *   invalid character.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMAttr
		 */
		virtual HRESULT CreateAttribute(
			const CATUnicodeString& iName, 
			CATIDOMAttr_var& oAttribute) = 0;
		
		/**
		 * Creates a <tt>CATIDOMEntityReference</tt> object.
		 *
		 * @param iName
		 * The name of the entity to reference.
		 * @param oEntityReference
		 * A @href CATIDOMEntityReference that references the newly
		 *  created EntityReference node.
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
		 *        <td class="errtd">XMLParserERR_2205</td>
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if the specified name contains an
		 *   invalid character.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMEntityReference
		 */
		virtual HRESULT CreateEntityReference(
			const CATUnicodeString& iName, 
			CATIDOMEntityReference_var& oEntityReference) = 0;
		
		/**
		 * Retrieves a <tt>CATIDOMNodeList</tt> of all the elements with a
		 * given tag name.
		 *
		 * The returned node list is "live", in that changes
		 * to the document tree made after a nodelist was initially
		 * returned will be immediately reflected in the node list.
		 *
		 * The elements in the node list are ordered in the same order in which they
		 * would be encountered in a
		 * preorder traversal of the @href CATIDOMDocument tree.
		 *
		 * @param iTagName
		 * The name of the tag to match on. The special value "*"
		 *   matches all tags.
		 * @param oNodeList
		 * A reference to a @href CATIDOMNodeList containing all the matched
		 *  instances of @href CATIDOMElement.
		 *
		 * @see CATIDOMNodeList
		 */
		virtual HRESULT GetElementsByTagName(
			const CATUnicodeString& iTagName,
			CATIDOMNodeList_var& oNodeList) = 0;
		
		/**
		 *  Imports a copy of a node from another document into this document.
		 *  The source node, which may belong to a different document, is
		 *  copied, with the copy belonging to this document.  The copy
		 *  is not placed into the document (the parent node is <tt>NULL_var</tt>).
		 *
		 * @param iNode
		 * The node to import.
		 * @param iDeep 
		 * If <tt>TRUE</tt>, recursively import the subtree under the specified
		 *  node; if <tt>FALSE</tt>, import only the node itself (and its attributes, if
		 *  if is a CATIDOMElement.
		 * @param oNode
		 * The newly created copy of the source node, belonging to this document
		 */
		virtual HRESULT ImportNode(
			const CATIDOMNode_var & iNode, 
			const CATBoolean & iDeep,
			CATIDOMNode_var& oNode) = 0;
		
		/**
		 * Creates an element of the given qualified name and namespace URI.
		 *
		 * @param iNamespaceURI 
		 * The namespace URI of the element to create. When it is an empty
		 *  @href CATUnicodeString, this method behaves like @href #CreateElement.
		 * @param iQualifiedName 
		 * The qualified name of the element type to instantiate.
		 * @param oElementNS
		 * A new @href CATIDOMElement object. The element has the
		 * following characteristics:
		 * <table border='1'>
		 * 
		 * <tr>
		 * <th>Attribute</th>
		 * <th>Value</th>
		 * </tr>
		 * <tr>
		 * <td> @href CATIDOMNode#GetNodeName </td>
		 * <td>
		 * 
		 * <tt>iQualifiedName</tt></td>
		 * </tr>
		 * <tr>
		 * <td> @href CATIDOMNode#GetNamespaceURI </td>
		 * <td>
		 * <tt>iNamespaceURI</tt></td>
		 * </tr>
		 * 
		 * <tr>
		 * <td> @href CATIDOMNode#GetPrefix </td>
		 * <td>prefix, extracted 
		 * from <tt>iQualifiedName</tt>, or an empty @href CATUnicodeString if there is 
		 * no prefix</td>
		 * </tr>
		 * <tr>
		 * 
		 * <td> @href CATIDOMNode#GetLocalName </td>
		 * <td>local name, extracted from 
		 * <tt>iQualifiedName</tt></td>
		 * </tr>
		 * <tr>
		 * <td> @href CATIDOMElement#GetTagName </td>
		 * <td>
		 * <tt>iQualifiedName</tt></td>
		 * 
		 * </tr>
		 * </table>
		 *
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
		 *        <td class="errtd">XMLParserERR_2205</td>
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if the specified name contains an
		 *   invalid character.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT CreateElementNS(
			const CATUnicodeString & iNamespaceURI, 
			const CATUnicodeString & iQualifiedName, 
			CATIDOMElement_var & oElementNS) = 0;
		
		
		/**
		 * Creates an attribute of the given qualified name and namespace URI.
		 *
		 * @param iNamespaceURI 
		 * The namespace URI of the attribute to create. When it is an empty
		 *   @href CATUnicodeString, this method behaves like @href #CreateAttribute.
		 * @param iQualifiedName 
		 * The qualified name
		 *   of the attribute type to instantiate.
		 * @param oAttribute
		 * A new @href CATIDOMAttr object. The attribute has the
		 * following characteristics:
		 *
		 * <table border='1'>
		 * 
		 * <tr>
		 * <th>
		 * Attribute</th>
		 * <th>Value</th>
		 * </tr>
		 * <tr>
		 * <td> @href CATIDOMNode#GetNodeName </td>
		 * 
		 * <td><tt>iQualifiedName</tt></td>
		 * </tr>
		 * <tr>
		 * <td> @href CATIDOMNode#GetNamespaceURI </td>
		 * <td><tt>iNamespaceURI</tt></td>
		 * </tr>
		 * 
		 * <tr>
		 * <td> @href CATIDOMNode#GetPrefix </td>
		 * <td>prefix, extracted from 
		 * <tt>iQualifiedName</tt>, or an empty @href CATUnicodeString if there is no 
		 * prefix</td>
		 * </tr>
		 * 
		 * <tr>
		 * <td> @href CATIDOMNode#GetLocalName </td>
		 * <td>local name, extracted from 
		 * <tt>iQualifiedName</tt></td>
		 * </tr>
		 * <tr>
		 * <td> @href CATIDOMAttr#GetName </td>
		 * <td>
		 * 
		 * <tt>iQualifiedName</tt></td>
		 * </tr>
		 * <tr>
		 * <td> @href CATIDOMNode#GetNodeValue </td>
		 * <td>the empty @href CATUnicodeString </td>
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
		 *        <td class="errtd">XMLParserERR_2205</td>
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if the specified name contains an
		 *   invalid character.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT CreateAttributeNS(
			const CATUnicodeString & iNamespaceURI, 
			const CATUnicodeString & iQualifiedName, 
			CATIDOMAttr_var & oAttribute) = 0;
		
		/**
		 * Retrieves a <tt>CATIDOMNodeList</tt> of all the <tt>CATIDOMElement</tt>s
		 * with a given local name and namespace URI.
		 *
		 * The elements are returned in the order in which they would be encountered in a
		 * preorder traversal of the @href CATIDOMDocument tree.
		 *
		 * @param iNamespaceURI 
		 * The namespace URI of
		 *   the elements to match on. The special value "*" matches all
		 *   namespaces. When it is an empty @href CATUnicodeString, this
		 *   method behaves like @href #GetElementsByTagName.
		 * @param iLocalName 
		 * The local name of the
		 *   elements to match on. The special value "*" matches all local names.
		 * @param  oNodeList
		 * A new @href CATIDOMNodeList object containing all the matched
		 * instances of @href CATIDOMElement.
		 */
		virtual HRESULT GetElementsByTagNameNS(
			const CATUnicodeString & iNamespaceURI,
			const CATUnicodeString & iLocalName, 
			CATIDOMNodeList_var & oNodeList) = 0;
		
		
		/**
		 * Retrieves the <tt>CATIDOMElement</tt> whose ID is given by <tt>iElementId</tt>.
		 * If no such element exists, returns <tt>NULL_var</tt>.
		 * Behavior is not defined if more than one element has this <tt>ID</tt>.
		 * @param iElementId 
		 * The unique <tt>id</tt> value for an element.
		 * @param oElement
		 * The matching element.
		 *
		 */
		virtual HRESULT GetElementById(
			const CATUnicodeString & iElementId, 
			CATIDOMElement_var & oElement) = 0;
};

CATDeclareHandler(CATIDOMDocument, CATIDOMNode);

#endif // CATIXMLDOMDocument_h
