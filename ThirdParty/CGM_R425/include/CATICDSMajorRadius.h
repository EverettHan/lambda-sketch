#ifndef CATICDSMajorRadius_H
#define CATICDSMajorRadius_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomDimConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying the major radius of an ellipse, hyperbola or torus.
 */
class ExportedByCDSInterface CATICDSMajorRadius : public CATICDSGeomDimConstraint
{
public:

  /**
   * Creates an instance of the CATICDSMajorRadius constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param pGeometry
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   */
  static CATICDSMajorRadius* Create(CATICDSFactory *ipFactory,
                                    CATICDSGeometryLeaf* pGeometry);

  virtual ~CATICDSMajorRadius() {}
};

#endif
