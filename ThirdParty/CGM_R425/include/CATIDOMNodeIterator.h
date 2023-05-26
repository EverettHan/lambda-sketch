// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMNodeIterator_h
#define CATIDOMNodeIterator_h

// System framework
#include "CATBoolean.h"
#include "CATBaseUnknown.h"

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNodeFilter.h"
class CATIDOMNode_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMNodeIterator;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMNodeIterator ;
#endif // LOCAL_DEFINITION_FOR_IID



/**
 * Interface used to step through a set of nodes. (e.g. the 
 * set of nodes in a @href CATIDOMNodeList, the document subtree governed by 
 * a particular @href CATIDOMNode, the results of a query, or any other set 
 * of nodes). The set of nodes to be iterated is determined by the 
 * implementation of the @href CATIDOMNodeIterator. DOM Level 2 specifies a 
 * single @href CATIDOMNodeIterator implementation for document-order 
 * traversal of a document subtree. Instances of these iterators are created 
 * by calling @href CATIDOMDocumentTraversal#CreateNodeIterator.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Traversal-Range-20001113'>Document Object Model (DOM) Level 2 Traversal and Range Specification</a>.
 */

class ExportedByCatXmlItfExt CATIDOMNodeIterator: public CATBaseUnknown {
	CATDeclareInterface;

	public:

		/**
		 * Retrieves the root node of the <tt>CATIDOMNodeIterator</tt>, as specified when it 
		 * was created.
		 *
		 * @param oRoot
		 * The root node of the @href CATIDOMNodeIterator
		 */
		virtual HRESULT GetRoot(
			CATIDOMNode_var & oRoot) = 0;

		/**
		 * Retrieves which node types are presented via the 
		 * iterator. The available set of constants is defined in the 
		 * @href CATIDOMNodeFilter interface.  Nodes not accepted by 
		 * @href #GetWhatToShow will be skipped, but their children may still 
		 * be considered. Note that this skip takes precedence over the filter, 
		 * if any. 
		 *
		 * @param oType
		 * The node types which are presented via the iterator
		 */
		virtual HRESULT GetWhatToShow(
			unsigned int& oType) = 0;

		/**
		 * Retrieves the <tt>CATIDOMNodeFilter</tt> used to screen nodes.
		 *
		 * @param oNodeFilter
		 * the @href CATIDOMNodeFilter used to screen nodes.
		 */
		virtual HRESULT GetFilter(
			CATIDOMNodeFilter_var & oNodeFilter ) = 0;

		/**
		 * Retrieves the flag which determines whether the children of entity 
		 * reference nodes are visible to the iterator. If false, they  and 
		 * their descendants will be rejected. Note that this rejection takes 
		 * precedence over @href #GetWhatToShow and the filter. Also note 
		 * that this is currently the only situation where 
		 * @href CATIDOMNodeIterator instances may reject a complete subtree rather than 
		 * skipping individual nodes. 
		 * <br>
		 * <br> To produce a view of the document that has entity references 
		 * expanded and does not expose the entity reference node itself, use 
		 * the @href #GetWhatToShow flags to hide the entity reference node 
		 * and set @href #GetExpandEntityReferences to true when creating the 
		 * iterator. To produce a view of the document that has entity reference 
		 * nodes but no entity expansion, use the @href #GetWhatToShow flags 
		 * to show the entity reference node and set 
		 * @href #GetExpandEntityReferences to false.
		 *
		 * @param oResult
		 * the flag which determines whether the children of entity 
		 * reference nodes are visible to the iterator.
		 *
		 */
		virtual HRESULT GetExpandEntityReferences(
			CATBoolean & oResult) = 0;

		/**
		 * Retrieves the next node in the set and advances the position of the 
		 * iterator in the set. After a @href CATIDOMNodeIterator is created, 
		 * the first call to @href #NextNode returns the first node in 
		 * the set.
		 *
		 * @param oNode
		 * The next @href CATIDOMNode in the set being iterated over, or 
		 *   <tt>NULL_var</tt> if there are no more members in that set.
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
		 *        <td class="errtd">XMLParserERR_2211</td>
		 *        <td class="errtd">INVALID_STATE_ERR: Raised if this method is called after the 
		 *   @href #Detach method was invoked.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT NextNode( 
			CATIDOMNode_var & oNode) = 0;

		/**
		 * Retrieves the previous node in the set and moves the position of the 
		 * <tt>CATIDOMNodeIterator</tt> backwards in the set.
		 *
		 * @param oNode
		 * The previous @href CATIDOMNode in the set being iterated over, 
		 *   or <tt>NULL_var</tt> if there are no more members in that set. 
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
		 *        <td class="errtd">XMLParserERR_2211</td>
		 *        <td class="errtd">INVALID_STATE_ERR: Raised if this method is called after the 
		 *   @href #Detach method was invoked.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT PreviousNode(
			CATIDOMNode_var & oNode) = 0;

		/**
		 * Detaches the <tt>CATIDOMNodeIterator</tt> from the set which it iterated 
		 * over, releasing any computational resources and placing the iterator 
		 * in the INVALID state. After @href #Detach has been invoked, 
		 * calls to @href #NextNode or @href #PreviousNode will 
		 * raise the exception INVALID_STATE_ERR.
		 */
		virtual HRESULT Detach() = 0;

};

CATDeclareHandler(CATIDOMNodeIterator, CATBaseUnknown);


#endif // CATIDOMNodeIterator_h
