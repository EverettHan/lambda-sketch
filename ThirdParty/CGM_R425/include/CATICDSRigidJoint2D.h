#ifndef CATICDSRigidJoint2D_H
#define CATICDSRigidJoint2D_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSVariable;
class CATICDSAxis2D;

/**
 * Rigid joint is a type of joint which connects two axes thus no degrees of
 * freedom between them are available.
 * @see #CATICDSAxis2D
 */
class ExportedByCDSInterface CATICDSRigidJoint2D : public CATICDSJoint
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
  virtual void GetAxis(CATICDSAxis2D *&opAxis1, CATICDSAxis2D *&opAxis2) const = 0;
  
  /**
   * Creates an instance of the CATICDSRigidJoint2D joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   */
  static CATICDSRigidJoint2D* Create(CATICDSFactory *ipFactory,
                               CATICDSAxis2D* ipAxis1,
                               CATICDSAxis2D* ipAxis2);

  virtual ~CATICDSRigidJoint2D() {}
};

#endif
