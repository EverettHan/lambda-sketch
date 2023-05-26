// COPYRIGHT DASSAULT SYSTEMES 2005
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

/**
* @required 
*/

#if defined(__CATOmbImportExport)
#define ExportedByCATOmbImportExport DSYExport
#else
#define ExportedByCATOmbImportExport DSYImport
#endif
#include "DSYExport.h"
