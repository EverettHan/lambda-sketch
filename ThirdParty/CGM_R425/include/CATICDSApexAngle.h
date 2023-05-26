#ifndef CATICDSApexAngle_H
#define CATICDSApexAngle_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomDimConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying angle between geometries.
 */
class ExportedByCDSInterface CATICDSApexAngle : public CATICDSGeomDimConstraint
{
public:

  /**
   * Creates an instance of the CATICDSApexAngle Constraint
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on
   */
  static CATICDSApexAngle* Create(CATICDSFactory *ipFactory,
                              CATICDSGeometryLeaf* pGeometry1);

  virtual ~CATICDSApexAngle() {}
};

#endif
