// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATIXMLDOMDocumentBuilderDbg_h
#define CATIXMLDOMDocumentBuilderDbg_h


// System framework
#include "CATBaseUnknown.h"

// XMLParser framework private headers
#include "CatXmlItfExt.h"
class CATIXMLDOMDocumentBuilder_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIXMLDOMDocumentBuilderDbg;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLDOMDocumentBuilderDbg ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * CLSID of DOM debug wrapper.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_DEBUG_DOM;


/**
 * Private interface to instantiate the DOM debug wrapper
 */
class ExportedByCatXmlItfExt CATIXMLDOMDocumentBuilderDbg : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		virtual HRESULT SetBuilder(
			const CATIXMLDOMDocumentBuilder_var& iBuilder) = 0;
};

CATDeclareHandler(CATIXMLDOMDocumentBuilderDbg, CATBaseUnknown);


#endif // CATIXMLDOMDocumentBuilderDbg_h
