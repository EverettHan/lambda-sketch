#ifndef CATFrFBlendDebug_H
#define CATFrFBlendDebug_H
// COPYRIGHT DASSAULT SYSTEMES 2016
//=============================================================================
//
// CATFrFBlendDebug: Debug infrastructure for blend software
//
//=============================================================================
// Usage notes:
//
// for programming: 
// ---------------
// - Use catfrfblenddebug() for breakpoint definition
//   on each blend creation or blend utility (to be called by any blend software)
//
// for debugging:
// -------------
//
// - Use this declaration for traces activation
//   export CATFrFBlendDebug=1
// - Use this declaration for traces and callstack prints activation
//   export CATFrFBlendDebug=2
//
// - Use a breakpoint on catfrfblenddebugbreakpoint() for traces and callstack management
//
// - Use a breakpoint on CATCompactCallStackManager::StackChangeBreakPoint()
//   for unique break on each call stack
//
//=============================================================================
// 14/03/16 NLD Création d'apres CATFrFCombDebug
//              catfrfblenddebug()
//              CATFrFBlendDebug_Info
// 02/10/20 NLD Suppression extern "C"
//=============================================================================

#include "FrFObjects.h"
#include "CATFrFFamilyDebug.h"

//=============================================================================
typedef enum {CATFrFBlendDebug_Trace = CATFrFFamilyDebug_Trace,
              CATFrFBlendDebug_Start = CATFrFFamilyDebug_Start,
              CATFrFBlendDebug_End   = CATFrFFamilyDebug_End
             }CATFrFBlendDebug_Info;

// --------------------------------------------------------------
// for programming: breakpoint for blend creation or blend utility (to be called by any blend software)
// --------------------------------------------------------------
// extern "C"  non necessaire ici, suppression NLD021020
ExportedByFrFObjects void catfrfblenddebug(char*                 iDebugText ,
                                           CATFrFBlendDebug_Info Info       = CATFrFBlendDebug_Trace);

// --------------------------------------------------------------

#endif
