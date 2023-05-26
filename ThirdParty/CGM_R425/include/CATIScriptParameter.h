#ifndef CATIScriptParameter_h
#define CATIScriptParameter_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATScriptParameterDirection.h"
#include "CATBoolean.h"

/**
 * Interface to represent a scripted function.
 * Author: JDU / DMO
 */

class CATIScriptParameter : public IUnknown {
	public:

		/**
		 * Returns the type of the parameter.
		 */
		virtual HRESULT __stdcall GetType(
			VARTYPE& oType) = 0;

		/**
		 * Returns the type description of the parameter.
		 */
		virtual HRESULT __stdcall GetTypeDescription(
			CATString& oTypeDescription) = 0;

		/**
		 * Returns the name of the parameter.
		 */
		virtual HRESULT __stdcall GetName(
			CATUnicodeString& oName) = 0;

		/**
		 * Retuns the direction of the parameter.
		 */
		virtual HRESULT __stdcall GetDirection(
			CATScriptParameterDirection& oDirection) = 0;

		/**
		 * Returns TRUE if the parameter is the returned value, FALSE otherwise.
		 */
		virtual HRESULT __stdcall IsRetVal(
			CATBoolean & oRetVal) = 0;

};

extern "C" const IID IID_CATIScriptParameter;

#endif
