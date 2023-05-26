// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Generic Minimum Distance Operator. For two Sets S1 and S2, it
// computes the minimum distance between the two sets, i.e. the
// smallest distance found between an element of S1 and an element of
// S2.
//
//=============================================================================
// 2009-03-17   XXC: New.
// 2013-08-22   JXO: CATTolerance for XScale compliance
//=============================================================================

#ifndef CATPolyBodyDistanceMinGeneric_h
#define CATPolyBodyDistanceMinGeneric_h

#include "CATPolyDistanceOperators.h"
class CATTolerance;
#include "CATBoolean.h"
#include "CATMathBox.h"
#include "CATListPV.h"

class CATPolyVoxelOctree;
class CATPolyVoxelPartition;
class CATPolyVoxelPartitionIterator;
class GenericDistanceMinOper_Distance;
class GenericDistanceMinOper_Element;
class GenericDistanceMinOper_DataSet;
class GenericDistanceMinOper_NodeSortedList;
class GenericDistanceMinOper_Marks;

/** Abstract class defining the behaviour of a set of elements.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_DataSet
{
public:
  inline GenericDistanceMinOper_DataSet();

  /** Initialize the set: mainly produces the array of elements, for
   *  a fast access to them and (only concerning the second set) to
   *  enable to store references of them in the voxel tree instead
   *  of multiple copies. Must be called only once, each time new
   *  data are given to the set.
   *  WARNING: the call to this method is done during the
   *  initialization of the generic distance operator
   *  CATPolyBodyDistanceMinGeneric. Implementations do not have to take
   *  care about it. However, implementations must take care that sets
   *  implementations can be initialized when the generic class is.
   *@return S_OK if the set is correctly initialized, E_FAIL
   *otherwise.
   */
  virtual HRESULT Initialize();

  /** Allows to free all elements stored in the set and set the
   *  cardinal to 0.
   */
  virtual void CleanUp();

  /** Return the cardinal (the number of elements) of the set.
   *@return the set cardinal.
   */
  inline const int SizeOfSet() const;

  inline CATPolyVoxelOctree * GetTree() const;

  /** Gets the box bounding all the set elements. Only depends on
   *  the implementation.
   */
  virtual HRESULT GetBoundingBox(CATMathBox& oBoundingBoxOfSet) = 0;

  /** Fast recovering of an element in the set. Only returns a const
   *  pointer to avoid duplications of elements and modifications of
   *  them.
   *@param iN: Index of the element in the set, starting at 0,
   *ending at (_NbElements - 1) included.
   *@return A pointer to the element at index iN in the array of the
   *set elements. NULL if iN does not correspond to a valid index.
   */
  inline const GenericDistanceMinOper_Element * GetElement(int iN) const;

  /** Return a new iterator (class CATPolyVoxelPartitionIterator) for
   *  the element at the given index and the given voxel partition.
   *@param iEltIdx: the index of the element in the set to intersect
   *with the voxel partition.
   *@param iPartition: the voxel partition containing the voxels to
   *intersect with the appropriate element and then to iterate on.
   */
  virtual CATPolyVoxelPartitionIterator * GetNewIterator(const int iEltIdx,
                                                         const CATPolyVoxelPartition * iPartition) const = 0;

  inline void AddRef();
  inline void Release();

protected:
  /** Return the size to be allocated for the array _Elements. Only
   *  depends on the implementation and is called only once by the
   *  Initialize method. The distance is then stored for a fast
   *  access. Indeed, this process can be more or less slow,
   *  according to the implementation.
   */
  virtual int GetNbElt() = 0;
  /** Iterate and return the element to be placed in the array
   *  _Elements. Only depends on the implementation and is called
   *  only once during the initialization. The elements are then
   *  stored for a fast access to them.
   *@return From the first to the last element in the array.
   */
  virtual GenericDistanceMinOper_Element * GetNextElt() = 0;

  inline virtual ~GenericDistanceMinOper_DataSet();

private:

  /** Creates the voxel tree then inserts elements of S2 into it.
   *@return S_OK if it works, E_FAIL if something is wrong.
   */
  HRESULT Populate();

  /** Delete the voxel tree allocated.
   */
  void ReleaseVoxelTree();

protected: // Attributes
  GenericDistanceMinOper_Element ** _Elements; // Array that maintains references on the
  // elements into the set. Allows to reference
  // elements in the voxel tree.
  int _NbElements; // Size of the array, number of elements in the set.
  CATPolyVoxelOctree * _VoxelTree;
