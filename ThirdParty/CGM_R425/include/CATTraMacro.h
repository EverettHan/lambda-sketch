#ifndef CATTraMacro_H
#define CATTraMacro_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/
/*
// COPYRIGHT DASSAULT SYSTEMES 1997
// DAL
//
//========================================================================
//
// IDENTIFICATION :
// --------------
//
//    RESPONSABLE : L. BAUDRY 
//    FONCTION   :  User Interface of trace using macro
//    NAME       :  CATTraMacro.h
//
//    COMMENT	 :  
//
//	CATTraMacro.h has following advantages on CATTrace.h :
//	- traces macro could be suppressed at link
//	time in order to reduce your code,
//      - CATTraMacro.h could be included in C programs as well as C++,
//      - CATTraMacro.h can be implemented without static constructor.
//	
// -----------------------------------------------------------------------------------------
//
//      I. SUPPRESS MACRO AT LINK TIME
//         ---------------------------
//
//	There is two level of macro with exactly the same functionalities :
//      - TRAINIT, TRAWRITE, TRAWRITEF,
//
//	- TRAINDEV, TRAWDEV, TRAWDEVF 
//
//      The family TRAINDEV, TRAWDEV is built only if the flag CAT_TRA_DEV is defined
//
//       #define CAT_TRA_DEV
//       #include "CATTraMacro.h"
//
//
//      Remarks :
//	A trace declared with TRAINIT accepts both macro of
//	TRAWRITE and TRAWDEV. A trace declared with TRAINDEV could
//	not accept macro of type TRAWRITE.
//
//
// 
// -----------------------------------------------------------------------------------------
//
//      II. Avoid static constructor
//         -------------------------
//
//
//     With the flag TRA_TRAUSER_OLD, you will use the C traces calls defined in CATtraproto.h
//     This implementation of traces does not used static constructor.
//
//
//	
//
// -----------------------------------------------------------------------------------------
//
//       III. HOW TO ACTIVATED TRACES ?
//       ----------------------------
//
//	1 - How can I activate traces from CNEXT FRAME ?
//          ------------------------------------------
//	The shared library JS08TRA ( framework debug) is a interactive command to activate traces.
//	From CNEXT frame, add JS08TRA icon with Customize menu. Click on it and you will activate
//	traces.
//	
//
//	2 - How can I activate a trace named TRACE1 before starting the application ?
//           ----------------------------------------------------------------------
//
//	Check if CATRADEC is in your path. CATRADEC is located in the steplib of your OS
//
//       CATRADEC TRACE1
//
//
//	3 - If I have no CATRADEC, how can I activate TRACE1 ?
//           ---------------------------------------------
//
//	Go to your $HOME et by passed CATRADEC with 
//
//		echo " TRACE1  " > .optionfile1
//
//
// 	4 - Under windows NT, how can I activate my trace  ?
//          -----------------------------------------------
//
//	CATRADEC is now avalaible under Windows NT. Otherwise, edit a OPFILE.1 in the root directory
//	of your device and write the name in it.
//
//	If you can not write in your root directory, declare another directory with the exported 
//	variable CATTraDecDir.
//
//	set CATTraDecDir=\MyDir
//
//	Edit a OPFILE.1 in this new directory.
//
//								   
//========================================================================
//								   
//  This class is a C++ interface to the soft of trace		   
//								   
//========================================================================
//								   
// June 97  
//								   
//========================================================================
*/

/*
*----------------------------------------------------------------------
*
*	CATtraproto is the C API of trace tool where following calls are
*	 defined :
*
*	traopen, traprint, traflush, traput, traputi, tramodif, ...
*
*
*
*----------------------------------------------------------------------
*/ 

#ifdef __cplusplus
extern "C"
{
#endif
/*Ia64+ */
#include "CATDataType.h"
/*Ia64- */
#include "JS03TRA.h"


#include "CATtraproto.h"

/* Complement to CATtraproto.h */
ExportedByJS03TRA int traprint(int tdj,int level, const char *format, ...);

#ifdef __cplusplus
}
#endif



#if defined( __cplusplus) && ! defined( TRA_TRAUSER_OLD ) 

/*
    =====================
    =====================
    =====================

    Begin CATTraMacro C++ interface
    
    =====================
    =====================
    =====================
*/


#include "CATTrace.h"



#define TRAINIT(xxx, comment ) 	static CATTrace Tra_ ## xxx ( # xxx , comment );
#define TRAINIT_EXTERN(xxx) 	static CATTrace Tra_ ## xxx ( # xxx , "");

