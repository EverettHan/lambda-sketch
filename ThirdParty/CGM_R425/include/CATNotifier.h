/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1996                                      */
/*=======================================================================*/
/*                                                                       */
/*  CATNotifier                                                          */
/*                                                                       */
/*  Usage Notes:                                                         */
/*                                                                       */
/*   CATNotifier dispatch :                                              */
/*      - SendNotification                                               */
/*      - Callbacks on Idle, Endtransaction, File Descriptor, Timer      */
/*                                                                       */
/*=======================================================================*/
/*  Creation Octobre 1996                                   jpl-sgt      */
/*=======================================================================*/
#ifndef __CATNotifier
#define __CATNotifier

#include "CATDataType.h"
#include "CATCommand.h"
#if !(defined (_WINDOWS_SOURCE) || defined (_COCOA_SOURCE) || defined(_IOS_SOURCE)|| defined (_ANDROID_SOURCE))
#include <X11/Intrinsic.h>
#endif

#ifndef _WINDOWS_SOURCE
#ifndef _X_SOURCE
#define _X_SOURCE
#endif
#endif


class CATNotification;
class CATString;
class CATCleaner;
class CATAppBaseList;
class CATNotificationET;
class CATNotificationFd;
class CATNotificationIdle;
class CATNotifierX;
#ifdef _ANDROID_SOURCE
class CATNotifierA;
#endif  // _ANDROID_SOURCE
#define _DebugNotifierCode
#define CATSysFMKeepId 0x02

class ExportedByJS0FM CATNotifier  : public CATCommand
{
  friend class CATNotifierXt;  
  friend class CATNotifierX;  
  friend class CATNotifierC;
  friend class CATNotifierGTK;
  friend class CATNotifierQt;
#ifdef _ANDROID_SOURCE
  friend class CATNotifierA;
#endif  // _ANDROID_SOURCE
 public :
  
  //===================================================
  // Methodes
  //===================================================
  
  // Instanciation
  //--------------
  CATNotifier ( void *);
  
  ~CATNotifier ( ) ;
  
  
  // Execute all Stack of SendNotification
  //----------------------------------- --
  int DoOtherList();
  
  // Execute The SendNotification in Wait
  //-------------------------------------
  int DoOtherSend();
  
  // For CATIAV4
  //------------
  static void SendefmV4 ( );
  
  // Put SendNotification in Send Stack
  //-----------------------------------
  static void PutSend ( CATCommand *ToClient ,
			CATCommand *FromClient, CATNotification* EvtDat,
			int Ident, int type );
  
  // InitNotifier : re-initialisation of CATAppInt
  //----------------------------------------------
  static void InitNotifier();
  
  // Receive Execution
  //-------------------
  static void ExecuteReceive ( CATNotifier* );
  
  // Time out  Subscription
  //-----------------------
  int virtual AddTimeOut
    ( int Time, CATCommand* ToClient,
      void* clientdata, void (*UserStaticMeth)(), 
      int *oIdSub=NULL, int iReserved=0);
  
  // Remove Time out
  //----------------
  int virtual RemoveTimeOut ( int Time, CATCommand* ToClient, int iID=0,int iFlags=0  );
  
  // Register a Work Procedure on :
  //  CATSubsribeIdle
  //  CATSubscribeEndTransaction
  //----------------------------------------------------------
  int virtual Subscribe
    ( int State, CATCommand* ToClient,
      void* clientdata, void (*UserStaticMeth)() ,
      int *oIdSub=NULL,int iReserved=0);
  
  // Reset the Subscribe
  //--------------------
  int virtual RemoveSubscribe
    ( int State, CATCommand* ToClient, int iID=0, int iFlags=0);
  
  // Register a File Descriptor
  //----------------------------------------------------------
  int virtual AddFileDescriptor
    ( int fd, CATCommand* ToClient,
      void* clientdata, void (*UserStaticMeth)() ,
      int *oIdSub=NULL,int iReserved=0);
  
