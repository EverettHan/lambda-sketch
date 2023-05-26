/**
 * @level Private
 * @usage U1
 */
#ifndef __CATOmxBaseOMap_H
#define __CATOmxBaseOMap_H

#include <stddef.h>
#include "CATOmxKernel.h"
#include "CATOmxPortability.h"
#include "CATOmxMapIter.h"

struct CATOmxBaseMapLetter;
struct CATOmxBaseMapNode;
class CATOmxBaseMap;
template<typename Key,typename Value,CATOmxCollecManagerLocator KeyMgr,CATOmxCollecManagerLocator ValueMgr >
class CATOmxOMap;

namespace CATOmx {
  /** 
   * ForWrite make a copy of collection if not Mutable
   * AllowSideEffect make a copy of collection if not Mutable and not only referenced by Iterators.
   */
  enum LocatePolicy { ForGet, ForWrite, AllowSideEffect };
};

struct ExportedByCATOmxKernel CATOmxMapContext 
{
    void *Key;
    void *Value;
    const CATOmxCollecManager* KeyMgr;
    const CATOmxCollecManager* ValueMgr;
    unsigned int m_flags;
    const unsigned int m_valueOffset;

    CATOmxMapContext(const CATOmxCollecManager *iKeyMgr, const CATOmxCollecManager *iValueMgr,size_t iValueOffset);
    CATOmxMapContext(CATOmxCollecManagerLocator iKeyMgr,CATOmxCollecManagerLocator iValueMgr,size_t iValueOffset,const void *iKey = NULL, const void *iValue = NULL );

    CATBoolean remove(CATOmxBaseMapNode *&iItem);
    CATBoolean removeChildren(CATOmxBaseMapNode *&iItem,CATOmxBaseMapNode *&iOther); 
    CATBoolean remove_status() const;
    /* stick the replace mode */ 
    void replace_mode();
    CATBoolean insert(CATOmxBaseMapNode *&iItem);
    CATBoolean insert_status() const;
    void* locate(CATOmxBaseMapNode *iItem);
    const void* locate_nearest(const CATOmxBaseMapNode *iItem,unsigned int relation) const;
    CATOmxMapIterContext *new_iterator(CATOmxBaseMapLetter *letter);
    CATBoolean insert(CATOmxBaseMapLetter *&letter);
};

/**
 * A template map
 * Inserted key and value are managed according to the provided collec manager
 * The collection use the Compare method to sort Key
 * .
 * Implementation note: 
 * - this class implement an AVL tree insert/remove/locate operation:
 *  1.5 * O(log2(n))
 * - Memory cost per insert item 4*pointer. 
 */
class ExportedByCATOmxKernel CATOmxBaseMap 
{
  friend class CATOmxBaseMapIter;
protected:  
  CATOmxBaseMapLetter *letter;

  CATOmxBaseMap(CATOmxCollecManagerLocator iKeyMgr,CATOmxCollecManagerLocator iValueMgr,size_t iValueOffset,const CATOmxBaseMap &iFrom);
  CATOmxBaseMap(CATOmxCollecManagerLocator iKeyMgr,CATOmxCollecManagerLocator iValueMgr,unsigned int iKeySize, unsigned int iValueSize);

  ~CATOmxBaseMap();

  /**
   * Insert an item in map.
   * @return true if newly inserted
   */
  CATBoolean Insert(CATOmxMapContext &iContext);
  /**
   * Insert or replace an item in map.
   * @return true if newly inserted
   */
  CATBoolean Replace(CATOmxMapContext &iContext);

  void* Require(CATOmxMapContext &iContext);
  /**
   * Locate an item in map.
   * @param iContext the context
   * @return the item or NULL
   */
  void* Locate(CATOmxMapContext &iContext, CATOmx::LocatePolicy iPolicy) const;
  /** @nodoc TODO remove after delivery in BSF */
  void* Locate(CATOmxMapContext &iContext) const;
 
  const void* LocateNearest(CATOmxMapContext &iContext,unsigned int relation) const;

  /**
   * Remove an item in map .
   * @param iKey the key
   * @return true if key is found and the item is removed
   */
  CATBoolean Remove(CATOmxMapContext &iContext);
  /**
   * Remove all items in map. 
   */
  void RemoveAll(CATOmxMapContext &iContext);

  /**
   * Clone map.
   */
  void Clone(CATOmxMapContext &iContext,const CATOmxBaseMap& iMap);
  /** Share two map is a COW fashion. */
  void Share(CATOmxMapContext &iContext,const CATOmxBaseMap& iMap);

  int IsEqual(CATOmxMapContext &iContext,const CATOmxBaseMap& iMap) const;
public:  
  /**
   * Return true if map contain nothing.
   */
  CATBoolean IsEmpty() const ;
  /**
   * @deprecated
   * Compute the size of the map.
   * O(n) algorithm
   */
  unsigned int ComputeSize() const;
  /** return the number of item in collection */
  unsigned int Size() const ;
};

#endif
