#ifndef CATBaseUnknownDebug_H
#define CATBaseUnknownDebug_H

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
//==[ CATBaseUnknown_LibraryManagement.cpp ]=============================
//=======================================================================
extern int* DebugActif;
//=======================================================================

//=======================================================================
//==[ CATBaseUnknown_LibraryManagement.cpp ]=============================
//=======================================================================
extern int Dbgdescri;
//=======================================================================

//=======================================================================
// Trace object for "OleDebug" log.
//=======================================================================
static DSYSysTrace* s_pOleDebugTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
//==[ CATBaseUnknown_LibraryManagement.cpp ]=============================
//=======================================================================
extern int* DebugActif; // !!!!!!!!!!!!!
//=======================================================================

//=======================================================================
//==[ CATBaseUnknown_LibraryManagement.cpp ]=============================
//=======================================================================
extern int DebugDescri;
//=======================================================================

//=======================================================================
// Trace object for "DicoString" log.
//=======================================================================
static DSYSysTrace* s_pDicoStringTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
//==[ CATGetEntryPoint.cpp ]=============================================
//=======================================================================
extern int* ActivateDebug;
//=======================================================================

//=======================================================================
//==[ CATGetEntryPoint.cpp ]=============================================
//=======================================================================
extern int DebugDesc;
//=======================================================================

//=======================================================================
// Trace object for "InterfaceDebug" log.
//=======================================================================
static DSYSysTrace* s_pInterfaceDebugTrace = NULL;
//=======================================================================

/************************************************************************/
/************************************************************************/

//=======================================================================
inline void __TRAOPEN(void)
//=======================================================================
{
  if ( s_pOleDebugTrace == NULL )
  {
    s_pOleDebugTrace = new DSYSysTrace(OLE_DEBUG_STRG);
    if ( s_pOleDebugTrace != NULL )
    {
      Dbgdescri = OLE_DEBUG_FLAG;
      DebugActif = (int *)s_pOleDebugTrace;
    }
  }

  if ( s_pDicoStringTrace == NULL )
  {
    s_pDicoStringTrace = new DSYSysTrace(DICOSTRING_DEBUG_STRG);
    if ( s_pDicoStringTrace != NULL )
    {
      DebugDescri = DICOSTRING_DEBUG_FLAG;
      DebugActif = (int *)s_pDicoStringTrace;
    }
  }

  if ( s_pInterfaceDebugTrace == NULL )
  {
    s_pInterfaceDebugTrace = new DSYSysTrace(INTERFACE_DEBUG_STRG);
    if ( s_pInterfaceDebugTrace != NULL )
    {
      DebugDesc = INTERFACE_DEBUG_FLAG;
      ActivateDebug = (int *)s_pInterfaceDebugTrace;
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
  case OLE_DEBUG_FLAG:
    {
      l_pTrace = s_pOleDebugTrace;
    }
    break;
  case DICOSTRING_DEBUG_FLAG:
    {
      l_pTrace = s_pDicoStringTrace;
    }
    break;
  case INTERFACE_DEBUG_FLAG:
    {
      l_pTrace = s_pInterfaceDebugTrace;
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
#endif  // CATBaseUnknownDebug_H