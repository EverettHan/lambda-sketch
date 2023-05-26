// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSCVJoint.h
// Implementation of CATCSCVJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  May 2005  Creation                    Andrey CHUGUEV
//===================================================================

#ifndef CATCSCVJoint_H
#define CATCSCVJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSJoint.h"

class CATCSUJoint;

//-----------------------------------------------------------------------

/**
 * CV joint is a type of joint which connects two U joints. Thus four degrees
 * of freedom are available.
 * @see #CATCSUJoint
 */
class ExportedBySolverInterface CATCSCVJoint : public CATCSJoint
{
public:
  /**
   * Constructs an instance of the joint.
   * @param ipUJoint1
   *   The first U joint.
   * @param ipUJoint2
   *   The second U joint.
   * @see #GetSubJoints
   */
  CATCSCVJoint(CATCSUJoint *ipUJoint1, CATCSUJoint *ipUJoint2);

  virtual ~CATCSCVJoint();

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
   * Retrieves the subjoints connected.
   * @param opUJoint1
   *   The first U joint.
   * @param opUJoint2
   *   The second U joint.
   */
  virtual void GetSubJoints(CATCSUJoint *&opUJoint1, CATCSUJoint *&opUJoint2);
private:
  CATCSUJoint *_pUJoint1, *_pUJoint2;
};

//-----------------------------------------------------------------------

#endif
