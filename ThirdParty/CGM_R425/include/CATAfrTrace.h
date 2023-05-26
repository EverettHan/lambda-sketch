#ifndef CATAfrTrace_h
#define CATAfrTrace_h

// COPYRIGHT DASSAULT SYSTEMES 2014

#include "UndoRedoUI.h"
#include "CATTrace.h"
#include "CATBoolean.h"

class CATUnicodeString;

ExportedByUndoRedoUI CATBoolean CATAfrTraceWithoutPtr (); // used in DI0STDMDL module

// Macro definitions

#define AFRTRALN(name) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPutLN(""); }
#define AFRTRASPACE(name,length) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint("%length##s"," "); }
#define AFRTRAMSG(name,msg) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPut(msg); }
#define AFRTRAMSGLN(name,msg) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPutLN(msg); }
#define AFRTRACTOR(name) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint("#%s[%.8x]",ClassName(),(CATAfrTraceWithoutPtr()?NULL:this)); }
#define AFRTRACTORLN(name) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint("#%s[%.8x]\n",ClassName(),(CATAfrTraceWithoutPtr()?NULL:this)); }
#define AFRTRADTOR(name) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint("~%s[%.8x]",ClassName(),(CATAfrTraceWithoutPtr()?NULL:this)); }
#define AFRTRADTORLN(name) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint("~%s[%.8x]\n",ClassName(),(CATAfrTraceWithoutPtr()?NULL:this)); }
#define AFRTRASTACK(name,id) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%.8x]::%s",ClassName(),(CATAfrTraceWithoutPtr()?NULL:this),id); }
#define AFRTRASTACKLN(name,id) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%.8x]::%s\n",ClassName(),(CATAfrTraceWithoutPtr()?NULL:this),id); }
#define AFRTRANAMESTACK(name,id) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%.8x][%s]::%s",ClassName(),(CATAfrTraceWithoutPtr()?NULL:this),(GetName().GetLengthInChar()?GetName().CastToCharPtr():""),id); }
#define AFRTRANAMESTACKLN(name,id) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%.8x][%s]::%s\n",ClassName(),(CATAfrTraceWithoutPtr()?NULL:this),(GetName().GetLengthInChar()?GetName().CastToCharPtr():""),id); }
#define AFRTRAPTR(name,id,value) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%.8x]",id,(CATAfrTraceWithoutPtr()?NULL:value)); }
#define AFRTRAPTRLN(name,id,value) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%.8x]\n",id,(CATAfrTraceWithoutPtr()?NULL:value)); }
#define AFRTRAINT(name,id,value) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%d]",id,value); }
#define AFRTRAINTLN(name,id,value) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%d]\n",id,value); }
#define AFRTRASTR(name,id,value) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%s]",id,value); }
#define AFRTRASTRLN(name,id,value) \
 { if (CATDevelopmentStage()) CATAfr##name##Trace.TraPrint(" %s[%s]\n",id,value); }

// Activated Trace declarations

extern ExportedByUndoRedoUI CATTrace CATAfrWarningTrace;

// Exposed Trace declarations

extern ExportedByUndoRedoUI CATTrace CATAfrSDOTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrUndoTrace; // used in DI0STDMDL module
extern ExportedByUndoRedoUI CATTrace CATAfrDumpTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrMessagesTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrUndoHeaderTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrUndoCSOTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrLicensingTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrAddinsTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrHelpTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrHelpFullTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrHelpIdTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrHelpIdToUrlTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrHelpRscTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrHelpRscFullTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrHelpUATrace;
extern ExportedByUndoRedoUI CATTrace CATAfrHelpUAPanelsTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrToolsPaletteTrace; // used in AfrStandard fw
extern ExportedByUndoRedoUI CATTrace CATAfrCommandSequenceTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrContextTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrCollabTrace; // used in AfrCollaboration fw
extern ExportedByUndoRedoUI CATTrace CATAfrComponentsTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrDeclarativeTrace;
extern ExportedByUndoRedoUI CATTrace CATAfrTransitionTrace;

// Internal trace declarations

#endif
