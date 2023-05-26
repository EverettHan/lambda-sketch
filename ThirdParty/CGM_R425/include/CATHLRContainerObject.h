/* -*-C++-*-*/
#ifndef CATHLRContainerObject_H
#define CATHLRContainerObject_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRContainerObject 
//
// DESCRIPTION :
/**
 * Container of objects for the HLR. It includes a CATHLRMemoryManager to handle
 * the memory and hash table to retrieve one object from its key.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

// For inheritance
#include "CATHLRContainer.h"

// Other 
#include "CATHLRHashObject.h"

class CATHLRMemoryManager;
class CATGeometry;

class ExportedByHLRModele CATHLRContainerObject : public CATHLRContainer
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor : with an estimated size
 */
  CATHLRContainerObject(CATLONG32  iEstimatedSize = 100);

/**
 * Destructor
 */
  virtual ~CATHLRContainerObject();

//=============================================================================
// OVERRIDDEN METHODS
//=============================================================================
/** Adding an object in the container
 */
  virtual void AddObject(CATHLRObject * iObject);

/** Retrieves an object in the container from its key ( which should be unique
 * in such a container). It returns NULL if not found.
 */
  CATHLRObject * RetrieveObject(unsigned int iKey);
  CATHLRObject * RetrieveObject(void * iGeometry);

/** Getting the memory manager of the container to create some objects in it.
 */
  CATHLRMemoryManager * GetMemoryManager() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Object that handles the memory
  CATHLRMemoryManager * _MemoryManager;

// Hash table to retrieve objects
  CATHLRHashObject    * _HashTable;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
