#ifndef CATThrLibraryManager_h
#define CATThrLibraryManager_h

#if defined(_WINDOWS_SOURCE)
#include <wtypes.h>
#else
#include <dlfcn.h>
#endif

#include "JS0MT.h"  // ExportedByJS0MT
#include "CATDataType.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "CATBoolean.h"
#include "CATSmartMutex.h"


#if defined(_WINDOWS_SOURCE)
typedef HINSTANCE CATThrLibraryType;
#else
typedef void* CATThrLibraryType;
#endif


struct CATThrLibraryHandler
{
   void* EntryPoint;
   CATThrLibraryType Handler;
};


class CATThrLibraryManager
{	
public :

    /**
     * iLibraryName = nom de la librairie contenant le point d'entree
     * EntryName   = nom du point d'entree
     */
    ExportedByJS0MT static CATThrLibraryHandler GetFunctionAddress(
                    const char *iLibraryName,
                    const char *iEntryName);

    ExportedByJS0MT static CATThrLibraryType LoadLibrary(const char *iLibraryName);
};

#endif // CATThrLibraryManager_h
