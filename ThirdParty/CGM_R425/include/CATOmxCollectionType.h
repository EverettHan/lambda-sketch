#ifndef __CATOmxCollectionType_h__
#define __CATOmxCollectionType_h__
/**
 * Used to manipulate collection type.
 */
enum CATOmxCollectionType {
  /** 0|1 cardinality. */
  omx_single = 0 ,
  /** 0|n cardinality indexed. */
  omx_list = 1,
  /** 0|n cardinality indexed and multidimensional (recursive list). */
  omx_struct,
  /** 0|n cardinality unordered. */
  omx_set
};

#endif

