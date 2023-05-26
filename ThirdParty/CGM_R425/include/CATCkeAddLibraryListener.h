#ifndef CATCkeAddLibraryListener_H
#define CATCkeAddLibraryListener_H

#include "CATLifDictionary.h"

#include "CATSysErrorDef.h"

class CATBaseUnknown_var;
class CATUnicodeString;

class ExportedByCATLifDictionary CATCkeAddLibraryListener {
public:
	virtual void BeginAddLibrary(const char * iLibraryName) = 0;
	virtual void EndAddLibrary(const char * iLibraryName) = 0;
	virtual HRESULT GetLibraryFromObject(const CATBaseUnknown_var& iTypeOrFct, CATUnicodeString& oLibrary) = 0;
};

extern "C" ExportedByCATLifDictionary void SetAddLibraryListener(CATCkeAddLibraryListener * ipListener);
extern "C" ExportedByCATLifDictionary CATCkeAddLibraryListener * GetAddLibraryListener();

#endif
