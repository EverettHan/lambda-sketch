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

#ifndef CATPolyBodyDistanceMinGenericLocalClasses_h
#define CATPolyBodyDistanceMinGenericLocalClasses_h

#include "CATPolyDistanceOperators.h"
#include "CATMathBox.h"
#include "CATBoolean.h"
#include "CATListPV.h"
#include "CATTolerance.h"
#include "CATHeap.h"
#include "CATDataType.h"

class CATPolyVoxelOctreeNode;
class CATPolyBodyDistanceMinGeneric;
class GenericDistanceMinOper_DataSet;

/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
/* CATPolyBodyDistanceMinGeneric LOCAL CLASSES        */
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/

/** Class Distance: defines the notion of distance. Only depends on
 *  the implementation of the distance operator. Can be a scalar or
 *  a scalar field, with other data.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_Distance
{
public:
  inline GenericDistanceMinOper_Distance();
  virtual ~GenericDistanceMinOper_Distance(){};

  /** Get the scalar distance stored in the Distance instance,
   *  corresponding to the distance between two element, one in the
   *  first Set, the other in the second Set.
   *@param the distance _Distance
   */
  inline double GetCeilingDistance();
protected:
  double _Distance;
};

/** Abstract class which defines an element of a
 *  set. Implementations of the generic distance operator must
 *  provide a classinherited from this one to define specifically
 *  the elements of the first set S1.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_Element
{
public:
  inline GenericDistanceMinOper_Element();
  virtual ~GenericDistanceMinOper_Element(){}
  /** Gets the box bounding the element. Only depends on the
   *  implementation.
   */
  virtual const CATMathBox & Box() const = 0;
  /** Define the index of the element in the set. This method is
   *  called only once by the initiliazer of the set DataSet,
   *  which know chich index to apply to each of its element (in
   *  other words, DO NOT INITIALIZE IT BY YOURSELF). The index is
   *  unique and used in the local class Marks to
   *  record which elements has been explored during the distance
   *  computation process. See this class for details.
   *@param iIndex: the index to set to the element.
   */ 
  inline void InitIndex(const int iIndex);
  /** Gets the index of the element in the set.
   *@return the index of the element.
   */
  inline int GetIndex() const;
private:
  int _Index;
};

/** Class used to mark every couple of elements of the two sets, using
 *  their index (given by the method Element::GetIndex()) in the
 *  set. The mark is used to indicate that the distance between an
 *  element in the first set and an element in the second set has
 *  already been computed. This is usefull to avoid multiple element
 *  to element distance computation with the same elements, in the
 *  case the option _AllowElementsInMultipleVoxels is set to
 *  true.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_Marks
{
 public:
  /** Marks constructor.
   *@param iNbMarks: the cardinal of the second set, i.e. the
   *number of marks to store.
   */
  inline GenericDistanceMinOper_Marks(int iNbMark1, int iNbMark2);
  inline ~GenericDistanceMinOper_Marks();
  /** Unset every mark.
   */
  void UnmarkAll();

  /** Set a mark for the couple of elements with the given indexes.
   *@param iIndex1: index of the element to mark in the first set.
   *@param iIndex2: index of the element to mark in the second set.
   */
  inline void SetMarked(int iIndex1, int iIndex2);
  /** Indicate if the couple of element with the given indexes is
   *  marked or not.
   *@param iIndex1: index of the element to mark in the first set.
   *@param iIndex2: index of the element to mark in the second set.
   *@return TRUE if the element is marked, FALSE if it is not.
   */
  inline CATBoolean IsMarked(int iIndex1, int iIndex2);
 private:
  static const int _Corresp[8];
  char * _Marks;
  CATULONG64 _NbMark1;
  CATULONG64 _NbMark2;
};

/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
/* CATDistanceMinGeneric PRIVATE LOCAL CLASSES      */
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/

class GenericDistanceMinOper_Node;
/** Class NodeSortedList. Allows to easily store and sort the nodes
 *  of a voxel tree that must be explored in order to compute the
 *  minimal distance between every element of the first set and the
 *  second set. Works as a chained list, in order to easily insert
 *  elements in the list.
 */
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_NodeSortedList
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
  inline GenericDistanceMinOper_NodeSortedList();
  /** Destructor, empties the list, delete cells and remove a
   *  reference on the nodes contained in the cells, via the cell
   *  destructor.
   */
  inline ~GenericDistanceMinOper_NodeSortedList();
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
  HRESULT Pop(const double iCeilingSqDist, GenericDistanceMinOper_Node*& oNode);
  /** Empties the list and erases all its cells. Remove a reference
   *  on the nodes contained in the cells via the cell destructor.
   */
  void Clean();

