// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSUJoint.h
// Header definition of CATCSUJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2005  Creation                    Andrey CHUGUEV
//===================================================================

#ifndef CATCSUJoint_H
#define CATCSUJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"

class CATCSAxis;

//-----------------------------------------------------------------------

/**
 * U joint is a type of joint which connects two axes thus two degrees of
 * freedom between them are available. The degrees are a rotation around z
 * of the first axis and a rotation around x of the second axis.
 * @see #CATCSAxis
 */
class ExportedBySolverInterface CATCSUJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSUJoint();

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSUJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2);)

  virtual ~CATCSUJoint();

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
   * Retrieves the axes connected.
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
