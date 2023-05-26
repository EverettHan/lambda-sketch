#ifndef DSYINSLISTINSTALLS_PROTECTEDINTERFACES_DSYINSLISTINSTALLSAPIMODULE_H_

// COPYRIGHT Dassault Systemes 2022

#include "DSYExport.h"

#if defined __DSYInsListInstallsAPI
  #define ExportedByDSYInsListInstallsAPI DSYExport
#else
  #define ExportedByDSYInsListInstallsAPI DSYImport
#endif // __DSYInsListInstallsAPI

#endif // DSYINSLISTINSTALLS_PROTECTEDINTERFACES_DSYINSLISTINSTALLSAPIMODULE_H_
