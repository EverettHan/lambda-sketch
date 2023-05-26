#ifndef _CATPLMRelationalCheckSumComparator_H
#define _CATPLMRelationalCheckSumComparator_H

/**
* @level Private
* @usage U1
*/

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"

class ExportedByCATPLMTos CATPLMRelationalCheckSumComparator
{
public:
  CATPLMRelationalCheckSumComparator();
  virtual ~CATPLMRelationalCheckSumComparator();

  /**
  * Checks if Ids are compatibles
  */
  virtual CATBoolean IsSame() = 0;

  /**
  * Unicode dump
  */
  virtual void PushUnicodeDump(CATListOfCATUnicodeString & ioDump) const = 0;
};

#endif
