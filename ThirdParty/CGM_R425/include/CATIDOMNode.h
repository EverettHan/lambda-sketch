// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMNode_h
#define CATIDOMNode_h

// System framework
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
class CATIDOMNode_var;
class CATIDOMNodeList_var;
class CATIDOMNamedNodeMap_var;
class CATIDOMDocument_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMNode;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMNode ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface used as the primary datatype for the entire Document Object Model. 
 * It represents a single node in the document tree. 
 * While all objects implementing the @href CATIDOMNode interface expose 
 * methods for dealing with children, not all objects implementing the 
 * @href CATIDOMNode interface may have children. For example, 
 * @href CATIDOMText nodes may not have children, and adding children to 
 * such nodes results in a @href CATDOMException being raised.
 * <p>The methods @href #GetNodeName, @href #GetNodeValue and @href #GetAttributes 
 * are included as a mechanism to get at node 
 * information without casting down to the specific derived interface. In 
 * cases where there is no obvious mapping of these attributes for a 
 * specific @href #NodeType (e.g., @href #GetNodeValue for an 
 * @href CATIDOMElement or @href #GetAttributes for a @href CATIDOMComment ), 
 * this returns empty @href CATUnicodeString or <tt>NULL_var</tt> values. 
 * Note that the specialized interfaces 
 * may contain additional and more convenient mechanisms to get and set the 
 * relevant information.
 * <p>The return values of @href #GetNodeName, 
 * @href #GetNodeValue, and @href #GetAttributes methods vary according to the 
 * node type as follows: 
 * <br>
 * <table border='1'>
 * <tr>
 * <th>Interface</th>
 * <th>GetNodeName</th>
 * <th>GetNodeValue</th>
 * <th>GetAttributes</th>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMAttr </td>
 * <td valign='top' rowspan='1' colspan='1'>name of 
 * attribute</td>
 * <td valign='top' rowspan='1' colspan='1'>value of attribute</td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMCDATASection </td>
 * <td valign='top' rowspan='1' colspan='1'><code>"#cdata-section"</code></td>
 * <td valign='top' rowspan='1' colspan='1'>
 * content of the CDATA Section</td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMComment </td>
 * <td valign='top' rowspan='1' colspan='1'><code>"#comment"</code></td>
 * <td valign='top' rowspan='1' colspan='1'>content of 
 * the comment</td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMDocument </td>
 * <td valign='top' rowspan='1' colspan='1'><code>"#document"</code></td>
 * <td valign='top' rowspan='1' colspan='1'>empty @href CATUnicodeString </td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMDocumentFragment </td>
 * <td valign='top' rowspan='1' colspan='1'>
 * <code>"#document-fragment"</code></td>
 * <td valign='top' rowspan='1' colspan='1'>empty @href CATUnicodeString </td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMDocumentType </td>
 * <td valign='top' rowspan='1' colspan='1'>document type name</td>
 * <td valign='top' rowspan='1' colspan='1'>empty @href CATUnicodeString </td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMElement </td>
 * <td valign='top' rowspan='1' colspan='1'>tag name</td>
 * <td valign='top' rowspan='1' colspan='1'>empty @href CATUnicodeString </td>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMNamedNodeMap </td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMEntity </td>
 * <td valign='top' rowspan='1' colspan='1'>entity name</td>
 * <td valign='top' rowspan='1' colspan='1'>empty @href CATUnicodeString </td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMEntityReference </td>
 * <td valign='top' rowspan='1' colspan='1'>name of entity referenced</td>
 * <td valign='top' rowspan='1' colspan='1'>empty @href CATUnicodeString </td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMNotation </td>
 * <td valign='top' rowspan='1' colspan='1'>notation name</td>
 * <td valign='top' rowspan='1' colspan='1'>empty @href CATUnicodeString </td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMProcessingInstruction </td>
 * <td valign='top' rowspan='1' colspan='1'>target</td>
 * <td valign='top' rowspan='1' colspan='1'>entire content excluding the target</td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * <tr>
 * <td valign='top' rowspan='1' colspan='1'>@href CATIDOMText </td>
 * <td valign='top' rowspan='1' colspan='1'>
 * <code>"#text"</code></td>
 * <td valign='top' rowspan='1' colspan='1'>content of the text node</td>
 * <td valign='top' rowspan='1' colspan='1'>NULL_var</td>
 * </tr>
 * </table> 
 */
