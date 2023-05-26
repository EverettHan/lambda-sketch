#ifndef IProvideClassInfo2_h
#define IProvideClassInfo2_h

#ifdef _WINDOWS_SOURCE
#include "ocidl.h"
#else // _WINDOWS_SOURCE

#include "IProvideClassInfo.h"

interface IProvideClassInfo2 : public IProvideClassInfo
{
	public:
		virtual HRESULT STDMETHODCALLTYPE GetGUID( 
				/* [in] */ DWORD dwGuidKind,
				/* [out] */ GUID * pGUID) = 0;
};


#endif // _WINDOWS_SOURCE

#endif // IProvideClassInfo2_h
