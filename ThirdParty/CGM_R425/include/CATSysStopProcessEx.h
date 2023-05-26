#ifndef CATSysStopProcess_H
#define CATSysStopProcess_H
/***
 *** CATSysStopProcessEx allows to request  a process submitted with
 *** CATStartProcess to stop its execution.
 ***                                         
 *** CATSysStopProcessEx is an improvement of CATStopProcess as it
 *** allows the caller that it want a logical exit instead of a violent 
 *** exit                                                                
 ***/
#include "JS0STDLIB.h"
#include "CATLib.h"

#define CATSysStopStandard 0 

#define CATSysStopLogical  1 

#ifdef __cplusplus
extern "C" 
{
#endif

ExportedByJS0STDLIB CATLibStatus CATSysStopProcessEx (int pid, int iFlags);

#ifdef __cplusplus
}
#endif

#endif
