// COPYRIGHT DASSAULT SYSTEMES 2007
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************
/**
 * @level Protected
 * @usage U1
 */

#if defined(__TempoDevFlags)
#define ExportedByTempoDevFlags DSYExport
#else
#define ExportedByTempoDevFlags DSYImport
#endif
#include "DSYExport.h"
