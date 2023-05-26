#ifndef CATSysStrtok_H
#define CATSysStrtok_H
/*
//COPYRIGHT DASSAULT SYSTEMES 2001 
*/
#include "JS0STDLIB.h"


#ifdef __cplusplus
extern "C" 
{
#endif

/**
 * Equivalent of strtok_r useable on all operating systems
 */
ExportedByJS0STDLIB char * CATSysStrtok( char * orig, const char * sep, char ** ptr);

#ifdef __cplusplus
}
#endif


#endif
