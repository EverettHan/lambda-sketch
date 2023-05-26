/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATFMDebug                                                           */
/*                                                                       */
/*  Usage Notes:                                                         */
/*                                                                       */
/*    Macro Definition For Debug                                         */
/*      TRAOPEN, TRAPRINT, TRAPUT                                        */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef CATFMDebug_H
#define CATFMDebug_H

// ++vxg - 11:11:03
#include "DSYSysTraceSystemMigration.h"

#ifdef DSY_SYS_TRACE_SYSTEM_MIGRATION
/************************************************************************/
/* Defines                                                              */
/************************************************************************/
# define CATDbgPrint(tracedescriptor, format, ...)                    \
  do {                                                                \
    TRAOPEN()                                                         \
                                                                      \
    register DSYSysTrace* l_pTrace = __TRAPRINT(FOCUS_MANAGER_FLAG);  \
    if ( l_pTrace != NULL ) l_pTrace->Info(format, ##__VA_ARGS__);\
  } while ( 0 )

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
//==[ CATNotifier.cpp ]==================================================
//=======================================================================
static int trace_desc = 0;
//=======================================================================

//=======================================================================
//==[ CATNotifier.cpp ]==================================================
//=======================================================================
static int* dbg_pt_flag = NULL;
//=======================================================================

//=======================================================================
// Trace object for "Focus_Manager" log.
//=======================================================================
static DSYSysTrace* s_pTrace = NULL;
//=======================================================================

//=======================================================================
//==[ CATCommandExt.cpp ]================================================
//=======================================================================
extern int _SuperDebugDesc;
//=======================================================================

//=======================================================================
//==[ CATCommandExt.cpp ]================================================
//=======================================================================
extern int* _CATCommandDebugOn;
//=======================================================================

//=======================================================================
// Trace object for "CmdSuperDebug" log.
//=======================================================================
static DSYSysTrace* s_pSuperDebugTrace = NULL;
//=======================================================================

//=======================================================================
//==[ CATRecord.cpp ]====================================================
//=======================================================================
extern int _CATRecordDebugDesc;
//=======================================================================

//=======================================================================
//==[ CATRecord.cpp ]====================================================
//=======================================================================
extern int* _CATRecordDebugOn;
//=======================================================================

//=======================================================================
// Trace object for "RecordDebug" log.
//=======================================================================
static DSYSysTrace* s_pRecordDebugTrace = NULL;
//=======================================================================

//=======================================================================
//==[ CATRecord.cpp ]====================================================
//=======================================================================
extern int _CATRecordDebugSpecDesc;
//=======================================================================

//=======================================================================
//==[ CATRecord.cpp ]====================================================
//=======================================================================
extern int* _CATRecordDebugSpecOn;
//=======================================================================

//=======================================================================
// Trace object for "RecordSpec" log.
//=======================================================================
static DSYSysTrace* s_pRecordSpecTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
inline void __TRAOPEN(void)
//=======================================================================
{
  if ( s_pTrace == NULL )
  {
    s_pTrace = new DSYSysTrace(FOCUS_MANAGER_STRG);
    if ( s_pTrace != NULL )
    {
      trace_desc = FOCUS_MANAGER_FLAG;
      dbg_pt_flag = (int *)s_pTrace;
    }
  }

  if ( s_pSuperDebugTrace == NULL )
  {
    s_pSuperDebugTrace = new DSYSysTrace(CMD_SUPER_DEBUG_STRG);
    if ( s_pSuperDebugTrace != NULL )
    {
      _SuperDebugDesc = CMD_SUPER_DEBUG_FLAG;
      _CATCommandDebugOn = (int *)s_pSuperDebugTrace;
    }
  }

  if ( s_pRecordDebugTrace == NULL )
  {
    s_pRecordDebugTrace = new DSYSysTrace(RECORD_DEBUG_STRG);
    if ( s_pRecordDebugTrace != NULL )
    {
      _CATRecordDebugDesc = RECORD_DEBUG_FLAG;
      _CATRecordDebugOn = (int *)s_pRecordDebugTrace;
    }
  }

  if ( s_pRecordSpecTrace == NULL )
  {
    s_pRecordSpecTrace = new DSYSysTrace(RECORD_SPEC_STRG);
    if ( s_pRecordSpecTrace != NULL )
    {
      _CATRecordDebugSpecDesc = RECORD_SPEC_FLAG;
      _CATRecordDebugSpecOn = (int *)s_pRecordSpecTrace;
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
  case FOCUS_MANAGER_FLAG:
    {
      l_pTrace = s_pTrace;
    }
    break;
  case CMD_SUPER_DEBUG_FLAG:
    {
      l_pTrace = s_pSuperDebugTrace;
    }
    break;
  case RECORD_DEBUG_FLAG:
    {
      l_pTrace = s_pRecordDebugTrace;
    }
    break;
  case RECORD_SPEC_FLAG:
    {
      l_pTrace = s_pRecordSpecTrace;
    }
    break;
  default:
    { }
  }

  // Done.
  return l_pTrace;
}
#else // DSY_SYS_TRACE_SYSTEM_MIGRATION
#define TRA_EXTERN
#ifdef DECLARE_VAR
#undef TRA_EXTERN
#endif

#include "CATTraMacro.h"
#include "JS0FM.h"
#include "CATSysCounter.h"

#ifndef _WINDOWS_SOURCE

#ifdef DECLARE_VAR
ExportedByJS0FM int CATFMDebug = 0;
ExportedByJS0FM int trace_desc;
ExportedByJS0FM int bidon=0;
ExportedByJS0FM int *dbg_pt_flag=&bidon;
ExportedByJS0FM int faccess = 0;
ExportedByJS0FM int fmdebug = 0;

char dbg_comment[25]="Focus Manager trace" ;

#else

ExportedByJS0FM extern int  CATFMDebug ;
ExportedByJS0FM extern int trace_desc;
ExportedByJS0FM extern int *dbg_pt_flag;
ExportedByJS0FM extern char dbg_comment[];
ExportedByJS0FM extern int  faccess ;
ExportedByJS0FM extern int  fmdebug ;
#endif


#else

#ifdef DECLARE_VAR

// lby mod
ExportedByJS0FM int CATFMDebug ;
ExportedByJS0FM int trace_desc;
ExportedByJS0FM int bidon;
ExportedByJS0FM int *dbg_pt_flag=NULL;
ExportedByJS0FM int faccess;
ExportedByJS0FM int fmdebug ;

char dbg_comment[25]="Focus Manager trace" ;

#else

// lby mod 
ExportedByJS0FM extern int bidon;

ExportedByJS0FM extern int  CATFMDebug ;
ExportedByJS0FM extern int trace_desc;
ExportedByJS0FM extern int *dbg_pt_flag;
ExportedByJS0FM extern char dbg_comment[];
ExportedByJS0FM extern int  faccess ;
ExportedByJS0FM extern int  fmdebug ;

#endif



#endif
//------------------------------------------------------------
// TRAOPEN
//------------------------------------------------------------
#ifdef _WINDOWS_SOURCE
#define TRAOPEN()                                   \
{                                                   \
  char dbg_name[16]="Focus_Manager";                \
  int dbg_init=0;                                   \
  char dbg_output[16]="FICFOCUS";                   \
  int dbg_limit=255;                                \
						    \
  CATFMDebug = 0;                                   \
  bidon=0;                                          \
  dbg_pt_flag=&bidon;                               \
  faccess = 0;                                      \
  fmdebug = 0;                                      \
  trace_desc =                                      \
  traopen( dbg_name,                                \
	   dbg_init,                                \
	   &dbg_pt_flag,                            \
	   dbg_output,                              \
	   dbg_limit,                               \
	   dbg_comment);                            \
						    \
						    \
						    \
}
#else
#define TRAOPEN()\
{                                                   \
  char dbg_name[16]="Focus_Manager";                \
  int dbg_init=0;                                   \
    char dbg_output[16]="STDOUT";                   \
  int dbg_limit=255;                                \
						    \
   trace_desc =                                     \
   traopen( dbg_name,                               \
	    dbg_init,                               \
	    &dbg_pt_flag,                           \
	    dbg_output,                             \
	    dbg_limit,                              \
	    dbg_comment);                           \
						    \
						    \
						    \
}
#endif


//------------------------------------------------------------
// TRAPUT
//------------------------------------------------------------
#define TRAPUT(tracedescriptor,level,message)                      \
{                                                                  \
  if (dbg_pt_flag && *dbg_pt_flag )                                \
    traput ( trace_desc, level,                                    \
	       tracedescriptor#message"\n");                       \
}

//------------------------------------------------------------
// TRAPRINT
//------------------------------------------------------------
#define TRAPRINT(tracedescriptor,level,message,format,variable)    \
{                                                                  \
  if (dbg_pt_flag && *dbg_pt_flag )                                \
    traprint ( trace_desc, level,                                  \
		 tracedescriptor#message" : "#format"\n",variable);\
}

#endif  // DSY_SYS_TRACE_SYSTEM_MIGRATION
// --vxg - 11:11:03

#endif
