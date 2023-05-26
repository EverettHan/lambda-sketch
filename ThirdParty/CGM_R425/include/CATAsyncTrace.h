#ifndef CATAsyncTrace_h
#define CATAsyncTrace_h

#include "CATAsyncStreamRequests.h"

#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "CATUuid.h"
#include "CATOmxList.h"
#include "CATVVSUrl.h"
#include "CATOmxArray.h"
#include "CATOmxLogError.h"

class CATError;

// 
// Trace are not thread safe but many Trace can trace concurrently 
//
// Main usage :
//   class MyClass {... Trace _Mytrace; ...}
//   MyClass::MyClass():_Mytrace("AppName",TRUE) {...}
//   MyClass::Method1AlwaysCalledInMainThread()   { StartTrace_Info(_Mytrace) << "I'm in Method1" << EndTrace_TS; ...}
//   MyClass::Method2CanBeCalledNotInMainThread() { StartTrace_Info(_Mytrace) << "I'm in Method1" << EndTrace_T;  ...}
// 
// If the code to generate the trace is expensive, one can test if the trace is active before using it
//   MyClass::Method3() {
//     if (_Mytrace.IsActive()) { 
//       CATUnicodeString strGeneratedTrace = ExpensiveFunction();
//       StartTrace_Warning(_Mytrace) << strGeneratedTrace << EndTrace_TS ;
//
// If a data member is not possible (e.g. in a static function), an instance can be created for each trace.
// If called from an auxiliary thread, it's a bit less efficient then it should be used carefully.
//   StaticFunctionOnError()   { TraceErrorT("AppName") << "I'm in error !" << EndTrace_T; }
//

// Encapsulation of CATOmxLogError
#define LogErrorIfAFailure(iErrId,iHr,iMsg)  { if (FAILED(iHr)) CATOmxLogError(iErrId, (CATUnicodeString) (CATAsync::Msg(iMsg).AddErrno()));}
#define LogImpactIfAFailure(iErrId,iHr,iMsg) { if (FAILED(iHr)) CATOmxLogImpact(iErrId,(CATUnicodeString) (CATAsync::Msg(iMsg).AddErrno()));}

// From the main thread : create and initialize a new trace with the given priority mode
#ifndef TraceError
#define TraceError(iTraceName)      CATAsync::Trace(iTraceName,TRUE).StartNewTrace(CATAsync::AT_ERROR)
#endif
#ifndef TraceWarning
#define TraceWarning(iTraceName)    CATAsync::Trace(iTraceName,TRUE).StartNewTrace(CATAsync::AT_WARNING)
#endif
#ifndef TraceInfo
#define TraceInfo(iTraceName)       CATAsync::Trace(iTraceName,TRUE).StartNewTrace(CATAsync::AT_INFO)
#endif
#ifndef TraceVerbose
#define TraceVerbose(iTraceName)    CATAsync::Trace(iTraceName,TRUE).StartNewTrace(CATAsync::AT_VERBOSE)
#endif

// From an auxiliary thread : create and initialize a new trace with the given priority mode
#define TraceErrorT(iTraceName)     CATAsync::Trace(iTraceName,FALSE).StartNewTrace(CATAsync::AT_ERROR)
#define TraceWarningT(iTraceName)   CATAsync::Trace(iTraceName,FALSE).StartNewTrace(CATAsync::AT_WARNING)
#define TraceInfoT(iTraceName)      CATAsync::Trace(iTraceName,FALSE).StartNewTrace(CATAsync::AT_INFO)
#define TraceVerboseT(iTraceName)   CATAsync::Trace(iTraceName,FALSE).StartNewTrace(CATAsync::AT_VERBOSE)

// Restart a new trace with the given priority mode.
#define StartTrace_Error(iTrace)   iTrace.StartNewTrace(CATAsync::AT_ERROR)
#define StartTrace_Warning(iTrace) iTrace.StartNewTrace(CATAsync::AT_WARNING)
#define StartTrace_Info(iTrace)    iTrace.StartNewTrace(CATAsync::AT_INFO)
#define StartTrace_Verbose(iTrace) iTrace.StartNewTrace(CATAsync::AT_VERBOSE)

// End of a trace from the main thread
#define EndTrace_TS CATAsync::EoT(TRUE)
// End of a trace from an auxiliary thread
#define EndTrace_T  CATAsync::EoT(FALSE)

#define Bool2String(iBool) ((iBool) ? ("TRUE") : ("FALSE") )

struct HR2Trace
{
  HR2Trace(HRESULT iHR) : _hr(iHR) {}
  HRESULT _hr;
};

struct PtrTrace
{
  PtrTrace(void * iPtr) : _ptr(iPtr) {}
  void * _ptr;
};

namespace CATAsync
{  
  class CATAsyncDumperTracer;

