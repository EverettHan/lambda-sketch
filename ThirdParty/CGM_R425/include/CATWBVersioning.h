#ifndef CATWBVersioning_h
#define CATWBVersioning_h

// Versioning
#include "CATCDSModifications.h"
#include "CATCDSGlobalParameters.h"

// CDS (for debug)
#include "CATCDSEnvironmentUtilities.h"

// Temporary versioning
// The active level is defined in CATCDSUtilities\ProtectedInterfaces\CATCDSModifications_inc.h
// The inactive level is CATCDSModificationInactive

// R1Y 26/02/20: For post-simplifying "sin(x)/cos(x)" to "tan(x)".
#ifndef CATWBx_Simplify_QuotientSinCos
#define CATWBx_Simplify_QuotientSinCos CATCDSModificationInactive
#endif

// Q48 23/05/22: Clone of black-box
#ifndef CATWBx_Printer_DerivBBx
#define CATWBx_Printer_DerivBBx CATCDSModificationInactive
//#define CATWBx_Printer_DerivBBx CDS_LEVEL(839)
#endif

// Q48 17/01/23: Enable clone of BBx in factory
#ifndef CATWBx_Factory_CloneBBx
#define CATWBx_Factory_CloneBBx CATCDSModificationInactive
//#define CATWBx_Factory_CloneBBx CDS_LEVEL(839)
#endif

// Q48 17/01/23: Update the value of cloned variables
#ifndef CATWBx_Factory_CloneVariableValue
#define CATWBx_Factory_CloneVariableValue CATCDSModificationInactive
//#define CATWBx_Factory_CloneVariableValue CDS_LEVEL(839)
#endif

#endif // CATWBVersioning_h
