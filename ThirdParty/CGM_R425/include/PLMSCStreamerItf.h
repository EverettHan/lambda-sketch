/**
 * @level Private
 * @usage U1
 */
#if defined(__PLMSCStreamerItf)
#define ExportedByPLMSCStreamerItf DSYExport
#else
#define ExportedByPLMSCStreamerItf DSYImport
#endif
#include "DSYExport.h"

// not active yet
#define NGS_SIMPLIFY_STREAMERS


