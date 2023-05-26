/**
@file

This file defines different auto pointer classes.

@COPYRIGHT

@author Nicolas Hognon

*/

#if !defined(__vkAutoPtr_h)
#define __vkAutoPtr_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkHeapObject_h)
	#include "vkHeapObject.h"
#endif
#if !defined(__vkMemory_h)
	#include "vkMemory.h"
#endif

//mortal addition : uncomment this and use function on autoptr to debug them when they change without your consent (because data breakpoints will just crash Visual Studio)
//#define _INDEPTH_DEBUG

namespace VKernel
{

/**
Auto pointer on a data with a release functor.

Objects keeped by vkAutoPtr are destroyed when the pointer
object is released (end of scope, destruction as a member, etc.). This 
remove the pointer management burden off the user. 

Contrary to the vkRefPtr, there can't be several pointer to the same 
object. When affecting a pointer to another, the ownership is transfered.

The vkGenAutoPtr is specialized for frequent behavior :
    - vkAutoPtr for objects destroyed with the delete operator
	- vkRawAutoPtr for raw data destroyed with the vkDeallocate operator

@param T The type of object for which storage is being allocated or deallocated. 
@param ReleaseCallback functor to release the pointed object.

@see vkRefPtr


This is an example of a release functor:
@code
	struct GDIRelease
	{
		void operator ()(void* iObject)
		{
			DeleteObject((HGDIOBJ)iObject);
		}
	};
@endcode

Here is some sample code of utilization:
@code 
	{
		vkAutoPtr<MyObject> p = new MyObject;
		vkAutoPtr<MyObject> p2 = p;
		// p is now 0
		//...
	} // nothing todo, p2 is released
@endcode 
*/
#ifdef _INDEPTH_DEBUG
	static uint32	s_OfficialReleaseCount=0;
	static uint32   s_AssertOnOfficialReleaseIndex=-1;		//put there the s_OfficialReleaseCount when asserting 
															//while using officially released autoptr somewhere 
															//in your code so not to recompile everything
#endif

template <class T, class ReleaseCallback>
class vkGenAutoPtr : public vkHeapObject
{
public:

#ifdef _INDEPTH_DEBUG
	//just change m_Debug of the AutoPtr you're interested in
	enum EDebugValues
	{
		ENone					= 0,			//nothing
		EAssertOnChange			= 1,			//assert if ptr change
		EAssertOnChangeToNull	= 2,			//assert if ptr change from non null, to null
		EAssertOnChangeToNullOrRelease	= 3,	//assert if ptr change from non null, to null or if released
		EHasBeenOfficiallyReleased		= 4,	//for user to flag this autoptr has released, but maybe it has been used later
		ECheckForUnofficialRelease		= 5,	//
	};

	EDebugValues GetDebug() {return m_Debug;}

	void SetDebug(EDebugValues iValue)
	{
		if (iValue==EHasBeenOfficiallyReleased)
		{
			s_OfficialReleaseCount++;
			if (s_OfficialReleaseCount==s_AssertOnOfficialReleaseIndex)
			{
				VKASSERTEX(0,"You are looking for this official release which shouldn't have happened yet because ptr will be used later");
			}
		}
		m_Debug=iValue;
	}
protected:
	EDebugValues	m_Debug;
public:
#endif

	/**
	Constructor.
	@param iP pointer to the object to keep. This pointer must not be help by any other vkAutoPtr.
	*/
	explicit vkGenAutoPtr(T iP = 0);

	/**
	Destructor.
	Releases the pointed object.
	*/
	~vkGenAutoPtr();

	/**
	Copy constructor.
	Copy the pointer and release the source pointer.
	*/
	vkGenAutoPtr(vkGenAutoPtr<T, ReleaseCallback>& iSrc);

	/**
	Affectation operator.
	Copy the pointer and release the source pointer.
	*/
	vkGenAutoPtr& operator=(const vkGenAutoPtr& iSrc);

	/**
	Other type pointer cast.
	*/
	template <typename U> 
	operator vkGenAutoPtr<U, ReleaseCallback>&()
	{
		U* p = (T*)0;
		return *(vkGenAutoPtr<U, ReleaseCallback>*)this;
	}

	/**
	Sets a new pointer to be handled, releasing the previously 
	handled one.
	@param iPointee new pointer to handle.
	*/
	vkGenAutoPtr& operator=(T iPointee);

	/**
	Direct access to the pointer.
	*/
	operator T() const;

	T Ptr() const;

	/**
	Direct access to the pointer.
	*/
	T operator->() const;

	/**
	Release the pointer from sure deletion.

	Discard the reference to the object. Object is not deleted and 
	internal pointer is set to 0

	@return The previously held pointer.
	*/
	T Release() const;

protected:

	void		_Free();

