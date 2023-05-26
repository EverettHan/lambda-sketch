/**
@file

Base class Wrapper storing a global contexted object

@COPYRIGHT

@author Gerald Guyomard
*/

#if defined(VK_MULTIPLE_CONTEXTS)

#if !defined(__vkCtxObjectBase_h)
#define __vkCtxObjectBase_h

#include "vkKernelLib.h"
#include "vkKernelTypes.h"

namespace VKernel
{
	class vkCtxObjectBase;

	// private
	extern vkCtxObjectBase* s_LocalCtxObjectList;
}

namespace VKernel 
{

/**
Base class
*/
class VKKERNEL_API vkCtxObjectBase
{
public:
	virtual ~vkCtxObjectBase(){}
	virtual uint32 GetObjectSize() const = 0;
	virtual uint8* Construct(uint8* iDst, uint32 iCount) = 0;
	virtual void Destruct(uint32 iCount) = 0;
	virtual void DestructOnlyForContext(vkCtx iCtx) = 0;

	uint8* Copy(uint8* iDst, uint32 iCount);

	bool IsInitialized() const;

	uint32 GetBufferSizeOfList(uint32 iContextCount) const;

	error CreateBuffers();
	error DeleteBuffers();
	error ResetBuffers(vkCtx iCtx);

	enum { kAlignment = 4 };

	static ptrdiff Align(ptrdiff iOffset);
	static uint8* Align(uint8* iPtr);
	static uint32 Align(uint32 iOffset);

protected:
	void _Register(vkCtxObjectBase*& ioList);
	vkCtxObjectBase();

	static error _Allocate(uint32 iSize, uint8*& oBuffer);
	static error _Deallocate(uint8* iBuffer);
	
	friend class vkModule;
	friend class vkContext;
	error			_CreateBuffers();
	error			_ExpandBuffers(); // +1 for this list
	error			_ShrinkBuffers(); // -1 for this list
	error			_DeleteBuffers();

	static error	_ExpandAllBuffers(); // +1 for ALL the lists
	static error	_ShrinkAllBuffers(); // -1 for ALL the lists

	uint8*			m_IndexedData;
private:
	vkCtxObjectBase* m_Next;
};

// Inlined implementations
VK_INLINE bool
vkCtxObjectBase::IsInitialized() const
{
	return m_IndexedData != 0;
}

VK_INLINE ptrdiff
vkCtxObjectBase::Align(ptrdiff iOffset)
{
	return ((iOffset - 1) & ~(kAlignment - 1)) + kAlignment;
}

VK_INLINE uint32
vkCtxObjectBase::Align(uint32 iOffset)
{
	return ((iOffset - 1) & ~(kAlignment - 1)) + kAlignment;
}

VK_INLINE uint8*
vkCtxObjectBase::Align(uint8* iPtr)
{
	ptrdiff ptr = VK_POINTER_TO_PTRDIFF(iPtr);
	ptr = Align(ptr);
	return (uint8*) ptr;
}
} // end namespace VKernel

#endif // __vkCtxObjectBase_h

#endif // VK_MULTIPLE_CONTEXTS


