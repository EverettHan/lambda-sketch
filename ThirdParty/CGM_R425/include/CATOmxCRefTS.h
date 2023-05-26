#ifndef CATOmxCRefTS_H
#define CATOmxCRefTS_H

#include "CATOmxCxxPortability.h"

#if OMX_CXX11 == 1
#include <atomic>
#endif

/**
 * atomic reference counter
 * It can be used for implementing IUnknown style classes reference counters, nothing more.
 * For other usages check std::atomic
 *
 * falls back on a raw integer on platforms where c++11 is not enabled (AIX V5)
 */
template<typename Number>
class CATOmxCRefTS
{
public:
#if OMX_CXX11 == 1
  constexpr CATOmxCRefTS(Number value) :m_cRef(value) {}

  /**
   * pre increment operator
   * do not use the returned value except for debugging purpose or in single thread context
   */
  Number operator++() { return m_cRef.fetch_add(Number(1), std::memory_order_relaxed) + 1; }

  /**
   * pre decrement operator
   * return value being zero indicates that the object can be freed, even in multithread context
   * else do not use the returned value except for debugging purpose or in single thread context
   */
  Number operator--() { return m_cRef.fetch_sub(Number(1), std::memory_order_acq_rel) - 1; }

  /**
   * getter
   * do not use the returned value except for debugging purpose or in single thread context
   */
  Number Get() const { return m_cRef.load(std::memory_order_relaxed); }
private:
  std::atomic<Number> m_cRef;
#else
  CATOmxCRefTS(Number value) :m_cRef(value) {}
  Number operator++() { return ++m_cRef; }
  Number operator--() { return --m_cRef; }
  Number Get() const { return m_cRef; }
private:
  Number m_cRef;
#endif
};

#endif
