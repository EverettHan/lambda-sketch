/**
@file

This file defines the vkMutex class and some
tools to manipulate mutexes.

@COPYRIGHT

@author Nicolas Hognon
*/

#if !defined(__vkMutex_h)
#define __vkMutex_h

#if !defined(__vkKernelDefines_h)
	#include "vkKernelDefines.h"
#endif

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif

#if defined(VK_API_POSIX)
	#include <pthread.h>
#endif

#if defined(VK_TARGET_MACOSX) || defined(VK_TARGET_IPHONE)
	#include <libkern/OSAtomic.h>
#endif

#if defined(VK_TARGET_WINCE)
#include <winbase.h>
#endif

#include "vkKernelTypes.h"
#include "vkKernelDefines.h"

namespace VKernel
{

/**
Represents an object used for mutual-exclusion synchronization
between threads.

A mutex is used to protect some part of your code from
a concurant access by more than one thread. A mutex is used to block
all thread will the first thread has not released the mutex.

In the following sample we manipulate 3 integer value to compute a new value.
The operation is not atomic, it means if many thread can call the function it is possible
that one thread begin the operation while another thread has not finished it. In this case
the result can be very strange. To prevent from it we protect the operation with a mutex.

Each time an mutex is acquired it must be released by the same thread which
acquired it. Even if some platform support it, it is not allowed for a thread
to acquire more than one time a mutex before releasing it.

@code
void MyFunction1(vkMutex& iMutex, uint32 iValue1, uint32 iValue2, uint32 oResult)
{
	iMutex.Acquire();
	oResult = (oResult+iValue1)*iValue2;
	iMutex.Release();
}
@endcode

Another way to do the same thing it to use an auto pointer on the mutex which aquire the mutex
in its constructor and release it in its destructor (so it is impossible to forget to release
the mutex).

@code
void MyFunction2(vkMutex& iMutex, uint32 iValue1, uint32 iValue2, uint32 oResult)
{
	vkMutex::Lock lock(iMutex);
	oResult = (oResult+iValue1)*iValue2;
}

@endcode

For more information about using mutex and other thread synchronization tools see @ref synchronizing_threads.

<b>Remarks</b>: Even if it is avaible on some operating system, in this implementation
mutex cannot be shared among processes.

@see Acquire, Release, vkMutex::Lock, vkLockPtr, vkSemaphore

@ingroup grp_thread
*/
class vkMutex
{
public:

	/**
	Default constructor.\ Initialize internal members.

	@param iName name of the mutex. Only used when profiling (i.e. when VK_MUTEX_PROFILE is one).
	iName must be a static string has been keep the pointer and does not allocate anything.
	*/
	VKKERNEL_API vkMutex(const char* iName);

	/**
	Destructor.\ Release internal members.

	Release is not called, even if the mutex has been acquired.

	@see Release
	*/
	VKKERNEL_API ~vkMutex();
    
	/**
	Lock the mutex.

	@see TryAcquire, Release
	*/
	VKKERNEL_API void Acquire();

	/**
	Try to lock the mutex.

	This call is non blocking. It tries to acquire the mutex. If the mutex is already
	owned by another thread it immediatly returns.

	@return true if the mutex has been locked (or was already locked) by the calling thread, else false

	@see Acquire, Release
	*/
	VKKERNEL_API bool TryAcquire();

	/**
	Unlock the mutex.

	@see Acquire, TryAcquire
	*/
	VKKERNEL_API void Release();

	/**
	Get the mutex handle.

	Only usefull when mutex is used by plaform dependent functions.
	*/
	VKKERNEL_API void* GetHandle();

	/**
	Represents an auto pointer on a mutex.
	
	This class define an auto pointer on a mutex. It means
	an object which acquire a mutex in its constructor and release the
	mutex in its destructor. It use the fact that local variables are
	local to a scop. With this object you never forget the unlock a mutex
	when you leave a scop.
	
	@code
		void MyFunction(vkMutex& iMutex)
		{
			DoSomeOperations();

			{
				// here we want to protect some operations
				vkMutex::Lock lock(iMutex);
				// here mutex has been acquired (locked)
				doSomething();
			}

			// here mutex has been released (unlocked)

			DoSomeOtherOperations();
		}
	@endcode

	For more information about using mutex and other thread synchronization tools see @ref synchronizing_threads.

	@see vkMutex

	@ingroup grp_thread
	*/
	class Lock
	{
	public:

		/**
		Construct the lock and acquire the mutex.
		*/
		Lock(vkMutex& iMutex);

		/**
		Release the lock and release the mutex.
		*/
		~Lock();

	private:

		vkMutex&	m_Mutex;	// the mutex to use.

		// a lock cannot be copied because a mutex is not recursive.
		VK_NO_COPYING(Lock);

	};

private:

	// Private implementation data (Pimpl pattern)
	void*	m_Data;

	// a mutex cannot be copied because it is not recursive.
	VK_NO_COPYING(vkMutex);

};

/**
Smart pointer used to temporarily protected
an object with a mutex.

This class is another smart pointer to use with mutex
(the first one is vkMutex::Lock which is a simple smart pointer).
In this case the idea is to protect a object with a mutex
and use the compiler to prevent your are using the object without
protecting it with a mutex.

When you want to protect an object (a list of string for example)
you declare it as volatile, so when you call methods on this object
the compiler will generate an error as the method is not volatile.
At this point, before accessing the object you create a vkLockPtr
object which is used to automatically acquire a mutex in its constructor,
release this mutex in its destructor and transform your object to a non
volatile object so you can access your object methods.

Here is a sample where we want to protect a list of string.

@code
class Sample
{
public:

	void MyMethod()
	{
		// as m_List is volatile we cannot call m_List.Begin()
		// because Begin is not a volatile method.
		// so we must use a vkLockPtr to protect m_List and access
		// a non volatile version of m_List.
		vkLockPtr<vkList<vkString> > pList(m_List,m_Mutex);
		MyListIt it = pList->Begin();
		MyListIt itEnd = pList->End();
		for (;it!=itEnd;it++) {
			// do something
		}
	}

private:

	// the list is declared as volatile so the compiler
	// can control we do not access it directly.
	volatile vkList<vkString>	m_List;
	// the mutex used to protect the list.
	vkMutex						m_Mutex;

};
@endcode

For more information about using mutex and other thread synchronization tools see @ref synchronizing_threads.

@see vkMutex, vkMutex::Lock

@ingroup grp_thread
*/
template <typename T>
class vkLockPtr
{
public:

