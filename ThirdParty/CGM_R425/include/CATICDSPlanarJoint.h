#ifndef CATICDSPlanarJoint_H
#define CATICDSPlanarJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSVariable;

/**
 * Planar joint is a type of joint which connects two axes thus three degrees
 * of freedom between them are available. The degrees are shifts and a
 * rotation in xy plane.
 */
class ExportedByCDSInterface CATICDSPlanarJoint : public CATICDSJoint
{
public:

  /**
   * Retrieves axis connected with the joint.
   * @param opGeom1
   *   The first geometry.
   * @param opGeom2
   *   The second geometry.
   *
   * @RETURNARRAY
   */
  virtual void GetAxis(CATICDSAxis *&opAxis1, CATICDSAxis *&opAxis2) const = 0;

  /**
   * Creates an instance of the CATICDSPlanarJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   * @param ipLength
   *   Pointer to the length variable.
   */
  static CATICDSPlanarJoint* Create(CATICDSFactory *ipFactory,
                                      CATICDSAxis* ipAxis1,
                                      CATICDSAxis* ipAxis2);

  virtual ~CATICDSPlanarJoint() {}
};

#endif
