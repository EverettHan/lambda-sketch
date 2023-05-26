#ifndef TopoOperError_h
#define TopoOperError_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#ifdef _STATIC_SOURCE
#define	ExportedByTopoOperError
#elif defined(__TopoOperError)
#define ExportedByTopoOperError DSYExport
#else
#define ExportedByTopoOperError DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"

#endif
