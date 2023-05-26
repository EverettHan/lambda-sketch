/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATLNK_TRACE_H_
#define CATLNK_TRACE_H_


#include "CATTraMacro.h"
#include "CATObjectModelerBase.h"

// ----------------------------------------------------------------------------
//                     Pour les traces relatives aux liens symboliques
//
// ----------------------------------------------------------------------------

extern ExportedByCATObjectModelerBase int* OMLNKTrace_Ptr ;
extern ExportedByCATObjectModelerBase int  OMLNKTrace_Desc ;

#ifndef CNEXT_CLIENT

#define OMLNK_TRACE1(level, message)                             \
if (OMLNKTrace_Ptr && *OMLNKTrace_Ptr )                          \
  {traprint(  OMLNKTrace_Desc, level , message ) ;               \
  traflush(  OMLNKTrace_Desc, "STDOUT", 50 ) ;}                  \

#define OMLNK_TRACE2(level, message, parm1 )                     \
if (OMLNKTrace_Ptr && *OMLNKTrace_Ptr )                          \
  {traprint(  OMLNKTrace_Desc, level , message, parm1 ) ;        \
  traflush(  OMLNKTrace_Desc, "STDOUT", 50 ) ;}      

#define OMLNK_TRACE3(level, message, parm1, parm2 )              \
if (OMLNKTrace_Ptr && *OMLNKTrace_Ptr )                          \
  {traprint(  OMLNKTrace_Desc, level , message, parm1, parm2 ) ; \
  traflush(  OMLNKTrace_Desc, "STDOUT", 50 ) ;}      

#else
#define OMLNK_TRACE1(level, message)                             
#define OMLNK_TRACE2(level, message, parm1 )                     
#define OMLNK_TRACE3(level, message, parm1, parm2 )             

#endif
#endif
