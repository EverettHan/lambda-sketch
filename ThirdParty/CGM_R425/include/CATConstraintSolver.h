#ifndef CATConstraintSolver_H
#define CATConstraintSolver_H

// COPYRIGHT DASSAULT SYSTEMES 2002

#include "CATCDS.h"
#include "CATCDSBoolean.h"
#include "CATCDSEnums.h"
#include "CATCDSInterruptDef.h"
#include "CATCSConstraint.h"
#include "CATCSEntity.h"
#include "CATCSGeometry.h"
#include "CATCSGeomConstraint.h"
#include "CATCSVariable.h"
#include "CATCSGeometryLeaf.h"
#include "CATCDSDebug.h"
#include "CATCSAxis.h"
#include "CATCSAxis2D.h"
#include "CATCSSketch.h"

class CATSoftwareConfiguration;
class CATCSAutoConstrainingTool;
class CATCSAxis;
class CATCSEquation;
class CATCSGeomDimConstraint;
class CATCSJoint;
class CATCSPattern;
class CATCSOffsetConstraint;
class CATCSRigidSet;
class CATCSSketch;
class CATCSProfile2D;
class CATCSPoint2D;
class CATCSMonoParametric;
class CATCSStreamTool;
class CATICDSMathBundle;

class CATCDSSolverInterface;
class CATCDSStream;
class CATCSInterferenceValidator;
class CATCSConstraintDescr;
class CATCSContact;
class CATCSSimpleJoint;

