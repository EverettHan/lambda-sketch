#ifndef CATScriptCodeMacro_h
#define CATScriptCodeMacro_h

#ifdef _WINDOWS_SOURCE

//
// Macros must be identical to ones from VBA\ProtectedInterfaces\CATVBACodeMacro.h
//

#include "JS0CATREG.h"

// Activation of VBA7
#define DS_VBA7_Integration

// Activation of hybrid architecture : In and Out process are supported on a single application 
#define VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS

namespace SysScriptInfra
{
	ExportedByJS0CATREG short Is_DS_VBAIntegration_OutProcess();	
}

#endif // _WINDOWS_SOURCE
#endif // CATScriptCodeMacro_h
