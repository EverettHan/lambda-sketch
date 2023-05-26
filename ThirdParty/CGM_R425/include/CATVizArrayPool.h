#ifndef _CATVizArrayPool_
#define _CATVizArrayPool_

#include <sys/types.h>

#include "SGInfra.h"

class ExportedBySGInfra CATVizArrayPool
{
public:
	static void *AllocateArray(size_t iSize);
	static void FreeArray(size_t iSize, void *array);
	static void *AllocateVolatileArray(size_t iSize);
	static void FreeVolatileArray(size_t iSize, void *array);
   static void *ReallocateVolatileArray(size_t iInitialSize,size_t iNewSize, void *oldArray);
};

#endif
