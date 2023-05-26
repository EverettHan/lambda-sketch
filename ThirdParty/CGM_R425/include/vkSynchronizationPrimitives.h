/**
@file

Primitive routines for thread synchronization.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkSynchronizationPrimitives_h)
#define __vkSynchronizationPrimitives_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkKernelTypes_h)
	#include "vkKernelTypes.h"
#endif


#if defined(VK_API_POSIX) && !defined(VK_API_BSD)
	#include <pthread.h>
#endif

#if defined(VK_API_BSD)
	#include <libkern/OSAtomic.h>
#endif

#if defined(VK_TARGET_WINDOWS)
	#undef _WriteBarrier
	#undef _ReadBarrier
	#undef _ReadWriteBarrier

#ifdef VK_GCC_XML
	typedef long LONG;
	typedef __int64 LONGLONG;

	LONG _InterlockedIncrement(LONG*);
	LONG _InterlockedDecrement(LONG*);
	LONG _InterlockedExchangeAdd(LONG*, LONG);
	LONG _InterlockedCompareExchange(LONG*, LONG, LONG);
	LONG _InterlockedCompareExchange64(LONGLONG*, LONG, LONG);
#else
	#include "intrin.h"
	typedef long LONG;
	typedef __int64 LONGLONG;
#endif

#elif defined(VK_TARGET_WINCE)
	#undef _WriteBarrier
	#undef _ReadBarrier
	#undef _ReadWriteBarrier

#include <winbase.h>

#endif

#if !defined(YieldProcessor)
#if defined(VK_TARGET_WINDOWS) || defined(VK_TARGET_MACOSX) || defined(VK_TARGET_LINUX) || defined(VK_TARGET_IPHONE) || defined(VK_TARGET_ANDROID) 
#define vkYieldProcessor() { vkThread::Sleep(0); }
#else
#error not yet implemented!
#endif //VK_TARGET_WINDOWS
#else
#define vkYieldProcessor() YieldProcessor()
#endif //YieldProcessor

namespace VKernel
{

	/**
	Increments (increases by one) the value of the specified 32-bit variable.
	The function prevents more than one thread from using the same variable simultaneously.
	@param ioInteger (in, out) Variable to be incremented. 
	@return Returns the resulting incremented value. 
	@see vkAtomicDecrement32, vkAtomicIncrement64, vkAtomicDecrement64
	@ingroup grp_thread
	*/
	VK_INLINE int32 vkAtomicIncrement32(int32& ioInteger);

	/**
	Decrements (decreases by one) the value of the specified 32-bit variable.
	The function prevents more than one thread from using the same variable simultaneously.
	@param ioInteger (in, out) Variable to be decremented. 
	@return Returns the resulting decremented value. 
	@see vkAtomicIncrement32, vkAtomicIncrement64, vkAtomicDecrement64
	@ingroup grp_thread
	*/
	VK_INLINE int32 vkAtomicDecrement32(int32& ioInteger);

	/**
	The InterlockedCompareExchange routine performs an atomic operation that
	compares the input value pointed to by ioDestination with the value of iComperand.
	If iComperand is equal to ioDestination, then ioDestination is set to equal iExchange.
	Otherwise, *Destination is unchanged. 
	The function prevents more than one thread from using the same variable simultaneously.
	@param ioDestination (in, out) Variable to be compared and changed. 
	@param ioDestination (in) Variable to be affected. 
	@param ioDestination (in) Variable to be compared. 
	@return Returns the original value of destination. 
	@see vkAtomicDecrement32, vkAtomicIncrement64, vkAtomicDecrement64
	@ingroup grp_thread
	*/
	VK_INLINE int32	vkAtomicCompareExchange32(int32& ioDestination, int32 iExchange, int32 iComperand);

	/**
	Same function than vkAtomicCompareExchange32 in 64 bits.
	@see vkAtomicCompareExchange32, vkAtomicIncrement64, vkAtomicDecrement64
	@ingroup grp_thread
	*/
	VK_INLINE int64	vkAtomicCompareExchange64(int64& ioDestination, int64 iExchange, int64 iComperand);

	/**
	Increments (increases by one) the value of the specified 32-bit variable.
	The function prevents more than one thread from using the same variable simultaneously.
	@param ioInteger (in, out) Variable to be incremented. 
	@return Returns the resulting incremented value. 
@see vkAtomicDecrement32, vkAtomicIncrement64, vkAtomicDecrement64
	@ingroup grp_thread
	*/
	VK_INLINE int32	vkAtomicAdd32(int32& ioInteger,int32 iValue);

	/**
	Increments (increases by one) the value of the specified 32-bit variable.
	The function prevents more than one thread from using the same variable simultaneously.
	@param ioInteger (in, out) Variable to be incremented. 
	@return Returns the resulting incremented value. 
	@see vkAtomicDecrement32, vkAtomicIncrement64, vkAtomicDecrement64
	@ingroup grp_thread
	*/
	VK_INLINE int32	vkAtomicSub32(int32& ioInteger,int32 iValue);


