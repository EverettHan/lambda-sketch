#include "CATIAV5Level.h"
#if defined(CATIAR420) && !defined(CATPolyBodyRemoveIntersectingSlivers_h)
#define CATPolyBodyRemoveIntersectingSlivers_h

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
// CATPolyBodyRemoveIntersectingSlivers.h
//===================================================================
// Fix up intersections in mesh with local operations (Bar flips and collapses)
// as long as they don't deform the mesh much or introduce bad topology
//===================================================================
// Oct 2017 Creation: MMN12.
//===================================================================
#include "CATPolyBodyCheckedEditor.h"
#include "CATPolyBodyGeoCheckerObserver.h"
#include "CATPolyBodyIntersectionAnomalyList.h"
#include "CATSysErrorDef.h"
#include "PolyBodyCheckedEditor.h"
#include <memory>
class CATIPolyMesh;
class CATPolyBody;
class CATProgressCallback;
class CATPolyBodyCheckedEditor;
class CATPolyFace;
class CATPolyBodyIntersectionAnomalyList;
/**
 * This operator removes illegal intersections in a mesh through a series of bar
 * flips and bar collapses which deform the mesh less than a set tolerance.
 **/
class ExportedByPolyBodyCheckedEditor CATPolyBodyRemoveIntersectingSlivers
{
public:
  CATPolyBodyRemoveIntersectingSlivers(CATPolyBodyCheckedEditor &iEditor);

  CATPolyBodyRemoveIntersectingSlivers(
    CATPolyBodyCheckedEditor &iEditor,
    CATPolyBodyIntersectionAnomalyList const &anoms);

  /**
   * This method returns S_OK if the body was healed, S_FALSE if
   * the body was improved but not completely healed.  E_FAIL is
   * reserved for cases where the operator completely failed.
   **/
  HRESULT Run();

  /**
   * Allows clients to set a progress callback for the operator.
   **/
  HRESULT SetProgressCallback(CATProgressCallback *iProgressCallback);

  /**
   * Set the maximum deformation tolerance for a single bar flip or bar
   *collapse. If no tolerance is set, a default value will be chosen which is
   *0.2% of the box diagonal.
   *
   * The operator will not do moves that exceed this deformation tolerance even
   * if that means not fixing all the problems.
   **/
  HRESULT SetTolerance(double iDeformationTolerance);

  /**
   * Provide notification if this operator did a local modification which
   * could change the topology (up to homeomorphism).
   *
   * If this returns false, the user may assume the macrotopology of the
   *CATPolyBody needs no further adjustment.  If it returns true, the
   *macrotopology may need to be fixed up.
   **/
  bool TopologyChanged() const;

  /**
   * After running this operator, if the result was S_OK you
   * may call the GetResultBody method to get a CATPolyBody
   * constructed using CATPolyCompactMeshConst meshes which is
   * suitable for wrapping in a CATBody (PH).  This method
   * returns E_FAIL and oBody will be NULL if the earlier
   * healing step failed.
   **/
  HRESULT GetResult(CATPolyBody *&oBody, bool iReturnEvenOnTopologyChange=false);

  ~CATPolyBodyRemoveIntersectingSlivers();
  class Impl;

  /**
   * For helping in situations where clients want to run the checker first then
   * use remove intersecting slivers, the following observer can be
   * used with calls to the geochecker.
   **/
  class ExportedByPolyBodyCheckedEditor GeoCheckObserver
    : public CATPolyBodyGeoCheckerObserver
  {
  public:
    GeoCheckObserver();

    CATPolyBodyIntersectionAnomalyList const &GetAnomalyList();
    void AddDegenerateTriangle(CATPolyFace *face,
                               const CATIPolyMesh *pmesh,
                               int degeneratetriangle);
    void AddIntersection(CATPolyFace *cell1,
                         const CATIPolyMesh *pmesh1,
                         int indext1,
                         CATPolyFace *cell2,
                         const CATIPolyMesh *pmesh2,
                         int indext2,
                         const CATLISTV(CATMathPoint) & intersection);
    void
    AddNeedle(CATPolyFace *face, const CATIPolyMesh *pmesh, int needletriangle);
    void
    AddCap(CATPolyFace *face, const CATIPolyMesh *pmesh, int needletriangle);

    void AddClearance(CATPolyFace *cell1,
                      const CATIPolyMesh *pmesh1,
                      int indext1,
                      const CATMathPoint &barycenter1,
                      CATPolyFace *cell2,
                      const CATIPolyMesh *pmesh2,
                      int indext2,
                      const CATMathPoint &barycenter2,
                      double distance);

    void AddIntersection(CATPolyEdge *cell1,
                         const CATIPolyCurve *pcurve1,
                         int indexb1,
                         CATPolyEdge *cell2,
                         const CATIPolyCurve *pcurve2,
                         int indexb2,
                         const CATLISTV(CATMathPoint) & intersection);

    void AddClearance(CATPolyEdge *cell1,
                      const CATIPolyCurve *pcurve1,
                      int indexb1,
                      const CATMathPoint2D &barycenter1,
                      CATPolyEdge *cell2,
                      const CATIPolyCurve *pcurve2,
                      int indexb2,
                      const CATMathPoint2D &barycenter2,
                      double distance);

    void AddIntersection(CATPolyEdge *cell1,
                         const CATIPolyCurve *pcurve1,
                         int indexb1,
                         CATPolyFace *cell2,
                         const CATIPolyMesh *pmesh2,
                         int indext2,
                         const CATLISTV(CATMathPoint) & intersection);

    void AddClearance(CATPolyEdge *cell1,
                      const CATIPolyCurve *pcurve1,
                      int indexb1,
                      const CATMathPoint2D &barycenter1,
                      CATPolyFace *cell2,
                      const CATIPolyMesh *pmesh2,
                      int indext2,
                      const CATMathPoint &barycenter2,
                      double distance);

    void AddFaceWithNonMatchingVertexNormals(CATPolyFace *face,
                                             const CATIPolyMesh *pmesh);

  private:
    CATPolyBodyIntersectionAnomalyList _anomalies;
  };

private:
  Impl *_impl;
};
#endif
