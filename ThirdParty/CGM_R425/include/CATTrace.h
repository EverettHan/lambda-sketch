// COPYRIGHT DASSAULT SYSTEMES 1996
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/
// DAL
//
//=================================================================
//
// IDENTIFICATION :
// --------------
//
//    RESPONSABLE : L. BAUDRY
//    FONCTION   :  User Interface of trace using object technology 
//    NAME       :  CATTrace.h
//
//    COMMENT	 :  
//
//	
//	If you want to suppress traces as development traces at build time, you
//	should use CATTraMacro.h. CATTraMacro.h is a new macro implementation on
//	CATTrace.h. trauser.h is now used only in C lamguage source.
//	However, if you want to put your traces in a constructor static or
//	if you want to suppress your traces at the build time, you have better to
//	use CATTraMAcro.h and implements a solution 100 % macros.
//
//       HOW TO ACTIVATED TRACES ?
//       ----------------------------
//
//	1 - How can I activate traces from CNEXT FRAME ?
//          ------------------------------------------
//	The shared library JS08TRA ( framework Debug) is a interactive command to activate traces.
//	From CNEXT frame, add JS08TRA icon with Customize menu. Click on it and you will activate
//	traces.
//	
//
//	2 - How can I activate a trace named TRACE1 before starting the application ?
//           ----------------------------------------------------------------------
//
//	Check if CATRADEC is in your path. CATRADEC is located in the directory System/steplib/`uname`.
//	and type the command
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
//=================================================================
//								   
//  This class is a C++ interface to the soft of trace		   
//								   
//=================================================================
//								   
// October 96   
//								   
//=================================================================

#ifndef CATTrace_H
#define CATTrace_H

// ++vxg - 12:09:27
#ifdef DSY_SYS_TRACE_SYSTEM_MIGRATION
#else // DSY_SYS_TRACE_SYSTEM_MIGRATION
// --vxg - 12:09:27

//Ia64+
#include "CATDataType.h"
//Ia64-

#include "CATtraproto.h"
/*
*----------------------------------------------------------------------
*
*			int _traput XX (int level, int tdi)
*
*   FONCTION :	
*   ---------
*     
*   New function traput with C++ prototype 
*
*----------------------------------------------------------------------
*/
#ifndef _WeDontNeedADoubleMan
ExportedByJS03TRA int _traputf(int tdj, int level, const char *msg, double *pt_var, char IsLN='\0');
#endif

ExportedByJS03TRA int _traputf(int tdj, int level, const char *msg, float *pt_var, char IsLN='\0');
ExportedByJS03TRA int _traputl(int tdj, int level, const char *msg, CATLONG32 *pt_var, char IsLN='\0');
ExportedByJS03TRA int _traputx(int tdj, int level, const char *msg, CATLONG32 *pt_var, char IsLN='\0');
#if defined(PLATEFORME_DS64)
ExportedByJS03TRA int _traputx(int tdj, int level, const char *msg, CATULONGPTR *pt_var, char IsLN='\0');
ExportedByJS03TRA int _traputx(int tdj, int level, const char *msg, CATLONGPTR *pt_var, char IsLN='\0');
#endif	





// Arguments of CATTrace Constructor at initialisation of the Trace
// -----------------------------------------------------------------
#define CATTraUnActivated	CATTraUnactivated

// ++vxg - 11:03:25 - This is to avoid compile errors if the new trace API header
//                    is declared too.
#ifndef DSYSysTrace_H
   enum CATTraMode { CATTraActivated   =1,
		     CATTraUnactivated  = 0
		   };
#endif  // DSYSysTrace_H
// --vxg - 11:03:25

class ExportedByJS03TRA  CATTrace 
{


   public :



//-----------------------------------------------------------------------
//
// Constructor
//
//
//-----------------------------------------------------------------------
 
  CATTrace () ;		// Default
  			// -------
  			// A trace of name TRA_DEBUG is declared but inactivates. 
  			// Its device is the STDERR



  CATTrace (	const char Name[TRA_NAME_SIZE], const char Comment[]="", 
  		CATTraMode = CATTraUnactivated ,
   		const char Device[]= "STDERR", int LevelMaxAtInit = 1024 ) ;
   
   			// Normal constructor of CATTrace
   			// -------------------------------
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
			


//-----------------------------------------------------------------------
//
//  Destructor
//
//
//-----------------------------------------------------------------------

 ~CATTrace ( ) ;
 			// Flush output and eventualy close the file


//-----------------------------------------------------------------------
//
//  Public Variable used in inline method
//
//-----------------------------------------------------------------------



//  Trace Descriptor 

     int TraDesc;
     
//  Level used by default in ouput function   
 
    int LevelInUsed ;

//  Pointor on Flag  = 1 : The trace is activated
//                   = 0 : The trace is unactivated
//  At init, *TraFlg pointed on the value of CATTraMode

     int *TraFlg;


//-----------------------------------------------------------------------
//
//  Read the value of *TraFlg
//
//-----------------------------------------------------------------------

inline int IsActive();

