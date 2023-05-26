// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanWireIntersectOper.h
// Header definition of CATPolyBooleanWireIntersectOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// November 2006 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanWireIntersectOper_H
#define CATPolyBooleanWireIntersectOper_H

#include "CATPolyBooleanOperators.h"
#include "CATPolyBoolean.h"
#include "CATPolyBitSet.h"
#include "CATPolyIntersectionPointBuckets.h"
#include "CATBucketsOfInt.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"  // For the definition of HRESULT.

#include "CATLISTV_CATMathPoint.h"
#include "CATListOfInt.h"

class CATPolyGriddedMeshAndBars;
class CATPolyGriddedMeshAndBarsConst;
class CATIPolyMesh;
class CATIPolyMeshTriangleIterator;
class CATPolyBars;
class CATPolyBarsBarIterator;
class CATPolyExactArithmetic;
class CATPolyBooleanObserver;
class CATPolyBooleanIntersectionPoints;
class CATPolyIntersectionPoint;
class CATMathPoint;

class CATIPolyCurve;


/*
Operator that calculates the intersection of wires (CATIPolyCurve objects) with a volume represented
by a CATIPolyMesh object.  The CATIPolyMesh object must be closed.  For the sake of the intersection
computation, the volume is considered a closed domain:  Points of the wire on the surface of the volume are
intersecting the volume and therefore part of the result.  The clipping volume should not be self-intersecting.
(The notion of inside and outside w.r.t. local relative boundary position is unambiguous.)

To run the operator, set the volume and optionally its spatial partition (to speed up the computation).
The Run method clips the free bars.  It does not clip bars that lie on the mesh.
*/
class ExportedByCATPolyBooleanOperators CATPolyBooleanWireIntersectOper
{

public :

