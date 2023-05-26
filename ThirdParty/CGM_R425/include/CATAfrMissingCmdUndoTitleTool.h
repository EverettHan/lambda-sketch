#ifndef CATAfrMissingCmdUndoTitleTool_H
#define CATAfrMissingCmdUndoTitleTool_H
#include "CATAfrFoundation.h"

// COPYRIGHT DASSAULT SYSTEMES 2016

#include "CATString.h"
#include "CATBoolean.h"


//---------------------------------------------------------------------------
/**
 * Dump the traces store for missing undoTitle on CATStateCommand used during this execution
 * Terminate the program with code 21 if needed
 */
ExportedByCATAfrFoundation void CATAfrAssertAndDumpMissingCmdUndoTitles();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdAgentEngine.cpp
//--- iTrace: Trace of the missing undo title for a CATStateCommand
//--- iIsError: Specify if the programm will assert with code 21 at its end or not (depends on the missing undo title gravity)
//---------------------------------------------------------------------------
ExportedByCATAfrFoundation void CATAfrAddTraceForMissingCmdUndoTitle(CATString iTrace, CATBoolean iIsError = FALSE);


#endif

