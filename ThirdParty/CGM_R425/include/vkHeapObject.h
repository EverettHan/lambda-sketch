/**
@file

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkHeapObject_h)
#define __vkHeapObject_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkKernelTypes_h)
	#include "vkKernelTypes.h"
#endif

namespace VKernel
{
/**
vkHeapObject class. 

Base class for objects wishing to be allocated with the
default allocator, under the default allocation context.

@ingroup grp_memory
*/
class VKKERNEL_API vkHeapObject 
{
public:

	void*	operator new(size_t iSize);
	void	operator delete(void* iP, size_t);

	// For placement new
	void*	operator new(size_t, void* p);
	void	operator delete(void*, void*);

};
// Store a type for each context
// an object could be created in...
// this class is intended to be stored as static of 
// objects that can be "typed"
class vkType;

} // VKernel

#include "vkMemory.h"

#include "vkHeapObject.hpp"

#endif // __vkHeapObject_h


