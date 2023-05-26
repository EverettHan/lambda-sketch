#ifndef CATICDS_H
#define CATICDS_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"

class CATICDSFactory;
class CATICDSVariable;
class CATICDSGeometry;
class CATICDSGeometryLeaf;
class CATICDSConstraintDescriptor;

/**
 * Class to create instances of geometric constraint solver called CDS.
 * <b>Role</b>: CATICDS is used to position geometric objects (such as points,
 * lines, planes, and others) in 3D space under logical and dimensional
 * constraints (such as coincidence, tangency, distance, and others).
 * Besides the main functionality, it implements also dynamic evaluation,
 * degrees of freedom analysis, overdefined diagnostics, kinematic simulation,
 * and other actions.
 * The geometric problem is formulated in terms of objects (instances of
 * classes derived from <tt>CATICDSGeometry</tt>) and constraints (instances of
 * classes derived from <tt>CATICDSGeomConstraint</tt>), also called callbacks
 * (since usually they are implemented the corresponding interface on the
 * application side).
 * They are passed to the solver with <tt>AddXXX</tt> methods, then
 * the method <tt>Run</tt> should be called to position of given objects
 * under given set of constraints.
 * Once a solution is found, the solver calls the corresponding methods
 * of each object to re-position it or to change its shape and dimensions.
 * After <tt>Run</tt>, some <tt>GetXXX</tt> methods can be called to gather
 * the information on objects and constraint statuses, their degrees of
 * freedom, etc.
 * <tt>SetXXX</tt> methods can be called before <tt>Run</tt> to specify
 * different solving modes.
 * All objects and constraints passed to the solver will be automatically
 * deleted when the instance of the solver is deleted.
 */
class ExportedByCDSInterface CATICDS
{
public:

  //-------------------------------------------------------
  //              Creation and destruction methods
  //-------------------------------------------------------

  /**
   * Static method that creates an instance of the CATICDS Interface.
   */
  static CATICDS * Create();

  /**
   * Static method that deletes an instance of the CATICDS Interface.
   */
  static void Remove(CATICDS *ipSolver);

  //-------------------------------------------------------
  //                  Solver parameters
  //-------------------------------------------------------
  
  /**
   * Retreive the level of the constraint solver.
   */
  virtual unsigned int GetCDSLevel() const = 0;
  
  /**
   * Set the level of the constraint solver.
   * @param iLevel
   *    the level of the solver
   */
  virtual void SetCDSLevel(unsigned int iLevel) = 0;

  /**
   * Retrieves current tolerances.
   * The tolerances define the minimal geometric discrepancy
   * for a constraint to do not consider it satisfied.
   * Linear tolerance defines the minimal distance between two points
   * to consider them different.
   * Angular tolerance defines the minimal angular deviation (in radians)
   * between two directions (unit vectors) to consider them different.
   * Both linear and angular tolerances are used to validate complex
   * constraints like line-curve tangency or line-plane distance.
   * Default values for both linear and angular tolerances is <tt>1e-4</tt>.
   * @param oLinearTolerance
   *   Linear tolerance (a positive real value).
   * @param oAngularTolerance
   *   Angular tolerance (a positive real value in radians).
   * @see #SetTolerances
   */
  virtual void GetTolerances(double &oLinearTolerance, double &oAngularTolerance) const = 0;

  /**
   * Sets tolerances.
   * @param iLinearTolerance
   *   Linear tolerance (a positive real value).
   * @param iAngularTolerance
   *   Angular tolerance (a positive real value in radians).
   * @see #GetTolerances
   */
  virtual void SetTolerances(double iLinearTolerance, double iAngularTolerance) = 0;

  /**
   * Estimates actual model size.
   * @return
   *   estimation of the actual model size, rounded up to the nearest degree of 10.
   */
  virtual double GetActualModelSize() const = 0;

  /**
   * Gets the current output mode.
   * @return iOutputMode
   *   Output mode.
   * @see #SetOutputMode
   */
  virtual CATCDSOutputMode GetOutputMode() const = 0;

