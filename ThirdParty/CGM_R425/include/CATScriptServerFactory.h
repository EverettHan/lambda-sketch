#ifndef CATScriptServerFactory_h
#define CATScriptServerFactory_h

// COPYRIGHT DASSAULT SYSTEMES 2002

// System framework
#include "CATUnicodeString.h"
class CATBaseDispatch;
class IClassFactory;

// AutomationInterfaces framework
#include "AutomationItf.h"
class CATIScriptServer;

/**
 * Factory class for objects which implement CATIScriptServer.
 * @author: Jean-Francois Doue (JDU)
 */
class ExportedByCATAutoItf CATScriptServerFactory {
	public:
#ifdef _WINDOWS_SOURCE
		/**
		 * Instantiates a COM Automation server.
		 */
		static HRESULT __stdcall CreateCOMServer(
			const CATUnicodeString& iName,
			const CLSID& iCLSID,
			IClassFactory* iFactory,
			DWORD iContext,
			DWORD iFlags,
			CATIScriptServer*& oServer);
#endif // _WINDOWS_SOURCE

		/**
		 * Instantiates a java RMI server.
		 */
		static HRESULT __stdcall CreateRMIServer(
			const CATUnicodeString& iInstanceName,
			CATBaseDispatch* iInstance,
			CATIScriptServer*& oServer);
};

#endif // CATScriptServerFactory_h
