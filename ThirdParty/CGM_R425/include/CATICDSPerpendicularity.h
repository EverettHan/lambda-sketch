#ifndef CATICDSPerpendicularity_H
#define CATICDSPerpendicularity_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying perpendicularity between geometries.
 */
class ExportedByCDSInterface CATICDSPerpendicularity : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSPerpendicularity constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   * @param pGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is placed on.
   */
  static CATICDSPerpendicularity* Create(CATICDSFactory *ipFactory,
                                         CATICDSGeometryLeaf* pGeometry1,
                                         CATICDSGeometryLeaf* pGeometry2);

  virtual ~CATICDSPerpendicularity() {}
};

#endif
