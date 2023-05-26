#ifndef CATICDSParallelism_H
#define CATICDSParallelism_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying parallelism between geometries.
 */
class ExportedByCDSInterface CATICDSParallelism : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSParallelism constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on.
   * @param pGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on.
   */
  static CATICDSParallelism* Create(CATICDSFactory *ipFactory,
                                    CATICDSGeometryLeaf* pGeometry1,
                                    CATICDSGeometryLeaf* pGeometry2);

  virtual ~CATICDSParallelism() {}
};

#endif