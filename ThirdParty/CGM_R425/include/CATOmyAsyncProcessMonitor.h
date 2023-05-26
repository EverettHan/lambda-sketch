//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2011/01/25
//===================================================================
// CATOmyAsyncProcessMonitor.cpp
// Header definition of class CATOmyAsyncProcessMonitor
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2011/01/25 Creation: Code generated by the 3DS wizard
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATOmyAsyncProcessMonitor_H
#define CATOmyAsyncProcessMonitor_H
#include "CATOmyAsyncSupport.h"
#include "CATOMYCuteIO.h"
#include "CATOmsXmlTraces.h"
#include "CATUnicodeString.h"
#include "CATTime.h"
#include "CATUuid.h"
#include "CATOmxEvent.h"
#include "CATOmxOHMap.h"

//------------------------------------------------------------------------------------
// MACROs definition :
//    - ASYNC_TRACE :
//         trace (to consol or xml file) a regular async message
//    - ASYNC_TRACE_WARNING :
//         trace (to consol or xml file) a warning async message
//    - ASYNC_TRACE_ERROR :
//         trace (to consol or xml file) a error async message
//------------------------------------------------------------------------------------

#define AsyncString CATOmyAsyncMonitorString

#define ALL_PROCESSES 0
#define NO_PROCESS -1

#define ASYNC_TRACE\
  CATOmyAsyncProcessMonitor::SetCallerInfo(__FILE__, __LINE__);\
  CATOmyAsyncProcessMonitor::TraceAsyncMessage

#define ASYNC_TRACE_WARNING\
  CATOmyAsyncProcessMonitor::SetCallerInfo(__FILE__, __LINE__);\
  CATOmyAsyncProcessMonitor::TraceAsyncMessageWarning

#define ASYNC_TRACE_ERROR\
  CATOmyAsyncProcessMonitor::SetCallerInfo(__FILE__, __LINE__);\
  CATOmyAsyncProcessMonitor::TraceAsyncMessageError

#ifdef _WINDOWS_SOURCE
#define CATAsyncThreadId CATThreadsId
#else
#define CATAsyncThreadId CATLONGPTR
#endif

/*******************************************************************************
* Probl�mes & Suggestions :
*   - g�n�ral : le stamp de temps pr�cis � la ms (voir si am�lioration possible)
*   - g�n�ral : Write Type of process (xml traces)
*******************************************************************************/

class CATOmyAsyncMonitorString;

//-----------------------------------------------------------------------------
// AsyncTraceLevel enum
//-----------------------------------------------------------------------------
enum AsyncTraceLevel
{
  AsyncTraceLevel_System_User         = 0x0101,
  AsyncTraceLevel_Functional_User     = 0x0102,
  AsyncTraceLevel_Comm_User           = 0x0104,
  AsyncTraceLevel_Debug_User          = 0x0108,
  AsyncTraceLevel_System_Dev          = 0x0201,
  AsyncTraceLevel_Functional_Dev      = 0x0202,
  AsyncTraceLevel_Comm_Dev            = 0x0204,
  AsyncTraceLevel_Debug_Dev           = 0x0208,
  AsyncTraceLevel_System_Verb         = 0x0401,
  AsyncTraceLevel_Functional_Verb     = 0x0402,
  AsyncTraceLevel_Comm_Verb           = 0x0404,
  AsyncTraceLevel_Debug_Verb          = 0x0408,
  AsyncTraceLevel_System_ODT          = 0x0801,
  AsyncTraceLevel_Functional_ODT      = 0x0802,
  AsyncTraceLevel_Comm_ODT            = 0x0804,
  AsyncTraceLevel_Debug_ODT           = 0x0808
};

