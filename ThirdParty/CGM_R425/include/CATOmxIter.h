/**
 * @level Private
 * @usage U1
**/
#ifndef __CATOmxIter_h__
#define __CATOmxIter_h__

#include "CATOmxPortability.h"
#include "CATOmxBaseIterVar.h"
#include "CATOmxGetIID.h"
#include "CATOmxDeprecated.h"

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)
// forwarding stuff from std namespace is "undefined behavior"
namespace std
{
  struct input_iterator_tag;
  struct bidirectional_iterator_tag;
  struct random_access_iterator_tag;
}
#else
// and does not work with clang because it uses inline namespace's
// problem is that this include comes with a whole jungle of headers.
// on windows more than 20000 lines + 1 compilation warning per source (xlocale(341): warning C4530: C++ exception handler used, but unwind semantics are not enabled. Specify /EHsc)
#include <iterator>
#endif

template<class Type> class CATOmxSTLIter;

/**
 * A pointer iterator.
 * <pre>
 * CATOmxIter<IUnkown> itr(fromSomething);
 * IUnkown* elt = NULL;
 * while (elt = itr.Next()) {
 *   // do something on elt
 * }
 * </pre>
 * @href http://osmwebdsy/wiki/index.php/CATOmxIter_Usage
 */
template<typename T>
class CATOmxIter : private CATOmxBaseIterVar
{
public:
  typedef T Type;
  typedef T ValueType;

  using CATOmxBaseIterVar::PrivateStrip;
  using CATOmxBaseIterVar::PrivateCopy;
  using CATOmxBaseIterVar::Size;
  using CATOmxBaseIterVar::Steal;

#if OMX_CXX11 == 1
  inline CATOmxIter(CATOmxIter && iter) : CATOmxBaseIterVar(iter.m_iter) { iter.m_iter = NULL; }
  inline CATOmxIter &operator =(CATOmxIter && iter) { CATOmxBaseIter *o = m_iter; m_iter = iter.m_iter; iter.m_iter = o; return *this; }
#endif

  /**
   * Create an empty iterator
   */
  inline CATOmxIter<T>() : CATOmxBaseIterVar(NULL) {}

  /**
   * internal constructor (must be used only by collections implementations)
   * notice that input pointer is "stolen"
   */
  inline CATOmxIter<T>(CATOmxBaseIter* iter) : CATOmxBaseIterVar(iter) {}

  /**
   * Duplicate an iterator.
   * @param to_copy is the source iterator
   */
  inline void Clone(const CATOmxIter<T>& to_copy) { CloneIterator(to_copy); }

  /**
   * Share an iterator.
   * @param to_copy is the source iterator
   */
  inline CATOmxIter<T>(const CATOmxIter<T>& to_copy) : CATOmxBaseIterVar(NULL)
  {
    AssignIterator(to_copy);
  }
  /**
   * Share an iterator.
   * @param to_copy is the source iterator
   */
  inline CATOmxIter<T>& operator=(const CATOmxIter<T>& to_copy)
  {
    AssignIterator(to_copy);
    return *this;
  }

  /**
   * append an iterator.
   * @param to_copy is the source iterator
   */
  inline CATOmxIter<T>& operator+=(const CATOmxIter<T>& to_copy)
  {
    AppendIterator(to_copy);
    return *this;
  }
  /**
   * @nodoc
   * return the next item.
   * @return the next item or NULL if nothing to eat
   */
  inline T* NextItem(void) { return (T*)nextItem(); }
  /**
   * return the next item.
   * @return the next item or NULL if nothing to eat
   */
  inline T* Next(void) { return (T*)nextItem(); }

  /** genericity */
  inline CATOmxIter<T> Iterator() const { return *this; }

  /** range for support */
  inline CATOmxSTLIter<T> begin() const;
  inline CATOmxSTLIter<T> end()   const;
};

/**
 * c++11 range-based for loop adapter for CATOmxIter
 * do not use or reference explicity
 */
template<typename T>
class CATOmxSTLIter
{
public:
  inline CATOmxSTLIter() : m_cur(NULL) {}
  inline CATOmxSTLIter(const CATOmxIter<T>& iIter) : m_iter(iIter) { m_cur = m_iter.Next(); }

