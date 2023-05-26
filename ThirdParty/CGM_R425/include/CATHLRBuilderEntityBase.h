/* -*-C++-*-*/
#ifndef CATHLRBuilderEntityBase_H
#define CATHLRBuilderEntityBase_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2001
//
// CATHLRBuilderEntityBase 
//
// DESCRIPTION :
/**
 * Object made to build an entity of type CATHLREntity from a pointer to void.
 */
//
//=============================================================================
// Abstract Class     : Yes
// Inline Functions   : No
//=============================================================================
//
// History
//
// Nov. 2001   Laurent ALT    Creation            
//
//=============================================================================

// For Windows NT
#include "HLRModele.h"

// Other includes
#include "CATHLRBodyId.h"

class CATHLRContainerEntity; 
class CATHLREntity; 
class CATHLRTransformation;
class CATSoftwareConfiguration;

class ExportedByHLRModele CATHLRBuilderEntityBase
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================

/**
 * Destructor
 */
  virtual ~CATHLRBuilderEntityBase();

//=============================================================================
// METHODS
//=============================================================================

  /** Builds a CATHLREntity from a model object to which a given transformation
  * will be applied.
  * oldest configuration (CGMVersion=0) will be considered if iSoftwareConfig is set to null
  */
  virtual CATHLREntity * BuildEntity(void                        * iModelObject,
		                                 CATHLRBodyId                  iIdentifier,
                                     CATHLRContainerEntity       * iContainer,
                                     const CATHLRTransformation  * iTransfoToApply,
                                     CATSoftwareConfiguration    * iSoftwareConfig=0,
                                     int                           iPriorityGroup = 0) = 0;

  /** Builds a CATHLREntity from a model object to which a given transformation
  * will be applied, and its context to make restitution of more information 
  * during CallBacks (Rep only today)
  * default implementation : Create a new entity (BuildEntity method) wihtout Context Data
  * clever implementation in derivated classes
  * oldest configuration (CGMVersion=0) will be considered if iSoftwareConfig is set to null
  */
  virtual CATHLREntity * BuildEntityInContext(void                        * iModelObject,
				                                      CATHLRBodyId                  iIdentifier,
                                              CATHLRContainerEntity       * iContainer,
                                              const CATHLRTransformation  * iTransfoToApply,
                                              const void                  * iEntityContextData,
                                              CATSoftwareConfiguration    * iSoftwareConfig=0,
                                              int                           iPriorityGroup = 0);

};

#endif
