/* -*-c++-*- */

// COPYRIGHT DASSAULT SYSTEMES 2002  

#ifndef CATOmbAutoSaveManager_h_v5
#define CATOmbAutoSaveManager_h_v5

/**
 * @level Private
 * @usage U1
 */

#include "CATBaseUnknown.h"
#include "CATOmbWarmStart.h"
#include "CATUnicodeString.h"
#include "CATListOfInt.h"
#include "CATWSTransactionID.h"
#include "CATDocument.h"
#include "CATEventSubscriber.h"


class CATOmbStream;

class ExportedByCATOmbWarmStart CATOmbAutoSaveManager : public CATEventSubscriber
{
	CATDeclareClass;

public:
	static CATOmbAutoSaveManager* GetAutoSaveManager();
	static void DeleteAutoSaveManager();

   //-------------------------------------------------------------------------
   //  Services a appeler par les applis pour gerer l'activation du warmstart
   //-------------------------------------------------------------------------
   
   //USELESS R201 static HRESULT IsWorkbenchAllowingAutoSave(const CATString& iWorkbenchName);
   static HRESULT ChangeWorkbench(const CATString& iFromWkb,const CATString& iToWkb,
      CATUnicodeString& oWarningMessage, CATUnicodeString& oTitle);
   static HRESULT ActivateAutoSave(CATUnicodeString &oMsg);
	// VCS 06/09/2006 PER NULPERCAM00291 add the capability to deactivate with/without deleting log
   static HRESULT DesactivateAutoSave(CATUnicodeString& oWarningMessageToDisplay, CATBoolean iDeleteLog = FALSE);

	 /* NE PLUS UTILISER */
	 //USELESS R201 static int CATWARMSTART(); // Imprecis et FAUX ! => A remplacer plutot suivant le cas par :
	 // (Rq : 90% des tests applicatifs doivent utiliser CATAutoSaveRunning pour eviter de degrader 
	 // la session sans autosave.) 

	 /* 1) Pour savoir si l'autosave est en cours. */
	 static boolean CATAutoSaveRunning() ;
	 /* 2) Pour savoir si le warmstart est en cours. */
	 static boolean CATWarmStartRunning() ;
	 /* 3) Pour savoir si les variables d'environnement autorisent l'autosave ou le warmstart. */
	 static boolean CATAutoSaveAndWarmStartEnv() ; 
	 /* 4) Pour savoir si autosave/warmstart sont permis par les variables d'environnement et les settings. */
	 static boolean CATAutoSaveAndWarmStartSetting() ;
	 /* 5) Pour savoir si on est en mode interne DS avec la ToolBar - ce mode est aussi utile pour les ODTs. */ 
	 static boolean CATDSAutoSaveAndWarmStart() ;
	 /* 6) Pour savoir si on est en mode debug */
	 static boolean CATAutoSaveAndWarmStartDebug() ;
   
   //-------------------------------------------------------------------------
   //  Services internes
   //-------------------------------------------------------------------------
	static void CATWarmStartRunning(boolean isRunning) ;
    HRESULT SetAutoSaveStatus(boolean iStatus);
	HRESULT GetAutoSaveStatus(boolean &oStatus);
	HRESULT Save(CATBaseUnknown *iModif);
	HRESULT Load(char *iBuffer, CATLONG32 iBufferSize, CATBaseUnknown **oModif);
	// saves a Log object to the log file
	HRESULT SaveToLogFile(CATBaseUnknown *iModif, CATWSTRANSACTIONID transID);
	// saves a Log object to the undo/redo log file
	HRESULT SaveToUndoRedoLog(CATBaseUnknown *ipLog);
	// saves a Marshallable object to a char buffer, used by SaveToUndoRedoLog and SaveToLogFile
	HRESULT SaveToCharBuffer(CATBaseUnknown *iModif, char **oBuffer, CATLONG32 *oBufferSize);
	// validates the transactions corresponding to the active editor
	HRESULT CommitTransaction(CATUnicodeString &iLabel, boolean iAllEditors = FALSE);
	// return a new transaction ID for undo/redo logging.
	CATWSTRANSACTIONID GetNewTransactionID();
	// flush buffer to log file
	HRESULT FlushBufferToFile();
	// return the lowest valid transaction ID (change when autosave is re-initialized)
	CATWSTRANSACTIONID GetFirstValidTransactionID();

