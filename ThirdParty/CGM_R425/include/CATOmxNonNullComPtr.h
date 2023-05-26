#ifndef CATOmxNonNullComPtr_H
#define CATOmxNonNullComPtr_H

#include "CATOmxPortability.h"
#include "CATOmxSR.h"

/**
 * smart pointer dedicated to non null COM objects
 * stored pointer is kept AddRef'ed
 *
 * CATOmxNonNullComPtr can be used as a pointer
 *   CATOmxNonNullComPtr<T> nnptr = ...;
 *   Do(nnptr);
 *   Do(*nnptr);
 *   nnptr->Do();
 * except for construction which requires a reference:
 *   T& ref = ...;
 *   CATOmxNonNullComPtr<T> nnptr{ref};
 *
 * const types are supported:
 *   const T* ptr = ...;
 *   CATOmxNonNullComPtr<const T> nnptr{*ptr};
 *
 * pointer cannot be null, the following compiles but is irrelevant
 * CATOmxNonNullComPtr<T> nnptr{ref};
 * if(nnptr) //useless check, cannot be null
 *   nnptr->Do();
 */
template<class Type>
class CATOmxNonNullComPtr final
{
  Type* m_ptr;

  template<class Type2>
  static Type2& ConstCast(const Type2& ref) { return const_cast<Type2&>(ref); }
public:
  /**
   * constructors, pointer is AddRef'ed
   */
  CATOmxNonNullComPtr(Type& ref) :m_ptr(&ref) { ConstCast(ref).AddRef(); }
  CATOmxNonNullComPtr(const CATOmxNonNullComPtr& ptr) : CATOmxNonNullComPtr(*ptr.m_ptr) {}
  template<class Type2>
  CATOmxNonNullComPtr(const CATOmxNonNullComPtr<Type2>& ptr) : CATOmxNonNullComPtr(*ptr.m_ptr) {}

  /**
   * copy operators
   */
  CATOmxNonNullComPtr& operator=(const CATOmxNonNullComPtr& ptr)
  {
    return this->operator=(ptr.Ref());
  }
  template<class Type2>
  CATOmxNonNullComPtr& operator=(const CATOmxNonNullComPtr<Type2>& ptr)
  {
    return this->operator=(ptr.Ref());
  }
  CATOmxNonNullComPtr& operator=(Type& ref)
  {
    ConstCast(ref).AddRef();
    ConstCast(*m_ptr).Release();
    m_ptr = &ref;
    return *this;
  }
  CATOmxNonNullComPtr& operator=(CATOmxNonNullComPtr&& other)
  {
    Type* ptr = m_ptr;
    m_ptr = other.m_ptr;
    other.m_ptr = ptr;
    return *this;
  }

  /** 'steal', pointer is not AddRef'ed */
  CATOmxNonNullComPtr(Type& ref, CATOmxSRSharingMode) :m_ptr(&ref) { }
  CATOmxNonNullComPtr& Steal(Type& ref)
  {
    ConstCast(*m_ptr).Release();
    m_ptr = &ref;
    return *this;
  }

  /** destructor, pointer is Release'd */
  ~CATOmxNonNullComPtr() { ConstCast(*m_ptr).Release(); }

  Type& Ref() const { return *m_ptr; }
  /** basic pointer operators */
  operator Type* () const { return &Ref(); }
  Type& operator*() const { return Ref(); }
  Type* operator->() const { return &Ref(); }

  /** prohibited */
  CATOmxNonNullComPtr() = delete;
  Type** operator&() const = delete;
};

#endif
