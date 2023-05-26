/**
@file

@COPYRIGHT

@author Aymeric Bard
*/


#if !defined(__vkSmartPtr_h)
#define __vkSmartPtr_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkObject_h)
	#include "vkObject.h"
#endif
#if !defined(__vkMutex_h)
	#include "vkMutex.h"
#endif
#include "vkPool.h"

#include "vkSynchronizationPrimitives.h"


#ifdef VK_SUPPORT_DEBUGSYMBOL
	#include "vkStrTools.h"
	#include "vkError.h"
	#include "vkString.h"
#endif

namespace VKernel {

class vkTypeManager;

class VKKERNEL_API vkSmartPtrObject : public vkObject 
{  
	
	template <class T>	
	friend class vkSmartPtr;
	friend class vkSmartPtrBase;
	friend class vkConcreteType; // TODO : better
	friend class vkTypeManager; // Allow to bind _Destroy()

public:
	VK_DECLARE_RTTI_ABSTRACTTYPE(vkSmartPtrObject, vkObject);
	// Ref class
	struct Link
	{
		Link():ptr(0),count(0) {}
		Link(int32 iRefCount):ptr(0),count(iRefCount) {}
		vkSmartPtrObject*		ptr;
		int32					count;
	};

	// Ctor
	vkSmartPtrObject(vkCtx iCtxHandle);
	// Copy ctor
	vkSmartPtrObject(const vkSmartPtrObject& iSrc);
	
	// virtual Dtor
	virtual ~vkSmartPtrObject();

	// Overridden from vkObject
	virtual int32	GetReferenceCount() const;

	// Overloaded from vkObject
	bool IsReferenced() const;

	/**
	Tells if this object is being destroyed.
	The IsBeingDestroyed test is generally used to avoid destruction reentrance
	@return true if it's being destroyed, false otherwise
	*/
	bool IsBeingDestroyed() const;

	/**
	Destroy the object pointed by the smart
	pointers.

	The object is really destroyed now, not waiting for the 
	reference count to reach 0. 
	Other smart pointer previously pointing on the	destroyed object will now point to a Null object, and when they 
	will all release their reference, the space used by the 
	old pointer will be released.
	*/
	virtual void Destroy();	

	/**
	Replace the pointed object with another one.\ Destroy the old one.
	
	Replace(0) is equivalent to calling Destroy()
		
	@param iNewObject the new object to reference.
	
	@see Destroy
	*/
	virtual error Replace(const vkSmartPtrObject* iNewObject);

	/**
	tells if a smartPtrObject is referenced.
	*/
	bool IsUncorrupted() const;
	
	/**
	Removes a reference to the object.
	*/
	void ExternalReleaseReference();
	/**
	Adds a reference to the object.
	*/
	void ExternalAddReference();

protected:
	enum {
		kNullLinkRefCount = -1
	};

	/**
	Virtual to override if some book keeping destruction code is needed.
	
	This function is called just before the deletion of the object.
	Don't forget to call the ParentClass::_Destroy() function.
	*/
	virtual	void _Destroy();


    // VSL tool
	static Link* _GetNullLink();

	/**
	Extension of the flags defined in vkObject
	*/
	enum
	{
		fIsBeingDestroyed = ParentClass::fLastObjectFlags,
		fLastObjectFlags = fIsBeingDestroyed << 1
	};
	
	mutable Link*	m_Link;
	// the static Null Block
	static Link		s_NullLink;
};

// {secret}
class vkSmartPtrManager : public vkHeapObject
{
	template <class T>
	friend class vkSmartPtr;
	friend class vkSmartPtrBase;
	friend class vkSmartPtrObject;
	friend class vkKernelModule;
	friend class vkConcreteType; // TODO : better
	friend class vkTypeManager; // Allow to bind Instance(), ReleaseLink() ...

	vkSmartPtrManager();

	///
	// Methods
	static vkSmartPtrManager& Instance() // Access To the Manager
	{
		return *s_Instance;
	}

	static error _Initialize();
	static error _Terminate();

	// Blocks Management
	VK_INLINE vkSmartPtrObject::Link*		GetFreeLink();
	VK_INLINE void							ReleaseLink(vkSmartPtrObject::Link* iLink);

	// A mutex for thread-safety
	vkMutex									m_Mutex;
	// Pool of links
	vkPool<vkSmartPtrObject::Link, true>	m_Links;

#ifdef VK_SUPPORT_DEBUGSYMBOL
	// an address to trace when _AddRef() and _Release() is done on vkSmartPtr<>
	void*									m_DebugRefAddress;
	vkHash<void*, vkString>					m_DebugCallStacks;
#endif

