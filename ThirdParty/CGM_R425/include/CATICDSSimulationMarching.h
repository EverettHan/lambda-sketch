#ifndef CATICDSSimulationMarching_H
#define CATICDSSimulationMarching_H

// COPYRIGHT DASSAULT SYSTEMES  2013

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"

class CATICDS;
class CATICDSVariable;

/**
 * @SKIP
 *
 */
class ExportedBySolverInterface CATICDSSimulationMarching
{
public:

  //-------------------------------------------------------
  //              Creation and destruction methods
  //-------------------------------------------------------

  /**
   * Static method that creates an instance of the CATICDSSimulationMarching operator.
   * @param ipSolver
   *   Pointer to the CATICDS solver. It is used to retrieve
   *   the geometry and compute simulation along the marching parameter.
   */
  static CATICDSSimulationMarching* Create(CATICDS *ipSolver);

  /**
   * Static method that deletes an instance of the CATICDS Interface.
   */
  static void Remove(CATICDSSimulationMarching *ipSolver);
  
  //-------------------------------------------------------
  //                 Operator parameters
  //-------------------------------------------------------
  
  /**
   * Returns the constraint solver which is used for computation.
   * @return
   *   Pointer to the CATICDS operator.
   */
  virtual CATICDS* GetSolver() const = 0;

  /**
   * Sets the marching parameter (time variable). It is used as a start point
   * for the simulation. The marching parameter has to belong its domain.
   * @param ipVariable
   *   Pointer to the marching parameter.
   * @see #SetMarchingInterval
   */
  virtual void SetMarchingParameter(CATICDSVariable *ipVariable) = 0;

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
  virtual void SetMarchingInterval(double iLower, double iUpper) = 0;

  /**
   * Sets the maximum value of simulation step for marching parameter (time variable).
   * @param iStep
   *   Maximum value of simulation step.
   */
  virtual void SetSimulationStep(double iStep) = 0;

  /**
   * Returns the maximum value of simulation step for marching parameter (time variable)
   * @return
   *   Maximum value of simulation step.
   */
  virtual double GetSimulationStep() const = 0;
  
  /**
   * Specify the number of points that will be used for initial sampling.
   * @param iNbSamplingPoints
   *    Number of points to use for sampling.
   */
  virtual void SetNbSamplingPoints(int iNbSamplingPoints) = 0;
  
  //-------------------------------------------------------
  //                   Operator methods
  //-------------------------------------------------------
  
  /**
   * Performs simulation along the marching parameter within its domain.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the run succeeded,
   *     <li><tt>1</tt> - if the run failed.
   *   </ul>
   * @see #SetMarchingParameter, SetMarchingInterval
   */
  virtual int Run() = 0;

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
  virtual void GetResultInterval(double &oLower, double &oUpper) const = 0;

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
  virtual int ComputeState(double iTargetValue) = 0;

  virtual ~CATICDSSimulationMarching() {}
};

#endif
