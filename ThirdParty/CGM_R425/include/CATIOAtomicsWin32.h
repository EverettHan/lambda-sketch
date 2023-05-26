#ifndef CATIOAtomicsWin32_H
#define CATIOAtomicsWin32_H

#ifdef _WINDOWS_SOURCE
#include <windows.h>
#include <cinttypes>

#ifdef SG_COMPOSITES_MULTIOS

inline int
CATIOAtomicCmpExch(int volatile *ioDst, int iExchange, int iComporand)
{
	return (int)InterlockedCompareExchange((LONG volatile *)ioDst, iExchange, iComporand);
}

inline float
CATIOAtomicCmpExch(float volatile *ioDst, float iExchange, float iComporand)
{
	LONG was = InterlockedCompareExchange((LONG volatile *)ioDst, *((LONG*)&iExchange), *((LONG*)&iComporand));
	return *(float*)(&was);
}

inline std::int64_t
CATIOAtomicCmpExch(std::int64_t volatile *ioDst, std::int64_t iExchange, std::int64_t iComporand)
{
	LONGLONG was =InterlockedCompareExchange64((LONGLONG volatile *)ioDst, iExchange, iComporand);
	return was;
}

inline int
CATIOAtomicIncrement(int volatile *ioVal)
{
	return (int)InterlockedIncrement((LONG volatile*)ioVal);
}

inline int
CATIOAtomicDecrement(int volatile *ioVal)
{
	return (int)InterlockedDecrement((LONG volatile*)ioVal);
}

inline void*
CATIOAtomicCmpExchPtr(void* volatile *ioDst, void* iExchange, void* iComporand)
{
	return (void*)InterlockedCompareExchangePointer((PVOID volatile *)ioDst, iExchange, iComporand);
}

inline std::int64_t 		  GetIOTimeStampInCount()
{
    std::int64_t res = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&res);
	return res;
}

inline std::int64_t 		  GetTimerFreqInCountPerSeconds()
{
    std::int64_t res = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&res);
	return res;
}

inline CATIOThreadId GetThreadId()
{
    return GetCurrentThreadId();
}

inline unsigned char GetPercentMemoryInUse()
{
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    return (unsigned char)statex.dwMemoryLoad;
}

class CATIOSemaphore
{
public:
	CATIOSemaphore()
	{
		_hSemaphore = CreateSemaphore(NULL, initialCount, maxCount, NULL);//two HANDLEs with the same non-NULL name point to the same semaphore so name is always set to NULL
	}

	~CATIOSemaphore()
	{
		CloseHandle(_hSemaphore);
	}

	HRESULT Signal()
	{
		if(!ReleaseSemaphore(_hSemaphore, 1, NULL)) {
			return E_FAIL;
		}

		return S_OK;
	}

	HRESULT WaitSignal()
	{
		DWORD dwWaitResult;
		dwWaitResult = WaitForSingleObject(
			_hSemaphore,
			INFINITE);     // blocking !!

		switch (dwWaitResult)
		{
		case WAIT_OBJECT_0:
			return S_OK;
			break;

		case WAIT_TIMEOUT:
			return E_FAIL;
			break;
		}

		return E_FAIL;
	}
private:
	HANDLE _hSemaphore;

	static const int initialCount = 0;
	static const int maxCount = 1000;
};

#endif // SG_COMPOSITES_MULTIOS
#endif //_WINDOWS_SOURCE
#endif // CATIOAtomicsWin32_H
