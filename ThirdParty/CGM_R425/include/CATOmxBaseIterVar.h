/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxBaseIterVar_h__
#define __CATOmxBaseIterVar_h__
#include "CATOmxKernel.h"

class CATOmxBaseIter;

/**
 * Internal use only (for low level collection implementators).
 * Core implementation for iterators.
 * Use CATOmxIter<T> instead.
 */
class ExportedByCATOmxKernel CATOmxBaseIterVar {
protected:
  CATOmxBaseIter *m_iter; 
  ~CATOmxBaseIterVar(void);
  inline CATOmxBaseIterVar(CATOmxBaseIter *iter): m_iter(iter) {}
  void AssignIterator(const CATOmxBaseIterVar &op);
  void AppendIterator(const CATOmxBaseIterVar &op);
  void CloneIterator(const CATOmxBaseIterVar &op);
  void *nextItem();
public:
  /**
   * Internal use only (for low level collection implementators).
   * Set the iterator, drop old iter if needed.
   */
  void Steal(CATOmxBaseIter *iter);
  /**
   * Internal use only (for low level collection implementators).
   * Get the underlying iterator.
   */
  inline CATOmxBaseIter *PrivateStrip() { return m_iter; }
  /**
   * Internal use only (for low level collection implementators).
   * Return the estimated number of item.
   * @return the number of item 
   */
   unsigned Size(void) const;
   /** Internal use. */
   CATOmxBaseIter *PrivateCopy() const;
};

#endif
