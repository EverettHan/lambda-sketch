// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMENOVIAImplTrace.h
// Trace object for your document
//
//===================================================================
//
// Usage notes:
// This class will enable you to output traces to the output console
// CNext traces can be turned on or off interactively during the session
// You may choose to use another existing trace object rather than having
// to many trace objects. 
// In this case, make the recommended changes in this header file and in 
// the corresponding source file.
//
//----------
// If you want to add traces in your .cpp, you must add at the top
// of your file the 2 following lines :
//
//   #include "CATPLMWtpTrace.h"
//   CATPLMWtpTraceDefine(MY_TRACE_NAME)
//
// where you must replace MY_TRACE_NAME by the name of your traces
//
//===================================================================
//
//  SRU(jul03) Creation
//===================================================================
#ifndef CATPLMWtpTrace_H
#define CATPLMWtpTrace_H

#include "CATTrace.h"
/**
* If you would rather use another existing trace object, add the include
* of the trace object here
*/

/**
* @level Private
* @usage U1
*/

/**
* <p>
* If you would rather use another existing trace object, remove this
* declaration
*/

// Always active trace even on client site
#define PLMQLERRORTRACE static CATTrace CATPLMQLErrorTrace("PLMQLError","",CATTraActivated)

// Trace active only in DS and deactivated by default
#ifndef CNEXT_CLIENT 
/** Define */
#define CATPLMWtpTraceDefine(a) static CATTrace CATPLMWtpTrace(#a,"Traces CATPLMWtpTrace",CATTraUnactivated);
/** Is Active ? */
#define CATPLMWtpTraceActive CATPLMWtpTrace.IsActive()
/** 1 strings */
#define CATPLMWtpTracePUT(Message)      do {CATPLMWtpTrace.TraPut(Message);} while (0)
/** 1 strings + rc*/
#define CATPLMWtpTracePUTLN(Message)    do {CATPLMWtpTrace.TraPutLN(Message);} while (0)
/** 2 strings + rc*/
#define CATPLMWtpTracePUTLN2(MSG1,MSG2)    do {CATPLMWtpTrace.TraPut(MSG1); CATPLMWtpTrace.TraPutLN(MSG2);} while (0)

#define CATPLMWtpTracePUTILN2(MSG1,MSG2)    do {CATPLMWtpTrace.TraPut(MSG1);CATUnicodeString str2;str2.BuildFromNum(MSG2);CATPLMWtpTrace.TraPutLN(str2.CastToCharPtr());} while (0)
/** 3 strings + rc*/
#define CATPLMWtpTracePUTLN3(MSG1,MSG2,MSG3)    do {CATPLMWtpTrace.TraPut(MSG1); CATPLMWtpTrace.TraPut(MSG2); CATPLMWtpTrace.TraPutLN(MSG3);} while (0)

#define CATPLMWtpTracePUTLN4(MSG1,MSG2,MSG3,MSG4)    do {CATPLMWtpTrace.TraPut(MSG1); CATPLMWtpTrace.TraPut(MSG2); CATPLMWtpTrace.TraPutLN(MSG3); CATPLMWtpTrace.TraPutLN(MSG4);} while (0)
/** 1 strings + int+rc*/
#define CATPLMWtpTracePUTNLN(Message,var)    do {CATPLMWtpTrace.TraPutLN(Message,var);} while (0)
/** string + long (hexa) + rc */
#define CATPLMWtpTracePUTXLN(Message,var)    do {CATPLMWtpTrace.TraPutXLN(Message,var);} while (0)
/** string + float + rc */
#define CATPLMWtpTracePUTFLN(Message,var)    do {CATPLMWtpTrace.TraPutFLN(Message,var);} while (0)
/** string + long + rc */
#define CATPLMWtpTracePUTLLN(Message,var)    do {CATPLMWtpTrace.TraPutLN(Message,var);} while (0)

#else

#define CATPLMWtpTraceDefine(a)
#define CATPLMWtpTraceActive 0
#define CATPLMWtpTracePUT(Message)    
#define CATPLMWtpTracePUTLN(Message) 
#define CATPLMWtpTracePUTLN2(MSG1,MSG2) 
#define CATPLMWtpTracePUTILN2(MSG1,MSG2)
#define CATPLMWtpTracePUTLN3(MSG1,MSG2,MSG3)
#define CATPLMWtpTracePUTLN4(MSG1,MSG2,MSG3,MSG4)
#define CATPLMWtpTracePUTNLN(Message,var)
#define CATPLMWtpTracePUTXLN(Message,var) 
#define CATPLMWtpTracePUTFLN(Message,var)
#define CATPLMWtpTracePUTLLN(Message,var)

#endif

#endif
