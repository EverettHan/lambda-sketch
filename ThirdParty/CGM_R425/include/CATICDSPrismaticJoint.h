#ifndef CATICDSPrismaticJoint_H
#define CATICDSPrismaticJoint_H

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
 * Prismatic joint is a type of joint which connects two axes thus only one
 * degree of freedom between them is available. The degree is a shift along z
 * axis wich is commanded by a length variable. No relative rotations are
 * available.
 */
class ExportedByCDSInterface CATICDSPrismaticJoint : public CATICDSJoint
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
   * Retrieves the length variable.
   * @return
   *   The variable.
   */
  virtual CATICDSVariable *GetLength() const = 0;

  /**
   * Creates an instance of the CATICDSPrismaticJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   * @param ipLength
   *   Pointer to the length variable.
   */
  static CATICDSPrismaticJoint* Create(CATICDSFactory *ipFactory,
                                       CATICDSAxis* ipAxis1,
                                       CATICDSAxis* ipAxis2,
                                       CATICDSVariable* ipLength);
  virtual ~CATICDSPrismaticJoint() {}
};

#endif