	// accessors for "fake" transaction creation mode
	//    change the behavior of CATIUndoTransaction::NewTransaction
	// These methods are temporary, to be replaced by a new interface method.
	HRESULT StartNewTransactionForWarmStart();
	HRESULT EndNewTransactionForWarmStart();
	boolean IsNewTransactionForWarmStart();

	HRESULT SetForbideValidation(boolean iForbideValidation);
	
	HRESULT GetLogFileName(CATUnicodeString* oLogFileName);
	HRESULT GetUndoRedoLogFileName(CATUnicodeString* oLogFileName);
	HRESULT DeleteAutoSaveData();
	HRESULT AddDocInAutoSaveData(CATDocument *iDocument, CATUnicodeString &oDocName);
	HRESULT GetDocFromAutoSaveData(const CATUnicodeString& iDocLocation, const CATUnicodeString& iDocName, CATDocument **oDocument);
	HRESULT AddDocWithEditor(CATUnicodeString &iDocName);
	HRESULT GetListDocsWithEditor(CATListOfCATUnicodeString &oListDocsWithEditor);
	//USELESS R201 HRESULT GetListDocsInAutoSaveData(CATLISTP(CATDocument) &oListDocsInAutoSaveData);
	HRESULT RemoveDocWithEditor(CATUnicodeString &iDocName);
	HRESULT RemoveListDocsWithEditor();

	HRESULT CommitTransaction();
	//USELESS R201 HRESULT EmptyLogMemory();
	HRESULT ActiveRegister(boolean iStatus);
	HRESULT IsRegisterActive(boolean &oStatus);
	HRESULT ActiveUndoRedoRegister(boolean iStatus);
	//USELESS R201 HRESULT IsUndoRedoRegisterActive(boolean &oStatus);
	//USELESS R201 boolean IsBufferEmpty();
	//USELESS R201 boolean IsAutoSaveAllowed();

	//USELESS R201 HRESULT EnoviaV5DocCreation(boolean iStatus);
	//USELESS R201 HRESULT IsEnoviaV5DocCreation(boolean &oStatus);

	// Set the last transaction ID for a given document in the dictionary
	HRESULT SetLastTransactionIDForDoc(CATUnicodeString &iDocName, CATWSTRANSACTIONID iTransID);
	// Get the last transaction ID for a given document in the dictionary
	HRESULT GetLastTransactionIDForDoc(CATUnicodeString &iDocName, CATWSTRANSACTIONID &oTransID);
	// Set the current active editor name
	HRESULT SetActiveEditorName(CATUnicodeString &iEditorName);
	// Get the current active editor name
	HRESULT GetActiveEditorName(CATUnicodeString &oEditorName);

	// Immediatly stop autosave and send warning message to reported.
	//USELESS R201 static void AutoSaveFatalError(const char* errorNb);

#ifdef _WINDOWS_SOURCE
    // VCS 23/01/04 RI : Autosave Multi-session pour mono user 

	// (declared as static only because called by static function ActivateAutoSave)
	// Reads current session log ID 
	//USELESS R201 static HRESULT GetSessionLogID (CATUnicodeString & oSessionLogID);

	// (declared as static because uses Static variables)
	// Reads the log ID of the ended session to be restored by current one
	static HRESULT GetLastSessionLogID (CATUnicodeString & oLastSessionLogID);

	// Deletes all log Data of the session currently restored
	HRESULT DeleteLastAutoSaveData(int iSessionLog);
#endif

private:
	CATOmbAutoSaveManager();
	virtual ~CATOmbAutoSaveManager();

	static CATOmbAutoSaveManager *_autoSaveManager;

