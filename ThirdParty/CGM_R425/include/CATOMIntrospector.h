#ifndef CATOMIntrospector_H
#define CATOMIntrospector_H

// COPYRIGHT DASSAULT SYSTEMES 2011

#include "JS0CORBA.h"
#include "CATBaseUnknown.h"
#include "CATVariant.h"
#include "CATSysSimpleHashTable.h"
#include "IntrospectionUtils.h"



class ExportedByJS0CORBA CATOMIntrospector 
{
	public:
	
		/*
		* Returns S_OK if the method has been invoked on iObject. Returns E_FAIL otherwise
		* oInvocationResult is the return code of the method that was invoked.
		*/
		static HRESULT Invoke(CATBaseUnknown * iObject, const char * iFunctionName, CATVariant iArgs[], int iNbArgs, HRESULT &oInvocationResult);
		
		/* 
		* Returns S_OK when iMethodName is found in the interface  of iObj or one of its ancestor classes
		* Returns E_FAIL otherwise or if there was a problem fetching the introspection library for the object interface.
		*/
		static HRESULT  FindMethod(CATBaseUnknown * iObj, const char * iMethodName);
		/*
		* Returns S_OK and fills oTypes and oDirections with the argument types and directions found for the provided method name. oNbArgs is the number of arguments of the methods 
		* and can be used as a size for arrays oTypes and oDirections.
		* Returns E_FAIL if the method could not be found or the was a problem fetching the introspection library for the object interface.
		*/
		static HRESULT GetMethodArguments(CATBaseUnknown * iObj, const char * iMethodName,int & oNbArgs ,VARTYPE  *&oTypes, Direction *& oDirections);
		
};
#endif
