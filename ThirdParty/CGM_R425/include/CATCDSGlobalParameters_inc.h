// Do not include this file directly. Use CATCDSGlobalParameters.h

// Usage:
// DECLARE_BOOL_VARIABLE(VariableName, DefaultValue, VariableComment)

// DECLARE_INT_VARIABLE(VariableName, DefaultValue, VariableComment)

// BEGIN_DECLARE_ENUM_VARIABLE(VariableName, DefaultValue)
//   DECLARE_ENUM_VALUE(VariableName, ValueName, ValueComment)
// END_DECLARE_ENUM_VARIABLE(VariableName)

// BEGIN_DECLARE_MASK_VARIABLE(VariableName)
//   DECLARE_MASK_BIT(VariableName, MaskBit, DefaultValue, ValueName, ValueComment)
// END_DECLARE_MASK_VARIABLE(VariableName)

#undef CATCDSGlobalParameters_UseSetMembers
#include "CATCDSGlobalParameters_macros.h"
#include "CATCDSDebug.h"

// UseGS
DECLARE_BOOL_VARIABLE(UseGS, TRUE, "use geometry simplification")

// UseGD
DECLARE_BOOL_VARIABLE(UseGD, TRUE, "use geometric decomposition")

// UseIMOny
DECLARE_BOOL_VARIABLE(UseIMOnly, FALSE, "use only IM for unit tests")

// UseRROnly
DECLARE_BOOL_VARIABLE(UseRROnly, FALSE, "use only RR for unit tests")

// GDMethods
BEGIN_DECLARE_MASK_VARIABLE(GDMethods)
  DECLARE_MASK_BIT(GDMethods, 0, 0, NA, "not used")
  DECLARE_MASK_BIT(GDMethods, 1, 1, Clustering, "use clustering method")
  DECLARE_MASK_BIT(GDMethods, 2, 1, Cutting, "use cutting decomposition method")
  DECLARE_MASK_BIT(GDMethods, 3, 1, ExtendedCutting, "use extension of cutting decomposition method")
  DECLARE_MASK_BIT(GDMethods, 4, 1, CleanGeometry, "use eliminating from geometry of ternary constraints and circles with unfixed radius")
  DECLARE_MASK_BIT(GDMethods, 5, 0, RecursiveNHGD, "decompose geometry recursively by cutting and articulation point decomposition")
  DECLARE_MASK_BIT(GDMethods, 6, 0, ZeroHeuristicCutting, "use zero-heuristic patterns in cutting decomposition")
END_DECLARE_MASK_VARIABLE(GDMethods)

// UseNonHR
DECLARE_BOOL_VARIABLE(UseNonHR, TRUE, "use non-heuristic rigidification (cycles method)")

// UseHRFormalDOF
DECLARE_BOOL_VARIABLE(UseHRFormalDOF, TRUE, "use heuristic rigidification (formal DOF method)")

// UseNonHRTwoRS
DECLARE_BOOL_VARIABLE(UseNonHRTwoRS, TRUE, "use non-heuristic rigidification (DA2RS glueing)")

// HRTwoRSMode
BEGIN_DECLARE_ENUM_VARIABLE(HRTwoRSMode, SOLVE3D)
  DECLARE_ENUM_VALUE(HRTwoRSMode, SATISFIED, "use DA2RS with ONLY satisified constraints")
  DECLARE_ENUM_VALUE(HRTwoRSMode, SOLVE, "use DA2RS with NOT satisified constraints (solve geometry first)")
  DECLARE_ENUM_VALUE(HRTwoRSMode, SOLVE3D, "use DA2RS with ONLY satisified constraints in 2D, solve first in 3D")
END_DECLARE_ENUM_VARIABLE(HRTwoRSMode)

// UseNonHRThreeRS
DECLARE_BOOL_VARIABLE(UseNonHRThreeRS, FALSE, "use non-heuristic rigidification (DA3RS glueing)")

