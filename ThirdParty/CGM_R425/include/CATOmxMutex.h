#ifndef __CATOmxMutex_h__
#define __CATOmxMutex_h__

// BSFBuildtimeData
#include "CATIAV5Level.h"
// ObjectModelerCollection
#include "CATOmxKernel.h"

#define OMX_SYNC_API_SRW       1
#define OMX_SYNC_API_WINLEGACY 2
#define OMX_SYNC_API_PTHREAD   3

#ifdef _WINDOWS_SOURCE

#include <Windows.h>
#if (defined(CATIAV5R26) || defined(CATIAR418))
//Use SWRLOCK and CONDITION_VARIABLE
#define OMX_SYNC_API OMX_SYNC_API_SRW
#else
//Use maybe SWRLOCK and CONDITION_VARIABLE (runtime check), maybe CRITICAL_SECTION and windows Events
#define OMX_SYNC_API OMX_SYNC_API_WINLEGACY
struct pthread_cond_EmulationData;
#endif
//not CONDITION_VARIABLE_LOCKMODE_SHARED
#define OMX_CONDITION_VARIABLE_LOCKMODE_EXCLUSIVE 0

#else //_WINDOWS_SOURCE

#include <pthread.h>
//use pthread
#define OMX_SYNC_API OMX_SYNC_API_PTHREAD

#endif

/**
 * COPYRIGHT DASSAULT SYSTEMES 2013
 * Mock the C++11 API of mutex'es and condition variable
 * It does not respect all specifications
 */
namespace CATOmx 
{

  /** not compliant with C++11 */
  namespace chrono 
  {
    typedef long long int fake_ratio;
    /**
     * Do not use this class directly.
     * Use seconds, milliseconds, microseconds or nanoseconds instead.
     * CATOmx::chrono::seconds(30) create the internal representation of 30 seconds.
     */
    template <typename Rep, fake_ratio Period> class duration 
    {
    public:
      Rep ticks; // do not use this data accurency may change to plateform dependant
      inline duration(Rep x) : ticks(x * Period) {}
    };
    template <typename Rep1, fake_ratio Period1, typename Rep2, fake_ratio Period2 > inline bool operator==(const duration<Rep1,Period1> &o1, const duration<Rep2,Period2> &o2) {return o1.ticks == o2.ticks;}
    template <typename Rep1, fake_ratio Period1, typename Rep2, fake_ratio Period2 > inline bool operator!=(const duration<Rep1,Period1> &o1, const duration<Rep2,Period2> &o2) {return o1.ticks != o2.ticks;}
    template <typename Rep1, fake_ratio Period1, typename Rep2, fake_ratio Period2 > inline bool operator>(const duration<Rep1,Period1> &o1, const duration<Rep2,Period2> &o2)  {return o1.ticks > o2.ticks;}
    template <typename Rep1, fake_ratio Period1, typename Rep2, fake_ratio Period2 > inline bool operator>=(const duration<Rep1,Period1> &o1, const duration<Rep2,Period2> &o2) {return o1.ticks >= o2.ticks;}
    template <typename Rep1, fake_ratio Period1, typename Rep2, fake_ratio Period2 > inline bool operator<(const duration<Rep1,Period1> &o1, const duration<Rep2,Period2> &o2)  {return o1.ticks < o2.ticks;}
    template <typename Rep1, fake_ratio Period1, typename Rep2, fake_ratio Period2 > inline bool operator<=(const duration<Rep1,Period1> &o1, const duration<Rep2,Period2> &o2) {return o1.ticks <= o2.ticks;}
    
