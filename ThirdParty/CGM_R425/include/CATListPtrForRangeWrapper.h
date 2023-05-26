#ifndef CATListPtrForRangeWrapper_H
#define CATListPtrForRangeWrapper_H

#include "CATListPtrIterator.h"

/**
 * internal class, do not use directly.
 * use CATListPtrForRangeWrapper
 */
template<class CATListPtrXXX>
class _CATListPtrForRangeWrapper
{
  const CATListPtrXXX& m_list;
public:
  inline _CATListPtrForRangeWrapper(const CATListPtrXXX& list) :m_list(list) {}

  inline CATListPtrIterator<CATListPtrXXX> begin() const { return CATListPtrIterator<CATListPtrXXX>(m_list, true); }
  inline CATListPtrIterator<CATListPtrXXX> end() const { return CATListPtrIterator<CATListPtrXXX>(m_list, false); }
};


/**
* range-for adapter for CATListPtr
* use it like this:
* CATListPtrCATIXXX list = ... ;
* for(CATIXXX& item: CATListPtrForRangeWrapper(list))
* {
*   item.DoSomething();
* }
*/
template<class CATListPtrXXX>
_CATListPtrForRangeWrapper<CATListPtrXXX> CATListPtrForRangeWrapper(const CATListPtrXXX& list) { return _CATListPtrForRangeWrapper<CATListPtrXXX>(list); }

#endif