class ExportedByCatXmlItfExt CATIDOMNode: public CATBaseUnknown {
	CATDeclareInterface;
		
	public:
		
		/**
		 * Possible node types.
		 * @param ELEMENT_NODE
		 * The node is a @href CATIDOMElement.
		 * @param ATTRIBUTE_NODE
		 * The node is a @href CATIDOMAttr.
		 * @param TEXT_NODE
		 * The node is a @href CATIDOMText.
		 * @param CDATA_SECTION_NODE
		 * The node is a @href CATIDOMCDATASection.
		 * @param ENTITY_REFERENCE_NODE
		 * The node is a @href CATIDOMEntityReference.
		 * @param ENTITY_NODE
		 * The node is a @href CATIDOMEntity.
		 * @param PROCESSING_INSTRUCTION_NODE
		 * The node is a @href CATIDOMProcessingInstruction.
		 * @param COMMENT_NODE
		 * The node is a @href CATIDOMComment.
		 * @param DOCUMENT_NODE
		 * The node is a @href CATIDOMDocument.
		 * @param DOCUMENT_TYPE_NODE
		 * The node is a @href CATIDOMDocumentType.
		 * @param DOCUMENT_FRAGMENT_NODE
		 * The node is a @href CATIDOMDocumentFragment.
		 * @param NOTATION_NODE
		 * The node is a @href CATIDOMNotation.
		 */
		enum NodeType {
			ELEMENT_NODE				= 1,
			ATTRIBUTE_NODE				= 2,
			TEXT_NODE					= 3,
			CDATA_SECTION_NODE			= 4,
			ENTITY_REFERENCE_NODE		= 5,
			ENTITY_NODE					= 6,
			PROCESSING_INSTRUCTION_NODE = 7,
			COMMENT_NODE				= 8,
			DOCUMENT_NODE				= 9,
			DOCUMENT_TYPE_NODE			= 10,
			DOCUMENT_FRAGMENT_NODE		= 11,
			NOTATION_NODE				= 12
		};
		
		/**
		 * Retrieves the name of this node, depending on its type.
		 * @param oNodeName 
		 * The retrieved name of the node.
		 */
		virtual HRESULT GetNodeName(
			CATUnicodeString & oNodeName) = 0;
		
		/**
		 * Retrieves the value of this node, depending on its type.
		 *
		 * @param oNodeValue 
		 * The retrieved value of the node.
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
		 *        <td class="errtd">XMLParserERR_2202</td>
		 *        <td class="errtd">DOMSTRING_SIZE_ERR: Raised when it would return more characters than supported by the underlying implementation.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see #SetNodeValue
		 */
		virtual HRESULT GetNodeValue(
			CATUnicodeString & oNodeValue) = 0;
		
		/**
		 * Sets the value of the node.
		 *
		 * Any node which can have a nodeValue will
		 * also accept requests to set it to a string. The exact response to
		 * this varies from node to node -- Attribute, for example, stores
		 * its values in its children and has to replace them with a new Text
		 * holding the replacement value.
		 *
		 * For most types of Node, value is an empty @href CATUnicodeString and attempting to set it
		 * will raise a @href CATDOMException (NO_MODIFICATION_ALLOWED_ERR). This will
		 * also be thrown if the node is read-only.
		 *
		 * @param iNodeValue 
		 * The value to set for the node.
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
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised when the node is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2202</td>
		 *        <td class="errtd">DOMSTRING_SIZE_ERR: Raised when it would return more characters than supported by the underlying implementation.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see #GetNodeValue
		 */
		virtual HRESULT SetNodeValue(
			const CATUnicodeString & iNodeValue) = 0;
		
		/**
		 * Retrieves the enum value representing the type of the underlying object.
		 *
		 * @param oNodeType 
		 * The retrieved type of the node.
		 *
		 * @see #NodeType
		 */
		virtual HRESULT GetNodeType(
			NodeType & oNodeType) = 0;
		
