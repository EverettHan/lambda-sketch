#pragma once

#include <DSYExport.h>

#if defined (__CATRmaMappingLib)
#define ExportedByCATRmaMappingLib DSYExport
#else
#define ExportedByCATRmaMappingLib DSYImport
#endif
