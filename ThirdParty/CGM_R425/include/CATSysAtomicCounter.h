#ifndef __CATSysAtomicCounter_h__
#define __CATSysAtomicCounter_h__

#include "CATOmxPortability.h"
#include "DSYSysAtomic.h"

/** OBSOLETE, UNDER REMOVAL*/
namespace CATSysAtomic
{
  template <typename Type> inline Type* exchange_pointer(Type * &ptr, Type * iValue);
  template <typename Type> inline Type* cas_pointer(Type * &ptr, Type *iCompare, Type * iValue);

  inline int pre_inc(int &counter) {
    return DSYSysInterlockedIncrement(&counter);
  }
  inline int pre_dec(int &counter) {
    return DSYSysInterlockedDecrement(&counter);
  }
  inline int add(int &counter, int v) {
    return DSYSysInterlockedAdd(&counter, v);
  }

  inline unsigned int pre_inc(unsigned int &counter) {
    return static_cast<unsigned int>(DSYSysInterlockedIncrement(reinterpret_cast<int*>(&counter)));
  }
  inline unsigned int pre_dec(unsigned int &counter) {
    return static_cast<unsigned int>(DSYSysInterlockedDecrement(reinterpret_cast<int*>(&counter)));
  }
  inline unsigned int add(unsigned int &counter, unsigned int v) {
    return static_cast<unsigned int>(DSYSysInterlockedAdd(reinterpret_cast<int*>(&counter), static_cast<int>(v)));
  }
#ifdef _WINDOWS_SOURCE
  inline unsigned long pre_inc(unsigned long &counter) {
    return static_cast<unsigned long>(DSYSysInterlockedIncrement(reinterpret_cast<int*>(&counter)));
  }
  inline unsigned long pre_dec(unsigned long &counter) {
    return static_cast<unsigned int>(DSYSysInterlockedDecrement(reinterpret_cast<int*>(&counter)));
  }
  inline unsigned long add(unsigned long &counter, unsigned long v) {
    return static_cast<unsigned long>(DSYSysInterlockedAdd(reinterpret_cast<int*>(&counter), static_cast<int>(v)));
  }
  inline long pre_inc(long &counter) {
    return static_cast<long>(DSYSysInterlockedIncrement(reinterpret_cast<int*>(&counter)));
  }
  inline long pre_dec(long &counter) {
    return static_cast<int>(DSYSysInterlockedDecrement(reinterpret_cast<int*>(&counter)));
  }
  inline  long add(long &counter, long v) {
    return static_cast<long>(DSYSysInterlockedAdd(reinterpret_cast<int*>(&counter), static_cast<int>(v)));
  }
#endif 
  template <typename X> inline X* exchange_pointer(X *&ptr, X*iValue) {
    return static_cast<X*>(DSYSysInterlockedExchangePtr((void**)(&ptr), iValue));
  }
  inline unsigned int exchange(unsigned int &ptr, unsigned int iValue) {
    return static_cast<unsigned int>(DSYSysInterlockedExchangeInt32((int *)(&ptr), iValue));
  }
  inline int exchange(int &ptr, int iValue) {
    return static_cast<int>(DSYSysInterlockedExchangeInt32(&ptr, iValue));
  }
  template <typename Type> inline Type *cas_pointer(Type * &iDestination, Type *iComparand, Type * iExchange) {
    return reinterpret_cast<Type*>(DSYSysInterlockedCompareExchangePtr(reinterpret_cast<void **>(&iDestination), iExchange, iComparand));
  }
  template <typename Type> inline Type cas(Type &iDestination, Type iComparand, Type iExchange);
  template <> inline int cas<int>(int &iDestination, int iComparand, int iExchange) {
    return DSYSysInterlockedCompareExchangeInt32(&iDestination, iExchange, iComparand);
  }
  template <> inline unsigned int cas<unsigned int>(unsigned int &iDestination, unsigned int iComparand, unsigned int iExchange) {
    return DSYSysInterlockedCompareExchangeInt32(reinterpret_cast<int*>(&iDestination), iExchange, iComparand);
  }

}
/** OBSOLETE, UNDER REMOVAL*/
template <typename Type> class CATSysAtomicCounter
{
public:
  /** direct access to counter is unsafe. */
  Type counter;
  inline CATSysAtomicCounter(Type v) : counter(v) {}
  inline CATSysAtomicCounter() : counter(0) {}
  inline CATSysAtomicCounter(const CATSysAtomicCounter &v) : counter(v.counter) {}
  inline CATSysAtomicCounter &operator=(const CATSysAtomicCounter &v) { counter = v.counter; return *this; }
  /* post increment */
  inline Type operator ++(int) { return CATSysAtomic::pre_inc(counter) - 1; }
  /* post decrement */
  inline Type operator --(int) { return CATSysAtomic::pre_dec(counter) + 1; }
  /* pre increment */
  inline Type operator ++() { return CATSysAtomic::pre_inc(counter); }
  /* pre decrement */
  inline Type operator --() { return CATSysAtomic::pre_dec(counter); }
  inline Type operator +=(Type v) {
    return CATSysAtomic::add(counter, v);
  }
  inline bool operator ==(Type v) const { return counter == v; }
  inline bool operator !=(Type v) const { return counter != v; }
  inline bool operator <=(Type v) const { return counter <= v; }
  inline bool operator <(Type v) const { return counter < v; }
  inline bool operator >=(Type v) const { return counter >= v; }
  inline bool operator >(Type v) const { return counter > v; }
  //inline operator Type() const { return counter; }
};
#endif
