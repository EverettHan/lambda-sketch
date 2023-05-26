#ifndef CATICDSCoincidentJoint_H
#define CATICDSCoincidentJoint_H

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
 * Coincident joint is a type of joint which connects two axes thus no degrees
 * of freedom between them are available. Moreover, the axes have to be
 * coincident.
 * @see #CATICDSAxis
 */
class ExportedByCDSInterface CATICDSCoincidentJoint : public CATICDSJoint
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
   * Creates an instance of the CATICDSCoincidentJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   */
  static CATICDSCoincidentJoint* Create(CATICDSFactory *ipFactory,
                               CATICDSAxis* ipAxis1,
                               CATICDSAxis* ipAxis2);

  virtual ~CATICDSCoincidentJoint() {}
};

#endif
