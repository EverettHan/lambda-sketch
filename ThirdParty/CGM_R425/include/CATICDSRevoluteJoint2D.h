#ifndef CATICDSRevoluteJoint2D_H
#define CATICDSRevoluteJoint2D_H

// COPYRIGHT DASSAULT SYSTEMES  2017

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSAxis2D;
class CATICDSVariable;

/**
 * 2D Revolute joint is a type of joint which connects two 2D axes thus only one
 * degree of freedom between them is available. The degree is a rotation around
 * the sktech normal wich is commanded by an angle variable. No relative translations
 * are available.
 * @see #CATICDSAxis2D, #CATICDSVariable
 */
class ExportedByCDSInterface CATICDSRevoluteJoint2D : public CATICDSJoint
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
   * Retrieves the angle variable.
   * @return
   *   The variable.
   */
  virtual CATICDSVariable *GetAngle() const = 0;

  /**
   * Creates an instance of the CATICDSRevoluteJoint2D joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   The first axis.
   * @param ipAxis2
   *   The second axis.
   * @param ipAngle
   *   The variable corresponding to the angle.
   */
  static CATICDSRevoluteJoint2D* Create(CATICDSFactory *ipFactory, CATICDSAxis2D *ipAxis1, CATICDSAxis2D *ipAxis2, CATICDSVariable *ipAngle);

  virtual ~CATICDSRevoluteJoint2D() {}
};

#endif
