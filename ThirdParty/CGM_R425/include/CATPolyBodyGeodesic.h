// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyGeodesic.h
// Implements algorithms found in:
// Efficiently Determining a Locally Exact Shortest Path on Polyhedral
// Surfaces, Shi-Qing Xin and Guo-Jin Wang, in Computer-Aided Design
// 39 (2007), pp 1081-1090
//
//===================================================================
//
// Usage notes: Computes the LESP (Locally Exact Shortest Path) on a
// CATPolyBody surfacic model given two points to join. The points are
// given by two CATPolyCellPoint that defines a point on a poly cell
// (vertex, edge, face of the given CATPolyBody).
// As the CATPolyBody is given in the constructor, many pathes on the
// same CATPolyBody can be computed from the same CATPolyBodyGeodesic
// instance without reinitializing the internal data, which
// can save computation time.
//
//===================================================================
//
// 2015-06-24 Creation: XXC
// 2019-05    XXC: only the eDijkstra initial method is implemented so far.
//===================================================================

#ifndef CATPolyBodyGeodesic_HH
#define CATPolyBodyGeodesic_HH

#include "PolyBodyMeasures.h"
#include "CATErrorDefs.h"
#include "CATListPV.h"

class CATPolyBody;
class CATPolyMeshCurve;
class CATMathPoint;
class CATPolyBodyVertexEdgeGraph;
class GeodesicPath;
class GeodesicPathElement;
class GeodesicPathEdge;
class GeodesicPathVertex;
class CATPolyCellPoint;
class CATTolerance;

class ExportedByPolyBodyMeasures CATPolyBodyGeodesic
{
public:

  /** Initial path methods. The LESP is obtained by shortening
   * iterations on an initial path consisting of a sequence of bars on
   * meshes of the CATPolyBody. The initial path methods can modify
   * the final result as the shortness is "local" to the initial path.
   */
  enum InitialPathMethod {
    eDijkstra = 0, /* Use a Dijkstra algorithm on the length of the bar only. */
    eImprovedFFM /* Not implemented yet */
  };

public:

  /** Create an instance of the geodesic solver to compute localy
   * shortest pathes on the given CATPolyBody.
   *@param iPolyBody: the polyhedral body on which the pathes has to be computed.
   *@param iTolerance: a CATTolerance instance to eventually stitch
   *the path on vertices. Use the modeler precision.
   */
  CATPolyBodyGeodesic(CATPolyBody * iPolyBody, const CATTolerance * iTolerance);
  ~CATPolyBodyGeodesic();

  /** Runs the computation of a Locally Shortest Path between two poly
   * cell points defined on the CATPolyBody given in the constructor.
   *@param iSource: starting point of the path.
   *@param iDestination: ending point of the path.
   *@return S_FALSE if the computation manage to find a path, an error code otherwise.
   */
  HRESULT ComputeGeodesic(const CATPolyCellPoint & iSource, const CATPolyCellPoint & iDestination);

  /** Returns the path computed by the ComputeGeodesic method. Returns
   * NULL if the ComputeGeodesic has not been called or if it failed
   * to compute a path. The returned CATPolyBody must be released by
   * the caller after use.
   *@param A wire CATPolyBody object containing curves lying on the
   *meshes of the original CATPolyBody and vertices linking the
   *curves. Must be released after use.
   */
  CATPolyBody * GetGeodesicCurves();

  /** Allows to switch between different methods to compute an
   * original path on the CATPolyBody following the bars linking the
   * microvertices. According the method, the original path may
   * converge to different locally exact shortest path.
   */
  void UseInitialPathMethod(InitialPathMethod iMethod);

private:

  HRESULT Dijkstra(GeodesicPath & oPath);

  HRESULT ImprovedFFM(GeodesicPath & oPath);

  HRESULT UpdateFaceSequence(GeodesicPath & oPath);

  HRESULT RefineToLESP(GeodesicPath & oPath);

private:
  static int GetOtherVertex(const GeodesicPathEdge * iEdge, GeodesicPathElement * iElem, double & lp, double & rp);
  static void InitLmRm(GeodesicPath & ioPath, const CATMathPoint & iSource, const int iIndex, double & olm, double & orm);

  int RefineLESPEdge(GeodesicPath & ioPath,
                     const double lm, const double rm, const double a, const double b, const int it/*,
                     double & lp, double & rp*/);

  int GetMinAngleInterval(GeodesicPathElement & precEl, GeodesicPathVertex & vertex, GeodesicPathElement & succEl,
                          int & oFirstEdgeIndex, int & oLastEdgeIndex);

  HRESULT BuildPolyBody(GeodesicPath & oPath);
  HRESULT ConvertResult(GeodesicPath & oPath, CATListPV & oCurves);
  HRESULT UpdateCurrentFace(GeodesicPathElement & iPrecElement, GeodesicPathElement & iElement, int & oNewFace, CATListPV & oMeshCurves);
  HRESULT AddPoint(const int iIdFace, GeodesicPathElement & iElement);
  int GetCommonFace(GeodesicPathElement & iPrecElement, GeodesicPathElement & iElement);

  HRESULT ReplaceEdgesExtremitiesByVertices(GeodesicPath & ioPath);
  HRESULT RemoveRedondantVertices(GeodesicPath & ioPath);
  HRESULT RemoveAdjacentEdgesToVertices(GeodesicPath & ioPath);

private:
  InitialPathMethod m_InitialPathMethod;
  CATPolyBodyVertexEdgeGraph * p_MeshGraph;
  CATPolyBody * p_PolyBody, * _GeodesicResult;
  CATPolyMeshCurve * p_MeshCurve;
  const CATTolerance * _Tol;
};

#endif // CATPolyBodyGeodesic_HH
