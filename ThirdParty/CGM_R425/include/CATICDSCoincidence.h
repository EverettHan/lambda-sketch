#ifndef CATICDSCoincidence_H
#define CATICDSCoincidence_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying coincidence between geometries.
 */
class ExportedByCDSInterface CATICDSCoincidence : public CATICDSGeomConstraint
{
public:
  
  /**
   * Retrieves orientation between a circle and a torus. This property is
   * meaningful in the case the constraint connects a circle and a torus.
   * @return
   *   An orientation between a circle and a torus.
   * @see #SetCircleTorusOrientation
   */
  virtual CATCDSTorusOrientation GetCircleTorusOrientation() const = 0;

  /**
   * Sets orientation between a circle and a torus. This property is meaningful in
   * the case the constraint connects a circle and a torus.
   * @param iOrientation
   *   An orientation between a circle and a torus.
   * @see #GetCircleTorusOrientation
   */
  virtual void SetCircleTorusOrientation(CATCDSTorusOrientation iOrientation) = 0;

  /**
   * Creates an instance of the CATICDSCoincidence Constraint
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use
   * @param pGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on
   * @param pGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on
   */
  static CATICDSCoincidence* Create(CATICDSFactory *ipFactory,
                                    CATICDSGeometryLeaf* pGeometry1,
                                    CATICDSGeometryLeaf* pGeometry2);

  virtual ~CATICDSCoincidence() {}
};

#endif
