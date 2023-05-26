/* -*-C++-*-*/
#ifndef CATHLRFactory_H
#define CATHLRFactory_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRFactory 
//
// DESCRIPTION :
/**
 * Factory for the HLR. A factory contains a pointer on a current transformation
 * that will be associated to all the objects created by it. *
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

class CATHLRContainer;
class CATHLRContainerObject;
class CATHLRMemoryManager;
class CATHLRTransformation;

class ExportedByHLRModele CATHLRFactory
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor with a container in which the created objects will be put.
 */
  CATHLRFactory(CATHLRContainerObject * iAssociatedContainer);

/**
 * Constructor with a container and a memory manager
 */
  CATHLRFactory(CATHLRContainerObject * iAssociatedContainer, 
		CATHLRMemoryManager * iMemoryManager);

/**
 * Destructor
 */
  virtual ~CATHLRFactory();

//=============================================================================
// METHODS
//=============================================================================
/** Sets the transformation that will be applied to all the next created objects
 */
  void SetCurrentTransformation(const CATHLRTransformation * iTransformation);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Container where the created objects are put
  CATHLRContainerObject * _Container;

// Memory manager taken on the container
  CATHLRMemoryManager   * _MemoryManager;

// Current transformation applied to the created objects
  const CATHLRTransformation * _Transformation;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
