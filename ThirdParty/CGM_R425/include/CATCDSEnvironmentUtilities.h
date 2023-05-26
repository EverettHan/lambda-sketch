// COPYRIGHT DASSAULT SYSTEMES 2015
//=============================================================================
//
// CATCDSEnvironmentUtilities:
//
//=============================================================================
//  Feb 2015  Creation                         TE9
//=============================================================================

#ifndef CATCDSEnvironmentUtilities_h
#define CATCDSEnvironmentUtilities_h

#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSString.h"
#include "CATCDSDebug.h"

class CATCDSStream;

ExportedByCATCDSUtilities void CATCDSSetEnv(const CATCDSString& iName, const CATCDSString& iValue);
ExportedByCATCDSUtilities CATCDSString CATCDSGetEnv(const CATCDSString& iName);
ExportedByCATCDSUtilities bool CATCDSIsEnvVariable(const CATCDSString& iName);
ExportedByCATCDSUtilities double CATCDSGetEnvF(const CATCDSString& iName);
ExportedByCATCDSUtilities int    CATCDSGetEnvI(const CATCDSString& iName);
ExportedByCATCDSUtilities void CATCDSUnsetEnv(const CATCDSString& iName);
ExportedByCATCDSUtilities void CATCDSPrintEnv(CATCDSStream& ioStream);
ExportedByCATCDSUtilities void CATCDSPrintEnvSection(CATCDSStream& ioStream);
ExportedByCATCDSUtilities void CATCDSFlushEnv();

#endif
