/**
@file

This file defines a templated array.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkArray_h)
#define __vkArray_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkUtil_h)
	#include "vkUtil.h"
#endif
#if !defined(__vkAssert_h)
	#include "vkAssert.h"
#endif
#if !defined(__vkMemory_h)
	#include "vkMemory.h"
#endif

#if defined(VK_COMPILER_MSVC)
	#pragma warning( disable : 4251 )
#endif

#define ARRAYNEW

namespace VKernel
{

/**
Class representation of an array.

This array allows to hold structure or class
which have something specific to do on the construction,
deletion or recopy, like allocating/destroying pointers.

@code
/////////
// parsing an array
/////////

vkArray<mp3dEntity*> array = FillArrayByType(TYPE_3DENTITY);

// The fastest way

vkArray<mp3dEntity*>::Iterator it = array.Begin();
for(; it != array.End(); ++it) {
	mp3dEntity* ent = *it;
	// do something with ent
}

// or

uint32 count = array.Size();
for (uint32 i=0; i<count; ++i) {
	mp3dEntity* ent = array[i];
	// do something with ent
}
@endcode

@param T type of element to store into the array.
@param A T allocator.

@see vkStack

@ingroup grp_containers
*/
template <typename T, class A = vkDefaultAllocator>
class vkArray : public vkGenHeapObject<A>
{
public:
	
	/**
	Constant iterator type on an array.
	
	@see ConstIterator Begin() const, 	ConstIterator End() const
	*/
	typedef const T*		ConstIterator;

	/**
	Iterator type on an array.
	
	@see Iterator Begin(), 	Iterator End()
	*/
	typedef T*				Iterator;

	/**
	Default Constructor.
	*/
	vkArray();

	/**
	Copy constructor.

	@param iSrc Source of the copy.
	*/
	vkArray(const vkArray& iSrc);

	/**
	Affectation operator.

	@param iSrc Source of the copy.
	*/
	vkArray& operator=(const vkArray& iSrc);

	/**
	Destructor.

	Release the elements contained in the array.

	If you were storing "dump" pointers, you need first to iterate
    on the array and call delete on each pointer.
	*/
	~vkArray();

	/**
	Swaps two arrays.

	@param iSrc Source of the swap operation.
	*/
	void Swap(vkArray& iSrc);
	
	/**
	Comparison operator.

	The content of the array must be identical and in the same order.

	@param iOp Second array to be compared with.
	*/
	bool operator==(const vkArray& iOp) const;

	/**
	Comparison operator.

	@param iOp Second array to be compared with.
	*/
	bool operator!=(const vkArray& iOp) const;


	/**
	Removes all the elements from the array.

	There is no more space reserved after this call.
	*/
	void Clear();

	/**
	Empties the array.

	The capacity of the array is kept, but its size is set to 0 and 
	its elements are removed.
	*/
	void Empty();

	/**
	Sets the capacity of the array.

	The space reserved beyond the used size is
	not initialized (no elements are constructed)
	The elements beyond the reserved limit are 
	discarded.

	@param iCapacity number of elements needed.
	@return true if the capacity change is a success

	@see ReserveCapacity, Resize
	*/
	bool SetCapacity(uint32 iCapacity);

	/**
	Reserves at least a given number of elements.

	If the capacity is greater than the one requested,
	nothing happens.

	@param iCapacity number of elements needed at least.
	@return true if the capacity change is a success

	@see SetCapacity, Resize
	*/
	bool ReserveCapacity(uint32 iCapacity);

	/**
	Resizes the array.

	After Resize(n) (n>0), you can address elements from [0]
	to [n-1]. Constructors for new elements are called, destructors for 
	destroyed elements are called.
	If the size is greater than the reserved size,
	the array is reallocated at the exact needed size.
	If not, there is no reallocation at all. 

	@param iSize new size of the array.
	@return true if the resizing is a success

	@see SetCapacity, ReserveCapacity
	*/
	bool Resize(uint32 iSize);

	/**
	Resizes the array without calling constructors / destructors.

	After Resize(n) (n>0), you can address elements from [0]
	to [n-1]. Constructors for new elements are NOT called, destructors for 
	destroyed elements are called.
	If the size is greater than the reserved size,
	the array is reallocated at the exact needed size.
	If not, there is no reallocation at all.
	Warning: don't use with non pod types

	@param iSize new size of the array.
	@return true if the resizing is a success

	@see SetCapacity, ReserveCapacity
	*/
	bool ResizeNoFill(uint32 iSize);

	/** 
	Ensures than the reserved size equals the used size. 
	*/
	bool Fit();

	/**
	Sets the InPlace buffer when using an vkInPlaceAllocator.

	Release	the elements contained in the array. If
	you were storing "dump" pointers, you need first to iterate 
	on the array and call delete on each pointer.

	@param iBuffer buffer to replace with
	@param iCount number of elements to copy from the buffer
	*/
	void SetInPlaceBuffer(const void* iBuffer, uint32 iCount);

