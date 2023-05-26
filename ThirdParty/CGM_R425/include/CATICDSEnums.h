#ifndef CATICDSEnums_H
#define CATICDSEnums_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/** Maximum number arguments of a geometric constraint. */
#define MAX_CONSTRAINT_ARGS 3

/** Maximum number of parameters per constraint. */
#define MAX_CONSTRAINT_PARAMS 2

/** Maximum number of doubles necessary to describe a parameter value. */
#define MAX_PARAM_VALUES 3

//-------------------------------------------------------
//                      Entities
//-------------------------------------------------------
  
#define DECL_CDSTypes          \
  tpNULLTYPE,                  \
  tpANYTYPE,                   \
/* Geometries */               \
  tpGEOMETRY,                  \
  tpGEOMETRYLEAF,              \
  tpRIGIDSET2D, /* deprecated : use tpRIGIDSET instead */ \
  tpPOINT2D,                   \
  tpLINE2D,                    \
  tpCIRCLE2D,                  \
  tpELLIPSE2D,                 \
  tpHYPERBOLA2D,               \
  tpPARABOLA2D,                \
  tpCURVE2D,                   \
  tpINTERPOLNURBSCURVE2D,      \
  tpNURBSCURVE2D,              \
  tpRIGIDSET,                  \
  tpPOINT,                     \
  tpLINE,                      \
  tpCIRCLE,                    \
  tpELLIPSE,                   \
  tpPARABOLA,                  \
  tpHYPERBOLA,                 \
  tpCURVE,                     \
  tpNURBSCURVE,                \
  tpINTERPOLNURBSCURVE,        \
  tpPLANE,                     \
  tpCYLINDER,                  \
  tpCONE,                      \
  tpSPHERE,                    \
  tpTORUS,                     \
  tpNURBSSURFACE,              \
/* Constraints */              \
  tpCONSTRAINT,                \
  tpGEOMCONSTRAINT,            \
  tpGEOMDIMCONSTRAINT,         \
  tpDISTANCE,                  \
  tpANGLE,                     \
  tpPARALLELISM,               \
  tpPERPENDICULARITY,          \
  tpCOINCIDENCE,               \
  tpTANGENCY,                  \
  tpANTITANGENCY,              \
  tpRADIUS,                    \
  tpMAJORRADIUS,               \
  tpMINORRADIUS,               \
  tpAPEXANGLE,                 \
  tpCONCENTRICITY,             \
  tpCOAXIALITY,                \
  tpMIDPOINT,                  \
  tpSYMMETRY,                  \
  tpSEGMENTLENGTH,             \
  tpCURVATURE,                 \
  tpVERTEXCURVATURE,           \
  tpFOCUS,                     \
  tpCONTACT,                   \
/* Patterns */                 \
  tpPATTERN,                   \
  tpCIRCULARPATTERN,           \
  tpLINEARPATTERN,             \
/* Variable */                 \
  tpVARIABLE,                  \
/* Axis */                     \
  tpAXIS,                      \
/* Joints */                   \
  tpJOINT,                     \
  tpCYLINDRICAL,               \
  tpFULLDOF,                   \
  tpPLANAR,                    \
  tpPRISMATIC,                 \
  tpREVOLUTE,                  \
  tpSPHERICAL,                 \
  tpU,                         \
/* Equation */                 \
  tpLINEAREQUATION,            \
  tpALGEBRAICEQUATION

/** Entity move status. */
enum CATCDSMoveStatus
{
  /** Unknown. */
  msUNKNOWN,
  /** Moved exactly as required. */
  msEXACTLYMOVED,
  /** Moved, but not exactly as required. */
  msMOVED,
  /** Not moved. */
  msNOTMOVED,
  /** Fixed. */
  msFIXED
};

//-------------------------------------------------------
//                     Geometries
//-------------------------------------------------------

// Geometry status
#define DECL_CDSGStatus \
  /** Unknow. */ \
  gsUNKNOWN, \
  /** It is fixed. */ \
  gsFIXED, \
  /** It is an argument of an inconsistent constraint. */ \
  gsNOTCONSISTENT, \
  /** It has some degrees of freedom. */ \
  gsUNDERDEFINED, \
  /** It has no degrees of freedom. */ \
  gsWELLDEFINED, \
  /** It is an argument of an overdefined constraint. */ \
  gsOVERDEFINED

/** Geometry underdefined status. */
enum CATCDSGUStatus
{
  /** Unknown. */
  usUNKNOWN     = 0x00,
  /** Its radius can be changed. */
  usRADIUS      = 0x01,
  /** Its major radius can be changed. */
  usMAJORRADIUS = 0x02,
  /** Its minor radius can be changed. */
  usMINORRADIUS = 0x04,
  /** It can be rotated. */
  usANGLE       = 0x08,
  /** It can be translated. */
  usPOSITION    = 0x10,
  /** It's apex angle can be changed. */
  usAPEXANGLE   = 0x20
};


