// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyHeapEvaluator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// sep 2003 Creation: dhp
//===================================================================
#ifndef CATPolyHeapEvaluator_H
#define CATPolyHeapEvaluator_H

#include "CATPolyMiscellaneous.h"


template <typename T>
class CATPolyHeapEvaluator
{

public:

	CATPolyHeapEvaluator () {};
	virtual ~CATPolyHeapEvaluator () {};

  /**
  * Compares the values of associated to the two integers arguments.
  * @param iNum1
  *   An index (or num) to the first value to compare for the evaluator.
  * @param iNum2
  *   An index (or num) to the second value to compare for the evaluator.
  * @return
  * <ul>
  *   <li> -1 if Value 1 < Value 2. 
  *   <li>  0 if Value 1 = Value 2.
  *   <li> +1 if Value 1 > Value 2.
  * </ul>
  */
  virtual int CompareValues (const T iNum1, const T iNum2) const = 0;

  /**
  * A class deriving from this class can save the index in the heap for each entry in the heap. 
  * This is generally done via a mapping.
  * Index 0 corresponds to the smallest entry according to the comparator CompareValues ().
  * @param iNum
  *    The index (or num) to the value for the evaluator.
  * @param iIndex
  *    The index into the heap associated to the entry.
  */
  virtual void UpdateNum (const T iNum, const int iIndex) = 0;

};

#endif
