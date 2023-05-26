#ifdef _STATIC_SOURCE
#define	ExportedByPPRobot
#elif defined __PolyPathPlanRobot
#define ExportedByPPRobot DSYExport
#else
#define ExportedByPPRobot DSYImport
#endif
#include "DSYExport.h"
