#ifndef CATICDSTangency_H
#define CATICDSTangency_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying tangency between geometries.
 */
class ExportedByCDSInterface CATICDSTangency : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSTangency constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   * @param pGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   * @param pCoincidencePoint
   *   Optional pointer to the CATICDSGeometryLeaf that specifies the point of tangency.
   */
  static CATICDSTangency* Create(CATICDSFactory *ipFactory,
                                 CATICDSGeometryLeaf* pGeometry1,
                                 CATICDSGeometryLeaf* pGeometry2,
                                 CATICDSGeometryLeaf* pCoincidencePoint = 0);

  virtual ~CATICDSTangency() {}
};

#endif