  /**
   * Sets the output mode.
   * This mode defines how the solving transformations (which makes all
   * constraints satisfied) will be applied to the geometric objects
   * and rigid sets. By default omCALLBACK_ROOT_ELEMENTS is used.
   * @param iOutputMode
   *   Output mode.
   */
  virtual void SetOutputMode(CATCDSOutputMode iOutputMode) = 0;

  /**
   * Sets the solver mode that preserves chirality or ignore it.
   * Preserving chirality means keeping the relative positions of objects
   * connected by constraints.
   * E.g. a 2D point cannot jump over 2D line is there is a distance
   * constraint between them; if a 2D point is outside a 2D circle, it
   * cannot move inside if there is distance constraint between them, etc.
   * @param iMode
   *   Chirality mode.
   * @see #ChangeChirality
   */
  virtual void SetPreserveChiralityMode(CATCDSChiralityMode iMode) = 0;

    /**
   * Get the solver mode that preserves chirality or ignore it.
   * Preserving chirality means keeping the relative positions of objects
   * connected by constraints.
   * E.g. a 2D point cannot jump over 2D line is there is a distance
   * constraint between them; if a 2D point is outside a 2D circle, it
   * cannot move inside if there is distance constraint between them, etc.
   * @return Chirality mode.
   * @see #ChangeChirality
   */
  virtual CATCDSChiralityMode GetPreserveChiralityMode() const = 0;

  //-------------------------------------------------------
  //                   Operator methods
  //-------------------------------------------------------
  
  /**
   * Computes the transformations and objects' parameters that satisfy
   * the imposed constraints.
   * This method also performs dynamic move and simulation, if
   * <tt>SetDynamicMove</tt> or <tt>SetTargetValues</tt> methods were
   * called before it.
   * The transformations and changes of parameters apllied to objects
   * during the <tt>Run</tt> method can be inverted with the call to
   * <tt>UndoRun</tt>.
   * @return
   *   The current solver state.
   *   <br><b>Legal values</b>:
   *   0 (succeeded)        - all constraints were satisfied,
   *   1 (failed)           - solving failed, no solution was found,
   *   2 (partially solved) - the number of broken constraints was reduced, but the entire geometry was not solved,
   *   3 (inconsistent)     - the problem is definitely inconsistent, though some part of it was probably solved.
   * @see #SetDynamicMove, #SetTargetValues, #UndoRun
   */
  virtual int Run() = 0;

  /**
   * Makes a rollback to the state that was before the last call to <tt>Run</tt>.
   * @see #Run
   */
  virtual void UndoRun() = 0;

  /**
   * Retreive the solver's factory
   */
  virtual CATICDSFactory* GetFactory() const = 0;
  
  //-------------------------------------------------------
  //                        Update  
  //-------------------------------------------------------

  /**
  * Reset all knowledge from previous run.
  *
  */
  virtual void ResetHistory() const = 0;
  
  /**
   * Sets the Update mode, umEVALUATE is used by default.
   * @param iUpdateMode
   *   Update mode.
   */
  virtual void SetUpdateMode(CATCDSUpdateMode iUpdateMode) = 0;

    /**
   * Get the Update mode, umEVALUATE is used by default.
   * @return
   *   Update mode.
   */
  virtual CATCDSUpdateMode GetUpdateMode() const = 0;

  /**
   * Sets solving mode for Update functionality, Minimum move is used by default.
   * @param iMode
   *   Solving mode.
   */
  virtual void SetSolvingMode(CATCDSSolvingMode iMode) = 0;

  /**
   * Get solving mode for Update functionality, Minimum move is used by default.
   * @return
   *   Solving mode.
   */
  virtual CATCDSSolvingMode GetSolvingMode() const = 0;

  /**
   * Sets the partial solving mode.
   * This mode defines how CDS will solve inconsistent problems: there is always
   * the tradeoff between performance and quality. psALWAYS is used by default.
   * @param iPSMode
   *   Partial solving mode.
   */
  virtual void SetPartialSolvingMode(CATCDSPartialSolvingMode iPSMode) = 0;

  /**
  * Get the partial solving mode.
  * This mode defines how CDS will solve inconsistent problems: there is always
  * the tradeoff between performance and quality. psALWAYS is used by default.
  * @return
  *   Partial solving mode.
  */
  virtual CATCDSPartialSolvingMode GetPartialSolvingMode() const = 0;

