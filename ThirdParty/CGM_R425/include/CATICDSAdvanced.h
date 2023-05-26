#ifndef CATICDSAdvanced_H
#define CATICDSAdvanced_H

// COPYRIGHT DASSAULT SYSTEMES  2012

#include "CATCDS.h"
#include "CATCDSAdvancedEnums.h"
#include "CATICDS.h"
#include "CATCDSDebug.h"
#include "CATIAV5Level.h"

class CATCDSString;
class CATCDSStream;
class CATCSStreamTool;
class CATConstraintSolver;
class CATICDSMathBundle;
class CATICDSGeometry;
class CATICDSSketch;
class CATICDSGeometry;
class CATICDSEntity;
class CATICDSGeomConstraint;
class CATICDSPoint;
class CATICDSPoint2D;
class CATICDSInterpolationNURBSCurve;
class CATICDSInterpolationNURBSCurve2D;
class CATICDSPattern;
class CATICDSGeometryLeaf;
class CATICDSParallelism;
class CATICDSVariable;
class CATICDSEquation;
class CATICDSSkinParam;
class CATICDSConstraint;
class CATConstraintSolver;
class CATCDSInterruptInterface;

#if defined(_EMSCRIPTEN_SOURCE) && defined(_EMSCRIPTEN_DEBUG)
#include <string>
#endif

/**
 * CDS advanced interface, dedicated to provide DS-only functionnalities.
 * All public functionnalities are available in base class CATICDS.
 */
class ExportedBySolverInterface CATICDSAdvanced : public CATICDS
{
public:

  //-------------------------------------------------------
  //              Creation and destruction methods
  //-------------------------------------------------------

  /**
   * Static method that creates an instance of the CATICDSAdvanced Interface.
   */
  static CATICDSAdvanced * Create();

  /**
   * Static method that deletes an instance of the CATICDSAdvanced Interface.
   */
  static void Remove(CATICDSAdvanced *ipSolver);
  
  //-------------------------------------------------------
  //            Solver's protected functionalities
  //-------------------------------------------------------

  /**
   * Retreive the full CDS level the constraint solver.
   */
  virtual unsigned int GetCDSLevel() const = 0;

  /**
   * Set the full CDS level the constraint solver.
   * @param iLevel
   *    the full level of the solver
   */
  virtual void SetCDSLevel(unsigned int iLevel) = 0;

  /**
   * Retreive the level and HF sublevel of the constraint solver.
   */
  virtual void GetCDSLevels(unsigned short & oLevel, unsigned short & oHFLevel) const = 0;
  
  /**
   * Set the level of the constraint solver.
   * @param iLevel
   *    the level of the solver
   * @param iHFLevel
   *    the HF sublevel of the solver
   */
  virtual void SetCDSLevels(unsigned short iLevel, unsigned short iHFLevel) = 0;

  /**
   * @SKIP
   *
   * Sets a bundle of mathematical operators to be used by CDS if extended functions
   * are enabled. The bundle is optional and remains owned by the caller, it will no
   * be deleted upon destruction of "this".
   * @param iMathBundle
   *    Current bundle to be used
   */  
  virtual void SetMathBundle(CATICDSMathBundle * ipMathBundle) = 0;

  /**
   * Softly fixes (if iStiffness > 0.0) and unfixes (if iStiffness <= 0.0) object on the sketch of the 2D geometry.
   * For 3D objects this function does nothing.
   * @param ipGeometry
   *    A pointer to the geometry callback (should be already created and added to the ConstraintSolver).
   * @param iStiffness
   *    stiffness of the fixation.
   * @return
   *    0 - if the function succeeded,
   *    1 - if arguments are invalid.
   * WARNING when exposion in public interface will be decided, move it to CATICDSGeometry and not CATICDS !!!
   */
  virtual int SetFixationStiffness2D(CATICDSGeometry* ipGeometry, double iStiffness) = 0;

  /**
   * Softly fixes (if iStiffness > 0.0) and unfixes (if iStiffness <= 0.0) geometry in 3D space.
   * @param ipGeometry
   *   A pointer to the geometry callback (should be already created and added to the ConstraintSolver).
   * @param iStiffness
   *   stiffness of the fixation.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid.
   * WARNING when exposion in public interface will be decided, move it to CATICDSGeometry and not CATICDS !!!
   */
  virtual int SetFixationStiffness(CATICDSGeometry* ipGeometry, double iStiffness) = 0;

