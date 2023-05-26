// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfMutex.h
//
//===================================================================
//
// Usage notes:
// Abstract class defining a mutex (Lock and Unlock) and
// providing two implementations: one actual based on CATMutex
// and one doing nothing (to be used for monothread code).
//
//===================================================================
//
// Feb 2010 Creation: JS9
//===================================================================

#ifndef CATPolyInterfMutex_h
#define CATPolyInterfMutex_h

#include "CATPolyBoundingVolumeOperators.h"
#include "CATBoolean.h"

class CATMutex;

class ExportedByCATPolyBoundingVolumeOperators CATPolyInterfMutex
{
public:

  virtual ~CATPolyInterfMutex() {}

  /**
   * Lock the mutex.
   */
  virtual void Lock() = 0;

  /**
   * Unlock it.
   */
  virtual void Unlock() = 0;

  /**
   * Force the current thread to stop.
   * Mutex must be locked when calling to this function.
   * @return E_FAIL if the mutex was not lock prior calling this function.
   *         S_OK otherwise.
   */
  virtual void Wait() = 0;

  /**
   * Awake all the threads that have been stopped.
   * Mutex must be locked when calling to this function.
   * @return E_FAIL if the mutex was not lock prior calling this function.
   *         S_OK otherwise.
   */
  virtual void NotifyAll() = 0;

  /**
   * @return a pointer on the actual mutex used to lock the data if any,
   *         NULL otherwise.
   */
  virtual CATMutex * GetActualMutex() = 0;


  virtual CATBoolean TryLock() = 0;

  /**
   * Create an instance of CATPolyInterfMutex based on CATMutex.
   * To be used in multi threaded code.
   */
  static CATPolyInterfMutex * GetMultiThreadMutex();

  /**
   * Create an instance of CATPolyInterfMutex which functions does actually nothing.
   * To be used in single threaded code.
   */
  static CATPolyInterfMutex * GetIdleMutex();

  virtual CATBoolean IsIdle() = 0;

protected:

  CATPolyInterfMutex() {}

};

#endif /* CATPolyInterfMutex_h */
