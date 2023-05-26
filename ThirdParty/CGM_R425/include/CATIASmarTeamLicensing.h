//
// COPYRIGHT DASSAULT SYSTEMES 2002
// ---------------------------------------------------------------------------
// Licensing code for CATIA-SmarTeam plugin
//
// The license is given by SmarTeam thru a specific DLL
// These CATIA APIs connects to the SmarTeam DLL and
// request/free the license
//
// - IsCATIASmarTeamLicenseAvailable
//   Determine if the SmarTeam DLL is available or not
//   If the DLL is available, the TeamPDM menu will be displayed in CATIA
//
// - TakeCATIASmarTeamLicense
//   Takes a SmarTeam license for the CATIA plugin
//   This call will be used the first time the user perform TeamPDM/Connect
//
// - ReleaseCATIASmarTeamLicense
//   Releases the SmarTeam license
//   This call will be used only when exiting CATIA
// ---------------------------------------------------------------------------
// History;
// 27/08/2002 JKR Creation
// ---------------------------------------------------------------------------
//
#ifndef CATIASmarTeamLicensing_H
#define CATIASmarTeamLicensing_H

#include "CATBaseUnknown.h"
#include "JS0SMT.h"

#ifdef _WINDOWS_SOURCE

ExportedByJS0SMT
bool
IsCATIASmarTeamLicenseAvailable();

ExportedByJS0SMT
HRESULT
TakeCATIASmarTeamLicense();

ExportedByJS0SMT
void
ReleaseCATIASmarTeamLicense();

#endif

#endif
