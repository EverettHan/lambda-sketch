// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSJoint.h
// Header definition of CATCSJoint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSJoint_H
#define CATCSJoint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSConstraint.h"

//-----------------------------------------------------------------------

/**
 * Joint is a type of constraint which connects two or more rigid geometries.
 * Generally all allowed degrees of freedom are connected with variables. Thus
 * it is possible to control movement between the geometries. CATCSJoint is a
 * basic class which is inherited by specific joints. It should not be created
 * directly.
 */
class ExportedBySolverInterface CATCSJoint : public CATCSConstraint
{
public:
  /**
   * Constructs an instance of the joint.
   */
  CATCSJoint();

  virtual ~CATCSJoint();

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
   * @nodoc
   */
  virtual CATCDSBoolean GetOwnsVariables() const;
};

//-----------------------------------------------------------------------

#endif
