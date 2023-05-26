// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshBisector.h
//
//===================================================================
// April 2014  Creation NDO
//===================================================================
#ifndef CATPolyMeshBisector_h
#define CATPolyMeshBisector_h

#include "CATPolyModOperators.h"
#include "CATErrorDefs.h"
#include "CATMathPoint.h"
#include "CATErrorDef.h"

class CATIPolyMesh;
class CATIPolySurfaceObserver;
class CATIPolyMeshTriangleIterator;
class CATIPolySurfaceVertexPositionLayer;
class CATIPolySurfaceVertexPositionConstLayer;
class CATIPolySurfaceVertexFacetNeighborhood;
class CATPolySurfaceVertexVertexFacetIterator;


/**
* Bisection operator.  It implements an algorithm to refine the triangles by bisection
* of their longest side.
* See:
* Rivara, M.: Local Modification of Meshes for Adaptive and/or Multigrid
* Finite-element Methods. Journal of Computational and Applied Mathematics,
* 36, pp. 79-89, 1991.
*/
class ExportedByCATPolyModOperators CATPolyMeshBisector 
{

public:

  /**
   * Interface class for getting the neighbor triangles adjacent to a bar.
   */
  class NeighborIterator
  {
  public:

    virtual NeighborIterator& Begin (CATIPolyMesh& mesh, CATIPolySurfaceVertexPositionLayer& posLayer, const CATIPolySurfaceVertexFacetNeighborhood& neighborhood, 
                                     const int v0, const int v1) = 0;

    virtual CATBoolean End () const = 0;

    virtual NeighborIterator& operator ++ () = 0;

  public:

    virtual const CATIPolyMesh* GetConstMesh () const = 0;
    virtual CATIPolyMesh* GetMesh () const = 0;
    virtual const CATIPolySurfaceVertexPositionConstLayer* GetPositionConstLayer () const = 0;
    virtual CATIPolySurfaceVertexPositionLayer* GetPositionLayer () const = 0;
    virtual const CATIPolySurfaceVertexFacetNeighborhood* GetNeighborhood () const = 0;
    virtual int GetBarVertex0 () const = 0;  // Returns v0 or its equivalent bar vertex.
    virtual int GetBarVertex1 () const = 0;  // Returns v1 or its equivalent bar vertex.

    virtual int GetTriangle () const = 0;

  };

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
     * @param iSqrLength
     *   The square of the length of the bar to test.
     */
    virtual CATBoolean EligibleBar (const CATIPolyMesh& mesh, const int v0, const int v1, const double iSqrLength) = 0;

  };

  /**
   * Returns an instance of a filter that prevents bars below the length limit from being split.  
   * A bar is eligible for a split if its length is strictly greater than the specified minimum length.  
   * The returned instance of the filter must be deleted.
   */
  static BarFilter* NewBarLengthFilter (const double iMinimumLength);

public:

  /**
   * Interface class for overriding the default computation of the coordinates 
   * of a new vertex for a bar split.
   */
  class SplitVertexCalculator
  {
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
    virtual HRESULT CalculateMidPoint (const CATIPolySurfaceVertexPositionConstLayer& iPosLayer, const int v0, const int v1, CATMathPoint& ioPoint) = 0;

  };

public:

  // NEW
  class BarSplitter
  {
  public:

    // Virtual destructor.
    virtual ~BarSplitter () {}

  public:

    /**
     * Method called to split the bar of a mesh.
     * It calls internally the method CATIPolyMesh::SplitBar ().
     */
    virtual HRESULT Split (const int v0, const int v1) = 0;

  };

  /**
   * Returns an instance of a bar splitter to perform the split of the bars and the update of the mesh layers.  
   * The returned instance of the splitter must be deleted.
   */
  BarSplitter* NewSplitter (CATIPolyMesh& mesh);

public:

  /**
   * Constructs an instance of a local bisection refiner for a given mesh.
   * Any of the optional arguments can be null.
   * @param iNeighborIterator
   *   An optional iterator to retrieve the adjacent triangles to a bar.
   * @param iFilter
   *   An optional filter to check the eligibility of bars for splits.
   *   If no filter is set, then all bars from the mesh are eligible for splits.
   * @param iCoordCalculator
   *   An optional argument for the computation of the coordinates of the vertex splitting a bar.
   */
  CATPolyMeshBisector (NeighborIterator* iNeighborIterator = 0, BarFilter* iFilter = 0, SplitVertexCalculator* iCoordCalculator = 0);

  /**
   * Destructor.
   */
  ~CATPolyMeshBisector (void);

public:

  /**
  * Refines a triangle from the mesh by bisection.
  * @param iMesh
  *   The mesh to which the triangle belongs.
  * @param t
  *   The triangle from the mesh.
  * @return
  *   <tt>S_OK</tt> if triangles were refined.
  */
  HRESULT Run (CATIPolyMesh& iMesh, const int t);

  HRESULT Run (CATIPolyMesh& iMesh, CATIPolySurfaceVertexPositionLayer& iPosLayer, 
               const CATIPolySurfaceVertexFacetNeighborhood& iNeighborhood, const int t);

private:

  class RefinerBisectionStack;

  HRESULT Refine (RefinerBisectionStack& iStack);

private:

  NeighborIterator* _NeighborIterator;
  BarFilter* _BarFilter;
  SplitVertexCalculator* _CoordCalculator;

};

#endif