#define TRAINIT_ARG(xxx, Comment, Mode, Device, Level ) 	static CATTrace Tra_ ## xxx ( # xxx , Comment, Mode, Device, Level );

   			// Macro with the full arguments list
   			// ---------------------------------
   			//	Name		: Name of the trace
   			//	CATTraMode	: Activation mode at init
   			//	Device		: Output device of the trace
   			//			Device takes the value :
   			//				STDOUT : stdout
   			//				STDERR : stderr
   			//				FIXXXXX : a file of name FICXXXXX
   			//				( XXXXX can be any character )
   			//				MEMXXXXX : circular trace in memory
   			//	LevelMaxAtInit	: Value of level filter at init
			// Default arguments are unactivated, on STDERR with a level filter of 1024
			



/*
*----------------------------------------------------------------------
* 
*
*		TRAWRITE
*
*   FONCTION :	
*   ---------
*
*	Send a string in a trace of the identifer num. TRAWRITE declare
*	the trace by itself if need.
*	If the trace is declared in another module, the trace descriptor
*	of the trace is automatically retreive.
*
*
*   ENTREES :
*   --------
*
*
*	num :	In the predefined trace, num is either the identifier 1, 2, 3
*		For a user trace, it will be the identifier xxx
*
*	msg :	Character string or pointor on a character string
*
*----------------------------------------------------------------------
*/

				
#define TRAWRITE(num, msg) Tra_ ## num .TraPut( msg );  									\


/*
*----------------------------------------------------------------------
*
*
*		TRAWRITEI (integer)
*		TRAWRITEL (CATLONG32)
*		TRAWRITEF (float)
*		TRAWRITEX (CATLONG32)
*
*   FONCTION :	
*   ---------
*
*	Store a number and a string 
*
*
*   ENTREES :
*   --------
*
*
*	num :	In the predefined trace, num is either the identifier 1, 2, 3
*		For a user trace, it will be the identifier xxx
*
*	msg :	Character string or pointor on a character string
*
*	var :	Integer, Long or Float variable name
*
*
*----------------------------------------------------------------------
*/


#define TRAWRITEI(num, msg, var)   	Tra_ ## num .TraPut( msg, (CATLONG32)var );  
#define TRAWRITEL(num, msg, var)	Tra_ ## num .TraPut( msg, (CATLONG32)var );

#ifndef _WeDontNeedDoubleMan
#define TRAWRITEF(num, msg, var)	Tra_ ## num .TraPutF( msg, (double)var );
#else
#define TRAWRITEF(num, msg, var)	Tra_ ## num .TraPutF( msg, (float)var );
#endif

/*Ia64C #define TRAWRITEX(num, msg, var)	Tra_ ## num .TraPutX( msg, (CATLONG32)var );*/
/*Ia64+*/
#define TRAWRITEX(num, msg, var)	Tra_ ## num .TraPutX( msg, (CATLONGPTR)var );
/*Ia64-*/



/*
*----------------------------------------------------------------------
*
*
*		TRAWRITELN
*
*   FONCTION :	
*   ---------
*
*	Same functionality than TRAWRITE but with a caraiage return at the end
*	of the message
*
*
*   ENTREES :
*   --------
*
*
*	num :	In the predefined trace, num is either the identifier 1, 2, 3
*		For a user trace, it will be the identifier xxx
*
*	msg :	Character string or pointor on a character string
*
*----------------------------------------------------------------------
*/

				
#define TRAWRITELN(num, msg)	Tra_ ## num .TraPutLN( msg );  								\

/*
*----------------------------------------------------------------------
*
*
*		TRAWRITEILN (integer)
*		TRAWRITELLN (CATLONG32)
*		TRAWRITEFLN (float)
*		TRAWRITEXLN (CATLONG32)
*
*   FONCTION :	
*   ---------
*
*	Store  a string, a number and a '\n' (new line separator) 
*
*
*   ENTREES :
*   --------
*
*
*	num :	In the predefined trace, num is either the identifier 1, 2, 3
*		For a user trace, it will be the identifier xxx
*
*	msg :	Character string or pointor on a character string
*
*	var :	Integer, Long or Float variable name
*
*
*----------------------------------------------------------------------
*/


#define TRAWRITEILN(num, msg, var)	Tra_ ## num .TraPutLN( msg, (CATLONG32)var );  	
#define TRAWRITELLN(num, msg, var)	Tra_ ## num .TraPutLN( msg, (CATLONG32)var );  	
#ifndef _WeDontNeedDoubleMan
#define TRAWRITEFLN(num, msg, var)	Tra_ ## num .TraPutFLN( msg, (double)var ); 
#else
#define TRAWRITEFLN(num, msg, var)	Tra_ ## num .TraPutFLN( msg, (float)var );  				
#endif
/*Ia64C #define TRAWRITEXLN(num, msg, var)	Tra_ ## num .TraPutXLN( msg, (CATLONG32)var );  */
/*Ia64+*/
#define TRAWRITEXLN(num, msg, var)	Tra_ ## num .TraPutXLN( msg, (CATLONGPTR)var );  
/*Ia64-*/

