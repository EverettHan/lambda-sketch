#ifndef CATOMYCollections_H
#define CATOMYCollections_H

#include "CATA5ParserExport.h"

#include "CATOmxAny.h"
#include "CATOmxOMap.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxDefaultCollecManager.h"

#include "CATOMYPairAnyToBool.h"

#include "CATA5AttrNoDfltAbstractProcessor.h"
#include "CATA5AbstractProcessor.h"
class CATOmxCollecManager;

typedef CATOmxOMap<CATA5AbstractProcessor*, CATOmxAny, CATOmxDefaultCollecManager<CATA5AbstractProcessor*>::manager, CATOmxDefaultCollecManager<CATOmxAny>::manager > CATOMYA5AbstractProcessorToAny;

typedef CATOmxOMap<CATA5AttrNoDfltAbstractProcessor*, CATOMYPairAnyToBool, CATOmxDefaultCollecManager<CATA5AttrNoDfltAbstractProcessor*>::manager, CATOMYPairAnyToBoolCollecMngr::mngrAnyToBool > CATOMYA5AttrNoDfltAbstractProcessorToPairAnyToBool;

typedef CATOmxOMap<CATA5AttrNoDfltAbstractProcessor*, CATOmxAny, CATOmxDefaultCollecManager<CATA5AttrNoDfltAbstractProcessor*>::manager, CATOmxDefaultCollecManager<CATOmxAny>::manager > CATOMYA5AttrNoDfltAbstractProcessorToAny;

typedef CATOmxOrderedOSet < CATA5AttrNoDfltAbstractProcessor*, CATOmxDefaultCollecManager<CATA5AttrNoDfltAbstractProcessor*>::manager> CATOMYA5AttrNoDfltAbstractPOrderedOSet;

#endif
