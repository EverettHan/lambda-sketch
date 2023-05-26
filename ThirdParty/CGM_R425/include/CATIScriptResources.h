#ifndef CATIScriptResources_h
#define CATIScriptResources_h

// COPYRIGHT DASSAULT SYSTEMES 2001

// AutomationInterfaces framework
#include "AutomationItf.h"
#include "CATIScriptServer.h"
#include "CATListOfITypeLib.h"

// System framework
#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

/**
 * Interface to provide access to the system resources
 * used by the scripting infrastructure.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptResources : public IUnknown {
	public:
		/**
		 * Register a scripting server in order to make
		 * it accessible by other processes.
		 */
		virtual HRESULT __stdcall RegisterServer(
			CATIScriptServer* iServer) = 0;

		/**
		 * Unregisters a server with the running object table.
		 */
		virtual HRESULT __stdcall UnregisterServer(
			unsigned int iIndex) = 0;

		/**
		 * Returns the count of servers currently registered in
		 * the running object table.
		 */
		virtual HRESULT __stdcall GetRegisteredServerCount(
			unsigned int& oServerCount) = 0;

		/**
		 * Retrieves the iIndex-th server registered in
		 * the running object table.
		 */
		virtual HRESULT __stdcall GetRegisteredServer(
			unsigned int iIndex,
			CATIScriptServer*& oServer) = 0;

		/**
		 * Returns the list of type libraries found in the runtime view.
		 */
		virtual HRESULT __stdcall GetInternalTypeLibs(
			CATListOfCATUnicodeString& oNames,
			CATListOfITypeLib& oLibs) = 0;
};

/**
 * Give access to a global <tt>CATIScriptResources</tt> object.
 */
extern HRESULT ExportedByCATAutoItf GetScriptResources(CATIScriptResources*& oScriptResources);

#ifdef _WINDOWS_SOURCE
/**
 * Name of the VBA Application Typelib.
 */
extern ExportedByCATAutoItf const CATUnicodeString g_CATIAAppTypeLibName;

#endif // _WINDOWS_SOURCE

extern "C" const IID IID_CATIScriptResources;

#endif // CATIScriptResources_h

