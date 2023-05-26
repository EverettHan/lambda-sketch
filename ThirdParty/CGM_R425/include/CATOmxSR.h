/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxSR_h__
#define __CATOmxSR_h__

#include "CATOmxKernel.h"
#include "CATDataType.h"
#include "IUnknown.h"
#include "CATOmxIter.h"
#include "CATOmxPortability.h"
#include "CATOmxCxxPortability.h"

class CATBaseUnknown;
class CATBaseUnknown_var;

/** Use only Steal value */
enum CATOmxSRSharingMode { Steal, /*do not use*/DoShare };

namespace CATOmx
{
  namespace Internals
  {
    OMX_Cxx11_NORETURN ExportedByCATOmxKernel void NullPointerAssertion();
    OMX_Cxx11_NORETURN ExportedByCATOmxKernel void NotNullPointerAssertion();
    ExportedByCATOmxKernel void SetComPtr(IUnknown*& dst, IUnknown* src);
    ExportedByCATOmxKernel CATOmxBaseIter* Iterator(IUnknown* item);
  }
}

/**
 * Smart pointer allowing automatic AddRef/Release handling on IUnknown subclasses.
 * @href http://osmwebdsy/wiki/index.php/CATOmxSR_Usage
 */
template <class Type>
class CATOmxSR
{
  OMX_STATIC_ASSERT_CLASS_SCOPE(std::is_class<Type>::value, "CATOmxSR must be used only on IUnknown descendants")
public:
  /** constructors */
  inline CATOmxSR() :sr(NULL) {}
  inline CATOmxSR(const Type* iPointer) : sr(const_cast<Type*>(iPointer)) { AddRef(iPointer); }
  inline CATOmxSR(const CATOmxSR & iSR) : sr(iSR.sr) { AddRef(iSR.sr); }
  template<class OtherType>
  inline CATOmxSR(const CATOmxSR<OtherType>& iSR) : sr(iSR.Get()) { AddRef(iSR.Get()); }


  /** assignment operators. */
  inline CATOmxSR & operator = (const Type* iPointer)
  {
    CATOmx::Internals::SetComPtr((IUnknown*&)sr, (IUnknown*)iPointer);
    return *this;
  }
  inline CATOmxSR & operator = (const CATOmxSR & iSR) { return this->operator=(iSR.sr); }
  template<class OtherType>
  inline CATOmxSR & operator = (const CATOmxSR<OtherType> & iSR) { return this->operator=(iSR.Get()); }

  /**
   * Steal a pointer assuming it has been AddRef'ed
   * Input pointer is assigned to input pointer without additional AddRef
   * but it will be nevertheless Release'd when the smart pointer dies.
   *
   * Use it in the following situation:
   * CATOmxSR<XXX> xxx(FunctionThatReturnsAnAddrefedPointer(), Steal);
   */
  inline CATOmxSR(const Type* iPointer, CATOmxSRSharingMode iMode) : sr(const_cast<Type*>(iPointer))
  {
    if (iMode != ::Steal)
      AddRef(iPointer);
  }
  /**
   * see previous constructor
   */
  inline CATOmxSR& Steal(const Type* iPointer)
  {
    Release(sr);
    sr = const_cast<Type*>(iPointer);
    return *this;
  }

  /**
   * The complementary method to Steal : extracts the AddRef'd (unless NULL) pointer
   * from the smart reference and set it's internal pointer to NULL.
   * Useful to return an AddRef'd pointer obtained from a method retuning a smart pointer.
   *
   * returned pointer must be Release'd by caller
   */
  inline Type* GiveBack()
  {
    Type* tmp = sr;
    sr = NULL;
    return tmp;
  }

  /**
   * Swaps (exchanges) the content of this (CATOmxSR) and iOther.
   * This does not perform any AddRef or Release as none is required, this can be a bit tricky when tracking a MLK though.
   */
  inline CATOmxSR& Swap(CATOmxSR & iOther)
  {
    Type* tmp = sr;
    sr = iOther.sr;
    iOther.sr = tmp;
    return *this;
  }

  /** return pointer */
  inline Type* Ref() const { return sr; }
  inline Type* Get() const { return sr; }

