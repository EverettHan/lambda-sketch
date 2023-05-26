/* -*-C++-*-*/
#ifndef CATHLRComputer_H
#define CATHLRComputer_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRComputer 
//
// DESCRIPTION :
/**
 * Main object that computes the HLR.
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
// Mar. 2000 HKL Halo mode
// Oct. 2000 TPD Mise en place d'un bloc d'encombrement de la vue
//
//=============================================================================

// For Windows NT
#include "HLRProject.h"

// Other includes
#include "CATHLRBodyId.h"
#include "CATHLRComputerBase.h"
#include "CATListPV.h"
#include "CATCGMScaleCategoryDef.h" // enum CATCGMScaleCategory

class CATBaseUnknown;
class CATHLRPartOfEdge;
class CATHLRResultBrowser;
class CATHLRTransformation;
class CATMathTransformation;
class CATTolerance;

class CATHLREntity;

// tcx 13 03 2008
class HLR_CATechExt;
class CATechExt;

typedef struct 
{
    CATBaseUnknown        *_Body;
    CATHLREntity          *_Entity;
    CATHLRTransformation  *_Transfo;
    CATHLRBodyId          _BodyId;
} CATHLREntityStruct;


class ExportedByHLRProject CATHLRComputer : public CATHLRComputerBase
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
  CATHLRComputer(CATSoftwareConfiguration * iConfig = 0, CATCGMScaleCategory iSceneScaleCategory = ScaleNotSet);

/**
 * Destructor
 */
  virtual ~CATHLRComputer();

//=============================================================================
// ADDING-REMOVING AN OBJECT
//=============================================================================
/** Adds a new object in the list of object to draw. Returns the identifier of
 * the body.
 */

  CATHLRBodyId AddBody(CATBaseUnknown * iBodyToCompute,
                       const CATMathTransformation *iMatrixPosition = NULL,
                       const CATHLRComputerFlag iHidingFlag = Standard);


/** Adding and object with an associated matrix.
 */
  CATHLRBodyId AddBody(CATBaseUnknown * iBodyToCompute, 
                       const CATMathTransformation & iMatrixPosition,
                       const CATHLRComputerFlag iHidingFlag = Standard);


  /** Adding and object with an associated matrix, and a ClientContext,
  * to make restitution of more information during CallBacks (for Rep only)
  */
  CATHLRBodyId AddBodyInContext(CATBaseUnknown * iBodyToCompute, 
                                const CATMathTransformation & iMatrixPosition,
                                const void * iRepContextData,
                                const CATHLRComputerFlag iHidingFlag = Standard);


/** Gets the body from its number.
 * <BR> @iIdxBody starts at 0 and is lower or equal to GetCountBodies()-1 .
 * <BR> If the identity of the body is required, provide a pointer on it as a second
 * arguement.
 */
  CATBaseUnknown * GetBody(CATLONG32 iIdxBody, CATHLRBodyId * oIdentity = 0L) const;

//=============================================================================
// DOING THE COMPUTATION AND GETTING THE RESULT
//=============================================================================

/** Gets the result as a list of parts of edges
 */
  virtual CATHLRResultBrowser * GetResult() const;

/** Create a new result (and stores it in the internal motor)
 */
  virtual void ResetResult();

  // deprecated, please use CreateNewEntityInContext()
  virtual void NewEntity(void * iBody, 
                         CATHLRBodyId iBodyIdentity,
                         const CATHLRTransformation * iTransformation);
  
  virtual void CreateAllEntityBuilders();
  // V4 only
  virtual void CreateEntityBuilder();
  virtual void CreateInternalMotor(const CATTolerance & iTol);

  // xlu
  virtual void CompleteResult();
  
  virtual void Reset();


protected:
    
  // Creation of a new entity from a Body and its context, 
  // to make restitution of more information during CallBacks (Rep only today)
  virtual void CreateNewEntityInContext(void * iBody, CATHLRBodyId iBodyIdentity,
		                    const CATHLRTransformation * iTransformation, 
                                        const void * iEntityContextData,
                                        CATHLRInputEntityType iBodyType,
                                        int iAlwaysVisible);



private:

  // xlu
  int                    _NHRNumber;
  CATHLRContainerEntity *_NHRContainer;
  CATListPV              _NHREntities;
  
  CATHLRBodyId AddNHRWire(CATBaseUnknown * iBodyToCompute,
                          const CATMathTransformation *iMatrixPosition);

  // tcx 13 03 2008
  friend class HLR_CATechExt;
};

 
//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

#endif
