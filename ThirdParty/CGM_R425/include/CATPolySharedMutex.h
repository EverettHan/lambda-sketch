
/**
*	Minimal implementation of std::shared_mutex from C++11 ( to be replaced by MSVC 2015 impl when available )
*/
#ifndef CATPolySharedMutex_H
#define CATPolySharedMutex_H

#ifdef _WINDOWS_SOURCE

#include <mutex>
#include <condition_variable>

#pragma pack(push,_CRT_PACKING)
#pragma warning(push,3)
#pragma push_macro("new")
#undef new

#ifdef _MSC_VER 
#if defined(_MSC_VER) && _MSC_VER >= 1915 
#define _NOEXCEPT noexcept 
#endif
#endif


class shared_mutex
{
public:

    shared_mutex() _NOEXCEPT : m_MutexHandle(0)
    {}

    ~shared_mutex() _NOEXCEPT
    {}

    void lock() _NOEXCEPT
    {
        AcquireSRWLockExclusive(reinterpret_cast<PSRWLOCK>(&m_MutexHandle));
    }

    bool try_lock() _NOEXCEPT
    {
        return (TryAcquireSRWLockExclusive(reinterpret_cast<PSRWLOCK>(&m_MutexHandle)) != 0);
    }

    void unlock() _NOEXCEPT
    {
        ReleaseSRWLockExclusive(reinterpret_cast<PSRWLOCK>(&m_MutexHandle));
    }

    void lock_shared() _NOEXCEPT
    {
        AcquireSRWLockShared(reinterpret_cast<PSRWLOCK>(&m_MutexHandle));
    }

    bool try_lock_shared() _NOEXCEPT
    {
        return (TryAcquireSRWLockShared(reinterpret_cast<PSRWLOCK>(&m_MutexHandle)) != 0);
    }

    void unlock_shared() _NOEXCEPT
    {
        ReleaseSRWLockShared(reinterpret_cast<PSRWLOCK>(&m_MutexHandle));
    }

    void* native_handle() _NOEXCEPT
    {
        return (&m_MutexHandle);
    }
private:
    shared_mutex(const shared_mutex&);
    shared_mutex& operator=(const shared_mutex&);

    void* m_MutexHandle;
};

template<class _Mutex>
class shared_lock
{
public:
    typedef _Mutex mutex_type;

    shared_lock() _NOEXCEPT : m_pMutex(0), m_Owns(false)
    {}

    explicit shared_lock(mutex_type& _Mtx) : m_pMutex(&_Mtx), m_Owns(true)
    {
        _Mtx.lock_shared();
    }

    shared_lock(mutex_type& _Mtx, std::defer_lock_t) _NOEXCEPT : m_pMutex(&_Mtx), m_Owns(false)
    {}

    shared_lock(mutex_type& _Mtx, std::try_to_lock_t) : m_pMutex(&_Mtx), m_Owns(_Mtx.try_lock_shared())
    {}

    shared_lock(mutex_type& _Mtx, std::adopt_lock_t) : m_pMutex(&_Mtx), m_Owns(true)
    {} 

    ~shared_lock() _NOEXCEPT
    {
        if (m_Owns)
            m_pMutex->unlock_shared();
    }

    shared_lock(shared_lock&& _Other) _NOEXCEPT : m_pMutex(_Other.m_pMutex), m_Owns(_Other.m_Owns)
    {
        _Other.m_pMutex = 0;
        _Other.m_Owns = false;
    }

    shared_lock& operator=(shared_lock&& _Right) _NOEXCEPT
    {
        if (m_Owns)
            m_pMutex->unlock_shared();
        m_pMutex = _Right.m_pMutex;
        m_Owns = _Right.m_Owns;
        _Right.m_pMutex = 0;
        _Right.m_Owns = false;
        return (*this);
    }


private:
    shared_lock(const shared_lock&);
    shared_lock& operator=(const shared_lock&);

public:

    void lock()
    {
        //debug
        //if (!_Pmtx) error
        //if (_Owns) error
        m_pMutex->lock_shared();
        m_Owns = true;
    }

    bool try_lock()
    {
        //debug
        //if (!_Pmtx) error
        //if (_Owns) error
        m_Owns = m_pMutex->try_lock_shared();
        return (m_Owns);
    }

    void unlock()
    {
        //debug
        //if (!_Pmtx || !_Owns) error           
        m_pMutex->unlock_shared();
        m_Owns = false;
    }

private:

    _Mutex* m_pMutex;
    bool m_Owns;

};

#pragma pop_macro("new")
#pragma warning(pop)
#pragma pack(pop)

#endif

#endif
