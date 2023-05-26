// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyEdgeFaceClashOper.h
//
//===================================================================
//
// Usage notes:
// Operator to compute clash between a poly curve and a poly surface
//
//===================================================================
//
// Sep 2009 Creation: JXO
//===================================================================
#ifndef CATPolyBodyEdgeFaceClashOper_h
#define CATPolyBodyEdgeFaceClashOper_h

#include "PolyBodyBVHOperators.h"
// Math
#include "CATMathTransformation.h"

// System
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATBVHNodeConst;
class CATBucketsOfDouble;
class CATBucketsOfInt;

/**
 * Computes clash between an edge and a face and returns intersection points.
 *
 */

class ExportedByPolyBodyBVHOperators CATPolyBodyEdgeFaceClashOper

{
public:
  /**
   * @param pos1: Position of edge
   * @param pos2: Position of face
   * @param Pos1ToPos2: Relative position of BVs of face regarding BVs of Edge (or inverted iff NodesAreInverted is set to TRUE)
   */
  CATPolyBodyEdgeFaceClashOper(CATMathTransformation * pos1 = NULL, CATMathTransformation * pos2 = NULL, CATMathTransformation * Pos1ToPos2 = NULL);
  ~CATPolyBodyEdgeFaceClashOper(){}

  /**
   * Clash Edge against Face and returns unsorted intersections points.
   * Edge should be contained in iNode1's attribute, and face in iNode2's.
   * Note that it is assumed that iNode1 and iNode2 are already clashing.
   * x, y, z coordinates of intersection points are appended to oPointsBucket.
   * IndicesBucket contains the indices, i.e. indices of intersecting bar in the edge
   * (even indices), indices of the intersecting triangles (odd indices)
   */
  HRESULT ClashEdgeAgainstFace(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2, CATBucketsOfDouble & oPointsBucket, CATBucketsOfInt & IndicesBucket, CATBoolean NodesAreInverted, CATBoolean iDiscardEdgeLimits = FALSE);

private:
/**
 * returns 0 if no clash, 1 otherwise
 */
  CATBoolean BVOverlap(CATBVHNodeConst & iNode1, CATBVHNodeConst & iNode2);

private:
  CATMathTransformation _Pos1;
  CATMathTransformation _Pos2;
  CATMathTransformation _Pos1To2;

};

#endif

