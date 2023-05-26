// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMEntityReference_h
#define CATIDOMEntityReference_h

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMEntityReference;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMEntityReference ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface for object which may be inserted into the structure 
 * model when an entity reference is in the source document, or when the 
 * user wishes to insert an entity reference. Note that character references 
 * and references to predefined entities are considered to be expanded by 
 * the HTML or XML processor so that characters are represented by their 
 * Unicode equivalent rather than by an entity reference. Moreover, the XML 
 * processor may completely expand references to entities while building the 
 * structure model, instead of providing @href CATIDOMEntityReference 
 * objects. If it does provide such objects, then for a given 
 * @href CATIDOMEntityReference node, it may be that there is no 
 * @href CATIDOMEntity node representing the referenced entity. If such an 
 * @href CATIDOMEntity exists, then the subtree of the 
 * @href CATIDOMEntityReference node is in general a copy of the 
 * @href CATIDOMEntity node subtree. However, this may not be true when an 
 * entity contains an unbound namespace prefix. In such a case, because the 
 * namespace prefix resolution depends on where the entity reference is, the 
 * descendants of the @href CATIDOMEntityReference node may be bound to 
 * different namespace URIs.
 * <p>As for @href CATIDOMEntity nodes, @href CATIDOMEntityReference nodes and 
 * all their descendants are readonly.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Core-20001113'>Document Object Model (DOM) Level 2 Core Specification</a>.
 */
class ExportedByCatXmlItfExt CATIDOMEntityReference: public CATIDOMNode {
	CATDeclareInterface;
	
	public:
	
};
CATDeclareHandler(CATIDOMEntityReference, CATIDOMNode);


#endif // CATIDOMEntityReference_h
