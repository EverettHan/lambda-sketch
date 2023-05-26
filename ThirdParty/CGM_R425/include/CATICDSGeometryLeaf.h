#ifndef CATICDSGeometryLeaf_H
#define CATICDSGeometryLeaf_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeometry.h"

class CATICDSRigidSet;

/**
 * A basic class for all geometries; not for rigid sets and non-instantiable.
 */
class ExportedByCDSInterface CATICDSGeometryLeaf : public CATICDSGeometry
{
public:
  
  /**
   * Retrieves a rigid set including its constituent geometries.
   * @return
   *   Pointer to the rigid set.
   */
  virtual CATICDSRigidSet *GetRigidSet() const = 0;

  /**
   * Check if at least one of object's parameters has non-identity current transformation.
   */
  virtual CATCDSBoolean HasParameterTransformation() const = 0;

  virtual ~CATICDSGeometryLeaf() {}
};

#endif
