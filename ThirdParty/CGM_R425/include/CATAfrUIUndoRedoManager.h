#ifndef CATAfrUIUndoRedoManager_h
#define CATAfrUIUndoRedoManager_h
#include "UndoRedoUI.h"
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2006
//------------------------------------------------------------------------------
// fw AfrFoundation
// CATAfrUndoRedo.m
// private
//------------------------------------------------------------------------------
// Abstract: CATAfrUIUndoRedoManager is the class which manages Undo and Redo
//           at the UI level.
//------------------------------------------------------------------------------
// Usage:    this class is static.
//           It is used by DialogEngine to stack Undo and Redo requests.
//           It is used by UNDO and REDO commands.
//           It should not be directly used by applications, which should use CATAfrUIUndoRedoServices
//------------------------------------------------------------------------------
#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATCallbackManager.h"
#include "CATBoolean.h"
#include "CATOmbUndoRedoDefs.h"
#include "CATISplitAfrServices.h"

class CATDiaNoEngine;
class CATCommand;
class CATUndoRequest;
class CATAfrUITransaction;
class CATAfrUndoRedoController;
class CATIModelUndoRedoManager;
class CATUndoTempCommand;
class CATLISTV(CATBaseUnknown_var);
class CATLISTP(CATBaseUnknown);
class CATLISTP(CATAfrUITransaction);
class CATError;
class CATCommand;

class ExportedByUndoRedoUI CATAfrUIUndoRedoManager : public CATBaseUnknown
{

	CATDeclareClass;

public:

	CATAfrUIUndoRedoManager(int iCore = 0);
	virtual ~CATAfrUIUndoRedoManager();

	/**
	* Safer life cycle management.
	*/
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();

	/**
	* Indicates whether Session Undo is active.
	*/
	static CATBoolean IsActive(int iCore = 0);

	/**
	* Gets manager instance which subscribes to some notifications.
	*/
	static CATAfrUIUndoRedoManager* GetUndoRedoManager();

	/**
	* Gets callback manager to subscribe to UI Undo/Redo notifications.
	*/
	static CATCallbackManager* GetUIUndoRedoCallbackManager();

	// Manage Normal or Undo or Redo current mode
	enum UndoRedoMode { NORMAL, UNDO, REDO };
	static CATAfrUIUndoRedoManager::UndoRedoMode GetUndoRedoMode();
	static CATBoolean IsUndoPending();
	static CATBoolean IsRedoPending();

	// Manage max number of Session Undo Requests
	static void SetCmdUndoMax(int iCmdUndoMax, CATBoolean iCheckSize = TRUE);
	static int GetCmdUndoMax();

	// Manage Stack Full Warning
	// Reserved for CATGeneralPerfoSettingsDialog
	static void SetStackFullWarningRequestedByUser(int iStackFullWarning);

	// Manage Availability of Undo/Redo buttons 
	static void SetAvailability(CATBoolean iAvailability);
	static CATBoolean GetAvailability();

	//-------------------------------------------------------
	//  Execute Undo and Redo Commands: return true if exclusive undo/redo, false otherwise
	//-------------------------------------------------------

	static HRESULT ExecuteUndo(CATBoolean iClean = TRUE, CATBoolean iKeepRedo = TRUE, int* oNumInRedoStack = NULL);
	static HRESULT ExecuteRedo(int* oNumInUndoStack = NULL);

	//-------------------------------------------------------
	//  Manage Stacks of Undo and Redo Requests
	//-------------------------------------------------------

	/**
	* Gets number of UndoRequests in Undo stack.
	*/
	static int GetUndoCount();
	/**
	* Gets UndoRequest index in Undo stack (0...N).
	*/
	static int GetUndoNumber(CATUndoRequest* iUndo);
	/**
	* Gets UndoRequest index in Redo stack (0...N).
	*/
	static int GetRedoNumber(CATUndoRequest* iUndo);

	static CATUndoRequest* GetLastActiveObjectUndo();
	static CATUndoRequest* GetLastUndoCommand();
	static CATUndoRequest* GetLastUndoRequest();
	static CATUndoRequest* GetPenultimateUndoRequest();
	static CATUndoRequest* GetLastRedoRequest();
	static int                      GetOneUndoStepUniqueId();
	static int                      GetLastCreatedUndoStepUniqueId();

	static CATUndoRequest* GetUndoByNum(int iNum);
	static CATUndoRequest* GetRedoByNum(int iNum);

	static void Empty();
	static void DeleteAllUndo();
	static void DeleteAllRedo();
	static void FlushPurgeableUndoSteps();
	static CATUndoRequest* UnstackUndo();
	static CATUndoRequest* RemoveUndo(int iIndex); // from 0 to _undoStackSize-1

	//-------------------------------------------------------
	//  Manage Model Transactions
	//-------------------------------------------------------

