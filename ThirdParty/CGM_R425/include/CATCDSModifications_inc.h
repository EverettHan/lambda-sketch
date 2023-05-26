
// Do not include this file directly. Use CATCDSModifications.h

#include "CATCDSVersMacros.h"

#define CDS_LEVEL(X)      CDS_INTERNAL_LEVEL(X,0)
#ifdef VERSIONING_V2
#define CDS_HF_LEVEL(X,Y) CDS_INTERNAL_LEVEL(X,Y)
#else
#define CDS_HF_LEVEL(X,Y) CATCDSModificationInactive
#endif

// Usage:
//
// to define a variable active on the main level CDSLevel
// #define VariableName CDS_LEVEL(CDSLevel) [, CDS_HF_LEVEL(CDSLevel1,CDSHFLevel1), ...]
// optional: add a list of HF levels (separated by ',') to activate this variable on HF levels as well
//
// to define a variable active on a HF sublevel of CDSLevel
// #define VariableName CDS_HF_LEVEL(CDSLevel,CDSHFLevel)
//
// VariableName     a unique identifier of the variable
// CDSLevel         level of activation
// CDSHFLevel       HF sublevel of activation
//
// Current level is located in GetCDSOpenConfigurationLevel (CATCDSGlobalParameters.h)
// Current HF sublevel is located in GetCDSOpenConfigurationHFLevel (CATCDSGlobalParameters.h)
// Use CATCDSModificationInactive to deactivate a variable

// level 0 corresponds to CDS_10W36

unsigned int const CATCDSModificationInactive = 0xFFFFFFFF;

// CDS_10W38
#define CATCDSGD_CuttingPattern_BunchOfLines                              CDS_LEVEL(1)
#define CATCDSRR_NoPatternsOnMovedRS                                      CDS_LEVEL(1)
#define CATCDSSD_AlwaysCheckTranslationNorm                               CDS_LEVEL(1)

// test
#define CATCDS_TestHF                                                     CDS_HF_LEVEL(1,1)

// CDS_10W40
#define CATCDSGS_Pattern_ReplaceRigidSymmetry_Correction                  CDS_LEVEL(2)

// CDS_10W42
#define CATCDSHR_FormalDOF_RejectDegenerateEllipses                       CDS_LEVEL(3)
#define CATCDSAC_UseNewSingularityProcessing                              CDS_LEVEL(3)
#define CATCDSGD_CheckWDDiagCutStatusesOfRemainder                        CDS_LEVEL(3)
#define CATCDSMathUtilities_SynchroniseAccuracy                           CDS_LEVEL(3)
#define CATCDSEllipseEquation_FixNumericalInstabilities                   CDS_LEVEL(3)
#define CATCDSIM_CreateHelpPointForPtElCo                                 CDS_LEVEL(3)

// CDS_10W44
#define CATCDSES_NewtonBug1Fixed                                          CDS_LEVEL(4)
#define CATCDSSD_PreventEndlessLoop                                       CDS_LEVEL(4)
#define CATCDSHR_FixedDistancesFromMovedBug                               CDS_LEVEL(4)

// CDS_10W46
#define CATCDSAC_AddConstraintsWithEllipsesAndCurves                      CDS_LEVEL(5)
#define CATCDSRR_MissedElElHP_BugFixed                                    CDS_LEVEL(5)
#define CATCDSRR_Diagnostics_CuCuDi2D                                     CDS_LEVEL(5)
#define CATCDSRR_GetSketchFromRS_BugFixed                                 CDS_LEVEL(5)

// CDS_10W47
#define CATCDSRR_CiElDi2D_HP_BugFixed                                     CDS_LEVEL(6)
#define CATCDSRR_ElCu_ZeroHP_BugFixed                                     CDS_LEVEL(6)

// CDS_10W48
#define CATCDSRR_PtCuDi2D_UnifyMixed                                      CDS_LEVEL(7)

// CDS_10W50
#define CATCDSRR_CySuHP_BugFixed                                          CDS_LEVEL(8)
#define CATCDSGD_CheckLine2LnDiAddDi_DisabledForDiag                      CDS_LEVEL(8)

// CDS_11W03
#define CATCDSSI_MUCVU_BestSolution                                       CDS_LEVEL(10)

// CDS_11W06
#define CATCDSSI_CorrectActualDiscCriterion                               CDS_LEVEL(12)
#define CATCDSGS_UseMergeFindSetBasedMergings                             CDS_LEVEL(12)
#define CATCDSGS_ClearImpliedFlagOnInputGeometry                          CDS_LEVEL(12)

// CDS_11W07
#define CATCDSPP_UseNewDOFProjectionAlgorithm                             CDS_LEVEL(13)
#define CATCDSGD_ForceFixMainCuttingGeometry                              CDS_LEVEL(13)
#define CATCDSEG_MinimizeNumberOfTrigonometricEquations                   CDS_LEVEL(13)

// CDS_11W09
#define CATCDSGD_CuttingPattern_RigidPair                                 CDS_LEVEL(14)
#define CATCDSEquation_AllowTrivialSubstitution                           CDS_LEVEL(14)

// CDS_11W10
#define CATCDSIM_NoDiagonalEquationForConicNormal                         CDS_LEVEL(15)
#define CATCDSEG_NoZeroConicEquations                                     CDS_LEVEL(15)

// CDS_11W11
#define CATCDSValidator_NewConicsAndCirclesCode                           CDS_LEVEL(16)

#define CATCDSModel_CheckCreateGeometry                                   CDS_LEVEL(17)

// CDS_11W14
#define CATCDSGD_CuttingPattern_Line2PtCoDiAxis                           CDS_LEVEL(19)

#define CATCDSDC_MinConstrNbToRunGSGDForWelldefined                       CDS_LEVEL(21)
#define CATCDSDC_WD_ProcesssSmallUnderdefinedGeometry                     CDS_LEVEL(21)
#define CATCDSDC_WD_FixedDOFForRigidset                                   CDS_LEVEL(21)
#define CATCDSGD_UseObjectTransformationInSetCoords                       CDS_LEVEL(21)

#define CATCDSAC_LnCiAt2D_IsSpecial                                       CDS_LEVEL(25)

#define CATCDSBBox_OnePeriodFlagForGetLimits                              CDS_LEVEL(26)
#define CATCDSAC_FindConnexComponents                                     CDS_LEVEL(26)

#define CATCDSSI_UseUpdateModesForArtPointClusters                        CDS_LEVEL(28)

#define CATCDSRR_Shape_Precise                                            CATCDSModificationInactive

// CDS_11W26
#define CATCDSAC_ConstraintsFiltering                                     CDS_LEVEL(29)

// CDS_11W29
#define CATCDSAC_CuttingPatterns_ClassOfParallism                         CDS_LEVEL(30)

// CDS_11W41
#define CATCDSSI_MUC_PerturbateSingularGeometries                         CDS_LEVEL(31)

// CDS_11W43
#define CATCDSGD_CuttingPatterns_BugFix                                   CDS_LEVEL(32)

// CDS_11W44
#define CATCDSSI_AvoidGeometryCollapsing                                  CDS_LEVEL(33)

// CDS_11W45
#define CATCDSSI_TriangleChirality                                        CDS_LEVEL(34)

// CDS_11W47
#define CATCDSSI_CalcNbImpactedObjects                                    CDS_LEVEL(35)
#define CATCDSSI_AccurateMoveConvergence                                  CDS_LEVEL(36)

// CDS_11W48
#define CATCDSAC_CheckingExistingConstraint                               CDS_LEVEL(37)

// CDS_11W49
#define CATCDSES_LevenbergMarquardt                                       CDS_LEVEL(38)

// CDS_12W01
#define CATCDSGS_MergeVariables                                           CDS_LEVEL(39)
#define CATCDSSI_MovingExclusiveParameter                                 CDS_LEVEL(39)

// CDS_12W04
#define CATCDSSD_UnplugShiftOfCenter                                      CATCDSModificationInactive
#define CATCDSHelpPoints_Resilience                                       CDS_LEVEL(41)
#define CATCDSSI_MUC_CheckMoveBackWithVariableTolerance                   CDS_LEVEL(41)

// CDS_12_W05
#define CATCDSEllipseEquation_FixDiscontinuity                            CDS_LEVEL(42)
#define CATCDSRR_CircleCircleTangencyNoChirality                          CDS_LEVEL(42)

// CDS_12_W05
#define CATCDSIM_BugRemovePlanarAngle                                     CDS_LEVEL(43)

// CDS_12_W09
#define CATCDSDS_ChangePriorityOfMovingVariableAndParametersRigidSets     CDS_LEVEL(44)
#define CATCDSDS_ChangePriorityOfMovingParameters                         CDS_LEVEL(44)

// CDS_12_W12
#define CATCDSGS_MergeRigidSetsWithSketches                               CDS_LEVEL(45)
#define CATCDSSI_MUC_2DPriority                                           CDS_LEVEL(45)
#define CATCDSDS_DisableTranslationPriority                               CDS_LEVEL(45)
#define CATCDSSI_OnlyApplyMoveOnDependencies                              CDS_LEVEL(45)

// WBx_12_W12
#define CATWBx_Test                                                       CATCDSModificationInactive

// CDS_12_W14
#define CATCDSDS_NewTranslationNormFormula                                CDS_LEVEL(46)

// CDS_12_W15
#define CATCDSSI_OnlySolveMovedConnexComponents                           CDS_LEVEL(47)

// CDS_12_W19
#define CATCDSHR_MUC_NoRigidificationForTangentRS                         CDS_LEVEL(48)
#define CATCDSHR_MUC_CheckForMovingVariablesOrParameters                  CDS_LEVEL(48)
#define CATCDSER_KeepSolutionClosestOfStartPoint                          CDS_LEVEL(48)

// CDS_12_W21
#define CATCDSSI_FixedVariablesForRRPTO                                   CDS_LEVEL(50)
#define CATCDSSI_PresolveEquationWithFixedGeom                            CDS_LEVEL(51)
#define CATCDSGU_CheckVariableFixationBeforeUpdate                        CDS_LEVEL(52)
#define CATCDSSI_TranslateDistancesChiralitiesMidpoints                   CDS_LEVEL(53)

// CDS_12_W22
#define CATCDSGD_CheckLine2PtCoBugCorrection                              CDS_LEVEL(54)
#define CATCDSDS_CheckTranslationNormForSingularityDetection              CDS_LEVEL(54)
#define CATCDSDS_UseVariableToleranceForSingularityDetection              CDS_LEVEL(54)

// CDS_12_W24
#define CATCDSDC_KUBPerturbationAlgorithm                                 CDS_LEVEL(55)

// CDS_12_W25
#define CATCDSGD_CorrectAnaliticalSolveGeometry                           CDS_LEVEL(56)
#define CATCDSER_KeepNonZeroRadiusAndDistance                             CDS_LEVEL(56)
#define CATCDSER_ReduceNFactorDegree                                      CDS_LEVEL(56)
#define CATCDSER_ReduceGeneralizedXYFactor                                CDS_LEVEL(56)
#define CATCDSSI_AdjustBBoxInsertStep                                     CDS_LEVEL(56)
#define CATCDSRR_LnCuDi2DIgnoreUndefinedChiralities                       CDS_LEVEL(56)

// CDS_12_W26
#define CATCDSGD_CorrectRSTransRotUnary                                   CDS_LEVEL(57)
#define CATCDSSI_UseNew3DTo2DTransformation                               CDS_LEVEL(57)

// CDS_12_W27
#define CATCDSAC_FixBugIsDependent                                        CDS_LEVEL(58)

// CDS_12_W33
#define CATCDS_SingularPositionDetection                                  CDS_LEVEL(59)

// CDS_12_W36
#define CATCDSGD_FixBugAddConstraint                                      CDS_LEVEL(60)
#define CATCDSGeometry_DimensionalConstraint                              CDS_LEVEL(61)
#define CATCDSGS_FixVariablesForDiagnostics                               CDS_LEVEL(61) // actif seulement si CATCDSGS_MergeVariables est actif

// CDS_12_W37
#define CATCDSSI_UseReturnCodeForRegenerate                               CDS_LEVEL(62)

// HF_R22SP4 
// comme on n'a pas réservé de variables pour la R22SP4, on met toutes les variables 'non' réservées à 62
#define CATCDS_R22SP4_HF1                                                 CDS_LEVEL(62)
#define CATCDS_R22SP4_HF2                                                 CDS_LEVEL(62)

#define CATCDSPlug_EvaluatateBeforeMUC_HFR22SP4                           CDS_LEVEL(62)
#define CATCDSPlug_NoMoveOnWD_HFR22SP4                                    CDS_LEVEL(62)

#define CATCDSGS_ReplaceSingularityForCiCuPtTan_HF                        CDS_LEVEL(62) //IR-324997
#define CATCDSGeometry_RefreshHelpParam_R22SP4_HF                         CDS_LEVEL(62) //IR-324997

// pareil pour R23GA
#define CATCDS_R23GA_HF1                                                  CDS_LEVEL(62)
#define CATCDS_R23GA_HF1                                                  CDS_LEVEL(62)

// CDS_12_W40
#define CATCDSGS_ReplaceSingularityRSSmart                                CDS_LEVEL(63)

// CDS_12_W41
#define CATCDSDS_ApplySingularityDetectionOnMovedRigidSets                CDS_LEVEL(64)

// CDS_12_W43
#define CATCDSHR_FormalDOF_VariablesAndEquations                          CDS_LEVEL(65)

// CDS_12_W44
#define CATCDSSI_RigidSetsInConnexComponents                              CDS_LEVEL(66)

// CDS_12_W46
#define CATCDSMO_NewConnectedComponents                                   CDS_LEVEL(67)

// CDS_12_W48
#define CATCDSGS_RemoveRedundantConstraints                               CDS_LEVEL(68)

