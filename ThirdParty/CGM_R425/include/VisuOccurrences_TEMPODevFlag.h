// COPYRIGHT DASSAULT SYSTEMES 2007
#ifndef VisuOccurrences_TEMPODevFlag_H
#define VisuOccurrences_TEMPODevFlag_H

/**
* @level Protected
* @usage U1
*/

#include "TempoDevFlags.h"
#include "CATBoolean.h"
#include "CATOmxDeprecated.h"

OMX_DEPRECATED("dead project") inline int Is_PS_OCC_MISSING_ITF_TEMPODevFlag() { return 0; }

OMX_DEPRECATED("dead project") inline int Is_PS_OCC_Linkable_TEMPODevFlag() { return 0; }

OMX_DEPRECATED("definitively activated") inline int Is_PS_OCC_TACTICAL() { return 1; }

OMX_DEPRECATED("dead project") inline int Is_PS_OCC_PLO() { return 0; }

OMX_DEPRECATED("dead project") inline int Is_PS_OCC_NOT_INST() { return 0; }
OMX_DEPRECATED("dead project") inline int Is_PS_OCC_ON_DEMAND() { return 0; }

/**
* Occurrences built on light model from index
*/
extern ExportedByTempoDevFlags int Is_OCC_WITH_LIGHT_MODEL();

/**
* MultiRep Project, visu update. Different modes :
* export PS_AFI=1 : activate AFO project with rep inst occurrences, public 3D overloadings
* export PS_AFI=2 : activate AFO project with rep inst occurrences, private 3D overloadings
* export PS_AFI=4 : activate AFO project without rep inst occurrences : use 3D overloadings
* export PS_AFI=8 : use rep inst occurrences everywhere, even if no overloading
*/
extern ExportedByTempoDevFlags int ProjectMultiRep();

/**
* Occurrence for Rep Instances
*/
extern ExportedByTempoDevFlags int Is_OCC_REPINST();

/**
* Occurrence for Rep Instances
* Tactical implementation for migration. Deactivated by default
*/
extern ExportedByTempoDevFlags int Is_PS_REPOCC_NOT_REPINST();

OMX_DEPRECATED("definitively activated") inline int PS_REPOCC_NO_CATIPrdObjectImpl() { return 1; }

#endif

