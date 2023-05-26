// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATCSCoincidentJoint.h
// Header definition of CATCSCoincidentJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2006  Creation                    Andrey CHUGUEV
//===================================================================

#ifndef CATCSCoincidentJoint_H
#define CATCSCoincidentJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"

class CATCSAxis;

//-----------------------------------------------------------------------

/**
 * Coincident joint is a type of joint which connects two axes thus no degrees
 * of freedom between them are available. Moreover, the axes have to be
 * coincident.
 * @see #CATCSAxis
 */
class ExportedBySolverInterface CATCSCoincidentJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSCoincidentJoint();

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSCoincidentJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2);)

  virtual ~CATCSCoincidentJoint();

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
   * Sets the axes to be coinsident.
   * @param ipAxis1
   *   The first axis.
   * @param ipAxis2
   *   The second axis.
   * @see #GetGeometries
   */
  virtual void SetGeometries(CATCSAxis *ipAxis1, CATCSAxis *ipAxis2);

  /**
   * Retrieves the axes to be coinsident.
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
