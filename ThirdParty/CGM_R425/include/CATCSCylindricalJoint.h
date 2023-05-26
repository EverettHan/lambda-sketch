// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSCylindricalJoint.h
// Header definition of CATCSCylindricalJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSCylindricalJoint_H
#define CATCSCylindricalJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSAxis;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * Cylindrical joint is a type of joint which connects two axes thus two
 * degrees of freedom between them are available. The first one is a rotation
 * around z axis wich is commanded by an angle variable. The second one is a
 * shift along z axis commanded by a length variable.
 * @see #CATCSAxis, #CATCSVariable
 */
class ExportedBySolverInterface CATCSCylindricalJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSCylindricalJoint(CATCSVariable *ipLength = 0, CATCSVariable* ipAngle = 0);

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSCylindricalJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, CATCSVariable *ipLength = 0, CATCSVariable* ipAngle = 0);)

  virtual ~CATCSCylindricalJoint();

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
   * Retrieves the length variable.
   * @return
   *   The variable.
   */
  virtual CATCSVariable *GetLength();

  /**
   * Sets the angle and length variables.
   * @param ipAngle
   *   The variable corresponding to the angle.
   * @param ipLength
   *   The variable corresponding to the length.
   */
  void SetVariables(CATCSVariable *ipAngle, CATCSVariable *ipLength);

private:
  void Init(CATCSVariable *ipLength, CATCSVariable* ipAngle);

  CATCSVariable *_pAngle, *_pLength;
};

//-----------------------------------------------------------------------

#endif
