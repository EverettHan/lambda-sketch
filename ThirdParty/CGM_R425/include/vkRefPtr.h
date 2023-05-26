/**
@file

This file defines a reference counted pointer class.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkRefPtr_h)
#define __vkRefPtr_h


#include "vkUtil.h"

///
namespace VKernel {


/**
Smart pointer class.

The object you want to use with this pointer must derive from kRefCount.

@see vkRefPtrObject

@code 
	class MyObject : public vkRefPtrObject
	{
		// ...
	};

	typedef vkRefPtr<MyObject> MyObjectPtr;
	
	{
		MyObjectPtr a = new MyObject;
		MyObjectPtr b;
		b = a;
		// ...
	}
	// no leaks here
@endcode 
*/
template <class T>
class vkRefPtr
{
public:
	/**
	Constructor.
	*/
	vkRefPtr();

	/**
	Constructor.
	@param iPointer source object (can be null) to construct the pointer from.
	*/
	 vkRefPtr(T* iPointer);

	 /**
	 Copy constructor.
	 */
	 vkRefPtr(const vkRefPtr& iSrc);

	 /**
	 Affectation operator.
	 
	 The previously referenced object is released (destroyed if
	 it was the last reference).
	 */
	 vkRefPtr& operator=(const vkRefPtr& iSrc);

	 /**
	 Affectation operator.

	 The previously referenced object is released (destroyed if
	 it was the last reference).
	 */

	 template <class U>
	 vkRefPtr& operator=(const vkRefPtr<U>& iSrc)
	 {
		  operator=(iSrc.Ptr());

		 return *this;
	 }


	 /**
	 Affectation operator.

	 The previously referenced object is released (destroyed if
	 it was the last reference).
	 */
	 vkRefPtr& operator=(T* iPointer);

	 /**
	Releases the pointed object.
	*/
	~vkRefPtr();

	/**
	Swap two vkRefPtr.
	*/
	void Swap(vkRefPtr& iCopy);

	/**
	Direct access to the pointer.
	*/
	T* operator->() const;

	/**
	Direct access to the object.
	*/
	T& operator*() const;

	/**
	Other type pointer cast.
	*/
	template <typename U> 
	operator vkRefPtr<U>&() 
	{
		return *(vkRefPtr<U>*)this;
	}

	/**
	Other type pointer cast.
	*/
	template <typename U> U* Cast() const {return static_cast<U*>(m_Pointee);}
	
	/**
	Original pointer cast.
	*/
	operator T*() const;

	/**
	Discard the pointee element.
	*/
	void Discard();

	/**
	Test if the pointee element is valid.

	A valid pointee element is a non NULL element without the invalid flag
	If the pointee element is non NULL with the invalid flag, it is set to NULL 
	*/
	bool Validate();

	
	T* Ptr() const;

protected:

	///
	// Members
	
	mutable T* m_Pointee; // The pointee object
};

#include "vkRefPtr.hpp"

} // end of namespace VKernel

#endif // __vkRefPtr_h

