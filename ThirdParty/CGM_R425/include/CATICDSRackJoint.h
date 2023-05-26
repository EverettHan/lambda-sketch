#ifndef CATICDSRackJoint_H
#define CATICDSRackJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSPrismaticJoint;
class CATICDSRevoluteJoint;

/**
 * Rack joint is a type of joint which connects prismatic and revolute joints.
 * Shift of the prismatic joint and rotation of the revolute joint are
 * linearly dependent with a specific ratio. Thus only one degree of freedom
 * is available.
 * @see #CATICDSPrismaticJoint, #CATICDSRevoluteJoint
 */
class ExportedByCDSInterface CATICDSRackJoint : public CATICDSJoint
{
public:
  /**
   * Sets the ratio between shift and rotation.
   * @param iRatio
   *   The ratio.
   * @see #GetRatio
   */
  virtual void SetRatio(double iRatio) = 0;

  /**
   * Retrieves the ratio between shift and rotation.
   * @return
   *   The ratio.
   * @see #SetRatio
   */
  virtual double GetRatio() const = 0;

  /**
   * Creates an instance of the CATICDSRackJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipPrismatic
   *   The prismatic joint.
   * @param ipRevolute
   *   The revolute joint.
   */
  static CATICDSRackJoint* Create(CATICDSFactory *ipFactory, CATICDSPrismaticJoint *ipPrismatic, CATICDSRevoluteJoint *ipRevolute);

  virtual ~CATICDSRackJoint() {}
};

#endif
