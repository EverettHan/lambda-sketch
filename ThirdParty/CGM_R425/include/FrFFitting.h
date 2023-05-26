#ifdef _STATIC_SOURCE
#define	ExportedByFrFFitting
#elif defined __FrFFitting
#define ExportedByFrFFitting DSYExport
#else
#define ExportedByFrFFitting DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
