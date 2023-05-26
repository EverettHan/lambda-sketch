#ifndef CATFrFCombDebug_H
#define CATFrFCombDebug_H
// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATFrFCombDebug: Debug infrastructure for combs and comb operations
//
//=============================================================================
// Usage notes:
//
// for programming: 
// ---------------
// - Use catfrfcombdebug() for breakpoint definition
//   on each comb creation or comb utility (to be called by any comb software)
//
// for debugging:
// -------------
//
// - Use this declaration for traces activation
//   export CATFrFCombDebug=1
// - Use this declaration for traces and callstack prints activation
//   export CATFrFCombDebug=2
//
// - Use a breakpoint on catfrfcombdebugbreakpoint() for traces and callstack management
//
// - Use a breakpoint on CATCompactCallStackManager::StackChangeBreakPoint()
//   for unique break on each call stack
//
//=============================================================================
// 22/11/11 NLD Création
//              catfrfcombdebug()
// 11/03/16 NLD Generalisation/extension
//              definition generale pour une famille de softs CATFrFFamilyDebug_Info
//              Ajout Usage notes
// 14/03/16 NLD CATFrFFamilyDebug est defini dans un fichier specifique
// 02/10/20 NLD Suppression extern "C"
//=============================================================================

#include "FrFObjects.h"
#include "CATFrFFamilyDebug.h"

//=============================================================================
typedef enum {CATFrFCombDebug_Trace = CATFrFFamilyDebug_Trace,
              CATFrFCombDebug_Start = CATFrFFamilyDebug_Start,
              CATFrFCombDebug_End   = CATFrFFamilyDebug_End
             }CATFrFCombDebug_Info;

// --------------------------------------------------------------
// for programming: breakpoint for comb creation or comb utility (to be called by any comb software)
// --------------------------------------------------------------
// extern "C"  non necessaire ici, suppression NLD021020
ExportedByFrFObjects void catfrfcombdebug(char*                iDebugText ,
                                          CATFrFCombDebug_Info Info       = CATFrFCombDebug_Trace);

// --------------------------------------------------------------

#endif
