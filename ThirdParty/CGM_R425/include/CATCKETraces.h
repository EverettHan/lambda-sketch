// COPYRIGHT DASSAULT SYSTEMES  1998
//=============================================================================
//
// CATCKETraces.h: KWE Internal Usage Only 
//                 This class offers a methodology to output traces
//                 It is based on the System Class that allows you to (des)activate them at runtime
//                 We are also able to make them completely disappear at build time
//                 If you do your job properly, we'll be able to trace the object leaks 
//                 (that are allocated and not released) 
//
//=============================================================================
// Usage Notes:
//
//   1- If you want to create a new kind of trace, concerning for example designtable
//
//     - create a CATCKETraceDesignTable.h like this to define the new trace type 
//        
//        //------------------------------------------              
//        #include "CK0FEAT.h"
//        #define   CATCKETraceType      DesignTable
//        #define   CATCKETraceExport    ExportedByCK0FEAT
//        #include "CATCKETraces.h"
//        //------------------------------------------              
//        DesignTable is used to generate static variables with different names
//        ExportedByCK0FEAT generates the good dllexport and import on NT
//        CK0FEAT must be the module in which  CATCKETraceDesignTable.cpp is
//
//     - create a CATCKETraceDesignTable.cpp like this (you can also put it in one of your .cpp)
//       to implement your trace type 
//        //------------------------------------------              
//        #include "CATCKETraceDesignTable.h"
//        CATCKETraceDefine("DesignTable",1,"comment")
//        //------------------------------------------              
//        "DesignTable" is the name of the trace shown in CNEXT so that you can activate 
//        or desactivate the traces.
//        1 is for activation at build time, 0 for desactivation at build time    
//        "comment"  is the name of the comment   shown in CNEXT
//
//   2- If you want to use traces of this kind in a class CATxx 
//
//     - first, include your trace type definition.    
//        //------------------------------------------              
//        #define   CATCKETraceClass     CATxx // this is used as a prefix in the traces output
//        #include "CATCKETraceDesignTable.h"
//        //------------------------------------------              
//
//        the CATCKETraceClass  define is optional. If not defined, the prefix will be DesignTable
//        (name first argument of CATCKETraceDefine
//
//     - then use it
//       use CATCKETraceCreate in constructor (to have a trace AND Purify management)
//       use CATCKETraceCopy   in copy-constructor (to have a trace AND Purify management)
//       use CATCKETraceDelete in destructor (to have a trace AND Purify management)
//
//       use CATCKEPut(2,hello) to trace "Hello"
//       use CATCKEPrint(2,hello %s,s) to trace "Hello John"
//       use CATCKEPrintN(2,hello %s,s) to trace "Hello John\n"
//       use CATCKEPlus(2,hello %s,s) to add trace "Hello John"
//       use CATCKEPlusN(2,hello %s,s) to add trace "Hello John\n"
//
//       if you want to see an example, look at CATCKETracesInit.h/.cpp 
//
//=============================================================================
// 20/08/98   Modification                                   T. Videcoq
// 24/09/98   Modification                                   F. Riche
//=============================================================================

#ifndef CATCKETraces_H
#define CATCKETraces_H


/** Let-s define two things to allow traces in developpement and purify management,
    and to avoid them on customer code

    - CNEXT_CLIENT is defined on releases for clients, so traces are'nt used in this mode
    - CATCKEPurify should NEVER be defined in release. It generates a listing of all objects
    created and not deleted. 
    - to have a leak report in your TestCode objects use CATCKEPurifyStart at the beginning
    and  CATCKEPurifyBilan at the end when everything should be deallocated    */

#include <stdlib.h>
#include <memory.h>
#include <string.h>

// Definit ou non le define CATCkePurifyOn
#include "CATCkePurify.h"

#ifdef CNEXT_CLIENT

  //---------------------------------------------
  // No traces
  //---------------------------------------------
