// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSRevoluteJoint.h
// Header definition of CATCSRevoluteJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSRevoluteJoint_H
#define CATCSRevoluteJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"

class CATCSAxis;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * Revolute joint is a type of joint which connects two axes thus only one
 * degree of freedom between them is available. The degree is a rotation
 * around z axis wich is commanded by an angle variable. The origines of axes
 * are coincident.
 * @see #CATCSAxis, #CATCSVariable
 */
class ExportedBySolverInterface CATCSRevoluteJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSRevoluteJoint(CATCSVariable *ipAngle = 0);

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSRevoluteJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, CATCSVariable *ipAngle = 0);)

  virtual ~CATCSRevoluteJoint();

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
   * Retrieves the angle variable.
   * @return
   *   The variable.
   */
  virtual CATCSVariable *GetAngle();

  /**
   * Sets the angle variable.
   * @param ipAngle
   *   The variable corresponding to the angle.
   */
  virtual void SetAngle(CATCSVariable *ipAngle);

private:
  void Init(CATCSVariable *ipAngle);

  CATCSVariable *_pAngle;
};

//-----------------------------------------------------------------------

#endif
