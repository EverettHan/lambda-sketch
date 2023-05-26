// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSphericalJoint.h
// Header definition of CATCSSphericalJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSSphericalJoint_H
#define CATCSSphericalJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSAxis;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * Spherical joint is a type of joint which connects two axes thus three
 * degrees of freedom between them are available. The degrees are rotations in
 * three-dimensional space commanded by angle variables. Namely, Tait-Bryan
 * angles with z-x-y convention are used. The origines of axes are coincident.
 * @see #CATCSAxis, #CATCSVariable
 */
class ExportedBySolverInterface CATCSSphericalJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSSphericalJoint(CATCSVariable *ipAngle1 = 0, CATCSVariable *ipAngle2 = 0, CATCSVariable *ipAngle3 = 0);

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSSphericalJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, CATCSVariable *ipAngle1 = 0, CATCSVariable *ipAngle2 = 0, CATCSVariable *ipAngle3 = 0);)

  virtual ~CATCSSphericalJoint();

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

  virtual void GetAngles(CATCSVariable *&opAngle1, CATCSVariable *&opAngle2, CATCSVariable *&opAngle3);

  /**
   * @nodoc
   */
  virtual void SetAngles(CATCSVariable *ipAngle1, CATCSVariable *ipAngle2, CATCSVariable *ipAngle3);

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

private:
  void Init(CATCSVariable *ipAngle1, CATCSVariable *ipAngle2, CATCSVariable *ipAngle3);

  CATCSVariable *_pAngle1, *_pAngle2, *_pAngle3;
  CATCSSphericalType _SphericalType;
  CATCDSBoolean _IsConicLimitEnabled;
  double _ConicLimitValue;
};

//-----------------------------------------------------------------------

#endif