// Variable status
enum CATCDSVStatus
{
  /** Unknow. */
  vsUNKNOWN,
  /** It is fixed. */
  vsFIXED,
  /** It is an argument of an inconsistent constraint. */
  vsNOTCONSISTENT,
  /** It has one degree of freedom. */
  vsUNDERDEFINED,
  /** It has no degree of freedom. */
  vsWELLDEFINED,
  /** It is an argument of an overdefined constraint. */
  vsOVERDEFINED
};

/** Degree-of-freedom status. */
enum CATCDSDOFStatus
{
  dsNOTUSED,
  dsTRANSLATION,
  dsROTATION,
  dsSCREW
};

/** Monoparametric parameter type. */
enum CATCDSParamType
{
  ptPERIODIC,
  ptBOUNDED
};

/** Monoparametric discontinuity side. */
enum CATCDSDiscontinuitySide
{
  dsLOWER,
  dsUPPER,
  dsNODISCONTINUITY
};

#define DECL_CDSTransitionCurve \
  tcNONE, \
  tcCLOTHOID

//-------------------------------------------------------
//             Monoparametrics and surfaces
//-------------------------------------------------------

/** Extrapolation options for curves and offset curves. */
enum CATCDSExtrapolMode
{
  /** No extrapolation. */
  exNONE,
  /** Linear the value of the 1st derivative at the old bound prevails throughout the extrapolated part
   *  of the parameter range. So the 1st derivative remains constant and equal to its value at the old bound. */
  exLINEAR,
  /** The 2nd derivative is null between the old and the bew bounds. */
  exC2
};

// Setting the behavior of a Profile when self-intersection exist.
enum CATCDSSelfIntersectionMode
{
  /** Allow self-intercection. */
  simNOTCHECKED,
  /** trim unwanted portions (offset profiles only). */
  simAUTOTRIM
};

/** Interpolation condition type of Interpolation NURBS curve. */
enum CATCDSInterpolConditionType
{
  /** Not specified. */
  icNONE,
  /** Passage point. */
  icPOINT,
  /** Tangent direction defined by a Line. */
  icFIRSTDERIV_DIR,
  /** @DEPRECATED */
  icFIRSTDERIV_ANGLE,
  /** @DEPRECATED */
  icFIRSTDERIV_ANGLE_VAR,
  /** Norm of the tangent. */
  icFIRSTDERIV_NORM,
  /** Norm of the tangent, as a variable. */
  icFIRSTDERIV_NORM_VAR,
  /** Curvature. */
  icCURVATURE,
  /** Curvature, as a variable. */
  icCURVATURE_VAR,
  /** Second derivative direction defined by a Line. */
  icSECONDDERIV_DIR,
  /** Norm of the second derivative. */
  icSECONDDERIV_NORM,
  /** Norm of the second derivative, as a variable. */
  icSECONDDERIV_NORM_VAR
};

//-------------------------------------------------------
//                     Constraints
//-------------------------------------------------------

// Constraint status
#define DECL_CDSStatus \
  /** Unknow. */ \
  csUNKNOWN,           \
  /** Is is not valid. */ \
  csNOTVALID,          \
  /** It is not satisfied (with given tolerances). */ \
  csNOTCONSISTENT,     \
  /** It is overdefined (i.e. it prevents the satisfaction of some other constraints). */ \
  csOVERDEFINED,       \
  /** It is satisfied (with given tolerances). */ \
  csSATISFIED,         \
  /** Is between fixed objects */ \
  csBETWEENFIXED,      \
  /** Is between members of the same rigidset */ \
  csBETWEENMEMBERS

/** Constraint EvalDiscrepancy status. */
enum CATCDSDiscrepancyStatus
{
  /** The constraint is satisfied. */
  dsSATISFIED,
  /** The constraint can't be satisfied with any value. */
  dsNOTSATISFIED,
  /** The constraint is not satisfied but can be satisfied with another value. */
  dsNOTSATISFIEDVALUE
};

/** Constraint redundancy status. */
enum CATCDSRedundancyStatus
{
  rsNOTSATISFIED,
  rsNOTREDUNDANT,
  rsFULLYREDUNDANT,
  rsPARTIALLYREDUNDANT
};

/** Constraint's geometries alignment. */
enum CATCAlignment
{
  /** Unknown*/
  caNOTSPECIFIED,
  caSPECIFIED, // TODO : TO HIDE, only makes sense for angles
  /** The directions of geometries are aligned */
  caALIGN,
  /** The directions of geometries are anti-aligned.*/
  caANTIALIGN
};

/** Geometry node half-space positioning for a distance constraint. */
enum CATCDSHalfSpace
{
  /** Unknown. */
  hsNOTSPECIFIED,
  /** The distance is taken on the positive side of the surface (with respect to the normal) */
  hsPOSITIVE,
  /** The distance is taken on the negative side of the surface (with respect to the normal). */
  hsNEGATIVE
};

/** Constraint node surfaces orientation. */
enum CATCDSSurfaceOrientation
{
  soNOTSPECIFIED,
  soPOSITIVE,
  soNEGATIVE
};

/** Torus orientation with respect to circle for a coincidence constraint. */
enum CATCDSTorusOrientation
{
  toNOTSPECIFIED,
  toPARALLEL,
  toPERPENDICULAR
};

