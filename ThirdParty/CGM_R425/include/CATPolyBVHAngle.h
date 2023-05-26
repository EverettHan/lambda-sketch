//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Angle Measure Operator between two single objects (assimilable to a
// line or a plane).
//
//=============================================================================
// 2009-09-22   XXC: New.
// 2013-08-22   JXO: CATTolerance passed as argument for XScale compliance
//=============================================================================

#ifndef CATPolyBVHAngle_h
#define CATPolyBVHAngle_h

#include "PolyBodyMeasureBetween.h"
#include "CATPolyBVHMeasureBetween.h"
#include "CATMathPoint.h"
#include "CATMathConstant.h"
#include "CATBoolean.h"

class CATMathTransformation;
class CATBVHTree;
class CATBVHNodeConst;

// Math
#include "CATTolerance.h"

/**
 * Computes the angle between two single polyhedral objects given by
 * two generic Bounding Volume Hierarchies (BVH). Works only if the
 * two BVH contains only one object (one leaf), and if this object
 * allow an angle measure to be computed. Two points ON the geometry
 * must be given with the two arguments to discard ambiguities for
 * objects where two different angle values can be measured.
 */

class ExportedByPolyBodyMeasureBetween CATPolyBVHAngle : public CATPolyBVHMeasureBetween
{
 public:

  CATPolyBVHAngle(const CATTolerance & iTol = CATGetDefaultTolerance());

  virtual ~CATPolyBVHAngle();

  /** Defines the first object to use for the distance computation.
   *@param iTree1: BVH tree containing the geometrical data of a 3D
   *object, spatially partitioned into a bounding volume hierarchy
   *(BVH). See @CATBVHTree.
   *@param iSelPoint1: a point on the geometry of the first object to
   *"place" the angle measure.
   *@param iPosition1: transformation (composition of a rotation and a
   *translation) defining the position of the object to use.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetFirstOperand(CATBVHTree * iTree1, const CATMathPoint & iSelPoint1, const CATMathTransformation * iPosition1 = NULL);

  /** Defines the second object to use for the distance computation.
   *@param iTree1: BVH tree containing the geometrical data of a 3D
   *object, spatially partitioned into a bounding volume hierarchy
   *(BVH). See @CATBVHTree.
   *@param iSelPoint2: a point on the geometry of the second object to
   *"place" the angle measure.
   *@param iPosition1: transformation (composition of a rotation and a
   *translation) defining the position of the object to use.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetSecondOperand(CATBVHTree * iTree2, const CATMathPoint & iSelPoint2, const CATMathTransformation * iPosition2 = NULL);

  /** Defines the two objects to use for the distance computation.
   *@param iTree1: BVH tree containing the geometrical data of the
   *first 3D object.
   *@param iSelPoint1: a point on the geometry of the first object to
   *"place" the angle measure.
   *@param iTree2: BVH tree containing the geometrical data of the
   *second 3D object.
   *@param iSelPoint2: a point on the geometry of the second object to
   *"place" the angle measure.
   *@param iPosition1: position to use for the first 3D object.
   *@param iPosition2: position to use for the second 3D object.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetOperands(CATBVHTree * iTree1, const CATMathPoint & iSelPoint1, CATBVHTree * iTree2, const CATMathPoint & iSelPoint2,
                      const CATMathTransformation * iPosition1 = NULL, const CATMathTransformation * iPosition2 = NULL);

  /** Sets the first selection point to use in the operator to measure
   *  angles without any ambiguity.
   *@param iSelPoint: first selection point on the geometry of the
   *first object.
   */
  void SetFirstSelectionPoint(const CATMathPoint & iSelPoint);

  /** Sets the second selection point to use in the operator to
   *  measure angles without any ambiguity.
   *@param iSelPoint: second selection point on the geometry of the
   *second object.
   */
  void SetSecondSelectionPoint(const CATMathPoint & iSelPoint);

  /** Sets the selection points to use in the operator to measure
   *  angles without any ambiguity.
   *@param iSelPoint1: first selection point on the geometry of the
   *first object.
   *@param iSelPoint2: second selection point on the geometry of the
   *second object.
   */
  void SetSelectionPoints(const CATMathPoint & iSelPoint1, const CATMathPoint & iSelPoint2);

