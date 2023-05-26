//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Minimal Distance Operator between two Visualization representations
// (CATRep). Gives an interface between Visualization data and the
// minimal distance operator on two CATBVHTree @CATPolyBVHMinimalDistance.
//
//=============================================================================
// 2009-10-16   XXC: New.
// 2013-08-22   JXO: CATTolerance for XScale compliance
//=============================================================================

#ifndef CATPolyVisuBVHMinimalDistance_h
#define CATPolyVisuBVHMinimalDistance_h

#include "PolyVisuMeasureBetween.h"
#include "CATPolyVisuBVHMeasureBetween.h"
#include "CATPolyBVHMinimalDistance.h"
#include "CATBVHTreeRepBuilder.h"

// Math
#include "CATMathInline.h"
#include "CATTolerance.h"

// System
#include "CATSysBoolean.h"

class CATBVHTree;
class CATRep;
class CAT3DBagRep;
class CAT4x4Matrix;
class CATPolyBVHTreeFilterHiddenAndPrimitive;
class CATMathPoint;

/**
 * Computes the minimal distance between two visualisation
 * representations (CATRep).
 * Note about memory consumption: Temporary computation data, refering
 * to the operands and their positions, are stored inside this
 * Operator and it does not return to the user of the operator to
 * manage them. These data are released each time an operand changes or
 * when the operator is rebooted or deleted.
 */

class ExportedByPolyhedralMeasureBetween CATPolyVisuBVHMinimalDistance : public CATPolyVisuBVHMeasureBetween
{
 public:
  CATPolyVisuBVHMinimalDistance(const CATTolerance & iTol = CATGetDefaultTolerance());

  ~CATPolyVisuBVHMinimalDistance();

  /** Indicates if subelements of the first operand have to be
   *  extended as infinite geometrical elements (flat surfaces as
   *  planes, segments as lines or half-lines). Default behaviour is
   *  to consider finite elements (FALSE).
   *@param iUse: TRUE to consider infinite elements, FALSE otherwise.
   */
  void SetFirstOperandInfinite(CATBoolean iUse);

  /** Indicates if subelements of the second operand have to be
   *  extended as infinite geometrical elements (flat surfaces as
   *  planes, segments as lines or half-lines). Default behaviour is
   *  to consider finite elements (FALSE).
   *@param iUse: TRUE to consider infinite elements, FALSE otherwise.
   */
  void SetSecondOperandInfinite(CATBoolean iUse);

  /** Gets the minimal distance between the two objects. The result is
   *  significant only if the class has been initialized with two
   *  BVH's and successfully run.
   *@return -1 or 1e37 if the class instance has not been correctly
   *initialized or successfully run, the computed minimal distance
   *between the two instanciated objects otherwise.
   */
  double GetSquareMinimalDistance();

  /** Gets the minimal distance results computed between the two
   *  instanciated objects. The result is significant only if the
   *  class has been initialized with two BVH's and successfully run.
   *@param oMinimalDistance: the minimal distance between the two
   *instanciated objects.
   *@param oP1: the point on the first object the closest to the
   *second object (one of the point realizing the minimum distance
   *between the two objects).
   *@param oP2: the point on the second object the closest to the
   *first object (one of the point realizing the minimum distance
   *between the two objects).
   *@param oType: the type of subelements that realize the minimal
   *distance.
   */
  HRESULT GetResult(double & oMinimalDistance, CATMathPoint & oP1, CATMathPoint & oP2,
                    CATPolyBVHMinimalDistance::DistanceType & oType);

};

#endif //CATPolyVisuBVHMinimalDistance_h
