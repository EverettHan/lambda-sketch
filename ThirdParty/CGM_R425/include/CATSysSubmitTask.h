/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 2000						                */
/*=======================================================================*/
/*                                                                       */
/*        	*/
/*                                                                       */
/*=======================================================================*/
/*  Creation 	2002                                 jnm             */
/*=======================================================================*/
#ifndef __CATSysSubmitTask_h_
#define __CATSysSubmitTask_h_

#include "CATCreateProcessAsUser.h"
#include "JS0LIB.h"



CATLibStatus ExportedByJS0LIB CATSysSubmitTask (
   int                    argc,
  char*			 argv [],
  int&			 pid,
  const char*		 hostname=NULL,
  const char*            user=NULL, 
  const char*            pwd=NULL, 
  func_SIGCHLD		 func=NULL,
  int				 iFlags=0,
  char*			 ichrReserved=NULL,
  void*			 ivoidReserved=NULL,
  int NoWnd=0
  );


#endif //__CATSysSubmitTask_h_
