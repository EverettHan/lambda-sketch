#ifdef	__LatticePolyOperators

#define ExportedByLatticePolyOperators DSYExport
#else
#define ExportedByLatticePolyOperators DSYImport
#endif

#ifdef _WINDOWS_SOURCE
#define CONFORMAL_LATTICE // To deactivate the ConformalLattice functionalities when compiling on OS other than WINDOWS
#endif

#include "DSYExport.h"
