#ifndef CATICDSCVJoint_H
#define CATICDSCVJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSUJoint;

/**
 * CV joint is a type of joint which connects two U joints. Thus four degrees
 * of freedom are available.
 * @see #CATICDSUJoint
 */
class ExportedByCDSInterface CATICDSCVJoint : public CATICDSJoint
{
public:
  /**
   * Creates an instance of the CATICDSCVJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipU1
   *   The first U joint.
   * @param ipU2
   *   The second U joint.
   * @param iRatio
   *   The ratio.
   */
  static CATICDSCVJoint* Create(CATICDSFactory *ipFactory, CATICDSUJoint *ipU1, CATICDSUJoint *ipU2);

  virtual ~CATICDSCVJoint() {}
};

#endif
