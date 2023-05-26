#ifndef CATICDSAntiTangency_H
#define CATICDSAntiTangency_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying anti-tangency between geometries.
 */
class ExportedByCDSInterface CATICDSAntiTangency : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSAntiTangency Constraint
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on
   * @param pGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on
   * @param pCoincidencePoint
   *   Optional pointer to the CATICDSGeometryLeaf that specifies the point of reference for anti tangency. 
   */
  static CATICDSAntiTangency* Create(CATICDSFactory *ipFactory,
                                     CATICDSGeometryLeaf* pGeometry1,
                                     CATICDSGeometryLeaf* pGeometry2,
                                     CATICDSGeometryLeaf* pCoincidencePoint = 0);

  virtual ~CATICDSAntiTangency() {}
};

#endif
