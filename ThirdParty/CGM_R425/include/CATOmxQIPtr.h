#ifndef __CATOmxQIPtr_H
#define __CATOmxQIPtr_H

#include "CATOmxKernel.h"
#include "CATOmxSR.h"
#include "CATBaseUnknown_var.h"
#include "CATOmxGetIID.h"
#include "CATOmxDeprecated.h"

class CATBaseUnknown;

/**DO NOT USE*/
ExportedByCATOmxKernel IUnknown* CATOmxQI(const IUnknown* iPtr, const IID& iIID, CATOmxSRSharingMode iMode);

/**DO NOT USE*/
ExportedByCATOmxKernel int CATOmxIsNull(const CATBaseUnknown* iPtr);

/**DO NOT USE*/
ExportedByCATOmxKernel int CATOmxIsNull(const IUnknown* iPtr);

/**DO NOT USE*/
ExportedByCATOmxKernel int CATOmxAreCOMEqual(const CATBaseUnknown* iPtr1, const CATBaseUnknown* iPtr2);

/**DO NOT USE*/
ExportedByCATOmxKernel int CATOmxAreCOMEqual(const IUnknown* iPtr1, const IUnknown* iPtr2);

/**
 * Smart pointer allowing automatic QueryInterface management.
 * Type must be an interface type (with a static ClassId method returning its IID or CATOmxGetIID correctly redefined).
 * Does not work on IUnknown.
 * Behavior is unspecified on implementation classes.
 */
template<class T>
class CATOmxQIPtr : public CATOmxSR<T>
{
  inline static T* QI(const IUnknown* iPtr, CATOmxSRSharingMode iMode = ::DoShare) { return static_cast<T*>(CATOmxQI(iPtr, CATOmxGetIID<T>(0), iMode)); }
public:
  //constructors

  /**default constructor*/
  inline CATOmxQIPtr() {}

  /**Initialize with interface pointer*/
  inline CATOmxQIPtr(const T* iPtr) :CATOmxSR<T>(iPtr) {}

  /**Initialize with interface pointer*/
  inline CATOmxQIPtr(T* iPtr, CATOmxSRSharingMode imode = DoShare) : CATOmxSR<T>(iPtr, imode) {}

  /**Initialize with pointer to other interface (QueryInterface)*/
  inline CATOmxQIPtr(const IUnknown* iPtr) : CATOmxSR<T>(QI(iPtr, ::DoShare), ::Steal) {}

  /**Initialize with pointer to other interface (QueryInterface)*/
  inline CATOmxQIPtr(IUnknown* iPtr, CATOmxSRSharingMode iMode) : CATOmxSR<T>(QI(iPtr, iMode), ::Steal) {}

  /**Initialize with other smart reference*/
  inline CATOmxQIPtr(const CATOmxSR<T>& iSR) : CATOmxSR<T>(iSR) {}

  /**Initialize with smart reference to other interface (QueryInterface)*/
  template<class T2>
  inline CATOmxQIPtr(const CATOmxSR<T2>& iSR) : CATOmxSR<T>(QI((const IUnknown*)iSR.Get()), ::Steal) {}

  /**Initialize with system var (QueryInterface)*/
  inline CATOmxQIPtr(const CATBaseUnknown_var& iVar) : CATOmxSR<T>(QI(iVar.operator CATBaseUnknown*()), ::Steal) {}

  //assignment operators

  /**assign interface pointer*/
  inline CATOmxQIPtr<T>& operator=(const T* iPtr) { return static_cast<CATOmxQIPtr<T>&>(CATOmxSR<T>::operator=(iPtr)); }

  /**assign other interface pointer (QueryInterface)*/
  inline CATOmxQIPtr<T>& operator=(const IUnknown* iPtr) { return static_cast<CATOmxQIPtr<T>&>(CATOmxSR<T>::Steal(QI(iPtr))); }

  /**assign smart reference*/
  inline CATOmxQIPtr<T>& operator=(const CATOmxSR<T>& iSR) { return static_cast<CATOmxQIPtr<T>&>(CATOmxSR<T>::operator=(iSR)); }

  /**assign other interface smart reference (QueryInterface)*/
  template<class T2>
  inline CATOmxQIPtr<T>& operator=(const CATOmxSR<T2>& iSR) { return this->operator=((const IUnknown*)iSR.Get()); }

  /**assign system var (QueryInterface)*/
  inline CATOmxQIPtr<T>& operator=(const CATBaseUnknown_var& iVar) { return static_cast<CATOmxQIPtr<T>&>(CATOmxSR<T>::Steal(QI(iVar.operator CATBaseUnknown*()))); }


