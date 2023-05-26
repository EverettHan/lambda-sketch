/**
@file

This file defines a templated hash table.

@COPYRIGHT

@author Aymeric Bard
*/

#if !defined(__vkHash_h)
#define __vkHash_h

#if !defined(__vkKernelLib_h)
	#include "vkKernelLib.h"
#endif
#if !defined(__vkUtil_h)
	#include "vkUtil.h"
#endif
#if !defined(__vkArray_h)
	#include "vkArray.h"
#endif

namespace VKernel {

/**
Class representation of an Hash Table container.

the hash table is a simple associative container. You can 
insert unique key along with a value. Insertion, removal and search are 
constant in time (depending on the complexity and the quality of the
hashing function).

Several hash functions for basic types are already defined in 
vkUtil.h

@param K is the type of the key
@param T is the type of element to insert
@param H is the hash function to hash the key
@param E is an equal operator to test keys
@param A is the allocator used for the memory used by the hash table.

@ingroup grp_containers
*/
template <typename K,typename T,class H = vkHashFunction<K>, class E = vkEqual<K>, class A = vkDefaultAllocator>
class vkHash : public vkGenHeapObject<A>
{
private:
	// Types
	
	struct _Entry
	{
		void				Swap(_Entry& iOp);
		_Entry*				next;
		K					key;
		T					data;		
	};
	typedef _Entry*			pEntry;

public:

	enum {
		kDefaultHashSize = 4
	};

	/**
	Constant Iterator on a hash table.

	This iterator is the only way to iterate on
	elements in a constant hash table. The iteration will be in no
	specific order, not in the insertion order.
	of how to use it:

	@code
	vkHash<T,K,H>::ConstIterator it = m_Hashtable.Begin();
	while (it != m_Hashtable.End()) {
		// access to the key
		it.GetKey();
		// access to the element
		*it;
		// next element
		++it;
	}
	@endcode
	*/
	class ConstIterator : public vkGenHeapObject<A>
	{
		friend class vkHash;
	public:
		/**
		Default constructor of the iterator.
		*/
		ConstIterator();

		/**
		Operator Equal of the iterator.
		*/
		bool operator==(const ConstIterator& iOp) const;

		/**
		Operator Not Equal of the iterator.
		*/
		bool operator!=(const ConstIterator& iOp) const;

		/**
		Goes to the next element.
		*/
		ConstIterator& operator++();
		ConstIterator operator++(int32);

		/**
		Goes to the previous element.
		*/
		ConstIterator& operator--();
		ConstIterator operator--(int32);

		/**
		Returns a const reference on the current element.
		*/
		const T& operator*() const;

		/**
		Returns a const reference on the current key.
		*/
		const K& GetKey() const;

	protected:
	#if !defined(VK_DOXYGEN)
		ConstIterator(_Entry* iT);
		pEntry it;
	#endif // VK_DOXYGEN
	};

	
	class Iterator : public ConstIterator
	{
		friend class vkHash;
	public:
		/**
		Default constructor.
		*/
		Iterator();

		/**
		Goes to the next element.
		*/
		Iterator& operator++();
		Iterator operator++(int);

		/**
		Goes to the previous element.
		*/
		Iterator& operator--();
		Iterator operator--(int);

		/**
		Returns a reference on the current element.
		*/
		T& operator*() const;

		/**
		Returns a reference on the current key.
		*/
		//K& GetKey() const;

	protected:
	#if !defined(VK_DOXYGEN)
		Iterator(_Entry* iE);
	#endif // VK_DOXYGEN
	};

	
	/**
	Defines a pair containing an iterator and a boolean.
	@see Insert
	*/
	typedef vkPair<Iterator, bool>		Pair;

	/**
	Default Constructor.

	@param iSize The default number of buckets (should be a power of 2, otherwise will be converted.)
	@param iCopy hash table to copy.

	*/
	vkHash(uint32 iSize = kDefaultHashSize);

	/**
	Copy Constructor.
	*/
	vkHash(const vkHash& iSrc);

	/**
	Affectation operator.
	*/
	vkHash& operator=(const vkHash& iSrc);

	/**
	Destructor.

	Release the elements contained in the hash table. If
	you were storing pointers, you need first to iterate 
	on the table and call delete on each pointer.
	*/
	~vkHash();

	/**
	Swap two hash tables.
	*/
	void Swap(vkHash& iSrc);

	/**
	access to the ith element of the hash.
	*/
	Iterator operator()(uint32 iIndex);

	
	ConstIterator operator()(uint32 iIndex) const;

	/**
	Rehash the content of the hash table, giving a 
	new buckets number.

	@param iSize number of buckets after the rehashing.
	*/
	void Rehash(uint32 iSize); 

