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

#ifndef CATPolyBVHMeasureBetween_h
#define CATPolyBVHMeasureBetween_h

#include "PolyBodyMeasureBetween.h"
#include "CATMathTransformation.h"
#include "CATListPV.h"
#include "CATMapOfPtrToPtr.h"

class BVHDistanceMinLocal_Distance;
class BVHMeasureBetweenLocal_BVHContent;
class CATBVHTree;
class CATBVHNodeConst;
class CATMathPoint;
class CATPolyBoundingVolume;
class CATCellId;
class CATIPolyPoint;
class CATPolyBVHMeasureBetweenObserver;

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

typedef int CompareFunctionType (const void *, const void *);

class ExportedByPolyBodyMeasureBetween CATPolyBVHMeasureBetween
{
 public:

  /** Type of element that realize the minimal distance */
  typedef enum {
    Undefined = 0,
    PointPoint = 1,
    PointEdge = 2,
    PointTriangle = 5,
    EdgePoint = 3,
    EdgeEdge = 4,
    EdgeTriangle = 7,
    TrianglePoint = 6,
    TriangleEdge = 8,
    TriangleTriangle = 9
  } DistanceType;

  CATPolyBVHMeasureBetween(CompareFunctionType * iCompare, const CATTolerance & iTol = CATGetDefaultTolerance());

  virtual ~CATPolyBVHMeasureBetween();

  /** Sets an observer to the solver. Only one observer can be
   * defined. Succeed if no observer has been defined previously,
   * fails if an observer has been already defined. Set a null
   * observer to undefine the current observer.
   */
  HRESULT SetObserver(CATPolyBVHMeasureBetweenObserver * ioObserver);

  /** Gets the observer already set to the operator. Returns a null
   * pointer if no observer as been defined.
   */
  CATPolyBVHMeasureBetweenObserver * GetObserver();

  /** Defines the first object to use for the distance computation.
   *@param iTree1: BVH tree containing the geometrical data of a 3D
   *object, spatially partitioned into a bounding volume hierarchy
   *(BVH). See @CATBVHTree.
   *@param iPosition1: transformation (composition of a rotation and a
   *translation) defining the position of the object to use.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetFirstOperand(CATBVHTree * iTree1, const CATMathTransformation * iPosition1 = NULL);
  /** Defines the second object to use for the distance computation.
   *@param iTree1: BVH tree containing the geometrical data of a 3D
   *object, spatially partitioned into a bounding volume hierarchy
   *(BVH). See @CATBVHTree.
   *@param iPosition1: transformation (composition of a rotation and a
   *translation) defining the position of the object to use.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetSecondOperand(CATBVHTree * iTree2, const CATMathTransformation * iPosition2 = NULL);

  /** Defines the two objects to use for the distance computation.
   *@param iTree1: BVH tree containing the geometrical data of the
   *first 3D object.
   *@param iTree2: BVH tree containing the geometrical data of the
   *second 3D object.
   *@param iPosition1: position to use for the first 3D object.
   *@param iPosition2: position to use for the second 3D object.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetOperands(CATBVHTree * iTree1, CATBVHTree * iTree2,
                      const CATMathTransformation * iPosition1 = NULL, const CATMathTransformation * iPosition2 = NULL);

  /** Frees the recorded attributes and removes the trees from the
   *  operator.
   */
  virtual void Reboot();

  /** Runs the operator. The minimal distance results are recorded
   *  into this class. See methods @GetResultData and
   *  @GetSquareMinimalDistance to see how to get the results.
   *@return S_OK if the computation succeeded, an error code (E_FAIL,
   *E_OUTOFMEMORY, etc.) otherwise.
   */
  virtual HRESULT Run();

  /** Shortcut for the run method: initializes operands then runs the
   *  operator on the given BVH.
   *@param iObject1: BVH build on the first object.
   *@param iObject2: BVH build on the second object.
   *@param iPosition1: position to apply to the first object.
   *@param iPosition2: position to apply to the second object.
   */
  virtual HRESULT Run(CATBVHTree * iObject1, CATBVHTree * iObject2,
                      const CATMathTransformation * iPosition1 = NULL, const CATMathTransformation * iPosition2 = NULL);

  /** Gets the distance results computed between the two instanciated
   *  objects. The result is significant only if the class has been
   *  initialized with two BVH's and successfully run.
   *@param oDistance: the square distance between the two instanciated
   *objects.
   *@param oP1: the point on the first object realizing the distance.
   *@param oP2: the point on the second object realizing the distance.
   *@return S_OK if it exists a distance between the two objects,
   *S_FALSE if there is not (e.a. for directional distances), E_FAIL
   *if it failed or has not been run.
   */
  virtual HRESULT GetResult(double & oMinimalDistance, CATMathPoint & oP1, CATMathPoint & oP2, CATPolyBVHMeasureBetween::DistanceType & oType) const = 0;

