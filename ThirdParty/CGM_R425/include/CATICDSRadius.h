#ifndef CATICDSRadius_H
#define CATICDSRadius_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomDimConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying the radius of a circle, cylinder, cylicone or sphere.
 */
class ExportedByCDSInterface CATICDSRadius : public CATICDSGeomDimConstraint
{
public:

  /**
   * Creates an instance of the CATICDSRadius constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param pGeometry
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   */
  static CATICDSRadius* Create(CATICDSFactory *ipFactory,
                               CATICDSGeometryLeaf* pGeometry);

  virtual ~CATICDSRadius() {}
};

#endif
