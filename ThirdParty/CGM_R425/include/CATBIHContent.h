// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBIHContent.h
//
//===================================================================
//
// Usage notes: List that represents the content included in nodes of
// a BIH (see @CATBIHTree).
// The content of the list is sorted along the three axis directions x,
// y and z. Therefore, there are four kinds of indices: the global
// index, the index in the X along sorted list, the index in the Y
// along sorted list and the index in the Z along sorted list.
// A subdivision of the list in two sublists along one direction is
// possible.
//
//===================================================================
//
// 2012-01-16 XXC: Creation
//===================================================================

#ifndef CATBIHContent_h
#define CATBIHContent_h

#include "PolyPathPlanning.h"

#include "CATMathInline.h"
#include "CATBIHNode.h"
#include "CATListPV.h"

class CATBVHTree;
class CATBVHNodeConst;
class CATMathBox;
class CATMathPoint;
class CATIPolyMesh;
class CATMathTransformation;

#define UNSORTEDBIHCONTENT

class ExportedByPolyPathPlanning CATBIHContent
{
public:
  
  /** Constructor of a list from a CATBVHTree.
   *@param iTree: the tree from which the content list is constructed.
   *@param iTolerance: tolerance which is added in every three
   *directions to the limits of each content element.
   *@param iUniqueLevel: if FALSE, the list follows the same hierarchy
   *than the CATBVHTree iTree. If TRUE, it expands the tree then put
   *every leaves content at the same level.
   */
  CATBIHContent(const CATListPV & iPolyBodies, FLOAT iTolerance);

  INLINE void AddRef() {_counter++;}
  INLINE void Release() {
    _counter--;
    if (_counter == 0)
      delete this;
  }

protected:
  CATBIHContent();
  CATBIHContent(CATIPolyMesh * iMesh, const CATMathTransformation * iPosition, FLOAT iTolerance);
  CATBIHContent(CATIPolyMesh * iMesh, const CATMathTransformation * iPosition, const FLOAT iBox[6], FLOAT iTolerance);
  virtual ~CATBIHContent();

  void Flush();

private:
  unsigned int _counter;

public:

  INLINE FLOAT GetTolerance () { return _Tolerance; }
  void SetTolerance(FLOAT iTolerance);

  INLINE unsigned int Size() { Expand(); return _Size; }

  /** Returns the element in the list at position given by the global
   *  index.
   */
  INLINE CATBIHContent * operator [] (unsigned int index) const { return _ContentList[index]; }

#ifndef UNSORTEDBIHCONTENT
  /** For a given index in the sorted list along the given direction,
   *  returns the index of the object in the global list.
   */
  INLINE unsigned int ID(CATBIHNode::PlaneDirection iDir, unsigned int iSortedId) {
    return _Correspondances[iSortedId]._GlobalIndex[iDir];
  }
#endif

  INLINE const FLOAT * GetContentBox() const { return _Box; }
  HRESULT ExtandBox(const FLOAT iBox[6]);

  /** If the content box is larger than the inner content box, return
   *  the content reduced on one side such that the box still contains
   *  all the elements contained in it and fit the inner content box
   *  on this side. If not, try to go to the level below.
   *@param oDir: the direction where the box was reduced to fit the
   *inner content box.
   *@param oContent: the new reduced content. Can be this content.
   *@param oPlaneValue: the value of the new box content.
   *@return 0 if the content box already fit the inner content box and
   *the new content cannot be split anymore. 1 if the content box was
   *reduced on its right side. 2 if the content box was reduced on its
   *left side. -1 if the content was not reduced and the content of
   *the level below is returned.
   */
  virtual char ReduceEmptySpace(CATBIHNode::PlaneDirection & oDir, CATBIHContent *& oContent, FLOAT & oPlaneValue);

  /** Split the content list into two sublist along the given
   *  direction. The result is the same list where the m^th first
   *  elements in all the sorted lists are the ones with the fewest
   *  iDir coordinates and the remaining elements in all the sorted
   *  lists are the ones with the greatest iDir cooridnates (with
   *  m=(start+end)/2 is the middle of the list's size).
   *  The effect is only a rearrangement of the indices in the x, y
   *  and z sorted lists.
   */
  virtual HRESULT SplitAlong(CATBIHNode::PlaneDirection iDir, CATBIHContent *& oLeftContent, FLOAT & oLeftPlane, CATBIHContent *& oRightContent, FLOAT & oRightPlane);

protected:

  virtual CATBIHContent * GetSubContent();
  virtual CATBoolean MergeSublists();

#ifndef UNSORTEDBIHCONTENT
  virtual void GetContentInnerLimits (FLOAT oLimits[6]);
#else
  void GetContentInnerLimits(int iSide, FLOAT & oLimit);
#endif

