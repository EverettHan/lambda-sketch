/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************
#ifdef  __CATOmbLifeCycle

#define ExportedByCATOmbLifeCycle DSYExport
#else
#define ExportedByCATOmbLifeCycle DSYImport
#endif
#include "DSYExport.h"
