// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMDocumentTraversal_h
#define CATIDOMDocumentTraversal_h

// System framework
#include "CATBaseUnknown.h"
#include "CATBoolean.h"

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNodeFilter.h"
class CATIDOMNodeIterator_var;
class CATIDOMTreeWalker_var;
class CATIDOMNode_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMDocumentTraversal;
#else // LOCAL_DEFINITION_FOR_IID
	extern const IID IID_CATIDOMDocumentTraversal ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface which contains methods that create iterators and 
 * tree-walkers to traverse a node and its children in document order (depth 
 * first, pre-order traversal, which is equivalent to the order in which the 
 * start tags occur in the text representation of the document). In DOMs 
 * which support the Traversal feature, @href CATIDOMDocumentTraversal will 
 * be implemented by the same objects that implement the @href CATIDOMDocument interface.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Traversal-Range-20001113'>Document Object Model (DOM) Level 2 Traversal and Range Specification</a>.
 */
class ExportedByCatXmlItfExt CATIDOMDocumentTraversal: public CATBaseUnknown {
	CATDeclareInterface;

	public:

		/**
		 * Creates a new <tt>CATIDOMNodeIterator</tt> over the subtree rooted at the 
		 * specified node.
		 *
		 * @param iRoot
		 * The node which will be iterated together with its children. 
		 * The iterator is initially positioned just before this node. The 
		 * <tt>iWhatToShow</tt> flags and the filter, if any, are not 
		 * considered when setting this position. The root must not be 
		 * <tt>NULL_var</tt>.
		 * @param iWhatToShow
		 * This flag specifies which node types may appear in 
		 * the logical view of the tree presented by the iterator. See the 
		 * description of @href CATDOMNodeFilterType for the set of possible 
		 * <tt>SHOW_</tt> values.These flags can be combined using 
		 * <tt>OR</tt>.
		 * @param iFilter
		 * The @href CATIDOMNodeFilter to be used with this @href CATIDOMTreeWalker, 
		 * or <tt>NULL_var</tt> to indicate no filter.
		 * @param iEntityReferenceExpansion
		 * The value of this flag determines 
		 * whether entity reference nodes are expanded.
		 * @param oNodeIterator
		 * The newly created @href CATIDOMNodeIterator.
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
		 *        <td class="errtd">NOT_SUPPORTED_ERR: Raised if the specified root is <tt>NULL_var</tt>.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 */
		virtual HRESULT CreateNodeIterator(
			const CATIDOMNode_var & iRoot, 
			const unsigned int iWhatToShow, 
			const CATIDOMNodeFilter_var & iFilter, 
			const CATBoolean iEntityReferenceExpansion, 
			CATIDOMNodeIterator_var & oNodeIterator) = 0;

		/**
		 * Creates a new <tt>CATIDOMTreeWalker</tt> over the subtree rooted at the 
		 * specified node.
		 *
		 * @param iRoot
		 * The node which will serve as the root for the @href CATIDOMTreeWalker. 
		 * The <tt>iWhatToShow</tt> flags and the  @href CATIDOMNodeFilter are not 
		 * considered when setting this value; 
		 * any node type will be accepted as the root. The 
		 * currentNode of the @href CATIDOMTreeWalker is 
		 * initialized to this node, whether or not it is visible. The 
		 * root functions as a stopping point for traversal 
		 * methods that look upward in the document structure, such as 
		 * @href CATIDOMTreeWalker#ParentNode and @href CATIDOMTreeWalker#NextNode. 
		 * The root must not be <tt>NULL_var</tt>.
		 * @param iWhatToShow
		 * This flag specifies which node types may appear in 
		 * the logical view of the tree presented by the tree-walker. See the 
		 * description of @href CATDOMNodeFilterType for the set of possible 
		 * SHOW_ values.These flags can be combined using <tt>OR</tt>.
		 * @param iFilter
		 * The @href CATIDOMNodeFilter to be used with this  @href CATIDOMTreeWalker, 
		 * or <tt>NULL_var</tt> to indicate no filter.
		 * @param iEntityReferenceExpansion
		 * If this flag is false, the contents of @href CATIDOMEntityReference nodes 
		 * are not presented in the logical view.
		 * @param oTreeWalker
		 * The newly created @href CATIDOMTreeWalker.
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
		 *        <td class="errtd">NOT_SUPPORTED_ERR: Raised if the specified root is <tt>NULL_var</tt>.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT CreateTreeWalker(
			const CATIDOMNode_var & iRoot, 
			const unsigned int iWhatToShow, 
			const CATIDOMNodeFilter_var & iFilter,
			const CATBoolean iEntityReferenceExpansion, 
			CATIDOMTreeWalker_var & oTreeWalker ) = 0;
};
CATDeclareHandler(CATIDOMDocumentTraversal, CATBaseUnknown);


#endif // CATIDOMDocumentTraversal_h
