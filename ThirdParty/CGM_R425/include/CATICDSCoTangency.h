#ifndef CATICDSCoTangency_H
#define CATICDSCoTangency_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying co-tangency between geometries.
 */
class ExportedBySolverInterface CATICDSCoTangency : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSCoTangency Constraint
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on
   * @param pGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on 
   */
  static CATICDSCoTangency* Create(CATICDSFactory *ipFactory,
                                     CATICDSGeometryLeaf* pGeometry1,
                                     CATICDSGeometryLeaf* pGeometry2);

  virtual ~CATICDSCoTangency() {}
};

#endif
