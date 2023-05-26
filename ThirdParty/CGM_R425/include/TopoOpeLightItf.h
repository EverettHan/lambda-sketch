#ifdef _STATIC_SOURCE
#define	ExportedByTopoOpeLightItf
#elif defined __TopoOpeLightItf
#define ExportedByTopoOpeLightItf DSYExport
#else
#define ExportedByTopoOpeLightItf DSYImport
#endif
#include "DSYExport.h"
