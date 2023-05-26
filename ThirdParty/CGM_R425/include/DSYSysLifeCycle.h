// COPYRIGHT DASSAULT SYSTEMES 2011
#ifndef DSYSysLifeCycle_H
#define DSYSysLifeCycle_H

/************************************************************************/
/* Defines                                                              */
/************************************************************************/
#define DSY_SYS_LIFECYCLE_STATECHANGE_BASE                              0x800/* 1024 */
#define DSY_SYS_LIFECYCLE_STATECHANGE(p)                                (DSY_SYS_LIFECYCLE_STATECHANGE_BASE | p)

#define DSY_SYS_LIFECYCLE_SYSTEMCALL_BASE                               0x400/* 2048 */
#define DSY_SYS_LIFECYCLE_SYSTEMCALL(p)                                 (DSY_SYS_LIFECYCLE_SYSTEMCALL_BASE | p)

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/
#include <stdlib.h>
#ifdef _WINDOWS_SOURCE
# include <windows.h>
#endif  // _WINDOWS_SOURCE

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/

/************************************************************************/
/* Functions declaration                                                */
/************************************************************************/

/** @struct DSYSysLifeCycleStateChangeFlag */
typedef enum DSYSysLifeCycleStateChangeFlag
{
#ifdef DSY_SYS_LIFECYCLE_NEW_FLAG
  DSY_SYS_LIFECYCLE_STATE_CHANGE_TERMINATE                              = DSY_SYS_LIFECYCLE_STATECHANGE(0x001)
, DSY_SYS_LIFECYCLE_STATE_CHANGE_RESUME                                 = DSY_SYS_LIFECYCLE_STATECHANGE(0x002)
, DSY_SYS_LIFECYCLE_STATE_CHANGE_SUSPEND                                = DSY_SYS_LIFECYCLE_STATECHANGE(0x003)
, DSY_SYS_LIFECYCLE_STATE_LAUNCHED_BY_APP                               = DSY_SYS_LIFECYCLE_STATECHANGE(0x004)
#else // DSY_SYS_LIFECYCLE_NEW_FLAG
  DSY_SYS_LIFECYCLE_STATE_CHANGE_TERMINATE                              = 0
, DSY_SYS_LIFECYCLE_STATE_CHANGE_RESUME                                 = 1
, DSY_SYS_LIFECYCLE_STATE_CHANGE_SUSPEND                                = 2
, DSY_SYS_LIFECYCLE_STATE_LAUNCHED_BY_APP                               = 8
#endif  // DSY_SYS_LIFECYCLE_NEW_FLAG
} DSYSysLifeCycleStateChangeFlag;

/** @struct DSYSysLifeCycleSystemCallFlag */
typedef enum DSYSysLifeCycleSystemCallFlag
{
#ifdef DSY_SYS_LIFECYCLE_NEW_FLAG
  DSY_SYS_LIFECYCLE_SYSTEM_NOTIFICATION_MEMORY_WARNING                  = DSY_SYS_LIFECYCLE_SYSTEMCALL(0x001)
, DSY_SYS_LIFECYCLE_SYSTEM_NOTIFICATION_PREFS_CHANGED                   = DSY_SYS_LIFECYCLE_SYSTEMCALL(0x002)
, DSY_SYS_LIFECYCLE_SYSTEM_NOTIFICATION_RUN                             = DSY_SYS_LIFECYCLE_STATECHANGE(0x003)
#else // DSY_SYS_LIFECYCLE_NEW_FLAG
  DSY_SYS_LIFECYCLE_SYSTEM_NOTIFICATION_MEMORY_WARNING                  = 0
, DSY_SYS_LIFECYCLE_SYSTEM_NOTIFICATION_PREFS_CHANGED                   = 3
, DSY_SYS_LIFECYCLE_SYSTEM_NOTIFICATION_RUN                             = 12
#endif  // DSY_SYS_LIFECYCLE_NEW_FLAG
} DSYSysLifeCycleSystemCallFlag;

/************************************************************************/
/************************************************************************/

//=======================================================================
typedef void(*DSYSysLifeCycleCreateFunc_t)(void*);
//=======================================================================

//=======================================================================
typedef void (*DSYSysLifeCycleStateChangeFunc_t)(const int);
//=======================================================================

//=======================================================================
typedef void (*DSYSysLifeCycleSystemCallFunc_t)(const int);
//=======================================================================

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

#endif  // DSYSysLifeCycle_H
