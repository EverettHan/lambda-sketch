#ifndef CATTocLib_H
#define CATTocLib_H

#if defined(__CATTocLib)
#define ExportedByCATTocLib DSYExport
#else
#define ExportedByCATTocLib DSYImport
#endif
#include "DSYExport.h"


#ifdef __cplusplus
extern "C" {
#endif

ExportedByCATTocLib int CATGetInstallSPKLevel ();
ExportedByCATTocLib int CATGetInstallHFXLevel ();
ExportedByCATTocLib char *CATGetInstallGALevel ();

#ifdef __cplusplus
};
#endif

#endif
