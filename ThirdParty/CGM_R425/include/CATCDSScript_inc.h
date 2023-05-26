static char const * const chActionsHeader = "#!ACTIONS";
static const char chDelimiter = ';';

struct TypeDescriptor {
  const char* _name;
  CATCDSScript::ActionType _type;
  CATCDSBoolean _isReplay;
  int _nNames;
  CATCDSBoolean _canOmit;
  int _nValues;
  CATCDSBoolean _changeGeom;
};

#define DECLARE_ACTION(name, isReplay) \
{ #name, CATCDSScript::at##name, isReplay, 0, FALSE, 0, FALSE }

#define DECLARE_ACTION_REPLAY(name) \
{ #name, CATCDSScript::at##name, TRUE, 0, FALSE, 0, FALSE }

#define DECLARE_ACTION_GEOM(name, nNames, nValues, ChangeGeom, CanOmit) \
{ #name, CATCDSScript::at##name, FALSE, nNames, CanOmit, nValues, ChangeGeom }

static TypeDescriptor aTypesDescr[] = {
  DECLARE_ACTION(None,            FALSE),
  DECLARE_ACTION(Create,          FALSE),
  DECLARE_ACTION(Destroy,         FALSE),
  DECLARE_ACTION_GEOM(AddGeometry,               1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(AddRigidSet,               1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(AddContact,                1, 0, TRUE,  FALSE), 
  DECLARE_ACTION_GEOM(AddSketch,                 1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(AddConstraint,             1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(AddPattern,                1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(AddOffsetConstraint,       1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(AddJoint,                  1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(AddVariable,               1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(AddEquation,               1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(Remove,                    1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(FixGeometry,               1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(FixGeometry2D,             1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(SetFixationStiffness,      1, 1, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(SetFixationStiffness2D,    1, 1, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(ModifyGeometry,            1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(ReplaceGeometry,           2, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(ModifyParameters,          1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(MoveGeometryToRigidSet,    2, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(MoveGeometryFromRigidSet,  1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(SetRigidSetStiffness,      1, 1, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(SetConstraintVariable,     2, 0, TRUE,  TRUE),
  DECLARE_ACTION_GEOM(ResetConstraintVariable,   1, 0, TRUE,  TRUE),
  DECLARE_ACTION_GEOM(SetHelpParameterVariable,     2, 0, TRUE,  TRUE),
  DECLARE_ACTION_GEOM(ResetHelpParameterVariable,   1, 0, TRUE,  TRUE),
  DECLARE_ACTION_GEOM(SetConstraintValue,        1, 1, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(SetConstraintStiffness,    1, 1, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(FlushConstraintChirality,  1, 0, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(SetVariableValue,          1, 1, TRUE,  FALSE),
  DECLARE_ACTION_GEOM(SetDynamicMove1,           1, 0, FALSE, FALSE),
  DECLARE_ACTION_GEOM(SetDynamicMove2,           1, 0, FALSE, FALSE),
  DECLARE_ACTION_GEOM(SetDynamicMove3,           1, 0, FALSE, FALSE),
  DECLARE_ACTION_GEOM(SetScalable,               2, 0, FALSE, FALSE),
  DECLARE_ACTION_GEOM(ModifyVariable,            1, 0, TRUE,  FALSE),
  DECLARE_ACTION(ModifyOptions,   FALSE),
  DECLARE_ACTION(Reset,           FALSE),
  DECLARE_ACTION(IsSimulable,     TRUE),
  DECLARE_ACTION(SetTargetValues, FALSE),
  DECLARE_ACTION(Run,             TRUE),
  DECLARE_ACTION(UndoRun,         FALSE),
  DECLARE_ACTION(GetDerivatives,  TRUE),
  DECLARE_ACTION_GEOM(SetMove2D,           1, 0, FALSE, FALSE),
  DECLARE_ACTION(EvalDiscrepancy,            TRUE),
  DECLARE_ACTION(ResetHistory,          FALSE),
  DECLARE_ACTION(SMCreate,               TRUE),
  DECLARE_ACTION(SMRun,                  TRUE),
  DECLARE_ACTION(SMComputeState,         TRUE),
  DECLARE_ACTION(SMSetMarchingParameter, TRUE),
  DECLARE_ACTION(SMSetMarchingInterval,  TRUE),
  DECLARE_ACTION(SMSetSimulationStep,    TRUE),
  DECLARE_ACTION_REPLAY(CSCreate),
  DECLARE_ACTION_REPLAY(CSDestroy),
  DECLARE_ACTION_REPLAY(CSAddSketch),
  DECLARE_ACTION_REPLAY(CSAddRigidSet),
  DECLARE_ACTION_REPLAY(CSAddContact),
  DECLARE_ACTION_REPLAY(CSAddGeometry),
  DECLARE_ACTION_REPLAY(CSAddConstraint),
  DECLARE_ACTION_REPLAY(CSAddPattern),
  DECLARE_ACTION_REPLAY(CSAddOffsetConstraint),
  DECLARE_ACTION_REPLAY(CSAddJoint),
  DECLARE_ACTION_REPLAY(CSAddFreeVariable),
  DECLARE_ACTION_REPLAY(CSAddEquation),
  DECLARE_ACTION_REPLAY(CSMoveGeometryToRigidSet),
  DECLARE_ACTION_REPLAY(CSSetConstraintVariable),
  DECLARE_ACTION_REPLAY(CSFixGeometryToggle),
  DECLARE_ACTION_REPLAY(CSFixGeometryToggle2D),
  DECLARE_ACTION_REPLAY(CSEraseNode),
  DECLARE_ACTION_REPLAY(CSRun),
  DECLARE_ACTION_REPLAY(CSUndoRun),
  DECLARE_ACTION_REPLAY(CSReset),
  DECLARE_ACTION_REPLAY(CSSetDynamicMoveMode),
  DECLARE_ACTION_REPLAY(CSSetDynamicMoveRadii),
  DECLARE_ACTION_REPLAY(CSSetDynamicMove),
  DECLARE_ACTION_REPLAY(CSSetDynamicMove2D),
  DECLARE_ACTION_REPLAY(CSReplaceGeometry),
  DECLARE_ACTION_REPLAY(CSSetRigidSetStiffness),
  DECLARE_ACTION_REPLAY(CSSetConstraintStiffness),
  DECLARE_ACTION_REPLAY(CSSetConstraintLeadingSoftness),
  DECLARE_ACTION_REPLAY(CSSetHelpParameterVariable),
  DECLARE_ACTION_REPLAY(CSSetFixationStiffness),
  DECLARE_ACTION_REPLAY(CSSetFixationStiffness2D),
  DECLARE_ACTION_REPLAY(CSIsRedundant),
  DECLARE_ACTION_REPLAY(CSGetDependentVariables),
  DECLARE_ACTION_REPLAY(CSGetDerivativesAtSimulationPoint),
  DECLARE_ACTION_REPLAY(CSGetLeadingConstraintStatus),
  DECLARE_ACTION_REPLAY(CSSetAutoConstrainingPattern),
  DECLARE_ACTION_REPLAY(CSSetAutoConstrainingCouplePattern),
  DECLARE_ACTION_REPLAY(CSSetAutoConstrainingTriplePattern),
  DECLARE_ACTION_REPLAY(CSResetAutoConstrainingPatterns),
  DECLARE_ACTION_REPLAY(CSSetAutoConstrainingTool),
  DECLARE_ACTION_REPLAY(CSDoAutoConstraining),
  DECLARE_ACTION_REPLAY(CSSetAutoConstraintMode),
  DECLARE_ACTION_REPLAY(CSSetACWeightType),
  DECLARE_ACTION_REPLAY(CSSetPreserveChiralityMode),
  DECLARE_ACTION_REPLAY(CSChangeChirality),
  DECLARE_ACTION_REPLAY(CSFlushChirality),
  DECLARE_ACTION_REPLAY(CSGetChirality),
  DECLARE_ACTION_REPLAY(CSComputeChirality),
  DECLARE_ACTION_REPLAY(CSSetTolerances),
  DECLARE_ACTION_REPLAY(CSGetTolerances),
  DECLARE_ACTION_REPLAY(CSSetOutputMode),
  DECLARE_ACTION_REPLAY(CSSetPartialSolvingMode),
  DECLARE_ACTION_REPLAY(CSSetSolvingMode),
  DECLARE_ACTION_REPLAY(CSSetUpdateMode),
  DECLARE_ACTION_REPLAY(CSSetDiagnosticsMode),
  DECLARE_ACTION_REPLAY(CSSetRigidSetDiagnosticsMode),
  DECLARE_ACTION_REPLAY(CSSetOverdefinedDiagnosticsMode),
  DECLARE_ACTION_REPLAY(CSSetSimulationMode),
  DECLARE_ACTION_REPLAY(CSSetVarDependencyMode),
  DECLARE_ACTION_REPLAY(CSRereadHelpParameters),
  DECLARE_ACTION_REPLAY(CSSetStreamTool),
  DECLARE_ACTION_REPLAY(CSRigidSetReducedTransfo),
  DECLARE_ACTION_REPLAY(CSIsSimulable),
  DECLARE_ACTION_REPLAY(CSIsSingularityDetected),
  DECLARE_ACTION_REPLAY(CSSetTargetValues),
  DECLARE_ACTION_REPLAY(CSSetVariablePriorities),
  DECLARE_ACTION_REPLAY(CSSetRedundantConstraintPriority),
  DECLARE_ACTION_REPLAY(CSComputeRedundantConstraints),
  DECLARE_ACTION_REPLAY(CSGetReachedVariableLimits),
  DECLARE_ACTION_REPLAY(CSSetDegreesOfFreedomMode),
  DECLARE_ACTION_REPLAY(CSGetDegreesOfFreedom),
  DECLARE_ACTION_REPLAY(CSGetRelativeDegreesOfFreedom),
  DECLARE_ACTION_REPLAY(CSGetDegreesOfFreedom2D),
  DECLARE_ACTION_REPLAY(CSGetRelativeDegreesOfFreedom2D),
  DECLARE_ACTION_REPLAY(CSGetNumberOfDegreesOfFreedom),
  DECLARE_ACTION_REPLAY(CSGetConnexComponents),
  DECLARE_ACTION_REPLAY(CSSetUseImplicitSketches),
  DECLARE_ACTION_REPLAY(CSSetMoveRadii),
  DECLARE_ACTION_REPLAY(CSSetMove2D),
  DECLARE_ACTION_REPLAY(CSSetMove),
  DECLARE_ACTION_REPLAY(CSSetInvariantDegreesOfFreedomComputation),
  DECLARE_ACTION_REPLAY(CSSetDerivativesComputationMode),
  DECLARE_ACTION_REPLAY(CSEvalDiscrepancy)
};
static int nTypesDescr = SIZEOF(aTypesDescr);

static CATCDSScript::ScriptType GetActionScriptType(CATCDSScript::ActionType iActionType)
{
  if (iActionType == CATCDSScript::atNone)
    return CATCDSScript::stNone;
  if (iActionType < CATCDSScript::atSMCreate)
    return CATCDSScript::stSolverInterface;
  if (iActionType < CATCDSScript::atCSCreate)
    return CATCDSScript::stSimulationMarching;
  return CATCDSScript::stConstraintSolver;
}

#define DECLARE_SCRIPT_VARIABLES(NAMESPACE) \
  char const * const NAMESPACE::chGeometryName("#!GeometryName"); \
  char const * const NAMESPACE::chCallbackName("#!CallbackName"); \
  char const * const NAMESPACE::chConstraintName("#!ConstraintName"); \
  char const * const NAMESPACE::chArgumentName("#!ArgumentName"); \
  char const * const NAMESPACE::chVariableName("#!VariableName"); \
  char const * const NAMESPACE::chRigidsetName("#!RigidsetName"); \
  char const * const NAMESPACE::chParentName("#!ParentName"); \
  char const * const NAMESPACE::chValue("#!VALUE"); \
  char const * const NAMESPACE::chMode("#!MODE");
