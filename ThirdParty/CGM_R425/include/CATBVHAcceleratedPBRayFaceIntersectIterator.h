// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBVHAcceleratedPBRayFaceIntersectIterator.h
//
//===================================================================
//
// Usage notes:
// Impelementation of CATIPolyBodyRayFaceIntersectionIterator using
// BVH trees for speed up.
//
//===================================================================
//
// Sep 2009 Creation: JS9
//===================================================================

#ifndef CATBVHAcceleratedPBRayFaceIntersectIterator_h
#define CATBVHAcceleratedPBRayFaceIntersectIterator_h

#include "CATPolyBoundingVolumeOperators.h"

// Other
#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATMathPoint.h"
#include "CATMathDirection.h"
#include "CATErrorDef.h"

// Polyhedral
class CATPolyBody;
class CATIPolyMesh;
class CATIPolyFastMesh;
class CATBVHNodeConst;

// Interference
#include "CATIPolyBodyRayFaceIntersectionIterator.h"
class CATPolyInterfDecoratedPolyBody;
class CATPolyInterfMutex;

class ExportedByCATPolyBoundingVolumeOperators CATBVHAcceleratedPBRayFaceIntersectIterator
  : public CATIPolyBodyRayFaceIntersectionIterator
{
public:

  CATBVHAcceleratedPBRayFaceIntersectIterator();
  virtual ~CATBVHAcceleratedPBRayFaceIntersectIterator();

  /**
   * Beginning of the iteration.
   * @param rayOrigin origin of the ray.
   * @param rayDirection direction of the ray.
   * @param polyBody polybody to test.
   */
  virtual CATIPolyBodyRayFaceIntersectionIterator & Begin(const CATMathPoint & rayOrigin, const CATMathDirection & rayDirection,
                                                          const CATPolyBody * polyBody);

  /**
   * Go to the next candidate face.
   */
  virtual CATIPolyBodyRayFaceIntersectionIterator & operator++();

  /**
   * @return TRUE when the last face has been returned.
   */
  virtual CATBoolean End();

  /**
   * Get a face which is candidate for the ray cast.
   * For example, it might mean that the ray is intersecting the face bounding volume.
   * This function is only used if GetOptimizedCandidate returns NULL.
   * In this case, the CATIPolyFastMesh is constructed from the face.
   */
  virtual const CATIPolyMesh * GetCandidate();

  /**
   * Get an representation of the face optimized for ray intersection.
   * Implementing this function is usefull to cache the creation of
   * the fast mesh unlike the use of the GetCandidate function.
   * This function is used if its result is not NULL, otherwise
   * the GetCanditate function is used instead.
   */
  virtual CATIPolyFastMesh * GetOptimizedCandidate();

  /**
   * Set additional informations about the polybody which will be used by the begin function.
   * @param polyBodyNode Node corresponding to the polybody in the BVH.
   * @param decoPB decorated polybody.
   */
  void SetPolyBodyAdditionalInfo(const CATPolyInterfDecoratedPolyBody & decoPB);

  /**
   * The function is redefined to improve performances on UV.
   */
  virtual HRESULT GetRayDirection(const CATMathPoint & rayOrigin,
                                  const CATPolyBody * polyBody,
                                  int numRay,
                                  CATMathDirection & oRayDirection);


private:

  //----------------------------------------------------------
  // Find all the intersections of the ray with meshes and store them in the list
  HRESULT FindIntersectionWithRay(const CATBVHNodeConst & node);

  // Check if the BVs of the node intersect the ray or not
  CATBoolean ContinueDescent(const CATBVHNodeConst & node) const;

  // Release the meshes stored each time Begin is called.
  void ClearIntersectedFaces();
  //----------------------------------------------------------
  CATMathPoint _oRayOrigin;
  CATMathDirection _oRayDir;
  const CATPolyInterfDecoratedPolyBody * _pPolyBody;
  const CATBVHNodeConst * _pRootNode;
  CATListPV _oIntersectedFaces; // list of faces intersected by the ray
  int _iCurFaceIndex; // index of the iterator.
  //----------------------------------------------------------

};

#endif // CATBVHAcceleratedPBRayFaceIntersectIterator_h
