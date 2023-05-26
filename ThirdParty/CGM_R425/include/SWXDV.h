#ifndef  SWXDV_H
#define  SWXDV_H


#if defined(__SWXDV)
#define ExportedBySWXDV DSYExport
#else
#define ExportedBySWXDV DSYImport
#endif
#include "DSYExport.h"


#endif //SWXDV_H

