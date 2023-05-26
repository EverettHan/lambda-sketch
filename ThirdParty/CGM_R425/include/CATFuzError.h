// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATFuzError.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// February 2004 Creation: NDO
//===================================================================
#ifndef CATFuzError_H
#define CATFuzError_H

#include "CATFuzzyOperators.h"


class ExportedByCATFuzzyOperators CATFuzError 
{

public:
  
  enum ErrorCode
  {
    eNoError = 0,
    eMemoryError,
    eInvalidVoxelSize,
    eBoundingBoxEmpty,
    eUninitializedVariable,
    eInterrupted,
    eFanMeshConfig
  };
  
};

#endif

