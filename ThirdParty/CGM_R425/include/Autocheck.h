// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
// Creation EDS  03/10/2000
//=============================================================================

#ifndef __Autocheck_h__
#define __Autocheck_h__


#if defined(__Autocheck)
#define ExportedByAutocheck DSYExport
#else
#define ExportedByAutocheck DSYImport
#endif
#include "DSYExport.h"

#endif
