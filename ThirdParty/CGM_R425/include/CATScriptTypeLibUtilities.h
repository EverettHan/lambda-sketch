#ifndef CATScriptTypeLibUtilities_h
#define CATScriptTypeLibUtilities_h

// COPYRIGHT DASSAULT SYSTEMES 2002

#ifdef _WINDOWS_SOURCE
#include <oaidl.h> 
#else // _WINDOWS_SOURCE
#include "CATMainwin.h"
#endif // _WINDOWS_SOURCE

#include "CATUnicodeString.h"
#include "CATString.h"
#include "CATBoolean.h"
#include "CATScriptParameterDirection.h"
#include "JS0LOGRP.h"

/**
 * Utility function to simplify the use of the ITypeInfo and
 * ITypeLib interfaces.
 * @author: Jean-Francois Doue (JDU)
 */
class ExportedByJS0LOGRP CATScriptTypeLibUtilities {
	public:

		/**
		 * Retrieve the declared type for the return parameter for the specified function and the
		 * the specified interface (in will be unique in Automation since
		 * methods cannot have differing signatures -- aside from properties).
		 * The method fails if the function has not retval parameter of if
		 * its type cannot be determined.
		 * @param iInterfaceName
		 * The interface name
		 * @param iFunctionName
		 * The function name
		 * @param oTypeName
		 * The declared type.
		 */
		static HRESULT RetrieveReturnParameterType(
			const CATUnicodeString& iInterfaceName,
			const CATUnicodeString& iFunctionName,
			CATUnicodeString& oTypeName);

		/**
		 * Determines if the interface represented by iItfName is either the same as, 
		 * or is a superinterface of, the interface represented by iItfParentName. 
		 */
		static CATBoolean IsKindOf(
			const CATUnicodeString& iItfName, 
			const CATUnicodeString& iItfParentName);

		/**
		 * Retrieves the typeinfo associated with the
		 * specified name by looking it up in all the typelibs
		 * known to the system.
		 */
		static HRESULT RetrieveTypeInfo(
			const CATUnicodeString& iName, 
			ITypeInfo*& oTypeInfo);

		/**
		 * Returns the name of the supplied function.
		 */
		static void FuncNameFromFuncDesc(
			ITypeInfo *iTypeInfo, 
			FUNCDESC *iFdesc, 
			CATUnicodeString &oName);
		/**
		 * Returns the name of the supplied interface.
		 */
		static void InterfaceNameFromTypeInfo(
			ITypeInfo *iTypeInfo, 
			CATUnicodeString &oName);

		/**
		 * Returns the interface which is pointed to by the supplied alias. 
		 */
		static ITypeInfo* InterfaceFromAlias(
			ITypeInfo *iTypeInfo);

		/**
		 * Returns the alias corresponding to the supplied interface. 
		 */
		static ITypeInfo* AliasFromInterface(
			ITypeInfo *iTypeInfo);

		/** 
		 * Returns the return interface of the supplied element 
		 * (or NULL if the element is not of interface type).
		 */
		static ITypeInfo* InterfaceFromElemDesc(
			ITypeInfo *iTypeInfo, 
			ELEMDESC *iEdesc);

		/**
		 * Retrieves the return parameter of the function. 
		 */
		static ITypeInfo* GetReturnInterfaceForFuncDesc(
			ITypeInfo *iTypeInfo, 
			FUNCDESC *iFdesc);

		/**
		 * Retrieves the ancestor of an interface is the interface 
		 * inheritance hierarchy. 
		 */
		static ITypeInfo* GetAncestor(
			ITypeInfo *iTypeInfo);

		/**
		 * Retrieves the TYPEKIND of the typinfo
		 */
		static TYPEKIND GetTypeInfoKind(
			ITypeInfo *iTypeInfo);

		/**
		 * Retrieves the number of functions declared in
		 * an interface.
		 */
		static long GetTypeInfoMethodCount(
			ITypeInfo *iTypeInfo);

		/**
		 * Retrieves the typeinfo associated with the
		 * specified GUID by looking it up in all the typelibs
		 * known to the system.
		 */
		static HRESULT RetrieveTypeInfo(
			const GUID& iGUID, 
			ITypeInfo*& oTypeInfo);


		/**
		 * Returns the marshalling direction of a function parameter.
		 */
		static HRESULT __stdcall GetParamDirection(
			ELEMDESC *iEdesc,
			CATScriptParameterDirection& oDirection,
			CATBoolean& oIsRetVal);