	static HRESULT AddToUndoRedoManagement(CATBaseUnknown* iClient, const CATUnicodeString& iClientID, CATBoolean iModelManagement = TRUE, CATBoolean iBeforeModelManagement = TRUE);
	static HRESULT RemoveFromUndoRedoManagement(CATBaseUnknown* iClient);

	static int GetCurrentTransactionSet();
	static int GetCurrentTransaction();
	static int GetCurrentTransaction(CATIModelUndoRedoManager* iModelUndoRedoManager);

	static int IsAvailableTransaction(int iTrans);
	static int IsAliveTransaction(int iTrans);
	static int IsEmptyTransaction(int iTrans);
	static int IsEmptyLocalTransaction(int iTrans);

	static void CommitLastTransactions(UndoRedoMode iMode);
	static void EmptyTransactions();

	static int NewTransaction(const CATUnicodeString& iId, OmbUndoRedoContext& Context, CATBoolean iForce = FALSE, CATBoolean iCheck = TRUE);
	// restricted to a list of CATIModelUndoRedoManager objects
	static int NewTransaction(CATLISTV(CATBaseUnknown_var)& iList, const CATUnicodeString& iId, OmbUndoRedoContext& Context, CATBoolean iForce = FALSE, CATBoolean iCheck = TRUE);
	static void DisableNewTransaction();
	static void EnableNewTransaction();
	static void CommitTransaction(int iFirstTrans, int iLastTrans);
	static void DeleteTransaction(int iTrans);
	static int UndoTransaction(int iTrans);
	static int RedoTransaction(int iTrans);

	static void SetBusyTransaction(int iTrans);
	static void UnsetBusyTransaction(int iTrans);

	static void DumpTransactions();
	static void DumpUndoRequests();

	static CATBoolean LockTransactions(CATBoolean iWarning = TRUE);
	static void UnlockTransactions();
	static CATBoolean IsLocked();

	//-------------------------------------------------------
	//  Reserved for special usage
	//-------------------------------------------------------

	// Reserved for CATECmdCommandEngine
	static void CheckStackSize();
	// Reserved for CATAfrUITransaction
	static void PushError(OmbUndoRedoErrorId iError);
	// Reserved for CATECmdCommandEngine
	static OmbUndoRedoErrorId PullError();
	// Reserved for CATActivationContext
	static void HideUndoStack();
	static void ShowUndoStack();

	// Reserved for CATAfrUITransaction, CATSelect and CATCSO
	static CATBoolean _TransCSO; // Indicates whether CSO is transactional

	// Reserved for CATDiaActionEngine
	static void ManageUndoErrorCaught(CATError* iError);
	static void ManageRedoErrorCaught(CATError* iError);

	// Reserved for macro undoability
	static HRESULT EnableInfiniteStack();
	static HRESULT DisableInfiniteStack();

	// Reserved for CATAfrUITransaction and CATCSOTransaction
	static CATBoolean _EmptyLocalTrans; // Request local IsEmptyTransaction()

	void EditorActivatedCB(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);

	//migration split AfrCore
	static CATUndoTempCommand* GetUndoTempCommand();

	CATBoolean GetUndoPerformedSinceLastIdle();

	static void AfrAwakeOnIdle(CATCommand*, int, void*);

private:

	

	static CATAfrUIUndoRedoManager* _undoRedoManager;
	static CATCallbackManager* _undoRedoCallbackManager;

	static void Init(int iCore = 0);
	static void Clean();

	// Add/Remove CATDiaNoEngine instances
	static void AddDiaNoEngine(CATBaseUnknown* iNoEngine);
	static void RemoveDiaNoEngine(CATBaseUnknown* iNoEngine);

	// Undo/Redo mode
	static void SetUndoRedoMode(CATAfrUIUndoRedoManager::UndoRedoMode iURMode);

	// Callbacks
	void InitializeDocumentCB(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);
	void RemoveDocumentCB(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);
	void OnGetStartSaveNotification(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);
	void OnSettingUpdated(CATCallbackEvent, void*, CATNotification*, CATSubscriberData, CATCallback);

	//-------------------------------------------------------
	//  Execute Undo and Redo Commands
	//-------------------------------------------------------

	static CATUndoTempCommand* _exclusiveCommand;
	static void SetUndoTempCommand(CATUndoTempCommand* iCmd);



	//-------------------------------------------------------
	//  Manage Stacks of Undo and Redo Requests
	//-------------------------------------------------------

	static int _undoStackMax; // allocated size
	static int _undoStackSize; // used size
	static CATUndoRequest** _undoStack; // Undo stack
	static int StackUndo(CATUndoRequest*);
	static void ReallocateUndo();
	static int _Core;