		/**
		 * Retrieves the parent of this node.
		 *
		 * All nodes, except @href CATIDOMDocument, @href CATIDOMDocumentFragment, 
		 * and @href CATIDOMAttr may have a parent.
		 * However, if a node has just been created and not yet added to the tree,
		 * or if it has been removed from the tree, a <tt>NULL_var</tt> CATIDOMNode
		 * is returned.
		 *
		 * @param oParentNode 
		 * The retrieved parent of the node.
		 */
		virtual HRESULT GetParentNode(
			CATIDOMNode_var& oParentNode) = 0;
		
		/**
		 * Retrieves a <tt>CATIDOMNodeList</tt> that contains all children of this node.
		 *
		 * If there are no children, this is a <tt>CATIDOMNodeList</tt> containing no nodes.
		 * The content of the returned <tt>CATIDOMNodeList</tt> is "live" in the sense
		 * that, for instance, changes to the children of the node object that
		 * it was created from are immediately reflected in the nodes returned by
		 * the <tt>CATIDOMNodeList</tt> accessors; it is not a static snapshot of the
		 * content of the node. This is true for every <tt>CATIDOMNodeList</tt>,
		 * including the ones returned by the @href CATIDOMElement#GetElementsByTagName method.
		 *
		 * @param oParentNode 
		 * The retrieved list of children of the node.
		 *
		 * @see CATIDOMNodeList
		 */
		virtual HRESULT GetChildNodes(
			CATIDOMNodeList_var& oChildNodes) = 0;
		
		/**
		 * Retrieves the first child of this node. 
		 * If there is no such node, <tt>oFirstChild</tt> is set to <tt>NULL_var</tt>.
		 *
		 * @param oFirstChild 
		 * The retrieved first child of this node.
		 */
		virtual HRESULT GetFirstChild(
			CATIDOMNode_var& oFirstChild) = 0;
		
		/**
		 * Retrieves the last child of this node. 
		 * If there is no such node, <tt>oLastChild</tt> is set to <tt>NULL_var</tt>.
		 *
		 * @param oLastChild 
		 * The retrieved last child of this node.
		 */
		virtual HRESULT GetLastChild(
			CATIDOMNode_var& oLastChild) = 0;
		
		/**
		 * Retrieves node immediately preceding this node. 
		 * If there is no such node, <tt>oPreviousSibling</tt> is set to <tt>NULL_var</tt>.
		 *
		 * @param oPreviousSibling 
		 * The retrieved node immediately preceding this node.
		 */
		virtual HRESULT GetPreviousSibling(
			CATIDOMNode_var& oPreviousSibling) = 0;
		
		/**
		 * Retrieves node immediately following this node. 
		 * If there is no such node, <tt>oNextSibling</tt> is set to <tt>NULL_var</tt>.
		 *
		 * @param oNextSibling 
		 * The retrieved node immediately following this node.
		 */
		virtual HRESULT GetNextSibling(
			CATIDOMNode_var& oNextSibling) = 0;
		
		/**
		 * Retrieves a <tt>CATIDOMNamedNodeMap</tt> containing the attributes of this node.
		 * This method sets <tt>oAttributes</tt> to <tt>NULL_var</tt> if this node is not 
		 * an @href CATIDOMElement.
		 *
		 * @param oAttributes 
		 * The retrieved CATIDOMNamedNodeMap containing the attributes of this node.
		 *
		 * @see CATIDOMNamedNodeMap, CATIDOMElement
		 */
		virtual HRESULT GetAttributes(
			CATIDOMNamedNodeMap_var& oAttributes) = 0;
		
		/**
		 * Retrieves the <tt>CATIDOMDocument</tt> object associated with this node.
		 *
		 * This is also the <tt>CATIDOMDocument</tt> object used to create new nodes. 
		 * When this node is a <tt>CATIDOMDocument</tt> or a <tt>CATIDOMDocumentType</tt>,
		 * which is not used with any <tt>CATIDOMDocument</tt> yet, <tt>oOwnerDocument</tt> is
		 * set to <tt>NULL_var</tt>.
		 *
		 * @param oOwnerDocument 
		 * The retrieved <tt>CATIDOMDocument</tt> object associated with this node.
		 *
		 * @see CATIDOMDocument, CATIDOMDocumentType
		 */
		virtual HRESULT GetOwnerDocument(
			CATIDOMDocument_var& oOwnerDocument) = 0;
		
