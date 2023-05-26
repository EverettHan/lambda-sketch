#ifndef CATAsyncXMQLTypes_H
#define CATAsyncXMQLTypes_H

#include "CATPLMxMQL.h"

//===================================================================
//  XMQL Request Types
//===================================================================
namespace xMQLRequest
{
  // Forward Declaration
  // -------------------------------------
  struct Args;
  struct FileInfo;
  struct BOProxy;
  class UuidList;

  // xMQLRequest::ListId
  // -------------------------------------
  typedef unsigned int ListId;
  
  // xMQLRequest::EType
  // -------------------------------------
  enum EType
  {
    NoType,
    Bus,
    Conn,
    Path,
    Ticket,
    MassiveLink,
    ListPolicy,
    Set,
    FlatTable,
    ListProcedure,
    init_repo,
    checkout,
    checkin,
    commit,
    branch,
    query_contentid,
    LoadSession,
    JSProcedure,
    MultiTypes
  };
  ExportedByCATPLMxMQL const char * ToString(EType iType);

  enum ETypeOfOwnerOfPath
  {
    OwnerBus,
    OwnerConn
  };

  // xMQLRequest::EMode
  // -------------------------------------
  enum EMode
  {
    NoMode,
    Add,
    Delete,
    Get,
    Post,
    // Print,
    Query,
    Search,
    Expand,
    // Script,
    MultiRequests
  };
  ExportedByCATPLMxMQL const char * ToString(EMode iMode);

  // xMQLRequest::ESearchMode
  // -------------------------------------
  enum ESearchMode
  {
    QueryOnIndex,
    QueryOnServer
  };
  ExportedByCATPLMxMQL const char * ToString(ESearchMode iMode);

  // xMQLRequest::EPathFilter
  // -------------------------------------
  enum EPathFilter
  {
    NoFilter,
    StartsWithAny,
    StartsWithSequence,
    EndWithAny,
    EndsWithSequence,
    ContainsAny,
    ContainsSequence,
    SubsetOf,
    WhereFilter
  };

};

//===================================================================
//  XMQL Request arguments definitions
//===================================================================
// For PCS Profiling pursose, identify MQL Query
#define xMQL_BASIC        "xMQL_BASIC"
#define xMQL_OPEN         "xMQL_OPEN"
#define xMQL_EXPAND       "xMQL_EXPAND"
#define xMQL_PUSHEXPAND   "xMQL_PUSHEXPAND"
#define xMQL_NAVIGATE     "xMQL_NAVIGATE"
#define xMQL_PUSHNAVIGATE "xMQL_PUSHNAVIGATE"
#define xMQL_STREAMS_DL   "xMQL_FastOpenConnection"

#endif