// HRThreeRSMode
BEGIN_DECLARE_ENUM_VARIABLE(HRThreeRSMode, SOLVE)
  DECLARE_ENUM_VALUE(HRThreeRSMode, SATISFIED, "use DA3RS with ONLY satisified constraints")
  DECLARE_ENUM_VALUE(HRThreeRSMode, SOLVE, "use DA3RS with NOT satisified constraints (solve geometry first)")
END_DECLARE_ENUM_VARIABLE(HRThreeRSMode)

// UseNonHGD
DECLARE_BOOL_VARIABLE(UseNonHGD, TRUE, "use non-heuristic geometric decomposition")

// UseFixationPreprocess
DECLARE_BOOL_VARIABLE(UseFixationPreprocess, TRUE, "use preprocessing thread for update of help parameters and variable values only")

// UseTO
DECLARE_BOOL_VARIABLE(UseTO, TRUE, "use translation only thread")

//Prototype for pt-pt-di chirality on a linear segment
//!tmp
DECLARE_BOOL_VARIABLE(KeepPtPtLnDiChirality, TRUE, "keep pt-pt-di chirality on a linear segment")

// CMMode
DECLARE_BOOL_VARIABLE(UseCMDOFRR, FALSE, "use DOF relative representation")

// DecompIMMode
BEGIN_DECLARE_ENUM_VARIABLE(DecompIMMode, ADIM3Specs)
  DECLARE_ENUM_VALUE(DecompIMMode, ADIMRS, "decomposition only inside RS")
  DECLARE_ENUM_VALUE(DecompIMMode, ADIM3Specs, "decomposition by 3 specs (non-heuristic)")
END_DECLARE_ENUM_VARIABLE(DecompIMMode)

// UseAD
DECLARE_BOOL_VARIABLE(UseAD, TRUE, "use algebraic decomposition")

// ADMode
BEGIN_DECLARE_ENUM_VARIABLE(ADMode, SOFT)
  DECLARE_ENUM_VALUE(ADMode, HARD, "detach overconstraining equations in a separate subsystem")
  DECLARE_ENUM_VALUE(ADMode, SOFT, "preserve integrity of the overconstrained component")
END_DECLARE_ENUM_VARIABLE(ADMode)

// ADOMode
BEGIN_DECLARE_MASK_VARIABLE(ADOMode)
  DECLARE_MASK_BIT(ADOMode, 0, 0, FullSystem, "full system will be solved after decomposed subsystems if one of them is corrupted")
  DECLARE_MASK_BIT(ADOMode, 1, 0, RestSystem, "rest of the system will be solved after first corrupted decomposed subsystem")
  DECLARE_MASK_BIT(ADOMode, 2, 1, Redundant, "ReduceRedundant() will be called")
  DECLARE_MASK_BIT(ADOMode, 3, 0, Backward, "")
  DECLARE_MASK_BIT(ADOMode, 4, 1, Partition, "")
END_DECLARE_MASK_VARIABLE(ADOMode)

// UseER
DECLARE_BOOL_VARIABLE(UseER, TRUE, "use simplification of equations")

// MUCMode
BEGIN_DECLARE_MASK_VARIABLE(MUCMode)
  DECLARE_MASK_BIT(MUCMode,  0, 0, NA0, "not used")
  DECLARE_MASK_BIT(MUCMode,  1, 1, UseIMPostsolving, "use IM modelisation for postsolving")
  DECLARE_MASK_BIT(MUCMode,  2, 1, UseRRPostsolving, "use RR modelisation for postsolving")
  DECLARE_MASK_BIT(MUCMode,  3, 1, UsePPPostsolving, "use RR with priority projection for postsolving")
  DECLARE_MASK_BIT(MUCMode,  4, 0, NA4, "not used")
  DECLARE_MASK_BIT(MUCMode,  5, 0, NA5, "not used")
  DECLARE_MASK_BIT(MUCMode,  6, 1, UseRK3Presolving, "use Runge-Kutta method for solving ODE")
  DECLARE_MASK_BIT(MUCMode,  7, 1, UseDP8Presolving, "use DOPRI8 method for solving ODE")
END_DECLARE_MASK_VARIABLE(MUCMode)