  inline CATOmxSTLIter<T>& operator++() { m_cur = m_iter.Next(); return *this; }
  //required on linux R426,
  //ObjectModelerCollection.tst/CATOmxKernelUT.m/src/TestAlgorithmIntegration.cpp:26:56: error: no matching function for call to 'inserter(CATOmxSet<IUnknown>&, CATOmxSTLIter<IUnknown>)'
  // 26 |     std::copy(vect1.begin(), vect1.end(), std::inserter(set1, set1.end()));
  OMX_DEPRECATED("use prefix version") CATOmxSTLIter<T> operator++(int) { CATOmxSTLIter<T> tmp(*this); ++(*this); return tmp; }

  inline T& operator*() const { return *m_cur; }
  inline T* operator->() const { return &this->operator*(); }

  inline bool operator!=(const CATOmxSTLIter& other) const { return m_cur != other.m_cur; }
  //Required for CATMatVisuTools.cpp
  inline bool operator==(const CATOmxSTLIter& other) const { return m_cur == other.m_cur; }

#if OMX_CXX11 == 1
  inline CATOmxSTLIter(CATOmxIter<T>&& iIter) : m_iter(std::move(iIter)) { m_cur = m_iter.Next(); }
  /** integration with <algorithm> (could not make it compile on AIX, but as there are no lambdas anyway...)*/
  using iterator_category = std::input_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T * ;
  using reference = T & ;
#endif

private:
  CATOmxIter<T> m_iter;
  T* m_cur;
};

template<typename T> CATOmxSTLIter<T> CATOmxIter<T>::begin() const { return CATOmxSTLIter<T>(*this); }
template<typename T> CATOmxSTLIter<T> CATOmxIter<T>::end()   const { return CATOmxSTLIter<T>(); }

/**
 * Allow conversion from CATOmxIter<T2> to CATOmxIter<T1> when T2 is a subclass of T1.
 */
template <typename T1, typename T2>
inline CATOmxIter<T1> iterator_cast(const CATOmxIter<T2> &iT2, T1 *iType = 0)
{
  T2 *assertT2_is_subclass_of_T1 = 0;
  iType = assertT2_is_subclass_of_T1;
  return iT2.PrivateCopy();
}

/**
 * Allow conversion from CATOmxIter<T2> to CATOmxIter<T1> (static_cast rules).
 */
template <typename T1, typename T2>
inline CATOmxIter<T1> iterator_static_cast(const CATOmxIter<T2> &iT2, T1 *iType = 0)
{
  (void)static_cast<T1*>((T2*)0);
  return iT2.PrivateCopy();
}

/**
 * Allow conversion from CATOmxIter<T2> to CATOmxIter<T1> (reinterpret_cast rules).
 * Use with care.
 */
template <typename T1, typename T2>
inline CATOmxIter<T1> iterator_reinterpret_cast(const CATOmxIter<T2> &iT2, T1 *iType = 0)
{
  (void)reinterpret_cast<T1*>((T2*)0);
  return iT2.PrivateCopy();
}

/**
 * Allow conversion of CATOmxIter<T> to CATOmxIter<const T>
 */
template <typename T>
inline CATOmxIter<const T> iterator_add_const(const CATOmxIter<T> &iT, T* iDummy = 0) { return iT.PrivateCopy(); }

/**
 * Allow conversion of CATOmxIter<const T> to CATOmxIter<T> (const_cast rules)
 * Use it only to solve API incompatibility problems,
 * not because you need to modify the items.
 * Modifying the items will lead to bugs/crashes.
 */
template <typename T>
inline CATOmxIter<T> iterator_const_cast(const CATOmxIter<const T> &iT, T* iDummy = 0) { return iT.PrivateCopy(); }

/**Internal usage*/
ExportedByCATOmxKernel CATOmxBaseIter* CATOmxQIIterator(CATOmxBaseIter*, const IID&);

/**
 * Filters a CATOmxIter using QueryInterface.
 * Usage:
 * CATOmxIter<SomeClass> iter1;
 * CATOmxIter<SomeInterface> iter2 = iterator_qi_cast<SomeInterface,SomeClass>(iter1);
 * SomeInterface* pItf;
 * while( pItf = iter2.Next() )
 * {
 *   //work
 * }
 */
template<typename T1, typename T2>
inline CATOmxIter<T1> iterator_qi_cast(CATOmxIter<T2> iT2, T1 *iType = 0)
{
  OMX_STATIC_ASSERT(std::is_base_of<IUnknown, T2>::value, "iterator_qi_cast must be used only on IUnknown descendants");
  return CATOmxQIIterator(iT2.PrivateStrip(), CATOmxGetIID<T1>((T1*)0));
}

#endif
