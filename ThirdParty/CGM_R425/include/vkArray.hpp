/**
@file

This file contains the implementation of a templated array.

@COPYRIGHT

@author Aymeric Bard
*/

#if defined(VK_COMPILER_MSVC)
	#pragma warning(push)
	#pragma warning( disable : 4127 )
#endif

//////////////////////////////////////////////////////////////////////////
// Public Part
//////////////////////////////////////////////////////////////////////////

template <typename T, class A>
VK_INLINE vkArray<T, A>::vkArray():m_Begin(0)
{
	// Fix crash in MMX optimized code (VS2010 - Studio 64bits) :
	// An aligned class should always use an aligned allocator for its vkArray template !
	// Make sure you declare your vkArray with the right allocator:  vkArray<T, My_Aligned_Allocator>

}

template <typename T, class A>
VK_INLINE vkArray<T, A>::vkArray(const vkArray& iSrc)
{
	// we stretch the new array to the exact size, not the capacity
	uint32 size = iSrc.Size();
	m_Begin	= _Allocate(size);
	if (m_Begin) {
		*((uint32*)m_Begin - 1) = size;
		*((uint32*)m_Begin - 2) = size;
		// copy the data
		vkMemoryTool<T>::UCopy(m_Begin, iSrc.m_Begin, iSrc.m_Begin + size);
	}
}

template <typename T, class A>
VK_INLINE vkArray<T, A>::~vkArray()
{
	_Free();
}

