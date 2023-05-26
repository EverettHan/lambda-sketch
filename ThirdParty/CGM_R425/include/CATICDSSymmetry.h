#ifndef CATICDSSymmetry_H
#define CATICDSSymmetry_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;
class CATICDSGeometryLeaf;

/**
 * A constraint specifying symmetry between geometries.
 */
class ExportedByCDSInterface CATICDSSymmetry : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSSymmetry constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   * @param ipGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   * @param ipAxis
   *   Pointer to the CATICDSGeometryLeaf that specifies the desired axis of symmetry.
   */
  static CATICDSSymmetry* Create(CATICDSFactory *ipFactory,
                                 CATICDSGeometryLeaf* ipGeometry1,
                                 CATICDSGeometryLeaf* ipGeometry2,
                                 CATICDSGeometryLeaf* ipAxis);

  virtual ~CATICDSSymmetry() {}
};

#endif
