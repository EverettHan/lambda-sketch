// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMText_h
#define CATIDOMText_h

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMCharacterData.h"
class CATIDOMText_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMText;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMText ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface representing the textual content (termed character data in XML) of a 
 * <code>CATIDOMElement</code> or <code>CATIDOMAttr</code>. 
 * This interface inherits from @href CATIDOMCharacterData. If there is no markup inside 
 * an element's content, the text is contained in a single object 
 * implementing the @href CATIDOMText interface that is the only child of 
 * the element. If there is markup, it is parsed into the information items 
 * (elements, comments, etc.) and @href CATIDOMText nodes that form the list 
 * of children of the element.
 * <p>When a document is first made available via the DOM, there is only one 
 * @href CATIDOMText node for each block of text. Users may create adjacent 
 * @href CATIDOMText nodes that represent the contents of a given element 
 * without any intervening markup, but should be aware that there is no way 
 * to represent the separations between these nodes in XML or HTML, so they 
 * will not (in general) persist between DOM editing sessions. The 
 * @href CATIDOMNode#Normalize method merges any such 
 * adjacent @href CATIDOMText objects into a single node for each block of 
 * text ; this is  recommended before employing operations that depend on a 
 * particular document structure, such as navigation with 
 * <code>XPointers.</code> 
 * @see CATIDOMCharacterData, CATIDOMElement, CATIDOMAttr
 */

class ExportedByCatXmlItfExt CATIDOMText: public CATIDOMCharacterData {
  CATDeclareInterface;

	public:
	
		/**
		 * Breaks this node into two nodes at the specified <code>iOffset</code>, 
		 * keeping both in the tree as siblings. 
		 * After being split, this node will contain all the content up 
		 * to the <code>iOffset</code> point.
		 * A new node of the same type, which contains all the content at and 
		 * after the <code>iOffset</code> point, is returned. If the original 
		 * node had a parent node, the new node is inserted as the next sibling 
		 * of the original node. When the <code>iOffset</code> is equal to the 
		 * length of this node, the new node has no data.
		 *
		 * @param iOffSet
		 * The characters offset at which to split, starting from <code>0</code>.
		 * @param oText
		 * The new node, of the same type as this node.
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
		 *        <td class="errtd">XMLParserERR_2201</td>
		 *        <td class="errtd">INDEX_SIZE_ERR: Raised if the specified <tt>iOffset</tt> is greater 
	     *   than the number of characters in <code>data</code>.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT SplitText(
			unsigned int iOffSet, 
			CATIDOMText_var& oText) = 0;

};

CATDeclareHandler(CATIDOMText, CATIDOMCharacterData);


#endif // CATIDOMText_h

