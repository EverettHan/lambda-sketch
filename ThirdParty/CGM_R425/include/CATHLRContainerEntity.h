/* -*-C++-*-*/
#ifndef CATHLRContainerEntity_H
#define CATHLRContainerEntity_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRContainerEntity 
//
// DESCRIPTION :
/**
 * Container of the entities for the HLR's computation.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 1998 JCH Creation            
//
// May  2013 DPS Ajout _DefaultCGMContainer pour gestion propre de la CATTolerance par defaut 
//               pour les entites autres que CATBody (CGR, PolyBody, Model V4 etc...)
//
//=============================================================================

#include "CATDataType.h"
// For Windows NT
#include "HLRModele.h"

// For inheritance
#include "CATHLRContainer.h"

// Other includes
#include "CATHLRListObjects.h"

class CATHLREntity;
class CATHLRObject;
class CATGeoFactory;
class CATTolerance;

class ExportedByHLRModele CATHLRContainerEntity : public CATHLRContainer
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
  CATHLRContainerEntity();

/**
 * Destructor
 */
  virtual ~CATHLRContainerEntity();

//=============================================================================
// METHODS
//=============================================================================
/** Inherited : adding an object in the container
 */
  virtual void AddObject(CATHLRObject * iObject);

//------------------------------------------------------------
// Management methods
//------------------------------------------------------------
/** Deleting all the entities of the container
 */
  void RemoveAllEntities();

//------------------------------------------------------------
// Reading the container
//------------------------------------------------------------

// Preparing all the entities for a computation ( to be used before reading them )
  void PrepareEntities();

// Puts the cursor on the first element to read it
  void GoToFirstEntity();

// Getting the current entity ( returns NULL if the list is exhausted)
  CATHLREntity * GetCurrentEntity();

// Getting an entity from its number from 0 to n-1.
// Returns NULL if the list is exhausted.
  CATHLREntity * GetEntity(int iIdxEntity) const;

// Advance in the list
  void GoToNextEntity();

// To check if the container is empty
  CATLONG32 IsEmpty() const;

// Gets the number of objects in the container.
  CATLONG32 GetCountEntities() const;

  // Get the CATTolerance of the Default CGMFactory to manage entities without Factory (PolyBody etc...)
  const CATTolerance & GetDefaultCGMTolerance();


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  // List of ObjectV4 used to store the entities
  CATHLRListObjects        * _ListEntities;

  // Cursor on the entities
  int                        _IdxCurrentEntity;


private :

  // CATTolerance contextual management
  CATGeoFactory            * _DefaultCGMContainer;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

#endif
