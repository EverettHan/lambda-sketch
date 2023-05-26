/* -*-C++-*-*/
#ifndef CATHLRObjectLinker_H
#define CATHLRObjectLinker_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRObjectLinker 
//
// DESCRIPTION :
/**
 * Object that is able to link an object to an other one according to it adress.
 * <BR> After the AddObject(adress, number), the method Retrieve() returns the
 * given number of -1 if it is not in the table.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Apr. 1998   Jose CHILLAN (jch)    Creation            
// Aout 2003 TPD passage en 64 bits 
//
//=============================================================================

#include "CATDataType.h"

//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "HLRTools.h"

//=============================================================================
// For inheritance and other includes
//-----------------------------------------------------------------------------


//=============================================================================
// Forward declarations
//-----------------------------------------------------------------------------
class CATHLRBlockLinkObject;
class CATHLRLinkObject;

class ExportedByHLRTools CATHLRObjectLinker
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor : with an estimated size of table.
 * <BR> This size if facultative. If it is too small, the object will enlarge
 * it when necessary. The size should as much as possible be a prime number, or
 * have few divisors.
 * <BR> By default, the links is made with a pointer.
 */
  CATHLRObjectLinker(CATLONG32 iEstimatedSize = 97, int iObjectIsPointer = 1);

/**
 * Destructor.
 */
  ~CATHLRObjectLinker();

 /**
 * ReleaseDynamicMemory.
 */
  void ReleaseDynamicMemory();

//=============================================================================
// METHODS
//=============================================================================
/** Associates an object with a given number.
 */
  void Associate(void * iPointerToObject, CATLONGPTR iNumber);

/** Associates an object with another object.
 */
  void Associate(void * iPointerToObject, void * iAssociatedObjcet);

/** Associates an identifier with an object.
 */
  void Associate(CATINTPTR iIdentifier, void * iAssociatedObjcet);

/** Retrieves the number of the object associated to the pointer given.
 */
  CATLONGPTR RetrieveNumber(void * iPointerToObject);

/** Retrieves the object associated to the pointer given.
 */
  void * RetrieveObject(void * iPointerToObject);

/** Retrieves the object associated to the identifier given.
 */
  void * RetrieveObject(CATINTPTR iIdentifier);

//=============================================================================
// INTERNAL METHODS
//=============================================================================
protected:
  static CATLONG32 GetGoodSize(CATLONG32 iSize);

  static inline unsigned int ComputeKey(void * iPointer);

/** Creates a new block.
 */
  void CreateNewBlock();

/** Adds an object in the table.
 */
  void AddLink(CATHLRLinkObject * iAddLink);

/** Retrieves a link from a pointer.
 */
  CATHLRLinkObject * RetrieveLink(void * iPointerOnObject);

/** Updates the buckets.
 */
  void UpdateBuckets();

//=============================================================================
// INTERNAL DATA
//=============================================================================
protected:
  // First block of links
  CATHLRBlockLinkObject * _FirstBlockLink;

  // Current block of links
  CATHLRBlockLinkObject * _CurrentBlockLink;

  // Current link in the block
  CATHLRLinkObject      * _CurrentLink;

  // Array of buckets
  CATHLRLinkObject     ** _Buckets;

  // Number for the modulo ( number of buckets)
  CATLONG32               _CountBuckets;

  // Remaining number of links in the block
  CATLONG32               _CountRemainingLinks;

  // Number of blocks
  CATLONG32               _CountBlocks;

  // Flag for the Key computation
  int                     _ObjectIsPointer;

  // Ratio when an update of the buckets ( number by which the number of buckets
  // is multiplied )
  enum  { UpdateRatio = 3, UpdateThreshold = 5}; 
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline unsigned int CATHLRObjectLinker::ComputeKey(void * Pointer)
{
#ifndef _WINDOWS_SOURCE
// Alignement depends on the system 
  return CATPtrToUINT32(((CATUINTPTR) Pointer) / 4);
#else
  return CATPtrToUINT32(((CATUINTPTR) Pointer) / 8);
#endif
}

    

#endif
