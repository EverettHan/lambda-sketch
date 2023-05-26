// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySPOctreeElement.h
// Header definition of CATPolySPOctreeElement
//
//===================================================================
//
// Usage notes:
// Union between a CATPolySPOctreeNode and a CATPolySPOctreeLeaf.
// 
//===================================================================
//
// May 2006 Creation: ndo
//===================================================================
#ifndef CATPolySPOctreeElement_H
#define CATPolySPOctreeElement_H

#include "CATPolySpatialPartitions.h"

class CATPolySPOctreeNode;
class CATPolySPOctreeLeaf;

// Description of the octree.
//
// The root of the octree is a node which can have eight children nodes.  Each node in the octree 
// corresponds to a cubic region of space.  If the node does not have any children, then it is called
// a leaf and the region of space, a voxel.  Otherwise, the node has eight children nodes for the eight 
// octants of the cubic region. 
//
// The following terminology is used when referring to a cubic region of space.
// - The eight corners of the cube are referred to as corners.
// - The six sides of the cube are referred to as sides.
// - The sides are composed of one or more faces depending on the subdivision of the cube.
// - Two cubes are neighbors if they share a face.
//
// Each level in the octree defines a refinement of space.  The tree is balanced when the dimensions
// of two neighboring voxels differ by at most two. 
//
// Corners, edges and sides of a cube are labelled as follows:
// (See also CATPolySPOctreeNode).
//
//             3-------X37--------7
//            /|    |            /|
//           / | Y1 |           / |
//       Y13/  |____|          /  | 
//         /   |              /|X1| 
//        /    |Z23     ---- / | /|
//       /     |      / Z1  /  |/ |Z67 
//      1--------X15-------5      | 
//      |      |           |      |
//      |      |           |      |
//      |      2-------X26-|------6
//      | /|  / Z0 /       |     /
//   Z01|/ | /____/        |    /             Z
//      |X0|/          ____|   /              /\   Y
//      |  /          |    |  / Y46           |  /
//      | /           | Y0 | /                | /
//      |/            |    |/                 |/
//      0--------X04-------4                  *-------> X


union ExportedByCATPolySpatialPartitions CATPolySPOctreeElement
{

public :

  inline CATPolySPOctreeElement ();

  inline void SetNode (CATPolySPOctreeNode* iNode);
  inline void SetLeaf (CATPolySPOctreeLeaf* iLeaf);

  inline void Clear ();

  inline CATPolySPOctreeNode* GetNode () const;
  inline CATPolySPOctreeLeaf* GetLeaf () const;

  // Computes the child octo-cube from the parent octo-cube.
  static void GetOctoCube (const double iCube[3][2], // Parent cube [X, Y or Z][Min or Max]
                           const int iOctant,        // 0, 1, 2, 3, 4, 5, 6 or 7
                           double oOctoCube[3][2]);  // Child octo-cube [X, Y or Z][Min or Max]

  // Computes the child octo-cube from the parent octo-cube; in-place operation.
  static void GetOctoCube (double ioCube[3][2],      // Parent and child octo-cube [X, Y or Z][Min or Max]
                           const int iOctant);       // 0, 1, 2, 3, 4, 5, 6 or 7

private :

  // Data (Union)
  CATPolySPOctreeNode* _Node;
  CATPolySPOctreeLeaf* _Leaf;

};


inline CATPolySPOctreeElement::CATPolySPOctreeElement () :
  _Leaf (0)
{
}


inline void CATPolySPOctreeElement::SetNode (CATPolySPOctreeNode* iNode)
{
  _Node = iNode;
}


inline void CATPolySPOctreeElement::SetLeaf (CATPolySPOctreeLeaf* iLeaf)
{
  _Leaf = iLeaf;
}


inline void CATPolySPOctreeElement::Clear ()
{
  _Leaf = 0;
}


inline CATPolySPOctreeNode* CATPolySPOctreeElement::GetNode () const
{
  return _Node;
}


inline CATPolySPOctreeLeaf* CATPolySPOctreeElement::GetLeaf () const
{
  return _Leaf;
}


#endif

