#ifndef CATSysRunBrwsr_H
#define CATSysRunBrwsr_H
//=====================================================
// COPYRIGHT DASSAULT SYSTEMES 2004
//=====================================================
#include <stdlib.h>
#include "CATBaseUnknown.h"
class CATSockets;
class CATSocketConnector;
class CATCommand;
class CATSysSHRequest;
//=====================================================
// export / import tag
//=====================================================
#if defined(__CATSysRunBrw)
#define ExportedByCATSysRunBrw DSYExport
#else
#define ExportedByCATSysRunBrw DSYImport
#endif
#include "DSYExport.h"

//=====================================================
// flags for Run
//=====================================================
#define CATSysRBNoFrame     0x00000001
#define CATSysRBUseExisting 0x00000002

//=====================================================
// exit values for the callback on event
//=====================================================
#define CATSysRBNormalEnd      0x00000001
#define CATSysRBSocketIsClosed 0x00000002


//=====================================================
// flags for OpenWindow
//=====================================================
#define CATSysRBOpenWinNoFrame      0x00000001
#define CATSysRBOpenWin             0x00000002
#define CATSysRBWinRaise            0x00000004
#define CATSysRBNoWinRaise          0x00000008
#define CATSysRBOpenWinScripted     0x00000020
#define CATSysRBOpenGetWinId        0x00000040
#define CATSysRBOpenLocationBar     0x00000100
#define CATSysRBOpenStatusBar       0x00000200
#define CATSysRBOpenScrollBar       0x00000400
#define CATSysRBOpenToolBar         0x00000800
#define CATSysRBOpenMenuBar         0x00001000
#define CATSysRBOpenResizable       0x00002000
#define CATSysRBOpenMainWinURL      0x00004000

// reserved for future use
#define CATSysRBNoWait          0x00000010

//=====================================================
// define the callback on  events
//=====================================================
typedef int (*CATRunBrowserCbk)( CATSockets *iSocket, CATSysSHRequest *iReq, void *iData) ;
enum CATSysRunBrwsrError 
{
  CATSysRBrwOK ,
  CATSysRBrwErrShellNotFound,
  CATSysRBrwErrSocketSrv,
  CATSysRBrwErrSocket,
  CATSysRBrwErrInput,
  CATSysRBrwErrNotInteractive,
  CATSysRBrwErrBrowserNotFound,
  CATSysRBrwErrBrowserFailed,
  CATSysRBrwErrAlreadyRunning,
  CATSysRBrwErrNotEnoughPagingSpace
};
//=====================================================
//class CATSysRunBrwsr
//=====================================================
class ExportedByCATSysRunBrw CATSysRunBrwsr
{
  public:
  
  /***
   *** Constructor :
   ***         iInteractive : must be set to 1 in interactive application (to 0 in batch )
   ***         iBrowserKind : supported values are netscape and mozilla
   ***         iForcePort   : should be let to zero in general.Will be taken into account
   ***                        only in the 1st CATSysRunBrwsr object of the session
   ***/
  CATSysRunBrwsr(int iInteractive=1, const char *iBrowserKind=NULL , unsigned short iForcePort=0);
  ~CATSysRunBrwsr();
  
  /***
   *** Run permits to run a new browser     
   ***
   *** Arguments
   ***
   ***     iURL : starting URL for the browser
   ***     iAddPortField  : if set to a non null string value, the answer port
   ***                      will be added to the browser request with
   ***                       iAddPortField as field name
   ***     iTimeout       : permits to set the time in ms after wich Run 
   ***                      will considere the browser has failed to launch
   *** 
   ***     iFlag          : may be set to CATSysRBNoFrame to get a browser window         
   ***                      without frame , menus etc...
   ***                      standard behaviour :  a standard browser window
   *** 
   ***     iXsize         : horizontal size of the window
   *** 
   ***     iYsize         : vertical  size of the window
   *** 
   ***/
  HRESULT Run(    const char *iURL, const char *iAddPortField=NULL ,int iTimeout=60000, int iFlag=0,
                 int iX=600, int iY=600);




  /***
   *** SetURL permits to  request the running browser to browser a specific URL
   ***   this browser must have been started with Run
   ***
   *** Arguments
   ***
   ***     iURL : requested URL for the browser
   ***     iAddPortField  : if set to a non null string value, the answer port
   ***                      will be added to the browser request with
   ***                       iAddPortField as field name
   ***     iFlag : reserved for future use      
   ***
   ***/
  HRESULT SetURL(  const char *iURL, const char *iAddPortField=NULL, int iFlag=0 );


