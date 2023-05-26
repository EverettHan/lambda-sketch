// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATIXMLMSVersion_h
#define CATIXMLMSVersion_h


// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

// XMLParser framework private headers
#include "CatXmlItfBase.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLMSVersion;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLMSVersion ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Private interface to specify the version of 
 * MSXML used.
 */
class ExportedByCatXmlItfBase CATIXMLMSVersion : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		virtual HRESULT SetVersion(
			unsigned int iVersion) = 0;
};

CATDeclareHandler(CATIXMLMSVersion, CATBaseUnknown);


#endif // CATIXMLMSVersion_h
