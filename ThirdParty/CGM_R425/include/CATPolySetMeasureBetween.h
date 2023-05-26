//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Distances Operator between pairs of objects in a set. The distances
// are given by the distance found between two any points on each
// given objects for each pair. The acceleration structure is based on
// the Bounding Volume Hierarchy (BVH) CATPolyBVHTree, the set is
// given by a set of BVH CATPolyBVHTreeSet.
//
//=============================================================================
// 2016-06-14   XXC: New.
//=============================================================================

#ifndef CATPolySetMeasureBetween_h
#define CATPolySetMeasureBetween_h

#include "CATIPolySetMeasureBetween.h"
#include "PolyBodyMeasureBetween.h"
#include "CATMapOfIntToInt.h"
#include "CATListPV.h"

class CATBVHTreeSet;
class CATPolyBVHMeasureBetween;
class CATTolerance;
class CATMathPoint;
class CATMeasureBetweenSetResult;
class CATPolyNeedDistanceUpdateObserver;
class CATIPolyInterfInputCoupleFilter;

// Math
#include "CATTolerance.h"

/**
 * Computes the distance between pairs of polyhedral objects given by
 * one or two sets of Bounding Volume Hierarchies (BVH). According to
 * the number of set given, one or two, it respectively computes all
 * the distances between pairs of BVH in the set or all the distances
 * between any one BVH taken in each of the two sets. If two sets are
 * given and selected mode is UniqueMeasure, computes only the best
 * measure (find solution faster by using bounding data of each tree
 * in the set)
 */

class ExportedByPolyBodyMeasureBetween CATPolySetMeasureBetween : public CATIPolySetMeasureBetween
{
public:
  using MeasureMode = CATIPolySetMeasureBetween::MeasureMode;

public:

  /** Type of element that realize the minimal distance */
  typedef enum {
    Minimal = 0,
    DirectionalMinimal = 1,
    Maximal = 2,
    Maximal1To2 = 3
  } MeasureType;

  /** Constructor. One has to define the distance type (minimal,
   *  maximal, directional, ...) in this method, then the tolerance to
   *  use in the distance computation.
   */
  CATPolySetMeasureBetween(MeasureType iType, const CATTolerance & iTol = CATGetDefaultTolerance());

  virtual ~CATPolySetMeasureBetween();

  /** Defines the first object set to use for the distance computation.
   *@param iTree1: BVH tree containing the geometrical data of a 3D
   *object, spatially partitioned into a bounding volume hierarchy
   *(BVH). See @CATBVHTree.
   *@param iPosition1: transformation (composition of a rotation and a
   *translation) defining the position of the object to use.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  virtual HRESULT SetFirstOperand(CATBVHTreeSet * iTree1);

  /** Defines the second object to use for the distance computation.
   *@param iTree1: BVH tree containing the geometrical data of a 3D
   *object, spatially partitioned into a bounding volume hierarchy
   *(BVH). See @CATBVHTree.
   *@param iPosition1: transformation (composition of a rotation and a
   *translation) defining the position of the object to use.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  virtual HRESULT SetSecondOperand(CATBVHTreeSet * iTree2);

  /** Frees the recorded attributes and removes the trees from the
   *  operator.
   */
  virtual void Reboot();

  /** Runs the operator. The minimal distance results are recorded
   *  into this class. See methods @GetResultData to see how to get
   *  the results.
   *@return S_OK if the computation succeeded, an error code (E_FAIL,
   *E_OUTOFMEMORY, etc.) otherwise.
   */
  virtual HRESULT Run();

  /** Gets the global best distance result computed between two
   *  instanciated objects contained in the set. Relevant in both
   *  AllMeasures and BestMeasureOnly modes.
   *@param oDistance: the square distance between the two instanciated
   *objects.
   *@param oId1: the id of the tree in set 1 realizing the best distance.
   *@param oP1: the point on the first object realizing the distance.
   *@param oId1: the id of the tree in set 2 realizing the best distance.
   *@param oP2: the point on the second object realizing the distance.
   *@return S_OK if it exists a distance between the two objects,
   *S_FALSE if there is not (e.a. for directional distances), E_FAIL
   *if it failed or has not been run.
   */
  virtual HRESULT GetResultData(double & oDistance, int & oId1, CATMathPoint & oP1, int & oId2, CATMathPoint & oP2);

  /** Gets the distance results computed between two particular
   *  instanciated objects contained in the set(s). Relevant only in
   *  AllMeasures mode.
   *@param iId1: id of the object in set 1 one wants to retrieve the distance result.
   *@param iId1: id of the object in set 2 (or set 1 if only one set
   *was given) one wants to retrieve the distance result.
   *@param oDistance: square distance realized between the two objects.
   *@param oP1: the point on the first object realizing the distance.
   *@param oP2: the point on the second object realizing the distance.
   *@return S_OK if it exists a distance between the two objects,
   *S_FALSE if there is not (e.g. for directional distances or
   *filtered couples), E_FAIL if it failed or has not been run.
   */
  virtual HRESULT GetResultData(int iId1, int iId2, double & oDistance, CATMathPoint & oP1, CATMathPoint & oP2);

private:

  /** @nodoc
   */
  HRESULT RunBestMode();

  void RebootFirst();
  void RebootSecond();
  void RebootResults();

  CATBoolean Filter(int object1Id, int object2Id);

private:

  MeasureType _Type;
  CATPolyBVHMeasureBetween * _Operator;

  CATBVHTreeSet * _Set1, * _Set2;
  unsigned int _SizeSet1, _SizeSet2;
  CATMapOfIntToInt _mapIdToRank1, _mapIdToRank2;

  CATPolyNeedDistanceUpdateObserver * _Observer1, * _Observer2;
  CATMeasureBetweenSetResult * _Results; // All results for each couple
  int _best1, _best2; // Ranks for the best result;
};

#endif //CATPolySetMeasureBetween_h
