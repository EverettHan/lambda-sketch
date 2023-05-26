#ifndef CATIScriptServer_h
#define CATIScriptServer_h

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "IUnknown.h"
#include "CATUnicodeString.h"

/**
 * Private interface to encapsulate scriptable object servers.
 * @author: Jean-Francois Doue (JDU)
 */
class CATIScriptServer : public IUnknown {
	public:
	    /**
		 * Returns the server name.
		 */
		virtual HRESULT __stdcall GetName(
			CATUnicodeString& oName) = 0;

		/**
		 * Activates the server, registering it
		 * with object directories if needed.
		 */
		virtual HRESULT __stdcall Activate() = 0;

		/**
		 * Deactivates the server, removing it from
		 * object directories if needed.
		 */
		virtual HRESULT __stdcall Deactivate() = 0;

};

extern "C" const IID IID_CATIScriptServer;

#endif // CATIScriptServer_h
