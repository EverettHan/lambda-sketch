/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATRecord                                                            */
/*                                                                       */
/*  Usage Notes: Record monitor for Capture/Replay                       */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl          */
/*=======================================================================*/
#ifndef __CATRecord
#define __CATRecord

#include "CATMarshal.h"
#include "JS0FM.h"
#include "CATCommand.h"
#include "CATRecordDriver.h"
//#include "CATNotificationRecord.h"

class CATCallbackManager;
class CATRecordNode;


class ExportedByJS0FM CATRecord  : public CATCommand
{
	
	
public :
	
	//===================================================
	// Methods
	//===================================================
	
	// Instanciation
	//--------------
	CATRecord ( );
	virtual ~CATRecord () ;
	
	// CATRecord instance
	//-------------------
	static  CATRecord *GetMain() ;

	void Init( );
	
	// Capture status
	//---------------
	int IsCapture();
	
	// Replay status
	//---------------
	int IsReplay();
	
	// Versinning informations
	// -----------------------
	void SetSoftwareRecordLevel( char *iSoftwareId, int iLevel );
	int  GetSoftwareRecordLevel( char  *iSoftwareId, int *oLevel);
	
	// Capture Driver Instance
	// ------------------------------
	static CATRecordDriver * _ptdrivercapture;
	
	// Replay Driver Instance
	// ------------------------------
	static CATRecordDriver * _ptdriverreplay;
	
	// Start and End Record Drivers
	// ------------------------------
	int BeginMode ( CATRecordMod );
	int EndMode   ( CATRecordMod );
	
	// Get Record Start Mode
	// ----------------------
	CATRecordMod RecordMod();
	
	// Start Replay status ( please used BeginMode )
	// -------------------
	void StartReplay();
	void ReplayInitialisation();
	
	// Start Replay status
	// -------------------
	void StartReplayCB( int );
	
	// Callback fo Replay status
	// -------------------------
	int ReplayCB(CATCommand*, int, void* );
	
	// Event dispath by CallbackManager
	// --------------------------------
	CATDeclareCBEvent(CATRecordBeginMode);
	CATDeclareCBEvent(CATRecordEndMode);
	CATDeclareCBEvent(CATRecordReplayCB);
	
	// Get Replay timer
	// ----------------
	int GetReplayTimer ();
	
	// Set Replay timer
	// ----------------
	void SetReplayTimer ( int );
	
	// Internal used Only
	// ------------------
	int SaveState(CATCommand*,CATNotification*);
	int RestoreState();              // a supprimer
	int RestoreState(CATCommand*);
	
	CATCommand* GetCmdFromPath ( CATString* );
	CATString* GetPathFromCmd ( CATCommand*  );
	
	
private :

	static void RunReplayCB (CATCommand*  ctester,  int  ctemps,  void*  cdata);
	
	//===================================================
	// Data
	//===================================================
	
	// Record Start Mode
	//-------------------------
	static CATRecordMod _RecordMod;
	
	// Callback Manager
	//------------------
	CATCallbackManager *_myCallbackManager;
	
	// CATRecord Instance
	//-------------------------
	static CATRecord* _First;
	
	// Path for last notif
	//-------------------------
	CATString _pathcherche;

	// Buffer for reading datas
	//-------------------------
	CATMarshal * _Load3;
	char * _MemoryBuffer;
	
	// data notification
	//-------------------------
	char * _datanotif;

	// To know if the command exists
	//------------------------------
	void * _adreceveur;
	CATString _cmderr;

	// For Asynchronous record
	//------------------------------
	int _AsyncTime; // Time for the longest Asynchronous interaction of the record
	int _AsyncTimeMax; // Max time for the longest Asynchronous interaction of the record
	int _TotalTime; // Total time for the last Asynchronous interaction of the record
	CATBoolean _RecordAsync; // the record is Asynchronous or not
	CATBoolean _TimerIsFinish; // The timer is finished or not
	CATBoolean _BlocReplayCB; // to block the ReplayCB access

	
	
};

// This service is delivered so that it can be called otherwise than as a callback on idle
// (through CATRecord::CATRecordTimerCB / CATRecord::ReplayInitialisation /
// CATApplication::BeginCB // CATNotifier::SubscribeOnIdleReplay), i.e. so that
// he can be called directly
ExportedByJS0FM void CATRecordIDLECB(CATCommand* ToClient,int State,CATCommand* clientdata);

#endif
