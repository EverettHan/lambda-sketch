// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// CATCDSThreadManager:
//   class for thread management, needed for parallel CDS
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Apr 2005  Creation                         Nikolay Snytnikovint
//=============================================================================

#ifndef CATCDSThreadManager_H
#define CATCDSThreadManager_H

#include "CATCDSUtilities.h"

class CATCDSThread;

class ExportedByCATCDSUtilities CATCDSThreadManager
{
public:
  static int MultiRun(CATCDSThread** ioaThreads, int iThreadsNb);
  static int ParallelRun(CATCDSThread** ioaThreads, int iThreadsNb, void **oaThreadHandles);
  static int GetProcessorsNumber();
  static unsigned int GetThreadId();
  static int GetThreadOrdinalId();
};

#endif
