// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMNodeList_h
#define CATIDOMNodeList_h

// System framework
#include "CATBaseUnknown.h"

// XMLParser framework
#include "CatXmlItfExt.h"
class CATIDOMNode_var;
 
#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMNodeList;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMNodeList ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface providing the abstraction of an ordered 
 * collection of nodes.
 * <tt>CATIDOMNodeList</tt>s are created by @href CATIDOMDocument#GetElementsByTagName, 
 * @href CATIDOMNode#GetChildNodes. 
 *
 * <p>The items in the @href CATIDOMNodeList are accessible via an integral 
 * index, starting from 0. 
 *
 * <tt>CATIDOMNodeList</tt>s are "live", in that any changes to the document tree are immediately
 * reflected in any <tt>CATIDOMNodeList</tt>s that may have been created for that tree.
 * @see CATIDOMDocument#GetElementsByTagName, CATIDOMNode#GetChildNodes
 */
class ExportedByCatXmlItfExt CATIDOMNodeList : public CATBaseUnknown {
	CATDeclareInterface;

	public:

		/**
		 * Retrieves the number of nodes in the list.
		 * The range of valid child node indices is 0 to <code>oLength - 1</code> inclusive.
		 *
		 * @param oLength
		 * The retrieved number of nodes in the list.
		 */
		virtual HRESULT	GetLength(
			unsigned int& oLength) = 0;

		/**
		 * Retrieves the <code>index</code>th item in the collection.
		 * If <code>index</code> is greater than or equal to the number of nodes in 
		 * the list, <tt>oItem</tt> is set to <code>NULL_var</code>.
		 *
		 * @param iIndex
		 * Index into the collection.
		 * @param oItem
		 * The node at the <code>index</code>th position in the 
		 *   @href CATIDOMNodeList, or <code>NULL_var</code> if that is not a valid 
		 *   index.
		 */
		virtual HRESULT	Item(
			unsigned int iIndex, 
			CATIDOMNode_var& oItem) = 0;

};

CATDeclareHandler(CATIDOMNodeList, CATBaseUnknown);

#endif // CATIDOMNodeList_h

