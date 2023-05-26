#ifndef CATDSPADebug_H
#define CATDSPADebug_H

#include "DSYSysTraceSystemMigration.h"

#ifdef DSY_SYS_TRACE_SYSTEM_MIGRATION
/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/

/************************************************************************/
/* Functions declaration                                                */
/************************************************************************/

#else // DSY_SYS_TRACE_SYSTEM_MIGRATION
# include "CATTrace.h"
#endif  // DSY_SYS_TRACE_SYSTEM_MIGRATION
#endif  // CATDSPADebug_H