// RRMode
BEGIN_DECLARE_MASK_VARIABLE(RRMode)
  DECLARE_MASK_BIT(RRMode, 0, 1, ExtPatterns, "use extended exp-patterns")
  DECLARE_MASK_BIT(RRMode, 1, 0, NA1, "not used")
  DECLARE_MASK_BIT(RRMode, 2, 0, NA2, "not used")
  DECLARE_MASK_BIT(RRMode, 3, 0, NoPatterns, "do not generate the RR tree")
  DECLARE_MASK_BIT(RRMode, 4, 0, NA4, "not used")
  DECLARE_MASK_BIT(RRMode, 5, 0, Update, "update mode")
  DECLARE_MASK_BIT(RRMode, 6, 0, Diagnostics, "diagnostics mode")
  DECLARE_MASK_BIT(RRMode, 7, 0, Shift, "shift geometry to it's center")
  DECLARE_MASK_BIT(RRMode, 8, 0, NA8, "not used")
  DECLARE_MASK_BIT(RRMode, 9, 0, SingularityPatterns, "use singularity patterns for diagnostics")
  DECLARE_MASK_BIT(RRMode,10, 0, UseDOS, "use DOS patterns")
  DECLARE_MASK_BIT(RRMode,11, 0, NA11, "not used")
  DECLARE_MASK_BIT(RRMode,12, 0, DOF, "DOF mode")
  DECLARE_MASK_BIT(RRMode,13, 0, NA13, "not used")
  DECLARE_MASK_BIT(RRMode,14, 0, NA14, "not used")
  DECLARE_MASK_BIT(RRMode,15, 0, TranslationOnly, "work in translation only mode")
  DECLARE_MASK_BIT(RRMode,16, 0, NA16, "not used")
  DECLARE_MASK_BIT(RRMode,17, 0, NA17, "not used")
  DECLARE_MASK_BIT(RRMode,18, 0, AC, "AutoConstraining mode")
END_DECLARE_MASK_VARIABLE(RRMode)

// IMMode
BEGIN_DECLARE_MASK_VARIABLE(IMMode)
  DECLARE_MASK_BIT(IMMode, 1, 0, FixLength, "specify the most shared length variable")
END_DECLARE_MASK_VARIABLE(IMMode)

// UseRRTransformationsForSpline
DECLARE_BOOL_VARIABLE(UseRRTransformationsForSpline, TRUE, "use transformations for spline at RR (dependent curve regeneration)")

// UseSplineDifferentiation
DECLARE_BOOL_VARIABLE(UseSplineDifferentiation, TRUE, "use precise derivatives from SplineCS callback in DependentEquation when they are available")

// DiagOptions
BEGIN_DECLARE_MASK_VARIABLE(DiagOptions)
  DECLARE_MASK_BIT(DiagOptions, 0, 1, UseCuttingForWelldefined, "use cutting decomposition for Welldefined diagnostic")
  DECLARE_MASK_BIT(DiagOptions, 1, 1, UsePerturbationForNotConsistent, "use perturbation for NotConsistent diagnostic")
  DECLARE_MASK_BIT(DiagOptions, 2, 1, MarkTriangleInconsistencies, "mark cycles of inconsistencies by triangle rule in NotConsistent diagnostic")
  DECLARE_MASK_BIT(DiagOptions, 3, 1, UsePerturbationInKernelForWelldefined, "use perturbation in kernel for Welldefined diagnostics")
  DECLARE_MASK_BIT(DiagOptions, 4, 0, UseRigidificationForWelldefined, "use HRTwoRS for Welldefined diagnostics")
END_DECLARE_MASK_VARIABLE(DiagOptions)

// DOFSpaceMethod
BEGIN_DECLARE_ENUM_VARIABLE(DOFSpaceMethod, REF)
  DECLARE_ENUM_VALUE(DOFSpaceMethod, SVD, "use SVD factorization to compute DOF space base")
  DECLARE_ENUM_VALUE(DOFSpaceMethod, GAUSS, "use Gauss elimination to compute DOF space base")
  DECLARE_ENUM_VALUE(DOFSpaceMethod, REF, "use REF (Gauss-Jordan) to compute DOF space base")