	static int _redoStackMax; // allocated size
	static int _redoStackSize; // used size
	static CATUndoRequest** _redoStack; // Redo stack
	static int StackRedo(CATUndoRequest*);
	static CATUndoRequest* UnstackRedo();
	static CATUndoRequest* RemoveRedo(int iIndex); // from 0 to _redoStackSize-1
	static void ReallocateRedo();

	// UndoRedo Title
	static CATUnicodeString GetUndoTitle();
	static CATUnicodeString GetRedoTitle();
	static void ChangeUndoRedoTitle();

	// Dispatch Undo/Redo notification
	static void DispatchNotification(CATNotification* iNotif);

	// Show/Hide management
	static CATUndoRequest* GetFirstHiddenUndo();

	// List of CATDiaNoEngine
	static CATLISTP(CATBaseUnknown)* _diaNoEngineList;
	// List of CATAfrUITransaction stored
	static CATLISTP(CATAfrUITransaction)* _transactionList;
	// List of CATIModelUndoRedoManager clients...
	static CATLISTV(CATBaseUnknown_var)* _clientManagerList;
	// ...and either CATBaseUnknown Client or CATDiaNoEngine client
	static CATLISTP(CATBaseUnknown)* _clientObjectList;
	// order management (before or after model)
	static int _inListBeforeModel;
	static int _inListAfterModel;

	static CATBoolean _cleaning; // Indicates whether Session Undo is cleaning or not
	static CATBoolean _isActive; // Indicates whether Session Undo is used or not
	static CATBoolean _undoLocked; // Indicates whether Undo is transiently locked (Use of ManualCommand or LockTransactions)
	static CATBoolean _availability; // Indicates whether Undo command is available or not
	static CATBoolean _postponeDeleteAllUndo; // Indicates whether a DeleteAllUndo() is to be called at the end of an Undo
	static CATBoolean _postponeDeleteAllRedo; // Indicates whether a DeleteAllRedo() is to be called at the end of an Undo
	static CATBoolean _undoPending; // Indicates whether an Undo is pending (used in CATECmdCommandEngine::Cancel)
	static CATBoolean _redoPending; // Indicates whether a Redo is pending (used in CATECmdCommandEngine::Cancel)
	static UndoRedoMode _UndoRedoMode; // Indicates whether currently undoing, redoing or not
	static int _cmdUndoMax; // Maximum number of Command Undo allowed, as defined in the settings
	static int _oldestTransaction; // Index of the oldest transaction remaining (1...)
	static int _transactionSet; // Index of the transaction set (1...)
	static int _undoCount; // Number of UndoRequests in Undo stack
	static CATBoolean _saveNotificationReceived; // Indicates whether a Save has just been done
	static CATBoolean _stackFlushedWithoutSave; // TRUE if the stack has been flushed without Save operation
	static CATBoolean _stepRemoved; // TRUE if at least one step of the stack has been unstacked
	static int _stackStatus; // 0:empty - 1:neither empty nor full - 2:becomes full - 3:full - 4:_cmdUndoMax==0
	static int _stackFullWarningRequestedByUser; // 0:no - 1:easy warning - 2:dialog box (message to be displayed if stack is full)
	// Reserved for CATAfrUITransaction and CATCSOTransaction
	static OmbUndoRedoErrorId _ombError;
	static CATBoolean _undoRequestStacked;
	static CATDiaNoEngine* _previousNoEngine;
	static CATDiaNoEngine* _lastNoEngine;
	static CATAfrUndoRedoController* _controller;
	static CATBaseUnknown* _previousCSO;
	static CATBaseUnknown* _lastCSO;
	static int _previousFirstTransaction;
	static int _lastFirstTransaction;
	static CATUndoRequest* _firstHiddenUndo;
	// indicates whether new transactions can be created
	static CATBoolean _disableNewTransaction;
	// indicates whether the stack is in inifinite mode (for macro "local undo" simulation)
	static CATBoolean _infiniteStack;
	static int _lastUndoStepUniqueId;
	static CATISplitAfrServices* _pIServ;

	// NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
	CATAfrUIUndoRedoManager(const CATAfrUIUndoRedoManager&);
	CATAfrUIUndoRedoManager& operator= (const CATAfrUIUndoRedoManager&);

	friend class CATAfrUIActivationUndoRedoManager;
	friend class CATActiveObjectUndo;
	friend class CATDiaNoEngine;
	friend class CATUndoTempCommand;
	friend class CATUndoRequest;
	friend class CATUndoHeader;
	friend class CATRedoHeader;
	friend class CATRedoOrRepeatHeader;
	friend class CATAfrUITransaction;
	friend class CATUndoRedoHistoryDlg;
	friend class CATEAfrModelUndoRedoManagerForCSO;
	//friend HRESULT CATAfrGetUndoTempCommand (CATUndoTempCommand *& UndoTempCmd);
	friend HRESULT CATAfrDeleteUndoCommands();

	static void InitIServ();

};

#endif

