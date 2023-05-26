#ifndef CATMMCTSBASEUNKNOWNPOOL_H
#define CATMMCTSBASEUNKNOWNPOOL_H

#include "CATMMediaPixelImage.h"
#include "CATMMCTSBaseUnknownPoolInstance.h"
#include <vector>

/**
 * @ingroup groupMMC
 * @defgroup groupMMCBaseUnknownPool Pool of CATSysTSBaseUnknown
 * This module contains the objects that take part to CATSysTSBaseUnknown Pool.
 * Pool of CATSysTSBaseUnkown to solve creation/destruction performance by sharing instance.
 * Instances have to derive from CATMMCTSBaseUnknownPoolInstance and declared in a CATMMCTSBaseUnknownPool at their creation.
 * Then after user and by calling Release(), instance will not be destroyed and will return to CATMMCTSBaseUnknownPool to be available for use by another client.
 * @brief Pool collecting free/available CATSysTSBaseUnknown instances.
 */

class CATMMCTSBaseUnknownPoolInstance;

/**
 * @ingroup groupMMCBaseUnknownPool
 * Pool implementation owning CATSystTSBaseUnknown instances.
 */
class ExportedByCATMMediaPixelImage CATMMCTSBaseUnknownPool
{
  friend class CATMMCTSBaseUnknownPoolInstance;
public:
  CATMMCTSBaseUnknownPool();
  CATMMCTSBaseUnknownPool(CATMMCTSBaseUnknownPoolInstance* (*pFactory)());
  virtual ~CATMMCTSBaseUnknownPool();

  /**
   * @param ipInstance will be AddRef().
   */
  bool RegisterAvailableInstance(CATMMCTSBaseUnknownPoolInstance* ipInstance);

  /**
   * @return CATSysTSBaseUnknown#Release. Returned CATMMCTSBaseUnknownPoolInstance has to be released after use.
   */
  CATMMCTSBaseUnknownPoolInstance* GetAvailableInstance();


private:
  std::vector<CATMMCTSBaseUnknownPoolInstance*>  _lstPoolAvailableObjectInstances;
  std::vector<CATMMCTSBaseUnknownPoolInstance*>  _lstPoolManagedInstances;
  CATMutex                                       _mutex;
  CATBoolean                                     _specific1Instance[2];
  CATMMCTSBaseUnknownPoolInstance*             (*_pFactory)();

  bool RegisterAvailableInstanceNoAddRef(CATMMCTSBaseUnknownPoolInstance* ipInstance);
  int NumberOfAvailableInstance();
  CATMutex& GetMutex();
};

#endif