  //-------------------------------------------------------
  //                 Move under constraints 
  //-------------------------------------------------------
  
  /**
   * Resets the dynamic move mode.
   * Dynamic move is a special solving mode: the solver will move given
   * objects according to given transformations or to change their parameters
   * (radii). This movement or change will be continuous, all imposed
   * constraints will be kept satisfied during dynamic move.
   * The dynamic move will stop either after achieving specified
   * transformations or parameters, either after the movement to a position
   * where it is impossible to continue the smooth movement.
   * Dynamic move is an iterative process - the transformations are
   * accumulated in objects (each time after <tt>Run</tt> they are applied
   * from the position when the dynamic move was started.
   * From the application view it corresponds to keeping a mouse button
   * pressed while a geometry is dragged. When the button is released,
   * a user can select another geometry to drag. That's why the <tt>Reset</tt>
   * method is needed - it resets the accumulated transformations and allowed
   * to start the dynamic move of other group of objects.
   */
  virtual void Reset() = 0;

  /**
   * Sets the solving mode for dynamic move and kinematics.
   * @param iMode
   *    Move mode.
   * @see #SetDynamicMove, #SetTargetValues
   */
  virtual void SetDynamicMoveMode(CATCDSMoveMode iMode) = 0;

  /**
   * Get the solving mode for dynamic move and kinematics.
   * @return
   *    Move mode.
   * @see #SetDynamicMove, #SetTargetValues
   */
  virtual CATCDSMoveMode GetDynamicMoveMode() const = 0;

  //-------------------------------------------------------
  //                    Diagnostic
  //-------------------------------------------------------
  
  /**
   * Validate current geometry
   * @return
   *    TRUE if geometry satisfied, otherwise FALSE
   */
  virtual CATCDSBoolean IsGeometrySatisfied() = 0;

  /**
   * Sets the diagnostics mode, dmNOTSOLVED is used but default.
   * @param iCATDiagMode
   *    Diagnostic mode.
   */
  virtual void SetDiagnosticsMode(CATCDSDiagMode iDiagMode) = 0;

  /**
   * Returns the diagnostics mode
   * @return Diagnostic mode.
   */
  virtual CATCDSDiagMode GetDiagnosticsMode() const = 0;
  
  /**
   * Sets the Variables Inter-dependency mode, vmNEVER is used by default.
   * @param iMode
   *   Variable Inter-dependency mode.
   */
  virtual void SetVarDependencyMode(CATCDSVarDepMode iMode) = 0;
  
  /**
  * Get the Variables Inter-dependency mode.
  * @return
  *   <br><b>legal values</b>:
  *   <tt>vmNEVER</tt>:        do not run the Variables Inter-dependency diagnostics (default)
  *
  *   <tt>vmSOLVED</tt>:       run the Variables Inter-dependency diagnostics if the model
  *                            is solved
  */
  virtual CATCDSVarDepMode GetVarDependencyMode() const = 0;

  /**
   * Returns the dependency classes of variables.
   * @param oapClass
   *   An array of array of pointers to the variables. Each array contains
   *   the variables which belong to the same dependency class.
   * @return
   *   0 - if the function succeeded,
   *   1 - if the function failed.
   *
   * @SIZE oanClasses onClasses
   * @SIZE oaapClasses onClasses oanClasses
   *
   * @CHECKRESULT 0
   */
  virtual int GetDependentVariables(int &onClasses, int *&oanClasses, CATICDSVariable*** &oaapClasses) const = 0;


  /**
   * @DEPRECATED
   */
  virtual int GetDependentVariables(int &onClasses, int *&oanClasses, CATICDSVariable** &oaapClasses) const = 0;

  //-------------------------------------------------------
  //                       Simulation
  //-------------------------------------------------------
  
