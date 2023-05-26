//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBVBVOperator.h
//
//=============================================================================
// 2009-01-26   JXO
//      * New
//=============================================================================
#ifndef CATPolyBVBVOperator_H
#define CATPolyBVBVOperator_H

#include "CATPolyBoundingVolumeOperators.h"

#include "CATBoolean.h"
#include "CATTolerance.h"

#ifndef NULL
#define NULL 0
#endif

class CATPolyBoundingVolume;
class CATMathTransformation;
class CATMathVector;

/**
 * This is the operator for Bounding Volume / Bounding Volume
 * computations (such as union, overlap, etc...)
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyBVBVOperator
{
public:
  CATPolyBVBVOperator(){}
  virtual ~CATPolyBVBVOperator() {}

public:

  /**
   * States whether two BVs overlap given a tolerance.
   * Note that if the intersection is just a point, or a line, or a surface, it will return TRUE.
   */
  CATBoolean BVOverLap(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                       double iTol = 0.,
                       CATMathTransformation * ipPosition1 = NULL, CATMathTransformation * ipPosition2 = NULL);
  CATBoolean BVOverLapOnePos(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                             double iTol = 0.,
                             CATMathTransformation * ipPosition2 = NULL);

  /**
   * Test intersection between two bounding volumes whose relative positioning is a translation
   */
  CATBoolean BVOverLapOnePos(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                             const CATMathVector & translation2, double iTol = 0.);

  /**
   * Test intersection of two bounding volumes with their initial position.
   */
  CATBoolean BVOverlapNoPos(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                            double iTol = 0.);

  /**
   * Returns the minimum distance between two BVs, minus the tolerance.
   * This is a guaranty that minimum distance between the geometry is BIGGER than this one.
   */
  double GetMinimumDistance(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                            double iTol = 0.,
                            CATMathTransformation * ipPosition1 = NULL, CATMathTransformation * ipPosition2 = NULL);
  /**
   * Returns the square minimum distance between two BVs, minus the tolerance.
   * Faster to compute.
   */
  double GetSquareMinimumDistance(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                                  double iTol = 0.,
                                  CATMathTransformation * ipPosition1 = NULL, CATMathTransformation * ipPosition2 = NULL);
  /**
   * Returns the maximum distance between two BVs, plus the tolerance.
   * This is a guaranty that maximum distance between the geometry is SMALLER than this one.
   */
  double GetMaximumDistance(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                            double iTol = 0.,
                            CATMathTransformation * ipPosition1 = NULL, CATMathTransformation * ipPosition2 = NULL);
  /**
   * Returns the square maximum distance between two BVs, plus the tolerance.
   * Faster to compute.
   */
  double GetSquareMaximumDistance(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                                  double iTol = 0.,
                                  CATMathTransformation * ipPosition1 = NULL, CATMathTransformation * ipPosition2 = NULL);

  /**
   * Returns both the min and max distances between two BVs, minus/plus the tolerance.
   */
  void GetMinMaxDistance(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                         double & oMinDistance, double & oMaxDistance,
                         double iTol = 0.,
                         CATMathTransformation * ipPosition1 = NULL, CATMathTransformation * ipPosition2 = NULL);

  /**
   * Returns both the square min and max distances between two BVs, minus/plus the tolerance.
   * Faster to compute.
   */
  void GetSquareMinMaxDistance(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                               double & oMinDistance, double & oMaxDistance,
                               double iTol = 0.,
                               CATMathTransformation * ipPosition1 = NULL, CATMathTransformation * ipPosition2 = NULL);

  /** Minimal distance along a direction between two bounding volumes.
   *@return TRUE if a distance exists, FALSE otherwise.
   */
  CATBoolean GetSquareMinDirDistance(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                                     const CATMathVector & iDirection, double & oDistance, double iTol,
                                     CATMathTransformation * ipPosition1, CATMathTransformation * ipPosition2,
                                     const double eps1 = CATGetDefaultTolerance().EpsgForLengthTest() * 1000.);

  /** Returns a negative penetration distance if the two BV's overlap,
   *  or else the positive minimal distance.
   */
  double GetOverlapDistance(const CATPolyBoundingVolume * ipBV1, const CATPolyBoundingVolume * ipBV2,
                            CATMathTransformation * ipPosition1 = NULL, CATMathTransformation * ipPosition2 = NULL);
};

#endif // !CATPolyBVBVOperator_H