  // Reset a File Descriptor
  //----------------------------------------------------------
  int virtual RemoveFileDescriptor
    ( int fd, CATCommand* ToClient ,int iID=0, int iFlags=0);
  
  // returns  TRUE if in an  IdleState  callback
  //--------------------------------------------
  int InIdleState();
  
  // returns TRUE if in  EndTransaction  callback
  //--------------------------------------------
  int InEndTransactionState();
  
  // returns TRUE if in a  File Descriptor callback
  //-----------------------------------------------
  int InFileCallbackState();
  
  
  // Work Procedure to be called when the Fd is activate
  //-----------------------------------------------------
#ifndef _WINDOWS_SOURCE
#ifdef _X_SOURCE
 
#else
  static void ExecFdCB ( XtPointer, int*, XtInputId* );
  static void TimeOutCB( XtPointer, XtIntervalId );
#endif
#else
  static void ExecFdCB ( void*, int*, void* );
  static void __stdcall TimeOutCB( HWND  hwnd,   UINT  uMsg,	
				   CATUINTPTR  idEvent, DWORD  dwTime ); 
  // Work Procedure to be called when the Application is IDLE
  //---------------------------------------------------------
  BOOL ExecWorkProcCB ( void* );
#endif
  
  CATDeclareClass;
  
  int SubscribeOnIdleReplay ( CATCommand* ToClient,
			      void* clientdata, void (*UserStaticMeth)() );
  CATNotification * GetNotificationOnIdle();
  CATNotification * GetNotificationOnET();
  CATNotification * GetNotificationOnFd();
  virtual int RestoreState(CATNotification*, CATMarshal&);
  virtual int SaveState(CATNotification*, CATMarshal&);
  
  int AmIInTransaction();
  
  //===================================================
  // Datas
  //===================================================
  
  static CATNotifier* CATAppInt;
  
#ifdef _DebugNotifierCode
  CATCleaner      * GetCleaner(); // returns associated CATCleaner
  int      _CleaningProcessing; // true during Cleaner Processus
#else
  static int      CleaningProcessing;
#endif
#ifdef _DebugNotifierCode
#ifdef _X_SOURCE
  int AddIdleHandler(void *pt=NULL);
#else
  int AddIdleHandler();
#endif
  int RemoveIdleHandler();
  int GetIdleHandlerStatus();
  
#ifndef _WINDOWS_SOURCE
#ifdef _X_SOURCE
  void GetWindowsInfo( CATNotifierX*, CATNotifier *iNewNot);
#else
  void GetWindowsInfo(Widget *iWid,Window *iWin,
		      Display **iDisp,XtAppContext *iApp,
		      CATNotifier *iNewNot);
#endif
#endif
#endif
  
  int DelayReceives();
  int CeaseDelayingReceives();
  int GetSendSynchronicityStatus();
  int AreReceivedDelayed(); 

#ifdef _ANDROID_SOURCE
  void SetMyNotifier(CATNotifierA* ipNotifier)
  { m_pCATNotifierA = ipNotifier; }

  CATNotifierA* GetMyNotifier(void)
  { return m_pCATNotifierA; }
#endif  // _ANDROID_SOURCE
  
 protected :

  //===================================================
  // Methods
  //===================================================
  
  // Work Procedure to be called when the Application is IDLE
  //---------------------------------------------------------
#ifndef _WINDOWS_SOURCE
#ifdef _X_SOURCE

#else
  static Boolean ExecWorkProcCB (XtPointer );
#endif
#endif
  
  // SendNotification Initialisation
  //--------------------------------
  void virtual SendInit(void*);
  
  // Call the Receives
  //------------------
  void virtual CallReceive ();
  
  // Post the Receives
  //------------------
  void virtual PostReceive ();
  
  // Execute the Stack CATSubsribeIdle
  //---------------------------------------
  int DoOtherIdle();
  
  // Execute the Stack CATSubscribeEndTransaction
  //------------------------------------------------------
  int DoOtherTransaction();
  
  // Execute the Stack File Descriptor
  //----------------------------------
  int DoOtherFd(int *fd);
  
