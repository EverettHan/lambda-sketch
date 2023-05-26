//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/08/13
//===================================================================
// IndexHashMap.h
// Header definition of class IndexHashMap
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/08/13 Creation: Code generated by the 3DS wizard  VV6
//===================================================================

#ifndef IndexHashMap_H
#define IndexHashMap_H

// VisuImmersiveDialog framework
#include <CATVidMdlIndex.h>

// UIVCoreTools framework
#include <CATSYPHashMap.h>

/**
 * Struct which defines the hash method to use for the expanded indexes hash map.
 */
struct IndexHashMap
{
  int ComputeHash(const CATVidMdlIndex &i_key){
    return CATSYPHashMapPointerHasherCompute(i_key.GetStoredItem());
  }
};

#endif