// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanTools.h
// Header definition of CATPolyBooleanTools
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2004 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanTools_H
#define CATPolyBooleanTools_H

#include "CATPolyBooleanOperators.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition

#include "CATLISTP_CATPolyMCurve.h"

class CATPolyGriddedMeshAndBarsConst;
class CATIPolyMesh;
class CATPolyIntersectionPoint;
class CATPolyMPointTopo;
class CATPolyMPoint;
class CATPolyExactArithmetic;
class CATPolyBooleanSegments1;
class CATPolyBooleanSegments2;
class CATMathPoint;
class CATMathPoint2D;
class CATMathVector;
class CATMathPlane;

#include "CATListPV.h"
#include "CATListOfInt.h"


class ExportedByCATPolyBooleanOperators CATPolyBooleanTools
{

public :

  CATPolyBooleanTools (const CATPolyExactArithmetic& iExactArithmetic, 
                       CATPolyGriddedMeshAndBarsConst* iOperandA, CATPolyGriddedMeshAndBarsConst* iOperandB); 

  ~CATPolyBooleanTools ();

  // 
  // CONSTRUCTIONS
  //

  HRESULT ConstructIntersectionPoint (const CATPolyIntersectionPoint& iIntersectionPoint,
                                      const CATMathPlane& iPlane,
                                      CATPolyMPointTopo& oMeshPoint0,
                                      CATMathPoint& oPoint) const;

  HRESULT ConstructIntersectionPoint (const CATPolyIntersectionPoint& iIntersectionPoint,
                                      CATPolyMPointTopo& oMeshPoint0,
                                      CATPolyMPointTopo& oMeshPoint1,
                                      CATMathPoint& oPoint) const;

  HRESULT ConstructBooleanSegments2 (const CATPolyBooleanSegments1& iSegments1,
                                     CATPolyBooleanSegments2& oSegments2) const;

  HRESULT ConstructBooleanSegments2 (const CATPolyBooleanSegments1& iSegments1,
                                     const CATIPolyMesh& iMesh, const CATMathPlane& iPlane,
                                     CATPolyBooleanSegments2& oSegments2) const;

  //
  // DISTANCE ANALYSIS
  //

  /**
   * Check whether a distance is within the merging distance.
   * @return 
   *   TRUE: The distance is within a merging distance.
   *   FALSE: Otherwise.
   */   
  CATBoolean IsDistanceWithinTolerance (const double iDistance) const;

  /**
   * Check whether two points are within merging distance.
   * Two points are within merging distance if the distances between their three coordinates is less 
   * than the grid sample size.
   * @param iPoint0
   *   The first point.
   * @param iPoint1
   *   The second point.
   * @return 
   *   TRUE: The points are within a merging distance.
   *   FALSE: Otherwise.
   */
  CATBoolean ArePointsWithinMergingDistance (const CATMathPoint& iPoint0, const CATMathPoint& iPoint1) const;

  /**
   * Check whether a point is within the grid sample size of a vertex.
   * The grid sample size is the minimum distance between two float values once they have
   * been normalized for exact arithmetic.
   * @param iPoint
   *   The point.
   * @param iVertexPosition
   *   The vertex position.
   * @return
   *   TRUE:  The distance is within the tolerance.
   *   FALSE: Otherwise.
   */
  CATBoolean IsPointWithinToleranceOfVertex (const CATMathPoint& iPoint,
                                             const CATMathPoint& iVertexPoint) const;

  /**
   * Check whether a point is within the grid sample size of a bar.
   * The grid sample size is the minimum distance between two float values once they have
   * been normalized for exact arithmetic.
   * @param iPoint
   *   The point
   * @param iBarPoint0
   *   The first point of the bar.
   * @param iBarPoint1
   *   The second point of the bar.
   * @return
   *   TRUE:  The distance is within the tolerance.
   *   FALSE: Otherwise.
   */
  CATBoolean IsPointWithinToleranceOfBar (const CATMathPoint& iPoint,
                                          const CATMathPoint& iBarPoint0,
                                          const CATMathPoint& iBarPoint1) const;

  /**
   * Check whether a point is within the grid sample size of a triangle.
   * The grid sample size is the minimum distance between two float values once they have
   * been normalized for exact arithmetic.
   * @return
   *   TRUE:  The distance is within the tolerance.
   *   FALSE: Otherwise.
   */
  CATBoolean IsPointWithinToleranceOfTriangle (const CATMathPoint& iPoint,
                                               const CATMathPoint& iTrianglePoint0,
                                               const CATMathPoint& iTrianglePoint1,
                                               const CATMathPoint& iTrianglePoint2) const;

  //
  // COMPARISON OF INTERSECTION POINTS
  //

  /**
   * Comparison of two intersection points defined symbolically.
   *   @return
   *      TRUE if the intersection points are identical or have equivalent definitions.
   *      FALSE otherwise.
   */
#if 0
  CATBoolean Compare (const CATPolyIntersectionPoint& iPoint1, const CATPolyIntersectionPoint& iPoint2) const;
#endif

protected :

  const CATPolyExactArithmetic& _ExactArithmetic;
  CATPolyGriddedMeshAndBarsConst* _GriddedOperand[2];

  HRESULT ConstructBarBarPoint (const CATMathPoint& startBar0, const CATMathPoint& endBar0,
                                const CATMathPoint& startBar1, const CATMathPoint& endBar1,
                                CATMathPoint& oPoint) const;

  HRESULT ConstructBarTrianglePoint (const CATMathPoint& startBar0, const CATMathPoint& endBar0,
                                     const CATMathPoint& vertex0, const CATMathPoint& vertex1, const CATMathPoint& vertex2,
                                     CATMathPoint& oPoint) const;

  HRESULT ConstructBarPlanePoint (const CATMathPoint& startBar0, const CATMathPoint& endBar0,
                                  const CATMathPlane& iPlane,
                                  CATMathPoint& oPoint) const;

  /*
   * Returns the tolerance below which two normalized values are within the grid sample size.
   * If the difference between two values is smaller than the tolerance, then the difference is
   * either equal to 0 or equal to the grid sample size.
   * If the difference is greater than the tolerance, then the difference is strictly greater than the 
   * grid sample size.
   */
  inline double GetTolerance () const;

};

#endif

