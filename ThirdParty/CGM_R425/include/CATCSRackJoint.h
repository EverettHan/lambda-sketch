// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSRackJoint.h
// Header definition of CATCSRackJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSRackJoint_H
#define CATCSRackJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSJoint.h"

class CATCSPrismaticJoint;
class CATCSRevoluteJoint;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * Rack joint is a type of joint which connects prismatic and revolute joints.
 * Shift of the prismatic joint and rotation of the revolute joint are
 * linearly dependent with a specific ratio. Thus only one degree of freedom
 * is available.
 * @see #CATCSPrismaticJoint, #CATCSRevoluteJoint
 */
class ExportedBySolverInterface CATCSRackJoint : public CATCSJoint
{
public:
  /**
   * Constructs an instance of the joint.
   * @param ipPrismatic
   *   The prismatic joint.
   * @param ipRevolute
   *   The revolute joint.
   * @see #GetSubJoints
   */
  CATCSRackJoint(CATCSPrismaticJoint *ipPrismatic, CATCSRevoluteJoint *ipRevolute);

  virtual ~CATCSRackJoint();

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
   * @param opPrismatic
   *   The prismatic joint.
   * @param opRevolute
   *   The revolute joint.
   */
  virtual void GetSubJoints(CATCSPrismaticJoint *&opPrismatic, CATCSRevoluteJoint *&opRevolute);

  /**
   * Sets the ratio between shift and rotation.
   * @param iRatio
   *   The ratio.
   * @see #GetRatio
   */
  virtual void SetRatio(double iRatio);

  /**
   * Retrieves the ratio between shift and rotation.
   * @return
   *   The ratio.
   * @see #SetRatio
   */
  virtual double GetRatio();

  /**
   * Retrieves the angle variable of the revolute joint.
   * @return
   *   The variable of the revolute joint.
   */
  virtual CATCSVariable *GetAngle();

  /**
   * Retrieves the length variable of the prismatic joint.
   * @return
   *   The variable of the prismatic joint.
   */
  virtual CATCSVariable *GetLength();
private:
  CATCSPrismaticJoint *_pPrismatic;
  CATCSRevoluteJoint *_pRevolute;
  double _dRatio;
};

//-----------------------------------------------------------------------

#endif
