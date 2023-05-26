#ifndef CATSYSCHECKCATSTART_H
#define CATSYSCHECKCATSTART_H

/* COPYRIGHT DASSAULT SYSTEMES 2001 */
#include        "JS0LIB.h"  // exported by..
#include        "CATLib.h"
/**
 * Check if the currrent process was launched by CATSTART.
 * Return CATLibSuccess if true, CATLibError otherwise
 */
ExportedByJS0LIB CATLibStatus IsLaunchedByCatstart();

#endif