  /**
   * Retrieves the diagnostics of kinematic simulability. A kinematic problem
   * is defined in terms of axes and joints with parameters. These parameters
   * can be commanded to some values to move the kinematic mechanism.
   * IsSimulable checks the number of degrees of freedom (DOF) of the
   * kinematic mechanism with commands and without them. The kinematic
   * mechanism is considered as simulable if its DOF are completely covered by
   * commands.
   * @param iNbCommands
   *   The number of commands.
   * @param iapCommands
   *   An array of pointers to the commands' callbacks.
   * @param oNbDofWithCommands
   *   The number of degrees of freedom with commands.
   * @param oNbDofWithoutCommands
   *   The number of degrees of freedom without commands.
   * @return
   *   The diagnostics of simulability.
   * @see #SetDegreesOfFreedomMode
   *
   * @SIZE iapCommands iNbCommands
   *
   * @RETURNNAME diagnostic
   */
  virtual CATCDSSimulabilityDiagnostics IsSimulable(int iNbCommands, CATICDSVariable** iapCommands, int &oNbDofWithCommands, int &oNbDofWithoutCommands) = 0;

  /**
   * Sets target values for commands. To force the simulation (continuous
   * movement of objects with keeping all joints satisfied until reaching the
   * target values of the commands), one should call to <tt>Run</tt> after the
   * call to <tt>SetTargetValues</tt>.
   * @param iNbCommands
   *   The number of commands.
   * @param iapCommands
   *   An array of pointers to the commands.
   * @param iaTargetValues
   *   An array of target values of the commands.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the function succeeded,
   *     <li><tt>1</tt> - if the function failed.
   *   </ul>
   * @see #Run
   *
   * @SIZE iapCommands iNbCommands
   * @SIZE iaTargetValues iNbCommands
   */
  virtual int SetTargetValues(int iNbCommands, CATICDSVariable **iapCommands, double *iaTargetValues) = 0;

  /**
   * Retrieves the singularity diagnostics. It allows to detect whether
   * a singularity has been passed during simulation.
   * @return
   *   <tt>TRUE</tt> if a singularity is detected,
   *   <tt>FALSE</tt> otherwise.
   */
  virtual CATCDSBoolean IsSingularityDetected() = 0;
  
  //-------------------------------------------------------
  //               Degree of Freedom analysis
  //-------------------------------------------------------
  
  /**
   * Sets the solving mode for degrees of freedom (DOF) calculation. It is
   * possible to compute full DOF space of an object or exclude its degrees
   * of symmetry (DOS) from DOF space.
   * @param iMode
   *   DOF mode.
   * @see #GetDegreesOfFreedom,
   *      #GetDegreesOfFreedom2D,
   *      #GetRelativeDegreesOfFreedom,
   *      #GetRelativeDegreesOfFreedom2D,
   *      #GetNumberOfDegreesOfFreedom,
   *      #IsSimulable
   */
  virtual void SetDegreesOfFreedomMode(CATCDSDOFMode iMode) = 0;

    /**
   * Get the solving mode for degrees of freedom (DOF) calculation. 
   * @return the DOF mode.
   * @see #GetDegreesOfFreedom,
   *      #GetDegreesOfFreedom2D,
   *      #GetRelativeDegreesOfFreedom,
   *      #GetRelativeDegreesOfFreedom2D,
   *      #GetNumberOfDegreesOfFreedom,
   *      #IsSimulable
   */
  virtual CATCDSDOFMode GetDegreesOfFreedomMode() const = 0;

  /**
   * Retrieves the information on the number of instantaneous degrees of
   * freedom (DOF) in a whole model. It is possible to compute the size of
   * full DOF space or do not take into account degrees of symmetry (DOS).
   * @param oNumber
   *   The number of instantaneous degrees of freedom.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the function succeeded,
   *     <li><tt>1</tt> - if the function failed.
   *   </ul>
   * @see #SetDegreesOfFreedomMode
   *
   * @CHECKRESULT 0
   */
  virtual int GetNumberOfDegreesOfFreedom(unsigned int &oNumber) = 0;

  //-------------------------------------------------------
  //                   Auto constraining
  //-------------------------------------------------------
  
