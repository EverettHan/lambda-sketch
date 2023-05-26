#ifndef _IntroInfra_H
#define _IntroInfra_H

#if defined __IntroInfra
#define ExportedByIntroInfra DSYExport
#else
#define ExportedByIntroInfra DSYImport
#endif
#include "DSYExport.h"

#include <IntroInfraDoc.h>

#endif
