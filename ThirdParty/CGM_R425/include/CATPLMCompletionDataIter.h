/*
 * CATPLMCompletionDataIter.h
 *
 *  Created on: Jul 16, 2012
 *      Author: PJQ
 */

#ifndef CATPLMCOMPLETIONDATAITER_H_
#define CATPLMCOMPLETIONDATAITER_H_
/**
 * @level Protected
 * @usage U1
 */

#include "CATPLMIntegrationAccess.h"
#include "CATPLMCompletionDataRawIter.h"
#include "CATPLMCompletionDataCplxMode.h"
#include "CATBoolean.h"
#include "CATPLMID.h"
class CATPLMCompletionData;

/**
 * Iterator on the content of a CATPLMCompletionData that allows the refined management of complex PLMIDs
 *
 * Basic usage :
 * <code>
 * CATPLMCompletionDataIter iter = myCompletionData.GetIterator(CATPLMCompletionDataCplxMode::Explode);
 * while(iter.Next())
 * {
 *   CATPLMID current = iter.Current();
 *   // ...
 * }
 * </code>
 */
class ExportedByCATPLMIntegrationAccess CATPLMCompletionDataIter
{
  CATPLMCompletionDataRawIter _raw;
  CATPLMCompletionDataRawIter _exploded;
  CATPLMCompletionDataCplxMode::Mode _mode;

public:
  CATPLMCompletionDataIter(const CATPLMCompletionDataOnTos & iData, CATPLMCompletionDataCplxMode::Mode iCplxMode);
  CATPLMCompletionDataIter(const CATPLMCompletionDataIter &);

  CATBoolean Next();
  CATPLMID Current();

private:
  CATPLMCompletionDataIter & operator =(const CATPLMCompletionDataIter &);
};
#endif /* CATPLMCOMPLETIONDATAITER_H_ */
