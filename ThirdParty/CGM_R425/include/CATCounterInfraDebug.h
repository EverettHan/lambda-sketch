#ifndef CATCounterInfraDebug_H
#define CATCounterInfraDebug_H

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

//=======================================================================
//==[ CATSysCounterInfra.cpp ]===========================================
//=======================================================================
extern int* S_TraceActive;
//=======================================================================

//=======================================================================
//==[ CATSysCounterInfra.cpp ]===========================================
//=======================================================================
extern int S_FdTrace;
//=======================================================================

//=======================================================================
// Trace object for "CounterInfraTrace" log.
//=======================================================================
static DSYSysTrace* s_pCounterInfraDebugTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
inline void __TRAOPEN(void)
//=======================================================================
{
  if ( s_pCounterInfraDebugTrace == NULL )
  {
    s_pCounterInfraDebugTrace = new DSYSysTrace(COUNTERINFRA_DEBUG_STRG);
    if ( s_pCounterInfraDebugTrace != NULL )
    {
      S_FdTrace = COUNTERINFRA_DEBUG_FLAG;
      S_TraceActive = (int *)s_pCounterInfraDebugTrace;
    }
  }
}

//=======================================================================
inline DSYSysTrace* __TRAPRINT(int iFileDescriptor)
//=======================================================================
{
  register DSYSysTrace* l_pTrace = NULL;

  switch( iFileDescriptor )
  {
  case COUNTERINFRA_DEBUG_FLAG:
    {
      l_pTrace = s_pCounterInfraDebugTrace;
    }
    break;
  default:
    { }
  }

  // Done.
  return l_pTrace;
}
#else // DSY_SYS_TRACE_SYSTEM_MIGRATION
# include "CATTraMacro.h"
# include "CATSysCounterInfra.h"
#endif  // DSY_SYS_TRACE_SYSTEM_MIGRATION
#endif  // CATCounterInfraDebug_H
