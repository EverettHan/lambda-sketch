// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSPrismaticJoint.h
// Header definition of CATCSPrismaticJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSPrismaticJoint_H
#define CATCSPrismaticJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSAxis;
class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * Prismatic joint is a type of joint which connects two axes thus only one
 * degree of freedom between them is available. The degree is a shift along z
 * axis wich is commanded by a length variable. No relative rotations are
 * available.
 * @see #CATCSAxis, #CATCSVariable
 */
class ExportedBySolverInterface CATCSPrismaticJoint : public CATCSSimpleJoint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSPrismaticJoint(CATCSVariable *ipLength = 0);

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSPrismaticJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2, CATCSVariable *ipLength = 0);)

  virtual ~CATCSPrismaticJoint();

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
   * Retrieves the length variable.
   * @return
   *   The variable.
   */
  virtual CATCSVariable *GetLength();

  /**
   * Sets the length variable.
   * @param ipLength
   *   The length variable.
   */
  virtual void SetLength(CATCSVariable *ipLength);

private:
  void Init(CATCSVariable *ipLength);

  CATCSVariable *_pLength;
};

//-----------------------------------------------------------------------

#endif