  // CallBack for Post Executing
  //----------------------------
  static void CBPostExecute (CATCommand*, int State,
			     void* clientdata );
  
  //===================================================
  // Datas
  //===================================================
  
#ifdef _DebugNotifierCode
  int _EventCBactif;     // Gestion de Send
#else
  static int _EventCBactif;     // Gestion de Send
#endif
  static int _CBAsynchactif;    // Gestion du Post
  
  // Stack Pointer of CATSubscribeEndTransaction
  // -------------------------------------------
  CATAppBaseList *PtSubET;
  
  // Stack Pointer of AddTimeOut callbacks
  // -------------------------------------
  CATAppBaseList *PtTimOut;
  
  // Stack Pointer of CATSubsribeIdle
  // --------------------------------
  CATAppBaseList *PtIdlET;
  
  // Stack Pointer of FileDescriptor
  // --------------------------------
  CATAppBaseList *PtFdET;
  
  // Stack Pointer of SendNotification
  // ---------------------------------
#ifdef _DebugNotifierCode
  CATAppBaseList *_PtSend;
  CATAppBaseList *_PtListofSendLists;
#else
  static CATAppBaseList *PtSend;
  static CATAppBaseList *PtListofSendLists;
#endif
  
#ifndef _WINDOWS_SOURCE
#ifdef _X_SOURCE
  CATNotifierX *_NotifierX;

# ifdef _ANDROID_SOURCE
  /// Android driver pointer.
  CATNotifierA* m_pCATNotifierA;
# endif  // _ANDROID_SOURCE
#else
  Widget _widget;
  XEvent _event;
  Display *_display;
  Window  _window;
  Atom    _atomId;
  
  XtAppContext _appc;
#endif
#endif
  // Send Mode
  // ---------
  static int _ModeSend ;
  
 public:
#ifdef _DebugNotifierCode
  CATNotifier  *_DebugNotifier;
#endif
 private :
  
  CATCleaner  *_Cleaner ; // Cleaner
  CATAppBaseList *_PtFdToBeRemoved;
  CATAppBaseList *_PtFdToBeAdded;
  void FdToBeAdded ( int fd, CATCommand* ToClient,
		     void* clientdata, void (*UserStaticMeth)(),int *oSubId );
  void FdToBeRemoved ( int fd, CATCommand* ToClient );
  
  int         _InDoOtherFD; /** @win64 fbq : 64-bit structure padding **/
  int         _InDoOtherIDLE;
  CATAppBaseList *_PtIdleToBeRemoved;
  CATAppBaseList *_PtIdleToBeAdded;
  void IdleToBeAdded ( CATCommand* ToClient,
		       void* clientdata, void (*UserStaticMeth)(),int *oSubId );
  int IdleToBeRemoved ( CATCommand* ToClient , int iId);
  
  CATAppBaseList *_PtETToBeRemoved;
  CATAppBaseList *_PtETToBeAdded;
  void ETToBeAdded ( CATCommand* ToClient,
		     void* clientdata, void (*UserStaticMeth)() ,int *oSubId);
  int ETToBeRemoved ( CATCommand* ToClient, int iId );
  
  // Ident WorkProc of CATSubsribeIdle
  // --------------------------------------
  int _StatusIdWorkProc;
  int         _InDoOtherET;
  int m_DelayReceives;
  CATBoolean S_InCeaseDelayingReceives;
  
#ifndef _WINDOWS_SOURCE
#ifdef _X_SOURCE

#else
  XtWorkProcId _IdWorkProc;
#endif
#endif
  // For Record management of OnIdle
  // -------------------------------
  CATNotificationIdle *p_OnIdlenotif;
  CATNotificationET *p_OnET;
  CATNotificationFd *p_OnFd;
  int _ReplayOnIdle;
  CATCommand* ReplayOnIdleClient;
  void *ReplayOnIdleclientdata ;
  void (*ReplayOnIdleUserStaticMeth)(CATCommand*,int,void*);
  
};


#endif
