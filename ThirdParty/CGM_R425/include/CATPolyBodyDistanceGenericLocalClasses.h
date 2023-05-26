// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Generic Distance Operator. For two Sets S1 and S2, it computes the
// distance from each element of S1 to elements of S2. The result as
// the distance notion are implementation dependant.
//
//=============================================================================
// 2009-01-13   XXC: New.
//=============================================================================

#ifndef CATPolyBodyDistanceGenericLocalClasses_h
#define CATPolyBodyDistanceGenericLocalClasses_h

#include "CATPolyDistanceOperators.h"
#include "CATMathBox.h"
#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATHeap.h"

class CATPolyBodyDistanceGeneric;
class CATPolyVoxelOctreeNode;
class CATPolyVoxelPartition;
class CATPolyVoxelPartitionIterator;

/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
/* CATPolyBodyDistanceGeneric LOCAL CLASSES           */
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/

/** Class Distance: defines the notion of distance. Only depends on
 *  the implementation of the distance operator. Can be a scalar or
 *  a scalar field, with other data.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_Distance
{
public:
  /** Let E be an element in the first set S1 and (*this), the
   *  distance between E and an element in the second set. This
   *  method defines a scalar valued distance such that if the
   *  distance returned by the method which compute the distance
   *  between the element E and a bounding box is greater than this
   *  distance, none elements in the box will result in an update of
   *  the given distance.  The method is used to discard some voxels
   *  in the voxel tree, and so accelerate the distance computation
   *  process.
   *@return A scalar valued distance compared to element/bounding
   *box distance.
   */
  virtual double GetCeilingDistance() = 0;
protected:
  GenericDistanceOper_Distance(){}
public:
  virtual ~GenericDistanceOper_Distance(){}
};

/** Abstract class which defines an element of a
 *  set. Implementations of the generic distance operator must
 *  provide a classinherited from this one to define specifically
 *  the elements of the first set S1.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_Element
{
public:
  GenericDistanceOper_Element(){}
  virtual ~GenericDistanceOper_Element(){}
};

/** Abstract class which describes the behaviour of the elements of
 *  the second set. Implementations of the distance operator must
 *  provide a class inherited from this class to define the element
 *  of the second set.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_Element_ref : public GenericDistanceOper_Element
{
public:
  INLINE GenericDistanceOper_Element_ref();
  virtual ~GenericDistanceOper_Element_ref(){}
public:
  /** Gets the box bounding the element. Only depends on the
   *  implementation.
   */
  virtual const CATMathBox & Box() const = 0;
  /** Define the index of the element in the set. This method is
   *  called only once by the initiliazer of the set DataSet_ref,
   *  which know chich index to apply to each of its element (in
   *  other words, DO NOT INITIALIZE IT BY YOURSELF). The index is
   *  unique and used in the local class DataSet_ref::Marks to
   *  record which elements has been explored during the distance
   *  computation process. See this class for details.
   *@param iIndex: the index to set to the element.
   */ 
  INLINE void InitIndex(const int iIndex);
  /** Gets the index of the element in the set.
   *@return the index of the element.
   */
  INLINE int GetIndex() const;
private:
  int _Index;
};

/** Mother abstract class defining the behaviour of a set of
 *  element. This behaviour is the one common to the first and the
 *  second set.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_DataSet
{
public:
  INLINE GenericDistanceOper_DataSet();
  INLINE virtual ~GenericDistanceOper_DataSet();

  /** Initialize the set: mainly produces the array of elements, for
   *  a fast access to them and (only concerning the second set) to
   *  enable to store references of them in the voxel tree instead
   *  of multiple copies. Must be called only once, each time new
   *  data are given to the set.
   *  WARNING: the call to this method is done during the
   *  initialization of the generic distance operator
   *  CATPolyBodyDistanceGeneric. Implementations do not have to take
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
  INLINE const int SizeOfSet() const;

  /** Gets the box bounding all the set elements. Only depends on
   *  the implementation.
   */
  virtual HRESULT GetBoundingBox(CATMathBox& oBoundingBoxOfSet) = 0;

