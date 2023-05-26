// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATIDOMNodeFilter_h
#define CATIDOMNodeFilter_h

// System framework
#include "CATBaseUnknown.h"

// XMLParser framework
#include "CatXmlItfExt.h"
class CATIDOMNode_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMNodeFilter;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMNodeFilter ;
#endif // LOCAL_DEFINITION_FOR_IID



/**
 * Interface for filters objects that know how to "filter out" nodes. If a 
 * @href CATIDOMNodeIterator or @href CATIDOMTreeWalker is given a 
 * @href CATIDOMNodeFilter, it applies the filter before it returns the next 
 * node. If the filter says to accept the node, the traversal logic returns 
 * it; otherwise, traversal looks for the next node and pretends that the 
 * node that was rejected was not there.
 * <p>The DOM does not provide any filters. @href CATIDOMNodeFilter is just an 
 * interface that users can implement to provide their own filters. 
 * <p>@href CATIDOMNodeFilter instances do not need to know how to traverse from node 
 * to node, nor do they need to know anything about the data structure that 
 * is being traversed. This makes it very easy to write filters, since the 
 * only thing they have to know how to do is evaluate a single node. One 
 * filter may be used with a number of different kinds of traversals, 
 * encouraging code reuse.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Traversal-Range-20001113'>Document Object Model (DOM) Level 2 Traversal and Range Specification</a>.
 */

class ExportedByCatXmlItfExt CATIDOMNodeFilter: public CATBaseUnknown {
	CATDeclareInterface;

	public:

		/**
		 * Constants returned by @href #AcceptNode
		 *
		 * @param FILTER_ACCEPT
		 * Accept the node. Navigation methods defined for 
		 * @href CATIDOMNodeIterator or @href CATIDOMTreeWalker will return this 
		 * node.
		 * @param FILTER_REJECT
		 * Reject the node. Navigation methods defined for 
		 * @href CATIDOMNodeIterator or @href CATIDOMTreeWalker will not return 
		 * this node. For @href CATIDOMTreeWalker, the children of this node 
		 * will also be rejected. <tt>NodeIterators</tt> treat this as a 
		 * synonym for <tt>FILTER_SKIP</tt>.
		 *
		 * @param FILTER_SKIP
		 * Skip this single node. Navigation methods defined for 
		 * @href CATIDOMNodeIterator or @href CATIDOMTreeWalker will not return 
		 * this node. For both @href CATIDOMNodeIterator and 
		 * @href CATIDOMTreeWalker, the children of this node will still be 
		 * considered. 
		 */
		enum FilterAction { 
			FILTER_ACCEPT                  = 0,
			FILTER_REJECT                  = 1,
 			FILTER_SKIP                    = 2
		};


		/**
		 * Tests whether a specified node is visible in the logical view of a 
		 * <tt>CATIDOMTreeWalker</tt> or <tt>CATIDOMNodeIterator</tt>. This function 
		 * will be called by the implementation of @href CATIDOMTreeWalker and 
		 * @href CATIDOMNodeIterator ; it is not normally called directly from 
		 * user code. (Though you could do so if you wanted to use the same 
		 * filter to guide your own application logic.)
		 * @param iNode
		 * The node to check to see if it passes the filter or not.
		 * @param oAccepted
		 * a constant to determine whether the node is accepted, 
		 *   rejected, or skipped, as defined above.
		 */
		virtual HRESULT AcceptNode(
			const CATIDOMNode_var & iNode, 
			FilterAction & oAccepted) = 0;
};
CATDeclareHandler(CATIDOMNodeFilter, CATBaseUnknown);

#endif // CATIDOMNodeFilter_h
