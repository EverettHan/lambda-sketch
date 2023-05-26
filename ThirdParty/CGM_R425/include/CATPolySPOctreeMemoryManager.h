// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySPOctreeMemoryManager.h
// Header definition of CATPolySPOctreeMemoryManager
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2006 Creation: ndo
//===================================================================
#ifndef CATPolySPOctreeMemoryManager_H
#define CATPolySPOctreeMemoryManager_H

#include "CATPolySpatialPartitions.h"
#include "CATListPV.h"

class CATPolySPOctreeNode;
class CATPolySPOctreeLeaf;


// Define the number of sub-block sizes used for the triangle buffers.
// Sub-block sizes increase by powers of 2 up to the maximum size.
#define POLYSPOCTREE_NUMBER_OF_SUBBLOCK_SIZES 10  // 2 ** 10 = 1024


class ExportedByCATPolySpatialPartitions CATPolySPOctreeMemoryManager
{

public :

  CATPolySPOctreeMemoryManager ();
  ~CATPolySPOctreeMemoryManager ();

  CATPolySPOctreeNode* NewNode ();
  CATPolySPOctreeLeaf* NewLeaf (int* iTriangles, const int iNbTriangles);

  // Return a buffer of size greater or equal than the requested size.
  int* NewTriangleBuffer (const int iNbTriangles);

  // Return the actual size of the buffer given the number of triangles stored in the buffer.
  static int GetTriangleBufferSize (const int iNbTriangles);

  void DeleteNode (CATPolySPOctreeNode* iNode);
  void DeleteLeaf (CATPolySPOctreeLeaf* iLeaf);

  void DeleteTriangleBuffer (int* iTriangleBuffer, const int iSize);

private :

  // No implementation of copy constructor and operator =.
  CATPolySPOctreeMemoryManager (CATPolySPOctreeMemoryManager& iOther) ;
  CATPolySPOctreeMemoryManager& operator = (CATPolySPOctreeMemoryManager& iOther) ;

  void DeleteAllNodes ();
  void DeleteAllLeaves ();
  void DeleteAllTriangleBuffers ();

  // DATA

  CATListPV _BlocksOfNodes;
  CATListPV _BlocksOfLeaves;

  // Triangle buffers are allocated by blocks of 1024 integers.
  // (Larger triangle buffers are allocated dynamically.)
  // Each block is divided in sub-blocks of sizes increasing from 2 to 1024 integers by power of 2:
  //   2, 4, 8, ..., 1024.
  // There are therefore 10 sub-block sizes (defined by POLYSPOCTREE_NUMBER_OF_SUBBLOCK_SIZES).
  CATListPV _BlocksOfTriangleBuffers;
  CATListPV _LargeTriangleBuffers;

  CATPolySPOctreeNode* _BlockNodes;
  CATPolySPOctreeLeaf* _BlockLeaves;

  // The sub-blocks are obtained by subdivision of a block in equal size sub-blocks.
  // There is one pointer for each sub-block size.
  int* _BlockTriangleBuffers[POLYSPOCTREE_NUMBER_OF_SUBBLOCK_SIZES];

  int _IndexNode;
  int _IndexLeaf;

  // Index that points to the current sub-block in a block (for each sub-block size.)
  int _IndexTriangleBuffer[POLYSPOCTREE_NUMBER_OF_SUBBLOCK_SIZES];

  CATListPV _RecycledNodes;
  CATListPV _RecycledLeaves;

  // Pointers to recycled triangle buffers (for each sub-block size.)
  CATListPV _RecycledTriangleBuffers[POLYSPOCTREE_NUMBER_OF_SUBBLOCK_SIZES];

  static const unsigned int _BlockSizeNodes;
  static const unsigned int _BlockSizeLeaves;

  static const unsigned int _NbSubBlockSizes;           // POLYSPOCTREE_NUMBER_OF_SUBBLOCK_SIZES
  static const unsigned int _BlockSizeTriangleBuffers;  // 2 ** POLYSPOCTREE_NUMBER_OF_SUBBLOCK_SIZES

//#ifdef DEBUG_SPOCTREE
  unsigned int _TagOfLastCreatedNode;
  unsigned int _TagOfLastCreatedLeaf;
//#endif

};

#endif

