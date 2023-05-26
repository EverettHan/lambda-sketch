#ifndef CATVBADebugUtilities_h
#define CATVBADebugUtilities_h

#ifdef _WINDOWS_SOURCE

// VBA Framework
#include "VbaAfx.h"
#include "CATVBAInfra.h"

/**
 * Class used to help debugging VBA integration.
 */
class ExportedByCATVBAInfra CATVBADebugUtilities {

	public:

		/**
		 * Prints the given message in the debugger output.
		 */
		static void OutputDebugString(LPCTSTR lpszFormat, ...);

};

#endif // _WINDOWS_SOURCE

#endif // CATVBADebugUtilities_h
