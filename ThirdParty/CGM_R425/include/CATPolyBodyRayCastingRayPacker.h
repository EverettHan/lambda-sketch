// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRayCastingRayPacker.h
//
//===================================================================
//
// Usage notes:
// Ray-casting against a BVHTree
//
//===================================================================
//
// April 2012 Creation: JXO
//===================================================================
#ifndef CATPolyBodyRayCastingRayPacker_h
#define CATPolyBodyRayCastingRayPacker_h

// Poly
#include "CAT3DVectorSetKDTree.h"
#include "CATThreadSafeStack.h"

// Math
#include "CATMathPoint.h"
#include "CATMathVector.h"

// System
#include "CATErrorDef.h"
#include "CATListOfInt.h"

// ExportedBy
#include "PolyBodyBVHOperators.h"

/**
 * In the context of ray-casting against a BVHTree, this operator packs 
 * "similar" rays together for a faster BVH traversal.
 */

class ExportedByPolyBodyBVHOperators CATPolyBodyRayCastingRayPacker
{
public:
  /**
   * Constructor
   */
  CATPolyBodyRayCastingRayPacker(const CATMathPoint * iOrigins, const CATMathVector * iDirections, unsigned int iNbRays, double iSceneRadius, int iNbMaxRaysPerPack = 10);
  /** Destructor */
  ~CATPolyBodyRayCastingRayPacker();
  /** returns number of computed packs */
  int GetNbPacks();
  /** returns size or i-th pack (begins at 0) */
  int GetSize(int iPack);
  /** returns i-th ray (begins at 0) in j-th pack (begins at 0) */
  int GetRay(int iPack, int jRay);


protected:
  /** @nodoc */
  void Descend(CAT3DVectorSetKDTree & iKDDirs);

private:
  CATThreadSafeStack<int> m_StackOfSizes;
  CATListOfInt m_ListOfSizes;
  CATListOfInt m_ListOfOffsets;
  CAT3DVectorSetKDTree m_KDDirs;
  const CATMathVector * m_Directions;
  const CATMathPoint * m_Origins;
  double m_SceneRadius;
  int m_NbPacks;
  double m_Tol;
  int m_NbMaxRaysPerPack;
};

#endif // CATPolyBodyRayCastingRayPacker_H

