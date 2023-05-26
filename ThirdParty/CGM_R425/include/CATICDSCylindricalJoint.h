#ifndef CATICDSCylindricalJoint_H
#define CATICDSCylindricalJoint_H

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
 * Cylindrical joint is a type of joint which connects two axes thus two
 * degrees of freedom between them are available. The first one is a rotation
 * around z axis wich is commanded by an angle variable. The second one is a
 * shift along z axis commanded by a length variable.
 */
class ExportedByCDSInterface CATICDSCylindricalJoint : public CATICDSJoint
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
   * Retrieves the angle variable.
   * @return
   *   The variable.
   */
  virtual CATICDSVariable *GetAngle() const = 0;

  /**
   * Retrieves the length variable.
   * @return
   *   The variable.
   */
  virtual CATICDSVariable *GetLength() const = 0;

  /**
   * Creates an instance of the CATICDSCylindricalJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   * @param ipAngle
   *   Pointer to the angle variable.
   * @param ipLength
   *   Pointer to the length variable.
   */
  static CATICDSCylindricalJoint* Create(CATICDSFactory *ipFactory,
                                         CATICDSAxis* ipAxis1,
                                         CATICDSAxis* ipAxis2,
                                         CATICDSVariable* ipAngle,
                                         CATICDSVariable* ipLength);

  virtual ~CATICDSCylindricalJoint() {}
};

#endif
