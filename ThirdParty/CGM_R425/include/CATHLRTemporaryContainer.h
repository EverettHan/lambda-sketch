/* -*-C++-*-*/
#ifndef CATHLRTemporaryContainer_H
#define CATHLRTemporaryContainer_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRTemporaryContainer 
//
// DESCRIPTION :
/**
 * Temporary container for the object created by the HLR (silhouettes, etc ...)
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

class CATHLREntity;
class CATHLRMemoryManager;
class CATHLRObject;
class CATHLRTemporaryFactory;
class CATHLRPolyWireLyingOn;

class CATMathTransformation;


class ExportedByHLRModele CATHLRTemporaryContainer : public CATHLRContainer
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor : from a CATHLREntity
 */
  CATHLRTemporaryContainer(CATHLREntity * iEntity);

/**
 * Destructor
 */
  ~CATHLRTemporaryContainer();

//=============================================================================
// METHODS
//=============================================================================
// Overriden method
/** Adds an object in the container
 */
  virtual void AddObject(CATHLRObject * iObjectToAdd);

/** Gets the memory manager of the container
 */
  inline CATHLRMemoryManager * GetMemoryManager() const;
 
/** Gets the factory of the container to create temporary objects
 */
  inline CATHLRTemporaryFactory * GetFactory();

  /** Creates a new empty PolyBod to fill with all silhouette information data
  */    
  CATHLRPolyWireLyingOn * CreateEmptyPolyWireSilhouette(CATMathTransformation * iTransfo);


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  // Object that handles the memory
  CATHLRMemoryManager    * _MemoryManager;
  CATHLRTemporaryFactory * _Factory;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

inline CATHLRTemporaryFactory * CATHLRTemporaryContainer::GetFactory() {
  return _Factory; }

inline CATHLRMemoryManager * CATHLRTemporaryContainer::GetMemoryManager() const {
  return _MemoryManager; }

#endif
