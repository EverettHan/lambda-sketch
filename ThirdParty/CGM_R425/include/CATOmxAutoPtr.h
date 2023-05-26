#ifndef __CATOmxAutoPtr_H
#define __CATOmxAutoPtr_H

#include "CATOmxPortability.h"
#include "CATOmxSR.h"

/**
 * smart pointer class for objects handled through new/delete
 *
 * you can use it to replace
 *   XXX* ptr = new XXX();
 *   foo(*ptr);
 *   delete ptr;
 * by RAII alternative
 *   CATOmxAutoPtr<XXX> ptr{new XXX};
 *   foo(*ptr);
 *   //ptr deletion is ensured by CATOmxAutoPtr
 *
 * It is a cheap alternative for std::unique_ptr
 *
 * It does not work for arrays (objects handled through new[]/delete[]) nor for malloc/free memory blocks
 */
template<typename Type>
class CATOmxAutoPtr
{
  Type* m_ptr;
public:
  /**
   * constructor, iPtr will be automatically delete'd at the end of the scope
   */
  CATOmxAutoPtr(Type* iPtr = NULL) :m_ptr(iPtr) { }

  /**
   * Assign a new pointer, old pointer is deleted.
   */
  CATOmxAutoPtr& operator=(Type* ptr)
  {
    OMX_STATIC_ASSERT(!std::is_base_of<IUnknown, Type>::value, "CATOmxAutoPtr must not be used on IUnknown descendants");
    delete m_ptr;
    m_ptr = ptr;
    return *this;
  }

  /**
   * Take ownership of the pointer
   */
  Type* GiveBack()
  {
    Type* ptr = m_ptr;
    m_ptr = NULL;
    return ptr;
  }

  /** get pointer*/
  Type* Ref() const { return m_ptr; }
  Type* Get() const { return m_ptr; }

  /** cast operators */
  operator Type*() const { return m_ptr; }

  /** operator -> */
  Type* operator->() const { return &this->operator*(); }

  // operator *
  Type& operator*() const
  {
    if (!m_ptr) CATOmx::Internals::NullPointerAssertion();
    return *m_ptr;
  }

  /**natural reference operator. Asserts if internal pointer is not NULL.*/
  Type** operator&() { return &AsPtrRef(); }
  Type*& AsPtrRef()
  {
    if (m_ptr) CATOmx::Internals::NotNullPointerAssertion();
    return m_ptr;
  }

  /**destructor, pointer is deleted*/
  ~CATOmxAutoPtr() { this->operator=(NULL); }

#if OMX_CXX11 == 1
  OMX_STATIC_ASSERT(!std::is_pointer<Type>::value, "CATOmxAutoPtr parameter must not be a pointer type (use CATOmxAutoPtr<T> and not CATOmxAutoPtr<T*>)");
  OMX_STATIC_ASSERT(!std::is_array<Type>::value, "CATOmxAutoPtr parameter must not be an array type (use std::unique_ptr<T[]> and not CATOmxAutoPtr<T[]>)");

  /** copy is forbidden */
  CATOmxAutoPtr& operator=(const CATOmxAutoPtr&) = delete;
  CATOmxAutoPtr(const CATOmxAutoPtr&) = delete;

  /** move constructions */
  CATOmxAutoPtr& operator=(CATOmxAutoPtr&& other)
  {
    Type* ptr = m_ptr;
    m_ptr = other.m_ptr;
    other.m_ptr = ptr;
    return *this;
  }
  CATOmxAutoPtr(CATOmxAutoPtr&& other) :m_ptr(other.m_ptr) { other.m_ptr = nullptr; }
#else
private:
  CATOmxAutoPtr<Type>& operator=(const CATOmxAutoPtr<Type>&);
#if defined(_WINDOWS_SOURCE) || (defined(_AIX_SOURCE) && !defined(__ibmxl__))
private:
  CATOmxAutoPtr(const CATOmxAutoPtr<Type>&);
#else
  /**
   * Problem with gcc compiler with the line
   * CATOmxAutoPtr<int> p = new int;
   * On windows/aix, it calls
   *    CATOmxAutoPtr<int>(int *)
   * With gcc, it calls
   *   CATOmxAutoPtr<int>(int *) (cast the int* to a CATOmxAutoPtr<int>)
   * and then
   *   CATOmxAutoPtr<int>(const CATOmxAutoPtr<Type>& ) (build an AutoPtr from the other one)
   * this leads to compilation error as copy constructor is private
   * Bypass: autorise copy constructor for these OS.
   */
public:
  CATOmxAutoPtr(const CATOmxAutoPtr<Type>& iPtr) :m_ptr(iPtr.m_ptr) { const_cast<CATOmxAutoPtr<Type>&>(iPtr).m_ptr = NULL; }
#endif
#endif
};

#endif