private:
  CATHeap _List;
};

/* Generic NODES
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
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
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_Node
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
  virtual HRESULT GetChildren(const double iCeilingSqDist, CATListPV& oChildrenNodes,
                              const GenericDistanceMinOper_DataSet * oDataSet1,
                              const GenericDistanceMinOper_DataSet * oDataSet2) const = 0;

  /** Get the elements contained in the node, if any.
   *@param oElt1: the element of the first set contained in the node.
   *@param oElt2: the element of the second set contained in the node.
   */
  virtual void GetElements(const GenericDistanceMinOper_Element *& oElt1,
                           const GenericDistanceMinOper_Element *& oElt2) const = 0;

  /** Gets the square distance between the two elements/voxels in the
   *  node.
   */
  inline double GetSquareDistance();

  /** Compare two nodes according to the stored distance between the
   *  two elements contained in them.
   *@param op2: the second node to compare to the cell (*this).
   *@return TRUE if (*this) <= op2, FALSE otherwise.
   */
  inline int operator <= (const GenericDistanceMinOper_Node & op2);

  virtual ~GenericDistanceMinOper_Node(){}

protected:
  inline GenericDistanceMinOper_Node(const double iRefSqDistance);

public:
  /** Method used to sort two cells between each others.
   *@return -1 if Node1 <= Node2, +1 if Node1 > Node2, 0 if at least
   *one of the two nodes is NULL.
   */
  static inline int Compare(const void * Node1, const void * Node2);

public:
  double _CompDistance;
};

/* Element/Element NODES
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_ElementElementNode : public GenericDistanceMinOper_Node
{
public:
  /** Constructor of the class.
   *@param iElement: the element inserted into the voxel tree and
   *which the node will contain.
   */
  inline GenericDistanceMinOper_ElementElementNode(const double iRefBoxSqDistance,
                                                   const GenericDistanceMinOper_Element& iElt1,
                                                   const GenericDistanceMinOper_Element& iElt2);
  /** Since a node containing an element has no children, this
   *  method return an emptied list.
   */
  inline HRESULT GetChildren(const double iCeilingSqDist, CATListPV& oChildrenNodes,
                             const GenericDistanceMinOper_DataSet * oDataSet1,
                             const GenericDistanceMinOper_DataSet * oDataSet2) const;
  /** Get the elements contained in the node, if any.
   *@param oElt1: the element of the first set contained in the node.
   *@param oElt2: the element of the second set contained in the node.
   */
  inline virtual void GetElements(const GenericDistanceMinOper_Element *& oElt1,
                                  const GenericDistanceMinOper_Element *& oElt2) const;
protected:
  const GenericDistanceMinOper_Element& _Element1;
  const GenericDistanceMinOper_Element& _Element2;
};

/* Element/Voxel NODES
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_ElementVoxelNode : public GenericDistanceMinOper_Node
{
public:
  /** Constructor of the class.
   *@param iElement: the element inserted into the voxel tree and
   *which the node will contain.
   */
  inline GenericDistanceMinOper_ElementVoxelNode(const double iRefSqDistance,
                                                 const GenericDistanceMinOper_Element& iElt1,
                                                 const CATPolyVoxelOctreeNode * iTree2);
  /** Since a node containing an element has no children, this
   *  method return an emptied list.
   */
  HRESULT GetChildren(const double iCeilingSqDist, CATListPV& oChildrenNodes,
                      const GenericDistanceMinOper_DataSet * oDataSet1,
                      const GenericDistanceMinOper_DataSet * oDataSet2) const;
  /** Get the elements contained in the node, if any.
   *@param oElt1: the element of the first set contained in the node.
   *@param oElt2: the element of the second set contained in the node.
   */
  inline virtual void GetElements(const GenericDistanceMinOper_Element *& oElt1,
                                  const GenericDistanceMinOper_Element *& oElt2) const;
protected:
  const GenericDistanceMinOper_Element& _Element1;
  const CATPolyVoxelOctreeNode * _Tree2;
};

/* Voxel/Element NODES
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_VoxelElementNode : public GenericDistanceMinOper_Node
{
public:
  /** Constructor of the class.
   *@param iElement: the element inserted into the voxel tree and
   *which the node will contain.
   */
  inline GenericDistanceMinOper_VoxelElementNode(const double iRefSqDistance, const CATPolyVoxelOctreeNode * iTree1,
                                                 const GenericDistanceMinOper_Element& iElt2);
  /** Since a node containing an element has no children, this
   *  method return an emptied list.
   */
  HRESULT GetChildren(const double iCeilingSqDist, CATListPV& oChildrenNodes,
                      const GenericDistanceMinOper_DataSet * oDataSet1,
                      const GenericDistanceMinOper_DataSet * oDataSet2) const;
  /** Get the elements contained in the node, if any.
   *@param oElt1: the element of the first set contained in the node.
   *@param oElt2: the element of the second set contained in the node.
   */
  inline virtual void GetElements(const GenericDistanceMinOper_Element *& oElt1,
                                  const GenericDistanceMinOper_Element *& oElt2) const;
