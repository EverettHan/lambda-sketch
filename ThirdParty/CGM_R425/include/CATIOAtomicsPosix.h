#ifndef CATIOAtomicsPosix_H
#define CATIOAtomicsPosix_H

#ifndef _WINDOWS_SOURCE

#include "DSYSysSemaphore.h"
#include "CATThreads.h"
#include "DSYSysAtomic.h"

#if defined(_MACOSX_SOURCE) && !defined(_IOS_SOURCE)
#include <mach/clock.h>
#include <mach/mach.h>
#else
#include <time.h>
#include <sys/time.h>
#endif
#include <cinttypes>
#include <sys/types.h>
#if defined(_LINUX_SOURCE)
#include <sys/sysinfo.h>
#endif // defined(_LINUX_SOURCE)

#ifdef SG_COMPOSITES_MULTIOS

#if defined(_LINUX_SOURCE) || defined(_DARWIN_SOURCE) \
    || defined(_MACOSX_SOURCE) || defined(_ANDROID_SOURCE)

inline int
CATIOAtomicCmpExch(int volatile *ioDst, int iExchange, int iComporand)
{
	return DSYSysInterlockedCompareExchangeInt32((int*)ioDst, iExchange, iComporand);
}

inline float
CATIOAtomicCmpExch(float volatile *ioDst, float iExchange, float iComporand)
{
	LONG was = DSYSysInterlockedCompareExchangeInt32((int*)ioDst, *((int*)&iExchange), *((int*)&iComporand));
	return *(float*)(&was);
}

inline std::int64_t
CATIOAtomicCmpExch(std::int64_t volatile *ioDst, std::int64_t iExchange, std::int64_t iComporand)
{
    return __sync_val_compare_and_swap(ioDst, iComporand, iExchange);
}

#elif defined(_AIX_SOURCE)
#include <sys/atomic_op.h>

//TODO this works only if (void*) is 64 bits
//DSYSysInterlockedCompareExchangePtr calls compare_and_swaplp and long is 32/64 bits on AIX 32/64 bits

inline int
CATIOAtomicCmpExch(int volatile *ioDst, int iExchange, int iComporand)
{
  void* was = DSYSysInterlockedCompareExchangePtr((void**)ioDst, (void*)iExchange, (void*)iComporand);
  return *(int*)was;
}

inline std::int64_t
CATIOAtomicCmpExch(std::int64_t volatile *ioDst, std::int64_t iExchange, std::int64_t iComporand)
{
	void* was =DSYSysInterlockedCompareExchangePtr((void**)ioDst, (void*)iExchange, (void*)iComporand);
	return *(std::int64_t*)was;
}

#elif defined(_SUNOS_SOURCE)
#include <sys/int_types.h>

//TODO the current implementation of DSYSysInterlockedCompareExchangePtr seams broken on SunOs

inline std::int64_t
CATIOAtomicCmpExch(std::int64_t volatile *ioDst, std::int64_t iExchange, std::int64_t iComporand)
{
	void* was = DSYSysInterlockedCompareExchangePtr((void**)ioDst, (void*)iExchange, (void*)iComporand);
	return *(std::int64_t*)was;
}

#else
#error "Unknown OS"
#endif

inline int
CATIOAtomicIncrement(int volatile *ioVal)
{
	return DSYSysInterlockedIncrement((int*)ioVal);
}

inline int
CATIOAtomicDecrement(int volatile *ioVal)
{
	return DSYSysInterlockedDecrement((int*)ioVal);
}

inline void*
CATIOAtomicCmpExchPtr(void* volatile *ioDst, void* iExchange, void* iComporand)
{
	return DSYSysInterlockedCompareExchangePtr((void**)ioDst, iExchange, iComporand);
}

#if defined(_IOS_SOURCE)

inline std::int64_t          GetIOTimeStampInCount()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    std::int64_t res = (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0); // <- milliseconds (1e-3)
    return res;
}
inline std::int64_t          GetTimerFreqInCountPerSeconds()
{
    return 1e3;
}

