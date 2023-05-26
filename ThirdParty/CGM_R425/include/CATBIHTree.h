// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBIHTree.h
//
//===================================================================
//
// Usage notes: BIH, Bouding Interval Hierarchy is a hierarchical
// structure to represent intervals between objects. See
// http://ainc.de/Research/BIH.pdf or
// http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.87.4612 for
// more details.
//
//===================================================================
//
// 2012-01-12 XXC: Creation
//===================================================================

#ifndef CATBIHTree_h
#define CATBIHTree_h

#define FLOAT double


#include "PolyPathPlanning.h"

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMathInline.h"

class CATBIHNode;
class CATBIHContent;
class CATBVHTree;
class CATMathBox;

class ExportedByPolyPathPlanning CATBIHTree {

 public:

  /** The way the hierarchy is built.
   * OnDemand: the hierarchy below a node is unfolded only when its left or right subnode is get.
   * OnTheFly: the hierarchy is fully unfolded to its lowest level (deepest nodes) directly when the building is called.
   */
  enum BIHBuildPattern {
    OnDemand = 0 ,
    OnTheFly = 1 ,
  };

 public:

  /** Constructor. The tree iTree is AddRefed by the BIH.
   */
  CATBIHTree ();
  virtual ~CATBIHTree ();

  /** Construct the BIH. After the call to this function, the root of
   *  the BIH can be get.
   *@param iPattern: Ask the BIH nodes to be constructed on demand
   *(i.e. a node is expanded when one ask for one of its sons, value
   *OnDemand) or immediately (all the tree is expanded until the
   *leaves, value OnTheFly)
   *@param iTolerance: the distance to object a space is considered as free.
   */
  HRESULT Build (CATBIHContent * iContent, BIHBuildPattern iPattern);

  INLINE CATBIHNode * GetRoot () { return _Root; }
  INLINE const CATBIHNode * GetRoot () const { return _Root; }

  INLINE const FLOAT * GetGlobalBox() { return _GlobalBox; }

 protected:

  void Vanish ();

  void ExpandAll (CATBIHNode * iNode);

  virtual CATBIHNode * CreateRoot(CATBIHContent * iContent);

 private:
  friend class CATBIHNode;

  FLOAT _GlobalBox[6];
  CATBIHNode * _Root;
};

#endif // CATBIHTree_h
