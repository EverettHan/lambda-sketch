// COPYRIGHT DASSAULT SYSTEMES 2021
//=============================================================================

#ifndef CATCDSHashTableWithAssoc_h
#define CATCDSHashTableWithAssoc_h

#include "CATCDSUtilities.h"
#include "CATCDSHashTable.h"

#define CDS_DEFAULT_HASH_TABLE_DIMENSION 31

/**
 * Hash table with associated item stored (equivalent to CATCGMHashTableWithAssoc).
 */
class ExportedByCATCDSUtilities CATCDSHashTableWithAssoc
{
public:

  /**
   * Constructs a CATCDSHashTable.
   * @param iSizeEstimate
   *   The initial estimated size of the hash table.
   * @param iPFH
   *   The given hash function.
   * @param iPFC
   *   The given elemts comparison function.
   */
  CATCDSHashTableWithAssoc(
        int iEstimatedSize = 0,
        PFHash iPFH = CATCDSSimpleHashIt,
        PFCompare iPFC = CATCDSSimpleHashCompare);

  /**
   * Destructor.
   */
  ~CATCDSHashTableWithAssoc();
    
  /**
   * Inserts an element in the table.
   * @param ipElem
   *    Element to insert.
   * @param ipAssoc
   *    Associated element.
   * @return
   *    Return 1 if successful, 0 in case of failure
   */
  int Insert(void* ipElem, void* ipAssoc);

  /**
   * Search for an object in table.
   * @param ipElem
   *    Object to search.
   * @param oppAssoc
   *    A pointer to the associated object (if ipElem is found), 0 otherwise.
   * @return
   *    Object index if found, -1 otherwise.
   */
  int LocateItem(void* ipElem, void** oppAssoc) const;

protected:

  PFHash    _PFH;
  PFCompare _PFC;

  int _NbAllocatedBuckets; // Dimension of the hashtab (maximum number of buckets to be stored in the Hashtable)
  void** _pAllocatedBuckets;  // Address of the allocated memory  
  void** _pFirstFreeBucket;   // Address of the first free bucket

  void* _StaticBuckets[4 * CDS_DEFAULT_HASH_TABLE_DIMENSION];  // Static array (124 = 4 * _NbAllocatedBuckets with _NbAllocatedBuckets = 31) 

  int _NbFreeBuckets;      // Number of free buckets 
  int _NbStoredElems;      // Number of stored elements in the hashtable

  void ReAllocate();

};

#endif // CATCDSHashTableWithAssoc_h


