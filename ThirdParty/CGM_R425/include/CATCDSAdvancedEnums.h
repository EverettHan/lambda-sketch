// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATCDSEnums.h
// Header definition of CATCDSEnums
//
//===================================================================
//
// Usage notes:
//  These values are used as result of
//  CATConstraintSolver::GetStatus() methods.
//
//===================================================================
//
//  Sep 2002  Creation:                Evgueni ROUKOLEEV
//===================================================================

#ifndef CATCDSAdvancedEnums_H
#define CATCDSAdvancedEnums_H

#define MAX_OBJECT_VARIABLES 2

#ifndef CDS_NOTYPES_DEF
#define CDS_NOTYPES_DEF
#include "CATICDSEnums.h"
#undef CDS_NOTYPES_DEF
#else
#include "CATICDSEnums.h"
#endif

#include "CATCDSBoolean.h"

#include "CATCDS.h"

class CATCSGeometryLeaf;

#ifndef CDS_NOTYPES_DEF
#ifndef CDS_TYPES
#define CDS_TYPES
/* Entity types */
enum CATCDSType
{
/** Public types (see CATICDSEnums.h) **/
  DECL_CDSTypes,

/** Protected types **/
/* Geometries */
  tpMONOPARAMETRIC,
  tpPARAMETRICCURVE2D,
  tpBEZIERCURVE2D,
  tpPARABOLICCURVE2D,
  tpEQUATIONCURVE2D,
  tpSTREAMCURVE2D,
  tpCONTROLEDCURVE,
  tpCONTROLEDCURVE2D,
  tpNURBSCONICARC2D,
  tpLINESEGMENTCURVE2D,
  tpCIRCLEARCCURVE2D,
  tpELLIPSEARCCURVE2D,
  tpPARABOLAARCCURVE2D,
  tpHYPERBOLAARCCURVE2D,
  tpCIRLINEARCCURVE2D,
  tpCURVESEGMENTCURVE2D,
  tpCOMPOSITECURVE2D,
  tpPROFILE2D,
  tpTRANSITIONCURVE2D,
  tpEXTERNALTRANSITIONCURVE2D,
  tpEXTERNALOFFSETCURVE2D,
  tpPARAMETRICCURVE,
  tpBEZIERCURVE,
  tpEQUATIONCURVE,
  tpCGMCURVE,
  tpOFFSETCURVE2D,
  tpOFFSETELLIPSE2D,
  tpOFFSETPARABOLA2D,
  tpOFFSETHYPERBOLA2D,
  tpCONNECTCURVE2D,
  tpALGEBRAICCURVE,
  tpALGEBRAICCURVE2D,
  tpSURFACE,
  tpALGEBRAICSURFACE,
  tpPARAMETRICSURFACE,
  tpBEZIERSURFACE,
  tpEQUATIONSURFACE,
  tpCGMSURFACE,
  tpCONTROLEDSURFACE,
  tpCYLICONE,
  tpCIRLINE,
  tpCIRLINE2D,
  tpSKIN,
  tpPARSERSKIN,
  tpPARSERSKINPARAM,
  tpMULTICURVE,
/* Constraints */
  tpDEPENDENCE, /*deprecated*/ 
  tpOFFSETCONSTRAINT,
  tpCOTANGENCY,
/* Axis */
  tpAXIS2D,
/* Joints */
  tpSIMPLEJOINT,
  tpCABLE,
  tpGEAR,
  tpRACK,
  tpRIGID,
  tpSCREW,
  tpCV,
  tpSLIDECURVE,
  tpPOINTCURVE,
  tpPOINTSURFACE,
  tpCOINCIDENT,
  tpSYMMETRIC,
  tpSYMMETRICIJ,
  tpSYMMETRICJK,
  tpSYMMETRICKI,
  tpSIMPLEJOINT2D,
  tpREVOLUTE2D,
  tpPRISMATIC2D,
  tpRIGID2D,
  tpFULLDOF2D,
  tpPOINTCURVE2D,
  tpSLIDECURVE2D,
/* Equation */
  tpEQUATION,
  tpWBEQUATION,
  tpPARSEREQUATION,
/* Pattern */
  tpFULLPATTERN2D,
/* Sketch */       
  tpSKETCH
};

/** Geometry status. */
enum CATCDSGStatus
{
  DECL_CDSGStatus,
  gsNOTCHANGED // not used
};

