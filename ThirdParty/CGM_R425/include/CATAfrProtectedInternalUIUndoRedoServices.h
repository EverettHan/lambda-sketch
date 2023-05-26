#ifndef CATAfrProtectedInternalUIUndoRedoServices_H
#define CATAfrProtectedInternalUIUndoRedoServices_H
#include "UndoRedoUI.h"

// COPYRIGHT DASSAULT SYSTEMES 2007
//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR UI UNDO/REDO INFRASTRUCTURE AND TESTS --------
//---------------------------------------------------------------------------

#include "CATBoolean.h"
#include "CATOmbUndoRedoDefs.h"

class CATFrmEditor;
class CATError;
class CATUndoTempCommand;
class CATUndoRequest;

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- AfrFoundation\CATAfrEditAndUIActive.m\src\CATExtIUIActivate.cpp
//--- AfrFoundation\CATAfrUndoRedo.m\src\CATActiveObjectUndo.cpp
//--- AfrFoundation\CATAfrUndoRedo.m\src\CATDiaNoEngine.cpp
//---------------------------------------------------------------------------
/**
 * Indicates whether the old UI-Activation Undo/Redo management is active.
 * @return
 * Returns TRUE if the old UI-Activation Undo/Redo management is active
 * (for records before october 2007 only).
 */
ExportedByUndoRedoUI
CATBoolean CATAfrIsOldUIActivationManagementActive ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- AfrFoundation\AfrUndoRedo.m\src\CATAfrUndoRedoController.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrEmptyUndoStack ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//--- ApplicationFrame.tst\CD0YESNO.m\src\tester.cpp
//--- DialogEngine.tst\DI0HPLT.m\src\CATComHTestUndo.cpp
//--- DialogEngine.tst\UndoPurge.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrEmptyRedoStack ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- ApplicationFrame.tst\CD0DUNDO.m\src\CATDeleteUndoDialog.cpp
//--- ApplicationFrame.tst\CD0YESNO.m\src\tester.cpp
//--- DialogEngine.tst\UndoPurge.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrFlushPurgeableUndoSteps ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- AfrFoundation.tst\AfrUnitTests.m\src\CATAfrUIUndoRedoManager_UT.cpp
//--- ApplicationFrame.tst\CD0DUNDO.m\src\CATDeleteUndoDialog.cpp
//--- ApplicationFrame.tst\CD0YESNO.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrGetLastUndoCommand (CATUndoRequest *& oUndo);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATDiaActionEngine.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrManageUndoErrorCaught (CATError * iError);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATDiaActionEngine.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrManageRedoErrorCaught (CATError * iError);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrPullUndoRedoError (OmbUndoRedoErrorId & oErrorId);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//--- DialogEngine\DI0STATE.m\src\CATUndoableCommand.cpp
//--- AfrFoundation.tst\AfrUnitTests.m\src\CATAfrUIUndoRedoManager_UT.cpp
//--- ApplicationFrame.tst\CD0YESNO.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrGetUIUndoStackCapacity (int & oValue);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//--- DialogEngine\DI0STATE.m\src\CATUndoableCommand.cpp
//--- ApplicationFrame.tst\CD0YESNO.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrSetUIUndoStackCapacity (int iValue, CATBoolean iCheckSize=TRUE);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrCheckUIUndoStackSize ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\CATDegEditAgent.m\src\CATEditAgent.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrDeleteLastUndo ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//---------------------------------------------------------------------------
/**
 * Indicates whether an Undo has been performed since the last idle.
 * @return
 * Returns TRUE if an Undo has been performed since the last idle.
 */
ExportedByUndoRedoUI
HRESULT CATAfrUndoPerformedSinceLastIdle ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrGetUndoTempCommand (CATUndoTempCommand *& oUndoTempCmd);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//--- DialogEngine.tst\UndoPurge.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrIsAliveTransaction (int iIndex);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//--- DialogEngine.tst\UndoPurge.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrIsAvailableTransaction (int iIndex);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//--- DialogEngine.tst\UndoPurge.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrIsEmptyLocalTransaction (int iIndex);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine.tst\UndoPurge.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrUndoTransaction (int iIndex);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine.tst\UndoPurge.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrRedoTransaction (int iIndex);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine.tst\UndoPurge.m\src\tester.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrSetBusyTransaction (int iIndex);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- AfrFoundation\CATAfrEditAndUIActive.m\src\CATActivationContext.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrHideUndoStack ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- AfrFoundation\CATAfrEditAndUIActive.m\src\CATActivationContext.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrShowUndoStack ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- DialogEngine\DI0STATE.m\src\CATECmdCommandEngine.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrSetFirstCommandTransaction (CATFrmEditor * iEditor, int iIndex);

//---------------------------------------------------------------------------
//Give the last unqiue ID set to an undo step
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
int CATAfrGetLastCreatedUndoStepUniqueId ();

//---------------------------------------------------------------------------
//Give the last unqiue ID set to an undo step
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
int CATAfrGetLastUndoStepUniqueId ();

//---------------------------------------------------------------------------
//Give the last unqiue ID set to an undo step
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
int CATAfrGetLastRedoStepUniqueId ();

//---------------------------------------------------------------------------
/**
 * Gets the oldest item in the Undo stack. (CAUTION it's not neccessary the first element
 * @param oUndo
 *  The oldest item in the Undo stack
 * @return
 * Returns S_OK if oldest undo request found E_FAIL otherwise.
 */
ExportedByUndoRedoUI
HRESULT CATAfrGetOldestUndoRequest (CATUndoRequest *& oUndo);

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- VB Infra
//--- CATIAApplicationFrame\CD0AUTOSTART.m\src\CATIAApplicationImpl.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrDisableNewTransaction ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- VB Infra
//--- CATIAApplicationFrame\CD0AUTOSTART.m\src\CATIAApplicationImpl.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrEnableNewTransaction ();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- VB Undo Infra
//--- AutomationInfrastructure\CATScriptProgramm.m\src\CATScriptFctCallBase.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrEnableInfiniteStack();

//---------------------------------------------------------------------------
//--- DO NOT USE, RESERVED FOR :
//--- VB Infra
//--- AutomationInfrastructure\CATScriptProgramm.m\src\CATScriptFctCallBase.cpp
//---------------------------------------------------------------------------
ExportedByUndoRedoUI
HRESULT CATAfrDisableInfiniteStack();


#endif
 
