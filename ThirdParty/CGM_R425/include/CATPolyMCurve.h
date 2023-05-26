// COPYRIGHT Dassault Systemes 2003, all rights reserved.
//===================================================================
//
// CATPolyMCurve.h
//
//===================================================================
//
// Usage notes: DON'T USE, DEPRECATED !!!!! USE CATIPOLYMESHCURVE INSTEAD
//
//===================================================================
//
//  sep 2003 Creation: dhp
//===================================================================
#ifndef CATPolyMCurve_h
#define CATPolyMCurve_h

#include "CATPolyMCrv.h"
#include "CATBaseUnknown.h"
#include "CATListPV.h"

#include "CATLISTV_CATPolyMPoint.h"

class CATPolyMPoint;
class CATIPolyMesh;
class CATMathPoint;
class CATMathSetOfPoints;
class CATMathSetOfPointsND;
class CATMathVector;
class CATMathBox;

class CATCGMOutput;

/**
* Class representing an ordered set of points where each point lies
* on a mesh.
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
* DEPRECATED -> Use CATIPOLYMESHCURVE
*/
class ExportedByCATPolyMCrv CATPolyMCurve : public CATBaseUnknown
{

  CATDeclareClass;

public:

  /**
  * Constructor.
  * @param iCldPolygon
  *   The polymesh to which the curve is associated.
  */
  CATPolyMCurve (CATIPolyMesh * polyMesh);

  /**
  * Copy constructor.
  * @param rhs
  *   The object to copy.
  */
  CATPolyMCurve(const CATPolyMCurve & rhs);

  /**
  * Destructor.
  */
  ~CATPolyMCurve();

  /**
  * Removes all points from the mesh curve.
  */
  void RemoveAllPoints ( void );

  /**
  * Returns the mesh.
  * @return
  *   The mesh.
  * <b> Lifecycle rule deviation: </b> The method does not call AddRef () on
  * the returned pointer.
  */
  CATIPolyMesh * GetPolyMesh ( void ) const;

  /**
  * Returns the number of points.
  * @return
  *   The number of points.
  */
  int GetNumPoints( void ) const;

  /**
  * Assignment operator.
  * @param rhs
  *   The object to copy.
  * @return
  *   The object resulting from the assignment.
  */
  CATPolyMCurve & operator = (const CATPolyMCurve & rhs);

  int operator == (const CATPolyMCurve & rhs) const;

  int operator != (const CATPolyMCurve & rhs) const;

  /**
  * Returns the mesh point at the specified index.
  * @param iIndex
  *   The index of the desired mesh point.
  *   <b>Legal values</b>: 1 to the number of mesh points, inclusive.
  * @param oPoint
  *   The desired mesh point.
  * @return
  *   TRUE if iIndex is in the proper range and FALSE otherwise.
  */
  CATBoolean GetMeshPoint( const int iIndex, CATPolyMPoint& oPoint) const;

  /**
  * Returns the position of the mesh point at the specified index.
  * @param index
  *   The index of the desired mesh point position.
  *   <b>Legal values</b>: 1 to the number of mesh points, inclusive.
  * @param point
  *   The position of the desired mesh point.
  * @return
  *   TRUE if the index is in the proper range and FALSE otherwise.
  */
  CATBoolean GetPoint (const int index,
    CATMathPoint & point) const;

    /**
    * Returns all points in the mesh curve as a set of points.
    * @param points
    *   The set of points.
    * @return
    *   TRUE if there is at least one point in the mesh curve and FALSE otherwise.
  */
  CATBoolean GetPoints (CATMathSetOfPoints & points) const;

  // CATBoolean GetPoints (CATMathSetOfPointsND & points) const;

  /**
  * Returns the bounding box of the mesh curve.
  * @param box
  *   The bounding box.
  * @return
  *   TRUE if there is at least one point in the mesh curve and FALSE otherwise.
  */
  CATBoolean GetBox (CATMathBox & box) const;

  /**
  * Returns the mesh point before the specified index.
  * @param iIndex
  *   The index of the mesh point after the desired point.
  *   <b>Legal values</b>: 1 to the number of mesh points, inclusive.
  * @param oPoint
  *   The desired mesh point.
  * @return
  *   TRUE if there is a mesh point before the index and FALSE otherwise.
  */
  CATBoolean GetPreviousPoint( int iIndex, CATPolyMPoint& oPoint) const;

  /**
  * Returns the mesh point after the specified index.
  * @param iIndex
  *   The index of the mesh point before the desired point.
  *   <b>Legal values</b>: 1 to the number of mesh points, inclusive.
  * @param oPoint
  *   The desired mesh point.
  * @return
  *   TRUE if there is a mesh point after the index and FALSE otherwise.
  */
  CATBoolean GetNextPoint( int iIndex, CATPolyMPoint& oPoint) const;

