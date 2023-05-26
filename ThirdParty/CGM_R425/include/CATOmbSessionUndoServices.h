/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//  July 2006  Creation: RJS
//===================================================================

#ifndef CATOmbSessionUndoServices_H
#define CATOmbSessionUndoServices_H
/**
* @level Protected 
* @usage U1
*/
#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATIModelUndoRedoManager.h"
#include "CATIAV5Level.h"
#include "CATOmbUndoRedoController.h"
class CATUnicodeString;
/**
* Provide a client from Model_UndoRedoEngine to handle all UndoRedo operations requested by UndoRedoEngine.
*	@param iSubscriber
*		The object requesting this client. It must be a document.
*	@param iEditorName
*		The related editor from which UndoRedo operations will be performed.
*	@param ioClient
*		The handle provided by Model_UndoRedoEngine.
*	@return
*		An HRESULT value:
*   <br><b>Legal values</b>:
*   <dl>
*     <dt><tt>S_OK</tt></dt>
*     <dd>The handle was successfully provided.</dd>
*     <dt><tt>E_NOINTERFACE</tt></dt>
*     <dd>The subscriber has no bindings with Model_UndoRedoEngine to get a handle<./dd>
*     <dt><tt>E_INVALIDARG</tt></dt>
*     <dd>The subscriber is invalid.</dd>
*     <dt><tt>E_OUTOFMEMORY</tt></dt>
*     <dd>Not enough memory to provide a client to manage UndoRedo operations.</dd>
*     <dt><tt>E_UNEXPECTED</tt></dt>
*     <dd>Some unexpected error occured.</dd>
*   </dl>
*/
#if defined (CATIAR208)
#if !defined(_WINDOWS_SOURCE) || defined (__CATAfrUndoRedo) || defined (__AC0XXLNK) || defined (__TestSessionUndo)|| defined (__TestSessionUndoVsOpen)|| defined (__TestSessionUndoServices) || defined (__TestSessionUndoController) || defined (__CATOmdUndoRedoTestEngine)
ExportedByAC0XXLNK  HRESULT GetUndoRedoClient(CATBaseUnknown* iSubscriber, CATUnicodeString& iEditorName, CATIModelUndoRedoManager_var& ioClient);
ExportedByAC0XXLNK  HRESULT GetUndoRedoClient(CATOmbUndoRedoController* iController, CATUnicodeString& iEditorName, CATIModelUndoRedoManager_var& ioClient);
#endif
#else
#if !defined(_WINDOWS_SOURCE) || defined (__CATAfrUndoRedo) || defined (__AC0XXLNK) || defined (__TestSessionUndo) || defined (__TestSessionUndoObserver) || defined (__TestMemento)
#if defined(__TestMemento)
#pragma message("WARNING : unautorized access you will get a build error on R208") 
#endif
ExportedByAC0XXLNK  HRESULT GetUndoRedoClient(CATBaseUnknown* iSubscriber, CATUnicodeString& iEditorName, CATIModelUndoRedoManager_var& ioClient);
#endif
#endif
#endif


