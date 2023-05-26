/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Inheritance
// -----------
// CATVisHashTable
//    
//
//==============================================================================
// Abstract
// --------
// Implementation of a dynamic hash table in which we store 2 values :
//		- the main value on which we compute the key
//		- a second value associated
//
// This class is an adaptation form the System SimpleHashTable
//
//==============================================================================
// Usage
//
// We have an association of 2 datas : a-b.
// Knowing a, we want to find b.
//
// An exemple of usage can be found with CATBodyIdentificator.
//
//==============================================================================
// History
// -------
//     - ??? ??, ????: Created.
//==============================================================================

#ifndef CATVisHashTable_H_
#define CATVisHashTable_H_
#include "SGInfra.h"

typedef      int             (*PFCompare) (void*, void*) ;
typedef      unsigned int    (*PFHash)    (void*) ;

ExportedBySGInfra unsigned  int CATVisHashIt (void*    iObj) ;
ExportedBySGInfra int CATVisHashCompare(void*   iObj1,void*   iObj2);

class ExportedBySGInfra CATVisHashTable
{
public:
  //---------
  // ~tors.
  //---------
  CATVisHashTable(int  SizeEstimate = 0,
                  PFHash iPFH = CATVisHashIt,
		            PFCompare iPFC = CATVisHashCompare);
  ~CATVisHashTable() ;
  
  //--------------------------------
  // Direct handling of elements.
  //------------------------------
  int    Insert(void* ipPtr, void* ipValue);
  void*  Next(void* ipPtr, void*& opValue) const;
  void*  NextWithKey(void*) const;
  void*  Get (int iPos) const;
  
  //-------------------
  // Hashed access.
  //-------------------
  void*  Locate(void* ipPtr, void*& opValue) const ;// Returns pointer on associated object
                                                   // or 0 if object not found.
                                                   // If found, opValue = the associated value
  void*  LocateBucket(void*) const ;         // Returns pointer on BUCKET
                                             // or 0 if object not found.
  void*  KeyLocate(unsigned int iKey) const; // Returns pointer on object,
                                             // or NULL if not found.
  
  void   Remove(void*) ;
  void   RemoveAll() ;
  int    Size() const ; 
  void   PrintStats() const ;
  int    ReAllocate(int new_dim = 0) ;

private:
  PFCompare	_PFC ;
  PFHash	_PFH ;
  static int UpToNiceModulo (int) ;
  
  void** _AllocatedZone ;   // address of the allocated memory  
  int    _DimArray ;        // dimension of the hashtab 
  //(maximum number of bucket to be stored in the Hashtable)
  inline void** NextEmptyBucket() const  // Address of the first free bucket
    { return _AllocatedZone+_DimArray+3*_NbObjStocke ; }
  
  int    _NbObjStocke ;    // number of bucket stored in the hashtable
};

#endif // CATVisHashTable_H_