// CDS_12_W49
#define CATCDSGD_SetCoordDependenciesFix                                  CDS_LEVEL(69)

// CDS_12W50
#define CATCDSPlug_MAE_MoveHelpPoints                                     CDS_LEVEL(70)
#define CATCDSValidator_SupportAlignementForDirectedDistance              CDS_LEVEL(70)

// HF_R23SP1 
// comme on n'a pas réservé de variables pour la R23SP1 , on met toutes les variables 'non' réservées à 70
#define CATCDS_R23SP1_HF1                                                 CDS_LEVEL(70)
#define CATCDS_R23SP1_HF2                                                 CDS_LEVEL(70)
#define CATCDS_R23SP1_HF3                                                 CDS_LEVEL(70)

// CDS_13W03
#define CATCDSGS_FixRemoveRedundantConstraintsBugs                        CDS_LEVEL(71)

// CDS_13W04
#define CATCDSGD_ParallelogramDetection                                   CDS_LEVEL(72)

// CDS_13_W05
#define CATCDS_VariablesForObjects                                        CATCDSModificationInactive
#define CATCDSGS_RemoveInconsistantMUC                                    CDS_LEVEL(73)
#define CATCDSHR_CorrectGlueVariableCondition                             CDS_LEVEL(73)
#define CATCDSHR_FormalDOF_EdgesOnVariablesInGraph                        CDS_LEVEL(73)
#define CATCDSSI_MUC_NoCheckMoveBack                                      CDS_LEVEL(73)
#define CATCDSSI_CompareMoveStates                                        CDS_LEVEL(73)
#define CATCDSSI_CorrectMoveAndSolve                                      CDS_LEVEL(73)

//CDS_13_W06
#define CATCDSGD_CorrectCheckSubset                                       CDS_LEVEL(74)

// CDS_13_W11
#define CATCDSHR_FormalDOF_CompareRSByWeight                              CDS_LEVEL(75)
#define CATCDSHR_FormalDOF_CompareRSByNeighbours                          CATCDSModificationInactive
#define CATCDSHR_FormalDOF_KeepFixedObjectInternalDOFWhenPossible         CDS_LEVEL(75)
#define CATCDSHR_FormalDOF_ActivateVariablesWhithImpliedRadiusEqualities  CDS_LEVEL(75)
#define CATCDSHR_FormalDOF_SymmetriesImplyRadiusEqualities                CDS_LEVEL(75)

// CDS_13_W12
#define CATCDSGS_RemoveRedundanciesCompletion                             CDS_LEVEL(76)

// CDS_13_W13
#define CATCDSGD_HelpPointsForTritangentCircles                           CDS_LEVEL(77)

// variables pour HF sur R23SP2
#define CATCDS_R23SP2_HF1                                                 CATCDSModificationInactive
#define CATCDS_R23SP2_HF2                                                 CATCDSModificationInactive
#define CATCDS_R23SP2_HF3                                                 CATCDSModificationInactive

// CDS_13_W15
#define CATCDSGD_CutSymmetricRigidSets                                    CDS_LEVEL(90)
#define CATCDSGS_SimplifyRedondantSymmetryEquations                       CDS_LEVEL(90)



#define CATCDSHR_FormalDOF_AlwaysKeepFixedMovedRS                         CDS_LEVEL(90)
#define CATCDSGS_NewArchi                                                 CDS_LEVEL(90)

#define CATCDSSI_CheckInconsistentProblems                                CDS_LEVEL(91)

// CDS_13_W17
#define CATCDSER_FixReduceNFactorDegreeBugs                               CDS_LEVEL(92)
#define CATCDSER_ExtendReduceNFactorDegree                                CDS_LEVEL(92)
#define CATCDSER_CheckVariantsWithMinAccuracy                             CDS_LEVEL(92)
#define CATCDSER_SubstituteQuadraticTerms                                 CDS_LEVEL(92)
#define CATCDSEquation_DoIdenticalSubstitution                            CDS_LEVEL(92)

//CDS_13W18
#define CATCDSGS_UpdateParameterValueFromAddedVariable                    CDS_LEVEL(93)
#define CATCDS_DiagnosticsOnEquations                                     CDS_LEVEL(93)
#define CATCDSGS_OnlyMergeCoincidentObjects                               CDS_LEVEL(93)
#define CATCDSSI_ApplyResidualTransformationOnHelpPoints                  CDS_LEVEL(93)
#define CATCDSGD_ReduceTransformationsAfterReturnFixedRS                  CDS_LEVEL(93)

//CDS_13W20
#define CATCDSDS_CorrectObjectVariableSingularityCheck                    CDS_LEVEL(100)
#define CATCDSGS_SingularityPatternsForDiagnostics                        CDS_LEVEL(100)

//CDS_13W21
#define CATCDSGD_ctLinePtCoPtCoSolveAnalitically                          CDS_LEVEL(101)
#define CATCDSAC_FixRankAndSizeHeuristic                                  CDS_LEVEL(101)
#define CATCDSDS_CompareRotationAngleWithCriticalNorm                     CDS_LEVEL(101)

//CDS_13W22
#define CATCDSGS_AddImplicitLineLineCoincidence                           CDS_LEVEL(102)

//CDS_13W23
#define CATCDSPlug_NewMAE                                                 CDS_LEVEL(103)

// variables pour HF sur R2013x, entre 104 et 149
#define CATCDS_R2013x_HF1                                                 CDS_LEVEL(104)
#define CATCDS_R2013x_HF2                                                 CDS_LEVEL(105)
#define CATCDS_R2013x_HF3                                                 CDS_LEVEL(106)
#define CATCDS_R2013x_HF4                                                 CATCDSModificationInactive
#define CATCDS_R2013x_HF5                                                 CATCDSModificationInactive

// variables pour HF sur R2014, entre 151 et 159
#define CATCDS_R2014_HF1                                                  CDS_LEVEL(151)
#define CATCDSSI_CompareSolutionOnMoveObjectsAndVariables_R215            CDS_LEVEL(152)

//CDS_13W24
#define CATCDSDS_EstimateCurveAndSurfaceCenter                            CDS_LEVEL(160)

//CDS_13W25
#define CATCDSGS_ChangeObjectTypeReducer                                  CDS_LEVEL(161)
#define CATCDSDC_VariableDiagnosticForWelldefined                         CDS_LEVEL(161)
#define CATCDSGD_ApplyTransformationsOnRealSolvedRS                       CDS_LEVEL(161)
#define CATCDSGD_OnlyOneRSCutForSymmetries                                CDS_LEVEL(161)
#define CATCDSGD_MidpointSearchCoincidenceByRS                            CDS_LEVEL(161)
#define CATCDSES_TryRemovingPertubationAfterSolve                         CDS_LEVEL(161)
#define CATCDSSU_EvalForDegeneratedEllipse                                CDS_LEVEL(161)
#define CATCDSGD_ArtPoint_AddIsolatedVariables                            CDS_LEVEL(161)

// CDS_13W27
#define CATCDSGS_AntitangencySingularityPattern                           CDS_LEVEL(162)
#define CATCDSGD_DoNotCutMovingVariables                                  CDS_LEVEL(162)

// CDS_13W28
#define CATCDSGD_EllipsesWithHandlers                                     CDS_LEVEL(163)

// CDS_13W30
#define CATCDS_ComputeRotationCenterForRS                                 CDS_LEVEL(164)

// CDS_13W34 variables pour HF sur R23SP2 (from 165 to 170)
#define CATCDS_R23SP3_HF1                                                 CATCDSModificationInactive
#define CATCDS_R23SP3_HF2                                                 CATCDSModificationInactive
#define CATCDS_R23SP3_HF3                                                 CATCDSModificationInactive
#define CATCDS_R23SP3_HF4                                                 CATCDSModificationInactive
#define CATCDS_R23SP3_HF5                                                 CATCDSModificationInactive

// CDS_13W35
#define CATCDSGS_AddImplicitCoincidenceForRadii                           CDS_LEVEL(170)
#define CATCDSDC_DisableFullyUnderdefined                                 CDS_LEVEL(170)
#define CATCDSGD_ActivateCheckLine2PtCoForWD                              CDS_LEVEL(170)
#define CATCDSGD_RemoveWDByArguments                                      CDS_LEVEL(170)
#define CATCDSGD_RemoveWDCuttingLevels                                    CDS_LEVEL(170)

// CDS_13W36
#define CATCDSGD_ReconvergeHPinSolveAnalytically                          CDS_LEVEL(171)
#define CATCDSRR_ReadHelpPointsForLnCiDi2D                                CDS_LEVEL(171)

// CDS_13W37
#define CATCDSGD_UseVariableForCuttingQeue                                CDS_LEVEL(172)
#define CATCDSGD_CutVariable                                              CDS_LEVEL(172)
#define CATCDSGD_FixVariableBugNaturalCutting                             CDS_LEVEL(172)
#define CATCDSGD_CheckOneConstraintWithVariable                           CDS_LEVEL(172)
#define CATCDSGD_CutVariable                                              CDS_LEVEL(172)
#define CATCDSGD_NewRulesForPatterns                                      CDS_LEVEL(172)
#define CATCDSGD_DisableVariableCheck                                     CDS_LEVEL(172)
#define CATCDSGS_ChangeTypeOfMovedObjects                                 CDS_LEVEL(172)
#define CATCDSSU_ReduceIdenticTransformations                             CDS_LEVEL(172)

// CDS_13W38
#define CATCDSGD_CheckAlignmentForConstraintSubset                        CDS_LEVEL(180)
#define CATCDSGD_CiTaLnTa                                                 CDS_LEVEL(180)
#define CATCDSGD_PtCoincidentToFixedObjects                               CDS_LEVEL(180)
#define CATCDSHR_MUC_NoRigidificationIfInternalDOF                        CDS_LEVEL(180)
#define CATCDSSI_ForceArtPointSolution                                    CDS_LEVEL(180)

// CDS_13W39
#define CATCDSAC_RemoveDuplicates                                         CDS_LEVEL(190)

// CDS_13W41
#define CATCDSGS_NotSatisfiedAngleChain                                   CDS_LEVEL(200)
#define CATCDSPlug_NewMAEHelpPoints                                       CDS_LEVEL(200)

// CDS_13W42
#define CATCDSValidator_ValueForPerpendicularity2D                        CDS_LEVEL(210)
#define CATCDSGD_WD_Variable                                              CDS_LEVEL(210)
#define CATCDSGD_WD_CheckLinePtCoLnAn                                     CDS_LEVEL(210)
#define CATCDSGD_WD_AutoSymmetry                                          CDS_LEVEL(210)
#define CATCDSGD_WD_CheckPointPtDiLnDiIfCloseEnough                       CDS_LEVEL(210)
#define CATCDSGD_CutPosVariableOfNonOrientedDi                            CDS_LEVEL(210)
#define CATCDSRR_AccurateKinSubspaceComputation                           CDS_LEVEL(210)
#define CATCDSDC_NewCheckWelldefinedForTangency                           CDS_LEVEL(210)
#define CATCDSDC_PtLnCoCiCoTa_MinAccuracy                                 CDS_LEVEL(210)
#define CATCDSRR_MinorRadiusEllipseBug                                    CDS_LEVEL(210)

// CDS_13W43
#define CATCDSGD_MUCOnArtPointComponents_MinimumMove                      CDS_LEVEL(220)
#define CATCDSGD_CutBoundedAngleVarIfDomainLargerThan2PI                  CDS_LEVEL(220)
#define CATCDSGD_CutConicsManipulators                                    CDS_LEVEL(220)
#define CATCDSGD_CutSymmetryLine                                          CDS_LEVEL(220)
#define CATCDSGD_CutCoincidentToTwoCoObjs                                 CDS_LEVEL(220)
#define CATCDSGS_SeflSymmetries                                           CDS_LEVEL(220)
#define CATCDSIM_SetNullVectorAsDecomposed                                CDS_LEVEL(220)

// CDS_13W44
#define CATCDSSM_UpdateHelpPointsBetweenMembers                           CDS_LEVEL(230)
#define CATCDSGD_SlotsCuttingPatterns                                     CDS_LEVEL(230)
#define CATCDSGS_UnlinkVariablesOfUnaryConstraints                        CDS_LEVEL(230)
#define CATCDSGS_ChangeObjectType_DiagPreAndPostProcess                   CDS_LEVEL(230)

// CDS_13W45
#define CATCDSGS_MergeBySatisfiedCoindence_CheckDiscrepancy               CDS_LEVEL(240)
#define CATCDSGS_Diag_MergeBySatisfiedCoindence                           CDS_LEVEL(240)
#define CATCDSSI_UpdateDependeeAfterLastArtPoint                          CDS_LEVEL(240)
#define CATCDS_DependenciesCanNotBeArtPoints                              CDS_LEVEL(240)
#define CATCDSGD_NoAddConstraintsRedondancies                             CDS_LEVEL(240)
#define CATCDSGS_RemoveSymmetryRedundancyWithRigidSets                    CDS_LEVEL(240)
#define CATCDSGS_ReplaceSymmetryInRigidSets                               CDS_LEVEL(240)
#define CATCDSSI_RRSolveOnSingularMovedRS                                 CDS_LEVEL(240)

// CDS_13W46
#define CATCDSGS_UnlinkFreeVariablesEquations                             CDS_LEVEL(250)
#define CATCDSGS_RemoveInconsistentConstraintInPriority                   CDS_LEVEL(250)

// CDS_14W37_HF
#define CATCDSGD_CheckCirclePtPtCoForOverdefined_HFCXR23SP4               CDS_LEVEL(251)

// HF R216
#define CATCDSIM_CheckSmallAnglesWithSinus_HFR216                         CDS_LEVEL(252)