  virtual CATBIHContent * Copy(const FLOAT newBox[6]);

protected:

  HRESULT GetBoxFromPolyMesh(CATIPolyMesh * iNode, const CATMathTransformation * iPosition, FLOAT oBox[6]);

  virtual void Expand(); 
  virtual void ExpandMesh();
  void ExpandMesh(CATListPV & ioContentList, const CATIPolyMesh & iMesh, const CATMathTransformation & iPosition);
  void ExpandTriangle(CATListPV & ioContentList, const double iTriangle[9]);

#ifndef UNSORTEDBIHCONTENT
/* protected: */

/*   struct HeapShape { */
/*     long int trees; */
/*     unsigned int smallestRank; */
    
/*     HeapShape() */
/*       : trees(0), smallestRank(0) {} */
/*   }; */

/*   /\* void SmoothDisplay(unsigned int axis); *\/ */
/*   void SmoothSort(unsigned int axis); */
/*   INLINE void SmoothTamiser(unsigned int axis, unsigned int pos, unsigned int rank); */
/*   void SmoothRectifyHeaps(unsigned int axis, unsigned int end, HeapShape iShape); */
/*   void SmoothAddValue(unsigned int axis, unsigned int root, unsigned int iSize, HeapShape & ioShape); */
/*   void SmoothRemoveValue(unsigned int axis, unsigned int root, HeapShape & ioShape); */

protected:

  HRESULT GenerateCorrespondances(CATBIHNode::PlaneDirection iDir);
  HRESULT InitContent(unsigned int iPos);
  virtual HRESULT InitContentBox(const FLOAT iBox[6], unsigned int iPos);
  virtual void Sort();
  virtual void Sort(unsigned int axis);

  INLINE unsigned int SortingCondition(unsigned int i, unsigned int j, unsigned int axis) {
    if (_Correspondances[i]._limit[axis] < _Correspondances[j]._limit[axis] || // It is strictly inferior
        (_Correspondances[i]._limit[axis] == _Correspondances[j]._limit[axis] && // Values are equal
         (_Correspondances[i]._what[axis] > _Correspondances[j]._what[axis] || // And i is an object's end and j an object's start
          (_Correspondances[i]._what[axis] == _Correspondances[j]._what[axis] &&
           _Correspondances[i]._GlobalIndex[axis] < _Correspondances[j]._GlobalIndex[axis])))) // Or i index is lower than j index.
      return 1;
    else
      return 0;
  }
  
  INLINE void Tamiser(unsigned int axis, unsigned int pos, unsigned int end)
  {
    int k = pos, j = 2*pos+1;
    
    while (j < end) {
      if (j < (end-1) && SortingCondition(j,j+1,axis))
        j++;
      if (SortingCondition(k,j,axis)) {
        Switch(axis, k, j);
        k = j;
        j = 2*k+1;
      }
      else
        break;
    }
  }
  
  INLINE void Switch(unsigned int axis, unsigned int pos1, unsigned int pos2)
  {
    unsigned int tmpIndex = _Correspondances[pos1]._GlobalIndex[axis];
    char tmpWhat = _Correspondances[pos1]._what[axis];
    FLOAT tmpLimit = _Correspondances[pos1]._limit[axis];
    
    _Correspondances[pos1]._GlobalIndex[axis] = _Correspondances[pos2]._GlobalIndex[axis];
    _Correspondances[pos1]._what[axis] = _Correspondances[pos2]._what[axis];
    _Correspondances[pos1]._limit[axis] = _Correspondances[pos2]._limit[axis];
    
    _Correspondances[pos2]._GlobalIndex[axis] = tmpIndex;
    _Correspondances[pos2]._what[axis] = tmpWhat;
    _Correspondances[pos2]._limit[axis] = tmpLimit;
  }
  
  struct SortData { // For a given direction, represent:
    unsigned int _GlobalIndex[3]; // Index in the global content array
    char _what[3]; // True if the limit correpond to the start of an object, false if it correpsonds to the end
    FLOAT _limit[3]; // Limit of the content bounding box
  };
#endif

protected:
  FLOAT _Box[6]; // X min, X max, Y min, Y max, Z min, Z max

  FLOAT _Tolerance;
  int _Size;
  CATBIHContent ** _ContentList;

#ifndef UNSORTEDBIHCONTENT
  // _Correspondances[id]._GlobalIndex[d] stands for the global index
  // of the element at position id in the d sorted list.
  SortData * _Correspondances;
#endif
  char _Init;

  CATIPolyMesh * _Content;
  const CATMathTransformation * _Position;
};


#endif // CATBIHContent
