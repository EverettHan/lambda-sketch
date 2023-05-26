// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySPOctreeNode.h
// Header definition of CATPolySPOctreeNode
//
//===================================================================
//
// Usage notes:
// An octree subdivision of a cube.
//
//===================================================================
//
// May 2006 Creation: ndo
//===================================================================
#ifndef CATPolySPOctreeNode_H
#define CATPolySPOctreeNode_H

#include "CATPolySpatialPartitions.h"

#include "CATBoolean.h"
#include "CATPolySPOctreeElement.h"
#include "CATPolySPOctreeDefine.h"
#include "CATErrorDef.h"  // HRESULT

class CATPolySPOctreeNode;
class CATPolySPOctreeLeaf;

class CATCGMOutput;


//   Indices of corners of the octants:      Octants of the cube bear the index of corner vertices
//                                           as follows:
//
//          8---------17---------26                 3-----------------7
//         /|        /|         /|                 /|                /|
//        / |       / |        / |                / |               / |
//       5---------14---------23 |               /  |              /  |
//      /|  |     /|  |      /|  |              /   |             /   |
//     / |  7----/-|--16----/-|--25            /    |            /    |
//    /  | /|   /  | /|    /  | /|            /     |           /     |
//   2---------11---------20  |/ |           1-----------------5      |
//   |   4-----|---13-----|---22 |           |      |          |      |
//   |  /|  |  |  /|  |   |  /|  |           |      |          |      |
//   | / |  6--|-/-|--15--|-/-|--24          |      2----------|------6
//   |/  | /   |/  | /    |/  | /            |     /           |     /
//   1---------10---------19  |/             |    /            |    /             Z
//   |   3-----|---12-----|---21             |   /             |   /              /\   Y
//   |  /      |  /       |  /               |  /              |  /               |  /
//   | /       | /        | /                | /               | /                | /
//   |/        |/         |/                 |/                |/                 |/
//   0---------9----------18                 0-----------------4                  *-------> X
//
//==============================================================================================================


class ExportedByCATPolySpatialPartitions CATPolySPOctreeNode
{

public :

  CATPolySPOctreeNode ();

  ~CATPolySPOctreeNode ();

#ifdef DEBUG_SPOCTREE
  // For debugging purposes only.
  inline void SetTag (const int iTag);
  inline unsigned int GetTag () const;
#endif

  // Check whether the child is a node or a leaf.
  // See upper right figure for order of the children (index from 0 to 7).
  inline CATBoolean IsChildANode (const int iChildIndex0to7) const;

  HRESULT SetChildNode (const int iChildIndex0to7, CATPolySPOctreeNode* iNode);

  HRESULT SetChildLeaf (const int iChildIndex0to7, CATPolySPOctreeLeaf* iLeaf);

  void ClearChild (const int iChildIndex0to7);

  void Clear ();

  inline CATPolySPOctreeNode* GetChildNode (const int iChildIndex0to7) const;
  inline CATPolySPOctreeLeaf* GetChildLeaf (const int iChildIndex0to7) const;

  // Increment the number of triangles stored under the node.
  inline void AddTriangle ();

  // Decrement the number of triangles stored under the node.
  inline void RemoveTriangle ();

  // Set the number of triangles stored under the node.
  inline void SetNbTriangles (const int iTriangles);

  // Return the number of triangles stored under the node.
  inline int GetNbTriangles () const;

  // For debugging purposes.
  void Print (CATCGMOutput& stream, const int iDepth = 0, int* positions = 0) const;

private :

  // No implementation of copy constructor and operator =.
  CATPolySPOctreeNode (CATPolySPOctreeNode& iOther) ;
  CATPolySPOctreeNode& operator = (CATPolySPOctreeNode& iOther) ;

#ifdef DEBUG_SPOCTREE
  unsigned int _Tag; 
#endif

  struct NodeInfo
  {
    unsigned int _ChildIsANode        :  8; // See upper right figure for order of children.
    unsigned int _WorkArea            : 24;
  };

  CATPolySPOctreeElement _Children[8];  // See upper right figure for order of children.
  NodeInfo _Info;

  int _NbTriangles;  // Number of triangles under the node.

};


#ifdef DEBUG_SPOCTREE
inline void CATPolySPOctreeNode::SetTag (const int iTag)
{
  _Tag = iTag;
}

inline unsigned int CATPolySPOctreeNode::GetTag () const 
{
  return _Tag; 
}
#endif


inline CATBoolean CATPolySPOctreeNode::IsChildANode (const int iChildIndex0to7) const 
{
  return CATPolySPOctreeDefine::IsBitSet (iChildIndex0to7, _Info._ChildIsANode);
}


inline CATPolySPOctreeNode* CATPolySPOctreeNode::GetChildNode (const int iChildIndex0to7) const
{
  return IsChildANode (iChildIndex0to7) ? _Children[iChildIndex0to7].GetNode () : 0;
}


inline CATPolySPOctreeLeaf* CATPolySPOctreeNode::GetChildLeaf (const int iChildIndex0to7) const
{
  return IsChildANode (iChildIndex0to7) ? 0 : _Children[iChildIndex0to7].GetLeaf ();
}


inline void CATPolySPOctreeNode::AddTriangle ()
{
  _NbTriangles++;
}


inline void CATPolySPOctreeNode::RemoveTriangle ()
{
  _NbTriangles--;
}


inline void CATPolySPOctreeNode::SetNbTriangles (const int iTriangles)
{
  _NbTriangles = iTriangles;
}


inline int CATPolySPOctreeNode::GetNbTriangles () const
{
  return _NbTriangles;
}

#endif

