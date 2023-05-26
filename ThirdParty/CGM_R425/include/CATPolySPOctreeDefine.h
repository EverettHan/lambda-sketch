// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySPOctreeDefine.h
// Header definition of CATPolySPOctreeDefine
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// May 2006 Creation: ndo
//===================================================================
#ifndef CATPolySPOctreeDefine_H
#define CATPolySPOctreeDefine_H

#include "CATPolySpatialPartitions.h"

// Define DEBUG_SPOCTREE for debugging purposes only.
// When this is defined, each CATPolySPOctreeNode and CATPolySPOctreeLeaf object bears a unique tag.
//#define DEBUG_SPOCTREE 1

// Within CATPolySPOctreeDefine:
//   - The maximum depth of the octree is defined by: MaximumDepth.
//     (The root of the octree has depth 0.)
//   - The maximum number of voxels along each axis is: MaximumNbVoxelsPerAxis = 2 ** MaximumDepth.
//   - The maximum number of voxels in total is: 8 ** MaximumDepth.

class ExportedByCATPolySpatialPartitions CATPolySPOctreeDefine
{
public:

  enum
  {
    MaximumDepth = 15,                 // Maximum depth of the octree.
    MaximumNbVoxelsPerAxis = 32768     // Maximum number of voxels along each axis: 2 ** MaximumDepth.
  };

  inline static void SetBit (const int iBit0To7, unsigned int& ioBitField);
  inline static void SetBit (const int iBit0To7, unsigned char& ioBitField);
  inline static void ResetBit (const int iBit0To7, unsigned int& ioBitField);
  inline static int IsBitSet (const int iBit0To7, const unsigned int iBitField);

  inline static unsigned int GetBitMask (const int iBit0To7);

protected:

  static const unsigned int _BitMask[8];

};


inline void CATPolySPOctreeDefine::SetBit (const int iBit0To7, unsigned int& ioBitField)
{
  ioBitField |= _BitMask[iBit0To7];
}

inline void CATPolySPOctreeDefine::SetBit (const int iBit0To7, unsigned char& ioBitField)
{
  ioBitField |= _BitMask[iBit0To7];
}

inline void CATPolySPOctreeDefine::ResetBit (const int iBit0To7, unsigned int& ioBitField)
{
  ioBitField &= ~_BitMask[iBit0To7];
}

inline int CATPolySPOctreeDefine::IsBitSet (const int iBit0To7, const unsigned int iBitField)
{
  return iBitField & _BitMask[iBit0To7]; 
}

inline unsigned int CATPolySPOctreeDefine::GetBitMask (const int iBit0To7)
{
  return _BitMask[iBit0To7];
}

#endif