// CDS_13W48
#define CATCDSGS_FixBugEquationReordering                                 CDS_LEVEL(260)
#define CATCDS_EquationsAreLogical                                        CDS_LEVEL(260)
#define CATCDSDC_NoMoreSpecificRulesForEquations                          CDS_LEVEL(260)
#define CATCDS_UnaryVariableConstraintsAreLogical                         CDS_LEVEL(260)
#define CATCDSDC_FixedVariablesAreDimensional                             CDS_LEVEL(260)
#define CATCDSGD_FixMappingBug_RestoreEquations                           CDS_LEVEL(260)
#define CATCDSDC_FixStatusInversion                                       CDS_LEVEL(260)
#define CATCDSGD_UseStandardIsDimensional                                 CDS_LEVEL(260)
#define CATCDSDC_DiagnosticsOnDependentCurves                             CDS_LEVEL(260)
#define CATCDS_DependentCurvesRigidification                              CDS_LEVEL(260)

#define CATCDSGS_UnlinkFreeVariablesGeomConstraints                       CATCDSModificationInactive
#define CATCDSGS_MergeVariablesReducer                                    CATCDSModificationInactive
#define CATCDSGS_UnlinkVariablesAfteRmCstsAndEqsMUCRed                    CATCDSModificationInactive
#define CATCDSHR_FormalDOF_LinePriorityForSegmentResizing                 CATCDSModificationInactive
#define CATCDSHR_FormalDOF_RedundantSuppressionOfFreedomsForSegments      CATCDSModificationInactive

// CDS_13W49
#define CATCDSAC_NotFullyDependenciesPostTreatement                       CDS_LEVEL(260)

// CDS_13W50
#define CATCDSSI_HRCyclesWithoutAngleisHeuristic                          CDS_LEVEL(260)
#define CATCDSGD_NoCheckHasConstrWithVariable                             CDS_LEVEL(260)

// CDS_13W51
#define CATCDSGS_MirrorReducer                                            CDS_LEVEL(270)

// CXR23SP5
#define CATCDS_R23SP5_GS_SimplifyConstraints                              CDS_LEVEL(271)
//#define CATCDSRR_OverdefinedDiag_ChangeCurveCurveDistanceEq_CXR23SP5      CDS_LEVEL(272)

#define CATCDSGS_IgnoreDimensionalConstraintsForOverdefined_HFCXR23SP5    CDS_LEVEL(273)
#define CATCDSGS_MirrorReducer_CompareConstraintValues_HFCXR23SP5         CDS_LEVEL(273)

#define CATCDSGD_CheckPointLnCoCuCoIfLnCuTa_HFCXR23SP5                    CDS_LEVEL(274)
//#define CATCDSGD_CheckCurve2LnTa_HFCXR23SP5                               CDS_LEVEL(274)

#define CATCDSModel_TranslateDistanceWithImplicitCoincidence_HFCXR23SP5   CDS_LEVEL(275) //IR-335822
#define CATCDSGD_LineDistantToFixedLineImplicitlyFixed_HFCXR23SP5         CDS_LEVEL(275)

#define CATCDSGD_SolveAnaliticallyCheckPointLnCoCiCoIfLineThroughCenter_HFCXR23SP5  CDS_LEVEL(276)
#define CATCDSGS_RerouteDistanceConstraintBetweenSymmetricPairs_CXR23SP5            CDS_LEVEL(276)

#define CATCDSGD_SolveForCurveWithDiscontinuities_HFR23SP5                CDS_LEVEL(277)
#define CATCDSPlug_EvaluatateBeforeMUC_HFR23SP5                           CDS_LEVEL(277)
#define CATCDSPlug_NoMoveOnWD_HFR23SP5                                    CDS_LEVEL(277)

#define CATCDSPlug_FirstReevaluateWithPreevaluate_HFCXR23SP5              CDS_LEVEL(278)
#define CATCDSGD_CheckLineLnDiMiAddDi_OrientationOnLine_HFCXR23SP5        CDS_LEVEL(278)

#define CATCDSGS_DirectionalDistanceForMAE_HFCXR23SP5                     CDS_LEVEL(279)
#define CATCDSGD_ConstraintSubsetLineTangentToTwoCircles_HFCXR23SP5       CDS_LEVEL(279)
#define CATCDSSI_TryGlobalMoveForMAE_HFCXR23SP5                           CDS_LEVEL(279)

//#define CATCDSGD_ParallelogramDetectionRollback_HFCXR23SP5                CDS_LEVEL(279)
#define CATCDSSI_ImplicitDirectionOnDistanceFromCommonLine_HFCXR23SP5     CDS_LEVEL(279)
#define CATCDSSI_ApplyAndValidate_HFCXR23SP5                              CDS_LEVEL(279)
#define CATCDSSI_GlobalMove_IsGeometrySatisfied_HFCXR23SP5                CDS_LEVEL(279)

// CXR23SP6
#define CATCDSGD_CheckCirclePtPtCoForOverdefined_HFCXR23                  CDS_LEVEL(272)

#define CATCDSGD_CheckPointCiCoPtDiIfPtOnCircle_HFCXR23SP6                CDS_LEVEL(274)

// CDS_14W02
#define CATCDSPlug_RemoveExtraDOFMode                                     CDS_LEVEL(280), CDS_HF_LEVEL(279,1)
#define CATCDSIM_InitializeOrthNullVector_PtPtDi                          CDS_LEVEL(280), CDS_HF_LEVEL(279,1)
#define CATCDSPlug_NewDeduceConstraint                                    CDS_LEVEL(280), CDS_HF_LEVEL(279,1)

// CDS_14W24_HF
#define CATCDSGD_SolveAnalyticallyForRaLnTaCiTa_HF                        CDS_LEVEL(281)
#define CATCDSAC_AvoidConstraintBetweenCurveAndDependencies_HF            CDS_LEVEL(281)
#define CATCDSGS_IgnoreDimensionalConstraintsForOverdefined_HFCXR24SP1    CDS_LEVEL(281)
#define CATCDSGS_MirrorReducer_CompareConstraintValues_HFCXR24SP1         CDS_LEVEL(281)
#define CATCDSDC_PerturbCurveHelpParam_HFCXR24SP1                         CDS_LEVEL(281)
#define CATCDSRR_RemoveDomainInconsistentDOF_HFCXR24SP1                   CDS_LEVEL(281)
#define CATCDSDC_PerturbInDOFWithDomains_HFCXR24SP1                       CDS_LEVEL(281)
#define CATCDSSI_TryGlobalMoveForMAE_HF                                   CDS_LEVEL(282)
#define CATCDSGD_SolveAnalyticallyForRaLnTaCiTa_SecondEdition_HFCXR24SP1  CDS_LEVEL(283)
#define CATCDSGS_ReplaceSingularityForCiCuPtTan_CXR24SP1_HF               CDS_LEVEL(284)
#define CATCDSGS_RestoreGeometry_CXR24SP1_HF                              CDS_LEVEL(284)
#define CATCDSRR_StoreInitialTransformationsForDiagnostics_CXR24SP1_HF    CDS_LEVEL(284)
#define CATCDSGD_SolveAnalyticallyFor2CiTa_CXR24SP1_HF                    CDS_LEVEL(285)
#define CATCDS_Porsche_CXR24SP1_HF                                        CDS_LEVEL(286)
#define CATCDSGS_RemoveSingularityDependentCurve_CXR24SP1_HF              CDS_LEVEL(287)
#define CATCDSAC_UseSimplifiedGeometry_CXR24SP1_HF                        CDS_LEVEL(288)
#define CATCDSGS_SimplifyConstraints_CXR24SP1_HF                          CDS_LEVEL(288)

// CDS_14W08
#define CATCDSIM_OptimalOrthogonalBasis                                   CDS_LEVEL(290), CDS_HF_LEVEL(279,1)
#define CATCDSIM_CheckSmallAnglesWithSinus                                CDS_LEVEL(290), CDS_HF_LEVEL(279,1)

// CDS_14W09
//#define CATCDSAC_FixBug_AddEveryInputConstraintsInRR                      CDS_LEVEL(300), CDS_HF_LEVEL(279,1)

#define CATCDSModel_AddSegmenthConstraint                                 CDS_LEVEL(300), CDS_HF_LEVEL(279,1)
#define CATCDSHR_FormalDOF_VariableParameters                             CDS_LEVEL(300), CDS_HF_LEVEL(279,1)
#define CATCDSHR_UseCurveRigidificationPatterns                           CDS_LEVEL(300), CDS_HF_LEVEL(279,1)
#define CATCDSES_BoundLevenbergMarquardtLambda                            CDS_LEVEL(300), CDS_HF_LEVEL(279,1)
#define CATCDSES_FixLevenbergMarquardt_RestorePrevGuess                   CDS_LEVEL(300), CDS_HF_LEVEL(279,1)

// CDS_14W10
#define CATCDS_UpdateAnchor_StrictEquality                                CDS_LEVEL(310), CDS_HF_LEVEL(279,1)
#define CATCDS_BBoxCache_StrictEquality                                   CDS_LEVEL(310), CDS_HF_LEVEL(279,1)
#define CATCDS_NURBSCurve_StrictEquality                                  CDS_LEVEL(310), CDS_HF_LEVEL(279,1)
#define CATCDSDC_RemoveMUCBeforeDiag                                      CDS_LEVEL(310), CDS_HF_LEVEL(279,1)

//CDS_14W11
#define CATCDSGD_CutOffsetCornerLineLine                                  CDS_LEVEL(320), CDS_HF_LEVEL(279,1)
#define CATCDSGD_FixationByDep                                            CDS_LEVEL(320), CDS_HF_LEVEL(279,1)

//CDS_14W12
#define CATCDSGD_CaclGeomDistanceOnInitialPosition                        CDS_LEVEL(330), CDS_HF_LEVEL(279,1)
#define CATCDSGS_CreateAndMergeMidpoints                                  CDS_LEVEL(330), CDS_HF_LEVEL(279,1)
#define CATCDSGS_ForceChiralityCcTaCircles                                CDS_LEVEL(330), CDS_HF_LEVEL(279,1)

//CDS_14W13
#define CATCDSGD_CutCircle2LnTa1PtCoIfParallelAndPtOnLine                 CDS_LEVEL(340), CDS_HF_LEVEL(279,1)
#define CATCDSGS_ChangeObjectType_CircleCircleCoSy                        CDS_LEVEL(340), CDS_HF_LEVEL(279,1)
#define CATCDSGS_Mirror_UseInitialPosition                                CDS_LEVEL(340), CDS_HF_LEVEL(279,1)
#define CATCDSGS_Mirror_ReplaceSymSymByCo                                 CDS_LEVEL(340), CDS_HF_LEVEL(279,1)

//CDS_14W30_HF
#define CATCDSGD_SolveAnalyticallyForRaLnTaCiTa_HFCXR24SP3                CDS_LEVEL(341)

//CDS_14W37_HF
#define CATCDSGS_RestoreGeometry_CXR24SP3_HF                              CDS_LEVEL(342)
#define CATCDSGS_ReplaceSingularityForCiCuPtTan_CXR24SP3_HF               CDS_LEVEL(342)
#define CATCDSRR_StoreInitialTransformationsForDiagnostics_CXR24SP3_HF    CDS_LEVEL(342)
#define CATCDSDC_PerturbInDOFWithDomains_HFCXR24SP3                       CDS_LEVEL(342)
#define CATCDSRR_RemoveDomainInconsistentDOF_HFCXR24SP3                   CDS_LEVEL(342)
#define CATCDSDC_PerturbCurveHelpParam_HFCXR24SP3                         CDS_LEVEL(342)
#define CATCDSGD_CheckCirclePtPtCoForOverdefined_HFCXR24SP3               CDS_LEVEL(342)

//CDS_14W41
#define CATCDSGS_IgnoreDimensionalConstraintsForOverdefined_HFCXR24SP3    CDS_LEVEL(343)
#define CATCDSGS_MirrorReducer_CompareConstraintValues_HFCXR24SP3         CDS_LEVEL(343)

// R24SP3 HF
#define CATCDSDC_TranslateTogether_Symmetries_HFCXR24SP3                  CDS_LEVEL(344)
#define CATCDSDC_TranslateTogether_ConicConcentricities_HFCXR24SP3        CDS_LEVEL(344)
#define CATCDSDC_TranslateTogether_Midpoint_HFCXR24SP3                    CDS_LEVEL(344)
#define CATCDSDC_MarkNotSpecifiedPerturbatedHelpPoints_HFCXR24SP3         CDS_LEVEL(344)
#define CATCDSDC_PerturbKernelGeom_HFCXR24SP3                             CDS_LEVEL(344)

#define CATCDSGD_CheckPointCiCo2LnCoAddPerp_HFCXR24SP3                    CDS_LEVEL(345)

#define CATCDSGD_CirclesHave3DOF_CXR24SP3                                 CDS_LEVEL(346)

//CDS_14W15
#define CATCDSSI_ProcessAlignmentsAndOrientations                         CDS_LEVEL(350), CDS_HF_LEVEL(279,1)
#define CATCDSGS_RefineConstraintReducer_NewRuleCiCiCc                    CDS_LEVEL(350), CDS_HF_LEVEL(279,1)
#define CATCDSGS_RemoveConstraintCopies_VariableForDiag                   CDS_LEVEL(350), CDS_HF_LEVEL(279,1)
#define CATCDSSU_TrueTypeForIsDimensional                                 CDS_LEVEL(350), CDS_HF_LEVEL(279,1)
#define CATCDSModel_Pure2DForFixedSketch                                  CDS_LEVEL(350), CDS_HF_LEVEL(279,1)

//CDS_14W16
#define CATCDSRR_RemoveCorrectStartPoint                                  CDS_LEVEL(360), CDS_HF_LEVEL(279,1)

