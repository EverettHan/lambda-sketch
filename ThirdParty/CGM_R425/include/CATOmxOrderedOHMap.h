#ifndef CATOmxOrderedOHMap_H
#define CATOmxOrderedOHMap_H

/**
 * CATOmxOrderedOHMap
 * This class has the exact same API as CATOmxOHMap but is based on an "ordered set"
 * As a consequence, the behavior is exactly the same as CATOmxOrderedOHMap
 * except that contrarily to CATOmxOHMap, enumeration order of the iterator is guaranteed to be insertion order
 * @see CATOmxOHMap
 */
#include "CATOmxOHMap.h"

//do not look what's hereunder, it's horrid
//warned you...

//remove guard for CATOmxOHMap
#undef CATOmxOHMap_H
//change class names
#define CATOmxOHMap CATOmxOrderedOHMap
#define CATOmxBaseSet CATOmxBaseOrderedOSet
#define CATOmxPairCollecManager CATOmxCoupleCollecManager
#include "CATOmxCoupleCollecManager.h"
#include "CATOmxBaseOrderedOSet.h"
//re-include
#include "CATOmxOHMap.h"

//clean the mess
#undef CATOmxOHMap
#undef CATOmxBaseSet
#undef CATOmxPairCollecManager

#endif
