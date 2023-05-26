// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshAlphaShapeFilter.h
//
//===================================================================
//
// Usage notes: Filters out triangles in the mesh which do not belong
// to the alpha shapes of the vertices of the mesh. The result may be
// not manifold.
// The Alpha value corresponds to the diameter of a sphere which must
// not "penetrate" inside any triangle (on the border) of the result
// mesh.
//
// Two modes are proposed: filtering from the border only or filtering
// everything.
// When filtering everything, every triangle which can contain the
// sphere of diameter alpha is removed from the resulting mesh.
// When filtering from the border, every triangle on one border of the
// mesh (which has at least one free bar) which allows the sphere of
// diameter alpha to enter inside it from one of its free bars is
// removed from the resulting mesh.
//
//===================================================================
//
// November 2019 Creation: XXC
//===================================================================
#ifndef CATPolyMeshAlphaShapeFilter_h
#define CATPolyMeshAlphaShapeFilter_h

#define __IBMCPP_TR1__ 1

#include "CATPolyRegularizeOperators.h"
#include <vector>
#include <functional>
#include "CATErrorDef.h"
#include "CATMathInline.h"

#include "CATPolyTriangleGraph.h"
class CATMathPoint;
class CATIPolyMesh;
class CATMapOfIntToInt;

class ExportedByCATPolyRegularizeOperators CATPolyMeshAlphaShapeFilter
{
public:

  // Prototype class for the Run method with a user defined
  // CATPolyTriangleGraph, to get positions of points considering its
  // index in the graph.
  class PositionGetter {
  public:
    PositionGetter() {}
    virtual ~PositionGetter() {}
    virtual CATMathPoint operator()(int i) const = 0;
  };

  struct TriangleData
  {
  public:
    size_t i; // triangle index in the mesh
    int sm; // longest side
    double cc; // Circumscribed circle diameter
    double l1; // length of bar 0-1
    double l2; // length of bar 1-2
    double l3; // length of bar 2-0

    INLINE TriangleData();
    INLINE TriangleData(size_t ii, int ism, double icc, double il1, double il2, double il3);
  };

  class CustomFilter {
  public:
    CustomFilter() : _Graph(nullptr), _Position(nullptr) {}
    virtual ~CustomFilter() {
      _Graph = nullptr;
      _Position = nullptr;
    }

    /* Called by the CATPolyMeshAlphaShapeFilter operator, do not care
     * about it in custom implementations, just use the corresponding
     * attribute.
     */
    void SetGraph(const CATPolyTriangleGraph & iTriangleGraph) { _Graph = &iTriangleGraph; }
    /* Called by the CATPolyMeshAlphaShapeFilter operator, do not care
     * about it in custom implementations, just use the corresponding
     * attribute.
     */
    void SetPositionGetter(const PositionGetter & iPositions) { _Position = &iPositions; }

    virtual bool operator()(const TriangleData & iTriangle) const = 0;

  protected:
    const CATPolyTriangleGraph * _Graph;
    const PositionGetter * _Position;
  };

public:

  CATPolyMeshAlphaShapeFilter ();
  ~CATPolyMeshAlphaShapeFilter ();

  /**
   * Turns on or off the option to filter only triangles on the border
   * of the shape and keep big triangles filling holes. (Default is
   * on.)
   * When filtering everything (false), every triangle which can
   * contain the sphere of diameter alpha is removed from the
   * resulting mesh.
   * When filtering from the border (true), every triangle which
   * allows the sphere of diameter alpha to enter inside it from one
   * of its free bars (the border side of the triangle) is removed
   * from the resulting mesh.
   */
  inline void SetOnlyFilterBorders (const bool iBorder);

  /**
   * Set an additive filter different than the alpha-value of triangle.
   */
  inline void SetFilter (CustomFilter & iFilter);

  /**
   * Set the mesh to filter. Several Run, for several alpha values, can
   * be called on this mesh. One mesh is generated each time.
   */
  HRESULT SetMesh (CATIPolyMesh & iInputMesh);

public:

  /**
   * Calls the alpha-shapes on the mesh which has been previously set
   * (see @SetMesh) for a specified alpha value.
   *@param alpha: the alpha value, it corresponds to the diameter of
   *the sphere used to filter triangles.
   *@param oOutputMesh: resulting filtered mesh. It is defined as a
   *submesh of the original mesh. Must be released after use.
   */
  HRESULT Run (double alpha, CATIPolyMesh *& oOutputMesh);

  /**
   * Calls the alpha-shapes on a CATIPolymesh.
   *@param iInputMesh: the input mesh which will be filtered. This mesh is not modified.
   *@param alpha: the alpha value, it corresponds to the diameter of the sphere used to filter triangles.
   *@param oOutputMesh: resulting filtered mesh. It is defined as a submesh of the original mesh. Must be released after use.
   */
  HRESULT Run (CATIPolyMesh & iInputMesh, double alpha, CATIPolyMesh *& oOutputMesh);

private:

  void Run (CATPolyTriangleGraph & iTriangles, PositionGetter & GetPosition, double alpha);

  void Flush();

  TriangleData ComputeCCRadius(CATPolyTriangleGraph & iTriangles, size_t i, double alpha, PositionGetter & GetPosition) const;
  bool CanPenetrate(const TriangleData & iTriangle, const CATPolyTriangleGraph & iTriangles, double alpha);
  void PropagateAlphaFiltering(TriangleData & iTriangle, CATPolyTriangleGraph & ioTriangles, double alpha);

private:

  bool _FilterBorder;
  std::vector<TriangleData> _OrderedTriangles;
  CATIPolyMesh * _Mesh;
  CATPolyTriangleGraph * _Graph;
  CATMapOfIntToInt * _Map;
  CustomFilter * _Filter;
};

CATPolyMeshAlphaShapeFilter::TriangleData::TriangleData():
  i(0), sm(0), cc(0.0), l1(0.0), l2(0.0), l3(0.0) {}
CATPolyMeshAlphaShapeFilter::TriangleData::TriangleData(size_t ii, int ism, double icc, double il1, double il2, double il3):
  i(ii), sm(ism), cc(icc), l1(il1), l2(il2), l3(il3) {}

inline void CATPolyMeshAlphaShapeFilter::SetOnlyFilterBorders (bool iBorder)
{
  _FilterBorder = iBorder;
}

inline void CATPolyMeshAlphaShapeFilter::SetFilter (CATPolyMeshAlphaShapeFilter::CustomFilter & iFilter)
{
  _Filter = &iFilter;
}

#endif // define CATPolyMeshAlphaShapeFilter_h