  /**
   * Converts a geometrical constraint to the soft constraint (if iStiffness > 0.0).
   * Or converts soft geometrical constraint to the ordinary constraint (if iStiffness <= 0.0)
   * @param ipConstraint
   *   A pointer to the constraint callback (should be already created and added to the ConstraintSolver)
   * @param iStiffness
   *   stiffness of the constraint; if iStiffness > 0.0 then constraint becomes soft constraint.
   *   Otherwise it becomes ordinary constraint
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   * WARNING when exposion in public interface will be decided, move it to CATICDSGeomConstraint and not CATICDS !!!
   */
  virtual int SetConstraintStiffness(CATICDSGeomConstraint* ipConstraint, double iStiffness) = 0;
  
  /**
   * Add a pattern for auto constraining.
   * This pattern allows the constraints only between the corresponding triples
   * of geometries.
   * @param iConstraintType
   *    Constraint type.
   * @param ipGeom1
   *    Pointer to the 1st argument.
   * @param ipGeom2
   *    Pointer to the 2nd argument.
   * @param ipGeom3
   *    Pointer to the 3rd argument.
   *
   * @SKIP
   */
  virtual void AddAutoConstrainingTriplePattern(CATCDSType iConstraintType,
                                                CATICDSGeometryLeaf* ipGeom1,
                                                CATICDSGeometryLeaf* ipGeom2,
                                                CATICDSGeometryLeaf* ipGeom3) = 0;
  
  /**
   * Retrieves skin help parameter of the constraint for a specified geometry.
   * @param ipConstraint
   *   A pointer to the constraint.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param ipSkinParam
   *   A pointer to the skin help parameter.
   *
   * @SKIP
   */
  virtual void SetSkinHelpParameter(CATICDSGeomConstraint *ipConstraint, CATICDSGeometryLeaf *ipGeom, CATICDSSkinParam *ipSkinParam) = 0;

  /**
   * Specify skin help parameter of the constraint for a specified geometry.
   * @param ipConstraint
   *   A pointer to the constraint.
   * @param ipGeom
   *   A pointer to the geometry.
   * @param opSkinParam
   *   A pointer to the skin help parameter.
   * @return
   *   TRUE if the help skin parameter is specified.
   *
   * @SKIP
   */
  virtual CATCDSBoolean GetSkinHelpParameter(CATICDSGeomConstraint *ipConstraint, CATICDSGeometryLeaf *ipGeom, CATICDSSkinParam *&opSkinParam) = 0;
  
  /**
   * @SKIP
   */
  virtual CATCDSBoolean GetRadiusOffset(CATICDSGeometryLeaf* ipGeometryLeaf, double &oRadius) = 0;

  /**
   * @SKIP
   */
  virtual CATCDSBoolean GetRadiiOffset(CATICDSGeometryLeaf* ipGeometryLeaf, double &oMajorRadius, double &oMinorRadius) = 0;

  /**
   * Set the previous radii of modified geometry
   * @param ipGeometry
   *   The modified geometry
   * @param iMajorRadius
   *   The value of object first parameter (radius for circle, major radius for ellipse, ...)
   * @param iMinorRadius
   *   The value of object second parameter (minor radius for ellipse, ...) if it exists
   * @return
   *   0 if the function succeeded
   */
  virtual int SetPreviousRadii(CATICDSGeometry* ipGeometry, double iMajorRadius, double iMinorRadius) = 0;

  /**
   * Set the move and evaluate transformation which have been applied on moved geometry
   * @param ipGeometry
   *   The moved geometry
   * @param iaaRotation
   *   The applied rotation in object sketch axis system
   * @param iaTranslation
   *   The applied translation in object sketch axis system
   * @return
   *   0 if the function succeeded
   */
  virtual int SetAppliedTransformation2D(CATICDSGeometry* ipGeometry, double iaaRotation[2][2], double iaTranslation[2]) = 0;

  /**
   * @SKIP
   */
  virtual int GetConnexComponents(int inNonCuttingFixedGeom, CATICDSGeometry **iapNonCuttingFixedGeom,
                                  int &onConnexComponents, int *&oanConnexComponentsEnd, CATICDSEntity **&oapConnexComponents) = 0;
  
