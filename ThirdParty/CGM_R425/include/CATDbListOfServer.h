// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef _CATDbListOfServer_h
#define _CATDbListOfServer_h

#if defined(__CATSysDbSettings)
#define ExportedByCATSysDbSettings DSYExport
#else
#define ExportedByCATSysDbSettings DSYImport
#endif
#include "DSYExport.h"

#include "CATDbServer.h"
#include <CATLISTP_Clean.h>

#define CATLISTP_Append
#define CATLISTP_ApplyDelete
#define CATLISTP_Swap
#define CATLISTP_InsertAt
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll

#include <CATLISTP_Declare.h>


#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedByCATSysDbSettings

CATLISTP_DECLARE( CATDbServer )

typedef CATLISTP(CATDbServer) CATDbServerColl; 

#define CATDbListOfServer  CATLISTP(CATDbServer)
#define CATDbListOfServerH CATLISTP(CATDbServer)*

#endif  // CATDbListOfServer_h