	// Static instance
	VKKERNEL_API static vkSmartPtrManager*	s_Instance;
};

/**
Base class for all smart ptrs.
Designed to factorize all methods independant 
*/
class VKKERNEL_API vkSmartPtrBase : public vkHeapObject
{
	friend class vkSmartPtrType;

public:
	// Ignore
	VK_INLINE const vkSmartPtrObject::Link* _GetLink() const {return m_Ref;}



	/**
	Make the smart pointer point to a null object using its own link.

	Calling this function is different from calling operator=(NULL).
	When you call operator=(NULL), the smart pointer's link is a static link used by
	all smart pointers to NULL objects.
	In the case of CreateEmptyLink, the smart pointer has its own link.
	*/
	void	CreateEmptyLink();

	/**
	Test if two smart pointers use the same link
	*/
	bool	HasSameLink(const vkSmartPtrBase& iOther);

protected:
	void _Set(const vkSmartPtrObject* iP);

	void	_AddRef();
	void	_Release();

	void	_DeleteObject();

#ifdef VK_SUPPORT_DEBUGSYMBOL
	void	_TraceAddRef();
	void	_TraceRelease();
#endif

	void	_SwapObjects(vkSmartPtrBase& iOther);

	// The Data !
	vkSmartPtrObject::Link* m_Ref;
};

/**
Templated SmartPtr class.

This smart pointer class handles manually destroyed objects, by 
delocalizing the refCount into a small structure, called the link.
Hence, you can destroy an object, or replace it, either if it is still referenced
by many objects.

You have to derive from the vkSmartPtrObject to be referenced by a vkSmartPtr.

@see vkSmartPtrObject


@code 
	vkSmartPtr<Shape> myShape = ///;
	myShape->Draw();
	myShape->Destroy();
	// myShape->Draw; // will crash
	myShape = 0; // to release the link, if we had the last reference on it.
@endcode 
*/
template <class T>	
class vkSmartPtr : public vkSmartPtrBase  
{
	//friend class vkSmartPtrObject;
	template <class U> friend class vkSmartPtr;

public:

	// Default Constructor
	vkSmartPtr();

	// Constructor with a given pointer
	vkSmartPtr(const T* iP);

	// Constructor with a given pointer
	vkSmartPtr(const vkSmartPtr& iCopy);

	// Destructor
	~vkSmartPtr();

	/**
	Swap two smart pointers.
	*/
	VK_INLINE void Swap(vkSmartPtr& iOp) 
	{
		vkSwap(m_Ref, iOp.m_Ref);
	}

	/**
	Swap pointed objects of two smart pointers
	*/
	void	SwapObjects(vkSmartPtr<T>& iOther);

	// Constructor with a given pointer
	vkSmartPtr& operator = (const T* iP);

	// Constructor with a given pointer
	vkSmartPtr<T>& operator = (const vkSmartPtr<T>& iCopy);

	template <class U>
	operator vkSmartPtr<U> ()	{return vkSmartPtr<U>(Ptr());}

#if defined(VK_COMPILER_MSVC)
	#pragma warning (push)
	#pragma warning (disable:4189)
#endif

	template <class U>
	vkSmartPtr<T>& operator = (const vkSmartPtr<U>& iCopy)	
	{
		_Release();

		if (iCopy.m_Ref->ptr != 0) {
			m_Ref = iCopy.m_Ref;
			_AddRef();
		} else { // we just copy something hollow -> prefer the null link
			m_Ref = &vkSmartPtrObject::s_NullLink;
		}
		return *this;
	}

#if defined(VK_COMPILER_MSVC)
	#pragma warning (pop)
#endif

	/**
	Direct access to the pointer.
	*/
	VK_INLINE T* operator-> () const {return (T*)(m_Ref->ptr);}

	/**
	Direct access to the pointer.
	*/
	VK_INLINE T& operator* () const {return *(T*)(m_Ref->ptr);}

	/**
	Original pointer cast.
	*/
	VK_INLINE operator T* () const {return (T*)(m_Ref->ptr);}

	/**
	Explicit access to the pointed object
	*/
	VK_INLINE T* Ptr() const {return (T*)(m_Ref->ptr);}
};

template <class T, class U>
VK_INLINE vkSmartPtr<T>&
Cast(const vkSmartPtr<U>& S) {return *(vkSmartPtr<T>*)(&S);}

#include "vkSmartPtr.hpp"

} // end of namespace VKernel

#endif // __vkSmartPtr_h

