// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshCleaner.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// February 2006 Creation: NDO
//===================================================================
#ifndef CATPolyMeshCleaner_h
#define CATPolyMeshCleaner_h

#include "CATPolyRegularizeOperators.h"
#include "CATPolyModOper.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATIPolyMesh;
class CATPolyBars;
class CATPolyExactArithmetic;
class CATPolyGriddedMeshAndBars;
class CATPolyGriddedPositionsConst;
class CATIPolySurfaceVertexPositionConstLayer;
class CATMathPoint;
class CATSetOfInt;


class ExportedByCATPolyRegularizeOperators CATPolyMeshCleaner : public CATPolyModOper
{

public:

  CATPolyMeshCleaner (const CATPolyExactArithmetic& iExactArithmetic);
  CATPolyMeshCleaner (const CATPolyExactArithmetic* iExactArithmetic);

  ~CATPolyMeshCleaner (void);

  // Turns on or off the option to clean unreferenced vertices. (Default is on.)
  // An unreferenced vertex is a vertex not referenced by any triangle 
  // (and any bar if using CATPolyGriddedMeshAndBars.)
  inline void SetCleanUnreferencedVertices (const CATBoolean iClean);

public:

  HRESULT Run (CATIPolyMesh& iMesh, const CATPolyGriddedPositionsConst& iGriddedVertexPositions);

  HRESULT Run (CATPolyGriddedMeshAndBars& iOperand);

public:

  // DO NOT USE.  DEPRECATED.
  HRESULT Run ();

private:

  const CATPolyExactArithmetic* _ExactArithmetic;
  const CATPolyBars* _Bars;
  const CATPolyGriddedPositionsConst* _GriddedPositions;
  CATIPolySurfaceVertexPositionConstLayer* _SurfaceVertexPositions;

  CATBoolean _CleanUnreferencedVertices;

private:

  void GetVertexPositions (const int vertices[], 
                           CATMathPoint& A, CATMathPoint& B, CATMathPoint& C) const;

  HRESULT RemoveUnreferencedVertex (CATIPolyMesh& mesh, const int vertex);
  HRESULT RemoveVertices (CATIPolyMesh& iMesh, const CATListOfInt& iVertices);

  HRESULT RemoveTriangle (CATIPolyMesh& mesh, const int triangle);
  HRESULT RemoveTriangles (CATIPolyMesh& iMesh, const CATListOfInt& iTriangles);
  HRESULT RemoveDuplicateTriangles (CATIPolyMesh& iMesh, const CATListOfInt& iTriangles);
  HRESULT RemoveDegenerateTriangles (const CATPolyExactArithmetic& iExactArithmetic,
                                     CATIPolyMesh& iMesh,
                                     CATSetOfInt& iTriangles);

  HRESULT RunPrivate (CATIPolyMesh& iMesh);

};

inline void CATPolyMeshCleaner::SetCleanUnreferencedVertices (const CATBoolean iClean)
{
  _CleanUnreferencedVertices = iClean;
}

#endif

