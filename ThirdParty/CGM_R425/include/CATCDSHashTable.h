// COPYRIGHT DASSAULT SYSTEMES 2013
//=============================================================================
//
// CATCDSHashTable:
//   Generic hash table.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  sep 2013  Creation                                                     D5T
//=============================================================================

#ifndef CATCDSHashTable_H_
#define CATCDSHashTable_H_

#include "CATCDSUtilities.h"

typedef int (*PFCompare)(void*, void*);
typedef unsigned int (*PFHash)(void*);

ExportedByCATCDSUtilities unsigned int CATCDSSimpleHashIt(void * iObj) ;
ExportedByCATCDSUtilities int CATCDSSimpleHashCompare(void * iObj1, void * iObj2);

/**
 * Simple hash table. Element are stored in buckets
 * that correspond to the same hashed value.
 */
class ExportedByCATCDSUtilities CATCDSHashTable 
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
  CATCDSHashTable(
        int iSizeEstimate = 0,
        PFHash iPFH = CATCDSSimpleHashIt,
        PFCompare iPFC = CATCDSSimpleHashCompare);

  /**
   * Destructor.
   */
  ~CATCDSHashTable();
    
  /**
   * Returns the number of stored elements in the hash table.
   */
  int Size() const;
    
  /**
   * Inserts an element in the table.
   * @param iObj
   *    Element to insert.
   * @return
   *    If an element, equal to the given one, already exists in the hashtable, this
   *  method returns it, otherwise it returns the given element. 0 in case of failure.
  */
  void* Insert(void *iObj);
  
  /**
   * Search for an object in table.
   * @param iObj
   *    Object to search for.
   * @return
   *    Object if present in table, 0 if not.
   */
  void* Locate(void *iObj) const;
  
  /**
   * Search for the first object associated with a given key in table.
   * @param iKey
   *    Key to search for.
   * @return
   *    Object if present in table, 0 if not.
   */
  void* GetFirst(unsigned int iKey) const;
  
  /**
   * Access the next element corresponding to the same key of the given object.
   * @param iFrom
   *    A pointer to the origin element.
   * @return
   *    Element next to the origin element with the same key, 0 is none.
   */
  void* GetNext(void* iFrom) const;

  /**
   * Iterate over all table elements.
   * @param ioIterator
   *    A pointer describing current position in internal HashTable structure : must be initialized to null pointer and not be modified after.
   * @return
   *    Next element or a null pointer at the end.
   */
  void* GetNext(void* &ioIterator) const;

  /**
   * Delete and remove all the elements of the hash table.
   */
  template<class T>
  void DeleteAll()
  {
    for (unsigned int i = 0; i < _DimArray; i++) {
      if(_AllocatedZone[i]) {
        CGMHBucket *pBucket = static_cast<CGMHBucket*>(_AllocatedZone[i]);
        do {
          delete static_cast<T>(pBucket->_ptr);
          pBucket = pBucket->_next;
        } while(pBucket);
        _AllocatedZone[i] = 0;
      }
    }
  }

  /**
   * Removes the associated object from the hash table.
   * @param iObj
   *    Object to search for.
   * @return
   *    The removed object if successful, 0 otherwise.
   */
  void* Remove(void *iObj);

  /**
   * Removes all the elements of the hash table.
   */
  void RemoveAll();

  /**
   * internal use only
   */
  static int UpToNiceModulo(int iNum);

  //-------------------
  // A TRIER
  //-------------------
private:
  
  /**
    * Returns the element stored next to the given element.
    */
  void * NextElem(void* iFrom) const;

  /**
    * Returns the element stored in the hash table to the specified index.
    */
  void * Get(int iPos) const;
  
  /**
    * Returns a pointer on the BUCKET containing the associated object 
    * or NULL if object not found.
    */
  void * LocateBucket(void*) const;

  /**
    * Reallocates the hashtable with the specified size.
    * If no size is specified, the dimension of the hashtable is doubled.
    * Returns 0 if successful, -1 in case of failure.
    */
  int ReAllocate(int new_dim = 0) ;
    
private:
  struct CGMHBucket
  {
    void*      _ptr ;
    CGMHBucket* _next ;
  };
  /*
    * Instances of this classes are not copiable. I declare but don't define these, so that
    * the compiler won't generate a default version of them for me, and also so that no one can
    * use them by mistake.
    */
  CATCDSHashTable(const CATCDSHashTable&);
  CATCDSHashTable& operator=(const CATCDSHashTable&);
  
  PFCompare _PFC; // Comparison function
  PFHash _PFH; // Hash function
  void ** _AllocatedZone; // address of the allocated memory  
  unsigned int _DimArray; // dimension of the hashtab (maximum number of bucket to be stored in the Hashtable)
  int _NbObjStocke; // number of bucket stored in the hashtable

  inline void ** NextEmptyBucket() const  // Address of the first free bucket
  { return _AllocatedZone + _DimArray + 2 * _NbObjStocke; }
};

#endif // CATCDSHashTable_H_


