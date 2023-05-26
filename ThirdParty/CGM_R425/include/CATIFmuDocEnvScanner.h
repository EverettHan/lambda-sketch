/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIFmuDocEnvScanner_h
#define _CATIFmuDocEnvScanner_h

#include "CATBaseUnknown.h"
#include "CATListOfCATString.h"
#include "CATListOfCATUnicodeString.h"
class CATIFmuDocEnv;

/**
 *  Manages the document environments
 */
#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIFmuDocEnvScanner;
#else
extern "C" const IID IID_CATIFmuDocEnvScanner;
#endif

class ExportedByCATInteractiveInterfaces CATIFmuDocEnvScanner : public CATBaseUnknown
{
	public:
		CATDeclareInterface;

		// gets the current document environment name 
		virtual HRESULT GetCurrentDocEnvName(CATString& oCurrentDocEnvName) = 0;

		// creates a document environment
    /**
      * @param oDocEnv [out, CATBaseUnknown#Release]
      * created doc environement
      */
		virtual HRESULT CreateDocEnv(const CATString& iDocEnvName,CATIFmuDocEnv*& oDocEnv)= 0;

		// gets the list of the names of the document environments 
		virtual HRESULT GetDocEnvNameList(CATListOfCATString& oDocEnvList,
			CATListOfCATUnicodeString& oDocEnvDisplayNameList) = 0;

};

#endif
