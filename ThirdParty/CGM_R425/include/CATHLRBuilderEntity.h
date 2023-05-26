/* -*-C++-*-*/
#ifndef CATHLRBuilderEntity_H
#define CATHLRBuilderEntity_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRBuilderEntity 
//
// DESCRIPTION :
/**
 * Object made to build an entity of type CATHLREntity from a pointer to void.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Feb. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

// Other includes
#include "CATHLRBodyId.h"
#include "CATHLRBuilderEntityBase.h"
#include "CATHLRComputerBase.h" // define typedef HLRTransparencyFunction

class CATHLRContainerEntity; 
class CATHLREntity; 
class CATHLRTransformation;
class CATSoftwareConfiguration;

class ExportedByHLRModele CATHLRBuilderEntity : public CATHLRBuilderEntityBase
{
public:

//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================

/**
 * Constructor
 */
  CATHLRBuilderEntity();

  /**
 * Destructor
 */
  virtual ~CATHLRBuilderEntity();


//=============================================================================
// METHODS
//=============================================================================

  /** Builds a CATHLREntity from a model object to which a given transformation
  * will be applied.
  * oldest configuration (CGMVersion=0) will be considered if iSoftwareConfig is set to null
  */
  // deprecated, please use BuildEntityInContext
  virtual CATHLREntity * BuildEntity(void                       * iModelObject,
                                     CATHLRBodyId                 iIdentifier,
                                     CATHLRContainerEntity      * iContainer,
                                     const CATHLRTransformation * iTransfoToApply,
                                     CATSoftwareConfiguration   * iSofwareConfig=0,
                                     int iPriorityGroup = 0);


  /** Builds an  EMPTY CATHLREntity from a model object to which a given transformation
  * will be applied.
  * Please, call the CATHLREntity::CompleteBuild method to fill it if needed later
  */
  virtual CATHLREntity * LightBuildEntity(void                       * iModelObject,
		                                      CATHLRBodyId                 iIdentifier,
                                          CATHLRContainerEntity      * iContainer,
                                          const CATHLRTransformation * iTransfoToApply,
                                          CATSoftwareConfiguration   * iSofwareConfig=0,
                                          int iPriorityGroup = 0);

  inline void SetHLRComputerBase(CATHLRComputerBase * iHLComputerBase);


  // Recuperation de la fonction cliente de gestion de la transparence
  HLRTransparencyFunction GetTransparencyFunction();


protected:

  //=============================================================================
  // INTERNAL DATA
  //=============================================================================

  // Pointeur vers le ComputerBase, pour acceder aux infos liees au point d'observation
  CATHLRComputerBase * _HLRComputerBase;

};

// methodes inline
// ===============
inline void CATHLRBuilderEntity::SetHLRComputerBase(CATHLRComputerBase * iHLComputerBase) {
  _HLRComputerBase = iHLComputerBase; }

#endif
