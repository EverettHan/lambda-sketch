#ifndef CATICDSSymmetricKIJoint_H
#define CATICDSSymmetricKIJoint_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSJoint.h"

class CATICDSFactory;
class CATICDSAxis;
class CATICDSPlane;

/**
 * The joint make two axes symmetric with respect to a plane. The symmetry is
 * created between z and x axes.
 * @see #CATICDSAxis, #CATICDSPlane
 */
class ExportedByCDSInterface CATICDSSymmetricKIJoint : public CATICDSJoint
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
   * Sets the symmetry plane.
   * @param ipPlane
   *   The symmetry plane.
   * @see #GetPlane
   */
  virtual void SetPlane(CATICDSPlane *ipPlane) = 0;

  /**
   * Retrieves the symmetry plane.
   * @return
   *   The symmetry plane.
   * @see #SetPlane
   */
  virtual CATICDSPlane* GetPlane() const = 0;

  /**
   * Creates an instance of the CATICDSSymmetricKIJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   * @param ipPlane
   *   Pointer to the plane.
   */
  static CATICDSSymmetricKIJoint* Create(CATICDSFactory *ipFactory,
                                      CATICDSAxis* ipAxis1,
                                      CATICDSAxis* ipAxis2,
                                      CATICDSPlane* ipPlane);

  virtual ~CATICDSSymmetricKIJoint() {}
};

#endif