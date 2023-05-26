//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014
//=============================================================================
//
// CATPolyBodyGeoCheckerObserver
//
// Check geometric consistency of a macro polyhedral body
//
//=============================================================================
// 2014-07-08 JXO: New.
// 2016-07-06 JXO: Edges & Normals
//=============================================================================
#ifndef CATPolyBodyGeoCheckerObserver_H
#define CATPolyBodyGeoCheckerObserver_H

#include "PolyBodyBVHOperators.h"

// Poly
#include "CATPolyObserver.h"
#include "CATPolyBodyGeoDiagnosis.h"
class CATPolyVertex;
class CATPolyEdge;
class CATIPolyCurve;
class CATPolyFace;
class CATIPolyMesh;
class CATIPolyCurve;
#include "CATPolyDeprecated.h"

// Math
#include "CATMathPoint.h"
#include "CATMathPoint2D.h"
#include "CATLISTV_CATMathPoint.h"

// System
#include "CATBoolean.h"
#include "CATErrorDef.h"

/**
 * This class logs several consistency checks of the geometry of a CATPolyBody.
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyGeoCheckerObserver : public CATPolyObserver<CATPolyBodyGeoCheckerObserver>
{

public:

  CATPolyBodyGeoCheckerObserver();
  ~CATPolyBodyGeoCheckerObserver();

public:
  // Error eBadFace_DegenerateTriangles
  virtual void AddDegenerateTriangle(CATPolyFace * face, const CATIPolyMesh * pmesh, int degeneratetriangle) = 0;
  // Error eBadFace_SelfIntersecting & eBadFaceFaceIntersection
  virtual void AddIntersection(CATPolyFace * cell1, const CATIPolyMesh * pmesh1, int indext1,
                               CATPolyFace * cell2, const CATIPolyMesh * pmesh2, int indext2,
                               const CATLISTV(CATMathPoint) & intersection) = 0;
  // Error eBadFace_NeedlesAndCaps
  virtual void AddNeedle(CATPolyFace * face, const CATIPolyMesh * pmesh, int needletriangle) = 0;
  // Error eBadFace_NeedlesAndCaps
  virtual void AddCap(CATPolyFace * face, const CATIPolyMesh * pmesh, int needletriangle) = 0;

  // Error eBadFace_SelfContact & eBadFaceFaceContact
  virtual void AddClearance(CATPolyFace * cell1, const CATIPolyMesh * pmesh1, int indext1, const CATMathPoint & barycenter1,
                            CATPolyFace * cell2, const CATIPolyMesh * pmesh2, int indext2, const CATMathPoint & barycenter2,
                            double distance) = 0;

  // Error eBadEdge_SelfIntersecting & eBadEdgeEdgeIntersection
  virtual void AddIntersection(CATPolyEdge * cell1, const CATIPolyCurve * pcurve1, int indexb1,
                               CATPolyEdge * cell2, const CATIPolyCurve * pcurve2, int indexb2,
                               const CATLISTV(CATMathPoint) & intersection){}

  // Error eBadEdge_SelfContact & eBadEdgeEdgeContact
  virtual void AddClearance(CATPolyEdge * cell1, const CATIPolyCurve * pcurve1, int indexb1, const CATMathPoint2D & barycenter1,
                            CATPolyEdge * cell2, const CATIPolyCurve * pcurve2, int indexb2, const CATMathPoint2D & barycenter2,
                            double distance){}

  // Error eBadEdgeFaceIntersection
  virtual void AddIntersection(CATPolyEdge * cell1, const CATIPolyCurve * pcurve1, int indexb1,
                               CATPolyFace * cell2, const CATIPolyMesh * pmesh2, int indext2,
                               const CATLISTV(CATMathPoint) & intersection){}

  // Error eBadEdgeFaceContact
  virtual void AddClearance(CATPolyEdge * cell1, const CATIPolyCurve * pcurve1, int indexb1, const CATMathPoint2D & barycenter1,
                            CATPolyFace * cell2, const CATIPolyMesh * pmesh2, int indext2, const CATMathPoint & barycenter2,
                            double distance){}

  // Error eBadFace_NonMatchingVertexNormals
  virtual void AddFaceWithNonMatchingVertexNormals(CATPolyFace * face, const CATIPolyMesh * pmesh){}

  /**
   * @deprecated CATIAR418 CATProgressCallback
   * To get feedback and to possibly stop the computation 
   * @param current current progress
   * @param total total range of progress
   * @return 1 if the computation has to stop, 0 otherwise
   */
  POLY_DEPRECATED("Use CATProgressCallback instead", virtual int Progress(int current, int total){return 0;});

};


#endif // !CATPolyBodyGeoCheckerObserver_H