#if defined(VK_TARGET_WINDOWS)

	VK_INLINE int32	
	vkAtomicIncrement32(int32& ioInteger)
	{
		return (int32)_InterlockedIncrement((LONG*)&ioInteger);
	}

	VK_INLINE int32	
	vkAtomicDecrement32(int32& ioInteger)
	{
		return (int32)_InterlockedDecrement((LONG*)&ioInteger);
	}

	VK_INLINE int32
	vkAtomicAdd32(int32& ioInteger,int32 iValue)
	{
		return iValue+(int32)_InterlockedExchangeAdd((LONG*)&ioInteger, (LONG)iValue);
	}

	VK_INLINE int32
	vkAtomicSub32(int32& ioInteger,int32 iValue)
	{
		return (int32)_InterlockedExchangeAdd((LONG*)&ioInteger, (LONG)-iValue) - iValue;
	}

	VK_INLINE int32
	vkAtomicCompareExchange32(int32& ioDestination, int32 iExchange, int32 iComperand)
	{
		return (int32)_InterlockedCompareExchange((LONG*)&ioDestination, iExchange, iComperand);
	}

	VK_INLINE int64
	vkAtomicCompareExchange64(int64& ioDestination, int64 iExchange, int64 iComperand)
	{
		return (int64)_InterlockedCompareExchange64((LONGLONG*)&ioDestination, iExchange, iComperand);
	}

#elif defined(VK_TARGET_WINCE)

	VK_INLINE int32	
	vkAtomicIncrement32(int32& ioInteger)
	{
		VKASSERT(uint32(&ioInteger)%4 == 0);
		return (int32)InterlockedIncrement((LONG*)&ioInteger);
	}

	VK_INLINE int32	
	vkAtomicDecrement32(int32& ioInteger)
	{
		return (int32)InterlockedDecrement((LONG*)&ioInteger);
	}

	VK_INLINE int32
	vkAtomicAdd32(int32& ioInteger,int32 iValue)
	{
		return iValue+(int32)InterlockedExchangeAdd((LONG*)&ioInteger, (LONG)iValue);
	}

	VK_INLINE int32
	vkAtomicSub32(int32& ioInteger,int32 iValue)
	{
		return (int32)InterlockedExchangeAdd((LONG*)&ioInteger, (LONG)-iValue)-iValue;
	}

	VK_INLINE int32
	vkAtomicCompareExchange32(int32& ioDestination, int32 iExchange, int32 iComperand)
	{
		return (int32)InterlockedCompareExchange((LONG*)&ioDestination, iExchange, iComperand);
	}

#elif defined(VK_PROC_XENON)
	
	VK_INLINE int32	
	vkAtomicIncrement32(int32& ioInteger)
	{
		VKASSERT(uint32(&ioInteger)%4 == 0);
		return (int32)InterlockedIncrement((LONG*)&ioInteger);
	}

	VK_INLINE int32	
	vkAtomicDecrement32(int32& ioInteger)
	{
		return (int32)InterlockedDecrement((LONG*)&ioInteger);
	}

	VK_INLINE int32
	vkAtomicAdd32(int32& ioInteger,int32 iValue)
	{
		return iValue+(int32)InterlockedExchangeAdd((LONG*)&ioInteger, (LONG)iValue);
	}

	VK_INLINE int32
	vkAtomicSub32(int32& ioInteger,int32 iValue)
	{
		return (int32)InterlockedExchangeAdd((LONG*)&ioInteger, (LONG)-iValue)-iValue;
	}

	VK_INLINE int32
		vkAtomicCompareExchange32(int32& ioDestination, int32 iExchange, int32 iComperand)
	{
		return (int32)InterlockedCompareExchange((LONG*)&ioDestination, iExchange, iComperand);
	}

	VK_INLINE int64
		vkAtomicCompareExchange64(int64& ioDestination, int64 iExchange, int64 iComperand)
	{
		return (int64)InterlockedCompareExchange64((LONGLONG*)&ioDestination, iExchange, iComperand);
	}

