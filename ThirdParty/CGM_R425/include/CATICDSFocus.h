#ifndef CATICDSFocus_H
#define CATICDSFocus_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying focus of geometries. One of the geometries has to be a conic curve and other has to be a point.
 * This constraint enforces that the point lies at the focus of the conic curve
 */
class ExportedByCDSInterface CATICDSFocus : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSFocus Constraint
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on. This geometry has to be a conic curve.
   * @param pPoint
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on. This has to be a point.
   */
  static CATICDSFocus* Create(CATICDSFactory *ipFactory,
                              CATICDSGeometryLeaf* pGeometry,
                              CATICDSGeometryLeaf* pPoint);

  virtual ~CATICDSFocus() {}
};

#endif
