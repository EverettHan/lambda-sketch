// COPYRIGHT Dassault Systemes 2017
/**
* @level Protected
* @usage U3
*/
#ifndef CATPLMOMXCOLLECTIONSADAPTERS_H_
#define CATPLMOMXCOLLECTIONSADAPTERS_H_

#include "CATPLMOmxCollections.h"
#include "CATOmxArray.h"
#include "CATOmxSet.h"

#include "CATListOfCATString.h"
#include "CATListPtrCATPLMType.h"

#include "CATPLMType.h"

class ExportedByCATPLMServicesItf CATPLMOmxCollectionsAdapters
{
public:
  static void CATLISTVCATStringToCATOmxArrayCATString(CATLISTV(CATString)& iCATStringList, CATOmxArray<CATString>& oCATStringArray);
  static void CATPLMTypeSetToCATLISTPCATPLMType(CATPLMTypeSet& iCATPLMTypeSet, CATLISTP(CATPLMType)& oCATPLMTypeList);
};

#endif /* CATPLMOMXCOLLECTIONSADAPTERS_H_ */