		/**
		 * Returns the type of a function parameter.
		 */
		static HRESULT __stdcall GetParamType(
			ITypeInfo *iTypeInfo,
			TYPEDESC *iTypeDesc,
			VARTYPE& oType);

		/**
		 * Returns a human readable description of the TYPEDESC.
		 */
		static HRESULT __stdcall TypedescToString(
			ITypeInfo* pti, 
			TYPEDESC* ptdesc, 
			CATString& ioDescription);

		/**
		 * Returns a human readable description of the VARTYPE.
		 */
		static HRESULT __stdcall VartypeToString(
			VARTYPE vt, 
			CATString& ioDescription);

		/**
		 * Retrieves the FUNCDESC and typeinfo which correspond
		 * to the method index as defined in the tie V5 classes.
		 */
		static HRESULT RetrieveFunctionByMethodIndex(
			ITypeInfo* iTypeInfo,
			long iMethodIndex,
			ITypeInfo*& oMethodTypeInfo,
			FUNCDESC*& oFuncDesc);

		/**
		 * Retrieve the TKIND_INTERFACE typeinfo associated with
		 * the TKIND_DISPATCH typeinfo
		 */
		static HRESULT DispInterfaceToInterface(
			ITypeInfo* iTypeInfo,
			ITypeInfo*& oTypeInfo);

		/**
		 * Registers all the V5 typelibs found in the runtime view
		 * with the Windows registry. A V5 typelib is a typelib which
		 * has been built with the V5 IDL compiler
		 */
		static HRESULT RegisterTypeLibs();

		/**
		 * Unregisters all the V5 typelibs found in the runtime view
		 * from the Windows registry. A V5 typelib is a typelib which
		 * has been built with the V5 IDL compiler
		 */
		static HRESULT UnRegisterTypeLibs();

		/**
		 * Returns the number of V5 typelibs in the runtime view
		 */
		static HRESULT RetrieveTypeLibCount(
			unsigned int& oCount);

		/**
		 * Returns the iIndex-th typelib in the runtime view
		 */
		static HRESULT RetrieveTypeLib(
			const unsigned int iIndex, 
			ITypeLib*& oTypeLib);

		/**
		 * Returns the typelib corresponding to the given framework name
		 */
		static HRESULT RetrieveTypeLib(
			const CATString& iFrameworkName, 
			ITypeLib*& oTypeLib,
			CATUnicodeString& oTypeLibName);

		/**
		 * Retrieve the FUNCDESC for the specified function and the
		 * the specified interface (in will be unique in Automation since
		 * methods cannot have differing signatures -- aside from properties).
		 * @param iInterfaceName
		 * The interface name
		 * @param iFunctionName
		 * The function name
		 * @param oTypeInfo
		 * The typeinfo of the interface which owns the FUNCDESC, or NULL if
		 * no matching FUNCDESC was found. The typeinfo must be released.
		 * @param oFuncDesc
		 * The matching FUNCDESC, or NULL if no matching FUNCDESC was found. 
		 * FUNCDESC must be released.
		 */
		static HRESULT RetrieveFunction(
			const CATUnicodeString& iInterfaceName,
			const CATUnicodeString& iFunctionName,
			ITypeInfo*& oTypeInfo,
			FUNCDESC*& oFuncDesc);

		/**
		 * Retrieve the fully qualified name of the iParameterValue enum value which is
		 * passed as the iParameterIndex-th parameter to the function
		 * iFunctionName of the interface iInterfaceName. If the iParameterIndex-th parameter
		 * is simply of type int, the function returns E_FAIL.
		 * @param iInterfaceName
		 * The interface name
		 * @param iFunctionName
		 * The function name
		 * @param iParameterIndex
		 * The parameter index in the function
		 * @param iParameterValue
		 * The parameter value
		 * @param oEnumName
		 * The name of the enum
		 * @param oLabelName
		 * The symbolic value of the enum
		 */
		static HRESULT GetEnumInfoForParameter(
			const CATUnicodeString& iInterfaceName,
			const CATUnicodeString& iFunctionName,
			unsigned int iParameterIndex,
			unsigned int iParameterValue,
			CATUnicodeString& oEnumName,
			CATUnicodeString& oLabelName,
			CATUnicodeString& oTypeLibName);


		static HRESULT __stdcall GetEnumInfoForParameter(
			ITypeInfo *iTypeInfo,
			TYPEDESC *iTypeDesc,
			unsigned int iParameterValue,
			CATUnicodeString& oEnumName,
			CATUnicodeString& oLabelName);

};

#endif // CATScriptTypeLibUtilities_h

