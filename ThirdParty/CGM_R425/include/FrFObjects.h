#ifdef _STATIC_SOURCE
#define	ExportedByFrFObjects
#elif defined __FrFObjects


// COPYRIGHT DASSAULT SYSTEMES 1999

/** @CAA2Required */

//**********************************************************************

//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *

//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *

//**********************************************************************
#define ExportedByFrFObjects DSYExport
#else
#define ExportedByFrFObjects DSYImport
#endif
#include "DSYExport.h"
#include <FrFCommonDec.h>
