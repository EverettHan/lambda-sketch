// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSScrewJoint.h
// Header definition of CATCSScrewJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSScrewJoint_H
#define CATCSScrewJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSAxis;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * Screw joint is a type of joint which connects two axes thus only one degree
 * of freedom between them is available. The degree is a screw movement around
 * z axis wich is commanded by an angle and a length variables.
 * @see #CATCSAxis, #CATCSVariable
 */
class ExportedBySolverInterface CATCSScrewJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSScrewJoint(CATCSVariable *ipLength = 0, CATCSVariable *ipAngle = 0);

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSScrewJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, CATCSVariable *ipLength = 0, CATCSVariable *ipAngle = 0);)

  virtual ~CATCSScrewJoint();

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
   * Sets the pitch of a screw.
   * @param iPitch
   *   The pitch.
   * @see #GetPitch
   */
  virtual void SetPitch(double iPitch);

  /**
   * Retrieves the pitch of a screw.
   * @return
   *   The pitch.
   * @see #SetPitch
   */
  virtual double GetPitch();

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
  void Init(CATCSVariable *ipLength, CATCSVariable *ipAngle);

  CATCSVariable *_pAngle, *_pLength;
  double _dPitch;
};

//-----------------------------------------------------------------------

#endif
