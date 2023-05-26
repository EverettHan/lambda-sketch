// COPYRIGHT DASSAULT SYSTEMES 2002
//===================================================================
//
// Trace:
//   Macro definition for trace messages.
//
//===================================================================
// Usage notes:
//===================================================================
// Jun 2002  Creation                     Dmitry Ushakovint
//===================================================================

#ifndef CATCDSTraces_h
#define CATCDSTraces_h

#include "CATCDSDebug.h"
#include "CATCDSStream.h"
#include "CATCDSGlobalParameters.h"

#ifdef CDS_DEBUG

#define ORD( iIdx ) \
  iIdx << (((iIdx)/10)%10 == 1 ? "th" : ((iIdx)%10 == 1 ? "st" : (iIdx)%10 == 2 ? "nd" : (iIdx)%10 == 3 ? "rd" : "th"))

#define CATCDS_INC_CIO \
  if (GetGlobalParameters().GetCheckMode() && !GetGlobalParameters().IsMeasureTime()) \
    GetGlobalParameters().IncCheckIndent();

#define CATCDS_DEC_CIO \
  if (GetGlobalParameters().GetCheckMode() && !GetGlobalParameters().IsMeasureTime()) \
    GetGlobalParameters().DecCheckIndent();

#define CATCDS_WRITE_CIO(expr) \
  if (GetGlobalParameters().GetCheckMode() && !GetGlobalParameters().IsMeasureTime()) { \
    CATCDSStream* pCheckStream = GetGlobalParameters().GetCheckStream(); \
    if (pCheckStream) { \
      *pCheckStream << cdssetw(GetGlobalParameters().GetCheckIndent()) << ""; \
      *pCheckStream << expr << cdsendl << cdsendl; \
      pCheckStream->Flush(); \
    } \
  }

#define CATCDS_WRITE_IF_CIO(cond, expr) \
  if(cond) { \
    CATCDS_WRITE_CIO(expr); \
  }

#define CATCDS_INC_IC \
  if (GetGlobalParameters().GetTraceLevel() >= 1) \
    GetGlobalParameters().IncICIndent();
#define CATCDS_DEC_IC \
  if (GetGlobalParameters().GetTraceLevel() >= 1) \
    GetGlobalParameters().DecICIndent();

#define CATCDS_TRACE_IC(level, expr) \
  if (GetGlobalParameters().GetTraceLevel() >= level) { \
    *GetGlobalParameters().GetTraceStream() << cdssetw(GetGlobalParameters().GetICIndent())<<"";\
    *GetGlobalParameters().GetTraceStream() << expr << cdsendl;\
  }


#define CATCDS_TRACE(level, expr) \
  if (GetGlobalParameters().GetTraceLevel() >= level) \
    *GetGlobalParameters().GetTraceStream() << expr << cdsendl;

#define CATCDS_TRACE_APPEND(expr) \
  *GetGlobalParameters().GetTraceStream() << expr

#define CATCDS_TRACE_FIXED_SIZE_DOUBLE(expr) \
  GetGlobalParameters().GetTraceStream()->WriteFixedSizeDouble(expr)

#define CATCDS_TRACE_LINE(expr) \
  *GetGlobalParameters().GetTraceStream() << expr << cdsendl

#define CATCDS_TRACE_ERROR(expr) \
  *GetGlobalParameters().GetErrorStream() << expr << cdsendl

#define CATCDS_TRACE_FUNC(level, expr) \
  if (GetGlobalParameters().GetTraceLevel() >= level) \
    expr;

#define CATCDS_TRACE_FOR(level, limit, startexpr, expr, endexpr) \
  if (GetGlobalParameters().GetTraceLevel() >= level) { \
    *GetGlobalParameters().GetTraceStream() << startexpr; \
    for (int iTrace = 0; iTrace < limit; iTrace++) { \
      *GetGlobalParameters().GetTraceStream() << expr; \
    } \
    *GetGlobalParameters().GetTraceStream() << endexpr << cdsendl; \
  }

#else

#define ORD( iIdx )
#define CATCDS_INC_CIO
#define CATCDS_DEC_CIO
#define CATCDS_WRITE_CIO(expr)
#define CATCDS_INC_IC
#define CATCDS_DEC_IC
#define CATCDS_TRACE_IC(level, expr)
#define CATCDS_TRACE(level, expr)
#define CATCDS_TRACE_APPEND(expr)
#define CATCDS_TRACE_FIXED_SIZE_DOUBLE(expr)
#define CATCDS_TRACE_LINE(expr)
#define CATCDS_TRACE_ERROR(expr)
#define CATCDS_TRACE_FUNC(level, expr)
#define CATCDS_TRACE_FOR(level, limit, startexpr, expr, endexpr)

#endif
#endif

