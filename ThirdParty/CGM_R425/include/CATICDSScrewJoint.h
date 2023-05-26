#ifndef CATICDSScrewJoint_H
#define CATICDSScrewJoint_H

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
 * Screw joint is a type of joint which connects two axes thus only one degree
 * of freedom between them is available. The degree is a screw movement around
 * z axis wich is commanded by an angle and a length variables.
 * @see #CATICDSAxis, #CATICDSVariable
 */
class ExportedByCDSInterface CATICDSScrewJoint : public CATICDSJoint
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
   * Sets the pitch of a screw.
   * @param iPitch
   *   The pitch.
   * @see #GetPitch
   */
  virtual void SetPitch(double iPitch) = 0;

  /**
   * Retrieves the pitch of a screw.
   * @return
   *   The pitch.
   * @see #SetPitch
   */
  virtual double GetPitch() const = 0;
  
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
   * Creates an instance of the CATICDSScrewJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   * @param ipAngle
   *   The variable corresponding to the angle.
   * @param ipLength
   *   The variable corresponding to the length.
   */
  static CATICDSScrewJoint* Create(CATICDSFactory *ipFactory, CATICDSAxis* ipAxis1, CATICDSAxis* ipAxis2, CATICDSVariable *ipAngle, CATICDSVariable *ipLength);

  virtual ~CATICDSScrewJoint() {}
};

#endif