//CDS_14W20
#define CATCDSGS_SimplifyConstraints                                      CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSSI_HRFormalDOFAfterGD                                       CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSSI_ProcessGeometryWithFixedRigidSets                        CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSGD_CuttingPriority_NumberOfParentConstraints                CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSGD_CheckConicCcCo                                           CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSGD_CheckPointLnCoPtDi                                       CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSGD_CheckLineLnDiMiAddDi_OrientationOnLine                   CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSGD_CheckContinuity                                          CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSGD_CheckLinePtCoCuTaIfCoincident                            CDS_LEVEL(370), CDS_HF_LEVEL(279,1)
#define CATCDSGD_CheckCirclePtCoCuTaIfCoincident                          CDS_LEVEL(370), CDS_HF_LEVEL(279,1)

//CDS_14W21
#define CATCDSGD_SymmmetryNaturalCutting                                  CDS_LEVEL(380), CDS_HF_LEVEL(279,1)

//CDS_14W23
#define CATCDSGD_CheckLinePtCoLnPaLnPeAddPe                               CDS_LEVEL(390), CDS_HF_LEVEL(279,1)
#define CATCDSGD_SolveAnalyticallyForRaLnTaCiTa                           CDS_LEVEL(390), CDS_HF_LEVEL(279,1)
#define CATCDSGD_SoftDecompositionResetMUC                                CDS_LEVEL(390), CDS_HF_LEVEL(279,1)

//CDS_14W24
#define CATCDSER_GeneralizedFullSolve                                     CDS_LEVEL(400), CDS_HF_LEVEL(279,1)
#define CATCDSGD_ArtPoint_CreateGeometriesForVariables                    CDS_LEVEL(400), CDS_HF_LEVEL(279,1)
#define CATCDSPlug_EvaluatateBeforeMUC                                    CDS_LEVEL(400), CDS_HF_LEVEL(279,1)
#define CATCDSPlug_NoMoveOnWD                                             CDS_LEVEL(400), CDS_HF_LEVEL(279,1)

//CDS_14W25
#define CATCDSGS_MirrorReducerSkipObjOnAxis                               CATCDSModificationInactive
#define CATCDSPlug_NewMAE_EvalByTransformDC                               CDS_LEVEL(410), CDS_HF_LEVEL(279,1)
#define CATCDSAC_AvoidConstraintBetweenCurveAndDependencies               CDS_LEVEL(410), CDS_HF_LEVEL(279,1)
#define CATCDSPlug_NewDeduceConstraint2                                   CDS_LEVEL(410), CDS_HF_LEVEL(279,1)

//CDS_14W28
#define CATCDSSI_DistancePropagationOnVariables                           CDS_LEVEL(420), CDS_HF_LEVEL(279,1)
#define CATCDSDC_PerturbInDOFWithDomains                                  CDS_LEVEL(420), CDS_HF_LEVEL(279,1)
#define CATCDSRR_RemoveDomainInconsistentDOF                              CDS_LEVEL(420), CDS_HF_LEVEL(279,1)
#define CATCDSRR_UseTolerancesForSupplementarySubspace                    CDS_LEVEL(420), CDS_HF_LEVEL(279,1)
#define CATCDSDC_PerturbCurveHelpParam                                    CDS_LEVEL(420), CDS_HF_LEVEL(279,1)
#define CATCDSGS_IgnoreDimensionalConstraintsForOverdefined               CDS_LEVEL(420), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_CompareConstraintValues                    CDS_LEVEL(420), CDS_HF_LEVEL(279,1)
#define CATCDSGS_NotMergeCstrsVarsWithDiffOr                              CDS_LEVEL(420), CDS_HF_LEVEL(279,1)

// CDS_14W29
#define CATCDSSI_TryGlobalMoveForMAE                                      CDS_LEVEL(430), CDS_HF_LEVEL(279,1)
#define CATCDSER_ForceESSolveForDegenerateFullSolve                       CDS_LEVEL(430), CDS_HF_LEVEL(279,1)

//CDS_14W31
#define CATCDSER_ReduceDegree_PreventDivisionBySmallValue                 CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGD_GeneralizedVariableClasses                               CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_AddSelfSymmetries                          CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_SetPerpendicularLinesSelfSym               CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_FixCompareAngleValueBug                    CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_UseTernaryConstraints                      CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_UseNonZeroDistance                         CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_UseRadius                                  CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_SelectClosestObject                        CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_SearchTangencyOnMirrorSide                 CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_NewPointPattern_LnCoPtDi                   CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_NewLinePattern_PtCoCiTa                    CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MirrorReducer_ReplaceLineSelfSymmetries                  CDS_LEVEL(440), CDS_HF_LEVEL(279,1)
#define CATCDSGD_SolveAnalyticallyForRaLnTaCiTa_SecondEdition             CDS_LEVEL(440), CDS_HF_LEVEL(279,1)

//CDS_14W32
#define CATCDSRR_StoreInitialTransformationsForDiagnostics                CDS_LEVEL(450), CDS_HF_LEVEL(279,1)
#define CATCDSGS_MergeVariableWithValueDependCstrOri                      CDS_LEVEL(450), CDS_HF_LEVEL(279,1)

//CDS_14W36
#define CATCDSGD_CheckLine3PtCoIfMidpoints                                CDS_LEVEL(460), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)

//CDS_14W37
#define CATCDSGD_SolveAnalyticallyFor2CiTa                                CDS_LEVEL(470), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGD_CheckCirclePtPtCoForOverdefined                          CDS_LEVEL(470), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSSI_SetModelCurrentComponent                                 CDS_LEVEL(470), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)

//CDS_14W39
#define CATCDSGS_ReplaceSingularityForCiCuPtTan                           CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(710,13)
#define CATCDSSI_RigidMove                                                CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGS_RemoveSatisfiedByCoincidenceInReevaluate                 CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGS_EvalTransform_DontCheckDiscrepancyBeforeMerge            CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGD_MoveCuttingPattern_RigidPair                             CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGS_MergeObject_UpdateConstraintHelpParam                    CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSSI_EvalTransform_RemovePropagateMove                        CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSSI_EvalTransform_GlobalMoveForRigidSolvingMode              CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSPlug_MoveAndEvaluate_RemoveMUC                              CDS_LEVEL(480), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)

#define CATCDSRR_DerivRadiusInCiCuTan                                     CDS_LEVEL(490), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSSI_DoNotChangeSpecifiedHelpParamForTangency                 CDS_LEVEL(490), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)

// CDS_14W39
#define CATCDSGS_AntitangencyPattern                                      CDS_LEVEL(500), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGD_LinePtCoCuTaExtended                                     CDS_LEVEL(500), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGeometry_RefreshHelpParam                                   CDS_LEVEL(500), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGD_CheckOneConstraintWithNonIsolatedVariable                CDS_LEVEL(500), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)

// CDS_14W40
#define CATCDSModel_SetMovedTransformationOnAllObjects                    CDS_LEVEL(510), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
//#define CATCDSRR_OverdefinedDiag_ChangeCurveCurveDistanceEq               CDS_LEVEL(510)
#define CATCDSGS_DetectAxisRSImpliedSymmetries                            CDS_LEVEL(510), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSDC_TranslateTogether_Symmetries                             CDS_LEVEL(510), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSDC_TranslateTogether_ConicConcentricities                   CDS_LEVEL(510), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSDC_TranslateTogether_Midpoint                               CDS_LEVEL(510), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSDC_MarkNotSpecifiedPerturbatedHelpPoints                    CDS_LEVEL(510), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSDC_PerturbKernelGeom                                        CDS_LEVEL(510), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSSI_SolveWithFixedArgs_FixDependentVariables                 CDS_LEVEL(510), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)

// CDS_14W41
#define CATCDSGD_GeneralizeCircleLineIntersection                         CDS_LEVEL(520), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGD_ctCircleRaLnTaCiTaUpdateRadiusAndHP                      CDS_LEVEL(520), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSGD_CircleRaCiTaCiTa                                         CDS_LEVEL(520), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)

// 15x_F02
#define CATCDSGS_AddImpliedAnglesForIsoscelesTriangle                     CDS_LEVEL(520), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSSI_DoNotCreateTrivialLinkInGraph                            CDS_LEVEL(520), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSHR_IgnoreConstraintsOnCurvesAndSurfaces                     CDS_LEVEL(520), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)
#define CATCDSSI_ReduceMovingTransformations                              CDS_LEVEL(520), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1)

// CXR24
#define CATCDSGD_CirclesHave3DOF_CXR24                                    CDS_LEVEL(521)

#define CATCDSGS_FixRSSmartSingularityBug_CXR24                           CDS_LEVEL(522)
#define CATCDSRR_SetDependencesForRRPatternEquations_CXR24                CDS_LEVEL(522)

// 2015x
#define CATCDSEG_FindDomainForSinAndCos_2015xFD01                         CDS_LEVEL(521)

#define CATCDSGD_WDRulesForSWSlots_2015xFD02                              CDS_LEVEL(522)

#define CATCDSGD_SolveAnaliticallyPointLnCoCiCo_HFR24SP5                  CDS_LEVEL(522)

// CDS_14W42
#define CATCDSGS_MergeObjectsUpdate_CheckForCoincidentPoints              CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_EnableStateManagerUndo                                   CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_LocalMapper                                              CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSPlug_MAEOnUnsatisfiedGeometry                               CDS_LEVEL(530), CDS_HF_LEVEL(279,8), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1) // FCX 06.2015 : active only in 279 hf8 because the code was not in the plug before
#define CATCDSGD_HeuristicAntiBouclettes                                  CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CheckLinePtCoCiTaIfPointOutsideCircle                    CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CheckPointCiCoCiCoIntersectingCircles                    CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_LookForImplicitlyFixedObjects                            CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_RemoveConstraintCopies_SpecifiedParameters               CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MergeObject_UseObjectMappingForSymmetry                  CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MergeObject_DisableSuperImposed                          CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_UseInitialAlignementAfterSymmetryMerging                 CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MergeSelfSymmetricPoints                                 CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_CheckIfCircleIsInLineRS                                  CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MirrorReducer_MirrorSide                                 CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MirrorReducer_ChangeMirrorRepresentation                 CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_Mirror_DisableReplaceSymSymByCo                          CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_Mirror_AddCenterForSelfSymmetries                        CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_Mirror_SelfSymetricCircleImpliedBytangencies             CDS_LEVEL(530), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_14W42_HF (R2013x)
#define CATCDSSI_ApplyAndValidate_HFR214                                  CDS_LEVEL(531)
#define CATCDSModel_SignInCalcValue_HFR214                                CDS_LEVEL(532)

// CDS_14W43
#define CATCDSSI_DisableHRFormalDOFForMUC                                 CDS_LEVEL(540), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_FixMovingVariablesForMUCViaUpdate                        CDS_LEVEL(540), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_ReplaceSingularityForCiCuPtTan_ImplicitPtCuCo            CDS_LEVEL(540), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_SoftDecomposition_RestoreHPOnBrokenConstraints           CDS_LEVEL(540), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_14W44
#define CATCDSGD_CheckPointCiCoPtDiIfPtOnCircle                           CDS_LEVEL(550), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_AddImplicitTangencies                                    CDS_LEVEL(550), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSIM_ChooseVectorInitForDegeneratePointLineDistance           CDS_LEVEL(550), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CheckPointLnCoCuCoIfLnCuTa                               CDS_LEVEL(550), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
//#define CATCDSGD_CheckCurve2LnTa                                          CDS_LEVEL(550)

