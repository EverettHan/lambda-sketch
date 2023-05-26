/**
 * @level Private
 * @usage U1
 */
// Do not edit this file use Counters.pl Counters
#ifndef __CATOmbCountersSetMmu_h__
#define __CATOmbCountersSetMmu_h__
#include "CATOmbMonitor.h"
// Do not edit this file use Counters.pl Counters
#define AddMmuDispatch(add) CATOmbMonitor::Add(24,(add))
#define IncMmuDispatch CATOmbMonitor::Add(24,1)
// Do not edit this file use Counters.pl Counters
#define AddMmuChangeRep(add) CATOmbMonitor::Add(21,(add))
#define IncMmuChangeRep CATOmbMonitor::Add(21,1)
// Do not edit this file use Counters.pl Counters
#define AddMmuSetGraphicAttribute(add) CATOmbMonitor::Add(23,(add))
#define IncMmuSetGraphicAttribute CATOmbMonitor::Add(23,1)
// Do not edit this file use Counters.pl Counters
#define AddMmuBuildPerForLinearBody(add) CATOmbMonitor::Add(22,(add))
#define IncMmuBuildPerForLinearBody CATOmbMonitor::Add(22,1)
#endif
