#ifndef CATICDSCableJoint_H
#define CATICDSCableJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSPrismaticJoint;

/**
 * Cable joint is a type of joint which connects two prismatic joints. Shifts
 * of the prismatic joints are linearly dependent with a specific ratio. Thus
 * only one degree of freedom is available.
 * @see #CATICDSPrismaticJoint
 */
class ExportedByCDSInterface CATICDSCableJoint : public CATICDSJoint
{
public:
  /**
   * Retrieves the ratio of shifts.
   * @return
   *   The variable.
   */
  virtual double GetRatio() const = 0;

  /**
   * Creates an instance of the CATICDSCableJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipPrismatic1
   *   The first prismatic joint.
   * @param ipPrismatic2
   *   The second prismatic joint.
   * @param iRatio
   *   The ratio.
   */
  static CATICDSCableJoint* Create(CATICDSFactory *ipFactory, CATICDSPrismaticJoint *ipPrismatic1, CATICDSPrismaticJoint *ipPrismatic2, double iRatio);

  virtual ~CATICDSCableJoint() {}
};

#endif
