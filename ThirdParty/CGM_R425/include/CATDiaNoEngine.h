#ifndef CATDiaNoEngine_h
#define CATDiaNoEngine_h
#include "UndoRedoUI.h"
//
// COPYRIGHT DASSAULT SYSTEMES 1996
//------------------------------------------------------------------------------
// Abstract: The class which manages Undo and Redo actions
//------------------------------------------------------------------------------
// Usage:    there is only one instance of this class by document editor
//           It is used by UNDO and REDO commands
//------------------------------------------------------------------------------#include "CATBaseUnknown.h"
#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATCallbackManager.h"
#include "CATBooleanDef.h"
#include "CATISplitAfrServices.h"

class CATNotification;
class CATUndoRequest;
class CATIUndoTransaction;
class CATUndoTempCommand;
class CATAfrUIActivationUndoRedoManager;
class CATLISTV(CATBaseUnknown_var);

class ExportedByUndoRedoUI CATDiaNoEngine : public CATBaseUnknown
{

  CATDeclareClass;

public:
  
  CATDiaNoEngine (CATBaseUnknown * iEditor = NULL);
  virtual ~CATDiaNoEngine ();

  void End();
  void CheckFirstTransaction ();
  static CATDiaNoEngine * GetNoEngine ();
  void DispatchNotification (CATNotification * iNotif);
  /*
  void CommitTransaction (int iFirstTrans, int iLastTrans);
  int GetAvailability ();
  int GetCurrentTransaction ();
  CATUndoRequest * GetLastUndoRequest ();
  CATUndoRequest * GetLastRedoRequest ();
  CATUndoRequest * GetUndoByNum (int iNum);
  CATUndoRequest * GetRedoByNum (int iNum);
  int GetUndoNumber ();
  int GetUndoNumber (CATUndoRequest * iUndo);
  int GetRedoNumber (CATUndoRequest * iUndo);
  int IsAliveTransaction (int iTrans);
  int IsEmptyTransaction (int iTrans);
  */
  CATUnicodeString GetDocumentName ();
  // Old UIActiveUndoManager
  CATBaseUnknown * GetUIActiveUndoRedoManager ();
  // UIActivationUndoRedoManager
  CATBaseUnknown* GetUIActivationUndoRedoManager ();
  int NewTransaction (const CATUnicodeString & iId, CATBoolean iForce=FALSE);
  enum UndoRedoMode {NORMAL, UNDO, REDO};
  // Reserved for CATFrmTransaction and CATCSOTransaction
  static int     _EmptyLocalTrans;
  CATBaseUnknown * _Editor;
  int            _TransCSO;

/*


  void HandleNo (int clean=1, int keepRedo=1);
  void HandleRedo ();

  // Manage max number of Undo
  static void SetCmdUndoMax (int iCmdUndoMax); // reserved for CATGeneralPerfoSettingsDialog
  int GetCmdUndoMax ();

  // Manage Normal or Undo or Redo current mode
  void SetUndoRedoMode (CATDiaNoEngine::UndoRedoMode iURMode); // reserved for CATUndoTempCommand
  CATDiaNoEngine::UndoRedoMode GetUndoRedoMode ();
  
  // Manage Availability of Undo/Redo buttons 
  void SetAvailability (int iAvailability);
  
  //-------------------------------------------------------
  //  Execute Undo and Redo Commands
  //-------------------------------------------------------
  
  
  void SetUndoTempCommand (CATUndoTempCommand * cmd); // reserved for CATUndoTempCommand
  CATUndoTempCommand * GetUndoTempCommand (); // reserved for CATECmdCommandEngine
  
  //-------------------------------------------------------
  //  Manage Stacks of Undo and Redo Requests
  //-------------------------------------------------------
  

  CATUndoRequest * GetLastUndoCommand ();

  
  void Empty ();
  void DeleteAllRedo ();
  void DeleteAllUndoCommand ();

  int StackUndo (CATUndoRequest *);
  CATUndoRequest * UnstackUndo ();
  CATUndoRequest * RemoveUndo (int);
  
  int StackRedo (CATUndoRequest *);
  CATUndoRequest * UnstackRedo ();
  CATUndoRequest * RemoveRedo (int);

  //-------------------------------------------------------
  //  Manage Model Transactions
  //-------------------------------------------------------
  
  int AddIUndoTransaction (CATIUndoTransaction * iIUndoTransCustomer, int iDoc=0, int iPos=0);
  int RemoveIUndoTransaction (CATIUndoTransaction * iIUndoTransCustomer);

  int GetCurrentTransaction (CATIUndoTransaction * iIUndoTransCustomer);

  int IsAvailableTransaction (int iTrans);
  int IsEmptyLocalTransaction (int iTrans);

  void CleanCurrentTransaction (int iRedo=0);
  void EmptyTransaction ();

  int NewTransaction (int iForce=0);
  // restricted to a list of CATIUndoTransaction objects
  int NewTransaction (CATLISTV(CATBaseUnknown_var) & iList, int iForce=NULL);
  void DeleteTransaction (int iTrans);
  int AbortTransaction (int iTrans);
  int RedoTransaction (int iTrans);
  
  void DumpTransactions ();
  void DumpUndoRequests ();

  void SetBusyTransaction (int iTrans);
  void UnsetBusyTransaction (int iTrans);
  
  //-------------------------------------------------------
  //  Reserved for special usage
  //-------------------------------------------------------

  // Lock
  int LockTransactions (int iWarning = 1); // Use by CATECmdCommandEngine only
  void UnlockTransactions (); // Use by CATECmdCommandEngine only
  void CheckStackSize (); // Use by CATECmdCommandEngine only

  // UndoRedo Title
  CATUnicodeString GetUndoTitle ();
  CATUnicodeString GetRedoTitle ();
  void ChangeUndoRedoTitle ();

  // Document name
  
  
  // Dispatch Undo/Redo notification
  
  // Reserved for CATODTEngine
  void CancelCurrentCmd ();
  
  // Reserved for ?
  // Reserved for CATSelect and CATCSO

  int NewTransaction (CATLISTV(CATBaseUnknown_var) & iList, const CATUnicodeString & iId, CATBoolean iForce=FALSE);

  // Reserved for CATAfrUIUndoRedoManager
  */
private:

