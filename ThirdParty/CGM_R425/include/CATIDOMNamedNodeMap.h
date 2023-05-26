// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMNamedNodeMap_h
#define CATIDOMNamedNodeMap_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
class CATIDOMNode_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMNamedNodeMap;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMNamedNodeMap ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface used to represent collections of nodes that can be accessed by name.
 * Note that @href CATIDOMNamedNodeMap does not inherit from @href CATIDOMNodeList ; 
 * <code>CATIDOMNamedNodeMap</code>s are not maintained in any particular order. 
 * Objects contained in an object implementing @href CATIDOMNamedNodeMap may 
 * also be accessed by an ordinal index, but this is simply to allow 
 * convenient enumeration of the contents of a @href CATIDOMNamedNodeMap, 
 * and does not imply that the DOM specifies an order to these Nodes. 
 * <p>@href CATIDOMNamedNodeMap objects in the DOM are live.
 */
class ExportedByCatXmlItfExt CATIDOMNamedNodeMap : public CATBaseUnknown {
	CATDeclareInterface;

	public:

		/**
		 * Retrieves the number of nodes in this map.
		 * The range of valid child node indices 
		 * is <code>0</code> to <code>oLength - 1</code> inclusive. 
		 *
		 * @param oLength
		 * The retrieved number of nodes in this map.
		 */
		virtual HRESULT GetLength(
			int& oLength) = 0;
		
		/**
		 * Retrieves a node specified by name.
		 *
		 * @param iName
		 * The name of a node to retrieve.
		 * @param oNamedItem
		 * A @href CATIDOMNode (of any type) with the specified 
		 *   name, or <code>NULL_var</code> if it does not identify 
		 *   any node in this map.
		 *
		 * @see CATIDOMNode, CATIDOMNode#GetNodeName
		 */
		virtual HRESULT GetNamedItem(
			const CATUnicodeString& iName, 
			CATIDOMNode_var& oNamedItem) = 0;
		
		/**
		 * Adds a node using its <code>nodeName</code> attribute.
		 * If a node with that name is already present in this map, 
		 * it is replaced by the new one.
		 * <br>As the <code>nodeName</code> attribute is used to derive the name 
		 * which the node must be stored under, multiple nodes of certain types 
		 * (those that have a "special" string value) cannot be stored as the 
		 * names would clash. This is seen as preferable to allowing nodes to be 
		 * aliased.
		 *
		 * @param iNodeToStore
		 * The node to store in this map. The node will later be 
		 *   accessible using the return value of its @href CATIDOMNode#GetNodeName method.
		 * @param oOldNode
		 * If the new @href CATIDOMNode replaces an existing node, oOldNode is set to the 
		 *   replaced @href CATIDOMNode, otherwise it is set to <code>NULL_var</code>.
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
		 *        <td class="errtd">WRONG_DOCUMENT_ERR: Raised if <code>iNodeToStore</code> was created from a 
		 *   different document than the one that created this map.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this map is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2210</td>
		 *        <td class="errtd">INUSE_ATTRIBUTE_ERR: Raised if <code>iNodeToStore</code> is an 
		 *   @href CATIDOMAttr that is already an attribute of another 
		 *   @href CATIDOMElement object. The DOM user must explicitly clone 
		 *   @href CATIDOMAttr nodes to re-use them in other elements.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMNode
		 */
		virtual HRESULT SetNamedItem(
			const CATIDOMNode_var& iNodeToStore,
			CATIDOMNode_var& oOldNode) = 0;
		
		/**
		 * Removes a node specified by name. 
		 * When this map contains the attributes 
		 * attached to an element, if the removed attribute is known to have a 
		 * default value, an attribute immediately appears containing the 
		 * default value as well as the corresponding namespace URI, local name, 
		 * and prefix when applicable.
		 *
		 * @param iName
		 * The name of the node to remove.
		 * @param oNamedItem
		 * The node removed from this map if a node with such a name exists.
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
		 *        <td class="errtd">XMLParserERR_2208</td>
		 *        <td class="errtd">NOT_FOUND_ERR: Raised if there is no node named <code>iName</code> in 
		 *   this map.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this map is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMNode, CATIDOMNode#GetNodeName
		 */
		virtual HRESULT RemoveNamedItem(
			const CATUnicodeString& iName, 
			CATIDOMNode_var& oNamedItem) = 0;
		
