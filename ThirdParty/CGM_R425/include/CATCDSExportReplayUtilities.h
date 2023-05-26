// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
//
// CATCDSExportReplayUtilities:
//   Auxiliary functions for work with replay mechanism .
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  April 2007  Creation                                        JSX
//=============================================================================
// JSX 25 avril 2007
// Duplication dans CATCDS du fichier de CATCDS.tst
// Declaration d'une class fille de CATConstraintSolver permettant de rendre un CATConstraintSolver

#ifndef CATCDSExportReplayUtilities_H
#define CATCDSExportReplayUtilities_H

#include "VarSweepDriver.h"
#include "CATConstraintSolver.h"
#include "CATCDSDebug.h"

class CATCDSString;
class CATCDSOperator;
class CATSoftwareConfiguration;
class CATICDSAdvanced;

CATICDSAdvanced* LoadSweepConstraintSolver(CATCDSString *iStreamName, int& oStreamVersion);

#endif

