// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMTreeWalker_h
#define CATIDOMTreeWalker_h

// System framework
#include "CATBoolean.h"
#include "CATBaseUnknown.h"

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNodeFilter.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMTreeWalker;
#else // LOCAL_DEFINITION_FOR_IID
	extern const IID IID_CATIDOMTreeWalker ;
#endif // LOCAL_DEFINITION_FOR_IID


class CATIDOMNode_var;
/**
 * Interface used to navigate a document tree or 
 * subtree using the view of the document defined by their 
 * <tt>GetWhatToShow</tt> flags and filter (if any). Any function which 
 * performs navigation using a @href CATIDOMTreeWalker will automatically 
 * support any view defined by a @href CATIDOMTreeWalker.
 * <p>Omitting nodes from the logical view of a subtree can result in a 
 * structure that is substantially different from the same subtree in the 
 * complete, unfiltered document. Nodes that are siblings in the 
 * @href CATIDOMTreeWalker view may be children of different, widely 
 * separated nodes in the original view. For instance, consider a 
 * @href CATIDOMNodeFilter that skips all nodes except for Text nodes and 
 * the root node of a document. In the logical view that results, all text 
 * nodes will be siblings and appear as direct children of the root node, no 
 * matter how deeply nested the structure of the original document.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Traversal-Range-20001113'>Document Object Model (DOM) Level 2 Traversal and Range Specification</a>.
 */

class ExportedByCatXmlItfExt CATIDOMTreeWalker: public CATBaseUnknown {
	CATDeclareInterface;

	public:

		/**
		 * Retrieves the root node of the <tt>CATIDOMTreeWalker</tt>, as specified 
		 * when it was created.
		 *
		 * @param oRoot
		 * The root node of the @href CATIDOMTreeWalker
		 */
		virtual HRESULT GetRoot(
			CATIDOMNode_var & oRoot) = 0;

		/**
		 * Retrieves the attribute which determines which node types are presented via the 
		 * <tt>CATIDOMTreeWalker</tt>. The available set of constants is defined in 
		 * the @href CATIDOMNodeFilter interface.  Nodes not accepted by 
		 * @href #GetWhatToShow will be skipped, but their children may still 
		 * be considered. Note that this skip takes precedence over the filter, 
		 * if any.
		 *
		 * @param oType
		 * the attribute which determines which node types are presented via the 
		 * @href CATIDOMTreeWalker
		 */
		virtual HRESULT GetWhatToShow(
			unsigned int& oType) = 0;

		/**
		 * Retrieves the filter used to screen nodes.
		 *
		 * @param oNodeFilter
		 * the filter used to screen nodes
		 */
		virtual HRESULT GetFilter(
			CATIDOMNodeFilter_var & oFilter) = 0;

		/**
		 * Retrieves the flag which determines whether the children of entity 
		 * reference nodes are visible to the <tt>CATIDOMTreeWalker</tt>. If false, 
		 * they  and their descendants will be rejected. Note that this 
		 * rejection takes precedence over @href #GetWhatToShow and the 
		 * filter, if any. 
		 * <br> To produce a view of the document that has entity references 
		 * expanded and does not expose the entity reference node itself, use 
		 * the @href #GetWhatToShow flags to hide the entity reference node 
		 * and set @href #GetExpandEntityReferences to true when creating the 
		 * @href CATIDOMTreeWalker. To produce a view of the document that has 
		 * entity reference nodes but no entity expansion, use the 
		 * @href #GetWhatToShow flags to show the entity reference node and 
		 * set @href #GetExpandEntityReferences to false.
		 *
		 * @param oResult
		 * the flag which determines whether the children of entity 
		 * reference nodes are visible to the @href CATIDOMTreeWalker.
		 *
		 */
		virtual HRESULT GetExpandEntityReferences(
			CATBoolean & oResult) = 0;

		/**
		 * Retrieves the node at which the <tt>CATIDOMTreeWalker</tt> is currently positioned.
		 * <br>Alterations to the DOM tree may cause the current node to no longer 
		 * be accepted by the @href CATIDOMTreeWalker 's associated filter. 
		 * @href #GetCurrentNode may also be explicitly set to any node, 
		 * whether or not it is within the subtree specified by the 
		 * @href #GetRoot node or would be accepted by the filter and 
		 * @href #GetWhatToShow flags. Further traversal occurs relative to 
		 * @href #GetCurrentNode even if it is not part of the current view, 
		 * by applying the filters in the requested direction; if no traversal 
		 * is possible, @href #GetCurrentNode is not changed.
		 *
		 * @param oCurrentNode
		 * the node at which the @href CATIDOMTreeWalker is currently positioned.
		 */
		virtual HRESULT GetCurrentNode(
			CATIDOMNode_var & oCurrentNode) = 0;

