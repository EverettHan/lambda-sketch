// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATCSGeomDimConstraint.h
// Header definition of CATCSGeomDimConstraint
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2006  Creation:                       Ilia IVANOV
//===================================================================

#ifndef CATCSGeomDimConstraint_H
#define CATCSGeomDimConstraint_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

class CATCSVariable;

//-----------------------------------------------------------------------

/**
 * A basic class for all dimensional constraints.
 */
class ExportedBySolverInterface CATCSGeomDimConstraint : public CATCSGeomConstraint
{
public:
  /**
   * Constructs an instance of the constraint.
   */
  CATCSGeomDimConstraint();

  virtual ~CATCSGeomDimConstraint();

  /**
   * Retrieves value of the dimensional constraint.
   * @see #SetValue
   */
  virtual double GetDimValue() const = 0;

  /**
   * Sets value of the dimensional constraint.
   * @param iValue
   *   A value of the dimensional constraint.
   * @see #GetValue
   */
  virtual void SetDimValue(const double iValue) = 0;
  
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
   * Retrieves dimensional variable of the constraint.
   * @return
   *   A pointer to the variable.
   */
  virtual CATCSVariable *GetVariable();
};

//-----------------------------------------------------------------------

#endif