  /**@return TRUE if pointer is NULL of if its CATBaseUnknown implementation is CATBaseUnknown::IsNull().*/
  inline int IsNull() const { return CATOmxIsNull(this->Get()); }

  /**return TRUE if pointer are "COM" equal*/
  inline int IsEqual(const CATBaseUnknown* iPtr) const { return CATOmxAreCOMEqual(this->Get(), iPtr); }

  /**return TRUE if pointer are "COM" equal*/
  inline int IsEqual(const IUnknown* iPtr) const { return CATOmxAreCOMEqual(this->Get(), iPtr); }

  /**Steal input pointer.*/
  inline CATOmxQIPtr<T>& Steal(const T* iPtr) { return static_cast<CATOmxQIPtr<T>&>(CATOmxSR<T>::Steal(iPtr)); }

  /**Steal input pointer on other interface (QueryInterface).*/
  inline CATOmxQIPtr<T>& Steal(const IUnknown* iPtr) { return static_cast<CATOmxQIPtr<T>&>(CATOmxSR<T>::Steal(QI(iPtr, ::Steal))); }

  /**FIXME CATBaseUnknown_var and IUnknown...*/
  inline CATBaseUnknown_var AsVar() const { return CATBaseUnknown_var((CATBaseUnknown*)this->Get()); }

private:
  //private because causes compilation errors on UNIXs. Use AsVar.
  //operator CATBaseUnknown_var() const;

#ifndef CATIAR422
  //private because causes compilation errors on UNIXs. Use IsEqual.
  template<typename T2> bool operator==(T2);
  template<typename T2> bool operator!=(T2);
#endif

  //private because...private on base class.
  template<class T2> CATOmxQIPtr<T2>& Steal(const CATOmxSR<T2>& iSR);
  CATOmxQIPtr<T>& Steal(const CATBaseUnknown_var& iVar);
};

#ifdef CATIAR422
namespace omx
{
  // CATOmxQIPtr traits
  template<typename T>
  struct is_qiptr : std::false_type {};

  template<class PointerType, template<class> class QIPtrType>
  struct is_qiptr<QIPtrType<PointerType>> : std::is_same<QIPtrType<PointerType>, CATOmxQIPtr<PointerType>> {};
}

//internal: COM compliant pointer comparison
template<class PointerType, typename OtherType>
inline bool _CATOmxQIPtrEquals(const CATOmxQIPtr<PointerType>& qiptr, const OtherType& other)
{
  return CATOmxAreCOMEqual(qiptr.Get(), other);
}

//internal: override of the previous for nullptr
template<class PointerType>
inline bool _CATOmxQIPtrEquals(const CATOmxQIPtr<PointerType>& qiptr, std::nullptr_t)
{
  return !qiptr;
}

//internal: override of the previous for NULL (deprecated, to be removed)
template<class PointerType>
/* OMX_DEPRECATED("use nullptr instead of NULL") some now use /WX flag to promote all warnings into error... */
bool _CATOmxQIPtrEquals(const CATOmxQIPtr<PointerType>& qiptr, decltype(NULL) null)
{
  if (null)
    CATOmx::Internals::NotNullPointerAssertion();
  return !qiptr;
}

/** operator==(CATOmxQIPtr, Anything) */
template<class QIPtrType, typename OtherType>
inline typename std::enable_if<omx::is_qiptr<QIPtrType>::value, bool>::type
operator==(const QIPtrType& qiptr, const OtherType& other) { return _CATOmxQIPtrEquals(qiptr, other); }

/** operator!=(CATOmxQIPtr, Anything) should be removed once c++20 is available */
template<class QIPtrType, typename OtherType>
inline typename std::enable_if<omx::is_qiptr<QIPtrType>::value, bool>::type
operator!=(const QIPtrType& qiptr, const OtherType& other) { return !(qiptr == other); }

/** operator==(Anything, CATOmxQIPtr) should be removed once c++20 is available */
template<class QIPtrType, typename OtherType>
inline typename std::enable_if<omx::is_qiptr<QIPtrType>::value && !omx::is_qiptr<OtherType>::value, bool>::type
operator==(const OtherType& other, const QIPtrType& qiptr) { return qiptr == other; }

/** operator!=(Anything, CATOmxQIPtr) should be removed once c++20 is available */
template<class QIPtrType, typename OtherType>
inline typename std::enable_if<omx::is_qiptr<QIPtrType>::value && !omx::is_qiptr<OtherType>::value, bool>::type
operator!=(const OtherType& other, const QIPtrType& qiptr) { return !(qiptr == other); }

#endif

#endif
