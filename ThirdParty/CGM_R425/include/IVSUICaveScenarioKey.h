//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2018
//-----------------------------------------------------------------------------
#ifndef IVSUICaveScenarioKey_H
#define IVSUICaveScenarioKey_H

#include "IVInterfaces.h"

#include "CATUnicodeString.h"


//=============================================================================
/**
 * IVSUICaveScenarioKey
 */
struct ExportedByIVInterfaces IVSUICaveScenarioKey
{
  static CATUnicodeString const IPD;          // unsigned int
  static CATUnicodeString const SPEED;        // double
  static CATUnicodeString const SCALE;        // double
  static CATUnicodeString const FILENAME;     // CATUnicodeString
  static CATUnicodeString const SCALEMODE;    // IVISUIScenarioMultipipe::ScaleMode
  static CATUnicodeString const SCENARIOMODE; // IVISUIScenarioMultipipe::Mode
};


#endif