  // Undoable commands
  int _stackUndoMax; // allocated size
  int _stackUndoSize; // used size
  CATUndoRequest ** _stackUndoInteractions;
  void ReallocateUndo ();
  
  // Redoable commands
  int _stackRedoMax; // allocated size
  int _stackRedoSize; // iused size
  CATUndoRequest ** _stackRedoInteractions;
  void ReallocateRedo ();
  
  // Number of Undo allowed
  int  _undoNumber;
  static int _cmdUndoMax; // maximum number of Command Undo allowed, as defined in the settings
  CATBoolean _noUndo; // Use of ManualCommand to idle Undo transiently
  
  // List of CATIUndoTransaction customers
  CATLISTV(CATBaseUnknown_var) * _IUndoTransactionCustomerList;

  // index of the oldest transaction remaining
  int _Begin;
  // indicates whether the current transaction is the very first one or not
  CATBoolean _FirstTransaction;
  // indicates whether the editor's UI-Active object has been added to Undo/Redo Management
  CATBoolean _NoActiveAdded;
  // indicates whether currently undoing, redoing or not
  UndoRedoMode _UndoRedoMode;
  // indicates whether currently dying or not
  CATBoolean _End;
  // indicates whether a DeleteAllRedo() is to be called at the end of a Redo
  CATBoolean _postponeDeleteAllRedo;
  // name of the edited document
  CATUnicodeString _documentName;

  // Multi-editors
  static CATDiaNoEngine * _lastNoEngine;
  static int _lastFirstTransaction;

  // Old UIActiveUndoManager
  CATBaseUnknown * _oldUIActiveManager;
  // UIActivationUndoRedoManager
  CATBaseUnknown * _UIActivationManager;
  
  CATUndoTempCommand * _TempCommand;
  
  int _Availability;

  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATDiaNoEngine (const CATDiaNoEngine &);
  CATDiaNoEngine & operator= (const CATDiaNoEngine &);

  static void InitIServ();

  static CATISplitAfrServices * _pIServ;
  
};

#endif

