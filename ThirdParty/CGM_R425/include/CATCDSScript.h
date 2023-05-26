
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// CATCDSScript:
//   Class supports script for multiple runs.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Sep 2005  Creation                              Andrey Chuguev
//=============================================================================

#ifndef CATCDSScript_H
#define CATCDSScript_H

#include "SolverUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSString.h"
#include "CATCDSStream.h"

class CATCDSStream;

#define MAX_SCRIPT_NAMES 2
#define MAX_SCRIPT_VALUES 2

class CATCDSScript {
public:
  CATCDSScript(unsigned int iCDSLevel) :
    _nActions(0), _iAction(0), _aActions(0),
    _pStream(0), _pDataStream(0),
    _geometryChanged(TRUE), _optionsChanged(FALSE),
    _replayIdx(0),
    _simpleMode(FALSE),
    _singleDataFile(FALSE),
    _scriptType(stNone),
    _level(iCDSLevel)
  {
  }

  virtual ~CATCDSScript()
  {
    FinalizeWriting();
    delete[] _aActions;
    _aActions = 0;
  }

  enum ActionType {
    atNone,
    atCreate,
    atDestroy,
    atAddGeometry,
    atAddRigidSet,
    atAddContact,
    atAddSketch,
    atAddConstraint,
    atAddPattern,
    atAddOffsetConstraint,
    atAddJoint,
    atAddVariable,
    atAddEquation,
    atRemove,
    atFixGeometry,
    atFixGeometry2D,
    atSetFixationStiffness,
    atSetFixationStiffness2D,
    atModifyGeometry,
    atReplaceGeometry,
    atModifyParameters,
    atMoveGeometryToRigidSet,
    atMoveGeometryFromRigidSet,
    atSetRigidSetStiffness,
    atSetConstraintVariable,
    atResetConstraintVariable,
    atSetHelpParameterVariable,
    atResetHelpParameterVariable,
    atSetConstraintValue,
    atSetConstraintStiffness,
    atFlushConstraintChirality,
    atSetVariableValue,
    atSetDynamicMove1,
    atSetDynamicMove2,
    atSetDynamicMove3,
    atSetScalable,
    atModifyVariable,
    atModifyOptions,
    atReset,
    atIsSimulable,
    atSetTargetValues,
    atRun,
    atUndoRun,
    atGetDerivatives,
    atSetMove2D,
    atEvalDiscrepancy,
    atResetHistory,
    // actions for Simulation Marching
    atSMCreate,
    atSMRun,
    atSMComputeState,
    atSMSetMarchingParameter,
    atSMSetMarchingInterval,
    atSMSetSimulationStep,
    // actions for CATConstraintSolver
    atCSCreate,
    //atCSCreate2,
    //atCSCreate3,
    atCSDestroy,
    atCSAddSketch,
    atCSAddRigidSet,
    atCSAddContact,
    atCSAddGeometry,
    atCSAddConstraint,
    atCSAddPattern,
    atCSAddOffsetConstraint,
    atCSAddJoint,
    atCSAddFreeVariable,
    atCSAddEquation,
    atCSMoveGeometryToRigidSet,
    atCSSetConstraintVariable,
    atCSFixGeometryToggle,
    atCSFixGeometryToggle2D,
    atCSEraseNode,
    atCSRun,
    atCSUndoRun,
    atCSReset,
    atCSSetDynamicMoveMode,
    atCSSetDynamicMoveRadii,
    atCSSetDynamicMove,
    //atCSSetDynamicMoveTransl,
    atCSSetDynamicMove2D,
    //atCSSetDynamicMove2DTransl,
    atCSReplaceGeometry, //TODO: Implement with Loader refactoring
    //atCSGetGeometriesInRigidSet,
    atCSSetRigidSetStiffness,
    atCSSetConstraintStiffness,
    atCSSetConstraintLeadingSoftness,
    atCSSetHelpParameterVariable,
    //atCSGetHelpParameterVariable,
    //atCSIsGeometryFixed,
    //atCSIsGeometryFixed2D,
    atCSSetFixationStiffness,
    atCSSetFixationStiffness2D,
    //atCSGetNodes,
    //atCSGetNodes2,
    //atCSGetCallbacks,
    //atCSGetStatus,
    //atCSGetUnderdefinedStatus,
    //atCSGetMoveStatus,
    //atCSGetStatus,
    //atCSGetStatus2,
    //atCSEvalDiscrepancy,
    //atCSEvalDiscrepancy2,
    atCSIsRedundant,
    //atCSIsRedundant2,
    //atCSIsRedundant3,
    atCSGetDependentVariables,
    //atCSGetDependentVariables2,
    atCSGetDerivativesAtSimulationPoint,
    atCSGetLeadingConstraintStatus,
    atCSSetAutoConstrainingPattern,
    atCSSetAutoConstrainingCouplePattern,
    atCSSetAutoConstrainingTriplePattern,
    atCSResetAutoConstrainingPatterns,
    //-----
    atCSSetAutoConstrainingTool, // How to save callback in the script?
    atCSDoAutoConstraining,
    atCSSetAutoConstraintMode,
    atCSSetACWeightType,
    atCSSetPreserveChiralityMode,
    atCSChangeChirality,
    atCSFlushChirality,
    atCSGetChirality, // Skipped
    atCSComputeChirality, // Skipped
    atCSSetTolerances, //Skipped
    atCSGetTolerances,
    //atCSGetActualModelSize,
    //atCSGetOutputMode,
    atCSSetOutputMode,
    atCSSetPartialSolvingMode,
    atCSSetSolvingMode,
    atCSSetUpdateMode,
    atCSSetDiagnosticsMode,
    atCSSetRigidSetDiagnosticsMode,
    atCSSetOverdefinedDiagnosticsMode,
    atCSSetSimulationMode,
    atCSSetVarDependencyMode,
    atCSRereadHelpParameters,
    atCSSetStreamTool,
    atCSRigidSetReducedTransfo,
    //atCSIsInitiallySatisfied,
    atCSIsSimulable,
    atCSIsSingularityDetected, //Skipped
    atCSSetTargetValues,
    atCSSetVariablePriorities,
    atCSSetRedundantConstraintPriority,
    atCSComputeRedundantConstraints,
    atCSGetReachedVariableLimits,
    atCSSetDegreesOfFreedomMode,
    atCSGetDegreesOfFreedom,
    atCSGetRelativeDegreesOfFreedom,
    atCSGetDegreesOfFreedom2D,
    atCSGetRelativeDegreesOfFreedom2D,
    atCSGetNumberOfDegreesOfFreedom,
    atCSGetConnexComponents,
    atCSSetUseImplicitSketches,
    //atCSGetTransformation,
    //atCSGetTransformation2D,
    //atCSHasTransformation,
    //atCSGetRadius,
    //atCSGetRadiusOffset,
    //atCSGetRadii,
    //atCSGetRadiiOffset,
    //atCSGetHelpPoint2D,
    //atCSCATConstraintSolver,
    //atCSLoad,
    //atCSDump,
    //atCSDump2,
    //atCSIsGeometrySatisfied,
    atCSSetMoveRadii,
    atCSSetMove2D,
    atCSSetMove,
    atCSSetInvariantDegreesOfFreedomComputation,
    atCSSetDerivativesComputationMode,
    atCSEvalDiscrepancy,
    atCSSetContactsDiagnosticsMode,
    atCSSetCheckUnsolvableConstraintsMode,
    atCSSetMoveOutOfClashMode,
    atCSSetInverseKinematicsMode, 
    atCSSetUpdateOutOfClashMode,
    atCSPreprocessKinematicsChains,
    atCSSetIncrementalMode
  };

#ifdef CDS_DEBUG
  static char const * const chGeometryName;
  static char const * const chCallbackName;
  static char const * const chVariableName;
  static char const * const chRigidsetName;
  static char const * const chConstraintName;
  static char const * const chArgumentName;
  static char const * const chParentName;
  static char const * const chValue;
  static char const * const chMode;
#endif