// CDS_14W46
#define CATCDSGS_RemoveSingularityDependentCurve                          CDS_LEVEL(560), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_14W48
#define CATCDSSI_ComputePerpendicularityClassesForParallelism             CDS_LEVEL(580), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_14W49
#define CATCDSModel_TranslateDistanceWithImplicitCoincidence              CDS_LEVEL(590), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_KeepSpecifiedHelpParam                                   CDS_LEVEL(590), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_SolveForCurveWithDiscontinuities                         CDS_LEVEL(590), CDS_HF_LEVEL(279,7), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1) // FCX 06.2015 : active only in 279 hf7
#define CATCDSSI_RRNoPriorityForFixedVariables                            CDS_LEVEL(590), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_14W51
#define CATCDSGS_RerouteDistanceConstraintBetweenSymmetricPairs           CDS_LEVEL(600), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_AccurateMergeObjectsUpdate                               CDS_LEVEL(600), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_RegenerateAfterMerge                                     CDS_LEVEL(600), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W03
#define CATCDSSI_ApplyAndValidate                                         CDS_LEVEL(610), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_GlobalMove_IsGeometrySatisfied                           CDS_LEVEL(610), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CheckPointCiCo2LnCoAddPerp                               CDS_LEVEL(610), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W04
#define CATCDSGS_CheckMergesInAntitangencyPattern                         CDS_LEVEL(620), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSModel_UpdateLimitsAfterRemovingFakeDiscontinuities          CDS_LEVEL(620), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSModel_UpdateLimitsForCurveWithDiscontinuities               CDS_LEVEL(620), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_SecondSolveForCollapsedGeometriesOnly                    CDS_LEVEL(620), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_SecondSolveForMissedChiralities                          CDS_LEVEL(620), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSIM_SetMidpointsLength                                       CDS_LEVEL(620), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSTest_ImplementGetNbOfDiscontinuities                        CDS_LEVEL(620), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W05
#define CATCDSSI_CompareSolutionOnMoveObjectsAndVariables                 CDS_LEVEL(630), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_DisableMUCVU                                             CDS_LEVEL(630), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W06
#define CATCDSGS_RemoveInconsistentConstraintInPriority_Fix               CDS_LEVEL(640), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CirclesHave3DOF                                          CDS_LEVEL(640), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_CheckNormalNormWithRespectToCenterNorm                   CDS_LEVEL(640), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W09
#define CATCDSRR_SetDependencesForRRPatternEquations                      CDS_LEVEL(650), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_RemoveSingularityCiCuDiValueZero                         CDS_LEVEL(650), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSU_IgnoreDimConstraintsForOverDiag_ParaClass                CDS_LEVEL(650), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W10
#define CATCDSModel_SignInCalcValue                                       CDS_LEVEL(660), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSPlug_FirstReevaluateWithPreevaluate                         CDS_LEVEL(660), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W12
#define CATCDSGS_DirectionalDistanceForMAE                                CDS_LEVEL(670), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSES_CheckDomainsAfterPerturbation                            CDS_LEVEL(670), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDS_ChangeCurvatureTolerance                                   CDS_LEVEL(670), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_ConstraintSubsetLineTangentToTwoCircles                  CDS_LEVEL(670), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W13
#define CATCDSEG_FindDomainForSinAndCos                                   CDS_LEVEL(680), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_ImplicitDirectionOnDistanceFromCommonLine                CDS_LEVEL(680), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_RSSimpleArtPointAngle_DoNotCutDependencies               CDS_LEVEL(680), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_FixRSSmartSingularityBug                                 CDS_LEVEL(680), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_UseRSForChoosingMirrorSide                               CDS_LEVEL(680), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_FixRerouteOnBaseCurve                                    CDS_LEVEL(680), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_SetOrientationOnDependencies                             CDS_LEVEL(680), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSModel_TriangleChiralityUpdate                               CDS_LEVEL(680), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSAC_UseSimplifiedGeometry                                    CDS_LEVEL(680), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W14
#define CATCDSGD_CheckBothLinesAndUsePriorities                           CDS_LEVEL(690), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CutCurveWithRedundantConstraints                         CDS_LEVEL(690), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CheckPointCiCoDiCenter                                   CDS_LEVEL(690), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CheckPointCiCoLnCoIntersectsASmallerConcentricCircle     CDS_LEVEL(690), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_SimplifyConstraintsAC                                    CDS_LEVEL(690), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_CheckDependencesForImplicitPtCuCo                        CDS_LEVEL(690), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_AngleBetweenLinesReportedOnAxisMirrorReducer             CDS_LEVEL(690), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_RemoveFalseRulesForSymObjects                            CDS_LEVEL(690), CDS_HF_LEVEL(279,1), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSIM_CorrectLinesSymmetryModelisation                         CDS_LEVEL(690), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W16
#define CATCDSValidator_ComputeHPForCiCiDiIfNotGivenAndConstSatisfied     CDS_LEVEL(691), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSValidator_OrientZeroDistanceBetweenCircles                  CDS_LEVEL(691), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_TranslateDistanceInGS                                    CDS_LEVEL(691), CDS_HF_LEVEL(279,12), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_WDRulesForSWSlots                                        CDS_LEVEL(691), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_RemoveRedundantWhenAddingExistingConstraint              CDS_LEVEL(691), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSU_LineCircleHP_UsePolynomMinima                            CDS_LEVEL(691), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_NoRigidSolveForOverconstrainedRS                         CDS_LEVEL(691), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSU_SkipDirectionAndAxis                                     CDS_LEVEL(691), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_SolveAnaliticallyCheckPointLnCoCiCoIfLineThroughCenter   CDS_LEVEL(691), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W17
#define CATCDSGD_ComputeAlignmentInCheckArtPair                           CDS_LEVEL(692), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_HandleDirectionalDistWhenComputingFixedObjects           CDS_LEVEL(692), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_HandlePtLineCoincidenceWhenComputingFixedObjects         CDS_LEVEL(692), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSPlug_KeepInitialDataOnInconsistentGeomComponent             CDS_LEVEL(692), CDS_HF_LEVEL(279,2), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W18
#define CATCDSGD_CorrectConfigurationsWithMultipleSolutions               CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSER_ReduceQuadraticTerms                                     CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSER_CheckDomainWithTolerances                                CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSER_ReduceNFactorDegreeExtension                             CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_DetectMirrorForLineCircleIntersection                    CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSValidator_AlignmentOnLinesSymmetry2D                        CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MirrorReducer_FilterInSearchSymmetric                    CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_DetectMirrorForCircleCircleIntersection                  CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MirrorReducer_SymmetricMUC                               CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_ToleranceForSelfSymmetry                                 CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_ComputeHPToSatisfyConstraintBetweenFixedArgs             CDS_LEVEL(693), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W19
#define CATCDSSI_ApproximatedResultInRRReturnToIM                         CDS_LEVEL(694), CDS_HF_LEVEL(279,4), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSU_FixFindRigidSetsAndVariables                             CDS_LEVEL(694), CDS_HF_LEVEL(279,4), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MirrorReducerAddOrOnReportDiSymPtPtToDiPtLn              CDS_LEVEL(694), CDS_HF_LEVEL(279,3), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W21
#define CATCDSGS_ParallelismBetweenLinesReportedOnAxisMirrorReducer       CDS_LEVEL(695), CDS_HF_LEVEL(279,4), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_UpdateMovedTransfoInMAEAndReduceTransfo                  CDS_LEVEL(695), CDS_HF_LEVEL(279,4), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_LinePointCircleTgCorrector                               CDS_LEVEL(695), CDS_HF_LEVEL(279,5), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MirrorReducer_AddSymmetryOnLineGoingThroughSymmetricPoints CDS_LEVEL(695), CDS_HF_LEVEL(279,5), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W22
#define CATCDSSI_EvalByTransformNoFlushChirality                          CDS_LEVEL(696), CDS_HF_LEVEL(279,6), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_2ndOrderPolynomalChoiceForSubstitutionVariable           CDS_LEVEL(696), CDS_HF_LEVEL(279,6), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSEG_EquationImpliedByCurveNormalNotAdded                     CDS_LEVEL(696), CDS_HF_LEVEL(279,7), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W23
#define CATCDSPlug_FlushChirality_PlugConvergence                         CDS_LEVEL(697), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSPlug_RestoreApplicationHPInMAE                              CDS_LEVEL(697), CDS_HF_LEVEL(279,8), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_BugFixComputeAlignmentInCheckArtPair                     CDS_LEVEL(697), CDS_HF_LEVEL(279,8), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_FixNullDistanceInCheckPointsNotCoincident                CDS_LEVEL(697), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_PositiveRadiusInctCircle_CiCcDi_Greater                  CDS_LEVEL(697), CDS_HF_LEVEL(279,9), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSER_DeleteMinAccuracyDivideBy100                             CDS_LEVEL(697), CDS_HF_LEVEL(279,10), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSER_KeepVarsWithNullCoeffInSumOfSquares                      CDS_LEVEL(697), CDS_HF_LEVEL(279,10), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W24
#define CATCDSGD_UseCorrectRuleToCutPtOnCircle                            CDS_LEVEL(698), CDS_HF_LEVEL(279,11), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSEG_SkipZEquationFor2DCurves                                 CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSEG_UseColinearEquation                                      CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_UseAlignmentForTangencyHP                                CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSRR_FixCuCuTaIncrBug                                         CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSEllipseEquation_FixWeirdIdea                                CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_UseAlignmentForComputingTangencyHP                       CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_UnifiedRemoveCurveTangencySingularities                  CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_RemoveCurveTangencySingularitiesBeforeGD                 CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_UpdateDependeeOnSubGeometry                              CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSSI_ReevaluateWithTransformations                            CDS_LEVEL(698), CDS_HF_LEVEL(279,12), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSPlug_MAENoAppliedTransformations                            CATCDSModificationInactive
#define CATCDSGS_CreateGeometryWhenInputGeometryHasBeenModified           CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGD_CheckNotHasVariable_PointCoincidentToFixedObjects        CDS_LEVEL(698), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)
#define CATCDSGS_ProcessMergings                                          CDS_LEVEL(698), CDS_HF_LEVEL(279,4), CDS_HF_LEVEL(451,1), CDS_HF_LEVEL(522,1)

// CDS_15W25
#define CATCDSGS_CheckCurveMirror                                         CDS_LEVEL(699), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(522,1)
#define CATCDSGS_FixConstraintReplaceBetweenSymmetricObjects              CDS_LEVEL(699), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(522,1)
#define CATCDSGS_RemoveRedundantInternalSymmetries                        CDS_LEVEL(699), CDS_HF_LEVEL(279,12), CDS_HF_LEVEL(522,1)
#define CATCDSGD_Diag_CutEllipseCoCc                                      CDS_LEVEL(699), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(522,1)
#define CATCDSGD_RemoveIrrelevantCutType                                  CDS_LEVEL(699), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(522,1)
#define CATCDSGD_Correct2PtCoSolveAnalytically                            CDS_LEVEL(699), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(522,1)
#define CATCDSGS_AddConstraintCompareDiscrepancyToOne                     CDS_LEVEL(699), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(522,1)

// CDS_15W26
#define CATCDSGS_FixSamePointsInCheckPointsNotCoincident                  CDS_LEVEL(700), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(522,1)
#define CATCDSGS_MirrorReducer_CheckConfigurationCircleSymmetry           CDS_LEVEL(700), CDS_HF_LEVEL(279,14), CDS_HF_LEVEL(522,1)
#define CATCDSSI_SecondADRunReset                                         CDS_LEVEL(700), CDS_HF_LEVEL(279,13), CDS_HF_LEVEL(522,1)
#define CATCDSGS_SwitchTranslateDistanceAndMergeReducer                   CDS_LEVEL(700), CDS_HF_LEVEL(279,15), CDS_HF_LEVEL(522,1)

// CDS_15W27
#define CATCDSER_FullSolve_ChooseClosestSolution                          CDS_LEVEL(701), CDS_HF_LEVEL(522,1)
#define CATCDSGD_SolveForCurveWithDiscontinuities2                        CDS_LEVEL(701), CDS_HF_LEVEL(279,7), CDS_HF_LEVEL(522,1)
#define CATCDSGD_SolveAnaliticallyPointLnCoCiCo                           CDS_LEVEL(701), CDS_HF_LEVEL(522,1)

#define CATCDS_ReconvergeHPInsteadOfUpdateHP                              CATCDSModificationInactive

// CDS_15W28
#define CATWBx_WBModel_WBValueProduct                                     CDS_LEVEL(702)
#define CATCDSGD_ImproveFixingCircleByCiCiAndCiLnTangency                 CDS_LEVEL(702)

// CDS_15W29
#define CATCDSRR_UseNewEquationForPtPtDiOnCircleDiag                      CDS_LEVEL(703), CDS_HF_LEVEL(451,3)

// CDS_15W30
#define CATCDSSU_FindPivot_SelectHighestAbsoluteValue                     CDS_LEVEL(704)
#define CATCDSSU_FindHeavyRigidSet_UseDistanceToBrokenConstraints         CDS_LEVEL(704)
#define CATCDSSU_FindHeavyRigidSet_SkipBrokenConstraints                  CDS_LEVEL(704)
#define CATCDSSU_ApplyInitialTransformationOnDependences                  CDS_LEVEL(704)
#define CATCDSGS_SimplifyPointLineCoincidenceRedundantConstraints         CDS_LEVEL(704)
#define CATCDSGD_SolveAnalyticallyForLine_PtCoCita                        CDS_LEVEL(704)
#define CATCDSGD_UseSingleForOneBrokenAngleConstraint                     CDS_LEVEL(704)

// CDS15_W31
#define CATCDSGS_ReportDiagnosticOnReplacedDistance                       CDS_LEVEL(705)
#define CATCDSGS_KeepEquationDiagnostics                                  CDS_LEVEL(705)
#define CATCDSGS_ReplaceSingularity_SearchForPtCiImplicitCo               CDS_LEVEL(705)
#define CATCDSGD_MarkUsedConstraintsAsNonRedundant                        CDS_LEVEL(705)
#define CATCDSValidator_TakeWantedDistanceAsRefWhenComputingHPForConics   CDS_LEVEL(705)

// CDS15_W32
#define CATWBx_WBModel_ConvertVarNode                                     CDS_LEVEL(706)
#define CATWBx_WBVariable_UpdateIsVariablesSorted                         CDS_LEVEL(706)

// CDS15_W33
#define CATCDSGS_MirrorReducer_RemoveEqOnlyIfSymmetryExists               CDS_LEVEL(707), CDS_HF_LEVEL(279,17), CDS_HF_LEVEL(522,5)

// CDS_15W35
#define CATCDSSI_InitRSInCATCSNBBox                                       CDS_LEVEL(708)

// CDS_15W36
// current work Pratt & Whitney
#define CATCDSGS_MergeCirclesInnerTangentSameRadius                       CDS_LEVEL(709), CDS_HF_LEVEL(522,2)

#define CATCDS_AddHelpPointsForAddedConstraints                           CDS_LEVEL(709)
#define CATCDSGS_CheckAutoSymmetryForPtLineCoCircleCo                     CDS_LEVEL(709), CDS_HF_LEVEL(279,18)
#define CATCDSModel_AddHelpPointForPointCoincidenceOnly                   CDS_LEVEL(709)
#define CATCDSSI_MapHelpParametersAfterCoordinateModificationOnly         CDS_LEVEL(709)

// CDS_15W38
#define CATCDSPlug_MAEUndoEvaluateIfNotInitiallySatisfied                 CDS_LEVEL(710), CDS_HF_LEVEL(522,3)
#define CATCDSGS_MergeSelfSymmetricCirclesNoCenterPoint                   CDS_LEVEL(710), CDS_HF_LEVEL(279,19)
#define CATCDSGD_LineCiTaCiTa_GetTransformation                           CDS_LEVEL(710), CDS_HF_LEVEL(279,19)
#define CATCDSGD_CheckLineCiTaCiTaImplicitlyFixedCircles                  CDS_LEVEL(710), CDS_HF_LEVEL(451,4), CDS_HF_LEVEL(279,21)
#define CATCDSDC_PostProcessFor_CircleRaLnTaPtCo                          CDS_LEVEL(710), CDS_HF_LEVEL(279,19)
#define CATCDSGD_SolveAnalytically_CircleRaLnTaPtCo                       CDS_LEVEL(710)
#define CATCDSSI_IgnoreChangeChiralityIfFailed                            CDS_LEVEL(710)
#define CATCDSPlug_IgnoreChangeChiralityIfFailed                          CATCDSModificationInactive

