#ifndef __CATOmxStructDescription_H
#define __CATOmxStructDescription_H

// ObjectModelerCollection
#include "CATOmxIter.h"
#include "CATOmxKeyString.h"
#include "CATOmxSharable.h"
#include "CATOmxDefaultCollecManager.h"

class CATOmxStructDescriptionAttribute;

/**
 * This class holds the "description" (name, attributes...) of a CATOmxStruct
 * You can create such description with CATOmxStructDescriptionBuilder.
 * You can use it in CATOmxKeyValueBlock.
 */
class CATOmxStructDescription: public CATOmxSharable
{
public:
  virtual CATOmxKeyString GetName() const = 0;
  virtual CATOmxKeyString GetNamespace() const = 0;
  /** returns "super type" (NON AddRef'ed)*/
  virtual const CATOmxStructDescription* GetParent() const = 0;
  /** returns attribute corresponding to iKey if found (NON AddRef'ed)*/
  virtual const CATOmxStructDescriptionAttribute* GetAttribute(const CATOmxKeyString& iKey) const = 0;
  virtual CATOmxIter<CATOmxStructDescriptionAttribute> ListAttributes() const = 0;
};

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATOmxStructDescription*>::manager();

#endif
