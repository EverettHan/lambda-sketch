#ifndef CATIScriptIDispatchIntrospector_h
#define CATIScriptIDispatchIntrospector_h

// COPYRIGHT DASSAULT SYSTEMES 2003

// System framework
#include "IUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "JS0DSPA.h"

class CATBaseDispatch;

/**
 * Interface used to invoke methods on an Automation object by introspection.
 *
 * Author: David Morisot (DMO)
 */
class CATIScriptIDispatchIntrospector : public IUnknown {
	public:

		/**
		 * Invokes the methods of iObject defined by the given patterns.
		 * The methods corresponding to at least one of the patterns will be invoked
		 * with default valued parameters.
		 */
		virtual HRESULT InvokeObjectMethods(
			CATBaseDispatch* iObject,
			const CATListOfCATUnicodeString& iMethodsPatterns) = 0;

		/**
		 * Same as InvokeObjectMethods, except that a list of method names
		 * not to invoke can be passed.
		 */
		virtual HRESULT InvokeObjectMethodsEx(
			CATBaseDispatch* iObject,
			const CATListOfCATUnicodeString& iMethodsPatterns,
			const CATListOfCATUnicodeString& iExcludedMethodNames) = 0;

};

/**
 * Give access to a <tt>CATIScriptIDispatchIntrospector</tt> object.
 */
HRESULT ExportedByJS0DSPA GetScriptIDispatchIntrospector(CATIScriptIDispatchIntrospector*& oIntrospector);

extern "C" const IID IID_CATIScriptIDispatchIntrospector;


#endif // CATIScriptIDispatchIntrospector_h

