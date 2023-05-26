// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Generic Distance Operator. For two Sets S1 and S2, it computes the
// distance from each element of S1 to elements of S2. The result as
// the distance notion are implementation dependant.
//
//=============================================================================
// 2009-04-24   XXC: Change of acceleration data structure from
//              CATPolyVoxelTree to CATPolyVoxelOctree.
// 2009-01-13   XXC: New. (From MPX CATDistanceSetSetDistance)
// 2013-06-26   JXO: Added CATTolerance as input parameter
//=============================================================================

#ifndef CATPolyBodyDistanceGeneric_h
#define CATPolyBodyDistanceGeneric_h

#include "CATPolyDistanceOperators.h"

// Math
class CATTolerance;
#include "CATBoolean.h"
#include "CATMathBox.h"

// System
#include "CATListPV.h"

class CATPolyVoxelOctree;
class GenericDistanceOper_Distance;
class GenericDistanceOper_Element;
class GenericDistanceOper_Element_ref;
class GenericDistanceOper_DataSet_diff;
class GenericDistanceOper_DataSet_ref;
class GenericDistanceOper_NodeSortedList;

/** Class CATPolyBodyDistanceGeneric.
 *  This base class is a generic tool designed to determine, for each
 *  element in an abstract Set S1 (set of triangles, points, etc.), a
 *  distance (here an abstract notion) to the elements of a second
 *  abstract Set S2 (which elements are not necessary of the same type
 *  than the element of the first set S1). Implementations of this
 *  class must provide:
 * 
 *  1. The type of elements contained in the two Sets S1 and S2
 *  (classes Element and Element_ref respectively)
 *  2. A way to iterate on these elements (the type of set)
 *  3. A distance notion and all operations on distances (Need update,
 *  Update)
 *      - This allows to manage different notions of distance: scalar,
          scalar field, etc.
 *      - This allows different behaviour. For instance, one distance
 *        for each element in the first set or only one distance (the
 *        minimum one) for all elements (Note that in this last case,
 *        no optimization is done on the elements of the first set S1).
 *  4. A distance computation method between an element of each set
 *  5. A scalar distance measure between an element of the first set
 *  S1 and a bounding box, which allows to assert that if this
 *  distance is greater than a reference scalar, the distance for the
 *  elements contained in the box is greater than the distance
 *  computed so far.
 *
 * In the sequel, classes with a name ending by "_ref " are specific
 * to the reference set (the set to which the distance is measured),
 * while classes ending by "_diff" are specific to the set of which
 * elements are considered to measure the distance to the second
 * reference set.
 */

class ExportedByPolyhedralDistanceOperators CATPolyBodyDistanceGeneric
{
 public:
  /**********************************************/
  /* CATDistanceGenericDistance public methods */
  /********************************************/
  
  virtual ~CATPolyBodyDistanceGeneric();
  
 public:
  
  /*************************************************/
  /* CATPolyBodyDistanceGeneric protected methods */
  /***********************************************/
  
  /** Generic class constructor.
   *@param iAllowElementsInMultipleVoxels: if FALSE, then each element
   *is added to the deepest voxel, possibly in an inner node in the
   *tree, that fully contains it. If TRUE, each element is added to
   *each voxel in the leaves of the tree it intersects.
   */
  CATPolyBodyDistanceGeneric(const CATTolerance & iTol);
  
 protected:
  /** Computes the distance between two elements, one in the first set
   *  S1, one in the second set S2. Central methods which only depends
   *  on the implementation.
   *@param iElement1: the element in S1.
   *@param iElement2: the element in S2.
   *@return the distance between iElement1 and iElement2.
   */
  virtual GenericDistanceOper_Distance *
    ElementToElementDistance(const GenericDistanceOper_Element& iElement1,
                             const GenericDistanceOper_Element_ref& iElement2) const = 0;
 public:
  virtual double ElementToBoxDistance(const GenericDistanceOper_Element& iElement, const CATMathBox& iBox) const = 0;
  
 protected:
  /** Delete the data sets S1 and S2.
   */
  void ReleaseDataSets();
  /** Delete the voxel tree allocated.
   */
  void ReleaseVoxelTree();
  
  /** Updates the current distance data associated to a given element
   * in the first set S1, according to a given distance, only if
   * needed. It (must) first verify(ies) if the update is actually
   * needed.
   *@param iElement: an element of the first set.
   *@param iDistance: the distance with potentially new usefull data.
   *@return S_OK if an update was needed and everything has gone
   *right, S_FALSE if the distance did not need to be updated, E_FAIL
   *if something has gone wrong.
   */
  virtual HRESULT UpdateDistanceIfNeeded(const GenericDistanceOper_Element * iElement,
                                         const GenericDistanceOper_Distance & iDistance) = 0;

  /** Initialization of the distance operator. First initializes the
   *  two sets S1 and S2, then creates the voxel tree and adds
   *  elements of S2 into it.
   *@return S_OK if the initialization process succeeds, E_FAIL
   *otherwise.
   */
  virtual HRESULT Initialize();

  /** Creates the voxel tree then inserts elements of S2 into it.
   *@return S_OK if it works, E_FAIL if something is wrong.
   */
  HRESULT Populate();

public:

  /** Run the operator. The way the distance data are returned to the
   *  user is left to the implementation, according to the needs. It
   *  can be in a layer on the elements of the first set S1 or any
   *  other structure defined in the implementation. The distances
   *  computed in this method are actually send to the implementation
   *  through the method UpdateDistanceIfNeeded. It is then of the
   *  implementation to manage/store/return them as they would be.
   */
  virtual HRESULT Run();

  /** Release the data sets S1 and S2 and the voxel tree, to prepare
   *  the operator to work on two another sets.
   */
  virtual void Reboot();

private:
  HRESULT RunElement(const GenericDistanceOper_Element * Elt,
                     GenericDistanceOper_NodeSortedList * NodesList,
                     double CeilingSqDist);

  static double BoxBoxMaxDistance(const CATMathBox & box1, const CATMathBox & box2);

protected:
  /*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
  /* CATPolyDistanceGenericDistance protected members */
  /*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/

  GenericDistanceOper_DataSet_diff * _DataSet_1;
  GenericDistanceOper_DataSet_ref * _DataSet_2;
  CATPolyVoxelOctree * _VoxelTree; // The voxel tree for the second set.
  CATBoolean _AllowElementsInMultipleVoxels;
  double _ToleranceForLengthTest;
};

#endif //CATPolyBodyDistanceGeneric_h

