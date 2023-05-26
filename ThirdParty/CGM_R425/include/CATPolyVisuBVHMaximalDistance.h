//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Maximal Distance Operator between two Visualization representations
// (CATRep). Gives an interface between Visualization data and the
// maximal distance operator on two CATBVHTree @CATPolyBVHMaximalDistance.
//
//=============================================================================
// 2009-10-16   XXC: New.
// 2013-08-22   JXO: CATTolerance for XScale compliance
//=============================================================================

#ifndef CATPolyVisuBVHMaximalDistance_h
#define CATPolyVisuBVHMaximalDistance_h

#include "PolyVisuMeasureBetween.h"
#include "CATPolyVisuBVHMeasureBetween.h"
#include "CATPolyBVHMeasureBetween.h"
#include "CATPolyBVHMaximalDistance.h"
#include "CATBVHTreeRepBuilder.h"

// Math
#include "CATTolerance.h"
#include "CATMathInline.h"

// System
#include "CATSysBoolean.h"

class CATBVHTree;
class CATRep;
class CAT3DBagRep;
class CAT4x4Matrix;
class CATPolyBVHTreeFilterHiddenAndPrimitive;
class CATMathPoint;

/**
 * Computes the maximal distance between two visualisation
 * representations (CATRep).
 * Note about memory consumption: Temporary computation data, refering
 * to the operands and their positions, are stored inside this
 * Operator and it does not return to the user of the operator to
 * manage them. These data are released each time an operand changes or
 * when the operator is rebooted or deleted.
 */

class ExportedByPolyhedralMeasureBetween CATPolyVisuBVHMaximalDistance : public CATPolyVisuBVHMeasureBetween
{
 public:
  CATPolyVisuBVHMaximalDistance(const CATTolerance & iTol = CATGetDefaultTolerance());

  ~CATPolyVisuBVHMaximalDistance();

  /** Gets the maximal distance between the two objects. The result is
   *  significant only if the class has been initialized with two
   *  BVH's and successfully run.
   *@return -1 or 1e37 if the class instance has not been correctly
   *initialized or successfully run, the computed maximal distance
   *between the two instanciated objects otherwise.
   */
  double GetSquareMaximalDistance();

  /** Gets the maximal distance results computed between the two
   *  instanciated objects. The result is significant only if the
   *  class has been initialized with two BVH's and successfully run.
   *@param oMaximalDistance: the maximal distance between the two
   *instanciated objects.
   *@param oP1: the point on the first object the closest to the
   *second object (one of the point realizing the maximum distance
   *between the two objects).
   *@param oP2: the point on the second object the closest to the
   *first object (one of the point realizing the maximum distance
   *between the two objects).
   *@param oType: the type of subelements that realize the maximal
   *distance.
   */
  HRESULT GetResult(double & oMaximalDistance, CATMathPoint & oP1, CATMathPoint & oP2,
                    CATPolyBVHMeasureBetween::DistanceType & oType);
};

#endif //CATPolyVisuBVHMaximalDistance_h
