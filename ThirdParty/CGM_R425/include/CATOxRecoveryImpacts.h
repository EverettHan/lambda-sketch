#ifndef CATOxRecoveryImpacts_H
#define CATOxRecoveryImpacts_H

/**
 * @level Private
 * @usage U1
 */
#include "CATBaseUnknown.h"

typedef unsigned int CATOxRecoveryImpacts;

#define CATOxRecoveryImpacts_Cardinality                        2
#define CATOxRecoveryImpacts_ALL                        0xFFFFFFFF
#define CATOxRecoveryImpacts_RELATIONAL                 0x00000001
#define CATOxRecoveryImpacts_STREAMS                    0x00000002

#endif
