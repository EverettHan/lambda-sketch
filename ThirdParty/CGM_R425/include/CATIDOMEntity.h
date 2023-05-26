// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMEntity_h
#define CATIDOMEntity_h

// System framework
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMEntity;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMEntity ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to represent an entity, either parsed or unparsed, in an XML 
 * document. Note that this models the entity itself not the entity 
 * declaration. @href CATIDOMEntity declaration modeling has been left for a 
 * later Level of the DOM specification.
 * <p>The @href CATIDOMNode#GetNodeName attribute that is inherited from 
 * @href CATIDOMNode contains the name of the entity.
 * <p>An XML processor may choose to completely expand entities before the 
 * structure model is passed to the DOM; in this case there will be no 
 * @href CATIDOMEntityReference nodes in the document tree.
 * <p>XML does not mandate that a non-validating XML processor read and 
 * process entity declarations made in the external subset or declared in 
 * external parameter entities. This means that parsed entities declared in 
 * the external subset need not be expanded by some classes of applications, 
 * and that the replacement value of the entity may not be available. When 
 * the replacement value is available, the corresponding @href CATIDOMEntity 
 * node's child list represents the structure of that replacement text. 
 * Otherwise, the child list is empty.
 * <p>The DOM Level 2 does not support editing @href CATIDOMEntity nodes; if a 
 * user wants to make changes to the contents of an @href CATIDOMEntity, 
 * every related @href CATIDOMEntityReference node has to be replaced in the 
 * structure model by a clone of the @href CATIDOMEntity 's contents, and 
 * then the desired changes must be made to each of those clones instead. 
 * @href CATIDOMEntity nodes and all their descendants are readonly.
 * <p>An @href CATIDOMEntity node does not have any parent. If the entity 
 * contains an unbound namespace prefix, the @href CATIDOMNode#GetNamespaceURI of 
 * the corresponding node in the @href CATIDOMEntity node subtree returns 
 * an empty @href CATUnicodeString. The same is true for @href CATIDOMEntityReference 
 * nodes that refer to this entity, when they are created using the 
 * @href CATIDOMDocument#CreateEntityReference method of the @href CATIDOMDocument
 * interface. The DOM Level 2 does not support any mechanism to resolve 
 * namespace prefixes.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Core-20001113'>Document Object Model (DOM) Level 2 Core Specification</a>.
 */

class ExportedByCatXmlItfExt CATIDOMEntity: public CATIDOMNode {
	CATDeclareInterface;

	public:
	
		/**
		 * Retrives the public identifier associated with the entity, if specified. If the 
		 * public identifier was not specified, this an empty @href CATUnicodeString.
		 * @param oPublicId
		 * the public identifier associated with the entity
		 */
		virtual HRESULT GetPublicId(
			CATUnicodeString & oPublicId)  = 0;

		/**
		 * Retrives the system identifier associated with the entity, if specified. If the 
		 * system identifier was not specified, this is an empty @href CATUnicodeString.
		 *
		 * @param oSystemId
		 * the system identifier associated with the entity
		 */
		virtual HRESULT GetSystemId(
			CATUnicodeString & oSystemId)  = 0;

		/**
		 * For unparsed entities, retrives the name of the notation for the entity. For 
		 * parsed entities, this is an empty @href CATUnicodeString. 
		 *
		 * @param oSystemId
		 * the name of the notation for the entity
		 */
		virtual HRESULT GetNotationName(
			CATUnicodeString & oNotationName)  = 0;

};
CATDeclareHandler(CATIDOMEntity, CATIDOMNode);


#endif // CATIDOMEntity_h
