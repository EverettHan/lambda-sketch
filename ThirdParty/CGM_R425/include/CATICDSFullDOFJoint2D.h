#ifndef CATICDSFullDOFJoint2D_H
#define CATICDSFullDOFJoint2D_H

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
 * FullDOF2D joint is a type of joint which connects two 2D axes thus 3 degrees
 * of freedom between them are available. The first degree is a rotations in 
 * the 2d space of the sketch commanded by an angle variable. The last 2 degrees
 * are shifts along x, y axes commanded by length variables.
 * @see #CATICDSAxis2D, #CATICDSVariable
 */
class ExportedByCDSInterface CATICDSFullDOFJoint2D : public CATICDSJoint
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
   * Retrieves the length and angle variables. If no variables were set then it returns
   * the internal variables created by the joint. Note, that the internal
   * variables will be destroyed by the joint. Thus, do not use the internal
   * variables after the joint has been destroyed.
   * @param opLength1
   *   The first length variable.
   * @param opLength2
   *   The second length variable.
   * @param opAngle
   *   The angle variable.
   */
  virtual void GetVariables(CATICDSVariable *&opLength1, CATICDSVariable *&opLength2, CATICDSVariable *&opAngle) const = 0;

  /**
   * Creates an instance of the CATICDSFullDOFJoint2D joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   The first axis.
   * @param ipAxis2
   *   The second axis.
   * @param ipLength1
   *   The first length variable.
   * @param ipLength2
   *   The second length variable.
   * @param ipAngle
   *   The angle variable.
   */
  static CATICDSFullDOFJoint2D* Create(CATICDSFactory *ipFactory, CATICDSAxis2D *ipAxis1, CATICDSAxis2D *ipAxis2, CATICDSVariable *ipLength1, CATICDSVariable *ipLength2, CATICDSVariable *ipAngle);

  virtual ~CATICDSFullDOFJoint2D() {}
};

#endif
