#ifndef CATIOAtomicsEmsc_H
#define CATIOAtomicsEmsc_H

#if defined(__EMSCRIPTEN__)

#ifdef SG_COMPOSITES_MULTIOS

#include <ctime>
#include <cinttypes>

inline int
CATIOAtomicIncrement(int volatile *ioVal)
{
	return ++(*ioVal);
}

inline float
CATIOAtomicCmpExch(float volatile *ioDst, float iExchange, float iComporand)
{
    float volatile prev = *ioDst;

    if(*ioDst == iComporand)
    {
        *ioDst = iExchange;
    }

	return prev;
}

inline int
CATIOAtomicCmpExch(int volatile *ioDst, int iExchange, int iComporand)
{
    int volatile prev = *ioDst;

    if(*ioDst == iComporand)
    {
        *ioDst = iExchange;
    }

	return prev;
}

inline std::int64_t
CATIOAtomicCmpExch(std::int64_t volatile *ioDst, std::int64_t iExchange, std::int64_t iComporand)
{
    std::int64_t volatile prev = *ioDst;

    if(*ioDst == iComporand)
    {
        *ioDst = iExchange;
    }

	return prev;
}

inline void*
CATIOAtomicCmpExchPtr(void* volatile *ioDst, void* iExchange, void* iComporand)
{
    if(sizeof(void*) == sizeof(int))
    {
        return (void*)CATIOAtomicCmpExch((int volatile *)ioDst, (int)iExchange, (int)iComporand);
    }
    else
    {
        return (void*)CATIOAtomicCmpExch((std::int64_t volatile *)ioDst, (std::int64_t)iExchange, (std::int64_t)iComporand);
    }
}

inline int
CATIOAtomicDecrement(int volatile *ioVal)
{
	return --(*ioVal);
}

inline CATIOThreadId GetThreadId()
{
	return 0;
}

inline std::int64_t 		  GetTimerFreqInCountPerSeconds()
{
    return CLOCKS_PER_SEC;
}

inline std::int64_t 		  GetIOTimeStampInCount()
{
    return std::clock();
}

#ifndef _WIN32
inline void Sleep(unsigned long /*milliseconds*/)
{
    //TODO FVM1, at the moment, no threads in emscripten, so no need to yield/sleep
}
#endif

inline unsigned char GetPercentMemoryInUse()
{
    return 0;
}

class CATMutex
{
public:
    CATMutex(int iThreadLockIt = 0, int iRecursive = 1, int iLazyCreation = 0)
    {
    }
    ~CATMutex()
    {
    }
    void Lock()
    {
    }
    void Unlock()
    {
    }
    int TryLock()
    {
        return 1;
    }
    inline int IsCreated()
    {
        return 1;
    }
};

class CATResourceLock
{
public:
    CATResourceLock(unsigned char iRecursive = 1)
    {
    }
    ~CATResourceLock()
    {
    }
    void ReadLock()
    {
    }
    void ReadUnlock()
    {
    }
    void WriteLock()
    {
    }
    void WriteUnlock()
    {
    }
};

#endif //SG_COMPOSITES_MULTIOS

#endif //defined(__EMSCRIPTEN__)

#endif //CATIOAtomicsEmsc_H