  /**
   * Find all the CATICDSEntity pointing on ipEntity.
   * @param ipEntity
   *    Target entity.
   * @param onEntities
   *    Size of oapEntities.
   * @param oapEntities
   *    Output array of entities pointing to the input entity. 
   * @param iType
   *    Type of the output entities.
   * @return
   *    0 - if the function succeeded,
   *    1 - if the function failed.
   *
   * @SIZE oapEntities onEntities
   * @CHECKRESULT 0
   */
  virtual int GetConnexEntities(CATICDSEntity *ipEntity, int &onEntities, CATICDSEntity **&oapEntities, CATCDSType iType = tpANYTYPE) const = 0;

  /**
   * Retreive geometry leaf's sketch.
   * WARNING when exposion in public interface will be decided, move it to CATICDSGeometryLeaf and not CATICDS !!!
   */
  virtual CATICDSSketch* GetSketch(const CATICDSGeometry* ipGeometry) const = 0;

  /**
   * Retreive geometry leaf's sketch.
   * WARNING when exposion in public interface will be decided, move it to CATICDSGeometryLeaf and not CATICDS !!!
   *
   * @SKIP
   */
  virtual CATICDSSketch* GetSketch(const CATICDSConstraint* ipConstraint) const = 0;
  

   /**
   * @SKIP
   */
  virtual void ReduceTransformation(const CATICDSGeometryLeaf* ipGeometryLeaf, double ioaaRotation[3][3], double ioaTranslation[3]) const = 0;


  /**
   * Specify sketch used for entities creation. Please note that the
   * object's sketch is specified at creation time once and for all.
   * @param ipSketch
   *    A pointer to the sketch entity.
   * WARNING when exposion in public interface will be decided, move it to CATICDSFactory and not CATICDS !!!  
   */
  virtual void SetSketch(CATICDSSketch* ipSketch) = 0;
  
  /**
   * Fills in list of pointers to entities of a given type.
   * @param onEntities
   *    Number of matching entities
   * @param oaEntities
   *    Array of matching entities (allocated by this method)
   * @param iType 
   *    Type to match
   * WARNING different than the same method in CATICDSFactory because in this case we return the pure 2D implicit sketch,
   * not in the CATICDSFactory method !!!
   *
   * @SIZE oapEntities onEntities
   */
  virtual void GetEntities(int &onEntities, CATICDSEntity **&oapEntities, CATCDSType iType = tpANYTYPE) const = 0;


  /**
   * Sets the overdefined diagnostics mode, odDIMENSIONAL is used by default.
   * @param iOverdefinedDiagMode
   *   Overdefined diagnostic mode.
   */
  virtual void SetOverdefinedDiagnosticsMode(CATCDSOverdefinedDiagMode iOverdefinedDiagMode) = 0;

  /**
   * Get the overdefined diagnostics mode, odDIMENSIONAL is used by default.
   * @return
   *   Overdefined diagnostic mode.
   */
  virtual CATCDSOverdefinedDiagMode GetOverdefinedDiagnosticsMode() const = 0;


  virtual void SetOptimisationMode(CATCDSBoolean iMode) const = 0;

    /**
   * Activate accurate move for dynamic move and kinematics.
   * @param iAccurateMove
   *   Activate or deactivate accurate move
   * @see #SetDynamicMove, #SetTargetValues
   */
  virtual void SetAccurateMove(CATCDSBoolean iAccurateMove) = 0;

    /**
   * return accurate move for dynamic move and kinematics.
   * @return
   *   Is accurate move is activated or deactivated 
   */
  virtual CATCDSBoolean GetAccurateMove() const = 0;

    /**
   * Activate perturbation for dynamic move and kinematics.
   * @param iAccurateMove
   *   Activate or deactivate perturbation
   * @see #SetDynamicMove, #SetTargetValues
   */
  virtual void SetPerturbationMove(CATCDSBoolean iPerturbationMove) = 0;

  /**
   * Get the status (Activate or deactivate) of the perturbation for dynamic move and kinematics.
   * @return iAccurateMove
   * @see #SetDynamicMove, #SetTargetValues
   */
  virtual CATCDSBoolean GetPerturbationMove() const = 0;

  /**
  * Activate adaptive move for dynamic move and kinematics.
  * @param iAdaptiveMove
  *   Activate or deactivate adaptive move
  */
  virtual void SetAdaptiveMove(CATCDSBoolean iAdaptiveMove) = 0;

