/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2003
 */
#ifndef __CATOmxBaseQueue_H
#define __CATOmxBaseQueue_H

#include "CATOmxKernel.h"
#include "CATOmxVector.h"
#include "CATOmxBaseSet.h"
#include "CATOmxPortability.h"
class CATOmxBaseIter;

/**
 * DO NOT USE
 * CATOmxBaseQueue is a base class for CATOmxQueue
 * Use CATOmxQueue and not this class directly.
 */
class ExportedByCATOmxKernel CATOmxBaseQueue
{
  int m_index,m_size;
protected:
  CATOmxVector<IUnknown> m_vect;
  CATOmxBaseSet m_set;
public:
  /**constructor*/
  CATOmxBaseQueue(const IUnknown* iItem,int iReserve,CATOmxCollecManagerLocator mgr);
  /**@return index [1,Size()] in the queue of last item returned by Next()*/
  inline int GetIndex() const {return m_index+1;}
  /**@return true if last item returned by Next() is the first element of the queue*/
  inline int IsFirst() const {return m_index==0;}
protected:
  /**see @href CATOmxQueue*/
  IUnknown* _Next();
  /**see @href CATOmxQueue*/
  int _Add(const IUnknown* iItem,CATOmxCollecManagerLocator mgr);
  /**see @href CATOmxQueue*/
  int _Add(CATOmxBaseIter* iIter,CATOmxCollecManagerLocator mgr);
  /**see @href CATOmxQueue*/
  int _Add(const CATOmxVector<IUnknown>& iIter,CATOmxCollecManagerLocator mgr);
  /**see @href CATOmxQueue*/
  void _Clear(CATOmxCollecManagerLocator mgr);
  /**see @href CATOmxQueue*/
  inline ~CATOmxBaseQueue() {}
private:
  CATOmxBaseQueue(const CATOmxBaseQueue&);
  CATOmxBaseQueue& operator=(const CATOmxBaseQueue&);
};

#endif
