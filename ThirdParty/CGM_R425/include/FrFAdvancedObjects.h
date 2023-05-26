#ifdef _STATIC_SOURCE
#define	ExportedByFrFAdvancedObjects
#elif defined __FrFAdvancedObjects


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */

//**********************************************************************

//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *

//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *

//**********************************************************************
#define ExportedByFrFAdvancedObjects DSYExport
#else
#define ExportedByFrFAdvancedObjects DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
