#ifndef CATScriptImplUtilities_h
#define CATScriptImplUtilities_h

// COPYRIGHT DASSAULT SYSTEMES 2002

// System framework
#include "IUnknown.h"
#include "CATBSTR.h"
#include "JS0LOGRP.h"
class CATBaseDispatch;

// InfInterfaces framework
class CATIAApplication;

/**
 * Utility methods used to simplify the implementations of Automation interfaces.
 * @author Jean-Francois Doue (JDU)
 */
class ExportedByJS0LOGRP CATScriptImplUtilities {

	public:
		/**
		 * Implement the get_Application property.
		 */
		static HRESULT __stdcall get_Application(
			CATIAApplication *& oApplication);

		/**
		 * Implement the GetItem CATIVBExtension mechanism.
		 */
		static HRESULT __stdcall GetItem (
			const CATBSTR & iNameBSTR,
			CATBaseUnknown *iTarget,
			CATBaseDispatch *& oObject,
			CATBoolean         iTestIAutomationExtension=FALSE);

};

#endif // CATScriptImplUtilities_h

