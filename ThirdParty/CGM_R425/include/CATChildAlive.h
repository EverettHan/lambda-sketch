/*
// COPYRIGHT DASSAULT SYSTEMES 1999
*/


#ifndef CATPROCSERVICES_H
#define CATPROCSERVICES_H

#include "JS0LIB.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @nodoc */
ExportedByJS0LIB CATLibStatus CATIsChildAlive (int pid, int *exitStatus,
					       int *fini);
  


#ifdef __cplusplus
};
#endif

#endif
