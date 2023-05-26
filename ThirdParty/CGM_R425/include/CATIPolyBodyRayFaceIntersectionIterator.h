// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATIPolyBodyRayFaceIntersectionIterator.h
//
//===================================================================
//
// Usage notes:
// Iterator used by CATPolyBodyInclusion. It iterate along the faces of
// a polybody to find candidates for ray / face inclusion.
//
//===================================================================
//
// Sep 2009 Creation: JS9
// Aug 2010 JS9 add the ability to specify the raycast direction.
//===================================================================

#ifndef CATIPolyBodyRayFaceIntersectionIterator_h
#define CATIPolyBodyRayFaceIntersectionIterator_h

#include "CATPolyBoundingVolumeOperators.h"


// Other
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATMathPoint;
class CATMathDirection;

// Polyhedral
class CATPolyBody;
class CATIPolyMesh;
class CATIPolyFastMesh;

class ExportedByCATPolyBoundingVolumeOperators CATIPolyBodyRayFaceIntersectionIterator
{
public:

  
  virtual ~CATIPolyBodyRayFaceIntersectionIterator() {}

  /**
   * Beginning of the iteration.
   * @param rayOrigin origin of the ray.
   * @param rayDirection direction of the ray.
   * @param polyBody polybody to test.
   */
  virtual CATIPolyBodyRayFaceIntersectionIterator & Begin(const CATMathPoint & rayOrigin, const CATMathDirection & rayDirection,
                                                          const CATPolyBody * polyBody) = 0;

  /**
   * Go to the next candidate face.
   */
  virtual CATIPolyBodyRayFaceIntersectionIterator & operator++() = 0;

  /**
   * @return TRUE when the last face has been returned.
   */
  virtual CATBoolean End() = 0;

  /**
   * Get a face (given as mesh) which is candidate for the ray cast.
   * For example, it might mean that the ray is intersecting the face bounding volume.
   * This function is only used if GetOptimizedCandidate returns NULL.
   * In this case, the CATIPolyFastMesh is constructed from the face.
   */
  virtual const CATIPolyMesh * GetCandidate() = 0;

  /**
   * Get an representation of the face optimized for ray intersection.
   * Implementing this function is usefull to cache the creation of
   * the fast mesh unlike the use of the GetCandidate function.
   * This function is used if its result is not NULL, otherwise
   * the GetCanditate function is used   */
  virtual CATIPolyFastMesh * GetOptimizedCandidate() = 0;

  /**
   * This method allows to choose the specific direction used for the ray cast.
   * Theorically, the inclusion check could be done with any ray direction.
   * However, the inclusion detection implementation is not (yet) totally
   * robust and it may lead to ambiguous situations. In this rare cases a new ray is
   * relaunched until a definite status can be computed. Consequently, the method
   * might be called several time and each time it should throw an other ray, distinct
   * for any previous one.
   * A default implementation is provided which should work on all the cases.
   * Normally there is no need to redefine it.
   * @param rayOrigin origin of the ray.
   * @param polyBody polybody in which the test is done.
   * @param numRay 1 if it is the first ray to be launched, 2 or more
   *               if there is a need to launch several rays. Normally only one
   *               ray is needed.
   * @param[out] oRayDirection direction of the ray that will be used.
   * @return if the returned value is S_OK, the inclusion computation is done,
   *         if S_FALSE it just stops silently, any other error will stops the computation
   *         and is reported upward.
   */
  virtual HRESULT GetRayDirection(const CATMathPoint & rayOrigin,
                                  const CATPolyBody * polyBody,
                                  int numRay,
                                  CATMathDirection & oRayDirection);


protected:

  CATIPolyBodyRayFaceIntersectionIterator() {}

};

#endif // CATIPolyBodyRayFaceIntersectionIterator_h
