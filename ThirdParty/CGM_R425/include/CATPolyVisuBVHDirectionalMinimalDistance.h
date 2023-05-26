//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Directional Minimal Distance Operator between two Visualization
// representations (CATRep). Gives an interface between Visualization
// data and the directional minimal distance operator on two
// CATBVHTree @CATPolyBVHDirectionalMinimalDistance.
//
//=============================================================================
// 2010-01-14   XXC: New.
//=============================================================================

#ifndef CATPolyVisuBVHDirectionalMinimalDistance_h
#define CATPolyVisuBVHDirectionalMinimalDistance_h

#include "PolyVisuMeasureBetween.h"
#include "CATPolyVisuBVHMeasureBetween.h"
#include "CATSysBoolean.h"
#include "CATPolyBVHDirectionalMinimalDistance.h"
#include "CATBVHTreeRepBuilder.h"

class CATBVHTree;
class CATRep;
class CAT3DBagRep;
class CAT4x4Matrix;
class CATPolyBVHTreeFilterHiddenAndPrimitive;
class CATMathPoint;

// Math
#include "CATTolerance.h"
#include "CATMathInline.h"

/**
 * Computes the minimal distance along a direction between two
 * visualisation representations (CATRep).
 * Note about memory consumption: Temporary computation data, refering
 * to the operands and their positions, are stored inside this
 * Operator and it does not return to the user of the operator to
 * manage them. These data are released each time an operand changes or
 * when the operator is rebooted or deleted.
 */

class ExportedByPolyhedralMeasureBetween CATPolyVisuBVHDirectionalMinimalDistance : public CATPolyVisuBVHMeasureBetween
{
 public:
  CATPolyVisuBVHDirectionalMinimalDistance(const CATTolerance & iTol = CATGetDefaultTolerance());

  ~CATPolyVisuBVHDirectionalMinimalDistance();

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

  /** Set the direction along which distances are computed. The
   *  direction does not need to be normalized.
   *@param iDirection: the direction along which distance have to be
   *computed.
   */
  void SetDirection(const CATMathVector & iDirection);

  /** Runs the operator with the specified direction. Shortcut, same
   *  as "SetDirection(iDirection) + Run(iPosition1,iPosition2)".
   *@param iDirection: the direction along which distances are
   *computed.
   *@param iPosition1: position to apply to the first object.
   *@param iPosition2: position to apply to the second object.
   *@return S_OK if the computation succeeded, an error code (E_FAIL,
   *E_OUTOFMEMORY, etc.) otherwise.
   */
  HRESULT Run(const CATMathVector & iDirection,
              const CAT4x4Matrix * iPosition1 = NULL, const CAT4x4Matrix * iPosition2 = NULL);

  /** Returns if a distance exists between the two objects along the
   *  given direction.
   */
  CATBoolean HasDistance();

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
   *@return E_FAIL if the base operator does not exists, S_OK if a
   *distance has been computed, S_FALSE if no distance has been
   *computed (the operator has not been run or no distance exists for
   *the two given operands)
   */
  HRESULT GetResult(double & oMinimalDistance, CATMathPoint & oP1, CATMathPoint & oP2,
                    CATPolyBVHMeasureBetween::DistanceType & oType);

};

#endif //CATPolyVisuBVHDirectionalMinimalDistance_h
