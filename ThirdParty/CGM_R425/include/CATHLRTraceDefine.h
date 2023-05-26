#ifndef CATHLRTraceDefine_H
#define CATHLRTraceDefine_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//=============================================================================
//
// MACROS TO ENCAPSULE THE TRACE IN THE HLR
//
//=============================================================================
//
// History
//
// Oct. 2000 TPD Mise en place d'ecriture
// Nov. 2000 TPD Mise en place d'un test pour avoir les ecritures que pour une Edge
//
//=============================================================================

#include "CATCGMOutput.h"

// #define HLRDOUBLE(Number)  setw(9) << setprecision(7) << Number
// #define HLRINTEGER(Number) setw(6) << Number
#define HLRDOUBLE(Number)  CATHLRDebug::ShowDouble(Number) 
#define HLRINTEGER(Number) CATHLRDebug::ShowInteger(Number) 

#define HLRSPACE(Number) CATHLRDebug::SetSpace(Number)
#define HLR_ELSE } else {  

inline void CATHLRDebugNothing(CATHLRDebug::DebugLevel iEntry)
{
  // Does nothing
}

extern ExportedByHLRDebug const CATHLRDebug::DebugLevel CATHLRCurrentDebugLevel;

#define HLR_TRACE_IF(Condition)                                                 \
  if (Condition)                                                                \
    {
  
#define HLR_TRACE_ELSE } else {
  
#define HLR_TRACE_ENDIF  }

#ifdef CATHLRLOCALTRACE
#define HLR_TESTLOCAL(Level) (CATHLRCurrentDebugLevel != CATHLRDebug::DebugOff)
#else
#define HLR_TESTLOCAL(Level) 0
#endif  // * defined(CATHLRLOCALTRACE)

// Stream for the output
#define HLR_DEBUG_COUT CATHLRCurrentDebugStream 

//=============================================================================
// CASE WHEN SOME TRACES ARE AVAILABLE IN THE GENERATED CODE
//=============================================================================
#ifdef CATHLRTRACE 

#ifdef _WINDOWS_SOURCE
#define HLR_ERROR_LINE(Message)                                                  \
CATHLRDebug::GetErrorStream()  << Message << endl;

#define HLR_ERROR_COUT(Message)                                                  \
CATHLRDebug::GetErrorStream()  << Message;

#define HLR_ERROR_LINE_ONCE(Message)                                             \
{                                                                                \
  static int CATHLRErorrOnceVariable = 0;                                        \
  if ( ! CATHLRErorrOnceVariable)                                                \
    {                                                                            \
      CATHLRDebug::GetErrorStream() << Message  << endl;                         \
      CATHLRErorrOnceVariable = 1;                                               \
    }                                                                            \
}

#else
#define HLR_ERROR_LINE(Message)                                                  \
CATHLRDebug::GetErrorStream() << "\033[31m" << Message <<  "\033[0m" << endl;

#define HLR_ERROR_COUT(Message)                                                  \
CATHLRDebug::GetErrorStream() << "\033[31m" << Message <<  "\033[0m";

#define HLR_ERROR_LINE_ONCE(Message)                                             \
{                                                                                \
  static int CATHLRErorrOnceVariable = 0;                                        \
  if ( ! CATHLRErorrOnceVariable)                                                \
    {                                                                            \
      CATHLRDebug::GetErrorStream() << "\033[31m" << Message <<"\033[0m" << endl;\
      CATHLRErorrOnceVariable = 1;                                               \
    }                                                                            \
}

#endif

#define HLR_TRACE_LINE(Message)                                                  \
HLR_DEBUG_COUT << CATHLRDebug::GetSpace(CATHLRCurrentDebugLevel) <<              \
  Message << endl;

#define HLR_TRACE_LINESPACE(Space,Message)                                       \
HLR_DEBUG_COUT << CATHLRSetSpace(Space) <<                                       \
Message << endl;

#define HLR_TRACE_COUT(Message)                                                  \
HLR_DEBUG_COUT  << Message;

#define HLR_TRACE_ENDL HLR_DEBUG_COUT << endl;

#define HLR_TRACE_DUMP(Level, Object)                                            \
  Object->DumpStream(CATHLRCurrentDebugStream, Level)


#define HLR_MACRO_BEGIN_GENERATION(WhichDomain, Level)                                  \
if ( ( (CATHLRDebug::GetLevelForDomain(CATHLRDebug::WhichDomain) >= CATHLRDebug::Level) \
     ||  HLR_TESTLOCAL(Level) )                                                         \
   &&   CATHLRDebug::GetLEdgeOK()  )                                                    \
  {                                                                                     \
     CATHLRDebug::DebugLevel CATHLRCurrentDebugLevel = CATHLRDebug::Level;              \
     ostream & CATHLRCurrentDebugStream =                                               \
       CATHLRDebug::GetStreamForDomain(CATHLRDebug::WhichDomain);

#define HLR_MACRO_END_GENERATION(WhichDomain)                                      \
    CATHLRDebugNothing(CATHLRCurrentDebugLevel);                                   \
  } 

#define HLR_EDGE_CHOIX(TagEdge)                                                  \
CATHLRDebug::CalLEdgeOK( TagEdge );                                              \

#define HLR_EDGE_CHOIXRESET                                                      \
CATHLRDebug::SetLEdgeOK( 1 );                                                    \

#define HLR_FACE_CHOIX(TagFace)                                                  \
CATHLRDebug::CalLFaceOK( TagFace );                                              \

#define HLR_FACE_CHOIXRESET                                                      \
CATHLRDebug::SetLEdgeOK( 1 );                                                    \

#else
//=============================================================================
// CASE WHEN NO TRACES ARE WANTED IN THE GENERATED CODE
//=============================================================================
#define HLR_ERROR_LINE(Message)
#define HLR_ERROR_COUT(Message)
#define HLR_ERROR_LINE_ONCE(Message)

#define HLR_TRACE_LINE(Message)
#define HLR_TRACE_LINESPACE(Space,Message)
#define HLR_TRACE_COUT(Message)

#define HLR_TRACE_ENDL 

#define HLR_TRACE_DUMP(Level, Object) 

#define HLR_MACRO_BEGIN_GENERATION(WhichDomain, Level)                             \
  if (0)                                                                           \
    {

#define HLR_MACRO_END_GENERATION(WhichDomain)   }

#define HLR_EDGE_CHOIX(TagEdge)

#define HLR_EDGE_CHOIXRESET 

#define HLR_FACE_CHOIX(TagEdge)

#define HLR_FACE_CHOIXRESET 

#endif  // Defined CATHLRTRACE

//------------------------------------------------------------
// Macros for the creation of the general
//------------------------------------------------------------
#define HLR_GENERAL_TRACE_BEGIN(Level) HLR_MACRO_BEGIN_GENERATION(General, Level)

#define HLR_GENERAL_TRACE_END          HLR_MACRO_END_GENERATION(General) 

//------------------------------------------------------------
// Macros for the creation of the geometry
//------------------------------------------------------------
#define HLR_GEOMETRY_TRACE_BEGIN(Level) HLR_MACRO_BEGIN_GENERATION(Geometry, Level)

#define HLR_GEOMETRY_TRACE_END          HLR_MACRO_END_GENERATION(Geometry) 

//------------------------------------------------------------
// Macros for the creation of the topology
//------------------------------------------------------------
#define HLR_TOPOLOGY_TRACE_BEGIN(Level)     HLR_MACRO_BEGIN_GENERATION(Topology, Level)

#define HLR_TOPOLOGY_TRACE_END              HLR_MACRO_END_GENERATION(Topology) 

//------------------------------------------------------------
// Macros for the creation of the model
//------------------------------------------------------------
#define HLR_MODEL_TRACE_BEGIN(Level)        HLR_MACRO_BEGIN_GENERATION(Model, Level)

#define HLR_MODEL_TRACE_END                 HLR_MACRO_END_GENERATION(Model)

//------------------------------------------------------------
// Macros for the performances
//------------------------------------------------------------
#define HLR_PERFORMANCE_TRACE_BEGIN(Level)  HLR_MACRO_BEGIN_GENERATION(Performance, Level)

#define HLR_PERFORMANCE_TRACE_END           HLR_MACRO_END_GENERATION(Performance)

//------------------------------------------------------------
// Macros for the projection
//------------------------------------------------------------
#define HLR_PROJECTION_TRACE_BEGIN(Level)   HLR_MACRO_BEGIN_GENERATION(Projection, Level)

#define HLR_PROJECTION_TRACE_END            HLR_MACRO_END_GENERATION(Projection)   

//------------------------------------------------------------
// Macros for the silhouettes' creation
//------------------------------------------------------------
#define HLR_SILHOUETTE_TRACE_BEGIN(Level)   HLR_MACRO_BEGIN_GENERATION(Silhouette, Level)

#define HLR_SILHOUETTE_TRACE_END            HLR_MACRO_END_GENERATION(Silhouette)

//------------------------------------------------------------
// Macros for the sub-model's creation
//------------------------------------------------------------
#define HLR_SUBMODEL_TRACE_BEGIN(Level)     HLR_MACRO_BEGIN_GENERATION(SubModel, Level)

#define HLR_SUBMODEL_TRACE_END              HLR_MACRO_END_GENERATION(SubModel)

//------------------------------------------------------------
// Macros for the hidden points' computation
//------------------------------------------------------------
#define HLR_HDNPOINTS_TRACE_BEGIN(Level)    HLR_MACRO_BEGIN_GENERATION(HiddenPoints, Level)

#define HLR_HDNPOINTS_TRACE_END             HLR_MACRO_END_GENERATION(HiddenPoints)

//------------------------------------------------------------
// Macros for the hidden lines' computation
//------------------------------------------------------------
#define HLR_HDNLINES_TRACE_BEGIN(Level)     HLR_MACRO_BEGIN_GENERATION(HiddenLines, Level)

#define HLR_HDNLINES_TRACE_END              HLR_MACRO_END_GENERATION(HiddenLines)

//------------------------------------------------------------
// Macros for the result's generation
//------------------------------------------------------------
#define HLR_RESULT_TRACE_BEGIN(Level)       HLR_MACRO_BEGIN_GENERATION(Result, Level)

#define HLR_RESULT_TRACE_END               HLR_MACRO_END_GENERATION(Result)

//------------------------------------------------------------
// Macros for the Cpu traces
// On les veut tout le temps
//------------------------------------------------------------
#define HLR_CPU_TRACE_BEGIN(Level)                                                 \
if ((CATHLRDebug::GetLevelForDomain(CATHLRDebug::Cpu) >=                           \
     CATHLRDebug::Level) ||  HLR_TESTLOCAL(Level))                                 \
  {                                                                                \
     CATHLRDebug::DebugLevel CATHLRCurrentDebugLevel = CATHLRDebug::Level;         \
     ostream & CATHLRCurrentDebugStream =                                          \
       CATHLRDebug::GetStreamForDomain(CATHLRDebug::Cpu);

#define HLR_CPU_TRACE_END                                                          \
    CATHLRDebugNothing(CATHLRCurrentDebugLevel);                                   \
  }
#define HLR_TRACEALL_LINE(Message)                                                 \
cgmout << Message << cgmendl;
//HLR_DEBUG_COUT << CATHLRDebug::GetSpace(CATHLRCurrentDebugLevel) <<                \
//  Message << cgmendl;

#endif  // Defined CATHLRTraceDefine_H