enum CATCSTransitionCurveType 
{
  DECL_CDSTransitionCurve
};

/** Diagnostic mode */
enum CATCDSDiagMode
{
  DECL_CDSDiagMode,
  /** Solve antagonisms (according to priorities). */
  dmHEAL,
  dmOLDALWAYS
};

/* Constraint status */
enum CATCDSStatus
{
  DECL_CDSStatus,
  csNOTCHANGED, // not used
  csSOLVED,     // not used
  csNOTSOLVED,  // not used
  csSOFT,
  csIGNORED // ignored by priority technology
};

/* Move mode */
enum CATCDSMoveMode
{
  DECL_CDSMoveMode,
  /** Similar to the standard mode but the solver will apply a perturbation
   *  technique before solving to overcome singularities in the initial configuration. */
  // Deprecated, use mmSTANDARD or mmMINIMUM_MOVE and option SetPerturbationMove(TRUE)
  mmPERTURBATION,
  /** Similar to the minimum mode mode but the solver will try to reach
   *  required movements exactly that can take more time. */
  // Deprecated, use mmSTANDARD or mmMINIMUM_MOVE and option SetAccurateMove(TRUE)
  mmACCURATE_MOVE
};

/* Update mode */
enum CATCDSUpdateMode
{
  DECL_CDSUpdateMode,
  /** Similar to the reevaluate mode but the solver will use the presious state to
   *  compute a more rigid solution */
  umEVALTRANSFORM
};

#endif
#endif

/* Node types */
enum CATCSNType
{
  ntNULLTYPE = 0,
  ntRIGIDSET = 0x1,
  ntGEOMETRYLEAF = 0x2,
  ntGEOMCONSTRAINT = 0x4,
  ntPATTERN = 0x8,
  ntSKETCH = 0x10,
  ntJOINT = 0x20,
  ntAXIS = 0x40,
  ntVARIABLE = 0x80,
  ntEQUATION = 0x100,
  ntOFFSET = 0x200,
  ntCONTACT = 0x1000,
  ntGEOMETRY = ntRIGIDSET | ntSKETCH | ntGEOMETRYLEAF | ntAXIS,
  ntRIGIDGEOMETRY = ntRIGIDSET | ntSKETCH | ntGEOMETRYLEAF | ntAXIS | 0x400,
  ntINTERNALGEOMETRY = ntSKETCH | ntGEOMETRYLEAF,
  ntCONSTRAINT = ntGEOMCONSTRAINT | ntPATTERN | ntJOINT | ntEQUATION | ntOFFSET | ntCONTACT,
  ntBBOX = 0x800 | ntGEOMETRYLEAF,
  ntANYTYPE = 0xFFFF
};

/* Rename public types (see CDSEnums.h) */
#define CATCSType CATCDSType
#define CATCSVariableType CATCDSVariableType
#define CATPHalfSpace CATCDSHalfSpace
#define CATGStatus CATCDSGStatus
#define CATGUStatus CATCDSGUStatus
#define CATVStatus CATCDSVStatus
#define CATMoveStatus CATCDSMoveStatus
#define CATCStatus CATCDSStatus
#define CATCSDiscrepancyStatus CATCDSDiscrepancyStatus
#define CATDOFStatus CATCDSDOFStatus
#define CATCSSimulabilityDiagnostics CATCDSSimulabilityDiagnostics
#define CATCSRedundancyStatus CATCDSRedundancyStatus
#define CATParamType CATCDSParamType
#define CATDiscontinuitySide CATCDSDiscontinuitySide
#define CATMoveMode CATCDSMoveMode
#define CATSolvingMode CATCDSSolvingMode
#define CATUpdateMode CATCDSUpdateMode
#define CATDiagMode CATCDSDiagMode
#define CATOverdefinedDiagMode CATCDSOverdefinedDiagMode
#define CATCSVarDepMode CATCDSVarDepMode
#define CATCSDOFMode CATCDSDOFMode
#define CATCSOutputMode CATCDSOutputMode
#define CATPartialSolvingMode CATCDSPartialSolvingMode
#define CATCSChiralityMode CATCDSChiralityMode
#define CATAutoConstraintMode CATAutoConstraintMode
#define CATWeightType CATWeightType
#define CATCSurfaceOrientation CATCDSSurfaceOrientation
#define CATCSTorusOrientation CATCDSTorusOrientation
#define CATCSExtrapolMode CATCDSExtrapolMode
#define CATCSInterpolConditionType CATCDSInterpolConditionType
#define CATCSSphericalType CATCDSSphericalType
#define CATCSHealingMode CATCDSHealingMode
#define CATCSHealingStatus CATCDSHealingStatus

