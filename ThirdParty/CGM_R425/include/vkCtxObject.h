/**
@file

Wrapper storing a global contexted object

@COPYRIGHT

@author Gerald Guyomard
*/

#if !defined(__vkCtxObject_h)
#define __vkCtxObject_h

#include "vkKernelLib.h"
#include "vkAssert.h"

#include "vkCtxObjectBase.h"

namespace VKernel
{

/**
Default array init.
*/
template <typename T>
struct vkCtxObjectInitFunction
{
	VK_INLINE static void Construct(T* iDst)
	{
		// Let T's constructor initialize themselves
		new (iDst) T;
	}

	VK_INLINE static void PostConstruct(T& iDst)
	{}

	VK_INLINE static void Destruct(T* iDst)
	{
		iDst->~T();
	}
};

/**
array init of weak pointers.
*/
template <typename T>
struct vkCtxObjectInitFunction<T*>
{
	VK_INLINE static void Construct(T** iDst)
	{
		// Weak pointers contain garbage by default.
		// Reset them to Zero
		*iDst = 0;
	}

	VK_INLINE static void PostConstruct(T*& iDst)
	{
		iDst = 0;
	}

	VK_INLINE static void Destruct(T** iDst)
	{
		*iDst = 0;
	}
};

/**
array init of weak pointers on const objects.
*/
template <typename T>
struct vkCtxObjectInitFunction<const T*>
{
	VK_INLINE static void Construct(const T** iDst)
	{
		// Weak pointers contain garbage by default.
		// Reset them to Zero
		*iDst = 0;
	}

	VK_INLINE static void PostConstruct(const T*& iDst)
	{
		iDst = 0;
	}

	VK_INLINE static void Destruct(const T** iDst)
	{
		*iDst = 0;
	}
};


template <class T, class TInit = vkCtxObjectInitFunction<T> >
class vkCtxObject
#if defined(VK_MULTIPLE_CONTEXTS)
	: public vkCtxObjectBase
#endif
{
public:

#if defined(VK_MULTIPLE_CONTEXTS)
	vkCtxObject(vkCtxObjectBase*& iCtxObjectList = VKernel::s_LocalCtxObjectList);

	// From vkCtxObjectBase
	virtual uint32	GetObjectSize() const;
	virtual uint8*	Construct(uint8* iDst, uint32 iCount);
	virtual void	Destruct(uint32 iCount);
	virtual void	DestructOnlyForContext(vkCtx iCtx);
#else
	// Single context
	vkCtxObject();
	bool IsInitialized() const;
#endif

	const T& operator[] (vkCtx iCtxHandle) const;
	T& operator[] (vkCtx iCtxHandle);
	VK_INLINE vkCtxObject(const vkCtxObject& /*iOther*/) {}

protected:
	VK_INLINE void operator=(const vkCtxObject& /*iOther*/) {}

private:
#if !defined(VK_MULTIPLE_CONTEXTS)
	T	m_Instance;
#endif
};

/**
Defines a contexted type.
*/
class vkType;
typedef  vkCtxObject<vkType*> vkCtxTypePtr;

// definition of basic types

struct vkInt8
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};
struct vkUint8
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkInt16
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};
struct vkUint16
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkInt32
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};
struct vkUint32
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkInt64
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};
struct vkUint64
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkFloat
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkDouble
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkBool
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkBool32
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkChar8
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkChar16
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkChar32
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

struct vkVoid
{
	static VKKERNEL_API vkCtxTypePtr s_Type;
};

#if defined(VK_REAL_DOUBLE_PRECISION)
	typedef vkDouble vkReal;
#else
	typedef vkFloat vkReal;
#endif

#include "vkCtxObject.hpp"

} // end namespace VKernel

#endif // __vkCtxObject_h



