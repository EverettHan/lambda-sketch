#ifndef vAtomic_H_
#define vAtomic_H_

#include <atomic>
#include <cstdint>
#include <vAtomicImpl.h>

namespace VKL
{
  /** this is to make sure if we transition to
   * std::atomic<InternalType>, we can implement the change
   * here and not modify everywhere
   */
  enum EAtomicMemoryOrder
  {
    eRelaxed = (int)std::memory_order_relaxed,
    eConsume = (int)std::memory_order_consume,
    eAcquire = (int)std::memory_order_acquire,
    eRelease = (int)std::memory_order_release,
    eAcqRel = (int)std::memory_order_acq_rel,
    eSeqCst = (int)std::memory_order_seq_cst
  };

  /**
   * vAtomic provides atomic types
   * Usage:
   * vAtomic<int> myAtomicInt;
   * myAtomicInt++; // atomic ++
   *
   *
   * Details:
   * This is just a wrapper over atomic
   * There is too much functionality provided in std library and
   * I dont see any use of replicating everything, but using this
   * class bluntly without considering proper memory ordering and
   * OP utilization would be bad design.
   * Instead for performance intensive code, consider using
   * vAtomic with the proper privitives, memory ordering and
   * proper OP (for eg, if you are using CAS, see if weak can substitute
   * strong, etc.) This will vary from case to case.
   */
  template <typename T>
  class vAtomic
  {

  public:

    typedef vAtomicTraits<T> Traits;
    typedef typename Traits::Type Type;
    typedef typename Traits::InternalType InternalType;

    V_FORCEINLINE Type operator=(Type desired) noexcept
    {
      return (m_Value = desired);
    }

    V_FORCEINLINE Type operator=(Type desired) volatile noexcept
    {
      return (m_Value = desired);
    }

    V_FORCEINLINE Type Load(const EAtomicMemoryOrder order = eSeqCst) const
    {
      return m_Value.load((std::memory_order)order);
    }

    V_FORCEINLINE Type Load(const EAtomicMemoryOrder order = eSeqCst) volatile const
    {
      return m_Value.load((std::memory_order)order);
    }

    V_FORCEINLINE void Store(Type iValue, const EAtomicMemoryOrder order = eSeqCst)
    {
      m_Value.store(iValue, (std::memory_order)order);
    }

    V_FORCEINLINE void Store(Type iValue, const EAtomicMemoryOrder order = eSeqCst) volatile
    {
      m_Value.store(iValue, (std::memory_order)order);
    }

    V_FORCEINLINE Type FetchAdd(Type iValue, const EAtomicMemoryOrder order = eSeqCst)
    {
      return m_Value.fetch_add(iValue, (std::memory_order)order);
    }

    V_FORCEINLINE Type FetchAdd(Type iValue, const EAtomicMemoryOrder order = eSeqCst) volatile
    {
      return m_Value.fetch_add(iValue, (std::memory_order)order);
    }

    V_FORCEINLINE Type FetchSub(Type iValue, const EAtomicMemoryOrder order = eSeqCst)
    {
      return m_Value.fetch_sub(iValue, (std::memory_order)order);
    }

    V_FORCEINLINE Type FetchSub(Type iValue, const EAtomicMemoryOrder order = eSeqCst) volatile
    {
      return m_Value.fetch_sub(iValue, (std::memory_order)order);
    }

    V_FORCEINLINE Type operator ++()
    {
      return ++m_Value;
    }

    V_FORCEINLINE Type operator --()
    {
      return --m_Value;
    }

    V_FORCEINLINE Type operator ++(int)
    {
      return m_Value++;
    }

    V_FORCEINLINE Type operator --(int)
    {
      return m_Value--;
    }

    V_FORCEINLINE Type operator ++() volatile
    {
      return ++m_Value;
    }

    V_FORCEINLINE Type operator --() volatile
    {
      return --m_Value;
    }

    V_FORCEINLINE Type operator ++(int) volatile
    {
      return m_Value++;
    }

    V_FORCEINLINE Type operator --(int) volatile
    {
      return m_Value--;
    }

    V_FORCEINLINE bool CompareExchange(Type& iExpected, Type iDesired, const EAtomicMemoryOrder success = eSeqCst, const EAtomicMemoryOrder failure = eSeqCst) noexcept
    {
      return CompareExchangeStrong(iExpected, iDesired, success, failure);
    }

    V_FORCEINLINE bool CompareExchangeStrong(Type& iExpected, Type iDesired, const EAtomicMemoryOrder success = eSeqCst, const EAtomicMemoryOrder failure = eSeqCst) noexcept
    {
      return m_Value.compare_exchange_strong(iExpected, iDesired, (std::memory_order)success, (std::memory_order)failure);
    }

    V_FORCEINLINE bool CompareExchangeWeak(Type& iExpected, Type iDesired, const EAtomicMemoryOrder success = eSeqCst, const EAtomicMemoryOrder failure = eSeqCst) noexcept
    {
      return m_Value.compare_exchange_weak(iExpected, iDesired, (std::memory_order)success, (std::memory_order)failure);
    }

    V_FORCEINLINE bool CompareExchangeStrong(Type& iExpected, Type iDesired, const EAtomicMemoryOrder success = eSeqCst, const EAtomicMemoryOrder failure = eSeqCst) volatile noexcept
    {
      return m_Value.compare_exchange_strong(iExpected, iDesired, (std::memory_order)success, (std::memory_order)failure);
    }

    V_FORCEINLINE bool CompareExchangeWeak(Type& iExpected, Type iDesired, const EAtomicMemoryOrder success = eSeqCst, const EAtomicMemoryOrder failure = eSeqCst) volatile noexcept
    {
      return m_Value.compare_exchange_weak(iExpected, iDesired, (std::memory_order)success, (std::memory_order)failure);
    }

    V_FORCEINLINE bool IsLockFree() const noexcept
    {
      return m_Value.is_lock_free();
    }

    V_FORCEINLINE vAtomic() {}
    V_FORCEINLINE vAtomic(Type iValue) : m_Value(iValue) {}

  private:

    InternalType m_Value;
  };


  struct vAtomicFlag
  {
    vAtomicFlag& operator=(const vAtomicFlag&) = delete;

    V_FORCEINLINE  void Clear(const EAtomicMemoryOrder order = eSeqCst) noexcept
    {
      m_Value.clear((std::memory_order)order);
    }

    V_FORCEINLINE  bool TestAndSet(const EAtomicMemoryOrder order = eSeqCst) noexcept
    {
      return m_Value.test_and_set((std::memory_order)order);
    }

    V_FORCEINLINE  void Clear(const EAtomicMemoryOrder order = eSeqCst) volatile noexcept
    {
      m_Value.clear((std::memory_order)order);
    }

    V_FORCEINLINE  bool TestAndSet(const EAtomicMemoryOrder order = eSeqCst) volatile noexcept
    {
      return m_Value.test_and_set((std::memory_order)order);
    }

    std::atomic_flag m_Value = ATOMIC_FLAG_INIT;
  };

}

#endif //vAtomic_H_