	/**
	Calculates the average occupation for the 
	buckets by filling an array with the population for
	different bucket size (represented by the index of 
	the array).

	array[0] = 8
	array[1] = 20
	array[2] = 2

	means that there is 24 elements in the hash, 20 are alone in their 
	bucket and 4 are by pair in their bucket.

	@param oBucketOccupation a vkArray of uint32 that will contain the number
	of buckets representing each occupation.

	*/
	void GetOccupation(vkArray<uint32>& oBucketOccupation) const;

	/**
	Insert a pair key/value in the table.

	If the key is already present in the table, 
	Insert() will not override the old value.
	Instead, the Pair.second returned will be false.

	@param iKey key of the element to insert.
	@param iValue element to insert.

	@return 
		A Pair containing an iterator on the element inserted
		and a boolean to see if the element was inserted (true) 
		or was already present (false).

	@see []
	*/
	Pair Insert(const K& iKey, const T& iValue);

	/**
	Access to an hash table element.

	If no element correspond to the key, an element
	is inserted in the table, constructed with default value.

	@param iKey key of the element to access.

	@return 
		a reference of the element found/inserted.
	*/
	T& operator [] (const K& iKey);

	/**
	Removes an element.

	@param iKey key of the element to remove.
	@param iPosition iterator on the object to remove.

	@return 
		true if the element was removed, false otherwise.
	-OR- 
		iterator on the element next to the one just removed.
	*/
	bool Remove(const K& iKey);

	
	Iterator Remove(const Iterator& iPosition);

	/**
	Removes all the elements from the table and clear the memory used.

	The hash table remains with the same number 
	of buckets after a Clear().
	*/
	void Clear();

	/**
	Removes all the elements from the table without freeing 
	the memory used by the hash itself.

	The hash table remains with the same number 
	of buckets after a Empty().
	*/
	void Empty();

	/**
	Search for an hash table element.

	This function exists in a const version, returning a ConstIterator.

	@param iKey key of the element to access.

	@return an iterator of the element found. End()
	if not found.
	
	@see IsHere
	*/
	Iterator Find(const K& iKey);

	
	ConstIterator Find(const K& iKey) const;

	/**
	test for the presence of a key.

	Do not use this function to test before
	doing an insertion. Use Insert() directly, and
	check for the Pair.second to see if the key 
	was present.

	@param iKey key of the element to access.

	@return true if the key was found, false 
	otherwise.

	@see Find
	*/
	bool IsHere(const K& iKey) const;

	/**
	Returns an iterator on the first element.

	
		Typically, an algorithm iterating on an hash table 
	looks like:

	@code
		vkHash<T,K,H>::Iterator it = h.Begin();
		vkHash<T,K,H>::Iterator itend = h.End();

		for(; it != itend; ++it) {
			// do something with *it
		}
	@endcode

	@see End
	*/
	Iterator Begin();

		
	ConstIterator Begin() const;

	/**
	Returns an iterator out of the hash table.
	*/
	Iterator End();

		
	ConstIterator End() const;

	/**
	Returns the index of the given key.

	@param iKey key of the element to find the index.
	*/
	uint32 Index(const K& iKey) const;

	/**
	Returns the elements number.
	*/
	uint32 Size() const;

	/**
	Returns the occupied memory, in bytes.

	@param iSelfSize whether the static size of the array should be added (20 bytes).
	*/
	uint32 GetMemoryOccupation(bool iSelfSize) const;

	/**
	Returns true if the hash is empty, false otherwise.
	*/
	bool IsEmpty() const;

	/**
	 Returns the internal offset of m_Table member.
	 To be used for infrastructure convenience only.
	 @return the internal offset.
	 */
	static uint32 GetOffsetOfTableMember();

	/**
	 Returns the internal offset of m_Pool member.
	 To be used for infrastructure convenience only.
	 @return the internal offset.
	 */
	static uint32 GetOffsetOfPoolMember();

protected:
	
	typedef vkHash<K,T,H,E,A> ThisClass;

	///
	// Methods

	void			_Copy(const vkHash& iCopy);
	const pEntry	_Find(uint32 iIndex,const K& iKey) const
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

	pEntry			_Insert(uint32 iIndex,const K& iKey,const T& iValue);
	void			_RemapEntry(pEntry iOld, pEntry iNew);

	///
	// Members
	
	vkArray<pEntry, A>		m_Table;	// the hash table data
	vkArray<_Entry, A>		m_Pool;		// the entry pool
};

#if !defined(VK_DOXYGEN)
	class vkHashTools
	{
	public:
		VKKERNEL_API static void ComputePreferredSize(uint32& ioSize);
	};
#endif // VK_DOXYGEN

#include "vkHash.hpp"

} // end of VKernel

#endif