		/**
		 * Retrieves the <code>index</code>th item in the map.
		 * If <code>index</code> is greater than or equal to the number of nodes in this map, 
		 * this returns <code>NULL_var</code>.
		 *
		 * @param iIndex
		 * Index into this map.
		 * @param oItem
		 * The node at the <code>index</code>th position in the map, or 
		 *   <code>NULL_var</code> if that is not a valid index.
		 *
		 * @see CATIDOMNode
		 */
		virtual HRESULT Item(
			int iIndex, 
			CATIDOMNode_var& oItem) = 0;
		
		/**
		 * Retrieves a node specified by local name and namespace URI.
		 *
		 * @param iNamespaceURI
		 * The namespace URI of the node to retrieve. 
		 * When it is an empty string, this method behaves like @href #GetNamedItem.
		 * @param iLocalName
		 * The local name of the node to retrieve.
		 * @param oItem
		 * A @href CATIDOMNode (of any type) with the specified
		 *    name, or <code>NULL_var</code> if the specified name did not
		 *    identify any node in the map.
		 *
		 * @see CATIDOMNode
		 */
		virtual HRESULT GetNamedItemNS(
			const CATUnicodeString& iNamespaceURI, 
			const CATUnicodeString& iLocalName, 
			CATIDOMNode_var& oItem)  = 0;
		
		/**
		 * Adds a node using its namespace URI and local name. 
		 * If a node with that namespace URI and that 
		 * local name is already present in this map, it is replaced by the new 
		 * one.
		 *
		 * @param iNamedItemNS
		 * The node to store in this map. The node will later be 
		 *   accessible using the return value of its @href CATIDOMNode#GetNamespaceURI and 
		 *   @href CATIDOMNode#GetLocalName methods.
		 * @param oOldNode
		 * If the new @href CATIDOMNode replaces an existing node, oOldNode is set to the 
		 *   replaced @href CATIDOMNode, otherwise to <code>NULL_var</code>.
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
		 *        <td class="errtd">WRONG_DOCUMENT_ERR: Raised if <code>iNamedItemNS</code> was created from a 
		 *   different document than the one that created this map.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this map is readonly.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2210</td>
		 *        <td class="errtd">INUSE_ATTRIBUTE_ERR: Raised if <code>iNodeToStore</code> is a 
		 *   @href CATIDOMAttr that is already an attribute of another 
		 *   @href CATIDOMElement object. The DOM user must explicitly clone 
		 *   @href CATIDOMAttr nodes to re-use them in other elements.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMNode, CATIDOMNode#GetNamespaceURI, CATIDOMNode#GetLocalName
		 */
		virtual HRESULT SetNamedItemNS(
			const CATIDOMNode_var& iNamedItemNS,
			CATIDOMNode_var& oOldNode) = 0;
		
		/**
		 * Removes a node specified by local name and namespace URI. 
		 * A removed attribute may be known to have a default value when this map contains 
		 * the attributes attached to an element, as returned by the attributes 
		 * attribute of the @href CATIDOMNode interface. If so, an attribute 
		 * immediately appears containing the default value as well as the 
		 * corresponding namespace URI, local name, and prefix when applicable.
		 *
		 * @param iNamespaceURI
		 * The namespace URI of the node to remove.
		 * @param iLocalName
		 * The local name of the node to remove.
		 * @param oRemovedNode
		 * The node removed from this map if a node with such a local 
		 *   name and namespace URI exists.
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
		 *        <td class="errtd">XMLParserERR_2208</td>
		 *        <td class="errtd">NOT_FOUND_ERR: Raised if there is no node named <code>iNamespaceURI</code>
		 *   and <code>iLocalName</code> in this map.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this map is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATIDOMNode, CATIDOMNode#GetNamespaceURI, CATIDOMNode#GetLocalName
		 */
		virtual HRESULT RemoveNamedItemNS(
			const CATUnicodeString& iNamespaceURI, 
			const CATUnicodeString& iLocalName, 
			CATIDOMNode_var& oRemovedNode) = 0;
			
};

CATDeclareHandler(CATIDOMNamedNodeMap, CATBaseUnknown);

#endif // CATIDOMNamedNodeMap_h