  /**
  * Get the status (Activated or Deactivated) of adaptive move for dynamic move and kinematics.
  * @return
  *   Is adaptive move activated.
  */
  virtual CATCDSBoolean GetAdaptiveMove() const = 0;

    /**
  * Sets the diagnostics computation mode for rigid sets.
  * @param iRigidSetDiagMode
  *   <br><b>legal values</b>:
  *   <tt>rdWITHOUTDOS</tt>:   DOS will be excluded from DOF for diagnostics computation of rigid sets (default)
  *
  *   <tt>rdFULL</tt>:         full DOF will be taken into account for diagnostics computation of rigid sets
  */
  virtual void SetRigidSetDiagnosticMode(CATRigidSetDiagMode iRigidSetDiagMode) = 0;

  /**
  * Returns the rigid set diagnostic mode.
  * @return
  *   Rigid set diagnostic mode from the following list of <br><b>legal values</b>:
  *  <tt>rdWITHOUTDOS</tt>: the DOS of the rigid sets are ignored in DOF computation.
  *  <tt>rdFULL</tt>: take into account the DOS of the rigid sets during DOF computation.
  */
  virtual CATRigidSetDiagMode GetRigidSetDiagnosticMode() const = 0;

    /**
   * Sets the solving mode for dynamic move and kinematics.
   * @param iMode
   *   <b>Legal values:</b>
   *   <dl>
   *   <dt><tt>mmSTANDARD</tt>
   *   <dd>the solver will move as many objects as it is needed to make a
   *       dynamic move
   *   <dt><tt>mmPERTURBATION</tt>
   *   <dd>similar to the previous but the solver will apply a perturbation
   *       technique before solving to overcome singularities in the initial
   *       configuration
   *   <dt><tt>mmMINIMUM_MOVE</tt>
   *   <dd>the solver will move as few objects as possible
   *   <dt><tt>mmACCURATE_MOVE</tt>
   *   <dd>similar to the previous but the solver will try to reach required
   *       movements exactly that can take more time
   *   </dl>
   * @see #SetDynamicMove, #SetTargetValues
   */
  virtual void SetDynamicMoveMode(CATMoveMode iMode) = 0;

    /**
   * Get the solving mode for dynamic move and kinematics.
   * @return solving mode
   *   <b>Legal values:</b>
   *   <dl>
   *   <dt><tt>mmSTANDARD</tt>
   *   <dd>the solver will move as many objects as it is needed to make a
   *       dynamic move
   *   <dt><tt>mmPERTURBATION</tt>
   *   <dd>similar to the previous but the solver will apply a perturbation
   *       technique before solving to overcome singularities in the initial
   *       configuration
   *   <dt><tt>mmMINIMUM_MOVE</tt>
   *   <dd>the solver will move as few objects as possible
   *   <dt><tt>mmACCURATE_MOVE</tt>
   *   <dd>similar to the previous but the solver will try to reach required
   *       movements exactly that can take more time
   *   </dl>
   * @see #SetDynamicMove, #SetTargetValues
   */
  virtual CATMoveMode GetDynamicMoveMode() const = 0;

    /**
   * Set the mode for the creation of the constraints list.
   * @param iOptimized boolean
   *    <br> TRUE : if wants to create with optimization.
   *    <br> FALSE : if wants to create full constraints list.
   */
  virtual void SetAutoConstraintMode(CATCDSBoolean iOptimized) = 0;

    /**
   * Get the mode for the creation of the constraints list.
   * @return the mode for the creation of the constraints list
   *    <br> TRUE : if wants to create with optimization.
   *    <br> FALSE : if wants to create full constraints list.
   */
  virtual CATCDSBoolean GetAutoConstraintMode() const = 0;

  virtual void UseNew3DRigidificationHeuristic(CATCDSBoolean iMode) = 0;
  virtual CATCDSBoolean GetNew3DRigidificationHeuristic() const = 0;


