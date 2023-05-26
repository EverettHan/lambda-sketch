// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCSFullDOFJoint.h
// Header definition of CATCSFullDOFJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Dec 2009  Creation                Semyon ROMANCHENKO
//===================================================================

#ifndef CATCSFullDOFJoint_H
#define CATCSFullDOFJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSAxis;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * FullDOF joint is a type of joint which connects two axes thus six degrees
 * of freedom between them are available. The first three degrees are
 * rotations in three-dimensional space commanded by angle variables. Namely,
 * Tait-Bryan angles with z-x-y convention are used. The last three degrees
 * are shifts along x, y, and z axes commanded by length variables.
 * @see #CATCSAxis, #CATCSVariable
 */
class ExportedBySolverInterface CATCSFullDOFJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSFullDOFJoint();

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSFullDOFJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2);)

  /**
   * Constructs an instance of the joint with angle and length variables.
   */
  CATCSFullDOFJoint(CATCSVariable *ipAngles[3], CATCSVariable *ipLengths[3]);

  virtual ~CATCSFullDOFJoint();

  /**
   * Retrieves type of the joint.
   * @return
   *   Type of the joint.
   * @see #IsMatched
   */
  virtual CATCSType GetType() const CATCDSOverride;

  /**
   * Checks whether the joint is matched to a specific type. The joint can be
   * casted to a corresponding class if the matching is successful.
   * @param iType
   *   A specific type.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the matching is successful,
   *     <li><tt>FALSE</tt> - otherwise.
   *   </ul>
   */
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  /**
   * Sets the axes to be connected.
   * @param ipAxis1
   *   The first axis.
   * @param ipAxis2
   *   The second axis.
   * @see #GetGeometries
   */
  virtual void SetGeometries(CATCSAxis *ipAxis1, CATCSAxis *ipAxis2);

  /**
   * Retrieves the axes to be connected.
   * @param opAxis1
   *   The first axis.
   * @param opAxis2
   *   The second axis.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSAxis *&opAxis1, CATCSAxis *&opAxis2);

  /**
   * Sets the length variables. It replaces the internal variables created by
   * the joint. If one of the arguments is null then no variables will be set
   * and the internal variables will be restored.
   * @param ipLength1
   *   The first length variable.
   * @param ipLength2
   *   The second length variable.
   * @param ipLength3
   *   The third length variable.
   * @see #GetLengths
   */
  virtual void SetLengths(CATCSVariable *ipLength1, CATCSVariable *ipLength2, CATCSVariable *ipLength3);

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
   * @see #SetLengths
   */
  virtual void GetLengths(CATCSVariable *&opLength1, CATCSVariable *&opLength2, CATCSVariable *&opLength3);

  /**
   * Checks whether the length variables were set by a user. If the variables
   * were not set then the joint uses the internal variables created by
   * itself.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the length variables were set by a user,
   *     <li><tt>FALSE</tt> - if internal variables are used.
   *   </ul>
   * @see #SetLengths
   */
  virtual CATCDSBoolean AreLengthsExternal();

  /**
   * Sets the angle variables. It replaces the internal variables created by
   * the joint. If one of the arguments is null then no variables will be set
   * and the internal variables will be restored.
   * @param ipAngle1
   *   The first angle variable.
   * @param ipAngle2
   *   The second angle variable.
   * @param ipAngle3
   *   The third angle variable.
   * @see #GetAngles
   */
  virtual void SetAngles(CATCSVariable *ipAngle1, CATCSVariable *ipAngle2, CATCSVariable *ipAngle3);

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
   * @see #SetAngles
   */
  virtual void GetAngles(CATCSVariable *&opAngle1, CATCSVariable *&opAngle2, CATCSVariable *&opAngle3);

  /**
   * Checks whether the angle variables were set by a user. If the variables
   * were not set then the joint uses the internal variables created by
   * itself.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt> - if the angle variables were set by a user,
   *     <li><tt>FALSE</tt> - if internal variables are used.
   *   </ul>
   * @see #SetAngles
   */
  virtual CATCDSBoolean AreAnglesExternal();

  /**
   * Initializes length and angle variables according to a current position of
   * the axes.
   */
  virtual void InitializeVariables();

  /**
   * Sets the spherical type of the joint.
   * @param iType
   *   The spherical type of the joint.
   * @see #GetSphericalType
   */
  virtual void SetSphericalType(CATCSSphericalType iType);

  /**
   * Retrieves the spherical type of the joint.
   * @return
   *   Spherical type of the joint.
   * @see #SetSphericalType
   */
  virtual CATCSSphericalType GetSphericalType() const;

  /**
   * Sets a conic limit value. To activate the limit use the EnableConicLimit method.
   * Limit value can be set only with the stZXZ spherical type.
   * @param iValue
   *   Value of the conic limit (positive value).
   * @see #GetConicLimitValue, #EnableConicLimit, #IsConicLimitEnabled
   */
  virtual void SetConicLimitValue(double iValue);

  /**
   * Retrieves the conic limit value (0 if not previously set by the user).
   * @return
   *   the conic limit value.
   * @see #SetConicLimitValue, #EnableConicLimit, #IsConicLimitEnabled
   */
  virtual double GetConicLimitValue() const;

  /**
   * Enables or disables the conic limit. The value should be set by the SetConicLimitValue method.
   * Limit value can be set only with the stZXZ spherical type.
   * @param iEnable
   *   TRUE: enables the conic limit
   *   FALSE: disables the conic limit
   * @see #SetConicLimitValue, #GetConicLimitValue, #IsConicLimitEnabled
   */
  virtual void EnableConicLimit(CATCDSBoolean iEnable = TRUE);

  /**
   * Returns the state of the conic limit.
   * @return
   *   TRUE if the conic limit is enabled
   *   FALSE otherwise
   * @see #SetConicLimitValue, #GetConicLimitValue, #EnableConicLimit
   */
  virtual CATCDSBoolean IsConicLimitEnabled() const;

  /**
   * nodoc
   */
  virtual CATCDSBoolean GetOwnsVariables() const CATCDSOverride;

private:
  void Init();

  CATCSVariable *_apAngles[3], *_apLengths[3];
  CATCDSBoolean _extAngles, _extLengths;
  CATCSSphericalType _SphericalType;
  CATCDSBoolean _IsConicLimitEnabled;
  double _ConicLimitValue;
};

//-----------------------------------------------------------------------

#endif
