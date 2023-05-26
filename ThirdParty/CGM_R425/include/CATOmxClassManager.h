/**
* @level Private
* @usage U1
*/

#ifndef CATOmxClassManager_H
#define CATOmxClassManager_H

#include "CATOmxPortability.h"
#include "CATOmxCollecManager.h"
#include "CATAssert.h" //required in DELSTTApplicativeContainerServices.cpp
#if OMX_CXX11 == 1
#include <type_traits>
#endif

namespace CATOmx
{
  // assert
  OMX_Cxx11_NORETURN ExportedByCATOmxKernel void NotImplementedAssertion();
}

/**
 * a dummy manager that does not implement comparison and hash (assert(0)).
 * do not use directly use CATOmxClassManager instead
 */
struct ExportedByCATOmxKernel CATOmxNoCompareManager :public CATOmxBasicTypeManager
{
  /** Constructor. */
  CATOmxNoCompareManager(unsigned int iSizeOf) : CATOmxBasicTypeManager(iSizeOf) {}

  /** not implemented (assert)*/
  virtual void InitVect(void* to, unsigned sz)	const;
  virtual int Compare(const void* v1, const void * v2) const;
  virtual CATHashKey Hash(const void * v) const;
};

/**
 * do not use directly, use CATOmxClassManager
 */
template<class T>
struct CATOmxClassManagerNoCtor : public CATOmxNoCompareManager
{
  //OMX_STATIC_ASSERT_CLASS_SCOPE(std::is_class<T>::value,"CATOmxClassManager must be used on class types") //still several misuses to FIX

  /**
  * Constructor.
  */
  CATOmxClassManagerNoCtor() :CATOmxNoCompareManager(sizeof(T)) {}

  /**
  * InitVect (copy constructor).
  */
  virtual void InitVect(void *to, const void *from, unsigned sz)	const
  {
    T* A = (T*)to;
    T* B = (T*)from;
    while (sz--)
      new(A++) T(*B++);
  }

  /**
   * SetVect (copy).
   * uses T copy constructor if provided
   * else will compile but assert at runtime
   */
  virtual void SetVect(void *to, const void *from, unsigned sz) const
  {
    _SetVect<T>(reinterpret_cast<T*>(to), reinterpret_cast<T const*>(from), sz);
  }

  /**
  * UnsetVect (destructor).
  */
  virtual void UnsetVect(void *to, unsigned sz) const
  {
    T* A = (T*)to;
    while (sz--)
      A++->~T();
  }

protected:
  /** helper for implementing Hash/Compare */
  inline static const T& Cast(const void* p) { return *reinterpret_cast<const T*>(p); }

private:
#if OMX_CXX11 == 1
  //implementation of SetVect for classes that do not provide a copy constructor
  template<typename U>
  /*SFINAE hack*/ typename std::enable_if<!std::is_assignable<U&, U const &>::value, void>::type
    _SetVect(U *A, U const *B, unsigned sz) const
  {
    CATOmx::NotImplementedAssertion();
  }

  template<typename U>
  /*SFINAE hack*/typename std::enable_if< std::is_assignable<U&, U const &>::value, void>::type
#else
  template<typename U>
  void
#endif
    _SetVect(U *A, U const *B, unsigned sz) const
  {
    if (B > A)
    {
      while (sz--)
        *A++ = *B++;
    }
    else
    {
      A += sz;
      B += sz;
      while (sz--)
        *--A = *--B;
    }
  }
};

namespace CATOmx
{
  namespace Internal
  {
#if OMX_CXX11 == 1
    //GenericHash for classes which provide Hash member function
    template<typename T>
    inline auto GenericHash(const T* obj) -> decltype(obj->Hash())
    {
      return obj->Hash();
    }

    //GenericHash for classes which provide ComputeHashKey member function
    template<typename T>
    inline auto GenericHash(const T* obj) -> decltype(obj->ComputeHashKey())
    {
      return obj->ComputeHashKey();
    }

    //default GenericHash (asserts)
    inline unsigned int GenericHash(const void* obj)
    {
      CATOmx::NotImplementedAssertion();
    }

    //GenericCompare for classes which provide Compare static member function
    template<typename T>
    inline auto GenericCompare(const T* obj1, const T* obj2) -> decltype(T::Compare(*obj1, *obj2))
    {
      return T::Compare(*obj1, *obj2);
    }

    //GenericCompare for classes which provide Compare member function
    template<typename T>
    inline auto GenericCompare(const T* obj1, const T* obj2) -> decltype(obj1->Compare(*obj2))
    {
      return obj1->Compare(*obj2);
    }

    //default GenericCompare (asserts)
    inline int GenericCompare(const void* obj1, const void* obj2)
    {
      CATOmx::NotImplementedAssertion();
    }
#endif
  }
}

/**
* This template MUST be used to generate automatically the manager of a C++ class.
* Compare and Hash are not implemented on purpose (usually useless and not implemented on C++ classes),
* if you need these inherit from this class and override these.
*
* Your C++ class must provide
*   a public copy constructor
*   a public destructor
* some operations might require
*   a public default constructor (required for example by CATOmxArray::Resize or CATOmxOHMap::operator[])
*   a public copy operator       (required for example by CATOmxArray::RemoveAt)
*
* @href http://osmwebdsy/wiki/index.php/CATOmxClassManager
*/
template<class T>
struct CATOmxClassManager : public CATOmxClassManagerNoCtor<T>
{
  /**
  * InitVect (default constructor).
  */
  virtual void InitVect(void *to, unsigned sz) const
  {
    _InitVect(reinterpret_cast<T*>(to), sz);
  }

private:
#if OMX_CXX11 == 1
  //implementation of InitVect for classes that do not provide a default constructor
  template<typename U>
  /*SFINAE hack*/ typename std::enable_if<!std::is_default_constructible<U>::value, void>::type
    _InitVect(U* A, unsigned sz) const
  {
    CATOmx::NotImplementedAssertion();
  }

  template<typename U>
  /*SFINAE hack*/ typename std::enable_if<std::is_default_constructible<U>::value, void>::type
#else
  template<typename U>
  void
#endif
    _InitVect(U* A, unsigned sz) const
  {
    while (sz--)
      new(A++) U();
  }

#if OMX_CXX11 == 1
  /**
   * implementation of CATOmxCollecManager::Compare by delegation to T::Compare
   */
  int Compare(const void* p1, const void* p2) const override
  {
    return CATOmx::Internal::GenericCompare(&this->Cast(p1), &this->Cast(p2));
  }

  /**
 * implementation of CATOmxCollecManager::Compare by delegation to T::Hash or T::ComputeHashKey
 */
  CATHashKey Hash(const void* p) const override
  {
    return CATOmx::Internal::GenericHash(&this->Cast(p));
  }
#endif
};

#endif
