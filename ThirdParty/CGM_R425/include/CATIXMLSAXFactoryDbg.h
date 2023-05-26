// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATIXMLSAXFactoryDbg_h
#define CATIXMLSAXFactoryDbg_h


// System framework
#include "CATBaseUnknown.h"

// XMLParser framework private headers
#include "CatXmlItfBase.h"
#include "CATBaseUnknown_var.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLSAXFactoryDbg;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLSAXFactoryDbg ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * CLSID of SAX debug wrapper.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_DEBUG_SAX;


/**
 * Private interface to instantiate the SAX debug wrapper
 */
class ExportedByCatXmlItfBase CATIXMLSAXFactoryDbg : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		virtual HRESULT SetFactory(
			const CATBaseUnknown_var& iFactory) = 0;
};

CATDeclareHandler(CATIXMLSAXFactoryDbg, CATBaseUnknown);


#endif // CATIXMLSAXFactoryDbg_h
