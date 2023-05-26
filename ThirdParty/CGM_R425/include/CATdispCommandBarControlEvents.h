#ifndef CATdispCommandBarControlEvents_h
#define CATdispCommandBarControlEvents_h

#include "CATVBACodeMacro.h"
#if defined(_WINDOWS_SOURCE) && (!defined(_DS_VBAIntegrationIsOutProcess))

#include "IDispatch.h"

class CATdispCommandBarControlEvents : public IDispatch {
	public:

    // CATdispCommandBarControlEvents methods
    virtual void __stdcall Click(
		IDispatch* CommandBarControl,
		VARIANT_BOOL* handled,
		VARIANT_BOOL* CancelDefault) = 0;
};

extern "C" const IID IID_CATdispCommandBarControlEvents;

#endif // defined(_WINDOWS_SOURCE) && (!defined(_DS_PLATEFORME_64))

#endif // CATdispCommandBarControlEvents_h

