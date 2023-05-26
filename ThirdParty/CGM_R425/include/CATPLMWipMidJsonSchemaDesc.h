#ifndef CATPLMWipMidJsonSchemaDesc_H
#define CATPLMWipMidJsonSchemaDesc_H

#include "CATPLMServicesItf.h"
#include "CATOmxKeyString.h"
#include "CATOmxArray.h"
#include "CATPLMOmxCollections.h"

//-----------------------------------------------------------------------

class ExportedByCATPLMServicesItf CATPLMWipMidJsonSchemaDesc
{
public:
  static const CATPLMWipMidJsonSchemaDesc &s();

  ~CATPLMWipMidJsonSchemaDesc ();

  const CATOmxKeyString ksWipMidJsonSchema;
  const CATOmxKeyString ksRowuuid;
  const CATOmxKeyString ksSchemaName;
  const CATOmxKeyString ksSchemaValue;
  const CATOmxKeyString ksDescription;

private:
  CATPLMWipMidJsonSchemaDesc();
  CATPLMWipMidJsonSchemaDesc (CATPLMWipMidJsonSchemaDesc &);
  CATPLMWipMidJsonSchemaDesc& operator=(CATPLMWipMidJsonSchemaDesc&);
};

//-----------------------------------------------------------------------

#endif
