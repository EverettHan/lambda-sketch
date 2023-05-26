#ifndef CATScriptEnvironment_h
#define CATScriptEnvironment_h

// AutomationInterfaces framework
#include "AutomationItf.h"

// System framework
#include "CATUnicodeString.h"
#include "CATBoolean.h"

/**
 * Class to access and position various environment variables.
 * @author Jean-Francois Doue (JDU)
 */
class ExportedByCATAutoItf CATScriptEnvironment {
	public:
		/**
		 * Returns the path concatenation character: ";" or ":"
		 */
		static CATUnicodeString GetSeparator();

		/**
		 * Returns the directory separator: "/" or "\"
		 */
		static CATUnicodeString GetSlash();

		/**
		 * Returns the os variable: solaris_a, intel_a ...
		 */
		static CATUnicodeString GetOs();

		/**
		 * Returns the PATH environment variable.
		 */
		static CATUnicodeString GetPath();

		/**
		 * Returns the current working directory.
		 */
		static CATUnicodeString GetWorkingDirectory();

		/**
		 * Returns the contents of the shared library path environment variable.
		 */
		static CATUnicodeString GetLibraryPath();

		/**
		 * Returns the name of the shared library path environment variable.
		 */
		static CATUnicodeString GetLibraryPathName();

		/**
		 * The CAT_SCRIPT_SKIP_OLD_DOCUMENTS can be used
		 * to prevent a CD when reading on a Y-endian machine a document
		 * which contains macros recorded with the old infrastructure on 
		 * a X-endian machine.
		 */
		static CATBoolean GetSkipOldDocuments();
};

#endif // CATScriptEnvironment_h


