#ifndef Primitives_h
#define Primitives_h

// COPYRIGHT DASSAULT SYSTEMES 1999
/** @CAA2Required */
/*---------------------------------------------------------------------*/
/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */
/*---------------------------------------------------------------------*/
#ifdef _STATIC_SOURCE
#define	ExportedByPrimitives
#elif defined(__Primitives)
#define ExportedByPrimitives DSYExport
#else
#define ExportedByPrimitives DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
#endif
