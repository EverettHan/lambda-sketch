/**
@file

This file defines a reference counted class.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkRefPtrObject_h)
#define __vkRefPtrObject_h

#if !defined(__vkObject_h)
	#include "vkObject.h"
#endif
#if !defined(__vkRefPtr_h)
	#include "vkRefPtr.h"
#endif

#include "vkSynchronizationPrimitives.h"

///
namespace VKernel {

class vkRefPtrObject;


// definition of the ptr type
typedef vkRefPtr<vkRefPtrObject> vkRefPtrObjectPtr;

/**
a reference counting class. You must derive from this class 
to use vkRefPtr<>

This class weights one 32 bits reference counter.

(Win32 only) vkRefPtrObject is declared as a dll-interface (VK_KERNEL_API),
even if not necessary (all methods are inlined) because .Net's compiler generates
a warning when declaring a dll-interface class deriving from a non-dll interface class.

@see vkRefPtr
*/
class VKKERNEL_API vkRefPtrObject : public vkObject
{
	
	//friend class vkRefPtr;
public :
	VK_DECLARE_RTTI_ABSTRACTTYPE(vkRefPtrObject, vkObject);

	// Overridden from vkObject
	virtual int32 GetReferenceCount() const;

	/**
	Asks for the destruction of the object by calling the 
	virtual function _Destroy().

	The object is really deleted from memory only if its 
	reference count reaches 0.

	After a call to this function, the object is not deleted, even
	it has a reference count of 1. Call Release() to achieve destruction + 
	deletion (with a reference count of 1).

	After a call to this function, the object will return 
	false when IsValid() is called.

	@see IsValid, _Destroy
	*/
	virtual void Destroy();

	// Overloaded from vkObject
	bool IsReferenced() const;

	/**
	Constructor.\ Reference count is initialized to 0. 
	The object is marked invalid if the given bool is false.

	@param iCtx the context in which the object is created
	@param Validity of the object post construction. Mark your object
	invalid if you have some sort of Create or Initialize to call explicitly.
	*/
	vkRefPtrObject(vkCtx iCtx, bool iIsValid = true);

	/**
	Copy constructor.\ Reference count is not copied but initialized to 0.
	*/
	vkRefPtrObject(const vkRefPtrObject &);

	/**
	Affectation operator.\ Reference count is not copied but initialized to 0.
	*/
	vkRefPtrObject& operator=(const vkRefPtrObject &);

	/**
	Tests if the object has already been destroyed.
	
	@return false if the object has already been destroyed
	(or is not fully initialized), true otherwise.

	@see Destroy, _Destroy
	*/
	bool IsValid() const;

	/**
	Adds a reference on the object.
	
	You should not use this function but manipulate your object 
	through the vkRefPtr class.
	
	@see Release, vkRefPtr
	*/
	void AddRef() const;


	/**
	Release a reference on the object.
	If the object reaches its last reference, _Destroy() is called
	and then the object is deleted.
	
	You should not use this function but manipulate your object 
	through the vkRefPtr class.
	
	@see AddRef, vkRefPtr
	*/

	void Release() const;

	void SetReferenceCount(uint32 iReferenceCount);

protected:
	
	friend class vkRefPtrObjectType;

	// override from vkObject. makes the object valid
	virtual error _Construct();

	/**
	Function called when the object is explicitly destroyed 
	(by calling the Destroy() public function) or when the object
	reference count reaches 0.

	This is the place you should clean up references you hold, and 
	destroy what you can in your class. After destroy, IsValid()
	will return false.
	
	You also have to call the ParentClass::_Destroy in the end of the 
	function.

	@see Destroy
	*/
	virtual void _Destroy();
	
	void _WaitForDeletion() const;

	/**
	You don't have the right to call 
	delete on a RefPtrObject. Use Release() instead.
	
	@see Release
	*/
	virtual ~vkRefPtrObject();

	enum { // Flags stored in the refcount
		fIsInvalid		= 0x80000000,
		fFlagsMask		= 0x00FFFFFF, // add all the possible flags here
		fDeleteCountInc = 0x01000000,
		fDeleteCountMask = 0x7F000000
	};

	// Reference counter
	//mutable uint32 m_DestroyFlags;
	mutable	uint32 m_Refcount;
		
};

#include "vkRefPtrObject.hpp"

} // end of namespace VKernel

#endif // __vkRefPtrObject_h