enum AsyncTraceLevelMask
{
  AsyncTraceLevel_Type                = 0x00FF,
  AsyncTraceLevel_System              = 0x0001,
  AsyncTraceLevel_Functional          = 0x0002,
  AsyncTraceLevel_Comm                = 0x0004,
  AsyncTraceLevel_Debug               = 0x0008,
  AsyncTraceLevel_Use                 = 0xFF00,
  AsyncTraceLevel_User                = 0x0100,
  AsyncTraceLevel_Dev                 = 0x0200,
  AsyncTraceLevel_Verbose             = 0x0400,
  AsyncTraceLevel_ODT                 = 0x0800,
};

//-----------------------------------------------------------------------------
// AsyncTraceWarningLevel enum
//-----------------------------------------------------------------------------
enum AsyncTraceWarningLevel
{
  AsyncTraceWarningLevel_Regular = 0,
  AsyncTraceWarningLevel_Warning = 1,
  AsyncTraceWarningLevel_Error = 2
};

enum AsyncTraceTransaction
{
  AsyncTraceTransaction_NA = 0,
  AsyncTraceTransaction_Reception = 1,
  AsyncTraceTransaction_Sending = 2
};

//-----------------------------------------------------------------------------
// class AsyncTracesMessage :
// - Class compatible with OmsXMLTracer allowing to add complementary element
// to an xml message
//-----------------------------------------------------------------------------
class AsyncTracesMessage : public TraceMessage
{
public:

  AsyncTracesMessage(const CATUnicodeString & iTag, int iNumText);
  AsyncTracesMessage(const CATUnicodeString & iTag, const CATOmyAsyncMonitorString & iInfo);
  AsyncTracesMessage(const CATOmyAsyncMonitorString & iInfo);

  virtual ~AsyncTracesMessage();
  virtual void Dump() const;

  private:

  AsyncTracesMessage& operator=(const AsyncTracesMessage&);
  AsyncTracesMessage(const AsyncTracesMessage&);

};

//-----------------------------------------------------------------------------
// Main class CATOmyAsyncProcessMonitor :
// - Class define by a singleton allowing to trace asynchronism messages
// to OMB XML TRACES and/or Console.
// - The xml traces are unique for asynchronism and contain complementary data
// for the async debug monitor process such as pid, ppid, related pid
// or synchronism stamp allowing to merge xml traces.
//-----------------------------------------------------------------------------
class ExportedByCATOMYCuteIO CATOmyAsyncProcessMonitor : public CATOmxEventListener
{

public:

  // set the caller information (file and line)
  static void SetCallerInfo(char const * iFile, int iLine);

  // set a particular PID to the process (only for odt mode)
  static void SetNewPid(int iNewPid);

  // set a particular TID to the current thread (only for odt mode)
  static void SetNewTid(CATAsyncThreadId iNewTid);

  // traces an XML error message and/or dumps a consol trace
  static void TraceAsyncMessageError(
    const CATOmyAsyncMonitorString& iMessage,
    AsyncTraceLevel iAsyncTraceLevel = AsyncTraceLevel_Functional_Verb,
    int iRelatedPID = NO_PROCESS,
    AsyncTraceTransaction iAsyncTraceTransaction = AsyncTraceTransaction_NA,
    bool iLightTrace = false);

  // traces an XML error message and/or dumps a consol trace
  static void TraceAsyncMessageError(
    AsyncTraceLevel iAsyncTraceLevel,
    const CATOmyAsyncMonitorString& iMessage,
    int iRelatedPID = NO_PROCESS,
    AsyncTraceTransaction iAsyncTraceTransaction = AsyncTraceTransaction_NA,
    bool iLightTrace = false);

  // traces an XML error message and/or dumps a consol trace
  static void TraceAsyncMessageWarning(
    const CATOmyAsyncMonitorString& iMessage,
    AsyncTraceLevel iAsyncTraceLevel = AsyncTraceLevel_Functional_Verb,
    int iRelatedPID = NO_PROCESS,
    AsyncTraceTransaction iAsyncTraceTransaction = AsyncTraceTransaction_NA,
    bool iLightTrace = false);

