#ifndef CATBRepMode_h
#define CATBRepMode_h

// COPYRIGHT DASSAULT SYSTEMES 2002
// FCV 05/06/2002

// Activate build time flag of BRep-mode project 
#define BREPMODE

//#ifndef CATIAV5R13
/**
 * @level Protected 
 * @usage U1
 */

#include "AD0XXBAS.h"

ExportedByAD0XXBAS int CATBRepModeActive(void);
//#endif

ExportedByAD0XXBAS int CATLightBRepModeActive(void);


#endif
