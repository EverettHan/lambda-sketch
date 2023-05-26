#ifndef  CATErrorInits_H
#define  CATErrorInits_H

/* COPYRIGHT DASSAULT SYSTEMES 2000 */

#include "JS0ERROR.h"
ExportedByJS0ERROR void CATErrorInstallSigHandler();
/*
 * used to indicate to system that it runs in batch mode
 */
ExportedByJS0ERROR void CATSetBatchMode(int iBMode);
/*
 * returns true if in batch mode
 */
ExportedByJS0ERROR int CATGetBatchMode();

#endif