  /**
   * Add the pattern for auto constraining.
   * @param iConstraintType
   *    Constraint type.
   * @param inGeom
   *    Size of the lists ipListGeom.
   * @param ipListGeom
   *    List of pointers to constrainable geometries.
   * @param iGeometryType1
   *    Type of the 1st argument If iGeometryType == tpANYTYPE,
   *    all geometry types are allowed (if it makes sense).
   * @param iGeometryType2
   *    Type of the 2nd argument.
   *
   * @SKIP
   *
   * @SIZE iapListGeom inGeom
   */
  virtual void AddAutoConstrainingPattern(CATCDSType iConstraintType, int inGeom, CATICDSGeometryLeaf** iapListGeom, CATCDSType iGeometryType1, CATCDSType iGeometryType2) = 0;

  /**
   * Clears the patterns for auto-constraining.
   * @see #AddAutoConstrainingPattern
   *
   * @SKIP
   */
  virtual void ResetAutoConstrainingPatterns() = 0;

  /**
   * Perform auto-constraining's first step : create the list 
   * of all relevant constraints that could be added to the solver.
   * @param onConstraints
   *    Number of contraints.
   * @param oaConstraints
   *    Array of constraint descriptors.
   * @param iOptimized
   *    If TRUE return a subset of constraint in which some redundant constraints were
   *    removed. Use this to optimize the auto-constraining step in large cases.
   * @return
   *    0 in case of success non-zero otherwise.
   *
   * @SKIP
   *
   * @SIZE oapConstraints onConstraints
   */
  virtual int CreateConstraintList(int &onConstraints, CATICDSConstraintDescriptor **&oapConstraints, CATCDSBoolean iOptimized = TRUE) = 0;

  /**
   * Perform auto-constraining's second's step : 
   * After constraints weights were specified, it computes the
   * subset of constraints that iso-constraint the geometry.
   * @param inConstraints
   *    Number of qualified contraints, MUST be produced by the last CreateConstraintList call.
   * @param iaConstraints
   *    Array of qualified constraints descriptors.
   * @param oaIsToAdd
   *    Are constraint to add to iso-constraint the problem (of size
   *    inQualifiedConstraints, must allocated by caller).
    * @return
   *    0 in case of success non-zero otherwise.
   *
   * @SKIP
   *
   * @SIZE iapConstraints inConstraints
   * @SIZE oaIsToAdd inConstraints
   */
  virtual int DoAutoConstraint(int inConstraints, CATICDSConstraintDescriptor **iapConstraints, CATCDSBoolean *oaIsToAdd) = 0;

  //-------------------------------------------------------
  //                 Debug and support
  //-------------------------------------------------------
  
  /**
   * Specify folder in which replays will be generated.
   * @param iPath
   *    Folder path.
   *
   * @SKIP
   */
  virtual void SetReplayPath(const char* iPath) = 0;

  /**
   * Retreive the folder in which replays are generated.
   *
   * @SKIP
   */
  virtual const char* GetReplayPath() const = 0;

  /**
   * @DEPRECATED
   *
   * @SKIP
   */
  virtual const char* GetReplayPath(const char* iPath) const = 0;

  /**
   * Specify a prefix for generated replay.
   * @param iPrefix
   *    The value is used as a prefix in the generated filename.
   *
   * @SKIP
   */
  virtual void SetReplayPrefix(const char* iPrefix) = 0;

  /**
   * Retreive the replay prefix.
   *
   * @SKIP
   */
  virtual const char* GetReplayPrefix() const = 0;

  /**
   * Specify a name for generated replay.
   * @param iName
   *    Name value
   */
  virtual void SetReplayFileName(const char* iName) = 0;

  /**
   * Retreive the replay file name.
   * @return
   *    Returned value of the replay file name.
   *
   * @SKIP
   */
  virtual const char* GetReplayFileName() const = 0;

  /**
   * Specify the replay mode.
   * @param iMode
   *    Replay mode.
   *
   * @DEBUG
   */
  virtual void SetReplayMode(CATCDSReplayMode iMode) = 0;
  
  /**
   * Retreive the replay mode.
   * @return 
   *     Returns the current replay mode.
   *
   * @DEBUG
   */
  virtual CATCDSReplayMode GetReplayMode() const = 0;

public:
  virtual ~CATICDS() {}
};

#endif