template <typename T, class A>
VK_INLINE vkArray<T, A>&
vkArray<T, A>::operator=(const vkArray& iSrc)
{
	if (this != &iSrc) {
		uint32 size = iSrc.Size();

		if (size) { // we stretch the new array to the exact size, not the capacity
			uint32 capacity = Capacity();
			if ((size <= capacity) && ((size<<1) >= capacity)) {
				// the capacity is just enough to keep it
				uint32 oldSize = *((uint32*)m_Begin - 1);

				if (size >= oldSize) {
					vkMemoryTool<T>::Copy(m_Begin, iSrc.m_Begin, iSrc.m_Begin + oldSize);
					vkMemoryTool<T>::UCopy(m_Begin + oldSize, iSrc.m_Begin + oldSize, iSrc.m_Begin + size);
				} else {
					vkMemoryTool<T>::Copy(m_Begin, iSrc.m_Begin, iSrc.m_Begin + size);
					vkMemoryTool<T>::Destroy(m_Begin + size, m_Begin + oldSize);
				}

				*((uint32*)m_Begin - 1) = size;
			} else {
				// destroy and deallocate
				_Free();

				m_Begin	= _Allocate(size);
				if (m_Begin) {
					*((uint32*)m_Begin - 1) = size;
					*((uint32*)m_Begin - 2) = size;
					// copy the data
					vkMemoryTool<T>::UCopy(m_Begin, iSrc.m_Begin, iSrc.m_Begin + size);
				}
			}

		} else {
			// destroy and deallocate
			_Free();

			m_Begin	= 0;
		}
	}

	return *this;
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::operator==(const vkArray& iOp) const
{
	if (this != &iOp) {
		T* it1 = m_Begin;
		T* it2 = iOp.m_Begin;

		uint32 size = Size();
		if (size != iOp.Size())
			return false;

		T* end = m_Begin + size;
		while (it1 != end) {

			if (*it1 != *it2)
				return false;

			++it1;
			++it2;
		}
	}

	return true;
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::operator!=(const vkArray& iOp) const
{
	return !((*this)==iOp);
}


template <typename T, class A>
VK_INLINE void
vkArray<T, A>::SetInPlaceBuffer(const void* iBuffer, uint32 iCount)
{
	A().inplace_alloc(); // to ensure the proper allocator is used
	uint32* buf = (uint32*)iBuffer + 2;
	m_Begin = buf;
	*(buf - 1) = 0; // size
	*(buf - 2) = (iCount - 2*sizeof(uint32)) / sizeof(T); // allocated size
}

template <typename T, class A>
VK_INLINE void
vkArray<T, A>::Clear()
{
	_Free();
	m_Begin			= 0;
}

template <typename T, class A>
VK_INLINE void
vkArray<T, A>::Empty()
{
	if (!m_Begin)
		return;

	vkMemoryTool<T>::Destroy(m_Begin, End());
	*((uint32*)m_Begin - 1) = 0;
}

template <typename T, class A>
VK_INLINE void
vkArray<T, A>::Swap(vkArray& iSrc)
{
	vkSwap(m_Begin, iSrc.m_Begin);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::SetCapacity(uint32 iCapacity)
{
	if (iCapacity != Capacity())
		return _SetCapacity(iCapacity);
	return true;
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::ReserveCapacity(uint32 iCapacity)
{
	if (iCapacity > Capacity())
		return _SetCapacity(iCapacity);
	return true;
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::Resize(uint32 iSize)
{
	if (iSize > Capacity()) { // needs to increase the capacity
		if ( !_SetCapacity(iSize) )
			return false;
		vkMemoryTool<T>::UFill(End(), CapacityEnd(), T());
		*((uint32*)m_Begin - 1) = iSize;
	} else { // can do in place
		if (!m_Begin)
			return false;

		T* oldEnd = m_Begin + *((uint32*)m_Begin - 1);
		T* newEnd = m_Begin + iSize;
		if (newEnd <= oldEnd) { // stretch
			vkMemoryTool<T>::Destroy(newEnd, oldEnd);
		} else { // expand
			vkMemoryTool<T>::UFill(oldEnd, newEnd, T());
		}
		*((uint32*)m_Begin - 1) = iSize;
	}
	return true;
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::ResizeNoFill(uint32 iSize)
{
	if (iSize > Capacity()) { // needs to increase the capacity
		if ( !_SetCapacity(iSize) )
			return false;
	} else if (!m_Begin)
		return false;

	*((uint32*)m_Begin - 1) = iSize;
	return true;
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::Fit()
{
	return SetCapacity(Size());
}

template <typename T, class A>
VK_INLINE void
vkArray<T, A>::Fill(const T& iElement)
{
	vkMemoryTool<T>::Fill(m_Begin, End(), iElement);
}

template <typename T, class A>
VK_INLINE T&
vkArray<T, A>::Expand()
{
	_Insert(End(), T());
	return Back();
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::PushBack(const T& iElement)
{
	return _Insert(End(), iElement);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::PushBack(ConstIterator iFirst, ConstIterator iLast)
{
	VKASSERT(iLast >= iFirst); // "Invalid insertion range"

	return _Insert(End(), iFirst, iLast);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::PushBack(ConstIterator iFirst, uint32 iCount)
{
	return _Insert(End(), iFirst, iFirst + iCount);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::PushFront(const T& iElement)
{
	return _Insert(m_Begin, iElement);
}

//////////////////////////////////////////////////////////////////////////

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::Insert(Iterator iPosition, const T& iElement)
{
	VKASSERT((iPosition >= m_Begin) && (iPosition <= End())); // "Insertion point out of range"

	return _Insert(iPosition, iElement);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::InsertAt(uint32 iIndex, const T& iElement)
{
	Iterator position = m_Begin + iIndex;
	VKASSERT((position >= m_Begin) && (position <= End())); // "Insertion point out of range"

	return _Insert(position, iElement);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::Insert(Iterator iPosition, ConstIterator iFirst, ConstIterator iLast)
{
	VKASSERT((iPosition >= m_Begin) && (iPosition <= End())); // "Insertion point out of range"
	VKASSERT(iLast >= iFirst); // "Invalid insertion range"

	return _Insert(iPosition, iFirst, iLast);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::Insert(Iterator iPosition, ConstIterator iFirst, uint32 iCount)
{
	VKASSERT((iPosition >= m_Begin) && (iPosition <= End())); // "Insertion point out of range"

	return _Insert(iPosition, iFirst, iFirst + iCount);
}

//////////////////////////////////////////////////////////////////////////

template <typename T, class A>
VK_INLINE uint32
vkArray<T, A>::InsertSorted(const T& iElement)
{
	return InsertSorted(iElement, vkLess<T>());
}

template <typename T, class A>
template <class Cmp>
VK_INLINE uint32
vkArray<T, A>::InsertSorted(const T& iElement, const Cmp& iComparison)
{
	// (GED) Dichotomic Insertion
	int32 hiIndex	= Size();
	int32 lowIndex	= 0;

	while (lowIndex < hiIndex)
	{
		const int32 middleIndex = (lowIndex + hiIndex) >> 1;
		if (iComparison(operator[](middleIndex), iElement))
		{
			lowIndex = middleIndex + 1;
		}
		else
		{
			hiIndex = middleIndex;
		}
	}

	VKASSERT(lowIndex >= 0);
	VKASSERT(lowIndex <= (int32) Size());

	if ( InsertAt(lowIndex, iElement) )
	return lowIndex;
	return Size()+1;

	// Linear Insertion
	/*
	T* end = End();
	for (Iterator it = m_Begin; it != end; ++it)	{
		if (iComparison(iElement, *it))  { // Insert here
			uint32 nInsertPos = (uint32)(it - m_Begin);
			Insert(it, iElement);
			return nInsertPos;
		}
	}
	PushBack(iElement);
	return Size()-1;*/
}

template <typename T, class A>
template <class Cmp>
typename vkArray<T, A>::ConstIterator
VK_INLINE vkArray<T, A>::FindSorted(const T& iElement, const Cmp& iComparison) const
{
	return _FindSorted(iElement, iComparison, vkEqual<T>());
}
template <typename T, class A>
template <class Cmp>
typename vkArray<T, A>::Iterator
VK_INLINE vkArray<T, A>::FindSorted(const T& iElement, const Cmp& iComparison)
{
	return (Iterator)_FindSorted(iElement, iComparison, vkEqual<T>());
}

template <typename T, class A>
typename vkArray<T, A>::ConstIterator
VK_INLINE vkArray<T, A>::FindSorted(const T& iElement) const
{
	return _FindSorted(iElement, vkLess<T>(), vkEqual<T>());
}
template <typename T, class A>
typename vkArray<T, A>::Iterator
VK_INLINE vkArray<T, A>::FindSorted(const T& iElement)
{
	return (Iterator)_FindSorted(iElement, vkLess<T>(), vkEqual<T>());
}

template <typename T, class A>
template <class TElement, class Cmp, class Equal>
typename vkArray<T, A>::ConstIterator
VK_INLINE vkArray<T, A>::FindSorted(const TElement& iElement, const Cmp& iComparison, const Equal& iEqual) const
{
	return _FindSorted(iElement, iComparison, iEqual);
}
template <typename T, class A>
template <class TElement, class Cmp, class Equal>
typename vkArray<T, A>::Iterator
VK_INLINE vkArray<T, A>::FindSorted(const TElement& iElement, const Cmp& iComparison, const Equal& iEqual)
{
	return (Iterator)_FindSorted(iElement, iComparison, iEqual);
}

template <typename T, class A>
template <class TElement, class Cmp, class Equal>
typename vkArray<T, A>::ConstIterator
VK_INLINE vkArray<T, A>::_FindSorted(const TElement& iElement, const Cmp& iComparison, const Equal& iEqual) const
{
	int32 hiIndex	= Size();

	if (hiIndex == 0)
	{
		return m_Begin + hiIndex; // End
	}

	// Compare with first value
	if (iEqual(*m_Begin, iElement))
	{
		return m_Begin;
	}
	else if (hiIndex == 1)
	{
		return m_Begin + 1; // End
	}
	else if (!iComparison(*m_Begin, iElement))
	{
		return m_Begin + hiIndex;
	}

	// Compare with last value
	const T* lastElement = m_Begin + hiIndex - 1;

	if (iEqual(*lastElement, iElement))
	{
		return lastElement;
	}
	else if (iComparison(*lastElement, iElement))
	{
		return m_Begin + hiIndex;
	}

	int32 lowIndex	= 0;

	while (lowIndex < hiIndex)
	{
		const int32 middleIndex = (lowIndex + hiIndex) >> 1;
		const T& middleElement = operator[](middleIndex);

		if (iEqual(middleElement, iElement))
		{
			return &middleElement;
		}
		else if (iComparison(middleElement, iElement))
		{
			lowIndex = middleIndex + 1;
		}
		else
		{
			hiIndex = middleIndex;
		}
	}

	VKASSERT(lowIndex >= 0);
	VKASSERT(lowIndex < (int32) Size());

	const T* elt = m_Begin + lowIndex;
	if (iEqual(*elt, iElement))
	{
		return elt;
	}
	else
	{
		return End();
	}
}

template <typename T, class A>
VK_INLINE T
vkArray<T, A>::PopBack()
{
	T* end = End();
	VKASSERT(m_Begin != end); // "You cannot pop back if you're empty"

	// If there is no last element, it will crash
	T t = *(end - 1);
	_Remove(end - 1);
	return t;
}


template <typename T, class A>
VK_INLINE T
vkArray<T, A>::PopFront()
{
	VKASSERT(m_Begin != End()); // "You cannot pop front if you're empty"

	// If there is no last first, it will crash
	T t = *m_Begin;
	_Remove(m_Begin);
	return t;
}

template <typename T, class A>
VK_INLINE void
vkArray<T, A>::Move(Iterator iNewPosition, Iterator iPosition)
{
	if (iNewPosition < iPosition) {
		T temp		= *iPosition;
		vkMemoryTool<T>::Move(iNewPosition+1, iNewPosition, iPosition);
		*iNewPosition	= temp;
	} else {
		T temp		= *iPosition;
		vkMemoryTool<T>::Move(iPosition, iPosition+1, iNewPosition);
		*(iNewPosition-1)	= temp;
	}
}

template <typename T, class A>
VK_INLINE void
vkArray<T, A>::Move(Iterator iNewPosition, Iterator iFirst, Iterator iLast)
{
	if (iNewPosition < iFirst)
	{
		for (Iterator i = iFirst; i != iLast; ++i) {
			Move(iNewPosition++, i);
		}
	}else {
		if (iNewPosition > iLast) {
			for (; iFirst != iLast; --iLast) {
				 Move(iNewPosition, iFirst);
			}

		} // else nothing to do !
	}
}

template <typename T, class A>
VK_INLINE void
vkArray<T, A>::FastRemove(ConstIterator iPosition)
{
	VKASSERT(iPosition>=m_Begin && iPosition<End()); // "Iterator out of range"

	Iterator last = End() - 1;
	if (iPosition != last) { // not the last one
		vkSwap(*(Iterator)iPosition, *last);
	}
	_Remove(last);
}

template <typename T, class A>
VK_INLINE void
vkArray<T, A>::RemoveAt(uint32 iIndex, T* oOldValue)
{
	Iterator position = m_Begin + iIndex;
	VKASSERT((position >= m_Begin) && (position < End())); // "Remove point out of range"

	if (oOldValue)
		*oOldValue = *position; // we keep the old value
	// the removal
	_Remove(position);
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::Remove(Iterator iPosition)
{
	// we ensure i is in boundary...
	VKASSERT(iPosition>=m_Begin && iPosition<End()); // "Iterator out of range"

	// the Call
	return _Remove(iPosition);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::Remove(const T& iElement)
{
	Iterator t = Find(iElement);
	// we ensure i is in boundary...
	if (t == End())
		return false;

	// the Call
	_Remove(t);
	return true;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::Remove(Iterator iFirst, Iterator iLast)
{
	// we ensure i is in boundary...
	VKASSERT(iFirst>=m_Begin && iFirst<End()); // "First iterator out of range"
	VKASSERT(iLast>iFirst && iLast<=End()); // "Last iterator out of range"

	// the Call
	return _Remove(iFirst, iLast);
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::Begin()
{
	return m_Begin;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::ConstIterator
vkArray<T, A>::Begin() const
{
	return m_Begin;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::RBegin()
{
	return End() - 1;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::ConstIterator
vkArray<T, A>::RBegin() const
{
	return End() - 1;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::End()
{
	if (m_Begin)
		return m_Begin + *((uint32*)m_Begin - 1);
	return 0;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::ConstIterator
vkArray<T, A>::End() const
{
	if (m_Begin)
		return m_Begin + *((uint32*)m_Begin - 1);
	return 0;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::CapacityEnd()
{
	if (m_Begin)
		return m_Begin + *((uint32*)m_Begin - 2);
	return 0;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::ConstIterator
vkArray<T, A>::CapacityEnd() const
{
	if (m_Begin)
		return m_Begin + *((uint32*)m_Begin - 2);
	return 0;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::REnd()
{
	return m_Begin - 1;
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::ConstIterator
vkArray<T, A>::REnd() const
{
	return m_Begin - 1;
}

template <typename T, class A>
VK_INLINE T&
vkArray<T, A>::Front()
{
	VKASSERT(!IsEmpty()); // "You cannot access the front if you're empty"
	return *Begin();
}

template <typename T, class A>
VK_INLINE const T&
vkArray<T, A>::Front() const
{
	VKASSERT(!IsEmpty()); // "You cannot access the front if you're empty"
	return *Begin();
}

template <typename T, class A>
VK_INLINE T&
vkArray<T, A>::Back()
{
	VKASSERT(!IsEmpty()); // "You cannot access the back if you're empty"
	return *(End()-1);
}

template <typename T, class A>
VK_INLINE const T&
vkArray<T, A>::Back() const
{
	VKASSERT(!IsEmpty()); // "You cannot access the back if you're empty"
	return *(End()-1);
}

template <typename T, class A>
VK_INLINE T&
vkArray<T, A>::operator[](uint32 iIndex)
{
	VKASSERT(iIndex < Size()); // "Invalid index"
	return *(m_Begin + iIndex);
}

template <typename T, class A>
VK_INLINE const T&
vkArray<T, A>::operator[](uint32 iIndex) const
{
	VKASSERT(iIndex < Size()); // "Invalid index"
	return *(m_Begin + iIndex);
}

template <typename T, class A>
VK_INLINE uint32
vkArray<T, A>::Capacity() const
{
	if (m_Begin)
		return *((uint32*)m_Begin - 2);
	return 0;
}

template <typename T, class A>
VK_INLINE uint32
vkArray<T, A>::Size() const
{
	if (m_Begin)
		return *((uint32*)m_Begin - 1);
	return 0;
}

template <typename T, class A>
VK_INLINE uint32
vkArray<T, A>::GetMemoryOccupation(bool iSelfSize) const
{
	uint32 size = Size() * sizeof(T);

	if (iSelfSize)
		size += sizeof(*this);

	return size;
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::IsEmpty() const
{
	if (!m_Begin)
		return true;
	return *((uint32*)m_Begin - 1) == 0;
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::IsCapacityReached() const
{
	if (!m_Begin)
		return true;
	return *((uint32*)m_Begin - 1) == *((uint32*)m_Begin - 2);
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::IsHere(const T& iElement) const
{
	return (_Find(m_Begin, iElement) != End());
}

template <typename T, class A>
VK_INLINE bool
vkArray<T, A>::GetPosition(const T& iElement, uint32& oPosition) const
{
	ConstIterator t = _Find(m_Begin, iElement);
	if (t == End()) {
		return false; // If the element is not found
	}

	oPosition = (uint32)(t - m_Begin);// else return the position
	return true;
}


template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::Find(const T& iElement)
{
	return (Iterator)_Find(m_Begin, iElement);
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::ConstIterator
vkArray<T, A>::Find(const T& iElement) const
{
	return _Find(m_Begin, iElement);
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::Iterator
vkArray<T, A>::Find(ConstIterator iStart, const T& iElement)
{
	VKASSERT(iStart>=m_Begin && iStart<=End()); // "Start position out of range"

	return (Iterator)_Find(iStart, iElement);
}

template <typename T, class A>
VK_INLINE typename vkArray<T, A>::ConstIterator
vkArray<T, A>::Find(ConstIterator iStart, const T& iElement) const
{
	VKASSERT(iStart>=m_Begin && iStart <= End()); // "Start position out of range"
	return _Find(iStart, iElement);
}

//////////////////////////////////////////////////////////////////////////
// Protected Part
//////////////////////////////////////////////////////////////////////////

template <typename T, class A>
bool
vkArray<T, A>::_Insert(Iterator iPosition, const T& iElement)
{
	// Test For Reallocation
	uint32 oldSize		= Size();
	uint32 oldCapacity	= Capacity();
	if (oldSize == oldCapacity) {
		uint32 newCapacity = oldCapacity + oldCapacity / 2;
		if (newCapacity < oldSize + 1)
			newCapacity = oldSize + 1;

		Iterator newData = _Allocate(newCapacity);
		if (!newData)
			return false;

		// Just plain copy the old memory
		// and do not destroy it

		uint32 sizeBefore = (uint32)((uint8*)iPosition - (uint8*)m_Begin);
		if (sizeBefore)
			vkMemCopy(newData, m_Begin, sizeBefore);

		// copy the new element
		Iterator insertionPoint = (Iterator)((uint8*)newData + sizeBefore);
		vkMemoryTool<T>::Construct(insertionPoint, iElement);

		uint32 sizeAfter = oldSize * sizeof(T) - sizeBefore;
		if (sizeAfter)
			vkMemCopy(insertionPoint + 1, iPosition, sizeAfter);

		// Simple Delete
		_Free(false);

		// New Pointers
		m_Begin			= newData;
		*((uint32*)m_Begin - 1) = oldSize + 1; // size
		*((uint32*)m_Begin - 2) = newCapacity; // capacity
	} else {
		// Move the block of data after the insertion point
		uint32 sizeBefore = (uint32)((uint8*)iPosition - (uint8*)m_Begin);
		if (sizeBefore != oldSize * sizeof(T)) // Do not move at end
			vkMemMove(iPosition+1, iPosition, oldSize * sizeof(T) - sizeBefore);
		// first we need to construct the inserted element
		vkMemoryTool<T>::Construct(iPosition, iElement);
		// store the new size
		*((uint32*)m_Begin - 1) = oldSize + 1; // size
	}
	return true;
}

template <typename T, class A>
bool
vkArray<T, A>::_Insert(Iterator iPosition, ConstIterator iFirst, ConstIterator iLast)
{
	uint32 sizeToCopy = (uint32)(iLast - iFirst);

	// Test For Reallocation
	uint32 oldSize		= Size();
	uint32 oldCapacity	= Capacity();
	if ((oldSize+sizeToCopy) > oldCapacity) {
		uint32 newCapacity = oldCapacity + oldCapacity / 2;
		if (newCapacity < oldSize + sizeToCopy)
			newCapacity = oldSize + sizeToCopy;

		Iterator newData = _Allocate(newCapacity);
		if (!newData)
			return false;

		// copy before insertion point
		uint32 sizeBefore = (uint32)((uint8*)iPosition - (uint8*)m_Begin);
		if (sizeBefore)
			vkMemCopy(newData, m_Begin, sizeBefore);

		// copy the inserted elements
		Iterator insertionPoint = (Iterator)((uint8*)newData + sizeBefore);
		if (iFirst) { // source is valid
			insertionPoint = vkMemoryTool<T>::UCopy(insertionPoint, iFirst, iLast);
		} else { // Null source
			insertionPoint = vkMemoryTool<T>::UFill(insertionPoint, insertionPoint + sizeToCopy, T());
		}

		// copy after insertion point
		uint32 sizeAfter = oldSize * sizeof(T) - sizeBefore;
		if (sizeAfter)
			vkMemCopy(insertionPoint, iPosition, sizeAfter);

		// Free old memory (and don't call dtors)
		_Free(false);

		// New Pointers
		m_Begin					= newData;
		*((uint32*)m_Begin - 1) = oldSize + sizeToCopy; // size
		*((uint32*)m_Begin - 2) = newCapacity; // capacity
	} else {
		if (!oldCapacity)
			return false;
		// Move the block of data after the insertion point
		uint32 sizeBefore = (uint32)((uint8*)iPosition - (uint8*)m_Begin);
		if (sizeBefore != oldSize * sizeof(T)) // Do not move at end
			vkMemMove(iPosition+sizeToCopy, iPosition, oldSize * sizeof(T) - sizeBefore);
		// first we need to construct the inserted element
		if (iFirst) // data to insert
			vkMemoryTool<T>::UCopy(iPosition, iFirst, iLast);
		else
			vkMemoryTool<T>::UFill(iPosition, iPosition + sizeToCopy, T());
		// store the new size
		*((uint32*)m_Begin - 1) = oldSize + sizeToCopy; // size
	}
	return true;
}

template <typename T, class A>
typename vkArray<T, A>::Iterator
vkArray<T, A>::_Remove(Iterator iPosition)
{
	// first destroy the memory
	vkMemoryTool<T>::Destroy(iPosition);

	// then copy the data that were after
	Iterator last	= iPosition + 1;
	uint32 oldSize	= *((uint32*)m_Begin - 1);
	T* end			= m_Begin + oldSize;
	if (last != end) {
		uint32 sizeToCopy = uint32((uint8*)end - (uint8*)(last));
		vkMemMove(iPosition, last, sizeToCopy);
	}
	*((uint32*)m_Begin - 1) = oldSize - 1;
	return iPosition;
}

template <typename T, class A>
typename vkArray<T, A>::Iterator
vkArray<T, A>::_Remove(Iterator iFirst, Iterator iLast)
{
	// first destroy the memory
	vkMemoryTool<T>::Destroy(iFirst, iLast);

	// then copy the data that were after
	uint32 oldSize		= *((uint32*)m_Begin - 1);
	T* end			= m_Begin + oldSize;
	if (iLast != end) {
		uint32 sizeToCopy = uint32((uint8*)end - (uint8*)iLast);
		vkMemMove(iFirst, iLast, sizeToCopy);
	}
	uint32 countToDelete = (uint32)(iLast - iFirst);
	*((uint32*)m_Begin - 1) = oldSize - countToDelete;

	return iFirst;
}


template <typename T, class A>
typename vkArray<T, A>::ConstIterator
vkArray<T, A>::_Find(ConstIterator iStart, const T& iElement) const
{
	if (!m_Begin)
		return 0;

	T* end = m_Begin + *((uint32*)m_Begin - 1);

	for (ConstIterator t = iStart; t != end; ++t) {
		if (*t == iElement)
			return t;
	}
	return end;

}

template <typename T, class A>
bool
vkArray<T, A>::_SetCapacity(uint32 iCapacity)
{
	// allocation of new size
	if (iCapacity) {
		T* newData		= _Allocate(iCapacity);
		if (!newData) return false;

		uint32 newSize  = Size();
		if (iCapacity < newSize) { // allocated < end : need to destroy extra elements
			// Recopy of old elements
			vkMemCopy(newData, m_Begin, iCapacity * sizeof(T));
			// now destroy the extra elements
			vkMemoryTool<T>::Destroy(m_Begin + iCapacity, m_Begin + newSize);
			// calculate the new byte size
			newSize = iCapacity;
		} else {
			// Recopy of old elements
			vkMemCopy(newData, m_Begin, newSize * sizeof(T));
		}
		// then deallocate memory
		_Free(false);

		m_Begin					= newData;
		*((uint32*)m_Begin - 1) = newSize; // size
		*((uint32*)m_Begin - 2) = iCapacity; // capacity
	} else {
		_Free(true);
		m_Begin			= 0;
	}

	return true;
}

template <typename T, class A>
T*
vkArray<T, A>::_Allocate(uint32 iCount)
{
	if (!iCount)
		return 0;

	// reserve the space and the size and capacity uint32
	uint32 align = A().GetAlignment();
	if (align < 8)
		align = 8;

	uint8* data = vkAllocateEx(A, (iCount)*sizeof(T) + align);
	return ( data ? (T*)(data + align) : 0 );
}

template <typename T, class A>
void
vkArray<T, A>::_Free(bool iDestroy)
{
	if (m_Begin != 0) {	// something to free, destroy and deallocate it
		T* oldBegin = m_Begin;
		m_Begin = 0;	// Set m_Begin at 0 , as Destroy calls may try to access the array

		if (iDestroy)
			vkMemoryTool<T>::Destroy(oldBegin, oldBegin + *((uint32*)oldBegin - 1));

		uint32 align = A().GetAlignment();
		if (align < 8)
			align = 8;

		vkDeallocateEx(A, (uint8*)oldBegin - align);
	}
}

//////////////////////////////////////////////////////////////////////////
// Template Specializations
//////////////////////////////////////////////////////////////////////////

template <typename T, typename A>
void vkSwap(vkArray<T, A>& iA, vkArray<T, A>& iB)
{
	iA.Swap(iB);
}

#if defined(VK_COMPILER_MSVC)
	#pragma warning(pop)
#endif



