// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonCompare2D.cpp
//
//===================================================================
//
// Usage notes: Compares two polygons for equality, whatever the index
// order of vertices and bars. Checks vertices, bars, faces are
// identicals.
//
//===================================================================
//
// January 2019 Creation: xxc
//===================================================================

#include "PolygonalOperators.h"

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATPolyPolygon2D.h"
#include "CATMapOfPtrToPtr.h"

class ExportedByPolygonalOperators CATPolyPolygonCompare2D
{
public:

  CATPolyPolygonCompare2D();
  ~CATPolyPolygonCompare2D();

  HRESULT Run(const CATPolyPolygon2D & iPolygonA, const CATPolyPolygon2D & iPolygonB);

private:

  HRESULT CheckBasics();
  HRESULT CheckVertices();
  HRESULT CheckBars();
  HRESULT CheckLoops();
  HRESULT CheckFaces();

private:

  CATPolyVertex2D** _MapOfVAToVB;
  CATPolyBar2D** _MapOfEAToEB;
  CATMapOfPtrToPtr _MapOfLAToLB;

  const CATPolyPolygon2D * _PolygonA, * _PolygonB;
};
