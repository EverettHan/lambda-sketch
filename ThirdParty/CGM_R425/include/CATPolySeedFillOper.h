// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySeedFillOper.h
// Header definition of CATPolySeedFillOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  July 2004/October 2005  Creation:  rxu/ndo
//===================================================================
#ifndef CATPolySeedFillOper_H
#define CATPolySeedFillOper_H

#include "CATPolyAnalyzeOper.h"
#include "CATPolyAnalyzeOperators.h"
#include "CATListOfInt.h"

class CATHTableOfIntInt;
class CATPolyMCurve;
class CATListPtrCATPolyMCurve;


/**
 * This operator floods a polymesh to find all the triangles and vertices that are connected to 
 * a set of seed triangles.  Vertex paths can be added to the operator to limit the search to 
 * the enclosed areas. 
 */
class ExportedByCATPolyAnalyzeOperators CATPolySeedFillOper : public CATPolyAnalyzeOper
{

public:

  /**
  * Constructor
  */
  CATPolySeedFillOper (CATIPolyMesh* iPolyMesh);

  /**
  * Destructor
  */
  virtual ~CATPolySeedFillOper ();

  /**
  * Adds vertex paths to the operator.  When the operator runs, it will flood the polymesh from the seeds
  * without ever crossing the vertex paths added to this operator.
  * @param iMeshCurves
  *   A list of vertex path represented by polymesh curves. Only the polymesh curves that are vertex
  *   paths will be added.
  */ 
  HRESULT AddVertexPaths (const CATListPtrCATPolyMCurve& iMeshCurves);

  /**
  * Adds a vertex path to the operator.  When the operator runs, it will flood the polymesh from the seeds
  * without ever crossing the vertex paths added to this operator.
  * @param iPolyMeshCurve
  *   A vertex path represented by a CATPolyMCurve. The polymesh curve will be added only if it is a vertex path.
  */ 
  HRESULT AddVertexPath (const CATPolyMCurve* iMeshCurve);

  /**
  * Adds a vertex path to the operator.  When the operator runs, it will flood the polymesh from the seeds
  * without ever crossing the vertex paths added to this operator.
  * @param iVertexPath
  *   The vertex path.  To prevent selection of triangles and vertices beyond the vertex path, the 
  *   vertex path should form a closed loop or extend from a free edge to a free edge.
  */ 
  HRESULT AddVertexPath (const CATListOfInt& iVertexPath);

  /**
  * Set a seed triangle.
  * @param iTriangle
  *   A seed triangle.
  */
  HRESULT SetSeedTriangle (const int iSeedTriangle);

  /**
  * Set the seed triangles.
  * @param iSeedTriangles
  *   The list of seed triangles.
  */
  HRESULT SetSeedTriangles (const CATListOfInt& iSeedTriangles);

  /**
  * Perform seed fill.
  * The operator finds all the triangles that can be reached along a vertex path from a seed triangle.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT Run ();

  /**
  * Returns the seed fill triangles.
  * @return
  *   The list of seed fill triangles.
  **/
  const CATListOfInt& GetSeedFillTriangles () const;

  /**
  * Returns the complement of the currently selected triangles.
  * @param ioSelectedTriangles
  *   The list that will be set with the selected triangles complement.
  * @return
  *   S_OK on successful completion and E_FAIL otherwise.
  **/
  HRESULT GetSeedFillTrianglesComplement (CATListOfInt& ioTriangles) const;

private:

  CATHTableOfIntInt* _Bars;
  CATListOfInt _SeedStack;

  CATListOfInt _SeedFillTriangles;
};

#endif
