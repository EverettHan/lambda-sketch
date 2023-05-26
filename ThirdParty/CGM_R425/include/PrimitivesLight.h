#ifndef PrimitivesLight_h
#define PrimitivesLight_h

// COPYRIGHT DASSAULT SYSTEMES 2010

/** @CAA2Required */
/*---------------------------------------------------------------------*/
/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */
/*---------------------------------------------------------------------*/
#ifdef _STATIC_SOURCE
#define	ExportedByPrimitivesLight
#elif defined(__PrimitivesLight)
#define ExportedByPrimitivesLight DSYExport
#else
#define ExportedByPrimitivesLight DSYImport
#endif
#include "DSYExport.h"
//#include "TopologicalOperatorsLightCommonDec.h"
#endif

