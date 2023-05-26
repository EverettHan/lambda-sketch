// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSRevoluteJoint2D.h
// Header definition of CATCSRevoluteJoint2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2013  Creation                                       FCX
//===================================================================

#ifndef CATCSRevoluteJoint2D_H
#define CATCSRevoluteJoint2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint2D.h"

class CATCSAxis2D;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * 2D Revolute joint is a type of joint which connects two 2D axes thus only one
 * degree of freedom between them is available. The degree is a rotation around
 * the sktech normal wich is commanded by an angle variable. No relative translations
 * are available.
 * @see #CATCSAxis2D, #CATCSVariable
 */
class ExportedBySolverInterface CATCSRevoluteJoint2D : public CATCSSimpleJoint2D
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSRevoluteJoint2D(CATCSVariable *ipAngle = 0);

  virtual ~CATCSRevoluteJoint2D();

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
  CATCSVariable *_pAngle;
};

//-----------------------------------------------------------------------

#endif