    typedef duration<long long int, 1000000000> seconds;
    typedef duration<long long int, 1000000> milliseconds;
    typedef duration<long long int, 1000> microseconds;
    typedef duration<long long int, 1> nanoseconds;  
  }

  
  /** mock C++11 std::unique_lock. */
  template <typename MutexType> class unique_lock 
  {    
    unique_lock(); // delete
    unique_lock(const unique_lock &); // delete 
  public:
    MutexType &mutex;
    inline unique_lock(const MutexType &iMutex) : mutex(const_cast<MutexType&>(iMutex)) { mutex.lock(); }
    inline ~unique_lock() { mutex.unlock(); }
  };

  /** mock C++11 std::lock_guard (same as unique_lock). */
  template <typename MutexType> class lock_guard 
  {
    MutexType &mutex;  
    lock_guard(); // delete
    lock_guard(const lock_guard &); // delete 
  public:
    /* const because of mutable disabled on Solaris (FIXME: why const ?)*/
    inline lock_guard(const MutexType &iMutex): mutex(const_cast<MutexType&>(iMutex)) { mutex.lock(); }
    inline ~lock_guard() { mutex.unlock(); }
  };

  /** mock C++11 std::recursive_mutex. 
   * This recursive_mutex is reentrant.
   */
  class recursive_mutex 
  {
    recursive_mutex(const recursive_mutex &);
  public:
#if OMX_SYNC_API_PTHREAD !=  OMX_SYNC_API
    CRITICAL_SECTION m_mutex;
    inline recursive_mutex()  { InitializeCriticalSection(&m_mutex); }
    inline ~recursive_mutex() { DeleteCriticalSection(&m_mutex); }
    inline void lock()   { EnterCriticalSection(&m_mutex); }
    inline void unlock() { LeaveCriticalSection(&m_mutex); }
#else
    pthread_mutex_t m_mutex;
    inline recursive_mutex() 
    {
      pthread_mutexattr_t attr;
      pthread_mutexattr_init(&attr);
      pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE); 
      pthread_mutex_init(&m_mutex,&attr); 
    }
    inline ~recursive_mutex() { pthread_mutex_destroy(&m_mutex); }
    inline void lock() { pthread_mutex_lock(&m_mutex); }
    inline void unlock() { pthread_mutex_unlock(&m_mutex); }
#endif
  };


  /** mock C++11 std::mutex. 
   * This mutex should not be assumed as recursive.
   */
  class mutex 
  {
    mutex(const mutex &);
  public:
#if OMX_SYNC_API_SRW ==  OMX_SYNC_API
    SRWLOCK m_mutex;
    inline mutex() { InitializeSRWLock(&m_mutex); }
    inline ~mutex() { /**no finaliser !*/ }
    inline void lock() { AcquireSRWLockExclusive(&m_mutex); }
    inline void unlock() { ReleaseSRWLockExclusive(&m_mutex); }
#elif OMX_SYNC_API_WINLEGACY ==  OMX_SYNC_API
    union {
      SRWLOCK m_lock;
      CRITICAL_SECTION *m_critical;
    };
    ExportedByCATOmxKernel mutex();
    ExportedByCATOmxKernel ~mutex();
    ExportedByCATOmxKernel void lock();
    ExportedByCATOmxKernel void unlock();
#else
    pthread_mutex_t m_mutex;
    inline mutex() { pthread_mutex_init(&m_mutex,NULL); }
    inline ~mutex() { pthread_mutex_destroy(&m_mutex); }
    inline void lock() { pthread_mutex_lock(&m_mutex); }
    inline void unlock() { pthread_mutex_unlock(&m_mutex); }
#endif
  };
  
  /** mock C++11 std::shared_mutex. */
  class shared_mutex
#if OMX_SYNC_API_PTHREAD !=  OMX_SYNC_API
    : private mutex
