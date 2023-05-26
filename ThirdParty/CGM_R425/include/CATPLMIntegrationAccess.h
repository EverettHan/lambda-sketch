/** 
* @CAA2Required 
*/ 
#ifdef  __CATPLMIntegrationAccess

#define ExportedByCATPLMIntegrationAccess DSYExport
#else
#define ExportedByCATPLMIntegrationAccess DSYImport
#endif
#include "DSYExport.h"
