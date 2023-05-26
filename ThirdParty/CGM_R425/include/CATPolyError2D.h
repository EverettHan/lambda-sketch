// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyError2D.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// February 2005 Creation: NDO
//===================================================================
#ifndef CATPolyError2D_H
#define CATPolyError2D_H

#include "PolygonalModel.h"

class CATCGMOutput;

class ExportedByPolygonalModel CATPolyError2D 
{

public:
  
  enum ErrorCode
  {
    eNoError = 0,
    eMemoryError,
    eFatalError,
    eInterrupted,
    eInitializationError,
    eConstructionPolygon,
    eDegenerateSegment,
    eVerticesWithIdenticalCoordinates,
    eOverlappingSegments,
    eIntersectingSegments,
    eConstructionMonotonePolygon,
    eTriangulationMonotonePolygon
  };

  static void Print (CATCGMOutput& stream, const int iError);

};

#endif

