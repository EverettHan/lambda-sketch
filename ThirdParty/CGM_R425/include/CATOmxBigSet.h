/**
* @level Private
* @usage U1
*/
#ifndef __CATOmxBigSet_h__
#define __CATOmxBigSet_h__

#include "CATOmxKernel.h"
#include "CATOmxSharable.h"
#include "CATOmxIter.h"
#include <stddef.h>
#include "CATOmxBaseBigSet.h"
#include "CATOmxPortability.h"
#include "CATOmxDefaultCollecManager.h"

/**
 * The API/usage is the same as CATOmxSet => refer to its documentation
 * The difference is that CATOmxBigSet is intended for "big" sets.
 * This means that:
 * We gain
 *   a few CPU time
 * We lose
 *    the memory optimization made in CATOmxSet for very little cardinalities (0, 1, 2)
 *    copy-on-write
 * Use this version of CATOmxSet sparingly, for example in singleton classes.
 * DO NOT use it as a data member of a class instanciated millions of times.
 * If you are not sure, use CATOmxSet.
 */
template<class T, CATOmxCollecManagerLocator TMgr = CATOmxDefaultCollecManager<T*>::manager>
class CATOmxBigSet : private CATOmxBaseBigSet
{
public:
  typedef T * ValueType;
  typedef T const * KeyType;
  typedef CATOmxIter<T> IteratorType;
  typedef CATOmxIter<const T> ConstIteratorType;

  /** @see CATOmxSet*/
  inline CATOmxBigSet<T, TMgr>() {}
  OMX_EXPLICIT inline CATOmxBigSet<T, TMgr>(unsigned iSize) : CATOmxBaseBigSet(iSize) {}
  inline ~CATOmxBigSet() { RemoveAll(); }

  /** return size.*/
  using CATOmxBaseBigSet::Size;

  inline CATBoolean IsEmpty() const { return Size() == 0; }

  /** @see CATOmxSet::Insert, item MUST be non NULL*/
  inline ValueType Insert(KeyType item, int allowDuplicate = 0) { return reinterpret_cast<ValueType>(CATOmxBaseBigSet::InsertItem(TMgr(), item, 0, allowDuplicate)); }

  /** @see CATOmxSet::Replace, item MUST be non NULL */
  inline ValueType Replace(KeyType item) { return reinterpret_cast<ValueType>(CATOmxBaseBigSet::InsertItem(TMgr(), item, 1, 0)); }

  /** @see CATOmxSet::Locate, item MUST be non NULL */
  inline ValueType Locate(KeyType item) const { return reinterpret_cast<ValueType>(CATOmxBaseBigSet::LocateItem(TMgr(), item)); }

  /** @see CATOmxSet::Remove, item MUST be non NULL */
  inline ValueType Remove(KeyType item) { return reinterpret_cast<ValueType>(CATOmxBaseBigSet::RemoveItem(TMgr(), item)); }

  /** @see CATOmxSet::RemoveAll */
  inline void RemoveAll(void) { CATOmxBaseBigSet::RemoveAll(TMgr()); }

  /** @see CATOmxSet::Reserve */
  inline void Reserve(unsigned int iSize) { CATOmxBaseBigSet::Reserve(TMgr(), iSize); }

  /** @see CATOmxSet::Iterator */
  inline IteratorType Iterator() const { return IteratorType(CATOmxBaseBigSet::Iterator(TMgr())); }
  inline ConstIteratorType ConstIterator() const { return ConstIteratorType(CATOmxBaseBigSet::Iterator(TMgr())); }

  /** @see CATOmxSet::NextInBucket  */
  inline ValueType NextInBucket(CATHashKey iHashKey, int& ioIndex) const { return (ValueType)CATOmxBaseBigSet::NextInBucket(iHashKey, ioIndex); }

  /** range for support */
  inline CATOmxSTLIter<T> begin() const { return CATOmxSTLIter<T>(Iterator()); }
  inline CATOmxSTLIter<T> end()   const { return CATOmxSTLIter<T>(); }

private:
  CATOmxBigSet(const CATOmxBigSet<T, TMgr> &collec);              //this object 
  CATOmxBigSet<T, TMgr>& operator=(const CATOmxBigSet<T, TMgr> &collec);   //is NOT copiable
};

#endif
