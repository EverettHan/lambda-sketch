// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSPlanarJoint.h
// Header definition of CATCSPlanarJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSPlanarJoint_H
#define CATCSPlanarJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSAxis;

//-----------------------------------------------------------------------

/**
 * Planar joint is a type of joint which connects two axes thus three degrees
 * of freedom between them are available. The degrees are shifts and a
 * rotation in xy plane.
 * @see #CATCSAxis
 */
class ExportedBySolverInterface CATCSPlanarJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSPlanarJoint();

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSPlanarJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2);)

  virtual ~CATCSPlanarJoint();

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
