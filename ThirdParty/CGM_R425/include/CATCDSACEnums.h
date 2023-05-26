// COPYRIGHT DASSAULT SYSTEMES 2013
//=============================================================================
//
// CATCDSACEnums:
//   Enumerations used in automatic constraining parameters.
//
//=============================================================================
//
// Usage notes:
//
//   If you change this file, ensure you don't break the class
// CATCDSAutoConstrainingParameters which uses these enumerations.
//
// List of enumerations declared in this file :
// - CATCDSACType : Constraint types used in automatic constraining.
// - CATCDSACWeightRules : modes which specify the rules which fill the
//                         autoconstraining weights
//=============================================================================
//  Nov 2013  Creation                                Delphine JENNEQUIN (KUB)
//                                              Etienne de SAINT GERMAIN (ZO4)
//=============================================================================


#ifndef CATCDSACEnums_h
#define CATCDSACEnums_h

#include "CATCDSUtilities.h"

/**
 * Enumeration of constraint types used in automatic constraining.
 */
enum ExportedByCATCDSUtilities CATCDSACType
{
  actConstraint =  0, // Only used for error !
  actDistance,       
  actAngle,
  actParallelism,
  actPerpendicularity,
  actCoincidence,
  actTangency,
  actAntiTangency,
  actRadius,
  actMajorRadius,
  actMinorRadius,
  actApexAngle,
  actConcentricity,
  actCoaxiality,
  actMidPoint,
  actSymmetry
};

/**
 * Enumeration of modes which specify the rules which fill the autoconstraining weights
 */
enum ExportedByCATCDSUtilities CATCDSACWeightRules
{
  /* If weights are specified by autoconstraining parameters */
  wrAutoConstrainingParameters,
  /* If weights are specified by a WBFactory (created by the applications) */
  wrWBFactory
};

#endif

