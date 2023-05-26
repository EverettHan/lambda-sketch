#ifndef CATICDSGeomDimConstraint_H
#define CATICDSGeomDimConstraint_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSGeomConstraint.h"

class CATICDSVariable;

/**
 * A basic class for all dimensional constraints.
 */
class ExportedByCDSInterface CATICDSGeomDimConstraint : public CATICDSGeomConstraint
{
public:
 
  /**
   * Retrieves value of the dimensional constraint.
   * @see #SetValue
   */
  virtual double GetValue() const = 0;

  /**
   * Sets value of the dimensional constraint.
   * @param iValue
   *   A value of the dimensional constraint.
   * @see #GetValue
   */
  virtual void SetValue(const double iValue) = 0;
  
  /**
   * Retrieves the dimensional variable of the constraint.
   * @return
   *   A pointer to the variable.
   */
  virtual CATICDSVariable *GetVariable() const = 0;

  /**
   * Set the dimensional variable of the constraint.
   * @param ipVariable
   *   A pointer to the variable.
   */
  virtual void SetVariable(CATICDSVariable *ipVariable) = 0;

  virtual ~CATICDSGeomDimConstraint() {}
};

#endif
