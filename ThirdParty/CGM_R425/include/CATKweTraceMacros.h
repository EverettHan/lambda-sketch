//===================================================================
// CATKweTraceMacros
// Macros for traces defined in the class CATkweTrace
//===================================================================
//
// Usage notes: 
//
//===================================================================
//  24.11.20 Creation KJD
//===================================================================/**

#ifndef CATKweTraceMacros_h
#define CATKweTraceMacros_h
#include "CATKweTrace.h"

//------------------------ TRACE
#define KWTRA(name, message)                     \
    {                                            \
        if (CAT##name##Trace.IsConfigured() && CAT##name##Trace._pConverter)        \
        {                                        \
          CAT##name##Trace._pConverter->Flush(); \
          (*CAT##name##Trace._pConverter) << message; \
          CAT##name##Trace.DumpTrace();          \
        }        \
	}

#define KWTRAN(name, message) KWTRA(name, message << endl);
//------------------------ NEW MACROS

#define KWTRA_ENTER_METHOD(name) CAT##name##Trace.EnterMethod(__FUNCTION__)
#define KWTRA_EXIT_METHOD(name) CAT##name##Trace.ExitMethod(__FUNCTION__)
#define KWTRA_EXIT_METHOD_RC(name, iRC) CAT##name##Trace.ExitMethodWithHRESULT(__FUNCTION__, iRC)

#define KWTRA_ACTIVATED(name) CAT##name##Trace.IsConfigured()

#endif

