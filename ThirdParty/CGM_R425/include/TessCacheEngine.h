#ifndef TessCacheEngine_h
#define TessCacheEngine_h

#ifdef _STATIC_SOURCE
#define	ExportedByTessCacheEngine
#elif defined __TessCacheEngine
#define ExportedByTessCacheEngine DSYExport
#else
#define ExportedByTessCacheEngine DSYImport
#endif
#include "DSYExport.h"

#endif
