// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSCableJoint.h
// Header definition of CATCSCableJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSCableJoint_H
#define CATCSCableJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSJoint.h"

class CATCSPrismaticJoint;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * Cable joint is a type of joint which connects two prismatic joints. Shifts
 * of the prismatic joints are linearly dependent with a specific ratio. Thus
 * only one degree of freedom is available.
 * @see #CATCSPrismaticJoint
 */
class ExportedBySolverInterface CATCSCableJoint : public CATCSJoint
{
public:
  /**
   * Constructs an instance of the joint.
   * @param ipPrismatic1
   *   The first prismatic joint.
   * @param ipPrismatic2
   *   The second prismatic joint.
   * @see #GetSubJoints
   */
  CATCSCableJoint(CATCSPrismaticJoint *ipPrismatic1, CATCSPrismaticJoint *ipPrismatic2);

  virtual ~CATCSCableJoint();

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
   * @param opPrismatic1
   *   The first prismatic joint.
   * @param opPrismatic2
   *   The second prismatic joint.
   */
  virtual void GetSubJoints(CATCSPrismaticJoint *&opPrismatic1, CATCSPrismaticJoint *&opPrismatic2);

  /**
   * Sets the ratio of shifts.
   * @param iRatio
   *   The ratio.
   * @see #GetRatio
   */
  virtual void SetRatio(double iRatio);

  /**
   * Retrieves the ratio of shifts.
   * @return
   *   The ratio.
   * @see #SetRatio
   */
  virtual double GetRatio();

  /**
   * Retrieves the length variables of the corresponding prismatic joints.
   * @param opLength1
   *   The variable of the first prismatic joint.
   * @param opLength2
   *   The variable of the second prismatic joint.
   */
  virtual void GetLengths(CATCSVariable *&opLength1, CATCSVariable *&opLength2);
private:
  CATCSPrismaticJoint *_pPrismatic1, *_pPrismatic2;
  double _dRatio;
};

//-----------------------------------------------------------------------

#endif
