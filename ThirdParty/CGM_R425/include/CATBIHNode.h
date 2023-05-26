// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBIHNode.h
//
//===================================================================
//
// Usage notes: BIH, Bouding Interval Hierarchy is a hierarchical
// structure to represent intervals between objects. See @CATBIHTree
// for more details. CATBIHNode describe a node of the CATBIHTree
// hierarchy.
//
//===================================================================
//
// 2012-01-12 XXC: Creation
//===================================================================

#ifndef CATBIHNode_h
#define CATBIHNode_h


#include "PolyPathPlanning.h"

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMathInline.h"

#include "CATBIHTree.h"

#define LEAF 8
#define PARTIALLEAF 4
#define UNBREAKABLE 20

class CATBIHContent;

class ExportedByPolyPathPlanning CATBIHNode
{

 public:

  enum PlaneDirection {
    X = 0,
    Y = 1,
    Z = 2,
    Undefined = 3
  };

 public:

  CATBIHNode (const CATBIHTree & iMembership, CATBIHContent * iList, CATBIHNode * iFather = NULL);
  virtual ~CATBIHNode ();

  INLINE CATBoolean IsLeaf () { Expand(); return (_data & LEAF ? TRUE : FALSE); }

  INLINE CATBIHNode * GetFather () { return _Father; }
  INLINE const CATBIHNode * GetFather () const { return _Father; }

  INLINE CATBIHNode * GetLeftNode () {
    Expand();
    return _LeftNode;
  }
  INLINE CATBIHNode * GetRightNode () {
    Expand();
    return _RightNode;
  }

  INLINE FLOAT GetLeftPlane () {
    Expand();
    return _LeftPlane;
  }
  INLINE FLOAT GetRightPlane () {
    Expand();
    return _RightPlane;
  }

  /** Returns the direction of the planes that split the node in two
   *  subspaces or subnodes. 
   */
  INLINE PlaneDirection GetDirection () {
    Expand();
    return (PlaneDirection) (_data & 3);
  }

  const FLOAT * GetLimits () const;

 protected:

  virtual CATBIHNode * New(const CATBIHTree & iMembership, CATBIHContent * iList, CATBIHNode * iFather);
  virtual void Expand();

  INLINE CATBoolean IsExpanded() {
    return (_Content && (_data | UNBREAKABLE) == (Undefined | UNBREAKABLE) ? FALSE : TRUE);
  }

 private:

  char _data;

 protected:

  // FLOAT _Box[6]; // X min, X max, Y min, Y max, Z min, Z max
  FLOAT _LeftPlane;
  FLOAT _RightPlane;
  CATBIHNode * _LeftNode;
  CATBIHNode * _RightNode;

  CATBIHNode * _Father;
  const CATBIHTree & _Membership;

 private:

  CATBIHContent * _Content;

};

#endif // CATBIHNode_h
