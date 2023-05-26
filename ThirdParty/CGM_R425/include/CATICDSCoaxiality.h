#ifndef CATICDSCoaxiality_H
#define CATICDSCoaxiality_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

/**
 * A constraint specifying coaxiality between geometries.
 */
class ExportedByCDSInterface CATICDSCoaxiality : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSCoaxiality Constraint
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on
   * @param pGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on
   */
  static CATICDSCoaxiality* Create(CATICDSFactory *ipFactory,
                                   CATICDSGeometryLeaf* pGeometry1,
                                   CATICDSGeometryLeaf* pGeometry2);

  virtual ~CATICDSCoaxiality() {}
};

#endif