  //USELESS R201 
  /*
	CATOmbAutoSaveManager( const CATOmbAutoSaveManager& );	// not implemented
	CATOmbAutoSaveManager& operator=( const CATOmbAutoSaveManager& );	// not implemented

	static boolean IsDocVolatile(CATDocument *iDocument);
	static int AreAllDocumentsSaved(CATLISTP(CATDocument)& docsInSession,CATLISTP(CATDocument)& docsModified);

#ifdef _WINDOWS_SOURCE
    // VCS 23/01/04 RI : Autosave Multi-session pour mono user 

	// (declared as static because called by static function GetLastSessionLogID)
	// Reads the log directory path of the ended session to be restored by current one
	static HRESULT GetLastSessionLogDirPath (CATUnicodeString & iCurSessionLogID, CATUnicodeString & oSessionLogDirPath, 
											 CATUnicodeString & oSessionLogID, int & oFound);

	// (declared as static because uses Static variables)
	// Deletes all log data and the directory related to a session
	static HRESULT DeleteAllSessionLogData(CATUnicodeString iPathForLogDirToDelete, boolean & obDeleted);

	// (declared as static because called by static function GetLastSessionLogID)
	// Deletes specific Settings of a session currently restored
	static HRESULT DeleteSessionLogSettings(CATUnicodeString iSessionLogID, boolean & obDeleted);
#endif

private:

	static boolean CATWarmStartIsRunning ;

	boolean _autoSaveStatus;
	boolean _registerActive;
	boolean _undoRedoRegisterActive;
	CATUnicodeString _logFileName;
	CATUnicodeString _undoRedoLogFileName;
	CATUnicodeString _logDirName;

#ifdef _WINDOWS_SOURCE
    // VCS 23/01/04 RI : Autosave Multi-session pour mono user 
	// Path for root Warm start log directory (...\CATTemp\CNext02.roll)
	CATUnicodeString _RootLogDirPath;

	// internal ID for Session log being handled (Session storing log)
	// Format : ProcessName_PID_user_date_time_increment
	// used to separate Settings fields with this suffix
	// (declared as static because called by static function GetSessionLogID)
	static CATUnicodeString _SessionLogID;

	// internal ID for Session log being handled (Session log beeing restored)
	// Format : ProcessName_PID_user_date_time_increment
	// used to separate Settings fields with this suffix
	static CATUnicodeString _LastSessionLogID;

	// Path for Session log directory being handled (...\CATTemp\CNext02.roll\AutoSave_ProcessName_PID_..)
	// (Previous Session log to be restored, in context, when found)
	static CATUnicodeString _LastSessionLogDirPath;

	// TRUE if a previous session log to be restored has been found
	static boolean _bLastSessionFound;
#endif

	// file handles
	FILE *_logFileHandle;
	FILE *_undoRedoLogFileHandle;
	
	// log counter (for debug only)
	int _logCounter;

	CATOmbStream *_buffer;
	static CATListOfCATUnicodeString _ListdocsWithEditor ;

	// Flag used to forbide autosave log validation (used during "cut" commands for example)
    boolean _forbideValidation;

	// Flag used for warmstart fake CATSpecTransaction
    boolean _newTransactionForWarmStart;

	// TRUE if autosave is allowed in the current workbench
	boolean _autoSaveAllowed;

	// transaction id for the next created transaction log
	CATWSTRANSACTIONID _newTransactionID;

	// id of the first transaction created since autosave init.
	// all valid ids must be bigger.
	CATWSTRANSACTIONID _firstValidTransactionID;
	
	// A dictionary that associates to each document name the identifier of the last 
	// transaction impacting this document.
	// 
	// It is used to retrieve a relevant transaction ID for CATSpecDatum's logs.
	CATHDICOTRANSACTIONID _lastTransactionIDForDoc;

	// The name of the current active editor name
	// It is updated by CATAutoSaveObj when it is notified of a editor activation
	// 
	// Used to retrieve the editor associated to each CATSpecTransaction
	CATUnicodeString _activeEditorName;

	// maximum size for log buffer.
	static const int _logBufferMaxSize;

	CATLISTP (CATDocument)  _ListDocsInAutoSaveData ;*/
};

#endif
