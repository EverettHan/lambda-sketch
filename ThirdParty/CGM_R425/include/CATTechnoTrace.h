/**
 * @level Private
 * @usage U1
 */
#ifndef CATTechnoTrace_H
#define CATTechnoTrace_H

// COPYRIGHT DASSAULT SYSTEMES   1998
//=============================================================================
//
// class CATTechnoTrace :
//    Traces utilities for TechnoLinks
//
//=============================================================================
// Usage Notes:
//
// 
//=============================================================================
// Sept. 98   Creation           RCI
//=============================================================================


#include "TECHNLNK.h"
#include "CATTraMacro.h"


extern ExportedByTECHNLNK int* TechnoTrace_Ptr ;
extern ExportedByTECHNLNK int  TechnoTrace_Desc ;

#ifndef CNEXT_CLIENT

#define Techno_Trace1(level, message)                             \
if (CATDevelopmentStage() && TechnoTrace_Ptr && *TechnoTrace_Ptr )                         \
  {traprint(  TechnoTrace_Desc, level , message ) ;               \
  traflush(  TechnoTrace_Desc, "STDOUT", 50 ) ;}                  \

#define Techno_Trace2(level, message, parm1 )                     \
if (CATDevelopmentStage() && TechnoTrace_Ptr && *TechnoTrace_Ptr )                         \
  {traprint(  TechnoTrace_Desc, level , message, parm1 ) ;        \
  traflush(  TechnoTrace_Desc, "STDOUT", 50 ) ;}      

#define Techno_Trace3(level, message, parm1, parm2 )              \
if (CATDevelopmentStage() && TechnoTrace_Ptr && *TechnoTrace_Ptr )                         \
  {traprint(  TechnoTrace_Desc, level , message, parm1, parm2 ) ; \
  traflush(  TechnoTrace_Desc, "STDOUT", 50 ) ;}      

#else
#define Techno_Trace1(level, message)                          
#define Techno_Trace2(level, message, parm1 )   
#define Techno_Trace3(level, message, parm1, parm2 ) 
#endif


#endif



