#ifndef CATICDSFactory_H
#define CATICDSFactory_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEnums.h"

class CATICDSEntity;
class CATICDSGeometryLeaf;
class CATICDSConstraint;
class CATICDSConstraintDescriptor;

/**
 * CDS factory
 */
class ExportedByCDSInterface CATICDSFactory
{
public:

  /**
   * Replaces geometric object in solver, the old geometry remains
   * in the solver but all it all of its releated constraints were
   * re-routed to the new geometry.
   * The fixation is rerooted only if ipOldGLeaf and ipNewGLeaf have the same dimension
   * (both are 2d geometries or both are 3d geometries)
   * @param ipOldGLeaf
   *   A pointer to the old geometry.
   * @param ipNewGLeaf
   *   A pointer to the new geometry.
   * @return
   *   0 - if the function succeeded,
   *   1 - if already existing constraints can't accept ipNewGLeaf as argument
   */
  virtual int ReplaceGeometry(CATICDSGeometryLeaf* ipOldGLeaf, CATICDSGeometryLeaf* ipNewGLeaf) = 0;

  /**
   * Fills in list of pointers to entities of a given type.
   * @param onEntities
   *    Number of matching entities
   * @param oaEntities
   *    Array of matching entities (allocated by this method)
   * @param iType 
   *    Type to match
   *
   * @SIZE oaEntities onEntities
   */
  virtual void GetEntities(int &onEntities, CATICDSEntity **&oaEntities, CATCDSType iType = tpANYTYPE) const = 0;

  /**
   * Create a constraint as described by a constraint descriptor.
   * @param ipDescriptor
   *   A pointer to the constraint descriptor to materialize.
   * @return
   *   The added constraint if the function succeeded, 0 otherwise.
   *
   * @SKIP
   */
  virtual CATICDSConstraint* CreateConstraint(CATICDSConstraintDescriptor* ipDescriptor) = 0;

  /**
   * Removes an entity from the solver and deletes it. Make sure that any all pointers
   * to the entity are set to NULL, otherwise they will point a freed memory area.
   * @param iopEntity
   *  A pointer to the entity callback that will be removed and deleted.
   * @return
   *   0 - if the function succeeded (in this case the object wasn't deleted)
   *   1 - if arguments are invalid
   */
  virtual int Remove(CATICDSEntity* ipEntity) = 0;

  /**
   * Removes all entities (object, rigid set or constraint) from 
   * the solver and delete them
   */
  virtual void RemoveAll() = 0;

  virtual ~CATICDSFactory() {}
};

#endif
