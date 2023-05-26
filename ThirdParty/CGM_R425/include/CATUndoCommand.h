#ifndef CATUndoCommand_h
#define CATUndoCommand_h
#include "UndoRedoUI.h"

// COPYRIGHT DASSAULT SYSTEMES 1996-2018

//------------------------------------------------------------------------------
// The base class for a command Undo step object.
//------------------------------------------------------------------------------
// This class encapsulates a CATCommandGlobalUndo object.
//------------------------------------------------------------------------------
// Standard use :
//
//  OmbUndoRedoContext context; // default context
//  CATCommandGlobalUndo * globalUndo = ... // cf CATCommandGlobalUndo class to know how to use it
//  CATUndoCommand * undoRequest = CATUndoCommand::Create("NLS title describing the step",globalUndo,context);
//  if (undoRequest)
//  {
//    ...
//  }
//------------------------------------------------------------------------------
// Derivation :
//
//  Calling the CATUndoRequest::Manage method after creating a CATUndoCommand instance is mandatory
//  in order to add it in the UI Undo stack.
//  So it is strongly recommended to create a Create static method as for the base class so that it is easier to use.
//------------------------------------------------------------------------------
#include "CATUndoRequest.h"
#include "CATString.h"

class CATCommand;
class CATCommandGlobalUndo;
class CATUnicodeString;
class OmbUndoRedoContext; // defined in CATOmbUndoRedoDefs.h

class ExportedByUndoRedoUI CATUndoCommand : public CATUndoRequest
{
  
  CATDeclareClass;
  
public:

  static CATUndoCommand * Create (const CATUnicodeString & iTitle,
                                  CATCommandGlobalUndo * iGlobalUndo,
                                  OmbUndoRedoContext & iContext,
                                  CATBoolean iLocalSave=TRUE);

  static void ResetLastRepeatedCommand();
  static void SetLastRepeatedCommand(const CATString& iLastRepeatedCmdName);
  virtual ~CATUndoCommand ();
  
  //-------------------------------------------------------
  //  For internal use only 
  //------------------------------------------------------- 
  
  virtual void BeforeUndoCommand ();
  virtual void BeforeRedoCommand ();
  virtual void AfterUndoCommand ();
  virtual void AfterRedoCommand ();
  
  virtual int RedoRegistered ();

private:

  CATUndoCommand (const CATUnicodeString & iTitle,
                  CATCommandGlobalUndo * iGlobalUndo);
  
  CATCommandGlobalUndo * _object;
  static CATString		 _lastRepeatedCommand;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATUndoCommand ();
  CATUndoCommand (const CATUndoCommand &);
  CATUndoCommand & operator= (const CATUndoCommand &);
  
};

#endif

 
