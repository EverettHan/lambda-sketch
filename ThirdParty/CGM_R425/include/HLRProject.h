#ifdef _STATIC_SOURCE
#define	ExportedByHLRProject
#elif defined __HLRProject
#define ExportedByHLRProject DSYExport
#else
#define ExportedByHLRProject DSYImport
#endif
#include "DSYExport.h"