#elif defined(VK_API_BSD)
	
	VK_INLINE int32
	vkAtomicIncrement32(int32& ioInteger)
	{
		return OSAtomicIncrement32Barrier(&ioInteger);
	}
	
	VK_INLINE int32
	vkAtomicDecrement32(int32& ioInteger)
	{
		return OSAtomicDecrement32Barrier(&ioInteger);
	}
	
	VK_INLINE int32
	vkAtomicAdd32(int32& ioInteger, int32 iValue)
	{
		return OSAtomicAdd32Barrier(iValue, &ioInteger);
	}
	
	VK_INLINE int32
	vkAtomicSub32(int32& ioInteger, int32 iValue)
	{
		return OSAtomicAdd32Barrier(-iValue, &ioInteger);
	}
	
	VK_INLINE int32
	vkAtomicCompareExchange32(int32& ioDestination, int32 iExchange, int32 iComperand)
	{
		// Should we be mutexed to store the backup value ?
		const int32 backup = ioDestination;
		
		OSAtomicCompareAndSwap32Barrier(iComperand, iExchange, &ioDestination);
		
		return backup;
	}
	
	VK_INLINE int64
	vkAtomicIncrement64(int64& ioInteger)
	{
		return OSAtomicIncrement64Barrier(&ioInteger);
	}
	
	VK_INLINE int64
	vkAtomicDecrement64(int64& ioInteger)
	{
		return OSAtomicDecrement64Barrier(&ioInteger);
	}
	
	VK_INLINE int64
	vkAtomicCompareExchange64(int64& ioDestination, int64 iExchange, int64 iComperand)
	{
		// Should we be mutexed to store the backup value ?
		const int64 backup = ioDestination;
		
		OSAtomicCompareAndSwap64Barrier(iComperand, iExchange, &ioDestination);
		
		return backup;
	}
	
#elif defined(VK_API_POSIX)

	/*class vkSynchronizationPrimitivesData
	{
	public:
		VKKERNEL_API static pthread_mutex_t s_SyncPrimitivesMutex;
	};*/

	VK_INLINE int32
	vkAtomicIncrement32(int32& ioInteger)
	{
		return __sync_add_and_fetch(&ioInteger, 1);
	}

	VK_INLINE int32
	vkAtomicDecrement32(int32& ioInteger)
	{
		return __sync_sub_and_fetch(&ioInteger, 1);
	}

	VK_INLINE int32
	vkAtomicAdd32(int32& ioInteger, int32 iValue)
	{
		return __sync_add_and_fetch(&ioInteger, iValue);
	}

	VK_INLINE int32
	vkAtomicSub32(int32& ioInteger, int32 iValue)
	{
		return __sync_sub_and_fetch(&ioInteger, iValue);
	}

	VK_INLINE int32
	vkAtomicCompareExchange32(int32& ioDestination, int32 iExchange, int32 iComperand)
	{
		return __sync_val_compare_and_swap(&ioDestination, iComperand, iExchange);
	}
	
	VK_INLINE int64
	vkAtomicCompareExchange64(int64& ioDestination, int64 iExchange, int64 iComperand)
	{
		return __sync_val_compare_and_swap(&ioDestination, iComperand, iExchange);
	}

#elif defined(VK_PROC_PPU) 

	// Since cellAtomicDecr32, cellAtomicIncr32, vkAtomicAdd32 and vkAtomicSub32
	// returns the previous value, we have to modify the return value from these 
	// function to comply with the vk Specification


	VK_INLINE int32	
		vkAtomicIncrement32(int32& ioInteger)
	{
		uint32_t old, tmp;
		int32* ea = &ioInteger;
		__asm__ volatile(
			"# cellAtomicIncr32(ea=%[ea],old=%[old],tmp=%[tmp])\n"
			".loop%=:\n"
			"	lwarx   %[old], 0, %[ea]\n"
			"	addi    %[tmp], %[old], 1\n"
			"	stwcx.  %[tmp], 0, %[ea]\n"
			"	bne-    .loop%=\n"
			: [old]"=&b"(old), [tmp]"=&r"(tmp)
			: [ea]"b"(ea)
			: "cc", "memory");

		return tmp;
	}

	VK_INLINE int32	
		vkAtomicDecrement32(int32& ioInteger)
	{
		uint32_t old, tmp;
		int32* ea = &ioInteger;

		__asm__ volatile(
			"# cellAtomicDecr32(ea=%[ea],old=%[old],tmp=%[tmp])\n"
			".loop%=:\n"
			"	lwarx   %[old], 0, %[ea]\n"
			"	subi    %[tmp], %[old], 1\n"
			"	stwcx.  %[tmp], 0, %[ea]\n"
			"	bne-    .loop%=\n"
			: [old]"=&b"(old), [tmp]"=&r"(tmp)
			: [ea]"b"(ea)
			: "cc", "memory");

		return tmp;
	}

	VK_INLINE int32
		vkAtomicAdd32(int32& ioInteger,int32 iValue)
	{
		uint32_t old, tmp;
		int32* ea = &ioInteger;

		__asm__ volatile(
			"# cellAtomicAdd32(ea=%[ea],old=%[old],val=%[value],tmp=%[tmp])\n"
			".loop%=:\n"
			"	lwarx   %[old], 0, %[ea]\n"
			"	add     %[tmp], %[value], %[old]\n"
			"	stwcx.  %[tmp], 0, %[ea]\n"
			"	bne-    .loop%=\n"
			: [old]"=&r"(old), [tmp]"=&r"(tmp)
			: [ea]"b"(ea), [value]"r"(iValue)
			: "cc", "memory");

		return tmp;
	}

	VK_INLINE int32
		vkAtomicSub32(int32& ioInteger,int32 iValue)
	{
		uint32_t old, tmp;
		int32* ea = &ioInteger;

		__asm__ volatile(
			"# cellAtomicSub32(ea=%[ea],old=%[old],val=%[value],tmp=%[tmp])\n"
			".loop%=:\n"
			"	lwarx   %[old], 0, %[ea]\n"
			"	subf    %[tmp], %[value], %[old]\n"
			"	stwcx.  %[tmp], 0, %[ea]\n"
			"	bne-    .loop%=\n"
			: [old]"=&r"(old), [tmp]"=&r"(tmp)
			: [ea]"b"(ea), [value]"r"(iValue)
			: "cc", "memory");

		return tmp;
	}

	VK_INLINE int32
		vkAtomicCompareExchange32(int32& ioDestination, int32 iExchange, int32 iComperand)
	{
		return (int32)cellAtomicCompareAndSwap32((uint32_t*)&ioDestination, (uint32_t)iComperand, (uint32_t)iExchange);
	}

	VK_INLINE int64
		vkAtomicCompareExchange64(int64& ioDestination, int64 iExchange, int64 iComperand)
	{
		return (int64)cellAtomicCompareAndSwap64((uint64_t*)&ioDestination, (uint64_t)iComperand, (uint64_t)iExchange);
	}