  /**
   * DEPRECATED : use method which computes all the dimensional values (double oConstraintValues[6])
   * Calculates constraint discrepancy.
   * If dimensional constraint is not satisfied, it also calculates value
   * which makes constraint satisfied.
   * @param ipConstraint
   *   A pointer to the constraint callback.
   * @param oConstraintDiscrepancy
   *   The value of constraint discrepancy
   * @param oConstraintValue
   *   The value for dimension to satisfy constraint
   * @param oNbOfHelpPointValues
   *   The number of coordinates of the help points.
   * @param oHelpPointValues
   *   The coordinates of the help points.
   * @param iRefreshData
   *   If TRUE the internal model is refreshed (the coordinates and parameters of objects are reread
   *   but previously computed statuses are lost)
   * @return
   *   The status of the constraint is defined as the first appropriate value
   *   from the following list of <br><b>legal values</b>:
   *   <tt>dsSATISFIED</tt>:         constraint is satisfied
   *   <tt>dsNOTSATISFIED</tt>:      constraint can't be satisfied with any value
   *   <tt>csNOTSATISFIEDVALUE</tt>: constraint is not satisfied but can be
   *                                 satisfied with oValue
   *
   * @SKIP
   */
  virtual CATCDSDiscrepancyStatus EvalDiscrepancy(CATICDSConstraint* ipConstraint,
                                                  double &oConstraintDiscrepancy,
                                                  double &oConstraintValue,
                                                  int oNbOfHelpPointValues[MAX_CONSTRAINT_PARAMS] = 0,
                                                  double oHelpPointValues[MAX_CONSTRAINT_PARAMS*MAX_PARAM_VALUES] = 0,
                                                  CATCDSBoolean iRefreshData = TRUE) = 0;

  /**
  * Calculates constraint discrepancy.
  * If dimensional constraint is not satisfied, it also calculates values
  * which makes constraint satisfied.
  * @param ipConstraint
  *   A pointer to the constraint callback.
  * @param oConstraintDiscrepancy
  *   The value of constraint discrepancy
  * @param oConstraintValues
  *   The values of dimensions to satisfy the constraint (up to 6)
  * @param oNbOfHelpPointValues
  *   The number of coordinates of the help points.
  * @param oHelpPointValues
  *   The coordinates of the help points.
  * @param iRefreshData
  *   If TRUE the internal model is refreshed (the coordinates and parameters of objects are reread
  *   but previously computed statuses are lost)
  * @return
  *   The status of the constraint is defined as the first appropriate value
  *   from the following list of <br><b>legal values</b>:
  *   <tt>dsSATISFIED</tt>:         constraint is satisfied
  *   <tt>dsNOTSATISFIED</tt>:      constraint can't be satisfied with any value
  *   <tt>csNOTSATISFIEDVALUE</tt>: constraint is not satisfied but can be
  *                                 satisfied with the values in oValues
  *
  * @SKIP
  */
  virtual CATCDSDiscrepancyStatus EvalDiscrepancy(CATICDSConstraint* ipConstraint,
    double &oConstraintDiscrepancy,
    double oConstraintValues[6],
    int oNbOfHelpPointValues[MAX_CONSTRAINT_PARAMS] = 0,
    double oHelpPointValues[MAX_CONSTRAINT_PARAMS*MAX_PARAM_VALUES] = 0,
    CATCDSBoolean iRefreshData = TRUE) = 0;

  /* Set the mode for keeping initial data on inconsistent geometry component
  * @param iKeepInitialData TRUE if we keep the initial data when a geometry component is inconsistent
  */
   virtual void SetInitialDataOnInconsistentGeomComponentMode(CATCDSBoolean iKeepInitialData) = 0;

  /* Get the mode for keeping initial data on inconsistent geometry component
  * @return TRUE if we keep the initial data when a geometry component is inconsistent
  */
  virtual CATCDSBoolean GetInitialDataOnInconsistentGeomComponentMode() const = 0;

  /**
  * Returns the status of a variables.
  * @param ipVariable
  *   A pointer to the variable callback.
  * @return
  *   The status of the variable is defined as the first appropriate value
  *   from the following list of <br><b>legal values</b>:
  *  <tt>vsUNKNOWN</tt>: the variable status has not been computed
  *  <tt>vsFIXED</tt>: the variable is fixed
  *  <tt>vsNOTCONSISTENT</tt>: the variable is an argument of an inconsistent constraint
  *  <tt>vsUNDERDEFINED</tt>: the variable has no degree of freedom
  *  <tt>vsWELLDEFINED</tt>: the variable is an argument of an inconsistent constraint
  *  <tt>vsOVERDEFINED</tt>: the variable is an argument of an overdefined constraint
  */
  virtual CATVStatus GetStatus(CATICDSVariable* ipVariable) const = 0;

