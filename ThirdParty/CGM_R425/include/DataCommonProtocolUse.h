
#ifndef __DataCommonProtocolUse_h__
#define __DataCommonProtocolUse_h__

// COPYRIGHT DASSAULT SYSTEMES 2009  

/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifdef  __DataCommonProtocolUse

#define ExportedByDataCommonProtocolUse DSYExport
#else
#define ExportedByDataCommonProtocolUse DSYImport
#endif
#include "DSYExport.h"


#endif // __DataCommonProtocolUse_h__
