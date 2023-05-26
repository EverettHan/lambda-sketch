// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshOpenOrCloseChecker.h
// Header definition of CATPolyMeshOpenOrCloseChecker
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2007  Creation: NDO
//===================================================================
#ifndef CATPolyMeshOpenOrCloseChecker_H
#define CATPolyMeshOpenOrCloseChecker_H

#include "CATPolyAnalyzeOperators.h"
#include "CATPolyAnalyzeOper.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"


/**
 * This operator checks if a mesh is closed or open.  
 * A mesh is closed if, for each bar, the sum of the orientation of the triangles around the bar (counting 
 * triangles multiplicities) is 0.  This verification is purely combinatorial.
 */
class ExportedByCATPolyAnalyzeOperators CATPolyMeshOpenOrCloseChecker : public CATPolyAnalyzeOper
{

public:

  CATPolyMeshOpenOrCloseChecker () {}
  virtual ~CATPolyMeshOpenOrCloseChecker () {}

public: 

  // Return TRUE if the mesh is open at the bar defined by (v0, v1) and FALSE otherwise.
  CATBoolean IsOpenBar (const CATIPolyMesh& iMesh, const int v0, const int v1);

  // Return TRUE if the mesh is closed and FALSE otherwise.
  // @param oNbOpenBars
  //   An optional argument to count the number of bars that fail the closure test.
  CATBoolean IsMeshClosed (const CATIPolyMesh& iMesh, int* opNbOpenBars = 0);

private:

  CATListOfInt _AdjacentTriangles;

};

#endif
