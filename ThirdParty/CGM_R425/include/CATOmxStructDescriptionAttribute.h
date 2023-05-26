#ifndef __CATOmxStructDescriptionAttribute_H
#define __CATOmxStructDescriptionAttribute_H

// ObjectModelerCollection
#include "CATOmxAny.h"
#include "CATOmxCollectionType.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxKeyString.h"
#include "CATOmxKind.h"
#include "CATOmxSharable.h"

class CATOmxStructDescriptionAttributeBuilder;

/**
 * Description of an attribute, see CATOmxStructDescription
 */
class CATOmxStructDescriptionAttribute: public CATOmxSharable
{
public:
  //public immutable and self explanatory fields
  const CATOmxKeyString Name;
  const CATOmxCollectionType CollectionType:16;
  const CATOmxKind ExtendedKind:16;
  const CATOmxKind Kind;
protected:
  CATOmxStructDescriptionAttribute(const CATOmxStructDescriptionAttributeBuilder& iBuilder);
};

#endif
