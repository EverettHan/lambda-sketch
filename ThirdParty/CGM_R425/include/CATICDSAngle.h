#ifndef CATICDSAngle_H
#define CATICDSAngle_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomDimConstraint.h"

class CATICDSFactory;

/**
 * A constraint specifying angle between geometries.
 */
class ExportedByCDSInterface CATICDSAngle : public CATICDSGeomDimConstraint
{
public:

  /**
   * Creates an instance of the CATICDSAngle Constraint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipGeometry1
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on.
   * @param ipGeometry2
   *   Pointer to the CATICDSGeometryLeaf that the constraint is being placed on.
   * @param ipDirection
   *   Optional pointer to the CATICDSGeometryLeaf that specifies axis for planar angles. 
   *   To define a planar angle the user has to provide a pointer to a geometry defining 
   *   an axis with the GetAxis method of CATICDSAngle. 
   *   This geometry is either a CATICDSLine or a CATICDSPlane, must be declared to CDS and 
   *   linked to the argument geometries of the planar angle by a coincident, a perpendicularity or a parallelism constraint.
   */
  static CATICDSAngle* Create(CATICDSFactory *ipFactory,
                              CATICDSGeometryLeaf* ipGeometry1,
                              CATICDSGeometryLeaf* ipGeometry2,
                              CATICDSGeometryLeaf* ipDirection = 0);
  /*
  *@return
  * TRUE if the angle is dimensional (ie we can change the angle continuously), FALSE if it is logical
  */
  virtual CATCDSBoolean IsDimensional() const=0;

  virtual ~CATICDSAngle() {}
};

#endif
