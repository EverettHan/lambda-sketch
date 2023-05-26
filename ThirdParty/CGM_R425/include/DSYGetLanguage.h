// COPYRIGHT DASSAULT SYSTEMES 2016

#ifndef DSYGETLANG_H
#define DSYGETLANG_H

// @deprecated header => include CATNLSUtilities.h instead!
#include "CATUnicodeString.h"
#include "CATNLSUtilities.h"    // DSYGetUILocaleNameForHttp

#include <string.h> // strncpy

inline HRESULT DSYGetLanguage (char *& oBuff)
{
    oBuff = NULL;
    CATUnicodeString szLocaleName;
    HRESULT hr = DSYGetUILocaleNameForHttp(szLocaleName);
    if(SUCCEEDED(hr))
    {
        int count = szLocaleName.GetLengthInByte()+1;
        oBuff = new char[count];
        if(oBuff)
            strncpy(oBuff, szLocaleName.ConvertToChar(), count);
        else
            hr = E_OUTOFMEMORY;
    }
    return hr;
}

#endif  // DSYGETLANG_H
