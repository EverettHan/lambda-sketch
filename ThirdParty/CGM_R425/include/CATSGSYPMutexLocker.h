#ifndef CATSGSYPMutexLocker_H
#define CATSGSYPMutexLocker_H


// COPYRIGHT DASSAULT SYSTEMES 2010

#include <CATMutex.h>

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsThreading
 * Class provider automatic unlocking of a mutex when exiting a scope.
 *
 * This class is meant to be instantiated on the stack inside a scope.
 *
 * Its constructor will lock the given mutex and its destructor will
 * unlock it.
 *
 * @par Example
 * @code
 * void MyClass::f() {
 *    ...
 *    {
 *      CATSGSYPMutexLocker locker(_mutex); // lock the mutex
 *      ...
 *      << in this scope the mutex _mutex is locked >>
 *      ...
 *      
 *    } // the mutex is unlocked when getting out of the scope
 *    ...
 *    << in this scope the mutex _mutex is NOT locked >>
 *    ...
 * }
 * @endcode
 */
class CATSGSYPMutexLocker
{
public:
  /**
   * Lock the mutex.
   *
   * @param i_mutex the mutex to lock. A reference to the mutex
   * will be kept in this class so this mutex must not be destroyed
   * until this object is destroyed
   */
  CATSGSYPMutexLocker(CATMutex &i_mutex) : _mutex(i_mutex) {
    _mutex.Lock();
  }

  /**
   * Unlock the mutex.
   */
  ~CATSGSYPMutexLocker() {
    _mutex.Unlock();
  }
private:
  CATSGSYPMutexLocker(const CATSGSYPMutexLocker &);
  CATSGSYPMutexLocker &operator=(const CATSGSYPMutexLocker &);
private:
  /** The locked mutex to be unlocked when this object is destroyed */
  CATMutex &_mutex;
};

#endif // CATSGSYPMutexLocker_H

