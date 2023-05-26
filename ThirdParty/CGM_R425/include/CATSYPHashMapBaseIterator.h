#ifndef CATSYPHashMapBaseIterator_H
#define CATSYPHashMapBaseIterator_H

#include "UIVCoreTools.h"

class CATSysSimpleHashTable;

/**
 * Base class used to implement iterators of CATSYPHashMap
 * @see CATSYPHashMap
 */
class ExportedByUIVCoreTools CATSYPHashMapBaseIterator
{
public:
  /**
   * Initialize the iterator
   * @param i_pHashTable the hash table to use for iteration.
   */
  CATSYPHashMapBaseIterator(const CATSysSimpleHashTable *i_pHashTable);
  ~CATSYPHashMapBaseIterator();
  /** @see CATSYPConstIteratorItf#IsDone */
  int IsDone() const;
  /** @see CATSYPConstIteratorItf#Next */
  void Next();
  /** @see CATSYPConstIteratorItf#CurrentItem */
  const void *InternalCurrentItem() const;
private:
  CATSYPHashMapBaseIterator(const CATSYPHashMapBaseIterator&);
  CATSYPHashMapBaseIterator &operator=(const CATSYPHashMapBaseIterator&);
private:
  /** the hash table to be iterated */
  const CATSysSimpleHashTable *_pHashTable;
  /** the initial size of _pHashTable */
  const int _size;
  /** the current item pointer in the hash table */
  int _currentItem;
};


#endif // CATSYPHashMapBaseIterator_H

