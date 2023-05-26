#ifndef CATSysEstimateAllocatableArea_H
#define CATSysEstimateAllocatableArea_H
/**
// COPYRIGHT DASSAULT SYSTEMES 2002 
**/
#include "CATLib.h"
#include "IUnknown.h"
/**
 * CATSysEstimateAllocatableArea gives an estimation of allocatable area 
 * in the process.
 * This is just an estimation of the largest uncommitted zone of address
 * space. Already committed area reserved by the system allocator
 * are not taken into account. 
 * It may occurs that the value returned by CATSysEstimateAllocatableArea
 * is not allocatable . This is normal. This is just a rough estimation of 
 * available memory. In particular  we do not guarantee that the returned 
 * value is  not fragmented.
 * It is advised not to allocate the whole value returned : you are generally
 * not alone in the processus.
 *
 * On NT only available paging space is also taken into account.
 * 
 **/
ExportedByJS0LIB  HRESULT CATSysEstimateAllocatableArea(size_t *oEstimatedArea);
#endif
