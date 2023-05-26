// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMNotation_h
#define CATIDOMNotation_h

// System framework
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMNotation;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMNotation ;
#endif // LOCAL_DEFINITION_FOR_IID


/**
 * Interface to represent a notation declared in the DTD. A notation either 
 * declares, by name, the format of an unparsed entity (see section 4.7 of 
 * the XML 1.0 specification ), or is used for formal declaration of 
 * processing instruction targets (see section 2.6 of the XML 1.0 
 * specification ). The @href CATIDOMNode#GetNodeName method inherited from 
 * @href CATIDOMNode is set to the declared name of the notation.
 * <p>The DOM Level 1 does not support editing @href CATIDOMNotation nodes; 
 * they are therefore readonly.
 * <p>A @href CATIDOMNotation node does not have any parent.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Core-20001113'>Document Object Model (DOM) Level 2 Core Specification</a>.
 */

class ExportedByCatXmlItfExt CATIDOMNotation: public CATIDOMNode {
	CATDeclareInterface;

	public:

		/**
		 * Retrieves the public identifier of this notation. If the public identifier was 
		 * not specified, this is an empty @href CATUnicodeString.
		 *
		 * @param oPublicId
		 * the public identifier of this notation
		 */
		virtual HRESULT GetPublicId(
			CATUnicodeString & oPublicId) = 0;

		/**
		 * Retrieves the system identifier of this notation. If the system identifier was 
		 * not specified, this is an empty @href CATUnicodeString.
		 *
		 * @param oSystemId
		 * the system identifier of this notation
		 */
		virtual HRESULT GetSystemId(
			CATUnicodeString & oSystemId) = 0;

};
CATDeclareHandler(CATIDOMNotation, CATIDOMNode);


#endif // CATIDOMNotation_h