protected:
  /** Return the size to be allocated for the array _Elements. Only
   *  depends on the implementation and is called only once by the
   *  Initialize method. The distance is then stored for a fast
   *  access. Indeed, this process can be more or less slow,
   *  according to the implementation.
   */
  virtual int GetNbElt() = 0;
  /** Iterates on and returns the elements to be placed in the array
   *  _Elements. Only depends on the implementation and is called
   *  only once during the initialization. The elements are then
   *  stored for a fast access to them.
   *@return From the first to the last element in the array/set.
   */
  virtual GenericDistanceOper_Element * GetNextElt() = 0;

protected: // Attributes
  GenericDistanceOper_Element ** _Elements; // Array that maintains references on the
  // elements into the set. Allows to reference
  // elements in the voxel tree.
  int _NbElements; // Size of the array, number of elements in the set.
};

class ExportedByPolyhedralDistanceOperators GenericDistanceOper_DataSet_diff : public GenericDistanceOper_DataSet {
public:
  GenericDistanceOper_DataSet_diff(){}
  virtual ~GenericDistanceOper_DataSet_diff(){}
public:
  /** Fast recovering of an element in the set. Only returns a const
   *  pointer to avoid duplications of elements and modifications of
   *  them.
   *@param iN: Index of the element in the set, starting at 0,
   *ending at (_NbElements - 1) included.
   *@return A pointer to the element at index iN in the array of the
   *set elements. NULL if iN does not correspond to a valid index.
   */
  INLINE const GenericDistanceOper_Element * GetElement(int iN) const;
};

/** Class used to mark every element of the set, using their index
 *  (given by the method Element_ref::GetIndex()) in the set. The
 *  mark is used to indicate that the distance between an element
 *  in the first set and the element to mark has already been
 *  computed. This is usefull to avoid multiple element to element
 *  distance computation with the same elements, in the case the
 *  option _AllowElementsInMultipleVoxels is set to true. Indeed,
 *  in this case, as an element of the second set can be in many
 *  different voxels, this element can be used many times to get
 *  the distance from the current element in the first set and
 *  consequently cost times. The mark, which is fast to set and
 *  get, avoid that extra cost.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_Marks
{
 public:
  /** Marks constructor.
   *@param iNbMarks: the cardinal of the second set, i.e. the
   *number of marks to store.
   */
  INLINE GenericDistanceOper_Marks(int iNbMark);
  INLINE ~GenericDistanceOper_Marks();
  /** Unset every mark.
   */
  void UnmarkAll();

  /** Set a mark for the element with the given index.
   *@param iIndex: index of the element to mark.
   */
  INLINE void SetMarked(int iIndex);
  /** Indicate if the element with the given index is marked or
   *  not.
   *@param iIndex: index of an element in the second set.
   *@return TRUE if the element is marked, FALSE if it is not.
   */
  INLINE CATBoolean IsMarked(int iIndex);
 private:
  static const int _Corresp[8];
  char * _Marks;
  int _NbMark;
};

class ExportedByPolyhedralDistanceOperators GenericDistanceOper_DataSet_ref : public GenericDistanceOper_DataSet {
public:
  INLINE GenericDistanceOper_DataSet_ref();
  virtual INLINE ~GenericDistanceOper_DataSet_ref();
public:

  /** Initialization of a set, specifically for reference sets:
   *  calls the initialization of the mother class then produces and
   *  initializes marks (see class DataSet_ref::Marks), and
   *  initializes the index of each element. Must be called only
   *  once, each time new data are given to the set.
   *  WARNING: the call to this method is done during the
   *  initialization of the generic distance operator
   *  CATPolyBodyDistanceGeneric. Implementations do not have to take
   *  care about it. However, implementations must take care that sets
   *  implementations can be initialized when the generic class is.
   *@return S_OK if the set is correctly initialized, E_FAIL
   *otherwise.
   */
  virtual HRESULT Initialize();

  /** Fast recovering of an element (of type Element_ref) in the
   *  set. Only returns a const pointer to avoid duplications and
   *  modifications of elements.
   *@param iN: Index of the element in the set, starting at 0,
   *ending at (_NbElements - 1) included.
   *@return A pointer to the element at index iN in the array of the
   *set elements. NULL if iN does not correspond to a valid index.
   */
  INLINE const GenericDistanceOper_Element_ref * GetElement(int iN) const;

