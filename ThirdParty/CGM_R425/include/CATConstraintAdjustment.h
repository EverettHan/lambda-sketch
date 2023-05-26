// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATConstraintAdjustment.h
// Header definition of CATConstraintAdjustment
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2004  Creation:                Alexey Ershov
//===================================================================

#ifndef CATConstraintAdjustment_H
#define CATConstraintAdjustment_H

#include "CATConstraintSolver.h"

class CATCSNEntity;
class CATCSNRigidSet;
class CATCSNGeometryLeaf;
class CATCSNGeomConstraint;
//-----------------------------------------------------------------------

class ExportedBySolverInterface CATConstraintAdjustment : public CATConstraintSolver
{
public:
  /**
   *  Default constructor.
   */
  CATConstraintAdjustment(CATSoftwareConfiguration * ipSoftwareConfiguration);

  /**
   *  Destructor.
   */
  virtual ~CATConstraintAdjustment();

  /**
   *  Add rigid set to solver.
   *  @param ipRigidSet
   *    rigid set callback
   *  @return
   *    created rigid set node
   */
  CATCSNRigidSet* AddRigidSet(CATCSRigidSet *ipRigidSet);

  /**
   *  Add geometry to given rigid set.
   *  @param ipGLeaf
   *    geometry callback
   *  @param ipRigidSet
   *    rigid set node
   *  @return
   *    created geometry node
   */
  CATCSNGeometryLeaf* AddGeometry(
    CATCSGeometryLeaf *ipGLeaf,
    CATCSNRigidSet    *ipRigidSet);

  /**
   *  Positioning geometry to given rigid set.
   *  @param ipGLeaf
   *    geometry node
   *  @param ipRigidSet
   *    rigid set node
   *  @return
   *    TRUE if succeed
   */
  CATCDSBoolean InitRigidSet(
    CATCSNGeometryLeaf *ipGLeaf,
    CATCSNRigidSet     *ipRigidSet);

  /**
   *  Add constraint to solver.
   *  @param ipConstraint
   *    constraint callback
   *  @param ipGLeaf1
   *    first constraint argument
   *  @param ipGLeaf2
   *    second constraint argument
   *  @return
   *    created constraint node
   */
  CATCSNGeomConstraint* AddConstraint(
    CATCSGeomConstraint *ipConstraint,
    CATCSNGeometryLeaf  *ipGLeaf1,
    CATCSNGeometryLeaf  *ipGLeaf2);

  /**
   *  Fix rigid set.
   *  @param ipRigidSet
   *    rigid set to be fixed
   */
  void FixRigidSet(CATCSNRigidSet *ipRigidSet);

  /**
   *  Add spring to solver.
   *  @param ipSpring
   *    spring callback
   *  @param ipGLeaf1
   *    first spring argument
   *  @param ipGLeaf2
   *    second spring argument
   *  @param iStiffness
   *    iStiffness of the spring
   *  @return
   *    created constraint node
   */
  CATCSNGeomConstraint* AddSpring(CATCSGeomConstraint *ipSpring,
                                  CATCSNGeometryLeaf  *ipGLeaf1,
                                  CATCSNGeometryLeaf  *ipGLeaf2,
                                  double iStiffness);

  /**
   *  Get constraint status.
   *  @param ipConstraint
   *    constraint to be checked
   *  @return
   *    current status
   */
  CATCStatus GetStatus(CATCSNGeomConstraint *ipConstraint);

  /**
   *  Remove node from solver.
   *  @param ipNode
   *    node to be removed
   */
  void EraseAny(CATCSNEntity *ipNode);

  /**
   *  Remove rigid set from solver.
   *  @param ipRigidSet
   *    rigid set node to be removed
   */
  void Erase(CATCSNRigidSet *ipRigidSet);

  /**
   *  Remove geometry from solver.
   *  @param ipGLeaf
   *    geometry node to be removed
   */
  void Erase(CATCSNGeometryLeaf *ipGLeaf);

  /**
   *  Remove constraint from solver.
   *  @param ipConstraint
   *    constraint node to be removed
   */
  void Erase(CATCSNGeomConstraint *ipConstraint);

private:
  CATConstraintAdjustment();
  CATConstraintAdjustment(const CATConstraintAdjustment &);
  void operator = (const CATConstraintAdjustment &);
};

//-----------------------------------------------------------------------

#endif
