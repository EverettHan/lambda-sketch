// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIXMLDOMElement_h
#define CATIXMLDOMElement_h

// System framework
#include "CATBoolean.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"
class CATIDOMAttr_var;
class CATIDOMNodeList_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMElement;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMElement ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface representing by far the vast majority of objects nodes (apart from text) that authors 
 * encounter when traversing a document.
 *
 * Assume the following XML document:
 * <br>
 * <br>&lt;elementExample id="demo"&gt; 
 * <br>&lt;subelement1/&gt; 
 * <br>&lt;subelement2&gt;&lt;subsubelement/&gt;&lt;/subelement2&gt;
 * <br>&lt;/elementExample&gt;
 *
 * <p>When represented using DOM, the top node is a <tt>CATIDOMElement</tt> node 
 * for "elementExample", which contains two child <tt>CATIDOMElement</tt> nodes, 
 * one for "subelement1" and one for "subelement2". "subelement1" contains no 
 * child nodes.
 * <p>Elements may have attributes associated with them; since the 
 * <tt>CATIDOMElement</tt> interface inherits from @href CATIDOMNode, the generic
 * @href CATIDOMNode interface method @href CATIDOMNode#GetAttributes may be used 
 * to retrieve the set of all attributes for an element.
 * <br>There are methods on the <tt>CATIDOMElement</tt> interface to retrieve 
 * either a @href CATIDOMAttr object by name or an attribute value by name. 
 * In XML, where an attribute value may contain entity references, 
 * a @href CATIDOMAttr object should be 
 * retrieved to examine the possibly fairly complex sub-tree representing the 
 * attribute value. On the other hand, in HTML, where all attributes have 
 * simple string values, methods to directly access an attribute value can 
 * safely be used as a convenience.
 */
class ExportedByCatXmlItfExt CATIDOMElement: public CATIDOMNode {
	CATDeclareInterface;
	
	public:
		
		/**
		 * Retrieves the name of the element.
		 *
		 * For example, in:
		 * <br>&lt;elementExample 
		 * id="demo"&gt;  ... &lt;/elementExample&gt; , 
		 * <br><tt>tagName</tt> has 
		 * the value <tt>"elementExample"</tt>. Note that this is 
		 * case-preserving in XML, as are all of the operations of the DOM.
		 *
		 * @param oTagName
		 * The retrieved name of the element.
		 */
		virtual HRESULT GetTagName(
			CATUnicodeString& oTagName) = 0;
		
		/**
		 * Retrieves an attribute value by name.
		 *
		 * @param iName
		 * The name of the attribute to retrieve.
		 * @param oValue
		 * The @href CATIDOMAttr value as a string, or the empty string if 
		 *   that attribute does not have a specified or default value.
		 */
		virtual HRESULT GetAttribute(
			const CATUnicodeString& iName, 
			CATUnicodeString& oValue) = 0;
		
		/**
		 * Adds a new attribute. 
		 * 
		 * If an attribute with that name is already present 
		 * in the element, its value is changed to be that of the value parameter. 
		 * This value is a simple string, it is not parsed as it is being set. So 
		 * any markup (such as syntax to be recognized as an entity reference) is 
		 * treated as literal text, and needs to be appropriately escaped by the 
		 * implementation when it is written out. In order to assign an attribute 
		 * value that contains entity references, the user must create an 
		 * @href CATIDOMAttr node plus any @href CATIDOMText and 
		 * @href CATIDOMEntityReference nodes, build the appropriate subtree, and 
		 * use @href #SetAttributeNode to assign it as the value of an 
		 * attribute.
		 *
		 * @param iAttributeName
		 * The name of the attribute to create or alter.
		 * @param iAttributeValue
		 * Value to set in string form.
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
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMAttr, CATIDOMText
		 */
		virtual HRESULT SetAttribute(
			const CATUnicodeString& iAttributeName, 
			const CATUnicodeString& iAttributeValue) = 0;
		
		/**
		 * Removes an attribute by name. 
		 *
		 * If the removed attribute has a default 
		 * value it is immediately replaced.
		 *
		 * @param iAttributeName
		 * The name of the attribute to remove.
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
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT RemoveAttribute(
			const CATUnicodeString& iAttributeName) = 0;
		
		/**
		 * Retrieves a <tt>CATIDOMAttr</tt> node by name.
		 *
		 * @param iAttributeName
		 * The name of the attribute to retrieve.
		 * @param oAttributeNode
		 * The retrieved @href CATIDOMAttr node with the specified attribute name or 
		 *   <tt>NULL_var</tt> if there is no such attribute.
		 *
		 * @see CATIDOMAttr
		 */
		virtual HRESULT GetAttributeNode(
			const CATUnicodeString& iAttributeName, 
			CATIDOMAttr_var& oAttributeNode) = 0;
		
