// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanSegments2.h
// Header definition of CATPolyBooleanSegments2
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// December 2005 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanSegments2_H
#define CATPolyBooleanSegments2_H

#include "CATPolyBooleanOperators.h"
#include "CATLISTV_CATPolyMPointTopo.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATIPolyMesh;
class CATPolyBooleanSegments1;
class CATPolyBooleanMap;
class CATPolyMPointTopo;
class CATMathPoint;
class CATHTableOfIntInt;
class CATHTableOfIntIntIterator;

class CATCGMOutput;


class ExportedByCATPolyBooleanOperators CATPolyBooleanSegments2
{

public :

  CATPolyBooleanSegments2 (const CATPolyBooleanSegments1* iIntersectionSegments);

  ~CATPolyBooleanSegments2 ();

  CATBoolean AddSegment (const int iIdxPoint0, const int iIdxPoint1);

  CATBoolean RemoveSegment (const int iIdxPoint0, const int iIdxPoint1);

  // LocateSegment is not symmetric because segments are oriented!  
  // LocateSegment (iIdxPoint0, iIdxPoint1) != LocateSegment (iIdxPoint1, iIdxPoint0).
  CATBoolean LocateSegment (const int iIdxPoint0, const int iIdxPoint1) const;

  // Returns the total number of segments.
  int GetNbSegments () const;

  HRESULT GetSegments (CATListOfInt& pointIndices0, CATListOfInt& pointIndices1) const;

  // Returns the set of segments.  Segments may be added or deleted into this array.
  // The segments are defined by indices to points in the list of points.
  // The indices start at 1.
  CATHTableOfIntInt* GetSegments ();

  HRESULT RemoveOppositeSegments (const CATPolyBooleanMap* mPointsMap, 
                                  CATListOfInt& oPointIndices0, CATListOfInt& oPointIndices1);

  // Returns the total number of points.
  int GetNbMeshPoints () const;

  /*
   * Returns the list of mesh points for the operand iMesh.
   * @param iMesh
   *   The operand index (0 or 1).
   */
  const CATLISTV(CATPolyMPointTopo)& GetMeshPoints (const int iMesh) const;

  /*
   * Returns the constructed position of the mesh points.
   */
  const CATLISTV(CATMathPoint)& GetConstructedPoints () const;

  /*
   * Returns the mesh point for one of the two operands.
   */
  const CATPolyMPointTopo& GetMeshPoint (const int iMesh, const int iPoint) const;

  /*
   * Sets the mesh point as a vertex point.
   */
  void SetVertex (const int iMesh, const int iIdxPoint, const int iVertex);

  /*
   * Sets the mesh point as a bar point.
   */
  void SetBar (const int iMesh, const int iIdxPoint, const int iVertex0, const int iVertex1);

  /*
   * Sets the mesh point as a triangle point.
   */
  void SetTriangle (const int iMesh, const int iIdxPoint, const int iTriangle);

  /*
   * Adds a new point with the specific topology and geometry.
   * Returns the index of the point added.
   */
  int AddPoint (const CATPolyMPointTopo& iMeshPoint0, const CATPolyMPointTopo& iMeshPoint1,
                const CATMathPoint& iPoint);

  /*
   * Adds a new point (no specific type) to split a segment.
   * The point must also be added to the mesh point map.
   * Returns the index of the point added.
   */
  int AddPoint ();

  /*
   * Adds a new vertex point.
   * The point must also be added to the mesh point map.
   * Returns the index of the point added.
   */
  int AddVertexPoint (const int iMesh, const int iVertex);

  /*
   * Adds a new bar point.
   * The point must also be added to the mesh point map.
   * Returns the index of the point added.
   */
  int AddBarPoint (const int iMesh, const int iBarVertex0, const int iBarVertex1);

  /*
   * Adds a new triangle point.
   * The point must also be added to the mesh point map.
   * Returns the index of the point added.
   */
  int AddTrianglePoint (const int iMesh, const int iTriangle);

  /*
   * Returns the mesh.
   * @param iMesh
   *   The mesh index: 0 for the first mesh and 1 for the second mesh.
   * @return
   *   The mesh.  The method does not AddRef () to the returned object.
   */
  const CATIPolyMesh* GetMesh (const int iMesh) const;

  // For debugging purposes.
  void Print (CATCGMOutput & stream) const;
  void PrintMeshPoints (CATCGMOutput & stream) const;
  void PrintSegments (CATCGMOutput& stream) const;

protected :

  const CATIPolyMesh* _Mesh[2];

  const CATPolyBooleanSegments1* _IntersectionSegments;

  CATLISTV(CATPolyMPointTopo) _MeshPoints0;
  CATLISTV(CATPolyMPointTopo) _MeshPoints1;
  CATLISTV(CATMathPoint) _Points;

  CATHTableOfIntInt* _ConstructedSegments;

  friend class CATPolyBooleanSegments2Iterator;
};


class ExportedByCATPolyBooleanOperators CATPolyBooleanSegments2Iterator
{

public:

  CATPolyBooleanSegments2Iterator (const CATPolyBooleanSegments2& iSegments);

  ~CATPolyBooleanSegments2Iterator ();

  // Resets the iterator to the beginning.
  void Beginning ();

  // Increments the iterator and returns an intersection segment.
  // Returns TRUE if a valid segment is returned and FALSE otherwise.
  CATBoolean GetNextSegment (int& oIdxPoint0, int& oIdxPoint1);

protected:

  CATHTableOfIntIntIterator* _Iterator;

};

#endif