/**
 * Class to create instances of geometric constraint solver called "CDS".
 * <b>Role</b>: CDS is used to position geometric objects (such as points,
 * lines, planes, and others) in 3D space under logical and dimensional
 * constraints (such as coincidence, tangency, distance, and others).
 * Besides the main functionality, it implements also dynamic evaluation,
 * degrees of freedom analysis, overdefined diagnostics, kinematic simulation,
 * and other actions.
 * The geometric problem is formulated in terms of objects (instances of
 * classes derived from <tt>CATCSGeometry</tt>) and constraints (instances of
 * classes derived from <tt>CATCSGeomConstraint</tt>), also called callbacks
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
class ExportedBySolverInterface CATConstraintSolver
{
public:
  /**
   * Constructs an instance of the CDS constraint solver.
   */
  CATConstraintSolver();

  /**
   * Constructs an instance of the CDS constraint solver.
   * @param iLevel
   *   A level of the solver.
   *   It defines what version of the constraint solver will be created.
   */
  CATConstraintSolver(unsigned short iLevel, unsigned short iHFLevel);

  /**
   * DO NOT USE
   * SoftwareConfiguration IS NOT MANAGED BY CDS
   */
  CATConstraintSolver(CATSoftwareConfiguration *ipSoftwareConfiguration);


  virtual ~CATConstraintSolver();

  /**
   * Retreive the level of the constraint solver.
   */
  unsigned int GetCDSLevel() const;

  /**
   * Set the level of the constraint solver.
   */
  void SetCDSLevel(unsigned int iLevel);

    /**
   * Retreive the standard and HF sublevel of the constraint solver.
   */
  void GetCDSLevels(unsigned short & oLevel, unsigned short & oHFLevel) const;

  /**
   * Set the level of the constraint solver.
   * @param iLevel
   *    the level of the solver
   * @param iHFLevel
   *    the HF sublevel of the solver
   */
  void SetCDSLevels(unsigned short iLevel, unsigned short iHFLevel);

  /**
   * Set an interrupt class.
   * @param ipInterruptClass
   *    the interrupt class pointer (see declaration in CATCDSInterruptDef.h)
   */
  void SetInterrupt(CATCDSInterruptInterface* ipInterrupt);

  /**
  * return the interrupt class pointer
  */
  CATCDSInterruptInterface* GetInterrupt();

  /**
  * Activate or deactivate "PreprocessKinematicsChains". This enables to solve successive MUC more rapidly. But it cannot be used if the model changes between MUC.
  * @param iActivate
  *   has to be true to activate, has to be false to deactivate.
  */
  void PreprocessKinematicsChains(CATCDSBoolean iActivate);

  /**
  * return PreprocessKinematicsChains mode.
  * @return
  *   TRUE if activated, FALSE otherwise
  */
  CATCDSBoolean GetPreprocessKinematicsChains() const;

  /**
   * Adds a sketch to the solver.
   * A sketch is a special 3D object that is used as 2D space for
   * 2D objects.
   * The sketch will be automatically deleted with the solver instance.
   * @param ipSketch
   *   A pointer to the sketch callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   */
  int AddSketch(CATCSSketch* ipSketch);

  /**
   * Adds a rigid set to the solver.
   * A rigid set contains geometric objects and declares that they
   * are relatively fixed with respect to each other.
   * Objects are added to rigid sets using <tt>MoveGeometryToRigidSet</tt>.
   * The rigid set will be automatically deleted with the solver instance.
   * @param ipRigidSet
   *   A pointer to the rigid set callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   * @see #MoveGeometryToRigidSet
   */
  int AddRigidSet(CATCSRigidSet* ipRigidSet);

  /**
   * Adds a geometric object to the solver.
   * The object will be automatically deleted with the solver instance.
   * @param ipGLeaf
   *   A pointer to the geometry callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   */
  int AddGeometry(CATCSGeometryLeaf* ipGLeaf);

  /**
   * Replaces geometric object in solver.
   * @param ipOldGLeaf
   *   A pointer to the old geometry callback.
   * @param ipNewGLeaf
   *   A pointer to the new geometry callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if already existing constraints can't accept ipNewGLeaf as argument
   */
  int ReplaceGeometry(CATCSGeometryLeaf* ipOldGLeaf, CATCSGeometryLeaf* ipNewGLeaf);

  /**
   * Puts a geometric object into a given rigid set.
   * @param ipGLeaf
   *   A pointer to the geometry callback.
   * @param ipRigidSet
   *   A pointer to the rigid set callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   */
  int MoveGeometryToRigidSet(CATCSGeometryLeaf* ipGLeaf, CATCSRigidSet* ipRigidSet);

  /**
   * Get list of geometric objects for given rigid set.
   * @param ipRigidSet
   *   A pointer to the rigid set callback.
   * @param oNodes
   *   The list of pointers to geometric objects callbacks.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   */
  int GetGeometriesInRigidSet(const CATCSRigidSet* ipRigidSet, CATCDSLISTP(CATCSEntity) &oNodes);

  /**
   * Get the number of geometries in the rigid set.
   * @param ipRigidSet
   *   A pointer to the rigid set callback.
   * @return
   *   The number of geometries in the rigid set.
   */
  int GetNbOfGeometriesInRigidSet(CATCSRigidSet* ipRigidSet);

  /**
   * Converts a rigid set into the soft rigid set (if iStiffness > 0.0)
   * or backwards to the ordinary rigid set (if iStiffness <= 0.0).
   * @param ipRigidSet
   *   A pointer to the rigid set callback (should be already created and added to the ConstraintSolver)
   * @param iStiffness
   *   stiffness of the rigid set.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   */
  int SetRigidSetStiffness(CATCSRigidSet* ipRigidSet, double iStiffness);

    /**
   * if retunrs a double > 0.0 means that is it a soft rigid set
   * @param ipRigidSet
   *   A pointer to the rigid set callback (should be already created and added to the ConstraintSolver)
   * @param iStiffness
   *   stiffness of the rigid set.
   * @return
   rigidset's stifness
   */
  double GetRigidSetStiffness(CATCSRigidSet* ipRigidSet);

  /**
   * Converts a rigid set into the rigid set with scale DOF.
   * The variable corresponds to the value of scale.
   * If ipVariable is NULL, rigid sets becomes ordinary.
   * @param ipRigidSet
   *   A pointer to the rigid set callback,
   * @param ipVariable
   *   A pointer to the variable for rigid sets' scale.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid.
   */
  int SetScaleVariable(CATCSRigidSet* ipRigidSet, CATCSVariable* ipVariable);

  /**
   * Retrieves scale variable of a rigid set.
   * @param ipRigidSet
   *   A pointer to the rigid set callback.
   * @return
   *   a pointer to rigid set's scale variable - if rigid set is scalable,
   *   NULL - if rigid set is not scalable.
   */
  CATCSVariable* GetScaleVariable(CATCSRigidSet* ipRigidSet);

  /**
   * Adds a constraint to the solver.
   * Each constraint has one, two, or three geometric objects as arguments.
   * The constraint will be automatically deleted with the solver instance.
   * @param ipConstraint
   *   A pointer to the constraint callback
   * @param ipGLeaf1
   *   A pointer to the geometric object that is the first argument
   * @param ipGLeaf2
   *   A pointer to the geometric object that is the second argument
   * @param ipGLeaf3
   *   An optional pointer to the geometric object that is the third argument
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid,
   *   2 - if constraint is not supported.
   */
  int AddConstraint(CATCSGeomConstraint* ipConstraint,
                    CATCSGeometryLeaf* ipGLeaf1,
                    CATCSGeometryLeaf* ipGLeaf2,
                    CATCSGeometryLeaf* ipGLeaf3 = 0);

  /**
   * Converts a dimensional constraint into a variable dimensional constraint.
   * @param ipConstraint
   *   A pointer to the constraint callback
   * @param ipVariable
   *   A pointer to variable callback
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   */
  int SetConstraintVariable(CATCSGeomDimConstraint* ipConstraint, CATCSVariable* ipVariable);

  /**
  * Associates given variables with a given argument of a given constraint.
  * @param ipConstraint
  *   A pointer to the constraint callback
  * @param ipGLeaf
  *   A pointer to the geometric object that is the argument of constraint
  * @param ipVariable1
  *   A pointer to variable callback to be associated
  *   with parameter on curve or the first parameter on surface
  * @param ipVariable2
  *   A pointer to variable callback to be associated
  *   with the second parameter on surface
  * @return
  *   0 - if the function succeeded,
  *   1 - if arguments are invalid.
  */
  int SetHelpParameterVariable(CATCSGeomConstraint* ipConstraint,
                               CATCSGeometryLeaf* ipGLeaf,
                               CATCSVariable* ipVariable1,
                               CATCSVariable* ipVariable2 = 0);
  int GetHelpParameterVariable(CATCSGeomConstraint* ipConstraint,
                               CATCSGeometryLeaf* ipGLeaf,
                               CATCSVariable*& opVariable1,
                               CATCSVariable*& opVariable2);

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
   */
  int SetConstraintStiffness(CATCSGeomConstraint* ipConstraint, double iStiffness);  

    /**
   * Gives a priotiy to an orientation (leading) of a constraint
   *   A pointer to the constraint callback (should be already created and added to the ConstraintSolver)
   * @param iStiffness
   *   softness of the orientation of the constraint; 
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   *   2 - if the constraint is not orientad ! 
   */
  int SetConstraintLeadingSoftness(CATCSGeomConstraint* ipConstraint , double iVarCleading_softness);

  /**
   * Adds a pattern constraint to the solver.
   * A pattern constraint is a (n+1)-ary constraint of symmetry for
   * axis and n objects.
   * The pattern will be automatically deleted with the solver instance.
   * @param ipPattern
   *   A pointer to the pattern callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if argument is NULL,
   *   2 - if the pattern constraint is not defined
   *       with the given geometric arguments.
   */
  int AddPattern(CATCSPattern* ipPattern);

  /**
   * Adds an offset constraint to the solver.
   * The pattern will be automatically deleted with the solver instance.
   * @param ipPattern
   *   A pointer to the pattern callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if argument is NULL,
   *   2 - if the pattern constraint is not defined
   *       with the given geometric arguments.
   */
  int AddOffsetConstraint(CATCSOffsetConstraint* ipOffsetConstraint);

  /**
   * Adds a kinematic joint to the solver.
   * A joint is a kind of constraints that is used for kinematic applications.
   * The joint will be automatically deleted with the solver instance.
   * @param ipJoint
   *   A pointer to the joint callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if argument is NULL.
   */
  int AddJoint(CATCSJoint* ipJoint);

  /**
   * Adds a contact to the solver.
   */
  int AddContact(CATCSContact* ipContact);

  /**
   * Adds a free variable to the solver.
   * The variable will be automatically deleted with the solver instance.
   * @param ipFreeVariable
   *   A pointer to the variable callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if argument is NULL.
   */
  int AddFreeVariable(CATCSVariable* ipFreeVariable);

  /**
   * Adds a equation to the solver.
   * The equation will be automatically deleted with the solver instance.
   * @param ipEquation
   *   A pointer to the equation callback.
   * @return
   *   0 - if the function succeeded,
   *   1 - if argument is NULL.
   */
  int AddEquation(CATCSEquation* ipEquation);

  /**
   * Fixes/unfixes a geometric object in 3D space
   * (geometric object is 3D or 2D).
   * This function is used as a toggle (it changes the previous state).
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   New fixation state: TRUE if fixed, FALSE if unfixed.
   */
  CATCDSBoolean FixGeometryToggle(CATCSGeometry* ipGeometry);

  /**
   * Fixes/unfixes a geometric object on the sketch of the 2D geometry.
   * For 3D geometric objects this function does nothing.
   * This function is used as a toggle (it changes the previous state).
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   New fixation state: TRUE if fixed, FALSE if unfixed.
   */
  CATCDSBoolean FixGeometryToggle2D(CATCSGeometry* ipGeometry);

  /**
   * Returns fixation status of a geometric object in 3D space.
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   The fixation state: TRUE if fixed, FALSE if unfixed.
   */
  CATCDSBoolean IsGeometryFixed(CATCSGeometry* ipGeometry);

  /**
   * Returns fixation status of a geometric object on its sketch.
   * Always FALSE for 3D objects.
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   The fixation state: TRUE if fixed, FALSE if unfixed.
   */
  CATCDSBoolean IsGeometryFixed2D(CATCSGeometry* ipGeometry);

  /**
   * Softly fixes (if iStiffness > 0.0) and unfixes (if iStiffness <= 0.0) geometry in 3D space.
   * @param ipGeometry
   *   A pointer to the geometry callback (should be already created and added to the ConstraintSolver).
   * @param iStiffness
   *   stiffness of the fixation.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid.
   */
  int SetFixationStiffness(CATCSGeometry* ipGeometry, double iStiffness);

  /**
   * Softly fixes (if iStiffness > 0.0) and unfixes (if iStiffness <= 0.0) object on the sketch of the 2D geometry.
   * For 3D objects this function does nothing.
   * @param ipGeometry
   *   A pointer to the geometry callback (should be already created and added to the ConstraintSolver).
   * @param iStiffness
   *   stiffness of the fixation.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid.
   */
  int SetFixationStiffness2D(CATCSGeometry* ipGeometry, double iStiffness);

  /**
   * Allocates and fills in the array of pointers to callbacks of a given type.
   * @param iType type mask
   * @param ioNodes list of pointers to callbacks
   */
  void GetNodes(CATCSNType iType, CATCDSLISTP(CATCSEntity) &ioNodes) const;

  /**
   * @nodoc
   * Do not use. For compatibility only.
   */
  void GetNodes(CATCSNType iType, int &oNbNodes, CATCSEntity** &opNodes) const;

  /**
   * Fills in list of pointers to callbacks of a given type.
   * @param iType type match
   * @param ioCallbacks list of pointers to callbacks
   */
  void GetCallbacks(CATCSType iType, CATCDSLISTP(CATCSEntity) &ioCallbacks) const;

  /**
   * Returns the status of a geometric object.
   * The status is defined by the constraints imposed on the objects.
   * This function can only be called after Run.
   * @param ipGeometry
   *   A pointer to the geometry callback.
   * @return
   *   The status of the object is defined as the first appropriate value
   *   from the following list of <br><b>legal values</b>:
   *   <tt>gsFIXED</tt>:        it is fixed
   *   <tt>gsNOTCONSISTENT</tt>:it is an argument of an inconsistent constraint
   *   <tt>gsOVERDEFINED</tt>:  it is an argument of an overdefined constraint
   *   <tt>gsUNDERDEFINED</tt>: it has some degrees of freedom
   *   <tt>gsWELLDEFINED</tt>:  it has no degrees of freedom
   * @see #GetUnderdefinedStatus
   */
  CATGStatus GetStatus(CATCSGeometry* ipGeometry);

  /**
   * Returns the extended status for an underdefined geometric object.
   * This function gives more detailed information on degrees of freedom
   * of the geometric object or rigid set than <tt>GetStatus<//tt>.
   * @param ipGeometry
   *   A pointer to the geometry or rigid set callback.
   * @return
   *   The underdefined status as a bitwise combination of the following
   *   <br><b>legal values</b>:
   *   <tt>usRADIUS</tt>:      if the object is a circle, a sphere or a cylinder,
   *                           its radius can be changed
   *   <tt>usMAJORRADIUS</tt>: if the object is an ellipse, its major radius
   *                           can be changed
   *   <tt>usMINORRADIUS</tt>: if the object is an ellipse, its minor radius
   *                           can be changed
   *   <tt>usANGLE</tt>:       if the object is a directed geometry (i.e. it
   *                           is not a point or a circle), it can be rotated
   *   <tt>usPOSITION</tt>:    the object can be translated
   * @see #GetStatus
   */
  CATGUStatus GetUnderdefinedStatus(CATCSGeometry* ipGeometry);

  /**
   * Returns the status for a moved geometric object (should be called after SetDynamicMove).
   * This function gives information on moved status
   * of the geometric object or rigid set in 3D space.
   * @param ipNode
   *   A pointer to the geometry, rigid set or variable callback.
   * @return
   *   The status of the object is defined as the first appropriate value
   *   from the following list of <br><b>legal values</b>:
   *   <tt>msEXACTLYMOVED</tt>: moved exactly as required
   *   <tt>msMOVED</tt>:        moved, but not exactly as required
   *   <tt>msNOTMOVED</tt>:     not moved
   *
   * @see #SetDynamicMove
   */
  CATMoveStatus GetMoveStatus(CATCSEntity* ipNode);

  /**
   * Returns the status of a constraint.
   * @param ipConstraint
   *   A pointer to the constraint callback.
   * @return
   *   The status of the constraint is defined as the first appropriate value
   *   from the following list of <br><b>legal values</b>:
   *   <tt>csNOTVALID</tt>:     is is not valid: either the constraint was
   *                            declared between fixed objects, or between
   *                            objects of the same rigid sets, or the
   *                            combination of its arguments is inadmissble
   *                            (e.g. an angle between two points)
   *   <tt>csNOTSOLVED</tt>:    it was not solved due to some internal problems
   *   <tt>csNOTCONSISTENT</tt>:it is not satisfied (with given tolerances)
   *   <tt>csOVERDEFINED</tt>:  it is overdefined (i.e. it prevents the
   *                            satisfaction of some other constraints)
   *   <tt>csSATISFIED</tt>:    it is satisfied (with given tolerances)
   */
  CATCStatus GetStatus(CATCSConstraint* ipConstraint);

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

  CATVStatus GetStatus(CATCSVariable* ipVariable);

  /**
  * Returns the status of a contact.
  * @param ipContact
  *   A pointer to the contact callback.
  * @return
  *   The status of the contact is defined as the first appropriate value
  *   from the following list of <br><b>legal values</b>:
  *   <tt>tsUNKNOWN</tt>:            the contact status has not been computed
  *   <tt>tsNOTCONSISTENT</tt>:      it is not satisfied (a clash has been detected
  *                                  between the involved rigid sets)
  *   <tt>tsOUTOFCLASH</tt>:         it is satisfied (out of clash)
  *   <tt>tsCONTACT</tt>:            it is satisfied (but we are in the contact area)
  */
  CATCtStatus GetStatus(CATCSContact* ipContact);

  /**
   * @nodoc
   * Do not use. For compatibility only.
   */
  CATCStatus GetStatus(CATCSGeomConstraint* ipConstraint);

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
   *                                 satisfied with oConstraintValue
   */
  CATCSDiscrepancyStatus EvalDiscrepancy(CATCSConstraint* ipConstraint,
                                         double &oConstraintDiscrepancy,
                                         double &oConstraintValue,
                                         int oNbOfHelpPointValues[MAX_CONSTRAINT_PARAMS] = 0,
                                         double oHelpPointValues[MAX_CONSTRAINT_PARAMS*MAX_PARAM_VALUES] = 0,
                                         CATCDSBoolean iRefreshData = TRUE);

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
  *                                 satisfied with the values in oConstraintValues
  */
  CATCSDiscrepancyStatus EvalDiscrepancy(CATCSConstraint* ipConstraint,
    double &oConstraintDiscrepancy,
    double oConstraintValues[6],
    int oNbOfHelpPointValues[MAX_CONSTRAINT_PARAMS] = 0,
    double oHelpPointValues[MAX_CONSTRAINT_PARAMS*MAX_PARAM_VALUES] = 0,
    CATCDSBoolean iRefreshData = TRUE);

  /**
   * Check if constraints are satisfied
   */
  CATCDSBoolean IsSatisfied() const;

  /*
   * Initialize constraint help points
   * Be careful model is initialized by the method
   */
  void InitializeHelpPoints();

  /**
   * @nodoc
   * Do not use. For compatibility only.
   */
  CATCSDiscrepancyStatus EvalDiscrepancy(CATCSGeomConstraint* ipConstraint,
                                         double &oConstraintDiscrepancy,
                                         double &oConstraintValue);

  /**
   * Returns the redundancy status of a given constraint and additional
   * information.
   *
   * A constraint is called redundant if its removal does not add any degree
   * of freedom to the geometric objects.
   * @param ipConstraint
   *   A pointer to the current constraint callback.
   * @param ioFullyRedConstraints
   *   If status is rsPARTIALLYREDUNDANT, the list contains pointers to the callbacks
   *   of constraints which become fully redundant due to the presence of the
   *   current constraint.
   * @param ioImpliedConstraints
   *   If status is rsPARTIALLYREDUNDANT, the list contains pointers to the callbacks
   *   of constraints which make the constraints of the list oapFullyRedConstraints
   *   fully redundant.
   *   If the status is rsFULLYREDUNDANT, the list contains pointers to the callbacks
   *   of constraints which make the current constraint fully redundant.
   * @return status of the current constraint
   *   The status of the constraint is defined as the first appropriate value
   *   from the following list of <br><b>legal values</b>:
   *     <tt>rsNOTSATISFIED</tt>
   *     <tt>rsNOTREDUNDANT</tt>
   *     <tt>rsFULLYREDUNDANT</tt>
   *     <tt>rsPARTIALLYREDUNDANT</tt>
   */
  CATCSRedundancyStatus IsRedundant(CATCSConstraint* ipConstraint,
                                    CATCDSLISTP(CATCSConstraint) &ioFullyRedConstraints,
                                    CATCDSLISTP(CATCSConstraint) &ioImpliedConstraints);

  /**
   * @nodoc
   * Do not use. For compatibility only.
   */
  CATCSRedundancyStatus IsRedundant(CATCSConstraint* ipConstraint,
                                    unsigned int &oFullyRedConstraints,
                                    CATCSConstraint** &oapFullyRedConstraints,
                                    unsigned int &oImpliedConstraints,
                                    CATCSConstraint** &oapImpliedConstraints);

  /**
   * @nodoc
   * Do not use. For compatibility only.
   */
  CATCSRedundancyStatus IsRedundant(CATCSGeomConstraint* ipConstraint,
                                    unsigned int &oFullyRedConstraints,
                                    CATCSGeomConstraint** &oapFullyRedConstraints,
                                    unsigned int &oImpliedConstraints,
                                    CATCSGeomConstraint** &oapImpliedConstraints);

  /**
  * Sets the priority of the constraint.
  * @param ipConstraint
  *   pointer to the constraint
  * @param iPriority
  *   priority of the constraint
  */
  void SetRedundantConstraintPriority(CATCSConstraint *ipConstraint, int iPriority);

  /**
   * Calculates redundancy states of constraints
   * @param oFullyRedConstraints - the list of pointers to the callbacks
   *   of constraints which are fully redundant
   * @param oPartiallyRedConstraints - the list of pointers to the callbacks
   *   of constraints which are partially redundant
   * @return
   *   0 - if the function succeeded,
   *   1 - if the geometry is not satisfied or arguments are invalid.
   */
  int ComputeRedundantConstraints(CATCDSLISTP(CATCSConstraint) &oFullyRedConstraints,
                                  CATCDSLISTP(CATCSConstraint) &oPartiallyRedConstraints);

  /**
   * Returns the dependency classes of variables.
   * @param ioVariablesInClass
   *   An array of list of pointers to the variables. Each list contains
   *   the variables which belong to the same dependency class.
   * @return
   *   0 - if the function succeeded,
   *   1 - if the function failed.
   */
  int GetDependentVariables(CATCDSARRAY(CATCDSListPCATCSVariable) &ioVariablesInClass);

  /**
   * @nodoc
   * Do not use. For compatibility only.
   */
  int GetDependentVariables(unsigned int &oClasses,
                            unsigned int *&oaVariablesInClass,
                            CATCSVariable*** &oaapVariablesInClass);

  /**
   * DEPRECATED : use SetDerivativesComputationMode, Run and GetDerivatives
   * Retrieves the first and the second partial derivatives for axis. All the
   * arrays must be allocated by the user.
   * @param ipAxis
   *   A pointer to the axis.
   * @param oaaJacobian[N][12]
   *   An array of the first derivatives, where N is the number of commands
   *   set with <tt>SetTargetValues</tt> method.
   * @param oaaaHessian[N][N][12]
   *   An array of the second derivatives, where N is the number of commands
   *   set with <tt>SetTargetValues</tt> method.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the function succeeded,
   *     <li><tt>1</tt> - if the function failed.
   *   </ul>
   * @see #SetTargetValues
   */
  int GetDerivativesAtSimulationPoint(CATCSAxis *ipAxis, double **oaaJacobian, double ***oaaaHessian);

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
  void SetDerivativesComputationMode(CATCSDerivMode iMode);

  /**
   * Gets the derivatives computation mode.
   * @return
   *   <br><b>legal values</b>:
   *   <tt>drNONE</tt>:                          do not perform derivatives computation (default)
   *   <tt>drDERIVATIVES_AT_START_POINT</tt>:    computes derivatives at the start point of the simulation step
   *   <tt>drDERIVATIVES_AT_END_POINT</tt>:      computes derivatives at the end point of the simulation step
   * @see #SetDerivativesComputationMode
   */
  CATCSDerivMode GetDerivativesComputationMode() const;

  /**
   * Sets the list of axes whose derivatives will be computed (if the derivatives computation mode is
   * not set to drNONE) during the following calls to <tt>Run</tt>.
   * See <tt>SetDerivativesComputationMode</tt> for more information about derivatives computation.
   * @param iAxes
   *   A list of pointers to CATCSAxis entities
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the function succeeded,
   *     <li><tt>1</tt> - if one argument is invalid.
   *   </ul>
   * @see #SetDerivativesComputationMode
   */
  int SetDerivativesComputationAxes(CATCDSLISTP(CATCSAxis) & iAxes);

  /**
   * Sets the list of sketches whose derivatives will be computed (if the derivatives computation mode is
   * not set to drNONE) during the following calls to <tt>Run</tt>.
   * See <tt>SetDerivativesComputationMode</tt> for more information about derivatives computation.
   * @param iSketches
   *   A list of pointers to CATCSSketch entities
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the function succeeded,
   *     <li><tt>1</tt> - if one argument is invalid.
   *   </ul>
   * @see #SetDerivativesComputationMode
   */
  int SetDerivativesComputationSketches(CATCDSLISTP(CATCSSketch) & iSketches);

  /**
   * Sets the list of variables whose derivatives will be computed (if the derivatives computation mode is
   * not set to drNONE) during the following calls to <tt>Run</tt>.
   * See <tt>SetDerivativesComputationMode</tt> for more information about derivatives computation.
   * @param iVariables
   *   A list of pointers to CATCVariable entities
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the function succeeded,
   *     <li><tt>1</tt> - if one argument is invalid.
   *   </ul>
   * @see #SetDerivativesComputationMode
   */
  int SetDerivativesComputationVariables(CATCDSLISTP(CATCSVariable) & iVariables);

  /**
   * Retrieves the first and the second partial derivatives for axis according to the
   * derivatives computation mode set by <tt>SetDerivativesComputationMode</tt>.
   * This function should be called after Run.
   * All the arrays must be allocated by the user.
   * @param ipAxis
   *   A pointer to the axis.
   * @param oaaJacobian[N][12]
   *   An array of the first derivatives, where N is the number of commands
   *   set with <tt>SetTargetValues</tt> method.
   * @param oaaaHessian[N][N][12]
   *   An array of the second derivatives, where N is the number of commands
   *   set with <tt>SetTargetValues</tt> method.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt>  - if the derivatives have been computed,
   *     <li><tt>FALSE</tt> - if no derivatives information is available for this axis
   *   </ul>
   * @see #SetTargetValues, #SetDerivativesComputationMode
   */
  CATCDSBoolean GetDerivatives(const CATCSAxis *ipAxis, double **oaaJacobian, double ***oaaaHessian) const;

  /**
   * Retrieves the first and the second partial derivatives for sketches according to the
   * derivatives computation mode set by <tt>SetDerivativesComputationMode</tt>.
   * This function should be called after Run.
   * All the arrays must be allocated by the user.
   * @param ipSketch
   *   A pointer to the sketch.
   * @param oaaJacobian[N][9]
   *   An array of the first derivatives, where N is the number of commands
   *   set with <tt>SetTargetValues</tt> method.
   * @param oaaaHessian[N][N][9]
   *   An array of the second derivatives, where N is the number of commands
   *   set with <tt>SetTargetValues</tt> method.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt>  - if the derivatives have been computed,
   *     <li><tt>FALSE</tt> - if no derivatives information is available for this sketch
   *   </ul>
   * @see #SetTargetValues, #SetDerivativesComputationMode
   */
  CATCDSBoolean GetDerivatives(const CATCSSketch *ipSketch, double **oaaJacobian, double ***oaaaHessian) const;

  /**
   * Retrieves the first and the second partial derivatives for variable according to the
   * derivatives computation mode set by <tt>SetDerivativesComputationMode</tt>.
   * This function should be called after Run.
   * All the arrays must be allocated by the user.
   * @param ipVariable
   *   A pointer to the variable.
   * @param oaJacobian[N]
   *   An array of the first derivatives, where N is the number of commands
   *   set with <tt>SetTargetValues</tt> method.
   * @param oaaHessian[N][N]
   *   An array of the second derivatives, where N is the number of commands
   *   set with <tt>SetTargetValues</tt> method.
   * @return
   *   <ul>
   *     <li><tt>TRUE</tt>  - if the derivatives have been computed,
   *     <li><tt>FALSE</tt> - if no derivatives information is available for this variable
   *   </ul>
   * @see #SetTargetValues, #SetDerivativesComputationMode
   */
  CATCDSBoolean GetDerivatives(const CATCSVariable *ipVariable, double *oaJacobian, double **oaaHessian) const;

  /**
   * Returns the leading status of a given constraint and additional information.
   * This function should be called after Run.
   * @param ipConstraint
   *   A pointer to the current constraint callback.
   * @param ioConstraintsInLoop
   *   If status is lsINVALID, the list contains pointers to the callbacks
   *   of constraints which involved in the current leading constraints loop
   * @return status of the current constraint,
   *   <br><b>legal values</b>:
   *     <tt>lsUNKNOWN</tt>:    status is unknown, call Run method first
   *     <tt>lsNOTLEADING</tt>: constraint is not leading
   *     <tt>lsVALID</tt>:      constraint is not involved in any leading constraints loop
   *     <tt>lsINVALID</tt>:    constraint is involved in some leading constraints loop
   */
  CATCSLeadingStatus GetLeadingConstraintStatus(CATCSGeomConstraint* ipConstraint,
                                                CATCDSLISTP(CATCSGeomConstraint) &ioConstraintsInLoop);

  /**
   * Specifies the pattern for auto constraining.
   * @param iConstraintType constraint type
   * @param ibLogical constraint type precision:
   *  to distinguish between a parallelity/perpendicularity and an angle
   * @param iGeometryType1 type of the 1st argument
   * @param iGeometryType2 type of the 2nd argument
   *  If iGeometryType == tpANYTYPE, all geometry types are allowed (if it makes sense)
   * @param inGeom size of the list ipListGeom
   * @param ipListGeom list of pointers to geometries
   */
  void SetAutoConstrainingPattern(CATCSType iConstraintType,
                                  CATCDSBoolean ibLogical,
                                  CATCSType iGeometryType1,
                                  CATCSType iGeometryType2,
                                  int inGeom,
                                  CATCSGeometryLeaf** ipListGeom);

  /**
   * Specifies the pattern for auto constraining.
   * This pattern allows the constraints only between the corresponding pairs
   * of geometries.
   * @param iConstraintType constraint type
   * @param ibLogical constraint type precision:
   *  to distinguish between a parallelity/perpendicularity and an angle
   * @param iGeometryType1 type of the 1st argument
   * @param iGeometryType2 type of the 2nd argument
   *  If iGeometryType == tpANYTYPE, all geometry types are allowed (if it makes sense)
   * @param inGeom size of the lists ipListGeom
   * @param ipListGeom1 list of pointers to the 1st arguments
   * @param ipListGeom2 list of pointers to the 2nd arguments
   */
  void SetAutoConstrainingCouplePattern(CATCSType iConstraintType,
                                        CATCDSBoolean ibLogical,
                                        CATCSType iGeometryType1,
                                        CATCSType iGeometryType2,
                                        int inGeom,
                                        CATCSGeometryLeaf** ipListGeom1,
                                        CATCSGeometryLeaf** ipListGeom2);

  /**
   * Specifies the pattern for auto constraining.
   * This pattern allows the constraints only between the corresponding triples
   * of geometries.
   * @param iConstraintType constraint type
   * @param iGeometryType1 type of the 1st argument
   * @param iGeometryType2 type of the 2nd argument
   * @param iGeometryType3 type of the 3rd argument
   *  If iGeometryType == tpANYTYPE, all geometry types are allowed (if it makes sense)
   * @param inGeom size of the lists ipListGeom
   * @param ipListGeom1 list of pointers to the 1st arguments
   * @param ipListGeom2 list of pointers to the 2nd arguments
   * @param ipListGeom3 list of pointers to the 3rd arguments
   */
  void SetAutoConstrainingTriplePattern(CATCSType iConstraintType,
                                        CATCSType iGeometryType1,
                                        CATCSType iGeometryType2,
                                        CATCSType iGeometryType3,
                                        int inGeom,
                                        CATCSGeometryLeaf** ipListGeom1,
                                        CATCSGeometryLeaf** ipListGeom2,
                                        CATCSGeometryLeaf** ipListGeom3);

  /**
   * Clears the patterns for auto-constraining.
   * @see #SetAutoConstrainingPattern, #SetAutoConstrainingCouplePattern
   */
  void ResetAutoConstrainingPatterns();

  /**
   * Sets the pointer to a callback used in auto-constraining
   * (for instance, to compute the weights of constraints).
   * @param ipTool pointer to an auto-constraining callback tool
   */
  void SetAutoConstrainingTool(CATCSAutoConstrainingTool* ipTool);

  /**
   * Perform auto-constraining.
   * @parm onConstraints number of constraint descriptors
   * @param oapConstraints table of constraint descriptors
   * @return
   *   0        in case of success
   *   non-zero otherwise
   */
  int DoAutoConstraining(int &onConstraints, CATCSConstraintDescr **&oapConstraints);

  /**
   * Set the mode for the creation of the constraints list.
   * @param iOptimized boolean
   *    <br> TRUE : if wants to create with optimization.
   *    <br> FALSE : if wants to create full constraints list.
   */
  void SetAutoConstraintMode(CATCDSBoolean iOptimized);

    /**
   * Get the mode for the creation of the constraints list.
   * @return the mode for the creation of the constraints list
   *    <br> TRUE : if wants to create with optimization.
   *    <br> FALSE : if wants to create full constraints list.
   */
  CATCDSBoolean GetAutoConstraintMode();

  /**
   * Set the type of ordering constraint using weights.
   * @param iACWeightType
   *   <br> CATACNone        : Without weight.
   *   <br> CATACExternal    : With weight generated by an external application.
   *   <br> CATACTopological : With weight generated by an internal function using topological considerations.
   *                           If this option is chosen, CATCSAutoConstrainingTool is ignored.
   */
  void SetACWeightType(CATACWeightType iACWeightType);

    /**
   * Get the type of ordering constraint using weights.
   * @return ACWeightType
   *   <br> CATACNone        : Without weight.
   *   <br> CATACExternal    : With weight generated by an external application.
   *   <br> CATACTopological : With weight generated by an internal function using topological considerations.
   *                           If this option is chosen, CATCSAutoConstrainingTool is ignored.
   */
  CATACWeightType GetACWeightType();

  void CreateListFoAutoConstraining(int &onConstraints, CATCSConstraintDescr **&oapConstraints, CATCDSBoolean iKeepResultInternaly = FALSE, CATCDSBoolean iOptimized = TRUE);

  // if oaIsToAdd is not null, it must be the initial size of ioConstraints. if oaIsToAdd[i] is TRUE, input ioConstraints[i] must be added to the model.
  // if iUseInternalData == FALSE, update internal list of constraints with the input list of constraint descriptors (foe example to take weight intp account).
  // set iUseInternalData to TRUE only when the list computed by CreateListFoAutoConstraining has not been modified.
  // ioConstraints is replaced by the list of constraint descriptor computed by auto-contraint.
  int DoACAddConstraint(int &ionConstraints, CATCSConstraintDescr ** &ioapConstraints, CATCDSBoolean iUseInternalData = FALSE, CATCDSBoolean *oaIsToAdd=0);

  /**
   * Create an CATCSGeomConstraint from an CATCSConstraintDescr.
   * @param ipConstrDescr
   *   CATCSConstraintDescr to convert in CATCSGeomConstraint
   * @return
   *   the CATCSGeomConstraint got from ipConstrDescr
   *
   * <b>Supported types</b> : tpDISTANCE, tpANGLE, tpPARALLELISM, tpPERPENDICULARITY, tpCOINCIDENCE, tpTANGENCY, tpANTITANGENCY,
   *                    tpRADIUS, tpMAJORRADIUS, tpMINORRADIUS,  tpAPEXANGLE, tpCONCENTRICITY, tpCOAXIALITY, tpMIDPOINT, tpSYMMETRY
   */
  CATCSGeomConstraint * CreateAndAddConstraint(CATCSConstraintDescr * ipConstrDescr);

  /**
   * Removes an entity (object, rigid set or constraint) from the solver
   * and deletes it.
   * @param ipEntity
   *  A pointer to the entity callback that will be removed and deleted.
   * @return
   *   0 - if the function succeeded,
   *   1 - if arguments are invalid
   */
  int EraseNode(CATCSEntity* ipEntity);

  /**
   * Removes all entities (object, rigid set or constraint) from the solver.
   * @param oRemovedEntities
   *   A list of pointers to the entities that has been removed. These
   *   entities can be deleted if they are not used anymore by the user.
   * @return
   *   0 - if the function succeeded,
   *   1 - if the function failed
   */
  int RemoveAllNodes(CATCDSListPCATCSEntity &oRemovedEntities);

  /**
   * Sets the solver mode that preserves chirality or ignore it.
   * Preserving chirality means keeping the relative positions of objects
   * connected by constraints.
   * E.g. a 2D point cannot jump over 2D line is there is a distance
   * constraint between them; if a 2D point is outside a 2D circle, it
   * cannot move inside if there is distance constraint between them, etc.
   * @param iMode
   *   <br><b>Legal values</b>:
   *   1 preserve chirality,
   *   0 do not care about chirality
   * @see #ChangeChirality
   */
  void SetPreserveChiralityMode(int iMode);

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
  virtual int GetPreserveChiralityMode();

  /**
   * Change chirality of a particular constraint.
   * This function forces the solver to find the opposite relative positions
   * for arguments of the constraints. E.g. if the constraint is a distance
   * between a point and a line in 2D, it forces the point to jump over the
   * line; if it is a point-circle distance, it forces a point to jump inside
   * or outside the circle to change their initial relative position.
   * @param ipConstraint
   *  A pointer to the constraint callback.
   * @see #SetPreserveChiralityMode
   */
  void ChangeChirality(CATCSGeomConstraint* ipConstraint);

  CATCDSBoolean GetChangeChirality(CATCSGeomConstraint* ipConstraint);

  /**
   * Flush chirality of a particular constraint, that was stored on the previous run.
   * @param ipConstraint
   *  A pointer to the constraint callback.
   * @see #SetPreserveChiralityMode, #ChangeChirality
   */
  void FlushChirality(CATCSGeomConstraint* ipConstraint);

  /**
   * Get chirality of a particular constraint, that was computed before the previous run.
   * If some values can't be calculated or have no sense
   * corresponding parameters get NOTSPECIFIED values.
   * @param ipConstraint
   *  A pointer to the constraint callback.
   * @param oAlignment
   *   <br><b>legal values</b>:
   *     <tt>caNOTSPECIFIED</tt>:     value is unknown,
   *     <tt>caALIGN</tt>:            the directions of geometries are aligned,
   *     <tt>caANTIALIGN</tt>:        the directions of geometries are anti-aligned.
   *
   * @param oSurfaceOrientation
   *  temporary used for 2d tangency
   *   <br><b>legal values</b>:
   *     <tt>soNOTSPECIFIED</tt>:     value is unknown,
   *     <tt>soPOSITIVE</tt>:         the normals of surfaces are aligned,
   *     <tt>soNEGATIVE</tt>:         the normals of surfaces are anti-aligned.
   *
   * @param oHalfSpaceGeom1
   * @param oHalfSpaceGeom2
   *   <br><b>legal values</b>:
   *     <tt>hsNOTSPECIFIED</tt>:     value is unknown,
   *     <tt>hsPOSITIVE</tt>:         the distance is taken on the positive side
   *                                  of the surface (with respect to the normal),
   *     <tt>hsNEGATIVE</tt>:         the distance is taken on the negative side
   *                                  of the surface (with respect to the normal).
   */
  void GetChirality(CATCSGeomConstraint* ipConstraint,
                    CATCAlignment& oAlignment,
                    CATCSurfaceOrientation& oSurfaceOrientation,
                    CATPHalfSpace& oHalfSpaceGeom1,
                    CATPHalfSpace& oHalfSpaceGeom2);

  /**
   * Compute current chirality of a particular constraint.
   * If some values can't be calculated or have no sense
   * corresponding parameters get NOTSPECIFIED values.
   * @param ipConstraint
   *  A pointer to the constraint callback.
   * @param oAlignment
   *   <br><b>legal values</b>:
   *     <tt>caNOTSPECIFIED</tt>:     value is unknown,
   *     <tt>caALIGN</tt>:            the directions of geometries are aligned,
   *     <tt>caANTIALIGN</tt>:        the directions of geometries are anti-aligned.
   *
   * @param oSurfaceOrientation
   *  temporary used for 2d tangency
   *   <br><b>legal values</b>:
   *     <tt>soNOTSPECIFIED</tt>:     value is unknown,
   *     <tt>soPOSITIVE</tt>:         the normals of surfaces are aligned,
   *     <tt>soNEGATIVE</tt>:         the normals of surfaces are anti-aligned.
   *
   * @param oHalfSpaceGeom1
   * @param oHalfSpaceGeom2
   *   <br><b>legal values</b>:
   *     <tt>hsNOTSPECIFIED</tt>:     value is unknown,
   *     <tt>hsPOSITIVE</tt>:         the distance is taken on the positive side
   *                                  of the surface (with respect to the normal),
   *     <tt>hsNEGATIVE</tt>:         the distance is taken on the negative side
   *                                  of the surface (with respect to the normal).
   */
  void ComputeChirality(CATCSGeomConstraint* ipConstraint,
                        CATCAlignment& oAlignment,
                        CATCSurfaceOrientation& oSurfaceOrientation,
                        CATPHalfSpace& oHalfSpaceGeom1,
                        CATPHalfSpace& oHalfSpaceGeom2);

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
  void GetTolerances(double &oLinearTolerance, double &oAngularTolerance);

  /**
   * Sets tolerances.
   * @param iLinearTolerance
   *   Linear tolerance (a positive real value).
   * @param iAngularTolerance
   *   Angular tolerance (a positive real value in radians).
   * @see #GetTolerances
   */
  void SetTolerances(double iLinearTolerance, double iAngularTolerance);

  /**
   * Sets reference linear tolerance.
   * @param iTolerance
   *   Reference linear tolerance (a positive real value).
   * @see #SetReferenceLinearTolerance
   */
  double GetReferenceLinearTolerance() const;

  /**
   * Retrieves reference linear tolerance.
   * @return
   *   Reference linear tolerance (a positive real value).
   * @see #GetReferenceLinearTolerance
   */
  void SetReferenceLinearTolerance(double iTolerance);

  /**
   * Estimates actual model size.
   * @return
   *   estimation of the actual model size, rounded up to the nearest degree of 10.
   */
  double GetActualModelSize();

  /**
   * Gets the current output mode.
   * @return iOutputMode
   *   <br><b>Output values</b>:
   *   <tt>omCALLBACK_ROOT_ELEMENTS</tt>
   *   <tt>omCALLBACK_ALL_ELEMENTS</tt>
   * @see #SetOutputMode
   */
  CATCSOutputMode GetOutputMode();

  /**
   * Sets the output mode.
   * This mode defines how the solving transformations (which makes all
   * constraints satisfied) will be applied to the geometric objects
   * and rigid sets.
   * @param iOutputMode
   *   <br><b>Legal values</b>:
   *   <tt>omCALLBACK_ROOT_ELEMENTS</tt>: transformation will be applied
   *                                      for root elements only:
   *                                      rigid sets and elements which are
   *                                      not included in rigid sets
   *                                      (this is the default mode)
   *   <tt>omCALLBACK_ALL_ELEMENTS</tt>:  transformations will be applied
   *                                      to all objects and rigid sets
   */
  void SetOutputMode(CATCSOutputMode iOutputMode);

  /**
   * Sets the partial solving mode.
   * This mode defines how CDS will solve inconsistent problems:
   * there is always the tradeoff between performance and quality.
   * @param iPSMode
   *   <br><b>Legal values</b>:
   *   <tt>psALWAYS</tt>:               always find partial solution, i.e.
   *                                    satisfy as many constraints as
   *                                    possible (the default mode)
   *   <tt>psFAIL_IF_INCONSISTENT</tt>: find partial solution, but stop
   *                                    the solving process if any
   *                                    inconsistency is detected during it
   */
  void SetPartialSolvingMode(CATPartialSolvingMode iPSMode);

    /**
   * Gets the partial solving mode.
   * This mode defines how CDS will solve inconsistent problems:
   * there is always the tradeoff between performance and quality.
   * @return
   *   <br><b>Legal values</b>:
   *   <tt>psALWAYS</tt>:               always find partial solution, i.e.
   *                                    satisfy as many constraints as
   *                                    possible (the default mode)
   *   <tt>psFAIL_IF_INCONSISTENT</tt>: find partial solution, but stop
   *                                    the solving process if any
   *                                    inconsistency is detected during it
   */
  CATPartialSolvingMode GetPartialSolvingMode();

  /**
   * Sets solving mode for Update functionality.
   * @param iMode
   *   <br><b>Legal values</b>:
   *   <tt>slSTANDARD</tt>:       the solver moves geometry rigidly if possible
   *
   *   <tt>slMINIMUM_MOVE</tt>:   the solver moves minimum of objects (default)
   */
  void SetSolvingMode(CATSolvingMode iMode);

    /**
   * Get solving mode for Update functionality.
   * @return
   *   <br><b>Legal values</b>:
   *   <tt>slSTANDARD</tt>:       the solver moves geometry rigidly if possible
   *
   *   <tt>slMINIMUM_MOVE</tt>:   the solver moves minimum of objects (default)
   */
  CATSolvingMode GetSolvingMode();

  /**
   * Sets the Update mode.
   * @param iUpdateMode
   *   <br><b>Legal values</b>:
   *   <tt>umEVALUATE</tt>:               usual mode (default)
   *
   *   <tt>umREEVALUATE</tt>:             for the black-box parameters,
   *                                      use stored values obtained during
   *                                      the previous run.
   *
   *   <tt>umEVALTRANSFORM</tt>:          Eval by transformation mode.
   */
  void SetUpdateMode(CATUpdateMode iUpdateMode);

    /**
   * Get the Update mode.
   * @return
   *   <br><b>Legal values</b>:
   *   <tt>umEVALUATE</tt>:               usual mode (default)
   *
   *   <tt>umREEVALUATE</tt>:             for the black-box parameters,
   *                                      use stored values obtained during
   *                                      the previous run.
   *
   *   <tt>umEVALTRANSFORM</tt>:          Eval by transformation mode.
   */
  CATUpdateMode GetUpdateMode();

  /**
   * Sets the diagnostics mode.
   * @param iDiagMode
   *   <br><b>legal values</b>:
   *   <tt>dmNOTSOLVED</tt>:       run diagnostics if the model could not be solved (default)
   *
   *   <tt>dmALWAYS</tt>:          always run diagnostics
   *
   *   <tt>dmNOTOVERDEFINED</tt>:  run overdefined diagnostics, and welldefined diagnostics if the model is not overdefined
   *
   *   <tt>dmNEVER</tt>:           do not run diagnostics
   *
   *   <tt>dmHEAL</tt>:            solve antagonisms (according to priorities)
   */
  void SetDiagnosticsMode(CATDiagMode iDiagMode);

  /**
   * Returns the diagnostics mode.
   * @return DiagMode
   */
  CATDiagMode GetDiagnosticsMode() const;

  /**
   * Sets the diagnostics computation mode for rigid sets.
   * @param iRigidSetDiagMode
   *   <br><b>legal values</b>:
   *   <tt>rdWITHOUTDOS</tt>:   DOS will be excluded from DOF for diagnostics computation of rigid sets (default)
   *
   *   <tt>rdFULL</tt>:         full DOF will be taken into account for diagnostics computation of rigid sets
   */
  void SetRigidSetDiagnosticMode(CATRigidSetDiagMode iRigidSetDiagMode);

    /**
   * Returns the rigid set diagnostic mode.
   * @return
   *   Rigid set diagnostic mode from the following list of <br><b>legal values</b>:
   *  <tt>rdWITHOUTDOS</tt>: the DOS of the rigid sets are ignored in DOF computation.
   *  <tt>rdFULL</tt>: take into account the DOS of the rigid sets during DOF computation.
   */
  CATRigidSetDiagMode GetRigidSetDiagnosticMode();

  /**
  * Sets the overdefined diagnostics mode.
  * @param iOverdefinedDiagMode
  *   <br><b>legal values</b>:
  *   <tt>odDIMENSIONAL</tt>: (default) only dimensional constraints are able to provide overdefined diagnostics
  *
  *   <tt>odFULL</tt>:        dimensional and logical constraints are able to provide overdefined diagnostics
  */
  void SetOverdefinedDiagnosticsMode(CATOverdefinedDiagMode iOverdefinedDiagMode);

    /**
  * Get the overdefined diagnostics mode.
  * @return
  *   <br><b>legal values</b>:
  *   <tt>odDIMENSIONAL</tt>: (default) only dimensional constraints are able to provide overdefined diagnostics
  *
  *   <tt>odFULL</tt>:        dimensional and logical constraints are able to provide overdefined diagnostics
  */
  CATOverdefinedDiagMode GetOverdefinedDiagnosticsMode();

  /**
   * Sets the simulation mode. This method is deprecated and should not be
   * used in newly-written code. Use <b>SetDynamicMoveMode</b> instead.
   * @param iSimMode
   *   <b>Legal values:</b>
   *   <dl>
   *   <dt><tt>smOBSOLETE</tt>
   *   <dd> run simulation using the deprecated architecture (do not use it
   *        unless you're sure you know what you're doing)
   *   <dt><tt>smSTANDARD</tt>
   *   <dd>run simulation in the usual configuration (default)
   *   <dt><tt>smPERTURBATION</tt>
   *   <dd>run simulation with a perturbation technique applied
   *   </dl>
   * @see #SetDynamicMoveMode
   */
  void SetSimulationMode(CATSimMode iSimMode);

  /**
   * Sets the Variables Inter-dependency mode.
   * @param iMode
   *   <br><b>legal values</b>:
   *   <tt>vmNEVER</tt>:        do not run the Variables Inter-dependency diagnostics (default)
   *
   *   <tt>vmSOLVED</tt>:       run the Variables Inter-dependency diagnostics if the model
   *                            is solved
   */
  void SetVarDependencyMode(CATCSVarDepMode iMode);


  /**
  Set a mode that minimize the discrepancy of the springs 
  */
  void SetOptimisationMode(CATCDSBoolean iMode);

    /**
   * Get the Variables Inter-dependency mode.
   * @return
   *   <br><b>legal values</b>:
   *   <tt>vmNEVER</tt>:        do not run the Variables Inter-dependency diagnostics (default)
   *
   *   <tt>vmSOLVED</tt>:       run the Variables Inter-dependency diagnostics if the model
   *                            is solved
   */
  CATCSVarDepMode GetVarDependencyMode();

  /**
  * Sets the contacts diagnostics mode.
  * @param iContactsDiagMode
  *   <br><b>legal values</b>:
  *   <tt>cdCLASH_DETECTED</tt>:  run contacts diagnostics if a clash is detected during solving (default)
  *
  *   <tt>cdALWAYS</tt>:          always run contacts diagnostics
  *
  *   <tt>cdNEVER</tt>:           do not run contacts diagnostics
  */
  void SetContactsDiagnosticsMode(CATContactsDiagMode iContactsDiagMode);

  /**
  * Returns the contacts diagnostics mode.
  * @return ContactsDiagMode
  */
  CATContactsDiagMode GetContactsDiagnosticsMode() const;

  /**
  * Sets the mode to check unsolvable constraints during the <tt>Run</tt> method
  * (unsolvable constraints are: (1) constraints between objects of the same rigid set
  *                              (2) constraints between fixed objects)
  * @param iMode boolean
  *    <br> TRUE : to check unsolvable constraints (the <tt>Run</tt> method will return an error code in case of failure).
  *    <br> FALSE : to ignore unsolvable constraints during the solve (default).
  */
  void SetCheckUnsolvableConstraintsMode(CATCDSBoolean iMode);

  /**
  * Gets the current mode for checking unsolvable constraints.
  * @return the mode (boolean)
  */
  CATCDSBoolean GetCheckUnsolvableConstraintsMode() const;

  /**
  * Sets the mode to move geometry without taking clashes into account but preserving contacts
  * @param iMode boolean
  *    <br> TRUE : ignore clash but preserve contacts
  *    <br> FALSE :  (default).
  */
  void SetMoveOutOfClashMode(CATCDSBoolean iMode);

  /**
  * Gets the current mode for GetMoveOutOfClashMode.
  * @return the mode (boolean)
  */
  CATCDSBoolean GetMoveOutOfClashMode() const;

  /**
   * Sets the solving mode for IK
   * @param iMode boolean
   *    <br> TRUE : IK only seeks exact solution (all variables are ExactlyMoved), does not move anything if no exact solution is found
   *    <br> FALSE : Default mode, seeks the closest solution in the DOF
  */
  void SetInverseKinematicsMode(CATCDSBoolean iMode);
  
  /**
   * Gets the current mode for IK
   * @return the mode (boolean)
  */
  CATCDSBoolean GetInverseKinematicsMode() const;

  /**
  * Sets the mode to solve geometry by solving all clashs 
  * @param iMode CATUpdateOutOfClashMode
  *    <br> ocNONE : (default).
  *    <br> ocBASIC : greedy algorithm
  */
  void SetUpdateOutOfClashMode(CATUpdateOutOfClashMode iMode);

  /**
  * Gets the current mode for GetUpdateOutOfClashMode.
  * @return CATUpdateOutOfClashMode
  */
  CATUpdateOutOfClashMode GetUpdateOutOfClashMode() const;

  /**
   * Activates incremental computation mode : independent components and diagnostics will be computed in an incremental way
   * (by default all is recomputed at each solve which costs more time).
   * @param iIncrementalMode
   *   Activate or deactivate incremental move
   */
  void SetIncrementalMode(CATCDSBoolean iIncrementalMode);

  /**
  * Gets the current incremental mode.
  * @return
  *   TRUE if the mode is activated, FALSE otherwise
  */
  CATCDSBoolean GetIncrementalMode() const;

  /** @nodoc
   *
   */
  void RereadHelpParameters(CATCDSBoolean iMode);
  CATCDSBoolean GetRereadHelpParameters() const;

  /**
   * Sets the streaming tool.
   * @param ipStreamTool
   *   pointer to a streaming tool object
   */