/** Simulation mode */
enum CATSimMode
{
  smSTANDARD,
  smPERTURBATION
};

/* Leading constraint status */
enum CATCSLeadingStatus
{
  lsUNKNOWN,
  lsNOTLEADING,
  lsVALID,
  lsINVALID,
  lsIGNORED
};

/* Ruled geometries mode for tangency constraint */
enum CATCSRuledGeometriesMode
{
  rmONPOINT,
  rmONGENERATRIX
};

/**** Constraint Solver data ****/

/* Rigid set diagnostic mode */
enum CATRigidSetDiagMode
{
  rdWITHOUTDOS,
  rdFULL, // Add dos to dof
  rdEXTRADOF // deprecated
};

/** Create optimized constraints list or not */
enum CATAutoConstraintMode
{
  CATACFull,
  CATACOptimized
};

/** Create constraints list with weight or not */
enum CATACWeightType
{
  CATACNone,        // Without weight
  CATACExternal,    // With weight generated by an external application
  CATACTopological  // With weight Generated by an internal function
};

/**** Skins ****/

/** Skin parameters types. */
enum CATCSParamType
{
  CATCSEmptyParam,
  CATCS0DParam,
  CATCS1DParam,
  CATCS2DParam
};

/** Continuity diagnostics for skin parameters. */
enum CATCSContinuity
{
  CATCSContinuityG0,
  CATCSContinuityG1,
  CATCSContinuityG2
};

/** Diagnostics of GetClosePoint on skin. */
enum CATCSClosePointDiagnostics
{
  CATCSClosePointSucceded,
  CATCSClosePointFailedW,
  CATCSClosePointFailedU,
  CATCSClosePointFailedV,
  CATCSClosePointFailedUV
};

/** GetClosePoint on skin stop command. */
enum CATCSStopCommand
{
  CATCSStopOnG0,
  CATCSNoStop
};

/** Degree-of-freedom computation diagnostic. */
enum CATCSDOFDiagnostic
{
  ddUNKNOWN,
  ddFULLY_INVARIANT,
  ddPARTIALLY_INVARIANT,
  ddINSTANTANEOUS,
  ddSINGULAR
};

/** Derivatives computation mode */
enum CATCSDerivMode
{
  drNONE,
  drDERIVATIVES_AT_START_POINT,
  drDERIVATIVES_AT_END_POINT
};

enum CATContactsDiagMode
{
  cdCLASH_DETECTED,
  cdALWAYS,
  cdNEVER
};

enum CATCtStatus
{
  tsUNKNOWN,
  tsNOTCONSISTENT,
  tsOUTOFCLASH,
  tsCONTACT
};


enum CATUpdateOutOfClashMode
{
  ocNONE,
  ocBASIC, // greedy but ...
};

enum CATCDSInterferenceMode {
  imNONE,      // "No interference Detection"
  imNOMOVE,    // "Stop at the beginning of the step in case of detected interference"
  imSTOP,      // "Stop On Detected Interference"
  imPUSH       // "Intermittent contact capability"
};

enum CATCDSScale {
  scXS,
  scS,
  scN,
  scL,
  scXL
};

enum CATCDSTransitionCurveType {
  tcUnknown = -1,
  tcParabola_2, // =  0
  tcParabola_3, // =  1
  tcClothoide, // =  2
  tcBloss, // =  3
  tcCosinusoidal, // =  4
  tcSinusoidal,   // =  5
  tcCatenary ,      // =  6
  tcSineHalfWavelengthDiminishingTangent, // = 7
  tcParabolaJP_3,  // = 8
  tcParabolsNSW_3, // = 9 
  tcQuadratic, // = 10
  tcBiQuadratic, // = 11
  tcLemniscate, // = 12
  tcViennesebend, // = 13
  tcHelmert     // = 14
};

enum CATCDSHealingStatus {
  htSUCCEEDED,
  htCORRECTED,
  htNOT_SATISFIED,
  htFAILED
};

enum CATCDSHealingMode {
  hmPLANAR_MECHANISM_MODE,
  hmGENERAL_MODE
};

//-----------------------------------------------------------------------

#endif
