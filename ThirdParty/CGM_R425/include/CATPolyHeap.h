// COPYRIGHT DASSAULT SYSTEMES 2003, all rights reserved
//===================================================================
//
// CATPolyHeap.h
//
//===================================================================
// sep 2003 Creation: dhp
//===================================================================
#ifndef CATPolyHeap_H
#define CATPolyHeap_H

#include "CATPolyMiscellaneous.h"
#include "CATBoolean.h"

template <typename T> class CATPolyHeapEvaluator;

/**
* This class implements a binary heap (minimum or maximum heap based on the evaluator/comparator .)
*/
template <typename T>
class ExportedByCATPolyMiscellaneous CATPolyHeap
{

public:

  CATPolyHeap(const int iSize, CATPolyHeapEvaluator<T> *iEvaluator):
    _MapHeapIndexToNum(0),
    _MaxSize(0),
    _Size(0)
  {
    _Evaluator = iEvaluator;
    if (iSize > 0)
      Reallocate(iSize);
  }

  ~CATPolyHeap()
  {
    delete[] _MapHeapIndexToNum;
    _MapHeapIndexToNum = 0;
    _Evaluator = 0;
  }

  inline int Size() const { return _Size; };

  CATBoolean Add(const T iNum);
  void Replace(const int iIndex, const T iNum);
  void Remove(const int iIndex);
  inline void RemoveAll() { _Size = 0; }

  inline T GetNum(const int iIndex) const { return _MapHeapIndexToNum[iIndex]; }

  /**
  * Checks if the heap is valid for debugging purpose.
  */
  //CATBoolean Check () const;

  /**
  * This implementation is buggy.
  * Replace call to this method by a call to Remove. (ODT impact.)
  */
  void BuggyRemove(const int iIndex);

private:

  void Update(const int index);
  void UpdateParent(int index);
  void UpdateChildren(int index);
  int UpdateNum(const int index);
  void SwapNum(const int index1, const int index2);

private:

  T* _MapHeapIndexToNum;  // Map from a heap index to a num value.
  int _MaxSize;
  int _Size;

  CATPolyHeapEvaluator<T>* _Evaluator;

  inline int GetParent(const int iIndex) const { return (iIndex > 0) ? (iIndex - 1) / 2 : -1; }
  inline int GetChild1(const int iIndex) const { return 2 * iIndex + 1; }
  inline int GetChild2(const int iIndex) const { return 2 * iIndex + 2; }

  void Reallocate(unsigned int size);

};

struct ExportedByCATPolyMiscellaneous CATPolyQMBarCost
{
  CATPolyQMBarCost(const unsigned int b = 0, const unsigned int f = 0, const double c = 0.) :
    _Cost(c), _Bar(b), _Frame(f)
  {}

  double _Cost;
  unsigned int _Bar;
  unsigned int _Frame;
};

struct ExportedByCATPolyMiscellaneous CATPolyBarCost
{
  CATPolyBarCost(const int b = 0, const float c = 0.) :
    _Cost(c), _Bar(b)
  {}

  float _Cost;
  int _Bar;
};

#endif
