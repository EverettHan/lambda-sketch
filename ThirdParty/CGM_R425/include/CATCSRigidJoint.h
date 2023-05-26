// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSRigidJoint.h
// Header definition of CATCSRigidJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSRigidJoint_H
#define CATCSRigidJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"

class CATCSAxis;

//-----------------------------------------------------------------------

/**
 * Rigid joint is a type of joint which connects two axes thus no degrees of
 * freedom between them are available.
 * @see #CATCSAxis
 */
class ExportedBySolverInterface CATCSRigidJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSRigidJoint();

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSRigidJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2);)

  virtual ~CATCSRigidJoint();

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
   * Sets the axes to be rigid.
   * @param ipAxis1
   *   The first axis.
   * @param ipAxis2
   *   The second axis.
   * @see #GetGeometries
   */
  virtual void SetGeometries(CATCSAxis *ipAxis1, CATCSAxis *ipAxis2);

  /**
   * Retrieves the axes to be rigid.
   * @param opAxis1
   *   The first axis.
   * @param opAxis2
   *   The second axis.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSAxis *&opAxis1, CATCSAxis *&opAxis2);
};

//-----------------------------------------------------------------------

#endif