  /** Gets the cell Ids couple where is realized the minimum distance.
   *@param oCell1: the cell id from the first argument where the minimum
   *distance is realized.
   *@param oCell2: the cell id from the second argument where the minimum
   *distance is realized.
   */
  virtual HRESULT GetResultSupportCells(CATCellId *& oCell1, CATCellId *& oCell2) const = 0;

  /** Gets the cell point couple where is realized the minimum
   * distance. It gives the polyhedral cell, the index and the
   * barycentric coordinates of the result point on each operand.
   *@param oPolyPoint1: the cell point from the first argument where
   *the minimum distance is realized.
   *@param oPolyPoint2: the cell point from the second argument where
   *the minimum distance is realized.
   */
  virtual HRESULT GetResultPolyPoints(CATIPolyPoint *& oPolyPoint1, CATIPolyPoint *& oPolyPoint2) const;

  /** Retrieves the content of a CATBVHNodeConst.
   *@param iTree: tree node where to get the content.
   *@param iPosition: the transformation that define the position of
   *the tree (object contained in the tree) according to their initial
   *positions.
   *@return the content of the node, enclosed in an abstract class
   *implemented according to the type of content.
   */
  BVHMeasureBetweenLocal_BVHContent * GetContent(CATBVHNodeConst * iTree, CATCellId * iCell, const CATMathTransformation * iPositionBody,
                                                 const CATMathTransformation * iTransformation = NULL);

  /** @nodoc */
  const CATTolerance & GetTol(){return m_Tol;}

 /** @nodoc
  */
 void ForceInitCeilingMeasure(double iCeilingMeasure);

 private:
  friend class BVHMeasureBetweenLocal_BVHBVHNode;
  friend class BVHMeasureBetweenLocal_BVHElementNode;
  friend class BVHMeasureBetweenLocal_ElementBVHNode;
  friend class BVHMeasureBetweenLocal_ElementElementNode;
  friend class BVHMeasureBetweenLocal_NodeSortedList;
  friend class CATPolySetMeasureBetween;

  /** Initialize the ceiling measure which allows to discard non
   *  interesting objects (bounding volumes or elements) such that it
   *  first discard nothing.
   *@param iBV1: bounding volume of the first tree root
   *@param iBV2: bounding volume of the second tree root
   *@param iPosition: Relative position of the two bounding volumes
   *@return the "greatest" ceiling measure.
   */
  virtual double InitCeilingMeasure(const CATPolyBoundingVolume * iBV1, const CATPolyBoundingVolume * iBV2,
                                    CATMathTransformation * iPosition) = 0;

  /** Computes the measure between two bounding volumes.
   *@param iBV1: first bounding volume
   *@param iBV2: second bounding volume
   *@param iPosition: Relative position of the two bounding volumes
   *@return the measure between the two bounding volumes.
   */
  virtual double BoundingVolumeToBoundingVolumeMeasure(const CATPolyBoundingVolume * BV1, const CATPolyBoundingVolume * BV2,
                                                       CATMathTransformation * iPosition) = 0;

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
  virtual HRESULT ElementToElementMeasure(BVHMeasureBetweenLocal_BVHContent * iElt1,
                                          BVHMeasureBetweenLocal_BVHContent * iElt2,
                                          double & ioCeilingMeasure) = 0;

  /** Indicates if the first measure is better than the
   *  second. Example given, for a minimal distance measure, the first
   *  is better than the second measure if it is smaller, whereas for
   *  a maximal distance measure, the first is better than the second
   *  if it is greater.
   *@param iFirst: the first measure.
   *@param iSecond: the second measure.
   *@return TRUE if iFirst is better than iSecond, FALSE otherwise.
   */
  virtual CATBoolean BetterMeasure (double iFirst, double iSecond) const = 0;

 protected:

  CompareFunctionType * _Compare;

  CATBVHTree * _Root1, * _Root2;
  // Respectively, position of the first operand, position of the
  // second operand, mixed positions _Trans2^{-1} * _Trans1, to move
  // only the first operand relatively to the second one. The points
  // in the result must be set back to the correct positions.
  CATMathTransformation _Trans1, _Trans2, _Trans;
  CATPolyBVHMeasureBetweenObserver * _Observer;

  CATMapOfPtrToPtr _mapOfNodeToMeshData; // To manage the lifecycle of attributes.

  const CATTolerance & m_Tol;
  double m_CeilingMeasure;
};

#endif //CATPolyBVHMeasureBetween_h