  virtual int GetNumberOfLeadingConstraint() const =0;
  /**
   * Sets the derivatives computation mode.
   * It enables the computation of derivatives during the following calls to <tt>Run</tt>.
   * The computation will be performed only during a simulation step (it means that
   * <tt>SetTargetValues</tt> method has been called before <tt>Run</tt>) and on the entities
   * declared with <tt>SetDerivativesComputationEntities</tt>.
   * @param iMode
   *   <br><b>legal values</b>:
   *   <tt>drNONE</tt>:                          do not perform derivatives computation (default)
   *   <tt>drDERIVATIVES_AT_START_POINT</tt>:    computes derivatives at the start point of the simulation step
   *   <tt>drDERIVATIVES_AT_END_POINT</tt>:      computes derivatives at the end point of the simulation step
   * @see #SetTargetValues, #Run, #GetDerivatives, #GetDerivativesComputationMode, #SetDerivativesComputationEntities
   */
  virtual void SetDerivativesComputationMode(CATCSDerivMode iMode) = 0;
  virtual CATCSDerivMode GetDerivativesComputationMode() const = 0;

  /**
  * Sets the contacts diagnostics mode, cdCLASH_DETECTED is used but default.
  * @param iCATDiagMode
  *    Diagnostic mode.
  */
  virtual void SetContactsDiagnosticsMode(CATContactsDiagMode iContactsDiagMode) = 0;

  /**
  * Returns the contacts diagnostics mode
  * @return Diagnostic mode.
  */
  virtual CATContactsDiagMode GetContactsDiagnosticsMode() const = 0;

  /**
  * Sets the mode to check unsolvable constraints during the <tt>Run</tt> method
  * (unsolvable constraints are: (1) constraints between objects of the same rigid set
  *                              (2) constraints between fixed objects)
  * @param iMode boolean
  *    <br> TRUE : to check unsolvable constraints (the <tt>Run</tt> method will return an error code in case of failure).
  *    <br> FALSE : to ignore unsolvable constraints during the solve (default).
  */
  virtual void SetCheckUnsolvableConstraintsMode(CATCDSBoolean iMode) = 0;

  /**
  * Gets the current mode for checking unsolvable constraints.
  * @return the mode (boolean)
  */
  virtual CATCDSBoolean GetCheckUnsolvableConstraintsMode() const = 0;

  /**
  * Sets the mode to move geometry without taking clashes into account but preserving contacts
  * @param iMode boolean
  *    <br> TRUE : ignore clash but preserve contacts
  *    <br> FALSE :  (default).
  */
  virtual void SetMoveOutOfClashMode(CATCDSBoolean iMode) = 0;

  /**
  * Gets the current mode for GetMoveOutOfClashMode.
  * @return the mode (boolean)
  */
  virtual CATCDSBoolean GetMoveOutOfClashMode() const = 0;

  /**
   * Sets the solving mode for IK
   * @param iMode boolean
   *    <br> TRUE : IK only seeks exact solution (all variables are ExactlyMoved), does not move anything if no exact solution is found
   *    <br> FALSE : Default mode, seeks the closest solution in the DOF
  */
  virtual void SetInverseKinematicsMode(CATCDSBoolean iMode) = 0;

  /**
   * Gets the current mode for IK
   * @return the mode (boolean)
  */
  virtual CATCDSBoolean GetInverseKinematicsMode() const = 0;

  /**
  * Sets the mode to solve geometry by solving all clashs
  * @param iMode CATUpdateOutOfClashMode
  *    <br> ocNONE : (default).
  *    <br> ocBASIC : greedy algorithm
  */
  virtual void SetUpdateOutOfClashMode(CATUpdateOutOfClashMode iMode) = 0;

  /**
  * Gets the current mode for GetUpdateOutOfClashMode.
  * @return CATUpdateOutOfClashMode
  */
  virtual CATUpdateOutOfClashMode GetUpdateOutOfClashMode() const = 0;

