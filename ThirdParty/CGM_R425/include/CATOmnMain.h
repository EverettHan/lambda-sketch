// COPYRIGHT DASSAULT SYSTEMES 2008
/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifdef	__CATOmnMain

#define ExportedByCATOmnMain DSYExport
#else
#define ExportedByCATOmnMain DSYImport
#endif
#include "DSYExport.h"

/** @nodoc */
typedef unsigned int CATOMNID_t;
