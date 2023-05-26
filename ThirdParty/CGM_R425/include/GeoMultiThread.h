// COPYRIGHT DASSAULT SYSTEMES 2022

#ifdef _STATIC_SOURCE
#define	ExportedByGeoMultiThread
#elif defined __GeoMultiThread
#define ExportedByGeoMultiThread DSYExport
#else
#define ExportedByGeoMultiThread DSYImport
#endif
#include "DSYExport.h"
#include <GeometricOperatorsCommonDec.h>