#endif
  {
  public:
#if OMX_SYNC_API_PTHREAD !=  OMX_SYNC_API
    using mutex::lock;
    using mutex::unlock;
#endif
#if OMX_SYNC_API_SRW == OMX_SYNC_API
    inline void shared_lock()   {AcquireSRWLockShared(&m_mutex);}
    inline void shared_unlock() {ReleaseSRWLockShared(&m_mutex);}
#elif OMX_SYNC_API_WINLEGACY == OMX_SYNC_API
    ExportedByCATOmxKernel void shared_lock();
    ExportedByCATOmxKernel void shared_unlock();
#else
    pthread_rwlock_t m_mutex;
    inline shared_mutex()  { pthread_rwlock_init(&m_mutex,NULL); }  
    inline ~shared_mutex() { pthread_rwlock_destroy(&m_mutex); }
    inline void shared_lock()   { pthread_rwlock_rdlock(&m_mutex); }
    inline void shared_unlock() { pthread_rwlock_unlock(&m_mutex); }
    inline void lock()   { pthread_rwlock_wrlock(&m_mutex); }
    inline void unlock() { pthread_rwlock_unlock(&m_mutex); }
#endif
  };

  /** mock C++11 std::shared_lock. */
  template <typename MutexType> class shared_lock 
  {
    MutexType& mutex;
    shared_lock(); // delete
    shared_lock(const shared_lock &); // delete 
    public:
    /* const because of mutable disabled on Solaris */
    inline shared_lock(const MutexType &iMutex) : mutex(const_cast<MutexType&>(iMutex)) { mutex.shared_lock(); }
    inline ~shared_lock() { mutex.shared_unlock(); }
  };

  /** not c++11 compliant, should be an enum class, use only constant values cv_status::no_timeou, cv_status::timeout and not the class name */
  namespace cv_status
  {
    enum _cv_status {no_timeout,timeout};
  };
  /** mock C++11 std::condition_variable. */
  class condition_variable 
  {
    condition_variable(const condition_variable &); // delete
  public:
#if OMX_SYNC_API_SRW == OMX_SYNC_API
    CONDITION_VARIABLE m_condition;
    inline condition_variable() { InitializeConditionVariable(&m_condition); }
    inline ~condition_variable() { /*no finaliser*/ }
    inline void notify_one() { WakeConditionVariable(&m_condition); }
    inline void notify_all() { WakeAllConditionVariable(&m_condition); }
    inline void wait(unique_lock<mutex> &iMutex) { SleepConditionVariableSRW(&m_condition,&iMutex.mutex.m_mutex,INFINITE,OMX_CONDITION_VARIABLE_LOCKMODE_EXCLUSIVE); }
#elif OMX_SYNC_API_WINLEGACY == OMX_SYNC_API
    union
    {
      CONDITION_VARIABLE m_condition;
      struct pthread_cond_EmulationData* m_emulation;
    };
    ExportedByCATOmxKernel condition_variable();
    ExportedByCATOmxKernel ~condition_variable();
    ExportedByCATOmxKernel void notify_one();
    ExportedByCATOmxKernel void notify_all();
    ExportedByCATOmxKernel void wait(unique_lock<mutex> &iMutex);
#else
    pthread_cond_t m_condition;
    inline condition_variable() { pthread_cond_init(&m_condition,NULL); }
    inline ~condition_variable() { pthread_cond_destroy(&m_condition); }
    inline void notify_one() { pthread_cond_signal(&m_condition); }
    inline void notify_all() { pthread_cond_broadcast(&m_condition); }
    inline void wait(unique_lock<mutex> &iMutex) { pthread_cond_wait(&m_condition,&iMutex.mutex.m_mutex); }
#endif

  private:
    ExportedByCATOmxKernel cv_status::_cv_status _wait_for(unique_lock<mutex> &iMutex, long long int iDuration);
  public:
    /** not fully complient to C++11.
     * No return code.
     * iMutex should be a unique_lock<mutex>
     */
    template <class Rep, chrono::fake_ratio Period> inline cv_status::_cv_status wait_for(unique_lock<mutex> &iMutex, const chrono::duration<Rep,Period> &iDuration) { return _wait_for(iMutex,iDuration.ticks); }
  };
}
#endif
