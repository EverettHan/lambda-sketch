#ifndef _CATxPDMLogEntryIterator_H
#define _CATxPDMLogEntryIterator_H


#include "CATOmxIter.h"
class CATxPDMLogEntry;

/**
 * This class is an iterator on all the log entries in a save log
 */

class CATxPDMLogEntryIterator
{
public:
  CATOmxIter<CATxPDMLogEntry> m_iter;

  CATxPDMLogEntryIterator(CATOmxIter<CATxPDMLogEntry>& iter) :m_iter(iter) {}
  /**
  * Next
  *
  * @return
  *   The next entry in the iterator
  */
  CATxPDMLogEntry * Next() { return m_iter.Next(); }

};

#endif
