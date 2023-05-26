// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySelfIntersectOper.h
// Header definition of CATPolySelfIntersectOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// November 2004  Creation:  NDO
//===================================================================
#ifndef CATPolySelfIntersectOper_H
#define CATPolySelfIntersectOper_H

#include "CATPolyAnalyzeOper.h"
#include "CATPolyAnalyzeOperators.h"

#include "CATListOfInt.h"

class CATPolyExactArithmetic;
class CATIPolyMesh;
class CATPolyGriddedPositionsConst;
class CATPolyMeshPartitionOper;


/**
 * This operator finds the self intersection in a polymesh. 
 *
 */
class ExportedByCATPolyAnalyzeOperators CATPolySelfIntersectOper : public CATPolyAnalyzeOper
{

public:

  CATPolySelfIntersectOper (const CATPolyExactArithmetic& iExactArithmetic);

  virtual ~CATPolySelfIntersectOper ();

  /**
  * Run the operator
  * @return
  *   S_OK the operator runs successfully; E_FAIL otherwise.
  **/
  HRESULT Run (const CATIPolyMesh& iMesh, CATPolyGriddedPositionsConst& iGriddedVertexPositions,
               CATPolyMeshPartitionOper* meshPartition = 0);

  /**
  * Returns the number of intersecting triangle pairs.
  **/
  int GetNbIntersectingTrianglePairs () const;

  /**
  * Returns the indices of the two triangles that are intersecting.
  * @param iIntersection
  *   The intersection number from 1 to the total number of intersections included.
  * @param oTriangle1
  *   The first intersecting triangle.
  * @param oTriangle2
  *   The second intersecting triangle.
  * @return
  *   S_OK the operator runs successfully; E_FAIL otherwise.
  */
  HRESULT GetIntersectingPair (const int iIntersection, int& oTriangle1, int& oTriangle2) const;

  /**
  * Returns the number of degenerate triangles.
  **/
  int GetNbDegenerateTriangles () const;

  /**
  * Returns the list of degenerate triangles.
  */
  const CATListOfInt& GetDegenerateTriangles () const;

private:

  const CATPolyExactArithmetic& _ExactArithmetic;

  CATListOfInt _Triangles1;
  CATListOfInt _Triangles2;

  CATListOfInt _DegenerateTriangles;

};

#endif

