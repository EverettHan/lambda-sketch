// COPYRIGHT Dassault Systemes 2003, all rights reserved
//===================================================================
//
// CATPolyBuildBarsOper.h
// Header definition of CATPolyBuildBarsOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Oct 2003 Creation: dhp
//===================================================================
#ifndef CATPolyBuildBarsOper_h
#define CATPolyBuildBarsOper_h

#include "CATPolyAnalyzeOperators.h"
#include "CATPolyAnalyzeOper.h"
#include "CATListOfInt.h"
#include "CATSetOfInt.h"
#include "CATListPV.h"
#include "CATBoolean.h"

class CATIPolyMesh;
class CATIPolyMeshTriangleIterator;

/**
* Class used to build a unique set of edges for a polygon.
*/
class ExportedByCATPolyAnalyzeOperators CATPolyBuildBarsOper : public CATPolyAnalyzeOper
{

public:

  CATPolyBuildBarsOper(CATIPolyMesh* iPolyMesh);

  ~CATPolyBuildBarsOper(void);

  /**
  * A parameter controlling whether to include bars with one or two vertices on a hole.
  * If the parameter is set to true, then the operator will not include bars with one or two vertices
  * on a hole.  By default, this parameter is set to false.  (Hole vertices included.)
  */
  void ExcludeBoundaryVertices(const CATBoolean iExcludeBoundaryVertices);

  /**
  * Mark a set of vertices to be treated as excluded boundary vertices.
  */
  void SetExcludedVertices(const CATSetOfInt* iExcludedVertices);

  HRESULT Run(void);

  HRESULT RunOnSelectedTriangles(const CATListOfInt& iTriangles);

  HRESULT RunOnSelectedVertices(const CATListOfInt& iVertices);

  /**
  * Returns the number of bars in the polygon or in the vertex or triangle selection.
  * @return
  *   The number of unique bars.
  */
  int GetNbBars() const;

  /**
  * Returns the vertices defining a bar.
  * @param iBarIndex
  *   The index of the desired bar.
  *   <br><b>Legal values</b>: 1 to the number of bars, inclusive.
  * @param oVertex0
  *   The index of the first vertex of the bar.
  * @param oVertex1
  *   The index of the second vertex of the bar.
  *
  */
  CATBoolean GetBar(const int iBarIndex, int & oVertex0, int & oVertex1) const;

  CATBoolean RemoveBar(const int iBarIndex);

  CATBoolean UpdateBar(const int iBarIndex, const int iVertex1, const int iVertex2);

  /**
  * Returns a unique list of vertices that are referenced by the bars.
  * @param
  *   The relative indices of the vertices.
  * @return
  *   TRUE if successful or FALSE otherwise.
  */
  CATBoolean GetVertices(CATListOfInt & oVertices) const;

  CATBoolean GetVertices(CATListOfInt & oVertices, CATListPV & vertexBars) const;

  CATBoolean GetBars(CATListOfInt & barVertices0, CATListOfInt & barVertices1) const;

private:

  HRESULT RunOnSelectedTriangles(const int iNbTriangles, CATIPolyMeshTriangleIterator& iTriangleIterator);

  CATBoolean IsHoleVertex(const int iVertex);

  CATBoolean _ExcludeBoundaryVertices;
  const CATSetOfInt* _ExcludedVertices;

  CATListOfInt _BarVertices0;
  CATListOfInt _BarVertices1;
};

#endif
