// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATCDSStack:
//
// A simple stack (LIFO) class based on CATCDSArray.
//
//=============================================================================
//  Feb 2016  Creation                         TE9
//=============================================================================

#ifndef CATCDSStack_h
#define CATCDSStack_h

#include "CATCDSBoolean.h"
#include "CATCDSArray.h"

template<class T>
class CATCDSStack
{
public:
  /**
   * Constructs a new stack
   * @param iSize A size to reserve in CATCDSArray
   */
  CATCDSStack()
  {

  }

  /**
   * Constructs a new stack
   * @param iSize A size to reserve in CATCDSArray
   */
  CATCDSStack(int iSize)
  {
    _array.Reserve(iSize);
  }

  /**
   * Test whether the stack is empty
   * @return TRUE if queue is empty
   */
  CATCDSBoolean Empty() const
  {
    return _array.Size() == 0;
  }

  /**
   * Retrieves number of elements in the stack
   * @return Queue size
   */
  int Size() const
  {
    return _array.Size();
  }

  /**
   * Retrieves top element
   * @return Queue top element
   */
  T const & Top() const
  {
    return _array.Back();
  }

  /**
   * Removes top element from the queue
   * @return Queue top element
   */
  void Pop()
  {
    _array.PopBack();
  }

  /**
   * Push a new element in the queue
   * @iE A new element
   */
  void Push(T const & iE)
  {
    _array.Append(iE);
  }

  /**
  * Removes all elements from the queue
  */
  void Clear()
  {
    _array.RemoveAll();
  }

private:
  CATCDSArray<T> _array;
};

#endif
