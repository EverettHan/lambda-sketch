#ifndef CATUndoTempCommand_h
#define CATUndoTempCommand_h
#include "UndoRedoUI.h"
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2000-2008
//------------------------------------------------------------------------------
// fw AfrFoundation
// CATAfrUndoRedo.m
// protected
//------------------------------------------------------------------------------
#include "CATCommand.h"

class CATNotification;

class ExportedByUndoRedoUI CATUndoTempCommand : public CATCommand
{

  CATDeclareClass;
  
public:
  
  CATUndoTempCommand (int iUndo1Redo2);
  ~CATUndoTempCommand ();
  
  void SetKeepRedo (int iKeepRedo);
  
  CATStatusChangeRC Activate (CATCommand * FromClient,
                              CATNotification * EvtDat);
  
private:
  
  int _UndoRedo;
  int _KeepRedo;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATUndoTempCommand ();
  CATUndoTempCommand (const CATUndoTempCommand &);
  CATUndoTempCommand & operator= (const CATUndoTempCommand &);
  
};

#endif
