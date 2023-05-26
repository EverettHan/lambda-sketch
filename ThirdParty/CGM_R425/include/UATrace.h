#ifndef UATrace_h
#define UATrace_h
#include "ExportedByUAServices.h"

// COPYRIGHT DASSAULT SYSTEMES 2014
// protected UserAssistance/UAServices.m

#include "CATTrace.h"
#include "CATBoolean.h"

ExportedByUAServices CATBoolean UATraceWithoutPtr ();

// Macro definitions

#define UATRALN(name) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPutLN(""); }
#define UATRASPACE(name,length) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint("%length##s"," "); }
#define UATRAMSG(name,msg) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPut(msg); }
#define UATRAMSGLN(name,msg) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPutLN(msg); }
#define UATRACTOR(name) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint("#%s[%.8x]",ClassName(),(UATraceWithoutPtr()?NULL:this)); }
#define UATRACTORLN(name) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint("#%s[%.8x]\n",ClassName(),(UATraceWithoutPtr()?NULL:this)); }
#define UATRADTOR(name) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint("~%s[%.8x]",ClassName(),(UATraceWithoutPtr()?NULL:this)); }
#define UATRADTORLN(name) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint("~%s[%.8x]\n",ClassName(),(UATraceWithoutPtr()?NULL:this)); }
#define UATRASTACK(name,id) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%.8x]::%s",ClassName(),(UATraceWithoutPtr()?NULL:this),id); }
#define UATRASTACKLN(name,id) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%.8x]::%s\n",ClassName(),(UATraceWithoutPtr()?NULL:this),id); }
#define UATRANAMESTACK(name,id) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%.8x][%s]::%s",ClassName(),(UATraceWithoutPtr()?NULL:this),(GetName().GetLengthInChar()?GetName().CastToCharPtr():""),id); }
#define UATRANAMESTACKLN(name,id) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%.8x][%s]::%s\n",ClassName(),(UATraceWithoutPtr()?NULL:this),(GetName().GetLengthInChar()?GetName().CastToCharPtr():""),id); }
#define UATRAPTR(name,id,value) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%.8x]",id,(UATraceWithoutPtr()?NULL:value)); }
#define UATRAPTRLN(name,id,value) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%.8x]\n",id,(UATraceWithoutPtr()?NULL:value)); }
#define UATRAINT(name,id,value) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%d]",id,value); }
#define UATRAINTLN(name,id,value) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%d]\n",id,value); }
#define UATRASTR(name,id,value) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%s]",id,value); }
#define UATRASTRLN(name,id,value) \
 { if (CATDevelopmentStage()) UA##name##Trace.TraPrint(" %s[%s]\n",id,value); }

// Exposed Trace declarations

extern ExportedByUAServices CATTrace UATooltipsTrace;
extern ExportedByUAServices CATTrace UAPanelsTrace;
extern ExportedByUAServices CATTrace UAHelpUATrace;

// Internal trace declarations

#endif
