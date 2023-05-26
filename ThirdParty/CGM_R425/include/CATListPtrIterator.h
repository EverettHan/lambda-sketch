#ifndef CATListPtrIterator_H
#define CATListPtrIterator_H

#include "CATOmxPortability.h"
#include "CATListPV.h"
#include "CATOmxListPtrHelpers.h"
#include "CATRawCollPVIterator.h"
#include <type_traits>

/**
 * internal implementation of STL like iterators on CATListPtr lists.
 * do not use directly.
 * use CATListPtrForRangeWrapper or CATListPtrAutoReleaser
 */
template<class CATListPtrXXX>
class CATListPtrIterator : private CATRawCollPVIterator
{
  typedef decltype(*static_cast<const CATListPtrXXX&>(CATListPtrXXX())[0]) RefToPointerType; //should be CATIXXX&
  typedef typename std::remove_reference<RefToPointerType>::type PointerType; //should be CATIXXX
public:
  inline CATListPtrIterator(const CATListPtrXXX& list, bool begin) :CATRawCollPVIterator(_CATOmxAsRawCollPV<const CATListPtrXXX>(list), begin) { }

  /** the bare necessary for range-for */
  inline PointerType& operator*() const { return **reinterpret_cast<PointerType**>(m_cur); }
  inline bool operator!=(const CATListPtrIterator& other) const { return m_cur != other.m_cur; }
  inline CATListPtrIterator& operator++() { MoveNext(); return *this; }
};

#endif
