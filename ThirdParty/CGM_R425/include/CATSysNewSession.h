#ifndef CATSysNewSession_H
#define CATSysNewSession_H

/* COPYRIGHT DASSAULT SYSTEMES 2001 */

#include <stdlib.h>
#include "JS0ERROR.h"


//=========================================================================
//  Values for argument iFlag of CATSysNewSession
//  Must be logical ORED to build a correct iFlag     

//  CATSysNewSessionInteractive  : the session is interactive
//    NB:CATSysNewSessionInteractive  and CATSysNewSessionBatch are
//       mutually exclusive
//
#define CATSysNewSessionInteractive             0x0000


// CATSysNewSessionBatch : the session is a batch
//    NB:CATSysNewSessionInteractive  and CATSysNewSessionBatch are
//       mutually exclusive
//
#define CATSysNewSessionBatch                   0x0001

// CATSysAllwaysManageAbends : this batch want abends to be traced
//                              even in development mode
//
#define CATSysAllwaysManageAbends               0x0002

// CATSysCleanExitOnParentProcessRequest : this process may receive
//       exit requests from its parent process via CATStopProcessEX 
//       thus it  needs to be exited cleanly in such case 
//       Lets remind that by default CATStopProcess  causes the 
//       child process to be stopped  very violently 
#define CATSysCleanExitOnParentProcessRequest   0x0004

//++vxg - 19:08:12 - To fix session initialization order.
// CATSysNewSessionBatchWithFullLogs : this session is a batch
//                        initializing like an interactive one.
#define CATSysNewSessionBatchEx                 0x0008
#define CATSysNewSessionBatchWithFullLogs       (CATSysNewSessionBatch | CATSysNewSessionBatchEx)
//--vxg - 19:08:12

// CATSysNoMemSec                        : this process will not   
//       benefit of mem sec mechanisms
#define CATSysNoMemSec   0x0020

//=========================================================================
// CATSysNewSession permits a main to declare he beginning of a new session
// an to activate the abend management
//   iFlag : permits to give information to error management software on the 
//           nature of the processus session

ExportedByJS0ERROR void CATSysNewSession( int iFlags=CATSysNewSessionInteractive,int iArgc=0,const char *iArgv[]=NULL, const char *iEnv[]=NULL);

ExportedByJS0ERROR void CATSysNewSessionStatic();

// void InitializeInstallPathHandlerForBundle(void);


#endif
