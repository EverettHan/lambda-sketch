//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Minimal Distance Operator between two Objects. The distance is
// given by the minimal distance found between two any points on each
// given objects. The acceleration structure is based on the
// Bounding Volume Hierarchy (BVH) CATPolyBVHTree.
//
//=============================================================================
// 2009-09-22   XXC: New.
// 2013-08-22   JXO: CATTolerance passed as argument for XScale compliance
// 2016-01-27   XXC: Cell support in result
//=============================================================================

#ifndef CATPolyBVHMinimalDistance_h
#define CATPolyBVHMinimalDistance_h

#include "PolyBodyMeasureBetween.h"
#include "CATPolyBVHMeasureBetween.h"
#include "CATPolyBVBVOperator.h"
#include "CATIAV5Level.h"

class CATPolyBVHMinimalDistanceObserver;
class BVHDistanceMinLocal_Distance;
class BVHDistanceMinLocal_BVHContent;
class CATBVHTree;
class CATBVHNodeConst;
class CATMathPoint;
class CATechExt;
class CATPolyCellId;
class CATIPolyPoint;

// Math
#include "CATTolerance.h"

/**
 * Computes the minimal distance between two polyhedral objects given
 * by two generic Bounding Volume Hierarchies (BVH).  These two
 * hierarchies should have been computed with the appropriate builder
 * according to the type of object given at the beginning
 * (Visualization model, NCGM model, etc.).
 * Note about memory consumption: Temporary computation data, refering
 * to the operands and their positions, are stored inside this
 * operator and it does not return to the user of the operator to
 * manage them. These data are released each time an operand changes or
 * when the operator is rebooted or deleted.
 */

class ExportedByPolyBodyMeasureBetween CATPolyBVHMinimalDistance : public CATPolyBVHMeasureBetween
{
 public:

  CATPolyBVHMinimalDistance(const CATTolerance & iTol = CATGetDefaultTolerance());

  virtual ~CATPolyBVHMinimalDistance();

  /** Indicates if subelements of the first operand have to be
   *  extended as infinite geometrical elements (flat surfaces as
   *  planes, segments as lines or half-lines). Default behaviour is
   *  to consider finite elements (FALSE).
   *@param iInfiniteGeometry: TRUE to consider infinite elements,
   *FALSE otherwise.
   */
  void SetInfiniteGeometry1(CATBoolean iInfiniteGeometry);
  /** Indicates if subelements of the second operand have to be
   *  extended as infinite geometrical elements (flat surfaces as
   *  planes, segments as lines or half-lines). Default behaviour is
   *  to consider finite elements (FALSE).
   *@param iInfiniteGeometry: TRUE to consider infinite elements,
   *FALSE otherwise.
   */
  void SetInfiniteGeometry2(CATBoolean iInfiniteGeometry);

  /** Frees the recorded attributes and removes the trees from the
   *  operator.
   */
  void Reboot();

  /** Runs the operator. The minimal distance results are recorded
   *  into this class. See methods @GetResultData and
   *  @GetSquareMinimalDistance to see how to get the results.
   *@return S_OK if the computation succeeded, an error code (E_FAIL,
   *E_OUTOFMEMORY, etc.) otherwise.
   */
  HRESULT Run();

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
   */
  virtual HRESULT GetResult(double & oMinimalDistance, CATMathPoint & oP1, CATMathPoint & oP2, CATPolyBVHMeasureBetween::DistanceType & oType) const;

  /** Gets the cells couple where is realized the minimum distance.
   *@param oCell1: the cell from the first argument where the minimum
   *distance is realized.
   *@param oCell2: the cell from the second argument where the minimum
   *distance is realized.
   */
  virtual HRESULT GetResultSupportCells(CATCellId *& oCell1, CATCellId *& oCell2) const;

  /** Gets the cell point couple where is realized the minimum
   * distance. It gives the polyhedral cell, the index and the
   * barycentric coordinates of the result point on each operand.
   *@param oPolyPoint1: the cell point from the first argument where
   *the minimum distance is realized.
   *@param oPolyPoint2: the cell point from the second argument where
   *the minimum distance is realized.
   */
  virtual HRESULT GetResultPolyPoints(CATIPolyPoint *& oPolyPoint1, CATIPolyPoint *& oPolyPoint2) const;

  /** Sets an observer that needs to listen to operator events
   *  If a previous observer is already set, then it will be replaced
   *  with the lastest observer
   *@param iObserver: The observer that is to be set.
   */
  void SetObserver(CATPolyBVHMinimalDistanceObserver * iObserver);

  /** Gets the current observer
   *@return current observer
   */
  CATPolyBVHMinimalDistanceObserver * GetObserver() const;

 private:
  /** Initialize the ceiling measure which allows to discard non
   *  interesting objects (bounding volumes or elements) such that it
   *  first discard nothing.
   *@param iBV1: bounding volume of the first tree root
   *@param iBV2: bounding volume of the second tree root
   *@param iPosition: Relative position of the two bounding volumes
   *@return the "greatest" ceiling measure.
   */
  double InitCeilingMeasure(const CATPolyBoundingVolume * iBV1, const CATPolyBoundingVolume * iBV2,
                            CATMathTransformation * iPosition);

  /** Computes the measure between two bounding volumes.
   *@param iBV1: first bounding volume
   *@param iBV2: second bounding volume
   *@param iPosition: Relative position of the two bounding volumes
   *@return the measure between the two bounding volumes.
   */
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
  CATPolyBVBVOperator computer;

  CATBoolean _FirstInfinite, _SecondInfinite;

  BVHDistanceMinLocal_Distance * _MinimalDistance;

  CATPolyBVHMinimalDistanceObserver * _Observer;
  CATechExt * _PhoenixExtension;
};

#endif //CATPolyBVHMinimalDistance_h
