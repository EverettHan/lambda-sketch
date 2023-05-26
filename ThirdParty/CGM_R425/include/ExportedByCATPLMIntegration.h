#undef ExportedByCATPLMIntegration

#if defined __CATPLMIntegration
#define ExportedByCATPLMIntegration DSYExport
#else
#define ExportedByCATPLMIntegration DSYImport
#endif
#include "DSYExport.h"
