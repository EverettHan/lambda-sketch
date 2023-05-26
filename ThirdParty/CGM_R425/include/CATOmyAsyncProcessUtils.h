/**
 * @level Private
 * @usage U1
 */

#ifndef _CATOMYASYNCPROCESSUTILS_H_
#define _CATOMYASYNCPROCESSUTILS_H_

#include "CATLib.h"
#include "CATStdLib.h"
#include "JS0STDLIB.h"

#include "CATAssert.h"
#include "CATSysMacroPtr.h"
#include "CATOMYCuteIO.h"



// ####################################################################################################
// CATSysIsProcessAlive
// ####################################################################################################
// return 1 if alive
// 0 if not
// < 0 for errors
ExportedByCATOMYCuteIO int CATOmySysIsChildProcessAlive(int iPid);
ExportedByCATOMYCuteIO int CATOmySysIsNonChildProcessAlive(int iPid);


#endif