  /**
   * cast operator
   */
  inline operator Type*() const { return sr; }

  /**
   * Pointer to member operator
   * Asserts if null pointer
   */
  inline Type* operator->() const
  {
    OMX_STATIC_ASSERT(std::is_base_of<IUnknown, Type>::value, "CATOmxSR must be used only on IUnknown descendants");
    if (!sr) CATOmx::Internals::NullPointerAssertion();
    return sr;
  }

  /**
   * Dereference operator
   * Asserts if null pointer
   */
  inline Type& operator*() const
  {
    if (!sr) CATOmx::Internals::NullPointerAssertion();
    return *sr;
  }

  /** Compute hash key. */
  inline unsigned int Hash() const { return CATPtrToUINT32(sr); }
  inline unsigned int hash() const { return Hash(); }

  /**
   * natural reference operator.
   * Asserts if internal pointer is not NULL.
   */
  inline Type** operator&()
  {
    if (sr)
      CATOmx::Internals::NotNullPointerAssertion();
    return &sr;
  }
  /**Same as above.*/
  inline Type*& AsPtrRef() { return *this->operator&(); }

  /**
   * obsolete, use CATOmxQIPtr
   */
  inline CATOmxSR& SetByQI(const IUnknown* iPtr)
  {
    Type* ptr = NULL;
    if (iPtr)
      const_cast<IUnknown*>(iPtr)->QueryInterface(Type::ClassId(), (void**)&ptr);
    return Steal(ptr);
  }

  /**
   * Returns an iterator on internal pointer.
   */
  inline CATOmxIter<Type> Iterator() const { return CATOmx::Internals::Iterator((IUnknown*)sr); }

  /**
   * Set pointer to NULL.
   */
  inline CATOmxSR& Clear() { return Steal(NULL); }

#ifdef DS_CXX11_SUPPORT_MOVE_SEMANTIC 
  /** move semantics */
  inline CATOmxSR(CATOmxSR&& iSR) :sr(iSR.sr) { iSR.sr = NULL; }
  template<class OtherType>
  inline CATOmxSR(CATOmxSR<OtherType>&& iSR) : sr(iSR.GiveBack()) {}
  inline CATOmxSR& operator=(CATOmxSR&& iSR)
  {
    Type* tmp = sr;
    sr = iSR.sr;
    iSR.sr = tmp;
    return *this;
  }
#endif

  inline ~CATOmxSR() { Release(sr); }

private:
  Type* sr;

  // Notice that CATOmxSR used to work on incomplete types
  // As a consequence the C-cast hereunder is required for compatibility
  // The downsides are:
  //   it inhibits buildtime errors (tranformed to runtime crashes)
  //   it is broken in case of multiple inheritance
  inline static void Release(const Type* pointer) { if (pointer) ((IUnknown*)pointer)->Release(); }
  inline static void AddRef(const Type* pointer) { if (pointer) ((IUnknown*)pointer)->AddRef(); }

  // Try to prevent broken constructions
  template<class OtherType> inline CATOmxSR(const CATOmxSR<OtherType>&, CATOmxSRSharingMode);
  template<class OtherType> inline CATOmxSR& Steal(const CATOmxSR<OtherType>&);
};

/**
 * Same as AsPtrRef helper which unset the CATOmxSR before getting the Type*&.
 * Usefull for pattern like
 * <pre>
 * CATOmxSR<Foo> p;
 * while( SUCCEEDED(iterator.Next(SafePtrRef(p)) ) {
 *    //use p.
 * }
 * </pre>
 */
template<class Type>
inline Type *& SafePtrRef(CATOmxSR<Type> & iSR) { return iSR.Clear().AsPtrRef(); }

/**
 * Same as SafePtrRef helper which unset the CATOmxSR before getting the Type**.
 * Usefull for pattern like
 * <pre>
 * CATOmxSR<Foo> p;
 * while( SUCCEEDED(iterator.Next(SafePtrPtr(p)) ) {
 *    //use p.
 * }
 * </pre>
 */
template<class Type>
inline Type ** SafePtrPtr(CATOmxSR<Type> & iSR) { return &iSR.Clear(); }

#include "CATOmxSRLegacy.h"

#endif // __CATOmxSR_h__
