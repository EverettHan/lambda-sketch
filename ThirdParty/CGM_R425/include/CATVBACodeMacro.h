#ifndef CATVBACodeMacro_h
#define CATVBACodeMacro_h

#ifdef _WINDOWS_SOURCE

//
// Macros must be identical to ones from System\ProtectedInterfaces\CATScriptCodeMacro.h
//

#include "CATVBAInfra.h"

// Activation of VBA7
#define DS_VBA7_Integration

// Activation of hybrid architecture : In and Out process are supported on a single application 
#define VBA_SUPPORTS_INPROCESS_AND_OUTPROCESS

namespace VBAScriptInfra
{
	ExportedByCATVBAInfra short Is_DS_VBAIntegration_OutProcess();	
}

#endif // _WINDOWS_SOURCE
#endif // CATVBACodeMacro_h
