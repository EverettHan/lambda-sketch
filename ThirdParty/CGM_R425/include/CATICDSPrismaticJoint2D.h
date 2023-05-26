#ifndef CATICDSPrismaticJoint2D_H
#define CATICDSPrismaticJoint2D_H

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
 * 2D Prismatic joint is a type of joint which connects two 2D axes thus only one
 * degree of freedom between them is available. The degree is a shift along the first
 * axis of the sketch wich is commanded by a length variable. No relative rotations are
 * available.
 * @see #CATICDSAxis2D, #CATICDSVariable
 */
class ExportedByCDSInterface CATICDSPrismaticJoint2D : public CATICDSJoint
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
   * Retrieves the length variable.
   * @return
   *   The variable.
   */
  virtual CATICDSVariable *GetLength() const = 0;

  /**
   * Creates an instance of the CATICDSPrismaticJoint2D joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   The first axis.
   * @param ipAxis2
   *   The second axis.
   * @param ipLength
   *   The variable corresponding to the length.
   */
  static CATICDSPrismaticJoint2D* Create(CATICDSFactory *ipFactory, CATICDSAxis2D *ipAxis1, CATICDSAxis2D *ipAxis2, CATICDSVariable *ipLength);

  virtual ~CATICDSPrismaticJoint2D() {}
};

#endif
