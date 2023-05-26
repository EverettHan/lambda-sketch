#ifndef CATICDSEntity_H
#define CATICDSEntity_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATIAV5Level.h"

#include "CATCDS.h"

#include "CATCDSBoolean.h"
#include "CATICDSEnums.h"

class CATICDSFactory;
class CATICDS;

/**
 * Base class for all CDS Entities.
 */
class ExportedByCDSInterface CATICDSEntity
{
public:

  /**
   * Retrieves the entity type.
   * @return
   *   Type of the entity.
   */
  virtual CATCDSType GetType() const = 0;
  
  /**
   * Check if entity type matched with another type (reflects entity's inheritance).
   * @return
   *   Type of the entity.
   */
  virtual CATCDSBoolean IsMatched(CATCDSType iType) const = 0;
  
  /**
   * Sets a user object.
   * @param iPtr
   *   Pointer to the object.
   * @see #GetUserObj
   *
   * @SKIP
   */
  virtual void SetUserObj(void *iPtr) = 0;

  /**
   * Retrieves a user object.
   * @return
   *   Pointer to the object.
   * @see #SetUserObj
   *
   * @SKIP
   */
  virtual void * GetUserObj() const = 0;

  /**
   * Returns the status for a moved geometric object (should be called after SetDynamicMove).
   * This function gives information on moved status
   * of the geometric object or rigid set in 3D space.
   * @return
   *   The move status of the object.
   * @see #SetDynamicMove
   */
  virtual CATCDSMoveStatus GetMoveStatus() const = 0;
  
  /**
   * @nodoc
   */
  virtual ~CATICDSEntity() {}

  /**
   * @nodoc
   *
   * @SKIP
   */
  virtual void * GetImp() const = 0;

#if defined(CATIAV5R27) || defined (CATIAR419) || defined(_EMSCRIPTEN_SOURCE)
  /**
   * Returns the solver to which the entity belongs
   * @return A pointer to the solver
   */
  virtual CATICDS* GetSolver() const = 0;

  /*
   * Set entity name (debugging only).
   * @param iName
   *   The new name of the entity.
   *
   * @DEBUG
   */
  virtual void SetName(char const *iName) = 0;

  /*
   * Get the entity name .
   * @return
   *   The name of the entity.
   *
   * @DEBUG
   */
  virtual char const * GetName() const = 0;
#endif

};

#endif
