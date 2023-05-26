#ifdef  __CATCDS

// COPYRIGHT DASSAULT SYSTEMES 2012 
/** @CAA2Required */
/*---------------------------------------------------------------------*/
/* DON'T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS  */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPPEAR AT ANY TIME */
/*---------------------------------------------------------------------*/
#define ExportedByCDSInterface DSYExport
#else
#define ExportedByCDSInterface DSYImport
#endif
#include "DSYExport.h"

#ifdef  __CATCDS
#define ExportedBySolverInterface DSYExport
#else
#define ExportedBySolverInterface DSYImport
#endif
#include "DSYExport.h"

/**
 * @nodoc
 */
#define CATICDSProtectClassCopy(Name) \
  private: \
    Name(const Name&); \
    void operator=(const Name&);
