#ifndef CATICDSFullDOFJoint_H
#define CATICDSFullDOFJoint_H

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
 * FullDOF joint is a type of joint which connects two axes thus six degrees
 * of freedom between them are available. The first three degrees are
 * rotations in three-dimensional space commanded by angle variables. Namely,
 * Tait-Bryan angles with z-x-y convention are used. The last three degrees
 * are shifts along x, y, and z axes commanded by length variables.
 */
class ExportedByCDSInterface CATICDSFullDOFJoint : public CATICDSJoint
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
   * Retrieves the length variables. If no variables were set then it returns
   * the internal variables created by the joint. Note, that the internal
   * variables will be destroyed by the joint. Thus, do not use the internal
   * variables after the joint has been destroyed.
   * @param opLength1
   *   The first length variable.
   * @param opLength2
   *   The second length variable.
   * @param opLength3
   *   The third length variable.
   *
   * @RETURNARRAY
   */
  virtual void GetLengths(CATICDSVariable *&opLength1,
                          CATICDSVariable *&opLength2,
                          CATICDSVariable *&opLength3) const = 0;

  /**
   * Retrieves the angle variables. If no variables were set then it returns
   * the internal variables created by the joint. Note, that the internal
   * variables will be destroyed by the joint. Thus, do not use the internal
   * variables after the joint has been destroyed.
   * @param opAngle1
   *   The first angle variable.
   * @param opAngle2
   *   The second angle variable.
   * @param opAngle3
   *   The third angle variable.
   *
   * @RETURNARRAY
   */
  virtual void GetAngles(CATICDSVariable *&opAngle1,
                         CATICDSVariable *&opAngle2,
                         CATICDSVariable *&opAngle3) const = 0;
  
  /**
   * Sets the spherical type of the joint.
   * @param iType
   *   The spherical type of the joint.
   * @see #GetSphericalType
   */
  virtual void SetSphericalType(CATCDSSphericalType iType) = 0;

  /**
   * Retrieves the spherical type of the joint.
   * @return
   *   Spherical type of the joint.
   * @see #SetSphericalType
   */
  virtual CATCDSSphericalType GetSphericalType() const = 0;

  /**
   * Sets a conic limit value. To activate the limit use the EnableConicLimit method.
   * Limit value can be set only with the stZXZ spherical type.
   * @param iValue
   *   Value of the conic limit (positive value).
   * @see #GetConicLimitValue, #EnableConicLimit, #IsConicLimitEnabled
   */
  virtual void SetConicLimitValue(double iValue) = 0;

  /**
   * Retrieves the conic limit value (0 if not previously set by the user).
   * @return
   *   the conic limit value.
   * @see #SetConicLimitValue, #EnableConicLimit, #IsConicLimitEnabled
   */
  virtual double GetConicLimitValue() const = 0;

  /**
   * Enables or disables the conic limit. The value should be set by the SetConicLimitValue method.
   * Limit value can be set only with the stZXZ spherical type.
   * @param iEnable
   *   TRUE: enables the conic limit
   *   FALSE: disables the conic limit
   * @see #SetConicLimitValue, #GetConicLimitValue, #IsConicLimitEnabled
   */
  virtual void EnableConicLimit(CATCDSBoolean iEnable = TRUE) = 0;

  /**
   * Returns the state of the conic limit.
   * @return
   *   TRUE if the conic limit is enabled
   *   FALSE otherwise
   * @see #SetConicLimitValue, #GetConicLimitValue, #EnableConicLimit
   */
  virtual CATCDSBoolean IsConicLimitEnabled() const = 0;

  /**
   * @DEPRECATED
   * Creates an instance of the CATICDSFullDOFJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   * @param ipLength1
   *   The first length variable.
   * @param ipLength2
   *   The second length variable.
   * @param ipLength3
   *   The third length variable.
   * @param ipAngle1
   *   The first angle variable.
   * @param ipAngle2
   *   The second angle variable.
   * @param ipAngle3
   *   The third angle variable.
   */
  static CATICDSFullDOFJoint* Create(CATICDSFactory *ipFactory,
                                     CATICDSAxis* ipAxis1,
                                     CATICDSAxis* ipAxis2,
                                     CATICDSVariable* ipLength1,
                                     CATICDSVariable* ipLength2,
                                     CATICDSVariable* ipLength3,
                                     CATICDSVariable* ipAngle1,
                                     CATICDSVariable* ipAngle2,
                                     CATICDSVariable* ipAngle3);

  /**
   * Creates an instance of the CATICDSFullDOFJoint joint.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAxis1
   *   Pointer to the first CATICDSAxis that the joint is being placed on.
   * @param ipAxis2
   *   Pointer to the second CATICDSAxis that the joint is being placed on.
   * @param iType
   *   Spherical type of the joint.
   * @param ipLength1
   *   The first length variable.
   * @param ipLength2
   *   The second length variable.
   * @param ipLength3
   *   The third length variable.
   * @param ipAngle1
   *   The first angle variable.
   * @param ipAngle2
   *   The second angle variable (optional, depending on the spherical type).
   * @param ipAngle3
   *   The third angle variable (optional, depending on the spherical type).
   */
  static CATICDSFullDOFJoint* Create(CATICDSFactory *ipFactory,
    CATICDSAxis* ipAxis1,
    CATICDSAxis* ipAxis2,
    CATCDSSphericalType iType,
    CATICDSVariable* ipLength1,
    CATICDSVariable* ipLength2,
    CATICDSVariable* ipLength3,
    CATICDSVariable* ipAngle1,
    CATICDSVariable* ipAngle2 = 0,
    CATICDSVariable* ipAngle3 = 0);

  virtual ~CATICDSFullDOFJoint() {}
};

#endif
