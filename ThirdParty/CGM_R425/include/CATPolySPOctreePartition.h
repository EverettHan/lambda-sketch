// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySPOctreePartition.h
// Header definition of CATPolySPOctreePartition
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2006 Creation: ndo
//===================================================================
#ifndef CATPolySPOctreePartition_H
#define CATPolySPOctreePartition_H

#include "CATPolySpatialPartitions.h"

#include "CATBoolean.h"
#include "CATMathBox.h"

class CATIPolyMesh;
class CATPolySPOctreeMemoryManager;
class CATPolySPOctreeNode;
class CATPolySPOctreeLeaf;
class CATPolySPOctreePath;
class CATMathPoint;
class CATCGMOutput;


class ExportedByCATPolySpatialPartitions CATPolySPOctreePartition
{

public :

  CATPolySPOctreePartition (const CATMathBox& iBox);

  ~CATPolySPOctreePartition ();

  /* 
   * Set the maximum depth allowed in the octree. The maximum depth is a number between 1 and CATPolySPOctreeDefine::MaximumDepth.
   * By default, the maximum depth of the octree is set to CATPolySPOctreeDefine::MaximumDepth.
   */
  HRESULT SetMaximumDepth (const int iMaximumDepth);

  /*
   * Set the mesh into the partition.  The initial bounding box must be set prior to setting the mesh.
   */
  HRESULT SetMesh (const CATIPolyMesh* iMesh);

  /*
   * Returns the bounding box of the mesh partition.
   */
  void GetBoundingBox (CATMathBox& oBox) const;

  /*
   * Returns the depth of the octree.
   */
  int GetDepth () const;

  /*
   * Returns the number of triangles in the mesh partition.
   */
  int GetNbTriangles () const;

  /*
   * Add a triangle to the mesh partition.
   */
  inline HRESULT AddTriangle (const int iTriangle);

  /*
   * Remove a triangle from the mesh partition.
   */
  inline HRESULT RemoveTriangle (const int iTriangle);

  /*
   * Return the memory manager used by the spatial partition.
   */
  CATPolySPOctreeMemoryManager* GetMemoryManager () const;

  /* METHODS FOR FRIEND CLASSES */

  CATPolySPOctreeNode* GetRootNode () const;

  /* FOR DEBUGGING PURPOSES */

  void Print (CATCGMOutput& stream) const;
  HRESULT Check () const;

protected :

  /*
   * Set the initial bounding box for the octree.  The largest dimension of the bounding box prevails 
   * to define a larger cubic bounding box.  The bounding box of the octree has the same minimum corner
   * as the initial bounding box (XMin, YMin, ZMin). Its dimensions along the three axis are equal 
   * (largest dimension of the initial bounding box.)
   */
  HRESULT SetInitialBox (const CATMathBox& iBox);

  // Set the root as a leaf and add the triangles from the mesh to that leaf.
  HRESULT SetRoot ();

  // Compute iteratively the depth of the octree given a node and the depth of the node.
  void GetDepth (CATPolySPOctreeNode* iNode, const int iDepth, int& ioMaxDepthReached) const;

  // Test to determine whether to split a voxel or not.
  // @param iNbTriangles
  //   Number of triangles in the voxel.
  // @param iDepth
  //   Depth of the voxel.
  CATBoolean SplitTest (const int iNbTriangles, const int iDepth) const;

  // Test to determine whether to merge the voxels under the current node or not.
  // @param iNbTriangles
  //   Number of triangles under the node.
  // @param iDepth
  //   Depth of the node.
  CATBoolean MergeTest (const int iNbTriangles, const int iDepth) const;

  // Split a voxel.  The end element of the octree path must be a leaf.
  // The leaf is replaced by a node that is split in eight octo-cubes.
  HRESULT SplitVoxel (CATPolySPOctreePath& iVoxelPath);

  // Merge voxels.  The end element of the octree path must be a node. 
  // The node is replaced by a leaf that combines all the leaves under the node.
  HRESULT MergeVoxels (CATPolySPOctreePath& iVoxelPath);

  // Add or remove a triangle from the partition.
  // If iTriangle is positive, the triangle is added to the partition.  
  // If iTriangle is negative, the triangle is removed from the partition.
  HRESULT ProcessTriangle (const int iTriangle);

  // Split a voxel (iCube).  The leaf is replaced by a node.
  // The definition of the cube associated to the voxel is used to check inclusions of the triangle
  // in the children octo-cubes.  The method returns the node created by the split.
  CATPolySPOctreeNode* SplitRecursively (const double iCube[3][2],  // Definition of the voxel.
                                         const int* iTriangles,     // Triangles contained in the voxel.
                                         const int iNbTriangles,    // Number of triangles in the voxel.
                                         const int iDepth);         // Depth of the voxel.

  // Merge the elements under a node.
  // The method returns the array of triangles under the node.
  int* MergeRecursively (CATPolySPOctreeNode* iNode);    // Node with children to merge.

  // Clear recursively all children under a node.
  // The node is not deleted by this method.
  void ClearRecursively (CATPolySPOctreeNode* iNode);

  // Add a triangle to a node.   This is a recursive method working downwards in the tree.
  // The definition of the cube associated to the node is used to check inclusions of the triangle
  // in the children octo-cubes.
  HRESULT AddRecursively (CATPolySPOctreeNode* iNode, const double iCube[3][2], 
                          const CATMathPoint iPoints[3], const int iTriangle,
                          const int iDepth);

  // Remove a triangle from a node.   This is a recursive method working downwards in the tree.
  // The definition of the cube associated to the node is used to check inclusions of the triangle
  // in the children octo-cubes.
  HRESULT RemoveRecursively (CATPolySPOctreeNode* iNode, const double iCube[3][2], 
                             const CATMathPoint iPoints[3], const int iTriangle,
                             const int iDepth);

  // Adds a triangle to a leaf.  Create a leaf if necessary (when ioLeaf is NULL).
  HRESULT AddTriangle (const int iTriangle, CATPolySPOctreeLeaf*& ioLeaf);

  // Remove a triangle from a leaf.  Delete the leaf if necessary (when ioLeaf is empty).
  HRESULT RemoveTriangle (const int iTriangle, CATPolySPOctreeLeaf*& ioLeaf);

private :

  // No implementation of copy constructor and operator =.
  CATPolySPOctreePartition (CATPolySPOctreePartition& iOther) ;
  CATPolySPOctreePartition& operator = (CATPolySPOctreePartition& iOther) ;

  CATPolySPOctreeMemoryManager* _MemoryManager; // Memory manager for allocation/deallocation of nodes and leaves.
  CATPolySPOctreeNode* _Root;                   // Root of the octree (always a node.)
  int _MaximumDepth;                            // Maximum depth allowed in the octree.  Root has depth 0.

  // Geometry of the spatial partition.

  // Min and max corners of the space that is partitionned.  
  // These corners define a cubic region in space.
  double _Box[3][2];  // [X, Y or Z][Min or Max]

  // Smallest voxel size.  The three dimensions are equal (cubic voxels).
  double _SmallestVoxelSize[3];

  // Mesh associated to this spatial partition.

  const CATIPolyMesh* _Mesh;

  // Error flags.
  CATBoolean _MemoryError; // A flag set to TRUE when a memory error occurs.
};


inline HRESULT CATPolySPOctreePartition::AddTriangle (const int iTriangle)
{
  return ProcessTriangle (iTriangle);
}


inline HRESULT CATPolySPOctreePartition::RemoveTriangle (const int iTriangle)
{
  return ProcessTriangle (-iTriangle);
}


#endif