// CDS_15W39
#define CATCDSGD_CheckPointLnCoCuDiIfLnPerpToTangent                      CDS_LEVEL(711)
#define CATCDSSU_UseDistanceValueForLineConicHelpPoints                   CDS_LEVEL(711)
#define CATCDSGD_DoNotApplyReturnFixedTransformationOnDependentCurve      CDS_LEVEL(711)
#define CATCDSGD_UpdateDependeeAfterReturnFixed                           CDS_LEVEL(711)

// CDS_15W40
#define CATCDSGS_AddPointToCiCiTangency                                   CDS_LEVEL(712), CDS_HF_LEVEL(710,3), CDS_HF_LEVEL(279,25)
#define CATCDSSU_NewAngleClasses                                          CDS_LEVEL(712)
#define CATCDSGD_DoNotCutOffsetPointOfParallelLines                       CDS_LEVEL(712), CDS_HF_LEVEL(279,21), CDS_HF_LEVEL(710,2)
#define CATCDSGD_SetAlignementInAddConstraint                             CDS_LEVEL(712)
#define CATCDSGS_MirrorReducer_FixLnCoPtDi                                CDS_LEVEL(712)
#define CATCDSPlug_UndoRun                                                CDS_LEVEL(712), CDS_HF_LEVEL(522,4)

// CDS_15W41
#define CATCDSGD_SolveAnalytically_CheckArtPairHeuristic                  CDS_LEVEL(713)

// CDS_15W42
#define CATCDSGS_RemoveSuspiciousTest                                     CDS_LEVEL(714), CDS_HF_LEVEL(522,4)
#define CATCDSGS_ImplyDistancesBetweenPointsDistantFromLine               CDS_LEVEL(714), CDS_HF_LEVEL(522,4)
#define CATCDSGS_ReplaceDoubleBitangentCircles                            CDS_LEVEL(714), CDS_HF_LEVEL(522,4)
#define CATCDSSI_ReverseMoveTransformInTranslateChirality                 CDS_LEVEL(714), CDS_HF_LEVEL(522,4)
#define CATCDSPlug_BetterUndoRun                                          CDS_LEVEL(714), CDS_HF_LEVEL(522,4)
#define CATCDSGD_CheckLine2PtDi1LnPerp                                    CDS_LEVEL(714), CDS_HF_LEVEL(522,4)
#define CATCDSGS_ReplaceWithRadius_FixedPtCiCoPtCiCc                      CDS_LEVEL(714)
#define CATCDSSI_DiagSymPerturbGeom                                       CDS_LEVEL(714), CDS_HF_LEVEL(279,22), CDS_HF_LEVEL(710,2)

// CDS_15W43
#define CATCDSGS_ReduceTransformationOfMergedRigidSets                    CDS_LEVEL(715)

// CDS_15W44
#define CATCDSSU_SetValueAfterConvertTypes                                CDS_LEVEL(716)
#define CATCDSPlug_NewMAEHelpPoints_Rollback                              CDS_LEVEL(716), CDS_HF_LEVEL(522,5)

// CDS_15W46
#define CATCDSGD_CheckPoint2PtDiOnNotParallelAxes                         CDS_LEVEL(717)

// CDS_15W47
#define CATCDSDC_UseSameToleranceAsRR                                     CDS_LEVEL(718), CDS_HF_LEVEL(279,25)
#define CATCDSDC_DoNotModifyComputedDOF                                   CDS_LEVEL(718), CDS_HF_LEVEL(279,25)
#define CATCDSGD_CheckEllipseSingularConfigurations                       CDS_LEVEL(718), CDS_HF_LEVEL(279,25)
#define CATCDSGD_FixCheckLineLineSyDi                                     CDS_LEVEL(718), CDS_HF_LEVEL(279,25)

// CDS_15W48
#define CATCDSSU_UseHelpPointForPointConicCoincidence                     CDS_LEVEL(719)
#define CATCDSSU_UpdatePointConicCoincidenceHelpPoint                     CDS_LEVEL(719)
#define CATCDSGD_NoCuttingPointCoincidentToFixedParallelLinesForDiag      CDS_LEVEL(719), CDS_HF_LEVEL(279,23), CDS_HF_LEVEL(710,2)

// CDS_15W49
#define CATCDSSU_FixedObjectClassesNullDistance                           CDS_LEVEL(720), CDS_HF_LEVEL(710,2)
#define CATCDSGS_KeepNotOverdefinedParallelismSatisfied                   CDS_LEVEL(720)

// CDS_15W50
#define CATCDSSU_FixDulmageMendelsohnDecomposition                        CDS_LEVEL(721)
#define CATCDSGD_ImplyPairedValuesSwapPair                                CDS_LEVEL(721), CDS_HF_LEVEL(279,24)

// CDS_15W51
#define CATCDSGD_MoveRSWithArtPoint                                       CDS_LEVEL(722)
#define CATCDSGD_CheckLineCiTaCiTaDistantCircles                          CDS_LEVEL(722), CDS_HF_LEVEL(451,6)

// CDS_16W01
#define CATCDSGD_PtCoincidentToFixedObjects_SolveAnalyticallyLnCoCiCo     CDS_LEVEL(723), CDS_HF_LEVEL(451,5), CDS_HF_LEVEL(710,9)
#define CATCDSGD_UseSingleForHeuristicGD                                  CDS_LEVEL(723)
#define CATCDSGD_NewUseSingle                                             CDS_LEVEL(723)
#define CATCDSGD_ApplyInverseTransfoFor_LineCiTaCiTa                      CDS_LEVEL(723)
#define CATCDSGD_SolveAnalyticallyAfterUseSingle                          CDS_LEVEL(723)

//  CDS_16W04
#define CATCDSSU_UseAlignmentForMidpointConstraintDOF                     CDS_LEVEL(724)
#define CATCDSRR_DiagnosticMidpointEquation                               CDS_LEVEL(724)
#define CATCDSGS_ExcludeDistanceToAxisFromSymetricSearch                  CDS_LEVEL(724)
#define CATCDSGS_MirrorDetectBiTangentCircleOnAxis                        CDS_LEVEL(724)
#define CATCDSGS_SimplifyCoincidenceConstraintForMidpoints                CDS_LEVEL(724)
#define CATCDSGS_Diag_ReplaceSingularCiCiDiByConcentricity                CDS_LEVEL(724)
#define CATCDSDC_GSUnlinkedVariablesForWelldefined                        CDS_LEVEL(724)
#define CATCDSDC_SelectPerturbedSolutionWhenDOFChange                     CDS_LEVEL(724)
#define CATCDSGD_DisableCheckLine2PtCoForWD                               CDS_LEVEL(724)
#define CATCDSGD_DisableCheckObject2ArgsRigid                             CDS_LEVEL(724)
#define CATCDSSU_VariableClasses                                          CDS_LEVEL(724)

// CDS_16W05
#define CATCDSRR_CheckDOSWhenSeveralObjInRS                               CDS_LEVEL(725)
#define CATCDSSI_KeepOverdefinedOnFixedVariables                          CDS_LEVEL(725)
#define CATCDSGS_SimplifyDistanceBetweenSamePoint                         CDS_LEVEL(725)
#define CATCDSGS_DoNotReorderEquations                                    CDS_LEVEL(725)
#define CATCDSGD_CheckLinePtDiLnAn                                        CDS_LEVEL(725)

// CDS_16W06
#define CATCDSGD_CutUntilLastRS                                           CDS_LEVEL(726)// CATCDSModificationInactive
#define CATCDSIM_FixConicConicAntiTangency2D                              CDS_LEVEL(726)
#define CATCDSGS_DiagReplaceConstraintByEquation                          CDS_LEVEL(726)

// CDS_16W07
#define CATCDSGD_CheckPointCiCoCuDiIfCiCuDiWithSameValue                  CDS_LEVEL(727), CDS_HF_LEVEL(451,7)
#define CATCDSSI_IsInitiallySatisfiedWithEquations                        CDS_LEVEL(727)

// CDS_16W09
#define CATCDSGD_SolveAnaliticallyLineCiTaCiTaLnPa                        CDS_LEVEL(728)
#define CATCDSGD_SolveAnalytically_CiCoCiCo_Ta_FixAndLockSolution         CDS_LEVEL(728)
#define CATCDSGD_CiTaPtCo_Co                                              CDS_LEVEL(728)

// CDS_16W11
#define CATCDSGS_FixRerouteOrientations                                   CDS_LEVEL(729), CDS_HF_LEVEL(252,2)

// CDS_16W14
#define CATCDSGD_PlaneCase_ctLine_2LnCo2PtCo                              CDS_LEVEL(730)
#define CATCDSGD_CutCiWithRaTanTo2Line                                    CDS_LEVEL(730)

// CDS_16W18
#define CATCDSGD_ConsiderMoveConstraintsAsBroken                          CDS_LEVEL(731)

// CDS_16W19
#define CATCDSGD_CheckPointLnCoCiCoIfDistantLineThroughConcentricCircle   CDS_LEVEL(732), CDS_HF_LEVEL(451,8)

// CDS_16W20
#define CATCDSGD_PointCiCoLnDiCorrector                                   CDS_LEVEL(733), CDS_HF_LEVEL(451,8)
#define CATCDSSU_GetInitialCoords                                         CDS_LEVEL(733), CDS_HF_LEVEL(451,8), CDS_HF_LEVEL(710,7)

// CDS_16W23
#define CATCDSModel_SoftFixedCuSu                                         CDS_LEVEL(734)
#define CATCDSPlug_FirstReevaluateWithPreevaluate_UpdateModel             CDS_LEVEL(734), CDS_HF_LEVEL(710,4)

// CDS_16W25
#define CATWBx_UnaryOp_AbsDiff                                            CDS_LEVEL(735)
#define CATWBx_AlgebraicOp_MinMaxDiff                                     CDS_LEVEL(735)
#define CATWBx_UnaryOp_RoundingFuncDiff                                   CDS_LEVEL(735)
#define CATWBx_BinaryOp_PowerDiff                                         CDS_LEVEL(735)
#define CATCDSSI_SolveGeometryDimensionalConstraintsWithDichotomy         CDS_LEVEL(735), CDS_HF_LEVEL(710,5)

// CDS_16W26
#define CATCDSGD_NoSolveAnalyticallyForFirstGeometry                      CDS_LEVEL(736)

// CDS_16W27
#define CATCDSModel_SaveParametersAfterReadParameters                     CDS_LEVEL(737)

// CDS_16W29
#define CATCDSSU_NewLineIntersections                                     CDS_LEVEL(738)
#define CATCDSSI_UpdateSpecifiedOnHelpPointsWhenInitialized               CDS_LEVEL(738), CDS_HF_LEVEL(710,7)
#define CATCDSSU_UseGetHelpPointForNotSpecifiedHelpPoints                 CDS_LEVEL(738), CDS_HF_LEVEL(710,7)
#define CATCDSIM_SetUnitVectorForLineCircleTangency2D                     CDS_LEVEL(738)
#define CATCDSGDHeuristic_ApplyTransformationsOnContraintHelpPoints       CDS_LEVEL(738)
#define CATCDSRR_UsePointCircleCoincidentHPForSpecifiedHPOnly             CDS_LEVEL(738), CDS_HF_LEVEL(710,7)
#define CATCDSSU_UseDistanceForComputingConicHelpPoints                   CDS_LEVEL(738), CDS_HF_LEVEL(710,7)
#define CATCDSSU_UseGenericGetHeltPointsForCircleCircleTangency           CDS_LEVEL(738), CDS_HF_LEVEL(710,7)
#define CATCDSSU_SimpleComputationForCircleHelpPoints                     CDS_LEVEL(738), CDS_HF_LEVEL(710,7)
#define CATCDSGS_ComputeAlignmentFromOrientationsIfPossible               CDS_LEVEL(738)
#define CATCDSSU_UseOrientationsForHelpPointComputation                   CDS_LEVEL(738), CDS_HF_LEVEL(710,7)
#define CATCDSGD_SoftDecomposition_HelpPointManagement                    CATCDSModificationInactive


// CDS16_W34
//#define CATCDSModel_Is2DRigidSet                                          CDS_LEVEL(739)

// CDS16_W35
#define CATCDSGS_MirrorReverseIterateToReportDiag                         CDS_LEVEL(740), CDS_HF_LEVEL(710,6)

// CDS16_W37
#define CATCDSGD_CheckPointsLnCoMiDi_AddCoincidenceConstraint             CDS_LEVEL(741)

// CDS16_W38
#define CATCDSSI_ProcessGeometryByAverageMove                             CDS_LEVEL(742), CDS_HF_LEVEL(710,7)
#define CATCDSHR_DOFRigidificationUpdateDependee                          CDS_LEVEL(742), CDS_HF_LEVEL(710,7)

// CDS16_W39
#define CATCDSGS_UpdateParameterInReviseOffsetCurvesDependencies          CDS_LEVEL(743), CDS_HF_LEVEL(710,4), CDS_HF_LEVEL(741,1)

// CDS16_W40
#define CATWBx_Perfo_EvalBuffer                                           CDS_LEVEL(744)

// CDS16_W42
#define CATCDSSI_ProcessGeometryWithFixedRigidSetsCheckLnCiPtTa           CDS_LEVEL(745), CDS_HF_LEVEL(710,8)