  /** Return a new iterator (class CATPolyVoxelPartitionIterator) for
   *  the element at the given index and the given voxel partition.
   *@param iEltIdx: the index of the element in the set to intersect
   *with the voxel partition.
   *@param iPartition: the voxel partition containing the voxels to
   *intersect with the appropriate element and then to iterate on.
   */
  virtual CATPolyVoxelPartitionIterator * GetNewIterator(const int iEltIdx,
                                                         const CATPolyVoxelPartition * iPartition) const = 0;

  /** Indicates that the element with index iIndex is marked,
   *  i.e. the distance between it and an element of the first set
   *  S1 just has been computed. See class DataSet_ref::Marks for
   *  details.
   *  This method is only used during the generic distance
   *  computation. Implementations must ignore it.
   *@param iIndex: the index (given by the method
   *Element_ref::GetIndex()) of the element to mark.
   */
  INLINE void SetMarked(int iIndex);
  /** Indicates if the element with index iIndex has been
   *  marked. See class DataSet_ref::Marks for details.
   *  This method is only used during the generic distance
   *  computation. Implementations must ignore it.
   *@param iIndex: the index (given by the method
   *Element_ref::GetIndex()) of the element to test if it has been
   *marked.
   *@return TRUE if the element has been marked, FALSE otherwise.
   */
  INLINE CATBoolean IsMarked(int iIndex);

  /** Unmark every element of the set. See class DataSet_ref::Marks
   *  for details.
   *  This method is called during the generic distance computation
   *  each time the process of an element of the first set S1 is
   *  finished and one iterates on a new one. Implementations must
   *  ignore it.
   */
  INLINE void UnmarkAll();

protected:
  /** Iterates on and returns the elements to be placed in the array
   *  _Elements. Only depends on the implementation and is called
   *  only once during the initialization. The elements are then
   *  stored for a fast access to them.
   *  Replaces the method GetNextElt used in the initialization of the
   *  mother class, to restrain elements to be of type Element_ref
   *  instead of Element.
   *@return From the first to the last element in the array.
   */
  virtual GenericDistanceOper_Element_ref * GetNextEltRef() = 0;
  /** Implementation of the mother astract method. Just calls the
   *  abstract method GetNextEltRef to allow to restrain elements of
   *  this set to be of type Element_ref.
   */
  INLINE GenericDistanceOper_Element * GetNextElt();

private:
  GenericDistanceOper_Marks * _Marks;
};

/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
/* CATDistanceGenericDistance PRIVATE LOCAL CLASSES */
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/

class GenericDistanceOper_Node;
/** Class NodeSortedList. Allows to easily store and sort the nodes
 *  of a voxel tree that must be explored in order to compute the
 *  minimal distance between every element of the first set and the
 *  second set. Works as a chained list, in order to easily insert
 *  elements in the list.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_NodeSortedList
{
public:
  /** Constructor. The list is defined from a reference element (of
   *  the first set S1) which is the current element used to compute
   *  distances. This element, referenced in the list, allows to
   *  compute the distance from it to the boxes bounding the nodes
   *  to store in the list. This distance is then used to sort
   *  elements.
   *@param iCompRef: the element in S1 used as a reference for the
   *distance sorting.
   */
  INLINE GenericDistanceOper_NodeSortedList();
  /** Destructor, empties the list, delete cells and remove a
   *  reference on the nodes contained in the cells, via the cell
   *  destructor.
   */
  INLINE ~GenericDistanceOper_NodeSortedList();
  /** Add a list of nodes in the list, correctly sorted by priority,
   *  according to a ceiling squared distance. This allows to consider
   *  the nodes close to the element before the other, and
   *  consequently accelerate the find of the real distance of the
   *  element of reference to the set Set2.
   *  The sort of the list is done in this method. The given list does
   *  not need to be sorted before.
   *@param iNodes: the list of nodes to add to the list.
   */
  HRESULT Add(CATListPV& iNodes);
  /** Pop the first node of the sorted list according to the current
   *  ceiling distance. The node is NULL if the list is empty or if
   *  the ceiling distance is smaller than the distance of the first
   *  node (distance from the reference element in the node to the
   *  box of the node). If a node is popped out, a reference is
   *  added and the lifecycle must then be managed by the user.
   *@param iCeilingSqDist: current ceiling distance.
   *@param oNode: the node popped out.
   *@return S_OK if a node has been popped out, E_FAIL otherwise.
   */
  HRESULT Pop(const double iCeilingSqDist, GenericDistanceOper_Node*& oNode);
  /** Empties the list and erases all its cells. Remove a reference
   *  on the nodes contained in the cells via the cell destructor.
   */
  void Clean();