	mutable T	m_Pointee; // The pointee object

};

//////////////////////////////////////////////////////////////////////////
// Implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
vkGenAutoPtr<T, ReleaseCallback>::vkGenAutoPtr(T iP) : m_Pointee(iP)
{
#ifdef _INDEPTH_DEBUG
	m_Debug=ENone;
#endif
}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
vkGenAutoPtr<T, ReleaseCallback>::~vkGenAutoPtr()
{
	_Free();
}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
vkGenAutoPtr<T, ReleaseCallback>::vkGenAutoPtr(vkGenAutoPtr<T, ReleaseCallback>& iSrc) : m_Pointee(iSrc.Release()) 
{}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
vkGenAutoPtr<T, ReleaseCallback>& 
vkGenAutoPtr<T, ReleaseCallback>::operator=(const vkGenAutoPtr& iSrc) 
{
	if (this != &iSrc)
		operator=(iSrc.Release());
	return *this;
}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
vkGenAutoPtr<T, ReleaseCallback>& 
vkGenAutoPtr<T, ReleaseCallback>::operator=(T iPointee) 
{
	if (m_Pointee != iPointee) {
		_Free();
		m_Pointee = iPointee;
	}

	return *this;
}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
vkGenAutoPtr<T, ReleaseCallback>::operator T() const
{
#ifdef _INDEPTH_DEBUG
	if (m_Debug==EHasBeenOfficiallyReleased)
	{
		VKASSERTEX(0,"using officially released autoptr");
		//check s_OfficialReleaseCount
	}
#endif
	return m_Pointee;
}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
T
vkGenAutoPtr<T, ReleaseCallback>::Ptr() const
{
#ifdef _INDEPTH_DEBUG
	if (m_Debug==EHasBeenOfficiallyReleased)
	{
		VKASSERTEX(0,"using officially released autoptr");
	}
#endif
	return m_Pointee;
}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
T 
vkGenAutoPtr<T, ReleaseCallback>::operator->() const
{
#ifdef _INDEPTH_DEBUG
	if (m_Debug==EHasBeenOfficiallyReleased)
	{
		VKASSERTEX(0,"using officially released autoptr");
	}
#endif
	return m_Pointee;
}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
T 
vkGenAutoPtr<T, ReleaseCallback>::Release() const
{
#ifdef _INDEPTH_DEBUG
	if (m_Debug==EAssertOnChangeToNullOrRelease || m_Debug==ECheckForUnofficialRelease)
	{
		VKASSERTEX(0,"autptr released");
	}
#endif
	T oldp		= m_Pointee;
	m_Pointee	= 0;
	return oldp;
}

//////////////////////////////////////////////////////////////////////////

template <class T, class ReleaseCallback>
void		
vkGenAutoPtr<T, ReleaseCallback>::_Free()
{
	if (m_Pointee) {
		ReleaseCallback rel;
		rel(m_Pointee);
	}
}

//////////////////////////////////////////////////////////////////////////
// Specialized Types
//////////////////////////////////////////////////////////////////////////

template <class T>
struct vkAutoDelete
{
	void operator ()(T* iP)
	{
		delete iP;
	}
};

template <class T> 
class vkAutoPtr : public vkGenAutoPtr<T*, vkAutoDelete<T> >
{
public:
	explicit vkAutoPtr(T* iP = 0):vkGenAutoPtr<T*, vkAutoDelete<T> >(iP) {}
	vkAutoPtr(const vkAutoPtr& iSrc):vkGenAutoPtr<T*, vkAutoDelete<T> >(iSrc.Release()) {}
	vkAutoPtr& operator=(T* iP)
	{
#ifdef _INDEPTH_DEBUG
		if (m_Debug>=EAssertOnChangeToNull)
		{
			if (this && iP==0)
			{
				VKASSERTEX(0,"AutoPtr Changed to Null");
			}
		}
		else if (m_Debug==EAssertOnChange)
		{
			VKASSERTEX(0,"AutoPtr Changed");
		}
#endif
		vkGenAutoPtr<T*, vkAutoDelete<T> >::operator=(iP);
		return *this;
	}
	vkAutoPtr& operator=(const vkAutoPtr& iSrc)
	{
#ifdef _INDEPTH_DEBUG
		if (m_Debug>=EAssertOnChangeToNull)
		{
			if (this && iSrc==0)
			{
				VKASSERTEX(0,"AutoPtr Changed to Null");
			}
		}
		else if (m_Debug==EAssertOnChange)
		{
			VKASSERTEX(0,"AutoPtr Changed");
		}
#endif
		if (this != &iSrc)
			vkGenAutoPtr<T*, vkAutoDelete<T> >::operator=(iSrc.Release());
		return *this;
	}

	// Redefining cast conversion from upper class
	// because it's masked.
	template <typename U> 
	operator vkAutoPtr<U>&()
	{		
		return *(vkAutoPtr<U>*)this;
	}
};

template <class A>
struct vkAutoRawDelete
{
	void operator ()(uint8* iP)
	{
		vkDeallocateEx(A, iP);
	}
};

template <class A = vkDefaultAllocator> 
class vkRawAutoPtr : public vkGenAutoPtr<uint8*, vkAutoRawDelete<A> >
{
public:
	explicit vkRawAutoPtr(uint8* iP = 0):vkGenAutoPtr<uint8*, vkAutoRawDelete<A> >(iP)
	{}
	vkRawAutoPtr(const vkRawAutoPtr& iSrc):vkGenAutoPtr<uint8*, vkAutoRawDelete<A> >(iSrc.Release())
	{}
	vkRawAutoPtr& operator=(uint8* iP)
	{
		vkGenAutoPtr<uint8*, vkAutoRawDelete<A> >::operator=(iP);
		return *this;
	}
	vkRawAutoPtr& operator=(const vkRawAutoPtr& iSrc)
	{
		if (this != &iSrc)
			vkGenAutoPtr<uint8*, vkAutoRawDelete<A> >::operator=(iSrc.Release());
		return *this;
	}
};

} // namespace VKernel

#endif // __vkAutoPtr_h

