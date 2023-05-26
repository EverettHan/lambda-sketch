#ifndef CATCOMPDebug_H
#define CATCOMPDebug_H

#include "DSYSysTraceSystemMigration.h"
#if !defined(FILE_NO_EXT_LINK) 
#include "CATLib.h" // CATGetEnv
#endif

// IMPORTANT: both implementations are not thread safe when traces are activated... 
// TODO Migrate to DSYSysTrace?
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
//==[ CompObjRep.cpp ]===================================================
//=======================================================================
extern int* CompObjDbg;
//=======================================================================

//=======================================================================
//==[ CompObjRep.cpp ]===================================================
//=======================================================================
extern int CompObjfd;
//=======================================================================

//=======================================================================
// Trace object for "STGObj" log.
//=======================================================================
static DSYSysTrace* s_pCATCOMPDebugTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
//==[ CATAPI.cpp ]=======================================================
//=======================================================================
extern int* IntAct;
//=======================================================================

//=======================================================================
//==[ CATAPI.cpp ]=======================================================
//=======================================================================
extern int Intfd;
//=======================================================================

//=======================================================================
// Trace object for "STGINTERFACE" log.
//=======================================================================
static DSYSysTrace* s_pCATSTGInterfaceTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
//==[ TOC.cpp ]==========================================================
//=======================================================================
extern int* DumpActif;
//=======================================================================

//=======================================================================
//==[ TOC.cpp ]==========================================================
//=======================================================================
extern int Dumpfd;
//=======================================================================

//=======================================================================
// Trace object for "TOCDUMP" log.
//=======================================================================
static DSYSysTrace* s_pTOCDUMPTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
inline void __TRAOPEN(void)
//=======================================================================
{
  if ( s_pCATCOMPDebugTrace == NULL )
  {
    s_pCATCOMPDebugTrace = new DSYSysTrace(COMP_DEBUG_STRG);
    if ( s_pCATCOMPDebugTrace != NULL )
    {
      CompObjfd = COMP_DEBUG_FLAG;
      CompObjDbg = (int *)s_pCATCOMPDebugTrace;
    }
  }

  if ( s_pCATSTGInterfaceTrace == NULL )
  {
    s_pCATSTGInterfaceTrace = new DSYSysTrace(STGINTERFACE_DEBUG_STRG);
    if ( s_pCATCOMPDebugTrace != NULL )
    {
      Intfd = STGINTERFACE_DEBUG_FLAG;
      IntAct = (int *)s_pCATSTGInterfaceTrace;
    }
  }

  if ( s_pTOCDUMPTrace == NULL )
  {
    s_pTOCDUMPTrace = new DSYSysTrace(TOCDUMP_DEBUG_STRG);
    if ( s_pTOCDUMPTrace != NULL )
    {
      Dumpfd = TOCDUMP_DEBUG_FLAG;
      DumpActif = (int *)s_pTOCDUMPTrace;
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
  case COMP_DEBUG_FLAG:
    {
      l_pTrace = s_pCATCOMPDebugTrace;
    }
    break;
  case STGINTERFACE_DEBUG_FLAG:
    {
      l_pTrace = s_pCATSTGInterfaceTrace;
    }
    break;
  case TOCDUMP_DEBUG_FLAG:
    {
      l_pTrace = s_pCATCOMPDebugTrace;
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

#if !defined(FILE_NO_EXT_LINK) 

/** @nodoc C++ pattern singleton to avoid init order fiasco etc... */
#define __CATCOMPTraceImpl(trace_name)  \
    struct Data {                   \
        Data() {                    \
            m_DebugActif = nullptr; \
            m_DbgDesc = traopen(trace_name,0, &m_DebugActif, "STDOUT", 1024, "");\
        }\
        int *m_DebugActif;\
        int  m_DbgDesc;\
    };\
    static struct Data s_DebugTrace;  /* static unique to the module (Dll/Exe) */\
    bool bActive = (s_DebugTrace.m_DebugActif != nullptr) && (*s_DebugTrace.m_DebugActif != 0);\
    return (bActive) ? s_DebugTrace.m_DbgDesc : -1

inline int DebugDescSTGI() {
    __CATCOMPTraceImpl("STGINTERFACE");
}

inline int DebugDescTOC() {
    __CATCOMPTraceImpl("TOCDUMP");
}

inline int DebugDescSTGO() {
    __CATCOMPTraceImpl("STGObj");
}

#endif  // NOT FILE_NO_EXT_LINK 

#endif  // DSY_SYS_TRACE_SYSTEM_MIGRATION




inline char CATSTGFormat()
{
    static char s_CATSTGFormat = []() 
    {
        char l_CATSTGFormat = 'D';
#ifdef _WINDOWS_SOURCE
#ifndef FILE_NO_EXT_LINK
        const char *pVar = CATGetEnv("STGFORMAT");
#else
        const char *pVar = getenv("STGFORMAT");
#endif
        if (pVar)
            memcpy(&l_CATSTGFormat,pVar,1);
#endif  // _WINDOWS_SOURCE
        return l_CATSTGFormat;
    }();    
    return s_CATSTGFormat;
}


#endif  // CATCOMPDebug_H
