// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSGearJoint.h
// Header definition of CATCSGearJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSGearJoint_H
#define CATCSGearJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSJoint.h"

class CATCSRevoluteJoint;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * Gear joint is a type of joint which connects two revolute joints. Rotations
 * of the revolute joints are linearly dependent with a specific ratio. Thus
 * only one degree of freedom is available.
 * @see #CATCSRevoluteJoint
 */
class ExportedBySolverInterface CATCSGearJoint : public CATCSJoint
{
public:
  /**
   * Constructs an instance of the joint.
   * @param ipRevolute1
   *   The first revolute joint.
   * @param ipRevolute2
   *   The second revolute joint.
   * @see #GetSubJoints
   */
  CATCSGearJoint(CATCSRevoluteJoint *ipRevolute1, CATCSRevoluteJoint *ipRevolute2);

  virtual ~CATCSGearJoint();

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
   * Retrieves the subjoints connected.
   * @param opRevolute1
   *   The first revolute joint.
   * @param opRevolute2
   *   The second revolute joint.
   */
  virtual void GetSubJoints(CATCSRevoluteJoint *&opRevolute1, CATCSRevoluteJoint *&opRevolute2);

  /**
   * Sets the ratio of rotations.
   * @param iRatio
   *   The ratio.
   * @see #GetRatio
   */
  virtual void SetRatio(double iRatio);

  /**
   * Retrieves the ratio of rotations.
   * @return
   *   The ratio.
   * @see #SetRatio
   */
  virtual double GetRatio();

  /**
   * Retrieves the angle variables of the corresponding revolute joints.
   * @param opAngle1
   *   The variable of the first revolute joint.
   * @param opAngle2
   *   The variable of the second revolute joint.
   */
  virtual void GetAngles(CATCSVariable *&opAngle1, CATCSVariable *&opAngle2);
private:
  CATCSRevoluteJoint *_pRevolute1, *_pRevolute2;
  double _dRatio;
};

//-----------------------------------------------------------------------

#endif
