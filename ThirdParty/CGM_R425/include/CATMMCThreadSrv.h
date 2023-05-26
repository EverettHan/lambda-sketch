#ifndef CATMMCTHREADSRV_H
#define CATMMCTHREADSRV_H

#include "CATMMediaCore2.h"

#include "CATThreads.h"

#define MAX_THREADS_PER_INSTANCE 10

class ExportedByCATMMediaCore2 CATMMCThreadSrv
{
public:
  static CATThreadsId GetMainThreadId();
  static bool CheckNotMainThreadNoMutex();
  static bool CheckNotMainThread(); //Pb, cette methode a son propre mutex, et non celui de son client...
  static bool CheckConcurrentUse(CATThreadsId& ioThreadIdLog); // By 2 differents threads. Pb, cette methode a son propre mutex, et non celui de son client...
};

#endif
