/**
 * @level Private
 * @usage U1
 */
#if defined(__CATOme)
#define ExportedByCATOme DSYExport
#else
#define ExportedByCATOme DSYImport
#endif
#include "DSYExport.h"
