#ifndef CATICDSMidpoint_H
#define CATICDSMidpoint_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying a midpoint between geometries.
 */
class ExportedByCDSInterface CATICDSMidpoint : public CATICDSGeomConstraint
{
public:

  /**
   * Creates an instance of the CATICDSMidpoint constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipStart
   *   Pointer to the CATICDSGeometryLeaf that specifies the start-point or start-line.
   * @param ipEnd
   *   Pointer to the CATICDSGeometryLeaf that specifies the end-point or end-line.
   * @param ipMidPoint
   *   Pointer to the CATICDSGeometryLeaf that specifies the mid-point between the start- and end-points or between the start- and end-lines.
   */
  static CATICDSMidpoint* Create(CATICDSFactory *ipFactory,
                                 CATICDSGeometryLeaf* ipStart,
                                 CATICDSGeometryLeaf* ipEnd,
                                 CATICDSGeometryLeaf* ipMidPoint);

  virtual ~CATICDSMidpoint() {}
};

#endif