  /**
  * Returns the start mesh point of the mesh curve.
  * @param oPoint
  *   The start mesh point.
  * @return
  *   TRUE if there is at least one mesh point in the curve and
  *   FALSE otherwise.
  */
  CATBoolean GetStartPoint( CATPolyMPoint& oPoint ) const;

  /**
  * Returns the end mesh point of the mesh curve.
  * @param oPoint
  *   The end mesh point.
  * @return
  *   TRUE if there is at least one mesh point in the curve and
  *   FALSE otherwise.
  */
  CATBoolean GetEndPoint( CATPolyMPoint& oPoint ) const;

  /**
  * Replaces an existing mesh point.
  * @param iIndex
  *   The index of the mesh point to replace.
  *   <b>Legal values</b>: 1 to the number of mesh points, inclusive.
  * @param iPoint
  *   The new mesh point.
  * @return
  *   TRUE if iIndex is in the proper range and FALSE otherwise.
  */
  CATBoolean SetMeshPoint( const int iIndex, const CATPolyMPoint& iPoint);

  /**
  * Appends a mesh point to the mesh curve.
  * @param iPoint
  *   The mesh point to append.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  CATBoolean AppendPoint( const CATPolyMPoint& iPoint );

  /**
  * Prepends a mesh point to the mesh curve.
  * @param iPoint
  *   The mesh point to prepend.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  CATBoolean PrependPoint( const CATPolyMPoint& iPoint );

  /**
  * Inserts a mesh point to the mesh curve.
  * <br><b>Note:</b> In the current implementation, this method is not very efficient and should
  * not be used if multiple points must be inserted.
  * @param iIndex
  *   The index of the point where it will be inserted.
  * <br><b>Legal values</b>: <tt>1</tt> for insertion at the beginning to
  * <tt>GetNumPoint() + 1</tt> for insertion at the end.
  * @param iPoint
  *   The mesh point to inserted.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  CATBoolean InsertPoint (const int iIndex,  const CATPolyMPoint& iPoint );

  /**
  * Removes a mesh point from the mesh curve.
  * <br><b>Note:</b> In the current implementation, this method is not very efficient and should
  * not be used if multiple points must be deleted.
  * @param iIndex
  *   The index of the point to remove.
  * <br><b>Legal values</b>: <tt>1</tt> to <tt>GetNumPoint ()</tt>.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  CATBoolean RemovePoint (const int iIndex);

  /**
  * Searches the mesh curve for the specified mesh point.
  * @param point
  *   The mesh point to find.
  * @return
  *   TRUE if the mesh point is contained in the curve; FALSE otherwise.
  */
  int FindPoint (const CATPolyMPoint & point) const;

  /**
  * Appends a mesh curve to the curve. This method does not check and change the orientation of the curve
  * to append.  The curve to append does not need to have the same starting point as the end point of the
  * other curve.
  * @param iCurve
  *   The mesh curve to append.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  CATBoolean Append ( const CATPolyMCurve& iCurve);

  CATBoolean Merge( const CATPolyMCurve& rhs );

  /**
  * Tests if the mesh curve is closed.
  * @return
  *   TRUE if the start and end mesh points are identical and there
  *   is more than one mesh point in the curve. Returns FALSE otherwise.
  */
  CATBoolean IsClosedLoop( void ) const;

  /**
  * Determines whether the curve is regular or not.  A regular mesh curve is a curve whose line
  * segments intersect triangle edges only at the extremities of the line segments (mesh curve points).
  * This means that a regular curve lies completely on the polymesh and that each edge crossing is
  * happening at a mesh curve point.  Edge crossing may be happening at a vertex.
  * @param oTrianglePath
  *   An optional list for the indices of the triangles where the line segments of the curve lie.  In
  * case of an edge, the index is one of the triangles (two at most) to which the edge belongs.
  * The size of the list is equal to the number of points of the curve.  The ith entry of the list
  * corresponds to the triangle index for the segmemt between the ith and (i+1)th points.  The last entry
  * is equal to 0.  When the curve is non-regular, then the entries are 0 for line segments not lying
  * completely on a triangle.
  * @return
  *   TRUE is the mesh curve is regular and FALSE otherwise.
  */
  CATBoolean IsRegular (CATListOfInt * oTrianglePath = 0) const;

  /**
  * Tests whether the mesh curve is a vertex path.  The curve is a vertex path if it is regular and
  * composed only of vertex points.
  * @return
  *   TRUE is the mesh curve is a vertex path and FALSE otherwise.
  */
  CATBoolean IsAVertexPath () const;

  /**
  * Returns the length of the mesh curve.
  * @return
  *   The length of the mesh curve.
  */
  double GetLength (void) const;

