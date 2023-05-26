/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2003
 */
#ifndef __CATOmxQueue_H
#define __CATOmxQueue_H

#include "CATOmxBaseQueue.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxPortability.h"
#include "CATOmxVector.h"
#include "CATOmxSet.h"
#include "CATOmxIter.h"

/**
 * CATOmxQueue implements a kind of "queue" container.
 * Notice that CATOmxQueue is not really a collection/container as it is also an "iterator".
 * It allows to process a set of objects in a FIFO order and at the same time add new objects to process.
 * Each object wil be processed only one time, this protect algorithms from cycles and infinite loops or stack overflows.
 * It can be used in order to process a "recursive" set of object.
 * Let's say we have a class Object which can aggregate a list of Object and we wan't to process all of them:
 * class Object
 * {
 * public:
 *   virtual CATOmxIter<Object> GetObjects();
 * };
 *
 * Then code would look like this:
 * Object* root = ...;
 * CATOmxQueue<Object> queue(root);
 * Object* cur;
 * while( NULL != (cur = queue.Next()) )
 * {
 *   //process cur
 *   ... 
 *   //add sub objects in the queue
 *   queue.Add(cur->GetObjects());
 * }
 *
 */
template<typename T,CATOmxCollecManagerLocator M=CATOmxDefaultCollecManager<T*>::manager  >
class CATOmxQueue: public CATOmxBaseQueue
{
public:
  /**build a queue containing item.*/
  CATOmxQueue(const T* iItem=NULL,int iReserve=0):CATOmxBaseQueue(iItem,iReserve,M) {}

  /**Pop first element from the queue and return it.*/
  inline T* Next() {return static_cast<T*>(_Next());}

  /**Add items at the end of the queue, returns number of items inserted.*/
  inline int Add(const T* item)               {return _Add(item,M);}

  /**Add items at the end of the queue, returns number of items inserted.*/
  inline int Add(CATOmxIter<T> iter)          {return _Add(iter.PrivateStrip(),M);}

  /**Add items at the end of the queue, returns number of items inserted.*/
  inline int Add(const CATOmxVector<T>& vect) {return _Add(reinterpret_cast<const CATOmxVector<IUnknown>&>(vect),M);}

  /**Returns an iterator on all items inserted.*/
  inline CATOmxIter<T> Iterator() const {return GetVector().Iterator();}

  /**Returns a vector containing all inserted items.*/
  inline CATOmxVector<T> GetVector() const {return const_cast<CATOmxVector<T>&>(reinterpret_cast<const CATOmxVector<T>&>(m_vect));}

  /**Returns a set containing all inserted items.*/
  inline CATOmxSet<T,M>  GetSet()    const {return const_cast<CATOmxSet<T,M>&>(reinterpret_cast<const CATOmxSet<T,M>&>(m_set));}

  /**Empty the queue.*/
  inline void Clear() {_Clear(M);}

  /**destructor.*/
  inline ~CATOmxQueue() {Clear();}
private:
  CATOmxQueue(const CATOmxQueue&);
  CATOmxQueue& operator=(const CATOmxQueue&);
};

#endif
