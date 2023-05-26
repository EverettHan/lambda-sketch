#ifndef TopoOperModel_h
#define TopoOperModel_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#ifdef _STATIC_SOURCE
#define	ExportedByTopoOperModel
#elif defined(__TopoOperModel)
#define ExportedByTopoOperModel DSYExport
#else
#define ExportedByTopoOperModel DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"

#endif