private:
  int _nb_ref;
};

/** Class CATPolyBodyDistanceMinGeneric.
 *  This base class is a generic tool designed to determine, for two
 *  abstract sets S1 and S2 (set of triangles, points, etc.), the
 *  minimum distance (here an abstract notion) realized by one element
 *  of each set. Implementations of this class must provide:
 * 
 *  1. The type of elements contained in the two Sets S1 and S2
 *  (classes Element and Element_ref respectively)
 *  2. A way to iterate on these elements (the type of set)
 *  3. A distance notion.
 *  4. A distance computation method between an element of each set
 */

class ExportedByPolyhedralDistanceOperators CATPolyBodyDistanceMinGeneric
{
 public:
  /**********************************************/
  /* CATDistanceMinGeneric public methods      */
  /********************************************/
  
  virtual ~CATPolyBodyDistanceMinGeneric();
  
 protected:
  
  /****************************************************/
  /* CATPolyBodyDistanceMinGeneric protected methods */
  /**************************************************/
  
  /** Generic class constructor.
   */
  CATPolyBodyDistanceMinGeneric(const CATTolerance & iTol);
  
 protected:
  /** Computes the distance between two elements, one in the first set
   *  S1, one in the second set S2. Central methods which only depends
   *  on the implementation.
   *@param iElement1: the element in S1.
   *@param iElement2: the element in S2.
   *@return the distance between iElement1 and iElement2.
   */
  virtual GenericDistanceMinOper_Distance *
    ElementToElementDistance(const GenericDistanceMinOper_Element& iElement1,
                             const GenericDistanceMinOper_Element& iElement2) const = 0;
  
 protected:
  /** Delete the data sets S1 and S2.
   */
  void ReleaseDataSets();
  
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
  virtual HRESULT UpdateDistanceIfNeeded(const GenericDistanceMinOper_Distance & iDistance) = 0;

  /** Initialization of the distance operator. First initializes the
   *  two sets S1 and S2, then creates the voxel tree and adds
   *  elements of S2 into it.
   *@return S_OK if the initialization process succeeds, E_FAIL
   *otherwise.
   */
  virtual HRESULT Initialize();

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

  /**
   * @param oDataSet1 [out, IUnknown#Release] 
   * @param oDataSet2 [out, IUnknown#Release] 
   */
  virtual HRESULT DetachDataSets(GenericDistanceMinOper_DataSet * & oDataSet1, GenericDistanceMinOper_DataSet * & oDataSet2);
  virtual HRESULT AttachDataSets(GenericDistanceMinOper_DataSet * iDataSet1, GenericDistanceMinOper_DataSet * iDataSet2);

private:
  HRESULT RunElement(const GenericDistanceMinOper_Element * Elt,
                     GenericDistanceMinOper_NodeSortedList * NodesList,
                     double CeilingSqDist);

  static double BoxBoxMaxDistance(const CATMathBox & box1, const CATMathBox & box2);

protected:
  /*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
  /* CATPolyDistanceMinGeneric protected members      */
  /*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/

  GenericDistanceMinOper_DataSet * _DataSet_1;
  GenericDistanceMinOper_DataSet * _DataSet_2;
  GenericDistanceMinOper_Marks * _Marks;
  double _ToleranceForLengthTest;
  const CATTolerance & m_Tol;
};

// Class GenericDistanceMinOper_DataSet
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

GenericDistanceMinOper_DataSet::GenericDistanceMinOper_DataSet()
  :
  _Elements(NULL),
  _NbElements(-1),
  _VoxelTree(NULL),
  _nb_ref(1)
{}

GenericDistanceMinOper_DataSet::~GenericDistanceMinOper_DataSet()
{
  CleanUp();
  _VoxelTree = NULL;
  _Elements = NULL;
}

const int GenericDistanceMinOper_DataSet::SizeOfSet() const
{
  return _NbElements;
}

CATPolyVoxelOctree * GenericDistanceMinOper_DataSet::GetTree() const
{
  return _VoxelTree;
}

const GenericDistanceMinOper_Element * GenericDistanceMinOper_DataSet::GetElement(int iN) const
{
  return ((iN >= 0 && iN < _NbElements)?_Elements[iN]:NULL);
}

void GenericDistanceMinOper_DataSet::AddRef()
{
  _nb_ref++;
}

void GenericDistanceMinOper_DataSet::Release()
{
  _nb_ref--;
  if (_nb_ref == 0)
    delete this;
}

#endif //CATPolyBodyDistanceMinGeneric_h

