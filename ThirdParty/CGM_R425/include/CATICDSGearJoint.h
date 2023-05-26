#ifndef CATICDSGearJoint_H
#define CATICDSGearJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSRevoluteJoint;

/**
 * Gear joint is a type of joint which connects two revolute joints. Rotations
 * of the revolute joints are linearly dependent with a specific ratio. Thus
 * only one degree of freedom is available.
 * @see #CATICDSRevoluteJoint
 */
class ExportedByCDSInterface CATICDSGearJoint : public CATICDSJoint
{
public:
  /**
   * Sets the ratio of rotations.
   * @param iRatio
   *   The ratio.
   * @see #GetRatio
   */
  virtual void SetRatio(double iRatio) = 0;

  /**
   * Retrieves the ratio of rotations.
   * @return
   *   The ratio.
   * @see #SetRatio
   */
  virtual double GetRatio() const = 0;

  /**
   * Creates an instance of the CATICDSGearJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipRevolute1
   *   The first revolute joint.
   * @param ipRevolute2
   *   The second revolute joint.
   */
  static CATICDSGearJoint* Create(CATICDSFactory *ipFactory, CATICDSRevoluteJoint *ipRevolute1, CATICDSRevoluteJoint *ipRevolute2);

  virtual ~CATICDSGearJoint() {}
};

#endif
