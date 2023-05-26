
// COPYRIGHT DASSAULT SYSTEMES 2020


#if defined(__ScalarFields)
#define ExportedByScalarFields DSYExport
// To be reactivate when correctly supported all targeted platform
// (ex. Android).
//#define ExportedByScalarFieldsTI template class
#else
#define ExportedByScalarFields DSYImport
// To be reactivate when correctly supported all targeted platform
// (ex. Android).
//#define ExportedByScalarFieldsTI extern template class
#endif
#include "DSYExport.h"
