#ifndef CATIAREGISTRATION_INCLUDE
#define CATIAREGISTRATION_INCLUDE


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0CATREG.h"
#include "CATBoolean.h"
#include "CATIAV5Level.h"
#include "CATScriptCodeMacro.h"

//
// Register/Unregister CATIA for OLE
//
// returns   0      if failed
//         non 0    if success
//

//
// CATIARegister: register CATIA using the given path
//
// - dontCheckFlag: 0     only register if what's in the register
//                        is out of date
//                  not 0 always register
//
// - serverPath:    executable path. If NULL the path to the running executable
//                  will be used
//
// - iProductLine: CATIA, ENOVIA_DMU_Navigator, ENOVIA_LCA, DELMIA, ENOVIA_3d_com

ExportedByJS0CATREG int CATIARegister (int dontCheckFlag = 0, const char *serverPath = (char *) 0);

ExportedByJS0CATREG int CATIARegisterEx (const char * iEnv, const char * iDirenv, int dontCheckFlag = 0, const char *serverPath = (char *) 0, const char *iProductLine = "CATIA");
//
// CATIAUnregister: remove the keys installed by CATIARegister
//
ExportedByJS0CATREG int CATIAUnregister ();

//
// CATIAUnregisterTypeLibs: unregister typelibs in a given directory
//
//ExportedByJS0CATREG void CATIAUnregisterTypeLibs (const char *dirpath);

#if defined (_DS_VBAIntegrationIsOutProcess) || defined (VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS)
// Do not use
ExportedByJS0CATREG int VBAHostingRegisterInHKCU();
ExportedByJS0CATREG int VBAHostingUnregisterFromHKCU();
#endif 

// Do not use
ExportedByJS0CATREG CATBoolean CanRegisteringInHKCU();
ExportedByJS0CATREG CATBoolean MustRegisteringInHKCU();

#endif
