#ifdef _STATIC_SOURCE
#define	ExportedByHLRModele
#elif defined __HLRModele
#define ExportedByHLRModele DSYExport
#else
#define ExportedByHLRModele DSYImport
#endif
#include "DSYExport.h"
