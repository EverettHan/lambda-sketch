#ifndef CATPolyFillNonPlanarHole_h
#define CATPolyFillNonPlanarHole_h


#include "CATProgressCallback.h"
#include "CATPolyFillHolesOperators.h"
#include "CATCollec.h"
#include "CATSysErrorDef.h"
#include <cstddef>
#include <array>
#include <vector>

class CATProgressCallback;
class CATMathPoint;
class CATMathVector;
class CATIPolyMesh;

class ExportedByCATPolyFillHolesOperators CATPolyFillNonPlanarHole
{
public:
  enum KindMeasure
  {
    Area = 0,
    AngleArea = 1,
  };

  ~CATPolyFillNonPlanarHole();
  CATPolyFillNonPlanarHole();

  /**
   * Set the kind of measure (Area or AngleArea) to be used in the cost
   * function that optimizes the hole triangulation.
   * @param kindMeasure specifies the kind of measure:
   *        Area Measure
   *        AngleArea Measure
   */
  void SetMeasure(KindMeasure kindMeasure);

  /**
   * Set the data required to compute the hole triangulation
   * @param nbPoints is the dimension of the vector of coordinates
   *        (vertices) and the vector of normals to the triangles
   *        adjacent to a boundary bar.
   * @param iaPoints is a pointer to the vector of coordinates
   *        (vertices) and the vector of normals to the triangles
   *        adjacent to a boundary bar.
   * @param (OPTIONAL) iaNormals is a pointer to the vector of normals
   *        to the triangles adjacent to a boundary bar.
   *        This argument is only needed for the AngleArea measure.
   */
  HRESULT SetBoundaryData(int nbPoints,
                                  CATMathPoint const *iaPoints,
                                  CATMathVector const *iaNormals = NULL);

  /**
   * Set pointer for progress callback
   * @param progressCallback is the pointer for progress callback.
   */
  HRESULT SetProgressCallback(CATProgressCallback *progressCallback);

  /**
   * Compute the hole triangulation
   */
  HRESULT Run();

  /**
   * Add the triangulation to the mesh.
   * @param mesh is the mesh container. The new triangulation
   *        will be added to this container.
   * @param (OPTIONAL) idx_vertices is the list of indices mapping the position
   *        of points in the boundary vector to indices in the output mesh.
   *        NOTICE:
   *           - A NULL container means the vertices have to be added to the
   *             mesh. The list of indices will be generated as the nodes
   *             are added to the mesh. In other words, when the container is
   *             NULL, both triangulation and vertices are added to the mesh.
   *           - If the container is not NULL, its size must be equal to the
   *             size of the container of vertices.
   *           - If the container is not NULL, only the triangulation is added
   *             to the mesh.
   */
  HRESULT GetResult(CATIPolyMesh &mesh,
                    CATListOfInt *idx_vertices = NULL);

private:
  /**
   * Kind of measure:
   *    0: Area
   *    1: AngleArea (default)
   */
  KindMeasure _kindMeasure;

  /**
   * Coordinates of the boundary points.
   * These coordinates describe a 3D polygonal curve.
   */
  std::vector<CATMathPoint> _coord_bd;

  /**
   * Normal to the element adjacent to a boundary edge.
   */
  std::vector<CATMathVector> _normal_adj_bd;

  /**
   * Container to store the hole triangulation (connectivity).
   */
  std::vector<std::array<int, 3>> _connectivity;

  /**
   * Pointer for progress callback.
   */
  CATProgressCallback *_progressCallback;
};

#endif

// end of file