END_DECLARE_ENUM_VARIABLE(DOFSpaceMethod)

// ESLinearMethod
BEGIN_DECLARE_MASK_VARIABLE(ESLinearMethod)
  DECLARE_MASK_BIT(ESLinearMethod, 0, 0, NA, "not used")
  DECLARE_MASK_BIT(ESLinearMethod, 1, 1, GaussJordan, "use Gauss-Jordan elimination and the Newton method based on it")
  DECLARE_MASK_BIT(ESLinearMethod, 2, 0, SVD, "use SVD and Newton-SVD methods")
END_DECLARE_MASK_VARIABLE(ESLinearMethod)

// ESUseGradient
DECLARE_BOOL_VARIABLE(ESUseGradient, TRUE, "use sum of squares gradient method in ES before applying Newton")

// ESUseLevenbergMarquardt
DECLARE_BOOL_VARIABLE(ESUseLevenbergMarquardt, TRUE, "use Levenberg-Marquardt in ES")

// REFOrder
BEGIN_DECLARE_ENUM_VARIABLE(REFOrder, ROWS)
  DECLARE_ENUM_VALUE(REFOrder, ROWS, "the pivot element is searched by rows")
  DECLARE_ENUM_VALUE(REFOrder, COLUMNS, "the pivot element is searched by columns")
END_DECLARE_ENUM_VARIABLE(REFOrder)

// PureNewtonMethod
BEGIN_DECLARE_ENUM_VARIABLE(PureNewtonMethod, REF)
  DECLARE_ENUM_VALUE(PureNewtonMethod, SVD, "use Newton-SVD to solve CM-system")
  DECLARE_ENUM_VALUE(PureNewtonMethod, REF, "use Newton-Gauss-Jordan to solve CM-system")
END_DECLARE_ENUM_VARIABLE(PureNewtonMethod)

// UseNewtonDomainCorrection
DECLARE_BOOL_VARIABLE(UseNewtonDomainCorrection, TRUE, "correct Newton guess to domain using kernel space")

// RelaxationMode
BEGIN_DECLARE_ENUM_VARIABLE(RelaxationMode, QUAD)
  DECLARE_ENUM_VALUE(RelaxationMode, NONE, "do not use relaxation")
  DECLARE_ENUM_VALUE(RelaxationMode, QUAD, "use relaxation with quadratic equations only")
  DECLARE_ENUM_VALUE(RelaxationMode, ALL, "use relaxation with all equations")
END_DECLARE_ENUM_VARIABLE(RelaxationMode)

// ParallelMode
BEGIN_DECLARE_MASK_VARIABLE(ParallelMode)
  DECLARE_MASK_BIT(ParallelMode, 0, 0, UseREF, "use parallel version of REF algorithm")
  DECLARE_MASK_BIT(ParallelMode, 1, 0, NA, "not used")
  DECLARE_MASK_BIT(ParallelMode, 2, 0, UseTopLevel, "support top-level reenterability")
END_DECLARE_MASK_VARIABLE(ParallelMode)

DECLARE_BOOL_VARIABLE(ExactElliptic, TRUE, "Use precise methods for elliptic integrals")
DECLARE_BOOL_VARIABLE(ExactEllipticDeriv, TRUE, "Use precise methods for derivative of elliptic length")

DECLARE_BOOL_VARIABLE(UseDefaultEEGradient, FALSE, "in CATCSParserEquation::EvalGradient use default finite difference implementation from CATCSEquation")

// Use energy criterion in DOPRI5:
DECLARE_BOOL_VARIABLE(UseDSEnergyCorrection, TRUE, "reject solution whenever discrepancy experiences a rough jump")

DECLARE_BOOL_VARIABLE(UseSketchPlanes, FALSE, "link 2D RS with its sketch by pl-pl-co instead of sketch index")

// UseDisCurveSmoothing
DECLARE_BOOL_VARIABLE(UseDisCurveSmoothing, FALSE, "use smoothing of discontinuous curve with help of bezier insert")

// UseMUCPriorities
DECLARE_BOOL_VARIABLE(UseMUCPriorities, FALSE, "use Priorities of RS for MUC")

