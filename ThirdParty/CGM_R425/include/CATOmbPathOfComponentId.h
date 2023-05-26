#ifndef CATOmbPathOfComponentId_H
#define CATOmbPathOfComponentId_H

#include "CATOmxPortability.h"

class CATComponentId;
class CATOmbTargetPath;

/**
 * abstraction of a path (array) of CATComponentId
 * intent is to avoid conversions
 */
class CATOmbPathOfComponentId
{
public:
  virtual int GetSize() const = 0;
  virtual CATComponentId GetItem(int i) const = 0;
};


#endif
