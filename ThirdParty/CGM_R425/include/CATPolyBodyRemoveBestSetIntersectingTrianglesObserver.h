// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRemoveBestSetIntersectingTrianglesObserver.h
//
//===================================================================
//
//===================================================================
//
// Feb 2015 Creation: NG4
//===================================================================
#ifndef CATPolyBodyRemoveBestSetIntersectingTrianglesObserver_h
#define CATPolyBodyRemoveBestSetIntersectingTrianglesObserver_h

#include "PolyBodyBVHOperators.h"

// Poly math
#include "CATPolyBodySelfClearanceObserver.h"
class CATCellId;

// Math
#include "CATMathPoint.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATSetOfPtr.h"

// Poly Objects
#include "CATIPolyMesh.h"
class CATPolyFace;

typedef struct TriangleNode
{
  TriangleNode() : _mArea(0.0), _mScore(0.0), _mMesh(0), _mTriangleID(0) {}

  double _mArea;
  CATSetOfPtr _mNeighbours;
  double _mScore;
  CATIPolyMesh * _mMesh;
  int _mTriangleID;
} TriangleNode;

class ExportedByPolyBodyBVHOperators CATPolyBodyRemoveBestSetIntersectingTrianglesObserver : public CATPolyBodySelfClearanceObserver
{

public:
  /** Default constructor, does nothing */
  CATPolyBodyRemoveBestSetIntersectingTrianglesObserver(CATPolyFace &iPolyFace);
  /** Destructor */
  ~CATPolyBodyRemoveBestSetIntersectingTrianglesObserver();
  /**
   * Returns the number of auto-intersecting triangles
   */ 
  int GetNbOfTriangles();

  /** 
   * Cleans the meshes by removing any intersecting triangles 
   * Call this method after having called CATPolyBodySelfIntersector::Check 
   */
  HRESULT Clean(CATBoolean iDeleteUnreferencedVertices = TRUE);

  /** CATPolyBodySelfClearanceObserver implementation */
  virtual void AddClearance(CATCellId * pCellId1, int indext1, const CATMathPoint & barycenter1,
                            CATCellId * pCellId2, int indext2, const CATMathPoint & barycenter2,
                            double distance);
  /** CATPolyBodySelfClearanceObserver implementation */
  virtual void AddIntersection(CATCellId * pCellId1, int indext1,
                               CATCellId * pCellId2, int indext2,
                               const CATLISTV(CATMathPoint) & intersection);

private:
  
  // Local service to find a specific TriangleNode in _mNodes
  void LookForTriangleNode(const CATIPolyMesh * iPolyMesh, const int &iIdx, TriangleNode * &oTriNode);

private:

  CATListPV _mNodes;
  CATPolyFace &_mPolyFace;
  CATIPolySurface &_mPolySurface;
  CATIPolySurfaceVertexCellConstLayer * _mCellLayer;
};

#endif // CATPolyBodyRemoveBestSetIntersectingTrianglesObserver_H

