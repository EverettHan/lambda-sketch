#ifndef CATCBAKDebug_H
#define CATCBAKDebug_H

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
//==[ CATEventSubscriber.cpp ]===========================================
//=======================================================================
static int* CATEventSubscriber_DebugOn = NULL;
//=======================================================================

//=======================================================================
//==[ CATEventSubscriber.cpp ]===========================================
//=======================================================================
static int CATEventSubscriber_DebugDesc = 0;
//=======================================================================

//=======================================================================
// Trace object for "CallbackDebug" log.
//=======================================================================
static DSYSysTrace* s_pCallbackDebugTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
inline void __TRAOPEN(void)
//=======================================================================
{
  if ( s_pCallbackDebugTrace == NULL )
  {
    s_pCallbackDebugTrace = new DSYSysTrace(CALLBACK_DEBUG_STRG);
    if ( s_pCallbackDebugTrace != NULL )
    {
      CATEventSubscriber_DebugDesc = CALLBACK_DEBUG_FLAG;
      CATEventSubscriber_DebugOn = (int *)s_pCallbackDebugTrace;
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
  case CALLBACK_DEBUG_FLAG:
    {
      l_pTrace = s_pCallbackDebugTrace;
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


// ++ik8 21:05:05 Code rewrite in order to fix data races in multithreaded scenarios, 
// while maintaining single-thread performance.
// Instead of using a magic static, which overhead(*) is measurable in the context of CATEventSubscriber(**), 
// use a regular POD static, initialized in CTORs and various entry points via thread-safe "std::call_once" routine
// 
// (*)  cost due to the hidden guard that protects the magic static from concurrent initialization
// (**) cf. ODT tCATCallbackManagerMT

struct TracerSCBAK {
    friend bool CATEvFirstTime();
    friend int  DebugDescSCBAK();
    friend int  DebugDescSCBAK_EvenIfNotActive();
private:
    int *m_DebugActif;
    int  m_DbgDesc;
    static TracerSCBAK s_Inst;
};

inline int DebugDescSCBAK() {
    TracerSCBAK const & s_DebugTrace = TracerSCBAK::s_Inst;
    bool bActive = (s_DebugTrace.m_DebugActif != nullptr) && (*s_DebugTrace.m_DebugActif != 0);
    return (bActive) ? s_DebugTrace.m_DbgDesc : -1;
}

inline int DebugDescSCBAK_EvenIfNotActive() {
    return TracerSCBAK::s_Inst.m_DbgDesc;
}
// ++ik8 21:05:05

#endif  // DSY_SYS_TRACE_SYSTEM_MIGRATION
#endif  // CATCBAKDebug_H
