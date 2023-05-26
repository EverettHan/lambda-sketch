// COPYRIGHT DASSAULT SYSTEMES 1996
// DAL
//
//=================================================================
//
// IDENTIFICATION :
// --------------
//
//    RESPONSABLE : L. BAUDRY - lby
//    FONCTION   :  Trace controle
//    USAGE      :  Class offer a controle of a trace by calls
//		    These controle included level limit modification, 
//		    flag modification, 
//		    Device modification, flush of one or all traces, ...
//    NAME       :  CATTraStream.h
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

#ifndef CATTraControle_H
#define CATTraControle_H


#include <stdio.h> 

#include "CATtraproto.h"



class ExportedByJS03TRA  CATTraControle 
{

   public :

//-----------------------------------------------------------------------
//
// Constructor
//
//
//-----------------------------------------------------------------------
  CATTraControle ( const char TraName[]="TRA_DEBUG") ;    


//-----------------------------------------------------------------------
//
//  Destructor
//
//
//-----------------------------------------------------------------------

 ~CATTraControle ( ) ;


//-----------------------------------------------------------------------
//
//  Public Variable used in inline method
//
//-----------------------------------------------------------------------



//  Trace Descriptor ( indice of the trace )

     int TraDesc;
     



//        *******************************************************
//        ***                                                 ***
//        ***            METHOD OF CONTROL                    ***
//        ***                                                 ***
//        *******************************************************



//-----------------------------------------------------------------------
//
//  Flag modification
//
//
//-----------------------------------------------------------------------

int  TraGetFlg() ;
void TraPutFlg(int TraActInit) ;

//-----------------------------------------------------------------------
//
//  Level limit modification
//
//
//-----------------------------------------------------------------------

int   TraGetLevelMax() ;
int   TraPutLevelMax(int Level) ;

int   TraGetLevelMin() ;
int   TraPutLevelMin(int Level) ;

//-----------------------------------------------------------------------
//
//  Device modification
//
//
//-----------------------------------------------------------------------


char * TraGetDevice() ;
void  TraPutDevice(const char *Device) ;

//-----------------------------------------------------------------------
//
//  Comment string read
//
//
//-----------------------------------------------------------------------

char *  TraGetComment() ;

//-----------------------------------------------------------------------
//
//  Flush of the current Trace from  the log in memory into the device
//
//
//-----------------------------------------------------------------------

int  TraFlushMemory(const char Device[]="STDERR", int LevelLimitMax=TRA_LEVEL_LIMIT_MAX );


//-----------------------------------------------------------------------
//
//  
//  If the trace is on a stream as STDOUT, STDERR, or a file
//  This stream is flush
//  If the trace is on the log in memory, nothing is made
//
//-----------------------------------------------------------------------

void  TraFlushStream();

//-----------------------------------------------------------------------
//
//  Flush of all trace of the log in memory
//  Membre static
//
//-----------------------------------------------------------------------

static int  TraFlushMemoryAll(const char Device[] = "STDERR", int LevelLimitMax = TRA_LEVEL_LIMIT_MAX  );


//-----------------------------------------------------------------------
//
//  Clear the log in memory
//
//
//-----------------------------------------------------------------------


static int  TraClearLog( );

//-----------------------------------------------------------------------
//
//  Controle Fonction Global to all trace
//  Membre static
//
//-----------------------------------------------------------------------

static int TraChOpt(const char *OptionStr, const char Device[]="NULL");

//-----------------------------------------------------------------------
//
//  Format of Stream of trace
//
//
//-----------------------------------------------------------------------

static int TraFormatStream(FILE *StreamOut, const char *FileName, 
			   int LevelLimit = TRA_LEVEL_LIMIT_MAX, const char TraName[]= "");

//  Number Max of Trace 
//-----------------------

static int   TraHowManyTrace() ;

//  List of name 
//---------------

static void  TraGetTraceInit() ;
static char * TraGetNextTrace() ;  // Return NULL pointor if no more traces

//-----------------------------------------------------------------------
//
//  This function modifies the path of where file trace are sent
//	
//
//-----------------------------------------------------------------------

static char *  TraGetTracePath() ;

static int   TraPutTracePath(const char *FileTrace) ;


//-----------------------------------------------------------------------
//
//  This function return the path of where the file of option is in
//	
//
//-----------------------------------------------------------------------

static const char *  TraGetTraDecPath() ;


//-----------------------------------------------------------------------
//
//  This function handles the flag about trace formated or not
//	
//
//-----------------------------------------------------------------------

static int  TraGetSpecialFileTraceFormated() ;

static void  TraPutSpecialFileTraceFormated(int flg) ;

//-----------------------------------------------------------------------
//
//  This is use to read an option file
//	
//
//-----------------------------------------------------------------------

static void TraUpdateFrOptFile(const char *OptionPath);

};
#endif


