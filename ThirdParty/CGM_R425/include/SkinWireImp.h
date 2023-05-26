#ifndef SkinWireImp_h
#define SkinWireImp_h

// COPYRIGHT DASSAULT SYSTEMES 2005

#ifdef _STATIC_SOURCE
#define	ExportedBySkinWireImp
#elif defined(__SkinWireImp)
#define ExportedBySkinWireImp DSYExport
#else
#define ExportedBySkinWireImp DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"

#endif
