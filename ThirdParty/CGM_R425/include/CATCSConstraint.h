// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSConstraint.h
// Header definition of CATCSConstraint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2005  Creation:                       Ilia IVANOV
//===================================================================
#ifndef CATCSConstraint_H
#define CATCSConstraint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSEntity.h"
#include "CATCDSListP.h"

//-----------------------------------------------------------------------

/**
 * A basic class for all constraints.
 */
class ExportedBySolverInterface CATCSConstraint : public CATCSEntity
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSConstraint();

  virtual ~CATCSConstraint();

  /**
   * Checks whether the entity is matched to a specific type. The entity can
   * be casted to a corresponding class if the matching is successful.
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
   * Activates or unactivate the constraint.
   * @see #GetActivity
   */
  virtual void SetActivity(CATCDSBoolean iActivity);

  /**
   * Retrieves the activity status of this constraint.
   * @return
   *   The constraint activity
   * @see #SetActivity
   */
  virtual CATCDSBoolean GetActivity() const;

  double GetStiffness() const;

protected:
  CATCDSBoolean _bActive;
};

CATCDSLISTP_DECLARE_EXPORTED(CATCSConstraint, ExportedBySolverInterface);

//-----------------------------------------------------------------------

#endif