  struct ExportedBySolverUtilities Action {
    ActionType _type;
    int _replayIdx;
    CATCDSString _aNames[MAX_SCRIPT_NAMES];
    double _aValues[MAX_SCRIPT_VALUES];

    Action() :
      _type(CATCDSScript::atNone), _replayIdx(-1)
    {
      int i;
      for (i = 0; i < MAX_SCRIPT_VALUES; i++) {
        _aValues[i] = 0.0;
      }
    }
  };

  enum ScriptType {
    stNone,
    stSolverInterface,
    stSimulationMarching,
    stConstraintSolver
  };

  void Prepare();

  // If we use Write with run and write replay Idx,
  // we need to call Prepare before using it
  void Write(ActionType iAction, CATCDSBoolean iWriteReplayIdx = FALSE);
  void WriteMUC(ActionType iAction, const CATCDSString &iName);

  void WriteGeometryChanging(
    ActionType iAction,
    const CATCDSString& iName1,
    const CATCDSString& iName2 = "");

  void WriteGeometryChanging(
    ActionType iAction,
    const CATCDSString& iName,
    const double& iValue);

  void WriteAction(ActionType iAction, const CATCDSString& iAdditionalData = "");
  void WriteActionAndName(ActionType iAction, const CATCDSString& iName1 = "", const CATCDSString& iName2 = "");
  void WriteInputData(const CATCDSString& iHeader, const CATCDSString& iValue);
  CATCDSStream* GetDataStream();
  CATCDSStream* GetInputDataStream();
  CATCDSStream* GetOutputDataStream();

  void SetGeometryChanged(CATCDSBoolean iChanged = TRUE);
  
  CATCDSBoolean IsGeometryChanged()
  {
    return _geometryChanged;
  }

  void SetOptionsChanged(CATCDSBoolean iChanged = TRUE);
  CATCDSBoolean IsOptionsChanged();

  void SetSimpleMode(CATCDSBoolean iSimpleMode = TRUE);
  CATCDSBoolean IsSimpleMode()
  {
    return _simpleMode;
  }

  void InitializeWriting();
  
  void FinalizeWriting()
  {
#ifdef CDS_DEBUG
    delete _pStream;
    _pStream = 0;
    delete _pDataStream;
    _pDataStream = 0;
#endif
  }

protected:
  //CATCDSBoolean ParseActions(const CATCDSString& iActions);
  //CATCDSBoolean RemoveUselessActions();

  int _nActions;
  int _iAction;
  Action* _aActions;

  CATCDSStream *_pStream;
  CATCDSStream *_pDataStream;
  CATCDSBoolean _geometryChanged, _optionsChanged;
  CATCDSString _scriptFile;
  int _replayIdx;
  CATCDSBoolean _simpleMode;
  CATCDSBoolean _singleDataFile;
  ScriptType _scriptType;
  unsigned int _level;
};
#endif