private:
  CATHeap _List;
};

/** Class Node: allows to define a sorted list of voxel tree node
 *  content to iterate on, during the distance computation
 *  process. A node can be of two types (see inherited class for
 *  each of these types): a voxel in the voxel tree or an element
 *  previously inserted into the voxel tree. The sort is made
 *  according to the distance, from lowest distances to highest
 *  distances.
 *  Includes an AddRef/Release mechanism to manage the node
 *  lifecycle. As long as the node is in the list, the lifecycle is
 *  managed into the list. As it is popped out, the user manages the
 *  lifecycle.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_Node
{
public:
  /** If the node corresponds to an inner node in the voxel tree,
   *  gets a list of all its children, i.e. elements possibly
   *  contained in the node and voxel children.
   *@param iCeilingSqDist: current ceiling distance used to filter
   *children which will potentially change the distance data.
   *@param iCompRef: an element of reference in the set S1, used to
   *filter and order the children according to their priority (the
   *distance between the element of reference and their bounding
   *boxes).
   *@param iComputer: the distance operator which allows to compute
   *the distance between the given element and the bounding box of
   *each child. Usefull for the filtering by the iCeilingSqDist value
   *and to determine the priority of each node box, from the nearests
   *to the farests to the element.   
   *@param oChildrenNodes: the list filled with the children of the
   *(*this) node.
   */
  virtual void GetChildren(const double iCeilingSqDist, const GenericDistanceOper_Element * iCompRef,
                           const CATPolyBodyDistanceGeneric * iComputer, const GenericDistanceOper_DataSet_ref * oDataSet,
                           CATListPV& oChildrenNodes) const = 0;
  /** If the node corresponds to an element inserted into the voxel
   *  tree, retrieves the corresponding element.
   *@return the element possibly contained in the node. NULL if no
   *element is in the node.
   */
  virtual const GenericDistanceOper_Element_ref* GetElement() const = 0;
  /** Gets the box bounding the node: the box of the voxel or the
   *  bounding box of the element according to the type of the node.
   */
  virtual const CATMathBox GetBox() const = 0;

  /** Compare two nodes according to the stored distance from an
   *  element of reference and their bounding boxes.
   *@param op2: the second node to compare to the cell (*this).
   *@return TRUE if (*this) <= op2, FALSE otherwise.
   */
  INLINE CATBoolean operator <= (const GenericDistanceOper_Node & op2);

  virtual ~GenericDistanceOper_Node(){}

protected:
  INLINE GenericDistanceOper_Node(const double iRefBoxSqDistance);

public:
  /** Method used to sort two cells between each others.
   *@return -1 if Node1 <= Node2, +1 if Node1 > Node2, 0 if at least
   *one of the two nodes is NULL.
   */
  static INLINE int Compare(const void * Node1, const void * Node2);

public:
  double _CompDistance;
};

// Class inherited from class Node, to represent a single element
// (previously inserted into the voxel tree) in the list of node to
// iterate on.
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_SingleElementNode : public GenericDistanceOper_Node
{
public:
  /** Constructor of the class.
   *@param iElement: the element inserted into the voxel tree and
   *which the node will contain.
   */
  INLINE GenericDistanceOper_SingleElementNode(const double iRefBoxSqDistance,
                                               const GenericDistanceOper_Element_ref& iElement);
  /** Retrieves the element contained in a node corresponding to an
   *  element inserted in the voxel tree.
   *@return the element contained in the node. Should not be null.
   */
  INLINE const GenericDistanceOper_Element_ref* GetElement() const;
  /** Since a node containing an element has no children, this
   *  method return an emptied list.
   */
  INLINE void GetChildren(const double iCeilingSqDist, const GenericDistanceOper_Element * iCompRef,
                          const CATPolyBodyDistanceGeneric * iComputer, const GenericDistanceOper_DataSet_ref * oDataSet,
                          CATListPV& oChildrenNodes) const;
  /** Get the box bounding the element contained in the node (use
   *  the method Box() in class Element_ref).
   */
  INLINE const CATMathBox GetBox() const;
protected:
  const GenericDistanceOper_Element_ref& _ElementInNode;
};

