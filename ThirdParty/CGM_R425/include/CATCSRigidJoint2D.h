// COPYRIGHT Dassault Systemes 2013
//===================================================================
//
// CATCSRigidJoint2D.h
// Header definition of CATCSRigidJoint2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2013  Creation                                       FCX
//===================================================================

#ifndef CATCSRigidJoint2D_H
#define CATCSRigidJoint2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint2D.h"

class CATCSAxis2D;

//-----------------------------------------------------------------------

/**
 * 2D Rigid joint is a type of joint which connects two axes thus no degrees of
 * freedom between them are available.
 * @see #CATCSAxis2D, #CATCSVariable
 */
class ExportedBySolverInterface CATCSRigidJoint2D : public CATCSSimpleJoint2D
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSRigidJoint2D();

  virtual ~CATCSRigidJoint2D();

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
};

//-----------------------------------------------------------------------

#endif