// CDS_16W45
#define CATCDSGD_GetCurrentTransformation                                 CDS_LEVEL(746), CDS_HF_LEVEL(710,9)
#define CATCDSGD_GetTransformation_MovedMovingTransfoFirst                CDS_LEVEL(746), CDS_HF_LEVEL(710,9)
#define CATCDSGD_CheckPointObjsCoIfObjectsIntersect_SolveAnalitically     CDS_LEVEL(746), CDS_HF_LEVEL(710,9)
#define CATCDSGD_SolveAnalitically_GetTransformation                      CDS_LEVEL(746), CDS_HF_LEVEL(710,9)

// CDS_16W46
#define CATCDSGS_MergePointCoincidentToTwoLineInSameRS                    CDS_LEVEL(747)

// CDS_16W47
#define CATCDSGD_CircleTgTo2CirclesCorrector                              CDS_LEVEL(748)
#define CATCDSGD_CircleTgToCircleAndLineCorrector_Translation             CDS_LEVEL(748)

// CDS_16W49
#define CATCDSSI_ProcessGeometryByAverageMove_AverageTransformation       CDS_LEVEL(749)
#define CATCDSSU_FixCircleHelpPointsInstability                           CDS_LEVEL(749)

// CDS_16W50
#define CATCDSSI_HideDegenerateSequencesInProfiles                        CDS_LEVEL(750)
#define CATCDSSI_SetActualLimitsForDependentCurvesWithDiscontinuities     CDS_LEVEL(750), CDS_HF_LEVEL(710,4), CDS_HF_LEVEL(741,1)

// CDS_17W05
#define CATCDSSI_ForceAccurateSolve                                       CDS_LEVEL(751)

// CDS_17W10
#define CATCDSGD_UseNbOfConstraintsForPrioriryQueue                       CDS_LEVEL(752)
#define CATCDSGD_UpdateHPInPtLineCircleSolveAnalytic                      CDS_LEVEL(752)

// CDS17W12
#define CATCDSGS_FixSketcherSplineBugInReplaceSingularity                 CDS_LEVEL(753)
#define CATCDSGS_MergeCoincidentCurvesInsideRigidSet                      CDS_LEVEL(753)
#define CATCDSSI_RRAsBackupForSmallVariableAngles                         CDS_LEVEL(753)
#define CATCDSES_UseSimplexForDomainCorrection                            CDS_LEVEL(753)
#define CATCDSGU_NoRoundOnRotations                                       CATCDSModificationInactive
#define CATCDSIM_UseSketchNormalRatherThanNormalizedNullVectorialProduct  CDS_LEVEL(753)
#define CATCDSGS_RemoveSingularity_DoNotBreakLoopWhenNoMergeOccured       CDS_LEVEL(753)
#define CATCDSGD_FixResolutionByDomainForDiscontinuities                  CDS_LEVEL(753)
#define CATCDSGD_ManageRotationForEllipseReconstruction                   CDS_LEVEL(753)
#define CATCDSGS_DetectMidpointImpliedSymmetries                          CDS_LEVEL(753)

// CDS17W14
#define CATCDSGS_SetAlignmentOnAddedCoincidence                           CDS_LEVEL(754)

// CDS_17W20
#define CATWBx_Differentiate_Architecture                                 CDS_LEVEL(755)

// CDS_17W21
#define CATCDSGS_ReplaceByAntitangency_FixTangencyParameter               CDS_LEVEL(756), CDS_HF_LEVEL(710,11)

// for compatibility with R25SP4 (first level : 710 hf3)
#define CATCDSGS_ReplaceByAntitangencyBeforeBugFix                        CDS_HF_LEVEL(710,3)
#define CATCDSGS_ReplaceByAntitangencyBugFix                              CDS_HF_LEVEL(710,10)

// CDS_17W23
#define CATWBx_Differentiate_NoAssert                                     CDS_LEVEL(757)
#define CATCDSES_UseVariableToleranceInCorrectGuessInDomainsWithSimplex   CATCDSModificationInactive

// CDS_17W25
#define CATCDSPlug_InitVariablesInPreevaluate                             CDS_LEVEL(758)

// CDS_17W26
#define CATCDSSU_ComputeAngleClassesDimensional                           CDS_LEVEL(759)
#define CATCDSGS_MirrorReducer_CircleSymmetryImpliedByLineTangencies      CDS_LEVEL(759)

// CDS_17W28
#define CATCDSGS_ReplaceByAntitangency_DependentCurveImplicitCoincidence  CDS_LEVEL(760), CDS_HF_LEVEL(710,12)

// CDS_17W36
#define CATWBx_Simplify_BlackBox                                          CDS_LEVEL(761)
#define CATWBx_Simplify_Trig                                              CDS_LEVEL(761)
#define CATCDSGS_SetUpdateDependeeCallback                                CDS_LEVEL(761), CDS_HF_LEVEL(710,13)
#define CATCDSGS_CheckPointCurveCoincidence_MoveAnchors                   CDS_LEVEL(761), CDS_HF_LEVEL(710,13)

// CDS_17W37
#define CATCDSGS_SimplifyRedundentRadiusEquations                         CDS_LEVEL(762)

// CDS_17W39
#define CATCDSModel_TriangleChiralityPointOnCircle                        CDS_LEVEL(763), CDS_HF_LEVEL(733,2)

// CDS_17W45
#define CATCDSSI_SolveWithVariableFixedUnsatisifedEquations               CDS_LEVEL(764)

// CDS_17W49
#define CATCDSPlug_MUCFixWDGeometries                                     CDS_LEVEL(765)
#define CATCDSGS_ComputeNormalOnRightCurveInIsOffsetMethod                CDS_LEVEL(765), CDS_HF_LEVEL(710,14), CDS_HF_LEVEL(762,1)

// CDS_18w09
#define CATCDSGD_ctCircle_CiTaPtCo_Co_SolveAnalitically                   CDS_LEVEL(766)

// CDS_18W11
#define CATCDSGD_CheckWDCuttingLevels                                     CDS_LEVEL(767), CDS_HF_LEVEL(762,2)
#define CATCDSSU_GeneralizedDistanceNoMaxCapacity                         CDS_LEVEL(767), CDS_HF_LEVEL(762,2)
#define CATCDSGD_RemoveWDCuttingLevels2                                   CDS_LEVEL(767), CDS_HF_LEVEL(762,2)

// CDS_18W14
#define CATCDSPlug2D_halfSpaceUpdate                                      CDS_LEVEL(768), CDS_HF_LEVEL(762,3), CDS_HF_LEVEL(762,4)
#define CATCDSRR_ScaleInDependencesEvalExpressions                        CDS_LEVEL(768)

// CDS_18W22
#define CATCDSGS_CorrectConstraintAlignmentBugFix                         CDS_LEVEL(769)

// CDS_18W23
#define CATCDSGS_FixRemoveRedundantConstraintsBugs2                       CDS_LEVEL(770)

// CDS_18W24
#define CATCDSBB_DiscontOnLinearSegment                                   CDS_LEVEL(771), CDS_HF_LEVEL(733,3)

// CDS_18W25
#define CATWBx_Converter_CkeBlackBox                                      CDS_LEVEL(772)

// CDS_18W26
#define CATCDSGD_CheckObjectConstraintsIfSubsetForOverdefined             CDS_LEVEL(773), CDS_HF_LEVEL(765,1)

// CDS_18W27
#define CATCDSSI_GlobalMove_SatisfiedInputGeometry                        CDS_LEVEL(774), CDS_HF_LEVEL(771,1)

// CDS_18W28
#define CATWBx_Simplify_UnrollNAry_IfThenElse                             CDS_LEVEL(775)

//CDS_18W29
#define CATCDSSI_SolveChiralityFirst                                      CDS_LEVEL(776)
#define CATCDSValidator_PlPlCoAlign                                       CDS_LEVEL(776)
#define CATCDSDiscrepancy_ValidateUserAlignement                          CDS_LEVEL(776)
#define CATCDSGeomConstraint_GetUserAlign                                 CDS_LEVEL(776)
#define CATCDSSI_TranslateChiralityInEvaldDiscr                           CDS_LEVEL(776)
#define CATCDSSI_OneMovingVariableComponent                               CDS_LEVEL(776)
#define CATCDSGD_CheckPointOnCircleAndLineForOverdefined                  CDS_LEVEL(776)

//CDS_18W30
#define CATWBx_WBModel_GetVarNode                                         CDS_LEVEL(777)

//CDS_18W35
#define CATCSNGeometry_PureTranslationInSetMoveTransformation             CDS_LEVEL(778)
#define CATCDSPlug_ResetHisrtory                                          CDS_LEVEL(778)
#define CATCDSPlug_NotOverwriteVariableInPreevaluate                      CDS_LEVEL(778)

// CDS_18W37
#define CATCDSSU_IdxInCorrectors                                          CDS_LEVEL(779)
#define CATCDSIM_PlanarAngleModelisationSmallCosAngle                     CDS_LEVEL(779), CDS_HF_LEVEL(762,4)

// CDS_18W38
#define CATWBx_Simplify_PlusMinus                                         CDS_LEVEL(780)
#define CATWBx_Simplify_TrigAngles                                        CDS_LEVEL(780)
#define CATWBx_Simplify_SumOfConstants                                    CDS_LEVEL(780)

// CDS_18W39
#define CATCDSGD_RemoveCheckPoint2LnCoCiCo                                CDS_LEVEL(781), CDS_HF_LEVEL(777,2)

// CDS_18W40
#define CATCDSGeometry_IsDimensionalConstraint                            CDS_LEVEL(782)
#define CATCDSGS_SpecifiedLengthInEquation                                CDS_LEVEL(782)

// CDS_18W41
#define CATCDSRR_DependencesInitTransformation                            CDS_LEVEL(783)

// CDS_18W44
#define CATWBx_Simplify_CreateTrigOrConstant                              CDS_LEVEL(784)
#define CATWBx_Printer_Fractions                                          CDS_LEVEL(784)

// CDS_18W45
#define CATCDSValidator_PointPointCircleDistance_WrongToleance            CDS_LEVEL(785), CDS_HF_LEVEL(762,3), CDS_HF_LEVEL(710,15)

// CDS_18W46
#define CATCDSGS_offsetRegenerateKO                                       CDS_LEVEL(786)

// CDS_18W48
#define CATCDSGeometry_UpdateHPForLiCiAt                                  CDS_LEVEL(787), CDS_HF_LEVEL(779, 1)
#define CATCSNConstraint_InitializeMandatoryHP                            CDS_LEVEL(787), CDS_HF_LEVEL(779, 1)

// CDS_18W50
#define CATWBx_Printer_MinusOne                                           CDS_LEVEL(788)
#define CATWBx_Simplify_RemoveRedundantVariables                          CDS_LEVEL(788)

// unactive variables
#define HPMustBeSpecified                                                 CATCDSModificationInactive
#define CATCDSGS_MirrorReducer_FindImplicitAxes                           CATCDSModificationInactive
#define CATWBx_Converter_CkeRule                                          CATCDSModificationInactive
#define CATCDSGD_ReconvergeHelpParamInMoveToNextGeometry                  CATCDSModificationInactive

// CDS_19W08
#define CATWBx_Simplify_UseCommonFactors                                  CDS_LEVEL(789)
#define CATWBx_Simplify_ReduceASinTwoPlusBSinCos                          CDS_LEVEL(789)

// CDS_19W10
#define CATCDSValidator_ValidateCanonicalSurfaceCurveCo                   CDS_LEVEL(790)
#define CATCDSBlackBox_DependentCurveOnMovingSketch                       CDS_LEVEL(790)

// CDS_19W14
#define CATCDSGD_SolveAnalyticallyRotationAroundIntersectionPoint         CDS_LEVEL(791)

// CDS_19W19
#define CATCDSGD_ConstraintMapping_UseArtPointGeometry                    CDS_LEVEL(792)

// CDS_19W20
#define CATWBx_Converter_Units                                            CDS_LEVEL(793)
#define CATWBx_Converter_CkeBBx_Law                                       CDS_LEVEL(793)
#define CATWBx_Converter_IfNoElse                                         CDS_LEVEL(793)

// CDS_19W22
#define CATCDSGS_MirrorReducer_NoMidSegmentCoincidenceSimplification      CDS_LEVEL(794)
#define CATCDSGD_NoPointCutOnCoincidentCircles                            CDS_LEVEL(794)

// CDS_19W27
#define CATCDSSI_initTargetValueForPostSolvingWithRR                      CDS_LEVEL(796), CDS_HF_LEVEL(777,1)
#define CATCDSGD_CheckCircle3PtCo                                         CDS_LEVEL(796)
#define CATCDSGD_CheckCcPt3FixedPtsCircle                                 CDS_LEVEL(796)

// CDS_19W28
#define CATCDSGD_CheckLine2CiTa1LnPa_UpdateVariableClasses                CDS_LEVEL(797)

// CDS_19W31
#define CATCDSGD_RadiusCorrector                                          CDS_LEVEL(798), CDS_HF_LEVEL(751,1), CDS_HF_LEVEL(779,2), CDS_HF_LEVEL(798,1)

// CDS_19W39
#define CATWBx_Integrate_MinMax                                           CDS_LEVEL(799)
#define CATWBx_Differentiate_Sign                                         CDS_LEVEL(799)
#define CATWBx_Differentiate_MinMax                                       CDS_LEVEL(799)
#define CATWBx_Differentiate_Abs                                          CDS_LEVEL(799)
#define CATWBx_Indefinite_Functions                                       CDS_LEVEL(799)
#define CATWBx_Expression_PartialEval                                     CDS_LEVEL(799)
#define CATWBx_Function_Pow                                               CDS_LEVEL(799)
#define CATWBx_Function_Round3                                            CDS_LEVEL(799)