protected:
  const CATPolyVoxelOctreeNode * _Tree1;
  const GenericDistanceMinOper_Element& _Element2;
};

/* Voxel/Voxel NODES
/*¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤*/
class ExportedByPolyhedralDistanceOperators GenericDistanceMinOper_VoxelVoxelNode : public GenericDistanceMinOper_Node
{
public:
  /** Constructor of a Voxel.
   *@param iTree: A reference to the voxel in the voxel tree
   *@param iVoxelNumber: the number of that voxel in the tree.
   */
  inline GenericDistanceMinOper_VoxelVoxelNode(const double iRefSqDistance,
                                               const CATPolyVoxelOctreeNode * iTree1,
                                               const CATPolyVoxelOctreeNode * iTree2);
  /** Gets nodes containing the elements and other voxels contained
   *  in the voxel represented by the node.
   *@param oChildrenNodes: a (out) list containing the nodes under
   *the current one in the tree hierarchy.
   */
  HRESULT GetChildren(const double iCeilingSqDist, CATListPV& oChildrenNodes,
                      const GenericDistanceMinOper_DataSet * oDataSet1,
                      const GenericDistanceMinOper_DataSet * oDataSet2) const;
  /** Get the elements contained in the node, if any.
   *@param oElt1: the element of the first set contained in the node.
   *@param oElt2: the element of the second set contained in the node.
   */
  inline virtual void GetElements(const GenericDistanceMinOper_Element *& oElt1,
                                  const GenericDistanceMinOper_Element *& oElt2) const;

private:
  const CATPolyVoxelOctreeNode * _Tree1;
  const CATPolyVoxelOctreeNode * _Tree2;
};

// _____________________________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
// Inline methods implementation. ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
// _____________________________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

// Class GenericDistanceMinOper_Distance
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
GenericDistanceMinOper_Distance::GenericDistanceMinOper_Distance()
  :
  _Distance(CATGetDefaultTolerance().Infinite())
{}

double GenericDistanceMinOper_Distance::GetCeilingDistance(){
  return _Distance;
}

// Class GenericDistanceMinOper_Element
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
GenericDistanceMinOper_Element::GenericDistanceMinOper_Element()
  :
  _Index(-1)
{}

void GenericDistanceMinOper_Element::InitIndex(const int iIndex)
{
  if (_Index == -1)
    _Index = iIndex;
}

int GenericDistanceMinOper_Element::GetIndex() const
{
  return _Index;
}

// Class GenericDistanceMinOper_DataSet::Marks
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

GenericDistanceMinOper_Marks::GenericDistanceMinOper_Marks(int iNbMark1, int iNbMark2)
  :
  _NbMark1(iNbMark1),
  _NbMark2(iNbMark2)
{
  CATULONG64 size = ((_NbMark1*_NbMark2)/8) + 1;
  if (size < 1e20) {
    _Marks = (char*)calloc(1,(size_t)size);
  }
  else
    _Marks = NULL;
  UnmarkAll();
}

GenericDistanceMinOper_Marks::~GenericDistanceMinOper_Marks()
{
  if (_Marks) {
    free (_Marks);
    _Marks = NULL;
  }
}

void GenericDistanceMinOper_Marks::SetMarked(int iIndex1, int iIndex2)
{
  if (_Marks) {
    CATULONG64 index = (iIndex1*_NbMark2) + iIndex2,
      index_div8 = index/8;
    _Marks[index_div8] = _Marks[index_div8] | _Corresp[index%8];
  }
}

CATBoolean GenericDistanceMinOper_Marks::IsMarked(int iIndex1, int iIndex2)
{
  CATBoolean result = FALSE;
  if (_Marks) {
    CATULONG64 index = (iIndex1*_NbMark2) + iIndex2;
    result = ((_Marks[index/8] & _Corresp[index%8]) ? TRUE : FALSE);
  }
  return result;
}

// Class GenericDistanceMinOper_Node
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

GenericDistanceMinOper_Node::GenericDistanceMinOper_Node(const double iRefSqDistance)
  :
  _CompDistance(iRefSqDistance)
{}