		/**
		 * Retrieves the namespace URI of this node, or an empty <tt>CATUnicodeString</tt> if it is 
		 * unspecified.
		 * <br>This is not a computed value that is the result of a namespace 
		 * lookup based on an examination of the namespace declarations in 
		 * scope. It is merely the namespace URI given at creation time.
		 * <br>For nodes of any type other than <tt>ELEMENT_NODE</tt> and 
		 * <tt>ATTRIBUTE_NODE</tt> and nodes created with a DOM Level 1 
		 * method, such as @href CATIDOMDocument#CreateElement method,
		 * this is always an empty @href CATUnicodeString.Per 
		 * the Namespaces in XML Specification  an attribute does not inherit 
		 * its namespace from the element it is attached to. If an attribute is 
		 * not explicitly given a namespace, it simply has no namespace.
		 *
		 * @param oNamespaceURI
		 * the namespace URI of this node, or an empty @href CATUnicodeString if it is 
		 * unspecified.
		 */
		virtual HRESULT GetNamespaceURI(
			CATUnicodeString & oNamespaceURI) = 0;
		
		/**
		 * Retrieves the namespace prefix
		 * of this node, or an empty <tt>CATUnicodeString</tt> if it is 
		 * unspecified. 
		 * When this node is of any type other than <tt>ELEMENT_NODE</tt> and
		 * <tt>ATTRIBUTE_NODE</tt> this is always an empty @href CATUnicodeString and
		 * setting it has no effect.
		 * <p>
		 * For nodes created with a DOM Level 1 method, such as the
		 * @href CATIDOMDocument#CreateElement method,
		 * this is an empty @href CATUnicodeString.
		 *
		 * @param oPrefix
		 * the namespace prefix of this node, or an empty @href CATUnicodeString if it is 
		 * unspecified.
		 */
		virtual HRESULT GetPrefix(
			CATUnicodeString & oPrefix) = 0;

		/**
		 * Sets the namespace prefix of this node.
		 * <br>Note that setting this attribute, when permitted, changes the 
		 * result of the @href CATIDOMNode#GetNodeName method, which returns the qualified name, as 
		 * well as the @href CATIDOMElement#GetTagName and @href CATIDOMAttr#GetName methods, when 
		 * applicable.
		 * <br>Note also that changing the prefix of an attribute that is known to 
		 * have a default value, does not make a new attribute with the default 
		 * value and the original prefix appear, since the result of 
		 * @href #GetNamespaceURI and @href #GetLocalName methods does not change.
		 * <br>For nodes of any type other than <tt>ELEMENT_NODE</tt> and 
		 * <tt>ATTRIBUTE_NODE</tt> and nodes created with a DOM Level 1 
		 * method, such as @href CATIDOMDocument#CreateElement method, this is always 
		 * an empty @href CATUnicodeString.
		 *
		 * @param iPrefix
		 * the namespace prefix of this node
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
		 *        <td class="errtd">INVALID_CHARACTER_ERR: Raised if the specified prefix contains an 
		 *   illegal character.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2214</td>
		 *        <td class="errtd">NAMESPACE_ERR: Raised if the specified <tt>iPrefix</tt> is 
		 *   malformed, if the @href #GetNamespaceURI of this node returns 
		 *   an empty @href CATUnicodeString, if the specified prefix is "xml" and the 
		 *   @href #GetNamespaceURI of this node is different from "
		 *   http://www.w3.org/XML/1998/namespace", if this node is an attribute 
		 *   and the specified prefix is "xmlns" and the 
		 *   @href #GetNamespaceURI of this node is different from "
		 *   http://www.w3.org/2000/xmlns/", or if this node is an attribute and 
		 *   the qualified name of this node is "xmlns"</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT SetPrefix(
			const CATUnicodeString & iPrefix) = 0;
		
		/**
		 * Retrieves the local part of the qualified name of this node.
		 * <br>For nodes of any type other than <tt>ELEMENT_NODE</tt> and 
		 * <tt>ATTRIBUTE_NODE</tt> and nodes created with a DOM Level 1 
		 * method, such as @href CATIDOMDocument#CreateElement method, this is always 
		 * an empty @href CATUnicodeString.
		 *
		 * @param oLocalName
		 * the local part of the qualified name of this node
		 */
		virtual HRESULT GetLocalName(
			CATUnicodeString & oLocalName) = 0;
		
