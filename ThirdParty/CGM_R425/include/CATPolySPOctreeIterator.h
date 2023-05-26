// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySPOctreeIterator.h
// Header definition of CATPolySPOctreeIterator
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2006 Creation: ndo
//===================================================================
#ifndef CATPolySPOctreeIterator_H
#define CATPolySPOctreeIterator_H

#include "CATPolySpatialPartitions.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATPolySPOctreeMemoryManager;
class CATPolySPOctreePartition;
class CATPolySPOctreePath;
class CATPolySPOctreeNode;
class CATPolySPOctreeLeaf;
class CATHTableOfIntInt;


class ExportedByCATPolySpatialPartitions CATPolySPOctreeIterator
{

public :

  CATPolySPOctreeIterator (CATPolySPOctreePartition* iPartition0, CATPolySPOctreePartition* iPartition1);

  ~CATPolySPOctreeIterator ();

  HRESULT Reset ();

  CATBoolean NextTrianglePair (int& oTriangle0, int& oTriangle1);

  // Recursive method collecting the triangles under a node of an octree.
  // The output array must have been allocated before calling the method.
  // The size of the output array should be greater or equal than the number of triangles in the node.
  static HRESULT GetTriangles (const CATPolySPOctreeNode* iNode, // Node with triangles to collect from the children.
                               CATPolySPOctreeMemoryManager* iMemManager, // Memory manager for internal use.
                               int* oTriangles);           // Array for the node triangles (to be filled in.)

protected :

  void ResetTriangleArrays ();

  HRESULT SetPartitions (CATPolySPOctreePartition* iPartition0, CATPolySPOctreePartition* iPartition1);

  // Two paths for the two partitions are equivalent if their deepest elements have the same octo-cube.
  // The path pair iterator finds all equivalent paths that lead to at least to a leaf in each pair.

  // Return the first pair of equivalent paths.
  static CATBoolean FirstPathPair (CATPolySPOctreePath& oPath0, CATPolySPOctreePath& oPath1);

  // Return the next pair of equivalent paths.
  static CATBoolean NextPathPair (CATPolySPOctreePath& oPath0, CATPolySPOctreePath& oPath1);

  // Return the number of triangles from the path element and return this path element (a node or a leaf).
  static int GetNbTriangles (const CATPolySPOctreePath* iPath, 
                             CATPolySPOctreeNode*& oNode, CATPolySPOctreeLeaf*& oLeaf);

  HRESULT FetchTriangles (const CATPolySPOctreeNode* iNode, const int iNbTriangles, int*& ioTriangles) const;
  HRESULT FetchTriangles (const CATPolySPOctreeLeaf* iLeaf, int*& ioTriangles) const;

private :

  // No implementation of copy constructor and operator =.
  CATPolySPOctreeIterator (CATPolySPOctreeIterator& iOther) ;
  CATPolySPOctreeIterator& operator = (CATPolySPOctreeIterator& iOther) ;

  // Octree partitions for the two meshes.
  CATPolySPOctreePartition* _Partitions[2];

  // Paths into the octree iterating through equivalent elements.
  CATPolySPOctreePath* _Path[2];

  // Arrays of triangles currently being iterated through.
  int* _Triangles[2];
  int _NbTriangles[2];
  int _IndexTriangle[2];

  // Arrays allocated in the iterator by the memory manager.
  int* _TrianglesMM[2];
  int _NbTrianglesMM[2];

  // Hash table of triangle pairs returned by the iterator.
  CATHTableOfIntInt* _TrianglePairs;

  // Memory manager for allocation/deallocation of triangle arrays.
  CATPolySPOctreeMemoryManager* _MemoryManager;

};


#endif