/** Spherical convention of Spherical and FullDOF joints. */
enum CATCDSSphericalType
{
  /** Tait-Bryan intrinsic ZXY angles (default type) */
  stZXY,
  /** Tait-Bryan intrinsic ZYX angles : yaw, pitch and roll */
  stZYX,
  /** Euler intrinsic ZXZ angles */
  stZXZ,
  /** No angle parameterization */
  stPOINTPOINT
};


//-------------------------------------------------------
//                      Variables
//-------------------------------------------------------

/** Variable type. */
enum CATCDSVariableType
{
  vtFREE,
  vtANGLE,
  vtDISTANCE,
  vtCURVATURE
};

//-------------------------------------------------------
//                      Solver
//-------------------------------------------------------

/** Solving mode. */
enum CATCDSSolvingMode
{
  /** The solver moves geometry rigidly if possible. */
  slSTANDARD,
  /** The solver moves minimum of objects. */
  slMINIMUM_MOVE
};

/** Update mode. */
#define DECL_CDSUpdateMode \
  /** Usual mode. */ \
  umEVALUATE, \
  /** Used after an first evalute, perform an update preserving chiralities computed during */ \
  /** the first evaluate. If no first evaluate was done, behaves like umEVALUATE. */ \
  umREEVALUATE

// Solving move mode
#define DECL_CDSMoveMode \
  /** The solver will move as many objects as it is needed to make a dynamic move. */ \
  mmSTANDARD, \
  /** The solver will move as few objects as possible. */ \
  mmMINIMUM_MOVE

// Diagnostics mode
#define DECL_CDSDiagMode \
  /** Run diagnostics if the model could not be solved. */ \
  dmNOTSOLVED, \
  /** Always run diagnostics. */ \
  dmALWAYS, \
  /** Run diagnostics, and stop computing welldefined diagnostics as soon as the model is detected as overdefined.*/ \
  dmNOTOVERDEFINED, \
  /** Do not run diagnostics. */ \
  dmNEVER

/** Overdefined diagnostics mode. */
enum CATCDSOverdefinedDiagMode
{
  /** Only dimensional constraints are able to provide overdefined diagnostics. */
  odDIMENSIONAL,
  /** Dimensional and logical constraints are able to provide overdefined diagnostics. */
  odFULL
};

/** Degrees of freedom mode. */
enum CATCDSDOFMode
{
  /** The solver will calculate full DOF. */
  dmFULL,
  /** The solver will exclude DOS from DOF. */
  dmWITHOUTDOS
};

/** Output mode. */
enum CATCDSOutputMode
{
  /** Transformation will be applied for root elements only: rigid sets and elements which are not included in rigid sets. */
  omCALLBACK_ROOT_ELEMENTS,
  /** Transformations will be applied to all objects and rigid sets. */
  omCALLBACK_ALL_ELEMENTS
};

/** Partial solving mode. */
enum CATCDSPartialSolvingMode
{
  /** Always find partial solution, i.e. satisfy as many constraints as possible. */
  psALWAYS,
  /** Find partial solution, but stop the solving process if any inconsistency is detected during it. */
  psFAIL_IF_INCONSISTENT
};

/** Chirality mode. */
enum CATCDSChiralityMode
{
  /** Do not care about chirality */
  cmFREE,
   /** Preserve chirality. */
  cmKEEP
};

/** Variables Inter-dependency mode. */
enum CATCDSVarDepMode
{
  /** Do not run the Variables Inter-dependency diagnostics. */
  vmNEVER,
  /** Run the Variables Inter-dependency diagnostics if the model is solved. */
  vmSOLVED
};

/** Simulability diagnostics. */
enum CATCDSSimulabilityDiagnostics
{
  /** The mechanism is simulable. */
  sdSIMULABLE,
  /** The mechanism is overconstrained since too many commands are given. */
  sdOVERCONSTRAINED,
  /** The mechanism is not simulable since too few commands are given. */
  sdUNDERCONSTRAINED,
  /** The mechanism is simulable with perturbation only. */
  sdSINGULAR
};

/** Debug level. */
enum CATCDSReplayMode
{
  /** No replay data is generated */
  rmNONE,
  /** Generate a replay file for each solver run */
  rmREPLAY,
  /** Generate a script file to record a run sequence */
  rmSCRIPT
};


//-------------------------------------------------------

#ifndef CDS_NOTYPES_DEF
#ifndef CDS_TYPES
#define CDS_TYPES
/** Entities types */
enum CATCDSType {DECL_CDSTypes};
/** Transition Curve types */
enum CATCSTransitionCurveType {DECL_CDSTransitionCurve};
/** Geometry status. */
enum CATCDSGStatus {DECL_CDSGStatus};
/** Constraint status */
enum CATCDSStatus {DECL_CDSStatus};
/** Move mode */
enum CATCDSMoveMode {DECL_CDSMoveMode};
/** Diagnostic mode */
enum CATCDSDiagMode {DECL_CDSDiagMode};
/** Update mode */
enum CATCDSUpdateMode {DECL_CDSUpdateMode};
#endif
#endif
#endif
