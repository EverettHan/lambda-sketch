// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATSimulationMarching.h
// Header definition of CATCATSimulationMarching
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2010  Creation:              Andrey KHARITONCHIK
//===================================================================

#ifndef CATSimulationMarching_H
#define CATSimulationMarching_H

#include "CATCDS.h"

class CATConstraintSolver;
class CATCDSSimulationMarching;
class CATCDSStream;
class CATCSVariable;
class CATSimulationMarchingOutputValidator;

class ExportedBySolverInterface CATSimulationMarching
{
public:
  /**
   * Constructs an instance of the CATSimulationMarching operator.
   * @param ipConstraintSolver
   *   Pointer to the CATConstraintSolver operator. It is used to retrieve
   *   the geometry and compute simulation along the marching parameter.
   * @see #GetConstraintSolver
   */
  CATSimulationMarching(CATConstraintSolver *ipConstraintSolver);

  virtual ~CATSimulationMarching();

  /**
   * Returns the CATConstraintSolver operator which is used for computation.
   * @return
   *   Pointer to the CATConstraintSolver operator.
   */
  CATConstraintSolver *GetConstraintSolver() const;

  /**
   * Sets the marching parameter (time variable). It is used as a start point
   * for the simulation. The marching parameter has to belong its domain.
   * @param ipVariable
   *   Pointer to the marching parameter.
   * @see #SetMarchingInterval
   */
  void SetMarchingParameter(CATCSVariable *ipVariable);

  /**
   * Sets the domain of marching parameter. The simulation will be performed
   * within this domain. It is required that the initial marching parameter
   * belongs to this domain.
   * @param iLower
   *   Lower boundary of the domain.
   * @param iUpper
   *   Upper boundary of the domain.
   * @see #SetMarchingParameter
   */
  void SetMarchingInterval(double iLower, double iUpper);

  /**
   * Performs simulation along the marching parameter within its domain.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the run succeeded,
   *     <li><tt>1</tt> - if the run failed.
   *   </ul>
   * @see #SetMarchingParameter, SetMarchingInterval
   */
  int Run();

  /**
   * Returns the actual domain of marching parameter obtained after the
   * simulation. It is always a subdomain of the initial domain. Has to be
   * called after the Run method.
   * @param oLower
   *   Lower boundary of the domain.
   * @param oUpper
   *   Upper boundary of the domain.
   * @see #Run, #SetMarchingInterval
   */
  void GetResultInterval(double &oLower, double &oUpper) const;

  /**
   * Retrieves the state of geometry which corresponds to the given marching
   * parameter. It is required that the parameter belongs to the actual
   * domain. Has to be called after the Run method.
   * @param iTargetValue
   *   The marching parameter corresponding to the required state.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the function succeeded,
   *     <li><tt>1</tt> - if the function failed.
   *   </ul>
   * @see #Run, #GetResultInterval
   */
  int ComputeState(double iTargetValue);

  /**
   * Sets the maximum value of simulation step for marching parameter (time variable).
   * @param iStep
   *   Maximum value of simulation step.
   */
  void SetSimulationStep(double iStep);

  /**
   * Returns the maximum value of simulation step for marching parameter (time variable)
   * @return
   *   Maximum value of simulation step.
   */
  double GetSimulationStep() const;

  /**
   *  !todo:
   */
  void SetOutputValidator(CATSimulationMarchingOutputValidator *ipOutputValidator);
  int GetLastValidationResult() const;

  /**
   * @nodoc only for internal use
   */
  void SetNbSamplingPoints(int iNbSamplingPoints);

protected:
  /**
  * @nodoc
  * Pointer to implementation class.
  */
  CATCDSSimulationMarching *_pImp;

private:
  CATSimulationMarching(const CATSimulationMarching &);
  void operator = (const CATSimulationMarching &);
};

#endif
