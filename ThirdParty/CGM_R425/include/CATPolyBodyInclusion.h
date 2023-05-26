// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyInclusion.h
//
//===================================================================
//
// Usage notes:
// Utility class containing functions performing inclusion tests on
// a PolyBody
//
//===================================================================
//
// Sep 2009 Creation: JS9
// Jul 2013 Modification JXO: added tolerance in constructor
//===================================================================

#ifndef CATPolyBodyInclusion_h
#define CATPolyBodyInclusion_h

#include "PolyBodyServices.h"

#include "CATPolyListOfRayTriangleIntersections.h"

// Other
#include "CATErrorDef.h"  // Definition of HRESULT.
#include "CATLISTV_CATMathPoint.h"
#include "CATTolerance.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
class CATMathDirection;
class CATMathTransformation;

// Polyhedral
class CATPolyBody;
class CATPolyFace;
class CATIPolyMesh;

// Inclusion
class CATIPolyBodyRayFaceIntersectionIterator;
class CATIPolyFastMesh;

struct CATPolyPointAndNormal
{
  CATMathPoint p;
  CATMathVector v;
};

#include "CATCGMSTDSafeIncludeStart.h"

#include <vector>

#include "CATCGMSTDSafeIncludeEnd.h"

class ExportedByPolyBodyServices CATPolyBodyInclusion
{
public:

  CATPolyBodyInclusion(const CATTolerance & iTol = CATGetDefaultTolerance());
  virtual ~CATPolyBodyInclusion();

  /**
   * Check if the point is inside the polybody.
   * This algortihm assume that the polybody is water-tight. There should not be any geometric gap between adjacent faces.
   * All the faces should be plain and not contain any hole. If the polybody does not satify this, the result
   * is uncertain.
   * @param transfo is not NULL, specify an additional transformation on the polyBody position.
   * @return S_OK if the point is inside or on the polybody, S_FALSE if the point is outside the polybody,
   *         an error code if somthing went wrong.
   */
  HRESULT IsPointInsidePolyBody(const CATMathPoint & point,
                                const CATPolyBody * polyBody,
                                const CATMathTransformation * transfo = NULL,
                                int nbrays = 1);

  /**
   * Set the iterator finding the meshes which may intersect with the ray.
   * If not set or set to NULL, uses the default (slow) iterator.
   */
  void SetFaceIterator(CATIPolyBodyRayFaceIntersectionIterator * iterator);

private:

  //-------------------------------------------------------------------------------
  HRESULT GetRayPolyBodyIntersections(CATIPolyBodyRayFaceIntersectionIterator & itFace,
                                      const CATMathPoint & rayOrigin,
                                      const CATPolyBody * polyBody,
                                      int & oNbIntersections,
                                      int & nbtries);

  
  // Convert a CATPolyFace into a CATPolyFastMesh.
  CATIPolyFastMesh * CreateOptimizedRepresentation(const CATIPolyMesh * mesh);

  // Return S_OK if the raycast was OK, E_ABORT if we need to cast an other ray
  // S_FALSE if the origin is actually on the polybody
  HRESULT GetIntersectionsWithMesh(const CATMathPoint & origin,
                                   const CATMathDirection & rayDir,
                                   CATIPolyFastMesh & mesh,
                                   std::vector<CATPolyPointAndNormal> & currentIntersections,
                                   const CATIPolyMesh * orig);

  // Check that the intersection point has not yet been found by an other
  // test. In this case, we need to launch an other ray.
  // TODO: Use robust techniques to avoid lauching several rays.
  CATBoolean CheckForDoubleIntersections(const CATMathPoint & point, const CATMathVector & normal, 
                                         std::vector<CATPolyPointAndNormal> & list);

  // Count how many intersections are in the list
  // Since the origin might be added several times
  // count it only once
  int CountInterferences(const std::vector<CATPolyPointAndNormal> & list, const CATMathPoint & rayOrigin) const;

  //-------------------------------------------------------------------------------
  CATIPolyBodyRayFaceIntersectionIterator * _pFaceIterator;
  const double m_tol;
  //-------------------------------------------------------------------------------

};

#endif // CATPolyBodyInclusion_h