/*
//----------------------------------------------------------------------
//
//	flag de test
//	-------------
//	This macro tests if the flag is active or not. Use it to encasulate
//	code that you want to execute only if traces are activated.
//
//	Remark :
//	This code could not be suppressed.
//
//----------------------------------------------------------------------
*/

#define TRA_IS_ACTIVE( name )	(Tra_ ## name .IsActive())

/*
//----------------------------------------------------------------------
//
//	level modification
//	------------------
//
//----------------------------------------------------------------------
*/

#define TRA_LEVEL_IN_USED( name , level ) 	Tra_ ## name .LevelInUsed = level;



/*
    =====================
    =====================
    =====================

    End CATTraMacro C++ interface
    
    =====================
    =====================
    =====================


*/




#else



/*
    =====================
    =====================
    =====================

    Begin C interface
    =====================
    =====================
    =====================


*/


/*
//----------------------------------------------------------------------
//
//	Old trauser.h is active for C program
//	-------------------------------------
//
//----------------------------------------------------------------------
*/
#ifdef __cplusplus
extern "C"
{
#endif


/*  In order to avoid duplicated symbol message, some variable has
been defined in the library JS03TRA   */

#define ExportedByXXX DSYExport
#define ImportedFromXXX DSYImport
#include "DSYExport.h"
 
/*
*----------------------------------------------------------------------
*
*		TRAINIT(xxx, comment )
*
*	Initialized traces on the format
*
*
*	int *tra_flg_xxx;
*	int tra_td_xxx;
*	char tra_name_xxx[TRA_NAME_SIZE]="yyyyyyyyyy";
*	char tra_com_xxx[TRA_COMMENT_SIZE] = comment ; 
*				
*
*
*----------------------------------------------------------------------
*/



#define TRAINIT(xxx, comment ) 						\
ExportedByXXX int tra_true ## xxx = 1 ; 				\
ExportedByXXX int tra_level_ ## xxx  = 2; 				\
ExportedByXXX int tra_act_init_ ## xxx = 0 ; 				\
ExportedByXXX int *tra_flg_ ## xxx =&tra_true ## xxx;			\
ExportedByXXX int tra_td_ ## xxx = 0;					\
ExportedByXXX char tra_name_ ## xxx [TRA_NAME_SIZE]= # xxx;		\
ExportedByXXX char tra_device_ ## xxx [TRA_DEVICE_SIZE]="STDERR";	\
ExportedByXXX char tra_com_ ## xxx [] =  comment ; 	



#define TRAINIT_EXTERN(xxx) 						\
ImportedFromXXX extern int *tra_flg_ ## xxx ;				\
ImportedFromXXX extern int tra_td_ ## xxx ;				\
ImportedByXXX int tra_level_ ## xxx  ; 					\
ImportedByXXX int tra_act_init_ ## xxx  ; 				\
ImportedFromXXX extern char tra_name_ ## xxx [TRA_NAME_SIZE];		\
ImportedFromXXX extern char tra_device_ ## xxx [TRA_NAME_SIZE];		\
ImportedFromXXX extern char tra_com_ ## xxx [] ; 	


#define TRAINIT_ARG(xxx, Comment, Mode, Device, CanNotUsedLevel )  	\					\
ExportedByXXX int tra_true ## xxx = 1 ; 				\
ExportedByXXX int tra_level_ ## xxx = 2 ; 				\
ExportedByXXX int tra_act_init_ ## xxx  = Mode; 			\
ExportedByXXX int *tra_flg_ ## xxx =&tra_true ## xxx;			\
ExportedByXXX int tra_td_ ## xxx = 0;					\
ExportedByXXX char tra_name_ ## xxx [TRA_NAME_SIZE]= # xxx;		\
ExportedByXXX char tra_device_ ## xxx [TRA_DEVICE_SIZE]= Device;	\
ExportedByXXX char tra_com_ ## xxx [] =  Comment ; 	
			


/*
*----------------------------------------------------------------------
*
*
*		TRAWRITE
*
*   FONCTION :	
*   ---------
*
*	Send a string in a trace of the identifer num. TRAWRITE declare
*	the trace by itself if need.
*	If the trace is declared in another module, the trace descriptor
*	of the trace is automatically retreive.
*
*
*   ENTREES :
*   --------
*
*
*	num :	In the predefined trace, num is either the identifier 1, 2, 3
*		For a user trace, it will be the identifier xxx
*
*	msg :	Character string or pointor on a character string
*
*----------------------------------------------------------------------
*/

				
#define TRAWRITE(num, msg)   									\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))			\
			traput(tra_td_ ## num, tra_level_ ## num, msg);  		\



/*
*----------------------------------------------------------------------
*
*
*		TRAWRITEI (integer)
*		TRAWRITEL (CATLONG32)
*		TRAWRITEF (float)
*		TRAWRITEX (CATLONG32)
*
*   FONCTION :	
*   ---------
*
*	Store a number and a string 
*
*
*   ENTREES :
*   --------
*
*
*	num :	In the predefined trace, num is either the identifier 1, 2, 3
*		For a user trace, it will be the identifier xxx
*
*	msg :	Character string or pointor on a character string
*
*	var :	Integer, Long or Float variable name
*
*
*----------------------------------------------------------------------
*/


#define TRAWRITEI(num, msg, var)   	{	int IntTmp = (int) var;						\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))			\
		traputi(tra_td_ ## num, tra_level_ ## num, msg, IntTmp);  		\
}

#define TRAWRITEL(num, msg, var)   	{	CATLONG32 LongTmp = (CATLONG32) var;							\
	if (tra_td_ ## num == 0)     							\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))			\
		traputl(tra_td_ ## num, tra_level_ ## num, msg, &LongTmp);  		\
}

#ifndef _WeDontNeedDoubleMan
#define TRAWRITEF(num, msg, var)   	{	double FloatTmp = (double)var;								\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))			\
		traputd(tra_td_ ## num, tra_level_ ## num, msg, &FloatTmp);  	\
}
#else
#define TRAWRITEF(num, msg, var)   	{	float FloatTmp = (float)var;								\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))			\
		traputf(tra_td_ ## num, tra_level_ ## num, msg, &FloatTmp);  	\
}
#endif
				
#define TRAWRITEX(num, msg, var)   	{	CATLONG32 LongTmp = (CATLONG32) var;							\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))			\
		traputx(tra_td_ ## num, tra_level_ ## num, msg, &LongTmp);  		\
}


/*
*----------------------------------------------------------------------
*
*
*		TRAWRITELN
*
*   FONCTION :	
*   ---------
*
*	Same functionality than TRAWRITE but with a caraiage return at the end
*	of the message
*
*
*   ENTREES :
*   --------
*
*
*	num :	In the predefined trace, num is either the identifier 1, 2, 3
*		For a user trace, it will be the identifier xxx
*
*	msg :	Character string or pointor on a character string
*
*----------------------------------------------------------------------
*/

				
#define TRAWRITELN(num, msg)   									\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))	{		\
			traput(tra_td_ ## num, tra_level_ ## num, msg);  				\
			traput(tra_td_ ## num, tra_level_ ## num,"\n");  		 \
	}

/*
*----------------------------------------------------------------------
*
*
*		TRAWRITEILN (integer)
*		TRAWRITELLN (CATLONG32)
*		TRAWRITEFLN (float)
*		TRAWRITEXLN (CATLONG32)
*
*   FONCTION :	
*   ---------
*
*	Store  a string, a number and a '\n' (new line separator) 
*
*
*   ENTREES :
*   --------
*
*
*	num :	In the predefined trace, num is either the identifier 1, 2, 3
*		For a user trace, it will be the identifier xxx
*
*	msg :	Character string or pointor on a character string
*
*	var :	Integer, Long or Float variable name
*
*
*----------------------------------------------------------------------
*/


#define TRAWRITEILN(num, msg, var)   		{	int IntTmp = (int) var;							\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))	{		\
		traputi(tra_td_ ## num, tra_level_ ## num, msg, IntTmp);  								\
		traput(tra_td_ ## num, tra_level_ ## num,"\n"); 					\
	}	}

#define TRAWRITELLN(num, msg, var)   	{	CATLONG32 LongTmp = (CATLONG32) var;						\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))	{		\
		traputl(tra_td_ ## num, tra_level_ ## num, msg, &LongTmp);  			\
		traput(tra_td_ ## num, tra_level_ ## num,"\n"); 		\
	}	}				

#ifndef _WeDontNeedDouble
#define TRAWRITEFLN(num, msg, var)   	{	double FloatTmp = (double)var;\
	if (tra_td_ ## num == 0)     					\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))\
        {\
		traputd(tra_td_ ## num, tra_level_ ## num, msg, &FloatTmp);\
		traput(tra_td_ ## num, tra_level_ ## num,"\n"); 	\
	}	}		
#else
#define TRAWRITEFLN(num, msg, var)   	{	float FloatTmp = (float)var;					\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))	{		\
		traputf(tra_td_ ## num, tra_level_ ## num, msg, &FloatTmp);  						\
		traput(tra_td_ ## num, tra_level_ ## num,"\n"); 					\
	}	}		
#endif
				
#define TRAWRITEXLN(num, msg, var)   	{	CATLONG32 LongTmp = (CATLONG32)var;							\
	if (tra_td_ ## num == 0)     								\
		tra_td_ ## num = traopen(tra_name_ ## num, tra_act_init_ ## num, &tra_flg_ ## num, tra_device_ ## num, 999, tra_com_ ## num);	\
	if ( (*tra_flg_ ## num ) && (tra_td_ ## num >= TRA_FIRST_INDICE_TD))   {			\
		traputx(tra_td_ ## num, tra_level_ ## num, msg, &LongTmp);  							\
		traput(tra_td_ ## num, tra_level_ ## num,"\n"); 						\
	}	}		


/*
//----------------------------------------------------------------------
//
//	flag de test
//	-------------
//
//----------------------------------------------------------------------
*/

#define TRA_IS_ACTIVE( name )	( *tra_flg_ ## name )

/*
//----------------------------------------------------------------------
//
//	level modification
//	------------------
//
//----------------------------------------------------------------------
*/

#define TRA_LEVEL_IN_USED( name , level ) 	tra_level_ ## name = level ;


		 				
#ifdef __cplusplus
}
#endif

		
/*

    =====================
    =====================
    =====================
    End C interface
    =====================
    =====================
    =====================

*/


#endif




/*
*----------------------------------------------------------------------
* 
*
*		TRAWDEV macro families
*
*   FONCTION :	
*   ---------
*
*	Functionalities are the same than for TRAWRITE macro.
*	You you define the flag CAT_TRA_DEV to keep this traces.
*	
*
*
*
*----------------------------------------------------------------------
*/


#ifdef CAT_TRA_DEV

#define TRAINDEV(xxx, comment ) 	TRAINIT(xxx, comment ) 
#define TRAINDEV_EXTERN(xxx) 		TRAINIT_EXTERN(xxx)	
#define TRAINDEV_ARG(xxx, Comment, Mode, Device, Level ) 	 TRAINIT_ARG(xxx, Comment, Mode, Device, Level ) 	

				
#define TRAWDEV(num, msg) 		TRAWRITE(num, msg)
#define TRAWDEVI(num, msg, var)  	TRAWRITEI(num, msg, var) 
#define TRAWDEVL(num, msg, var)		TRAWRITEL(num, msg, var)  	
#define TRAWDEVF(num, msg, var)		TRAWRITEF(num, msg, var)
#define TRAWDEVX(num, msg, var)		TRAWRITEX(num, msg, var)
				
#define TRAWDEVLN(num, msg)		TRAWRITELN(num, msg)
#define TRAWDEVILN(num, msg, var)	TRAWRITEILN(num, msg, var)
#define TRAWDEVLLN(num, msg, var)	TRAWRITELLN(num, msg, var)	
#define TRAWDEVFLN(num, msg, var)	TRAWRITEFLN(num, msg, var)
#define TRAWDEVXLN(num, msg, var)	TRAWRITEXLN(num, msg, var)

#define TRA_IS_ACTIVE_DEV( name )		TRA_IS_ACTIVE( name )
#define TRA_LEVEL_IN_USED_DEV( name , level )	TRA_LEVEL_IN_USED( name , level )



#else

#define TRAINDEV(xxx, comment )
#define TRAINDEV_EXTERN(xxx) 	
#define TRAINDEV_ARG(xxx, Comment, Mode, Device, Level ) 	
				
#define TRAWDEV(num, msg) 
#define TRAWDEVI(num, msg, var)  
#define TRAWDEVL(num, msg, var)	
#define TRAWDEVF(num, msg, var)	
#define TRAWDEVX(num, msg, var)
				
#define TRAWDEVLN(num, msg)	
#define TRAWDEVILN(num, msg, var)	
#define TRAWDEVLLN(num, msg, var)
#define TRAWDEVFLN(num, msg, var)
#define TRAWDEVXLN(num, msg, var)
#define TRA_IS_ACTIVE_DEV( name )	(0)		
#define TRA_LEVEL_IN_USED_DEV( name , level ) 

#endif

/*
*----------------------------------------------------------------------
* 
*
*		End of TRAWDEV macro families
*
*
*----------------------------------------------------------------------
*/



#endif
