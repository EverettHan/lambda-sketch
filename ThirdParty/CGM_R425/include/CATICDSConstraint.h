#ifndef CATICDSConstraint_H
#define CATICDSConstraint_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEntity.h"

/**
 * A basic class for all constraints.
 */
class ExportedByCDSInterface CATICDSConstraint : public CATICDSEntity
{
public:

  /**
   * Returns the status of a constraint.
   * @return
   *   The status of the constraint.
   */
  virtual CATCDSStatus GetStatus() = 0;

  /**
   * DEPRECATED : use method which computes all the dimensional values (double oConstraintValues[6])
   * Calculates constraint discrepancy.
   * If dimensional constraint is not satisfied, it also calculates value
   * which makes constraint satisfied.
   * @param ipConstraint
   *   A pointer to the constraint callback.
   * @param oConstraintDiscrepancy
   *   The value of constraint discrepancy
   * @param oConstraintValues
   *   The value for dimension to satisfy constraint
   * @param oNbOfHelpPointValues
   *   The number of coordinates of the help points.
   * @param oHelpPointValues
   *   The coordinates of the help points.
   * @return
   *   The status of the constraint.
   *
   * @SKIP
   */
#if !defined(_EMSCRIPTEN_SOURCE)
  virtual CATCDSDiscrepancyStatus EvalDiscrepancy(double &oConstraintDiscrepancy, double &oConstraintValue, int oNbOfHelpPointValues[MAX_CONSTRAINT_PARAMS] = 0, double oHelpPointValues[MAX_CONSTRAINT_PARAMS*MAX_PARAM_VALUES] = 0) = 0;
#else
  /**
   * @RETURNNAME status
   */
  virtual CATCDSDiscrepancyStatus EvalDiscrepancy(double &oConstraintDiscrepancy, double &oConstraintValue) = 0;
#endif

  /**
  * Calculates constraint discrepancy.
  * If dimensional constraint is not satisfied, it also calculates values
  * which makes constraint satisfied.
  * @param ipConstraint
  *   A pointer to the constraint callback.
  * @param oConstraintDiscrepancy
  *   The value of constraint discrepancy
  * @param oConstraintValues
  *   The value for dimension to satisfy constraint
  * @param oNbOfHelpPointValues
  *   The number of coordinates of the help points.
  * @param oHelpPointValues
  *   The coordinates of the help points.
  * @return
  *   The status of the constraint.
  *
  * @SKIP
  */
#if !defined(_EMSCRIPTEN_SOURCE)
  virtual CATCDSDiscrepancyStatus EvalDiscrepancyValues(double &oConstraintDiscrepancy, double oConstraintValues[6], int oNbOfHelpPointValues[MAX_CONSTRAINT_PARAMS] = 0, double oHelpPointValues[MAX_CONSTRAINT_PARAMS*MAX_PARAM_VALUES] = 0) = 0;
#else
  /**
  * @RETURNNAME status
  */
  virtual CATCDSDiscrepancyStatus EvalDiscrepancyValues(double &oConstraintDiscrepancy, double oConstraintValues[6]) = 0;
#endif

  /**
   * Returns the redundancy status of a the constraint and additional information.
   * A constraint is called redundant if its removal does not add any degree
   * of freedom to the geometric objects.
   * @param onRedundantConstraints
   *   Size of oaRedundantConstraints.
   * @param oaRedundantConstraints
   *   If status is rsPARTIALLYREDUNDANT, the list contains pointers to the callbacks
   *   of constraints which become fully redundant due to the presence of the
   *   current constraint.
   * @param onImpliedConstraints
   *   Size of oaImpliedConstraints.
   * @param oaImpliedConstraints
   *   If status is rsPARTIALLYREDUNDANT, the list contains pointers to the callbacks
   *   of constraints which make the constraints of the list oapFullyRedConstraints
   *   fully redundant.
   *   If the status is rsFULLYREDUNDANT, the list contains pointers to the callbacks
   *   of constraints which make the current constraint fully redundant.
   * @return status of the current constraint
   *   The status of the constraint is defined as the first appropriate value.
   * 
   * @SIZE oaRedundantConstraints onRedundantConstraints
   * @SIZE oaImpliedConstraints onImpliedConstraints
   * @RETURNNAME status
   */
  virtual CATCDSRedundancyStatus IsRedundant(int &onRedundantConstraints, CATICDSConstraint** &oaRedundantConstraints, int &onImpliedConstraints, CATICDSConstraint** &oaImpliedConstraints) = 0;

  virtual ~CATICDSConstraint() {}
};

#endif
