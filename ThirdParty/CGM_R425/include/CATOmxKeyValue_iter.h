#ifndef __CATOmxKeyValue_iter_h__
#define __CATOmxKeyValue_iter_h__

#include "CATOmxKernel.h"
#include "CATOmxIter.h"
#include "CATOmxSR.h"
#include "CATOmxKeyValueBlock.h"
#include "CATOmxKeyValue.h"

namespace
{
  /**
   * deprecated: use CATOmxKeyValueBlock::ConstIterator
   */
  class CATOmxKeyValue_iter
  {
    CATOmxIter<const CATOmxKeyValue> itr;
    const CATOmxKeyValue *current;
  public:
    CATOmxKeyValue_iter(const CATOmxKeyValueBlock& block) :itr(block.ConstIterator()), current(NULL) {}
    CATBoolean Next() { return NULL != (current = itr.NextItem()); }
    const CATOmxKeyString& Key() { return current->m_key; }
    const CATOmxAny& Value() { return current->m_value; }
  };
}

#endif
