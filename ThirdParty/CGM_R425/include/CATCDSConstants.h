// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATCDSESConstants:
//   Different constants needed for implementation.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Jul 2002  Creation                         Vladislav Kornienkoint
//=============================================================================

#ifndef CATCDSConstants_h
#define CATCDSConstants_h

#include "CATCDSUtilities.h"

// Relative Representation normalizing factor
extern ExportedByCATCDSUtilities const double CATCDSRRNormalizingFactor;

// Maximum relative precision.
extern ExportedByCATCDSUtilities const double CATCDSEpsilon;

extern ExportedByCATCDSUtilities const double CATCDSDomainInfinity;

//!nb can be modified from ReplayTest option
extern ExportedByCATCDSUtilities double CATCDSValidativeAccuracy;

// Value that is used as goal accuracy in numerical methods.
extern ExportedByCATCDSUtilities const double CATCDSGoalAccuracy;
extern ExportedByCATCDSUtilities const double CATCDSSquareGoalAccuracy;
extern ExportedByCATCDSUtilities const double CATCDSSqrtGoalAccuracy;

// Minimal admissible accuracy in numerical methods.
extern ExportedByCATCDSUtilities const double CATCDSMinAccuracy;

extern ExportedByCATCDSUtilities const double CATCDSOverDefinedRatio;

extern ExportedByCATCDSUtilities const double CATCDSDefaultTolerance;
extern ExportedByCATCDSUtilities const double CATCDSDefaultReferenceLinearTolerance;
extern ExportedByCATCDSUtilities const double CATCDSDefaultLinearTolerance;
extern ExportedByCATCDSUtilities const double CATCDSDefaultAngularTolerance;
extern ExportedByCATCDSUtilities const double CATCDSDefaultGoalDiscrepancy;

extern ExportedByCATCDSUtilities const double CATCDSGausPivThreshold;

// Tolérance de normalisation de la matrice RR pour le calcul de DOF
extern ExportedByCATCDSUtilities const double CATCDSRRGaussAccuracy;

extern ExportedByCATCDSUtilities char const * const chReplayExt;
extern ExportedByCATCDSUtilities char const * const chScriptExt;

extern ExportedByCATCDSUtilities char const * const chOutputSeparator;
extern ExportedByCATCDSUtilities char const * const chReferenceSeparator;
extern ExportedByCATCDSUtilities char const * const chLineComment;
extern ExportedByCATCDSUtilities char const * const chRigidSetPrefix;
extern ExportedByCATCDSUtilities char const * const chSketchPrefix;
extern ExportedByCATCDSUtilities char const * const chAxisPrefix;

extern ExportedByCATCDSUtilities char const * const chOpeningBrace;
extern ExportedByCATCDSUtilities char const * const chClosingBrace;

extern ExportedByCATCDSUtilities const double CATCDSBadStiffness;
extern ExportedByCATCDSUtilities const double CATCDSNotSoft; 
extern ExportedByCATCDSUtilities const double CATCDSMandatory; 

extern ExportedByCATCDSUtilities const double CATCDSDiscrepancy_MissedValidation;
extern ExportedByCATCDSUtilities const double CATCDSDiscrepancy_ChiralityChanged;
extern ExportedByCATCDSUtilities const double CATCDSDiscrepancy_UnsupportedConstraints;
extern ExportedByCATCDSUtilities const double CATCDSDiscrepancy_NotMoved;
extern ExportedByCATCDSUtilities const double CATCDSDiscrepancy_VariableOutOfLimits;

#endif