#define CATCKETraceDefine(x,i,z) 
  #define CATCKETraceCreate {}
  #define CATCKETraceCopy {}
  #define CATCKETraceDelete {}
  #define CATCKEPut(l,x) {}
  #define CATCKEPrint(l,x,y) {}
  #define CATCKEPrintN(l,x,y) {}
  #define CATCKEPlus(l,x,y) {}
  #define CATCKEPlusN(l,x,y) {}
  #define CATCKEPrintf(x){}
  #define CATCKETraceOpen {}
  #define CATCKEIn(level,message) {}
  #define CATCKEOut(level,message) {}
#else

//#define CATCKEPurifyOn
//#define CATCKETracesOn
  //---------------------------------------------
  // structure definition to manage informations on traces
  //---------------------------------------------
  struct CATCkeTracesType  
  {
  const char  *T;
  int          I; 
  int          D; 
  int         *O; 
  int          E; 
  const char  *C; 
};

  //---------------------------------------------
  // with traces
  //---------------------------------------------
#include "CATTraMacro.h"
#include "CATCKETracesIndent.h"

//------------------------------------------------------------
// CATCKETraceDefine
//------------------------------------------------------------
  // define the generated variable with CATCKETraceType suffix

  CATCKETraceExport extern CATCkeTracesType CATCKETraceType; 


  // defines the name of the system kind of class that you'll be able to activate
  // and implement the generated variable (should be done once)
  #define CATCKETraceDefine(x,y,c)  \
  CATCKETraceExport CATCkeTracesType  CATCKETraceType ={x,y,0,NULL,0,c};  


//------------------------------------------------------------
// CATCKETraceClassname
//------------------------------------------------------------
  // defines the class name to prefix the traces
  #ifdef CATCKETraceClass
  #define CATCKETraceClass2  CATCKETraceClass
  #else
  #define CATCKETraceClass2  CATCKETraceType.T
  #endif




//------------------------------------------------------------
// CATCKETraceOpen (used by CATCKETraceCreate and CATCKETraceCopy 
//------------------------------------------------------------
// init = 0 si inactivée
// init = 1 si activée
// trace_name est le nom de la trace (max : 14 caractères)

#ifdef _WINDOWS_SOURCE

#define CATCKETraceOpen     \
{                                                   \
  char dbg_output[14]="STDOUT";                     \
  int dbg_limit=255;                                \
  if (CATCKETraceType.D == 0)                       \
  {                                                 \
	  CATCKETraceType.O = &CATCKETraceType.E;       \
	  CATCKETraceType.D =                           \
	  traopen( CATCKETraceType.T,                   \
	    CATCKETraceType.I,                          \
	    &CATCKETraceType.O,                         \
	    dbg_output,                                 \
	    dbg_limit,                                  \
	    (char*)(CATCKETraceType.C));                \
  }                                                 \
}

#else

#define CATCKETraceOpen    \
{                                                   \
   char dbg_output[14]="STDOUT";                    \
  int dbg_limit=255;                                \
   if (CATCKETraceType.D ==0)   CATCKETraceType.D =                         \
   traopen( CATCKETraceType.T,                              \
   	    CATCKETraceType.I,                                        \
	    &CATCKETraceType.O,                               \
	    dbg_output,                                 \
	    dbg_limit,                                  \
	    (char *)(CATCKETraceType.C));                              \
}

#endif


#define CATCKEDecal(level) \
{	if(CATCKEIndentVar) { \
		char* Decal = new char[CATCKEIndentVar+1]; \
		memset(Decal,' ',CATCKEIndentVar); \
		Decal[CATCKEIndentVar]='\0'; \
		traput (CATCKETraceType.D, level, Decal);\
		traput (CATCKETraceType.D, level, Decal);\
		delete [] Decal;}}

#define CATCKEIn(level,message) \
{  if (CATCKETraceType.O && *CATCKETraceType.O)   {                          \
		CATCKEDecal(level); \
    traput ( CATCKETraceType.D, level,"-->");\
    traput ( CATCKETraceType.D, level,CATCKETraceClass2); \
    traput ( CATCKETraceType.D, level, message);              \
		traput ( CATCKETraceType.D, level,"\n"); } \
  CATCKEIndentVar++;}

