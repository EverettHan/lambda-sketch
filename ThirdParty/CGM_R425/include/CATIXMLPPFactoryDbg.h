// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATIXMLPPFactoryDbg_h
#define CATIXMLPPFactoryDbg_h


// System framework
#include "CATBaseUnknown.h"

// XMLParser framework private headers
#include "CatXmlItfBase.h"
#include "CATBaseUnknown_var.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLPPFactoryDbg;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLPPFactoryDbg ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * CLSID of PP debug wrapper.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_DEBUG_PP;


/**
 * Private interface to instantiate the PP debug wrapper
 */
class ExportedByCatXmlItfBase CATIXMLPPFactoryDbg : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		virtual HRESULT SetFactory(
			const CATBaseUnknown_var& iFactory) = 0;
};

CATDeclareHandler(CATIXMLPPFactoryDbg, CATBaseUnknown);


#endif // CATIXMLPPFactoryDbg_h