// CDS_19W40
#define CATCDSReduceTransfo_SingleReduceTransfo                           CDS_LEVEL(800)
#define CATCDSGS_SubGeometryRSMapping                                     CDS_LEVEL(800), CDS_HF_LEVEL(796,1)
#define CATCDSGD_CheckPointsLnCoMiDi_CheckSecondPointCoincidence          CDS_LEVEL(800)
#define CATWBx_Simplify_UnaryMinus                                        CDS_LEVEL(800)

// CDS_19W41
#define CATWBx_Converter_String                                           CDS_LEVEL(801)
#define CATWBx_Simplify_GetVarFromExpr                                    CDS_LEVEL(801)
#define CATWBx_Printer_OrderVariables                                     CDS_LEVEL(801)
#define CATWBx_Factory_CloneStep                                          CDS_LEVEL(801)
#define CATCDS_UpdateParametersDependentCurves                            CDS_LEVEL(801), CDS_HF_LEVEL(796,2)

// CDS_19W47
#define CATWBx_Simplify_ProductsWithPowers                                CDS_LEVEL(803)
#define CATWBx_Factory_PredefinedConstants                                CDS_LEVEL(803)
#define CATWBx_Converter_CkeBBx_Law2                                      CDS_LEVEL(803)
#define CATWBx_Simplify_OddAndEvenFunctions                               CDS_LEVEL(803)

// CDS_19W49
#define CATWBx_Value_FractionType                                         CDS_LEVEL(804)
#define CATCDS_DependentCurvesManagement                                  CDS_LEVEL(804), CDS_HF_LEVEL(796,3)
#define CATWBx_Differentiate_Power                                        CDS_LEVEL(804)

// CDS_20W03
#define CATWBx_Simplify_SinCosSum                                         CDS_LEVEL(805)
#define CATWBx_Simplify_ExtendASin2PlusBCos2                              CDS_LEVEL(805)

// CDS_20W05
#define CATWBx_Simplify_Restructure                                       CDS_LEVEL(806)

// CDS_20W06
#define CATWBx_Simplify_ProductCosTan                                     CDS_LEVEL(807)

// CDS_20W10
#define CATWBx_Printer_PowerWithConstBase                                 CDS_LEVEL(808)
#define CATWBx_Simplify_MoveSinMultCosToPost                              CATCDSModificationInactive
#define CATWBx_Simplify_PostSinCosMult                                    CDS_LEVEL(808)

// CDS_20W11
#define CATCDSGD_VariableClassesInit                                      CDS_LEVEL(809), CDS_HF_LEVEL(805,1), CDS_HF_LEVEL(796,4)
#define CATCDSValidator_TernaryTangencyHelpPoints                         CDS_LEVEL(809)

// CDS_20W13
#define CATCDSDC_RSWithFreeObjectNotWDByArguments                         CDS_LEVEL(810), CDS_HF_LEVEL(777,3)

// CDS_20W15
#define CATCDSValidator_AlignmentOnConicsSymmetry2D                       CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSSU_UpdateAntiTangencyHP                                     CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSSU_AngleClassesForConics2D                                  CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_CheckSupportLinePerpendicularityForMidpointMirror        CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_MirrorReducer_CheckNonParallelLines                      CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_MirrorReducer_ChooseMirrorOrderAndSides                  CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_MirrorReducer_ReplaceAngleConstraints                    CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_Mirror_SimplifyTernaryConstraints                        CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_MirrorReducer_CreateConstraintOnRefSide                  CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_MirrorReducer_SimplifyRedundantCircleCenterSelfSymmetry  CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_MirrorReducer_UseSelfSymmetryAlignments                  CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_MirrorReducer_DoNotReplaceSimplifiedSelfSymmetries       CDS_LEVEL(811), CDS_HF_LEVEL(805,2)
#define CATCDSGS_Mirror_MultiMirrorDetection                              CDS_LEVEL(811), CDS_HF_LEVEL(805,2)

// CDS_20W17
#define CATCDSGS_NURBSCurvature                                           CDS_LEVEL(812), CDS_HF_LEVEL(797,2), CDS_HF_LEVEL(805,1)
#define CATCDSGS_MergeInsideRigidSetCummulativeError                      CDS_LEVEL(812)
#define CATCDSGS_CompareObjectsErrorValues                                CDS_LEVEL(812)

// CDS_20W18
#define CATCDSGS_SubGeometryRSMappingWDRestriction                        CDS_LEVEL(813)

// CDS_20W20
#define CATCDSModel_PropagateFixedRS                                      CDS_LEVEL(814), CDS_HF_LEVEL(796,5)

// CDS_20W23
#define CATCDSPlug_Preevaluate_VariableAbsoluteValue                      CDS_LEVEL(815), CDS_HF_LEVEL(805,3), CDS_HF_LEVEL(797,3)

// CDS_20W24
#define CATCDSSI_ConstraintRedundancy_FixedVariables                       CDS_LEVEL(816), CDS_HF_LEVEL(777,4)
#define CATCDSDC_ConstraintRedundancy_KeepPartiallyRedundantCstr           CDS_LEVEL(816), CDS_HF_LEVEL(777,4)

//CDS_20W30
#define CATCDSGS_PatternReduce_SubstituteVariables                         CDS_LEVEL(817)

//CDS_20W36
#define CATCDSSI_CheckMovingVarDirectionAfterIMPostSolving                 CDS_LEVEL(818), CDS_HF_LEVEL(796,6)

//CDS_20W49
#define CATCDSSI_ResetChangeChirality                                      CDS_LEVEL(819), CDS_HF_LEVEL(797,4), CDS_HF_LEVEL(805,4), CDS_HF_LEVEL(794,2)

// CDS_20W51
#define CATCDSPlug_UndoAndRigidSets                                        CDS_LEVEL(820)

// CDS_21W03
#define CATCDSModel_TangencyOnGeneratrixNullAngle                          CDS_LEVEL(821), CDS_HF_LEVEL(777,5)

// CDS_21W05
#define CATCDSGS_MirrorReducer_UseCoefInMirrorOrderingMinimizer            CDS_LEVEL(822), CDS_HF_LEVEL(805,5)
#define CATCDSGS_TCReducer_ReplaceArcCstrByAngleOnTSCST                    CDS_LEVEL(822)
#define CATCDSSI_ConvergeAfterMUCDependsOnDiscr                            CDS_LEVEL(822)
#define CATCDSPlug_ChangeRefLinTolDependsOnLinTol                          CDS_LEVEL(822)

// CDS_21W11
#define CATCDSSI_CheckAverageDirInEvalTransform                            CDS_LEVEL(823), CDS_HF_LEVEL(797,5), CDS_HF_LEVEL(805,6)

// CDS_21W12
#define CATCDSGD_PointCircleCircleCorrector                                CDS_LEVEL(824), CDS_HF_LEVEL(805,4)
#define CATCDSGD_PointCircleCircleSolveAnalitically                        CDS_LEVEL(824), CDS_HF_LEVEL(805,4)

// CDS_21W13
#define CATCDSModel_MapParameterToInternalLimits                           CDS_LEVEL(825)
#define CATCDSSI_CheckMovingVarValueAfterPostSolving                       CDS_LEVEL(825), CDS_HF_LEVEL(777, 6), CDS_HF_LEVEL(796,7), CDS_HF_LEVEL(805,2)

// CDS_21W20
#define CATCDSGS_TC_TSCST_FreeRad                                          CDS_LEVEL(826)

// CDS_21W23
#define CATCDSGS_TC_TSCSC_FreeRad                                          CDS_LEVEL(827)

// CDS_21W25
#define CATCDSSI_KeepDOPRIResultForDepCu                                   CDS_LEVEL(828), CDS_HF_LEVEL(827, 1)

//CDS_21W26
#define CATCDSGD_SoftDecompositionCleanGeometry                            CDS_LEVEL(829)

//CDS_21W34
#define CATWBx_Expression_SegmentFunctionBuffer                            CDS_LEVEL(830)

//CDS_21W36
#define CATCDSGS_RigidTCDuringDiag                                         CDS_LEVEL(831)
#define CATCDSGMInfra_CacheForRegenerate                                   CDS_LEVEL(831)

// CDS_21W39
#define CATCDSValidator_AngularValueForCurveDistances                      CDS_LEVEL(832)
#define CATCDSSU_CheckCollapsedMidpoints                                   CDS_LEVEL(832)

// CDS_21W46
#define CATWBx_Converter_Floor                                             CDS_LEVEL(833)
#define CATCDS_TC_EvaluateLength                                           CDS_LEVEL(833)

// CDS_22W02
#define CATCDSGS_RedundantConstraintsColinearAngleFix                      CDS_LEVEL(834)

// CDS_22W03
#define CATCDSGD_CheckBunchOfLinesFixedRS                                  CDS_LEVEL(835)

// CDS_22W10
#define CATCDSGS_ReplaceApexAngleInIsoscelesTriangle                       CDS_LEVEL(836), CDS_HF_LEVEL(835, 1)

// CDS_22W13
#define CATCDSGD_FreeRadCircleTCDiag                                       CDS_LEVEL(837)
#define CATCDSDC_DeactivateMoveAnchor                                      CDS_LEVEL(837)
#define CATCDSSI_MoveParamToBoundsInMapParameterBBox                       CDS_LEVEL(837)
#define CATCDSSI_UpdateDependeeWhenFailedRRAfterMUC                        CDS_LEVEL(837)
#define CATCDSGS_ReplaceApexAngleInIsoscelesTriangle_fixed                 CDS_LEVEL(837)

// CDS_22W19
#define CATCDSNURBS_RationalLengthComputation                              CDS_LEVEL(838)

// CDS_22W20
#define CATCDSGS_MirrorReducer_MirrorOrderingMinimizerNbOperationLimit     CDS_LEVEL(839)
#define CATCDSGS_CutStartCoincidenceOnPointLineParamsTC                    CDS_LEVEL(839)

// CDS_22W28
#define CATCDSGS_RigidTCDuringDiag2                                        CDS_LEVEL(840), CDS_HF_LEVEL(839,1)
#define CATCDSGS_PerfoOptimSatisfiedPatterns                               CDS_LEVEL(840)

// CDS_22W30
#define CATWBx_Converter_CkeBBx_Int                                        CDS_LEVEL(841)
#define CATWBx_Converter_InvHyp                                            CDS_LEVEL(841)
#define CATWBx_Converter_Ceil                                              CDS_LEVEL(841)
#define CATWBx_Converter_Ternary                                           CDS_LEVEL(841)

// CDS_22W39
#define CATCDSGS_RedundantConstraintFixBug                                 CDS_LEVEL(842)

// CDS_22W41
#define CATCDSGD_ConstraintsSubsetCheckGenericCo                           CDS_LEVEL(843)

// CDS_22W42
#define CATWBx_Solver_MigrateVersioning                                    CDS_LEVEL(844)
#define CATWBx_Expression_ExprValue                                        CDS_LEVEL(844)

// CDS_22W47
#define CATCDSGS_AddImplicitCoincidenceForRadii_CheckNullRadius            CDS_LEVEL(845), CDS_HF_LEVEL(839,3), CDS_HF_LEVEL(827,1)
#define CATCDSGS_AddImplicitCoincidenceForRadiiAfterReplaceWithRadius      CDS_LEVEL(845), CDS_HF_LEVEL(839,3), CDS_HF_LEVEL(827,1)

// CDS_22W48
#define CATCDSCorrector_SignatureChange                                    CDS_LEVEL(846), CDS_HF_LEVEL(827,2), CDS_HF_LEVEL(839,4), CDS_HF_LEVEL(779,3)
#define CATCDSCorrector_ForceCorrector                                     CDS_LEVEL(846), CDS_HF_LEVEL(827,2), CDS_HF_LEVEL(839,4), CDS_HF_LEVEL(779,3)
#define CATCDSCorrector_PointCiCoPtDiCorrector                             CDS_LEVEL(846), CDS_HF_LEVEL(827,2), CDS_HF_LEVEL(839,4), CDS_HF_LEVEL(779,3)

// CDS_23W01
#define CATCDSGD_CorrectorUilities_DoNotUsePoint                           CDS_LEVEL(847), CDS_HF_LEVEL(827,2), CDS_HF_LEVEL(839,4), CDS_HF_LEVEL(779,3)
#define CATCDSPlug_MAECheckSatisfiedSketch                                 CATCDSModificationInactive

// CDS_23W04
#define CATCDSPlug2D_HalfSpaceLimitedToTheFirstTwoArguments                CDS_LEVEL(848)

// CDS_23W05
#define CATCDSSI_AcceptPostRRAfterMUCIfBetterDiscrthanInput                CDS_LEVEL(849)
#define CATCDSEG_DoNotSetToleranceTo0ForCurveParameter                     CDS_LEVEL(849)
#define CATCDSGS_TC_ProcessReverseSpiralCurve                              CDS_LEVEL(849)

// CDS_23W06
#define CATCDSGD_CheckLine2Co2PerpLinesRestriction                         CDS_LEVEL(850)

// CDS_23W07
#define CATCDSGD_CirclePtCoCiTaCorrector                                   CDS_LEVEL(851)
#define CATCDSGD_CircleTgTo2CirclesCorrector_GetInitialCoords              CATCDSModificationInactive
#define CATCDSGD_PointCiCoPtDiCorrector_CheckDiscrepancy                   CDS_LEVEL(851)
#define CATCDSGD_CheckCircle2CiTaOrPtCo_AntialignTangencies                CDS_LEVEL(851)

// CDS_23W13
#define CATCDSGS_ProcessFixTC                                              CDS_LEVEL(852)
#define CATCDSSU_FixedObjClassesDirectedDistance                           CDS_LEVEL(852)
