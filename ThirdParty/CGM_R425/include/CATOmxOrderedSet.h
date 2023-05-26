#ifndef CATOmxOrderedSet_H
#define CATOmxOrderedSet_H

/**
 * CATOmxOrderedSet
 * This class has the exact same API as CATOmxSet but is based on an "ordered set"
 * As a consequence, the behavior is exactly the same as CATOmxSet
 *  except that contrarily to CATOmxSet, enumeration order of the iterator is guaranteed to be insertion order
 * @see CATOmxSet
 */
#include "CATOmxSet.h"


//do not look what's hereunder, it's horrid
//warned you...
//remove guard for CATOmxSet
#undef CATOmxSet_H 
//remove guard for CATOmxBaseSet
#undef CATOmxBaseSet_H

//change class names
#define CATOmxBaseSet CATOmxBaseOrderedSet
#define CATOmxSet CATOmxOrderedSet
#define CATOmxBaseSetInternal CATOmxBaseOrderedOSetInternal
#define naive_set_manager naive_ordered_set_manager
#define com_set_manager com_ordered_set_manager
#define sharable_set_manager sharable_ordered_set_manager
//re-include
#include "CATOmxSet.h"

#ifndef OMX_IMPLEMENT_ORDERED_SET
//clean the mess
#undef CATOmxBaseSet
#undef CATOmxSet
#undef CATOmxBaseSetInternal
#undef naive_set_manager
#undef com_set_manager
#undef sharable_set_manager
#endif

#endif

