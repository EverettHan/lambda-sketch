// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATCSSymmetricJKJoint.h
// Header definition of CATCSSymmetricJKJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  Oct 2007  Creation                      Ilia Ivanov
//===================================================================

#ifndef CATCSSymmetricJKJoint_H
#define CATCSSymmetricJKJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSSimpleJoint.h"
#include "CATCDSDeprecated.h"

class CATCSAxis;
class CATCSPlane;

//-----------------------------------------------------------------------

/**
 * The joint make two axes symmetric with respect to a plane. The symmetry is
 * created between y and z axes.
 * @see #CATCSAxis, #CATCSPlane
 */
class ExportedBySolverInterface CATCSSymmetricJKJoint : public CATCSSimpleJoint {
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSSymmetricJKJoint();

  CATCDS_DEPRECATED("28/10/2016", "Remove useless rigid sets arguments", CATCSSymmetricJKJoint(CATCSRigidSet *ipRigidSet1, CATCSRigidSet *ipRigidSet2);)

  virtual ~CATCSSymmetricJKJoint();

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
   * Sets the axes to be symmetric.
   * @param ipAxis1
   *   The first axis.
   * @param ipAxis2
   *   The second axis.
   * @param ipPlane
   *   The symmetry plane.
   * @see #GetGeometries
   */
  virtual void SetGeometries(CATCSAxis *ipAxis1, CATCSAxis *ipAxis2, CATCSPlane *ipPlane);

  /**
   * Retrieves the axes being symmetric.
   * @param opAxis1
   *   The first axis.
   * @param opAxis2
   *   The second axis.
   * @param opPlane
   *   The symmetry plane.
   * @see #SetGeometries
   */
  virtual void GetGeometries(CATCSAxis *&opAxis1, CATCSAxis *&opAxis2, CATCSPlane *&opPlane);

  /**
   * Sets the symmetry plane.
   * @param ipPlane
   *   The symmetry plane.
   * @see #GetPlane
   */
  void SetPlane(CATCSPlane *ipPlane);

  /**
   * Retrieves the symmetry plane.
   * @return
   *   The symmetry plane.
   * @see #SetPlane
   */
  CATCSPlane* GetPlane() const;
};

//-----------------------------------------------------------------------

#endif
