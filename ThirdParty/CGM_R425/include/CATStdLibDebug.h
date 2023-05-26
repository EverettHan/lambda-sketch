#ifndef CATStdLibDebug_H
#define CATStdLibDebug_H

#include "DSYSysTraceSystemMigration.h"

#ifdef DSY_SYS_TRACE_SYSTEM_MIGRATION
/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#undef TRAINDEV
#define TRAINDEV( a, b )

#undef TRAINDEV_EXTERN
#define TRAINDEV_EXTERN( a )

#undef TRAWDEV
#define TRAWDEV(a, b)

#undef TRAWDEVLN
#define TRAWDEVLN(a,b)

#undef TRA_IS_ACTIVE_DEV
#define TRA_IS_ACTIVE_DEV(a)                                          \
  CATDevelopmentStage(NULL)

#undef TRAWDEVLLN
#define TRAWDEVLLN(a,b,c) 

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
//==[ CATSysDLNameSettingCtrl.cpp]=======================================
//=======================================================================
extern int* DbgAct;
//=======================================================================

//=======================================================================
//==[ CATSysDLNameSettingCtrl.cpp]=======================================
//=======================================================================
extern int Dbfd;
//=======================================================================

//=======================================================================
// Trace object for "DLName" log.
//=======================================================================
static DSYSysTrace* s_pDLNameTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
inline void __TRAOPEN(void)
//=======================================================================
{
  if ( s_pDLNameTrace == NULL )
  {
    s_pDLNameTrace = new DSYSysTrace(DLNAME_DEBUG_STRG);
    if ( s_pDLNameTrace != NULL )
    {
      Dbfd = DLNAME_DEBUG_FLAG;
      DbgAct = (int *)s_pDLNameTrace;
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
  case DLNAME_DEBUG_FLAG:
    {
      l_pTrace = s_pDLNameTrace;
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
# include "CATSysCounter.h"
#endif  // DSY_SYS_TRACE_SYSTEM_MIGRATION
#endif  // CATStdLibDebug_H