#ifdef CDS_DEBUG
  void SetStreamTool(CATCSStreamTool* ipStreamTool);
#endif
  /**
   * Gets the streaming tool.
   * @return
   *   A pointer to the declared streaming tool object (null if no streaming
   *   tool has been declared to the solver).
   */
#ifdef CDS_DEBUG
  CATCSStreamTool* GetStreamTool();
#endif
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
  int Run();

  /**
   * Makes a rollback to the state that was before the last call to
   * <tt>Run</tt>.
   * @see #Run
   */
  void UndoRun();

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
  CATCDSBoolean IsInitiallySatisfied();

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
  void Reset();


  /**
  reset the state manager for the reevalute.
  next call of reevaluate will be a full evaluate
  To use for instance if geometry has been moved in order to change the chirality of the solution.
  */
  void ResetHistory();

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
  void SetDynamicMoveMode(CATMoveMode iMode);

    /**
   * Get the solving mode for dynamic move and kinematics.
   * @return
   *    Move mode.
   * @see #SetDynamicMove, #SetTargetValues
   */
  CATCDSMoveMode GetDynamicMoveMode();

  void AddInterferenceValidator(CATCSInterferenceValidator* ipInterferenceValidator);

  /**
   * Activate accurate move for dynamic move and kinematics.
   * @param iAccurateMove
   *   Activate or deactivate accurate move
   * @see #SetDynamicMove, #SetTargetValues
   */
  void SetAccurateMove(CATCDSBoolean iAccurateMove);

    /**
   * return accurate move for dynamic move and kinematics.
   * @return
   *   Is accurate move is activated or deactivated 
   */
  CATCDSBoolean GetAccurateMove();

  /**
   * Activate perturbation for dynamic move and kinematics.
   * @param iAccurateMove
   *   Activate or deactivate perturbation
   * @see #SetDynamicMove, #SetTargetValues
   */
  void SetPerturbationMove(CATCDSBoolean iPerturbationMove);

  /**
   * Get the status (Activate or deactivate) of the perturbation for dynamic move and kinematics.
   * @return iAccurateMove
   * @see #SetDynamicMove, #SetTargetValues
   */
  CATCDSBoolean GetPerturbationMove();

  /**
  * Activate adaptive move for dynamic move and kinematics.
  * @param iAdaptiveMove
  *   Activate or deactivate adaptive move
  */
  void SetAdaptiveMove(CATCDSBoolean iAdaptiveMove);

  /**
  * Get the status (Activated or Deactivated) of adaptive move for dynamic move and kinematics.
  * @return
  *   Is adaptive move activated.
  */
  CATCDSBoolean GetAdaptiveMove();

  /**
   * Sets the value of a circle or ellipse radii for dynamic move.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   A pointer to the geometry callback
   * @param iMajorRadius
   *   The value for a circle radius or ellipse major radius
   * @param iMinorRadius
   *   The value for an ellipse minor radius
   * @return
   *   0 if the function succeeded
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  int SetDynamicMove(CATCSGeometry* ipGeometry, double iMajorRadius, double iMinorRadius);

  /**
   * Sets a transformation for dynamic move.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   A pointer to the geometry callback
   * @param iaaRotation
   *   A rotation matrix
   * @param iaTranslation
   *   A translation vector
   * @return
   *   1 if the function succeeded
   *   0 if the geometry is fixed
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  int SetDynamicMove(CATCSGeometry* ipGeometry, double iaaRotation[3][3], double iaTranslation[3]);

  /**
   * Set translation only to re-evaluate.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   geometry to be moved
   * @param iaTranslation
   *   translation vector
   * @return
   *   1 if the function succeeded
   *   0 if the geometry is fixed
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  int SetDynamicMove(CATCSGeometry* ipGeometry, double iaTranslation[3]);

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
  int SetDynamicMove(CATCSGeometryLeaf* ipGeometry, double const iDragLineOrigin[3], double const iDragLineDirection[3]);

  /**
   * Sets a drag line for dynamic move. The geometries will be moved in order to be as close as
   * possible to the drag line.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param iGeometries
   *   Geometries to be moved
   * @param iDragLineOrigin
   *   Coordinates of the drag line origin
   * @param iDragLineDirection
   *   Coordinates of the drag line direction
   * @return
   *   0 if the function succeeded
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  int SetDynamicMove(CATCDSLISTP(CATCSGeometryLeaf) &iGeometries, double iDragLineOrigin[3], double iDragLineDirection[3]);

  /**
   * Sets a 2D rotation for dynamic move.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   A pointer to the geometry callback
   * @param iaaRotation
   *   A rotation matrix
   * @param iaTranslation
   *   A translation vector
   * @return
   *   0 if the function succeeded
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  int SetDynamicMove2D(CATCSGeometry* ipGeometry, double iaaRotation[2][2], double iaTranslation[2]);

  /**
   * Sets a 2D translation for dynamic move.
   * To make the dynamic move, one should call to <tt>Run</tt> after
   * the call to <tt>SetDynamicMove</tt>.
   * To reset the initial position for dynamic move, use <tt>Reset</tt>.
   * To set the desired behaviour of the solver during the dynamic move
   * use <tt>SetDynamicMoveMode</tt>.
   * @param ipGeometry
   *   A pointer to the geometry callback
   * @param iaTranslation
   *   A translation vector
   * @return
   *   0 if the function succeeded
   * @see #Run, #Reset, #SetDynamicMoveMode
   */
  int SetDynamicMove2D(CATCSGeometry* ipGeometry, double iaTranslation[2]);

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
  int SetPreviousRadii(CATCSGeometry* ipGeometry, double iMajorRadius, double iMinorRadius);

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
  int SetAppliedTransformation2D(CATCSGeometry* ipGeometry, double iaaRotation[2][2], double iaTranslation[2]);

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
   *   The diagnostics of simulability:
   *   <ul>
   *     <li><tt>sdSIMULABLE</tt> - the mechanism is simulable,
   *     <li><tt>sdOVERCONSTRAINED</tt> - the mechanism is overconstrained
   *     since too many commands are given,
   *     <li><tt>sdUNDERCONSTRAINED</tt> - the mechanism is not simulable
   *     since too few commands are given,
   *     <li><tt>sdSINGULAR</tt> - the mechanism is simulable with
   *     perturbation only.
   *   </ul>
   * @see #SetDegreesOfFreedomMode
   */
  CATCSSimulabilityDiagnostics IsSimulable(int iNbCommands,
                                           CATCSVariable** iapCommands,
                                           int &oNbDofWithCommands,
                                           int &oNbDofWithoutCommands);

  /**
   * Retrieves the singularity diagnostics. It allows to detect whether
   * a singularity has been passed during simulation.
   * @return
   *   <tt>TRUE</tt> if a singularity is detected,
   *   <tt>FALSE</tt> otherwise.
   */
  CATCDSBoolean IsSingularityDetected();

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
   */
  int SetTargetValues(int iNbCommands, CATCSVariable **iapCommands, double *iaTargetValues);

  /**
   * Sets variable priorities for commands. Must be used with <tt>SetDynamicMove</tt> or <tt>SetTargetValues</tt>.
   * @param iNbCommands
   *   The number of commands.
   * @param iapCommands
   *   An array of pointers to the commands.
   * @param iaPriorities
   *   An array of priorities values of the commands.
   * @return
   *   <ul>
   *     <li><tt>0</tt> - if the function succeeded,
   *     <li><tt>1</tt> - if the function failed.
   *   </ul>
   * @see #SetDynamicMove, #SetTargetValues,
   */
  int SetVariablePriorities(int iNbCommands, CATCSVariable **iapCommands, int *iaPriorities);

  /**
   * Retrieves the variables which have reached their limits after dynamic move or simulation.
   * @param ioVariables
   *   A list of variables
   * @param ioIsUpperLimit
   *   A list of indicators:
   *   <tt>TRUE</tt> if the upper limit has been reached,
   *   <tt>FALSE</tt> if the lower limit has been reached.
   */
  void GetReachedVariableLimits(CATCDSLISTP(CATCSVariable) &ioVariables,
                                CATCDSArray<CATCDSBoolean> &ioIsUpperLimit);

  /**
   * Sets the solving mode for degrees of freedom (DOF) calculation. It is
   * possible to compute full DOF space of an object or exclude its degrees
   * of symmetry (DOS) from DOF space.
   * @param iMode
   *   <br><b>Legal values:</b>
   *   <ul>
   *     <li><tt>dmFULL</tt> - the solver will calculate full DOF,
   *     <li><tt>dmWITHOUTDOS</tt> - the solver will exclude DOS from DOF.
   *   </ul>
   * @see #GetDegreesOfFreedom,
   *      #GetDegreesOfFreedom2D,
   *      #GetRelativeDegreesOfFreedom,
   *      #GetRelativeDegreesOfFreedom2D,
   *      #GetNumberOfDegreesOfFreedom,
   *      #IsSimulable
   */
  void SetDegreesOfFreedomMode(CATCSDOFMode iMode);

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
  CATCDSDOFMode GetDegreesOfFreedomMode();

  /**
   * Retrieves the information on the instantaneous degrees of freedom (DOFs)
   * of an object or a rigid set under constraints imposed on it.
   * An instantaneous DOF defines an infinitesimal transformation that
   * can be applied to the object (rigid set) without violation of any
   * constraint imposed on it.
   * An instantaneous DOF can be either a translation along some direction,
   * either a rotation around some axis, or a screw (a combination of a
   * rotation around some axis with a translation along it with a given
   * pitch value - a ratio between rotation and translation).
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and axis,
   * All the arrays must be allocated by the user.
   * The function assumes that any object/rigid set always has 6 DOFs.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param oTranslations
   *   The number of translational DOFs
   * @param oRotations
   *   The number of rotational DOFs
   * @param oScrews
   *   The number of screw DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOFs:
   *   for a translational DOF its data is a direction (a unit vector),
   *   for a rotational DOF it is an axis (point and direction),
   *   for a screw DOF it is an axis (point and direction) and a pitch value.
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error.
   * @see #GetDegreesOfFreedom2D
   */
  int GetDegreesOfFreedom(CATCSGeometry* ipGeom,
                          unsigned int &oTranslations,
                          unsigned int &oRotations,
                          unsigned int &oScrews,
                          CATDOFStatus oaStatuses[6],
                          double oaData[6][7]);

  /**
   * DEPRECATED : use method with CATCSDOFDiagnostic instead
   * Retrieves the information on the relative degrees of freedom (DOFs)
   * of an object or a rigid set under constraints which connects it with
   * the parent object or rigid set.
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and axis,
   * All the arrays must be allocated by the user.
   * The function assumes that any object/rigid set always has 6 DOFs.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param ipParentGeom
   *   A pointer to the parent geometry
   * @param oTranslations
   *   The number of translational DOFs
   * @param oRotations
   *   The number of rotational DOFs
   * @param oScrews
   *   The number of screw DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOFs:
   *   for a translational DOF its data is a direction (a unit vector),
   *   for a rotational DOF it is an axis (point and direction),
   *   for a screw DOF it is an axis (point and direction) and a pitch value.
   * @param iRestrictingConstraints
   *   A pointer to a list of constraints to take into account to compute the
   *   relative degrees of freedom (all other constraints will be ignored).
   *   Constraints that are not between the input objects will be ignored and 3
   *   is returned by this method.
   *   If null or if the size of the list is 0, all constraints connecting the object
   *   to the parent object are taken into account.
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error,
   *   3 if a constraint in iRestrictingConstraints is not between the input objects.
   */
  int GetRelativeDegreesOfFreedom(CATCSGeometry* ipGeom,
                                  CATCSGeometry* ipParentGeom,
                                  unsigned int &oTranslations,
                                  unsigned int &oRotations,
                                  unsigned int &oScrews,
                                  CATDOFStatus oaStatuses[6],
                                  double oaData[6][7],
                                  CATCDSLISTP(CATCSConstraint) *iRestrictingConstraints = 0);

  /**
   * @nodoc
   * Internal use only
   */
  void SetInvariantDegreesOfFreedomComputation(CATCDSBoolean iInvariantDOFComputation);

  /**
   * Retrieves the information on the relative degrees of freedom (DOFs)
   * of an object or a rigid set under constraints which connects it with
   * the parent object or rigid set.
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and axis,
   * All the arrays must be allocated by the user.
   * The function assumes that any object/rigid set always has 6 DOFs.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param ipParentGeom
   *   A pointer to the parent geometry
   * @param oTranslations
   *   The number of translational DOFs
   * @param oRotations
   *   The number of rotational DOFs
   * @param oScrews
   *   The number of screw DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOFs:
   *   for a translational DOF its data is a direction (a unit vector),
   *   for a rotational DOF it is an axis (point and direction),
   *   for a screw DOF it is an axis (point and direction) and a pitch value.
   * @param oDiagnostic
   *   A diagnostic for invariant DOF computation (always ddUNKNOWN if invariant
   *   DOF computation is set to FALSE)
   * @param iRestrictingConstraints
   *   A pointer to a list of constraints to take into account to compute the
   *   relative degrees of freedom (all other constraints will be ignored).
   *   Constraints that are not between the input objects will be ignored and 3
   *   is returned by this method.
   *   If null or if the size of the list is 0, all constraints connecting the object
   *   to the parent object are taken into account.
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error,
   *   3 if a constraint in iRestrictingConstraints is not between the input objects.
   */
  int GetRelativeDegreesOfFreedom(CATCSGeometry* ipGeom,
                                  CATCSGeometry* ipParentGeom,
                                  unsigned int &oTranslations,
                                  unsigned int &oRotations,
                                  unsigned int &oScrews,
                                  CATDOFStatus oaStatuses[6],
                                  double oaData[6][7],
                                  CATCSDOFDiagnostic & oDiagnostic,
                                  CATCDSLISTP(CATCSConstraint) *iRestrictingConstraints = 0);

  /**
   * @nodoc
   * Internal use only.
   */
  CATCDSBoolean GetInvariantDegreesOfFreedom(unsigned int &oTranslations,
                                             unsigned int &oRotations,
                                             unsigned int &oScrews,
                                             CATDOFStatus oaStatuses[6],
                                             double oaData[6][7]);

  /**
   * @nodoc
   * Internal use only.
   */
  CATCDSBoolean GetInvariantDegreesOfFreedom2D(unsigned int &oTranslations,
                                               unsigned int &oRotations,
                                               CATDOFStatus oaStatuses[3],
                                               double oaData[3][2]);

  /**
   * Retrieves the information on the instantaneous 2D degrees of freedom (DOFs)
   * of an object or a rigid set under constraints imposed on it in 2D space.
   * An instantaneous 2D DOF defines an infinitesimal 2D transformation that
   * can be applied to the object (rigid set) without violation of any
   * constraint imposed on it.
   * An instantaneous 2D DOF can be either a translation along some direction,
   * either a rotation around some point.
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and points.
   * All the arrays must be allocated by the user.
   * The function assumes that any object (rigid set) always has 3 degrees
   * of freedom in 2D space.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param oTranslations
   *   The number of translational DOFs
   * @param oRotations
   *   The number of rotational DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOF:
   *   for translational DOF this data is a direction,
   *   for rotational DOF it is a point of rotation
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error.
   * @see #GetDegreesOfFreedom
   */
  int GetDegreesOfFreedom2D(CATCSGeometry* ipGeom,
                            unsigned int &oTranslations,
                            unsigned int &oRotations,
                            CATDOFStatus oaStatuses[3],
                            double oaData[3][2]);

  /**
   * DEPRECATED : use method with CATCSDOFDiagnostic instead
   * Retrieves the information on the instantaneous 2D degrees of freedom (DOFs)
   * of an object or a rigid set under constraints which connects it with
   * the parent object or rigid set in 2D space.
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and points.
   * All the arrays must be allocated by the user.
   * The function assumes that any object (rigid set) always has 3 degrees
   * of freedom in 2D space.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param ipParentGeom
   *   A pointer to the parent geometry
   * @param oTranslations
   *   The number of translational DOFs
   * @param oRotations
   *   The number of rotational DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOF:
   *   for translational DOF this data is a direction,
   *   for rotational DOF it is a point of rotation
   * @param iRestrictingConstraints
   *   A pointer to a list of constraints to take into account to compute the
   *   relative degrees of freedom (all other constraints will be ignored).
   *   Constraints that are not between the input objects will be ignored and 3
   *   is returned by this method.
   *   If null or if the size of the list is 0, all constraints connecting the object
   *   to the parent object are taken into account.
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error,
   *   3 if a constraint in iRestrictingConstraints is not between the input objects.
   */
  int GetRelativeDegreesOfFreedom2D(CATCSGeometry* ipGeom,
                                    CATCSGeometry* ipParentGeom,
                                    unsigned int &oTranslations,
                                    unsigned int &oRotations,
                                    CATDOFStatus oaStatuses[3],
                                    double oaData[3][2],
                                    CATCDSLISTP(CATCSConstraint) *iRestrictingConstraints = 0);

  /**
   * Retrieves the information on the instantaneous 2D degrees of freedom (DOFs)
   * of an object or a rigid set under constraints which connects it with
   * the parent object or rigid set in 2D space.
   * Returned information is: the total number of DOFs, status flags and
   * arrays of directions and points.
   * All the arrays must be allocated by the user.
   * The function assumes that any object (rigid set) always has 3 degrees
   * of freedom in 2D space.
   * @param ipGeom
   *   A pointer to the geometry which DOFs are required to find
   * @param ipParentGeom
   *   A pointer to the parent geometry
   * @param oTranslations
   *   The number of translational DOFs
   * @param oRotations
   *   The number of rotational DOFs
   * @param oaStatuses
   *   An array of statuses of all DOFs
   * @param oaData
   *   An array of data of all DOF:
   *   for translational DOF this data is a direction,
   *   for rotational DOF it is a point of rotation
   * @param oDiagnostic
   *   A diagnostic for invariant DOF computation (always ddUNKNOWN if invariant
   *   DOF computation is set to FALSE)
   * @param iRestrictingConstraints
   *   A pointer to a list of constraints to take into account to compute the
   *   relative degrees of freedom (all other constraints will be ignored).
   *   Constraints that are not between the input objects will be ignored and 3
   *   is returned by this method.
   *   If null or if the size of the list is 0, all constraints connecting the object
   *   to the parent object are taken into account.
   * @return
   *   0 if the function calculated all the DOFs successfully,
   *   1 if there are violated constraints in given rigid set,
   *   2 in case of internal error,
   *   3 if a constraint in iRestrictingConstraints is not between the input objects.
   */
  int GetRelativeDegreesOfFreedom2D(CATCSGeometry* ipGeom,
                                    CATCSGeometry* ipParentGeom,
                                    unsigned int &oTranslations,
                                    unsigned int &oRotations,
                                    CATDOFStatus oaStatuses[3],
                                    double oaData[3][2],
                                    CATCSDOFDiagnostic & oDiagnostic,
                                    CATCDSLISTP(CATCSConstraint) *iRestrictingConstraints = 0);

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
   */
  int GetNumberOfDegreesOfFreedom(unsigned int &oNumber);

  int GetConnexComponents(const CATCDSListPCATCSGeometry &iNonCuttingFixedGeom,
                          CATCDSARRAY(CATCDSListPCATCSEntity) &oConnexComponents);

  
  /**
  no doc
  */
  int GetConnexComponentFromEntity(CATCSEntity * iStartEntity, const CATCDSListPCATCSGeometry &iNonCuttingFixedGeom, CATCDSListPCATCSEntity &oConnexComponent);

  /**
   * Find all the CATCSEntity pointing on ipEntity.
   * @param ipEntity
   *    Target entity.
   * @param onEntities
   *    Size of oapEntities.
   * @param oapEntities
   *    Output array of entities pointing to the input entity. 
   * @param iType
   *    Type of the output entities. 
   */
  int GetConnexEntities(CATCSEntity *ipEntity, CATCDSListPCATCSEntity &oListOfConnexEntities, CATCDSType iType = tpANYTYPE) const;

  /**
  * Retrieves the current transformation on a geometry.
  * @param ipGeometry
  *   A pointer to the geometry or rigid set callback
  * @param oaaMatrix
  *   A rotation matrix
  * @param oaVector
  *   A translation vector
  * @return
  *   <tt>TRUE</tt> for non-identity transformation,
  *   <tt>FALSE</tt> otherwise
  */
  CATCDSBoolean GetTransformation(const CATCSGeometry* ipGeometry, double oaaMatrix[3][3], double oaVector[3]) const;

  /**
   * Retrieves the current transformation on a geometry.
   * @param ipGeometry
   *   A pointer to the geometry or rigid set callback
   * @param oaaMatrix
   *   A transformation matrix (2x2 rotation and translation vector)
   * @return
   *   <tt>TRUE</tt> for non-identity matrix,
   *   <tt>FALSE</tt> otherwise
   */
  CATCDSBoolean GetTransformation2D(const CATCSGeometry* ipGeometry, double oaaMatrix[3][3]) const;

  /**
   * Checks if a geometry has non-identity current transformation.
   * For dependent curve, checks if any of its definition objects has transformation.
   * Does not take into account dependency on parameter or another dependent curve.
   * @param ipGeometry
   *   A pointer to the geometry or rigid set callback
   * @return
   *   <tt>TRUE</tt> for non-identity transformation,
   *   <tt>FALSE</tt> otherwise
   */
  CATCDSBoolean HasTransformation(CATCSGeometry* ipGeometry) const;

  /**
   * Retrieves the radius of a circle.
   * @param ipGeometryLeaf
   *   A pointer to the circle callback
   * @param oRadius
   *   The value of a radius
   * @return
   *   <tt>TRUE</tt> if succeeded,
   *   <tt>FALSE</tt> is failed
   */
  CATCDSBoolean GetRadius(CATCSGeometryLeaf* ipGeometryLeaf, double &oRadius);

  /**
   * Retrieves the offset between the current and the initial values of the circle radius.
   * @param ipGeometryLeaf
   *   A pointer to the circle callback
   * @param oRadius
   *   The value of a radius
   * @return
   *   <tt>TRUE</tt> if succeeded,
   *   <tt>FALSE</tt> is failed
   */
  CATCDSBoolean GetRadiusOffset(CATCSGeometryLeaf* ipGeometryLeaf, double &oRadius);

  /**
   * Retrieves the radii of an ellipse.
   * @param ipGeometryLeaf
   *   A pointer to the circle callback
   * @param oMajorRadius
   *   The value of the major radius
   * @param oMinorRadius
   *   The value of the minor radius
   * @return
   *   <tt>TRUE</tt> if succeeded,
   *   <tt>FALSE</tt> is failed
   */
  CATCDSBoolean GetRadii(CATCSGeometryLeaf* ipGeometryLeaf, double &oMajorRadius, double &oMinorRadius);

  /**
   * Retrieves the offsets between the current and the initial values of the ellipse radii.
   * @param ipGeometryLeaf
   *   A pointer to the circle callback
   * @param oMajorRadius
   *   The value of the major radius
   * @param oMinorRadius
   *   The value of the minor radius
   * @return
   *   <tt>TRUE</tt> if succeeded,
   *   <tt>FALSE</tt> is failed
   */
  CATCDSBoolean GetRadiiOffset(CATCSGeometryLeaf* ipGeometryLeaf, double &oMajorRadius, double &oMinorRadius);

  /**
   * Retrieves the help point location for a constraint with a circle.
   * A help point is a point where the circle is coincident to a point or
   * tangent to a line, or from what the distance constraint is measured.
   * @param ipGeometry
   *   A pointer to the circle callback
   * @param ipConstraint
   *   A pointer to the constraint callback
   * @param oaHelpPoint
   *   Coordinates of the corresponding help point
   * @return
   *   <tt>TRUE</tt> if succeeded,
   *   <tt>FALSE</tt> is failed
   */
  CATCDSBoolean GetHelpPoint2D(CATCSGeometryLeaf* ipGeometry, CATCSGeomConstraint* ipConstraint, double oaHelpPoint[2]);

  /**
   * Set the help point location for a constraint with a circle.
   * A help point is a point where the circle is coincident to a point or
   * tangent to a line, or from what the distance constraint is measured.
   * @param ipGeometry
   *   A pointer to the circle callback
   * @param ipConstraint
   *   A pointer to the constraint callback
   * @param iaHelpPoint
   *   Coordinates of the corresponding help point
   */
  void SetHelpPoint2D(CATCSGeometryLeaf* ipGeometry, CATCSGeomConstraint* ipConstraint, double iaHelpPoint[2]);

  /**
   * @nodoc
   * Used to create ConstraintSolver with existing Imp object.
   */
  CATConstraintSolver(CATCDSSolverInterface* ipSolverInterfaceImp);

  void UseNew3DRigidificationHeuristic(CATCDSBoolean iMode);

  CATCDSBoolean GetNew3DRigidificationHeuristic();


  // --- 2d/32 API ---

