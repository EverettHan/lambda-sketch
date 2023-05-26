/* -*-C++-*-*/
#ifndef CATHLRGeoFactory_H
#define CATHLRGeoFactory_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRGeoFactory 
//
// DESCRIPTION :
/**
 * Geometry factory for the HLR. A factory contains a pointer on a current
 * transformation that will be associated to all the objects created by it.
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
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRFactory.h"

class CATHLRContainer;
class CATHLRContainerObject;
class CATHLRMemoryManager; 
class CATHLRTransformation;

class ExportedByHLRGeometry CATHLRGeoFactory : public CATHLRFactory
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor with a container in which the created objects will be put.
 *
 */
  CATHLRGeoFactory(CATHLRContainerObject * iAssociatedContainer);

/**
 * Constructor from a container and a memory manager
 */
  CATHLRGeoFactory(CATHLRContainerObject     * iAssociatedContainer, 
		   CATHLRMemoryManager * iMemoryManager);

/**
 * Destructor
 */
  virtual ~CATHLRGeoFactory();

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Container where the created objects are put
  CATHLRContainer     * _AssociatedContainer;

// Memory manager taken on the container
// CATHLRMemoryManager * _MemoryManager;

// Current transformation applied to the created objects
  const CATHLRTransformation * _CurrentTransformation;


};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
