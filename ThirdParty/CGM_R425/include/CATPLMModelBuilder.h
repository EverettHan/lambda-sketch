/**
 * @level Protected
 * @usage U1
 */
#if defined(__CATPLMModelBuilder)
#define ExportedByCATPLMModelBuilder DSYExport
#else
#define ExportedByCATPLMModelBuilder DSYImport
#endif
#include "DSYExport.h"
