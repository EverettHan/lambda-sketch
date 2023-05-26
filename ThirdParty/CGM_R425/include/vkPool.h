/**
@file

This file defines the vkPool template class.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkPool_h)
#define __vkPool_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkHeapObject_h)
	#include "vkHeapObject.h"
#endif
#include "vkFixedSizeAllocator.h"
#if !defined(__vkAssert_h)
	#include "vkAssert.h"
#endif

#include <new>
#include "vkMutex.h"

namespace VKernel {

template <typename T, bool K = true>
class Truc
{
	Truc();
};

template <typename T, bool K>
Truc<T,K>::Truc()
{
}

/**
Class representation of a pool of object.

This class allow you to instanciate objects faster than 
with the default or standard allocator because space allocation is done
by a given chunk size. So this the perfect allocator for large number
of small objects, preferably POD objects without constructor or destructor.
(but non-POD objects are supported too).

The memory is not wiped after a destruction so if your object constructor
does not clean things, you can obtain an object with the insides of
a previously released object.

@param T type of element to store into the pool.

@see vkFixedSizeAllocator

@code
	struct MyStruct
	{
	// ....
	};

	// if you don't want an explicit call to the destructor of your class,
	// specialize the IsPOD template
	template <> struct vkIsPod<MyStruct> {enum {result = 1};};

	vkPool<MyStruct> pool;
	// allocate a MyStruct
	MyStruct* s = pool.New();
	// ....
	// allocate a MyStruct with a default value
	MyStruct* s2 = pool.New(*s);
	
	///
	// Release all
	pool.Delete(s);
	pool.Delete(s2);
	// -OR-
	pool.Clear();
@endcode 

@ingroup grp_memory
*/
template <typename T, bool TFastStack = false>
class vkPool : public vkHeapObject 
{
public:
	/**
	Constructor

	Default chunk size is vkFixedSizeAllocator::kDefaultChunkSize = 4096 bytes
	
	@param iChunkSize size of chunks containing the data. This is the minimum granularity of the allocation that will take place.
	@param iAlignment value of the alignment in bytes the pool's allocator must use to allocate memory.
	*/
	vkPool(const uint32 iChunkSize = vkFixedSizeAllocator::kDefaultChunkSize, const uint16 iAlignment = 0);

	/**
	Destructor.
	*/
	~vkPool();

	/**
	Allocates a new instance of the template object.
	
	@param iValue optional default value to give (by copy constructor).
	
	@return 
		a pointer on the allocated object.
	
	@see Delete
	*/
	T* New();
	T* New(const T& iValue);

	/**
	Deletes an instance of the template object.

	@param iP pointer to a previously allocated object.

	@see New, Clear
	*/
	void Delete(T* iP);

	
	/**
	Release all the memory used by the pool.

	The destructor will be called if the object does not specialize the IsPOD template.

	@see New, Delete
	*/
	void Clear();

	/**
	Release all the objects allocated by the pool.

	This function does not free the memory used by the pool.
	Call Clear() for this particular purpose.

	The destructor will be called if the object does not specialize the IsPOD template.

	@see Clear
	*/
	void Empty();

	/**
	Returns the vkFixedSizeAllocator used in the pool.
	*/
	const vkFixedSizeAllocator&	GetAllocator() const;

private:

	vkFixedSizeAllocator	m_Allocator;
	// mutex for thread safety
	vkMutex*				m_Mutex;
};

#include "vkPool.hpp"

} // end of namespace VKernel

#endif // __vkPool_h

