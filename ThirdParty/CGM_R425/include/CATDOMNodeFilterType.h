// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATDOMNodeFilterType_h
#define CATDOMNodeFilterType_h

#include "CatXmlItfExt.h"

/**
 * Class to group the constants which can be passed to
 * the <tt>iWhatToShow</tt> parameter of the <tt>CATIDOMTreeWalker</tt> and
 * <tt>CATIDOMNodeIterator</tt> classes. You never instantiate this class.
 *
 * @see CATIDOMDocumentTraversal, CATIDOMTreeWalker#GetWhatToShow, CATIDOMNodeIterator#GetWhatToShow
 */
class ExportedByCatXmlItfExt CATDOMNodeFilterType {
	public:
		/**
		 * Show all instances of <tt>CATIDOMNode</tt>.
		 * @see CATIDOMNode
		 */
		static const unsigned int SHOW_ALL;

		/**
		 * Show all instances of <tt>CATIDOMElement</tt>.
		 * @see CATIDOMElement
		 */
		static const unsigned int SHOW_ELEMENT;

		/**
		 * Show all instances of <tt>CATIDOMAttr</tt>. This is meaningful only when creating an 
		 * iterator or tree-walker with an attribute node as its 
		 * @href CATIDOMTreeWalker#GetRoot; in this case, it means that the attribute node 
		 * will appear in the first position of the iteration or traversal. 
		 * Since attributes are never children of other nodes, they do not 
		 * appear when traversing over the document tree.
		 * @see CATIDOMAttr
		 */
		static const unsigned int SHOW_ATTRIBUTE;

		/**
		 * Show all instances of <tt>CATIDOMText</tt>.
		 * @see CATIDOMText
		 */
		static const unsigned int SHOW_TEXT;

		/**
		 * Show all instances of <tt>CATIDOMCDATASection</tt>.
		 * @see CATIDOMCDATASection
		 */
		static const unsigned int SHOW_CDATA_SECTION;

		/**
		 * Show all instances of <tt>CATIDOMEntityReference</tt>.
		 * @see CATIDOMEntityReference
		 */
		static const unsigned int SHOW_ENTITY_REFERENCE;

		/**
		 * Show all instances of <tt>CATIDOMEntity</tt>. This is meaningful only when creating 
		 * an iterator or tree-walker with an @href CATIDOMEntity node as its 
		 * @href CATIDOMTreeWalker#GetRoot; in this case, it means that the @href CATIDOMEntity
		 *  node will appear in the first position of the traversal. Since 
		 * entities are not part of the document tree, they do not appear when 
		 * traversing over the document tree.
		 * @see CATIDOMEntity
		 */
		static const unsigned int SHOW_ENTITY;

		/**
		 * Show all instances of <tt>CATIDOMProcessingInstruction</tt>.
		 * @see CATIDOMProcessingInstruction
		 */
		static const unsigned int SHOW_PROCESSING_INSTRUCTION;

		/**
		 * Show all instances of <tt>CATIDOMComment</tt>.
		 * @see CATIDOMComment
		 */
		static const unsigned int SHOW_COMMENT;

		/**
		 * Show all instances of <tt>CATIDOMDocument</tt>.
		 * @see CATIDOMDocument
		 */
		static const unsigned int SHOW_DOCUMENT;

		/**
		 * Show all instances of <tt>CATIDOMDocumentType</tt>.
		 * @see CATIDOMDocumentType
		 */
		static const unsigned int SHOW_DOCUMENT_TYPE;

		/**
		 * Show all instances of <tt>CATIDOMDocumentFragment</tt>.
		 * @see CATIDOMDocumentFragment
		 */
		static const unsigned int SHOW_DOCUMENT_FRAGMENT;

		/**
		 * Show all instances of <tt>CATIDOMNotation</tt>. This is meaningful only when creating 
		 * an iterator or tree-walker with a @href CATIDOMNotation node as its 
		 * @href CATIDOMTreeWalker#GetRoot; in this case, it means that the 
		 * @href CATIDOMNotation node will appear in the first position of the 
		 * traversal. Since notations are not part of the document tree, they do 
		 * not appear when traversing over the document tree.
		 * @see CATIDOMNotation
		 */
		static const unsigned int SHOW_NOTATION;

	private:
		// The constructor, copy constructor and the equal operator must not be implemented
		CATDOMNodeFilterType();
		CATDOMNodeFilterType (CATDOMNodeFilterType &);
		CATDOMNodeFilterType& operator=(CATDOMNodeFilterType&);
};

#endif // CATDOMNodeFilterType_h