  /**
  * Returns the normal to the polymesh at the mesh point whose index is <tt> iIndex </tt>.
  * @param iIndex
  *   The index of the mesh point.
  * @param oNormal
  *   A vector that will be set to the normal to the polymesh.
  * @return
  *   TRUE if the normal is calculated successfully and FALSE otherwise.
  */
  CATBoolean GetMeshPointNormal (const int iIndex, CATMathVector& oNormal) const;

  /**
  * Retrieves the list of vertices from the mesh curve
  * assuming that the mesh curve is a vertex path.
  * @param vertices
  *   The vertices in the mesh curve.
  * @return
  *   TRUE if the mesh curve represents a vertex path and FALSE otherwise.
  */
  CATBoolean GetVertexPath (CATListOfInt & vertices) const;

  /**
  * Removes duplicate consecutive mesh points.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */

  CATBoolean RemoveDuplicates (void);

  /**
  * Tests if meshCurve is completely contained within this
  * mesh curve. The test for containment will be performed
  * only if the number of points in meshCurve is not greater
  * than the number of points in this mesh curve.
  * @param meshCurve
  *   The mesh curve to test for inclusion.
  * @return
  *   TRUE if the mesh curve is completely contained within this
  *   mesh curve and FALSE otherwise.
  */

  CATBoolean Contains (const CATPolyMCurve & meshCurve) const;

  /**
  * Tests if meshCurve overlaps with this mesh curve.
  * @param meshCurve
  *   The mesh curve to test for overlap.
  * @return
  *   TRUE if meshCurve overlaps this mesh curve and FALSE otherwise.
  */

  CATBoolean Overlaps (const CATPolyMCurve & meshCurve) const;

  CATBoolean DoubleOverlaps (const CATPolyMCurve & meshCurve) const;

  /**
  * Tests if meshCurve overlaps with this mesh curve and if there
  * is overlap returns information about the overlap.
  * @param meshCurve
  *   The mesh curve to test for overlap.
  * @param index0
  *   The index of the start of the overlap for this mesh curve.
  * @param index1
  *   The index of the end of the overlap for this mesh curve.
  * @param rhsIndex0
  *   The index of the start of the overlap for meshCurve.
  * @param rhsIndex1
  *   The index of the end of the overlap for meshCurve.
  * @return
  *   TRUE if meshCurve overlaps this mesh curve and FALSE otherwise.
  */
  CATBoolean GetOverlap (const CATPolyMCurve & meshCurve,
    int & index0,
    int & index1,
    int & rhsIndex0,
    int & rhsIndex1) const;

    /**
    * Tests if both ends of meshCurve overlaps with this mesh curve.
    * @param meshCurve
    *   The meshCurve to test for overlap.
    * @param index0
    *   The index of the start of the overlap for this mesh curve.
    * @param index1
    *   The index of the end of the overlap for this mesh curve.
    * @param rhsIndex0
    *   The index of the start of the overlap for meshCurve.
    * @param rhsIndex1
    *   The index of the end of the overlap for meshCurve.
    * @return
    *   TRUE if meshCurve overlaps this mesh curve and FALSE otherwise.
  */
  CATBoolean GetDoubleOverlap (const CATPolyMCurve & meshCurve,
    int & index0,
    int & index1,
    int & rhsIndex0,
    int & rhsIndex1) const;

    /**
    * Reverses the mesh points in the mesh curve.
    * @return
    *   TRUE if the mesh curve has at least one mesh point and FALSE otherwise.
  */
  CATBoolean Reverse (void);

  /**
  * For debugging purposes.  Prints the curve definition in the console window.
  */
  void Print (CATCGMOutput & out) const;

  /**
  * Extract a subset of mesh points from this mesh curve and appends them
  * to the specified mesh curve. All existing points in meshCurve will
  * first be removed. The end index must be greater than or equal to
  * the start index.
  * @param startIndex
  *   The index of the first mesh point.
  * @param endIndex
  *   The index of the last mesh point.
  * @return
  *   TRUE if the indices or OK (start less than end) and FALSE otherwise.
  */
  CATBoolean GetSubMeshCurve (const int startIndex,
    const int endIndex,
    CATPolyMCurve & meshCurve) const;

  /**
  * Inserts mesh points so that no segment in the mesh curve
  * is longer than the specified length.
  */
  CATBoolean SuperSample (const double length);

  CATBoolean PrintForDebug (CATCGMOutput & stream) const;

protected:

  void MergeOverlap (const CATPolyMCurve & rhs,
    const int index0,
    const int index1,
    const int rhsIndex0,
    const int rhsIndex1);

  void MergeDoubleOverlap (const CATPolyMCurve & rhs,
    const int index0,
    const int index1,
    const int rhsIndex0,
    const int rhsIndex1);

  CATIPolyMesh * _polyMesh;
  CATListValCATPolyMPoint _meshPoints;

};

#endif