// UseFullMUCVU
DECLARE_BOOL_VARIABLE(UseFullMUCVU, FALSE, "use full MUCVU before MUCDE method for MUC problems")

// UseIKVU
DECLARE_BOOL_VARIABLE(UseIKVU, FALSE, "use Update approach (MUCVU and MUCIM) for MUC: needed to test IK scenarios")

// PrintSubtotal
DECLARE_BOOL_VARIABLE(PrintSubtotal, FALSE, "print subtotal after directory replayed")

// UseGSGlobalRedundancy
DECLARE_BOOL_VARIABLE(UseGSForGlobalRedundancy, FALSE, "use GS for Global Redundancy diagnostics")

// UseGDGlobalRedundancy
DECLARE_BOOL_VARIABLE(UseGDForGlobalRedundancy, FALSE, "use GD for Global Redundancy diagnostics")

// default value for orientations priorities
BEGIN_DECLARE_ENUM_VARIABLE(PriorityOrientations, WEAK)
  DECLARE_ENUM_VALUE(PriorityOrientations, NONE, "no global value for orientations prorities")
  DECLARE_ENUM_VALUE(PriorityOrientations, WEAK, "all are weaker than constraints")
  DECLARE_ENUM_VALUE(PriorityOrientations, STRONG, "all are stronger than constraints")
END_DECLARE_ENUM_VARIABLE(PriorityOrientations)


// ReplayDigits
DECLARE_INT_VARIABLE(ReplayDigits, 0, "number of digits with leading zeroes in script's replay names, 0 - default numeration")

DECLARE_BOOL_VARIABLE(AssertDeprecatedAPI, FALSE, "assert if deprecated methods of CATConstraintSolver are called")

DECLARE_BOOL_VARIABLE(ReadableOptions, TRUE, "Write Options with readable names")

DECLARE_BOOL_VARIABLE(WriteOldOptionsMode, FALSE, "Write old Options mode in replay for compatibility")

// CATWBx
DECLARE_BOOL_VARIABLE(UseOldST, FALSE, "use old version of SymbolicTransformations operator (10W52)")

DECLARE_BOOL_VARIABLE(UseCoordinatesInSM, TRUE, "to call UpdateCoordinates on callbacks instead of ApllyTransformation, while restoring the state of simulation marching")

DECLARE_BOOL_VARIABLE(UseUpdateForSMComputeState, FALSE, "use update on interpolated geometry in ComputeState")

DECLARE_BOOL_VARIABLE(UseGDForAutoDim, TRUE, "use geometric decompoistion for autodimensioning problems")

// Disable alignment overwriting
DECLARE_BOOL_VARIABLE(AlignementOverwriting, FALSE, "Disable alignment overwriting on planar angle constraints")

#define CATCDSGlobalParameters_UseSetMembers
#include "CATCDSGlobalParameters_macros.h"

DECLARE_INT_VARIABLE(ScaleFactor, 1, "factor for linear tests scaling")

// PrintVersion
DECLARE_BOOL_VARIABLE(PrintVersion, TRUE, "print CDS version in replays")

// CDS Version of read replay
DECLARE_BOOL_VARIABLE(NewCDSReplayChiralitiesVersion, TRUE, "if TRUE read chiralities from CDSReplay in new format plugged on 10W20")

DECLARE_BOOL_VARIABLE(ReadAllChiralities, TRUE, "in CATCSNGeomConstraint::ReadOrientations read all chiralities from callback")

DECLARE_BOOL_VARIABLE(ForceWriteInputMode, FALSE, "force generation of all inputs when replaying scripts")

// Simulation marching script mode
BEGIN_DECLARE_ENUM_VARIABLE(SMScriptMode, NONE)
  DECLARE_ENUM_VALUE(SMScriptMode, NONE, "don't write script")
  DECLARE_ENUM_VALUE(SMScriptMode, SINGLE, "write script data in one file")
  DECLARE_ENUM_VALUE(SMScriptMode, FULL, "write data for each action in its own file")
