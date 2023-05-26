#ifndef CATICDSUJoint_H
#define CATICDSUJoint_H

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
 * U joint is a type of joint which connects two axes thus two degrees of
 * freedom between them are available. The degrees are a rotation around z
 * of the first axis and a rotation around x of the second axis.
 */
class ExportedByCDSInterface CATICDSUJoint : public CATICDSJoint
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
   * Creates an instance of the CATICDSUJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   */
  static CATICDSUJoint* Create(CATICDSFactory *ipFactory,
                               CATICDSAxis* ipAxis1,
                               CATICDSAxis* ipAxis2);

  virtual ~CATICDSUJoint() {}
};

#endif