/*#elif defined(VK_PROC_X86) && !defined(VK_DOXYGEN) && !defined(VK_GCC_XML)

	VK_INLINE int32	vkAtomicIncrement32(int32& ioInteger)
	{
		__asm {
			mov         ecx,ioInteger 
				mov         eax,1 
				lock xadd   dword ptr [ecx],eax 
				inc     eax
		}
	}

	VK_INLINE int32	vkAtomicDecrement32(int32& ioInteger)
	{
		__asm {
			mov         ecx,ioInteger 
				mov         eax,-1 
				lock xadd   dword ptr [ecx],eax 
				dec			eax
		}
	}
	VK_INLINE int32	vkAtomicAdd32(int32& ioInteger,int32 iValue)
	{
		__asm {
			mov         ecx,ioInteger 
				mov         eax,iValue 
				lock xadd   dword ptr [ecx],eax 
				add     eax,iValue
		}
	}

	VK_INLINE int32	vkAtomicSub32(int32& ioInteger,int32 iValue)
	{
		return vkAtomicAdd32(ioInteger,-iValue);
	}

	VK_INLINE int32	vkAtomicCompareExchange32(int32& ioDestination, int32 iExchange, int32 iComperand)
	{
		__asm {
			mov edx, ioDestination
			mov ecx, iExchange
			mov eax, iComperand
			lock cmpxchg dword ptr [edx], ecx
		}
	}

	__declspec(naked)
	VK_INLINE int64	vkAtomicCompareExchange64(int64& ioDestination, int64 iExchange, int64 iComperand)
	{
		__asm {
			push        ebx
			push        ebp
			mov         ebp,dword ptr [esp+0Ch] 
			mov         ebx,dword ptr [esp+10h] 
			mov         ecx,dword ptr [esp+14h] 
			mov         eax,dword ptr [esp+18h] 
			mov         edx,dword ptr [esp+1Ch] 
			lock cmpxchg8b qword ptr [ebp] 
			pop         ebp
			pop         ebx
			ret
		}
	}
*/			
#endif

	
#if defined(VK_64BIT) || defined(VK_DOXYGEN)

	/**
	Increments (increases by one) the value of the specified 64-bit variable.
	The function prevents more than one thread from using the same variable simultaneously.
	this function is only available on 64
	@param ioInteger (in, out) Variable to be incremented. 
	@return Returns the resulting incremented value. 
	@see vkAtomicDecrement32, vkAtomicDecrement32, vkAtomicDecrement64
	@ingroup grp_thread
	*/
	VKKERNEL_API int64	vkAtomicIncrement64(int64& ioInteger);
	
	/**
	Decrements (decreases by one) the value of the specified 64-bit variable.
	The function prevents more than one thread from using the same variable simultaneously.
	@param ioInteger (in, out) Variable to be decremented. 
	@return Returns the resulting decremented value. 
	@see vkAtomicIncrement32, vkAtomicIncrement32, vkAtomicIncrement64
	@ingroup grp_thread
	*/
	VKKERNEL_API int64	vkAtomicDecrement64(int64& ioInteger);
#endif

} // end of namespace VKernel

#endif // __vkSynchronizationPrimitives_h



