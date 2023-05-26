#ifndef CATICDSRevoluteJoint_H
#define CATICDSRevoluteJoint_H

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
 * Revolute joint is a type of joint which connects two axes thus only one
 * degree of freedom between them is available. The degree is a rotation
 * around z axis wich is commanded by an angle variable. The origines of axes
 * are coincident.
 */
class ExportedByCDSInterface CATICDSRevoluteJoint : public CATICDSJoint
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
   * Creates an instance of the CATICDSRevoluteJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   * @param ipAngle
   *   Pointer to the angle variable.
   */
  static CATICDSRevoluteJoint* Create(CATICDSFactory *ipFactory,
                                      CATICDSAxis* ipAxis1,
                                      CATICDSAxis* ipAxis2,
                                      CATICDSVariable* ipAngle);

  virtual ~CATICDSRevoluteJoint() {}
};

#endif
