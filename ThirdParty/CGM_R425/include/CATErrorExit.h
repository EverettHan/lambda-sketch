#ifndef CATErrorExit_H
#define CATErrorExit_H  42400

// COPYRIGHT DASSAULT SYSTEMES 2000

// ============================================================================
// SERVICES QU'ON A ETE OBLIGE DE FOURNIR A CAUSE DU COUT FANTASTIQUE
// ENDURE PAR LA SOCIETE SUITE A L'INTRODUCTION  DU FOUTU EXIT 84
// ============================================================================
#include "JS0ERROR.h"

//=============================================================================
// CATError Services
// ------------------
// CATExit : asks System  to exit with  specified exit code
//  Should be used only in the following cases
//     in Dialog and System frameworks
//     in some odt's (non Record / non macro odt's)
// ----------------------------------------------------------------------------
[[noreturn]] ExportedByJS0ERROR void CATExit(int iExitCode);
//=============================================================================
// CATError Services
// ------------------
// CATErrorNormalEnd : permits to specify the ending exit code of CATIA
//  Must be used only if you can't use CATExit
//  Should be used only in the following cases
//     in Dialog and System frameworks
// ----------------------------------------------------------------------------
ExportedByJS0ERROR void CATErrorNormalEnd(int iExitCode);
//=============================================================================
// CATError Services
// ------------------
// CATGetExitCode : asks the exit status of CATIA
//  *oExitCode is valued to the exit status if the status is known
//  return 0  if the status is known and -1 else
// ----------------------------------------------------------------------------
ExportedByJS0ERROR int CATGetExitCode(int *oExitCode);
//=============================================================================
// CATError Services
// ------------------
// CATCallOnExit  : asks the exit status of CATIA
//
// ----------------------------------------------------------------------------
#define CATCallOnNormalEnd      1
#define CATCallOnAbnormalEnd    2
#define CATCallAllways          3 
#define CATCallOnGroupUnloading 8 
ExportedByJS0ERROR int CATCallOnExit( int (*iFunction)(int), int iCallSpecifier=CATCallOnNormalEnd);

#endif