	/**
	Create the smart pointer and acquire the mutex.

	@param iObj the object to be protected.
	@param iMutex the mutex used to protect the object.
	*/
	vkLockPtr(volatile T& iObj,volatile vkMutex& iMutex);

	/**
	Release the smart pointer and release the mutex.
	*/
	~vkLockPtr();

	/**
	Returns a non volatile reference on the object.
	*/
	T& operator*();

	/**
	Returns a non volatile pointer on the object.
	*/
	T* operator->();

private:

	T&			m_Obj;
	vkMutex&	m_Mutex;

	// a lock ptr cannot be copied because a mutex is not recursive.
	VK_NO_COPYING(vkLockPtr);

};

/**
Same as vkLockPtr, but in this case the protected object is constant.

For more information about using mutex and other thread synchronization tools see @ref synchronizing_threads.

@see vkLockPtr

@ingroup grp_thread
*/
template <typename T>
class vkConstLockPtr
{
public:

	/**
	Create the smart pointer and acquire the mutex.

	@param iObj the object to be protected.
	@param iMutex the mutex used to protected the object.
	*/
	vkConstLockPtr(volatile const T& iObj,volatile const vkMutex& iMutex);

	/**
	Release the smart pointer and release the mutex.
	*/
	~vkConstLockPtr();

	/**
	Returns a non volatile reference on the object.
	*/
	const T& operator*();

	/**
	Returns a non volatile pointer on the object.
	*/
	const T* operator->();

private:

	const T&	m_Obj;
	vkMutex&	m_Mutex;

	// a lock ptr cannot be copied because a mutex is not recursive.
	VK_NO_COPYING(vkConstLockPtr);

};

/** A fast mutex with reentrant behaviour
    Memory consumption is higher than a vkFastMutex (aligned 64 bits)
  */
class vkReentrantFastMutex
{
public:
	vkReentrantFastMutex() : m_mutexData(0)
	{}

	/**
	Lock the mutex.
	*/
	VKKERNEL_API void Acquire()
	{
		/*
		bool done = false;
		while(!done) {
			int64 oldValue = m_mutexData;
			uint32 threadID = (uint32)(oldValue>>32);
			int32 count = (int32)oldValue;
			int64 newMutexData;
			if(threadID == 0) {
				// Then we think it is safe to lock!
				newMutexData = ((int64) CATThreads::GetCurrentThreadId()<<32) | 1;
				done = (oldValue == vkAtomicCompareExchange64(m_mutexData, newMutexData, oldValue));
			} else if(threadID == CATThreads::GetCurrentThreadId()) {
				newMutexData = ((int64) CATThreads::GetCurrentThreadId()<<32) | (++count);
				done = (oldValue == vkAtomicCompareExchange64(m_mutexData, newMutexData, oldValue));
			}
			if(!done)
				vkYieldProcessor();
		}
		*/
	}

	/**
	 Unlock the mutex.
	*/
	VKKERNEL_API void Release()
	{
		/*bool done = false;
		while(!done) {
			int64 oldValue = m_mutexData;
			uint32 threadID = (uint32)(oldValue>>32);
			int32 count = (int32)oldValue;
			int64 newMutexData;
			if(threadID == 0) {
				VKASSERTEX(0, "Invalid State");
			} else if(threadID != vkThread::GetCurrentID()) {
				VKASSERTEX(0, "Invalid State");
			} else if(count==1) {
				newMutexData = 0;
				done = (oldValue == vkAtomicCompareExchange64(m_mutexData, newMutexData, oldValue));
			} else if(count > 1) {
				newMutexData = ((int64)vkThread::GetCurrentID()<<32) | (--count);
				done = (oldValue == vkAtomicCompareExchange64(m_mutexData, newMutexData, oldValue));
			}
			if(!done)
				vkYieldProcessor();
		}*/
	}

	/**
	Represents an auto pointer on a mutex.

	This class define an auto pointer on a mutex. It means
	an object which acquire a mutex in its constructor and release the
	mutex in its destructor. It use the fact that local variables are
	local to a scope. With this object you never forget the unlock a mutex
	when you leave a scope.

	@see vkFastMutex

	@ingroup grp_thread
	*/
	class Lock
	{
	public:

		/**
		Construct the lock and acquire the mutex.
		*/
		VK_INLINE Lock(vkReentrantFastMutex& iMutex) : m_Mutex(iMutex) {
			m_Mutex.Acquire();
		}

		/**
		Release the lock and release the mutex.
		*/
		VK_INLINE  ~Lock(){
			m_Mutex.Release();
		}
	private:
		vkReentrantFastMutex&	m_Mutex;	// the mutex to use.
		VK_NO_COPYING(Lock);
	};
private:
	VK_ALIGNED_DATA(int64, 8)	m_mutexData;		
	VK_NO_COPYING(vkReentrantFastMutex);
};

} // namespace VKernel

#include "vkMutex.hpp"

#endif // __vkMutex_h


