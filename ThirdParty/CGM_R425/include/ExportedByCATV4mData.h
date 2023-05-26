/**
* @level Private 
* @usage U1
*/
#include "DSYExport.h"
#if defined(__CATV4mData)
#define ExportedByCATV4mData DSYExport
#else
#define ExportedByCATV4mData DSYImport
#endif

