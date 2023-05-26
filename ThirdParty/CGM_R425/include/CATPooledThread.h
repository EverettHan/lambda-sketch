#ifndef CATPooledThread_H
#define CATPooledThread_H

// COPYRIGHT Dassault Systemes 2003
//===================================================================
//  April 2003  Creation: sbp
//===================================================================

#include "CATThreads.h"
#include "CATWaitingPoint.h"
#include "SGInfra.h"

class CATThreadBehaviour;
class CATThreadPool;


void ExportedBySGInfra RunFunctionInThread();


class ExportedBySGInfra CATPooledThread : public CATThreads
{
public:
  
  CATPooledThread(const char *name,CATThreadPool* pool);
  virtual ~CATPooledThread();

  // Interface:
  //////////////////////////////////

  void SetBehaviour(CATThreadBehaviour*);
  void SetAutoReleaseMode(int mode); // automatically goes back to the pool when done

  void WaitForEndOfTask();
  void Start();
  void Stop();

  float GetTaskTime() { return _taskTime; }

  void SetWaitingPoint(CATWaitingPoint*); // will be broadcasted when behaviour done
  //////////////////////////////////

  CATThreadsReturnCode Begin(void *iArg);

private:

  CATPooledThread(CATPooledThread&);
  CATPooledThread& operator=(CATPooledThread&);

  CATThreadBehaviour*     _behaviour;

  CATWaitingPoint*        _start;
  CATWaitingPoint*        _stop;
  CATWaitingPoint*        _end;
  //CATWaitingPoint*        _destroyed;

  int                     _thread_continue();

  CATMutex                _contmutex;
  int                     _continue;
  float                   _taskTime;

  int                     _autoReleaseMode;

  CATThreadPool*           _pool;            

  int _test;

};
#endif 
  
