#ifdef _STATIC_SOURCE
#define ExportedByPowerFrFOperators
#elif defined __PowerFrFOperators
#define ExportedByPowerFrFOperators DSYExport
#else
#define ExportedByPowerFrFOperators DSYImport
#endif
#include "DSYExport.h"
#include<FrFCommonDec.h>
