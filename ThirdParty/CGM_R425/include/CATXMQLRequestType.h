//===================================================================
// COPYRIGHT Microsoft 2012/02/09
//===================================================================

#ifndef CATXMQLRequestType_H
#define CATXMQLRequestType_H

// CATPLMServices
#include "CATPLMAsync.h"

/////////////////////////////////////////////////////////
/// Generic Interface XMQL - Supported Requests Types ///
/////////////////////////////////////////////////////////
enum ExportedByCATPLMAsync CATXMQLRequestType
{
  QueryBus,
  QueryConn,
  CheckoutTicket,
  ListPolicy,
  MLink,
  FlatTable,
  init_repo,
  checkout,
  checkin,
  commit,
  branch,
  query_contentid,
  LoadSession,
  JSProcedure
};

#endif
