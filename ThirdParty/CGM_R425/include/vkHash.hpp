/**
@file

This file contains the implementation of an hash table.

@COPYRIGHT

@author Aymeric Bard
*/

//////////////////////////////////////////////////////////////////////////
// _Entry

template <typename K, typename T, class H, class E, class A>
VK_INLINE void 
vkHash<K,T,H,E,A>::_Entry::Swap(_Entry& iOp)
{
	vkSwap(key, iOp.key);
	vkSwap(data, iOp.data);
	vkSwap(next, iOp.next);
}

//////////////////////////////////////////////////////////////////////////
// ConstIterator
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Public

template <typename K, typename T, class H, class E, class A>
VK_INLINE vkHash<K,T,H,E,A>::ConstIterator::ConstIterator():it(0)
{
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE bool 
vkHash<K,T,H,E,A>::ConstIterator::operator==(const ConstIterator& iOp) const 
{
	return (it == iOp.it); 
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE bool 
vkHash<K,T,H,E,A>::ConstIterator::operator!=(const ConstIterator& iOp) const 
{
	return (it != iOp.it); 
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::ConstIterator& 
vkHash<K,T,H,E,A>::ConstIterator::operator++()
{
	++it;
	return *this;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::ConstIterator 
vkHash<K,T,H,E,A>::ConstIterator::operator++(int32)
{
	ConstIterator tmp = *this;
	++*this;
	return tmp;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::ConstIterator& 
vkHash<K,T,H,E,A>::ConstIterator::operator--()
{
	--it;
	return *this;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::ConstIterator 
vkHash<K,T,H,E,A>::ConstIterator::operator--(int32)
{
	ConstIterator tmp = *this;
	--*this;
	return tmp;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE const T& 
vkHash<K,T,H,E,A>::ConstIterator::operator*() const 
{
	return it->data; 
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE const K& 
vkHash<K,T,H,E,A>::ConstIterator::GetKey() const
{
	return it->key;
}

//////////////////////////////////////////////////////////////////////////
// Private

template <typename K, typename T, class H, class E, class A>
VK_INLINE vkHash<K,T,H,E,A>::ConstIterator::ConstIterator(_Entry* iT):it(iT)
{
}

//////////////////////////////////////////////////////////////////////////
// Iterator
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Public

template <typename K, typename T, class H, class E, class A>
VK_INLINE vkHash<K,T,H,E,A>::Iterator::Iterator()
{
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator& 
vkHash<K,T,H,E,A>::Iterator::operator++()
{
	
	++ConstIterator::it;
	return *this;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator 
vkHash<K,T,H,E,A>::Iterator::operator++(int32)
{
	Iterator tmp = *this;
	++ConstIterator::it;
	return tmp;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator& 
vkHash<K,T,H,E,A>::Iterator::operator--()
{

	--ConstIterator::it;
	return *this;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator 
vkHash<K,T,H,E,A>::Iterator::operator--(int32)
{
	Iterator tmp = *this;
	--ConstIterator::it;
	return tmp;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE T& 
vkHash<K,T,H,E,A>::Iterator::operator*() const 
{
	return ConstIterator::it->data; 
}

//////////////////////////////////////////////////////////////////////////

/*template <typename K, typename T, class H, class E, class A>
VK_INLINE K& 
vkHash<K,T,H,E,A>::Iterator::GetKey() const
{
	return ConstIterator::it->key;
}*/

//////////////////////////////////////////////////////////////////////////
// Private

template <typename K, typename T, class H, class E, class A>
VK_INLINE vkHash<K,T,H,E,A>::Iterator::Iterator(_Entry* iT):ConstIterator(iT)
{
}

//////////////////////////////////////////////////////////////////////////
// Hash
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Public

template <typename K, typename T, class H, class E, class A>
VK_INLINE vkHash<K,T,H,E,A>::vkHash(uint32 iSize)
{
	vkHashTools::ComputePreferredSize(iSize);

	m_Table.Resize(iSize);
	m_Pool.SetCapacity(iSize);
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE vkHash<K,T,H,E,A>::vkHash(const vkHash& iCopy)
{
	_Copy(iCopy);
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE vkHash<K,T,H,E,A>::~vkHash()
{
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE vkHash<K,T,H,E,A>& 
vkHash<K,T,H,E,A>::operator=(const vkHash& a)
{
	if (this != &a) {
		// We clear the current table 
		Clear();
		// we then copy the content of a
		_Copy(a);
	}

	return *this;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE void 
vkHash<K,T,H,E,A>::Swap(vkHash& iOp)
{
	m_Table.Swap(iOp.m_Table);
	m_Pool.Swap(iOp.m_Pool);
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator	
vkHash<K,T,H,E,A>::operator()(uint32 iIndex)
{
	VKASSERT(iIndex < m_Pool.Size()); // "Invalid index"
	return Iterator(m_Pool.Begin() + iIndex);
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::ConstIterator	
vkHash<K,T,H,E,A>::operator()(uint32 iIndex) const
{
	return ConstIterator((pEntry)(m_Pool.Begin()) + iIndex);
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE void 
vkHash<K,T,H,E,A>::Empty()
{
	// we clear all the allocated entries
	m_Pool.Empty();
	// we clear the table
	m_Table.Fill(0);
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE void 
vkHash<K,T,H,E,A>::Clear()
{
	// we clear all the allocated entries
	m_Pool.Clear();
	// we clear the table
	m_Table.Clear();
	m_Table.Resize(kDefaultHashSize);
	// TODO : check if necessary
	m_Table.Fill(0);
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
void 
vkHash<K,T,H,E,A>::Rehash(uint32 iSize) 
{
	VKASSERT(vkIsPowerOf2(iSize)); // "Buckets number must be power of 2"

	uint32 oldSize = m_Table.Size();

	// we create a new pool
	vkArray<_Entry, A> pool;
	pool.SetCapacity(iSize);
	pool.PushBack(m_Pool.Begin(), m_Pool.End());

	// Temporary table
	vkArray<pEntry, A> tmp;
	tmp.Resize(iSize);
	tmp.Fill(0);

	H hashfun;
	for (uint32 index = 0; index < oldSize; ++index) {
		_Entry* first = m_Table[index];
		while (first) {
			uint32 newindex	= hashfun(first->key) & (iSize-1);

			_Entry* newe	= pool.Begin() + (first - m_Pool.Begin());

			// insert new entry in new table
			newe->next		= tmp[newindex];
			tmp[newindex]	= newe;

			first			= first->next;          
		}
	}
	m_Table.Swap(tmp);
	m_Pool.Swap(pool);
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
void 
vkHash<K,T,H,E,A>::GetOccupation(vkArray<uint32>& oBucketOccupation) const
{
	vkArray<uint32>& bo = oBucketOccupation;

	bo.Resize(1);
	bo[0] = 0;

	for(const pEntry* it = m_Table.Begin();it != m_Table.End();it++) {
		if (!*it) { // there is someone there
			bo[0]++;
		} else {
			// count the number of occupant
			uint32 count = 1;
			pEntry e = *it;
			while (e->next) {
				e = e->next;
				count++;
			}
			
			uint32 oldsize = bo.Size();
			if (oldsize <= count) { // we need to resize
				bo.Resize(count+1);

				// and we init to 0
				for (uint32 i=oldsize; i<=count; ++i)
					bo[i] = 0;
			}
	
			// the recensing
			bo[count]++;
		}
	}
}

//////////////////////////////////////////////////////////////////////////


template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Pair
vkHash<K,T,H,E,A>::Insert(const K& iKey,const T& iValue)
{
	uint32 index = Index(iKey);
	E equalFunc;

	// we look for existing key
	for (pEntry e = m_Table[index]; e != 0; e = e->next) {
		if (equalFunc(e->key, iKey)) {
			return Pair(Iterator(e),0);
		}
	}
	
	// Key not found

	if (m_Pool.Size() == m_Pool.Capacity()) { // Need Rehash
		Rehash(m_Table.Size()*2);
		return Insert(iKey, iValue);
	} else { // No
		return Pair(Iterator(_Insert(index, iKey, iValue)),1);
	}
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
T& 
vkHash<K,T,H,E,A>::operator[](const K& iKey)
{
	uint32 index = Index(iKey);

	// we look for existing key
	pEntry e = _Find(index, iKey);
	if (e == m_Pool.End()) {
		if (m_Pool.Size() == m_Pool.Capacity()) { // Need Rehash
			Rehash(m_Table.Size()*2);
			return operator [] (iKey);
		} else { // No
			e = _Insert(index, iKey, T());
		}
	}

	return e->data;
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE bool
vkHash<K,T,H,E,A>::Remove(const K& iKey)
{
	uint32 index = Index(iKey);
	E equalFunc;

	// we look for existing key
	pEntry old = 0;
	for (pEntry e = m_Table[index]; e != 0; e = e->next) {
		if (equalFunc(e->key, iKey)) {
			// This is the element to remove
			
			// change the pointers to it
			if (old) {
				old->next = e->next;
			} else {
				m_Table[index] = e->next;
			}

			// then removed it from the pool
			m_Pool.FastRemove(e);
			if (e != m_Pool.End()) { // wasn't the last one... we need to remap
				_RemapEntry(m_Pool.End(), e);
			}


			return true;
		}
		old = e;
	}
	return false;
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator 
vkHash<K,T,H,E,A>::Remove(const Iterator& iT)
{
	VKASSERT(m_Pool.Size()); // "Nothing to remove" // ??

	uint32 index = Index(iT.GetKey());
	VKASSERT(index < m_Table.Size()); // "Iterator out of range"

	// we look for existing key
	pEntry old = NULL;
	for (pEntry e = m_Table[index]; e != 0; e = e->next) {
		if (e == iT.it) {
			// This is the element to remove
			if (old) {
				old->next = e->next;
				old = old->next;
			} else {
				m_Table[index] = e->next;
				old = m_Table[index];
			}

			// then removed it from the pool
			m_Pool.FastRemove(e);
			if (e != m_Pool.End()) { // wasn't the last one... we need to remap
				_RemapEntry(m_Pool.End(), e);
				if (old == m_Pool.End())
					old = e;
			}

			break;
		}
		old = e;
	}

	return iT;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator 
vkHash<K,T,H,E,A>::Find(const K& iKey)
{
	return Iterator(_Find(Index(iKey),iKey));
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::ConstIterator 
vkHash<K,T,H,E,A>::Find(const K& iKey) const
{
	return ConstIterator(_Find(Index(iKey),iKey));
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE bool 
vkHash<K,T,H,E,A>::IsHere(const K& iKey) const
{
	return (_Find(Index(iKey), iKey) != m_Pool.End());
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator 
vkHash<K,T,H,E,A>::Begin()
{
	return Iterator(m_Pool.Begin());
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::ConstIterator 
vkHash<K,T,H,E,A>::Begin() const
{
	return ConstIterator((pEntry)m_Pool.Begin());
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::Iterator 
vkHash<K,T,H,E,A>::End()
{
	return Iterator(m_Pool.End());
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE typename vkHash<K,T,H,E,A>::ConstIterator 
vkHash<K,T,H,E,A>::End() const
{
	return ConstIterator((pEntry)m_Pool.End());
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE uint32 
vkHash<K,T,H,E,A>::Index(const K& iKey) const
{
	H hashfun;
	return hashfun(iKey) & (m_Table.Size() - 1);
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE uint32 
vkHash<K,T,H,E,A>::Size() const
{
	return m_Pool.Size();
}

////////////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
uint32 
vkHash<K,T,H,E,A>::GetMemoryOccupation(bool iSelfSize) const 
{
	uint32 size = 0;
	size += m_Table.GetMemoryOccupation(false);
	size += m_Pool.GetMemoryOccupation(false);

	if (iSelfSize)
		size += sizeof(*this);
	
	return size;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
VK_INLINE bool
vkHash<K,T,H,E,A>::IsEmpty() const
{
	return m_Pool.Size() == 0;
}

//////////////////////////////////////////////////////////////////////////
// protected:
	
//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
void 
vkHash<K,T,H,E,A>::_Copy(const vkHash& iCopy)
{
	uint32 size = iCopy.m_Table.Size();
	m_Table.Resize(size);
	m_Table.Fill(0);

	m_Pool.SetCapacity(iCopy.m_Pool.Capacity());
	m_Pool = iCopy.m_Pool;

	// remap the address in the table
	for (uint32 i=0; i<size; ++i) {
		if (iCopy.m_Table[i])
			m_Table[i] = m_Pool.Begin() + (iCopy.m_Table[i] - iCopy.m_Pool.Begin());
	}

	// remap the adresses in the entries
	for (_Entry* e = m_Pool.Begin(); e != m_Pool.End(); ++e) {
		if (e->next) {
			e->next = m_Pool.Begin() + (e->next - iCopy.m_Pool.Begin());
		}
	}
}

//////////////////////////////////////////////////////////////////////////

/*
template <typename K, typename T, class H, class E, class A> 
typename const vkHash<K,T,H,E,A>::Entry* 
vkHash<K,T,H,E,A>::_Find(uint32 iIndex,const K& iKey) const
{
	E equalFunc;

	// we look for existing key
	for(pEntry e=m_Table[iIndex];e != 0;e = e->next) {
		if (equalFunc(e->key,iKey)) {
			return e;
		}
	}
	return (const pEntry)m_Pool.End();
}
*/

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
typename vkHash<K,T,H,E,A>::pEntry 
vkHash<K,T,H,E,A>::_Insert(uint32 iIndex,const K& iKey,const T& iValue)
{
	// create new entry
	_Entry& newe	= m_Pool.Expand();
	newe.key		= iKey; 
	newe.data		= iValue;
	newe.next		= m_Table[iIndex];
	m_Table[iIndex]	= &newe;
	return &newe;
}

//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, class H, class E, class A>
void	
vkHash<K,T,H,E,A>::_RemapEntry(pEntry iOld, pEntry iNew)
{
	uint32 index = Index(iNew->key);
	VKASSERT(m_Table[index] != 0); // "key not mapping to an entry"

	if (m_Table[index] == iOld) { // It was the first of the bucket
		m_Table[index] = iNew;
	} else {
		for (pEntry n = m_Table[index]; n->next != NULL; n = n->next) {
			if (n->next == iOld) { // found one
				n->next = iNew;
				return; // only one can match
			}
		}
		VKUNSUPPORTEDEX("Entry not found, remapping broken");
	}
	
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE uint32
vkHash<K,T,H,E,A>::GetOffsetOfTableMember()
{
	return (uint32) offsetof(ThisClass, m_Table);
}

template <typename K, typename T, class H, class E, class A>
VK_INLINE uint32
vkHash<K,T,H,E,A>::GetOffsetOfPoolMember()
{
	return (uint32) offsetof(ThisClass, m_Pool);
}

//////////////////////////////////////////////////////////////////////////
// Template Specializations
//////////////////////////////////////////////////////////////////////////

template <typename K, typename T, typename H, typename E, typename A>
void vkSwap(vkHash<K,T,H,E,A>& iOp1, vkHash<K,T,H,E,A>& iOp2) 
{
	iOp1.Swap(iOp2);
}

template <typename K, typename T, typename H, typename E, typename A>
void vkSwap(typename vkHash<K,T,H,E,A>::_Entry& iOp1, typename vkHash<K,T,H,E,A>::_Entry& iOp2) 
{
	iOp1.Swap(iOp2);
}