		/**
		 * Inserts the node <tt>iNewChild</tt> before the existing child node
		 * <tt>iRefChild</tt>.
		 *
		 * If <tt>iRefChild</tt> equals <tt>NULL_var</tt>,
		 * inserts <tt>iNewChild</tt> at the end of the list of children.
		 * <br>If <tt>iNewChild</tt> is a @href CATIDOMDocumentFragment object,
		 * all of its children are inserted, in the same order, before
		 * <tt>iRefChild</tt>. If the <tt>iNewChild</tt> is already in the
		 * tree, it is first removed.
		 *
		 * @param iNewChild
		 * The node to insert.
		 * @param iRefChild
		 * The reference node, i.e., the node before which the new node must be inserted.
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
		 *        <td class="errtd">XMLParserERR_2203</td>
		 *        <td class="errtd">HIERARCHY_REQUEST_ERR: Raised if this node is of a type that does not
		 *   allow children of the type of the <tt>iNewChild</tt> node, or if
		 *   the node to insert is one of this node's ancestors.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2204</td>
		 *        <td class="errtd">WRONG_DOCUMENT_ERR: Raised if <tt>iNewChild</tt> was created
		 *   from a different document than the one that created this node.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2208</td>
		 *        <td class="errtd">NOT_FOUND_ERR: Raised if <tt>iRefChild</tt> is not a child of
		 *   this node.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMDocumentFragment
		 */
		virtual HRESULT InsertBefore(
			const CATIDOMNode_var& iNewChild, 
			const CATIDOMNode_var& iRefChild) = 0;
		
		/**
		 * Replaces the child node <tt>iOldChild</tt> with <tt>iNewChild</tt>
		 * in the list of children.
		 *
		 * If the <tt>iNewChild</tt> is already in the tree, it is first removed.
		 * @param iNewChild
		 * The new node to put in the child list.
		 * @param iOldChild
		 * The node being replaced in the list.
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
		 *        <td class="errtd">XMLParserERR_2203</td>
		 *        <td class="errtd">HIERARCHY_REQUEST_ERR: Raised if this node is of a type that does not
		 *   allow children of the type of the <tt>iNewChild</tt> node, or it
		 *   the node to put in is one of this node's ancestors.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2204</td>
		 *        <td class="errtd">WRONG_DOCUMENT_ERR: Raised if <tt>iNewChild</tt> was created
		 *   from a different document than the one that created this node.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2208</td>
		 *        <td class="errtd">NOT_FOUND_ERR: Raised if <tt>iRefChild</tt> is not a child of
		 *   this node.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 */
		virtual HRESULT ReplaceChild(
			const CATIDOMNode_var& iNewChild,
			const CATIDOMNode_var & iOldChild) = 0;
		
		/**
		 * Removes the child node indicated by <tt>iOldChild</tt> from the list 
		 * of children.
		 *
		 * @param oldChild
		 * The node being removed.
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
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2208</td>
		 *        <td class="errtd">NOT_FOUND_ERR: Raised if <tt>iRefChild</tt> is not a child of
		 *   this node.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT RemoveChild(
			const CATIDOMNode_var& iOldChild) = 0;
		
		/**
		 * Adds the node <tt>iNewChild</tt> to the end of the list of children 
		 * of this node.
		 *
		 * If the <tt>iNewChild</tt> is already in the tree, it is first removed.
		 * @param newChild
		 * The node to add.If it is a @href CATIDOMDocumentFragment object,
		 * the entire contents of the document fragment are moved 
		 * into the child list of this node
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
		 *        <td class="errtd">XMLParserERR_2203</td>
		 *        <td class="errtd">HIERARCHY_REQUEST_ERR: Raised if this node is of a type that does not 
		 *   allow children of the type of the <tt>iNewChild</tt> node, or if 
		 *   the node to append is one of this node's ancestors.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2204</td>
		 *        <td class="errtd">WRONG_DOCUMENT_ERR: Raised if <tt>iNewChild</tt> was created 
		 *   from a different document than the one that created this node.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMDocumentFragment
		 */
		virtual HRESULT AppendChild(
			const CATIDOMNode_var& iNewChild) = 0;
		