  /***
   *** OpenWindow permits to  request the running browser to 
   *** open a window with a specific URL
   ***
   *** Arguments
   ***
   ***     iURL : requested URL for the browser
   ***     iAddPortField  : if set to a non null string value, the answer port
   ***                      will be added to the browser request with
   ***                       iAddPortField as field name
   ***     iFlag : possible values are  combinaison of flags
   ***              CATSysRBOpenWin        : opens a framed window
   ***              CATSysRBOpenWinNoFrame : opens an unframed window without
   ***                                       impact on the original window
   ***                                       Opening a file URL in this mode does
   ***                                       not work and is NOT supported        
   ***              CATSysRBOpenWinScripted: open an unframed window through
   ***                                       a script usage.This impacts the
   ***                                       original window
   ***
   ***        NB . CATSysRBOpenWin,CATSysRBOpenWinNoFrame,CATSysRBOpenScripted 
   ***         are mutually exclusive
   ***
   ***        The mode CATSysRBOpenWinScripted supports a number of features
   ***        which are not supported by the other modes                    
   ***        CATSysRBOpenGetWinId       : obtentions of the newly opened win id
   ***                                     this id cannot be use for the window 
   ***                                     control                              
   ***        CATSysRBOpenLocationBar    : add location bar
   ***        CATSysRBOpenStatusBar      : add status bar
   ***        CATSysRBOpenScrollBar      : add scroll bar
   ***        CATSysRBOpenToolBar        : add tool bar
   ***        CATSysRBOpenMenuBar        : add menu bar
   ***        CATSysRBOpenResizable      : add resize handles
   ***        CATSysRBOpenMainWinURL     : change the meaning of the 
   ***                                     argument iBodyForSOW
   ***
   ***
   ***        iX permits to specify the default window height
   ***        iY permits to specify the default window height
   ***
   ***        NB : iX & iY are ignored for if iFlag is worth CATSysRBOpenWin
   ***
   ***        iTimeout is the timeout  of  CATSysRBOpenWinNoFrame and
   ***                        CATSysRBOpenScripted           
   ***
   ***        iBodyForScriptedOW : used only with     CATSysRBOpenWinScripted 
   ***        allows to provide a body for the original window.
   ***        if ( iFlag contains CATSysRBOpenMainWinURL iBodyForScriptedOW
   ***        meannings changes and allow caller to give the final URL for
   ***        the main window URL. This final URL MUST not be a reference
   ***        to the V5.
   ***
   ***        oWinId : permits to request the windowid.
   ***                 WindowId obtention is supported only with
   ***                  CATSysRBOpenWinScripted .
   ***                  passing a non null oWinId pointer on another mode 
   ***                  transforms the request in a corresponding scripted
   ***                  open .
   ***
   ***
   ***        IMPORTANT NOTE . this window id may not be used to  
   ***                          change the URL on this page or control
   ***                          the content of the page .              
   ***                         In the same way CATSysRunBrwsr cannot close
   ***                         the window from its window id
   ***
   ***
   ***/
  HRESULT OpenWindow( const char *iURL, const char *iAddPortField=NULL, int iFlag=CATSysRBOpenWin, int iX=-1, int iY=-1, int iTimeOut=3000,const char *iBodyForScriptedOW=NULL , int *oWinId=NULL );



  /***
   *** Kill allows to  kill a  browser    started with Run  
   ***/
  HRESULT Kill( );

  /***
   *** SetCallback permits to add an interactive callback function which
   *** will be called back when an http request is received from the browser
   ***
   *** One and only one callback may be set at any given time
   ***
   *** Arguments
   ***  
   ***   iCbk : function respecting the CATRunBrowserCbk prototype  which
   ***           will be called back when a request from the browser
   ***           is received
   ***   iCliDat :  client data pointer 
   ***   iFlag   :  reserved for future use.Must be set to zero .
   ***
   ***/
  HRESULT SetCallback(CATRunBrowserCbk iCbk,void *,int iFlag=0);

  /***
   ***  ResetCallback cancels the callback set by SetCallback 
   ***/
  HRESULT ResetCallback(CATRunBrowserCbk iCbk,int iFlag=0);

  /***
   ***  GetCallback returns the current callback 
   ***/
  CATRunBrowserCbk  GetCallback(){ return m_Callback; };

  /***
   *** return the current WindowsId of the browser started with Run
   ***/
  int GetWindowId() { return m_WinId ; } ;

  /***
   *** return the declaration port
   ***/
  unsigned short GetPort() { return S_ThePort ; } ;
  int  GetMajorVersion() { return m_Level ; } ;
  CATSysRunBrwsrError GetLastErrorId() { return m_LastErrorId ; };
  const char *GetLastError() { return m_LastError;};
  //=========================================================================
  HRESULT Wait(CATSockets **oSock, int iTm=-1); // do not use

private:
  int m_Status;
  int m_WinId;
  int m_CallbackFd;
  int m_Level;
  char *m_Exe;
  char const *m_LastError;
  const char *m_BrowserKind;
  CATSysRunBrwsrError m_LastErrorId;
  CATCommand *  m_Cmd ;
  CATRunBrowserCbk m_Callback;
  void *m_CallbackData ;
  static CATSocketConnector  *S_Connector;
  CATSockets *m_Socket;
  CATSockets **m_SocketRef;
  int  m_X;
  int  m_Y;
  void *m_PrivateData;
  static unsigned short S_ThePort;
  static int S_Order;
  static void CbkOnFd( CATCommand *iCmd, int iFd,void *iAddr);
  static void CbkOnSrv(  CATCommand *iCmd, int iFd, void *iAddr);
  void *GetCallbackData() { return m_CallbackData ; } ;
  HRESULT SetURLx(  const char *iURL, const char *iAddPortField=NULL, int iFlag=0, int iX=-1, int iY=-1,  int iTimeout=3000 ,const char *iBodyForSOW=NULL,int *oWinId=NULL);
  int TreatRequest( int );

};
#endif
