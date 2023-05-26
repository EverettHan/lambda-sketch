#ifndef CATIOAtomics_H
#define CATIOAtomics_H

#include "CATSGUtil.h"

#ifdef SG_COMPOSITES_MULTIOS

#include "SGComposites.h"
#include "CATUnicodeString.h"
#ifndef __EMSCRIPTEN__
#include "CATMutex.h"
#include "CATResourceLock.h"
#endif // !__EMSCRIPTEN__

#include "VisGPGPUTypes.h" // for alignement directives (needed for atomic operaitions)

#include <cinttypes>

#define ATOMIC_SET 1;
#define ATOMIC_UNSET 0;

#define ALIGNED_INT     __align__(4)
#define ALIGNED_FLOAT   __align__(4)
#define ALIGNED_INT64   __align__(8)
#define ALIGNED_ULONG   __align__(8)
#define ALIGNED_PTR     __align__(8)

#define MAXJOBSINQUEUE 30

typedef CATULONG32  CATIOThreadId;
#ifndef _WINDOWS_SOURCE
typedef long long LONGLONG;
#endif

#if defined(__EMSCRIPTEN__)
    #include "CATIOAtomicsEmsc.h"
#elif defined(_WINDOWS_SOURCE)
    #include "CATIOAtomicsWin32.h"
#else
    #include "CATIOAtomicsPosix.h"
#endif

class ExportedBySGComposites CATIOAtomicNotReentrantLock
{
public:
    CATIOAtomicNotReentrantLock(int iThreadLockIt = 0, int iLazyCreation = 0)
        : _mutex(iThreadLockIt, 0, iLazyCreation)
    {
    }
    ~CATIOAtomicNotReentrantLock()
    {
    }

    void Lock()
    {
        _mutex.Lock();
    }
    void Unlock()
    {
        _mutex.Unlock();
    }
    int TryLock()
    {
        return _mutex.TryLock();
    }
    inline int IsCreated()
    {
        return _mutex.IsCreated();
    }

private:
    CATIOAtomicNotReentrantLock(const CATIOAtomicNotReentrantLock&);

private:
    CATMutex _mutex;
};
class ExportedBySGComposites CATIOAtomicNotReentrantStackLock
{
public:
    CATIOAtomicNotReentrantStackLock(CATIOAtomicNotReentrantLock& iLock) : _lock(iLock)
    {
        _lock.Lock();
    }
    ~CATIOAtomicNotReentrantStackLock()
    {
        _lock.Unlock();
    }

private:
    CATIOAtomicNotReentrantLock& _lock;

    CATIOAtomicNotReentrantStackLock(const CATIOAtomicNotReentrantLock&);
    CATIOAtomicNotReentrantStackLock& operator=(const CATIOAtomicNotReentrantLock&);
    static void* operator new(size_t);
    static void* operator new[](size_t);
};

typedef CATMutex CATIOAtomicLock;
class ExportedBySGComposites CATIOAtomicStackLock
{
public:
    CATIOAtomicStackLock(CATIOAtomicLock& iLock) : _lock(iLock)
    {
        _lock.Lock();
    }
    ~CATIOAtomicStackLock()
    {
        _lock.Unlock();
    }

private:
    CATIOAtomicLock& _lock;

    CATIOAtomicStackLock(const CATIOAtomicStackLock&);
    CATIOAtomicStackLock& operator=(const CATIOAtomicStackLock&);
    static void* operator new(size_t);
    static void* operator new[](size_t);
};

typedef CATResourceLock CATIOAtomicReadWriteLock;
class ExportedBySGComposites CATIOAtomicStackReadLock
{
public:
    CATIOAtomicStackReadLock(CATIOAtomicReadWriteLock& iLock) : _lock(iLock)
    {
        _lock.ReadLock();
    }
    ~CATIOAtomicStackReadLock()
    {
        _lock.ReadUnlock();
    }

private:
    CATIOAtomicReadWriteLock& _lock;

    CATIOAtomicStackReadLock();
    CATIOAtomicStackReadLock(const CATIOAtomicStackReadLock&);
    CATIOAtomicStackReadLock& operator=(const CATIOAtomicStackReadLock&);
    static void* operator new(size_t);
    static void* operator new[](size_t);
};
class ExportedBySGComposites CATIOAtomicStackWriteLock
{
public:
    CATIOAtomicStackWriteLock(CATIOAtomicReadWriteLock& iLock) : _lock(iLock)
    {
        _lock.WriteLock();
    }
    ~CATIOAtomicStackWriteLock()
    {
        _lock.WriteUnlock();
    }

private:
    CATIOAtomicReadWriteLock& _lock;

    CATIOAtomicStackWriteLock();
    CATIOAtomicStackWriteLock(const CATIOAtomicStackWriteLock&);
    CATIOAtomicStackWriteLock& operator=(const CATIOAtomicStackWriteLock&);
    static void* operator new(size_t);
    static void* operator new[](size_t);
};

#endif // SG_COMPOSITES_MULTIOS

#endif // CATIOAtomics_H