		/**
		 * Returns whether this node has any children.
		 * Returns <tt>TRUE</tt> if this node has any children, 
		 * <tt>FALSE</tt> otherwise.
		 * @param oHasChildren
		 * The retrieve boolean specifying whether this node has any children.
		 */
		virtual HRESULT HasChildNodes(
			CATBoolean& oHasChildren) = 0;
		
		/**
		 * Returns a duplicate of this node.
		 *
		 * This function serves as a generic copy constructor for nodes.
		 * The duplicate node has no parent (@href #GetParentNode returns <tt>NULL_var</tt>.).
		 * <br>Cloning a @href CATIDOMElement copies all attributes and their
		 * values, including those generated by the XML processor to represent
		 * defaulted attributes, but this method does not copy any text it contains
		 * unless it is a deep clone, since the text is contained in a child
		 * @href CATIDOMText node. Cloning any other type of node simply returns a
		 * copy of this node.
		 *
		 * @param iDeep
		 * If <tt>TRUE</tt>, recursively clones the subtree under the
		 *   specified node; if <tt>FALSE</tt>, clones only the node itself (and
		 *   its attributes, if it is an <tt>CATIDOMElement</tt>).
		 * @param oNewNode
		 * The duplicate node.
		 *
		 * @see CATIDOMElement, CATIDOMText
		 */
		virtual HRESULT CloneNode(
			CATBoolean iDeep, 
			CATIDOMNode_var& oNewNode) = 0 ;
		
		/**
		 * Puts all <tt>CATIDOMText</tt> nodes in the full depth of the sub-tree 
		 * underneath this <tt>CATIDOMNode</tt>, including attribute nodes, into a 
		 * "normal" form.
		 * In the normal form, only structure (e.g., elements, comments, 
		 * processing instructions, CDATA sections, and entity references) 
		 * separates <tt>CATIDOMText</tt> nodes, i.e., there are neither adjacent 
		 * <tt>CATIDOMText</tt> nodes nor empty <tt>CATIDOMText</tt> nodes.
		 * This can be used to ensure that the DOM view of a document is the same as if 
		 * it were saved and re-loaded, and is useful when operations (such as 
		 * XPointer lookups) that depend on a particular document tree 
		 * structure are to be used.
		 *
		 * @see CATIDOMText
		 */
		virtual HRESULT Normalize() = 0;
		
		/**
		 * Tests whether the DOM implementation implements a specific feature and 
		 * that feature is supported by this node.
		 *
		 * @param iFeature 
		 * name of the feature to test. This is the same name 
		 * which can be passed to the method @href CATIDOMImplementation#HasFeature.
		 * @param iVersion 
		 * The version number of the feature to test. In Level 2, version 1, 
		 * this is the string "2.0". If the version is not 
		 * specified, supporting any version of the feature will cause the 
		 * method to return <tt>TRUE</tt>.
		 * @param oResult
		 * <tt>TRUE</tt> if the specified feature is 
		 *   supported on this node, <tt>FALSE</tt> otherwise.
		 */
		virtual HRESULT IsSupported(
			const  CATUnicodeString & iFeature,
			const  CATUnicodeString & iVersion, 
			CATBoolean & oResult) = 0;
		
		/**
		 * Returns whether this node (if it is an element) has any attributes.
		 *
		 * @param oResult 
		 * <tt>TRUE</tt> if this node has any attributes, <tt>FALSE</tt> otherwise.
		 */
		virtual HRESULT HasAttributes(
			CATBoolean & oResult) = 0;	
};

CATDeclareHandler(CATIDOMNode, CATBaseUnknown);

#endif // CATIDOMNode_h
