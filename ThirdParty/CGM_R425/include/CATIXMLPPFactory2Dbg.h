// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATIXMLPPFactory2Dbg_h
#define CATIXMLPPFactory2Dbg_h


// System framework
#include "CATBaseUnknown.h"

// XMLParser framework private headers
#include "CatXmlItfBase.h"
#include "CATBaseUnknown_var.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLPPFactory2Dbg;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLPPFactory2Dbg ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * CLSID of PP debug wrapper.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_DEBUG_PP;


/**
 * Private interface to instantiate the PP debug wrapper
 */
class ExportedByCatXmlItfBase CATIXMLPPFactory2Dbg : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		virtual HRESULT SetFactory(
			const CATBaseUnknown_var& iFactory2) = 0;
};

CATDeclareHandler(CATIXMLPPFactory2Dbg, CATBaseUnknown);


#endif // CATIXMLPPFactory2Dbg_h