  /**
   * Sets a drag line for dynamic move. The geometry will be moved in order to be as close as
   * possible to the drag line.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   Geometry to be moved
   * @param iDragLineOrigin
   *   Coordinates of the drag line origin
   * @param iDragLineDirection
   *   Coordinates of the drag line direction
   * @return
   *   0 if the function succeeded
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  virtual int SetDynamicMove(CATICDSGeometryLeaf* ipGeometry, double const iDragLineOrigin[3], double const iDragLineDirection[3]) = 0;

  /**
   * Set an interrupt class.
   * @param ipInterruptClass
   *    the interrupt class pointer (see declaration in CATCDSInterruptDef.h)
   */
  virtual void SetInterrupt(CATCDSInterruptInterface* ipInterrupt) = 0;

  /**
  * return the interrupt class pointer
  */
  virtual CATCDSInterruptInterface* GetInterrupt() = 0;

  /**
  * Activate or deactivate "PreprocessKinematicsChains". This enables to solve successive MUC more rapidly. But it cannot be used if the model changes between MUC.
  * @param iActivate
  *   has to be true to activate, has to be false to deactivate.
  */
  virtual void PreprocessKinematicsChains(CATCDSBoolean iActivate) = 0;

  /**
  * return PreprocessKinematicsChains mode.
  * @return
  *   TRUE if activated, FALSE otherwise
  */
  virtual CATCDSBoolean GetPreprocessKinematicsChains() const = 0;

  /**
   * Activates incremental computation mode : independent components and diagnostics will be computed in an incremental way
   * (by default all is recomputed at each solve which costs more time).
   * @param iIncrementalMode
   *   Activate or deactivate incremental move
   */
  virtual void SetIncrementalMode(CATCDSBoolean iIncrementalMode) = 0;

  /**
  * Gets the current incremental mode.
  * @return
  *   TRUE if the mode is activated, FALSE otherwise
  */
  virtual CATCDSBoolean GetIncrementalMode() const = 0;

  // Test Infra
  static int GetUnderdefinedStatus(CATICDSGeometry const *ipGeometry);


  // --- 2d/32 API ---

  /**
  * Create the p2DObject associated to ip3DObject in ipSketch
  * @param ip3DObject : the 3D object
  * @param ipSketch : the support sketch
   @return :
    0 if 2d Object is created and p3DObject is lying on ipSketch
    1 if the 2d Object is created but p3DObject is not lying on ipSketch
    2 if the 2d object has already been created
    3 if the 2d object cannot be created(invalid type of input ..
    */

  virtual int Create2DRep(CATICDSSketch* ipSketch, CATICDSGeometryLeaf* p3DObject) = 0;

  /**
  * Get the associated 2d Geometry
  * @param ipSketch : the support sketch
  * @param ipGeomLeaf3D : the 3D geometry
  * @return the associated coincident 2D geometry if it exists, 0 elsewhere 
  */
  virtual CATICDSGeometryLeaf* Get2DRep(CATICDSSketch * ipSketch, CATICDSGeometryLeaf * ipGeomLeaf3D) const = 0;

  /**
  * Get the refenernce 2D Geometry
  * @param ipGeomLeaf2D : the 2D geometry
  * @return the associated coincident 3D geometry if it exists, 0 elsewhere
  */
  virtual CATICDSGeometryLeaf* Get3DRep(CATICDSGeometryLeaf * ipGeomLeaf2D) const = 0 ;


  /**
  * Get the list of sketch coincident of a 3d geometry
  * @param ipGeomLeaf3D : the 3D geometry
  * @param oNbSketches : the number of sketchs coincident to the 3d geometry
  * @param oaSketches : the table of pointers on sketched coincident to ipGeomLeaf3D 
  */
  virtual int GetListOfSupportSketch(CATICDSGeometryLeaf* ipGeomLeaf3D, int& oNbSketches, CATICDSSketch**& oaSketches) = 0;



  // CDS Javascript

#if defined(_EMSCRIPTEN_SOURCE)
  static unsigned short GetCDSOpenConfigurationLevel();

  static unsigned int GetCDSFullOpenConfigurationLevel();

  static char const * GetCDSVersion();  

#if defined(_EMSCRIPTEN_DEBUG)
  virtual char const * GetCDSReplay() const = 0;

  virtual int GetNbOfStreams() const = 0;

  virtual char const * GetStreamName(int iIdx) const = 0;

  virtual char const * GetStream(int iIdx) const = 0;

  virtual char const * GetReplayMethod() const = 0;

  virtual void SetReplayMethod(char const *iMethod) = 0;

