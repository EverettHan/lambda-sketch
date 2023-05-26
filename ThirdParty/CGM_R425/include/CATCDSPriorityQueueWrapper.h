// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSPriorityQueueWrapper:
//
// A template priority queue class.
//
//=============================================================================
//  Feb 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSPriorityQueueWrapper_h
#define CATCDSPriorityQueueWrapper_h

#include "CATCDSBoolean.h"
#include "CATCDSInline.h"
#include "CATCDSUtilities.h"
#include "CATCDSComparator.h"
#include "CATCDSArray.h"

// Encapsulation de std::priority_queue

#include <queue>
#include <set>

template<class T, class Compare>
#ifdef ExportCATCDSPriorityQueueWrapper
class ExportCATCDSPriorityQueueWrapper CATCDSPriorityQueueWrapper
#else
class CATCDSPriorityQueueWrapper
#endif
{
public:
  CATCDSPriorityQueueWrapper(Compare const & iCompare);

  CATCDSBoolean Empty() const;

  int Size() const;

  T const & Top() const;

  void Pop();

  void Push(T const & iE);

  void Clear();

private:
  std::priority_queue<T, std::vector<T>, Compare> _queue;
};

#ifdef ExportCATCDSPriorityQueueWrapper

template<class T, class Compare>
CATCDSPriorityQueueWrapper<T, Compare>::CATCDSPriorityQueueWrapper(Compare const & iCompare) :
  _queue(iCompare)
{
}

template<class T, class Compare>
CATCDSBoolean CATCDSPriorityQueueWrapper<T, Compare>::Empty() const
{
  return _queue.empty();
}

template<class T, class Compare>
int CATCDSPriorityQueueWrapper<T, Compare>::Size() const
{
  return static_cast<int>(_queue.size());
}

template<class T, class Compare>
T const & CATCDSPriorityQueueWrapper<T, Compare>::Top() const
{
  return _queue.top();
}

template<class T, class Compare>
void CATCDSPriorityQueueWrapper<T, Compare>::Pop()
{
  _queue.pop();
}

template<class T, class Compare>
void CATCDSPriorityQueueWrapper<T, Compare>::Push(T const &iE)
{
  _queue.push(iE);
}

template<class T, class Compare>
void CATCDSPriorityQueueWrapper<T, Compare>::Clear()
{
  while(!_queue.empty()) {
    _queue.pop();
  }
}  

#endif

// Utilitaires pour spécialisation partielle
template<class T>
struct CATCDSPriorityQueueSpecialization
{
  typedef T type;
  typedef std::less<T> compare;
};

template<class T>
struct CATCDSPriorityQueueSpecialization<T*>
{
  typedef void* type;
  typedef CATCDSMore<void*> compare;
};


template<>
class ExportedByCATCDSUtilities CATCDSPriorityQueueWrapper<void*, CATCDSMore<void*> >
{
public:
  typedef void* T;
  typedef CATCDSMore<T> Compare;

  CATCDSPriorityQueueWrapper(Compare const & iCompare);

  CATCDSBoolean Empty() const;

  int Size() const;

  T const & Top() const;

  void Pop();

  void Push(T const & iE);

  void Remove(T const & iE);

  void Insert(T iArrayBegin, T iArrayEnd, int iSize);

  void Clear();

private:
  std::set<T, Compare> _set;
};

#endif