		/**
		 * Adds a new attribute. 
		 * 
		 * If an attribute with that name is already present 
		 * in the element, it is replaced by the new one.
		 *
		 * @param iAttributeNode
		 * The @href CATIDOMAttr node to add to the attribute list.
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
		 *        <td class="errtd">XMLParserERR_2204</td>
		 *        <td class="errtd">WRONG_DOCUMENT_ERR: Raised if <tt>iAttributeNode</tt> was created from a 
		 *   different document than the one that created the element.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2210</td>
		 *        <td class="errtd">INUSE_ATTRIBUTE_ERR: Raised if <tt>iAttributeNode</tt> is already an 
		 *   attribute of another @href CATIDOMElement object. The DOM user must 
		 *   explicitly clone @href CATIDOMAttr nodes to re-use them in other 
		 *   elements.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMAttr
		 */
		virtual HRESULT SetAttributeNode(
			const CATIDOMAttr_var& iAttributeNode) = 0;
		
		/**
		 * Removes the specified attribute.
		 *
		 * @param iAttributeNodeToRemove
		 * The @href CATIDOMAttr node to remove from the attribute 
		 *   list. If the removed @href CATIDOMAttr has a default value it is 
		 *   immediately replaced.
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
		 *        <td class="errtd">NOT_FOUND_ERR: Raised if <tt>iAttributeNodeToRemove</tt> is not an attribute 
		 *   of the element.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMAttr
		 */
		virtual HRESULT RemoveAttributeNode(
			const CATIDOMAttr_var& iAttributeNodeToRemove) = 0;
		
		/**
		 * Returns a <tt>CATIDOMNodeList</tt> of all descendant elements with a given tag name.
		 * The elements are returned in the order in which they would be encountered in a preorder 
		 * traversal of the <tt>CATIDOMElement</tt> tree.
		 *
		 * @param iElementsName
		 * The name of the tag to match on. The special value "*" matches all tags.
		 * @param oListOfElements
		 * A list of matching @href CATIDOMElement nodes.
		 *
		 * @see CATIDOMNodeList
		 */
		virtual HRESULT GetElementsByTagName(
			const CATUnicodeString& iElementsName, 
			CATIDOMNodeList_var& oListOfElements) = 0;
		
		/**
		 * Retrieves an attribute value by local name and namespace URI.
		 *
		 * @param iNamespaceURI
		 * The namespace URI of
		 *   the attribute to retrieve. When it is an empty
		 *   @href CATUnicodeString, this method behaves like @href #GetAttribute.
		 * @param iLocalName
		 * The local name of the
		 *    attribute to retrieve.
		 * @param oValue
		 * The @href CATIDOMAttr value as a string, or an empty string if
		 *    that attribute does not have a specified or default value.
		 */
		virtual HRESULT GetAttributeNS(
			const CATUnicodeString & iNamespaceURI, 
			const CATUnicodeString & iLocalName, 
			CATUnicodeString & oValue) = 0;
		
		/**
		 * Adds a new attribute. If an attribute with the same local name and
		 * namespace URI is already present in the element, its prefix is changed
		 * to be that of the <tt>qualifiedName</tt> parameter,
		 * and its value is changed to be that of the <tt>value</tt> parameter.
		 * This value is a simple string, it is
		 * not parsed as it is being set. So any markup (such as syntax to be
		 * recognized as an entity reference) is treated as literal text, and
		 * needs to be appropriately escaped by the implementation when it is
		 * written out. In order to assign an attribute value that contains entity
		 * references, the user must create a @href CATIDOMAttr node plus any
		 * @href CATIDOMText and @href CATIDOMEntityReference nodes, build the
		 * appropriate subtree, and use @href #SetAttributeNodeNS or
		 * @href #SetAttributeNode to assign it as the value of an
		 * attribute.
		 *
		 * @param iNamespaceURI 
		 * The namespace URI of
		 *    the attribute to create or alter. When it is an empty
		 *    @href CATUnicodeString, this method behaves like @href #SetAttribute.
		 * @param iQualifiedName 
		 * The qualified name of the attribute to create or alter.
		 * @param iValue 
		 * The value to set in string form.
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
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT SetAttributeNS(
			const CATUnicodeString & iNamespaceURI, 
			const CATUnicodeString & iQualifiedName, 
			const CATUnicodeString & iValue) = 0;
		
		/**
		 * Removes an attribute by local name and namespace URI. If the
		 * removed attribute has a default value it is immediately replaced.
		 *
		 * @param iNamespaceURI 
		 * The namespace URI of
		 *    the attribute to remove. When it is an empty
		 *    @href CATUnicodeString, this method behaves like @href #RemoveAttribute.
		 * @param iLocalName 
		 * The local name of the
		 *    attribute to remove.
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
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT RemoveAttributeNS(
			const CATUnicodeString & iNamespaceURI, 
			const CATUnicodeString & iLocalName) = 0;
		
		/**
		 * Retrieves a <tt>CATIDOMAttr</tt> node by local name and namespace URI.
		 *
		 * @param iNamespaceURI
		 * The namespace URI of
		 *    the attribute to retrieve. When it is or an empty
		 *    @href CATUnicodeString, this method behaves like @href #GetAttributeNode.
		 * @param iLocalName
		 * The local name of the
		 *    attribute to retrieve.
		 * @param oAttribute
		 * The @href CATIDOMAttr node with the specified attribute local
		 *    name and namespace URI or <tt>NULL_var</tt> if there is no such attribute.
		 */
		virtual HRESULT GetAttributeNodeNS(
			const CATUnicodeString & iNamespaceURI, 
			const CATUnicodeString & iLocalName, 
			CATIDOMAttr_var & oAttribute) = 0;
		