  virtual int GetTraceLevel() const = 0;

  virtual void SetTraceLevel(int iLevel) = 0;

  virtual CATCDSBoolean GetCheckMode() const = 0;

  virtual void SetCheckMode(CATCDSBoolean iCheckMode) = 0;

  virtual std::string GetTraces() const = 0;
#endif
#endif
  //-------------------------------------------------------
  //                  Stream/Unstream
  //-------------------------------------------------------
  // DO NOT USE (test infra only)
  virtual CATConstraintSolver* GetImp() const = 0;

#ifdef CDS_DEBUG
  /**
   * @SKIP
   */
  virtual void SetStreamTool(CATCSStreamTool* ipStreamTool) = 0;
  
  /**
   * @SKIP
   *
   * Retreive debug name of an entity.
   */
  virtual void GetName(const CATICDSEntity* ipEntity, CATCDSString& oName) const = 0;
#endif

  //-------------------------------------------------------
  //  CATIA Sketcher specific
  //  (see CATCDSSolverInterface::RunImpl), DO NOT USE !!!
  //-------------------------------------------------------
  /**
   * @SKIP
   */
  virtual void SetRereadHelpParameters(CATCDSBoolean iMode) = 0;
  /**
   * @SKIP
   */
  virtual CATCDSBoolean GetRereadHelpParameters() const = 0;
  /**
   * @SKIP
   */
  virtual void RereadParameters(CATICDSEntity* ipEntity) = 0;
  /**
   * @SKIP
   */
  virtual void GetLastTransformation2D(CATICDSGeometry* ipGeometry, double oaaTranf[3][3]) const = 0;
  /**
   * @SKIP
   */
  virtual void GetLastInverseTransformation2D(CATICDSGeometry* ipGeometry, double oaaTranf[3][3]) const = 0;
  /**
   * @SKIP
   */
  virtual void GetChirality(CATICDSConstraint* ipConstraint, CATCAlignment& oAlignment, CATCDSSurfaceOrientation& oSurfaceOrientation,
                            CATCDSHalfSpace& oHalfSpaceGeom1, CATCDSHalfSpace& oHalfSpaceGeom2) = 0;

  //-------------------------------------------------------
  //  Plug specific
  //  (see CATCDSPlug2DSolver), DO NOT USE !!!
  //------------------------------------------------------- 
  /**
   * @SKIP
   */
  virtual void ChangePatternDefinition(CATICDSPattern* ipPattern, CATICDSGeometryLeaf *ipAxis,
                                       int iNbGeometries, CATICDSGeometryLeaf **iapGeometries,
                                       CATICDSVariable **iapVariables, CATCAlignment *iaAlignment) = 0;
  
  /**
   * @SKIP
   */
  virtual void ChangeEquationDefinition(CATICDSEquation* ipEquation, unsigned int inVariables, CATICDSVariable **iapVariables) = 0;

  /**
   * @SKIP
   */
  virtual int GetState() = 0;

  /**
    * Check if constraints are satisfied
    * @return TRUE if all contraints and equations are satisfied
    */
  virtual CATCDSBoolean IsSatisfied() const = 0;

    /**
   * Retrieves the information: was the given set of geometries and constraints (equations, joints)
   * already satisfied before <tt>Run</tt> (in this all returned transformations are identities).
   * The method should be called after <tt>Run</tt> for Update functionality only.
   * It doesn't perform any validation, just stores informations from the previous <tt>Run</tt>
   * until the next <tt>Run</tt> is called.
   * @return
   *   State of constraints before the <tt>Run</tt>: TRUE if satisfied, FALSE if unsatisfied.
   * @see #Run
   */
  virtual CATCDSBoolean IsInitiallySatisfied() = 0;


  /**
  * Forbidden use
  * CATCDSInterfaces only !!!
  */
  virtual void SetConstraintSolver(CATConstraintSolver *ipSolver, CATCDSBoolean iDeleteOldSolver) = 0;

public:
  virtual ~CATICDSAdvanced() {}
};

// Do not use, test infra only (@see CATICDSParallelism::Create)
ExportedBySolverInterface CATICDSParallelism* CreateParallelism(CATICDSFactory *ipFactory, CATICDSGeometryLeaf* pGeometry1, CATICDSGeometryLeaf* pGeometry2, CATICDSGeometryLeaf* pGeometry3);

#endif
