// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATIXMLXSLFactoryDbg_h
#define CATIXMLXSLFactoryDbg_h


// System framework
#include "CATBaseUnknown.h"

// XMLParser framework private headers
#include "CatXmlItfExt.h"
#include "CATBaseUnknown_var.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIXMLXSLFactoryDbg;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLXSLFactoryDbg ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * CLSID of SAX debug wrapper.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XSLT_DEBUG;


/**
 * Private interface to instantiate the SAX debug wrapper
 */
class ExportedByCatXmlItfExt CATIXMLXSLFactoryDbg : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		virtual HRESULT SetFactory(
			const CATBaseUnknown_var& iFactory) = 0;
};

CATDeclareHandler(CATIXMLXSLFactoryDbg, CATBaseUnknown);


#endif // CATIXMLXSLFactoryDbg_h