/** Class inherited from class Node, to represent a node containing a
 *  voxel (containing elements and other voxels as children) of the
 *  voxel tree, in the list of node to iterate on.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceOper_Voxel : public GenericDistanceOper_Node
{
public:
  /** Constructor of a Voxel.
   *@param iTree: A reference to the voxel in the voxel tree
   *@param iVoxelNumber: the number of that voxel in the tree.
   */
  INLINE GenericDistanceOper_Voxel(const double iRefBoxSqDistance,
                                   const CATPolyVoxelOctreeNode * iTree);
  /** Gets nodes containing the elements and other voxels contained
   *  in the voxel represented by the node.
   *@param oChildrenNodes: a (out) list containing the nodes under
   *the current one in the tree hierarchy.
   */
  void GetChildren(const double iCeilingSqDist, const GenericDistanceOper_Element * iCompRef,
                   const CATPolyBodyDistanceGeneric * iComputer, const GenericDistanceOper_DataSet_ref * oDataSet,
                   CATListPV& oChildrenNodes) const;
  /** Get the box defining the voxel represented by the node.
   */
  const CATMathBox GetBox() const;
  /** Since a node representing a voxel does not contain a unique
   *  element, return a NULL pointer.
   *@return NULL (no element in the node)
   */
  INLINE const GenericDistanceOper_Element_ref* GetElement() const;

private:
  const CATPolyVoxelOctreeNode * _Tree;
};

// _____________________________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
// Inline methods implementation. ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
// _____________________________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

// Class GenericDistanceOper_Element_ref
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
INLINE GenericDistanceOper_Element_ref::GenericDistanceOper_Element_ref()
  :
  _Index(-1){}

INLINE void GenericDistanceOper_Element_ref::InitIndex(const int iIndex)
{
  if (_Index == -1)
    _Index = iIndex;
}

INLINE int GenericDistanceOper_Element_ref::GetIndex() const
{
  return _Index;
}

// Class GenericDistanceOper_DataSet
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

INLINE GenericDistanceOper_DataSet::GenericDistanceOper_DataSet()
  :
  _Elements(NULL),
  _NbElements(-1)
{}

INLINE GenericDistanceOper_DataSet::~GenericDistanceOper_DataSet()
{
  CleanUp();
  _Elements = NULL;
}

INLINE const int GenericDistanceOper_DataSet::SizeOfSet() const
{
  return _NbElements;
}

// Class GenericDistanceOper_DataSet_diff
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

INLINE const GenericDistanceOper_Element * GenericDistanceOper_DataSet_diff::GetElement(int iN) const
{
  return ((iN >= 0 && iN < _NbElements)?_Elements[iN]:NULL);
}

// Class GenericDistanceOper_DataSet_ref
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

INLINE GenericDistanceOper_DataSet_ref::GenericDistanceOper_DataSet_ref()
  :
  _Marks(NULL)
{}
INLINE GenericDistanceOper_DataSet_ref::~GenericDistanceOper_DataSet_ref()
{
  if (_Marks) {
    delete _Marks;
    _Marks = NULL;
  }
}

INLINE const GenericDistanceOper_Element_ref *
GenericDistanceOper_DataSet_ref::GetElement(int iN) const
{
  return (GenericDistanceOper_Element_ref *)((iN >= 0 && iN < _NbElements)?_Elements[iN]:NULL);
}

INLINE void GenericDistanceOper_DataSet_ref::SetMarked(int iIndex)
{
  if (_Marks)
    _Marks->SetMarked(iIndex);
}

INLINE CATBoolean GenericDistanceOper_DataSet_ref::IsMarked(int iIndex)
{
  if (_Marks)
    return _Marks->IsMarked(iIndex);
  else
    return FALSE;
}

INLINE void GenericDistanceOper_DataSet_ref::UnmarkAll()
{
  if (_Marks) _Marks->UnmarkAll();
}

