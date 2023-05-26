// COPYRIGHT DASSAULT SYSTEMES 2000
/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifdef  __CATProviderItf

#define ExportedByCATProviderItf DSYExport
#else
#define ExportedByCATProviderItf DSYImport
#endif
#include "DSYExport.h"
