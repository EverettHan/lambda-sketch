#ifdef _STATIC_SOURCE
#define	ExportedByBO0LOGRP
#elif defined __BO0LOGRP
#define ExportedByBO0LOGRP DSYExport
#else
#define ExportedByBO0LOGRP DSYImport
#endif
#include "DSYExport.h"
#include "TopologicalOperatorsCommonDec.h"