	// This method should be used to encapsulate code used for the trace
	//
	// if (TraceInstance.IsActive()) { 
	//
	//	... 
	//	...
	//	TraceInstance.TraPut ... 
	//
	//
	// }



//        *******************************************************
//        ***                                                 ***
//        ***            METHOD OF OUTPUT                     ***
//        ***                                                 ***
//        *******************************************************



//-----------------------------------------------------------------------
//
//  TraPut
//
//	TraPut, TraPutF, TraPutX is an efficient way to generate trace 
//	message.
//	
//	TraPut is used to send message string  and integer
//	The argument level is used to classify message by level of importance
//	Its value by default is 2 ( 0 and 1 is reserves for title )
//	In using a level argument, you will change the level value for
//	all next trace
//
//	TraPut 	is used to pass string or string + integer
//
//	TraPutF is used to pass floats
//
//	TraPutX is used to pass integer with on hexa format
//
//-----------------------------------------------------------------------


// 	Argument a string alone or a string + long integer
//      --------------------------------------------------


int TraPut( const char *Message );

int TraPut(int Level  , const char *Message ); 

int TraPut( const char *Message, CATLONG32 Var  ); 

int TraPut(int Level  , const char *Message, CATLONG32 Var  ); 

// 	Argument is a string + float
//      ----------------------------

int  TraPutF(const char *Message, float Var ); 

int  TraPutF(int Level, const char *Message, float Var ); 

#ifndef _WeDontNeedADoubleMan
//      Argument is a string + float
//      ----------------------------

int  TraPutF(const char *Message, double Var );

int  TraPutF(int Level, const char *Message, double Var );

#endif

// 	Argument is a string + long integer (formatted on hexa)
//      -------------------------------------------------------

int TraPutX(const char *Message, CATLONG32 Var ); 

int TraPutX(int Level, const char *Message, CATLONG32 Var ); 

#if defined(PLATEFORME_DS64)
// 	Argument is a string + CATULONGPTR (formatted on hexa)
//      -------------------------------------------------------

int TraPutX(const char *Message, CATULONGPTR Var ); 

int TraPutX(int Level, const char *Message, CATULONGPTR Var ); 

// 	Argument is a string + CATLONGPTR (formatted on hexa)
//      -------------------------------------------------------

int TraPutX(const char *Message, CATLONGPTR Var ); 

int TraPutX(int Level, const char *Message, CATLONGPTR Var ); 

#endif

//-----------------------------------------------------------------------
//
//  TraPutLN
//
//	TraPutLN, TraPutFLN, TraPutXLN have same functionality than  
//	TraPut, TraPutF, TraPutX but generate a "\n" after the argument passage
//
//	For performance reason, you should prefer to code your trace 
//
//
//	TraceInstance.TraPut("Msg Num = ", 1)
//	TraceInstance.TraPutLN("\nMsg Num = ", 2)
//
//	than
//
//	TraceInstance.TraPutLN("Msg Num = ", 1)
//	TraceInstance.TraPutLN("Msg Num = ", 2)
//
//-----------------------------------------------------------------------

// 	Argument a string alone or a string + long integer
//      --------------------------------------------------

int TraPutLN( const char *Message ); 

int TraPutLN(int Level  , const char *Message ); 

int TraPutLN( const char *Message, CATLONG32 Var  ); 

int TraPutLN(int Level  , const char *Message, CATLONG32 Var  ); 

// 	Argument is a string + float
//      ----------------------------

int  TraPutFLN(const char *Message, float Var ); 

int  TraPutFLN(int Level, const char *Message, float Var ); 

#ifndef _WeDontNeedADoubleMan

//      Argument is a string + float
//      ----------------------------

int  TraPutFLN(const char *Message, double Var );

int  TraPutFLN(int Level, const char *Message, double Var ); 

#endif

// 	Argument is a string + long integer (formatted on hexa)
//      -------------------------------------------------------

int TraPutXLN(const char *Message, CATLONG32 Var ); 

int TraPutXLN(int Level, const char *Message, CATLONG32 Var ); 

#if defined(PLATEFORME_DS64)

// 	Argument is a string + unsigned long integer (formatted on hexa)
//      ----------------------------------------------------------------

int TraPutXLN(const char *Message, CATULONGPTR Var ); 

int TraPutXLN(int Level, const char *Message, CATULONGPTR Var ); 

// 	Argument is a string + long integer (formatted on hexa)
//      -------------------------------------------------------

int TraPutXLN(const char *Message, CATLONGPTR Var ); 

int TraPutXLN(int Level, const char *Message, CATLONGPTR Var ); 

#endif

//-----------------------------------------------------------------------
//
//  TraPrint
//
//	TraPrint is used to pass trace message with a variable number of argument
//
//	format is a string format with the same syntaxe than printf
//
//	In the case of the log in memory, this trace is far less performance
//	than TraPut familly and should be avoided.
//
//	Another point TraPrint can not inline. Function supporting variable number
//	of argument can not be inline and are costly in performance 
//	so code it this way
//
//		if (TraceInstance.IsActive()) {
//			TraceInstance.TraPrint ...
//		
//		}
//
//	If your trace is not actived, you will avoid to lose perfo.
//
//-----------------------------------------------------------------------

int TraPrint( const char *format, ...) ; 

int TraPrint(int Level, const char *format, ...) ; 

};

inline int CATTrace::IsActive()
{
  return( TraFlg ?  *TraFlg : 0);
}

// ++vxg - 12:09:27
#endif  // DSY_SYS_TRACE_SYSTEM_MIGRATION
// --vxg - 12:09:27

#endif