  // traces an XML error message and/or dumps a consol trace
  static void TraceAsyncMessageWarning(
    AsyncTraceLevel iAsyncTraceLevel,
    const CATOmyAsyncMonitorString& iMessage,
    int iRelatedPID = NO_PROCESS,
    AsyncTraceTransaction iAsyncTraceTransaction = AsyncTraceTransaction_NA,
    bool iLightTrace = false);

  // traces an XML message and/or dumps a consol trace
  static void TraceAsyncMessage(
    const CATOmyAsyncMonitorString& iMessage,
    AsyncTraceLevel iAsyncTraceLevel = AsyncTraceLevel_Functional_Verb,
    int iRelatedPID = NO_PROCESS,
    AsyncTraceTransaction iAsyncTraceTransaction = AsyncTraceTransaction_NA,
    bool iLightTrace = false,
    AsyncTraceWarningLevel iWarningLevel = AsyncTraceWarningLevel_Regular,
    bool iTraceMT = false);

  // traces an XML message and/or dumps a consol trace
  static void TraceAsyncMessage(
    const CATOmyAsyncMonitorString& iMessage,
    AsyncTraceLevel iAsyncTraceLevel,
    bool iLightTrace);

  // traces an XML message and/or dumps a consol trace
  static void TraceAsyncMessage(
    AsyncTraceLevel iAsyncTraceLevel,
    const CATOmyAsyncMonitorString& iMessage,
    bool iLightTrace);

  // traces an XML message and/or dumps a console trace
  static void TraceAsyncMessage(
    AsyncTraceLevel iAsyncTraceLevel,
    const CATOmyAsyncMonitorString& iMessage,
    int iRelatedPID = NO_PROCESS,
    AsyncTraceTransaction iAsyncTraceTransaction = AsyncTraceTransaction_NA,
    bool iLightTrace = false);


private:
  // Singleton
  static CATOmyAsyncProcessMonitor * _asyncMonitorInstance;

  // Get Singleton Instance (do not release pointer after use)
  static CATOmyAsyncProcessMonitor * GetInstance();

  // Clean Instance
  static int Clean(int iExitStatus);

  // Caller informations
  static CATUnicodeString _callerFile;

  // PID
  int _pid;

  // Set the async trace level given by OMY_MP_TRACE var env
  static int GetAsyncTraceLevel();

  // Check if the trace hase to be traced depending on level and warning level
  bool HasToBeTraced(AsyncTraceLevel iAsyncTraceLevel, AsyncTraceWarningLevel iAsyncTraceWarningLevel);

  // Check if MICAT(var env) and OMB XML Traces are activated
  bool AsyncMonitoringActivated();

  // Check if the trace have to be dumped to the console
  bool DumpAsyncTraceToConsole(int iAsyncTraceLevel);

  // Type of async process (CATIA or Async Proc)
  CATUnicodeString _processType;
  // Arrow for console
  CATUnicodeString _messageProcessDirection;
  // Mask for displaying different level of trace (System or Functional) to the consol
  const int _traceLevel;

  // Synchronism
  CATULONG64 _syncTraceStamp;
  CATULONG64 _currentTime;

  // For displaying light trace
  bool _lightTrace;

  // Message Process ID
  AsyncTracesMessage * _pidProcessMessage;

  // Initialize the singleton
  void Initialize();

  // Launch Merger
  bool LaunchMICAT();

  // Set process Type data
  void SetProcessTypeData();

  // Returns the string corresponding to the trace level (System or Functional)
  CATUnicodeString AsyncTraceLevelToChar(AsyncTraceLevel iLevel) const;

  // Returns the string corresponding to the trace level (System or Functional)
  char* AsyncTraceWarningLevelToChar(AsyncTraceWarningLevel iWarningLevel) const;

  // Returns a sync stamp
  CATUnicodeString& GetSyncStamp(AsyncTraceTransaction iAsyncTraceTransaction, CATUnicodeString& oSyncStampStringAsyncTraceTransaction);