INLINE GenericDistanceOper_Element * GenericDistanceOper_DataSet_ref::GetNextElt()
{
  return (this->GetNextEltRef());
}

// Class GenericDistanceOper_DataSet_ref::Marks
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

INLINE GenericDistanceOper_Marks::GenericDistanceOper_Marks(int iNbMark)
  :
  _NbMark(iNbMark)
{
  int size = (iNbMark/8) + ((iNbMark%8 == 0)?0:1);
  _Marks = (char*)calloc(1,size);
  UnmarkAll();
}

INLINE GenericDistanceOper_Marks::~GenericDistanceOper_Marks()
{
  if (_Marks) {
    free (_Marks);
    _Marks = NULL;
  }
}

INLINE void GenericDistanceOper_Marks::SetMarked(int iIndex) {
  if (_Marks != NULL && iIndex >= 0 && iIndex < _NbMark)
    _Marks[iIndex/8] = _Marks[iIndex/8] | _Corresp[iIndex%8];
}

INLINE CATBoolean GenericDistanceOper_Marks::IsMarked(int iIndex)
{
  // return true also if the index is invalid. This allows to stop
  // the action on the current element, because someting is wrong.
  return (_Marks == NULL || iIndex < 0 || iIndex >= _NbMark || (_Marks[iIndex/8] & _Corresp[iIndex%8]))?TRUE:FALSE;
}

// Class GenericDistanceOper_Node
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

INLINE GenericDistanceOper_Node::GenericDistanceOper_Node(const double iRefBoxSqDistance)
  :
  _CompDistance(iRefBoxSqDistance)
{}

INLINE CATBoolean GenericDistanceOper_Node::operator <= (const GenericDistanceOper_Node & op2)
{
  return (this->_CompDistance <= op2._CompDistance)?TRUE:FALSE;
}

INLINE int GenericDistanceOper_Node::Compare(const void * Node1, const void * Node2)
{
  return (!(Node1 && Node2))
    ? 0
    : (((const GenericDistanceOper_Node*)Node1)->_CompDistance < ((const GenericDistanceOper_Node*)Node2)->_CompDistance)
       ? -1
       :  1;
}

// Class GenericDistanceOper_SingleElementNode
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

INLINE GenericDistanceOper_SingleElementNode::GenericDistanceOper_SingleElementNode(const double iRefBoxSqDistance,
                                                                             const GenericDistanceOper_Element_ref& iElement)
  :
  GenericDistanceOper_Node(iRefBoxSqDistance),
  _ElementInNode(iElement)
{}

INLINE const GenericDistanceOper_Element_ref* GenericDistanceOper_SingleElementNode::GetElement() const
{
  return &_ElementInNode;
}

INLINE void GenericDistanceOper_SingleElementNode::GetChildren(const double iCeilingSqDist,
                                                               const GenericDistanceOper_Element * iCompRef,
                                                               const CATPolyBodyDistanceGeneric * iComputer,
                                                               const GenericDistanceOper_DataSet_ref * oDataSet,
                                                               CATListPV& oChildrenNodes) const
{
  // no children in a leaf
  if (oChildrenNodes.Size() != 0) oChildrenNodes.RemoveAll();
}

INLINE const CATMathBox GenericDistanceOper_SingleElementNode::GetBox() const {
  return _ElementInNode.Box();
}

// Class GenericDistanceOper_Voxel
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

INLINE GenericDistanceOper_Voxel::GenericDistanceOper_Voxel(const double iRefBoxSqDistance,
                                                     const CATPolyVoxelOctreeNode * iTree)
  :
  GenericDistanceOper_Node(iRefBoxSqDistance),
  _Tree(iTree)
{}

INLINE const GenericDistanceOper_Element_ref* GenericDistanceOper_Voxel::GetElement() const
{
  return NULL;
}

// Class GenericDistanceOper_NodeSortedList
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

INLINE GenericDistanceOper_NodeSortedList::GenericDistanceOper_NodeSortedList()
  :
  _List(500,GenericDistanceOper_Node::Compare)
{}
INLINE GenericDistanceOper_NodeSortedList::~GenericDistanceOper_NodeSortedList()
{
  Clean();
}

#endif //CATPolyBodyDistanceGenericLocalClasses_h
