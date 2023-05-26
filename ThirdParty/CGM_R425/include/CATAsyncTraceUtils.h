#ifndef CATAsyncTraceUtils_H
#define CATAsyncTraceUtils_H

#include "CATOMY.h"                   // ExportedByCATOMY
#include "CATAsyncTasksPlatform_NG.h" // ExportedByCATAsyncTasksPlatform
#include "CATA5ParserExport.h"        // ExportedByCATA5Parser

#include "CATAsyncTrace.h"
#include "CATOmyResourceReference.h"
#include "CATAsyncTaskID_NG.h"
#include "CATAsyncRequest.h"
#include "CATA5CsvRow.h"

//------------------------
// CATOmyResourceReference
//------------------------
ExportedByCATOMY CATAsync::Msg& operator << (CATAsync::Msg&, const CATOmyResourceReference & );

//---------------
// CATOmyStreamId
//---------------
ExportedByCATOMY CATAsync::Msg& operator << (CATAsync::Msg&, const CATOmyStreamId & );

//---------------
// CATAsyncTaskID
//---------------
struct Id2Trace // Id2Trace is a class with only goal is help dump of CATAsyncTaskIDs
{
  Id2Trace(CATAsyncTaskID iId) : _id(iId) {}
  CATAsyncTaskID _id;
};
ExportedByCATAsyncTasksPlatform CATAsync::Msg& operator << (CATAsync::Msg&, const Id2Trace & ); 

//----------------
// CATAsyncRequest
//----------------
ExportedByCATAsyncTasksPlatform CATAsync::Msg& operator << (CATAsync::Msg& iMsg, const CATAsyncRequest * iRequest);

//--------------
// CATA5::CsvRow
//--------------
ExportedByCATA5Parser CATAsync::Msg& operator << (CATAsync::Msg& , const CATA5::CsvRow & );

#endif