END_DECLARE_ENUM_VARIABLE(SMScriptMode)

// Constraint solver script mode
BEGIN_DECLARE_ENUM_VARIABLE(CSScriptMode, NONE)
DECLARE_ENUM_VALUE(CSScriptMode, NONE, "don't write script")
DECLARE_ENUM_VALUE(CSScriptMode, SINGLE, "write script data in one file")
DECLARE_ENUM_VALUE(CSScriptMode, FULL, "write data for each action in its own file")
END_DECLARE_ENUM_VARIABLE(CSScriptMode)

// Profiles auto-trimming forced when regenerating a profile without unsolved adjacencies even if no POC has moved (provided the profile is in auto-trim mode)
DECLARE_BOOL_VARIABLE(ProfileAutoTrimForced, FALSE, "in CATCSNProfile2D::Regenerate, force auto-trim when no unsolved adjacency exists")

DECLARE_BOOL_VARIABLE(MUCOnWelldefinedObjects, FALSE, "Enable MUC on welldefined objects in CATIA plug")

DECLARE_BOOL_VARIABLE(JavascriptDebug, FALSE, "When TRUE, use CATCDS JS debug file for odt replay")

DECLARE_BOOL_VARIABLE(ForceReStream, FALSE, "if TRUE force the streaming of curves, skins and skin params (otherwise the input data files are copied into the output directory)")

// Double precision used for matrix streaming
#ifdef CDS_DEBUG
DECLARE_INT_VARIABLE(Precision, 3, "Number of digits in matrix value printing")
#endif

DECLARE_INT_VARIABLE(ReplaySolverModeMask, 0, "Mask to filter replay generation depending on SI solver modes")

DECLARE_BOOL_VARIABLE(PreprocessKinematicsChains, FALSE, "if TRUE, enable the PreprocessKinematicsChains mode for MUC and KIN")

// Force solver tolerances
BEGIN_DECLARE_ENUM_VARIABLE(ForceTolerances, NO)
DECLARE_ENUM_VALUE(ForceTolerances, NO, "use declared tolerances")
DECLARE_ENUM_VALUE(ForceTolerances, NORMAL, "force normal scale tolerances : 0.001, 1e-9")
DECLARE_ENUM_VALUE(ForceTolerances, LARGE, "force large scale tolerances : 0.1, 1e-9")
END_DECLARE_ENUM_VARIABLE(ForceTolerances)

DECLARE_BOOL_VARIABLE(StreamGlobalRedPriorities, FALSE, "Stream the constraints global redundency priority in CDSReplay")

// use PreprocessKinematicsChains only if active (no rattrap)
DECLARE_BOOL_VARIABLE(PreprocessKinematicsChainsOnly, FALSE, "use PreprocessKinematicsChains only if active (no rattrap)")

// check discrepancy in PreprocessKinematicsChains mode (for tests only)
DECLARE_BOOL_VARIABLE(PreprocessKinematicsChainsCheckDiscrepancy, FALSE, "check discrepancy in PreprocessKinematicsChains mode")

// force Incremental mode
DECLARE_BOOL_VARIABLE(IncrementalMode, FALSE, "if TRUE, enable the incremental mode")

// force inverse kinematics mode
DECLARE_BOOL_VARIABLE(InverseKinematicsMode, FALSE, "if TRUE, enable the inverse kinematics mode")

// use only the analytical solve for inverse kinematics
DECLARE_BOOL_VARIABLE(InverseKinematicsAnalyticalSolveOnly, FALSE, "if TRUE, use only the analytical solve for inverse kinematics")

// Select the algorithm used in Adaptive Move Mode for a MUC
BEGIN_DECLARE_ENUM_VARIABLE(AdaptiveMoveAlgo, BASIC_DICHOTOMY)
DECLARE_ENUM_VALUE(AdaptiveMoveAlgo, BASIC_DICHOTOMY, "use basic dichotomy")
DECLARE_ENUM_VALUE(AdaptiveMoveAlgo, DELMIA_HEURISTIC, "use delmia algorithm")
END_DECLARE_ENUM_VARIABLE(AdaptiveMoveAlgo)
