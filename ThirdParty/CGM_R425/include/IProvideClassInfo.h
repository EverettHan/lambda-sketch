#ifndef IProvideClassInfo_h
#define IProvideClassInfo_h

#ifdef _WINDOWS_SOURCE
#include "ocidl.h"
#else // _WINDOWS_SOURCE

#include "IUnknown.h"
#include "ITypeInfo.h"

interface IProvideClassInfo : public IUnknown
{
	public:
		virtual HRESULT STDMETHODCALLTYPE GetClassInfo(/* [out] */ ITypeInfo ** ppTI) = 0;
    
};


#endif // _WINDOWS_SOURCE

#endif // IProvideClassInfo_h