  CATPolyBooleanWireIntersectOper (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolyBooleanWireIntersectOper ();

  /**
   * Clip the free bars by intersecting them with the clipping volume.
   * @param iMesh
   *   Mesh containing the coordinates of the free bar vertices.
   * @param iBars
   *   The set of free bars.  The bars refer to vertices of the mesh.
   * @param iClippingVolume
   *   The clipping volume.
   * @param iObserver
   *   Boolean observer to update layers on top of the bars.
   */
  HRESULT Run (CATPolyGriddedMeshAndBars& iGriddedOperand,
               CATPolyGriddedMeshAndBarsConst& iClippingVolume, CATPolyBooleanObserver* iObserver = 0);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;

  // The clipping volume.
  CATPolyGriddedMeshAndBarsConst* _ClippingVolume;

  // The bars.
  CATPolyGriddedMeshAndBars* _GriddedOperand;

  // Observer of boolean events (for updates of layer data.)
  CATPolyBooleanObserver* _Observer;

private:

  // Iterator through all pairs Triangle-Bar that might be intersecting.
  CATIPolyMeshTriangleIterator* _TriangleIter;
  CATPolyBarsBarIterator* _BarIter;

  int _Triangle;
  int _Bar;

  CATPolyBitSet _BarIsFreeLayer;  // A flag set to TRUE for free bars.

private:

  // Intersection points.
  CATPolyIntersectionPointBuckets _IntersectionPoints;    // Intersection points (symbolic definition.)

  // Constructed intersection points.
  CATLISTV(CATMathPoint) _Points;                         // Constructed intersection points.
  CATListOfInt           _SortedPointIndices;             // Sorted list of point indices.

  // Position w.r.t. clipping volume before and after an intersection point along the bar.
  CATListOfInt _PointBitFields;     // Positions before and after the intersection points.

  // A WN attribute can be negative, null or positive:
  //   - A positive value means the bar is inside the clipping volume.
  //   - A negative value means the bar is outside the clipping volume.
  //   - A value equals to 0 means the bar is on the boundary of the clipping volume.
  CATBucketsOfInt _BarWNLayer;  // An attribute layer for the bars (in/out w.r.t. clipping volume).

private:

  void Clear (); // Clear working data before a clipping operation.

  // Iterator to go though the valid (triangle, bar) pairs that might be interecting.
  // where triangle is a triangle from the clipping volume and bar is a free bar.
  void BeginTriangleBarIterator () ;
  CATBoolean EndTriangleBarIterator ();
  void StepTriangleBarIterator ();

  // Find all the intersection points between the segments and the mesh (symbolic definition).
  HRESULT FindIntersectionPoints ();
  HRESULT CopyIntersectionPoints (const CATPolyBooleanIntersectionPoints& iCopyFrom,
                                  CATPolyIntersectionPointBuckets& iCopyTo) const;

private:

  // Construction of the intersection points.
  HRESULT ConstructTriangleBarPoint (const CATMathPoint T[], const CATMathPoint S[], CATMathPoint& oPoint);
  HRESULT ConstructBarBarPoint (const CATMathPoint& T0, const CATMathPoint& T1, const CATMathPoint S[], CATMathPoint& oPoint);
  HRESULT ConstructIntersectionPoints () ;

  // Sort the intersection points according to (1) the bar index and (2) according to their relative 
  // position on a same bar.
  HRESULT SortIntersectionPoints () ;

private:

  // Return the position of a point w.r.t. the plane defined by the triangle.
  int GetPointPositionWRTPlane (const CATMathPoint T[], const CATMathPoint& P) const;

  // Return the bit fields for the ith intersection point.
  unsigned int& GetPointBitFields (const int iPoint) ;

  // Set the bit fields of an intersection point.  The bit fields give the position of points along the curve
  // slightly before and slightly after the intersection point.
  HRESULT SetPointBitFields (const CATPolyIntersectionPoint& intPoint, 
                             const CATMathPoint T[], const CATMathPoint S[],
                             unsigned int& bitFields) const;

  HRESULT SetPointBitFieldsTriangleBar (const CATMathPoint T[],
                                        const CATMathPoint S[],
                                        unsigned int& bitFields) const;

  HRESULT SetPointBitFieldsTriangleVertex (const CATMathPoint T[],
                                           const CATMathPoint S[],
                                           const int indexVertex, // 0 or 1
                                           unsigned int& bitFields) const;

  HRESULT SetPointBitFieldsBarBar (const CATPolyIntersectionPoint& intPoint,
                                   const CATMathPoint S[],
                                   unsigned int& bitFields) const;

  HRESULT SetPointBitFieldsBarVertex (const CATPolyIntersectionPoint& I,
                                      const CATMathPoint S[],
                                      const int idxVertex,  // 0 or 1
                                      unsigned int& bitFields) const;

  HRESULT SetPointBitFieldsVertexBar (const CATPolyIntersectionPoint& intPoint,
                                      const CATMathPoint S[],
                                      unsigned int& bitFields) const;

  HRESULT SetPointBitFieldsVertexVertex (const CATPolyIntersectionPoint& I,
                                         const CATMathPoint S[],
                                         const int idxVertex,  // 0 or 1
                                         unsigned int& bitFields) const;

private:

  HRESULT GatherBarPoints (const CATListOfInt& mapIntersectionPointToVertex,
                           const int kStart, int& kEnd, 
                           CATListOfInt& intersectionPoints,
                           CATListOfInt& barVertices) const;

  HRESULT RefineBar (const int bar, const CATListOfInt& intersectionPoints,const CATListOfInt& vertices);

  HRESULT RefineBars ();

  HRESULT RemoveBars ();

private:

  int GetPosition (const CATMathPoint& point) const;

  void ResetBarWNLayer ();

  HRESULT PropagateWNAttributes ();
  HRESULT PropagateWNAttributes (const int bar, const int wn, CATPolyBitSet& barVisited);
  HRESULT PropagateWNAttributes (const int b, const int wn, const int v,
                                 CATPolyBitSet& barVisited, CATListOfInt& stack);

};

#endif