		/**
		 * Sets the node at which the <tt>CATIDOMTreeWalker</tt> is to be currently positioned.
		 *
		 * @param iCurrentNode
		 * the node at which the @href CATIDOMTreeWalker is to be currently positioned.
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
		 *        <td class="errtd">NOT_SUPPORTED_ERR: Raised if an attempt is made to call 
		 *   @href #SetCurrentNode with a <tt>NULL_var</tt> argument.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 */
		virtual HRESULT SetCurrentNode(
			const CATIDOMNode_var & iCurrentNode) = 0;

		/**
		 * Moves to and returns the closest visible ancestor node of the current 
		 * node. If the search for @href #ParentNode attempts to step 
		 * upward from the @href CATIDOMTreeWalker 's @href #GetRoot node, or 
		 * if it fails to find a visible ancestor node, this method retains the 
		 * current position and returns <tt>NULL_var</tt>.
		 *
		 * @param oParentNode
		 * The new parent node, or <tt>NULL_var</tt> if the current node 
		 *   has no parent  in the @href CATIDOMTreeWalker 's logical view.  
		 */
		virtual HRESULT ParentNode(
			CATIDOMNode_var & oParentNode) = 0;

		/**
		 * Moves the <tt>CATIDOMTreeWalker</tt> to the first visible child of the 
		 * current node, and returns the new node. If the current node has no 
		 * visible children, returns <tt>NULL_var</tt>, and retains the current 
		 * node.
		 * 
		 * @param oFirstChild
		 * The new node, or <tt>NULL_var</tt> if the current node has no 
		 *   visible children  in the @href CATIDOMTreeWalker 's logical view.  
		 */
		virtual HRESULT FirstChild(
			CATIDOMNode_var & oFirstChild) = 0;

		/**
		 * Moves the <tt>CATIDOMTreeWalker</tt> to the last visible child of the 
		 * current node, and returns the new node. If the current node has no 
		 * visible children, returns <tt>NULL_var</tt>, and retains the current 
		 * node.
		 *
		 * @param oLastChild
		 * The new node, or <tt>NULL_var</tt> if the current node has no 
		 *   children  in the @href CATIDOMTreeWalker 's logical view.  
		 */
		virtual HRESULT LastChild(
			CATIDOMNode_var & oLastChild) = 0;

		/**
		 * Moves the <tt>CATIDOMTreeWalker</tt> to the previous sibling of the 
		 * current node, and returns the new node. If the current node has no 
		 * visible previous sibling, returns <tt>NULL_var</tt>, and retains the 
		 * current node.
		 *
		 * @param oPreviousSibling
		 * The new node, or <tt>NULL_var</tt> if the current node has no 
		 *   previous sibling.  in the @href CATIDOMTreeWalker 's logical view.  
		 */
		virtual HRESULT PreviousSibling(
			CATIDOMNode_var & oPreviousSibling) = 0;

		/**
		 * Moves the <tt>CATIDOMTreeWalker</tt> to the next sibling of the current 
		 * node, and returns the new node. If the current node has no visible 
		 * next sibling, returns <tt>NULL_var</tt>, and retains the current node.
		 *
		 * @param oNextSibling
		 * The new node, or <tt>NULL_var</tt> if the current node has no 
		 *   next sibling.  in the @href CATIDOMTreeWalker 's logical view.  
		 */
		virtual HRESULT NextSibling(
			CATIDOMNode_var & oNextSibling) = 0;

		/**
		 * Moves the <tt>CATIDOMTreeWalker</tt> to the previous visible node in 
		 * document order relative to the current node, and returns the new 
		 * node. If the current node has no previous node,  or if the search for 
		 * <tt>previousNode</tt> attempts to step upward from the 
		 * @href CATIDOMTreeWalker 's @href #GetRoot node,  returns 
		 * <tt>NULL_var</tt>, and retains the current node.
		 *
		 * @param oPreviousNode
		 * The new node, or <tt>NULL_var</tt> if the current node has no 
		 *   previous node  in the @href CATIDOMTreeWalker 's logical view.  
		 */
		virtual HRESULT PreviousNode(
			CATIDOMNode_var & oPreviousNode) = 0;

		/**
		 * Moves the <tt>CATIDOMTreeWalker</tt> to the next visible node in document 
		 * order relative to the current node, and returns the new node. If the 
		 * current node has no next node, or if the search for nextNode attempts 
		 * to step upward from the @href CATIDOMTreeWalker 's @href #GetRoot 
		 * node, returns <tt>NULL_var</tt>, and retains the current node.
		 *
		 * @param oNextNode
		 * The new node, or <tt>NULL_var</tt> if the current node has no 
		 *   next node  in the @href CATIDOMTreeWalker 's logical view.  
		 */
		virtual HRESULT NextNode(
			CATIDOMNode_var & oNextNode) = 0;

};
CATDeclareHandler(CATIDOMTreeWalker, CATBaseUnknown);


#endif // CATIDOMTreeWalker_h
