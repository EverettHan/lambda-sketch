
#if defined(__VisPrivateServices)
  #define ExportedByVisPrivateServices DSYExport
#else
  #define ExportedByVisPrivateServices DSYImport
#endif
#include "DSYExport.h"
