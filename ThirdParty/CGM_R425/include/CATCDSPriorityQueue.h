// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSPriorityQueue:
//
// A template priority queue class.
//
//=============================================================================
//  Feb 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSPriorityQueue_h
#define CATCDSPriorityQueue_h

#include "CATCDSBoolean.h"
#include "CATCDSInline.h"
#include "CATCDSUtilities.h"
#include "CATCDSComparator.h"
#include "CATCDSPriorityQueueWrapper.h"
#include "CATCDSArray.h"

template<class T, class Compare = typename CATCDSPriorityQueueSpecialization<T>::compare >
class CATCDSPriorityQueue
{
public:
  /**
   * Constructs a new priority queue
   * @param Compare A comparison object
   */
  CATCDSPriorityQueue(Compare const & iCompare = Compare());

  /**
   * Test whether the queue is empty
   * @return TRUE if queue is empty
   */
  CATCDSBoolean Empty() const;

  /**
   * Retrieves number of elements in the queue
   * @return Queue size
   */
  int Size() const;

  /**
   * Retrieves top element
   * @return Queue top element
   */
  T const & Top() const;

  /**
   * Removes top element from the queue
   * @return Queue top element
   */
  void Pop();

  /**
   * Push a new element in the queue
   * @iE A new element
   */
  void Push(T const & iE);

  /**
   * Remove an element from the queue
   * Only available on default priority queue with pointers
   * @iE An element
   */
  void Remove(T const & iE);

  /**
   * Insert all pointers iArrayBegin + i in [iArrayBegin, iArrayEnd[
   * Only available on default priority queue with pointers
   * @iArray The array to insert
   */
  void Insert(T iArrayBegin, T iArrayEnd);

  /**
   * Remove all elements from the queue
   */
  void Clear();

private:
  CATCDSPriorityQueueWrapper<typename CATCDSPriorityQueueSpecialization<T>::type, Compare> _queue;
};

template<class T, class Compare>
CATCDSPriorityQueue<T, Compare>::CATCDSPriorityQueue(Compare const & iCompare) :
  _queue(iCompare)
{
}

template<class T, class Compare>
CATCDSBoolean CATCDSPriorityQueue<T, Compare>::Empty() const
{
  return _queue.Empty();
}

template<class T, class Compare>
int CATCDSPriorityQueue<T, Compare>::Size() const
{
  return _queue.Size();
}

template<class T, class Compare>
T const & CATCDSPriorityQueue<T, Compare>::Top() const
{
  return reinterpret_cast<T const &>(_queue.Top());
}

template<class T, class Compare>
void CATCDSPriorityQueue<T, Compare>::Pop()
{
  _queue.Pop();
}

template<class T, class Compare>
void CATCDSPriorityQueue<T, Compare>::Push(T const &iE)
{
  _queue.Push(iE);
}

template<class T, class Compare>
void CATCDSPriorityQueue<T, Compare>::Remove(T const &iE)
{
  _queue.Remove(iE);
}

template<class T, class Compare>
void CATCDSPriorityQueue<T, Compare>::Insert(T iArrayBegin, T iArrayEnd)
{
  _queue.Insert(iArrayBegin, iArrayEnd, sizeof(iArrayBegin[0]));
}

template<class T, class Compare>
void CATCDSPriorityQueue<T, Compare>::Clear()
{
  _queue.Clear();
}

#endif
