//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Maximal Distance Operator along normal directions of the first
// operand between two Visualization representations (CATRep). Gives
// an interface between Visualization data and the maximal distance
// "from 1 to 2" operator on two CATBVHTree
// @CATPolyBVHMaximalDistance1To2.
//
//=============================================================================
// 2010-01-22   XXC: New.
// 2013-08-22   JXO: CATTolerance for XScale compliance
//=============================================================================

#ifndef CATPolyVisuBVHMaximalDistance1To2_h
#define CATPolyVisuBVHMaximalDistance1To2_h

#include "PolyVisuMeasureBetween.h"
#include "CATPolyVisuBVHMeasureBetween.h"
#include "CATPolyBVHMeasureBetween.h"
#include "CATPolyBVHMaximalDistance1To2.h"
#include "CATBVHTreeRepBuilder.h"

// Math
#include "CATMathInline.h"
#include "CATTolerance.h"

// Sytem
#include "CATBoolean.h"

class CATBVHTree;
class CATRep;
class CAT3DBagRep;
class CAT4x4Matrix;
class CATPolyBVHTreeFilterHiddenAndPrimitive;
class CATMathPoint;

/**
 * Computes the maximal distance between two polyhedral objects along
 * the directions orthogonal to the first object sub-element
 * (triangles, segments, vertices). The objects are given by two
 * visualisation representations (CATRep).
 * Note about memory consumption: Temporary computation data, refering
 * to the operands and their positions, are stored inside this
 * operator and it does not return to the user of the operator to
 * manage them. These data are released each time an operand changes or
 * when the operator is rebooted or deleted.
 */

class ExportedByPolyhedralMeasureBetween CATPolyVisuBVHMaximalDistance1To2 : public CATPolyVisuBVHMeasureBetween
{
 public:
  CATPolyVisuBVHMaximalDistance1To2(const CATTolerance & iTol = CATGetDefaultTolerance());

  ~CATPolyVisuBVHMaximalDistance1To2();

  /** Returns if a distance has been measured between the two objects along the
   *  normal directions of the first object subelement.
   */
  CATBoolean HasDistance();

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
   *@return E_FAIL if the base operator does not exists, S_OK if a
   *distance has been computed, S_FALSE if no distance has been
   *computed (the operator has not been run or no distance exists for
   *the two given operands)
   */
  HRESULT GetResult(double & oMaximalDistance, CATMathPoint & oP1, CATMathPoint & oP2,
                    CATPolyBVHMeasureBetween::DistanceType & oType);

  /** Indicates if subelements of the first operand have to be
   *  extended as infinite geometrical elements (flat surfaces as
   *  planes, segments as lines or half-lines). Default behaviour is
   *  to consider finite elements (FALSE).
   *@param iUse: TRUE to consider infinite elements, FALSE otherwise.
   */
  void SetFirstOperandInfinite(CATBoolean iUse);

};

#endif //CATPolyVisuBVHMaximalDistance1To2_h
