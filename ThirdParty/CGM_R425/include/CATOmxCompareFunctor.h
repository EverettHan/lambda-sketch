#ifndef __CATOmxCompareFunctor_H
#define __CATOmxCompareFunctor_H

#include "CATOmxPortability.h"

/**
 * Comparison functor interface
 * @see CATOmxArray::Sort
 * Implement this interface if your sorting comparison function requires data.
 */
template<typename T> 
class CATOmxCompareFunctor
{
protected:
  /**
   * a strcmp like comparison function.
   * Must return
   *   strictly negative if a<b
   *   strictly positive if a>b 
   *   zero              if a==b 
   */
  virtual int operator()(T const& a, T const& b) = 0;
public:
  /*DO NOT USE, reserved to Omx implementation*/
  static int Compare(CATOmxCompareFunctor& iFct, T const & a, T const & b) { return iFct(a,b);}
};

#endif
