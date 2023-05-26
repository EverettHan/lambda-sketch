#ifndef CATOMYPairAnyToBool_H
#define CATOMYPairAnyToBool_H

#include "CATA5ParserExport.h"

#include "CATOmxPair.h"
#include "CATOmxAny.h"

class CATOmxCollecManager;

namespace CATOMYPairAnyToBoolCollecMngr
{
  ExportedByCATA5Parser CATOmxCollecManager& mngrAnyToBool();
};

typedef CATOmxPair<CATOmxAny, bool> CATOMYPairAnyToBool;

#endif