/**
* Create the p2DObject associated to ip3DObject in ipSketch
* @param ip3DObject : the 3D object
* @param ipSketch : the support sketch
* @param op2DObject : the 2d object if the node have already been created by public interfaces, do not use with old interfaces
 @return :
  0 if 2d Object is created and p3DObject is lying on ipSketch
  1 if the 2d Object is created but p3DObject is not lying on ipSketch
  2 if the 2d object has already been created
  3 if the 2d object cannot be created(invalid type of input ..
  */

  int Create2DRep(CATCSSketch* ipSketch, CATCSGeometryLeaf* p3DObject, CATCSGeometryLeaf* op2DObject = 0);

  /**
  * Get the associated 2d Geometry
  * @param ipSketch : the support sketch
  * @param ipGeomLeaf3D : the 3D geometry
  * @return the associated coincident 2D geometry if it exists, 0 elsewhere
  */
  CATCSGeometryLeaf* Get2DRep(CATCSSketch* ipSketch, CATCSGeometryLeaf* ipGeomLeaf3D);

  /**
  * Get the refenernce 2D Geometry
  * @param ipGeomLeaf2D : the 2D geometry
  * @return the associated coincident 3D geometry if it exists, 0 elsewhere
  */
  CATCSGeometryLeaf* Get3DRep(CATCSGeometryLeaf* ipGeomLeaf2D);


  /**
  * Get the list of sketch coincident of a 3d geometry
  * @param ipGeomLeaf3D : the 3D geometry
  * @param oNbSketches : the number of sketchs coincident to the 3d geometry
  * @param oaSketches : the table of pointers on sketched coincident to ipGeomLeaf3D
  */
  int GetListOfSupportSketch(CATCSGeometryLeaf* ipGeomLeaf3D, int& oNbSketches, CATCSSketch**& oaSketches);