	/**
	Fills the array with an element.

	@param iElement element to fill.
	*/
	void Fill(const T& iElement);

	/**
	Expands the array by one element, constructed with its default value.

	@return A reference on the inserted element
	*/
	T& Expand();

	/**
	Inserts an element at the end of the array.

	@param iElement element to insert.
	@return true if the insertion is a success
	*/
	bool PushBack(const T& iElement);

	/**
	Append a bunch of elements after the current content of the array.

	@param iFirst iterator on the start of the sequence to copy
	@param iLast iterator on the end of the sequence to copy
	@return true if the insertion is a success
	*/
	bool PushBack(ConstIterator iFirst, ConstIterator iLast);

	/**
	Append a bunch of elements after the current content of the array.

	If you specify 0 as iFirst, iCount elements will be reserved,
	constructed with their default value.

	@param iFirst iterator on the start of the sequence to copy (can be 0).
	@param iCount number of elements to append.
	@return true if the insertion is a success
	*/
	bool PushBack(ConstIterator iFirst, uint32 iCount);

	/**
	Inserts an element at the start of an array.

	@param iElement element to insert.
	@return true if the insertion is a success
	*/
	bool PushFront(const T& iElement);

	/**
	Inserts an element at a given index.

	@param iIndex index where the element must be inserted
	@param iElement element to insert.
	@return true if the insertion is a success
	*/
	bool InsertAt(uint32 iIndex, const T& iElement);

	/**
	Inserts an element before another one.

	- The element to insert before is given as an iterator on it, i.e. a pointer on it in this case.
	- If you specify 0 as iFirst, iCount elements will be inserted, constructed with their default value.

	@param iPosition iterator on the element to insert before.
	@param iElement element to insert.
	@param iFirst iterator on the start of the sequence to copy
	@param iLast iterator on the end of the sequence to copy
	@param iCount number of elements pointed by iFirst.
	@return true if the insertion is a success
	*/
	bool Insert(Iterator iPosition, const T& iElement);

	
	bool Insert(Iterator iPosition, ConstIterator iFirst, ConstIterator iLast);

	
	bool Insert(Iterator iPosition, ConstIterator iFirst, uint32 iCount);

	/**
	Inserts an element, with a comparison function.

	@param iElement element to insert.
	@param iComparison The function comparing two elements.

	@return 
	The index of insertion or more than this array size if memory allocation failed
	*/
	uint32 InsertSorted(const T& iElement);

	template <class Cmp>
	uint32 InsertSorted(const T& iElement, const Cmp& iComparison);

	/**
	Finds an element in a sorted array.
	@param iElement element to find.
	@param iComparison The function comparing two elements.
	@return the iterator pointing to the found element or End() if not found
	*/
	template <class Cmp>
	ConstIterator FindSorted(const T& iElement, const Cmp& iComparison) const;
	template <class Cmp>
	Iterator FindSorted(const T& iElement, const Cmp& iComparison);

	// vkLess op
	ConstIterator FindSorted(const T& iElement) const;
	Iterator FindSorted(const T& iElement);

	/**
	Finds an element of type TElement in a sorted array of A.
	@param iElement element to find.
	@param iComparison The function comparing two elements. This predicate
	must have a method bool operator(const T& iA, const TElement& iB) const
	@param iEqual the function test equality between a T and a TElement.  This predicate
	must have a method bool operator(const T& iA, const TElement& iB) const
	@return the iterator pointing to the found element or End() if not found
	*/
	template <class TElement, class Cmp, class Equal>
	ConstIterator FindSorted(const TElement& iElement, const Cmp& iComparison, const Equal& iEqual) const;
	template <class TElement, class Cmp, class Equal>
	Iterator FindSorted(const TElement& iElement, const Cmp& iComparison, const Equal& iEqual);

	/**
	Removes the last element of the array.

	You must be sure that the array isn't empty.

	@return element removed.
	*/
	T PopBack();

	/**
	Removes the first element of the array.

	You must be sure that the array isn't empty.

	@return element removed.
	*/
	T PopFront();

	/**
	Removes an element at a given position, non conservatively (order is lost).

	@param iPosition position of the element to remove.
	*/
	void FastRemove(ConstIterator iPosition);

	/**
	Removes an element at a given index.

	@param iIndex index of the element to remove.
	@param oOldValue value of the element removed (can be 0 if not interesting).
	*/
	void RemoveAt(uint32 iIndex, T* oOldValue = 0);

	/**
	Removes an element.

	The elements are given by iterators on them, i.e. pointer on them in this case.

	@param iPosition iterator on the element to remove.

	@return An iterator on the next element after 
		the element removed (to go on with an iteration).
	*/
	Iterator Remove(Iterator iPosition);

