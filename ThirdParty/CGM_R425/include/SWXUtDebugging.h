#ifndef  SWXUtDebugging_H
#define  SWXUtDebugging_H


#if defined(__SWXUtDebugging)
#define ExportedBySWXUtDebugging DSYExport
#else
#define ExportedBySWXUtDebugging DSYImport
#endif
#include "DSYExport.h"


#endif //SWXUtDebugging_H

