/*=======================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 2000						                */
/*=======================================================================*/
/*                                                                       */
/*  CATBatStartMessage                                                    */
/*                                                                        */
/*  Usage Notes: Creation d'un process sur un USER donne                  */
/*   ATTENTION : sur NT l'appelent doit avoir les droits suivants        */
/*																		*/
/*				-> Replace a process level token						*/
/*				-> Create a token object						         */
/*				-> Increase quotas				                		*/
/*				-> Take ownership of files or other objects		     	*/
/*				-> Act as a part of the operating system	        	*/
/*                                                                       */
/*=======================================================================*/
/*  Creation Nov	2000                                 jnm             */
/*=======================================================================*/


//		CLIENTS :        DO NOT USE, FUNCTIONS ONLY for Fws :
//
//		->BatchInfrastructure
//	    ->CORBAServerBase 



#ifndef __CATCreateProcessAsUser_h_
#define __CATCreateProcessAsUser_h_

typedef void (*func_SIGCHLD)(int,int);


#include "JS0LIB.h"
#include "CATLib.h"
#include "CATDataType.h"

#define CATSysEndChildInMainThread           0x00000001



CATLibStatus ExportedByJS0LIB CATCreateProcessAsUser (
  const char*            user, 
  const char*            cryptedpwd, 
  int                    argc,
  char*					 argv [],
  func_SIGCHLD			 func,
  int&					 pid,
  CATINTPTR*					 reserved=NULL,
  int NoWnd=0, unsigned int flags=0);


#endif //__CATCreateNTProcessAsUser_h_
