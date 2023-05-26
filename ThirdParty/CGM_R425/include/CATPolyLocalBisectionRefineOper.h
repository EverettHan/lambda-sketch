// COPYRIGHT Dassault Systemes 2003, all rights reserved
//===================================================================
//
// CATPolyLocalBisectionRefineOper.h
//
//===================================================================
// Dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolyLocalBisectionRefineOper_h
#define CATPolyLocalBisectionRefineOper_h

#include "CATPolyModOperators.h"
#include "CATPolyModOper.h"
#include "CATMathPoint.h"
#include "CATListOfInt.h"

class CATIPolySurface;
class CATIPolySurfaceObserver;
class CATIPolyMeshTriangleIterator;
class CATIPolySurfaceVertexPositionLayer;
class CATIPolySurfaceVertexFacetNeighborhood;
class CATPolySurfaceVertexVertexFacetIterator;

class CATPolyRefineMap;
class CATSetOfInt;
class CATSoftwareConfiguration;


/**
* This class implements the refinement algorithm from:
*
* Rivara, M.: Local Modification of Meshes for Adaptive and/or Multigrid
* Finite-element Methods. Journal of Computational and Applied Mathematics,
* 36, pp. 79-89, 1991.
*
* @see CATPolyMeshBisector
*/
class ExportedByCATPolyModOperators CATPolyLocalBisectionRefineOper : public CATPolyModOper
{

public:

  /**
   * Interface class for checking the eligibility of bars to bisection.
   * If the bar is not eligible, it will not be split.
   */
  class BarFilter
  {
  public:

    virtual ~BarFilter () {}

  public:

    /**
     * Method to check if a bar is eligible for a split or not.
     * A bar that is not eligible (<tt>FALSE</tt>) will not be split.
     */
    virtual CATBoolean EligibleBar (const int v0, const int v1) = 0;

  };

  /**
   * Returns an instance of a filter that prevents bars below the length limit
   * from being split.  A bar is eligible for a split if its length is strictly greater than the
   * specified minimum length.  
   *
   * The returned instance of the filter must be deleted.
   */
  static BarFilter* NewBarLengthFilter (const CATIPolySurface& iPolySurface, const double iMinimumLength);

public:

  /**
   * Interface class for overriding the default computation of the coordinates 
   * of a new vertex for a bar split.
   */
  class SplitVertexCalculator
  {
  public:

    virtual ~SplitVertexCalculator () {}

  public:

    /**
     * Method to implement to calculate the coordinates of a new vertex.
     * @param v0
     *   The start vertex of the bar.
     * @param v1
     *   The end vertex of the bar.
     * @param ioPoint
     *   The point whose coordinates must be set by the method.
     * @return
     *   <tt>S_OK</tt> if the coordinates were set.
     */
    virtual HRESULT CalculateMidPoint (const int v0, const int v1, CATMathPoint& ioPoint) = 0;

  };

public:

  /**
   * Default constructor.
   * A null configuration is equivalent to an open configuration.
   */
  CATPolyLocalBisectionRefineOper (CATSoftwareConfiguration* ipConfig = 0);

  /**
   * Construct an instance of a local bisection refiner for a given mesh.
   * @param iMesh
   *   The mesh to refine.
   * @param iFilter
   *   An optional filter to check the eligibility of bars for splits.
   *   If no filter is set, then all bars from the mesh are eligible for splits.
   */
  CATPolyLocalBisectionRefineOper (CATIPolyMesh& iMesh, BarFilter* iFilter = 0, SplitVertexCalculator* iCoordCalculator = 0);

  /**
   * Destructor.
   */
  ~CATPolyLocalBisectionRefineOper (void);

  /**
   * Refines a CATIPolyMesh.
   * @return
   *   Returns <tt>S_OK</tt> when triangles were refined and <tt>S_FALSE</tt> if no triangles were refined.
   */
  HRESULT Run (void);

public:

  /**
  * Refines a subset of the triangles from the mesh.
  * @param triangles
  *   The list of triangles to refine.
  * @return
  *   <tt>S_OK</tt> if triangles were refined.
  */
  HRESULT RunOnSelectedTriangles (const CATListOfInt& triangles);

  /**
  * Refines a subset of the triangles in the polygon and returns
  * information on the subdivided triangles.
  * @param triangles
  *   The indices of the triangles to refine.
  * @param triangleMap
  *   A map that contains the triangles that were refined along with the children
  *   associated with each triangle.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  HRESULT RunOnSelectedTriangles (const CATListOfInt& triangles, CATPolyRefineMap* triangleMap);

  /**
  * Refines a subset of the triangles in the polygon.
  * @param triangles
  *   The indices of the triangles to refine.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  HRESULT RunOnSelectedTriangles (CATIPolyMeshTriangleIterator* iTriangles);

  /**
  * Refines a subset of the triangles in the polygon and returns
  * information on the subdivided triangles.
  * @param triangles
  *   The indices of the triangles to refine.
  * @param triangleMap
  *   A map that contains the triangles that were refined along with the children
  *   associated with each triangle.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  HRESULT RunOnSelectedTriangles (CATIPolyMeshTriangleIterator* iTriangles, CATPolyRefineMap* triangleMap);

public:

  virtual CATMathPoint CalculateMidPoint (const int vertex0, const int vertex1) const;

private :

  CATBoolean EligibleBar (const int vertex0, const int vertex1) const;

  void SetVisited (const int triangle);

  CATBoolean IsVisited (const int triangle) const;

private:

  // Obsolete.
  CATBoolean RefineObsolete (const int triangle);

  // Obsolete method (old configuration).
  CATBoolean  Bisect (const int vertex0, const int vertex1);
  // Obsolete method (old configuration).
  CATBoolean  Bisect (const int triangle, const int barVertex0, const int barVertex1, const int midVertex);

private:

  BarFilter* _BarFilter;
  SplitVertexCalculator* _CoordCalculator;

  CATPolyRefineMap* _TriangleMap;
  CATSetOfInt* _TriangleSet;

  CATIPolySurfaceVertexPositionLayer* _VertexCoords;
  CATIPolySurfaceVertexFacetNeighborhood* _Neighborhood;
  CATPolySurfaceVertexVertexFacetIterator* _NeighborIterator;

  CATSoftwareConfiguration* _Configuration;

};

#endif
