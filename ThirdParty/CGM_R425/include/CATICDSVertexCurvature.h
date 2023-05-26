#ifndef CATICDSCurvature_H
#define CATICDSCurvature_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomDimConstraint.h"

class CATICDSFactory;

/**
 * A constraint that specifies the curvature of a parabola at its vertex.
 */
class ExportedByCDSInterface CATICDSVertexCurvature : public CATICDSGeomDimConstraint
{
public:

  /**
   * Creates an instance of the CATICDSVertexCurvature constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param pGeometry
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   */
  static CATICDSVertexCurvature* Create(CATICDSFactory *ipFactory,
                                        CATICDSGeometryLeaf* pGeometry);

  virtual ~CATICDSVertexCurvature() {}
};

#endif
