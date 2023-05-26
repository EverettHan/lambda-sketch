/* -*-c++-*- */
#ifndef CATFilTraces_h_
#define CATFilTraces_h_
#define CATFILLETTRACEIN

#include <stdio.h>
#include "CATErrors.h"
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"

extern ExportedByRIBLight int CATFILTraceOn;

#ifdef CATFILLETTRACEIN
#define FILLETTRACE(message)                                     \
  if (CATFILTraceOn)                                       \
     { printf("%s",message); }                         
      
//-----------------------------------------------------
//  level = niveau de trace
//
//  txtafter= "" ou "\n" pour fin de ligne
//
//  typ = x pour pointeurs
//        d pour integers
//        f pour float,double..
//
//    pour ecrire plusieurs methodes dans les trace :
//   #ifdef  CGMTRACEON
//   if (CATCGMDebug::TraceOn >= level) 
//     {
//       blabla ...
//     }
//   #endif
//-----------------------------------------------------
#define FILLETTRACEARG(txtbefore, typ , variable , txtafter)       \
  if (CATFILTraceOn)                                         \
     { printf("%s%"#typ"%s",txtbefore,variable, txtafter); }                               


#define FILLETTRACELINE                                            \
 if (CATCGMJournalTraceOn)                                          \
   { printf("File:%s Line:%d \n", __FILE__ , __LINE__); }             

#else


#define FILLETTRACE
#define FILLETTRACEARG(txtbefore, typ , variable , txtafter)  
#define FILLETTRACELINE


#endif


#endif

