// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSFullDOFJoint2D.h
// Header definition of CATCSFullDOFJoint2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2013  Creation                                       FCX
//===================================================================

#ifndef CATCSFullDOFJoint2D_H
#define CATCSFullDOFJoint2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint2D.h"

class CATCSAxis2D;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * FullDOF2D joint is a type of joint which connects two 2D axes thus 3 degrees
 * of freedom between them are available. The first degree is a rotations in 
 * the 2d space of the sketch commanded by an angle variable. The last 2 degrees
 * are shifts along x, y axes commanded by length variables.
 * @see #CATCSAxis2D, #CATCSVariable
 */
class ExportedBySolverInterface CATCSFullDOFJoint2D : public CATCSSimpleJoint2D
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSFullDOFJoint2D();

  /**
   * Constructs an instance of the joint with variables.
   */
  CATCSFullDOFJoint2D(CATCSVariable *ipAngle, CATCSVariable *ipLength1, CATCSVariable *ipLength2);

  virtual ~CATCSFullDOFJoint2D();

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
  virtual void SetGeometries(CATCSAxis2D *ipAxis1, CATCSAxis2D *ipAxis2);

  /**
   * Retrieves the axes to be connected.
   * @param opAxis1
   *   The first axis.
   * @param opAxis2
   *   The second axis.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSAxis2D *&opAxis1, CATCSAxis2D *&opAxis2);

  /**
   * Sets the length and angle variables. It replaces the internal variables created by
   * the joint. If one of the arguments is null then no variables will be set
   * and the internal variables will be restored.
   * @param ipLength1
   *   The first length variable.
   * @param ipLength2
   *   The second length variable.
   * @param ipAngle
   *   The angle variable.
   * @see #GetVariables
   */
  virtual void SetVariables(CATCSVariable *ipLength1, CATCSVariable *ipLength2, CATCSVariable *ipAngle);

  /**
   * Retrieves the length and angle variables. If no variables were set then it returns
   * the internal variables created by the joint. Note, that the internal
   * variables will be destroyed by the joint. Thus, do not use the internal
   * variables after the joint has been destroyed.
   * @param opLength1
   *   The first length variable.
   * @param opLength2
   *   The second length variable.
   * @param opAngle
   *   The angle variable.
   * @see #SetVariables
   */
  virtual void GetVariables(CATCSVariable *&opLength1, CATCSVariable *&opLength2, CATCSVariable *&opAngle);

private:
  CATCSVariable * _apVariables[3];
};

//-----------------------------------------------------------------------

#endif
