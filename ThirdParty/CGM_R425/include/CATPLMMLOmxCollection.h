#ifndef CATPLMMLOmxCollection_H
#define CATPLMMLOmxCollection_H

#include "CATPLMModelerLanguage.h"

#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxArray.h"
#include "CATOmxOMap.h"
#include "CATOmxOSet.h"
#include "CATPLMTypeH.h"

class CATString;

class ExportedByCATPLMModelerLanguage CATPLMMLOmxCollection
{
public:
  //static template <> CATOmxCollecManager & CATOmxDefaultCollecManager < CATOmxArray<CATString> >::manager();
  static CATOmxCollecManager & managerArrayOfString();

};

typedef CATOmxOMap< CATString,CATOmxArray<CATString>,CATOmxDefaultCollecManager<CATString>::manager,CATPLMMLOmxCollection::managerArrayOfString > MapStringWithArrayOfString;

#endif