#ifdef CDS_DEBUG
  /**
   * @nodoc
   * Used to dump the constraint problem into a standard output stream.
   */
  void Dump();

  /**
   * @nodoc
   * Used to write current input information (geometry, options) into defined stream.
   */
  void Dump(CATCDSStream &ioStream, int iStreamVersion);

  /**
   * @nodoc
   * Writes current solver state into ioStream for validation purpose
   * @param idx
   *   if positive output section headers has the corresponding suffix
   */
  void WriteOutput(CATCDSStream &ioStream, int iStreamVersion, int idx = -1);
#endif

  /**
   * @nodoc
   *  Sets a bundle of mathematical operators to be used by CDS if extended functions are enabled
   *  The bundle is optional and remains owned by the caller, it will no be deleted upon destruction of "this"
   * @param iMathBundle
   *   Current bundle to be used
   */  
  void SetMathBundle(CATICDSMathBundle * iMathBundle);

  /**
   * @nodoc
   * Internal use only
   */
  void SetUseImplicitSketches(CATCDSBoolean iUseImplicitSketches);

  /*
   * Validate current geometry
   * Note: the internal model is refreshed with the new coordinates and parameters of the objects
   * (therefore all stored statuses are erased)
   * @return
   *    TRUE if geometry satisfied, otherwise FALSE
   */
  CATCDSBoolean IsGeometrySatisfied() const;

  /*
   * Update the nodes with the interface object values
   * @return
   */
  void RefreshInternalData();

  /*
   * Add a new component into a profile. All components must lie on the same CATCSSketck
   * Note: The two bounding vertices must have been created before a curve, or line, or conic is added. The coincidence constraints that bind these vertices
   * to the mono-parametric element must also exist before the AddComponent method is invoked.
   * Start and end vertices are taken with respect to the profile orientation (if iRelativeOrientation=-1, iStartVertex is the end of the component according to its own parameterization)
   * Note that the profile cannot be used until the solver is run
   * @param iProfile Profile that will be modified
   * @param iComponent New curve, line or conic. Only a segment of it will be actually added to the profile. iComponent must be attached to the end of the profile
   * @param iRelativeOrientation +1 if iComponent and iProfile have same orientations, otherwise -1
   * @param iStartVertex Start vertex of the new curve (if the profile is not empty, it must be equal to the end vertex of the existing profile)
   * @param iEndVertex End vertex of the new curve 
   * @param iStartVertexExtrapolMode Defines the behavior of the mono-parametric element if it requires being extrapolated to meet the previous element of the profile
   * @param iEndVertexExtrapolMode Defines the behavior of the mono-parametric element if it requires being extrapolated to meet the next element of the profile
   */
  CATCDSBoolean AppendComponentToProfile(CATCSProfile2D & iProfile, CATCSMonoParametric & iComponent, int iRelativeOrientation, 
                                         CATCSPoint2D & iStartVertex, CATCSPoint2D & iEndVertex);

  /* Set the mode for keeping initial data on inconsistent geometry component
  * @param iKeepInitialData TRUE if we keep the initial data when a geometry component is inconsistent
  */
  void SetInitialDataOnInconsistentGeomComponentMode(CATCDSBoolean iKeepInitialData);

  /* Get the mode for keeping initial data on inconsistent geometry component
  * @return TRUE if we keep the initial data when a geometry component is inconsistent
  */
  CATCDSBoolean GetInitialDataOnInconsistentGeomComponentMode();

  /* Reduce the transformation 
  */
  void ReduceTransformation(CATCSGeometryLeaf* ipGeometryLeaf, double ioaaRotation[3][3], double ioaTranslation[3]) const;

  // For test infra
  //CATCDSVariableDomainStatus GetDomainStatus(CATCSVariable *ipVariable) const;
  int GetLeadingConstraintSubStatus(CATCSGeomConstraint *ipConstraint) const;

protected:
  /**
   * @nodoc
   * Pointer to implementation class.
   */
  CATCDSSolverInterface* _pImp;
  CATCDSBoolean _isOwnImp;

public:
  /**
   * @nodoc Temporary for public interface
   */
  CATCDSSolverInterface *GetImp();

  /**
   * @nodoc To specify if ConstraintSolver was created by Public Interfaces
   */
  void SetFromPublicInterfaces();

  /**
   * @nodoc Internal use only (plug)
   */
  int GetState();
     
  /** 
  *@nodoc Internal use only (plug)
  */
  int SetSpringStiffness(CATCSGeomConstraint* ipConstraint, double iStiffness);

#ifdef CDS_DEBUG
  /**
   * @nodoc
   */
  void WriteInput(CATCDSStream& ioStream);

  /**
   * @nodoc
   */
  int WriteInputJSON(CATCDSStream& ioStream);
#endif

private:
  CATConstraintSolver(const CATConstraintSolver &);
  void operator = (const CATConstraintSolver &);

  friend class CATConstraintSolverAdapter;
};

//-----------------------------------------------------------------------

#endif
