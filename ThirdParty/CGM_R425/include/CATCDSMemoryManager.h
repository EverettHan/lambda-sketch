// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
//
// CATCDSMemoryManager:
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Nov 2007  Creation                         Vladislav Kornienkoint
//=============================================================================

#ifndef CATCDSMemoryManager_h
#define CATCDSMemoryManager_h

//#define CATCDS_MEMORY_MANAGER

#ifdef CATCDS_MEMORY_MANAGER
#include "CATCDSUtilities.h"

#include <stdio.h>
#include <stdlib.h>

class ExportedByCATCDSUtilities CATCDSMemoryManager {
public:
  virtual ~CATCDSMemoryManager();

  virtual size_t GetBlockSize(void * ipBlock) const = 0;

  //virtual void * Calloc(size_t iNumber, size_t iSize) = 0;
  virtual void * Malloc(size_t iSize) = 0;
  //virtual void * MallocA(size_t iSize) = 0;
  //virtual void * Realloc(void * ipBlock, size_t iSize) = 0;
  virtual void Free(void * ipBlock) = 0;
  //virtual void FreeA(void * ipBlock) = 0;

  virtual void BeginMeasureMemory() {}
  virtual void EndMeasureMemory() {}

  virtual size_t GetMemoryUsageTotal() const { return 0; }
  virtual size_t GetMemoryUsagePeak() const { return 0; }

  virtual size_t GetNbOfAllocatedBlocks() const;

  virtual void PrintStatistics() {}
};

extern ExportedByCATCDSUtilities CATCDSMemoryManager *pMemoryManager;
#endif

#endif
