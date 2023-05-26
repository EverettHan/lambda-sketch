#ifndef CATHLRLockableThread_h
#define CATHLRLockableThread_h

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "CATThreads.h"
#include "CATMutex.h"

#include "HLRTools.h"
#include "CATHLRObjectLinker.h"

class ExportedByHLRTools CATHLRLockableThread : public CATThreads 
{
public:
  CATHLRLockableThread (const char *iThreadName=NULL,
                     void       *iArg=NULL,
                     int   iJoinable=-1,
                     int   iInterface=0);
  ~CATHLRLockableThread();
  
  static void Lock();
  static void Unlock();
  static int IsThreadLockable(CATThreads * iThread);
  
protected:
  // static CATMutex LockableThreadsMutex;
  // static CATHLRObjectLinker LockableThreadsTable;
};

#endif

