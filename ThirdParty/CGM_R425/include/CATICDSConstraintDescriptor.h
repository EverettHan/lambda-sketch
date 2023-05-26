#ifndef CATICDSConstraintDescriptor_H
#define CATICDSConstraintDescriptor_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEnums.h"

class CATICDSGeometryLeaf;

/**
 * @SKIP
 *
 * The <tt>CATICDSConstraintDescriptor</tt> class provides detailed information about a constraint.
 * It provides the constraint type,supporting geometries, weight as well as dimensional values in the case of
 * dimensional constraints.
 * It is widely used by auto-constraining
 */
class ExportedByCDSInterface CATICDSConstraintDescriptor
{
public:

  /**
   * Returns the Constraint type
   */
  virtual CATCDSType GetType() const = 0;
  
  /**
   * Returns an array of length 3 which has the constraint's supporting geometries.
   */
  virtual void GetGeometries(CATICDSGeometryLeaf* oapGeometries[MAX_CONSTRAINT_ARGS]) const = 0;
  
  /**
   * Returns the Dimensional value for dimensional constraints. Returns zero otherwise
   */
  virtual double GetValue() const = 0;
  
  /**
   * Return the help parameters for each geometries.
   */
  virtual void GetHelpParams(double oaValues[MAX_CONSTRAINT_ARGS]) const = 0;

  /**
   * Return the help points for each geometries.
   */
  virtual void GetHelpPoints(double oaValues[MAX_CONSTRAINT_ARGS][MAX_PARAM_VALUES]) const = 0;
  
  /**
   * Returns constraint's weigth 
   */
  virtual double GetWeight() const = 0;

  /**
   * Specify constraint's weight
   * 1 by default, if set to negative value the constraint won't be added
   */
  virtual void SetWeight(double iWeight) = 0;

  /**
   * Remove a constraint descriptor
   */
  static void Remove(CATICDSConstraintDescriptor *ipToRemove);

  virtual ~CATICDSConstraintDescriptor() {}
};

#endif