	/**
	Removes an element.

	@param iElement element to remove (first occurence found).

	@return true if the element was removed, 
		otherwise false.
	*/	
	bool Remove(const T& iElement);

	/**
	Removes a range of elements.

	@param iFirst iterator on the start of the sequence to remove
	@param iLast iterator on the end of the sequence to remove

	@return An iterator on the next 
		element after the element removed (to go on with 
		an iteration).
	*/
	Iterator Remove(Iterator iFirst, Iterator iLast);



	/**
	Returns the number of elements allocated.
	*/
	uint32 Capacity() const;

	/**
	Returns the number of elements in the array.
	*/
	uint32 Size() const;

	/**
	Returns the occupied memory, in bytes.

	@param iSelfSize whether the static size of the array should be added (12 bytes).
	*/
	uint32 GetMemoryOccupation(bool iSelfSize) const;

	/**
	Returns true if the array is empty, false otherwise.
	*/
	bool IsEmpty() const;

	/**
	Returns Checks if the size of the array has reached its capacity.
	
	@return true is Size() == Capacity()

	@see Size, Capacity
	*/
	bool IsCapacityReached() const;

	/**
	Returns an iterator on the first element.

	@code
		for(Iterator t = a.Begin(); t != a.End(); ++t) {
			// do something with *t
		}
	@endcode
	*/
	Iterator Begin();

	
	ConstIterator Begin() const;

	/**
	Returns an iterator on the last element.
	*/
	Iterator RBegin();

	
	ConstIterator RBegin() const;

	/**
	Returns an iterator after the last element.
	*/
	Iterator End();

	
	ConstIterator End() const;

	/**
	Returns an iterator after the last element of the capacity.
	*/
	Iterator CapacityEnd();
	ConstIterator CapacityEnd() const;

	/**
	Returns an iterator before the first element.
	*/
	Iterator REnd();

	
	ConstIterator REnd() const;

	/**
	Returns a reference on the first element of the array.

	No test is provided to see if there is an element.
	*/
	T& Front();

	/**
	Returns a const reference on the first element of the array.

	No test is provided to see if there is an element.
	*/
	const T& Front() const;

	/**
	Returns a reference on the last element of the array.

	No test is provided to see if there is an element.
	*/
	T& Back();

	/**
	Returns a const reference on the last element of the array.

	No test is provided to see if there is an element.
	*/
	const T& Back() const;

	/**
	Access to an array element by its index.

	No test is provided on iIndex.

	@param iIndex index of the element to access.

	@return a reference on the object accessed.
	*/
	T& operator[](uint32 iIndex);
	
	
	const T& operator[](uint32 iIndex) const;



	/**
	Tests for an element presence.

	@param iElement value to test.

	@return true if the element is present, otherwise false.
	*/
	bool IsHere(const T& iElement) const;

	/**
	Returns the position of an element.

	@param iElement element to find.
	@param oPosition index of the element (if found) 

	@return true if element found, otherwise false.
	*/
	bool GetPosition(const T& iElement, uint32& oPosition) const;

	/**
	Finds an element.

	@param iElement element to find.
	@param iStart iterator from which begin the search.

	@return a pointer on the first element found 
		or End() if the element is not found.
	*/
	Iterator Find(const T& iElement);

	
	ConstIterator Find(const T& iElement) const;

	
	Iterator Find(ConstIterator iStart, const T& iElement);

	
	ConstIterator Find(ConstIterator iStart, const T& iElement) const;


	
	/**
	Moves an element or a range before another element.

	The elements are given by iterators on them, i.e. pointer on them in this case.

	@param iNewPosition iterator on the element to insert before.
	@param iPosition iterator on the element to move.
	@param iFirst iterator on the start of the sequence to move.
	@param iLast iterator on the end of the sequence to move
	*/
	void Move(Iterator iNewPosition, Iterator iPosition);

	
	void Move(Iterator iNewPosition, Iterator iFirst, Iterator iLast);

protected:

	#if !defined(VK_DOXYGEN)

	// Insert
	bool _Insert(Iterator iPosition, const T& iElement);
	bool _Insert(Iterator iPosition, ConstIterator iFirst, ConstIterator iLast);

	// Remove
	Iterator _Remove(Iterator iPosition);
	Iterator _Remove(Iterator iFirst, Iterator iLast);

	// Find
	ConstIterator _Find(ConstIterator iStart, const T& iElement) const;
	template <class TElement, class Cmp, class Equal>
	ConstIterator _FindSorted(const TElement& iElement, const Cmp& iComparison, const Equal& iEqual) const;

	bool	_SetCapacity(uint32 iCapacity);
	T*		_Allocate(uint32 iCount); // Allocation
	void	_Free(bool iDestroy = true);// Deallocation

	///
	// Members

	T*			m_Begin;		// elements start 

	#endif // VK_DOXYGEN
};



#include "vkArray.hpp"

} // end of namespace VKernel

#endif