  /** Reboot the measure between solver and set 'no angle' in the
   *  result.
   *@param iRebootSelPoints: indicates if the selection points must
   *also be rebooted (no selection point), or not.
   */
  void Reboot(CATBoolean iRebootSelPoints);

  /** Reboot the measure between solver and set 'no angle' in the
   *  result. Overload, equivalent to Reboot(FALSE): do not reboot the
   *  selection points.
   *@param iRebootSelPoints: indicates if the selection points must
   *also be rebooted (no selection point), or not.
   */
  void Reboot();

  /** Runs the operator.
   *@return S_OK if the computation succeeded, an error code (E_FAIL,
   *E_OUTOFMEMORY, E_INVALIDARG, etc.) otherwise.
   */
  HRESULT Run();

  /** Gets the angle measured between the two objects. The result is
   *  significant only if the class has been initialized with two
   *  BVH's and successfully run.
   *@param iFormat: ask the method to return the measure in degree or
   *radian. Legal values are 0 for degree (default value) or any other
   *value for radian.
   *@return the angle measured or -1 if no angle has been measured
   *(operator was not run, or the run failed).
   */
  CATAngle GetAngle(int iFormat = 0);

  /** Gets the distance results computed between the two instanciated
   *  objects. The result is significant only if the class has been
   *  initialized with two BVH's and successfully run.
   *@param oDistance: the distance between the two instanciated
   *objects.
   *@param oP1: the point on the first object realizing the distance.
   *@param oP2: the point on the second object realizing the distance.
   *@return S_OK if it exists a distance between the two objects,
   *S_FALSE if there is not (e.a. for directional distances), E_FAIL
   *if it failed or has not been run.
   */
  virtual HRESULT GetResult(double & oAngle, CATMathPoint & oP1, CATMathPoint & oP2, CATPolyBVHMeasureBetween::DistanceType & oType) const;

  /** Gets the cells couple where is realized the minimum distance.
   *@param oCell1: the cell from the first argument where the minimum
   *distance is realized.
   *@param oCell2: the cell from the second argument where the minimum
   *distance is realized.
   */
  virtual HRESULT GetResultSupportCells(CATCellId *& oCell1, CATCellId *& oCell2) const;

 private:
  double InitCeilingMeasure(const CATPolyBoundingVolume * iBV1, const CATPolyBoundingVolume * iBV2,
                            CATMathTransformation * iPosition);

  double BoundingVolumeToBoundingVolumeMeasure(const CATPolyBoundingVolume * iBV1, const CATPolyBoundingVolume * iBV2,
                                               CATMathTransformation * iPosition);

  /** Computes the measure between two atomical elements (surface,
   *  curve, vertex). This method must also updates, if needed, the
   *  measure recorded in the object instance and computed so far, and
   *  the ceiling measure to discard some further elements pairs.
   *@param iElt1: the first Element.
   *@param iElt2: the second Element.
   *@param iPosition1: composition of positions of object 1 and object
   *2, applied to the first mesh to get the relative position of the
   *two objects.
   *@param ioCeilingMeasure: ceiling measure to update if needed.
   *@return S_OK if the distance was updated, S_FALSE if it was not,
   *fails if something is wrong.
   */
  HRESULT ElementToElementMeasure(BVHMeasureBetweenLocal_BVHContent * iElt1,
                                  BVHMeasureBetweenLocal_BVHContent * iElt2,
                                  double & ioCeilingMeasure);

  /** Function to give to node lists to define an order between two
   *  nodes according to the measure contained into them.
   */
  static int compare(const void * i, const void * j);

  /** Indicates if the first measure is better than the
   *  second. Example given, for a minimal distance measure, the first
   *  is better than the second measure if it is smaller, whereas for
   *  a maximal distance measure, the first is better than the second
   *  if it is greater.
   *@param iFirst: the first measure.
   *@param iSecond: the second measure.
   *@return TRUE if iFirst is better than iSecond, FALSE otherwise.
   */
  CATBoolean BetterMeasure (double iFirst, double iSecond) const;

 private:
  CATAngle _Angle;                      // The angle measured
  CATMathPoint _SelPoint1, _SelPoint2; // The two points given on the geometry
  CATBoolean _MeasureSet;             // Indicate if a measure has already been computed
  CATBoolean _Point1Set;             // Points on the geometry of first and second object are
  CATBoolean _Point2Set;            // initialized (in case of use of the default SetOperands method)
};

#endif //CATPolyBVHAngle_h
