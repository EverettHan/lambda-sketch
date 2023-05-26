#ifndef CATSetDebug_H
#define CATSetDebug_H

#include "CATTrace.h"
#include "DSYSysTraceSystemMigration.h"

#ifdef DSY_SYS_TRACE_SYSTEM_MIGRATION
/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#define TRAINIT_EXTERN(a)
#define TRAWRITE(a, m)

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/

/************************************************************************/
/* Functions declaration                                                */
/************************************************************************/

//=======================================================================
inline void __TRAOPEN(void)
//=======================================================================
{
}

//=======================================================================
inline DSYSysTrace* __TRAPRINT(int iFileDescriptor)
//=======================================================================
{
  register DSYSysTrace* l_pTrace = NULL;

  // Done.
  return l_pTrace;
}

#else // DSY_SYS_TRACE_SYSTEM_MIGRATION
# include "CATTraMacro.h"
#endif  // DSY_SYS_TRACE_SYSTEM_MIGRATION
#endif  // CATSetDebug_H
