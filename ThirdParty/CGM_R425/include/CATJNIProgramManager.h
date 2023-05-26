#ifndef CATJNIProgramManager_h
#define CATJNIProgramManager_h

// COPYRIGHT DASSAULT SYSTEMES 2001

// System framework
#include "CATUnicodeString.h"

// CATJavaBridge framework
#include "CATJNIBridge.h"

// AutomationInterfaces framework
#include "CATScriptError.h"

/**
 * Class to invoke the java infrastructure which manages the java source code.
 * @author: Jean-Francois Doue (JDU) - David Morisot (DMO)
 */
class CATJNIProgramManager {
	public:
		CATJNIProgramManager();
		~CATJNIProgramManager();
		static HRESULT CreateProgram(
			const CATUnicodeString& iRootDirectoryName,
			CATBoolean iIsTemporaryProgram,
			const CATUnicodeString& iDefaultProgramName,
			const CATUnicodeString& iProgramText,
			CATUnicodeString& oJavaClassName,
			CATScriptError *& oError);
};

extern "C" {
	HRESULT ExportedByCATJNIBridge CreateJNIProgram(
		const CATUnicodeString& iRootDirectoryName,
		CATBoolean iIsTemporaryProgram,
		const CATUnicodeString& iDefaultProgramName,
		const CATUnicodeString& iProgramText,
		CATUnicodeString& oJavaClassName,
		CATScriptError *& oError);
}


#endif // CATJNIProgramManager_h
