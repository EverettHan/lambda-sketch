// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMDocumentType_h
#define CATIDOMDocumentType_h

// System framework
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"
class CATIDOMNamedNodeMap_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMDocumentType;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMDocumentType ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface providing access to the list of entities and notations that are defined in the document.
 * Each @href CATIDOMDocument has a <code>doctype</code> whose value 
 * is either <code>NULL_var</code> or a @href CATIDOMDocumentType object. 
 *
 * <p>The DOM Level 1 doesn't support editing @href CATIDOMDocumentType nodes.
 * @see CATIDOMDocument, CATIDOMNode
 */
class ExportedByCatXmlItfExt CATIDOMDocumentType : public CATIDOMNode {
  CATDeclareInterface;

	public:

		/**
		 * Retrieves the name of DTD.
		 * This name is immediately following the 
		 * <code>DOCTYPE</code> keyword in an XML source document.
		 *
		 * @param oName
		 * The retrieved name of DTD.
		 */
		virtual HRESULT GetName(
			CATUnicodeString& oName) = 0;
		
		/**
		 * Retrieves a <code>CATIDOMNamedNodeMap</code> containing the general entities, both 
		 * external and internal, declared in the DTD.
		 * Duplicate entities are discarded. 
		 *
		 * @param oEntities
		 * The retrieved @href CATIDOMNamedNodeMap containing the general entities declared in the DTD.
		 *
		 * @see CATIDOMNamedNodeMap
		 */
		virtual HRESULT GetEntities(
			CATIDOMNamedNodeMap_var& oEntities) = 0;
		
		/**
		 * Retrieves a <code>CATIDOMNamedNodeMap</code> containing an entry for
		 * each notation declared in a document's DTD.
		 * Duplicate notations are discarded. 
		 *
		 * @param oNotations
		 * The retrieved @href CATIDOMNamedNodeMap containing an entry for
		 * each notation declared in a document's DTD.
		 *
		 * @see CATIDOMNamedNodeMap
		 */
		virtual HRESULT GetNotations(
			CATIDOMNamedNodeMap_var& oNotations) = 0;
		
		/**
		 * Retrieves the public identifier of the external subset.
		 *
		 * @param oPublicId
		 * The public identifier of the external subset.
		 */
		virtual HRESULT GetPublicId(
			CATUnicodeString& oPublicId) = 0;
		
		/**
		 * Get the system identifier of the external subset.
		 *
		 * @param oSystemId
		 * The system identifier of the external subset.
		 */
		virtual HRESULT GetSystemId(
			CATUnicodeString& oSystemId) = 0;
		
		/**
		 * Get the internal subset as a string.
		 *
		 * @param oInternalSubset
		 * The internal subset as a string.
		 */
		virtual HRESULT GetInternalSubset(
			CATUnicodeString& oInternalSubset) = 0;

};

CATDeclareHandler(CATIDOMDocumentType, CATIDOMNode);


#endif // CATIDOMDocumentType_h