  // ==================================
  // Msg
  // ==================================
  struct ExportedByCATAsyncStreamRequests Msg
  {     
    Msg(const char  * iMsg=NULL)
      { if (iMsg) this->operator << (iMsg);}
    Msg(const Msg& iOther ) : _CurMsg(iOther._CurMsg)
      {}
    Msg& operator=(const Msg& iOther)
      { if (&iOther!=this) _CurMsg = iOther._CurMsg; return *this;}
    virtual ~Msg()
      {}  
    
    template <class T>
    Msg& operator << (const T * iObjPtr) = delete;
    
    template <class T>
    Msg& operator << (const T & iObjRef) = delete;
      
    // Main methods to add strings to the current Msg
    Msg& operator << ( const char *);     // << will be converted into CATUnicodeString then use if possible the operator "<<" with CATUnicodeString
    Msg& operator << ( const CATUnicodeString&);  
    
    // Numericals
    Msg& operator << ( const int &); 
    Msg& operator << ( const unsigned int &); 
    Msg& operator << ( const long &); 
    Msg& operator << ( const unsigned long &); 
    Msg& operator << ( const CATLONG64 &); 
    Msg& operator << ( const CATULONG64 &); 
    Msg& operator << ( const double &);   
    
    // Some usual classes or types
    Msg& operator << ( const CATUuid &); 
    Msg& operator << ( const CATBoolean &); 
    Msg& operator << ( const CATOmxArray<CATUuid>& );   
    Msg& operator << ( const CATError * );
    Msg& operator << ( const CATVVSUrl & );    
    Msg& operator << ( const HR2Trace & );  // Dump a HRESULT
    Msg& operator << ( const PtrTrace & ); // Dump the adress of a pointer  
    
    // Add the current errno
    Msg& AddErrno();
    
    // Get the content of the current Msg
    inline operator CATUnicodeString () const 
      { return _CurMsg; } 
    // Reset the content of the current Msg
    inline void Reset()
      {_CurMsg="";}
           
  private:    
      
    CATUnicodeString _CurMsg;  
  };

  // Class used to indicate the end of a trace
  struct EoT
  {
    // If iMt==TRUE, all tracers (i.e. thread safe or not) are allowed.  
    // If iMt==FALSE, only thread safe tracers are allowed (e.g. OMB_XML_TRACE tracer will be filtered)
    EoT(CATBoolean iMt) : _FromMT(iMt) {}
    CATBoolean _FromMT;
  };     

  enum TracePriority
  {
    AT_UNSET   = 0,
    AT_ERROR   = 1,
    AT_WARNING = 2,
    AT_INFO    = 3,
    AT_VERBOSE = 4
  };

  // ==================================
  // Trace
  // ==================================
  struct ExportedByCATAsyncStreamRequests Trace
  {     
    Trace(const char * iNameSpace, CATBoolean iMainThread, const char * iOwnerName=NULL);    
    virtual ~Trace()
      {}

    // Check if the trace is active. 
    // Warning a trace is not active before StartNewTrace has been called on it.
    inline CATBoolean IsActive()
      {return (_ListOfTracers.Size()>0 && _TraceMode!=AT_UNSET) ? TRUE : FALSE ;}
    
    // This method should always be called before any write in the trace.
    // It set the rigth priority mode (Error, Warning or Info) and reset to empty the trace content (the string)  
    inline Trace& StartNewTrace(TracePriority iMode)
      {_TraceMode = iMode; _CurTraceMsg.Reset(); return *this; }
      
    // Redirects the call to the class Msg
    template <class T>
    Trace& operator << (const T & iObjRef) 
      {
        if (IsActive())
          _CurTraceMsg << iObjRef;
        return *this;
      }
      
    // Redirects the call to the class Msg
    template <class T>
    Trace& operator << (const T * iObjPtr) 
      {
        if (IsActive())
          _CurTraceMsg << iObjPtr;
        return *this;
      }  
    
    // Redirects the call to the class Msg
    template <class T>
    Trace& operator << (T * iObjPtr) 
      {
        if (IsActive())
          _CurTraceMsg << (const T *)iObjPtr;
        return *this;
      }  
      
    // Indicates the end of the current trace then induces the flush.
    CATUnicodeString operator << ( const EoT & iEOT);      
        
    //
    static CATBoolean IsVerboseActive();
    // Flust the different tracers
    static void Flush(); 
    
  private:    
    
    Trace(const Trace& ) = delete ;
    Trace& operator=(const Trace&) = delete;
      
    CATOmxList<CATAsync::CATAsyncDumperTracer>  _ListOfTracers;
    TracePriority                               _TraceMode;  
    Msg                                         _CurTraceMsg;  
  };
}

typedef CATAsync::Trace CATAsyncTrace;

extern "C" ExportedByCATAsyncStreamRequests void ForceFlushOfDumper();

#endif