  // Initialize process beginning time attribute
  void InitializeProcessBeginningTime();

  // Get the current time
  CATULONG64 GetAsyncMonitorCurrentTime();

  // CATOmxEvent Reception
  void Receive(CATOmxEventContext &iContext);

  //*************************
  // Threads management
  //*************************
  // Threads logging files
  CATOmxOHMap<CATAsyncThreadId, void*> _threadsFilesMap;

  CATBoolean IsCalledOnMainThread(); 

  FILE* GetLogFileForThread(CATAsyncThreadId iTid); 

  HRESULT LogMessageForCurrentThread(const CATUnicodeString& iLevel,
                                     const CATUnicodeString& iSyncID,
                                     const CATUnicodeString& iMessageType,
                                     const CATUnicodeString& iMessage,
                                     const CATUnicodeString& iRelatedPid,
                                     const CATUnicodeString& iTransaction,
                                     const CATUnicodeString& iCaller);

  CATOmxOHMap<CATAsyncThreadId, int> _threadsTracesId; // for ODT only

  CATOmxOHMap<CATAsyncThreadId, CATAsyncThreadId> _newTidsMap; // for ODT only

  CATMutex _tMut;

  //*************************
  // Threads management
  //*************************

  // Standard constructor and destructor
  // Constructor should not be called
  // Use GetInstance instead
  // -------------------------------------
  CATOmyAsyncProcessMonitor ();
  virtual ~CATOmyAsyncProcessMonitor ();

  // Copy constructor and equal operator
  // -----------------------------------
  CATOmyAsyncProcessMonitor (const CATOmyAsyncProcessMonitor &);
  CATOmyAsyncProcessMonitor& operator=(const CATOmyAsyncProcessMonitor&);

  //Mask for MICAT: to remove when dev finished
  int _asyncTraceLevel_MICATMask;

  void InitializeFilter();

};

//-----------------------------------------------------------------------


//-----------------------------------------------------------------------------
// class CATOmyAsyncMonitorString :
// - Class allowing to concat CATUnicodeString with anything (num) thanks to
// operator +
//-----------------------------------------------------------------------------
class ExportedByCATOMYCuteIO CATOmyAsyncMonitorString
{
public:

  CATOmyAsyncMonitorString(const CATUnicodeString& stringRef);
  CATOmyAsyncMonitorString(const char* stringRef);
  CATOmyAsyncMonitorString(const CATOmyAsyncMonitorString&);

  virtual ~CATOmyAsyncMonitorString();

  const CATUnicodeString& StringRef() const { return _stringRef; }

  CATOmyAsyncMonitorString& operator+ (const CATOmyAsyncMonitorString& msg);
  CATOmyAsyncMonitorString& operator+ (const CATUnicodeString& msg);
  CATOmyAsyncMonitorString& operator+ (const char* msg);
  CATOmyAsyncMonitorString& operator+ (CATINT32 msg);
  CATOmyAsyncMonitorString& operator+ (CATUINT32 msg);
#if !defined(PLATEFORME_DS64)
  CATOmyAsyncMonitorString& operator+ (CATLONG32 msg);
  CATOmyAsyncMonitorString& operator+ (CATULONG32 msg);
#else
#if !defined(_WINDOWS_SOURCE)
  CATOmyAsyncMonitorString& operator+ (CATINTPTR msg);
#endif
#endif
  CATOmyAsyncMonitorString& operator+ (CATLONG64 msg);
  CATOmyAsyncMonitorString& operator+ (CATULONG64 msg);
  CATOmyAsyncMonitorString& operator+ (double msg);

  // To remove
  CATOmyAsyncMonitorString& operator+ (const CATUuid &msg);

private:
  static const bool _asyncMonitoring;

  CATOmyAsyncMonitorString& operator=(const CATOmyAsyncMonitorString&);
  CATUnicodeString _stringRef;
};

//-----------------------------------------------------------------------
#define CATOMY_PROCESS_MONITOR(a) a
#endif