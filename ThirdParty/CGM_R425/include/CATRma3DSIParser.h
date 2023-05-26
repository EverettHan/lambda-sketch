#pragma once

#include <DSYExport.h>

#if defined (__CATRma3DSIParser)
#define ExportedByCATRma3DSIParser DSYExport
#else
#define ExportedByCATRma3DSIParser DSYImport
#endif
