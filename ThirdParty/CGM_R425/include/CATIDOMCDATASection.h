// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMCDATASection_h
#define CATIDOMCDATASection_h

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMText.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMCDATASection;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMCDATASection ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface referring to the data from an
 * XML CDATA section.  
 * @href CATIDOMCDATASection are used to escape blocks of text containing characters 
 * that would otherwise be regarded as markup.
 *
 * <p>Note that the string data associated with the CDATA section may 
 * contain characters that need to be escaped when appearing in an
 * XML document outside of a CDATA section.  
 * <p> The @href CATIDOMCDATASection class inherits from the 
 * @href CATIDOMCharacterData class through the @href CATIDOMText 
 * interface. Adjacent @href CATIDOMCDATASection nodes are not merged by use 
 * of the @href CATIDOMElement#normalize method.
 * @see CATIDOMText, CATIDOMCharacterData
 */

class ExportedByCatXmlItfExt CATIDOMCDATASection : public CATIDOMText {
	CATDeclareInterface;
	
	public:

};

CATDeclareHandler(CATIDOMCDATASection, CATIDOMText);

#endif // CATIDOMCDATASection_h

