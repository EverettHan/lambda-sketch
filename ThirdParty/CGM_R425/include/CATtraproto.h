/*  */
#ifndef CATtraproto_H
#define CATtraproto_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

#include "CATDataType.h"
           
#ifdef __cplusplus
extern "C"
{
#endif
/* WINDOWS NT FLAG    */
#include "JS03TRA.h"


/*
* DAL
* COPYRIGHT DASSAULT SYSTEMES 1996
*-------------------------------------------------------------
* IDENTIFICATION :
* --------------
*
*    RESPONSABLE : L. BAUDRY - lby
*    FONCTION   :  trace API 
*    USAGE      :  Contain the prototype of the user include fonction ( Copy de trauser.h)
*    NAME       :  CATtraproto.h
*
*	
*-------------------------------------------------------------
*
*  MOTS CLES :
*  -----------
*  
*	TRACE
*
*------------------------------------------------------------------------
*/

/*
*---------------------------traopen-------------------------------------
*
*   FONCTION 	 
*   ---------
*     
* 	Traopen initialise trace in CATIA and return a trace descriptor  
*	to identidy traces 
*   
*
*
*   ENTREES :
*   --------
*	trace_name: Name of the trace as it is referenced in a tradec,
*
*	initiale_state : Value of the initial state of the trace
*
*	flag : Adresse of Pointor on a flag which indicates the current state of
*	the trace
*	dev: Device output used for the traces
*
*	level_limit: limitation of the trace generation.
*
*	comment : poined on a character string specifying the trace	
*
*   SORTIES :
*   --------
*
*	Trace descriptor: indice of array of structure 
*	Adress of a pointer on flag
*
*					      
*	typedef struct
*	{
*		char name[TRA_NAME_SIZE];
*		int flag;
*		char dev[DEV_NAME_SIZE];
*		int level;
*		char *com;
*		FILE *id;
*	} 
*
*	name is the trace_name
*	level contains level_limit
*	dev: Output device
*	flag is 1 if the trace is activated and 0 if the trace is unactived
*	com : pointed on a character string comment.	
*	id : pointed on a file if the std is a file
*	
*----------------------------------------------------------------------	
*/
ExportedByJS03TRA int traopen(const char *trace_name, int initiale_state, int **flag, const char *dev_name, int level_limit, const char *comment);

/*
*---------------------------traprint-------------------------------------
*
*   FONCTION :	
*   ---------
*     
*	traprint store a trace message in a file or optionally send it
*	to an external process. 
*
*
*-------------------------------------------------------------------
*
*   DECLARATION :
*   ------------
*
*   int	traprint(int tdj, int level, const char *format, va_alist)	
*
*   ENTREES :
*   --------
*
*	tdj: Trace descriptor return by traopen.
*	
*	level: traprint is executed if level < level_limit of traopen
*
*	Other arguments are similar to function:
*
*	printf(const char *format, va_alist)
*
*  RETURN :
*  -------
*
*   Return of the current level_limit of the trace table if normal execution
*   -1 :  Trace descriptor inferior to 1
*   -2 :  Level_limit < level of the traprint
*   -3 :  Trace descriptor > Total trace
*   -4 :  Dynamic flag unactivated
*   -5 :  Reentrance of traput
*
*  NOTICE :
*  -------
*
*	Due to same mangling problem with HP-UX compiler, traprint
*	is not declared in this header.
*	traprint is directly declared in user interface trauser.h
*
*-------------------------------------------------------------------
*/

/* There is a problem on HP if traprint is declared in this header */
/* So traprint should be declare has a prototype close to this header */
/* Complement to CATtraproto.h */

/*
*---------------------------traput-------------------------------------
*
*   FONCTION :	
*   ---------
*     
*	traput is the same then traprint but the message is limitated
*	to a string. 
*
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traput(int tdj,int level, const char *msg);

/*
*---------------------------traputi-------------------------------------
*
*   FONCTION :	
*   ---------
*     
*	traputi is the same then traprint but the message is limitated
*	to a string and a long integer. 
*
*
*----------------------------------------------------------------------
*
*   DECLARATION :
*   ------------
*
*	traputi(int fd, int level, const char *msg, int var)	
*
*   ENTREES :
*   --------
*
*	fd: Trace descriptor return by traopen.
*	
*	level: traputi is executed if level < level_limit of traopen
*
*	msg : Message string
*
*	var : Pointor on the long integer
*
*  RETURN :
*  -------
*
*   Return of the current level_limit of the trace table if normal execution
*   -1 :  Trace descriptor inferior to 1
*   -2 :  Level_limit < level of the traput
*   -3 :  Trace descriptor > Total trace
*   -4 :  Dynamic flag unactivated
*   -5 :  Reentrance of traput
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traputi(int tdj, int level, const char *msg, int var);

/*
*---------------------------traputl-------------------------------------
*
*   FONCTION :	
*   ---------
*     
*	traputl is the same then traprint but the message is limitated
*	to a string and a long integer. 
*
*
*----------------------------------------------------------------------
*
*   DECLARATION :
*   ------------
*
*	traputl(int fd, int level, const char *msg, CATLONG32 *var)	
*
*   ENTREES :
*   --------
*
*	fd: Trace descriptor return by traopen.
*	
*	level: traputl is executed if level < level_limit of traopen
*
*	msg : Message string
*
*	var : Pointor on the long integer
*
*  RETURN :
*  -------
*
*   Return of the current level_limit of the trace table if normal execution
*   -1 :  Trace descriptor inferior to 1
*   -2 :  Level_limit < level of the traput
*   -3 :  Trace descriptor > Total trace
*   -4 :  Dynamic flag unactivated
*   -5 :  Reentrance of traput
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traputl(int tdj, int level, const char *msg, CATLONG32 *pt_var);

/*
*---------------------------traputx-------------------------------------
*
*   FONCTION :	
*   ---------
*     
*	traputx is the same then traprint but the message is limitated
*	to a string and a long integer showed with its hexadecimal value. 
*
*
*----------------------------------------------------------------------
*
*   DECLARATION :
*   ------------
*
*	traputx(int fd, int level, const char *msg, long *var)	
*
*   ENTREES :
*   --------
*
*	fd: Trace descriptor return by traopen.
*	
*	level: traputx is executed if level < level_limit of traopen
*
*	msg : Message string
*
*	var : Pointor on the long integer
*
*  RETURN :
*  -------
*
*   Return of the current level_limit of the trace table if normal execution
*   -1 :  Trace descriptor inferior to 1
*   -2 :  Level_limit < level of the traput
*   -3 :  Trace descriptor > Total trace
*   -4 :  Dynamic flag unactivated
*   -5 :  Reentrance of traput
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traputx(int tdj, int level, const char *msg, long *pt_var);

/*
*---------------------------traputf-------------------------------------
*
*   FONCTION :	
*   ---------
*     
*	traputf is the same then traprint but the message is limitated
*	to a string and a float. 
*
*
*----------------------------------------------------------------------
*
*   DECLARATION :
*   ------------
*
*	traputf(int fd, int level, const char *msg, float *var)	
*
*   ENTREES :
*   --------
*
*	fd: Trace descriptor return by traopen.
*	
*	level: traputf is executed if level < level_limit of traopen
*
*	msg : Message string
*
*	var : Pointor on the float
*
*  RETURN :
*  -------
*
*   Return of the current level_limit of the trace table if normal execution
*   -1 :  Trace descriptor inferior to 1
*   -2 :  Level_limit < level of the traput
*   -3 :  Trace descriptor > Total trace
*   -4 :  Dynamic flag unactivated
*   -5 :  Reentrance of traput
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traputf(int tdj, int level, const char *msg, float *pt_var);
ExportedByJS03TRA int traputd(int tdj, int level, const char *msg, double *pt_var);


/*
*---------------------------traflushMemory-------------------------------------
*
*   FONCTION :	
*   ---------
*     
*	flush traces contained in shared memory in open output
*
*
*
*----------------------------------------------------------------------
*
*   DECLARATION :
*   ------------
*
*	traflushMemory(int fd, const char *device, int level)	
*
*   ENTREES :
*   --------
*
*	fd: Trace descriptor return by traopen.
*	device: output device of the traces
*	level: limitation of the trace generation
*
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traflushMemory(int tdk, const char *device, int level);

/*
*----------------------------------------------------------------------
*
*			tramodif
*
*   FONCTION :	
*   ---------
*     
*	Initialize trace environnement variable
*     	Routage in tradec fonction according to the option variable
*	Ask information about trace table
*
*   ENTREES :
*   --------
*
*	char *dev_state: Device vers the state table of trace is sent
*	STDOUT : Standard output
*	STDERR : Standard error
*	XCO    : The message is returnet in the msg_transmit string
*	NULL : No state table of trace are generate
*			
*
*   ENTREES / SORTIES :
*   ------------------
*   
*
*	msg_transmit : String contening the option string read and	
*	returning the state a the considered trace if the size
*	is big enough (otherwise the state table is truncated).
*	
*	sz_msg_transmit: Size of the string msg_read
*
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int tramodif(const char *dev_state, const char *msg_transmit, int sz_transmit);

/*
*----------------------------------------------------------------------
*
*			int traflush(int tdi);
*
*   FONCTION :	
*   ---------
*     
*   Flush the device
*
*   ENTREES :
*   --------
*
*
*   tdi : Trace descriptor			
*
*
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traflush(int tdk, const char *device, int level);


/*
*----------------------------------------------------------------------
*
*			int traglev(int tdi);
*
*   FONCTION :	
*   ---------
*     
*   Return the value of the level limit currently used
*
*   ENTREES :
*   --------
*
*
*   tdi : Trace descriptor			
*
*
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traglev(int tdi);

/*
*----------------------------------------------------------------------
*
*			int traplev(int level, int tdi)
*
*   FONCTION :	
*   ---------
*     
*   Modify the value of the level  and return the new level value
*
*   ENTREES :
*   --------
*
*
*   int level : New level value	
*   int tdi  : Trace descriptor		
*
*
*
*----------------------------------------------------------------------
*/

ExportedByJS03TRA int traplev(int level, int tdi);


 
/*
*----------------------------------------------------------------------
*
*
*		PROGRAMMING MACRO OF TRACE
*
*
*
*----------------------------------------------------------------------
*/

 
#define TRA_FIRST_MODULE	(int *)9999 /* Don't check is the trace has already been declared in another module */
#define TRA_ALL			-999
#define TRA_LEVEL_LIMIT_MAX	1024
#define TRA_LEVEL_DEFAULT	2
#define	TRA_NAME_SIZE		16
#define TRA_DEVICE_SIZE		16
#define TRA_FIRST_INDICE_TD	1
#define	TRA_VAR_LG		9


#define MSG_SIZE	1024

#ifdef __cplusplus

}
#endif
#ifdef __cplusplus
extern "C"
{
ExportedByJS03TRA int CATDevelopmentStage(int **iDevelopmentStatus=(int **)0L );
}
#else
ExportedByJS03TRA int CATDevelopmentStage(int **iDevelopmentStatus);
#endif

#endif