#define CATCKEOut(level,message) \
{  if (CATCKETraceType.O && *CATCKETraceType.O)   { \
	if(CATCKEIndentVar) \
		CATCKEIndentVar--; \
		CATCKEDecal(level); \
    traput ( CATCKETraceType.D, level,"<--"); \
    traput ( CATCKETraceType.D, level,CATCKETraceClass2); \
    traput ( CATCKETraceType.D, level, message);              \
		traput ( CATCKETraceType.D, level,"\n"); }}

//------------------------------------------------------------
// CATCKEPut
//------------------------------------------------------------

#define CATCKEPut(level,message)                         \
{  if (CATCKETraceType.O && *CATCKETraceType.O)   {                          \
		CATCKEDecal(level); \
    traput ( CATCKETraceType.D, level,CATCKETraceClass2); \
    traput ( CATCKETraceType.D, level,message);                 \
    traput ( CATCKETraceType.D, level,"\n"); }  }


//------------------------------------------------------------
// CATCKEPrint
//------------------------------------------------------------

#define CATCKEPrint(level,message,variable)              \
{  if (CATCKETraceType.O && *CATCKETraceType.O)   {                          \
		CATCKEDecal(level); \
    traput ( CATCKETraceType.D, level,CATCKETraceClass2); \
    traprint ( CATCKETraceType.D, level, message,variable);  } }

//------------------------------------------------------------
// CATCKEPrintN
//------------------------------------------------------------
#define CATCKEPrintN(level,message,variable)             \
{  if (CATCKETraceType.O && *CATCKETraceType.O)   {                          \
		CATCKEDecal(level); \
    traput ( CATCKETraceType.D, level,CATCKETraceClass2); \
    traprint ( CATCKETraceType.D, level, message,variable);              \
    traput ( CATCKETraceType.D, level,"\n"); }  }


#define CATCKEPrintf(x) \
	if (CATCKETraceType.O && *CATCKETraceType.O)   {                          \
		traput(CATCKETraceType.D, 2, x);}

//------------------------------------------------------------
// CATCKEPlus
//------------------------------------------------------------
#define CATCKEPlusN(level,message,variable)              \
{  if (CATCKETraceType.O && *CATCKETraceType.O)   {                          \
		CATCKEDecal(level); \
    traprint ( CATCKETraceType.D, level, message,variable);              \
    traput ( CATCKETraceType.D, level,"\n");    }        }

//------------------------------------------------------------
// CATCKEPlus
//------------------------------------------------------------
#define CATCKEPlus(level,message,variable)               \
{  if (CATCKETraceType.O && *CATCKETraceType.O)   {                          \
		CATCKEDecal(level); \
    traprint ( CATCKETraceType.D, level,                   \
		 message,variable); }   }         

//------------------------------------------------------------
// CATCKEPlus
//------------------------------------------------------------

#ifndef CATCKEPurifyOn

  //---------------------------------------------
  // Sans Purify
  //---------------------------------------------
//------------------------------------------------------------
// CATCKETraceCreate/Copy/Delete
//------------------------------------------------------------
#define CATCKETraceCreate CATCKETraceOpen  CATCKEPut(3,"Constructor")
#define CATCKETraceCopy   CATCKETraceOpen  CATCKEPut(3,"Copy-Constructor")
#define CATCKETraceDelete                  CATCKEPut(3,"Destructor")

#else

//---------------------------------------------
// Avec Purify
//---------------------------------------------
//#include "CATCkePurify.h"

//------------------------------------------------------------
// CATCKETraceCreate/Copy/Delete
//------------------------------------------------------------
#define CATCKETraceCreate CATCKETraceOpen  \
CATCKEPut(3,"Constructor") \
CATCkePurify::Push(CATCKETraceClass2);
/*void *ptr = (void *) this;\
CATCkePurify::PushForName(ptr); \*/


#define CATCKETraceCopy   \
CATCKETraceOpen  \
CATCKEPut(3,"Copy-Constructor") \
CATCkePurify::Push(CATCKETraceClass2); 
/*void *ptr = (void *) this;\
CATCkePurify::PushForName(ptr); \*/


#define CATCKETraceDelete        \
CATCKEPut(3,"Destructor") \
CATCkePurify::Pop(CATCKETraceClass2); 
/*void *ptr = (void *) this;\
CATCkePurify::PopForName(ptr); \*/


#endif



#endif

#endif

