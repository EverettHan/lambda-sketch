/**
 * @level Protected
 * @usage U1
 */

#ifndef CATOmxBaseIter_H
#define CATOmxBaseIter_H

#include "CATOmxSharable.h"
class CATOmxCollecManager;

/**
 * Abstract iterator
 * Do not use directly (@see CATOmxIter)
 * Can be implemented
 */
class ExportedByCATOmxKernel CATOmxBaseIter : public CATOmxSharable
{
protected:
  /**destructor*/
  virtual ~CATOmxBaseIter();
public:
  CATOmxBaseIter();

  /**
   * new overriding (efficient for transient objects).
   */
  void* operator new(size_t size);

  /**
   * delete overriding (efficient for transient objects).
   */
  void operator delete(void* ptr);

  /**
   * return next item of underlying collection.
   * Returned object must be internally kept "alive" (pe AddRef) until next call to NextItem().
   */
  virtual void* NextItem(void) = 0;

  /**
   * return estimated number of items.
   * After a call to NextItem, the behavior of this method is unspecified
   */
  virtual unsigned Size() const;

  /**
   * return a "deep" (isolated) copy of the iterator.
   * After a call to NextItem, the behavior of this method is unspecified
   */
  virtual CATOmxBaseIter* Clone() const;

  /**
   * poor man RTTI (do not call/implement outside ObjectModelerCollection)
   */
  virtual const char* GetType() const;

  /**
   * return a single object iterator.
   */
  static CATOmxBaseIter* SingleItemIter(void* single, const CATOmxCollecManager& manager);

  /**
   * return an iterator on a pair of objects.
   */
  static CATOmxBaseIter* CoupleItemIter(void* couple[2], const CATOmxCollecManager& manager);
};

#endif