#elif defined(_MACOSX_SOURCE)

//inspired by "SystemTS/ProtectedInterfaces/CATSysElapseTime.h"

inline std::int64_t          GetIOTimeStampInCount()
{
    clock_serv_t cclock;
    mach_timespec_t startTime;
    clock_get_time(cclock, &startTime);
    std::int64_t res = startTime.tv_sec * 1000.0 + startTime.tv_nsec / 1000000.0; // <- milliseconds (1e-3)
	return res;
}
inline std::int64_t          GetTimerFreqInCountPerSeconds()
{
	return 1e3;
}

#else

inline std::int64_t          GetIOTimeStampInCount()
{
    timespec startTime;
    clock_gettime(CLOCK_REALTIME, &startTime);
    std::int64_t res = startTime.tv_sec * 1000.0 + startTime.tv_nsec / 1000000.0; // <- milliseconds (1e-3)
	return res;
}
inline std::int64_t          GetTimerFreqInCountPerSeconds()
{
	return 1e3;
}

#endif

inline CATIOThreadId GetThreadId()
{
#if defined(_DARWIN_SOURCE) || defined(_LINUX_SOURCE) || defined(_IOS_SOURCE)
    return CATPtrToULONG32(CATThreads::GetCurrentThreadId());
#else // All Os apart MacOS
    return CATThreads::GetCurrentThreadId();
#endif
}

inline void Sleep(unsigned long iTime)
{
	struct timespec ts;
	ts.tv_sec = (iTime - (iTime % 1000)) / 1000;
	ts.tv_nsec = (iTime % 1000) * 1000000;
	nanosleep(&ts, NULL);
}

inline unsigned char GetPercentMemoryInUse()
{
#if defined(_LINUX_SOURCE)
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    /* // ++ Physical RAM ++

        // Total RAM
        std::uint64_t totalPhysMem = memInfo.totalram;

        // Current RAM usage
        std::uint64_t physMemUsed = memInfo.totalram - memInfo.freeram;

        // Current RAM usage (as a percent of total)
        physMemUsed *= 100; // <- (multiply in next statement to avoid int overflow on right hand side)
        std::uint64_t percent = physMemUsed;
        percent /= totalPhysMem; // <- (multiply in next statement to avoid int overflow on right hand side)

    /*/ // ++ Virtual RAM ++

        // Total RAM
        std::uint64_t totalVirtualMem = memInfo.totalram;
        totalVirtualMem += memInfo.totalswap; // <- (add other values in next statement to avoid int overflow on right hand side)

        // Current RAM usage
        std::uint64_t virtualMemUsed = memInfo.totalram - memInfo.freeram;
        virtualMemUsed += memInfo.totalswap - memInfo.freeswap; // <- (add other values in next statement to avoid int overflow on right hand side)

        // Current RAM usage (as a percent of total)
        virtualMemUsed *= 100; // <- (multiply in next statement to avoid int overflow on right hand side)
        std::uint64_t percent = virtualMemUsed;
        percent /= totalVirtualMem; // <- (multiply in next statement to avoid int overflow on right hand side)

    //*/

    return static_cast<unsigned char>(percent);
#else // defined(_LINUX_SOURCE)
    return 0;
#endif // !defined(_LINUX_SOURCE)
}

class CATIOSemaphore
{
public:
	CATIOSemaphore()
	{
        _semaphore = DSYSysSemaphore::DSYSysCreateSemaphore(maxCount, initialCount);
	}

	~CATIOSemaphore()
	{
        delete _semaphore;
	}

	HRESULT Signal()
	{
		return _semaphore->Signal();
	}

	HRESULT WaitSignal()
	{
		return _semaphore->Wait();
	}
private:

    DSYSysSemaphore* _semaphore;

	static const int initialCount = 0;
	static const int maxCount = 1000;
};

#endif // SG_COMPOSITES_MULTIOS
#endif // not _WINDOWS_SOURCE
#endif // CATIOAtomicsPosix_H