		/**
		 * Adds a new attribute. 
		 * 
		 * If an attribute with that local name and namespace URI is already present 
		 * in the element, it is replaced by the new one.
		 *
		 * @param iNewAttribute
		 * The @href CATIDOMAttr node to add to the attribute list.
		 *    When the node has no <tt>namespaceURI</tt>, this method behaves like
		 *    @href #SetAttributeNode.
		 * @param oPreviousAttr
		 * If the <tt>newAttr</tt> attribute replaces an existing
		 *    attribute with the same local name and namespace URI,
		 *    the previously existing @href CATIDOMAttr node is
		 *    returned, otherwise <tt>NULL_var</tt> is returned.
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
		 *        <td class="errtd">XMLParserERR_2204</td>
		 *        <td class="errtd">WRONG_DOCUMENT_ERR: Raised if <tt>iNewAttribute</tt> was created from a 
		 *   different document than the one that created the element.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2210</td>
		 *        <td class="errtd">INUSE_ATTRIBUTE_ERR: Raised if <tt>iNewAttribute</tt> is already an 
		 *   attribute of another @href CATIDOMElement object. The DOM user must 
		 *   explicitly clone @href CATIDOMAttr nodes to re-use them in other 
		 *   elements.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT SetAttributeNodeNS(
			const CATIDOMAttr_var & iNewAttribute,
			CATIDOMAttr_var& oPreviousAttr) = 0;

		/**
		 * Returns a <tt>CATIDOMNodeList</tt> of all the <tt>CATIDOMElement</tt>s
		 * with a given local name and namespace URI in the order in which they
		 * would be encountered in a preorder traversal of the
		 * <tt>CATIDOMDocument</tt> tree, starting from this node.
		 *
		 * @param iNamespaceURI 
		 * The namespace URI of
		 *    the elements to match on. The special value "*" matches all
		 *    namespaces. When it is an empty @href CATUnicodeString, this
		 *    method behaves like @href #GetElementsByTagName .
		 * @param iLocalName 
		 * The local name of the
		 *    elements to match on. The special value "*" matches all local names.
		 * @param oElementList
		 * A new @href CATIDOMNodeList object containing all the matched
		 *   instances of @href CATIDOMElement.
		 */
		virtual HRESULT GetElementsByTagNameNS(
			const CATUnicodeString & iNamespaceURI, 
			const CATUnicodeString & iLocalName, 
			CATIDOMNodeList_var & oElementList ) = 0;
		
		/**
		 * Returns <tt>TRUE</tt> when an attribute with a given name is 
		 * specified on this element or has a default value, <tt>FALSE</tt> 
		 * otherwise.
		 *
		 * @param iName
		 * The name of the attribute to look for.
		 * @param oResult
		 * <tt>TRUE</tt> if an attribute with the given name is 
		 *   specified on this element or has a default value, <tt>FALSE</tt>
		 *    otherwise.
		 */
		virtual HRESULT HasAttribute(
			const CATUnicodeString & iName,
			CATBoolean & oResult) = 0; 
		
		/**
		 * Returns <tt>TRUE</tt> when an attribute with a given local name and 
		 * namespace URI is specified on this element or has a default value, 
		 * <tt>FALSE</tt> otherwise. HTML-only DOM implementations do not 
		 * need to implement this method.
		 *
		 * @param iNamespaceURI
		 * The namespace URI of the attribute to look for.
		 * @param iLocalName
		 * The local name of the attribute to look for.
		 * @param oResult
		 * <tt>TRUE</tt> if an attribute with the given local name 
		 *   and namespace URI is specified or has a default value on this 
		 *   element, <tt>FALSE</tt> otherwise.
		 */
		virtual HRESULT HasAttributeNS(
			const CATUnicodeString & iNamespaceURI,
			const CATUnicodeString & iLocalName,
			CATBoolean & oResult) = 0; 

};

CATDeclareHandler(CATIDOMElement, CATIDOMNode);

#endif // CATIXMLDOMElement_h