double GenericDistanceMinOper_Node::GetSquareDistance()
{
  return _CompDistance;
}

int GenericDistanceMinOper_Node::operator <= (const GenericDistanceMinOper_Node & op2)
{
  return (this->_CompDistance <= op2._CompDistance);
}

int GenericDistanceMinOper_Node::Compare(const void * Node1, const void * Node2)
{
  return (!(Node1 && Node2))
    ? 0
    : (((const GenericDistanceMinOper_Node*)Node1)->_CompDistance < ((const GenericDistanceMinOper_Node*)Node2)->_CompDistance)
       ? -1
       :  1;
}

// Class GenericDistanceMinOper_ElementElementNode
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

GenericDistanceMinOper_ElementElementNode::GenericDistanceMinOper_ElementElementNode(const double iRefSqDistance,
                                                                                     const GenericDistanceMinOper_Element& iElt1,
                                                                                     const GenericDistanceMinOper_Element& iElt2)
  :
  GenericDistanceMinOper_Node(iRefSqDistance),
  _Element1(iElt1),
  _Element2(iElt2)
{}

void GenericDistanceMinOper_ElementElementNode::GetElements(const GenericDistanceMinOper_Element *& oElt1,
                                                            const GenericDistanceMinOper_Element *& oElt2) const
{
  oElt1 = &_Element1;
  oElt2 = &_Element2;
}

HRESULT GenericDistanceMinOper_ElementElementNode::GetChildren(const double iCeilingSqDist,
                                                               CATListPV& oChildrenNodes,
                                                               const GenericDistanceMinOper_DataSet * oDataSet1,
                                                               const GenericDistanceMinOper_DataSet * oDataSet2) const
{
  // no children in a leaf
  if (oChildrenNodes.Size() != 0) oChildrenNodes.RemoveAll();
  return S_FALSE;
}

// Class GenericDistanceMinOper_ElementVoxelNode
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

GenericDistanceMinOper_ElementVoxelNode::GenericDistanceMinOper_ElementVoxelNode(const double iRefSqDistance,
                                                                                 const GenericDistanceMinOper_Element& iElt1,
                                                                                 const CATPolyVoxelOctreeNode * iTree2)
  :
  GenericDistanceMinOper_Node(iRefSqDistance),
  _Element1(iElt1),
  _Tree2(iTree2)
{}

void GenericDistanceMinOper_ElementVoxelNode::GetElements(const GenericDistanceMinOper_Element *& oElt1,
                                                          const GenericDistanceMinOper_Element *& oElt2) const
{
  oElt1 = &_Element1;
  oElt2 = NULL;
}

// Class GenericDistanceMinOper_VoxelElementNode
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

GenericDistanceMinOper_VoxelElementNode::GenericDistanceMinOper_VoxelElementNode(const double iRefSqDistance,
                                                                                 const CATPolyVoxelOctreeNode * iTree1,
                                                                                 const GenericDistanceMinOper_Element& iElt2)
  :
  GenericDistanceMinOper_Node(iRefSqDistance),
  _Tree1(iTree1),
  _Element2(iElt2)
{}

void GenericDistanceMinOper_VoxelElementNode::GetElements(const GenericDistanceMinOper_Element *& oElt1,
                                                          const GenericDistanceMinOper_Element *& oElt2) const
{
  oElt1 = NULL;
  oElt2 = &_Element2;
}

// Class GenericDistanceMinOper_VoxelVoxelNode
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

GenericDistanceMinOper_VoxelVoxelNode::GenericDistanceMinOper_VoxelVoxelNode(const double iRefSqDistance,
                                                                             const CATPolyVoxelOctreeNode * iTree1,
                                                                             const CATPolyVoxelOctreeNode * iTree2)
  :
  GenericDistanceMinOper_Node(iRefSqDistance),
  _Tree1(iTree1),
  _Tree2(iTree2)
{}

void GenericDistanceMinOper_VoxelVoxelNode::GetElements(const GenericDistanceMinOper_Element *& oElt1,
                                                        const GenericDistanceMinOper_Element *& oElt2) const
{
  oElt1 = oElt2 = NULL;
}

// Class GenericDistanceMinOper_NodeSortedList
// _______________________________________________________________
// ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

GenericDistanceMinOper_NodeSortedList::GenericDistanceMinOper_NodeSortedList()
  :
  _List(500,GenericDistanceMinOper_Node::Compare)
{}

GenericDistanceMinOper_NodeSortedList::~GenericDistanceMinOper_NodeSortedList()
{
  Clean();
}

#endif //CATPolyBodyDistanceMinGenericLocalClasses_h
