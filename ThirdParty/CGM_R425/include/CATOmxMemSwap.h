/**
 * @level Private
 * @usage U1
 */

#ifndef __CATOmxMemSwap_H
#define __CATOmxMemSwap_H

#include "CATOmxKernel.h"

/** swap size bytes between p1 and p2*/
ExportedByCATOmxKernel void CATOmxMemSwap(void* p1,void* p2,unsigned int size);

/**
 * Swaps obj1 and obj2 memory zone.
 * Type T must be "movable".
 */
template<typename T>
inline void CATOmxMemSwap(T& obj1,T& obj2) {CATOmxMemSwap(&obj1,&obj2,sizeof(T));}

#endif
